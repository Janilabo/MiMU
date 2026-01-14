{$IFDEF HELPERS}
function Even: Boolean;
function Odd: Boolean;
function Parity: Byte;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Even>
  @action: Returns true if Int64 value x is an even number.
  @note: None
[==============================================================================}
function TInt64Helper.Even: Boolean;
begin
  Result := ((Self mod 2) = 0);
end;

{==============================================================================]
  <Odd>
  @action: Returns true if Int64 value x is an odd number.
  @note: None
[==============================================================================}
function TInt64Helper.Odd: Boolean;
begin
  Result := ((Self mod 2) <> 0);
end;

{==============================================================================]
  <Parity>
  @action: Returns the Int64 Parity Bit as Byte.
  @note: 0 = even, 1 = odd.
[==============================================================================}
function TInt64Helper.Parity: Byte;
begin
  Result := (Self mod 2);
end;
{$ENDIF}