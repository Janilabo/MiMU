{$IFDEF HELPERS}
function BinaryLocate(const x: Integer; const aAscending: Boolean = True): TRange;
function BinaryLocation(const x: Integer; const aAscending: Boolean = True): TRange;
function BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload;
function BinaryRange(const x: Integer; const aAscending: Boolean = True): TRange; overload;
function BinarySpan(const x: TRange; const aAscending: Boolean = True): TRange; overload;
function BinarySpanning(const value: Integer; const oAscending: Boolean = True): TRange; overload;
function BinarySpanning(const range: TRange; const oAscending: Boolean = True): TRange; overload;
function BinarySpanOf(const value: Integer; const oAscending: Boolean = True): TRange; overload;
function BinarySpanOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
function BinaryRangeOf(const value: Integer; const oAscending: Boolean = True): TRange; overload;
function BinaryRangeOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
function BinaryRangeEx(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryLocate>
  @action: Returns Binary Search left and right index as TRange based on x value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TIntegerArrayHelper.BinaryLocate(const x: Integer; const aAscending: Boolean = True): TRange; {$DEFINE Skeleton_BinaryLocate}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLocate}

{==============================================================================]
  <BinaryLocation>
  @action: Binary Contains function for TIntegerArrays. Contains location storage variable. With Result as False it will be -1..-1.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryLocation(const x: Integer; const aAscending: Boolean = True): TRange; {$DEFINE Skeleton_BinaryLocation}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLocation}

{==============================================================================]
  <BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            values lie within the value interval x.start..x.stop.
            Uses binary search for look-ups in an ascending or descending sorted array.
  @note:    Returns (-1,-1) when no elements fall in the interval or when
            the array is empty.
[==============================================================================}
function TIntegerArrayHelper.BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRange1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRange1}

{==============================================================================]
  <BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            value equals x. Uses binary search to find the leftmost
            and rightmost matching indexes.
  @note:    Returns (-1,-1) if x is not present. Works for arrays sorted
            ascending or descending as controlled by aAscending.
[==============================================================================}
function TIntegerArrayHelper.BinaryRange(const x: Integer; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRange2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRange2}

{==============================================================================]
  <BinarySpan>
  @action: Performs a binary search on a sorted integer array to find the index range
           (start..stop) of values that fall within a given numeric range.
           Works for both ascending and descending arrays.
  @note:   - Returns (-1, -1) if no elements lie within the specified range.
           - Requires the array to be sorted (ascending or descending).
           - Uses two-pass binary search:
               1. Finds the first index where values ≥ Range.start (or ≤ Range.stop for descending).
               2. Finds the last index where values ≤ Range.stop (or ≥ Range.start for descending).
[==============================================================================}
function TIntegerArrayHelper.BinarySpan(const x: TRange; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpan}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySpan}

{==============================================================================]
  <BinaryRangeEx>
  @action: Returns the range of indices containing values within `tolerance` of
           `value`. Uses binary search to find boundaries efficiently.
  @note: The array must be sorted according to `oAscending`. Unlike the expand
         function, this searches the entire array for the range, not just from
         a starting index. Time complexity is O(log n).
  @example: arr=[10,15,20,25,30,35], value=22, tolerance=5
            → includes 20,25 → range(2,3)
[==============================================================================}
function TIntegerArrayHelper.BinaryRangeEx(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): TRange; overload;
var
  m: TRange;
begin
  if (tolerance < 0) then
    Exit(TRange.Construct(-1, -1));
  m.Create((value - tolerance), (value + tolerance));
  Result.start := Self.BinaryBoundLeft(IfThen(oAscending, m.start, m.stop), oAscending);
  Result.stop := Self.BinaryBoundRight(IfThen(oAscending, m.stop, m.start), oAscending);
  if (Result.stop > 0) then
    Dec(Result.stop);
  if ((Result.start = -1) or (Result.start > High(Self)) or (Result.stop = -1) or (Result.stop < Result.start)) then
    Result := TRange.Construct(-1, -1);
end;

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
function TIntegerArrayHelper.BinarySpanning(const value: Integer; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanning1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySpanning1}

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
function TIntegerArrayHelper.BinarySpanning(const range: TRange; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanning2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySpanning2}

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
function TIntegerArrayHelper.BinarySpanOf(const value: Integer; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanOf1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySpanOf1}

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
function TIntegerArrayHelper.BinarySpanOf(const range: TRange; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanOf2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySpanOf2}

{==============================================================================]
  <BinaryRangeOf>
  @action: Finds the contiguous range of a specific value in a sorted array.
  @note:
    - Fully binary search based; no linear expansion.
    - Works with arrays sorted ascending or descending.
    - Returns TRange(-1, -1) if the value is not found.
  @return: TRange containing start and stop indices of the value in the array.
[==============================================================================}
function TIntegerArrayHelper.BinaryRangeOf(const value: Integer; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRangeOf1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRangeOf1}

{==============================================================================]
  <BinaryRangeOf>
  @action: Finds the contiguous range of elements within a specified value range in a sorted array.
  @note:
    - Fully binary search based; no linear expansion.
    - Works with arrays sorted ascending or descending.
    - Returns TRange(-1, -1) if no elements fall within the range.
  @return: TRange containing start and stop indices of elements in the array within the range.
[==============================================================================}
function TIntegerArrayHelper.BinaryRangeOf(const range: TRange; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRangeOf2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRangeOf2}
{$ENDIF}
