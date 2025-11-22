{$DEFINE Double}{$I config\Defines.inc}

{==============================================================================]
  <TDoubleArrayHelper.Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           while keeping the current length unchanged.
  @note: None.
[==============================================================================}
function TDoubleArrayHelper.Reinit: Integer; overload;
begin
  Result := Length(Self);
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(Double)), 0);
end;

{==============================================================================]
  <TDoubleArrayHelper.Attach>
  @action: Appends all points from the given array to the end of Self.
           Returns the new total length of the array after appending.
  @note:   Uses Move() for efficiency since Integer is an unmanaged type.
           If the input array is empty, the function returns the current length
           of Self without modification.
[==============================================================================}
function TDoubleArrayHelper.Attach(const items: TDoubleArray): Integer; overload;
var
  l, i: Integer;
begin
  l := Length(Self);
  i := Length(items);
  if (i = 0) then
    Exit(l);
  Result := (l + i);
  SetLength(Self, Result);
  Move(items[0], Self[l], (i * SizeOf(Double)));
end;

{==============================================================================]
  <TDoubleArrayHelper.Embed>
  @action: Inserts the contents of another double array into the current array
           at the specified index. Existing elements from that position onward
           are shifted to make room for the new items.
  @note: If the index exceeds the current length, the items are appended.
         Passing an empty array leaves the original array unchanged.
         The function returns the new total element count.
[==============================================================================}
function TDoubleArrayHelper.Embed(const items: TDoubleArray; const index: Integer = 2147483647): Integer; overload;
var
  s, l, p, t: Integer;
begin
  s := Length(Self);
  l := Length(items);
  if (l = 0) then
    Exit(s);
  p := EnsureRange(index, 0, s);
  t := (s - p);
  SetLength(Self, (s + l));
  if (t > 0) then
    Move(Self[p], Self[p + l], (t * SizeOf(Double)));
  Move(items[0], Self[p], (l * SizeOf(Double)));
  Result := Length(Self);
end;

{==============================================================================]
  <arr.IsMonotonic>
  @action: Returns True if the array elements are monotonic (entirely non-decreasing or non-increasing).
  @note: Works for empty and single-element arrays (they are trivially monotonic).
[==============================================================================}
function TDoubleArrayHelper.IsMonotonic: Boolean; overload;
var
  c: Double;
  i: Integer;
  A, D: Boolean;
begin
  A := True;
  D := True;
  for i := 1 to High(Self) do
  begin
    c := (Self[i] - Self[i - 1]);
    if (c > 0) then
      D := False
    else
      if (c < 0) then
        A := False;
    if not (A or D) then
      Exit(False);
  end;
  Result := (A or D);
end;

{==============================================================================]
  <arr.Monotonicity>
  @action:
    Determines whether the array is monotonic — that is, whether all its
    elements are entirely non-decreasing or entirely non-increasing.

    The function compares each element with the previous one, establishing
    a direction based on the first non-equal pair. If any subsequent element
    violates this direction, the function immediately returns False.
  @note:
    • Empty or single-element arrays are considered monotonic (trivially True).
    • Equal adjacent elements do not affect monotonicity.
    • Uses Sign(A - B) to determine the direction between consecutive elements.
    • Short-circuits for efficiency — exits as soon as a violation is detected.
[==============================================================================}
function TDoubleArrayHelper.Monotonicity: Boolean; overload;
var
  s, d: Double;
  i: Integer;
begin
  d := 0;
  for i := 1 to High(Self) do
  begin
    s := Sign(Self[i] - Self[i - 1]);
    if (s = 0) then
      Continue;
    if (d = 0) then
      d := s
    else if (s <> d) then
      Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <arr.Monotony>
  @action:
    Determines whether the array of doubles is monotone — that is, whether all 
    its elements are entirely non-decreasing or entirely non-increasing.

    The function iterates through adjacent elements, computing the difference
    between each pair. If the difference is smaller than a small tolerance (EPS),
    the elements are considered equal. Otherwise, the sign of the difference 
    establishes the direction (increasing or decreasing). Once a direction is 
    locked, any reversal causes the function to return False immediately.

  @note:
    • Empty or single-element arrays are considered monotone (trivially True).  
    • Equal adjacent elements (within EPS tolerance) do not affect monotonicity.  
    • EPS is a small threshold to account for floating-point rounding errors.  
    • The function short-circuits for efficiency — exits as soon as a direction
      reversal is detected.  
    • Uses Sign(c) from Math unit to determine the direction of change.
[==============================================================================}
function TDoubleArrayHelper.Monotony: Boolean; overload;
const
  EPS = 1E-12;
var
  i, s, d: Integer;
  c: Double;
begin
  d := 0;
  for i := 1 to High(Self) do
  begin
    c := (Self[i] - Self[i - 1]);
    if (Abs(c) < EPS) then
      s := 0
    else
      s := Sign(c);
    if (s = 0) then
      Continue;
    if (d = 0) then
      d := s
    else if (s <> d) then
      Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <TDoubleArray.BSort>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TDoubleArrayHelper.BSort(const aAscending: Boolean = True): Integer; var a: Double; {$DEFINE Skeleton_BSort}{$I config\Skeletons.inc}{$UNDEF Skeleton_BSort}

{==============================================================================]
  <TDoubleArray.BinarySort>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TDoubleArrayHelper.BinarySort(const aAscending: Boolean = True): Integer; var a: Double; {$DEFINE Skeleton_BinarySort}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySort}

{==============================================================================]
  <TDoubleArray.BinarySorted>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns sorted array arr.
[==============================================================================}
function TDoubleArrayHelper.BinarySorted(const aAscending: Boolean = True): TDoubleArray; var a: Double; {$DEFINE Skeleton_BinarySorted}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySorted}

{==============================================================================]
  <TDoubleArray.BinaryBoundL>
  @action: Returns Binary Search Lower Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryBoundL(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryBoundL}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryBoundL}

{==============================================================================]
  <TDoubleArray.BinaryBoundR>
  @action: Returns Binary Search Upper Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryBoundR(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryBoundR}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryBoundR}

{==============================================================================]
  <TDoubleArray.BinaryPosL>
  @action: Returns L-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryPosL(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPosL}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryPosL}

{==============================================================================]
  <TDoubleArray.BinaryPosR>
  @action: Returns R-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryPosR(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPosR}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryPosR}

{==============================================================================]
  <TDoubleArray.BinarySearch>
  @action: Binary Search function for TDoubleArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearch(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearch}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearch}

{==============================================================================]
  <TDoubleArray.BinarySeek>
  @action: Binary Search function for TDoubleArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySeek(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySeek}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySeek}

{==============================================================================]
  <TDoubleArray.BinaryContains>
  @action: Binary Contains function for TDoubleArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryContains(const x: Double; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryContains}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryContains}

{==============================================================================]
  <TDoubleArray.BinaryCount>
  @action: Binary Count function for TDoubleArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryCount(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryCount}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryCount}

{==============================================================================]
  <TDoubleArray.BinaryLocate>
  @action: Returns Binary Search left and right index as TRange based on x value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryLocate(const x: Double; const aAscending: Boolean = True): TRange; {$DEFINE Skeleton_BinaryLocate}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLocate}

{==============================================================================]
  <TDoubleArray.BinaryLocation>
  @action: Binary Contains function for TDoubleArrays. Contains location storage variable. With Result as False it will be -1..-1.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryLocation(const x: Double; const aAscending: Boolean = True): TRange; {$DEFINE Skeleton_BinaryLocation}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLocation}

{==============================================================================]
  <TDoubleArray.BinaryAppend>
  @action: Binary Append method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the index x was added to.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryAppend(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryAppend}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryAppend}

{==============================================================================]
  <TDoubleArray.BinaryAdd>
  @action: Binary Add method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the arr with x.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryAdd(const x: Double; const aAscending: Boolean = True): TDoubleArray; {$DEFINE Skeleton_BinaryAdd}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryAdd}

{==============================================================================]
  <TDoubleArray.BinarySearchF>
  @action: Binary Search which supports TRange search, uses first match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearchF}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchF}

{==============================================================================]
  <TDoubleArray.BinarySearchL>
  @action: Binary Search which supports TRange search, uses last match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearchL}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchL}

{==============================================================================]
  <TDoubleArray.BinaryPrune>
  @action: Binary Search-based Prune method.
  @note: None.
[==============================================================================}
function TDoubleArrayHelper.BinaryPrune(const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPrune}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryPrune}

{==============================================================================]
  <TDoubleArray.BinaryPruned>
  @action: Binary Search-based Pruned method.
  @note: None.
[==============================================================================}
function TDoubleArrayHelper.BinaryPruned(const aAscending: Boolean = True): TDoubleArray; {$DEFINE Skeleton_BinaryPruned}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryPruned}

{==============================================================================]
  <TDoubleArray.BinaryUndupe>
  @action: Binary Search-based Undupe method.
  @note: None
[==============================================================================}
function TDoubleArrayHelper.BinaryUndupe: Integer; var u: TDoubleArray; {$DEFINE Skeleton_BinaryUndupe}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUndupe}

{==============================================================================]
  <TDoubleArray.BinaryUnduped>
  @action: Binary Search-based Unduped method.
  @note: None
[==============================================================================}
function TDoubleArrayHelper.BinaryUnduped: TDoubleArray; {$DEFINE Skeleton_BinaryUnduped}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUnduped}

{==============================================================================]
  <TDoubleArray.BinaryUnified>
  @action: Binary Search-based Unified method.
  @note: None
[==============================================================================}
function TDoubleArrayHelper.BinaryUnified(const dAscending: Boolean = True): TDoubleArray; var u: TDoubleArray; {$DEFINE Skeleton_BinaryUnified}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUnified}

{==============================================================================]
  <TDoubleArray.BinaryGrow>
  @action: Inserts an integer x into the array while maintaining sorted order.
           Works with ascending or descending order based on aAscending.
  @note: Returns True if the value was inserted, False if it already exists.
[==============================================================================}
function TDoubleArrayHelper.BinaryGrow(const x: Double; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryGrow}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryGrow}

{==============================================================================]
  <TDoubleArray.BinaryShrink>
  @action: Removes an integer x from the array while maintaining sorted order.
  @note: Returns True if the value was removed, False if it was not found.
[==============================================================================}
function TDoubleArrayHelper.BinaryShrink(const x: Double; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryShrink}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryShrink}

{==============================================================================]
  <TDoubleArray.BinaryLowerBound>
  @action: Finds the first index where the array value is greater than or equal to x
           (ascending) or less than or equal to x (descending).
  @note:
    - Returns Length(Self) if no element satisfies the condition.
    - Equivalent to std::lower_bound in C++.
    - Works correctly for arrays sorted either ascending or descending.
[==============================================================================}
function TDoubleArrayHelper.BinaryLowerBound(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLowerBound}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLowerBound}

{==============================================================================]
  <TDoubleArray.BinaryUpperBound>
  @action: Finds the first index where the array value is strictly greater than x
           (ascending) or strictly less than x (descending).
  @note:
    - Returns Length(Self) if no element satisfies the condition.
    - Equivalent to std::upper_bound in C++.
    - Works correctly for arrays sorted either ascending or descending.
[==============================================================================}
function TDoubleArrayHelper.BinaryUpperBound(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUpperBound}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUpperBound}

{==============================================================================]
  <TDoubleArray.BinaryRightmost>
  @action: Finds the last index where the array value is less than or equal to x
           (ascending) or greater than or equal to x (descending).
  @note:
    - Returns -1 if no element satisfies the condition.
    - Useful for “rightmost occurrence” searches.
    - Differs from BinaryUpperBound: includes elements equal to x.
[==============================================================================}
function TDoubleArrayHelper.BinaryRightmost(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRightmost}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryRightmost}

{==============================================================================]
  <TDoubleArray.BinaryLeftmost>
  @action: Finds the first index where the array value is greater than or equal to x
           (ascending) or less than or equal to x (descending).
  @note:
    - Returns -1 if no element satisfies the condition.
    - Useful for “leftmost occurrence” searches.
    - Equivalent to BinaryLowerBound but returns -1 when not found instead of Length(Self).
[==============================================================================}
function TDoubleArrayHelper.BinaryLeftmost(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLeftmost}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLeftmost}

{==============================================================================]
  <TDoubleArray.BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            values lie within the value interval x.start..x.stop.
            Uses binary search for look-ups in an ascending or descending sorted array.
  @note:    Returns (-1,-1) when no elements fall in the interval or when
            the array is empty.
[==============================================================================}
function TDoubleArrayHelper.BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRange1}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryRange1}

{==============================================================================]
  <TDoubleArray.BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            value equals x. Uses binary search to find the leftmost
            and rightmost matching indexes.
  @note:    Returns (-1,-1) if x is not present. Works for arrays sorted
            ascending or descending as controlled by aAscending.
[==============================================================================}
function TDoubleArrayHelper.BinaryRange(const x: Double; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRange2}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryRange2}

{==============================================================================]
  <TDoubleArray.BinarySpan>
  @action: Performs a binary search on a sorted double array to find the index range
           (start..stop) of values that fall within a given numeric range.
           Works for both ascending and descending arrays.
  @note:   - Returns (-1, -1) if no elements lie within the specified range.
           - Requires the array to be sorted (ascending or descending).
           - Uses two-pass binary search:
               1. Finds the first index where values ≥ Range.start (or ≤ Range.stop for descending).
               2. Finds the last index where values ≤ Range.stop (or ≥ Range.start for descending).
[==============================================================================}
function TDoubleArrayHelper.BinarySpan(const x: TRange; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpan}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySpan}

function TDoubleArrayHelper.BinaryMerge(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryMerge}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryMerge}

function TDoubleArrayHelper.BinaryMerged(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryMerged}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryMerged}

function TDoubleArrayHelper.BinaryCombine(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryCombine}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryCombine}

{==============================================================================]
  <arr.BinaryRemove>
  @action: Removes one or all occurrences of a specified value from a sorted double array.
  @note: The array must be sorted in either ascending or descending order,
         depending on the `aAscending` flag. The method uses binary search
         to quickly locate the value, then shifts remaining elements and
         resizes the array accordingly. Returns the number of removed items.
[==============================================================================}
function TDoubleArrayHelper.BinaryRemove(const val: Double; const all: Boolean = True; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRemove}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryRemove}

{==============================================================================]
  <arr.BinaryFind>
  @action: Performs a binary search on a sorted double array to locate a specific value.
  @note:   The array must be sorted in either ascending or descending order, 
           as specified by `aAscending`. If the value is found, its index is 
           returned; otherwise, -1 is returned. This function assumes there are 
           no ignored or placeholder values in the array.
[==============================================================================}
function TDoubleArrayHelper.BinaryFind(const val: Double; const aAscending: Boolean): Integer; overload; {$DEFINE Skeleton_BinaryFind}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryFind}

{==============================================================================]
  <arr.BinarySearchEx>
  @action: Performs a binary search on a sorted double array to locate a specific value,
           skipping over ignored elements and supporting both ascending and descending order.
  @note:   The array must be pre-sorted according to the `aAscending` flag. Elements equal
           to `ignore` are bypassed when searching. Returns the index of the first matching
           element, or -1 if the value is not found or if all elements are ignored.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchEx(const x: Double; const ignore: Double = -2147483648; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchEx}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchEx}

{==============================================================================]
  <arr.BinaryInsert>
  @action: Insert an double into a sorted array using binary search, preserving order.
  @note: Returns the index where the element was inserted. Supports ascending or descending order.
[==============================================================================}
function TDoubleArrayHelper.BinaryInsert(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryInsert}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryInsert}

{==============================================================================]
 <arr.BinarySearchRange>
 @action: Perform a binary search for a value within a specific index range.
 @note: Returns the index of the found element or -1 if not present.
        Works on ascending or descending arrays, depending on aAscending.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchRange(const x: Double; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchRange}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchRange}

{==============================================================================]
 <arr.BinaryDeduplicate>
 @action: Rebuilds the array in place by removing duplicate elements using binary search.
 @note: Creates a temporary copy of the original array and appends only unique values back.
        Returns the number of elements removed.
        Requires the array to be sorted (ascending or descending according to aAscending).
        Runs in O(n log n) time with O(n) additional memory usage.
[==============================================================================}
function TDoubleArrayHelper.BinaryDeduplicate(const aAscending: Boolean = True): Integer; overload; var u: TDoubleArray; {$DEFINE Skeleton_BinaryDeduplicate}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryDeduplicate}

{==============================================================================]
 <arr.BinaryUnduplicate>
 @action: Removes duplicate elements from the array in place using binary search.
 @note: Keeps only the first occurrence of each unique value.
        Returns the number of elements removed.
        Requires the array to be sorted (ascending or descending as specified).
        Operates in O(n log n) time and O(1) extra space.
[==============================================================================}
function TDoubleArrayHelper.BinaryUnduplicate(const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUnduplicate}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUnduplicate}

{==============================================================================]
 <arr.BinaryDeduplicated>
 @action: Return a new array containing unique elements from the current one.
 @note: The original array remains unchanged.
        Uses binary search to avoid inserting duplicates.
        Sorting is recommended before calling for best results.
[==============================================================================}
function TDoubleArrayHelper.BinaryDeduplicated(const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryDeduplicated}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryDeduplicated}

{==============================================================================]
 <arr.BinaryUnduplicated>
 @action: Return a deduplicated copy of the current array using in-place logic.
 @note: Works like BinaryUnduplicate but produces a new array instead of modifying Self.
        Requires sorted input for correct results.
[==============================================================================}
function TDoubleArrayHelper.BinaryUnduplicated(const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryUnduplicated}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUnduplicated}

{==============================================================================]
 <arr.BinaryCombined>
 @action: Merge two sorted arrays into one sorted array.
 @note: Both arrays must be sorted in the same order (ascending or descending).
        The result is a new array that combines both inputs, preserving order.
        Complexity: O(n + m)
[==============================================================================}
function TDoubleArrayHelper.BinaryCombined(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryCombined}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryCombined}

{==============================================================================]
 <arr.BinaryRank>
 @action: Returns the insertion index (rank) of a value in the sorted array.
 @note: If the value exists, its first occurrence index is returned.
        If not found, returns the position where it should be inserted
        to maintain sort order.
        Works for ascending or descending arrays.
        Complexity: O(log n)
[==============================================================================}
function TDoubleArrayHelper.BinaryRank(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRank}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryRank}

{==============================================================================]
 <arr.BinaryIndex>
 @action: Returns the index of a given value in the sorted array using binary search.
 @note: If the value is not found, returns -1.
        Works for both ascending and descending arrays.
[==============================================================================}
function TDoubleArrayHelper.BinaryIndex(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryIndex}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryIndex}

{==============================================================================]
 <arr.BinaryUpdate>
 @action: Updates the first occurrence of an element in the sorted array.
 @note: Searches for old_value using binary search. If found, replaces it with new_value.
        Returns True if updated, False if the value was not found.
        After replacement, sorting may be violated if new_value changes order.
[==============================================================================}
function TDoubleArrayHelper.BinaryUpdate(const oValue, nValue: Double; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryUpdate}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUpdate}

{==============================================================================]
 <arr.BinaryDelete>
 @action: Removes the first occurrence of a specific value from a sorted array.
 @note: Uses binary search to locate the target efficiently.
        Returns True if the value was found and deleted, otherwise False.
        Works for ascending or descending arrays.
[==============================================================================}
function TDoubleArrayHelper.BinaryDelete(const x: Double; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryDelete}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryDelete}

{==============================================================================]
 <arr.BinaryReplace>
 @action: Replaces a specific value in a sorted array with a new one.
 @note:   Uses binary search to locate and delete the old value,
          then reinserts the new one while maintaining sorted order.
          Returns True if the old value was found and replaced, otherwise False.
          Complexity: O(log n + n)
[==============================================================================}
function TDoubleArrayHelper.BinaryReplace(const oValue, nValue: Double; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryReplace}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryReplace}

{==============================================================================]
 <arr.BinaryReplaceAll>
 @action: Replaces all occurrences of a specified value (oValue) with another
          value (nValue) in the array, preserving binary order if necessary.
 @note: Returns the number of replacements performed. If any substitution
        breaks sorted order, the array is re-sorted automatically using
        BinaryInsertionSort. The comparison order is determined by aAscending.
[==============================================================================}
function TDoubleArrayHelper.BinaryReplaceAll(const oValue, nValue: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryReplaceAll}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryReplaceAll}

{==============================================================================]
  <arr.BinarySinglify>
  @action: Removes consecutive duplicates of the specified value in a sorted array,
           keeping only one occurrence.
  @note: The array must be sorted (ascending or descending as specified).
         Uses binary search for fast location. Returns the number of removed items.
[==============================================================================}
function TDoubleArrayHelper.BinarySinglify(const item: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySinglify}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySinglify}

{==============================================================================]
  <arr.BinarySinglified>
  @action: Returns a new array where consecutive duplicates of the specified value
           are collapsed into a single instance.
  @note: The source array must be sorted. The order is preserved, and if the value
         does not exist, a full copy of the array is returned unchanged.
[==============================================================================}
function TDoubleArrayHelper.BinarySinglified(const item: Double; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinarySinglified}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySinglified}

{==============================================================================]
 <TDoubleArray.BinarySearchFirst>
  @action: Performs a binary search to find the first (lowest) index of a specified
           double value within a sorted TDoubleArray.
  @note: - The array must be sorted in ascending order.
         - If the value occurs multiple times, the index of its first occurrence is returned.
         - If the value is not found, returns -1.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchFirst(const value: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchFirst}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchFirst}

{==============================================================================]
 <TDoubleArray.BinarySearchLast>
  @action: Performs a binary search to find the last (highest) index of a specified
           double value within a sorted TDoubleArray.
  @note: - The array must be sorted in ascending order.
         - If the value occurs multiple times, the index of its last occurrence is returned.
         - If the value is not found, returns -1.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchLast(const value: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchLast}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchLast}

{==============================================================================]
 <TDoubleArray.BinaryLocalize>
  @action: Determines the insertion position for a specified double value within
           a sorted TDoubleArray.
  @note: - The array must be sorted in ascending order.
         - Returns the index where the value should be inserted to maintain sort order.
         - If the value already exists, returns the index of its first occurrence.
         - Commonly used to find insertion points for sorted inserts or range lookups.
[==============================================================================}
function TDoubleArrayHelper.BinaryLocalize(const value: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLocalize}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLocalize}

{==============================================================================]
 <TDoubleArray.BinaryLookup>
  @action: Performs a binary search on the array to find the index of the specified value.
           Automatically detects whether the array is sorted in ascending or descending order.
           Returns the index of the value if found; otherwise returns -1.
  @note:   The array must be monotonic (fully ascending or fully descending).  
           If the array contains duplicates, the function returns an arbitrary occurrence.
           This method does not modify the array.
[==============================================================================}
function TDoubleArrayHelper.BinaryLookup(const value: Double): Integer; overload; {$DEFINE Skeleton_BinaryLookup}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLookup}

{==============================================================================]
  <TDoubleArray.BinaryFirst>
  @action: Return the index of the first element in the sorted array
           that is greater than or equal to x.
           Works with ascending or descending order depending on aAscending.
  @note:   Returns -1 if all elements are less than x (or greater when
           searching a descending array).
[==============================================================================}
function TDoubleArrayHelper.BinaryFirst(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFirst}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryFirst}

{==============================================================================]
  <TDoubleArray.BinaryLast>
  @action: Return the index of the last element in the sorted array
           that is less than or equal to x.
           Honors the aAscending flag for array order.
  @note:   Returns -1 if all elements are greater than x (or less when
           searching a descending array).
[==============================================================================}
function TDoubleArrayHelper.BinaryLast(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLast}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLast}

{==============================================================================]
  <TDoubleArray.BinaryValues>
  @action: Returns all items in the array that match a given value using binary search.
  @note: The array must be sorted (ascending or descending) depending on
         the value of aAscending. If the value does not occur in the array,
         an empty array is returned.
[==============================================================================}
function TDoubleArrayHelper.BinaryValues(const value: Double; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryValues1}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryValues1}

{==============================================================================]
  <TDoubleArray.BinaryValues>
  @action: Returns all items in the array whose values fall within a given
           numeric range, determined via binary search.
  @note: The array must be sorted (ascending or descending) according to
         aAscending. The order of the returned values matches the direction
         of the input TRange: ascending input returns ascending results,
         and descending input returns results in descending order. If no
         items fall within the specified range, an empty array is returned.
[==============================================================================}
function TDoubleArrayHelper.BinaryValues(const values: TRange; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryValues2}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryValues2}

function TDoubleArrayHelper.BinaryIndexOf(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryIndexOf}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryIndexOf}

function TDoubleArrayHelper.BinaryExists(const value: Double; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryExists}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryExists}

function TDoubleArrayHelper.BinarySearchSpan(const value: Double; const L, R: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchSpan1}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchSpan1}
function TDoubleArrayHelper.BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchSpan2}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchSpan2}

{$UNDEF Double}
