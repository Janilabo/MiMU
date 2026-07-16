{$IFDEF HELPERS}
function Squeeze: Integer; overload;
function Squeezed: M2DArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Squeeze>
  @action: Removes empty subarrays from the current 2D point array (in place).
  @note: Returns the number of removed (empty) subarrays; the array itself is resized.
[==============================================================================}
function M2DArrayHelper.Squeeze: Integer; overload;
var
  i, r, l: Integer;
begin
  l := Self.Length;
  r := 0;
  for i := 0 to High(Self) do
    if (Self[i].Size > 0) then
      Self[r.Increase] := Self[i];
  Result := (l - r);
  if (Result > 0) then
    SetLength(Self, r);
end;

{==============================================================================]
  <Squeezed>
  @action: Creates and returns a copy of the array with all empty subarrays removed.
  @note: The original array remains unchanged; the result is the squeezed copy.
[==============================================================================}
function M2DArrayHelper.Squeezed: M2DArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, Self.Length);
  if Result.Empty then
    Exit;
  r := 0;
  for i := 0 to High(Self) do
    if (Self[i].Size > 0) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;
{$ENDIF}