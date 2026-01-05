{$IFDEF HELPERS}
function BinaryCount(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryCount(const x: TRange; const aAscending: Boolean = True): Integer; overload;
function BinaryCountOf(const x: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryCountOf(const x: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryCountFor(const x: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryCountFor(const x: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryCounted(const x: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryCounted(const x: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryAmount(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryAmount(const x: TRange; const aAscending: Boolean = True): Integer; overload;
function BinaryQuantity(const x: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryQuantity(const x: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryTally(const x: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryTally(const x: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryLowerCount(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryHigherCount(const value: Integer; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryCount>
  @action: Binary Count function for TIntegerArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryCount(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  r: TRange;
begin
  r := Self.BinaryLocate(x, aAscending);
  Result := IfThen((r.start > -1), r.Size, 0);
end;

function TIntegerArrayHelper.BinaryCount(const x: TRange; const aAscending: Boolean = True): Integer; overload;
var
  r: TRange;
begin
  if Self.Empty then
    Exit(0);
  r := x.Normalize;
  Result := Self.BinaryLeftmost(r, aAscending);
  if (Result > -1) then
    Result := ((Self.BinaryRightmost(r, aAscending) - Result) + 1)
  else
    Result := 0;
end;

{==============================================================================]
  <BinaryCountOf>
  @action: Counts the number of occurrences of a specific integer value
           in a sorted array. Uses a single binary search to locate any
           occurrence of the value, then expands left and right to
           count contiguous occurrences.
  @note: - Assumes the array is sorted according to the `oAscending` flag.
         - Returns 0 if the array is empty or the value is not present.
         - Time complexity is O(log n + k), where k is the number of occurrences.
         - Works correctly for ascending or descending arrays.
         - This overload counts a single integer value.
[==============================================================================}
function TIntegerArrayHelper.BinaryCountOf(const x: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M, I, H: Integer;
  R: TRange;
begin
  Result := 0;
  H := High(Self);
  if (H = -1) then
    Exit;
  R.Create(0, H);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = x) then
    begin
      Result := 1;
      I := (M - 1);
      while ((I >= 0) and (Self[I.Decrease] = x)) do
        Inc(Result);
      I := (M + 1);
      while ((I <= H) and (Self[I.Increase] = x)) do
        Inc(Result);
      Exit;
    end;
    if ((oAscending and (Self[M] < x)) or ((not oAscending) and (Self[M] > x))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryCountOf>
  @action: Counts the number of elements within a specified inclusive range
           (`TRange`) in a sorted array. Performs a single binary search
           to locate any element within the range, then expands left and
           right to count all elements inside the range.
  @note: - Assumes the array is sorted according to the `oAscending` flag.
         - Returns 0 if the array is empty or no elements fall within the range.
         - The input range is normalized internally (start <= stop).
         - Time complexity is O(log n + k), where k is the number of elements in the range.
         - Works correctly for ascending or descending arrays.
         - Use this overload for ranges instead of single values.
[==============================================================================}
function TIntegerArrayHelper.BinaryCountOf(const x: TRange; const oAscending: Boolean = True): Integer; overload;
var
  M, I, H: Integer;
  R, N: TRange;
begin
  Result := 0;
  H := High(Self);
  if (H = -1) then
    Exit;
  N := x.Normalize;
  R.Create(0, H);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if InRange(Self[M], N.start, N.stop) then
    begin
      Result := 1;
      I := (M - 1);
      while ((I >= 0) and InRange(Self[I.Decrease], N.start, N.stop)) do
        Inc(Result);
      I := (M + 1);
      while ((I <= H) and InRange(Self[I.Increase], N.start, N.stop)) do
        Inc(Result);
      Exit;
    end;
    if ((oAscending and (Self[M] < N.start)) or ((not oAscending) and (Self[M] > N.stop))) then
      R.start := (M + 1)
    else if ((oAscending and (Self[M] > N.stop)) or ((not oAscending) and (Self[M] < N.start))) then
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryCountFor>
  @action: Counts the number of occurrences of a specific integer value
           in a sorted array. Performs a single binary search to locate
           any occurrence of the value, then uses **exponential ("gallop")**
           expansion left and right to efficiently count all contiguous duplicates.
  @note: - Assumes the array is sorted according to the `oAscending` flag.
         - Returns 0 if the array is empty or if the value is not present.
         - Time complexity is O(log n + log k), where k is the number of occurrences.
         - Works correctly for ascending or descending arrays.
         - Use this function instead of a linear count when duplicates may form
           large contiguous blocks.
[==============================================================================}
function TIntegerArrayHelper.BinaryCountFor(const x: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M, I, H, S: Integer;
  R: TRange;
begin
  Result := 0;
  H := High(Self);
  if (H = -1) then
    Exit;
  R.Create(0, H);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = x) then
      Break;
    case oAscending of
      True:
      if (Self[M] < x) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
      False:
      if (Self[M] > x) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
  if (Self[M] <> x) then
    Exit(0);
  Result := 1;
  S := 1;
  I := (M - 1);
  while (((I - S) >= 0) and (Self[I - S] = x)) do
    S := (S * 2);
  for I := Max(((I - S) + 1), 0) to (M - 1) do
    if (Self[I] = x) then
      Inc(Result);
  S := 1;
  I := (M + 1);
  while (((I + S) <= H) and (Self[I + S] = x)) do
    S := (S * 2);
  for I := (M + 1) to Min(((I + S) - 1), H) do
    if (Self[I] = x) then
      Inc(Result);
end;

{==============================================================================]
  <BinaryCountFor>
  @action: Counts the number of elements within a specified inclusive range
           (`TRange`) in a sorted array. Uses a **single binary search** to locate
           any element in the range, then expands **exponentially ("gallop")**
           left and right to efficiently count all contiguous elements in the range.
  @note: - Assumes the array is sorted according to the `oAscending` flag.
         - Returns 0 if the array is empty or no elements fall within the range.
         - The input range is normalized internally (start <= stop).
         - This is a hybrid approach: O(log n) for the binary search plus
           O(log k) for the exponential expansion, where k is the number of elements in the range.
         - Works correctly for ascending or descending arrays.
         - Use this overload when the range may include a large contiguous block to reduce linear expansion.
[==============================================================================}
function TIntegerArrayHelper.BinaryCountFor(const x: TRange; const oAscending: Boolean = True): Integer; overload;
var
  M, I, H, S: Integer;
  R, N: TRange;
begin
  Result := 0;
  H := High(Self);
  if (H = -1) then
    Exit;
  N := x.Normalize;
  R.Create(0, H);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if InRange(Self[M], N.start, N.stop) then
      Break;
    case oAscending of
      True:
      if (Self[M] < N.start) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
      False:
      if (Self[M] > N.stop) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
  if not InRange(Self[M], N.start, N.stop) then
    Exit(0);
  Result := 1;
  S := 1;
  I := (M - 1);
  while (((I - S) >= 0) and InRange(Self[I - S], N.start, N.stop)) do
    S := (S * 2);
  for I := Max(((I - S) + 1), 0) to (M - 1) do
    if InRange(Self[I], N.start, N.stop) then
      Inc(Result);
  S := 1;
  I := (M + 1);
  while (((I + S) <= H) and InRange(Self[I + S], N.start, N.stop)) do
    S := (S * 2);
  for I := (M + 1) to Min(((I + S) - 1), H) do
    if InRange(Self[I], N.start, N.stop) then
      Inc(Result);
end;

{==============================================================================]
  <BinaryCounted>
  @action: Counts the number of occurrences of a specific integer value within
           the sorted array.
           Uses a binary search to locate one matching element, then expands
           linearly to the left and right to count all contiguous equal values.
  @note: - The array must be sorted according to `oAscending`.
         - Returns 0 if the array is empty or the value is not present.
         - Best-case time complexity is O(log n); worst-case is O(log n + k),
           where k is the number of equal values.
         - Equality comparison is order-independent; `oAscending` is used only
           for binary search navigation.
[==============================================================================}
function TIntegerArrayHelper.BinaryCounted(const x: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M, I, H: Integer;
  R: TRange;
begin
  Result := 0;
  H := High(Self);
  if (H = -1) then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Compared(x, oAscending) of
      0:
      begin
        Result := 1;
        I := (M - 1);
        while ((I >= 0) and (Self[I.Decrease] = x)) do
          Inc(Result);
        I := (M + 1);
        while ((I <= H) and (Self[I.Increase] = x)) do
          Inc(Result);
        Exit;
      end;
      -1: R.start := (M + 1);
      1:  R.stop := (M - 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryCounted>
  @action: Counts the number of elements whose values fall within the specified
           inclusive range (`TRange`) in the sorted array.
           Performs a binary search to locate any element inside the range, then
           expands linearly to the left and right to count the full contiguous
           block of values within the range.
  @note: - The array must be sorted according to `oAscending`.
         - The input range is normalized internally (start ≤ stop).
         - Returns 0 if the array is empty or no elements fall within the range.
         - Best-case time complexity is O(log n); worst-case is O(log n + k),
           where k is the number of elements within the range.
         - Range membership is evaluated independently of sort order; ordering
           is used only to guide the binary search.
[==============================================================================}
function TIntegerArrayHelper.BinaryCounted(const x: TRange; const oAscending: Boolean = True): Integer; overload;
var
  M, H, I: Integer;
  R, N: TRange;
begin
  Result := 0;
  H := High(Self);
  if (H = -1) then
    Exit;
  N := x.Normalize;
  R.Create(0, H);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case InRange(Self[M], N.start, N.stop) of
      False:
      if (Self[M].Compared(N.stop, oAscending) > 0) then
        R.stop := (M - 1)
      else if (Self[M].Compared(N.start, oAscending) < 0) then
        R.start := (M + 1);
      True:
      begin
        Result := 1;
        I := (M - 1);
        while ((I >= 0) and InRange(Self[I.Decrease], N.start, n.Stop)) do
          Inc(Result);
        I := (M + 1);
        while ((I <= H) and InRange(Self[I.Increase], N.start, n.Stop)) do
          Inc(Result);
        Exit;
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryAmount>
  @action: Returns count of x
  @note: Alternative for BinaryCount
[==============================================================================}
function TIntegerArrayHelper.BinaryAmount(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  s: TRange;
  M, f, l: Integer;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  s.Create(0, High(Self));
  f := -1;
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case (Self[M] = x) of
      True:
      begin
        f := M;
        s.stop := (M - 1);
      end;
      False:
      if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        s.start := (M + 1)
      else
        s.stop := (M - 1);
    end;
  end;
  if (f = -1) then
    Exit(0);
  s.Create(f, High(Self));
  l := -1;
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case (Self[M] = x) of
      True:
      begin
        l := M;
        s.start := (M + 1);
      end;
      False:
      if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        s.start := (M + 1)
      else
        s.stop := (M - 1);
    end;
  end;
  Result := ((l - f) + 1);
end;

function TIntegerArrayHelper.BinaryAmount(const x: TRange; const aAscending: Boolean = True): Integer; overload;
var
  r, s: TRange;
  M, f, l: Integer;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  r := x.Normalize;
  s.Create(0, High(Self));
  f := -1;
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case InRange(Self[M], r.start, r.stop) of
      True:
      begin
        f := M;
        s.stop := (M - 1);
      end;
      False:
      if ((aAscending and (Self[M] < r.start)) or ((not aAscending) and (Self[M] > r.stop))) then
        s.start := (M + 1)
      else if ((aAscending and (Self[M] > r.stop)) or ((not aAscending) and (Self[M] < r.start))) then
        s.stop := (M - 1);
    end;
  end;
  if (f = -1) then
    Exit(0);
  s.Create(f, High(Self));
  l := -1;
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case InRange(Self[M], r.start, r.stop) of
      True:
      begin
        l := M;
        s.start := (M + 1);
      end;
      False:
      if ((aAscending and (Self[M] < r.start)) or ((not aAscending) and (Self[M] > r.stop))) then
        s.start := (M + 1)
      else if ((aAscending and (Self[M] > r.stop)) or ((not aAscending) and (Self[M] < r.start))) then
        s.stop := (M - 1);
    end;
  end;
  Result := ((l - f) + 1);
end;

{==============================================================================]
  <BinaryQuantity>
  @action: Returns the number of occurrences of a specific integer value within
           the sorted array.
           Performs a binary search to locate the first and last positions of
           the target value and computes the count as (last - first + 1).
  @note: - Assumes the array is sorted according to the `oAscending` flag.
         - Returns 0 if the array is empty or the value does not exist.
         - Time complexity is O(log n) for the search.
         - The `oAscending` parameter must match the array’s actual sort order.
[==============================================================================}
function TIntegerArrayHelper.BinaryQuantity(const x: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M, F, L, H: Integer;
  R: TRange;
begin
  H := High(Self);
  if (H = -1) then
    Exit(0);
  R.Create(0, H);
  F := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Compared(x, oAscending) of
      0:
      begin
        F := M;
        R.stop := (M - 1);
      end;
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
    end;
  end;
  if (F = -1) then
    Exit(0);
  R.Create(F, H);
  L := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Compared(x, oAscending) of
      0:
      begin
        L := M;
        R.start := (M + 1);
      end;
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
    end;
  end;
  Result := ((L - F) + 1);
end;

{==============================================================================]
  <BinaryQuantity>
  @action: Returns the number of elements within a specified inclusive range
           (`TRange`) in the sorted array.
           Performs binary searches to find the first element >= range.start
           and the last element <= range.stop, then computes the count as
           (last - first + 1).
  @note: - Assumes the array is sorted according to the `oAscending` flag.
         - Returns 0 if the array is empty or if no elements fall within the range.
         - The input range `x` is normalized internally (start <= stop).
         - Time complexity is O(log n) for each of the lower and upper bound searches.
         - The `oAscending` parameter must match the array’s actual sort order.
[==============================================================================}
function TIntegerArrayHelper.BinaryQuantity(const x: TRange; const oAscending: Boolean = True): Integer; overload;
var
  M, F, L, H: Integer;
  R, N: TRange;
begin
  H := High(Self);
  if (H = -1) then
    Exit(0);
  N := x.Normalize;
  R.Create(0, H);
  F := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((oAscending and (Self[M].Compare(N.start) >= 0)) or ((not oAscending) and (Self[M].Compare(N.stop) <= 0))) then
    begin
      F := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  end;
  if (F = -1) then
    Exit(0);
  R.Create(F, H);
  L := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((oAscending and (Self[M].Compare(N.stop) <= 0)) or ((not oAscending) and (Self[M].Compare(N.start) >= 0))) then
    begin
      L := M;
      R.start := (M + 1);
    end else
      R.stop := (M - 1);
  end;
  Result := ((L - F) + 1);
end;

{==============================================================================]
  <BinaryTally>
  @action: Counts the number of occurrences of a specific value in a sorted array
           using two binary searches to find the first and last occurrence.
  @note: - Assumes the array is sorted according to the `oAscending` flag.
         - Returns 0 if the array is empty or the value is not found.
         - Time complexity is O(log n) - performs two binary searches.
         - More efficient than linear expansion for many duplicates.
[==============================================================================}
function TIntegerArrayHelper.BinaryTally(const x: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M, F, L: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit(0);
  R.Create(0, High(Self));
  F := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M] = x) of
      True:
      begin
        F := M;
        R.stop := (M - 1);
      end;
      False:
      if ((oAscending and (Self[M] < x)) or ((not oAscending) and (Self[M] > x))) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
  if (F = -1) then
    Exit(0);
  R.Create(F, High(Self));
  L := F;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M] = x) of
      True:
      begin
        L := M;
        R.start := (M + 1);
      end;
      False:
      if ((oAscending and (Self[M] < x)) or ((not oAscending) and (Self[M] > x))) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
  Result := ((L - F) + 1);
end;

{==============================================================================]
  <BinaryTally>
  @action: Counts the number of elements within a specified inclusive range
           in a sorted array using two binary searches to find the boundaries.
  @note: - Assumes the array is sorted according to the `oAscending` flag.
         - Returns 0 if the array is empty or no elements fall within the range.
         - The input range is normalized internally (start <= stop).
         - Time complexity is O(log n) - performs two binary searches.
         - More efficient than linear expansion for large contiguous ranges.
[==============================================================================}
function TIntegerArrayHelper.BinaryTally(const x: TRange; const oAscending: Boolean = True): Integer; overload;
var
  M, F, L: Integer;
  R, N: TRange;
begin
  if Self.Empty then
    Exit(0);
  N := x.Normalize;
  R.Create(0, High(Self));
  F := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((oAscending and (Self[M] >= N.start)) or ((not oAscending) and (Self[M] <= N.stop))) then
    begin
      F := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  end;
  if (F = -1) then
    Exit(0);
  R.Create(F, High(Self));
  L := -1;
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((oAscending and (Self[M] <= N.stop)) or ((not oAscending) and (Self[M] >= N.start))) then
    begin
      L := M;
      R.start := (M + 1);
    end else
      R.stop := (M - 1);
  end;
  if (L = -1) then
    Exit(0);
  Result := ((L - F) + 1);
end;

{==============================================================================]
  <BinaryLowerCount>
  @action: Returns the number of elements in the array strictly less than `value`.
  @note: - The array must be sorted according to `oAscending` (True = ascending, False = descending).
         - Uses binary search for efficient calculation (O(log n)).
[==============================================================================}
function TIntegerArrayHelper.BinaryLowerCount(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  p, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  p := Self.BinaryBoundLeft(value, oAscending);
  if ((p = -1) or (p > (l - 1))) then
    Result := oAscending.Select(l, 0)
  else
    Result := oAscending.Select(p, (l - p));
end;

{==============================================================================]
  <BinaryHigherCount>
  @action: Returns the number of elements in the array strictly greater than `value`.
  @note: - The array must be sorted according to `oAscending` (True = ascending, False = descending).
         - Uses binary search for efficient calculation (O(log n)).
[==============================================================================}
function TIntegerArrayHelper.BinaryHigherCount(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  p, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  p := Self.BinaryBoundRight(value, oAscending);
  if ((p = -1) or (p > (l - 1))) then
    Result := oAscending.Select(0, l)
  else
    Result := oAscending.Select((l - p), p);
end;
{$ENDIF}
