{$IFDEF HELPERS}
function BinaryLocate(const x: Double; const aAscending: Boolean = True): TRange;
function BinaryLocation(const x: Double; const aAscending: Boolean = True): TRange;
function BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload;
function BinaryRange(const x: Double; const aAscending: Boolean = True): TRange; overload;
function BinarySpan(const x: TRange; const aAscending: Boolean = True): TRange; overload;
function BinarySpanning(const value: Double; const oAscending: Boolean = True): TRange; overload;
function BinarySpanning(const range: TRange; const oAscending: Boolean = True): TRange; overload;
function BinarySpanOf(const value: Double; const oAscending: Boolean = True): TRange; overload;
function BinarySpanOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
function BinaryRangeOf(const value: Double; const oAscending: Boolean = True): TRange; overload;
function BinaryRangeOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
function BinaryValues(const value: Double; const aAscending: Boolean = True): TDoubleArray; overload;
function BinaryValues(const values: TRange; const aAscending: Boolean = True): TDoubleArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryLocate>
  @action: Returns Binary Search left and right index as TRange based on x value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryLocate(const x: Double; const aAscending: Boolean = True): TRange; {$DEFINE Skeleton_BinaryLocate}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLocate}

{==============================================================================]
  <BinaryLocation>
  @action: Binary Contains function for TDoubleArrays. Contains location storage variable. With Result as False it will be -1..-1.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryLocation(const x: Double; const aAscending: Boolean = True): TRange; {$DEFINE Skeleton_BinaryLocation}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLocation}

{==============================================================================]
  <BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            values lie within the value interval x.start..x.stop.
            Uses binary search for look-ups in an ascending or descending sorted array.
  @note:    Returns (-1,-1) when no elements fall in the interval or when
            the array is empty.
[==============================================================================}
function TDoubleArrayHelper.BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRange1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRange1}

{==============================================================================]
  <BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            value equals x. Uses binary search to find the leftmost
            and rightmost matching indexes.
  @note:    Returns (-1,-1) if x is not present. Works for arrays sorted
            ascending or descending as controlled by aAscending.
[==============================================================================}
function TDoubleArrayHelper.BinaryRange(const x: Double; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRange2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRange2}

{==============================================================================]
  <BinarySpan>
  @action: Performs a binary search on a sorted double array to find the index range
           (start..stop) of values that fall within a given numeric range.
           Works for both ascending and descending arrays.
  @note:   - Returns (-1, -1) if no elements lie within the specified range.
           - Requires the array to be sorted (ascending or descending).
           - Uses two-pass binary search:
               1. Finds the first index where values ≥ Range.start (or ≤ Range.stop for descending).
               2. Finds the last index where values ≤ Range.stop (or ≥ Range.start for descending).
[==============================================================================}
function TDoubleArrayHelper.BinarySpan(const x: TRange; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpan}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySpan}

{==============================================================================]
  <BinarySpanning>
  @action: Finds the contiguous range (span) of a specific value in a sorted array.
  @note:
    - This function performs a binary search to find the first and last occurrences
      of the given value in the array.
    - The array must be sorted. Use `oAscending = False` if the array is sorted in descending order.
    - Returns a TRange structure representing the start and stop indices of the value.
    - If the value is not found, returns TRange(-1, -1).
  @return: TRange containing start and stop indices of the value in the array.
[==============================================================================}
function TDoubleArrayHelper.BinarySpanning(const value: Double; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanning1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySpanning1}

{==============================================================================]
  <BinarySpanning>
  @action: Finds the contiguous range (span) of values within a specified range in a sorted array.
  @note:
    - This function performs a binary search to find the first and last elements in the array
      that lie within the given range.
    - The array must be sorted. Use `oAscending = False` if the array is sorted in descending order.
    - Returns a TRange structure representing the start and stop indices of elements within the range.
    - If no elements fall within the range, returns TRange(-1, -1).
  @return: TRange containing start and stop indices of elements in the array that are within the specified range.
[==============================================================================}
function TDoubleArrayHelper.BinarySpanning(const range: TRange; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanning2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySpanning2}

{==============================================================================]
  <BinarySpanOf>
  @action: Finds the contiguous range (span) of a specific value in a sorted array.
  @note:
    - Performs a binary search to locate any occurrence of the value.
    - Once found, expands linearly left and right to determine the full span.
    - Works on arrays sorted ascending or descending (controlled by oAscending).
    - Returns TRange(-1, -1) if the value is not found.
  @return: TRange containing start and stop indices of the value in the array.
[==============================================================================}
function TDoubleArrayHelper.BinarySpanOf(const value: Double; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanOf1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySpanOf1}

{==============================================================================]
  <BinarySpanOf>
  @action: Finds the contiguous range (span) of elements within a specified value range in a sorted array.
  @note:
    - Performs a binary search to locate any element within the target range.
    - Once found, expands linearly left and right to determine the full span of elements inside the range.
    - Works on arrays sorted ascending or descending (controlled by oAscending).
    - Returns TRange(-1, -1) if no elements are within the specified range.
  @return: TRange containing start and stop indices of elements in the array within the range.
[==============================================================================}
function TDoubleArrayHelper.BinarySpanOf(const range: TRange; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanOf2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySpanOf2}

{==============================================================================]
  <BinaryRangeOf>
  @action: Finds the contiguous range of a specific value in a sorted array.
  @note:
    - Fully binary search based; no linear expansion.
    - Works with arrays sorted ascending or descending.
    - Returns TRange(-1, -1) if the value is not found.
  @return: TRange containing start and stop indices of the value in the array.
[==============================================================================}
function TDoubleArrayHelper.BinaryRangeOf(const value: Double; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRangeOf1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRangeOf1}

{==============================================================================]
  <BinaryRangeOf>
  @action: Finds the contiguous range of elements within a specified value range in a sorted array.
  @note:
    - Fully binary search based; no linear expansion.
    - Works with arrays sorted ascending or descending.
    - Returns TRange(-1, -1) if no elements fall within the range.
  @return: TRange containing start and stop indices of elements in the array within the range.
[==============================================================================}
function TDoubleArrayHelper.BinaryRangeOf(const range: TRange; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRangeOf2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRangeOf2}

{==============================================================================]
  <BinaryValues>
  @action: Returns all items in the array that match a given value using binary search.
  @note: The array must be sorted (ascending or descending) depending on
         the value of aAscending. If the value does not occur in the array,
         an empty array is returned.
[==============================================================================}
function TDoubleArrayHelper.BinaryValues(const value: Double; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryValues1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryValues1}

{==============================================================================]
  <BinaryValues>
  @action: Returns all items in the array whose values fall within a given
           numeric range, determined via binary search.
  @note: The array must be sorted (ascending or descending) according to
         aAscending. The order of the returned values matches the direction
         of the input TRange: ascending input returns ascending results,
         and descending input returns results in descending order. If no
         items fall within the specified range, an empty array is returned.
[==============================================================================}
function TDoubleArrayHelper.BinaryValues(const values: TRange; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryValues2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryValues2}
{$ENDIF}
