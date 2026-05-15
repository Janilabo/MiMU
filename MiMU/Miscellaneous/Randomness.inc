{$IFDEF FUNCTIONS}
function Rand(const R: Integer = 2): Integer; overload;
function Randify(const R: Integer = 2): Integer; overload;
function RandIn(const R: Integer = 2; const N: Integer = 2): Integer; overload;
function Rando(const R: Integer = 2): Integer; overload;
function Random2(const x: Integer; const r: Integer = 2): Integer; overload;
function RandomB: Boolean; overload;
function RandomBit: Byte; overload;
function RandomEx(const l: Integer = 2): Integer; overload;
function RandomLower(const R: Integer = 2): Integer; overload;
function RandomMax(const x: Integer; const r: Integer = 2): Integer; overload;
function RandomMean(const x: Integer; const sample: Integer = 10): Integer; overload;
function RandomMin(const x: Integer; const r: Integer = 2): Integer; overload;
function Randomish(const R: Integer = 2): Integer; overload;
function RandomSample(const x: Integer; const size: Integer): TIntegerArray; overload;
function RandomUpper(const R: Integer = 2): Integer; overload;
function RandOut(const R: Integer = 2; const N: Integer = 2): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function Rand(const R: Integer = 2): Integer; overload;
begin
  case Sign(R) of
    0: Exit(0);
    1: Result := Random(R);
    -1: Result := -(Random(-R));
  end;
end;

function Randify(const R: Integer = 2): Integer; overload;
begin
  if (R > 0) then
    Result := Random(R)
  else if (R < 0) then
    Result := -Random(-R)
  else
    Result := 0;
end;

function RandIn(const R: Integer = 2; const N: Integer = 2): Integer; overload;
var
  i, v: Integer;
begin
  if (N < 1) then
    Exit(Rand(R));
  v := Abs(R);
  Result := Random(v);
  i := 0;
  while ((Result > 0) and (i.Increase < N)) do
    Result := Min(Result, Random(v));
  if (R < 0) then
    Result := -Result;
end;

function Rando(const R: Integer = 2): Integer; overload;
begin
  if (R = 0) then
    Exit(0);
  Result := (Random(Abs(R)) * Sign(R));
end;

function Random2(const x: Integer; const r: Integer = 2): Integer; overload;
var
  i: Integer;
begin
  for i := 1 to Random(r + 1) do
    Random(x);
  Result := Random(x);
end;

function RandomB: Boolean; overload;
begin
  Result := (Random(2) = 1);
end;

function RandomBit: Byte; overload;
begin
  Result := Random(2);
end;

function RandomEx(const l: Integer = 2): Integer; overload;
begin
  if (l > -1) then
    Result := Random(l)
  else
    Result := (Random(Abs(l)) * -1);
end;

function RandomLower(const R: Integer = 2): Integer; overload;
begin
  Result := Min(Random(R), Random(R));
end;

function RandomMax(const x: Integer; const r: Integer = 2): Integer; overload;
var
  i: Integer;
begin
  Result := -2147483648;
  for i := 1 to r do
    Result := Max(Result, Random(x));
end;

function RandomMean(const x: Integer; const sample: Integer = 10): Integer; overload;
begin
  Result := Round(RandomSample(x, sample).Mean);
end;

function RandomMin(const x: Integer; const r: Integer = 2): Integer; overload;
var
  i: Integer;
begin
  Result := 2147483647;
  for i := 1 to r do
    Result := Min(Result, Random(x));
end;

function Randomish(const R: Integer = 2): Integer; overload;
begin
  if (R = 0) then
    Exit(0);
  Result := Random(Abs(R));
  if ((R shr 31) <> 0) then
    Result := -Result;
end;

function RandomSample(const x: Integer; const size: Integer): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, size);
  for i := 0 to High(Result) do
    Result[i] := Random(x);
end;

function RandomUpper(const R: Integer = 2): Integer; overload;
begin
  Result := Max(Random(R), Random(R));
end;

function RandOut(const R: Integer = 2; const N: Integer = 2): Integer; overload;
var
  i, m, v: Integer;
begin
  if (N < 1) then
    Exit(Rand(R));
  v := Abs(R);
  m := (v - 1);
  Result := Random(v);
  i := 0;
  while ((Result < m) and (i.Increase < N)) do
    Result := Max(Result, Random(v));
  if (R < 0) then
    Result := -Result;
end;
{$ENDIF}