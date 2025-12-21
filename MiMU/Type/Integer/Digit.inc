{$IFDEF HELPERS}
function DigitCount: Integer;
function Digitz: TIntegerArray;
function Digits: TIntegerArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <DigitCount>
  @action: Returns count of digits Integer x value contains.
  @note: If x is negative value, the negative sign is ignored.
         Works with -2147483648 - 2147483647!
[==============================================================================}
function TIntegerHelper.DigitCount: Integer;
var
  a, n, m: Int64;
begin
  a := Abs(Self);
  Result := 0;
  m := 10;
  repeat
    n := (a mod m);
    m := (m * 10);
  until ((Result.Increment = 10) or (n = a));
end;

{==============================================================================]
  <Digitz>
  @action: Converts Integer value (x) to digits of it.
           Example: 1234 => 1,2,3,4, -999 => 9,9,9
  @note: If x is negative value, the negative sign is ignored.
         Works with -2147483648 - 2147483647!
[==============================================================================}
function TIntegerHelper.Digitz: TIntegerArray;
var
  a, n, m: Int64;
  i, r: Integer;
begin
  a := Abs(Self);
  r := 0;
  SetLength(Result, 10);
  m := 10;
  repeat
    n := (a mod m);
    Result[r] := (n div (m div 10));
    m := (m * 10);
  until ((r.Increment = 10) or (n = a));
  SetLength(Result, r);
  for i := 0 to ((r div 2) - 1) do
    Swap(Result[i], Result[(r - i) - 1]);
end;

{==============================================================================]
  <Digits>
  @action: Converts Integer value (x) to digits of it.
           Example: 1234 => 1,2,3,4, -999 => 9,9,9
  @note: If x is negative value, the negative sign is ignored.
         Works with -2147483648 - 2147483647!
[==============================================================================}
function TIntegerHelper.Digits: TIntegerArray;
var
  s: string;
  l, i: Integer;
begin
  s := IntToStr(Abs(Self));
  l := Length(s);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := StrToInt(s[i + 1]);
end;
{$ENDIF}