{$IFDEF HELPERS}
function Even: Boolean; inline;
function IsEven: Boolean; inline;
function IsOdd: Boolean; inline;
function Odd: Boolean; inline;
function Parity: Byte; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Even>
  @action: Returns true if Integer value x is an even number.
  @note: None
[==============================================================================}
function TIntegerHelper.Even: Boolean; inline;
begin
  Result := ((Self mod 2) = 0);
end;

{==============================================================================]
  <IsEven>
  @action: Returns true if Integer value x is an even number.
  @note: None
[==============================================================================}
function TIntegerHelper.IsEven: Boolean; inline;
begin
  Result := ((Self and 1) = 0);
end;

{==============================================================================]
  <IsOdd>
  @action: Returns true if Integer value x is an odd number.
  @note: None
[==============================================================================}
function TIntegerHelper.IsOdd: Boolean; inline;
begin
  Result := ((Self and 1) = 1);
end;

{==============================================================================]
  <Odd>
  @action: Returns true if Integer value x is an odd number.
  @note: None
[==============================================================================}
function TIntegerHelper.Odd: Boolean; inline;
begin
  Result := ((Self mod 2) <> 0);
end;

{==============================================================================]
  <Parity>
  @action: Returns the Integer Parity Bit as Byte.
  @note: 0 = even, 1 = odd.
[==============================================================================}
function TIntegerHelper.Parity: Byte; inline;
begin
  Result := (Self mod 2);
end;
{$ENDIF}