{$IFDEF HELPERS}
function Secure: Integer; overload;
function Fixid(const fIndex: Integer = 0): Integer; overload;
function Invalid(const fIndex: Integer = 0): Boolean; overload;
function Valid(const fIndex: Integer = 0): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Fixid>
  @action: Fixes a raw identifier/index by clamping it into valid array bounds.
  @note: Returns -1 on empty arrays, neutralizing potential range estimation errors.
[==============================================================================}
function MArrayHelper.Fixid(const fIndex: Integer = 0): Integer; overload;
var
  l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Result := -1
  else if (fIndex < 0) then
    Result := 0
  else if (fIndex >= l) then
    Result := (l - 1)
  else
    Result := fIndex;
end;

{==============================================================================]
  <Valid>
  @action: Analyzes the given index to determine if it safely exists within the array.
  @note: Returns True if the index is active and completely safe for read/write operations.
[==============================================================================}
function MArrayHelper.Valid(const fIndex: Integer = 0): Boolean; overload;
begin
  Result := ((fIndex > -1) and (fIndex < Self.Length));
end;

{==============================================================================]
  <Invalid>
  @action: Analyzes the given index to determine if it falls outside the valid array range.
  @note: Returns True if the index will cause a range error, or if called on an empty array.
[==============================================================================}
function MArrayHelper.Invalid(const fIndex: Integer = 0): Boolean; overload;
begin
  Result := ((fIndex <= -1) or (fIndex >= Self.Length));
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
{$ENDIF}
