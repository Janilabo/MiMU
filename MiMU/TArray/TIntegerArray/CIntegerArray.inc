{$IFDEF TYPES}
CIntegerArray = class
public
  class function Combine(const A, B: TIntegerArray): TIntegerArray; overload;
  class function Init(var arr: TIntegerArray): Integer; overload;
  class function Reverse(var arr: TIntegerArray): Boolean; overload;
  class function Reversed(const arr: TIntegerArray): TIntegerArray; overload;
  class function Unique(var arr: TIntegerArray): Integer; overload;
end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
class function CIntegerArray.Combine(const A, B: TIntegerArray): TIntegerArray; overload;
var
  x, y: Integer;
begin
  x := Length(A);
  y := Length(B);
  SetLength(Result, (x + y));
  if (x > 0) then
    Move(A[0], Result[0], (x * SizeOf(Integer)));
  if (y > 0) then
    Move(B[0], Result[x], (y * SizeOf(Integer)));
end;

class function CIntegerArray.Init(var arr: TIntegerArray): Integer; overload;
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], (Result * SizeOf(Integer)), 0);
end;

class function CIntegerArray.Reverse(var arr: TIntegerArray): Boolean; overload;
var
  a: TIntegerArray;
  i: Integer;
begin
  Result := (Length(arr) > 1);
  if not Result then
    Exit;
  SetLength(a, Length(arr));
  for i := 0 to High(arr) do
    a[i] := arr[High(arr) - i];
  Move(a[0], arr[0], (Length(arr) * SizeOf(Integer)));
end;

class function CIntegerArray.Reversed(const arr: TIntegerArray): TIntegerArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, Length(arr));
  if (Length(arr) = 0) then
    Exit;
  Move(arr[0], Result[0], (Length(arr) * SizeOf(Integer)));
  for i := 0 to (High(Result) div 2) do
  begin
    r := Result[i];
    Move(Result[High(Result) - i], Result[i], SizeOf(Integer));
    Move(r, Result[High(Result) - i], SizeOf(Integer));
  end;
end;

class function CIntegerArray.Unique(var arr: TIntegerArray): Integer; overload;
var
  x, y, z: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  y := High(arr);
  if (y > 0) then
  begin
    z := 0;
    r := arr.Bounds;
    b.Create(r.Size, False);
    for x := 0 to y do
      if b[arr[x] - r.start].Enable then
        arr[z.Increase] := arr[x];
    SetLength(b, 0);
    SetLength(arr, z);
    Result := ((y + 1) - z);
  end else
    Result := 0;
end;
{$ENDIF}