{$IFDEF HELPERS}
function BinaryCount(const x: Double; const aAscending: Boolean = True): Integer;
function BinaryLowerCount(const value: Double; const oAscending: Boolean = True): Integer; overload;
function BinaryHigherCount(const value: Double; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryCount>
  @action: Binary Count function for TDoubleArrays.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryCount(const x: Double; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryCount}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryCount}

{==============================================================================]
  <BinaryLowerCount>
  @action: Returns the number of elements in the array strictly less than `value`.
  @note: - The array must be sorted according to `oAscending` (True = ascending, False = descending).
         - Uses binary search for efficient calculation (O(log n)).
[==============================================================================}
function TDoubleArrayHelper.BinaryLowerCount(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryLowerCount}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryLowerCount}

{==============================================================================]
  <BinaryHigherCount>
  @action: Returns the number of elements in the array strictly greater than `value`.
  @note: - The array must be sorted according to `oAscending` (True = ascending, False = descending).
         - Uses binary search for efficient calculation (O(log n)).
[==============================================================================}
function TDoubleArrayHelper.BinaryHigherCount(const value: Double; const oAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryHigherCount}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryHigherCount}
{$ENDIF}
