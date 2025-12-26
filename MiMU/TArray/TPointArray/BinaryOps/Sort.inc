{$IFDEF HELPERS}
function BSort(const aAscending: Boolean = True): Integer; overload;
function BSorted(const aAscending: Boolean = True): TPointArray; overload;
function BinaryInsertSorted(const oAscending: Boolean = True): TPointArray; overload;
function BinaryInsertSort(const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BSort>
  @action: Sorts the array of points in-place using the Binary Insertion Sort algorithm.
  @note: - The sorting order is determined by the 'aAscending' flag.
         - Comparison is performed using 'TPoint.Compare'.
         - Uses binary search to find the insertion position for efficiency, but
           shifting elements still makes it O(n²) in worst case.
         - Returns the total number of elements in the array after sorting.
[==============================================================================}
function TPointArrayHelper.BSort(const aAscending: Boolean = True): Integer; overload;
var
  C, i, M: Integer;
  s: TPointArray;
  R: TRange;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  s := Self.Copy;
  SetLength(Self, 1);
  for i := 1 to (Result - 1) do
  begin
    R.Create(0, High(Self));
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if aAscending then
        C := Self[M].Compare(s[i])
      else
        C := s[i].Compare(Self[M]);
      case C of
        -1: R.start := (M + 1);
        1: R.stop := (M - 1);
	    0:
	    begin
          R.start := M;
          Break;
        end;
      end;
    end;
    Insert(s[i], Self, R.start);
  end;
end;

{==============================================================================]
  <BSorted>
  @action: Returns a new sorted copy of the current point array using Binary Insertion Sort.
  @note: - The original array remains unchanged.
         - Sorting order depends on the 'aAscending' parameter.
         - Comparison uses 'TPoint_Compare' to determine ordering.
         - Efficient for small arrays, but still O(n²) due to insertion shifting.
         - Binary search minimizes comparisons when finding insertion points.
[==============================================================================}
function TPointArrayHelper.BSorted(const aAscending: Boolean = True): TPointArray; Overload;
var
  C, i, M: Integer;
  R: TRange;
begin
  if (Self.Size < 2) then
    Exit(Self.Copy);
  SetLength(Result, 1);
  Result[0] := Self[0];
  for i := 1 to High(Self) do
  begin
    R.Create(0, High(Result));
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if aAscending then
        C := Result[M].Compare(Self[i])
      else
        C := Self[i].Compare(Result[M]);
      case C of
        -1: R.start := (M + 1);
        1: R.stop := (M - 1);
	    0:
        begin
          R.start := M;
          Break;
        end;
      end;
    end;
    Insert(Self[i], Result, R.start);
  end;
end;

{==============================================================================]
  <BinaryInsertSorted>
  @action: Performs an insertion sort on a copy of the TPointArray using binary search
           to find the correct insertion position. Returns a new sorted TPointArray.
  @param: oAscending - Boolean indicating sort order. True = ascending (top-to-bottom, left-to-right),
                       False = descending (bottom-to-top, right-to-left).
  @note: The original array is not modified. Sorting is based on scanline order:
         first by Y coordinate, then by X if Y values are equal.
[==============================================================================}
function TPointArrayHelper.BinaryInsertSorted(const oAscending: Boolean = True): TPointArray; overload;
var
  K: TPoint;
  i, j, L, R, M, P: Integer;
begin
  Result := Self.Copy;
  for i := 1 to High(Result) do
  begin
    K := Result[i];
    L := 0;
    R := (i - 1);
    while (L <= R) do
    begin
      M := (L + ((R - L) div 2));
      if K.Lower(Result[M], oAscending) then
        R := (M - 1)
      else
        L := (M + 1);
    end;
    P := L;
    j := (i - 1);
    while (j >= P) do
      Result[j + 1] := Result[j.Decrease];
    Result[P] := K;
  end;
end;

{==============================================================================]
  <BinaryInsertSort>
  @action: Sorts the current TPointArray in-place using insertion sort with binary search
           to find the insertion position.
  @param: oAscending - Boolean indicating sort order. True = ascending (top-to-bottom, left-to-right),
                       False = descending (bottom-to-top, right-to-left).
  @return: Returns the length of the array after sorting (same as Length(Self)).
  @note: Sorting is done in scanline order: first by Y coordinate, then by X if Y values are equal.
[==============================================================================}
function TPointArrayHelper.BinaryInsertSort(const oAscending: Boolean = True): Integer; overload;
var
  K: TPoint;
  i, j, L, R, M, P: Integer;
begin
  Result := Self.Size;
  for i := 1 to (Result - 1) do
  begin
    K := Self[i];
    L := 0;
    R := (i - 1);
    while (L <= R) do
    begin
      M := (L + ((R - L) div 2));
      if K.Lower(Self[M], oAscending) then
        R := (M - 1)
      else
        L := (M + 1);
    end;
    P := L;
    j := (i - 1);
    while (j >= P) do
      Self[j + 1] := Self[j.Decrease];
    Self[P] := K;
  end;
end;
{$ENDIF}
