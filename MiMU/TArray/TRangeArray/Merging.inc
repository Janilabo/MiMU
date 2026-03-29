{$IFDEF HELPERS}
function Merge: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Merge>
  @action: Merges overlapping/adjacent ranges into a normalized, non-overlapping set.
  @note: Creates sorted copy (by start), then folds ranges sequentially.
         Adjacent ranges (stop + 1) are merged. Uses Normalize before merge.
         Preserves original direction via Ascending flag (reverses if needed).
         Result is compacted (may be shorter than input). Does not modify Self.
         Time: O(n log n) due to sort, merge pass O(n). Requires valid ranges.
[==============================================================================}
function TRangeArrayHelper.Merge: TRangeArray; overload;
var
  S: TRangeArray;
  R: TRange;
  a: Boolean;
  i, l: Integer;
begin
  if (Self.Length <= 1) then
    Exit(Self.Copy);
  a := Self[0].Ascending;
  S := Self.Copy;
  S.SortByMinimum;
  SetLength(Result, S.Length);
  l := 0;
  R := S[0].Normalize;
  for i := 1 to High(S) do
    if (S[i].start > (R.stop + 1)) then
    begin
      if not a then
        R.Reverse;
      Result[l.Increase] := R;
      R := S[i].Normalize;
    end else
      R.stop := Max(R.stop, S[i].stop);
  if not a then
    R.Reverse;
  Result[l.Increase] := R;
  SetLength(Result, l);
end;
{$ENDIF}
