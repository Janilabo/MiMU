{$IFDEF HELPERS}
function Glean: Integer; overload;
function Gleaned: M2DArray; overload;
function Reap: Integer; overload;
function Reaped: M2DArray; overload;
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
  <Reap>
  @action: Removes all empty sub-arrays from Self in place, preserving the
           relative order of the remaining (non-empty) sub-arrays, via a full
           element-by-element deep copy into each surviving row's position. Returns
           the total number of elements retained across all rows.
  @note: Mutating — Self is modified directly. Unlike Glean, which relocates
         surviving rows by reference reassignment (O(1) per row, aliasing the
         original row data), Reap resizes and manually copies every element into
         place (O(n) per row), leaving each surviving row's data fully independent
         of its prior storage. Result reports total element count, not row count.
[==============================================================================}
function M2DArrayHelper.Reap: Integer; overload;
var
  i, j, r: Integer;
begin
  Result := 0;
  r := -1;
  for i := 0 to High(Self) do
    if (Self[i].Length > 0) then
    begin
      Inc(Result, Self[i].Length);
      for j := 0 to Self[r.Increment].Alloc(Self[i].Length) do
        Self[r][j] := Self[i][j];
    end;
  SetLength(Self, (r + 1));
end;

{==============================================================================]
  <Reaped>
  @action: Returns a copy of Self with all empty sub-arrays removed,
           preserving the relative order of the remaining (non-empty) sub-arrays, via
           a full element-by-element deep copy of each surviving row into the result.
  @note: Non-mutating; Self is left unchanged. Unlike Gleaned, which builds
         the result by reference reassignment (aliasing the original rows), Reaped
         resizes and manually copies every element into the result, so the
         surviving rows in Result are fully independent of Self's underlying data.
[==============================================================================}
function M2DArrayHelper.Reaped: M2DArray; overload;
var
  i, j, r: Integer;
begin
  r := -1;
  for i := 0 to (Result.SetSize(Self.Length) - 1) do
    if (Self[i].Length > 0) then
    for j := 0 to Result[r.Increment].Alloc(Self[i].Length) do
      Result[r][j] := Self[i][j];
  SetLength(Result, (r + 1));
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