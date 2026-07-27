{$IFDEF HELPERS}
function Glean: Integer; overload;
function Gleaned: M2DArray; overload;
function Squeeze: Integer; overload;
function Squeezed: M2DArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Glean>
  @action: Removes all empty sub-arrays from Self in place, preserving the
           relative order of the remaining (non-empty) sub-arrays. Returns the new
           (post-removal) length of Self.
  @note: Mutating — Self is modified directly. Only whole sub-arrays are
         filtered — the contents of surviving sub-arrays are untouched. Result
         doubles as the write-cursor during the scan, via the Increase post-increment.
[==============================================================================}
function M2DArrayHelper.Glean: Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    if (Self[i].Length > 0) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;

{==============================================================================]
  <Gleaned>
  @action: Returns a copy of Self with all empty sub-arrays removed, preserving
           the relative order of the remaining (non-empty) sub-arrays.
  @note: Non-mutating; Self is left unchanged. Only whole sub-arrays are
         filtered — the contents of surviving sub-arrays are untouched.
[==============================================================================}
function M2DArrayHelper.Gleaned: M2DArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  for i := 0 to (Result.SetSize(Self.Length) - 1) do
    if (Self[i].Length > 0) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

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
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  r := 0;
  for i := 0 to High(Self) do
    if (Self[i].Size > 0) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;
{$ENDIF}