{$IFDEF HELPERS}
function Bits: Integer;
function Bitify: Integer;
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
