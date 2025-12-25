{$IFDEF HELPERS}
function BSort(const aAscending: Boolean = True): Integer;
function BinarySort(const aAscending: Boolean = True): Integer;
function BinarySorted(const aAscending: Boolean = True): TDoubleArray;
function BinaryInsertSort(const oAscending: Boolean = True): Integer; overload;
function BinaryInsertSorted(const oAscending: Boolean = True): TDoubleArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BSort>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TDoubleArrayHelper.BSort(const aAscending: Boolean = True): Integer; var a: Double; {$DEFINE Skeleton_BSort}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BSort}

{==============================================================================]
  <BinarySort>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns High(arr).
[==============================================================================}
function TDoubleArrayHelper.BinarySort(const aAscending: Boolean = True): Integer; var a: Double; {$DEFINE Skeleton_BinarySort}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySort}

{==============================================================================]
  <BinarySorted>
  @action: BinarySort algorithm for TDoubleArrays (based on Binary Search).
  @note: Returns sorted array arr.
[==============================================================================}
function TDoubleArrayHelper.BinarySorted(const aAscending: Boolean = True): TDoubleArray; var a: Double; {$DEFINE Skeleton_BinarySorted}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinarySorted}

function TDoubleArrayHelper.BinaryInsertSorted(const oAscending: Boolean = True): TDoubleArray; overload; var K: Double; {$DEFINE Skeleton_BinaryInsertSorted}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryInsertSorted}
function TDoubleArrayHelper.BinaryInsertSort(const oAscending: Boolean = True): Integer; overload; var K: Double; {$DEFINE Skeleton_BinaryInsertSort}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryInsertSort}
{$ENDIF}
