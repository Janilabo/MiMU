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
    else
      R.stop := (M - 1);
  end;
end;
{$ENDIF}
