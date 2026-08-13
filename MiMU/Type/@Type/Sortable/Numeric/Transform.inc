{$IFDEF HELPERS}
function Abso: MType; overload;
function Neg: MType; overload;
function NegA: MType; overload;
function NegAbs: MType; overload;
function Negate: MType; overload;
function Negated: MType; overload;
function Negatize: Boolean; overload;
function Opponize: Boolean; overload;
function Oppose: MType; overload;
function Opposite: MType; overload;
function Posite: MType; overload;
function Posited: MType; overload;
function Positize: Boolean; overload;
function Zeroize: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Abso>
  @action: Returns the absolute value of the Self, stripping away any negative 
           sign so that the returned result is always greater than or equal to zero.
  @note: A pure, non-mutating shorthand function. Leaves 'Self' completely unchanged. 
[==============================================================================}
function MTypeHelper.Abso: MType; overload;
begin
  if (Self < 0) then
    Result := -Self
  else
    Result := Self;
end;

{==============================================================================]
  <Neg>
  @action: Returns the negative number of Self.
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function MTypeHelper.Neg: MType; overload;
begin
  if (Self > 0) then
    Result := (Self * -1)
  else
    Result := Self;
end;

{==============================================================================]
  <NegA>
  @action: Returns the negative number of Self.
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function MTypeHelper.NegA: MType; overload;
begin
  Result := (Abs(Self) * -1);
end;

{==============================================================================]
  <NegAbs>
  @action: Returns the negative absolute value of the Self, ensuring the result is always less than or equal to zero.
  @note: Uses the built-in Abs function for a cleaner, more concise implementation than manual conditional checks.
[==============================================================================}
function MTypeHelper.NegAbs: MType; overload;
begin
  Result := -Abs(Self);
end;

{==============================================================================]
  <Negate>
  @action: Mutates the Self in-place by inverting its sign (if positive) or clamping it to 0 (if less than 1). 
           Returns the original value of the Self if it was positive, or returns 0 if it was less than 1.
  @note: This functions like a "pop and invert" operation. The caller receives the pre-negated value (or a fallback of 0),
         while the variable itself is successfully mutated.
[==============================================================================}
function MTypeHelper.Negate: MType; overload;
begin
  if (Self < 1) then
    Exit(0);
  Result := Self;
  Self := -Self;
end;

{==============================================================================]
  <Negated>
  @action: Returns the negative absolute value of the Self, ensuring the returned result is always zero or less. 
  @note: A pure, side-effect-free function. Unlike its mutating counterpart,
         this method leaves the original variable ('Self') completely unchanged and is safe to use on constants or literals.
[==============================================================================}
function MTypeHelper.Negated: MType; overload;
begin
  if (Self > 0) then
    Result := -Self
  else
    Result := Self;
end;

{==============================================================================]
  <Negatize>
  @action: Converts a strictly positive Self into its negative counterpart in-place. 
           Returns True if the sign was flipped, or False if the Self was already negative or 0.
  @note: Destructive operation. This functions as a conditional absolute negation, leaving 
         non-positive values entirely unaffected while providing a boolean success flag.
[==============================================================================}
function MTypeHelper.Negatize: Boolean; overload;
begin
  Result := (Self > 0);
  if Result then
    Self := -Self;
end;

{==============================================================================]
  <Opponize>
  @action: Inverts the sign of the Self in-place (positive to negative, or negative to positive) as long as it is not zero. 
           Returns True if the Self was successfully inverted, or False if the Self was 0 (and thus left unchanged).
  @note: Unlike 'Negate', this is a true mathematical sign-flipper that handles both positive and negative bounds,
         treating 0 as the only neutral, unchangeable state.
[==============================================================================}
function MTypeHelper.Opponize: Boolean; overload;
begin
  Result := (Self <> 0);
  if Result then
    Self := -Self;
end;

{==============================================================================]
  <Oppose>
  @action: Inverts the sign of the Self in-place (positive to negative, or negative to positive) and returns the original pre-inverted value.
  @note: Destructive operation. Modifies 'Self' directly. Unlike 'Negate', this performs a true mathematical negation across all values, including negative numbers and zero.
[==============================================================================}
function MTypeHelper.Oppose: MType; overload;
begin
  Result := Self;
  Self := -Self;
end;

{==============================================================================]
  <Opposite>
  @action: Returns the direct mathematical opposite of the Self by inverting its sign (multiplying by -1).
  @note: A pure, non-mutating function. Unlike 'Oppose', this method leaves 'Self' completely unchanged and
         safely returns the inverted value for any positive, negative, or zero Self.
[==============================================================================}
function MTypeHelper.Opposite: MType; overload;
begin
  Result := (Self * -1);
end;

{==============================================================================]
  <Posit>
  @action: Mutates the integer in-place by inverting its sign (if negative) or clamping it to 0 (if greater than -1). 
           Returns the original value of the integer if it was negative, or returns 0 if it was greater than -1.
  @note: This functions like a "pop and invert" operation for the negative spectrum. The caller receives the pre-posited value (or a fallback of 0), while the variable itself is successfully mutated.
[==============================================================================}
function MTypeHelper.Posite: MType; overload;
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
function MTypeHelper.Posited: MType; overload;
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
function MTypeHelper.Positize: Boolean; overload;
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
function MTypeHelper.Zeroize: Boolean; overload;
begin
  Result := (Self <> 0);
  if Result then
    Self := 0;
end;
{$ENDIF}
