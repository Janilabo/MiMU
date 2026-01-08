{$IFDEF HELPERS}
function WithinBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
function OutOfBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
function Accepts(const item: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
function Rejects(const item: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
function InsideBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
function OutsideBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <WithinBounds>
  @action: Returns True if the specified item lies within the minimum and
           maximum bounds of the array.
  @note: The array must be sorted according to the value of oAscending.
         An empty array always returns False.
[==============================================================================}
function MArrayHelper.WithinBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  if oAscending then
    Result := not (Self.Empty or (item < Self[0]) or (item > Self[High(Self)]))
  else
    Result := not (Self.Empty or (item > Self[0]) or (item < Self[High(Self)]));
end;

{==============================================================================]
  <OutOfBounds>
  @action: Returns True if the specified item lies outside the bounds of the
           array, or if the array is empty.
  @note: This function is the logical inverse of WithinBounds and assumes
         the same sort-order invariant.
[==============================================================================}
function MArrayHelper.OutOfBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  Result := not Self.WithinBounds(item, oAscending);
end;

{==============================================================================]
  <Accepts>
  @action: Returns True if the specified item is acceptable with respect to
           the array’s boundary constraints.
  @note: The array must contain at least one element.
         The array is assumed to be sorted according to oAscending.
         The check is inclusive of the first and last elements.
         An empty array rejects all values.
[==============================================================================}
function MArrayHelper.Accepts(const item: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  Result := ((Self.Length > 0) and ((oAscending and ((item >= Self[0]) and (item <= Self[High(Self)]))) or ((not oAscending) and ((item <= Self[0]) and (item >= Self[High(Self)])))));
end;

{==============================================================================]
  <Rejects>
  @action: Returns True if the specified item violates the array’s boundary
           constraints or if the array is empty.
  @note: This function is the logical inverse of Accepts.
         The array is assumed to be sorted according to oAscending.
         Boundary violations provide a strict (exclusive) rejection.
[==============================================================================}
function MArrayHelper.Rejects(const item: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  Result := ((Self.Length = 0) or ((oAscending and ((item < Self[0]) or (item > Self[High(Self)]))) or ((not oAscending) and ((item > Self[0]) or (item < Self[High(Self)])))));
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
function MArrayHelper.InsideBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  Result := ((Self.Length > 0) and ((oAscending and ((item >= Self[0]) and (item <= Self[High(Self)]))) or ((not oAscending) and ((item <= Self[0]) and (item >= Self[High(Self)])))));
end;

{==============================================================================]
  <OutsideBounds>
  @action: Returns True if the specified item lies outside the bounds of the
           array or if the array is empty.
  @note: - Logical inverse of InsideBounds.
         - The array must be sorted according to the value of oAscending.
         - Supports ascending or descending sorted arrays depending on oAscending.
[==============================================================================}
function MArrayHelper.OutsideBounds(const item: MType; const oAscending: Boolean = True): Boolean; overload; cdecl;
begin
  Result := not Self.InsideBounds(item, oAscending);
end;
{$ENDIF}