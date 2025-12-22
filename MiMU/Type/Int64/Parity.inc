{$IFDEF HELPERS}
function Parity: Byte; inline;
function Even: Boolean; inline;
function Odd: Boolean; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Parity>
  @action: Returns the Int64 Parity Bit as Byte.
  @note: 0 = even, 1 = odd.
[==============================================================================}
function TInt64Helper.Parity: Byte; inline;
begin
  Result := (Self mod 2);
end;

{==============================================================================]
  <Even>
  @action: Returns true if Int64 value x is an even number.
  @note: None
[==============================================================================}
function TInt64Helper.Even: Boolean; inline;
begin
  Result := ((Self mod 2) = 0);
end;

{==============================================================================]
  <Odd>
  @action: Returns true if Int64 value x is an odd number.
  @note: None
[==============================================================================}
function TInt64Helper.Odd: Boolean; inline;
begin
  Result := ((Self mod 2) <> 0);
end;
{$ENDIF}