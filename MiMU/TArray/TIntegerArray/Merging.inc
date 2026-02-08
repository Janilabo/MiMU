{$IFDEF HELPERS}
function Combinate(const items: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
function Fuse(const items: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
function Fusion: TRangeArray; overload;
function Merge(const rAscending: Boolean = True): TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Combinate>
  @action: Merges the contents of Self and items into a single sorted array and removes
           duplicate values during the merge. The merge preserves the specified ordering
           (ascending or descending) and guarantees that the resulting array contains only
           unique values in correct sorted order.
  @note: Combine & Unduplicate
[==============================================================================}
function TIntegerArrayHelper.Combinate(const items: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
var
  s: TIntegerArray;
  l, a, i, j, k, v, c: Integer;
begin
  l := Self.Length;
  a := items.Size;
  if ((l = 0) and (a = 0)) then
  begin
    SetLength(Self, 0);
    Exit(0);
  end;
  s := Self.Copy;
  SetLength(Self, (l + a));
  i := 0;
  j := 0;
  k := 0;
  v := IfThen(oAscending, 2147483647, -2147483648);
  while ((i < l) or (j < a)) do
  begin
    c := 0;
    case oAscending of
      True:
      if ((i < l) and ((j >= a) or (s[i] <= items[j]))) then
        c := s[i.Increase]
      else if (j < a) then
        c := items[j.Increase]
      else
        Continue;
      False:
      if ((i < l) and ((j >= a) or (s[i] >= items[j]))) then
        c := s[i.Increase]
      else if (j < a) then
        c := items[j.Increase]
      else
        Continue;
    end;
    if ((k = 0) or (c <> v)) then
    begin
      Self[k.Increase] := c;
      v := c;
    end;
  end;
  if (k <> Self.Size) then
    SetLength(Self, k);
  Result := k;
end;

{==============================================================================]
  <Fuse>
  @action: Merge the contents of Self with the given items array using a standard merge-operation.
           Both arrays must already be sorted in the order specified by oAscending.
           The function produces a single sorted array containing all elements,
           from both sources, preserving duplicates. The merged result
           replaces Self and the final length of the array is returned.
  @note: - Both Self and items must be pre-sorted in the same ordering; the routine
           does not perform any sorting beyond the merge step.
         - All values from Self and items are preserved; no deduplication occurs.
         - The resulting array is always sorted according to oAscending.
         - Operation runs in O(n + m) time and allocates temporary storage equal to
           the length of Self.
         - The merge preserves element stability with respect to the original Self
           and items ordering.
[==============================================================================}
function TIntegerArrayHelper.Fuse(const items: TIntegerArray; const oAscending: Boolean = True): Integer; overload;
var
  l, a, i, j, k: Integer;
  s: TIntegerArray;
begin
  l := Self.Length;
  a := items.Size;
  Result := (l + a);
  if (a = 0) then
    Exit;
  if (l = 0) then
  begin
    Self := items.Copy;
    Exit;
  end;
  s := Self.Copy;
  SetLength(Self, Result);
  i := 0;
  j := 0;
  k := 0;
  case oAscending of
    True:
    while ((i < l) and (j < a)) do
      if (s[i] <= items[j]) then
        Self[k.Increase] := s[i.Increase]
      else
        Self[k.Increase] := items[j.Increase];
    False:
    while ((i < l) and (j < a)) do
      if (s[i] >= items[j]) then
        Self[k.Increase] := s[i.Increase]
      else
        Self[k.Increase] := items[j.Increase];
  end;
  while (i < l) do
    Self[k.Increase] := s[i.Increase];
  while (j < a) do
    Self[k.Increase] := items[j.Increase];
end;

{==============================================================================]
  <Fusion>
  @action: Aggregates neighboring integer values into contiguous TRange segments
           when successive elements differ by at most ±1. Each resulting range
           is normalized so that Start holds the minimum and Stop the maximum
           value observed within the fused cluster.
  @note:
    - Returns an empty TRangeArray when the source array is empty.
    - The input order is preserved; no sorting is performed.
    - Fusion condition:
      Self[i + 1] ∈ [Self[i] - 1 .. Self[i] + 1]
      This supports increasing sequences, decreasing sequences,
      and duplicate values.
    - During fusion:
        • The range is initialized with Create(Self[i]).
        • For each accepted neighbor, the index is advanced first,
          then Start/Stop are adjusted to maintain:
          Start = Min(cluster values)
          Stop  = Max(cluster values)
      This guarantees Start ≤ Stop regardless of traversal direction.
    - Initial capacity equals Length and is trimmed to the actual
      number of produced ranges.
    - Time complexity: O(n)
    - Space complexity: O(n)
[==============================================================================}
function TIntegerArrayHelper.Fusion: TRangeArray; overload;
var
  h, i, l: Integer;
begin
  if Self.Empty then
    Exit([]);
  h := High(Self);
  SetLength(Result, (h + 1));
  l := 0;
  i := 0;
  while (i <= h) do
  begin
	Result[l].Create(Self[i]);
    while ((i < h) and InRange(Self[i + 1], (Self[i] - 1), (Self[i] + 1))) do
	begin
	  Inc(i);
	  if (Self[i] < Result[l].start) then
	    Result[l].start := Self[i]
      else if (Self[i] > Result[l].stop) then
	    Result[l].stop := Self[i];
	end;
    Inc(l);
    Inc(i);
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <Merge>
  @action: Consolidates the integer values of the array into a minimal set of
           contiguous TRange instances. Adjacent values (based on ordering
           direction) are coalesced into a single range.
  @note:
    - If the array is empty, an empty TRangeArray is returned.
    - The input array is first sorted using QuickSorted according to rAscending.
    - Duplicate values are ignored.
    - Contiguity is determined by a step of:
      +1 when rAscending = True
      -1 when rAscending = False
    - Each resulting range is inclusive: Create(StartValue, EndValue).
    - Time complexity:
      O(n log n) due to sorting
    - Space complexity:
      O(n)
[==============================================================================}
function TIntegerArrayHelper.Merge(const rAscending: Boolean = True): TRangeArray; overload;
var
  i, s, e, c, d: Integer;
  a: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  a := Self.QuickSorted(rAscending);
  SetLength(Result, a.Length);
  c := 0;
  s := a[0];
  e := a[0];
  d := IfThen(rAscending, 1, -1);
  for i := 1 to High(a) do
  begin
    if (a[i] = e) then
      Continue;
    if (a[i] <> (e + d)) then
    begin
      Result[c.Increase].Create(s, e);
      s := a[i];
    end;
    e := a[i];
  end;
  Result[c.Increase].Create(s, e);
  SetLength(Result, c);
end;
{$ENDIF}
