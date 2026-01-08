{$IFDEF HELPERS}
function Even: Boolean; cdecl; inline;
function Odd: Boolean; cdecl; inline;
function Parity: Byte; cdecl; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Even>
  @action: Returns true if Int64 value x is an even number.
  @note: None
[==============================================================================}
function TInt64Helper.Even: Boolean; cdecl; inline;
begin
  Result := ((Self mod 2) = 0);
end;

{==============================================================================]
  <Odd>
  @action: Returns true if Int64 value x is an odd number.
  @note: None
[==============================================================================}
function TInt64Helper.Odd: Boolean; cdecl; inline;
begin
  Result := ((Self mod 2) <> 0);
end;

{==============================================================================]
  <Parity>
  @action: Returns the Int64 Parity Bit as Byte.
  @note: 0 = even, 1 = odd.
[==============================================================================}
function TInt64Helper.Parity: Byte; cdecl; inline;
begin
  Result := (Self mod 2);
end;
{$ENDIF}