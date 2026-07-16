{$IFDEF HELPERS}
function Destroy: Int64; overload;
function Free: Int64; overload;
function Kill: Integer; overload;
function Kill(const k2D: TIntegerArray): Int64; overload;
function Pull: M2DArray; overload;
function Recreate(const arrSize: Integer): Boolean; overload;
function Reset: Int64; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Destroy>
  @action: Combination of Length(arr) + SetLength(arr, 0) for array indexes by k2D.
  @note: Completely wipes the array.
[==============================================================================}
function M2DArrayHelper.Destroy: Int64; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
  begin
    Result := (Result + Self[i].Size);
    SetLength(Self[i], 0);	
  end;
  SetLength(Self, 0);
end;

{==============================================================================]
  <Free>
  @action: Result := Length(Self) + SetLength(Self, 0) combo for 2D array
  @note: None.
[==============================================================================}
function M2DArrayHelper.Free: Int64; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := (Result + Self[i].Size);
  SetLength(Self, 0);
end;

{==============================================================================]
  <Kill>
  @action: Combination of Length(arr) + SetLength(arr, 0).
  @note: Returns the length of main array (1st dimension)!
[==============================================================================}
function M2DArrayHelper.Kill: Integer; overload;
begin
  Result := Self.Length;
  SetLength(Self, 0);
end;

{==============================================================================]
  <Kill>
  @action: Combination of Length(arr) + SetLength(arr, 0) for array indexes by k2D.
  @note: Supports custom start index! Returns the modified arr.
        Unsafe, simply goes through the given indexes, no safety checks!
		Use with caution, correctly.
[==============================================================================}
function M2DArrayHelper.Kill(const k2D: TIntegerArray): Int64; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(k2D) do
  begin
    Result := (Result + Self[k2D[i]].Size);
    SetLength(Self[k2D[i]], 0);	
  end;
end;

{==============================================================================]
  <Pull>
  @action: Returns the contents of the array and leaves it empty.
  @note: After calling Pull, Self.Length = 0.
[==============================================================================}
function M2DArrayHelper.Pull: M2DArray; overload;
var
  i, j: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Self) do
  begin
    SetLength(Result[i], Self[i].Size);
    for j := 0 to High(Self[i]) do
      Result[i][j] := Self[i][j];
  end;
  SetLength(Self, 0);
end;

{==============================================================================]
  <Recreate>
  @action: Clear the array and reallocate to arrSize (negative = previous length).
  @note: Returns True if array was non-empty and/or arrSize <> 0.
[==============================================================================}
function M2DArrayHelper.Recreate(const arrSize: Integer): Boolean; overload;
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
function M2DArrayHelper.Reset: Int64; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
  begin
    Result := (Result + Self[i].Size);
    SetLength(Self[i], 0);
  end;
end;
{$ENDIF}