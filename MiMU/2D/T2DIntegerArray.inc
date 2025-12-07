{$DEFINE TVar := Integer}
{$DEFINE TArr := TIntegerArray}
{$DEFINE T2DArr := T2DIntegerArray}
{$DEFINE THelper := T2DIntegerArrayHelper}
{$DEFINE Sortable}

{$IFDEF TYPES}
ATIA = class
public
  class function Merge(const arr: T2DIntegerArray): TIntegerArray; overload; 
  class function Create(const width, height: Integer; const value: Integer = 0): T2DIntegerArray; overload; 
  class function Build(const rows, columns: Integer; const value: Integer = 0): T2DIntegerArray; overload; 
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DIntegerArrayHelper = type helper for T2DIntegerArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) or DEFINED(T2D)}
{$I Core.inc}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
class function ATIA.Merge(const arr: T2DIntegerArray): TIntegerArray; overload; 
var
  i, r: Integer;
begin
  SetLength(Result, Length(arr));
  if Result.Empty then
    Exit;
  r := 0;
  for i := 0 to High(arr) do
    if (arr[i].Size > 0) then
      Move(arr[i][0], Result[r.Increase(arr[i].Size)], (arr[i].Size * SizeOf(Integer)));
end;

class function ATIA.Create(const width, height: Integer; const value: Integer = 0): T2DIntegerArray; overload; 
var
  x, y: Integer;
begin
  SetLength(Result, height, width);
  for y := 0 to High(Result) do
    for x := 0 to High(Result[y]) do
      Result[y][x] := value;
end;

class function ATIA.Build(const rows, columns: Integer; const value: Integer = 0): T2DIntegerArray; overload; 
var
  r, c: Integer;
begin
  SetLength(Result, rows, columns);
  for r := 0 to High(Result) do
    for c := 0 to High(Result[r]) do
      Result[r][c] := value;
end;
{$ENDIF}