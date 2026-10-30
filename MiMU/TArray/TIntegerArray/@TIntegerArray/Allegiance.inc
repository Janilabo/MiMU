{$IFDEF HELPERS}
function Cantoned: TIntegerArray; overload;
function Hauled: TIntegerArray; overload;

function Anchored(const oAscending: Boolean = True): TIntegerArray; overload;
function Meted(const oAscending: Boolean = True): TIntegerArray; overload;
function Moored(const oAscending: Boolean = True): TIntegerArray; overload;
function Patrolled(const oAscending: Boolean = True): TIntegerArray; overload;
function Sounded(const oAscending: Boolean = True): TIntegerArray; overload;
function Tacked(const oAscending: Boolean = True): TIntegerArray; overload;

function Plied: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Cantoned>
  @action: Generates a stepped/quantized integer array by splitting the interval between consecutive elements at their exact integer midpoint,
           using direct index mapping relative to the starting element.
  @note: Computes absolute offsets (k and d) from the start of the array (Self[0]), assigning the first half of each interval (0 to d div 2) to Self[i] and the remainder to Self[i + 1].
         Unlike other methods, the oAscending parameter is unused in this implementation, as absolute differences (Abs) are used for distance calculations regardless of direction.
[==============================================================================}
function TIntegerArrayHelper.Cantoned: TIntegerArray; overload;
var
  h, i, j, k, d: Integer;
begin
  h := High(Self);
  if (h < 1) then
    Exit(Self.Copy);
  SetLength(Result, (Abs(Int64(Self[h]) - Self[0]) + 1));
  for i := 0 to (h - 1) do
  begin
    k := Abs(Self[i] - Self[0]);
    d := Abs(Self[i + 1] - Self[i]);
    for j := 0 to (d div 2) do
      Result[k + j] := Self[i];
    for j := ((d div 2) + 1) to (d - 1) do
      Result[k + j] := Self[i + 1];
  end;
  Result[High(Result)] := Self[h];
end;

{==============================================================================]
  <Hauled>
  @action: Generates a stepped/quantized integer array using a branchless nearest-neighbor selection per output position.
  @note: For each offset j within an interval of length d, the value is Self[i] + (Self[i + 1] - Self[i]) * Ord(2 * j > d),
         so the result flips to the next element only once j is strictly past the midpoint (ties stay with Self[i]).
         Offsets use Int64 for the doubling to avoid overflow on large intervals. Handles ascending and descending sequences.
[==============================================================================}
function TIntegerArrayHelper.Hauled: TIntegerArray; overload;
var
  h, i, j, r, a, d: Integer;
begin
  h := High(Self);
  if (h < 1) then
    Exit(Self.Copy);
  SetLength(Result, (Abs(Int64(Self[h]) - Self[0]) + 1));
  r := 0;
  for i := 0 to (h - 1) do
  begin
    a := Self[i];
    d := Abs(Self[i + 1] - a);
    for j := 0 to (d - 1) do
      Result[r.Increase] := (a + ((Self[i + 1] - a) * Ord((Int64(j) * 2) > d)));
  end;
  Result[r] := Self[h];
end;

{==============================================================================]
  <Anchored>
  @action: Precomputes output-index boundaries, then fills output in one pass.
  @note: O(N + h) time, O(h) extra memory. Each Bounds[i] marks the first
         output index NOT owned by Self[i]. Unlike Patrolled (value sweep),
         this compares the current output index against positional thresholds.
[==============================================================================}
function TIntegerArrayHelper.Anchored(const oAscending: Boolean = True): TIntegerArray; overload;
var
  h, i, r, d, s, p: Integer;
  b: TIntegerArray;
begin
  h := High(Self);
  if (h < 1) then
    Exit(Self.Copy);
  SetLength(Result, (Abs(Int64(Self[h]) - Self[0]) + 1));
  SetLength(b, h);
  p := 0;
  for i := 0 to (h - 1) do
  begin
    if (i > 0) then
    begin
      s  := Abs(Self[i] - Self[i - 1]);
      Inc(p, (s - ((s div 2) + 1)));
    end;
    d := Abs(Self[i + 1] - Self[i]);
    Inc(p, ((d div 2) + 1));
    b[i] := p;
  end;
  i := 0;
  for r := 0 to High(Result) do
  begin
    while ((i < h) and (r >= b[i])) do
      Inc(i);
    Result[r] := Self[i];
  end;
end;

{==============================================================================]
  <Meted>
  @action: Generates a stepped/quantized integer array by splitting the interval between consecutive elements at their exact integer midpoint.
  @note: Calculates the midpoint $m$ using integer division (div 2), assigning values up to the midpoint to Self[i] and values past the midpoint to Self[i+1].
         Handles both ascending and descending sequences.
[==============================================================================}
function TIntegerArrayHelper.Meted(const oAscending: Boolean = True): TIntegerArray; overload;
var
  h, i, j, r, m: Integer;
begin
  h := High(Self);
  if (h < 1) then
    Exit(Self.Copy);
  SetLength(Result, (Abs(Int64(Self[h]) - Self[0]) + 1));
  r := 0;
  case oAscending of
    True:
    for i := 0 to (h - 1) do
    begin
      m := (Self[i] + ((Self[i +  1] - Self[i]) div 2));
      for j := Self[i] to m do
        Result[r.Increase] := Self[i];
      for j := (m + 1) to (Self[i + 1] - 1) do
        Result[r.Increase] := Self[i + 1];
    end;
    False:
    for i := 0 to (h - 1) do
    begin
      m := (Self[i] + ((Self[i +  1] - Self[i]) div 2));
      for j := Self[i] downto m do
        Result[r.Increase] := Self[i];
      for j := (m - 1) downto (Self[i + 1] + 1) do
        Result[r.Increase] := Self[i + 1];
    end;
  end;
  Result [r] := Self[h];
end;

{==============================================================================]
  <Moored>
  @action: Generates a stepped/quantized integer array by performing a nearest-neighbor
           interpolation between consecutive elements of the source array.
  @note: Uses nested for loops to iterate through each sub-range between elements,
         assigning each intermediate value to the closest boundary (Self[i] or Self[i+1]). Supports both ascending and descending orders.
[==============================================================================}
function TIntegerArrayHelper.Moored(const oAscending: Boolean = True): TIntegerArray; overload;
var
  r, h, i, j: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit([]);
  r := 0;
  case oAscending of
    True:
    begin
      SetLength(Result, ((Self[h] - Self[0]) + 1));
      for i := 0 to (h - 1) do
        for j := Self[i] to (Self[i + 1] - 1) do
          if ((j - Self[i]) <= (Self[i + 1] - j)) then
            Result[r.Increase] := Self[i]
          else
            Result[r.Increase] := Self[i + 1];
    end;
    False:
    begin
      SetLength(Result, ((Self[0] - Self[h]) + 1));
      for i := 0 to (h - 1) do
        for j := Self[i] downto (Self[i + 1] + 1) do
          if ((Self[i] - j) <= (j - Self[i + 1])) then
            Result[r.Increase] := Self[i]
          else
            Result[r.Increase] := Self[i + 1];
    end;
  end;
  Result[r] := Self[h];
end;

{==============================================================================]
  <Patrolled>
  @action: Generates a stepped/quantized integer array via a forward-sweeping nearest-neighbor interpolation from the starting element to the ending element.
  @note: Iterates step-by-step through every integer value from Self[0] to Self[h] using a running value variable (v) and a direction multiplier (o).
         It dynamically advances the active segment index (i) as v crosses boundaries, assigning the closest segment endpoint (Self[i] or Self[i + 1]) to each position in the result array.
		 Fully supports both ascending and descending sequences based on oAscending.
[==============================================================================}
function TIntegerArrayHelper.Patrolled(const oAscending: Boolean = True): TIntegerArray; overload;
var
  h, i, r, o, v, a, b: Integer;
begin
  h := High(Self);
  if (h < 1) then
    Exit(Self.Copy);
  o := 1;
  if (not oAscending) then
    o := -1;
  SetLength(Result, (Abs(Int64(Self[h]) - Self[0]) + 1));
  i := 0;
  v := Self[0];
  for r := 0 to High(Result) do
  begin
    while ((i < (h - 1)) and (((v - Self[i + 1]) * o) >= 0)) do
      Inc(i);
    a := Self[i];
    b := Self[i + 1];
    if (((v - a) * o) <= ((b - v) * o)) then
      Result[r] := a
    else
      Result[r] := b;
    Inc(v, o);
  end;
end;

{==============================================================================]
  <Sounded>
  @action: Generates a stepped/quantized integer array via an optimized, binary-search-based nearest-neighbor interpolation from the starting element to the ending element.
  @note: Similar to Patrolled, but instead of a linear scan to find the active segment index for each step v,
         it uses a binary search (l and u bounds with midpoint m) to find the correct interval in $O(\log h)$ time per point.
		 It then evaluates the distance to the two boundaries (a and b) using the direction multiplier o, fully supporting both ascending and descending sequences.
[==============================================================================}
function TIntegerArrayHelper.Sounded(const oAscending: Boolean = True): TIntegerArray; overload;
var
  h, l, m, u, r, v, o, a, b: Integer;
begin
  h := High(Self);
  if (h < 1) then
    Exit(Self.Copy);
  o := 1;
  if not oAscending then
    o := -1;
  SetLength(Result, (Abs(Int64(Self[h]) - Self[0]) + 1));
  v := Self[0];
  for r := 0 to High(Result) do
  begin
    l := 0;
    u := (h - 1);
    while (l < u) do
    begin
      m := (l + ((u - l + 1) div 2));
      if (((Self[m] - v) * o) <= 0) then
        l := m
      else
        u := (m - 1);
    end;
    a := Self[l];
    b := Self[l + 1];
    if (((v - a) * o) <= ((b - v) * o)) then
      Result[r] := a
    else
      Result[r] := b;
    Inc(v, o);
  end;
end;

{==============================================================================]
  <Tacked>
  @action: Generates a stepped/quantized integer array via nearest-neighbor interpolation between consecutive elements using an optimized while-loop structure.
  @note: Functionally equivalent to Moored, but replaces nested for loops with conditional while loops and .Increase/.Decrease helper calls for interval traversal.
[==============================================================================}
function TIntegerArrayHelper.Tacked(const oAscending: Boolean = True): TIntegerArray; overload;
var
  a, b, r, h, i, j: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit([]);
  r := 0;
  case oAscending of
    True:
    begin
      SetLength(Result, ((Self[h] - Self[0]) + 1));
      for i := 0 to (h - 1) do
      begin
        a := Self[i];
        b := Self[i + 1];
        j := a;
        while ((j < b) and ((j - a) <= (b - j))) do
        begin
          Result[r.Increase] := a;
          Inc(j);
        end;
        while (j.Increase < b) do
          Result[r.Increase] := b;
      end;
    end;
    False:
    begin
      SetLength(Result, ((Self[0] - Self[h]) + 1));
      for i := 0 to (h - 1) do
      begin
        a := Self[i];
        b := Self[i + 1];
        j := a;
        while ((j > b) and ((a - j) <= (j - b))) do
        begin
          Result[r.Increase] := a;
          Dec(j);
        end;
        while (j.Decrease > b) do
          Result[r.Increase] := b;
      end;
    end;
  end;
  Result[r] := Self[h];
end;

{==============================================================================]
  <Plied>
  @action: Generates a stepped/quantized integer array using a branchless nearest-neighbor selection per output position.
  @note: For each offset j within an interval of length d, the value is Self[i] + (Self[i + 1] - Self[i]) * Ord(2 * j > d),
         so the result flips to the next element only once j is strictly past the midpoint (ties stay with Self[i]).
         Result length is the sum of all interval distances + 1, so non-monotonic input is supported.
[==============================================================================}
function TIntegerArrayHelper.Plied: TIntegerArray; overload;
var
  h, i, j, r, a, d: Integer;
  t: Int64;
begin
  h := High(Self);
  if (h < 1) then
    Exit(Self.Copy);
  t := 1;
  for i := 0 to (h - 1) do
    Inc(t, Abs(Int64(Self[i + 1]) - Self[i]));
  SetLength(Result, t);
  r := 0;
  for i := 0 to (h - 1) do
  begin
    a := Self[i];
    d := Abs(Self[i + 1] - a);
    for j := 0 to (d - 1) do
      Result[r.Increase] := (a + ((Self[i + 1] - a) * Ord((Int64(j) * 2) > d)));
  end;
  Result[r] := Self[h];
end;
{$ENDIF}
