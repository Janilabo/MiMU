{$IFDEF HELPERS}
function AsValue: Int64; overload;
function Bevalue: Int64; overload;
function Number: Int64; overload;
function Numeric: Int64; overload;
function Numerical: Int64; overload;
function Numerize: Int64; overload;
function Numerized: Int64; overload;
function Numero: Int64; overload;
function ToValue: Int64; overload;
function Valuement: Int64; overload;
function Valuent: Int64; overload;
function ToInt64: Int64; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsValue>
  @action: Combines an array of single-digit integers into a single Int64 using 
           pure mathematical accumulation.
  @note:   Fast and memory-efficient. Assumes elements are single digits (0-9). 
           Will silently wrap on overflow unless overflow checking is on.
[==============================================================================}
function TIntegerArrayHelper.AsValue: Int64; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := ((Result * 10) + Self[i]);
end;

{==============================================================================]
  <Bevalue>
  @action: Concatenates an array of digits into a single 64-bit integer.
  @note: Assumes all array elements are single digits (0-9). Non-digit values 
         will cause a runtime string-to-integer conversion error.
[==============================================================================}
function TIntegerArrayHelper.Bevalue: Int64; overload;
var
  b: TStringBuilder;
  i: Integer;
begin
  b := TStringBuilder.Create;
  try
    for i := 0 to High(Self) do
      b.Append(Char(Ord('0') + Self[i]));
    Result := StrToInt64(b.ToString);
  finally
    b.Free;
  end;
end;

{==============================================================================]
  <Number>
  @action: Combines all integers in the array into a single Int64 value using unsafe pointer arithmetic to traverse the array sequentially.
  @note: Drops negative signs via Abs(). This is a highly optimized, low-overhead version of the single-pass mathematical approach,
         bypassing standard array indexing boundaries for maximum execution speed.
[==============================================================================}
function TIntegerArrayHelper.Number: Int64; overload;
var
  p, e: PInteger;
  v: Int64;
begin
  if (Self.Length = 0) then
    Exit(0);
  Result := 0;
  p := @Self[0];
  e := @Self[High(Self)];
  while (p <= e) do
  begin
    v := Abs(Int64(p^));
    Result := ((Result * POWERS_OF_TEN[v.DigitCount]) + v);
    Inc(p);
  end;
end;

{==============================================================================]
  <Numeric>
  @action: Combines all integers in the array into a single Int64 value by mathematically shifting the running total by the digit count of each subsequent element.
  @note: Drops negative signs via Abs(). Unlike the string-based version, this performs pure mathematical calculation using powers of ten,
         making it faster and avoiding string allocation overhead.
[==============================================================================}
function TIntegerArrayHelper.Numeric: Int64; overload;
var
  i, d: Integer;
  v: Int64;
begin
  Result := 0;
  for i := 0 to High(Self) do
  begin
    v := Abs(Int64(Self[i]));
    d := v.DigitCount;
    Result := ((Result * POWERS_OF_TEN[d]) + v);
  end;
end;

{==============================================================================]
  <Numerical>
  @action: Concatenates the absolute values of all integers in the array into a single numeric string using stack-allocated ShortStrings, then converts the final result into an Int64.
  @note: Drops negative signs via Abs(). Uses the built-in Str() procedure to convert integers to ShortStrings, avoiding heap allocations during the element loop before processing the final buffer.
[==============================================================================}
function TIntegerArrayHelper.Numerical: Int64; overload;
var
  i, j, t, l: Integer;
  s: ShortString;
  r: String;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  SetLength(r, (l * 20));
  t := 0;
  for i := 0 to High(Self) do
  begin
    Str(Abs(Int64(Self[i])), s);
    for j := 1 to System.Length(s) do
      r[t.Increment] := s[j];
  end;
  SetLength(r, t);
  Result := StrToInt64(r);
end;

{==============================================================================]
  <Numerize>
  @action: Concatenates the absolute string representations of all integers in the array into a single numeric string,
           then converts that string into a single Int64 value.
  @note: Pre-allocates buffer memory assuming the maximum possible string length for Int64 elements to optimize performance before trimming.
         Drops negative signs by using Abs().
[==============================================================================}
function TIntegerArrayHelper.Numerize: Int64; overload;
var
  i, j, l, t: Integer;
  r, s: string;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  SetLength(r, (l * 20));
  t := 0;
  for i := 0 to High(Self) do
  begin
    s := IntToStr(Abs(Self[i]));
    for j := 1 to System.Length(s) do
      r[t.Increment] := s[j];
  end;
  SetLength(r, t);
  Result := StrToInt64(r);
end;

{==============================================================================]
  <Numerized>
  @action: Combines all integers in the array into a single Int64 value using a two-pass mathematical approach that pre-calculates positional multiplier weights for each element.
  @note: Drops negative signs via Abs(). The first pass iterates backwards to construct an array of base-10 multipliers (weights) based on digit counts,
         while the second pass accumulates the total purely through multiplication and addition.
[==============================================================================}
function TIntegerArrayHelper.Numerized: Int64; overload;
var
  i: Integer;
  v, w: Int64;
  a: TInt64Array;
begin
  if (Self.Length = 0) then
    Exit(0);
  SetLength(a, Self.Length);
  w := 1;
  for i := High(Self) downto 0 do
  begin
    a[i] := w;
    w := (w * POWERS_OF_TEN[Abs(Int64(Self[i])).DigitCount]);
  end;
  Result := 0;
  for i := 0 to High(Self) do
    Inc(Result, (Abs(Int64(Self[i])) * a[i]));
end;

{==============================================================================]
  <Numero>
  @action: Concatenates the absolute values of all integers in the array into a single Int64 by first calculating the exact required buffer length,
           building the string via stack-allocated ShortStrings, and converting it.
  @note: Drops negative signs via Abs(). Performs a two-pass optimization: the first pass calculates the precise string buffer length needed,
         eliminating the over-allocation padding and final trimming step seen in previous versions.
[==============================================================================}
function TIntegerArrayHelper.Numero: Int64; overload;
var
  i, j, t: Integer;
  s: ShortString;
  r: String;
begin
  if (Self.Length = 0) then
    Exit(0);
  t := 0;
  for i := 0 to High(Self) do
    Inc(t, Abs(Int64(Self[i])).DigitCount);
  SetLength(r, t);
  t := 0;
  for i := 0 to High(Self) do
  begin
    Str(Abs(Int64(Self[i])), s);
    for j := 1 to System.Length(s) do
      r[t.Increment] := s[j];
  end;
  Result := StrToInt64(r);
end;

{==============================================================================]
  <ToValue>
  @action: Compines an array of individual digits back into a single Int64 value.
  @note: Pairs symmetrically as the inverse operation to TIntegerHelper.Digitment.
         Relies on string concatenation and may raise an EConvertError if the
         resulting value overflows Int64.
[==============================================================================}
function TIntegerArrayHelper.ToValue: Int64; overload;
var
  i: Integer;
  r: string;
begin
  r := '';
  for i := 0 to High(Self) do
    r := (r + IntToStr(Self[i]));
  Result := StrToInt64(r);
end;

{==============================================================================]
  <Valuement>
  @action: Blends an array of single-digit integers into a single Int64 value 
           using optimized, direct string buffer manipulation.
  @note: Highly efficient alternative to ToValue. Pre-allocates string memory 
         to maximize performance, but strictly requires array elements to be 
         single digits (0-9). Raises EConvertError if the result overflows 
         Int64 or contains invalid characters.
[==============================================================================}
function TIntegerArrayHelper.Valuement: Int64; overload;
var
  i: Integer;
  r: string;
begin
  SetLength(r, Self.Length);
  for i := 0 to High(Self) do
    r[i + 1] := Chr(Ord('0') + Self[i]);
  Result := StrToInt64(r);
end;

{==============================================================================]
  <Valuent>
  @action: Converts an array of single-digit integers into a single Int64 numeric value (e.g., [1, 2, 3] becomes 123).
  @note: Restricted to arrays of length 19 or fewer to prevent Int64 overflow. Returns -1 if the array exceeds this limit.
[==============================================================================}
function TIntegerArrayHelper.Valuent: Int64; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l > 19) then
    Exit(-1);
  Result := 0;
  for i := 0 to (l - 1) do
    Result := (Result + (Self[i] * POWERS_OF_TEN[(l - i) - 1]));
end;

{==============================================================================]
  <ToInt64>
  @action: Combines an array of individual digits back into a single Int64 integer.
  @note: Relies on a precalculated `POWERS_OF_TEN` array. Ensure the input array 
         length does not exceed the maximum precision of a 64-bit signed integer 
         (up to 19 digits) to prevent overflow or out-of-bounds errors.
[==============================================================================}
function TIntegerArrayHelper.ToInt64: Int64; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := (Result + (Self[i] * POWERS_OF_TEN[High(Self) - i]));
end;
{$ENDIF}
