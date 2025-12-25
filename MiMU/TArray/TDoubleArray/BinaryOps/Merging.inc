{$IFDEF HELPERS}
function BinaryMerge(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
function BinaryMerged(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
function BinaryCombine(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
function BinaryCombined(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function TDoubleArrayHelper.BinaryMerge(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryMerge}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryMerge}

function TDoubleArrayHelper.BinaryMerged(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryMerged}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryMerged}

function TDoubleArrayHelper.BinaryCombine(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryCombine}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryCombine}

{==============================================================================]
  <BinaryCombined>
  @action: Merge two sorted arrays into one sorted array.
  @note: Both arrays must be sorted in the same order (ascending or descending).
         The result is a new array that combines both inputs, preserving order.
         Complexity: O(n + m)
[==============================================================================}
function TDoubleArrayHelper.BinaryCombined(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload; {$DEFINE Skeleton_BinaryCombined}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryCombined}
{$ENDIF}
