{$IFDEF HELPERS}
function Accepts(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function Boundate(var aMin, aMax: MType): Boolean; overload;
function Boundify(var aMin, aMax: MType): Integer; overload;
function GetBounds(var AMin, AMax: MType): Boolean; overload;
function InBounds(const x: MType; const oAscending: Boolean = True): Boolean; overload;
function InsideBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function OutsideBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function OutOfBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function Rejects(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function WithinBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;

function Insider(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function Outsider(const item: MType; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Accepts>
  @action: Returns True if the specified item is acceptable with respect to
           the array’s boundary constraints.
  @note: The array must contain at least one element.
         The array is assumed to be sorted according to oAscending.
         The check is inclusive of the first and last elements.
         An empty array rejects all values.
[==============================================================================}
function MArrayHelper.Accepts(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((Self.Length > 0) and ((oAscending and ((item >= Self[0]) and (item <= Self[High(Self)]))) or ((not oAscending) and ((item <= Self[0]) and (item >= Self[High(Self)])))));
end;

{==============================================================================]
  <Boundate>
  @action: Computes the minimum and maximum bounds of an array in a single
          linear pass using High(Self) loop limits, returning True if the
          array is non-empty.
  @note:
  - Array validation: Sets Result := (Self.Length > 0). If empty, exits immediately
    returning False without mutating `aMin` or `aMax`.
  - Zero-offset iteration: Seeds `aMin` and `aMax` with `Self[0]`, then scans
    from index 1 through `High(Self)`.
  - Selective comparison: Utilizes `if not aMin.Minate(Self[i]) then aMax.Maxate(Self[i])`
    to bypass checking `Maxate` whenever a new minimum is found, optimizing
    evaluation passes on descending patterns.
  - Sibling relationship: Provides the Boolean status alternative to `Boundify`
    (which returns the total `Integer` element count).
[==============================================================================}
function MArrayHelper.Boundate(var aMin, aMax: MType): Boolean; overload;
var
  i: Integer;
begin
  Result := (Self.Length > 0);
  if not Result then
    Exit;
  aMin := Self[0];
  aMax := Self[0];
  for i := 1 to High(Self) do
    if not aMin.Minate(Self[i]) then
      aMax.Maxate(Self[i]);
end;

{==============================================================================]
  <Boundify>
  @action: Scans an array in a single linear pass to find its minimum and 
          maximum values while returning the total element count.
  @note: 
  - Initializes both `aMin` and `aMax` with the first element (`Self[0]`), then 
    evaluates remaining elements in a single `O(N)` loop.
  - Uses conditional branching (`else if`) to avoid redundant maximum checks 
    when a new minimum value is encountered.
  - Returns `0` immediately without modifying `aMin` or `aMax` if the array is 
    empty (`Result = 0`).
[==============================================================================}
function MArrayHelper.Boundify(var aMin, aMax: MType): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  if (Result = 0) then
    Exit;
  aMin := Self[0];
  aMax := Self[0];
  for i := 1 to (Result - 1) do
    if (aMin > Self[i]) then
      aMin := Self[i]
    else if (aMax < Self[i]) then
      aMax := Self[i];
end;

{==============================================================================]
  <GetBounds>
  @action: Scans the collection in a single pass to identify the minimum and 
           maximum values present.
  @note: 
    - Returns False if the array is empty; otherwise returns True.
    - Uses the '<' and '>' operators of MType to determine order.
    - Time Complexity: O(n), where n is the length of the array.
    - Space Complexity: O(1) as it performs an in-place comparison.
[==============================================================================}
function MArrayHelper.GetBounds(var AMin, AMax: MType): Boolean; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(False);
  Result := True;
  AMin := Self[0];
  AMax := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] < AMin) then
      AMin := Self[i]
    else if (Self[i] > AMax) then
      AMax := Self[i];
end;

{==============================================================================]
  <InBounds>
  @action: Checks whether the specified value lies within the bounds
           of the helper array.
  @note: Works on sorted arrays.
         If oAscending = True, assumes ascending sorted order.
         If oAscending = False, assumes descending sorted order.
         Returns False if the array is empty.
[==============================================================================}
function MArrayHelper.InBounds(const x: MType; const oAscending: Boolean = True): Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  case oAscending of
    True: Result := ((h > -1) and (x >= Self[0]) and (x <= Self[h]));
    False: Result := ((h > -1) and (x <= Self[0]) and (x >= Self[h]));
  end;
end;

{==============================================================================]
  <InsideBounds>
  @action  Returns True if the specified item lies within the minimum and
           maximum bounds of the array.
  @note    - The array must be sorted according to the value of oAscending.
           - Boundary values (first and last elements) are included.
           - Returns False if the array is empty.
           - Supports ascending or descending sorted arrays depending on oAscending.
[==============================================================================}
function MArrayHelper.InsideBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((Self.Length > 0) and ((oAscending and ((item >= Self[0]) and (item <= Self[High(Self)]))) or ((not oAscending) and ((item <= Self[0]) and (item >= Self[High(Self)])))));
end;

{==============================================================================]
  <OutOfBounds>
  @action: Returns True if the specified item lies outside the bounds of the
           array, or if the array is empty.
  @note: This function is the logical inverse of WithinBounds and assumes
         the same sort-order invariant.
[==============================================================================}
function MArrayHelper.OutOfBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := not Self.WithinBounds(item, oAscending);
end;

{==============================================================================]
  <OutsideBounds>
  @action: Returns True if the specified item lies outside the bounds of the
           array or if the array is empty.
  @note: - Logical inverse of InsideBounds.
         - The array must be sorted according to the value of oAscending.
         - Supports ascending or descending sorted arrays depending on oAscending.
[==============================================================================}
function MArrayHelper.OutsideBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := not Self.InsideBounds(item, oAscending);
end;

{==============================================================================]
  <Rejects>
  @action: Returns True if the specified item violates the array’s boundary
           constraints or if the array is empty.
  @note: This function is the logical inverse of Accepts.
         The array is assumed to be sorted according to oAscending.
         Boundary violations provide a strict (exclusive) rejection.
[==============================================================================}
function MArrayHelper.Rejects(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((Self.Length = 0) or ((oAscending and ((item < Self[0]) or (item > Self[High(Self)]))) or ((not oAscending) and ((item > Self[0]) or (item < Self[High(Self)])))));
end;

{==============================================================================]
  <WithinBounds>
  @action: Returns True if the specified item lies within the minimum and
           maximum bounds of the array.
  @note: The array must be sorted according to the value of oAscending.
         An empty array always returns False.
[==============================================================================}
function MArrayHelper.WithinBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  if oAscending then
    Result := not (Self.Empty or (item < Self[0]) or (item > Self[High(Self)]))
  else
    Result := not (Self.Empty or (item > Self[0]) or (item < Self[High(Self)]));
end;

{==============================================================================]
  <Insider>
  @action: Determines whether `item` falls within or directly on the inclusive range bounded by the first and last elements of a sorted array.
  @note: Operates in O(1) constant time by testing if `item` is bounded between `Self[0]` and `Self[High(Self)]`. Returns `False` if the array is empty.
         Functionally equivalent to `not Outsider(item, oAscending)`. Supports both ascending and descending order via `oAscending`.
[==============================================================================}
function MArrayHelper.Insider(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit(False);
  if oAscending then
    Result := ((item >= Self[0]) and (item <= Self[h]))
  else
    Result := ((item <= Self[0]) and (item >= Self[h]));
end;

{==============================================================================]
  <Outsider>
  @action: Determines whether `item` falls strictly outside the range bounded by the first and last elements of a sorted array.
  @note: Operates in O(1) constant time by evaluating boundary conditions against `Self[0]` and `Self[High(Self)]`. Returns `True` if the array is empty.
         Functionally equivalent to `not Insider(item, oAscending)`. Supports both ascending and descending order via `oAscending`.
[==============================================================================}
function MArrayHelper.Outsider(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit(True);
  if oAscending then
    Result := ((item < Self[0]) or (item > Self[h]))
  else
    Result := ((item > Self[0]) or (item < Self[h]));
end;
{$ENDIF}
