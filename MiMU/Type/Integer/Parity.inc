{$IFDEF HELPERS}
function Even: Boolean; cdecl; inline;
function IsEven: Boolean; cdecl; inline;
function IsOdd: Boolean; cdecl; inline;
function Odd: Boolean; cdecl; inline;
function Parity: Byte; cdecl; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Even>
  @action: Returns true if Integer value x is an even number.
  @note: None
[==============================================================================}
function TIntegerHelper.Even: Boolean; cdecl; inline;
begin
  Result := ((Self mod 2) = 0);
end;

{==============================================================================]
  <IsEven>
  @action: Returns true if Integer value x is an even number.
  @note: None
[==============================================================================}
function TIntegerHelper.IsEven: Boolean; cdecl; inline;
begin
  Result := ((Self and 1) = 0);
end;

{==============================================================================]
  <IsOdd>
  @action: Returns true if Integer value x is an odd number.
  @note: None
[==============================================================================}
function TIntegerHelper.IsOdd: Boolean; cdecl; inline;
begin
  Result := ((Self and 1) = 1);
end;

{==============================================================================]
  <Odd>
  @action: Returns true if Integer value x is an odd number.
  @note: None
[==============================================================================}
function TIntegerHelper.Odd: Boolean; cdecl; inline;
begin
  Result := ((Self mod 2) <> 0);
end;

{==============================================================================]
  <Parity>
  @action: Returns the Integer Parity Bit as Byte.
  @note: 0 = even, 1 = odd.
[==============================================================================}
function TIntegerHelper.Parity: Byte; cdecl; inline;
begin
  Result := (Self mod 2);
end;
{$ENDIF}