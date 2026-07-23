{$IFDEF HELPERS}
function SetSize(const sSize: UInt32 = 1): Integer; overload;
function SetSize(const sSize: UInt32; const iCreated: Char): Integer; overload;
function Size: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <SetSize>
  @action: Resizes the string to the specified length.
  @note: Adjusts string length directly via `SetLength`.
         Uninitialized newly allocated characters retain default memory state. Returns the updated string length.
[==============================================================================}
function TStringHelper.SetSize(const sSize: UInt32 = 1): Integer; overload;
begin
  SetLength(Self, sSize);
  Result := Self.Size;
end;

{==============================================================================]
  <SetSize>
  @action: Resizes the string to the specified length and initializes any newly added characters with a default character.
  @note: Preserves existing characters up to the previous length, then fills all newly appended index positions with `iCreated`.
         Returns the updated string length.
[==============================================================================}
function TStringHelper.SetSize(const sSize: UInt32; const iCreated: Char): Integer; overload;
var
  i, l: Integer;
begin
  l := Self.Size;
  SetLength(Self, sSize);
  Result := Self.Size;
  for i := (l + 1) to Result do
    Self[i] := iCreated;
end;

{==============================================================================]
  <Size>
  @action: System.Length()
  @note: Returns length of the Self.
[==============================================================================}
function TStringHelper.Size: Integer; overload;
begin
  Result := System.Length(Self);
end;
{$ENDIF}
