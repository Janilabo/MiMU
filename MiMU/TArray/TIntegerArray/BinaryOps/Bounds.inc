{$IFDEF HELPERS}
function BinaryBoundL(const x: Integer; const aAscending: Boolean = True): Integer;
function BinaryBoundLeft(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryBoundR(const x: Integer; const aAscending: Boolean = True): Integer;
function BinaryBoundRight(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryCeil(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryClosest(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryFarthest(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryFindFirst(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryFindFirst(const range: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryFindLast(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryFindLast(const range: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryFirst(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryFloor(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryLast(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryLeftmost(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryLeftmost(const x: TRange; const aAscending: Boolean = True): Integer; overload;
function BinaryLowerBound(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryNear(const target: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryNearest(const target: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryPosL(const x: Integer; const aAscending: Boolean = True): Integer;
function BinaryPosR(const x: Integer; const aAscending: Boolean = True): Integer;
function BinaryRightmost(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryRightmost(const x: TRange; const aAscending: Boolean = True): Integer; overload;
function BinaryRound(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer;
function BinarySearchFirst(const value: Integer; const aAscending: Boolean = True): Integer; overload;
function BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer;
function BinarySearchLast(const value: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryTrunc(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryUpperBound(const x: Integer; const aAscending: Boolean = True): Integer; overload;

{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryBoundL>
  @action: Returns Binary Search Lower Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundL(const x: Integer; const aAscending: Boolean = True): Integer;
var
  m, o: Integer;
  r: TRange;
begin
  o := aAscending.Select(1, -1);
  r.Create(0, Self.Size);
  while r.Grows do
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
  <BinaryBoundLeft>
  @action: Finds the left boundary index for the given value in the array.
  @note: Returns the index of the first element greater than or equal to the value for ascending arrays,
         or the first element less than or equal for descending arrays.
         If all elements are smaller/larger, returns Length(Self).
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundLeft(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Size;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < value) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > value) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryBoundR>
  @action: Returns Binary Search Upper Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundR(const x: Integer; const aAscending: Boolean = True): Integer;
var
  m, o: Integer;
  r: TRange;
begin
  o := aAscending.Select(1, -1);
  r.Create(0, Self.Size);
  while r.Grows do
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
  <BinaryBoundRight>
  @action: Finds the right boundary index for the given value in the array.
  @note: Returns the index of the first element strictly greater than the value for ascending arrays,
         or strictly smaller for descending arrays.
         If all elements satisfy the condition, returns Length(Self).
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundRight(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Size;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] <= value) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] >= value) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryCeil>
  @action: Returns the index of the smallest array element that is greater than
           or equal to `value`. If no such element exists, returns -1.
  @note: The array must be sorted according to `oAscending`. For ascending
         order, this corresponds to the mathematical ceiling. For descending
         order, the search logic is inverted but the resulting index still
         identifies the nearest upper-or-equal bound with respect to `value`.
[==============================================================================}
function TIntegerArrayHelper.BinaryCeil(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < value) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > value) of
        False:
        begin
          Result := M;
          R.stop := (M - 1);
        end;
        True: R.start := (M + 1);
      end;
    end;
  end;
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
function TIntegerArrayHelper.BinaryClosest(const value: Integer; const oAscending: Boolean = True): Integer; overload;
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
function TIntegerArrayHelper.BinaryFarthest(const value: Integer; const oAscending: Boolean = True): Integer; overload;
begin
  Result := High(Self);
  if (Result < 0) then
    Exit;
  if (Abs(Self[0] - value) = Abs(Self[Result] - value)) then
    Exit(IfThen(oAscending, 0, Result));
  Result := IfThen((Abs(Self[0] - value) > Abs(Self[Result] - value)), 0, Result);
end;

{==============================================================================]
  <BinaryFindFirst>
  @action: Performs a binary search on the entire array and returns the index of
           the first occurrence of `value`. If the value is not present,
           returns -1.

  @note:   Assumes the array is pre-sorted according to `oAscending`. The
           “first” occurrence corresponds to the lowest index in an ascending
           array or the highest index in a descending array.
[==============================================================================}
function TIntegerArrayHelper.BinaryFindFirst(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < value) of
        False:
        begin
          R.stop := (M - 1);
          if (Self[M] = value) then
            Result := M;
        end;
        True: R.start := (M + 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > value) of
        False:
        begin
          R.stop := (M - 1);
          if (Self[M] = value) then
            Result := M;
        end;
        True: R.start := (M + 1);
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryFindFirst>
  @action: Executes a binary search to locate the first element within the
           specified numeric range (`range.start`..`range.stop`) and returns its
           index. Returns -1 if no element falls within that range.

  @note:   The comparison is against element values, not array index positions.
           The search space is the full array; `range` specifies the acceptable
           value interval. The array must be sorted according to `oAscending`.
[==============================================================================}
function TIntegerArrayHelper.BinaryFindFirst(const range: TRange; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  N, R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  if (R.stop > -1) then
  begin
    N := range.Normalize;
    case oAscending of
      True:
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] < N.start) of
          False:
          begin
            R.stop := (M - 1);
            if InRange(Self[M], N.start, N.stop) then
              Result := M;
          end;
          True: R.start := (M + 1);
        end;
      end;
      False:
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] > N.stop) of
          False:
          begin
            R.stop := (M - 1);
            if InRange(Self[M], N.start, N.stop) then
              Result := M;
          end;
          True: R.start := (M + 1);
        end;
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryFindLast>
  @action: Performs a binary search on the entire array and returns the index of
           the last occurrence of `value`. If the value is not present,
           returns -1.

  @note:   Assumes the array is sorted according to `oAscending`. The “last”
           occurrence corresponds to the highest index in an ascending array or
           the lowest index in a descending array.
[==============================================================================}
function TIntegerArrayHelper.BinaryFindLast(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > value) of
        False:
        begin
          R.start := (M + 1);
          if (Self[M] = value) then
            Result := M;
        end;
        True: R.stop := (M - 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < value) of
        False:
        begin
          R.start := (M + 1);
          if (Self[M] = value) then
            Result := M;
        end;
        True: R.stop := (M - 1);
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryFindLast>
  @action: Executes a binary search to locate the last element whose value falls
           within the given numeric range (`range.start`..`range.stop`) and
           returns its index. Returns -1 when no element matches.

  @note:   Elements are evaluated by their value, not their position. The array
           must be sorted in accordance with `oAscending`. The overload identifies
           the last qualifying value relative to the sorted order.
[==============================================================================}
function TIntegerArrayHelper.BinaryFindLast(const range: TRange; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  N, R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  if (R.stop > -1) then
  begin
    N := range.Normalize;
    case oAscending of
      True:
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] > N.stop) of
          False:
          begin
            R.start := (M + 1);
            if InRange(Self[M], N.start, N.stop) then
              Result := M;
          end;
          True: R.stop := (M - 1);
        end;
      end;
      False:
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] < N.start) of
          False:
          begin
            R.start := (M + 1);
            if InRange(Self[M], N.start, N.stop) then
              Result := M;
          end;
          True: R.stop := (M - 1);
        end;
      end;
    end;
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
function TIntegerArrayHelper.BinaryFirst(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Ascending do
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
  <BinaryFloor>
  @action: Returns the index of the greatest array element that is less than or
           equal to `value`. If no such element exists, returns -1.
  @note: The array must be sorted according to `oAscending`. For ascending
         order, this corresponds to the mathematical floor. For descending
         order, the search logic is reversed but the returned index still
         represents the element whose value is the nearest lower-or-equal
         bound relative to `value`.
[==============================================================================}
function TIntegerArrayHelper.BinaryFloor(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] > value) of
        False:
        begin
          Result := M;
          R.start := (M + 1);
        end;
        True: R.stop := (M - 1);
      end;
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      case (Self[M] < value) of
        False:
        begin
          Result := M;
          R.start := (M + 1);
        end;
        True: R.stop := (M - 1);
      end;
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
function TIntegerArrayHelper.BinaryLast(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Ascending do
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
  <BinaryLeftmost>
  @action: Finds the first index where the array value is greater than or equal to x
           (ascending) or less than or equal to x (descending).
  @note:
    - Returns -1 if no element satisfies the condition.
    - Useful for “leftmost occurrence” searches.
    - Equivalent to BinaryLowerBound but returns -1 when not found instead of Length(Self).
[==============================================================================}
function TIntegerArrayHelper.BinaryLeftmost(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case aAscending of
      True:
      if (Self[M] >= x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
      False:
      if (Self[M] <= x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryLeftmost>
  @action: Searches the integer array for the first (lowest-index) element whose value lies within the specified range.
           The search uses a binary-search strategy under the assumption that the array is sorted either ascending or descending.
           If a matching element is found, the index of the earliest such occurrence is returned; otherwise the function returns –1.
  @note: After locating any in-range element, the routine performs a backward scan to reach the earliest contiguous match.
[==============================================================================}
function TIntegerArrayHelper.BinaryLeftmost(const x: TRange; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  r, s: TRange;
begin
  if Self.Empty then
    Exit(-1);
  r := x.Normalize;
  s.Create(0, High(Self));
  if TRange.Construct(Self[0], Self[s.stop]).Contains(r) then
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    if InRange(Self[M], r.start, r.stop) then
    begin
      while ((M > 0) and InRange(Self[M - 1], r.start, r.stop)) do
        Dec(M);
      Exit(M);
    end;
    if ((aAscending and (r.stop < Self[M])) or ((not aAscending) and (r.stop > Self[M]))) then
      s.stop := (M - 1)
    else if ((aAscending and (r.start > Self[M])) or ((not aAscending) and (r.start < Self[M]))) then
      s.start := (M + 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinaryLowerBound>
  @action: Finds the first index where the array value is greater than or equal to x
           (ascending) or less than or equal to x (descending).
  @note:
    - Returns Length(Self) if no element satisfies the condition.
    - Equivalent to std::lower_bound in C++.
    - Works correctly for arrays sorted either ascending or descending.
[==============================================================================}
function TIntegerArrayHelper.BinaryLowerBound(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Size;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case aAscending of
      True:
      if (Self[M] >= x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
      False:
      if (Self[M] <= x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryNear>
  @action: Returns the index of the element in the sorted array whose value is
           closest to the specified target, using binary search.
  @note:
    - The array must already be sorted according to oAscending.
    - If the target exists, its index is returned.
    - If not found, the index of the nearest value (by absolute difference)
      is returned.
    - If the array is empty, returns Low(Integer).
    - If the target is outside the range, returns the nearest boundary index.
    - In case of equal distance, the lower index is preferred.
    - Time complexity: O(log n).
    - Uses Int64 arithmetic to prevent overflow during difference calculation.
[==============================================================================}
function TIntegerArrayHelper.BinaryNear(const target: Integer; const oAscending: Boolean = True): Integer; overload;
var
  h, s: Integer;
  p, c: Int64;
begin
  h := High(Self);
  if (h = -1) then
    Exit(Low(Integer));
  s := Self.BinarySpot(target, oAscending);
  if (s >= 0) then
    Exit(s);
  s := not s;
  if (s <= 0) then
    Exit(0);
  if (s > h) then
    Exit(h);
  if (Abs(Int64(target) - Self[s - 1]) <= Abs(Int64(target) - Self[s])) then
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
function TIntegerArrayHelper.BinaryNearest(const target: Integer; const oAscending: Boolean = True): Integer; overload;
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
function TIntegerArrayHelper.BinaryPosL(const x: Integer; const aAscending: Boolean = True): Integer;
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  o := aAscending.Select(1, -1);
  r.Create(0, Self.Size);
  while r.Grows do
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
function TIntegerArrayHelper.BinaryPosR(const x: Integer; const aAscending: Boolean = True): Integer;
var
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  o := aAscending.Select(1, -1);
  r.Create(0, Self.Size);
  while r.Grows do
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
  <BinaryRightmost>
  @action: Finds the last index where the array value is less than or equal to x
           (ascending) or greater than or equal to x (descending).
  @note:
    - Returns -1 if no element satisfies the condition.
    - Useful for “rightmost occurrence” searches.
    - Differs from BinaryUpperBound: includes elements equal to x.
[==============================================================================}
function TIntegerArrayHelper.BinaryRightmost(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case aAscending of
      True:
      if (Self[M] <= x) then
      begin
        Result := M;
        R.start := (M + 1);
      end else
        R.stop := (M - 1);
      False:
      if (Self[M] >= x) then
      begin
        Result := M;
        R.start := (M + 1);
      end else
        R.stop := (M - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySearch>
  @action: Searches the integer array for the last (highest-index) element whose value lies within the specified range.
           The operation uses a binary-search strategy based on the assumption that the array is sorted either ascending or descending.
           If a matching element is found, the index of the latest such occurrence is returned; otherwise the function returns –1.
  @note: After detecting any in-range element, the routine performs a forward scan to reach the final contiguous match.
[==============================================================================}
function TIntegerArrayHelper.BinaryRightmost(const x: TRange; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  r, s: TRange;
begin
  if Self.Empty then
    Exit(-1);
  r := x.Normalize;
  s.Create(0, High(Self));
  if TRange.Construct(Self[0], Self[s.stop]).Contains(r) then
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    if InRange(Self[M], r.start, r.stop) then
    begin
      while ((M < s.stop) and InRange(Self[M + 1], r.start, r.stop)) do
        Inc(M);
      Exit(M);
    end;
    if ((aAscending and (r.stop < Self[M])) or ((not aAscending) and (r.stop > Self[M]))) then
      s.stop := (M - 1)
    else if ((aAscending and (r.start > Self[M])) or ((not aAscending) and (r.start < Self[M]))) then
      s.start := (M + 1);
  end;
  Result := -1;
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
function TIntegerArrayHelper.BinaryRound(const value: Integer; const oAscending: Boolean = True): Integer; overload;
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
  <BinarySearchF>
  @action: Binary Search which supports TRange search, uses first match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer;
var
  m, o: Integer;
  f, r: TRange;
begin
  Result := -1;
  f := x.Normalize;
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while r.Ascending do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * f.start)) then
      r.start := (m + 1)
    else
      if ((o * Self[m]) > (o * f.stop)) then
        r.stop := (m - 1)
    else
    begin
      Result := m;
      r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySearchFirst>
  @action: Performs a binary search to find the first (lowest) index of a specified
           integer value within a sorted TIntegerArray.
  @note: - The array must be sorted in ascending order.
         - If the value occurs multiple times, the index of its first occurrence is returned.
         - If the value is not found, returns -1.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchFirst(const value: Integer; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  Result := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M] = value) of
      True:
      begin
        Result := M;
        R.stop := (M - 1);
      end;
      False:
      if ((aAscending and (Self[M] < value)) or ((not aAscending) and (Self[M] > value))) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySearchL>
  @action: Binary Search which supports TRange search, uses last match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer;
var
  m, o: Integer;
  f, r: TRange;
begin
  Result := -1;
  f := x.Normalize;
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while r.Ascending do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * f.start)) then
      r.start := (m + 1)
    else
      if ((o * Self[m]) > (o * f.stop)) then
        r.stop := (m - 1)
      else
      begin
        Result := m;
        r.start := (m + 1);
      end;
  end;
end;

{==============================================================================]
  <BinarySearchLast>
  @action: Performs a binary search to find the last (highest) index of a specified
           integer value within a sorted TIntegerArray.
  @note: - The array must be sorted in ascending order.
         - If the value occurs multiple times, the index of its last occurrence is returned.
         - If the value is not found, returns -1.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchLast(const value: Integer; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  Result := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M] = value) of
      True:
      begin
        Result := M;
        R.start := (M + 1);
      end;
      False:
      if ((aAscending and (Self[M] < value)) or ((not aAscending) and (Self[M] > value))) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
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
function TIntegerArrayHelper.BinaryTrunc(const value: Integer; const oAscending: Boolean = True): Integer; overload;
begin
  if (value >= 0) then
    Result := Self.BinaryFloor(value, oAscending)
  else
    Result := Self.BinaryCeil(value, oAscending);
end;

{==============================================================================]
  <BinaryUpperBound>
  @action: Finds the first index where the array value is strictly greater than x
           (ascending) or strictly less than x (descending).
  @note:
    - Returns Length(Self) if no element satisfies the condition.
    - Equivalent to std::upper_bound in C++.
    - Works correctly for arrays sorted either ascending or descending.
[==============================================================================}
function TIntegerArrayHelper.BinaryUpperBound(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := Self.Size;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case aAscending of
      True:
      if (Self[M] > x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
      False:
      if (Self[M] < x) then
      begin
        Result := M;
        R.stop := (M - 1);
      end else
        R.start := (M + 1);
    end;
  end;
end;
{$ENDIF}
