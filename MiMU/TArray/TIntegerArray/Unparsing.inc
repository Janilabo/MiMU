{$IFDEF HELPERS}
function AsValue: Int64; overload;
function Bevalue: Int64; overload;
function ToValue: Int64; overload;
function Valuement: Int64; overload;
function Valuent: Int64; overload;
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
const
  POW10: array[0..18] of Int64 = (
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000,
    1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000,
    100000000000000, 1000000000000000, 10000000000000000, 100000000000000000,
    1000000000000000000
  );
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l > 19) then
    Exit(-1);
  Result := 0;
  for i := 0 to (l - 1) do
    Result := (Result + (Self[i] * POW10[(l - i) - 1]));
end;
{$ENDIF}
