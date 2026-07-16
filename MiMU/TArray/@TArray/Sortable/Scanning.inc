{$IFDEF HELPERS}
function Hits(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function HitsOf(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
function Where(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Hits>
  @action: Returns the indices of elements in Self whose values occur in a given set
  @note: - Self must be sorted according to oAscending
         - items are internally sorted before evaluation
         - The result contains indices into Self, not the matching values
         - Multiple equal values in Self produce multiple hits
         - Returns an empty array if Self or items is empty
         - Time complexity: O(N + M), where N = Length(Self) and M = Length(items)
[==============================================================================}
function MArrayHelper.Hits(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  s: MArray;
  h, i, j, k, l: Integer;
begin
  h := High(items);
  l := Self.Length;
  if ((l = 0) or (h = -1)) then
    Exit([]);
  SetLength(Result, l);
  s := items.QuickSorted(oAscending);
  i := 0;
  j := 0;
  k := 0;
  while ((i < l) and (j <= h)) do
  case (Self[i] = s[j]) of
    True:
    begin
      Result[k.Increase] := i;
      Inc(i);
      Inc(j);
    end;
	False:
    if ((Self[i] < s[j]) = oAscending) then
      Inc(i)
    else
      Inc(j);
  end;
  SetLength(Result, k);
end;

{==============================================================================]
  <HitsOf>
  @action: Performs a linear, merge-style comparison between the current array
           (`Self`) and the supplied array `items`, returning the indices in `Self`
           where matching values are found.
           Both arrays are traversed in order. When `Self[i]` equals `items[j]`,
           the index `i` is recorded as a hit and the scan continues. The result
           therefore contains positions within `Self` corresponding to values that
           also exist in `items`.
  @note:
    - Both `Self` and `items` must be sorted according to the order specified
      by `oAscending`; otherwise, the comparison logic is invalid.
    - If either array is empty, the function returns an empty array.
    - Each successful comparison advances the `items` index; therefore,
      duplicate values in `items` are matched at most once.
    - The maximum number of hits is limited to the minimum length of the two
      arrays.
    - This function runs in linear time O(n + m) and is more efficient than
      repeated binary searches for large, sorted inputs.
[==============================================================================}
function MArrayHelper.HitsOf(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, j, k: Integer;
begin
  if (Self.Empty or items.Empty) then
    Exit([]);
  SetLength(Result, Min(Self.Length, items.Length));
  i := 0;
  j := 0;
  k := 0;
  while ((i <= High(Self)) and (j <= High(items))) do
  case (Self[i] = items[j]) of
    True:
    begin
      Result[k] := i;
      Inc(k);
      Inc(j);
    end;
    False:
    if ((Self[i] < items[j]) = oAscending) then
      Inc(i)
    else
      Inc(j);
  end;
  SetLength(Result, k);
end;

{==============================================================================]
  <Where>
  @action: Performs batch membership index scanning between the current array and
           a query collection using a merge-style binary traversal.
           Both arrays are sorted according to the specified ordering, and the
           algorithm advances two pointers to efficiently identify matching values.
           Returns the list of indices in the current array where elements exist
           in the `items` collection.
  @note:
    - The query array `items` is internally sorted before scanning.
    - This algorithm combines sorting and linear merge traversal.
    - Duplicate matches may produce multiple indices in the result.
    - Non-existent elements are not included in the output.
    - Time complexity is approximately:
        O(n + m log m), where:
            n = length(Self),
            m = length(items)
    - Requires monotonic ordering consistency with `oAscending`.
    - If either array is empty, returns an empty array.
[==============================================================================}
function MArrayHelper.Where(const items: MArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, l, x, y, z, c: Integer;
  s: MArray;
begin
  l := Self.Length;
  if (items.Empty or (l = 0)) then
    Exit([]);
  s := items.QuickSorted(oAscending);
  z := High(s);
  SetLength(Result, l);
  x := 0;
  y := 0;
  c := 0;
  while ((x < l) and (y <= z)) do
    if (Self[x] = s[y]) then
    begin
      Result[c] := x;
      Inc(c);
      Inc(x);
    end else if ((oAscending and (Self[x] < s[y])) or ((not oAscending) and (Self[x] > s[y]))) then
      Inc(x)
    else
      Inc(y);
  SetLength(Result, c);
end;
{$ENDIF}