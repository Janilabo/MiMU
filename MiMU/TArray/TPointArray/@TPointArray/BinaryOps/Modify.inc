{$IFDEF HELPERS}
function BinaryMerge(const items: TPointArray): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryMerge>
  @action: Merges the current sorted TPointArray with another sorted TPointArray,
           producing a new sorted array.
  @note: - Both arrays must be sorted in ascending lexicographic order by X, then by Y,
           consistent with TPoint.Compare.
         - The resulting array preserves sort order.
         - Duplicate points are preserved.
[==============================================================================}
function TPointArrayHelper.BinaryMerge(const items: TPointArray): TPointArray; overload;
var
  i, j, k: Integer;
  s, o: Integer;
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
    if (Self[i].Compare(items[j]) <= 0) then
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
{$ENDIF}
