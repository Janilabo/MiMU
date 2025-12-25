{$IFDEF HELPERS}
function BinaryBoundL(const x: Double; const aAscending: Boolean = True): Integer;
function BinaryBoundR(const x: Double; const aAscending: Boolean = True): Integer;
function BinaryBoundLeft(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryBoundRight(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryPosL(const x: Double; const aAscending: Boolean = True): Integer;
function BinaryPosR(const x: Double; const aAscending: Boolean = True): Integer;
function BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer;
function BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer;
function BinaryLowerBound(const x: Double; const aAscending: Boolean = True): Integer; overload;
function BinaryUpperBound(const x: Double; const aAscending: Boolean = True): Integer; overload;
function BinaryLeftmost(const x: Double; const aAscending: Boolean = True): Integer; overload;
function BinaryRightmost(const x: Double; const aAscending: Boolean = True): Integer; overload;
function BinarySearchFirst(const value: Double; const aAscending: Boolean = True): Integer; overload;
function BinarySearchLast(const value: Double; const aAscending: Boolean = True): Integer; overload;
function BinaryFirst(const x: Double; const aAscending: Boolean = True): Integer; overload;
function BinaryLast(const x: Double; const aAscending: Boolean = True): Integer; overload;
function BinaryFindFirst(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryFindFirst(const range: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryFindLast(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryFindLast(const range: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryClosest(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryFarthest(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryFloor(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryCeil(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryTrunc(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryRound(const value: Double; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryBoundL>
  @action: Returns Binary Search Lower Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryBoundL(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryBoundL}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryBoundL}

{==============================================================================]
  <BinaryBoundR>
  @action: Returns Binary Search Upper Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryBoundR(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryBoundR}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryBoundR}

{==============================================================================]
  <BinaryBoundLeft>
  @action: Finds the left boundary index for the given value in the array.
  @note: Returns the index of the first element greater than or equal to the value for ascending arrays,
         or the first element less than or equal for descending arrays.
         If all elements are smaller/larger, returns Length(Self).
[==============================================================================}
function TDoubleArrayHelper.BinaryBoundLeft(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryBoundLeft}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryBoundLeft}

{==============================================================================]
  <BinaryBoundRight>
  @action: Finds the right boundary index for the given value in the array.
  @note: Returns the index of the first element strictly greater than the value for ascending arrays,
         or strictly smaller for descending arrays.
         If all elements satisfy the condition, returns Length(Self).
[==============================================================================}
function TDoubleArrayHelper.BinaryBoundRight(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryBoundRight}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryBoundRight}

{==============================================================================]
  <BinaryPosL>
  @action: Returns L-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryPosL(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPosL}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryPosL}

{==============================================================================]
  <BinaryPosR>
  @action: Returns R-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryPosR(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPosR}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryPosR}

{==============================================================================]
  <BinarySearchF>
  @action: Binary Search which supports TRange search, uses first match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearchF}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchF}

{==============================================================================]
  <BinarySearchL>
  @action: Binary Search which supports TRange search, uses last match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearchL}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchL}

{==============================================================================]
  <BinaryLowerBound>
  @action: Finds the first index where the array value is greater than or equal to x
           (ascending) or less than or equal to x (descending).
  @note:
    - Returns Length(Self) if no element satisfies the condition.
    - Equivalent to std::lower_bound in C++.
    - Works correctly for arrays sorted either ascending or descending.
[==============================================================================}
function TDoubleArrayHelper.BinaryLowerBound(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLowerBound}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLowerBound}

{==============================================================================]
  <BinaryUpperBound>
  @action: Finds the first index where the array value is strictly greater than x
           (ascending) or strictly less than x (descending).
  @note:
    - Returns Length(Self) if no element satisfies the condition.
    - Equivalent to std::upper_bound in C++.
    - Works correctly for arrays sorted either ascending or descending.
[==============================================================================}
function TDoubleArrayHelper.BinaryUpperBound(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUpperBound}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryUpperBound}

{==============================================================================]
  <BinaryRightmost>
  @action: Finds the last index where the array value is less than or equal to x
           (ascending) or greater than or equal to x (descending).
  @note:
    - Returns -1 if no element satisfies the condition.
    - Useful for “rightmost occurrence” searches.
    - Differs from BinaryUpperBound: includes elements equal to x.
[==============================================================================}
function TDoubleArrayHelper.BinaryRightmost(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRightmost}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRightmost}

{==============================================================================]
  <BinaryLeftmost>
  @action: Finds the first index where the array value is greater than or equal to x
           (ascending) or less than or equal to x (descending).
  @note:
    - Returns -1 if no element satisfies the condition.
    - Useful for “leftmost occurrence” searches.
    - Equivalent to BinaryLowerBound but returns -1 when not found instead of Length(Self).
[==============================================================================}
function TDoubleArrayHelper.BinaryLeftmost(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLeftmost}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLeftmost}

{==============================================================================]
  <BinarySearchFirst>
  @action: Performs a binary search to find the first (lowest) index of a specified
           double value within a sorted TDoubleArray.
  @note: - The array must be sorted in ascending order.
         - If the value occurs multiple times, the index of its first occurrence is returned.
         - If the value is not found, returns -1.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchFirst(const value: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchFirst}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchFirst}

{==============================================================================]
  <BinarySearchLast>
  @action: Performs a binary search to find the last (highest) index of a specified
           double value within a sorted TDoubleArray.
  @note: - The array must be sorted in ascending order.
         - If the value occurs multiple times, the index of its last occurrence is returned.
         - If the value is not found, returns -1.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchLast(const value: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchLast}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchLast}

{==============================================================================]
  <BinaryFirst>
  @action: Return the index of the first element in the sorted array
           that is greater than or equal to x.
           Works with ascending or descending order depending on aAscending.
  @note:   Returns -1 if all elements are less than x (or greater when
           searching a descending array).
[==============================================================================}
function TDoubleArrayHelper.BinaryFirst(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFirst}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFirst}

{==============================================================================]
  <BinaryLast>
  @action: Return the index of the last element in the sorted array
           that is less than or equal to x.
           Honors the aAscending flag for array order.
  @note:   Returns -1 if all elements are greater than x (or less when
           searching a descending array).
[==============================================================================}
function TDoubleArrayHelper.BinaryLast(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLast}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLast}

{==============================================================================]
  <BinaryFindFirst>
  @action: Performs a binary search on the entire array and returns the index of
           the first occurrence of `value`. If the value is not present,
           returns -1.

  @note:   Assumes the array is pre-sorted according to `oAscending`. The
           “first” occurrence corresponds to the lowest index in an ascending
           array or the highest index in a descending array.
[==============================================================================}
function TDoubleArrayHelper.BinaryFindFirst(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindFirst1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFindFirst1}

{==============================================================================]
  <BinaryFindFirst>
  @action: Executes a binary search to locate the first element within the
           specified numeric range (`range.start`..`range.stop`) and returns its
           index. Returns -1 if no element falls within that range.

  @note:   The comparison is against element values, not array index positions.
           The search space is the full array; `range` specifies the acceptable
           value interval. The array must be sorted according to `oAscending`.
[==============================================================================}
function TDoubleArrayHelper.BinaryFindFirst(const range: TRange; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindFirst2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFindFirst2}

{==============================================================================]
  <BinaryFindLast>
  @action: Performs a binary search on the entire array and returns the index of
           the last occurrence of `value`. If the value is not present,
           returns -1.

  @note:   Assumes the array is sorted according to `oAscending`. The “last”
           occurrence corresponds to the highest index in an ascending array or
           the lowest index in a descending array.
[==============================================================================}
function TDoubleArrayHelper.BinaryFindLast(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindLast1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFindLast1}

{==============================================================================]
  <BinaryFindLast>
  @action: Executes a binary search to locate the last element whose value falls
           within the given numeric range (`range.start`..`range.stop`) and
           returns its index. Returns -1 when no element matches.

  @note:   Elements are evaluated by their value, not their position. The array
           must be sorted in accordance with `oAscending`. The overload identifies
           the last qualifying value relative to the sorted order.
[==============================================================================}
function TDoubleArrayHelper.BinaryFindLast(const range: TRange; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindLast2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFindLast2}

{==============================================================================]
  <BinaryClosest>
  @action: Returns the index of the element closest to the given value in the array.
  @note:
    - If the exact value exists, returns its index.
    - If the value does not exist, returns the index of the closest element.
    - Handles both ascending and descending sorted arrays (controlled by oAscending).
    - Returns -1 if the array is empty.
[==============================================================================}
function TDoubleArrayHelper.BinaryClosest(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryClosest}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryClosest}

{==============================================================================]
  <BinaryFarthest>
  @action: Returns the index of the array element farthest from the given value.
  @note: Compares only the first and last elements. In case of a tie (both endpoints equally far),
         `oAscending = True` selects the lower index (first element),
         `oAscending = False` selects the higher index (last element). Returns -1 for empty arrays.
[==============================================================================}
function TDoubleArrayHelper.BinaryFarthest(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFarthest}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFarthest}

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
function TDoubleArrayHelper.BinaryFloor(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFloor}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFloor}

{==============================================================================]
  <BinaryCeil>
  @action: Returns the index of the smallest array element that is greater than
           or equal to `value`. If no such element exists, returns -1.
  @note: The array must be sorted according to `oAscending`. For ascending
         order, this corresponds to the mathematical ceiling. For descending
         order, the search logic is inverted but the resulting index still
         identifies the nearest upper-or-equal bound with respect to `value`.
[==============================================================================}
function TDoubleArrayHelper.BinaryCeil(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryCeil}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryCeil}

{==============================================================================]
  <BinaryTrunc>
  @action: Returns the index of the array element closest to `value` when
           truncating towards zero. For positive values, behaves like Floor
           (rounds down). For negative values, behaves like Ceil (rounds up
           towards zero). If no appropriate element exists, returns -1.
  @note: The array must be sorted according to `oAscending`. This mimics the
         behavior of mathematical truncation, which always rounds towards zero.
[==============================================================================}
function TDoubleArrayHelper.BinaryTrunc(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryTrunc}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryTrunc}

{==============================================================================]
  <BinaryRound>
  @action: Returns the index of the array element nearest to `value`. If two
           elements are equidistant, returns the one with the lower index
           (tie-breaking towards floor). If no elements exist, returns -1.
  @note: The array must be sorted according to `oAscending`. This performs
         rounding to the nearest element, similar to mathematical rounding
         with ties going to the lower value.
[==============================================================================}
function TDoubleArrayHelper.BinaryRound(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRound}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRound}
{$ENDIF}
