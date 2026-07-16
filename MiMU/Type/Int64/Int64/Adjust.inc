{$IFDEF HELPERS}
function Decrease(const N: Int64 = 1): Int64; overload;
function Decrease(const B: Boolean; const N: Int64 = 1): Int64; overload;
function Decrement(const N: Int64 = 1): Int64; overload;
function Decrement(const B: Boolean; const N: Int64 = 1): Int64; overload;
function Increase(const N: Int64 = 1): Int64; overload;
function Increase(const B: Boolean; const N: Int64 = 1): Int64; overload;
function Increment(const N: Int64 = 1): Int64; overload;
function Increment(const B: Boolean; const N: Int64 = 1): Int64; overload;
function X(const N: Int64 = 1): Int64; overload;
function X2(const N: Int64 = 1): Int64; overload;
function X3(const N: Int64 = 1): Int64; overload;
function X4(const N: Int64 = 1): Int64; overload;
function X10(const N: Int64 = 1): Int64; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function X(var val: Int64; const N: Int64 = 1): Int64; overload;
function X2(var val: Int64; const N: Int64 = 1): Int64; overload;
function X3(var val: Int64; const N: Int64 = 1): Int64; overload;
function X4(var val: Int64; const N: Int64 = 1): Int64; overload;
function X10(var val: Int64; const N: Int64 = 1): Int64; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Decrease>
  @action: Decreases the Int64 value x by N.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function TInt64Helper.Decrease(const N: Int64 = 1): Int64; overload;
begin
  Result := Self;
  Self := (Self - N);
end;

{==============================================================================]
  <Decrease>
  @action: Decreases the Int64 value x by N if B is true.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function TInt64Helper.Decrease(const B: Boolean; const N: Int64 = 1): Int64; overload;
begin
  Result := Self;
  if B then
    Self := (Self - N);
end;

{==============================================================================]
  <Decrement>
  @action: Decreases the Int64 value x by N.
  @note: Returns the decreased x!
[==============================================================================}
function TInt64Helper.Decrement(const N: Int64 = 1): Int64; overload;
begin
  Self := (Self - N);
  Result := Self;
end;

{==============================================================================]
  <Decrement>
  @action: Decreases the Int64 value x by N if B is true.
  @note: Returns the decreased x!
[==============================================================================}
function TInt64Helper.Decrement(const B: Boolean; const N: Int64 = 1): Int64; overload;
begin
  if B then
    Self := (Self - N);
  Result := Self;
end;

{==============================================================================]
  <Increase>
  @action: Increases the Int64 value x by N.
  @note: Returns x before increasing it with N!
[==============================================================================}
function TInt64Helper.Increase(const N: Int64 = 1): Int64; overload;
begin
  Result := Self;
  Self := (Self + N);
end;

{==============================================================================]
  <Increase>
  @action: Increases the Int64 value x by N if B is true.
  @note: Returns x before increasing it!
[==============================================================================}
function TInt64Helper.Increase(const B: Boolean; const N: Int64 = 1): Int64; overload;
begin
  Result := Self;
  if B then
    Self := (Self + N);
end;

{==============================================================================]
  <Increment>
  @action: Increases the Int64 value x by N.
  @note: Returns the increased x!
[==============================================================================}
function TInt64Helper.Increment(const N: Int64 = 1): Int64; overload;
begin
  Self := (Self + N);
  Result := Self;
end;

{==============================================================================]
  <Increment>
  @action: Increases the Int64 value x by N if B is true.
  @note: Returns the increased x!
[==============================================================================}
function TInt64Helper.Increment(const B: Boolean; const N: Int64 = 1): Int64; overload;
begin
  if B then
    Self := (Self + N);
  Result := Self;
end;

{==============================================================================]
  <X>
  @action: Returns the value of the Int64 multiplied by the specified factor `N`.
  @note:
    - Does not modify the original Int64; returns the computed value.
    - If `N` is not specified, it defaults to 1 and returns the Int64 itself.
    - Equivalent to `Self * N`.
[==============================================================================}
function TInt64Helper.X(const N: Int64 = 1): Int64; overload;
begin
  Result := (Self * N);
end;

{==============================================================================]
  <X2>
  @action: Returns the value of the Int64 multiplied by 2 and further scaled by
           the specified factor `N`.
  @note:
    - Does not modify the original Int64; returns the computed value.
    - Equivalent to `Self * (2 * N)`.
    - If `N` is not specified, it defaults to 1 and the result is `Self * 2`.
[==============================================================================}
function TInt64Helper.X2(const N: Int64 = 1): Int64; overload;
begin
  Result := ((Self * 2) * N);
end;

{==============================================================================]
  <X3>
  @action: Returns the value of the Int64 multiplied by 3 and further scaled by
           the specified factor `N`.´
  @note:
    - Does not modify the original Int64; returns the computed value.
    - Equivalent to `Self * (3 * N)`.
    - If `N` is not specified, it defaults to 1 and the result is `Self * 3`.
[==============================================================================}
function TInt64Helper.X3(const N: Int64 = 1): Int64; overload;
begin
  Result := ((Self * 3) * N);
end;

{==============================================================================]
  <X4>
  @action: Returns the value of the Int64 multiplied by 4 and further scaled by
           the specified factor `N`.
  @note:
    - Does not modify the original Int64; returns the computed value.
    - Equivalent to `Self * (4 * N)`.
    - If `N` is not specified, it defaults to 1 and the result is `Self * 4`.
[==============================================================================}
function TInt64Helper.X4(const N: Int64 = 1): Int64; overload;
begin
  Result := ((Self * 4) * N);
end;

{==============================================================================]
  <X10>
  @action: Returns the value of the Int64 multiplied by 10 and further scaled by
           the specified factor `N`.
  @note:
    - Does not modify the original Int64; returns the computed value.
    - Equivalent to `Self * (10 * N)`.
    - If `N` is not specified, it defaults to 1 and the result is `Self * 10`.
[==============================================================================}
function TInt64Helper.X10(const N: Int64 = 1): Int64; overload;
begin
  Result := ((Self * 10) * N);
end;

{==============================================================================]
  <X>
  @action: Multiplies the given Int64 variable `val` by the specified factor `N`
           and returns the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - If `N` is not specified, it defaults to 1 and `val` remains unchanged.
    - Equivalent to: `val := val * N`.
[==============================================================================}
function X(var val: Int64; const N: Int64 = 1): Int64; overload;
begin
  val := (val * N);
  Result := val;
end;

{==============================================================================]
  <X2>
  @action: Multiplies the given Int64 variable `val` by 2 and further scales it by
           the specified factor `N`, returning the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - Equivalent to: `val := val * (2 * N)`.
    - If `N` is not specified, it defaults to 1 and `val` is multiplied by 2.
[==============================================================================}
function X2(var val: Int64; const N: Int64 = 1): Int64; overload;
begin
  val := ((val * 2) * N);
  Result := val;
end;

{==============================================================================]
  <X3>
  @action: Multiplies the given Int64 variable `val` by 3 and further scales it by
           the specified factor `N`, returning the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - Equivalent to: `val := val * (3 * N)`.
    - If `N` is not specified, it defaults to 1 and `val` is multiplied by 3.
[==============================================================================}
function X3(var val: Int64; const N: Int64 = 1): Int64; overload;
begin
  val := ((val * 3) * N);
  Result := val;
end;

{==============================================================================]
  <X4>
  @action: Multiplies the given Int64 variable `val` by 4 and further scales it by
           the specified factor `N`, returning the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - Equivalent to: `val := val * (4 * N)`.
    - If `N` is not specified, it defaults to 1 and `val` is multiplied by 4.
[==============================================================================}
function X4(var val: Int64; const N: Int64 = 1): Int64; overload;
begin
  val := ((val * 4) * N);
  Result := val;
end;

{==============================================================================]
  <X10>
  @action: Multiplies the given Int64 variable `val` by 10 and further scales it by
           the specified factor `N`, returning the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - Equivalent to: `val := val * (10 * N)`.
    - If `N` is not specified, it defaults to 1 and `val` is multiplied by 10.
[==============================================================================}
function X10(var val: Int64; const N: Int64 = 1): Int64; overload;
begin
  val := ((val * 10) * N);
  Result := val;
end;
{$ENDIF}