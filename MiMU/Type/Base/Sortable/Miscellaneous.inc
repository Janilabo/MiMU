{$IFDEF FUNCTIONS}
function Arrangement3(const A, B, C: MType): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Arrangement3>
  @action: Returns the arrangement index (0-5) for three values.
  @note: An arrangement describes the order/permutation of values.
  @return: 0=ABC, 1=ACB, 2=BAC, 3=BCA, 4=CAB, 5=CBA
[==============================================================================}
function Arrangement3(const A, B, C: MType): Integer; overload;
begin
  case (A <= B) of
    True:
    if (B <= C) then
      Result := 0
    else if (A <= C) then
      Result := 1
    else
      Result := 4;
    False:
    if (A <= C) then
      Result := 2
    else if (B <= C) then
      Result := 3
    else
      Result := 5;
  end;
end;
{$ENDIF}
