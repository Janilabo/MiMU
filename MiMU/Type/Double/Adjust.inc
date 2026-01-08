{$IFDEF HELPERS}
function Decrease(const N: Double = 1): Double; overload; cdecl;
function Decrease(const B: Boolean): Double; overload; cdecl;
function Decrement(const N: Double = 1): Double; overload; cdecl;
function Decrement(const B: Boolean): Double; overload; cdecl;
function Increase(const N: Double = 1): Double; overload; cdecl;
function Increase(const B: Boolean): Double; overload; cdecl;
function Increment(const N: Double = 1): Double; overload; cdecl;
function Increment(const B: Boolean): Double; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Decrease>
  @action: Decreases the Double value x by N.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function TDoubleHelper.Decrease(const N: Double = 1): Double; overload; cdecl;
begin
  Result := Self;
  Self := (Self - N);
end;

{==============================================================================]
  <Decrease>
  @action: Decreases the Double value x by 1 if B is true.
  @note: Returns x before decreasing it!
[==============================================================================}
function TDoubleHelper.Decrease(const B: Boolean): Double; overload; cdecl;
begin
  Result := Self;
  if B then
    Self := (Self - 1);
end;

{==============================================================================]
  <Decrement>
  @action: Decreases the Double value x by N.
  @note: Returns the decreased x!
[==============================================================================}
function TDoubleHelper.Decrement(const N: Double = 1): Double; overload; cdecl;
begin
  Self := (Self - N);
  Result := Self;
end;

{==============================================================================]
  <Decrement>
  @action: Decreases the Double value x by 1 if B is true.
  @note: Returns the decreased x!
[==============================================================================}
function TDoubleHelper.Decrement(const B: Boolean): Double; overload; cdecl;
begin
  if B then
    Self := (Self - 1);
  Result := Self;
end;

{==============================================================================]
  <Increase>
  @action: Increases the Double value x by N.
  @note: Returns x before increasing it with N!
[==============================================================================}
function TDoubleHelper.Increase(const N: Double = 1): Double; overload; cdecl;
begin
  Result := Self;
  Self := (Self + N);
end;

{==============================================================================]
  <Increase>
  @action: Increases the Double value x by 1 if B is true.
  @note: Returns x before increasing it!
[==============================================================================}
function TDoubleHelper.Increase(const B: Boolean): Double; overload; cdecl;
begin
  Result := Self;
  if B then
    Self := (Self + 1);
end;

{==============================================================================]
  <Increment>
  @action: Increases the Double value x by N.
  @note: Returns the increased x!
[==============================================================================}
function TDoubleHelper.Increment(const N: Double = 1): Double; overload; cdecl;
begin
  Self := (Self + N);
  Result := Self;
end;

{==============================================================================]
  <Increment>
  @action: Increases the Double value x by 1 if B is true.
  @note: Returns the increased x!
[==============================================================================}
function TDoubleHelper.Increment(const B: Boolean): Double; overload; cdecl;
begin
  if B then
    Self := (Self + 1);
  Result := Self;
end;
{$ENDIF}