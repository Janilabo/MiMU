{$IFDEF HELPERS}
function BinaryShrink(const x: Double; const aAscending: Boolean = True): Boolean;
function BinaryRemove(const val: Double; const all: Boolean = True; const aAscending: Boolean = True): Integer; overload;
function BinaryUpdate(const oValue, nValue: Double; const aAscending: Boolean = True): Boolean; overload;
function BinaryDelete(const x: Double; const aAscending: Boolean = True): Boolean; overload;
function BinaryReplace(const oValue, nValue: Double; const aAscending: Boolean = True): Boolean; overload;
function BinaryReplaceAll(const oValue, nValue: Double; const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryShrink>
  @action: Removes an integer x from the array while maintaining sorted order.
  @note: Returns True if the value was removed, False if it was not found.
[==============================================================================}
function TDoubleArrayHelper.BinaryShrink(const x: Double; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryShrink}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryShrink}

{==============================================================================]
  <BinaryRemove>
  @action: Removes one or all occurrences of a specified value from a sorted double array.
  @note: The array must be sorted in either ascending or descending order,
         depending on the `aAscending` flag. The method uses binary search
         to quickly locate the value, then shifts remaining elements and
         resizes the array accordingly. Returns the number of removed items.
[==============================================================================}
function TDoubleArrayHelper.BinaryRemove(const val: Double; const all: Boolean = True; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryRemove}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryRemove}

{==============================================================================]
  <BinaryUpdate>
  @action: Updates the first occurrence of an element in the sorted array.
  @note: Searches for old_value using binary search. If found, replaces it with new_value.
         Returns True if updated, False if the value was not found.
         After replacement, sorting may be violated if new_value changes order.
[==============================================================================}
function TDoubleArrayHelper.BinaryUpdate(const oValue, nValue: Double; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryUpdate}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryUpdate}

{==============================================================================]
  <BinaryDelete>
  @action: Removes the first occurrence of a specific value from a sorted array.
  @note: Uses binary search to locate the target efficiently.
         Returns True if the value was found and deleted, otherwise False.
         Works for ascending or descending arrays.
[==============================================================================}
function TDoubleArrayHelper.BinaryDelete(const x: Double; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryDelete}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryDelete}

{==============================================================================]
  <BinaryReplace>
  @action: Replaces a specific value in a sorted array with a new one.
  @note:   Uses binary search to locate and delete the old value,
           then reinserts the new one while maintaining sorted order.
           Returns True if the old value was found and replaced, otherwise False.
           Complexity: O(log n + n)
[==============================================================================}
function TDoubleArrayHelper.BinaryReplace(const oValue, nValue: Double; const aAscending: Boolean = True): Boolean; overload; {$DEFINE Skeleton_BinaryReplace}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryReplace}

{==============================================================================]
  <BinaryReplaceAll>
  @action: Replaces all occurrences of a specified value (oValue) with another
           value (nValue) in the array, preserving binary order if necessary.
  @note: Returns the number of replacements performed. If any substitution
         breaks sorted order, the array is re-sorted automatically using
         BinaryInsertionSort. The comparison order is determined by aAscending.
[==============================================================================}
function TDoubleArrayHelper.BinaryReplaceAll(const oValue, nValue: Double; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryReplaceAll}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryReplaceAll}
{$ENDIF}
