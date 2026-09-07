{$IFDEF METHODS}
function Decrease(const xN, yN: Integer): TPoint; overload;
function Decrease(const N: Integer = 1): TPoint; overload;
function Decrement(const xN, yN: Integer): TPoint; overload;
function Decrement(const N: Integer = 1): TPoint; overload;

function Increase(const xN, yN: Integer): TPoint; overload;
function Increase(const N: Integer = 1): TPoint; overload;
function Increment(const xN, yN: Integer): TPoint; overload;
function Increment(const N: Integer = 1): TPoint; overload;

function XDecrease(const N: Integer = 1): TPoint; overload;
function XDecrement(const N: Integer = 1): TPoint; overload;

function XIncrease(const N: Integer = 1): TPoint; overload;
function XIncrement(const N: Integer = 1): TPoint; overload;

function YDecrease(const N: Integer = 1): TPoint; overload;
function YDecrement(const N: Integer = 1): TPoint; overload;

function YIncrease(const N: Integer = 1): TPoint; overload;
function YIncrement(const N: Integer = 1): TPoint; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Decrease>
  @action: Decrements `Self` by `(xN, yN)`, returning the point's value *before* the change.
  @note: Postfix-style semantics (like `i--`) — mirrors `Increase`. Mutates `Self`.
[==============================================================================}
function TPoint.Decrease(const xN, yN: Integer): TPoint; overload;
begin
  Result.X := Self.X;
  Result.Y := Self.Y;
  Self.X := (Self.X - xN);
  Self.Y := (Self.Y - yN);
end;

function TPoint.Decrease(const N: Integer = 1): TPoint; overload;
begin
  Result := Self.Decrease(N, N);
end;

{==============================================================================]
  <Decrement>
  @action: Decrements `Self` by `(xN, yN)`, returning the point's value *after* the change.
  @note: Prefix-style semantics (like `--i`) — mirrors `Increment`, and matches the
         established `Increment`/`Decrement` contract (mutate, then return the new value).
         Mutates `Self`.
[==============================================================================}
function TPoint.Decrement(const xN, yN: Integer): TPoint; overload;
begin
  Self.X := (Self.X - xN);
  Self.Y := (Self.Y - yN);
  Result.X := Self.X;
  Result.Y := Self.Y;
end;

function TPoint.Decrement(const N: Integer = 1): TPoint; overload;
begin
  Result := Self.Decrement(N, N);
end;

{==============================================================================]
  <Increase>
  @action: Increments `Self` by `(xN, yN)`, returning the point's value *before* the change.
  @note: Postfix-style semantics (like `i++`) — mirrors `Decrease`. Mutates `Self`.
[==============================================================================}
function TPoint.Increase(const xN, yN: Integer): TPoint; overload;
begin
  Result.X := Self.X;
  Result.Y := Self.Y;
  Self.X := (Self.X + xN);
  Self.Y := (Self.Y + yN);
end;

function TPoint.Increase(const N: Integer = 1): TPoint; overload;
begin
  Result := Self.Increase(N, N);
end;

{==============================================================================]
  <Increment>
  @action: Increments `Self` by `(xN, yN)`, returning the point's value *after* the change.
  @note: Prefix-style semantics (like `++i`) — mirrors `Decrement`, and matches the
         established `Increment`/`Decrement` contract (mutate, then return the new value).
         Mutates `Self`.
[==============================================================================}
function TPoint.Increment(const xN, yN: Integer): TPoint; overload;
begin
  Self.X := (Self.X + xN);
  Self.Y := (Self.Y + yN);
  Result.X := Self.X;
  Result.Y := Self.Y;
end;

function TPoint.Increment(const N: Integer = 1): TPoint; overload;
begin
  Result := Self.Increment(N, N);
end;

{==============================================================================]
  <XDecrease>
  @action: Decrements `Self.X` by `N`, returning the point's value *before* the change.
  @note: Postfix-style semantics (like `x--`) — mirrors `XIncrease`. Only `X` is mutated;
         `Y` is untouched and returned as-is. Mutates `Self`.
[==============================================================================}
function TPoint.XDecrease(const N: Integer = 1): TPoint; overload;
begin
  Result.X := Self.X;
  Result.Y := Self.Y;
  Self.X := (Self.X - N);
end;

{==============================================================================]
  <XDecrement>
  @action: Decrements `Self.X` by `N`, returning the point's value *after* the change.
  @note: Prefix-style semantics (like `--x`) — mirrors `XIncrement`. Only `X` is mutated;
         `Y` is untouched and returned as-is. Mutates `Self`.
[==============================================================================}
function TPoint.XDecrement(const N: Integer = 1): TPoint; overload;
begin
  Self.X := (Self.X - N);
  Result.X := Self.X;
  Result.Y := Self.Y;
end;

{==============================================================================]
  <XIncrease>
  @action: Increments `Self.X` by `N`, returning the point's value *before* the change.
  @note: Postfix-style semantics (like `x++`) — mirrors `XDecrease`. Only `X` is mutated;
         `Y` is untouched and returned as-is. Mutates `Self`.
[==============================================================================}
function TPoint.XIncrease(const N: Integer = 1): TPoint; overload;
begin
  Result.X := Self.X;
  Result.Y := Self.Y;
  Self.X := (Self.X + N);
end;

{==============================================================================]
  <XIncrement>
  @action: Increments `Self.X` by `N`, returning the point's value *after* the change.
  @note: Prefix-style semantics (like `++x`) — mirrors `XDecrement`. Only `X` is mutated;
         `Y` is untouched and returned as-is. Mutates `Self`.
[==============================================================================}
function TPoint.XIncrement(const N: Integer = 1): TPoint; overload;
begin
  Self.X := (Self.X + N);
  Result.X := Self.X;
  Result.Y := Self.Y;
end;

{==============================================================================]
  <YDecrease>
  @action: Decrements `Self.Y` by `N`, returning the point's value *before* the change.
  @note: Postfix-style semantics (like `y--`) — mirrors `YIncrease`. Only `Y` is mutated;
         `X` is untouched and returned as-is. Mutates `Self`.
[==============================================================================}
function TPoint.YDecrease(const N: Integer = 1): TPoint; overload;
begin
  Result.X := Self.X;
  Result.Y := Self.Y;
  Self.Y := (Self.Y - N);
end;

{==============================================================================]
  <YDecrement>
  @action: Decrements `Self.Y` by `N`, returning the point's value *after* the change.
  @note: Prefix-style semantics (like `--y`) — mirrors `YIncrement`. Only `Y` is mutated;
         `X` is untouched and returned as-is. Mutates `Self`.
[==============================================================================}
function TPoint.YDecrement(const N: Integer = 1): TPoint; overload;
begin
  Self.Y := (Self.Y - N);
  Result.X := Self.X;
  Result.Y := Self.Y;
end;

{==============================================================================]
  <YIncrease>
  @action: Increments `Self.Y` by `N`, returning the point's value *before* the change.
  @note: Postfix-style semantics (like `y++`) — mirrors `YDecrease`. Only `Y` is mutated;
         `X` is untouched and returned as-is. Mutates `Self`.
[==============================================================================}
function TPoint.YIncrease(const N: Integer = 1): TPoint; overload;
begin
  Result.X := Self.X;
  Result.Y := Self.Y;
  Self.Y := (Self.Y + N);
end;

{==============================================================================]
  <YIncrement>
  @action: Increments `Self.Y` by `N`, returning the point's value *after* the change.
  @note: Prefix-style semantics (like `++y`) — mirrors `YDecrement`. Only `Y` is mutated;
         `X` is untouched and returned as-is. Mutates `Self`.
[==============================================================================}
function TPoint.YIncrement(const N: Integer = 1): TPoint; overload;
begin
  Self.Y := (Self.Y + N);
  Result.X := Self.X;
  Result.Y := Self.Y;
end;
{$ENDIF}
