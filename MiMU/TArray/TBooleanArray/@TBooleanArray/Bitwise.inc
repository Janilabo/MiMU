{$IFDEF HELPERS}
function Bitify: Integer;
function Bitmask: Int64; overload;
function Bits: Integer;
function ToBits: Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Bitify>
  @action: Returns TBooleanArray as bits.
  @note: [True, False, True] => 5.
[==============================================================================}
function TBooleanArrayHelper.Bitify: Integer;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
  begin
    Result := (Result shl 1);
    if Self[i] then
      Inc(Result);
  end;
end;

{==============================================================================]
  <Bitmask>
  @action: Converts the elements of a boolean array into a 64-bit integer mask.
  @note: Maps each array index i (up to index 63) to bit position i using 
         64-bit shift logic (Int64(1) shl i). Returns 0 for empty arrays.
[==============================================================================}
function TBooleanArrayHelper.Bitmask: Int64; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to Min(High(Self), 63) do
    if Self[i] then
      Result := (Result or (Int64(1) shl i));
end;

{==============================================================================]
  <Bits>
  @action: Returns TBooleanArray as bits.
  @note: [True, False, True] => 5.
[==============================================================================}
function TBooleanArrayHelper.Bits: Integer;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := ((Result shl 1) or Self[i].Bit);
end;

{==============================================================================]
  <ToBits>
  @action: Returns TBooleanArray as bits.
  @note: [True, False, True] => 5.
[==============================================================================}
function TBooleanArrayHelper.ToBits: Integer;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := ((Result shl 1) or Byte(Self[i]));
end;
{$ENDIF}
