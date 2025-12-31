{$IFDEF HELPERS}
function BinaryContains(const x: Integer; const aAscending: Boolean = True): Boolean;
function BinaryFit(const value: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryUnfit(const value: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryIncludes(const value: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryExcludes(const value: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryExistent(const item: Integer; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryExists(const value: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryContact(const x: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryContact(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
function BinaryMember(const x: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryMember(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
function BinaryAvailable(const x: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryAvailable(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
function BinaryUnavailable(const x: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryUnavailable(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
function BinaryOverlaps(const x: Integer; const oAscending: Boolean = True): Boolean; overload;
function BinaryOverlaps(const x: TRange; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryContains>
  @action: Binary Contains function for TIntegerArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryContains(const x: Integer; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryContains}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryContains}

function TIntegerArrayHelper.BinaryExists(const value: Integer; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryExists}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryExists}

{==============================================================================]
  <BinaryFit>
  @action: Returns True if the specified value falls within the sortable domain
           represented by the current array. In other words, it verifies that
           the value is within the inclusive bounds defined by the first and
           last elements of the array, assuming that the array is sorted in the
           direction indicated by oAscending.
  @note: This function does not perform a binary search. It simply checks
         whether the value is eligible for a binary lookup or insertion
         attempt. For empty arrays, the function always returns False. When
         oAscending = False, the comparison logic is inverted to support
         descending-sorted arrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryFit(const value: Integer; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryFit}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFit}

{==============================================================================]
  <BinaryUnfit>
  @action: Returns True if the specified value is outside the inclusive bounds
           of the array, or if the array is empty. This indicates that the
           value cannot exist in the array and is not a candidate for a binary
           search within the current bounds.
  @note: This routine is essentially the logical inverse of BinaryFit. It is
         useful as a pre-check before performing binary search or before
         attempting bounded insertion logic. When oAscending = False, the
         boundary comparisons are reversed to support descending-sorted
         arrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryUnfit(const value: Integer; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryUnfit}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryUnfit}

{==============================================================================]
  <BinaryIncludes>
  @action: Determines whether the specified value exists in this array by using
           a binary search. The array is assumed to be pre-sorted in the order
           specified by oAscending.
  @note: Performs boundary checks before invoking the binary search for
         efficiency. Returns True only if the array is non-empty, the value
         lies within the array’s sorted bounds, and the binary search locates
         the element.
[==============================================================================}
function TIntegerArrayHelper.BinaryIncludes(const value: Integer; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryIncludes}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryIncludes}

{==============================================================================]
  <BinaryExcludes>
  @action: Determines whether the specified value does not exist in this array
           by using a binary search. The array is assumed to be pre-sorted in
           the order specified by oAscending.
  @note: Performs boundary checks before invoking the binary search. Returns
         True if the array is empty, if the value lies outside the array’s
         sorted bounds, or if the binary search fails to locate the value.
[==============================================================================}
function TIntegerArrayHelper.BinaryExcludes(const value: Integer; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryExcludes}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryExcludes}

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
  <BinaryContact>
  @action: Determines whether a specific integer value exists in a sorted array
           using binary search.
  @note: - Assumes the array is sorted according to the `oAscending` flag.
         - Returns True if the value is found, False otherwise.
         - Time complexity is O(log n).
         - Works for ascending or descending arrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryContact(const x: Integer; const oAscending: Boolean = True): Boolean; overload;
var
  M, H: Integer;
  R: TRange;
begin
  H := High(Self);
  Result := False;
  if ((H = -1) or (oAscending and ((x < Self[0]) or (x > Self[H]))) or ((not oAscending) and ((x > Self[0]) or (x < Self[H])))) then
    Exit;
  R.Create(0, H);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = x) then
      Exit(True);
    if ((oAscending and (Self[M] < x)) or ((not oAscending) and (Self[M] > x))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
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
  <BinaryMember>
  @action: Performs a binary search to determine whether a specific integer value
           exists in the array. The search logic is comparison-driven and supports
           both ascending and descending sorted arrays.
  @note: The array must already be sorted according to the value of oAscending.
         Uses Integer_Compare for ordering semantics. Returns True immediately
         upon finding an exact match; otherwise returns False if the value is not present.
[==============================================================================}
function TIntegerArrayHelper.BinaryMember(const x: Integer; const oAscending: Boolean = True): Boolean; overload;
var
  M, C: Integer;
  R: TRange;
begin
  Result := False;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if oAscending then
      C := Self[M].Compare(x)
    else
      C := x.Compare(Self[M]);
    case C of
      0: Exit(True);
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
    end;
  end;
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
  <BinaryAvailable>
  @action: Performs a classic binary search to test whether a specific integer
           value is present in the array.
  @note: The array must be sorted in ascending or descending order as indicated
         by oAscending. Uses direct relational comparisons rather than abstract
         comparison helpers. Returns True if the value is found; otherwise False.
[==============================================================================}
function TIntegerArrayHelper.BinaryAvailable(const x: Integer; const oAscending: Boolean = True): Boolean; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := False;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  case oAscending of
    True:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = x) then
        Exit(True)
      else if (Self[M] < x) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = x) then
        Exit(True)
      else if (Self[M] > x) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
end;

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
  <BinaryUnavailable>
  @action: Determines whether a specific integer value is not present in the array
           using binary search semantics.
  @note: This function is a logical negation of BinaryAvailable for integer values.
         The array must be sorted according to oAscending. Returns True if the
         value does not exist in the array; otherwise returns False.
[==============================================================================}
function TIntegerArrayHelper.BinaryUnavailable(const x: Integer; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := not Self.BinaryAvailable(x, oAscending);
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

{==============================================================================]
  <BinaryOverlaps>
  @action: Performs a binary search to determine whether the specified integer
           value overlaps the array; that is, whether the value exists as an
           element of the array.
  @note: The array must be sorted according to oAscending. Although named
         "Overlaps", this overload performs an equality-based binary search
         and returns True only when an exact match is found. Returns False
         if the array is empty or if the value is not present.
[==============================================================================}
function TIntegerArrayHelper.BinaryOverlaps(const x: Integer; const oAscending: Boolean = True): Boolean; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  if (R.stop > -1) then
  repeat
    M := R.Pivot;
    if (Self[M] = x) then
      Exit(True);
    if ((oAscending and (Self[M] < x)) or ((not oAscending) and (Self[M] > x))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  until (R.start > R.stop);
  Result := False;
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
{$ENDIF}
