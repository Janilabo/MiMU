{$IFDEF HELPERS}
function Abso: Integer; overload;
function Neg: Integer; overload;
function NegA: Integer; overload;
function NegAbs: Integer; overload;
function Negate: Integer; overload;
function Negated: Integer; overload;
function Negatize: Boolean; overload;
function Opponize: Boolean; overload;
function Oppose: Integer; overload;
function Opposite: Integer; overload;
function Posite: Integer; overload;
function Posited: Integer; overload;
function Positize: Boolean; overload;
function Zeroize: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Abso>
  @action: Returns the absolute value of the integer, stripping away any negative 
           sign so that the returned result is always greater than or equal to zero.
  @note: A pure, non-mutating shorthand function. Leaves 'Self' completely unchanged. 
[==============================================================================}
function TIntegerHelper.Abso: Integer; overload;
begin
  if (Self < 0) then
    Result := -Self
  else
    Result := Self;
end;

{==============================================================================]
  <Neg>
  @action: Returns the negative number of x.
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TIntegerHelper.Neg: Integer; overload;
begin
  if (Self > 0) then
    Result := (Self * -1)
  else
    Result := Self;
end;

{==============================================================================]
  <NegA>
  @action: Returns the negative number of x.
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TIntegerHelper.NegA: Integer; overload;
begin
  Result := (Abs(Self) * -1);
end;

{==============================================================================]
  <NegAbs>
  @action: Returns the negative absolute value of the integer, ensuring the result is always less than or equal to zero.
  @note: Uses the built-in Abs function for a cleaner, more concise implementation than manual conditional checks.
[==============================================================================}
function TIntegerHelper.NegAbs: Integer; overload;
begin
  Result := -Abs(Self);
end;

{==============================================================================]
  <Negate>
  @action: Mutates the integer in-place by inverting its sign (if positive) or clamping it to 0 (if less than 1). 
           Returns the original value of the integer if it was positive, or returns 0 if it was less than 1.
  @note: This functions like a "pop and invert" operation. The caller receives the pre-negated value (or a fallback of 0),
         while the variable itself is successfully mutated.
[==============================================================================}
function TIntegerHelper.Negate: Integer; overload;
begin
  if (Self < 1) then
    Exit(0);
  Result := Self;
  Self := -Self;
end;

{==============================================================================]
  <Negated>
  @action: Returns the negative absolute value of the integer, ensuring the returned result is always zero or less. 
  @note: A pure, side-effect-free function. Unlike its mutating counterpart,
         this method leaves the original variable ('Self') completely unchanged and is safe to use on constants or literals.
[==============================================================================}
function TIntegerHelper.Negated: Integer; overload;
begin
  if (Self > 0) then
    Result := -Self
  else
    Result := Self;
end;

{==============================================================================]
  <Negatize>
  @action: Converts a strictly positive integer into its negative counterpart in-place. 
           Returns True if the sign was flipped, or False if the integer was already negative or 0.
  @note: Destructive operation. This functions as a conditional absolute negation, leaving 
         non-positive values entirely unaffected while providing a boolean success flag.
[==============================================================================}
function TIntegerHelper.Negatize: Boolean; overload;
begin
  Result := (Self > 0);
  if Result then
    Self := -Self;
end;

{==============================================================================]
  <Opponize>
  @action: Inverts the sign of the integer in-place (positive to negative, or negative to positive) as long as it is not zero. 
           Returns True if the integer was successfully inverted, or False if the integer was 0 (and thus left unchanged).
  @note: Unlike 'Negate', this is a true mathematical sign-flipper that handles both positive and negative bounds,
         treating 0 as the only neutral, unchangeable state.
[==============================================================================}
function TIntegerHelper.Opponize: Boolean; overload;
begin
  Result := (Self <> 0);
  if Result then
    Self := -Self;
end;

{==============================================================================]
  <Oppose>
  @action: Inverts the sign of the integer in-place (positive to negative, or negative to positive) and returns the original pre-inverted value.
  @note: Destructive operation. Modifies 'Self' directly. Unlike 'Negate', this performs a true mathematical negation across all values, including negative numbers and zero.
[==============================================================================}
function TIntegerHelper.Oppose: Integer; overload;
begin
  Result := Self;
  Self := -Self;
end;

{==============================================================================]
  <Opposite>
  @action: Returns the direct mathematical opposite of the integer by inverting its sign (multiplying by -1).
  @note: A pure, non-mutating function. Unlike 'Oppose', this method leaves 'Self' completely unchanged and
         safely returns the inverted value for any positive, negative, or zero integer.
[==============================================================================}
function TIntegerHelper.Opposite: Integer; overload;
begin
  Result := (Self * -1);
end;

{==============================================================================]
  <Posit>
  @action: Mutates the integer in-place by inverting its sign (if negative) or clamping it to 0 (if greater than -1). 
           Returns the original value of the integer if it was negative, or returns 0 if it was greater than -1.
  @note: This functions like a "pop and invert" operation for the negative spectrum. The caller receives the pre-posited value (or a fallback of 0), while the variable itself is successfully mutated.
[==============================================================================}
function TIntegerHelper.Posite: Integer; overload;
begin
  if (Self > -1) then
    Exit(0);
  Result := Self;
  Self := -Self;
end;

{==============================================================================]
  <Posited>
  @action: Returns the positive equivalent of the integer (its absolute magnitude), 
           ensuring the returned result is always greater than or equal to zero.
  @note: A pure, side-effect-free function. Unlike its mutating counterpart 'Posite', 
         this method leaves the original variable ('Self') completely unchanged and 
         is safe to use on constants or literals.
[==============================================================================}
function TIntegerHelper.Posited: Integer; overload;
begin
  if (Self < 0) then
    Result := -Self
  else
    Result := Self;
end;

{==============================================================================]
  <Positize>
  @action: Converts a strictly negative integer into its positive counterpart in-place. 
           Returns True if the sign was flipped, or False if the integer was already positive or 0.
  @note: Destructive operation. This functions as a conditional absolute value mechanism, leaving 
         non-negative values entirely unaffected while providing a boolean success flag.
[==============================================================================}
function TIntegerHelper.Positize: Boolean; overload;
begin
  Result := (Self < 0);
  if Result then
    Self := -Self;
end;

{==============================================================================]
  <Zeroize>
  @action: Forces the integer to 0 in-place. Returns True if the value was changed,
           or False if the value was already 0.
[==============================================================================}
function TIntegerHelper.Zeroize: Boolean; overload;
begin
  Result := (Self <> 0);
  if Result then
    Self := 0;
end;
{$ENDIF}
