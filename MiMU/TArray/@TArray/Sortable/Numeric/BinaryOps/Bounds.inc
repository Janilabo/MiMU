{$IFDEF HELPERS}
function BinaryBoundL(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryBoundR(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryClosest(const value: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFarthest(const value: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFindClosest(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFindNearest(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFirst(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryLast(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryNear(const target: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryNearest(const target: MType; const oAscending: Boolean = True): MType; overload;
function BinaryPosL(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryPosR(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryRound(const value: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryTrunc(const value: MType; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryBoundL>
  @action: Returns Binary Search Lower Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function MArrayHelper.BinaryBoundL(const x: MType; const aAscending: Boolean = True): Integer; overload;
var
  m, o: Integer;
  r: TRange;
begin
  o := aAscending.Select(1, -1);
  r.Create(0, Self.Size);
  while r.Ascends do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := m;
  end;
  Result := r.start;
end;

{==============================================================================]
  <BinaryBoundR>
  @action: Returns Binary Search Upper Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function MArrayHelper.BinaryBoundR(const x: MType; const aAscending: Boolean = True): Integer; overload;
var
  m, o: Integer;
  r: TRange;
begin
  o := aAscending.Select(1, -1);
  r.Create(0, Self.Size);
  while r.Ascends do
  begin
    m := r.Pivot;
    if ((o * Self[m]) <= (o * x)) then
      r.start := (m + 1)
    else
      r.stop := m;
  end;
  Result := r.start;
end;

{==============================================================================]
  <BinaryClosest>
  @action: Returns the index of the element closest to the given value in the array.
  @note:
    - If the exact value exists, returns its index.
    - If the value does not exist, returns the index of the closest element.
    - Handles both ascending and descending sorted arrays (controlled by oAscending).
    - Returns -1 if the array is empty.
[==============================================================================}
function MArrayHelper.BinaryClosest(const value: MType; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  if (R.stop > -1) then
  case oAscending of
    True:
    begin
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        if (Self[M] = value) then
          Exit(M)
        else if (Self[M] < value) then
          R.start := (M + 1)
        else
          R.stop := (M - 1);
      end;
      if (R.stop < 0) then
        Result := R.start
      else if (R.start > High(Self)) then
        Result := R.stop
      else if ((Abs(Self[R.stop] - value) <= Abs(Self[R.start] - value))) then
        Result := R.stop
      else
        Result := R.start;
    end;
    False:
    begin
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        if (Self[M] = value) then
          Exit(M)
        else if (Self[M] > value) then
          R.start := (M + 1)
        else
          R.stop := (M - 1);
      end;
      if (R.stop < 0) then
        Result := R.start
      else if (R.start > High(Self)) then
        Result := R.stop
      else if ((Abs(Self[R.stop] - value) <= Abs(Self[R.start] - value))) then
        Result := R.stop
      else
        Result := R.start;
    end;
  end;
end;

{==============================================================================]
  <BinaryFarthest>
  @action: Returns the index of the array element farthest from the given value.
  @note: Compares only the first and last elements. In case of a tie (both endpoints equally far),
         `oAscending = True` selects the lower index (first element),
         `oAscending = False` selects the higher index (last element). Returns -1 for empty arrays.
[==============================================================================}
function MArrayHelper.BinaryFarthest(const value: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := High(Self);
  if (Result < 0) then
    Exit;
  if (Abs(Self[0] - value) = Abs(Self[Result] - value)) then
    Exit(IfThen(oAscending, 0, Result));
  Result := IfThen((Abs(Self[0] - value) > Abs(Self[Result] - value)), 0, Result);
end;

{==============================================================================]
  <BinaryFindClosest>
  @action: Finds the index of the element whose value is closest to the
           specified item in a sorted array using binary search.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns:
           - Index of the element whose value is nearest to `item`
           - -1 if the array is empty
         If the target lies between two elements, the one with the smaller
         absolute difference is selected.
         If both neighbors are equally close, the lower index is returned.
         Internally uses BinaryInsertPosition to locate the candidate
         position, then compares the two nearest neighbors.
[==============================================================================}
function MArrayHelper.BinaryFindClosest(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(-1);
  Result := Self.BinaryInsertPosition(item, oAscending);
  if (Result <= 0) then
    Exit(0);
  if (Result >= l) then
    Exit(l - 1);
  if not (Abs(Self[Result] - item) < Abs(Self[Result - 1] - item)) then
    Dec(Result);
end;

{==============================================================================]
  <BinaryFindNearest>
  @action: Searches the sorted array using binary search and returns the index
           of the element closest to the specified item (nearest neighbor search).
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Returns:
           0 .. Length(Self)-1 -> index of nearest element
           -1                  -> array is empty
         If an exact match exists, its index is returned.
         Otherwise, the function returns the index of the element with the
         smallest absolute difference to the target item.
[==============================================================================}
function MArrayHelper.BinaryFindNearest(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  O, D: MType;
  M: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit(-1);
  R.Create(0, High(Self));
  Result := 0;
  O := Abs(Self[R.start] - item);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    D := Abs(Self[M] - item);
    if (D < O) then
    begin
      O := D;
      Result := M;
      if (D = 0) then
        Break;
    end;
    if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryFirst>
  @action: Return the index of the first element in the sorted array
           that is greater than or equal to x.
           Works with ascending or descending order depending on aAscending.
  @note:   Returns -1 if all elements are less than x (or greater when
           searching a descending array).
[==============================================================================}
function MArrayHelper.BinaryFirst(const x: MType; const aAscending: Boolean = True): Integer; overload;
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Asceal do
  begin
    m := r.Pivot;
    case ((o * Self[m]) < (o * x)) of
      False:
      begin
        Result := m;
        r.stop := (m - 1);
      end;
      True: r.start := (m + 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryLast>
  @action: Return the index of the last element in the sorted array
           that is less than or equal to x.
           Honors the aAscending flag for array order.
  @note:   Returns -1 if all elements are greater than x (or less when
           searching a descending array).
[==============================================================================}
function MArrayHelper.BinaryLast(const x: MType; const aAscending: Boolean = True): Integer; overload;
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Asceal do
  begin
    m := r.Pivot;
    case ((o * Self[m]) > (o * x)) of
      False:
      begin
        Result := m;
        r.start := (m + 1);
      end;
      True: r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryNear>
  @action: Returns the index of the element in the sorted array whose value is
           closest to the specified target, using binary search.
  @note:
    - The array must already be sorted according to aAscending.
    - If the target exists, its index is returned.
    - If not found, the index of the nearest value (by absolute difference)
      is returned.
    - If the array is empty, returns Low(Integer).
    - If the target is outside the range, returns the nearest boundary index.
    - In case of equal distance, the lower index is preferred.
    - Time complexity: O(log n).
    - MType must be a numeric type (supports subtraction and Abs). No
      overflow-widening is performed; narrow specializations (e.g. Byte,
      SmallInt) are the caller's responsibility, consistent with other
      numeric-only Binary* methods.
[==============================================================================}
function MArrayHelper.BinaryNear(const target: MType; const aAscending: Boolean = True): Integer; overload;
var
  h, s: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit(Low(Integer));
  s := Self.BinarySpot(target, aAscending);
  if (s >= 0) then
    Exit(s);
  s := not s;
  if (s <= 0) then
    Exit(0);
  if (s > h) then
    Exit(h);
  if (Abs(target - Self[s - 1]) <= Abs(target - Self[s])) then
    Result := (s - 1)
  else
    Result := s;
end;

{==============================================================================]
  <BinaryNearest>
  @action: Returns the element in the sorted array whose value is closest to the
           specified target, using binary search to determine proximity.
  @note:
    - The array must already be sorted according to oAscending.
    - If the target exists, the exact value is returned.
    - If not found, the nearest neighbor (by absolute difference) is returned.
    - If the array is empty, returns Low(Integer).
    - Time complexity: O(log n).
    - In case of equal distance, the lower neighbor is preferred.
[==============================================================================}
function MArrayHelper.BinaryNearest(const target: MType; const oAscending: Boolean = True): MType; overload;
var
  h, p: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit(Low(Integer));
  p := Self.BinarySpot(target, oAscending);
  if (p >= 0) then
    Exit(Self[p]);
  p := not p;
  if (p = 0) then
    Exit(Self[0]);
  if (p > h) then
    Exit(Self[h]);
  if ((target - Self[p - 1]) <= (Self[p] - target)) then
    Result := Self[p - 1]
  else
    Result := Self[p];
end;

{==============================================================================]
  <BinaryPosL>
  @action: Returns L-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function MArrayHelper.BinaryPosL(const x: MType; const aAscending: Boolean = True): Integer; overload;
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  o := aAscending.Select(1, -1);
  r.Create(0, Self.Size);
  while r.Ascends do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := m;
  end;
  if ((r.start < Self.Size) and (Self[r.start] = x)) then
    Result := r.Start;
end;

{==============================================================================]
  <BinaryPosR>
  @action: Returns R-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function MArrayHelper.BinaryPosR(const x: MType; const aAscending: Boolean = True): Integer; overload;
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  o := aAscending.Select(1, -1);
  r.Create(0, Self.Size);
  while r.Ascends do
  begin
    m := r.Pivot;
    if ((o * Self[m]) <= (o * x)) then
      r.start := (m + 1)
    else
      r.stop := m;
  end;
  if ((r.start > 0) and (Self[r.start - 1] = x)) then
    Result := (r.Start - 1);
end;

{==============================================================================]
  <BinaryRound>
  @action: Returns the index of the array element nearest to `value`. If two
           elements are equidistant, returns the one with the lower index
           (tie-breaking towards floor). If no elements exist, returns -1.
  @note: The array must be sorted according to `oAscending`. This performs
         rounding to the nearest element, similar to mathematical rounding
         with ties going to the lower value.
[==============================================================================}
function MArrayHelper.BinaryRound(const value: MType; const oAscending: Boolean = True): Integer; overload;
var
  c, f: Integer;
begin
  if Self.Empty then
    Exit(-1);
  f := Self.BinaryFloor(value, oAscending);
  c := Self.BinaryCeil(value, oAscending);
  if (f = -1) then
    Exit(c);
  if ((c = -1) or (f = c))then
    Exit(f);
  Result := IfThen((Abs(Self[f] - value) <= Abs(Self[c] - value)), f, c);
end;

{==============================================================================]
  <BinaryTrunc>
  @action: Returns the index of the array element closest to `value` when
           truncating towards zero. For positive values, behaves like Floor
           (rounds down). For negative values, behaves like Ceil (rounds up
           towards zero). If no appropriate element exists, returns -1.
  @note: The array must be sorted according to `oAscending`. This mimics the
         behavior of mathematical truncation, which always rounds towards zero.
[==============================================================================}
function MArrayHelper.BinaryTrunc(const value: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if (value >= 0) then
    Result := Self.BinaryFloor(value, oAscending)
  else
    Result := Self.BinaryCeil(value, oAscending);
end;
{$ENDIF}
