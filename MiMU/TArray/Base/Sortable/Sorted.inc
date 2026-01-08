{$IFDEF HELPERS}
function Sortable: Boolean; overload; cdecl;
function Sorted(const aAscending: Boolean = True): Boolean; overload; cdecl;
function IsSorted(const aAscending: Boolean = True): Boolean; overload; cdecl;
function IsSorted(const iStart, iStop: Integer; const aAscending: Boolean = True): Boolean; overload; cdecl;
function IsSorted(const indexes: TRange; const aAscending: Boolean = True): Boolean; overload; cdecl;
function IsSorted(const index: Integer; const aAscending: Boolean = True): Boolean; overload; cdecl;
function Sortedness: Boolean; overload; cdecl;
function SortednessEx(const stride: Integer = 16): Boolean; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Sortable>
  @action: Checks whether the array contains at least two different elements.
           Returns True if sorting would change the array order.
  @note: Arrays with all equal elements, a single element, or empty arrays
         return False.
[==============================================================================}
function MArrayHelper.Sortable: Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Sorted>
  @action: Returns true if array arr is in ascending/descending order by aAscending.
  @note: By default checking for ascending order.
[==============================================================================}
function MArrayHelper.Sorted(const aAscending: Boolean = True): Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 0 to (High(Self) - 1) do
    if (aAscending and (Self[i] > Self[i + 1])) or ((not aAscending) and (Self[i] < Self[i + 1])) then
      Exit(False);
  Result := (not Self.Empty);
end;

{==============================================================================]
  <IsSorted>
  @action: Checks whether the entire array is sorted in ascending or descending order.
  @note:   Returns True if all elements are in the correct order according to aAscending.
[==============================================================================}
function MArrayHelper.IsSorted(const aAscending: Boolean = True): Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if ((aAscending and (Self[i] < Self[i - 1])) or ((not aAscending) and (Self[i] > Self[i - 1]))) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <IsSorted>
  @action: Checks whether the elements between iStart and iStop are in correct
           ascending or descending order.
  @note: The range [iStart..iStop] is automatically normalized and clamped to
         valid array bounds. Returns True if all elements within the range
         follow the specified order.
[==============================================================================}
function MArrayHelper.IsSorted(const iStart, iStop: Integer; const aAscending: Boolean = True): Boolean; overload; cdecl;
var
  i, s, e, h: Integer;
begin
  h := High(Self);
  if (h <= 0) then
    Exit(True);
  s := Max(0, Min(iStart, iStop));
  e := Min(Max(iStart, iStop), h);
  if (s >= e) then
    Exit(True);
  for i := (s + 1) to e do
    if ((aAscending and (Self[i] < Self[i - 1])) or ((not aAscending) and (Self[i] > Self[i - 1]))) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <IsSorted>
  @action: Determines whether the array elements within the specified range
           (given as TRange) are ordered in ascending or descending order.
  @note: Internally calls the (iStart, iStop) overload. The range is
         automatically normalized and clamped to valid array bounds.
         Returns True if all elements within the range follow the specified order.
[==============================================================================}
function MArrayHelper.IsSorted(const indexes: TRange; const aAscending: Boolean = True): Boolean; overload; cdecl;
begin
  Result := Self.IsSorted(indexes.start, indexes.stop, aAscending);
end;

{==============================================================================]
  <IsSorted>
  @action: Checks whether the element at the specified index is correctly
           positioned relative to its immediate neighbors according to
           ascending or descending order.
  @note: Returns True if the element at the given index maintains proper
         order with adjacent elements. Boundary or single-element arrays are
         considered sorted. Returns False for out-of-range indices.
[==============================================================================}
function MArrayHelper.IsSorted(const index: Integer; const aAscending: Boolean = True): Boolean; overload; cdecl;
var
  h: Integer;
begin
  h := High(Self);
  if (index < 0) or (index > h) then
    Exit(False);
  if (h = 0) then
    Exit(True);
  if ((index < h) and (aAscending and (Self[index] > Self[index + 1])) or ((not aAscending) and (Self[index] < Self[index + 1]))) then
    Exit(False);
  if ((index > 0) and (aAscending and (Self[index] < Self[index - 1])) or ((not aAscending) and (Self[index] > Self[index - 1]))) then
    Exit(False);
  Result := True;
end;

{==============================================================================]
  <Sortedness>
  @action: Checks whether the array is monotonic (either ascending or descending).
           Performs a two-phase check: a fast global trend detection from both ends,
           followed by a full local adjacency check to ensure strict monotonicity.
  @note: Returns True for arrays of length 0 or 1.
         Uses Integer_Sign(Self[L], Self[R]) to detect initial trend.
         Efficient for large arrays due to early exit if disorder is detected.
         This version checks every element in both phases.
[==============================================================================}
function MArrayHelper.Sortedness: Boolean; overload; cdecl;
var
  L, R, D: Integer;
begin
  L := 0;
  R := High(Self);
  Result := True;
  if (R <= L) then
    Exit;
  D := 0;
  repeat
    case D of
      0: D := Self[L].Sign(Self[R]);
      1: Result := (Self[L] <= Self[R]);
      -1: Result := (Self[L] >= Self[R]);
    end;
  until ((not Result) or ((L.Increment > R.Decrement)));
  if (not Result) then
    Exit;
  L := -1;
  case (D > 0) of
    False:
    while (L.Increment < R) do
      if (Self[L] < Self[L + 1]) then
        Exit(False);
    True:
    while (L.Increment < R) do
      if (Self[L] > Self[L + 1]) then
        Exit(False);
  end;
end;

{==============================================================================]
  <SortednessEx>
  @action: Enhanced version of Sortedness with configurable stride.
           Performs a subsampled global trend check (using left and right indices
           at intervals of "stride") to quickly detect gross disorder,
           followed by a full local adjacency check if the array passes the global phase.
  @note: Default stride = 16; larger values reduce global comparisons but may delay detection
         of small local disorder. Returns True for arrays of length 0 or 1.
         Useful for extremely large arrays where global trend violation is likely.
[==============================================================================}
function MArrayHelper.SortednessEx(const stride: Integer = 16): Boolean; overload; cdecl;
var
  L, R, D: Integer;
begin
  L := 0;
  R := High(Self);
  Result := True;
  if (R <= L) then
    Exit;
  D := 0;
  repeat
    case D of
      0: D := Self[L].Sign(Self[R]);
      1: Result := (Self[L] <= Self[R]);
      -1: Result := (Self[L] >= Self[R]);
    end;
  until ((not Result) or (L.Increment(stride) >= R.Decrement(stride)));
  if not Result then
    Exit;
  L := -1;
  R := High(Self);
  case (D >= 0) of
    False:
    while (L.Increment < R) do
      if (Self[L] < Self[L + 1]) then
        Exit(False);
    True:
    while (L.Increment < R) do
      if (Self[L] > Self[L + 1]) then
        Exit(False);
  end;
end;
{$ENDIF}