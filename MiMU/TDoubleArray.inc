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