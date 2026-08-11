{$IFDEF HELPERS}
function BinaryBoundL(const x: Double; const aAscending: Boolean = True): Integer;
function BinaryBoundR(const x: Double; const aAscending: Boolean = True): Integer;
function BinaryClosest(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryFarthest(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryFindFirst(const range: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryFindLast(const range: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryFirst(const x: Double; const aAscending: Boolean = True): Integer; overload;
function BinaryLast(const x: Double; const aAscending: Boolean = True): Integer; overload;
function BinaryPosL(const x: Double; const aAscending: Boolean = True): Integer;
function BinaryPosR(const x: Double; const aAscending: Boolean = True): Integer;
function BinaryRound(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer;
function BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer;
function BinaryTrunc(const value: Double; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryBoundL>
  @action: Returns Binary Search Lower Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryBoundL(const x: Double; const aAscending: Boolean = True): Integer;
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
function TDoubleArrayHelper.BinaryBoundR(const x: Double; const aAscending: Boolean = True): Integer;
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
function TDoubleArrayHelper.BinaryClosest(const value: Double; const oAscending: Boolean = True): Integer; overload;
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
function TDoubleArrayHelper.BinaryFarthest(const value: Double; const oAscending: Boolean = True): Integer; overload;
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
  @action: Executes a binary search to locate the first element within the
           specified numeric range (`range.start`..`range.stop`) and returns its
           index. Returns -1 if no element falls within that range.

  @note:   The comparison is against element values, not array index positions.
           The search space is the full array; `range` specifies the acceptable
           value interval. The array must be sorted according to `oAscending`.
[==============================================================================}
function TDoubleArrayHelper.BinaryFindFirst(const range: TRange; const oAscending: Boolean = True): Integer; overload;
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
  @action: Executes a binary search to locate the last element whose value falls
           within the given numeric range (`range.start`..`range.stop`) and
           returns its index. Returns -1 when no element matches.

  @note:   Elements are evaluated by their value, not their position. The array
           must be sorted in accordance with `oAscending`. The overload identifies
           the last qualifying value relative to the sorted order.
[==============================================================================}
function TDoubleArrayHelper.BinaryFindLast(const range: TRange; const oAscending: Boolean = True): Integer; overload;
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
function TDoubleArrayHelper.BinaryFirst(const x: Double; const aAscending: Boolean = True): Integer; overload;
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
function TDoubleArrayHelper.BinaryLast(const x: Double; const aAscending: Boolean = True): Integer; overload;
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
  <BinaryPosL>
  @action: Returns L-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryPosL(const x: Double; const aAscending: Boolean = True): Integer;
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
function TDoubleArrayHelper.BinaryPosR(const x: Double; const aAscending: Boolean = True): Integer;
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
function TDoubleArrayHelper.BinaryRound(const value: Double; const oAscending: Boolean = True): Integer; overload;
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
function TDoubleArrayHelper.BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer;
var
  m, o: Integer;
  f, r: TRange;
begin
  Result := -1;
  f := x.Normalize;
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while r.Asceal do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * f.start)) then
      r.start := (m + 1)
    else if ((o * Self[m]) > (o * f.stop)) then
      r.stop := (m - 1)
    else
    begin
      Result := m;
      r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySearchL>
  @action: Binary Search which supports TRange search, uses last match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer;
var
  m, o: Integer;
  f, r: TRange;
begin
  Result := -1;
  f := x.Normalize;
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while r.Asceal do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * f.start)) then
      r.start := (m + 1)
    else if ((o * Self[m]) > (o * f.stop)) then
      r.stop := (m - 1)
    else
    begin
      Result := m;
      r.start := (m + 1);
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
function TDoubleArrayHelper.BinaryTrunc(const value: Double; const oAscending: Boolean = True): Integer; overload;
begin
  if (value >= 0) then
    Result := Self.BinaryFloor(value, oAscending)
  else
    Result := Self.BinaryCeil(value, oAscending);
end;
{$ENDIF}
