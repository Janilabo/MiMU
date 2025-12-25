{$IFDEF HELPERS}
function BinaryAppend(const x: Integer; const aAscending: Boolean = True): Integer;
function BinaryAdd(const x: Integer; const aAscending: Boolean = True): TIntegerArray;
function BinaryGrow(const x: Integer; const aAscending: Boolean = True): Boolean;
function BinaryInsert(const x: Integer; const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryAppend>
  @action: Binary Append method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the index x was added to.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryAppend(const x: Integer; const aAscending: Boolean = True): Integer; {$DEFINE Skeleton_BinaryAppend}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryAppend}

{==============================================================================]
  <BinaryAdd>
  @action: Binary Add method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the arr with x.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryAdd(const x: Integer; const aAscending: Boolean = True): TIntegerArray; {$DEFINE Skeleton_BinaryAdd}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryAdd}

{==============================================================================]
  <BinaryGrow>
  @action: Inserts an integer x into the array while maintaining sorted order.
           Works with ascending or descending order based on aAscending.
  @note: Returns True if the value was inserted, False if it already exists.
[==============================================================================}
function TIntegerArrayHelper.BinaryGrow(const x: Integer; const aAscending: Boolean = True): Boolean; {$DEFINE Skeleton_BinaryGrow}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryGrow}

{==============================================================================]
  <BinaryInsert>
  @action: Insert an integer into a sorted array using binary search, preserving order.
  @note: Returns the index where the element was inserted. Supports ascending or descending order.
[==============================================================================}
function TIntegerArrayHelper.BinaryInsert(const x: Integer; const aAscending: Boolean = True): Integer; overload; {$DEFINE Skeleton_BinaryInsert}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryInsert}
{$ENDIF}
