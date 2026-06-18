{$IFDEF HELPERS}
function AsValue: Int64; overload;
function ToValue: Int64; overload;
function Valuement: Int64; overload;
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
{$ENDIF}
