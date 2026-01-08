{$IFDEF HELPERS}
function Clear: Boolean; overload; cdecl;
function Free: Integer; overload; cdecl;
function Kill: Integer; overload; cdecl;
function Recreate(const arrSize: Integer): Boolean; overload; cdecl;
function Reset: Integer; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Clear>
  @action: SetLength(arr, 0) and returns true if items existed before doing it.
  @note: None.
[==============================================================================}
function MArrayHelper.Clear: Boolean; overload; cdecl;
begin
  Result := (Self.Length > 0);
  SetLength(Self, 0);
end;

{==============================================================================]
  <Free>
  @action: Result := Length(Self) + SetLength(Self, 0) combo.
  @note: None.
[==============================================================================}
function MArrayHelper.Free: Integer; overload; cdecl;
begin
  Result := Self.Size;
  SetLength(Self, 0);
end;

{==============================================================================]
  <Kill>
  @action: Combination of Length(arr) + SetLength(arr, 0).
  @note: Returns the length of the arr!
[==============================================================================}
function MArrayHelper.Kill: Integer; overload; cdecl;
begin
  Result := Self.Size;
  SetLength(Self, 0);
end;

{==============================================================================]
  <Recreate>
  @action: Clear the array and reallocate to arrSize (negative = previous length).
  @note: Returns True if array was non-empty and arrSize <> 0.
[==============================================================================}
function MArrayHelper.Recreate(const arrSize: Integer): Boolean; overload; cdecl;
var
  l: Integer;
begin
  l := Self.Length;
  Result := ((l > 0) or (arrSize <> 0));
  SetLength(Self, 0);
  if Result then
    if (arrSize < 0) then
      SetLength(Self, l)
    else
      SetLength(Self, arrSize);
end;

{==============================================================================]
  <Reset>
  @action: Resets all elements of the array to default values while preserving its structure.
  @note: Returns the number of elements that were reset.
[==============================================================================}
function MArrayHelper.Reset: Integer; overload; cdecl;
begin
  Result := Self.Size;
  SetLength(Self, 0);
  SetLength(Self, Result);
end;
{$ENDIF}