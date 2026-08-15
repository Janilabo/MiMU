{$IFDEF HELPERS}
function BinaryAvailable(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
function BinaryContact(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
function BinaryExistent(const item: Integer; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryMember(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
function BinaryOverlaps(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
function BinaryUnavailable(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryAvailable>
  @action: Performs a classic binary search to test whether any element in the
           array lies within the specified integer range.
  @note: The input range is normalized before searching. The array must be
         sorted according to oAscending. Uses direct relational comparisons
         against the range bounds. Returns True if at least one value in the
         array falls within the range; otherwise False.
[==============================================================================}
function TIntegerArrayHelper.BinaryAvailable(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
var
  M: Integer;
  R, N: TRange;
begin
  Result := False;
  if Self.Empty then
    Exit;
  N := x.Normalize;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if InRange(Self[M], N.start, N.stop) then
        Exit(True)
      else if (Self[M] < N.start) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if InRange(Self[M], N.start, N.stop) then
        Exit(True)
      else if (Self[M] > N.stop) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryContact>
  @action: Determines whether any element exists within a specified inclusive
           range (`TRange`) in a sorted array using binary search.
  @note: - Assumes the array is sorted according to the `oAscending` flag.
         - Returns True if at least one element falls within the range, False otherwise.
         - The input range is normalized internally (start <= stop).
         - Time complexity is O(log n).
         - Works for ascending or descending arrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryContact(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
var
  M: Integer;
  R, N: TRange;
begin
  Result := False;
  R.Create(0, High(Self));
  if (R.stop = -1) then
    Exit;
  N := x.Normalize;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if InRange(Self[M], N.start, N.stop) then
      Exit(True);
    if ((oAscending and (Self[M] < N.start)) or ((not oAscending) and (Self[M] > N.stop))) then
      R.start := (M + 1)
    else if ((oAscending and (Self[M] > N.stop)) or ((not oAscending) and (Self[M] < N.start))) then
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryExistent>
  @action: Performs a binary search on the integer array to determine if a
           specified item exists. Returns True if found and provides the
           item's index via the out parameter.
  @note: Assumes the array is pre-sorted in ascending or descending order,
         depending on the oAscending flag. Uses a directional multiplier
         for handling sort order efficiently. Returns -1 in the index
         parameter when the item is not found.
[==============================================================================}
function TIntegerArrayHelper.BinaryExistent(const item: Integer; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
var
  C, D: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  D := ((Ord(oAscending) * 2) - 1);
  while (R.start <= R.stop) do
  begin
    index := R.Pivot;
    C := ((Self[index] - item) * D);
    if (C = 0) then
      Exit(True);
    if (C < 0) then
      R.start := (index + 1)
    else
      R.stop := (index - 1);
  end;
  index := -1;
  Result := False;
end;

{==============================================================================]
  <BinaryMember>
  @action: Performs a binary search to determine whether any element of the array
           falls within the specified integer range.
  @note: The input range is normalized prior to searching. The array must be
         sorted according to oAscending. Returns True if at least one element
         lies within the range; otherwise returns False. Comparison direction
         is controlled via Integer_Compared to support descending order.
[==============================================================================}
function TIntegerArrayHelper.BinaryMember(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
var
  M: Integer;
  R, N: TRange;
begin
  Result := False;
  if Self.Empty then
    Exit;
  N := x.Normalize;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if InRange(Self[M], N.start, N.stop) then
      Exit(True);
    if (Self[M].Compared(N.stop, oAscending) > 0) then
      R.stop := (M - 1)
    else if (Self[M].Compared(N.start, oAscending) < 0) then
      R.start := (M + 1);
  end;
end;

{==============================================================================]
  <BinaryOverlaps>
  @action: Performs a binary search to determine whether any element of the array
           overlaps (falls within) the specified integer range.
  @note: The input range is normalized prior to searching. The array must be
         sorted according to oAscending. Returns True if at least one element
         lies within the range; otherwise returns False. This function detects
         overlap based on value inclusion rather than structural range
         intersection.
[==============================================================================}
function TIntegerArrayHelper.BinaryOverlaps(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
var
  M: Integer;
  R, N: TRange;
begin
  R.Create(0, High(Self));
  if (R.stop = -1) then
    Exit(False);
  N := x.Normalize;
  repeat
    M := R.Pivot;
    if InRange(Self[M], N.start, N.stop) then
      Exit(True);
    if ((oAscending and (Self[M] < N.start)) or ((not oAscending) and (Self[M] > N.stop))) then
      R.start := (M + 1)
    else if ((oAscending and (Self[M] > N.stop)) or ((not oAscending) and (Self[M] < N.start))) then
      R.stop := (M - 1);
  until (R.start > R.stop);
  Result := False;
end;

{==============================================================================]
  <BinaryUnvailable>
  @action: Determines whether no elements of the array fall within the specified
           integer range using binary search semantics.
  @note: This function is a logical negation of BinaryAvailable for ranges.
         The input range is normalized by the underlying call. The array must
         be sorted according to oAscending. Returns True if no element in the
         array lies within the range; otherwise returns False.
[==============================================================================}
function TIntegerArrayHelper.BinaryUnavailable(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := not Self.BinaryAvailable(x, oAscending);
end;
{$ENDIF}
