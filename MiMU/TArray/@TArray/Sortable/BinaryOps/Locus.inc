{$IFDEF HELPERS}
function BinaryLocate(const x: MType; const aAscending: Boolean = True): TRange; overload;
function BinaryNest(const item: MType; const aAscending: Boolean = True): TRange; overload;
function BinaryPocket(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryRange(const item: MType; const aAscending: Boolean = True): TRange; overload;
function BinaryRangeOf(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinarySpanning(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinarySpanOf(const item: MType; const oAscending: Boolean = True): TRange; overload;
function BinaryWindow(const item: MType; const aAscending: Boolean = True): TRange; overload;
function BinaryZone(const item: MType; const aAscending: Boolean = True): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryLocate>
  @action: Returns Binary Search left and right index as TRange based on x value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function MArrayHelper.BinaryLocate(const x: MType; const aAscending: Boolean = True): TRange; overload;
begin
  Result.start := Self.BinaryLefty(x, aAscending);
  if (Result.start > -1) then
    Result.stop := Self.BinaryRighty(x, aAscending)
  else
    Result.stop := -1;
end;

{==============================================================================]
  <BinaryNest>
  @action: Return the index range (start..stop) of all elements whose
           value equals item. Uses binary search to find the leftmost
           and rightmost matching indexes.
  @note: Returns (-1,-1) if item is not present. Works for arrays sorted
         ascending or descending as controlled by aAscending.
[==============================================================================}
function MArrayHelper.BinaryNest(const item: MType; const aAscending: Boolean = True): TRange; overload;
begin
  Result.Create(Self.BinaryLefty(item, aAscending), Self.BinaryRighty(item, aAscending));
end;

{==============================================================================]
  <BinaryRange>
  @action: Performs a binary search to find the contiguous index range of all
           points equal to the specified item.
  @note:   Assumes the array is sorted according to TPoint_Compare.
           Returns (-1,-1) if no matching point is found.
[==============================================================================}
function MArrayHelper.BinaryPocket(const item: MType; const oAscending: Boolean = True): TRange; overload;
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
    case Self[M].Compete(item, oAscending) of
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
    case Self[M].Compete(item, oAscending) of
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
  <BinaryRange>
  @action: Returns Binary Search left and right index as TRange based on item value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
        - Locates any occurrence via binary search, then expands linearly in
          both directions to find the full equal-value window.
[==============================================================================}
function MArrayHelper.BinaryRange(const item: MType; const aAscending: Boolean = True): TRange; overload;
var
  M, H: Integer;
  R: TRange;
begin
  Result := TRange.Construct(-1, -1);
  H := High(Self);
  R.Create(0, H);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
    begin
      Result.start := M;
      Result.stop := M;
      while ((Result.start > 0) and (Self[Result.start - 1] = item)) do
        Dec(Result.start);
      while ((Result.stop < H) and (Self[Result.stop + 1] = item)) do
        Inc(Result.stop);
      Exit;
    end else if ((Self[M] < item) = aAscending) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryRangeOf>
  @action: Finds the contiguous range of a specific item in a sorted array.
  @note:
    - Fully binary search based; no linear expansion.
    - Works with arrays sorted ascending or descending.
    - Returns TRange(-1, -1) if the item is not found.
  @return: TRange containing start and stop indices of the item in the array.
[==============================================================================}
function MArrayHelper.BinaryRangeOf(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  m: Integer;
  r: TRange;
begin
  Result.Create(-1, -1);
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) of
      False:
      begin
        r.stop := (m - 1);
        if (Self[m] = item) then
          Result.start := m;
      end;
      True: r.start := (m + 1);
    end;
  end;
  if (Result.start = -1) then
    Exit;
  r.Create(Result.start, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = item) of
      True:
      begin
        Result.stop := m;
        r.start := (m + 1);
      end;
      False:
      if ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySpanning>
  @action: Finds the contiguous range (span) of a specific item in a sorted array.
  @note:
    - This function performs a binary search to find the first and last occurrences
      of the given item in the array.
    - The array must be sorted. Use `oAscending = False` if the array is sorted in descending order.
    - Returns a TRange structure representing the start and stop indices of the item.
    - If the item is not found, returns TRange(-1, -1).
  @return: TRange containing start and stop indices of the item in the array.
[==============================================================================}
function MArrayHelper.BinarySpanning(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  m: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  Result.start := -1;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = item) of
      True:
      begin
        Result.start := m;
        r.stop := (m - 1);
      end;
      False:
      if ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
  if (Result.start = -1) then
    Exit(TRange.Construct(-1, -1));
  r.start := Result.start;
  r.stop := High(Self);
  Result.stop := Result.start;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = item) of
      True:
      begin
        Result.stop := m;
        r.start := (m + 1);
      end;
      False:
      if ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySpanOf>
  @action: Finds the contiguous range (span) of a specific item in a sorted array.
  @note:
    - Performs a binary search to locate any occurrence of the item.
    - Once found, expands linearly left and right to determine the full span.
    - Works on arrays sorted ascending or descending (controlled by oAscending).
    - Returns TRange(-1, -1) if the item is not found.
  @return: TRange containing start and stop indices of the item in the array.
[==============================================================================}
function MArrayHelper.BinarySpanOf(const item: MType; const oAscending: Boolean = True): TRange; overload;
var
  m: Integer;
  r: TRange;
begin
  Result.Create(-1, -1);
  r.Create(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    case (Self[m] = item) of
      True:
      begin
        Result.start := m;
        Result.stop := m;
        while ((Result.start > 0) and (Self[Result.start - 1] = item)) do
          Dec(Result.start);
        while ((Result.stop < High(Self)) and (Self[Result.stop + 1] = item)) do
          Inc(Result.stop);
        Exit;
      end;
      False:
      if ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) then
        r.start := (m + 1)
      else
        r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryWindow>
  @action: Performs a binary search on a sorted array and returns the closed index
           interval [start, stop] containing all occurrences of <item>.
           The function determines:
            - The first index at which Self[i] = item
            - The last  index at which Self[i] = item
           Both bounds are located using independent binary searches.
  @note:
    - Self must be sorted according to <aAscending>.
    - Returns (-1, -1) if <item> is not present.
    - The resulting range contains only indices whose value equals <item>.
    - Time complexity: O(log n), where n = Length(Self).
    - No linear expansion is performed.
[==============================================================================}
function MArrayHelper.BinaryWindow(const item: MType; const aAscending: Boolean = True): TRange; overload;
var
  M, S: Integer;
  R: TRange;
begin
  Result := TRange.Construct(-1, -1);
  S := Self.Length;
  if (S = 0) then
    Exit;
  R.Create(0, (S - 1));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((Self[M] >= item) = aAscending) then
    begin
      if (Self[M] = item) then
        Result.start := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  end;
  if (Result.start = -1) then
    Exit;
  Result.stop := Result.start;
  R.Create(0, (S - 1));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((Self[M] <= item) = aAscending) then
    begin
      if (Self[M] = item) then
        Result.stop := M;
      R.start := (M + 1);
    end else
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryZone>
  @action: Returns Binary Search left and right index as TRange based on item value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
        - Runs two independent boundary searches (leftmost/rightmost equal-item
          index) without a preliminary existence probe.
[==============================================================================}
function MArrayHelper.BinaryZone(const item: MType; const aAscending: Boolean = True): TRange; overload;
var
  M: Integer;
  R: TRange;
begin
  Result.start := -1;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M] = item) of
      True:
      begin
        Result.start := M;
        R.stop := (M - 1);
      end;
      False:
      if ((Self[M] < item) = aAscending) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
  if (Result.start = -1) then
  begin
    Result.stop := -1;
    Exit;
  end;
  Result.stop := Result.start;
  R.Create(Result.start, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M] = item) of
      True:
      begin
        Result.stop := M;
        R.start := (M + 1);
      end;
      False:
      if ((Self[M] < item) = aAscending) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
end;
{$ENDIF}
