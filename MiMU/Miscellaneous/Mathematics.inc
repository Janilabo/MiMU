{$IFDEF FUNCTIONS}
function AsNextPowerOf2(const x: Integer): Integer; overload;
function AtNextPowerOf2(const x: Integer): Integer; overload;
function CountNextPowerOf2(const x: Integer): Integer; overload;
function FindNextPowerOf2(const x: Integer): Integer; overload;
function Fiv(const a, b: Integer): Integer; overload;
function Fivision(const a, b: Integer): Integer; overload;
function ForNextPowerOf2(const x: Integer): Integer; overload;
function GetNextPowerOf2(const x: Integer): Integer; overload;
function GetPowersOf2(const upTo: Integer = 2147483647): TIntegerArray; overload;
function IsPowerOf2(const x: Integer): Boolean; overload;
function IsPowerOfTwo(const x: Integer): Boolean; overload;
function IsPowOf2(const x: Integer): Boolean; overload;
function NearestPowerOf2(const x: Integer): Integer; overload;
function NearestPowerOfTwo(const x: Integer): Integer; overload;
function NextPowerOf2(const x: Integer): Integer; overload;
function PowerOf2: TIntegerArray; overload;
function PowerOf2Array: TIntegerArray; overload;
function PowersOf2: TIntegerArray; overload;
function PowersOf2(const pCount: Integer): TIntegerArray; overload;
function PreviousPowerOf2(const x: Integer): Integer; overload;
function PreviousPowerOfTwo(const x: Integer): Integer; overload;
function ReturnNextPowerOf2(const x: Integer): Integer; overload;
function ToNextPowerOf2(const x: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function AsNextPowerOf2(const x: Integer): Integer; overload;
begin
  if (x < 2) then
    Exit(1);
  Result := 1;
  while (Result < x) do
    Result := (Result * 2);
end;

function AtNextPowerOf2(const x: Integer): Integer; overload;
const
  powers: array[0..31] of Integer =
    (1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
     65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216,
     33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, -2147483648);
var
  i: Integer;
begin
  if (x < 2) then
    Exit(1);
  for i := 0 to 30 do
    if (powers[i] >= x) then
      Exit(powers[i]);
  Result := Low(Integer);
end;

function CountNextPowerOf2(const x: Integer): Integer; overload;
var
  v, z: Integer;
begin
  if (x < 2) then
    Exit(1);
  if ((x and (x - 1)) = 0) then
    Exit(x);
  v := (x - 1);
  z := 0;
  while (v <> 0) do
  begin
    v := (v shr 1);
    Inc(z);
  end;
  Result := (1 shl z);
end;

function FindNextPowerOf2(const x: Integer): Integer; overload;
begin
  if (x < 2) then
    Exit(1);
  Result := (1 shl (Ceil(Log2(x))));
end;

{==============================================================================]
  <Fiv>
  @action: Performs floored integer division on two inputs, rounding towards 
           negative infinity.
  @note: Uses a branchless, expression-driven optimization. The result of a 
         standard truncating 'div' is adjusted down by 1 if there is a non-zero 
         remainder and the operands possess opposing signs.
[==============================================================================}
function Fiv(const a, b: Integer): Integer; overload;
begin
  Result := ((a div b) - Integer(((a mod b) <> 0) and ((a < 0) <> (b < 0))));
end;

{==============================================================================]
  <Fivision>
  @action: Performs floored integer division on two inputs, rounding towards 
           negative infinity.
  @note: Implements the exact same floored division logic as Fiv, but prioritizes
         readability by utilizing an explicit conditional branch (Dec) rather 
         than type-casting a boolean expression to an integer.
[==============================================================================}
function Fivision(const a, b: Integer): Integer; overload;
begin
  Result := (a div b);
  if (((a mod b) <> 0) and ((a < 0) <> (b < 0))) then
    Dec(Result);
end;

function ForNextPowerOf2(const x: Integer): Integer; overload;
var
  i, r: Integer;
begin
  if (x < 2) then
    Exit(1);
  Result := (x - 1);
  r := 1;
  Result := (Result or (Result shr r));
  for i := 0 to 4 do
    Result := (Result or (Result shr r.Increase((r * 2) - 1)));
  Result := (Result + 1);
end;

function GetNextPowerOf2(const x: Integer): Integer; overload;
begin
  if (x < 2) then
    Exit(1);
  Result := 2;
  while (Result < x) do
  begin
    Result := (Result shl 1);
    if (Result < 1) then
      Exit(High(Integer));
  end;
end;

function GetPowersOf2(const upTo: Integer = 2147483647): TIntegerArray; overload;
var
  i, p, l: Integer;
begin
  if (upTo < 1) then
    Exit([]);
  SetLength(Result, 31);
  l := 1;
  Result[0] := 1;
  for i := 1 to 30 do
    if (Result[i - 1] > upTo) then
      Break
    else
      Result[l.Increase] := (Result[i - 1] shl 1);
  if (Result[l - 1] > upTo) then
    Dec(l);
  SetLength(Result, l);
end;

function IsPowerOf2(const x: Integer): Boolean; overload;
begin
  Result := ((x > 0) and ((x and (x - 1)) = 0));
end;

function IsPowerOfTwo(const x: Integer): Boolean; overload;
begin
  Result := ((x > 0) and ((x and -x) = x));
end;

function IsPowOf2(const x: Integer): Boolean; overload;
const
  powers: array[0..30] of Integer =
    (1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
	 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216,
	 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824);
var
  M: Integer;
  R: TRange;
begin
  if (x <= 0) then
    Exit(False);
  R.Create(0, 30);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (powers[M] = x) then
      Exit(True);
    if (powers[M] < x) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := False;
end; 

function NearestPowerOf2(const x: Integer): Integer; overload;
var
  n, p: Integer;
begin
  if (x < 1) then
    Exit(1);
  if ((x and (x - 1)) = 0) then
    Exit(x);
  n := NextPowerOf2(x);
  p := (n shr 1);
  if (x.Distance(p) < x.Distance(n)) then
    Result := p
  else
    Result := n;
end;

function NearestPowerOfTwo(const x: Integer): Integer; overload;
var
  n, p: Integer;
begin
  if (x < 1) then
    Exit(1);
  if ((x and (x - 1)) = 0) then
    Exit(x);
  n := NextPowerOf2(x);
  p := (n shr 1);
  if (x < (p + (p shr 1))) then
    Result := p
  else
    Result := n;
end;

function NextPowerOf2(const x: Integer): Integer; overload;
begin
  if (x < 2) then
    Exit(1);
  if ((x and (x - 1)) = 0) then
    Exit(x);
  Result := 1;
  while (Result < x) do
    Result := (Result shl 1);
end;

function PowerOf2: TIntegerArray; overload;
const
  powers: array[0..30] of Integer = 
    (1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768,
	 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216,
	 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824);
begin
  SetLength(Result, 31);
  Move(powers[0], Result[0], (31 * SizeOf(Integer)));
end;

function PowerOf2Array: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 31);
  Result[0] := 1;
  for i := 1 to 30 do
    Result[i] := (Result[i - 1] * 2);
end;

function PowersOf2: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 31);
  for i := 0 to 30 do
    Result[i] := (1 shl i);
end;

function PowersOf2(const pCount: Integer): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Max(Min(pCount, 31), 0));
  for i := 0 to High(Result) do
    Result[i] := 1 shl i;
end;

function PreviousPowerOf2(const x: Integer): Integer; overload;
var
  r: Integer;
begin
  if (x < 1) then
    Exit(0);
  r := x;
  r := (r or (r shr 1));
  r := (r or (r shr 2));
  r := (r or (r shr 4));
  r := (r or (r shr 8));
  r := (r or (r shr 16));
  Result := (r - (r shr 1));
end;

function PreviousPowerOfTwo(const x: Integer): Integer; overload;
begin
  if (x < 1) then
    Exit(0);
  if ((x and (x - 1)) = 0) then
    Exit(x);
  Result := 1;
  while (Result <= x) do
    Result := (Result shl 1);
  Result := (Result shr 1);
end;

function ReturnNextPowerOf2(const x: Integer): Integer; overload;
begin
  if (x < 2) then
    Exit(1);
  if ((x and (x - 1)) = 0) then
    Exit(x);
  Result := (NextPowerOf2((x shr 1) + 1) shl 1);
end;

function ToNextPowerOf2(const x: Integer): Integer; overload;
var
  r: Integer;
begin
  if (x < 2) then
    Exit(1);
  r := (x - 1);
  r := (r or (r shr 1));
  r := (r or (r shr 2));
  r := (r or (r shr 4));
  r := (r or (r shr 8));
  r := (r or (r shr 16));
  Result := (r + 1);
end;
{$ENDIF}
