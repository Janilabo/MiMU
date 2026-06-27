{$IFDEF HELPERS}
function Accuracy(const a: Integer): Double; overload;
function Digits: TIntegerArray; overload;
function Fractional: Double; overload;
function MaxDecimal: Double; overload;
function MinDecimal: Double; overload;
function Whole: Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Acc>
  @action: Returns x with decimal accuracy of a. Examples below with '123.456789'.
           a=0    a=1     a=2       a=3       a=4         a=5
           123   123.4   123.45   123.456   123.4567   123.45678
  @note: None
[==============================================================================}
function TDoubleHelper.Accuracy(const a: Integer): Double; overload;
var
  d: Double;
  z: Boolean;
begin
  if (a < 1) then
    Exit(Self);
  Result := Int(Real(Self));
  d := Frac(Self);
  z := (d < 0.1);
  if z then
    d := (d + 0.1);
  Result := (Result + StrToFloatDef((',' + Copy(FloatToStr(d), 3, a)), 0));
  if z then
    Result := (Result - 0.1);
end;

{==============================================================================]
  <Digits>
  @action: Converts Double value (x) to digits of it.
           Example: 1234 => 1,2,3,4, -999 => 9,9,9
  @note: If x is negative value, the negative sign is ignored.
[==============================================================================}
function TDoubleHelper.Digits: TIntegerArray; overload;
var
  s: string;
  l, i: Integer;
begin
  s := FloatToStr(Abs(Self));
  l := Length(s);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := StrToInt(s[i + 1]);
end;

{==============================================================================]
  <Fractional>
  @action: Returns the fractional part of a floating-point number.
  @note: Uses System.Int to isolate the integer portion. For negative numbers, 
         note that System.Int rounds toward zero, meaning Fractional retains 
         the original sign (e.g., -5.75 returns -0.75).
[==============================================================================}
function TDoubleHelper.Fractional: Double; overload;
begin
  Result := (Self - System.Int(Self));
end;

{==============================================================================]
  <MaxDecimal>
  @action: Returns the maximum decimal value.
           0.12345 => 0.99999
  @note: None
[==============================================================================}
function TDoubleHelper.MaxDecimal: Double; overload;
var
  d: Double;
begin
  d := Frac(Self);
  if (d = 0) then
    Result := 0
  else if (d < 0) then
    Result := StrToFloat('-0,' + StringOfChar('9', (Length(FloatToStr(d)) - 3)))
  else
    Result := StrToFloat('0,' + StringOfChar('9', (Length(FloatToStr(d)) - 2)));
end;

{==============================================================================]
  <MinDecimal>
  @action: Returns the minimum decimal value.
           0.12345 => 0.00001
  @note: None
[==============================================================================}
function TDoubleHelper.MinDecimal: Double; overload;
var
  d: Double;
begin
  d := Frac(Self);
  if (d = 0) then
    Result := 0
  else if (d < 0) then
    Result := StrToFloat('-0,' + StringOfChar('0', (Length(FloatToStr(d)) - 4)) + '1')
  else
    Result := StrToFloat('0,' + StringOfChar('0', (Length(FloatToStr(d)) - 3)) + '1');
end;

{==============================================================================]
  <Whole>
  @action: Returns the whole integer component of the floating-point number.
  @note: Drops the decimal portion by subtracting the fractional component
         from the original value (e.g., 123.4567 - 0.4567 = 123.0).
[==============================================================================}
function TDoubleHelper.Whole: Double; overload;
begin
  Result := (Self - System.Frac(Self));
end;
{$ENDIF}
