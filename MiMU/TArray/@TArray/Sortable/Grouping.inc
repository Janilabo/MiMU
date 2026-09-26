{$IFDEF HELPERS}
function Congress(const rAscending: Boolean = True): M2DArray; overload;
function Congressment(const oAscending: Boolean = True): M2DArray; overload;

function AsPiles(const oAscending: Boolean = True): M2DArray; overload;
function ForPiles(const oAscending: Boolean = True): M2DArray; overload;
function Piledly(const oAscending: Boolean = True): M2DArray; overload;
function Piles(const oAscending: Boolean = True): M2DArray; overload;
function Repilus(const oAscending: Boolean = True): M2DArray; overload;
function Selip(const oAscending: Boolean = True): M2DArray; overload;
function ToPiles(const oAscending: Boolean = True): M2DArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Congress>
  @action: Groups identical elements into sorted sub-arrays by assembling matching 
          values after a full sort pass.
  @note: 
  - QuickSort pass: Pre-sorts the entire array via QuickSorted into buffer 
    to bring all duplicate elements into contiguous adjacent blocks.
  - Single-pass scanning: Traverses the sorted buffer to gather identical 
    values into distinct 2D rows ("congresses" of equal values).
  - Dynamic buffer management: Pre-allocates working row buffers using maximum 
    possible remaining length and trims each completed row to its true 
    count upon detecting a value boundary.
  - Functional equivalence: Performs the same grouping task as BinaryGrouping, 
    but relies on sorting + linear scan rather than binary grow + search lookups.
[==============================================================================}
function MArrayHelper.Congress(const rAscending: Boolean = True): M2DArray; overload;
var
  g, s, c, i: Integer;
  r: MArray;
begin
  s := Self.Length;
  SetLength(Result, s);
  if (s = 0) then
    Exit;
  r := Self.QuickSorted(rAscending);
  g := 0;
  SetLength(Result[0], s);
  Result[0][0] := r[0];
  c := 1;
  for i := 1 to (s - 1) do
    if (r[i] <> Result[g][0]) then
    begin
      SetLength(Result[g], c);
      SetLength(Result[g.Increment], (s - i));
      c := 1;
      Result[g][0] := r[i];
    end else
      Result[g][c.Increase] := r[i];
  SetLength(Result[g], c);
  SetLength(Result, (g + 1));
end;

{==============================================================================]
  <Congressment>
  @action: Groups duplicate values into sorted 2D sub-arrays using a two-pass 
          run-length counting algorithm on a sorted buffer.
  @note: 
  - Pass 1 (Sort & Count): Pre-sorts the array via QuickSorted into r and sweeps 
    it linearly to calculate exact run-length duplicate counts into array n.
  - Pass 2 (Exact Allocation & Copy): Pre-allocates exact row capacities using the run counts,
    then copies elements directly without mid-loop reallocations or trimming.
  - Optimization over Congress: Eliminates intermediate array resizing/trimming 
    during row population by front-loading run-length detection.
[==============================================================================}
function MArrayHelper.Congressment(const oAscending: Boolean = True): M2DArray; overload;
var
  s, i, g, c: Integer;
  r: MArray;
  n: TIntegerArray;
begin
  s := Self.Length;
  if (s = 0) then
    Exit;
  r := Self.QuickSorted(oAscending);
  SetLength(n, s);
  g := 0;
  n[0] := 1;
  for i := 1 to (s - 1) do
    if (r[i] = r[i - 1]) then
      Inc(n[g])
    else
      n[g.Increment] := 1;
  SetLength(n, (g + 1));
  SetLength(Result, n.Length);
  c := 0;
  for g := 0 to High(n) do
    for i := 0 to Result[g].Alloc(n[g]) do
      Result[g][i] := r[c.Increase];
end;

{==============================================================================]
  <AsPiles>
  @action: Splits the array into a 2D array (piles) of ordered subsequences, greedily grouped into non-decreasing or non-increasing order.
  @note: In each pass, it forms a pile by scanning left-to-right and extracting elements that maintain the chosen sorting order (based on oAscending).
         Skipped elements are pushed to the next pass. The worst-case time complexity is O(N^2) if the array is perfectly reversed relative to the desired order.
[==============================================================================}
function MArrayHelper.AsPiles(const oAscending: Boolean = True): M2DArray; overload;
var
  h, i, l, r: Integer;
  s: TIntegerArray;
begin
  l := Self.Length;
  if (l < 2) then
    Exit([Self.Cloned]);
  SetLength(Result, l);
  s := Self.Indexes;
  r := 0;
  while (l > 0) do
  begin
    SetLength(Result[r], l);
    l := 0;
    h := -1;
    for i := 0 to High(Result[r]) do
      if ((h = -1) or ((oAscending and (Self[s[i]] >= Result[r][h])) or ((not oAscending) and (Self[s[i]] <= Result[r][h])))) then
        Result[r][h.Increment] := Self[s[i]]
      else
        s[l.Increase] := s[i];
    SetLength(Result[r.Increase], (h + 1));
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <ForPiles>
  @action: Organizes an array into non-strictly monotonic sub-arrays ("piles") 
          using a two-pass deferred greedy distribution algorithm.
  @note: 
    - Pass 1: Attempts to extend existing piles with incoming elements. If an 
      element cannot fit into any active pile and the last active pile has a length 
      of 1, its index is deferred into array `d` to avoid prematurely spawning 
      single-element piles.
    - Pass 2: Iterates through the deferred indices (`d`) and places them into 
      existing piles or appends new piles as needed.
    - Returns a 2D array containing the resulting monotonic sub-arrays.
[==============================================================================}
function MArrayHelper.ForPiles(const oAscending: Boolean = True): M2DArray; overload;
var
  i, j, k, l, g, r: Integer;
  f: Boolean;
  d: TIntegerArray;
begin
  l := Self.Length;
  if (l < 2) then
    Exit([Self.Cloned]);
  SetLength(Result, l);
  Result[0] := [Self[0]];
  g := 0;
  r := 0;
  SetLength(d, l);
  for i := 1 to (l - 1) do
  begin
    f := False;
    for j := 0 to g do
      if ((oAscending and (Self[i] >= Result[j][High(Result[j])])) or ((not oAscending) and (Self[i] <= Result[j][High(Result[j])]))) then
      begin
        f := True;
		Result[j].Supply(Self[i]);
        Break;
      end;
    if not f then
	  if (Result[g].Length > 1) then
        Result[g.Increment] := [Self[i]]
	  else
        d[r.Increase] := i;
  end;
  for k := 0 to (r - 1) do
  begin
    f := False;
    for j := 0 to g do
      if ((oAscending and (Self[d[k]] >= Result[j][High(Result[j])])) or ((not oAscending) and (Self[d[k]] <= Result[j][High(Result[j])]))) then
      begin
        f := True;
		Result[j].Supply(Self[d[k]]);
        Break;
      end;
    if not f then
      Result[g.Increment] := [Self[d[k]]];
  end;
  SetLength(Result, (g + 1));
end;

{==============================================================================]
  <Piledly>
  @action: Decomposes an array into monotonic sub-arrays using an alternating-direction 
          multi-pass extraction algorithm.
  @note: 
  - Pass-based extraction: Uses an index tracking array to extract a 
    long maximal monotonic subsequence in each pass, collecting unplaced index 
    positions for subsequent passes.
  - Alternating direction: Calls Reverse at the end of each pass (when remaining 
    unplaced index count > 1), flipping the traversal direction for the next 
    pile extraction (zigzag/boustrophedon processing).
  - Trims each pile buffer dynamically to its actual length and terminates 
    when all index references have been distributed.
[==============================================================================}
function MArrayHelper.Piledly(const oAscending: Boolean = True): M2DArray; overload;
var
  h, i, l, r: Integer;
  s: TIntegerArray;
begin
  l := Self.Length;
  if (l < 2) then
    Exit([Self.Cloned]);
  s := Self.Indexes();
  r := 0;
  repeat
    SetLength(Result, (Result.Length + 1));
    SetLength(Result[r], l);
    l := 0;
    h := -1;
    for i := 0 to High(Result[r]) do
      if ((h = -1) or ((oAscending and (Self[s[i]] >= Result[r][h])) or ((not oAscending) and (Self[s[i]] <= Result[r][h])))) then
        Result[r][h.Increment] := Self[s[i]]
      else
        s[l.Increase] := s[i];
    SetLength(Result[r.Increase], (h + 1));
    if (s.SetSize(l) > 1) then
      s.Reverse;
  until (l = 0);
end;

{==============================================================================]
  <Piles>
  @action: Partitions the array into non-decreasing (or non-increasing) 2D element piles based on Patience Sorting distribution logic.
  @note: Directly stores array values (rather than indices) in sub-arrays; automatically trims unused tail allocations before returning.
[==============================================================================}
function MArrayHelper.Piles(const oAscending: Boolean = True): M2DArray; overload;
var
  i, j, l, g: Integer;
  f: Boolean;
begin
  l := Self.Length;
  if (l < 2) then
    Exit([Self.Cloned]);
  SetLength(Result, l);
  Result[0] := [Self[0]];
  g := 0;
  for i := 1 to (l - 1) do
  begin
    f := False;
    for j := 0 to g do
      if ((oAscending and (Self[i] >= Result[j][High(Result[j])])) or ((not oAscending) and (Self[i] <= Result[j][High(Result[j])]))) then
      begin
        f := True;
		Result[j].Supply(Self[i]);
        Break;
      end;
    if not f then
      Result[g.Increment] := [Self[i]];
  end;
  SetLength(Result, (g + 1));
end;

{==============================================================================]
  <Repilus>
  @action: Organizes an array into non-strictly monotonic sub-arrays ("piles") 
          by processing elements in reverse order (right-to-left).
  @note: 
    - Iterates backward from the last element to the first, building piles greedily 
      based on the trailing element of each pile.
    - Since elements are processed right-to-left and appended to the end of each 
      pile, elements inside each resulting sub-array appear in reverse chronological 
      order relative to their position in the source array.
    - Returns a 2D array containing the resulting right-to-left piles.
[==============================================================================}
function MArrayHelper.Repilus(const oAscending: Boolean = True): M2DArray; overload;
var
  i, j, l, g: Integer;
  f: Boolean;
begin
  l := Self.Length;
  if (l < 2) then
    Exit([Self.Cloned]);
  SetLength(Result, l);
  Result[0] := [Self[l - 1]];
  g := 0;
  for i := (l - 2) downto 0 do
  begin
    f := False;
    for j := 0 to g do
      if ((oAscending and (Self[i] >= Result[j][High(Result[j])])) or ((not oAscending) and (Self[i] <= Result[j][High(Result[j])]))) then
      begin
        f := True;
		Result[j].Supply(Self[i]);
        Break;
      end;
    if not f then
      Result[g.Increment] := [Self[i]];
  end;
  SetLength(Result, (g + 1));
end;

{==============================================================================]
  <Selip>
  @action: Decomposes an array into monotonic sub-arrays using an asymmetric, 
          semi-alternating multi-pass extraction algorithm.
  @note: 
  - Multi-pass extraction: Uses an index tracking array (`s`) to sweep and extract 
    a maximal monotonic subsequence per pass, compacting remaining unplaced 
    indices into `s` for subsequent passes.
  - Asymmetric directional veering: Reverses the remaining index queue (`s.Reverse`) 
    after evaluating passes where `(r mod 2) = 0`, alternating the traversal 
    direction across successive passes.
  - Execution order fix: Resizes the index buffer `s` and performs conditional 
    reversal prior to incrementing the pass counter `r`, ensuring exact alignment 
    between pass index evaluation and pile buffer trimming.
[==============================================================================}
function MArrayHelper.Selip(const oAscending: Boolean = True): M2DArray; overload;
var
  h, i, l, r: Integer;
  s: TIntegerArray;
begin
  l := Self.Length;
  if (l < 2) then
    Exit([Self.Cloned]);
  s := Self.Indexes();
  r := 0;
  repeat
    SetLength(Result, (Result.Length + 1));
    SetLength(Result[r], l);
    l := 0;
    h := -1;
    for i := 0 to High(Result[r]) do
      if ((h = -1) or ((oAscending and (Self[s[i]] >= Result[r][h])) or ((not oAscending) and (Self[s[i]] <= Result[r][h])))) then
        Result[r][h.Increment] := Self[s[i]]
      else
        s[l.Increase] := s[i];
    if ((s.SetSize(l) > 1) and ((r mod 2) = 0)) then
      s.Reverse;
	SetLength(Result[r.Increase], (h + 1));
  until (l = 0);
end;

{==============================================================================]
  <ToPiles>
  @action: Partitions the array into non-increasing or non-decreasing runs via patience sorting and tracks subsequence tails to identify monotonic sequences.
  @note: Uses binary search in O(n log n) time to place elements into active sorted buckets/runs based on the specified sort order.
[==============================================================================}
function MArrayHelper.ToPiles(const oAscending: Boolean = True): M2DArray; overload;
var
  i, s, g, l, h, m, p: Integer;
begin
  s := Self.Length;
  if (s < 2) then
    Exit([Self.Cloned]);
  SetLength(Result, (s + 1));
  Result[0] := [Self[0]];
  SetLength(Result[s], s);
  Result[s][0] := Self[0];
  g := 0;
  for i := 1 to (s - 1) do
  begin
    l := 0;
    h := g;
    p := (g + 1);
    while (l <= h) do
    begin
      m := ((l + h) div 2);
      if ((oAscending and (Self[i] >= Result[s][m])) or ((not oAscending) and (Self[i] <= Result[s][m]))) then
      begin
        p := m;
        h := (m - 1);
      end else
        l := (m + 1);
    end;
    if (p <= g) then
    begin
      Result[p].Supply(Self[i]);
      Result[s][p] := Self[i];
    end else
    begin
      Inc(g);
      Result[g] := [Self[i]];
      Result[s][g] := Self[i];
    end;
  end;
  SetLength(Result, (g + 1));
end;
{$ENDIF}
