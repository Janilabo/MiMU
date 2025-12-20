{$DEFINE MType := Double}
{$DEFINE MArray := TDoubleArray}
{$DEFINE M2DArray := T2DDoubleArray}
{$DEFINE MHelper := TDoubleArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
TDoubleArrayHelper = type helper for TDoubleArray
  {$I Core.inc}
  function Reinit: Integer; overload;
  function Attach(const items: TDoubleArray): Integer; overload;
  function Embed(const items: TDoubleArray; const index: Integer = 2147483647): Integer; overload;
  function IsMonotonic: Boolean; overload;
  function Monotonicity: Boolean; overload;
  function Monotony: Boolean; overload;
  function Pure(const allowed: TDoubleArray): Boolean; overload;
  function TernarySearch(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function TernaryPeak: Integer; overload;
  function TernaryValley: Integer; overload;
  function TernaryMountain: Integer; overload;
  function BSort(const aAscending: Boolean = True): Integer;
  function BinarySort(const aAscending: Boolean = True): Integer;
  function BinarySorted(const aAscending: Boolean = True): TDoubleArray;
  function BinaryInsertSort(const oAscending: Boolean = True): Integer; overload;
  function BinaryInsertSorted(const oAscending: Boolean = True): TDoubleArray; overload;
  function BinaryBoundL(const x: Double; const aAscending: Boolean = True): Integer;
  function BinaryBoundR(const x: Double; const aAscending: Boolean = True): Integer;
  function BinaryBoundLeft(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryBoundRight(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryPos(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryPosL(const x: Double; const aAscending: Boolean = True): Integer;
  function BinaryPosR(const x: Double; const aAscending: Boolean = True): Integer;
  function BinaryPosOf(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryPosition(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryHybridSearch(const value: Double; const oAscending: Boolean = True; const threshold: Integer = 8): Integer; overload;
  function BinaryHybridSearch(const value: Double; const threshold: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinarySearch(const x: Double; const aAscending: Boolean = True): Integer;
  function BinarySeek(const x: Double; const aAscending: Boolean = True): Integer;
  function BinaryContains(const x: Double; const aAscending: Boolean = True): Boolean;
  function BinaryCount(const x: Double; const aAscending: Boolean = True): Integer;
  function BinaryLocate(const x: Double; const aAscending: Boolean = True): TRange;
  function BinaryLocation(const x: Double; const aAscending: Boolean = True): TRange;
  function BinaryAppend(const x: Double; const aAscending: Boolean = True): Integer;
  function BinaryAdd(const x: Double; const aAscending: Boolean = True): TDoubleArray;
  function BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer;
  function BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer;
  function BinaryPrune(const aAscending: Boolean = True): Integer;
  function BinaryPruned(const aAscending: Boolean = True): TDoubleArray;
  function BinaryUndupe: Integer;
  function BinaryUnduped: TDoubleArray;
  function BinaryUnified(const dAscending: Boolean = True): TDoubleArray;
  function BinaryGrow(const x: Double; const aAscending: Boolean = True): Boolean;
  function BinaryShrink(const x: Double; const aAscending: Boolean = True): Boolean;
  function BinaryLowerBound(const x: Double; const aAscending: Boolean = True): Integer; overload;
  function BinaryUpperBound(const x: Double; const aAscending: Boolean = True): Integer; overload;
  function BinaryLeftmost(const x: Double; const aAscending: Boolean = True): Integer; overload;
  function BinaryRightmost(const x: Double; const aAscending: Boolean = True): Integer; overload;
  function BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload;
  function BinaryRange(const x: Double; const aAscending: Boolean = True): TRange; overload;
  function BinarySpan(const x: TRange; const aAscending: Boolean = True): TRange; overload;
  function BinaryMerge(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
  function BinaryMerged(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
  function BinaryCombine(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
  function BinaryRemove(const val: Double; const all: Boolean = True; const aAscending: Boolean = True): Integer; overload;
  function BinaryFind(const val: Double; const aAscending: Boolean): Integer; overload;
  function BinarySearchEx(const x: Double; const ignore: Double = -2147483648; const aAscending: Boolean = True): Integer; overload;
  function BinaryInsert(const x: Double; const aAscending: Boolean = True): Integer; overload;
  function BinarySearchRange(const x: Double; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryDeduplicate(const aAscending: Boolean = True): Integer; overload;
  function BinaryUnduplicate(const aAscending: Boolean = True): Integer; overload;
  function BinaryDeduplicated(const aAscending: Boolean = True): TDoubleArray; overload;
  function BinaryUnduplicated(const aAscending: Boolean = True): TDoubleArray; overload;
  function BinaryCombined(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
  function BinaryRank(const x: Double; const aAscending: Boolean = True): Integer; overload;
  function BinaryIndex(const x: Double; const aAscending: Boolean = True): Integer; overload;
  function BinaryUpdate(const oValue, nValue: Double; const aAscending: Boolean = True): Boolean; overload;
  function BinaryDelete(const x: Double; const aAscending: Boolean = True): Boolean; overload;
  function BinaryReplace(const oValue, nValue: Double; const aAscending: Boolean = True): Boolean; overload;
  function BinaryReplaceAll(const oValue, nValue: Double; const aAscending: Boolean = True): Integer; overload;
  function BinarySinglify(const item: Double; const aAscending: Boolean = True): Integer; overload;
  function BinarySinglified(const item: Double; const aAscending: Boolean = True): TDoubleArray; overload;
  function BinarySearchFirst(const value: Double; const aAscending: Boolean = True): Integer; overload;
  function BinarySearchLast(const value: Double; const aAscending: Boolean = True): Integer; overload;
  function BinaryLocalize(const value: Double; const aAscending: Boolean = True): Integer; overload;
  function BinaryLookup(const value: Double): Integer; overload;
  function BinaryFirst(const x: Double; const aAscending: Boolean = True): Integer; overload;
  function BinaryLast(const x: Double; const aAscending: Boolean = True): Integer; overload;
  function BinaryFindFirst(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryFindFirst(const range: TRange; const oAscending: Boolean = True): Integer; overload;
  function BinaryFindLast(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryFindLast(const range: TRange; const oAscending: Boolean = True): Integer; overload;
  function BinaryValues(const value: Double; const aAscending: Boolean = True): TDoubleArray; overload;
  function BinaryValues(const values: TRange; const aAscending: Boolean = True): TDoubleArray; overload;
  function BinaryIndexOf(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryExists(const value: Double; const oAscending: Boolean = True): Boolean; overload;
  function BinarySearchSpan(const value: Double; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
  function BinaryFloor(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryCeil(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryTrunc(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryRound(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryPoint(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryClosest(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryFarthest(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinarySearchNth(const value: Double; const N: Integer; const oAscending: Boolean = True): Integer; overload;
  function BinaryApproximateSearch(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload;
  function BinarySearchApproximate(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryLowerCount(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryHigherCount(const value: Double; const oAscending: Boolean = True): Integer; overload;
  function BinaryFit(const value: Double; const oAscending: Boolean = True): Boolean; overload;
  function BinaryUnfit(const value: Double; const oAscending: Boolean = True): Boolean; overload;
  function BinaryIncludes(const value: Double; const oAscending: Boolean = True): Boolean; overload;
  function BinaryExcludes(const value: Double; const oAscending: Boolean = True): Boolean; overload;
  function BinarySpanning(const value: Double; const oAscending: Boolean = True): TRange; overload;
  function BinarySpanning(const range: TRange; const oAscending: Boolean = True): TRange; overload;
  function BinarySpanOf(const value: Double; const oAscending: Boolean = True): TRange; overload;
  function BinarySpanOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
  function BinaryRangeOf(const value: Double; const oAscending: Boolean = True): TRange; overload;
  function BinaryRangeOf(const range: TRange; const oAscending: Boolean = True): TRange; overload;
  function BinaryUnique(const oAscending: Boolean = True): Integer; overload;
  function BinaryUniqued(const oAscending: Boolean = True): TDoubleArray; overload;
  function BinaryUniq(const oAscending: Boolean = True): Integer; overload;
  function BinaryUniqd(const oAscending: Boolean = True): TDoubleArray; overload;
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           while keeping the current length unchanged.
  @note: None.
[==============================================================================}
function TDoubleArrayHelper.Reinit: Integer; overload;
begin
  Result := Self.Size;
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(Double)), 0);
end;

{==============================================================================]
  <Attach>
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
  l := Self.Length;
  i := items.Size;
  if (i = 0) then
    Exit(l);
  Result := (l + i);
  SetLength(Self, Result);
  Move(items[0], Self[l], (i * SizeOf(Double)));
end;

{==============================================================================]
  <Embed>
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
  s := Self.Size;
  l := items.Length;
  if (l = 0) then
    Exit(s);
  p := EnsureRange(index, 0, s);
  t := (s - p);
  SetLength(Self, (s + l));
  if (t > 0) then
    Move(Self[p], Self[p + l], (t * SizeOf(Double)));
  Move(items[0], Self[p], (l * SizeOf(Double)));
  Result := Self.Size;
end;

{==============================================================================]
  <IsMonotonic>
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
  <Monotonicity>
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
  <Monotony>
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
  <Pure>
  @action: Returns true if arr is made with only allowed items.
  @note: None.
[==============================================================================}
function TDoubleArrayHelper.Pure(const allowed: TDoubleArray): Boolean; var a: TDoubleArray; {$DEFINE Skeleton_Pure}{$I Skeletons.inc}{$UNDEF Skeleton_Pure}

{==============================================================================]
  <TernarySearch>
  @action: Performs a ternary search over the array to locate the specified value.
           The routine splits the current search interval into three segments,
           compares the target value against the two internal partition points,
           and repeatedly narrows the interval until the value is found or the range is exhausted.

  @note: Requires the array to be pre-sorted in either ascending or descending order depending on oAscending.
         Returns the index of the matching element when found; otherwise returns -1.
         This implementation executes in logarithmic time relative to array length,
         but is generally not faster than binary search in practical scenarios due to the additional comparisons.
[==============================================================================}
function TDoubleArrayHelper.TernarySearch(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_TernarySearch}{$I Skeletons.inc}{$UNDEF Skeleton_TernarySearch}

{==============================================================================]
  <TernaryPeak>
  @action: Performs a ternary-search-style scan to locate a single local maximum.
  @note: The algorithm attempts to find any valid local maximum with
         sublinear search behavior by iteratively narrowing the search
         interval. Edge maxima are detected up front. If no valid local
         maximum exists in the interior segment, the function returns -1.
         The method guarantees O(log n) probe behavior in the expected case
         but completes with a linear fallback scan when necessary.
[==============================================================================}
function TDoubleArrayHelper.TernaryPeak: Integer; overload; {$DEFINE Skeleton_TernaryPeak}{$I Skeletons.inc}{$UNDEF Skeleton_TernaryPeak}

{==============================================================================]
  <TernaryValley>
  @action: Performs a ternary-search-style scan to locate a single local minimum.
  @note: The algorithm mirrors the logic used in TernaryPeak but inverts
         all comparisons to detect a valley rather than a peak. Edge
         minima are tested first. If no valid local minimum exists in the
         narrowed search interval, the function returns -1. Expected
         complexity is O(log n) with a linear fallback validation.
[==============================================================================}
function TDoubleArrayHelper.TernaryValley: Integer; overload; {$DEFINE Skeleton_TernaryValley}{$I Skeletons.inc}{$UNDEF Skeleton_TernaryValley}

{==============================================================================]
  <TernaryMountain>
  @action: Identifies an index at or near the global maximum by using a
           ternary-search-inspired unimodal search.
  @note: Assumes the array can be treated as unimodal (first rising,
         eventually falling). The method contracts the search range by
         comparing values at symmetric trisection points. No explicit
         local-maximum validation is performed; the algorithm simply
         converges to the region containing the highest value encountered.
         Returns the index of the final converged position.
[==============================================================================}
function TDoubleArrayHelper.TernaryMountain: Integer; overload; {$DEFINE Skeleton_TernaryMountain}{$I Skeletons.inc}{$UNDEF Skeleton_TernaryMountain}

{==============================================================================]
  <BSort>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TDoubleArrayHelper.BSort(const aAscending: Boolean = True): Integer; var a: Double; {$DEFINE Skeleton_BSort}{$I Skeletons.inc}{$UNDEF Skeleton_BSort}

{==============================================================================]
  <BinarySort>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TDoubleArrayHelper.BinarySort(const aAscending: Boolean = True): Integer; var a: Double; {$DEFINE Skeleton_BinarySort}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySort}

{==============================================================================]
  <BinarySorted>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns sorted array arr.
[==============================================================================}
function TDoubleArrayHelper.BinarySorted(const aAscending: Boolean = True): TDoubleArray; var a: Double; {$DEFINE Skeleton_BinarySorted}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySorted}

{==============================================================================]
  <BinaryBoundL>
  @action: Returns Binary Search Lower Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryBoundL(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryBoundL}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryBoundL}

{==============================================================================]
  <BinaryBoundR>
  @action: Returns Binary Search Upper Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryBoundR(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryBoundR}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryBoundR}

{==============================================================================]
  <BinaryBoundLeft>
  @action: Finds the left boundary index for the given value in the array.
  @note: Returns the index of the first element greater than or equal to the value for ascending arrays,
         or the first element less than or equal for descending arrays.
         If all elements are smaller/larger, returns Length(Self).
[==============================================================================}
function TDoubleArrayHelper.BinaryBoundLeft(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryBoundLeft}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryBoundLeft}

{==============================================================================]
  <BinaryBoundRight>
  @action: Finds the right boundary index for the given value in the array.
  @note: Returns the index of the first element strictly greater than the value for ascending arrays,
         or strictly smaller for descending arrays.
         If all elements satisfy the condition, returns Length(Self).
[==============================================================================}
function TDoubleArrayHelper.BinaryBoundRight(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryBoundRight}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryBoundRight}

{==============================================================================]
  <BinaryPos>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TDoubleArrayHelper.BinaryPos(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryPos}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPos}

{==============================================================================]
  <BinaryPosL>
  @action: Returns L-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryPosL(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPosL}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPosL}

{==============================================================================]
  <BinaryPosR>
  @action: Returns R-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryPosR(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPosR}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPosR}

{==============================================================================]
  <BinaryPosOf>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TDoubleArrayHelper.BinaryPosOf(const value: Double; const oAscending: Boolean = True): Integer; overload; var C: Double; {$DEFINE Skeleton_BinaryPosOf}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPosOf}

{==============================================================================]
  <BinaryPosition>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TDoubleArrayHelper.BinaryPosition(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryPosition}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPosition}

function TDoubleArrayHelper.BinaryHybridSearch(const value: Double; const oAscending: Boolean = True; const threshold: Integer = 8): Integer; overload; {$DEFINE Skeleton_BinaryHybridSearch}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryHybridSearch}
function TDoubleArrayHelper.BinaryHybridSearch(const value: Double; const threshold: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryHybridSearch}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryHybridSearch}

{==============================================================================]
  <BinarySearch>
  @action: Binary Search function for TDoubleArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearch(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearch}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearch}

{==============================================================================]
  <BinarySeek>
  @action: Binary Search function for TDoubleArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySeek(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySeek}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySeek}

{==============================================================================]
  <BinaryContains>
  @action: Binary Contains function for TDoubleArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryContains(const x: Double; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryContains}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryContains}

{==============================================================================]
  <BinaryCount>
  @action: Binary Count function for TDoubleArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryCount(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryCount}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryCount}

{==============================================================================]
  <BinaryLocate>
  @action: Returns Binary Search left and right index as TRange based on x value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryLocate(const x: Double; const aAscending: Boolean = True): TRange; {$DEFINE Skeleton_BinaryLocate}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLocate}

{==============================================================================]
  <BinaryLocation>
  @action: Binary Contains function for TDoubleArrays. Contains location storage variable. With Result as False it will be -1..-1.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryLocation(const x: Double; const aAscending: Boolean = True): TRange; {$DEFINE Skeleton_BinaryLocation}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLocation}

{==============================================================================]
  <BinaryAppend>
  @action: Binary Append method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the index x was added to.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryAppend(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryAppend}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryAppend}

{==============================================================================]
  <BinaryAdd>
  @action: Binary Add method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the arr with x.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryAdd(const x: Double; const aAscending: Boolean = True): TDoubleArray; {$DEFINE Skeleton_BinaryAdd}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryAdd}

{==============================================================================]
  <BinarySearchF>
  @action: Binary Search which supports TRange search, uses first match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearchF}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchF}

{==============================================================================]
  <BinarySearchL>
  @action: Binary Search which supports TRange search, uses last match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearchL}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchL}

{==============================================================================]
  <BinaryPrune>
  @action: Binary Search-based Prune method.
  @note: None.
[==============================================================================}
function TDoubleArrayHelper.BinaryPrune(const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPrune}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPrune}

{==============================================================================]
  <BinaryPruned>
  @action: Binary Search-based Pruned method.
  @note: None.
[==============================================================================}
function TDoubleArrayHelper.BinaryPruned(const aAscending: Boolean = True): TDoubleArray; {$DEFINE Skeleton_BinaryPruned}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPruned}

{==============================================================================]
  <BinaryUndupe>
  @action: Binary Search-based Undupe method.
  @note: None
[==============================================================================}
function TDoubleArrayHelper.BinaryUndupe: Integer; var u: TDoubleArray; {$DEFINE Skeleton_BinaryUndupe}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUndupe}

{==============================================================================]
  <BinaryUnduped>
  @action: Binary Search-based Unduped method.
  @note: None
[==============================================================================}
function TDoubleArrayHelper.BinaryUnduped: TDoubleArray; {$DEFINE Skeleton_BinaryUnduped}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUnduped}

{==============================================================================]
  <BinaryUnified>
  @action: Binary Search-based Unified method.
  @note: None
[==============================================================================}
function TDoubleArrayHelper.BinaryUnified(const dAscending: Boolean = True): TDoubleArray; var u: TDoubleArray; {$DEFINE Skeleton_BinaryUnified}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUnified}

{==============================================================================]
  <BinaryGrow>
  @action: Inserts an integer x into the array while maintaining sorted order.
           Works with ascending or descending order based on aAscending.
  @note: Returns True if the value was inserted, False if it already exists.
[==============================================================================}
function TDoubleArrayHelper.BinaryGrow(const x: Double; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryGrow}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryGrow}

{==============================================================================]
  <BinaryShrink>
  @action: Removes an integer x from the array while maintaining sorted order.
  @note: Returns True if the value was removed, False if it was not found.
[==============================================================================}
function TDoubleArrayHelper.BinaryShrink(const x: Double; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryShrink}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryShrink}

{==============================================================================]
  <BinaryLowerBound>
  @action: Finds the first index where the array value is greater than or equal to x
           (ascending) or less than or equal to x (descending).
  @note:
    - Returns Length(Self) if no element satisfies the condition.
    - Equivalent to std::lower_bound in C++.
    - Works correctly for arrays sorted either ascending or descending.
[==============================================================================}
function TDoubleArrayHelper.BinaryLowerBound(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLowerBound}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLowerBound}

{==============================================================================]
  <BinaryUpperBound>
  @action: Finds the first index where the array value is strictly greater than x
           (ascending) or strictly less than x (descending).
  @note:
    - Returns Length(Self) if no element satisfies the condition.
    - Equivalent to std::upper_bound in C++.
    - Works correctly for arrays sorted either ascending or descending.
[==============================================================================}
function TDoubleArrayHelper.BinaryUpperBound(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUpperBound}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUpperBound}

{==============================================================================]
  <BinaryRightmost>
  @action: Finds the last index where the array value is less than or equal to x
           (ascending) or greater than or equal to x (descending).
  @note:
    - Returns -1 if no element satisfies the condition.
    - Useful for “rightmost occurrence” searches.
    - Differs from BinaryUpperBound: includes elements equal to x.
[==============================================================================}
function TDoubleArrayHelper.BinaryRightmost(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRightmost}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRightmost}

{==============================================================================]
  <BinaryLeftmost>
  @action: Finds the first index where the array value is greater than or equal to x
           (ascending) or less than or equal to x (descending).
  @note:
    - Returns -1 if no element satisfies the condition.
    - Useful for “leftmost occurrence” searches.
    - Equivalent to BinaryLowerBound but returns -1 when not found instead of Length(Self).
[==============================================================================}
function TDoubleArrayHelper.BinaryLeftmost(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLeftmost}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLeftmost}

{==============================================================================]
  <BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            values lie within the value interval x.start..x.stop.
            Uses binary search for look-ups in an ascending or descending sorted array.
  @note:    Returns (-1,-1) when no elements fall in the interval or when
            the array is empty.
[==============================================================================}
function TDoubleArrayHelper.BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRange1}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRange1}

{==============================================================================]
  <BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            value equals x. Uses binary search to find the leftmost
            and rightmost matching indexes.
  @note:    Returns (-1,-1) if x is not present. Works for arrays sorted
            ascending or descending as controlled by aAscending.
[==============================================================================}
function TDoubleArrayHelper.BinaryRange(const x: Double; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRange2}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRange2}

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
function TDoubleArrayHelper.BinarySpan(const x: TRange; const aAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpan}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySpan}

function TDoubleArrayHelper.BinaryMerge(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryMerge}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryMerge}

function TDoubleArrayHelper.BinaryMerged(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryMerged}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryMerged}

function TDoubleArrayHelper.BinaryCombine(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryCombine}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryCombine}

{==============================================================================]
  <BinaryRemove>
  @action: Removes one or all occurrences of a specified value from a sorted double array.
  @note: The array must be sorted in either ascending or descending order,
         depending on the `aAscending` flag. The method uses binary search
         to quickly locate the value, then shifts remaining elements and
         resizes the array accordingly. Returns the number of removed items.
[==============================================================================}
function TDoubleArrayHelper.BinaryRemove(const val: Double; const all: Boolean = True; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRemove}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRemove}

{==============================================================================]
  <BinaryFind>
  @action: Performs a binary search on a sorted double array to locate a specific value.
  @note:   The array must be sorted in either ascending or descending order, 
           as specified by `aAscending`. If the value is found, its index is 
           returned; otherwise, -1 is returned. This function assumes there are 
           no ignored or placeholder values in the array.
[==============================================================================}
function TDoubleArrayHelper.BinaryFind(const val: Double; const aAscending: Boolean): Integer; overload; {$DEFINE Skeleton_BinaryFind}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFind}

{==============================================================================]
  <BinarySearchEx>
  @action: Performs a binary search on a sorted double array to locate a specific value,
           skipping over ignored elements and supporting both ascending and descending order.
  @note:   The array must be pre-sorted according to the `aAscending` flag. Elements equal
           to `ignore` are bypassed when searching. Returns the index of the first matching
           element, or -1 if the value is not found or if all elements are ignored.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchEx(const x: Double; const ignore: Double = -2147483648; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchEx}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchEx}

{==============================================================================]
  <BinaryInsert>
  @action: Insert an double into a sorted array using binary search, preserving order.
  @note: Returns the index where the element was inserted. Supports ascending or descending order.
[==============================================================================}
function TDoubleArrayHelper.BinaryInsert(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryInsert}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryInsert}

{==============================================================================]
  <BinarySearchRange>
  @action: Perform a binary search for a value within a specific index range.
  @note: Returns the index of the found element or -1 if not present.
         Works on ascending or descending arrays, depending on aAscending.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchRange(const x: Double; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchRange}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchRange}

{==============================================================================]
  <BinaryDeduplicate>
  @action: Rebuilds the array in place by removing duplicate elements using binary search.
  @note: Creates a temporary copy of the original array and appends only unique values back.
         Returns the number of elements removed.
         Requires the array to be sorted (ascending or descending according to aAscending).
         Runs in O(n log n) time with O(n) additional memory usage.
[==============================================================================}
function TDoubleArrayHelper.BinaryDeduplicate(const aAscending: Boolean = True): Integer; overload; var u: TDoubleArray; {$DEFINE Skeleton_BinaryDeduplicate}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryDeduplicate}

{==============================================================================]
  <BinaryUnduplicate>
  @action: Removes duplicate elements from the array in place using binary search.
  @note: Keeps only the first occurrence of each unique value.
         Returns the number of elements removed.
         Requires the array to be sorted (ascending or descending as specified).
         Operates in O(n log n) time and O(1) extra space.
[==============================================================================}
function TDoubleArrayHelper.BinaryUnduplicate(const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUnduplicate}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUnduplicate}

{==============================================================================]
  <BinaryDeduplicated>
  @action: Return a new array containing unique elements from the current one.
  @note: The original array remains unchanged.
         Uses binary search to avoid inserting duplicates.
         Sorting is recommended before calling for best results.
[==============================================================================}
function TDoubleArrayHelper.BinaryDeduplicated(const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryDeduplicated}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryDeduplicated}

{==============================================================================]
  <BinaryUnduplicated>
  @action: Return a deduplicated copy of the current array using in-place logic.
  @note: Works like BinaryUnduplicate but produces a new array instead of modifying Self.
         Requires sorted input for correct results.
[==============================================================================}
function TDoubleArrayHelper.BinaryUnduplicated(const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryUnduplicated}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUnduplicated}

{==============================================================================]
  <BinaryCombined>
  @action: Merge two sorted arrays into one sorted array.
  @note: Both arrays must be sorted in the same order (ascending or descending).
         The result is a new array that combines both inputs, preserving order.
         Complexity: O(n + m)
[==============================================================================}
function TDoubleArrayHelper.BinaryCombined(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryCombined}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryCombined}

{==============================================================================]
  <BinaryRank>
  @action: Returns the insertion index (rank) of a value in the sorted array.
  @note: If the value exists, its first occurrence index is returned.
         If not found, returns the position where it should be inserted
         to maintain sort order.
         Works for ascending or descending arrays.
         Complexity: O(log n)
[==============================================================================}
function TDoubleArrayHelper.BinaryRank(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRank}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRank}

{==============================================================================]
  <BinaryIndex>
  @action: Returns the index of a given value in the sorted array using binary search.
  @note: If the value is not found, returns -1.
         Works for both ascending and descending arrays.
[==============================================================================}
function TDoubleArrayHelper.BinaryIndex(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryIndex}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryIndex}

{==============================================================================]
  <BinaryUpdate>
  @action: Updates the first occurrence of an element in the sorted array.
  @note: Searches for old_value using binary search. If found, replaces it with new_value.
         Returns True if updated, False if the value was not found.
         After replacement, sorting may be violated if new_value changes order.
[==============================================================================}
function TDoubleArrayHelper.BinaryUpdate(const oValue, nValue: Double; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryUpdate}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUpdate}

{==============================================================================]
  <BinaryDelete>
  @action: Removes the first occurrence of a specific value from a sorted array.
  @note: Uses binary search to locate the target efficiently.
         Returns True if the value was found and deleted, otherwise False.
         Works for ascending or descending arrays.
[==============================================================================}
function TDoubleArrayHelper.BinaryDelete(const x: Double; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryDelete}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryDelete}

{==============================================================================]
  <BinaryReplace>
  @action: Replaces a specific value in a sorted array with a new one.
  @note:   Uses binary search to locate and delete the old value,
           then reinserts the new one while maintaining sorted order.
           Returns True if the old value was found and replaced, otherwise False.
           Complexity: O(log n + n)
[==============================================================================}
function TDoubleArrayHelper.BinaryReplace(const oValue, nValue: Double; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryReplace}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryReplace}

{==============================================================================]
  <BinaryReplaceAll>
  @action: Replaces all occurrences of a specified value (oValue) with another
           value (nValue) in the array, preserving binary order if necessary.
  @note: Returns the number of replacements performed. If any substitution
         breaks sorted order, the array is re-sorted automatically using
         BinaryInsertionSort. The comparison order is determined by aAscending.
[==============================================================================}
function TDoubleArrayHelper.BinaryReplaceAll(const oValue, nValue: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryReplaceAll}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryReplaceAll}

{==============================================================================]
  <BinarySinglify>
  @action: Removes consecutive duplicates of the specified value in a sorted array,
           keeping only one occurrence.
  @note: The array must be sorted (ascending or descending as specified).
         Uses binary search for fast location. Returns the number of removed items.
[==============================================================================}
function TDoubleArrayHelper.BinarySinglify(const item: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySinglify}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySinglify}

{==============================================================================]
  <BinarySinglified>
  @action: Returns a new array where consecutive duplicates of the specified value
           are collapsed into a single instance.
  @note: The source array must be sorted. The order is preserved, and if the value
         does not exist, a full copy of the array is returned unchanged.
[==============================================================================}
function TDoubleArrayHelper.BinarySinglified(const item: Double; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinarySinglified}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySinglified}

{==============================================================================]
  <BinarySearchFirst>
  @action: Performs a binary search to find the first (lowest) index of a specified
           double value within a sorted TDoubleArray.
  @note: - The array must be sorted in ascending order.
         - If the value occurs multiple times, the index of its first occurrence is returned.
         - If the value is not found, returns -1.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchFirst(const value: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchFirst}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchFirst}

{==============================================================================]
  <BinarySearchLast>
  @action: Performs a binary search to find the last (highest) index of a specified
           double value within a sorted TDoubleArray.
  @note: - The array must be sorted in ascending order.
         - If the value occurs multiple times, the index of its last occurrence is returned.
         - If the value is not found, returns -1.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchLast(const value: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchLast}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchLast}

{==============================================================================]
  <BinaryLocalize>
  @action: Determines the insertion position for a specified double value within
           a sorted TDoubleArray.
  @note: - The array must be sorted in ascending order.
         - Returns the index where the value should be inserted to maintain sort order.
         - If the value already exists, returns the index of its first occurrence.
         - Commonly used to find insertion points for sorted inserts or range lookups.
[==============================================================================}
function TDoubleArrayHelper.BinaryLocalize(const value: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLocalize}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLocalize}

{==============================================================================]
  <BinaryLookup>
  @action: Performs a binary search on the array to find the index of the specified value.
           Automatically detects whether the array is sorted in ascending or descending order.
           Returns the index of the value if found; otherwise returns -1.
  @note:   The array must be monotonic (fully ascending or fully descending).  
           If the array contains duplicates, the function returns an arbitrary occurrence.
           This method does not modify the array.
[==============================================================================}
function TDoubleArrayHelper.BinaryLookup(const value: Double): Integer; overload; {$DEFINE Skeleton_BinaryLookup}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLookup}

{==============================================================================]
  <BinaryFirst>
  @action: Return the index of the first element in the sorted array
           that is greater than or equal to x.
           Works with ascending or descending order depending on aAscending.
  @note:   Returns -1 if all elements are less than x (or greater when
           searching a descending array).
[==============================================================================}
function TDoubleArrayHelper.BinaryFirst(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFirst}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFirst}

{==============================================================================]
  <BinaryLast>
  @action: Return the index of the last element in the sorted array
           that is less than or equal to x.
           Honors the aAscending flag for array order.
  @note:   Returns -1 if all elements are greater than x (or less when
           searching a descending array).
[==============================================================================}
function TDoubleArrayHelper.BinaryLast(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLast}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLast}

{==============================================================================]
  <BinaryFindFirst>
  @action: Performs a binary search on the entire array and returns the index of
           the first occurrence of `value`. If the value is not present,
           returns -1.

  @note:   Assumes the array is pre-sorted according to `oAscending`. The
           “first” occurrence corresponds to the lowest index in an ascending
           array or the highest index in a descending array.
[==============================================================================}
function TDoubleArrayHelper.BinaryFindFirst(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindFirst1}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFindFirst1}

{==============================================================================]
  <BinaryFindFirst>
  @action: Executes a binary search to locate the first element within the
           specified numeric range (`range.start`..`range.stop`) and returns its
           index. Returns -1 if no element falls within that range.

  @note:   The comparison is against element values, not array index positions.
           The search space is the full array; `range` specifies the acceptable
           value interval. The array must be sorted according to `oAscending`.
[==============================================================================}
function TDoubleArrayHelper.BinaryFindFirst(const range: TRange; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindFirst2}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFindFirst2}

{==============================================================================]
  <BinaryFindLast>
  @action: Performs a binary search on the entire array and returns the index of
           the last occurrence of `value`. If the value is not present,
           returns -1.

  @note:   Assumes the array is sorted according to `oAscending`. The “last”
           occurrence corresponds to the highest index in an ascending array or
           the lowest index in a descending array.
[==============================================================================}
function TDoubleArrayHelper.BinaryFindLast(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindLast1}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFindLast1}

{==============================================================================]
  <BinaryFindLast>
  @action: Executes a binary search to locate the last element whose value falls
           within the given numeric range (`range.start`..`range.stop`) and
           returns its index. Returns -1 when no element matches.

  @note:   Elements are evaluated by their value, not their position. The array
           must be sorted in accordance with `oAscending`. The overload identifies
           the last qualifying value relative to the sorted order.
[==============================================================================}
function TDoubleArrayHelper.BinaryFindLast(const range: TRange; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFindLast2}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFindLast2}

{==============================================================================]
  <BinaryValues>
  @action: Returns all items in the array that match a given value using binary search.
  @note: The array must be sorted (ascending or descending) depending on
         the value of aAscending. If the value does not occur in the array,
         an empty array is returned.
[==============================================================================}
function TDoubleArrayHelper.BinaryValues(const value: Double; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryValues1}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryValues1}

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
function TDoubleArrayHelper.BinaryValues(const values: TRange; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryValues2}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryValues2}

function TDoubleArrayHelper.BinaryIndexOf(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryIndexOf}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryIndexOf}

function TDoubleArrayHelper.BinaryExists(const value: Double; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryExists}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryExists}

function TDoubleArrayHelper.BinarySearchSpan(const value: Double; const L, R: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchSpan1}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchSpan1}
function TDoubleArrayHelper.BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchSpan2}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchSpan2}

function TDoubleArrayHelper.BinaryInsertSorted(const oAscending: Boolean = True): TDoubleArray; overload; var K: Double; {$DEFINE Skeleton_BinaryInsertSorted}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryInsertSorted}
function TDoubleArrayHelper.BinaryInsertSort(const oAscending: Boolean = True): Integer; overload; var K: Double; {$DEFINE Skeleton_BinaryInsertSort}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryInsertSort}

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
function TDoubleArrayHelper.BinaryFloor(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFloor}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFloor}

{==============================================================================]
  <BinaryCeil>
  @action: Returns the index of the smallest array element that is greater than
           or equal to `value`. If no such element exists, returns -1.
  @note: The array must be sorted according to `oAscending`. For ascending
         order, this corresponds to the mathematical ceiling. For descending
         order, the search logic is inverted but the resulting index still
         identifies the nearest upper-or-equal bound with respect to `value`.
[==============================================================================}
function TDoubleArrayHelper.BinaryCeil(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryCeil}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryCeil}

{==============================================================================]
  <BinaryTrunc>
  @action: Returns the index of the array element closest to `value` when
           truncating towards zero. For positive values, behaves like Floor
           (rounds down). For negative values, behaves like Ceil (rounds up
           towards zero). If no appropriate element exists, returns -1.
  @note: The array must be sorted according to `oAscending`. This mimics the
         behavior of mathematical truncation, which always rounds towards zero.
[==============================================================================}
function TDoubleArrayHelper.BinaryTrunc(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryTrunc}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryTrunc}

{==============================================================================]
  <BinaryRound>
  @action: Returns the index of the array element nearest to `value`. If two
           elements are equidistant, returns the one with the lower index
           (tie-breaking towards floor). If no elements exist, returns -1.
  @note: The array must be sorted according to `oAscending`. This performs
         rounding to the nearest element, similar to mathematical rounding
         with ties going to the lower value.
[==============================================================================}
function TDoubleArrayHelper.BinaryRound(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRound}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRound}

{==============================================================================]
  <BinaryPoint>
  @action: Determines the positional index at which `value` should be inserted
           to preserve the array's sorted order. Returns the first index whose
           element is not less than `value` when ascending, or not greater than
           `value` when descending. If all elements are less (ascending) or
           greater (descending), returns Length(Self).
  @note: This routine does not search for an existing match. It calculates the
         stable insertion point (lower-bound position) using binary search.
         The array must already be sorted according to `oAscending`. The
         returned index will always be in the range 0..Length(Self).
[==============================================================================}
function TDoubleArrayHelper.BinaryPoint(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryPoint}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryPoint}

{==============================================================================]
  <BinaryClosest>
  @action: Returns the index of the element closest to the given value in the array.
  @note:
    - If the exact value exists, returns its index.
    - If the value does not exist, returns the index of the closest element.
    - Handles both ascending and descending sorted arrays (controlled by oAscending).
    - Returns -1 if the array is empty.
[==============================================================================}
function TDoubleArrayHelper.BinaryClosest(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryClosest}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryClosest}

{==============================================================================]
  <BinaryFarthest>
  @action: Returns the index of the array element farthest from the given value.
  @note: Compares only the first and last elements. In case of a tie (both endpoints equally far),
         `oAscending = True` selects the lower index (first element),
         `oAscending = False` selects the higher index (last element). Returns -1 for empty arrays.
[==============================================================================}
function TDoubleArrayHelper.BinaryFarthest(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryFarthest}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFarthest}

{==============================================================================]
  <BinarySearchNth>
  @action: Returns the index of the N-th occurrence of the given value in the array.
  @note:
    - Uses binary search to locate the first occurrence of the value, then adds N to find the N-th occurrence.
    - Returns -1 if:
        * N is out of bounds (negative or larger than the array size),
        * the value is not found,
        * or the N-th occurrence does not exist.
    - Works for both ascending and descending sorted arrays (controlled by oAscending).
[==============================================================================}
function TDoubleArrayHelper.BinarySearchNth(const value: Double; const N: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchNth}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchNth}

{==============================================================================]
  <BinaryApproximateSearch>
  @action: Performs a binary search over an ordered array (ascending or descending),
           to locate the index of the element that exactly matches the target value,
           or—if no exact match exists—the closest element whose absolute difference from the target does not exceed the specified tolerance.
  @note: This implementation evaluates all candidate positions encountered during the binary-search traversal and selects the closest qualifying value.
         It returns –1 when no element falls within the tolerance or when the array is empty or the tolerance is negative.
[==============================================================================} 
function TDoubleArrayHelper.BinaryApproximateSearch(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload; var H, D: Double; {$DEFINE Skeleton_BinaryApproximateSearch}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryApproximateSearch}

{==============================================================================]
  <BinarySearchApproximate>
  @action: Retrieves the closest element to the specified value using arr.BinaryClosest,
           and returns its index only if the element’s difference from the target value is within the specified tolerance.
  @note: This is a higher-level wrapper around arr.BinaryClosest. It does not perform the comparison logic itself beyond tolerance validation.
         Returns –1 when the closest element is outside tolerance, the array is empty, or no closest candidate is found.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchApproximate(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchApproximate}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySearchApproximate}

{==============================================================================]
  <BinaryLowerCount>
  @action: Returns the number of elements in the array strictly less than `value`.
  @note: - The array must be sorted according to `oAscending` (True = ascending, False = descending).
         - Uses binary search for efficient calculation (O(log n)).
[==============================================================================}
function TDoubleArrayHelper.BinaryLowerCount(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLowerCount}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryLowerCount}

{==============================================================================]
  <BinaryHigherCount>
  @action: Returns the number of elements in the array strictly greater than `value`.
  @note: - The array must be sorted according to `oAscending` (True = ascending, False = descending).
         - Uses binary search for efficient calculation (O(log n)).
[==============================================================================}
function TDoubleArrayHelper.BinaryHigherCount(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryHigherCount}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryHigherCount}

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
function TDoubleArrayHelper.BinaryFit(const value: Double; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryFit}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryFit}

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
function TDoubleArrayHelper.BinaryUnfit(const value: Double; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryUnfit}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUnfit}

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
function TDoubleArrayHelper.BinaryIncludes(const value: Double; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryIncludes}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryIncludes}

{==============================================================================]
  <BinaryExcludes>
  @action: Determines whether the specified value does not exist in this array
           by using a binary search. The array is assumed to be pre-sorted in
           the order specified by oAscending.
  @note: Performs boundary checks before invoking the binary search. Returns
         True if the array is empty, if the value lies outside the array’s
         sorted bounds, or if the binary search fails to locate the value.
[==============================================================================}
function TDoubleArrayHelper.BinaryExcludes(const value: Double; const oAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryExcludes}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryExcludes}

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
function TDoubleArrayHelper.BinarySpanning(const value: Double; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanning1}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySpanning1}

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
function TDoubleArrayHelper.BinarySpanning(const range: TRange; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanning2}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySpanning2}

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
function TDoubleArrayHelper.BinarySpanOf(const value: Double; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanOf1}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySpanOf1}

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
function TDoubleArrayHelper.BinarySpanOf(const range: TRange; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinarySpanOf2}{$I Skeletons.inc}{$UNDEF Skeleton_BinarySpanOf2}

{==============================================================================]
  <BinaryRangeOf>
  @action: Finds the contiguous range of a specific value in a sorted array.
  @note:
    - Fully binary search based; no linear expansion.
    - Works with arrays sorted ascending or descending.
    - Returns TRange(-1, -1) if the value is not found.
  @return: TRange containing start and stop indices of the value in the array.
[==============================================================================}
function TDoubleArrayHelper.BinaryRangeOf(const value: Double; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRangeOf1}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRangeOf1}

{==============================================================================]
  <BinaryRangeOf>
  @action: Finds the contiguous range of elements within a specified value range in a sorted array.
  @note:
    - Fully binary search based; no linear expansion.
    - Works with arrays sorted ascending or descending.
    - Returns TRange(-1, -1) if no elements fall within the range.
  @return: TRange containing start and stop indices of elements in the array within the range.
[==============================================================================}
function TDoubleArrayHelper.BinaryRangeOf(const range: TRange; const oAscending: Boolean = True): TRange; overload; {$DEFINE Skeleton_BinaryRangeOf2}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryRangeOf2}

{==============================================================================]
  <BinaryUnique>
  @action: Sorts the array using binary sort, removes duplicate values in-place,
           and returns the final number of unique elements.
  @note: This routine always performs a full binary sort prior to uniqueness
         filtering. After sorting, it compacts the array by overwriting
         duplicates and truncating the underlying storage to the count of
         uniques.
[==============================================================================}
function TDoubleArrayHelper.BinaryUnique(const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUnique}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUnique}

{==============================================================================]
  <BinaryUniqued>
  @action: Returns a new array containing the unique values of the source array,
           sorted according to the specified order, without modifying the
           original array.
  @note: The function makes a full copy of the source array, applies a binary
         sort, removes duplicates by in-place compaction of the copy, and
         trims the resulting array to the count of unique elements.
[==============================================================================}
function TDoubleArrayHelper.BinaryUniqued(const oAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryUniqued}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUniqued}

{==============================================================================]
  <BinaryUniq>
  @action: Removes duplicate values from an already monotonic array (ascending
           or descending), preserving only unique values and returning the final
           count.
  @note: Unlike BinaryUnique, this routine does not sort the array. It assumes
         the array is already ordered in the direction specified by oAscending.
         It performs a linear scan to compact unique values and truncates the
         array afterward.
[==============================================================================}
function TDoubleArrayHelper.BinaryUniq(const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUniq}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUniq}

{==============================================================================]
  <BinaryUniqd>
  @action: Returns a new array containing only the unique values from the source
           array, assuming the source is already ordered (ascending or descending),
           without modifying the original array.
  @note: This routine does not perform sorting. It creates a copy of the source
         array and then performs a linear uniqueness pass based on the direction
         specified by oAscending. Only strictly increasing (or strictly
         decreasing) transitions are preserved. The result is compacted in-place
         and truncated to the number of unique values.
[==============================================================================}
function TDoubleArrayHelper.BinaryUniqd(const oAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryUniqd}{$I Skeletons.inc}{$UNDEF Skeleton_BinaryUniqd}
{$ENDIF}