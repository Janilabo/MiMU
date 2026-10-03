{$IFDEF HELPERS}
function BinaryCombine(const items: MArray; const aAscending: Boolean = True): MArray; overload;
function BinaryCombined(const items: MArray; const aAscending: Boolean = True): MArray; overload;
function BinaryCompound(const items: MArray; const oAscending: Boolean = True): MArray; overload;
function BinaryInterposal(const items: MArray; const oAscending: Boolean = True): MArray; overload;
function BinaryInterposed(const items: MArray; const oAscending: Boolean = True): MArray; overload;
function BinaryMerge(const items: MArray; const aAscending: Boolean = True): MArray; overload;
function BinaryMerged(const items: MArray; const aAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function BinaryJoin(const A, B: MArray; const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryJoin>
  @action: Merges two sorted arrays via binary-search placement instead of a
           linear scan. A's elements use B.BinaryLowerBound, B's use A.BinaryUpperBound,
           keeping duplicates stable.
  @note: Assumes A and B are already sorted per oAscending. O(la*log(lb) +
         lb*log(la)) — more total work than Merge2 for balanced sizes, but each
         placement is independent (useful for very uneven sizes or parallelizing).
[==============================================================================}
function BinaryJoin(const A, B: MArray; const oAscending: Boolean = True): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, (A.Length + B.Length));
  for i := 0 to High(A) do
    Result[i + B.BinaryLowerBound(A[i], oAscending)] := A[i];
  for i := 0 to High(B) do
    Result[i + A.BinaryUpperBound(B[i], oAscending)] := B[i];
end;

{==============================================================================]
  <BinaryCombine>
  @action: Merges two sorted arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function MArrayHelper.BinaryCombine(const items: MArray; const aAscending: Boolean = True): MArray; overload;
var
  k: Integer;
  s, i: TRange;
begin
  s.Create(0, High(Self));
  i.Create(0, High(items));
  k := Result.SetSize(Self.Length + items.Length);
  while ((s.start <= s.stop) and (i.start <= i.stop)) do
    if ((aAscending and (Self[s.stop] >= items[i.stop])) or ((not aAscending) and (Self[s.stop] <= items[i.stop]))) then
      Result[k.Decrement] := Self[s.stop.Decrease]
    else
      Result[k.Decrement] := items[i.stop.Decrease];
  while (s.start <= s.stop) do
    Result[k.Decrement] := Self[s.stop.Decrease];
  while (i.start <= i.stop) do
    Result[k.Decrement] := items[i.stop.Decrease];
end;

{==============================================================================]
  <BinaryCombined>
  @action: Merge two sorted arrays into one sorted array.
  @note: Both arrays must be sorted in the same order (ascending or descending).
         The result is a new array that combines both inputs, preserving order.
         Complexity: O(n + m)
[==============================================================================}
function MArrayHelper.BinaryCombined(const items: MArray; const aAscending: Boolean = True): MArray; overload;
var
  i, j, k, s, o: Integer;
begin
  s := Self.Size;
  o := items.Size;
  SetLength(Result, (s + o));
  i := 0;
  j := 0;
  k := 0;
  while ((i < s) and (j < o)) do
    if ((aAscending and (Self[i] <= items[j])) or ((not aAscending) and (Self[i] >= items[j]))) then
      Result[k.Increase] := Self[i.Increase]
    else
      Result[k.Increase] := items[j.Increase];
  while (i < s) do
    Result[k.Increase] := Self[i.Increase];
  while (j < o) do
    Result[k.Increase] := items[j.Increase];
end;

{==============================================================================]
  <BinaryCompound>
  @action: Merges two sorted arrays (Self and items) into a new sorted array,
           using TType.Compete for element comparison.
  @note:
    • Assumes both Self and items are already sorted according to oAscending.
    • Uses Compete rather than direct <=/>= comparison, so ordering follows
      whatever comparison semantics Compete defines for MType.
    • On equal elements (Compete = 0), Self's element is taken first,
      preserving stability toward Self — consistent with BinaryCombined
      and the original BinaryMerge comparison-operator variant.
    • If Result.SetSize returns < 1 (i.e. both arrays are empty), the
      function exits early with an empty Result.
    • Time complexity: O(n + m).
[==============================================================================}
function MArrayHelper.BinaryCompound(const items: MArray; const oAscending: Boolean = True): MArray; overload;
var
  i, j, k, s, o: Integer;
begin
  s := Self.Size;
  o := items.Size;
  if (Result.SetSize(s + o) < 1) then
    Exit;
  i := 0;
  j := 0;
  k := 0;
  while ((i < s) and (j < o)) do
  begin
    if (Self[i].Compete(items[j], oAscending) <= 0) then
      Result[k] := Self[i.Increase]
    else
      Result[k] := items[j.Increase];
    Inc(k);
  end;
  while (i < s) do
    Result[k.Increase] := Self[i.Increase];
  while (j < o) do
    Result[k.Increase] := items[j.Increase];
end;

{==============================================================================]
  <BinaryInterposal>
  @action: Merges an array of elements into a pre-sorted array in reverse order using binary search,
           returning a new sorted combined array.
  @note: Requires both Self and items to be sorted according to oAscending.
         Iterates backwards through items, constraining each binary search upper bound to previous insertion points,
		 and immediately places elements into the result buffer from right to left in a single memory-efficient pass.
[==============================================================================}
function MArrayHelper.BinaryInterposal(const items: MArray; const oAscending: Boolean = True): MArray; overload;
var
  n, m, k, s, l, h, q, c: Integer;
begin
  n := Self.Length;
  m := items.Length;
  if (Result.SetSize(n + m) = 0) then
    Exit;
  s := n;
  c := (n + m);
  for k := (m - 1) downto 0 do
  begin
    l := 0;
    h := s;
    while (l < h) do
    begin
      q := (l + ((h - l) div 2));
      if ((oAscending and (Self[q] <= items[k])) or ((not oAscending) and (Self[q] >= items[k]))) then
        l := (q + 1)
      else
        h := q;
    end;
    while (s > l) do
      Result[c.Decrement] := Self[s.Decrement];
    Result[c.Decrement] := items[k];
  end;
  while (s > 0) do
    Result[c.Decrement] := Self[s.Decrement];
end;

{==============================================================================]
  <BinaryInterposed>
  @action: Merges an array of elements into a pre-sorted array by using binary search to find insertion positions,
           returning a new sorted combined array.
  @note: Requires both Self and items to be sorted according to oAscending.
         Iteratively binary searches Self—leveraging monotonically advancing lower search bounds—to compute insertion offsets for items,
		 then interleave-copies both sequences into the destination buffer in a single linear pass.
[==============================================================================}
function MArrayHelper.BinaryInterposed(const items: MArray; const oAscending: Boolean = True): MArray; overload;
var
  p: TIntegerArray;
  n, m, k, l, h, q, a, c: Integer;
begin
  n := Self.Length;
  m := items.Length;
  if (Result.SetSize(n + m) = 0) then
    Exit;
  l := 0;
  for k := 0 to p.Alloc(m) do
  begin
    h := n;
    while (l < h) do
    begin
      q := (l + ((h - l) div 2));
      if ((oAscending and (Self[q] <= items[k])) or ((not oAscending) and (Self[q] >= items[k]))) then
        l := (q + 1)
      else
        h := q;
    end;
    p[k] := l;
  end;
  a := 0;
  c := 0;
  for k := 0 to (m - 1) do
  begin
    while (a < p[k]) do
      Result[c.Increase] := Self[a.Increase];
    Result[c.Increase] := items[k];
  end;
  while (a < n) do
    Result[c.Increase] := Self[a.Increase];
end;

{==============================================================================]
  <BinaryMerge>
  @action: Merges two sorted arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function MArrayHelper.BinaryMerge(const items: MArray; const aAscending: Boolean = True): MArray; overload;
var
  l: Integer;
  s, i: TRange;
begin
  l := 0;
  s.Create(0, Self.Size);
  i.Create(0, items.Size);
  SetLength(Result, (s.stop + i.stop));
  case aAscending of
    True:
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if (Self[s.start] <= items[i.start]) then
        Result[l.Increase] := Self[s.start.Increase]
      else
        Result[l.Increase] := items[i.start.Increase];
    False:
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if (Self[s.start] >= items[i.start]) then
        Result[l.Increase] := Self[s.start.Increase]
      else
        Result[l.Increase] := items[i.start.Increase];
  end;
  while (s.start < s.stop) do
    Result[l.Increase] := Self[s.start.Increase];
  while (i.start < i.stop) do
    Result[l.Increase] := items[i.start.Increase];
end;

{==============================================================================]
  <BinaryMerged>
  @action: Merges two sorted arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function MArrayHelper.BinaryMerged(const items: MArray; const aAscending: Boolean = True): MArray; overload;
var
  l: Integer;
  s, i: TRange;
begin
  l := 0;
  s.Create(0, Self.Size);
  i.Create(0, items.Size);
  SetLength(Result, (s.stop + i.stop));
  while ((s.start < s.stop) and (i.start < i.stop)) do
    if Self[s.start].Precede(items[i.start], aAscending) then
      Result[l.Increase] := Self[s.start.Increase]
    else
      Result[l.Increase] := items[i.start.Increase];
  while (s.start < s.stop) do
    Result[l.Increase] := Self[s.start.Increase];
  while (i.start < i.stop) do
    Result[l.Increase] := items[i.start.Increase];
end;
{$ENDIF}
