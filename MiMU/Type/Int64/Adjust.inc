{$IFDEF HELPERS}
function Decrease(const N: Int64 = 1): Int64; overload; cdecl;
function Decrease(const B: Boolean): Int64; overload; cdecl;
function Decrement(const N: Int64 = 1): Int64; overload; cdecl;
function Decrement(const B: Boolean): Int64; overload; cdecl;
function Increase(const N: Int64 = 1): Int64; overload; cdecl;
function Increase(const B: Boolean): Int64; overload; cdecl;
function Increment(const N: Int64 = 1): Int64; overload; cdecl;
function Increment(const B: Boolean): Int64; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Decrease>
  @action: Decreases the Int64 value x by N.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function TInt64Helper.Decrease(const N: Int64 = 1): Int64; overload; cdecl;
begin
  Result := Self;
  Self := (Self - N);
end;

{==============================================================================]
  <Decrease>
  @action: Decreases the Int64 value x by 1 if B is true.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function TInt64Helper.Decrease(const B: Boolean): Int64; overload; cdecl;
begin
  Result := Self;
  if B then
    Self := (Self - 1);
end;

{==============================================================================]
  <Decrement>
  @action: Decreases the Int64 value x by N.
  @note: Returns the decreased x!
[==============================================================================}
function TInt64Helper.Decrement(const N: Int64 = 1): Int64; overload; cdecl;
begin
  Self := (Self - N);
  Result := Self;
end;

{==============================================================================]
  <Decrement>
  @action: Decreases the Int64 value x by 1 if B is true.
  @note: Returns the decreased x!
[==============================================================================}
function TInt64Helper.Decrement(const B: Boolean): Int64; overload; cdecl;
begin
  if B then
    Self := (Self - 1);
  Result := Self;
end;

{==============================================================================]
  <Increase>
  @action: Increases the Int64 value x by N.
  @note: Returns x before increasing it with N!
[==============================================================================}
function TInt64Helper.Increase(const N: Int64 = 1): Int64; overload; cdecl;
begin
  Result := Self;
  Self := (Self + N);
end;

{==============================================================================]
  <Increase>
  @action: Increases the Int64 value x by 1 if B is true.
  @note: Returns x before increasing it!
[==============================================================================}
function TInt64Helper.Increase(const B: Boolean): Int64; overload; cdecl;
begin
  Result := Self;
  if B then
    Self := (Self + 1);
end;

{==============================================================================]
  <Increment>
  @action: Increases the Int64 value x by N.
  @note: Returns the increased x!
[==============================================================================}
function TInt64Helper.Increment(const N: Int64 = 1): Int64; overload; cdecl;
begin
  Self := (Self + N);
  Result := Self;
end;

{==============================================================================]
  <Increment>
  @action: Increases the Int64 value x by 1 if B is true.
  @note: Returns the increased x!
[==============================================================================}
function TInt64Helper.Increment(const B: Boolean): Int64; overload; cdecl;
begin
  if B then
    Self := (Self + 1);
  Result := Self;
end;
{$ENDIF}