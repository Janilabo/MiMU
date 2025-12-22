{$IFDEF METHODS}
function RandomB: Boolean; overload; 
function RandomBit: Byte; overload; 
function RandomSample(const x: Integer; const size: Integer): TIntegerArray; overload; 
function RandomMean(const x: Integer; const sample: Integer = 10): Integer; overload; 
function Random2(const x: Integer; const r: Integer = 2): Integer; overload; 
function RandomMax(const x: Integer; const r: Integer = 2): Integer; overload; 
function RandomMin(const x: Integer; const r: Integer = 2): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function RandomB: Boolean; overload; 
begin
  Result := (Random(2) = 1);
end;

function RandomBit: Byte; overload; 
begin
  Result := Random(2);
end;

function RandomSample(const x: Integer; const size: Integer): TIntegerArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, size);
  for i := 0 to High(Result) do
    Result[i] := Random(x);
end;

function RandomMean(const x: Integer; const sample: Integer = 10): Integer; overload; 
begin
  Result := Round(RandomSample(x, sample).Mean);
end;

function Random2(const x: Integer; const r: Integer = 2): Integer; overload; 
var
  i: Integer;
begin
  for i := 1 to Random(r + 1) do
    Random(x);
  Result := Random(x);
end;

function RandomMax(const x: Integer; const r: Integer = 2): Integer; overload; 
var
  i: Integer;
begin
  Result := -2147483648;
  for i := 1 to r do
    Result := Max(Result, Random(x));
end;

function RandomMin(const x: Integer; const r: Integer = 2): Integer; overload; 
var
  i: Integer;
begin
  Result := 2147483647;
  for i := 1 to r do
    Result := Min(Result, Random(x));
end;
{$ENDIF}