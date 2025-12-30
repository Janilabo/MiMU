{$IFDEF HELPERS}
function BSearch(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryPos(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryPosOf(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryPosition(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySearch(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinarySearch(const x: TRange; const aAscending: Boolean = True): Integer; overload;
function BinarySeek(const x: Integer; const aAscending: Boolean = True): Integer;
function BinaryHybridSearch(const value: Integer; const oAscending: Boolean = True; const threshold: Integer = 8): Integer; overload;
function BinaryHybridSearch(const value: Integer; const threshold: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryRank(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryIndex(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryFind(const val: Integer; const aAscending: Boolean): Integer; overload;
function BinarySearchEx(const x: Integer; const ignore: Integer = -2147483648; const aAscending: Boolean = True): Integer; overload;
function BinarySearchRange(const x: Integer; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryIndexOf(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySearchSpan(const value: Integer; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
function BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryPoint(const value: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySearchNth(const value: Integer; const N: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryApproximateSearch(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySearchApproximate(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryLocalize(const value: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryLookup(const value: Integer): Integer; overload;
function BinaryInterpolationSearch(const x: Integer; const aAscending: Boolean = True): Integer;
function BinaryProbabilisticSearch(const x: Integer; const bias: Double = 0.0; const aAscending: Boolean = True): Integer; overload;
function BinaryProbabilisticSearch(const x: Integer; const aAscending: Boolean; const bias: Double = 0.0): Integer; overload;
function BinaryPinpoint(const x: Integer; const aAscending: Boolean = True): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BSearch>
  @action: Performs a binary search on the current integer array using a 
           branchless, arithmetic-driven search strategy. The routine locates 
           the index of a target value within a sorted array, supporting both 
           ascending and descending order based on the supplied flag.
  @note: This implementation uses mask-based comparisons and branchless 
         interval updates to avoid data-dependent branching. It is designed 
         to provide predictable control flow and consistent performance 
         regardless of input distribution. The function returns the index of 
         one matching element if the value is present; otherwise, it returns 
         -1. The input array must be pre-sorted in the specified order.
[==============================================================================}
function TIntegerArrayHelper.BSearch(const value: Integer; const oAscending: Boolean = True): Integer; overload;
var
  M, C, D, F: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  Result := -1;
  F := Ord(not oAscending);
  while (R.start <= R.stop) do
  begin
    M := ((R.start + R.stop) shr 1);
    C := (Self[M] - value);
    Result.Increase(Integer((((UInt32(C) or UInt32(-C)) shr 31) xor 1) and 1) * (M - Result));
    D := (Integer(UInt32(C) shr 31) xor F);
    R.start := (R.start + (D * ((M + 1) - R.start)));
    R.stop := (R.stop - ((1 - D) * (R.stop - (M - 1))));
  end;
end;

{==============================================================================]
  <BinaryPos>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TIntegerArrayHelper.BinaryPos(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryPos}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryPos}

{==============================================================================]
  <BinaryPosOf>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TIntegerArrayHelper.BinaryPosOf(const value: Integer; const oAscending: Boolean = True): Integer; overload; var C: Integer; {$DEFINE Skeleton_BinaryPosOf}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryPosOf}

{==============================================================================]
  <BinaryPosition>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TIntegerArrayHelper.BinaryPosition(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryPosition}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryPosition}

function TIntegerArrayHelper.BinaryHybridSearch(const value: Integer; const oAscending: Boolean = True; const threshold: Integer = 8): Integer; overload; {$DEFINE Skeleton_BinaryHybridSearch}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryHybridSearch}
function TIntegerArrayHelper.BinaryHybridSearch(const value: Integer; const threshold: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryHybridSearch}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryHybridSearch}

{==============================================================================]
  <BinarySearch>
  @action: Binary Search function for TIntegerArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySearch(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearch}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearch}

{==============================================================================]
  <BinarySearch>
  @action: Searches the integer array for any element whose value falls within the specified range.
           The search is performed using a binary-search strategy based on the assumption that the array is sorted either ascending or descending.
           If an element within the range is found, its index is returned; otherwise, the function returns –1.

  @note: The routine returns the index of the first matching element encountered during the binary-search traversal,
         not necessarily the lowest or highest index satisfying the range.
[==============================================================================}
function TIntegerArrayHelper.BinarySearch(const x: TRange; const aAscending: Boolean = True): Integer; overload;
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
      Exit(M);
    if ((aAscending and (r.stop < Self[M])) or ((not aAscending) and (r.stop > Self[M]))) then
      s.stop := (M - 1)
    else if ((aAscending and (r.start > Self[M])) or ((not aAscending) and (r.start < Self[M]))) then
      s.start := (M + 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinarySeek>
  @action: Binary Search function for TIntegerArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinarySeek(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySeek}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySeek}

{==============================================================================]
  <BinaryFind>
  @action: Performs a binary search on a sorted integer array to locate a specific value.
  @note:   The array must be sorted in either ascending or descending order, 
           as specified by `aAscending`. If the value is found, its index is 
           returned; otherwise, -1 is returned. This function assumes there are 
           no ignored or placeholder values in the array.
[==============================================================================}
function TIntegerArrayHelper.BinaryFind(const val: Integer; const aAscending: Boolean): Integer; overload; {$DEFINE Skeleton_BinaryFind}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFind}

{==============================================================================]
  <BinarySearchEx>
  @action: Performs a binary search on a sorted integer array to locate a specific value,
           skipping over ignored elements and supporting both ascending and descending order.
  @note:   The array must be pre-sorted according to the `aAscending` flag. Elements equal
           to `ignore` are bypassed when searching. Returns the index of the first matching
           element, or -1 if the value is not found or if all elements are ignored.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchEx(const x: Integer; const ignore: Integer = -2147483648; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchEx}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchEx}

{==============================================================================]
  <BinarySearchRange>
  @action: Perform a binary search for a value within a specific index range.
  @note: Returns the index of the found element or -1 if not present.
         Works on ascending or descending arrays, depending on aAscending.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchRange(const x: Integer; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchRange}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchRange}

{==============================================================================]
  <BinaryRank>
  @action: Returns the insertion index (rank) of a value in the sorted array.
  @note: If the value exists, its first occurrence index is returned.
         If not found, returns the position where it should be inserted
         to maintain sort order.
         Works for ascending or descending arrays.
         Complexity: O(log n)
[==============================================================================}
function TIntegerArrayHelper.BinaryRank(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRank}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRank}

{==============================================================================]
  <BinaryIndex>
  @action: Returns the index of a given value in the sorted array using binary search.
  @note: If the value is not found, returns -1.
         Works for both ascending and descending arrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryIndex(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryIndex}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryIndex}

{==============================================================================]
  <BinaryLocalize>
  @action: Determines the insertion position for a specified integer value within
           a sorted TIntegerArray.
  @note: - The array must be sorted in ascending order.
         - Returns the index where the value should be inserted to maintain sort order.
         - If the value already exists, returns the index of its first occurrence.
         - Commonly used to find insertion points for sorted inserts or range lookups.
[==============================================================================}
function TIntegerArrayHelper.BinaryLocalize(const value: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLocalize}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLocalize}

{==============================================================================]
  <BinaryLookup>
  @action: Performs a binary search on the array to find the index of the specified value.
           Automatically detects whether the array is sorted in ascending or descending order.
           Returns the index of the value if found; otherwise returns -1.
  @note:   The array must be monotonic (fully ascending or fully descending).  
           If the array contains duplicates, the function returns an arbitrary occurrence.
           This method does not modify the array.
[==============================================================================}
function TIntegerArrayHelper.BinaryLookup(const value: Integer): Integer; overload; {$DEFINE Skeleton_BinaryLookup}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLookup}

{==============================================================================]
  <BinaryInterpolationSearch>
  @action: Performs an interpolation search on a sorted integer array to find the index of a given value.
  @note: This algorithm estimates the probable position of the target using linear interpolation
         between the low and high bounds, resulting in faster performance than binary search
         for uniformly distributed data. Returns -1 if the element is not found.
[==============================================================================}
function TIntegerArrayHelper.BinaryInterpolationSearch(const x: Integer; const aAscending: Boolean = True): Integer;
var
  L, H, M: Integer;
begin
  L := 0;
  H := High(Self);
  while (L <= H) do
  begin
    case aAscending of
	  True:
      begin
        if ((x < Self[L]) or (x > Self[H])) then
		  Break;
        if (Self[L] = Self[H]) then
          if (Self[L] = x) then
		    Exit(L)
          else
		    Break;
        M := (L + ((x - Self[L]) * (H - L)) div (Self[H] - Self[L]));
      end;
      False:
      begin
        if ((x > Self[L]) or (x < Self[H])) then
		  Break;
        if (Self[L] = Self[H]) then
          if (Self[L] = x) then
		    Exit(L)
          else
		    Break;
        M := (L + ((Self[L] - x) * (H - L)) div (Self[L] - Self[H]));
      end;
    end;
    if (Self[M] = x) then
      Exit(M)
    else
	  if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        L := (M + 1)
      else
        H := (M - 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinaryProbabilisticSearch>
  @action: Performs a probabilistic variant of binary interpolation search, introducing a random bias
           to the estimated midpoint to improve robustness on non-uniform or noisy data.
  @note: The optional `bias` parameter (default = 0.0) adjusts how much random variation is applied
         to the interpolation estimate. A small bias can prevent worst-case patterns and clustering effects.
         Returns -1 if the element is not found.
[==============================================================================}
function TIntegerArrayHelper.BinaryProbabilisticSearch(const x: Integer; const bias: Double = 0.0; const aAscending: Boolean = True): Integer;
var
  L, H, M: Integer;
begin
  L := 0;
  H := High(Self);
  while (L <= H) do
  begin
    if (Self[L] = Self[H]) then
	  M := ((L + H) div 2)
    else
      if aAscending then
        M := (L + Trunc(EnsureRange((((x - Self[L]) / (Self[H] - Self[L])) + bias * (Random - 0.5)), 0.0, 1.0) * (H - L)))
      else
        M := (L + Trunc(EnsureRange((((Self[L] - x) / (Self[L] - Self[H])) + bias * (Random - 0.5)), 0.0, 1.0) * (H - L)));
    if (Self[M] = x) then
      Exit(M)
    else
	  if ((aAscending and (Self[M] < x)) or ((not aAscending) and (Self[M] > x))) then
        L := (M + 1)
      else
        H := (M - 1);
  end;
  Result := -1;
end;

function TIntegerArrayHelper.BinaryProbabilisticSearch(const x: Integer; const aAscending: Boolean; const bias: Double = 0.0): Integer; overload;
begin
  Result := Self.BinaryProbabilisticSearch(x, bias, aAscending);
end;

{==============================================================================]
  <BinaryPinpoint>
  @action: Finds the index of the element closest in value to the specified integer.
  @note: - The array must be sorted in ascending or descending order as specified by aAscending.
         - Returns the index of the exact match if found, otherwise the index of the nearest element
           by absolute distance to x.
         - Runs in O(log n) time using BinaryRank to locate the insertion position and then compares
           adjacent elements to choose the closest one.
[==============================================================================}
function TIntegerArrayHelper.BinaryPinpoint(const x: Integer; const aAscending: Boolean = True): Integer;
var
  H, D: Integer;
begin
  H := High(Self);
  case H of
    -1: Exit(-1);
    0: Exit(0);
  end;
  Result := Self.BinaryRank(x, aAscending);
  if (Result > H) then
    Exit(H);
  if (Result < 0) then
    Exit(0);
  if (Self[Result] = x) then
    Exit;
  D := x.Distance(Self[Result]);
  if (Result = 0) then
     Exit(IfThen((D < x.Distance(Self[Result + 1])), Result, (Result + 1)));
  if (Result = H) then
    Exit(IfThen((D < x.Distance(Self[Result - 1])), Result, (Result - 1)));
  if (D > x.Distance(Self[Result - 1])) then
    Dec(Result)
  else
    if (D > x.Distance(Self[Result + 1])) then
      Inc(Result);
end;

function TIntegerArrayHelper.BinaryIndexOf(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryIndexOf}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryIndexOf}

function TIntegerArrayHelper.BinarySearchSpan(const value: Integer; const L, R: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchSpan1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchSpan1}
function TIntegerArrayHelper.BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchSpan2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchSpan2}

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
function TIntegerArrayHelper.BinaryPoint(const value: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryPoint}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryPoint}

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
function TIntegerArrayHelper.BinarySearchNth(const value: Integer; const N: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchNth}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchNth}

{==============================================================================]
  <BinaryApproximateSearch>
  @action: Performs a binary search over an ordered array (ascending or descending),
           to locate the index of the element that exactly matches the target value,
           or—if no exact match exists—the closest element whose absolute difference from the target does not exceed the specified tolerance.
  @note: This implementation evaluates all candidate positions encountered during the binary-search traversal and selects the closest qualifying value.
         It returns –1 when no element falls within the tolerance or when the array is empty or the tolerance is negative.
[==============================================================================} 
function TIntegerArrayHelper.BinaryApproximateSearch(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): Integer; overload; var H, D: Integer; {$DEFINE Skeleton_BinaryApproximateSearch}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryApproximateSearch}

{==============================================================================]
  <BinarySearchApproximate>
  @action: Retrieves the closest element to the specified value using arr.BinaryClosest,
           and returns its index only if the element’s difference from the target value is within the specified tolerance.
  @note: This is a higher-level wrapper around arr.BinaryClosest. It does not perform the comparison logic itself beyond tolerance validation.
         Returns –1 when the closest element is outside tolerance, the array is empty, or no closest candidate is found.
[==============================================================================}
function TIntegerArrayHelper.BinarySearchApproximate(const value: Integer; const tolerance: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchApproximate}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchApproximate}
{$ENDIF}
