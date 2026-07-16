{$IFDEF HELPERS}
function BinaryRange(const item: TPoint): TRange; overload;
function BinaryRangeOf(const item: TPoint): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryRange>
  @action: Performs a binary search to find the contiguous index range of all
           points equal to the specified item.
  @note:   Assumes the array is sorted according to TPoint_Compare.
           Returns (-1,-1) if no matching point is found.
[==============================================================================}
function TPointArrayHelper.BinaryRange(const item: TPoint): TRange; overload;
var
  M: Integer;
  R: TRange;
begin
  Result.Create(-1);
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Compare(item) of
      0:
      begin
        Result.start := M;
        R.stop := (M - 1);
      end;
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
    end;
  end;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Compare(item) of
      0:
      begin
        Result.stop := M;
        R.start := (M + 1);
      end;
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryRangeOf>
  @action: Returns the range of indices that correspond to all elements
           equal to a specified point within a sorted TPointArray.
  @note: - The array must be sorted in ascending lexicographic order by X, then Y,
           consistent with TPoint.Compare.
         - If the point is not found, Result.start > Result.stop.
         - Result.start is the index of the first element >= item.
         - Result.stop  is the index of the last element <= item.
[==============================================================================}
function TPointArrayHelper.BinaryRangeOf(const item: TPoint): TRange; overload;
begin
  Result.Create(Self.BinaryPosL(item), Self.BinaryPosR(item));
end;
{$ENDIF}
