{$IFDEF HELPERS}
function BinaryBoundL(const x: Integer; const aAscending: Boolean = True): Integer;
function BinaryBoundR(const x: Integer; const aAscending: Boolean = True): Integer;
function BinaryBoundLeft(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryBoundRight(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryPosL(const x: Integer; const aAscending: Boolean = True): Integer;
function BinaryPosR(const x: Integer; const aAscending: Boolean = True): Integer;
function BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer;
function BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer;
function BinaryLowerBound(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryUpperBound(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryLeftmost(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryLeftmost(const x: TRange; const aAscending: Boolean = True): Integer; overload;
function BinaryRightmost(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryRightmost(const x: TRange; const aAscending: Boolean = True): Integer; overload;
function BinaryFirst(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryLast(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryFindFirst(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryFindFirst(const range: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryFindLast(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryFindLast(const range: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryClosest(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryFarthest(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySearchFirst(const value: Integer; const aAscending: Boolean = True): Integer; overload;
function BinarySearchLast(const value: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryFloor(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryCeil(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryTrunc(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryRound(const value: Integer; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryBoundL>
  @action: Returns Binary Search Lower Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundL(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryBoundL}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryBoundL}

{==============================================================================]
  <BinaryBoundR>
  @action: Returns Binary Search Upper Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundR(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryBoundR}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryBoundR}

{==============================================================================]
  <BinaryBoundLeft>
  @action: Finds the left boundary index for the given value in the array.
  @note: Returns the index of the first element greater than or equal to the value for ascending arrays,
         or the first element less than or equal for descending arrays.
         If all elements are smaller/larger, returns Length(Self).
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundLeft(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryBoundLeft}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryBoundLeft}

{==============================================================================]
  <BinaryBoundRight>
  @action: Finds the right boundary index for the given value in the array.
  @note: Returns the index of the first element strictly greater than the value for ascending arrays,
         or strictly smaller for descending arrays.
         If all elements satisfy the condition, returns Length(Self).
[==============================================================================}
function TIntegerArrayHelper.BinaryBoundRight(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryBoundRight}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryBoundRight}

{==============================================================================]
  <BinaryPosL>
  @action: Returns L-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryPosL(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPosL}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryPosL}

{==============================================================================]
  <BinaryPosR>
  @action: Returns R-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryPosR(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPosR}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryPosR}

{==============================================================================]
  <BinarySearchF>
  @action: Binary Search which supports TRange search, uses first match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearchF}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchF}

{==============================================================================]
  <BinarySearchL>
  @action: Binary Search which supports TRange search, uses last match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearchL}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchL}

{==============================================================================]
  <BinaryLowerBound>
  @action: Finds the first index where the array value is greater than or equal to x
           (ascending) or less than or equal to x (descending).
  @note: 
    - Returns Length(Self) if no element satisfies the condition.
    - Equivalent to std::lower_bound in C++.
    - Works correctly for arrays sorted either ascending or descending.
[==============================================================================}
function TIntegerArrayHelper.BinaryLowerBound(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLowerBound}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLowerBound}

{==============================================================================]
  <BinaryUpperBound>
  @action: Finds the first index where the array value is strictly greater than x
           (ascending) or strictly less than x (descending).
  @note: 
    - Returns Length(Self) if no element satisfies the condition.
    - Equivalent to std::upper_bound in C++.
    - Works correctly for arrays sorted either ascending or descending.
[==============================================================================}
function TIntegerArrayHelper.BinaryUpperBound(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUpperBound}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryUpperBound}

{==============================================================================]
  <BinaryRightmost>
  @action: Finds the last index where the array value is less than or equal to x
           (ascending) or greater than or equal to x (descending).
  @note: 
    - Returns -1 if no element satisfies the condition.
    - Useful for “rightmost occurrence” searches.
    - Differs from BinaryUpperBound: includes elements equal to x.
[==============================================================================}
function TIntegerArrayHelper.BinaryRightmost(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRightmost}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRightmost}

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
  <BinaryLeftmost>
  @action: Finds the first index where the array value is greater than or equal to x
           (ascending) or less than or equal to x (descending).
  @note: 
    - Returns -1 if no element satisfies the condition.
    - Useful for “leftmost occurrence” searches.
    - Equivalent to BinaryLowerBound but returns -1 when not found instead of Length(Self).
[==============================================================================}
function TIntegerArrayHelper.BinaryLeftmost(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLeftmost}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLeftmost}

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
  <BinarySearchFirst>
  @action: Performs a binary search to find the first (lowest) index of a specified
           integer value within a sorted TIntegerArray.
  @note: - The array must be sorted in ascending order.
         - If the value occurs multiple times, the index of its first occurrence is returned.
         - If the value is not found, returns -1.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchFirst(const value: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchFirst}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchFirst}

{==============================================================================]
  <BinarySearchLast>
  @action: Performs a binary search to find the last (highest) index of a specified
           integer value within a sorted TIntegerArray.
  @note: - The array must be sorted in ascending order.
         - If the value occurs multiple times, the index of its last occurrence is returned.
         - If the value is not found, returns -1.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchLast(const value: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchLast}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchLast}

{==============================================================================]
  <BinaryFirst>
  @action: Return the index of the first element in the sorted array
           that is greater than or equal to x.
           Works with ascending or descending order depending on aAscending.
  @note:   Returns -1 if all elements are less than x (or greater when
           searching a descending array).
[==============================================================================}
function TIntegerArrayHelper.BinaryFirst(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFirst}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFirst}

{==============================================================================]
  <BinaryLast>
  @action: Return the index of the last element in the sorted array
           that is less than or equal to x.
           Honors the aAscending flag for array order.
  @note:   Returns -1 if all elements are greater than x (or less when
           searching a descending array).
[==============================================================================}
function TIntegerArrayHelper.BinaryLast(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLast}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLast}

{==============================================================================]
  <BinaryFindFirst>
  @action: Performs a binary search on the entire array and returns the index of
           the first occurrence of `value`. If the value is not present,
           returns -1.

  @note:   Assumes the array is pre-sorted according to `oAscending`. The
           “first” occurrence corresponds to the lowest index in an ascending
           array or the highest index in a descending array.
[==============================================================================}
function TIntegerArrayHelper.BinaryFindFirst(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindFirst1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFindFirst1}

{==============================================================================]
  <BinaryFindFirst>
  @action: Executes a binary search to locate the first element within the
           specified numeric range (`range.start`..`range.stop`) and returns its
           index. Returns -1 if no element falls within that range.

  @note:   The comparison is against element values, not array index positions.
           The search space is the full array; `range` specifies the acceptable
           value interval. The array must be sorted according to `oAscending`.
[==============================================================================}
function TIntegerArrayHelper.BinaryFindFirst(const range: TRange; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindFirst2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFindFirst2}

{==============================================================================]
  <BinaryFindLast>
  @action: Performs a binary search on the entire array and returns the index of
           the last occurrence of `value`. If the value is not present,
           returns -1.

  @note:   Assumes the array is sorted according to `oAscending`. The “last”
           occurrence corresponds to the highest index in an ascending array or
           the lowest index in a descending array.
[==============================================================================}
function TIntegerArrayHelper.BinaryFindLast(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindLast1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFindLast1}

{==============================================================================]
  <BinaryFindLast>
  @action: Executes a binary search to locate the last element whose value falls
           within the given numeric range (`range.start`..`range.stop`) and
           returns its index. Returns -1 when no element matches.

  @note:   Elements are evaluated by their value, not their position. The array
           must be sorted in accordance with `oAscending`. The overload identifies
           the last qualifying value relative to the sorted order.
[==============================================================================}
function TIntegerArrayHelper.BinaryFindLast(const range: TRange; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindLast2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFindLast2}

{==============================================================================]
  <BinaryClosest>
  @action: Returns the index of the element closest to the given value in the array.
  @note:
    - If the exact value exists, returns its index.
    - If the value does not exist, returns the index of the closest element.
    - Handles both ascending and descending sorted arrays (controlled by oAscending).
    - Returns -1 if the array is empty.
[==============================================================================}
function TIntegerArrayHelper.BinaryClosest(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryClosest}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryClosest}

{==============================================================================]
  <BinaryFarthest>
  @action: Returns the index of the array element farthest from the given value.
  @note: Compares only the first and last elements. In case of a tie (both endpoints equally far),
         `oAscending = True` selects the lower index (first element),
         `oAscending = False` selects the higher index (last element). Returns -1 for empty arrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryFarthest(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFarthest}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFarthest}

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
function TIntegerArrayHelper.BinaryFloor(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFloor}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFloor}

{==============================================================================]
  <BinaryCeil>
  @action: Returns the index of the smallest array element that is greater than
           or equal to `value`. If no such element exists, returns -1.
  @note: The array must be sorted according to `oAscending`. For ascending
         order, this corresponds to the mathematical ceiling. For descending
         order, the search logic is inverted but the resulting index still
         identifies the nearest upper-or-equal bound with respect to `value`.
[==============================================================================}
function TIntegerArrayHelper.BinaryCeil(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryCeil}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryCeil}

{==============================================================================]
  <BinaryTrunc>
  @action: Returns the index of the array element closest to `value` when
           truncating towards zero. For positive values, behaves like Floor
           (rounds down). For negative values, behaves like Ceil (rounds up
           towards zero). If no appropriate element exists, returns -1.
  @note: The array must be sorted according to `oAscending`. This mimics the
         behavior of mathematical truncation, which always rounds towards zero.
[==============================================================================}
function TIntegerArrayHelper.BinaryTrunc(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryTrunc}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryTrunc}

{==============================================================================]
  <BinaryRound>
  @action: Returns the index of the array element nearest to `value`. If two
           elements are equidistant, returns the one with the lower index
           (tie-breaking towards floor). If no elements exist, returns -1.
  @note: The array must be sorted according to `oAscending`. This performs
         rounding to the nearest element, similar to mathematical rounding
         with ties going to the lower value.
[==============================================================================}
function TIntegerArrayHelper.BinaryRound(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRound}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRound}
{$ENDIF}
