{$IFDEF HELPERS}
function Cut(const N: MType = 1): MType; overload;
function Dec2(const AMin: MType; const N: MType = 1): Boolean; overload;
function Decr(const N: MType = 1): MType; overload;
function Decrease(const N: MType = 1): MType; overload;
function Decrease(const B: Boolean; const N: MType = 1): MType; overload;
function Decrement(const N: MType = 1): MType; overload;
function Decrement(const B: Boolean; const N: MType = 1): MType; overload;
function Decret(const N: MType = 1): MType; overload;
function DecTo(const AMin: MType; const N: MType = 1): Boolean; overload;
function Pre(const N: MType = 1): MType; overload;
function Retdec(const N: MType = 1): MType; overload;
function Take(const N: MType = 1): MType; overload;
function Take(const B: Boolean; const N: MType = 1): MType; overload;
function TryDec(const AMin: MType; const N: MType = 1): Boolean; overload;

function Give(const N: MType = 1): MType; overload;
function Give(const B: Boolean; const N: MType = 1): MType; overload;
function Inc2(const AMax: MType; const N: MType = 1): Boolean; overload;
function Incr(const N: MType = 1): MType; overload;
function Increase(const N: MType = 1): MType; overload;
function Increase(const B: Boolean; const N: MType = 1): MType; overload;
function Increment(const N: MType = 1): MType; overload;
function Increment(const B: Boolean; const N: MType = 1): MType; overload;
function Incret(const N: MType = 1): MType; overload;
function IncTo(const AMax: MType; const N: MType = 1): Boolean; overload;
function Post(const N: MType = 1): MType; overload;
function Put(const N: MType = 1): MType; overload;
function Retinc(const N: MType = 1): MType; overload;
function TryInc(const AMax: MType; const N: MType = 1): Boolean; overload;

function X(const N: MType = 1): MType; overload;
function X2(const N: MType = 1): MType; overload;
function X3(const N: MType = 1): MType; overload;
function X4(const N: MType = 1): MType; overload;
function X10(const N: MType = 1): MType; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Dec2(var A, B: MType; const N: MType = 1): MType; overload;
function Dec3(var A, B, C: MType; const N: MType = 1): MType; overload;
function Dec4(var A, B, C, D: MType; const N: MType = 1): MType; overload;
function DecGet(var val: MType; const N: MType = 1): MType; overload;
function DecGet(var val: MType; const B: Boolean; const N: MType = 1): MType; overload;
function GetDec(var val: MType; const N: MType = 1): MType; overload;
function GetDec(var val: MType; const B: Boolean; const N: MType = 1): MType; overload;

function GetInc(var val: MType; const N: MType = 1): MType; overload;
function GetInc(var val: MType; const B: Boolean; const N: MType = 1): MType; overload;
function Inc2(var A, B: MType; const N: MType = 1): MType; overload;
function Inc3(var A, B, C: MType; const N: MType = 1): MType; overload;
function Inc4(var A, B, C, D: MType; const N: MType = 1): MType; overload;
function IncGet(var val: MType; const N: MType = 1): MType; overload;
function IncGet(var val: MType; const B: Boolean; const N: MType = 1): MType; overload;

function X(var val: MType; const N: MType = 1): MType; overload;
function X2(var val: MType; const N: MType = 1): MType; overload;
function X3(var val: MType; const N: MType = 1): MType; overload;
function X4(var val: MType; const N: MType = 1): MType; overload;
function X10(var val: MType; const N: MType = 1): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Cut>
  @action: Decreases the Self by N.
  @note: Mutates Self in place and returns the updated value after subtraction.
         Equivalent to a prefix-style decrement.
[==============================================================================}
function MTypeHelper.Cut(const N: MType = 1): MType; overload;
begin
  Result := (Self - N);
  Self := Result
end;

{==============================================================================]
  <Dec2>
  @action: Attempts to decrement the value of Self by N, floored at a minimum limit.
  @note: Returns True if the value was strictly greater than AMin before the operation.
         If Self is already below AMin, it safely clamps Self to AMin and returns False.
[==============================================================================}
function MTypeHelper.Dec2(const AMin: MType; const N: MType = 1): Boolean; overload;
begin
  Result := (Self > AMin);
  if Result then
    Self := Max((Self - N), AMin)
  else if (Self < AMin) then
    Self := AMin;
end;

{==============================================================================]
  <Decr>
  @action: Decrements the Self value by N (default = 1) and returns
           the updated result.
  @note:
    • Uses pre-decrement semantics (result reflects the new value).
    • N may be negative, effectively performing an increment.
    • Only mutates the original variable when called on a true variable;
      calling on a temporary modifies a copy.
[==============================================================================}
function MTypeHelper.Decr(const N: MType = 1): MType; overload;
begin
  {$IFDEF Double}
    Self := (Self - N);
  {$ELSE}
    Dec(MPointer(@Self)^, N);
  {$ENDIF}
  Result := Self;
end;

{==============================================================================]
  <Decrease>
  @action: Decreases the Self value x by N.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function MTypeHelper.Decrease(const N: MType = 1): MType; overload;
begin
  Result := Self;
  Self := (Self - N);
end;

{==============================================================================]
  <Decrease>
  @action: Decreases the Self value x by N if B is true.
  @note: Returns x before decreasing!
[==============================================================================}
function MTypeHelper.Decrease(const B: Boolean; const N: MType = 1): MType; overload;
begin
  Result := Self;
  if B then
    Self := (Self - N);
end;

{==============================================================================]
  <Decrement>
  @action: Decreases the Self value x by N.
  @note: Returns the decreased x!
[==============================================================================}
function MTypeHelper.Decrement(const N: MType = 1): MType; overload;
begin
  Self := (Self - N);
  Result := Self;
end;

{==============================================================================]
  <Decrement>
  @action: Decreases the Self value x by N if B is true.
  @note: Returns the decreased x!
[==============================================================================}
function MTypeHelper.Decrement(const B: Boolean; const N: MType = 1): MType; overload;
begin
  if B then
    Self := (Self - N);
  Result := Self;
end;

{==============================================================================]
  <Decret>
  @action: Decrements Self by N, then returns the newly updated value.
  @param: N The step delta to decrement by (defaults to 1).
  @return: The freshly decremented value of Self.
  @note: Prefix decrement operator. Useful for dropping a tracking index 
         immediately before evaluating bounds or performing memory access.
[==============================================================================}
function MTypeHelper.Decret(const N: MType = 1): MType; overload;
begin
  Self := (Self - N);
  Result := Self;
end;

{==============================================================================]
  <DecTo>
  @action: Decrements the Self by N towards a minimum limit.
  @note: Returns True if the resulting value has successfully reached or hit AMin.
[==============================================================================}
function MTypeHelper.DecTo(const AMin: MType; const N: MType = 1): Boolean; overload;
begin
  Self := Max((Self - N), AMin);
  Result := (Self = AMin);
end;

{==============================================================================]
  <Pre>
  @action: Calculates a relative offset preceding the current value.
  @param: N The distance to look backward (defaults to 1).
  @return: The pure mathematical result of (Self - N).
  @note: Immutable. Does not mutate Self. Useful for safe, side-effect-free
         look-behind operations in arrays and streams.
[==============================================================================}
function MTypeHelper.Pre(const N: MType = 1): MType; overload;
begin
  Result := (Self - N);
end;

{==============================================================================]
  <Retdec>
  @action: Returns the current value of Self, then decrements Self by N.
  @param: N The step delta to decrement by (defaults to 1).
  @return: The historical (old) value of Self prior to the decrement.
[==============================================================================}
function MTypeHelper.Retdec(const N: MType = 1): MType; overload;
begin
  Result := Self;
  Self := (Self - N);
end;

{==============================================================================]
  <Take>
  @action: Decreases the Self by N.
  @note: Mutates Self and returns the updated value after subtraction.
         Equivalent to a prefix decrement of N.
[==============================================================================}
function MTypeHelper.Take(const N: MType = 1): MType; overload;
begin
  Result := (Self - N);
  Self := (Self - N);
end;

{==============================================================================]
  <Take>
  @action: Decreases the Self by N if B is True.
  @note: Mutates Self and returns the updated value after subtraction.
         Equivalent to a prefix decrement of N.
[==============================================================================}
function MTypeHelper.Take(const B: Boolean; const N: MType = 1): MType; overload;
begin
  if not B then
    Exit(Self);
  Result := (Self - N);
  Self := (Self - N);
end;

{==============================================================================]
  <TryDec>
  @action: Attempts to decrement Self by N, but only if the result
           would not go below AMin.
  @return: True if the decrement was applied; False if it would go below AMin.
  @note: Value remains unchanged if False.
[==============================================================================}
function MTypeHelper.TryDec(const AMin: MType; const N: MType = 1): Boolean; overload;
begin
  Result := ((Self - N) >= AMin);
  if not Result then
    Exit;
  Self := (Self - N);
end;

{==============================================================================]
  <Give>
  @action: Increases the Self by N.
  @note: Mutates Self and returns the updated value after addition.
         Equivalent to a prefix increment of N.
[==============================================================================}
function MTypeHelper.Give(const N: MType = 1): MType; overload;
begin
  Result := (Self + N);
  Self := (Self + N);
end;

{==============================================================================]
  <Give>
  @action: Increases the Self by N if B is True.
  @note: Mutates Self and returns the updated value after addition.
         Equivalent to a prefix increment of N.
[==============================================================================}
function MTypeHelper.Give(const B: Boolean; const N: MType = 1): MType; overload;
begin
  if not B then 
    Exit(Self);
  Result := (Self + N);
  Self := (Self + N);
end;

{==============================================================================]
  <Inc2>
  @action: Attempts to increment the Self by N, capped at a maximum limit.
  @note: Returns True if the value was strictly less than AMax before the operation.
         If Self already exceeds AMax, it safely clamps Self to AMax and returns False.
[==============================================================================}
function MTypeHelper.Inc2(const AMax: MType; const N: MType = 1): Boolean; overload;
begin
  Result := (Self < AMax);
  if Result then
    Self := Min((Self + N), AMax)
  else if (Self > AMax) then
    Self := AMax;
end;

{==============================================================================]
  <Incr>
  @action: Increments the Self value by N (default = 1) and returns
           the updated result.
  @note:
    • Uses pre-increment semantics (result reflects the new value).
    • N may be negative, effectively performing a decrement.
    • Only mutates the original variable when called on a true variable;
      calling on a temporary modifies a copy.
[==============================================================================}
function MTypeHelper.Incr(const N: MType = 1): MType; overload;
begin
  {$IFDEF Double}
    Self := (Self + N);
  {$ELSE}
    Inc(MPointer(@Self)^, N);
  {$ENDIF}
  Result := Self;
end;

{==============================================================================]
  <Increase>
  @action: Increases the Self value x by N.
  @note: Returns x before increasing it with N!
[==============================================================================}
function MTypeHelper.Increase(const N: MType = 1): MType; overload;
begin
  Result := Self;
  Self := (Self + N);
end;

{==============================================================================]
  <Increase>
  @action: Increases the Self value x by N when B is true.
  @note: Returns x before increasing!
[==============================================================================}
function MTypeHelper.Increase(const B: Boolean; const N: MType = 1): MType; overload;
begin
  Result := Self;
  if B then
    Self := (Self + N);
end;

{==============================================================================]
  <Increment>
  @action: Increases the Self value x by N.
  @note: Returns the increased x!
[==============================================================================}
function MTypeHelper.Increment(const N: MType = 1): MType; overload;
begin
  Self := (Self + N);
  Result := Self;
end;

{==============================================================================]
  <Increment>
  @action: Increases the Self value x by N if B is true.
  @note: Returns the increased x!
[==============================================================================}
function MTypeHelper.Increment(const B: Boolean; const N: MType = 1): MType; overload;
begin
  if B then
    Self := (Self + N);
  Result := Self;
end;

{==============================================================================]
  <Incret>
  @action: Increments Self by N, then returns the newly updated value.
  @param: N The step delta to increment by (defaults to 1).
  @return: The freshly incremented value of Self.
  @note: Prefix increment operator. Useful for stepping a tracking index 
         immediately before evaluating bounds or performing memory access.
[==============================================================================}
function MTypeHelper.Incret(const N: MType = 1): MType; overload;
begin
  Self := (Self + N);
  Result := Self;
end;

{==============================================================================]
  <IncTo>
  @action: Increments the Self by N towards a maximum limit.
  @note: Returns True if the resulting value has successfully reached or hit AMax.
[==============================================================================}
function MTypeHelper.IncTo(const AMax: MType; const N: MType = 1): Boolean; overload;
begin
  Self := Min((Self + N), AMax);
  Result := (Self = AMax);
end;

{==============================================================================]
  <Post>
  @action: Calculates a relative offset posterior to the current value.
  @param: N The distance to look forward (defaults to 1).
  @return: The pure mathematical result of (Self + N).
  @note: Immutable. Does not mutate Self. Useful for safe, side-effect-free
         look-ahead operations in arrays and streams.
[==============================================================================}
function MTypeHelper.Post(const N: MType = 1): MType; overload;
begin
  Result := (Self + N);
end;

{==============================================================================]
  <Put>
  @action: Increases the Self by N.
  @note: Mutates Self in place and returns the updated value after addition.
         Equivalent to a prefix-style increment.
[==============================================================================}
function MTypeHelper.Put(const N: MType = 1): MType; overload;
begin
  Result := (Self + N);
  Self := Result
end;

{==============================================================================]
  <Retinc>
  @action: Returns the current value of Self, then increments Self by N.
  @param: N The step delta to increment by (defaults to 1).
  @return: The historical (old) value of Self prior to the increment.
[==============================================================================}
function MTypeHelper.Retinc(const N: MType = 1): MType; overload;
begin
  Result := Self;
  Self := (Self + N);
end;

{==============================================================================]
  <TryInc>
  @action: Attempts to increment Self by N, but only if the result
           would not exceed AMax.
  @return: True if the increment was applied; False if it would exceed AMax.
  @note: Value remains unchanged if False.
[==============================================================================}
function MTypeHelper.TryInc(const AMax: MType; const N: MType = 1): Boolean; overload;
begin
  Result := ((Self + N) <= AMax);
  if not Result then
    Exit;
  Self := (Self + N);
end;

{==============================================================================]
  <X>
  @action: Returns the value of the Self multiplied by the specified factor `N`.
  @note:
    - Does not modify Self; returns the computed value.
    - If `N` is not specified, it defaults to 1 and returns the value itself.
    - Equivalent to `Self * N`.
[==============================================================================}
function MTypeHelper.X(const N: MType = 1): MType; overload;
begin
  Result := (Self * N);
end;

{==============================================================================]
  <X2>
  @action: Returns the value of the integer multiplied by 2 and further scaled by
           the specified factor `N`.
  @note:
    - Does not modify the original integer; returns the computed value.
    - Equivalent to `Self * (2 * N)`.
    - If `N` is not specified, it defaults to 1 and the result is `Self * 2`.
[==============================================================================}
function MTypeHelper.X2(const N: MType = 1): MType; overload;
begin
  Result := ((Self * 2) * N);
end;

{==============================================================================]
  <X3>
  @action: Returns the value of the integer multiplied by 3 and further scaled by
           the specified factor `N`.´
  @note:
    - Does not modify the original integer; returns the computed value.
    - Equivalent to `Self * (3 * N)`.
    - If `N` is not specified, it defaults to 1 and the result is `Self * 3`.
[==============================================================================}
function MTypeHelper.X3(const N: MType = 1): MType; overload;
begin
  Result := ((Self * 3) * N);
end;

{==============================================================================]
  <X4>
  @action: Returns the value of the integer multiplied by 4 and further scaled by
           the specified factor `N`.
  @note:
    - Does not modify the original integer; returns the computed value.
    - Equivalent to `Self * (4 * N)`.
    - If `N` is not specified, it defaults to 1 and the result is `Self * 4`.
[==============================================================================}
function MTypeHelper.X4(const N: MType = 1): MType; overload;
begin
  Result := ((Self * 4) * N);
end;

{==============================================================================]
  <X10>
  @action: Returns the value of the integer multiplied by 10 and further scaled by
           the specified factor `N`.
  @note:
    - Does not modify the original integer; returns the computed value.
    - Equivalent to `Self * (10 * N)`.
    - If `N` is not specified, it defaults to 1 and the result is `Self * 10`.
[==============================================================================}
function MTypeHelper.X10(const N: MType = 1): MType; overload;
begin
  Result := ((Self * 10) * N);
end;

{==============================================================================]
  <DecGet>
  @action: Decrements val by N.
  @note: Returns the updated value after subtraction (prefix decrement semantics).
[==============================================================================}
function DecGet(var val: MType; const N: MType = 1): MType; overload;
begin
  val := (val - N);
  Result := val;
end;

{==============================================================================]
  <DecGet>
  @action: Decrements val by N if B is True.
  @note: Returns the current value after evaluation (updated if decremented).
         Equivalent to conditional prefix decrement.
[==============================================================================}
function DecGet(var val: MType; const B: Boolean; const N: MType = 1): MType; overload;
begin
  if B then
    val := (val - N);
  Result := val;
end;

{==============================================================================]
  <GetDec>
  @action: Decrements val by N.
  @note: Returns the original value before subtraction (postfix decrement semantics).
[==============================================================================}
function GetDec(var val: MType; const N: MType = 1): MType; overload;
begin
  Result := val;
  val := (val - N);
end;

{==============================================================================]
  <GetDec>
  @action: Decrements val by N if B is True.
  @note: Returns the original value prior to conditional decrement.
         Equivalent to conditional postfix decrement.
[==============================================================================}
function GetDec(var val: MType; const B: Boolean; const N: MType = 1): MType; overload;
begin
  Result := val;
  if B then
    val := (val - N);
end;

{==============================================================================]
  <GetInc>
  @action: Increments val by N.
  @note: Returns the original value before addition (postfix increment semantics).
[==============================================================================}
function GetInc(var val: MType; const N: MType = 1): MType; overload;
begin
  Result := val;
  val := (val + N);
end;

{==============================================================================]
  <GetInc>
  @action: Increments val by N if B is True.
  @note: Returns the original value prior to conditional increment.
         Equivalent to conditional postfix increment.
[==============================================================================}
function GetInc(var val: MType; const B: Boolean; const N: MType = 1): MType; overload;
begin
  Result := val;
  if B then
    val := (val + N);
end;

{==============================================================================]
  <Dec2>
  @action: Decrements two variables by a specified value and returns their sum.
  @note: Operates directly on the passed variables (var). Defaults to subtracting 1.
[==============================================================================}
function Dec2(var A, B: MType; const N: MType = 1): MType; overload;
begin
  A := (A - N);
  B := (B - N);
  Result := (A + B);
end;

{==============================================================================]
  <Dec3>
  @action: Decrements three variables by a specified value and returns their sum.
  @note: Operates directly on the passed variables (var). Defaults to subtracting 1.
[==============================================================================}
function Dec3(var A, B, C: MType; const N: MType = 1): MType; overload;
begin
  A := (A - N);
  B := (B - N);
  C := (C - N);
  Result := (A + B + C);
end;

{==============================================================================]
  <Dec4>
  @action: Decrements four variables by a specified value and returns their sum.
  @note: Operates directly on the passed variables (var). Defaults to subtracting 1.
[==============================================================================}
function Dec4(var A, B, C, D: MType; const N: MType = 1): MType; overload;
begin
  A := (A - N);
  B := (B - N);
  C := (C - N);
  D := (D - N);
  Result := (A + B + C + D);
end;

{==============================================================================]
  <Inc2>
  @action: Increments two variables by a specified value and returns their sum.
  @note: Operates directly on the passed variables (var). Defaults to adding 1.
[==============================================================================}
function Inc2(var A, B: MType; const N: MType = 1): MType; overload;
begin
  A := (A + N);
  B := (B + N);
  Result := (A + B);
end;

{==============================================================================]
  <Inc3>
  @action: Increments three variables by a specified value and returns their sum.
  @note: Operates directly on the passed variables (var). Defaults to adding 1.
[==============================================================================}
function Inc3(var A, B, C: MType; const N: MType = 1): MType; overload;
begin
  A := (A + N);
  B := (B + N);
  C := (C + N);
  Result := (A + B + C);
end;

{==============================================================================]
  <Inc4>
  @action: Increments four variables by a specified value and returns their sum.
  @note: Operates directly on the passed variables (var). Defaults to adding 1.
[==============================================================================}
function Inc4(var A, B, C, D: MType; const N: MType = 1): MType; overload;
begin
  A := (A + N);
  B := (B + N);
  C := (C + N);
  D := (D + N);
  Result := (A + B + C + D);
end;

{==============================================================================]
  <IncGet>
  @action: Increments val by N.
  @note: Returns the updated value after addition (prefix increment semantics).
[==============================================================================}
function IncGet(var val: MType; const N: MType = 1): MType; overload;
begin
  val := (val + N);
  Result := val;
end;

{==============================================================================]
  <IncGet>
  @action: Increments val by N if B is True.
  @note: Returns the current value after evaluation (updated if incremented).
         Equivalent to conditional prefix increment.
[==============================================================================}
function IncGet(var val: MType; const B: Boolean; const N: MType = 1): MType; overload;
begin
  if B then
    val := (val + N);
  Result := val;
end;

{==============================================================================]
  <X>
  @action: Multiplies the given variable `val` by the specified factor `N`
           and returns the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - If `N` is not specified, it defaults to 1 and `val` remains unchanged.
    - Equivalent to: `val := val * N`.
[==============================================================================}
function X(var val: MType; const N: MType = 1): MType; overload;
begin
  val := (val * N);
  Result := val;
end;

{==============================================================================]
  <X2>
  @action: Multiplies the given variable `val` by 2 and further scales it by
           the specified factor `N`, returning the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - Equivalent to: `val := val * (2 * N)`.
    - If `N` is not specified, it defaults to 1 and `val` is multiplied by 2.
[==============================================================================}
function X2(var val: MType; const N: MType = 1): MType; overload;
begin
  val := ((val * 2) * N);
  Result := val;
end;

{==============================================================================]
  <X3>
  @action: Multiplies the given variable `val` by 3 and further scales it by
           the specified factor `N`, returning the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - Equivalent to: `val := val * (3 * N)`.
    - If `N` is not specified, it defaults to 1 and `val` is multiplied by 3.
[==============================================================================}
function X3(var val: MType; const N: MType = 1): MType; overload;
begin
  val := ((val * 3) * N);
  Result := val;
end;

{==============================================================================]
  <X4>
  @action: Multiplies the given variable `val` by 4 and further scales it by
           the specified factor `N`, returning the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - Equivalent to: `val := val * (4 * N)`.
    - If `N` is not specified, it defaults to 1 and `val` is multiplied by 4.
[==============================================================================}
function X4(var val: MType; const N: MType = 1): MType; overload;
begin
  val := ((val * 4) * N);
  Result := val;
end;

{==============================================================================]
  <X10>
  @action: Multiplies the given variable `val` by 10 and further scales it by
           the specified factor `N`, returning the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - Equivalent to: `val := val * (10 * N)`.
    - If `N` is not specified, it defaults to 1 and `val` is multiplied by 10.
[==============================================================================}
function X10(var val: MType; const N: MType = 1): MType; overload;
begin
  val := ((val * 10) * N);
  Result := val;
end;
{$ENDIF}
