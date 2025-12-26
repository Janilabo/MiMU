{$IFDEF HELPERS}
function BinaryCount(const item: TPoint): Integer; overload;
function BinaryAmount(const item: TPoint): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryCount>
  @action: Counts the total number of occurrences of a specified point in a
           sorted TPointArray using binary search for efficient lookup.
  @note: - The algorithm performs a binary search to locate one matching element,
           then scans outward in both directions to count all equal items.
         - Returns 0 if the specified point is not found.
[==============================================================================}
function TPointArrayHelper.BinaryCount(const item: TPoint): Integer; overload;
var
  M, i: Integer;
  R: TRange;
begin
  Result := 0;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Compare(item) of
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
      0:
      begin
        i := M;
        while ((i >= 0) and (Self[i] = item)) do
        begin
          Inc(Result);
          Dec(i);
        end;
        i := (M + 1);
        while ((i <= High(Self)) and (Self[i] = item)) do
        begin
          Inc(Result);
          Inc(i);
        end;
        Exit;
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryAmount>
  @action: Returns the number of elements in the sorted TPointArray that are
           equal to the specified point.
  @note: - The array must be sorted in ascending lexicographic order by X, then Y,
           consistent with TPoint.Compare.
         - Returns 0 if the point does not exist in the array.
         - Internally uses BinaryRangeOf to determine the index range.
[==============================================================================}
function TPointArrayHelper.BinaryAmount(const item: TPoint): Integer; overload;
var
  r: TRange;
begin
  r := Self.BinaryRangeOf(item);
  if (r.start > r.stop) then
    Exit(0);
  Result := ((r.stop - r.start) + 1);
end;
{$ENDIF}
