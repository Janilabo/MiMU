{$DEFINE Double}{$I config\Defines.inc}

{==============================================================================]
  <TDoubleArrayHelper.Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           while keeping the current length unchanged.
  @note: None.
[==============================================================================}
function TDoubleArrayHelper.Reinit: Integer; overload; cdecl;
begin
  Result := Length(Self);
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(Double)), 0);
end;

{==============================================================================]
  <TDoubleArrayHelper.BSort>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TDoubleArrayHelper.BSort(const aAscending: Boolean = True): Integer; cdecl; var a: Double; {$DEFINE Skeleton_BSort}{$I config\Skeletons.inc}{$UNDEF Skeleton_BSort}

{==============================================================================]
  <TDoubleArrayHelper.BinarySort>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TDoubleArrayHelper.BinarySort(const aAscending: Boolean = True): Integer; cdecl; var a: Double; {$DEFINE Skeleton_BinarySort}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySort}


{==============================================================================]
  <TDoubleArrayHelper.BinarySorted>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns sorted array arr.
[==============================================================================}
function TDoubleArrayHelper.BinarySorted(const aAscending: Boolean = True): TDoubleArray; cdecl; var a: Double; {$DEFINE Skeleton_BinarySorted}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySorted}

{==============================================================================]
  <TDoubleArrayHelper.BinaryBoundL>
  @action: Returns Binary Search Lower Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryBoundL(const x: Double; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinaryBoundL}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryBoundL}

{==============================================================================]
  <TDoubleArrayHelper.BinaryBoundR>
  @action: Returns Binary Search Upper Bound based on x-value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryBoundR(const x: Double; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinaryBoundR}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryBoundR}

{==============================================================================]
  <TDoubleArrayHelper.BinaryPosL>
  @action: Returns L-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryPosL(const x: Double; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinaryPosL}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryPosL}

{==============================================================================]
  <TDoubleArrayHelper.BinaryPosR>
  @action: Returns R-side pos of x in arr with Binary Search. -1 if x does not exist.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryPosR(const x: Double; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinaryPosR}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryPosR}

{==============================================================================]
  <TDoubleArrayHelper.BinarySearch>
  @action: Binary Search function for TDoubleArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearch(const x: Double; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinarySearch}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearch}

{==============================================================================]
  <TDoubleArrayHelper.BinarySeek>
  @action: Binary Search function for TDoubleArrays. Searches x from arr and returns the index.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySeek(const x: Double; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinarySeek}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySeek}

{==============================================================================]
  <TDoubleArrayHelper.BinaryContains>
  @action: Binary Contains function for TDoubleArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryContains(const x: Double; const aAscending: Boolean = True): Boolean; cdecl; {$DEFINE Skeleton_BinaryContains}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryContains}

{==============================================================================]
  <TDoubleArrayHelper.BinaryCount>
  @action: Binary Count function for TDoubleArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryCount(const x: Double; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinaryCount}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryCount}

{==============================================================================]
  <TDoubleArrayHelper.BinaryLocate>
  @action: Returns Binary Search left and right index as TRange based on x value.
  @note: Works with sorted arrays! (supports both aAscending and descending order)
[==============================================================================}
function TDoubleArrayHelper.BinaryLocate(const x: Double; const aAscending: Boolean = True): TRange; cdecl; {$DEFINE Skeleton_BinaryLocate}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLocate}

{==============================================================================]
  <TDoubleArrayHelper.BinaryLocation>
  @action: Binary Contains function for TDoubleArrays. Contains location storage variable. With Result as False it will be -1..-1.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryLocation(const x: Double; const aAscending: Boolean = True): TRange; cdecl; {$DEFINE Skeleton_BinaryLocation}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLocation}

{==============================================================================]
  <TDoubleArrayHelper.BinaryAppend>
  @action: Binary Append method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the index x was added to.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryAppend(const x: Double; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinaryAppend}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryAppend}

{==============================================================================]
  <TDoubleArrayHelper.BinaryAdd>
  @action: Binary Add method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the arr with x.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryAdd(const x: Double; const aAscending: Boolean = True): TDoubleArray; cdecl; {$DEFINE Skeleton_BinaryAdd}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryAdd}

{==============================================================================]
  <TDoubleArrayHelper.BinarySearchF>
  @action: Binary Search which supports TRange search, uses first match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinarySearchF}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchF}

{==============================================================================]
  <TDoubleArrayHelper.BinarySearchL>
  @action: Binary Search which supports TRange search, uses last match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinarySearchL}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinarySearchL}

{==============================================================================]
  <TDoubleArrayHelper.BinaryUnique>
  @action: Binary Search-based Unique method.
  @note: Alternative for TArray_Unique, for TDoubleArrays.
[==============================================================================}
function TDoubleArrayHelper.BinaryUnique(const aAscending: Boolean = True): Integer; cdecl; {$DEFINE Skeleton_BinaryUnique}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUnique}

{==============================================================================]
  <TDoubleArrayHelper.BinaryUniqued>
  @action: Binary Search-based Uniqued method.
  @note: Alternative for TArray_Uniqued, for TDoubleArrays.
[==============================================================================}
function TDoubleArrayHelper.BinaryUniqued(const aAscending: Boolean = True): TDoubleArray; cdecl; {$DEFINE Skeleton_BinaryUniqued}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUniqued}

{==============================================================================]
  <TDoubleArrayHelper.BinaryUndupe>
  @action: Binary Search-based Undupe method.
  @note: None
[==============================================================================}
function TDoubleArrayHelper.BinaryUndupe: Integer; cdecl; var u: TDoubleArray; {$DEFINE Skeleton_BinaryUndupe}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUndupe}

{==============================================================================]
  <TDoubleArrayHelper.BinaryUnduped>
  @action: Binary Search-based Unduped method.
  @note: None
[==============================================================================}
function TDoubleArrayHelper.BinaryUnduped: TDoubleArray; cdecl; {$DEFINE Skeleton_BinaryUnduped}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUnduped}

{==============================================================================]
  <TDoubleArrayHelper.BinaryUnduplicated>
  @action: Binary Search-based Unduplicated method.
  @note: None
[==============================================================================}
function TDoubleArrayHelper.BinaryUnduplicated(const dAscending: Boolean = True): TDoubleArray; cdecl; var u: TDoubleArray; {$DEFINE Skeleton_BinaryUnduplicated}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUnduplicated}

{==============================================================================]
  <TDoubleArrayHelper.BinaryGrow>
  @action: Inserts an integer x into the array while maintaining sorted order.
           Works with ascending or descending order based on aAscending.
  @note: Returns True if the value was inserted, False if it already exists.
[==============================================================================}
function TDoubleArrayHelper.BinaryGrow(const x: Double; const aAscending: Boolean = True): Boolean; cdecl; {$DEFINE Skeleton_BinaryGrow}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryGrow}

{==============================================================================]
  <TDoubleArrayHelper.BinaryShrink>
  @action: Removes an integer x from the array while maintaining sorted order.
  @note: Returns True if the value was removed, False if it was not found.
[==============================================================================}
function TDoubleArrayHelper.BinaryShrink(const x: Double; const aAscending: Boolean = True): Boolean; cdecl; {$DEFINE Skeleton_BinaryShrink}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryShrink}

{==============================================================================]
  <TDoubleArrayHelper.BinaryLowerBound>
  @action: Return the index of the first element in the sorted array
           that is greater than or equal to x.
           Works with ascending or descending order depending on aAscending.
  @note:   Returns -1 if all elements are less than x (or greater when
           searching a descending array).
[==============================================================================}
function TDoubleArrayHelper.BinaryLowerBound(const x: Double; const aAscending: Boolean): Integer; cdecl; {$DEFINE Skeleton_BinaryLowerBound}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryLowerBound}

{==============================================================================]
  <TDoubleArrayHelper.BinaryUpperBound>
  @action: Return the index of the last element in the sorted array
           that is less than or equal to x.
           Honors the aAscending flag for array order.
  @note:   Returns -1 if all elements are greater than x (or less when
           searching a descending array).
[==============================================================================}
function TDoubleArrayHelper.BinaryUpperBound(const x: Double; const aAscending: Boolean): Integer; cdecl; {$DEFINE Skeleton_BinaryUpperBound}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryUpperBound}

{==============================================================================]
  <TDoubleArrayHelper.BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            values lie within the value interval x.start..x.stop.
            Uses binary search for look-ups in an ascending or descending sorted array.
  @note:    Returns (-1,-1) when no elements fall in the interval or when
            the array is empty.
[==============================================================================}
function TDoubleArrayHelper.BinaryRange(const x: TRange; const aAscending: Boolean = True): TRange; overload; cdecl; {$DEFINE Skeleton_BinaryRange1}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryRange1}

{==============================================================================]
  <TDoubleArrayHelper.BinaryRange>
  @action:  Return the index range (start..stop) of all elements whose
            value equals x. Uses binary search to find the leftmost
            and rightmost matching indexes.
  @note:    Returns (-1,-1) if x is not present. Works for arrays sorted
            ascending or descending as controlled by aAscending.
[==============================================================================}
function TDoubleArrayHelper.BinaryRange(const x: Double; const aAscending: Boolean = True): TRange; overload; cdecl; {$DEFINE Skeleton_BinaryRange2}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryRange2}

function TDoubleArrayHelper.BinaryMerge(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; cdecl; {$DEFINE Skeleton_BinaryMerge}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryMerge}

function TDoubleArrayHelper.BinaryMerged(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; cdecl; {$DEFINE Skeleton_BinaryMerged}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryMerged}

function TDoubleArrayHelper.BinaryCombine(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; cdecl; {$DEFINE Skeleton_BinaryCombine}{$I config\Skeletons.inc}{$UNDEF Skeleton_BinaryCombine}

{$UNDEF Double}