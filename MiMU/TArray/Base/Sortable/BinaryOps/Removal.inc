{$IFDEF HELPERS}
function BinaryRemoveAll(const items: MArray; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryRemoveAll>
  @action: Removes all elements from Self that also appear in the items array,
           modifying Self in place using a binary-style merge scan.
  @param: items      – Sorted array containing values to remove from Self.
  @param: oAscending  – Sort order of both arrays:
                        True  = arrays are sorted ascending (default)
                        False = arrays are sorted descending
  @return: The number of elements removed from Self.
  @note:
    - Both Self and items must already be sorted according to oAscending.
      If the ordering differs, the result is undefined.
    - Performs an in-place removal using a two-pointer linear scan.
      Time complexity: O(L + T), where L = Length(Self) and T = Length(target).
    - The array capacity is reused during compaction, then truncated to the
      new length at the end.
    - If no elements are removed, Self remains unchanged and the function
      returns 0.
    - Duplicate values in Self that match items values will all be removed.
[==============================================================================}
function MArrayHelper.BinaryRemoveAll(const items: MArray; const oAscending: Boolean = True): Integer; overload;
var
  i, j, l, t, r: Integer;
begin
  t := items.Length;
  if (t = 0) then
    Exit(0);
  l := Self.Length;
  i := 0;
  j := 0;
  Result := 0;
  while (i < l) do
    if ((j < t) and (Self[i] = items[j])) then
      Inc(i)
    else if ((j < t) and ((oAscending and (Self[i] > items[j])) or ((not oAscending) and (Self[i] < items[j])))) then
      Inc(j)
    else
      Self[Result.Increase] := Self[i.Increase];
  if (l = Result) then
    Exit(0);
  SetLength(Self, Result);
  Result := (l - Result);
end;
{$ENDIF}