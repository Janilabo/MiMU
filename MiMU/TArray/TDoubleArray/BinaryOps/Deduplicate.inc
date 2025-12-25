{$IFDEF HELPERS}
function BinaryUndupe: Integer;
function BinaryUnduped: TDoubleArray;
function BinaryUnified(const dAscending: Boolean = True): TDoubleArray;
function BinaryDeduplicate(const aAscending: Boolean = True): Integer; overload;
function BinaryUnduplicate(const aAscending: Boolean = True): Integer; overload;
function BinaryDeduplicated(const aAscending: Boolean = True): TDoubleArray; overload;
function BinaryUnduplicated(const aAscending: Boolean = True): TDoubleArray; overload;
function BinaryUnique(const oAscending: Boolean = True): Integer; overload;
function BinaryUniqued(const oAscending: Boolean = True): TDoubleArray; overload;
function BinaryUniq(const oAscending: Boolean = True): Integer; overload;
function BinaryUniqd(const oAscending: Boolean = True): TDoubleArray; overload;
function BinaryPrune(const aAscending: Boolean = True): Integer;
function BinaryPruned(const aAscending: Boolean = True): TDoubleArray;
function BinarySinglify(const item: Double; const aAscending: Boolean = True): Integer; overload;
function BinarySinglified(const item: Double; const aAscending: Boolean = True): TDoubleArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryPrune>
  @action: Binary Search-based Prune method.
  @note: None.
[==============================================================================}
function TDoubleArrayHelper.BinaryPrune(const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryPrune}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryPrune}

{==============================================================================]
  <BinaryPruned>
  @action: Binary Search-based Pruned method.
  @note: None.
[==============================================================================}
function TDoubleArrayHelper.BinaryPruned(const aAscending: Boolean = True): TDoubleArray; {$DEFINE Skeleton_BinaryPruned}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryPruned}

{==============================================================================]
  <BinaryUndupe>
  @action: Binary Search-based Undupe method.
  @note: None
[==============================================================================}
function TDoubleArrayHelper.BinaryUndupe: Integer; var u: TDoubleArray; {$DEFINE Skeleton_BinaryUndupe}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryUndupe}

{==============================================================================]
  <BinaryUnduped>
  @action: Binary Search-based Unduped method.
  @note: None
[==============================================================================}
function TDoubleArrayHelper.BinaryUnduped: TDoubleArray; {$DEFINE Skeleton_BinaryUnduped}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryUnduped}

{==============================================================================]
  <BinaryUnified>
  @action: Binary Search-based Unified method.
  @note: None
[==============================================================================}
function TDoubleArrayHelper.BinaryUnified(const dAscending: Boolean = True): TDoubleArray; var u: TDoubleArray; {$DEFINE Skeleton_BinaryUnified}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryUnified}

{==============================================================================]
  <BinaryDeduplicate>
  @action: Rebuilds the array in place by removing duplicate elements using binary search.
  @note: Creates a temporary copy of the original array and appends only unique values back.
         Returns the number of elements removed.
         Requires the array to be sorted (ascending or descending according to aAscending).
         Runs in O(n log n) time with O(n) additional memory usage.
[==============================================================================}
function TDoubleArrayHelper.BinaryDeduplicate(const aAscending: Boolean = True): Integer; overload; var u: TDoubleArray; {$DEFINE Skeleton_BinaryDeduplicate}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryDeduplicate}

{==============================================================================]
  <BinaryUnduplicate>
  @action: Removes duplicate elements from the array in place using binary search.
  @note: Keeps only the first occurrence of each unique value.
         Returns the number of elements removed.
         Requires the array to be sorted (ascending or descending as specified).
         Operates in O(n log n) time and O(1) extra space.
[==============================================================================}
function TDoubleArrayHelper.BinaryUnduplicate(const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUnduplicate}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryUnduplicate}

{==============================================================================]
  <BinaryDeduplicated>
  @action: Return a new array containing unique elements from the current one.
  @note: The original array remains unchanged.
         Uses binary search to avoid inserting duplicates.
         Sorting is recommended before calling for best results.
[==============================================================================}
function TDoubleArrayHelper.BinaryDeduplicated(const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryDeduplicated}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryDeduplicated}

{==============================================================================]
  <BinaryUnduplicated>
  @action: Return a deduplicated copy of the current array using in-place logic.
  @note: Works like BinaryUnduplicate but produces a new array instead of modifying Self.
         Requires sorted input for correct results.
[==============================================================================}
function TDoubleArrayHelper.BinaryUnduplicated(const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryUnduplicated}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryUnduplicated}

{==============================================================================]
  <BinaryUnique>
  @action: Sorts the array using binary sort, removes duplicate values in-place,
           and returns the final number of unique elements.
  @note: This routine always performs a full binary sort prior to uniqueness
         filtering. After sorting, it compacts the array by overwriting
         duplicates and truncating the underlying storage to the count of
         uniques.
[==============================================================================}
function TDoubleArrayHelper.BinaryUnique(const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUnique}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryUnique}

{==============================================================================]
  <BinaryUniqued>
  @action: Returns a new array containing the unique values of the source array,
           sorted according to the specified order, without modifying the
           original array.
  @note: The function makes a full copy of the source array, applies a binary
         sort, removes duplicates by in-place compaction of the copy, and
         trims the resulting array to the count of unique elements.
[==============================================================================}
function TDoubleArrayHelper.BinaryUniqued(const oAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryUniqued}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryUniqued}

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
function TDoubleArrayHelper.BinaryUniq(const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryUniq}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryUniq}

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
function TDoubleArrayHelper.BinaryUniqd(const oAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryUniqd}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryUniqd}

{==============================================================================]
  <BinarySinglify>
  @action: Removes consecutive duplicates of the specified value in a sorted array,
           keeping only one occurrence.
  @note: The array must be sorted (ascending or descending as specified).
         Uses binary search for fast location. Returns the number of removed items.
[==============================================================================}
function TDoubleArrayHelper.BinarySinglify(const item: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinarySinglify}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySinglify}

{==============================================================================]
  <BinarySinglified>
  @action: Returns a new array where consecutive duplicates of the specified value
           are collapsed into a single instance.
  @note: The source array must be sorted. The order is preserved, and if the value
         does not exist, a full copy of the array is returned unchanged.
[==============================================================================}
function TDoubleArrayHelper.BinarySinglified(const item: Double; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinarySinglified}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySinglified}
{$ENDIF}
