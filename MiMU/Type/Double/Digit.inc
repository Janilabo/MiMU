{$IFDEF HELPERS}
function Digits: TIntegerArray;
function MinDecimal: Double;
function MaxDecimal: Double;
function Accuracy(const a: Integer): Double;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Digits>
  @action: Converts Double value (x) to digits of it.
           Example: 1234 => 1,2,3,4, -999 => 9,9,9
  @note: If x is negative value, the negative sign is ignored. 
[==============================================================================}
function TDoubleHelper.Digits: TIntegerArray; 
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
  <MinDecimal>
  @action: Returns the minimum decimal value.
           0.12345 => 0.00001
  @note: None
[==============================================================================}
function TDoubleHelper.MinDecimal: Double; 
var
  d: Double;
begin
  d := Frac(Self);
  if (d = 0) then
    Result := 0
  else
    if (d < 0) then
      Result := StrToFloat('-0,' + StringOfChar('0', (Length(FloatToStr(d)) - 4)) + '1')
    else
      Result := StrToFloat('0,' + StringOfChar('0', (Length(FloatToStr(d)) - 3)) + '1');
end;

{==============================================================================]
  <MaxDecimal>
  @action: Returns the maximum decimal value.
           0.12345 => 0.99999
  @note: None
[==============================================================================}
function TDoubleHelper.MaxDecimal: Double; 
var
  d: Double;
begin
  d := Frac(Self);
  if (d = 0) then
    Result := 0
  else
    if (d < 0) then
      Result := StrToFloat('-0,' + StringOfChar('9', (Length(FloatToStr(d)) - 3)))
    else
      Result := StrToFloat('0,' + StringOfChar('9', (Length(FloatToStr(d)) - 2)));
end;

{==============================================================================]
  <Acc>
  @action: Returns x with decimal accuracy of a. Examples below with '123.456789'.
           a=0    a=1     a=2       a=3       a=4         a=5
           123   123.4   123.45   123.456   123.4567   123.45678
  @note: None
[==============================================================================}
function TDoubleHelper.Accuracy(const a: Integer): Double; 
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
{$ENDIF}