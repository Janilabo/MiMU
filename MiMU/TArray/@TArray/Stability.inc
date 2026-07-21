{$IFDEF HELPERS}
function Claim: Integer; overload;
function Downsize(const aCeiling: Integer = -1): Integer; overload;
function Fixid(const aIndex: Integer = 0): Integer; overload;
function Invalid(const aIndex: Integer = 0): Boolean; overload;
function Secure: Integer; overload;
function Sever: Integer; overload;
function Upsize(const aFloor: Integer; const null: MType): Integer; overload;
function Upsize(const aFloor: Integer = 1): Integer; overload;
function Valid(const aIndex: Integer = 0): Boolean; overload;
function Wipe: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Claim>
  @action: Forces Self to become a uniquely-owned array, detached from any
           shared reference, and returns its length.
  @note: Uses the grow-then-shrink SetLength trick to force reallocation
         when Self's reference count is greater than 1.
[==============================================================================}
function MArrayHelper.Claim: Integer; overload;
begin
  Result := Self.Length;
  SetLength(Self, (Result + 1));
  SetLength(Self, Result);
end;

{==============================================================================]
  <Downsize>
  @action: Enforces a maximum structural size ceiling on the array and returns 
           the exact count of evicted elements.
  @note: Passing a negative threshold (or omitting the argument) triggers a 
         full Wipe. Returns 0 if the array is already within bounds.
[==============================================================================}
function MArrayHelper.Downsize(const aCeiling: Integer = -1): Integer; overload;
var
  l: Integer;
begin
  l := Self.Length;
  if (aCeiling < 0) then
  begin
    Self := nil;
    Exit(l);
  end;
  if (l > aCeiling) then
    SetLength(Self, aCeiling);
  Result := (l - Self.Length);
end;

{==============================================================================]
  <Fixid>
  @action: Fixes a raw identifier/index by clamping it into valid array bounds.
  @note: Returns -1 on empty arrays, neutralizing potential range estimation errors.
[==============================================================================}
function MArrayHelper.Fixid(const aIndex: Integer = 0): Integer; overload;
var
  l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Result := -1
  else if (aIndex < 0) then
    Result := 0
  else if (aIndex >= l) then
    Result := (l - 1)
  else
    Result := aIndex;
end;

{==============================================================================]
  <Invalid>
  @action: Analyzes the given index to determine if it falls outside the valid array range.
  @note: Returns True if the index will cause a range error, or if called on an empty array.
[==============================================================================}
function MArrayHelper.Invalid(const aIndex: Integer = 0): Boolean; overload;
begin
  Result := ((aIndex <= -1) or (aIndex >= Self.Length));
end;

{==============================================================================]
  <Secure>
  @action: Forces the array into its own unique memory block and returns its length.
  @note: Breaks shared references (Copy-on-Write) before providing the count,
         making it ideal for initializing for-loops safely.
[==============================================================================}
function MArrayHelper.Secure: Integer; overload;
begin
  Result := Self.Length;
  SetLength(Self, Result);
end;

{==============================================================================]
  <Sever>
  @action: Forces Self to become a uniquely-owned array, detached from any
           shared reference, and returns its length.
  @note: Uses the grow-then-shrink trick in a single expression: Alloc grows
         capacity to Length + 1 (forcing FPC to reallocate when Self's
         refcount is greater than 1), then returns Length - 1 of that request
         — i.e. the original length — which SetSize then applies, restoring
         Self to its true size with freshly-owned, non-shared memory.
[==============================================================================}
function MArrayHelper.Sever: Integer; overload;
begin
  Result := Self.SetSize(Self.Alloc(Self.Length + 1));
end;

{==============================================================================]
  <Upsize>
  @action: Enforces a minimum structural size floor on the array, initializing 
           any newly allocated trailing slots with a default fallback value.
  @note: Returns the exact count of new elements appended to reach the floor.
         If the array is already at or above the floor limit, it returns 0.
[==============================================================================}
function MArrayHelper.Upsize(const aFloor: Integer; const null: MType): Integer; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  if (aFloor <= l) then
    Exit(0);
  SetLength(Self, aFloor);
  for i := l to (aFloor - 1) do
    Self[i] := null;
  Result := (Self.Length - l);
end;

{==============================================================================]
  <Upsize>
  @action: Enforces a minimum structural size floor on the array and returns 
           the exact count of newly allocated elements.
  @note: Omitting the argument defaults to 1, guaranteeing the array has at 
         least one physical element slot. New slots contain uninitialized data.
[==============================================================================}
function MArrayHelper.Upsize(const aFloor: Integer = 1): Integer; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  if (aFloor <= l) then
    Exit(0);
  SetLength(Self, aFloor);
  Result := (Self.Length - l);
end;

{==============================================================================]
  <Valid>
  @action: Analyzes the given index to determine if it safely exists within the array.
  @note: Returns True if the index is active and completely safe for read/write operations.
[==============================================================================}
function MArrayHelper.Valid(const aIndex: Integer = 0): Boolean; overload;
begin
  Result := ((aIndex > -1) and (aIndex < Self.Length));
end;

{==============================================================================]
  <Wipe>
  @action: Deep-clears the array by neutralizing its heap footprint and 
           returns the count of cleared elements.
  @note: Sets the instance to nil, forcing full resource deallocation 
         while safely returning the original length.
[==============================================================================}
function MArrayHelper.Wipe: Integer; overload;
begin
  Result := Self.Length;
  Self := nil; 
end;
{$ENDIF}
