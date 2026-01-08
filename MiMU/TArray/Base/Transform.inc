{$IFDEF HELPERS}
function As2D(const rows, columns: Integer): M2DArray; overload; cdecl;
function As2D(const width: Integer): M2DArray; overload; cdecl;
function To2D(const rows, columns: Integer): M2DArray; overload; cdecl;
function To2D(const height: Integer): M2DArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <As2D>
  @action: Converts 1D array to 2D by rows and columns.
  @note: TIA := [1,2,3,4,5,6];
         TIA.To2D(2, 3) = [[1, 2, 3], [4, 5, 6]]
         TIA.To2D(3, 2) = [[1, 2], [3, 4], [5, 6]]
[==============================================================================}
function MArrayHelper.As2D(const rows, columns: Integer): M2DArray; overload; cdecl;
var
  l, i: Integer;
begin
  l := Self.Length;
  SetLength(Result, rows, columns);
  for i := 0 to ((rows * columns) - 1) do
    if (i < l) then
      Result[i div columns][i mod columns] := Self[i];
end;

{==============================================================================]
  <As2D>
  @action: Converts 1D array to 2D by width.
  @note: None.
[==============================================================================}
function MArrayHelper.As2D(const width: Integer): M2DArray; overload; cdecl;
var
  l, h, i, r, c: Integer;
begin
  l := Self.Length;
  h := Ceil(l / width);
  SetLength(Result, h, width);
  i := 0;
  for r := 0 to (h - 1) do
    for c := 0 to (width - 1) do
      if (i < l) then
        Result[r][c] := Self[i.Increase];
end;

{==============================================================================]
  <To2D>
  @action: Converts 1D array to 2D by rows and columns.
  @note: Make sure Length(array) equals rows*columns (otherwise returns [])! Working examples below.
         TIA := [1,2,3,4,5,6];
         TIA.To2D(2, 3) = [[1, 2, 3], [4, 5, 6]]
         TIA.To2D(3, 2) = [[1, 2], [3, 4], [5, 6]]
[==============================================================================}
function MArrayHelper.To2D(const rows, columns: Integer): M2DArray; overload; cdecl;
var
  i, r, c, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, rows, columns);
  i := 0;
  for r := 0 to (rows - 1) do
    for c := 0 to (columns - 1) do
      if (i < l) then
        Result[r][c] := Self[i.Increase];
end;

{==============================================================================]
  <To2D>
  @action: Converts 1D array to 2D by height.
  @note: 
[==============================================================================}
function MArrayHelper.To2D(const height: Integer): M2DArray; overload; cdecl;
var
  l, w, i, r, c: Integer;
begin
  l := Self.Length;
  w := Ceil(l / height);
  SetLength(Result, height, w);
  i := 0;
  for r := 0 to (height - 1) do
    for c := 0 to (w - 1) do
      if (i < l) then
        Result[r][c] := Self[i.Increase];
end;
{$ENDIF}