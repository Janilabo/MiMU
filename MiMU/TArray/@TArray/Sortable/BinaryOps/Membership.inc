{$IFDEF HELPERS}
function BinaryAvailable(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryContains(const item: MType; const aAscending: Boolean = True): Boolean; overload;
function BinaryContact(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryExcludes(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryExistence(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryExistency(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryExisting(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryExists(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryFit(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryIncludes(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryMember(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryOverlaps(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryUnavailable(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryUnfit(const item: MType; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryAvailable>
  @action: Performs a classic binary search to test whether a specific item is present in the array.
  @note: The array must be sorted in ascending or descending order as indicated
         by oAscending. Uses direct relational comparisons rather than abstract
         comparison helpers. Returns True if the value is found; otherwise False.
[==============================================================================}
function MArrayHelper.BinaryAvailable(const item: MType; const oAscending: Boolean = True): Boolean; overload;
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
      if (Self[M] = item) then
        Exit(True)
      else if (Self[M] < item) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
    False:
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if (Self[M] = item) then
        Exit(True)
      else if (Self[M] > item) then
        R.start := (M + 1)
      else
        R.stop := (M - 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryContains>
  @action: Binary Contains function for arrays, based on BinarySearch.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function MArrayHelper.BinaryContains(const item: MType; const aAscending: Boolean = True): Boolean; overload;
begin
  Result := (Self.BinarySearch(item, aAscending) > -1);
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
function MArrayHelper.BinaryContact(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  M, H: Integer;
  R: TRange;
begin
  H := High(Self);
  Result := False;
  if ((H = -1) or (oAscending and ((item < Self[0]) or (item > Self[H]))) or ((not oAscending) and ((item > Self[0]) or (item < Self[H])))) then
    Exit;
  R.Create(0, H);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(True);
    if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
end;

{==============================================================================]
  <BinaryExcludes>
  @action: Determines whether the specified item does not exist in this array
           by using a binary search. The array is assumed to be pre-sorted in
           the order specified by oAscending.
  @note: Performs boundary checks before invoking the binary search. Returns
         True if the array is empty, if the item lies outside the array’s
         sorted bounds, or if the binary search fails to locate the item.
[==============================================================================}
function MArrayHelper.BinaryExcludes(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := (Self.BinaryUnfit(item, oAscending) or (Self.BinaryPos(item, oAscending) = -1));
end;

{==============================================================================]
  <BinaryExistence>
  @action: Determines whether the specified item exists in the array using
           a binary lower-bound search.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Internally relies on BinaryLowerBound().
         Returns False if the array is empty or the item is not present.
[==============================================================================}
function MArrayHelper.BinaryExistence(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(False);
  i := Self.BinaryLowerBound(item, oAscending);
  Result := ((i > -1) and (i < l) and (Self[i] = item));
end;

{==============================================================================]
  <BinaryExistency>
  @action: Determines whether the specified item exists in the sorted array
           using the BinaryUpperBound method.
  @note:   Requires the array to be sorted.
           oAscending = True  -> ascending order assumed.
           oAscending = False -> descending order assumed.
           BinaryUpperBound returns the index immediately after the last
           occurrence of the searched item.
           If the returned index is greater than zero and the preceding
           element equals the item, the item exists in the array.
[==============================================================================}
function MArrayHelper.BinaryExistency(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  i: Integer;
begin
  i := Self.BinaryUpperBound(item, oAscending);
  Result := ((i > 0) and (Self[i - 1] = item));
end;

{==============================================================================]
  <BinaryExisting>
  @action: Performs a binary search for a specified item in a sorted array.
  @note: Returns True if the matching item is found. Supports ascending and descending order.
[==============================================================================}
function MArrayHelper.BinaryExisting(const item: MType; const oAscending: Boolean = True): Boolean; overload;
  function BS(const L, R: Integer): Boolean;
  var
    M: Integer;
  begin
    if (L > R) then
      Exit(False);
    M := (L + ((R - L) div 2));
    case Self[M].Contest(item, oAscending) of
      0: Exit(True);
      1: Result := BS(L, (M - 1));
      -1: Result := BS((M + 1), R);
    end;
  end;
begin
  Result := BS(0, High(Self));
end;

{==============================================================================]
  <BinaryExists>
  @action: Determines whether the specified item exists in the array using
           a recursive binary search.
  @note: Requires the array to be sorted.
         oAscending = True  -> ascending order assumed.
         oAscending = False -> descending order assumed.
         Implements a divide-and-conquer search over index range.
         Time complexity: O(log n).
         Space complexity: O(log n) due to recursion.
         Returns False if the array is empty or the item is not present.
[==============================================================================}
function MArrayHelper.BinaryExists(const item: MType; const oAscending: Boolean = True): Boolean; overload;
  function BS(const L, R: Integer): Boolean;
  var
    M: Integer;
  begin
    if (L > R) then
      Exit(False);
    M := (L + ((R - L) div 2));
    if (Self[M] = item) then
      Exit(True);
    if ((oAscending and (item < Self[M])) or ((not oAscending) and (item > Self[M]))) then
      Result := BS(L, (M - 1))
    else
      Result := BS((M + 1), R);
  end;
begin
  Result := BS(0, High(Self));
end;

{==============================================================================]
  <BinaryFit>
  @action: Returns True if the specified item falls within the sortable domain
           represented by the current array. In other words, it verifies that
           the item is within the inclusive bounds defined by the first and
           last elements of the array, assuming that the array is sorted in the
           direction indicated by oAscending.
  @note: This function does not perform a binary search. It simply checks
         whether the item is eligible for a binary lookup or insertion
         attempt. For empty arrays, the function always returns False. When
         oAscending = False, the comparison logic is inverted to support
         descending-sorted arrays.
[==============================================================================}
function MArrayHelper.BinaryFit(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  if oAscending then
    Result := ((not Self.Empty) and (item >= Self[0]) and (item <= Self[High(Self)]))
  else
    Result := ((not Self.Empty) and (item <= Self[0]) and (item >= Self[High(Self)]));
end;

{==============================================================================]
  <BinaryIncludes>
  @action: Determines whether the specified item exists in this array by using
           a binary search. The array is assumed to be pre-sorted in the order
           specified by oAscending.
  @note: Performs boundary checks before invoking the binary search for
         efficiency. Returns True only if the array is non-empty, the item
         lies within the array’s sorted bounds, and the binary search locates
         the element.
[==============================================================================}
function MArrayHelper.BinaryIncludes(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := (Self.BinaryFit(item, oAscending) and (Self.BinaryPos(item, oAscending) > -1));
end;

{==============================================================================]
  <BinaryMember>
  @action: Performs a binary search to determine whether a specific item
           exists in the array. The search logic is comparison-driven and supports
           both ascending and descending sorted arrays.
  @note: The array must already be sorted according to the value of oAscending.
         Uses Integer_Compare for ordering semantics. Returns True immediately
         upon finding an exact match; otherwise returns False if the value is not present.
[==============================================================================}
function MArrayHelper.BinaryMember(const item: MType; const oAscending: Boolean = True): Boolean; overload;
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
      C := Self[M].Compare(item)
    else
      C := item.Compare(Self[M]);
    case C of
      0: Exit(True);
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryOverlaps>
  @action: Performs a binary search to determine whether the specified item overlaps the array; that is, whether the value exists as an
           element of the array.
  @note: The array must be sorted according to oAscending. Although named
         "Overlaps", this overload performs an equality-based binary search
         and returns True only when an exact match is found. Returns False
         if the array is empty or if the value is not present.
[==============================================================================}
function MArrayHelper.BinaryOverlaps(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  if (R.stop > -1) then
  repeat
    M := R.Pivot;
    if (Self[M] = item) then
      Exit(True);
    if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  until (R.start > R.stop);
  Result := False;
end;

{==============================================================================]
  <BinaryUnavailable>
  @action: Determines whether a specific item is not present in the array
           using binary search semantics.
  @note: This function is a logical negation of BinaryAvailable for integer values.
         The array must be sorted according to oAscending. Returns True if the
         value does not exist in the array; otherwise returns False.
[==============================================================================}
function MArrayHelper.BinaryUnavailable(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := not Self.BinaryAvailable(item, oAscending);
end;

{==============================================================================]
  <BinaryUnfit>
  @action: Returns True if the specified item is outside the inclusive bounds
           of the array, or if the array is empty. This indicates that the
           item cannot exist in the array and is not a candidate for a binary
           search within the current bounds.
  @note: This routine is essentially the logical inverse of BinaryFit. It is
         useful as a pre-check before performing binary search or before
         attempting bounded insertion logic. When oAscending = False, the
         boundary comparisons are reversed to support descending-sorted
         arrays.
[==============================================================================}
function MArrayHelper.BinaryUnfit(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  if oAscending then
    Result := (Self.Empty or (item < Self[0]) or (item > Self[High(Self)]))
  else
    Result := (Self.Empty or (item > Self[0]) or (item < Self[High(Self)]));
end;
{$ENDIF}
