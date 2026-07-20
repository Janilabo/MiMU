{$IFDEF HELPERS}
function Clear: Boolean; overload;
function Destruct: Integer; overload;
function Free: Integer; overload;
function Kill: Integer; overload;
function Nullify: Integer; overload;
function Recreate(const arrSize: Integer): Boolean; overload;
function Reinitialize(const aSize: Integer = 1): Integer; overload;
function Release: MArray; overload;
function Repossess(const newSize: Integer = 0): MArray; overload;
function Reset: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Clear>
  @action: SetLength(arr, 0) and returns true if items existed before doing it.
  @note: None.
[==============================================================================}
function MArrayHelper.Clear: Boolean; overload;
begin
  Result := (Self.Length > 0);
  SetLength(Self, 0);
end;

{==============================================================================]
  <Destruct>
  @action: Thoroughly destroys array contents, finalizes managed types, and frees memory.
  @note: More comprehensive than Clear - ensures all elements are properly finalized.
  @returns: Number of elements that were destroyed.
[==============================================================================}
function MArrayHelper.Destruct: Integer; overload;
begin
  Result := Self.Size;
  Finalize(Self);
  SetLength(Self, 0);
end;

{==============================================================================]
  <Free>
  @action: Result := Length(Self) + SetLength(Self, 0) combo.
  @note: None.
[==============================================================================}
function MArrayHelper.Free: Integer; overload;
begin
  Result := Self.Size;
  SetLength(Self, 0);
end;

{==============================================================================]
  <Kill>
  @action: Combination of Length(arr) + SetLength(arr, 0).
  @note: Returns the length of the arr!
[==============================================================================}
function MArrayHelper.Kill: Integer; overload;
begin
  Result := Self.Size;
  SetLength(Self, 0);
end;

{==============================================================================]
  <Nullify>
  @action: Deallocates the array memory and reduces its length to zero.
  @note: Returns 0 to represent the new length or an initialized state code.
[==============================================================================}
function MArrayHelper.Nullify: Integer; overload;
begin
  Result := 0;
  SetLength(Self, 0);
end;

{==============================================================================]
  <Recreate>
  @action: Clear the array and reallocate to arrSize (negative = previous length).
  @note: Returns True if array was non-empty and arrSize <> 0.
[==============================================================================}
function MArrayHelper.Recreate(const arrSize: Integer): Boolean; overload;
var
  l: Integer;
begin
  l := Self.Length;
  Result := ((l > Self.Nullify) or (arrSize <> 0));
  if Result then
    if (arrSize < 0) then
      SetLength(Self, l)
    else
      SetLength(Self, arrSize);
end;

{==============================================================================]
  <Reinitialize>
  @action: Resets the array to a fresh state with the specified size.
  @note: Existing data is destroyed. Returns the new size (clamped to >= 0).
[==============================================================================}
function MArrayHelper.Reinitialize(const aSize: Integer = 1): Integer; overload;
begin
  Result := Max(0, aSize);
  if (Result > Self.Nullify) then
    SetLength(Self, Result);
end;

{==============================================================================]
  <Release>
  @action: Creates a copy of the dynamic array and clears the source array to release memory/ownership.
  @note: Uses System.Copy to clone the source dynamic array into Result, then resets the caller's length to 0.
[==============================================================================}
function MArrayHelper.Release: MArray; overload;
begin
  Result := System.Copy(Self);
  SetLength(Self, 0);
end;

{==============================================================================]
  <Repossess>
  @action: Transfers the current array contents to Result, clears the original array, and optionally pre-allocates a new capacity.
  @note: Copies Self into Result, zeroes out Self, and then resizes Self to newSize if a value greater than 0 is specified.
[==============================================================================}
function MArrayHelper.Repossess(const newSize: Integer = 0): MArray; overload;
begin
  Result := System.Copy(Self);
  if (newSize > Self.Nullify) then
    SetLength(Self, newSize);
end;

{==============================================================================]
  <Reset>
  @action: Resets all elements of the array to default values while preserving its structure.
  @note: Returns the number of elements that were reset.
[==============================================================================}
function MArrayHelper.Reset: Integer; overload;
begin
  Result := Self.Size;
  SetLength(Self, 0);
  SetLength(Self, Result);
end;
{$ENDIF}
