{$IFDEF METHODS}
class function Create(const width, height: Integer; const value: Integer = 0): T2DIntegerArray; overload; 
class function Build(const rows, columns: Integer; const value: Integer = 0): T2DIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
class function C2DIntegerArray.Create(const width, height: Integer; const value: Integer = 0): T2DIntegerArray; overload; 
var
  x, y: Integer;
begin
  SetLength(Result, height, width);
  for y := 0 to High(Result) do
    for x := 0 to High(Result[y]) do
      Result[y][x] := value;
end;

class function C2DIntegerArray.Build(const rows, columns: Integer; const value: Integer = 0): T2DIntegerArray; overload; 
var
  r, c: Integer;
begin
  SetLength(Result, rows, columns);
  for r := 0 to High(Result) do
    for c := 0 to High(Result[r]) do
      Result[r][c] := value;
end;
{$ENDIF}