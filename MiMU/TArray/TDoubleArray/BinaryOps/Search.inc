{$IFDEF HELPERS}
function BinaryPos(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryPosOf(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryPosition(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinarySearch(const x: Double; const aAscending: Boolean = True): Integer;
function BinarySeek(const x: Double; const aAscending: Boolean = True): Integer;
function BinaryFind(const val: Double; const aAscending: Boolean): Integer; overload;
function BinarySearchEx(const x: Double; const ignore: Double = -2147483648; const aAscending: Boolean = True): Integer; overload;
function BinaryIndex(const x: Double; const aAscending: Boolean = True): Integer; overload;
function BinaryIndexOf(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryLocalize(const value: Double; const aAscending: Boolean = True): Integer; overload;
function BinaryRank(const x: Double; const aAscending: Boolean = True): Integer; overload;
function BinaryLookup(const value: Double): Integer; overload;
function BinaryPoint(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryHybridSearch(const value: Double; const oAscending: Boolean = True; const threshold: Integer = 8): Integer; overload;
function BinaryHybridSearch(const value: Double; const threshold: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryApproximateSearch(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload;
function BinarySearchApproximate(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload;
function BinarySearchRange(const x: Double; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload;
function BinarySearchNth(const value: Double; const N: Integer; const oAscending: Boolean = True): Integer; overload;
function BinarySearchSpan(const value: Double; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
function BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryPos>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TDoubleArrayHelper.BinaryPos(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryPos}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryPos}

{==============================================================================]
  <BinaryPosOf>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TDoubleArrayHelper.BinaryPosOf(const value: Double; const oAscending: Boolean = True): Integer; overload; var C: Double; {$DEFINE Skeleton_BinaryPosOf}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryPosOf}

{==============================================================================]
  <BinaryPosition>
  @action: Binary Search
  @note: Alternative.
[==============================================================================}
function TDoubleArrayHelper.BinaryPosition(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryPosition}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryPosition}

{==============================================================================]
  <BinarySearch>
  @action: Binary Search function for TDoubleArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearch(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySearch}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearch}

{==============================================================================]
  <BinarySeek>
  @action: Binary Search function for TDoubleArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySeek(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinarySeek}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySeek}

{==============================================================================]
  <BinaryFind>
  @action: Performs a binary search on a sorted double array to locate a specific value.
  @note:   The array must be sorted in either ascending or descending order, 
           as specified by `aAscending`. If the value is found, its index is 
           returned; otherwise, -1 is returned. This function assumes there are 
           no ignored or placeholder values in the array.
[==============================================================================}
function TDoubleArrayHelper.BinaryFind(const val: Double; const aAscending: Boolean): Integer; overload; {$DEFINE Skeleton_BinaryFind}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryFind}

{==============================================================================]
  <BinarySearchEx>
  @action: Performs a binary search on a sorted double array to locate a specific value,
           skipping over ignored elements and supporting both ascending and descending order.
  @note:   The array must be pre-sorted according to the `aAscending` flag. Elements equal
           to `ignore` are bypassed when searching. Returns the index of the first matching
           element, or -1 if the value is not found or if all elements are ignored.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchEx(const x: Double; const ignore: Double = -2147483648; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchEx}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchEx}

{==============================================================================]
  <BinaryIndex>
  @action: Returns the index of a given value in the sorted array using binary search.
  @note: If the value is not found, returns -1.
         Works for both ascending and descending arrays.
[==============================================================================}
function TDoubleArrayHelper.BinaryIndex(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryIndex}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryIndex}

{==============================================================================]
  <BinaryLocalize>
  @action: Determines the insertion position for a specified double value within
           a sorted TDoubleArray.
  @note: - The array must be sorted in ascending order.
         - Returns the index where the value should be inserted to maintain sort order.
         - If the value already exists, returns the index of its first occurrence.
         - Commonly used to find insertion points for sorted inserts or range lookups.
[==============================================================================}
function TDoubleArrayHelper.BinaryLocalize(const value: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLocalize}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLocalize}

{==============================================================================]
  <BinaryRank>
  @action: Returns the insertion index (rank) of a value in the sorted array.
  @note: If the value exists, its first occurrence index is returned.
         If not found, returns the position where it should be inserted
         to maintain sort order.
         Works for ascending or descending arrays.
         Complexity: O(log n)
[==============================================================================}
function TDoubleArrayHelper.BinaryRank(const x: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRank}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRank}

{==============================================================================]
  <BinaryLookup>
  @action: Performs a binary search on the array to find the index of the specified value.
           Automatically detects whether the array is sorted in ascending or descending order.
           Returns the index of the value if found; otherwise returns -1.
  @note:   The array must be monotonic (fully ascending or fully descending).  
           If the array contains duplicates, the function returns an arbitrary occurrence.
           This method does not modify the array.
[==============================================================================}
function TDoubleArrayHelper.BinaryLookup(const value: Double): Integer; overload; {$DEFINE Skeleton_BinaryLookup}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLookup}

function TDoubleArrayHelper.BinaryIndexOf(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryIndexOf}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryIndexOf}

{==============================================================================]
  <BinarySearchRange>
  @action: Perform a binary search for a value within a specific index range.
  @note: Returns the index of the found element or -1 if not present.
         Works on ascending or descending arrays, depending on aAscending.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchRange(const x: Double; const rLeft, rRight: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchRange}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchRange}

function TDoubleArrayHelper.BinarySearchSpan(const value: Double; const L, R: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchSpan1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchSpan1}
function TDoubleArrayHelper.BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchSpan2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchSpan2}

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
function TDoubleArrayHelper.BinaryPoint(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryPoint}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryPoint}

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
function TDoubleArrayHelper.BinarySearchNth(const value: Double; const N: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchNth}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchNth}

{==============================================================================]
  <BinaryApproximateSearch>
  @action: Performs a binary search over an ordered array (ascending or descending),
           to locate the index of the element that exactly matches the target value,
           or—if no exact match exists—the closest element whose absolute difference from the target does not exceed the specified tolerance.
  @note: This implementation evaluates all candidate positions encountered during the binary-search traversal and selects the closest qualifying value.
         It returns –1 when no element falls within the tolerance or when the array is empty or the tolerance is negative.
[==============================================================================} 
function TDoubleArrayHelper.BinaryApproximateSearch(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload; var H, D: Double; {$DEFINE Skeleton_BinaryApproximateSearch}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryApproximateSearch}

{==============================================================================]
  <BinarySearchApproximate>
  @action: Retrieves the closest element to the specified value using arr.BinaryClosest,
           and returns its index only if the element’s difference from the target value is within the specified tolerance.
  @note: This is a higher-level wrapper around arr.BinaryClosest. It does not perform the comparison logic itself beyond tolerance validation.
         Returns –1 when the closest element is outside tolerance, the array is empty, or no closest candidate is found.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchApproximate(const value: Double; const tolerance: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySearchApproximate}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySearchApproximate}

function TDoubleArrayHelper.BinaryHybridSearch(const value: Double; const oAscending: Boolean = True; const threshold: Integer = 8): Integer; overload; {$DEFINE Skeleton_BinaryHybridSearch}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryHybridSearch}
function TDoubleArrayHelper.BinaryHybridSearch(const value: Double; const threshold: Integer; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryHybridSearch}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryHybridSearch}
{$ENDIF}
