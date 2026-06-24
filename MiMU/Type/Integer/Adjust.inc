{$IFDEF HELPERS}
function Add(const N: Integer; const aBounds: TRange): Integer; overload;
function Adjust(const cValue: Integer; const limits: TRange): Boolean; overload;
function Adjusted(const cValue: Integer; const limits: TRange): Integer; overload;
function AdjustedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer; overload;
function AdjustedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer; overload;
function AdjustMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean; overload;
function AdjustMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean; overload;
function Cut(const N: Integer = 1): Integer; overload;
function Dec2(const AMin: Integer; const N: Integer = 1): Boolean; overload;
function Decr(const N: Integer = 1): Integer; overload;
function Decrease(const N: Integer = 1): Integer; overload;
function Decrease(const B: Boolean; const N: Integer = 1): Integer; overload;
function Decrement(const N: Integer = 1): Integer; overload;
function Decrement(const B: Boolean; const N: Integer = 1): Integer; overload;
function Decret(const N: Integer = 1): Integer; overload;
function DecTo(const AMin: Integer; const N: Integer = 1): Boolean; overload; 
function Give(const N: Integer = 1): Integer; overload;
function Give(const B: Boolean; const N: Integer = 1): Integer; overload;
function Inc2(const AMax: Integer; const N: Integer = 1): Boolean; overload;
function Incr(const N: Integer = 1): Integer; overload;
function Increase(const N: Integer = 1): Integer; overload;
function Increase(const B: Boolean; const N: Integer = 1): Integer; overload;
function Increment(const N: Integer = 1): Integer; overload;
function Increment(const B: Boolean; const N: Integer = 1): Integer; overload;
function Incret(const N: Integer = 1): Integer; overload;
function IncTo(const AMax: Integer; const N: Integer = 1): Boolean; overload;
function Post(const N: Integer = 1): Integer; overload;
function Pre(const N: Integer = 1): Integer; overload;
function Pred(const N: Integer = 1; const minBound: Integer = -2147483648): Integer; overload;
function Put(const N: Integer = 1): Integer; overload;
function Retinc(const N: Integer = 1): Integer; overload;
function Retdec(const N: Integer = 1): Integer; overload;
function Succ(const N: Integer = 1; const maxBound: Integer = 2147483647): Integer; overload;
function Take(const N: Integer = 1): Integer; overload;
function Take(const B: Boolean; const N: Integer = 1): Integer; overload;
function Update(const cValue: Integer; const limits: TRange): Boolean; overload;
function Updated(const cValue: Integer; const limits: TRange): Integer; overload;
function UpdatedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer; overload;
function UpdatedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer; overload;
function UpdateMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean; overload;
function UpdateMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean; overload;
function X(const N: Integer = 1): Integer; overload;
function X2(const N: Integer = 1): Integer; overload;
function X3(const N: Integer = 1): Integer; overload;
function X4(const N: Integer = 1): Integer; overload;
function X10(const N: Integer = 1): Integer; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Dec2(var A, B: Integer; const N: Integer = 1): Int64; overload;
function Dec3(var A, B, C: Integer; const N: Integer = 1): Int64; overload;
function Dec4(var A, B, C, D: Integer; const N: Integer = 1): Int64; overload;
function DecGet(var val: Integer; const N: Integer = 1): Integer; overload;
function DecGet(var val: Integer; const B: Boolean; const N: Integer = 1): Integer; overload;
function GetDec(var val: Integer; const N: Integer = 1): Integer; overload;
function GetDec(var val: Integer; const B: Boolean; const N: Integer = 1): Integer; overload;
function GetInc(var val: Integer; const N: Integer = 1): Integer; overload;
function GetInc(var val: Integer; const B: Boolean; const N: Integer = 1): Integer; overload;
function Inc2(var A, B: Integer; const N: Integer = 1): Int64; overload;
function Inc3(var A, B, C: Integer; const N: Integer = 1): Int64; overload;
function Inc4(var A, B, C, D: Integer; const N: Integer = 1): Int64; overload;
function IncGet(var val: Integer; const N: Integer = 1): Integer; overload;
function IncGet(var val: Integer; const B: Boolean; const N: Integer = 1): Integer; overload;
function X(var val: Integer; const N: Integer = 1): Integer; overload;
function X2(var val: Integer; const N: Integer = 1): Integer; overload;
function X3(var val: Integer; const N: Integer = 1): Integer; overload;
function X4(var val: Integer; const N: Integer = 1): Integer; overload;
function X10(var val: Integer; const N: Integer = 1): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Add>
  @action: Adds N to Self, clamped within the given range (aBounds).
  @note: Uses Int64 arithmetic to prevent overflow; handles negative N by clamping to Min(aBounds), positive N by clamping to Max(aBounds).
[==============================================================================}
function TIntegerHelper.Add(const N: Integer; const aBounds: TRange): Integer; overload;
begin
  if (N < 0) then
    Result := Max((Int64(Self) + N), Min(aBounds.start, aBounds.stop))
  else
    Result := Min((Int64(Self) + N), Max(aBounds.start, aBounds.stop));
end;

{==============================================================================]
  <Adjust>
  @action: Attempts to adjust the current value by cValue if the resulting value
           stays within the specified limits range.
  @note: Returns True if the value was adjusted, False if it would go out of range.
[==============================================================================}
function TIntegerHelper.Adjust(const cValue: Integer; const limits: TRange): Boolean; overload;
begin
  Result := limits.Contains(Self + cValue);
  if Result then
    Self := (Self + cValue);
end;

{==============================================================================]
  <Adjusted>
  @action: Returns a potentially adjusted copy of the integer, adding cValue
           only if it stays within limits.
  @note: Non-mutating version of Adjust.
[==============================================================================}
function TIntegerHelper.Adjusted(const cValue: Integer; const limits: TRange): Integer; overload;
begin
  Result := Self;
  if limits.Contains(Self + cValue) then
    Result := (Result + cValue);
end;

{==============================================================================]
  <AdjustedMax>
  @action: Returns Self + cValue if below limit; otherwise returns Self.
  @note:   Non-mutating version of AdjustMax.
[==============================================================================}
function TIntegerHelper.AdjustedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer; overload;
begin
  Result := Self;
  if ((Self + cValue) <= limit) then
    Result := (Result + cValue);
end;

{==============================================================================]
  <AdjustedMin>
  @action: Returns Self + cValue if above limit; otherwise returns Self.
  @note: Non-mutating version of AdjustMin.
[==============================================================================}
function TIntegerHelper.AdjustedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer; overload;
begin
  Result := Self;
  if ((Self + cValue) >= limit) then
    Result := (Result + cValue);
end;

{==============================================================================]
  <AdjustMax>
  @action: Attempts to adjust by cValue but prevents exceeding the upper limit.
  @note: Returns True if the new value remains <= limit.
[==============================================================================}
function TIntegerHelper.AdjustMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean; overload;
begin
  Result := ((Self + cValue) <= limit);
  if Result then
    Self := (Self + cValue);
end;

{==============================================================================]
  <AdjustMin>
  @action: Attempts to increase or decrease the integer by cValue, but prevents
           it from going below limit.
  @note: Returns True if the value stayed above or equal to limit.
[==============================================================================}
function TIntegerHelper.AdjustMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean; overload;
begin
  Result := ((Self + cValue) >= limit);
  if Result then
    Self := (Self + cValue);
end;

{==============================================================================]
  <Cut>
  @action: Decreases the integer by N.
  @note: Mutates Self in place and returns the updated value after subtraction.
         Equivalent to a prefix-style decrement.
[==============================================================================}
function TIntegerHelper.Cut(const N: Integer = 1): Integer; overload;
begin
  Result := (Self - N);
  Self := Result
end;

{==============================================================================]
  <Dec2>
  @action: Attempts to decrement the integer by N, floored at a minimum limit.
  @note: Returns True if the value was strictly greater than AMin before the operation.
         If Self is already below AMin, it safely clamps Self to AMin and returns False.
[==============================================================================}
function TIntegerHelper.Dec2(const AMin: Integer; const N: Integer = 1): Boolean; overload;
begin
  Result := (Self > AMin);
  if Result then
    Self := Max((Self - N), AMin)
  else if (Self < AMin) then
    Self := AMin;
end;

{==============================================================================]
  <Decr>
  @action: Decrements the integer value by N (default = 1) and returns
           the updated result.
  @note:
    • Uses pre-decrement semantics (result reflects the new value).
    • N may be negative, effectively performing an increment.
    • Only mutates the original variable when called on a true variable;
      calling on a temporary modifies a copy.
[==============================================================================}
function TIntegerHelper.Decr(const N: Integer = 1): Integer; overload;
begin
  Dec(PInteger(@Self)^, N);
  Result := Self;
end;

{==============================================================================]
  <Decrease>
  @action: Decreases the Integer value x by N.
  @note: Returns x before decreasing it with N!
[==============================================================================}
function TIntegerHelper.Decrease(const N: Integer = 1): Integer; overload;
begin
  Result := Self;
  Self := (Self - N);
end;

{==============================================================================]
  <Decrease>
  @action: Decreases the Integer value x by N if B is true.
  @note: Returns x before decreasing!
[==============================================================================}
function TIntegerHelper.Decrease(const B: Boolean; const N: Integer = 1): Integer; overload;
begin
  Result := Self;
  if B then
    Self := (Self - N);
end;

{==============================================================================]
  <Decrement>
  @action: Decreases the Integer value x by N.
  @note: Returns the decreased x!
[==============================================================================}
function TIntegerHelper.Decrement(const N: Integer = 1): Integer; overload;
begin
  Self := (Self - N);
  Result := Self;
end;

{==============================================================================]
  <Decrement>
  @action: Decreases the Integer value x by N if B is true.
  @note: Returns the decreased x!
[==============================================================================}
function TIntegerHelper.Decrement(const B: Boolean; const N: Integer = 1): Integer; overload;
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
function TIntegerHelper.Decret(const N: Integer = 1): Integer; overload;
begin
  Dec(Self, N);
  Result := Self;
end;

{==============================================================================]
  <DecTo>
  @action: Decrements the integer by N towards a minimum limit.
  @note: Returns True if the resulting value has successfully reached or hit AMin.
[==============================================================================}
function TIntegerHelper.DecTo(const AMin: Integer; const N: Integer = 1): Boolean; overload;
begin
  Self := Max((Self - N), AMin);
  Result := (Self = AMin);
end;

{==============================================================================]
  <Give>
  @action: Increases the integer by N.
  @note: Mutates Self and returns the updated value after addition.
         Equivalent to a prefix increment of N.
[==============================================================================}
function TIntegerHelper.Give(const N: Integer = 1): Integer; overload;
begin
  Result := (Self + N);
  Inc(Self, N);
end;

{==============================================================================]
  <Give>
  @action: Increases the integer by N if B is True.
  @note: Mutates Self and returns the updated value after addition.
         Equivalent to a prefix increment of N.
[==============================================================================}
function TIntegerHelper.Give(const B: Boolean; const N: Integer = 1): Integer; overload;
begin
  if not B then 
    Exit(Self);
  Result := (Self + N);
  Inc(Self, N);
end;

{==============================================================================]
  <Inc2>
  @action: Attempts to increment the integer by N, capped at a maximum limit.
  @note: Returns True if the value was strictly less than AMax before the operation.
         If Self already exceeds AMax, it safely clamps Self to AMax and returns False.
[==============================================================================}
function TIntegerHelper.Inc2(const AMax: Integer; const N: Integer = 1): Boolean; overload;
begin
  Result := (Self < AMax);
  if Result then
    Self := Min((Self + N), AMax)
  else if (Self > AMax) then
    Self := AMax;
end;

{==============================================================================]
  <Incr>
  @action: Increments the integer value by N (default = 1) and returns
           the updated result.
  @note:
    • Uses pre-increment semantics (result reflects the new value).
    • N may be negative, effectively performing a decrement.
    • Only mutates the original variable when called on a true variable;
      calling on a temporary modifies a copy.
[==============================================================================}
function TIntegerHelper.Incr(const N: Integer = 1): Integer; overload;
begin
  Inc(PInteger(@Self)^, N);
  Result := Self;
end;

{==============================================================================]
  <Increase>
  @action: Increases the Integer value x by N.
  @note: Returns x before increasing it with N!
[==============================================================================}
function TIntegerHelper.Increase(const N: Integer = 1): Integer; overload;
begin
  Result := Self;
  Self := (Self + N);
end;

{==============================================================================]
  <Increase>
  @action: Increases the Integer value x by N when B is true.
  @note: Returns x before increasing!
[==============================================================================}
function TIntegerHelper.Increase(const B: Boolean; const N: Integer = 1): Integer; overload;
begin
  Result := Self;
  if B then
    Self := (Self + N);
end;

{==============================================================================]
  <Increment>
  @action: Increases the Integer value x by N.
  @note: Returns the increased x!
[==============================================================================}
function TIntegerHelper.Increment(const N: Integer = 1): Integer; overload;
begin
  Self := (Self + N);
  Result := Self;
end;

{==============================================================================]
  <Increment>
  @action: Increases the Integer value x by N if B is true.
  @note: Returns the increased x!
[==============================================================================}
function TIntegerHelper.Increment(const B: Boolean; const N: Integer = 1): Integer; overload;
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
function TIntegerHelper.Incret(const N: Integer = 1): Integer; overload;
begin
  Inc(Self, N);
  Result := Self;
end;

{==============================================================================]
  <IncTo>
  @action: Increments the integer by N towards a maximum limit.
  @note: Returns True if the resulting value has successfully reached or hit AMax.
[==============================================================================}
function TIntegerHelper.IncTo(const AMax: Integer; const N: Integer = 1): Boolean; overload;
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
function TIntegerHelper.Post(const N: Integer = 1): Integer; overload;
begin
  Result := (Self + N);
end;

{==============================================================================]
  <Pre>
  @action: Calculates a relative offset preceding the current value.
  @param: N The distance to look backward (defaults to 1).
  @return: The pure mathematical result of (Self - N).
  @note: Immutable. Does not mutate Self. Useful for safe, side-effect-free
         look-behind operations in arrays and streams.
[==============================================================================}
function TIntegerHelper.Pre(const N: Integer = 1): Integer; overload;
begin
  Result := (Self - N);
end;

{==============================================================================]
  <Pred>
  @action: Returns the predecessor of Self, decreased by N, not below minBound.
  @note: Uses Int64 arithmetic to prevent underflow; default N = 1, default minBound = Low(Integer).
[==============================================================================}
function TIntegerHelper.Pred(const N: Integer = 1; const minBound: Integer = -2147483648): Integer; overload;
begin
  Result := Max((Int64(Self) - N), minBound);
end;

{==============================================================================]
  <Put>
  @action: Increases the integer by N.
  @note: Mutates Self in place and returns the updated value after addition.
         Equivalent to a prefix-style increment.
[==============================================================================}
function TIntegerHelper.Put(const N: Integer = 1): Integer; overload;
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
function TIntegerHelper.Retinc(const N: Integer = 1): Integer; overload;
begin
  Result := Self;
  Inc(Self, N);
end;

{==============================================================================]
  <Retdec>
  @action: Returns the current value of Self, then decrements Self by N.
  @param: N The step delta to decrement by (defaults to 1).
  @return: The historical (old) value of Self prior to the decrement.
[==============================================================================}
function TIntegerHelper.Retdec(const N: Integer = 1): Integer; overload;
begin
  Result := Self;
  Dec(Self, N);
end;

{==============================================================================]
  <Succ>
  @action: Returns the successor of Self, increased by N, not above maxBound.
  @note: Uses Int64 arithmetic to prevent overflow; default N = 1, default maxBound = High(Integer).
[==============================================================================}
function TIntegerHelper.Succ(const N: Integer = 1; const maxBound: Integer = 2147483647): Integer; overload;
begin
  Result := Min((Int64(Self) + N), maxBound);
end;

{==============================================================================]
  <Take>
  @action: Decreases the integer by N.
  @note: Mutates Self and returns the updated value after subtraction.
         Equivalent to a prefix decrement of N.
[==============================================================================}
function TIntegerHelper.Take(const N: Integer = 1): Integer; overload;
begin
  Result := (Self - N);
  Dec(Self, N);
end;

{==============================================================================]
  <Take>
  @action: Decreases the integer by N if B is True.
  @note: Mutates Self and returns the updated value after subtraction.
         Equivalent to a prefix decrement of N.
[==============================================================================}
function TIntegerHelper.Take(const B: Boolean; const N: Integer = 1): Integer; overload;
begin
  if not B then
    Exit(Self);
  Result := (Self - N);
  Dec(Self, N);
end;

{==============================================================================]
  <Update>
  @action: Adjusts the integer by cValue and clamps it within the specified limits.
  @note: Returns True if the result was within the range and assigned without clamping.
[==============================================================================}
function TIntegerHelper.Update(const cValue: Integer; const limits: TRange): Boolean; overload;
var
  r: TRange;
  n: Integer;
begin
  r := limits.Normalized;
  n := (Self + cValue);
  if (n < r.start) then
    Self := r.start
  else if (n > r.stop) then
    Self := r.stop
  else
    Self := n;
  Result := (n = Self);
end;

{==============================================================================]
  <Updated>
  @action: Returns a new value equal to Self + cValue, clamped within the specified limits.
  @note: Does not modify Self.
[==============================================================================}
function TIntegerHelper.Updated(const cValue: Integer; const limits: TRange): Integer; overload;
var
  r: TRange;
  n: Integer;
begin
  r := limits.Normalized;
  n := (Self + cValue);
  if (n < r.start) then
    Result := r.start
  else if (n > r.stop) then
    Result := r.stop
  else
    Result := n;
end;

{==============================================================================]
  <UpdatedMax>
  @action: Returns Self + cValue, ensuring the result is not above limit.
  @note: Does not modify Self.
[==============================================================================}
function TIntegerHelper.UpdatedMax(const cValue: Integer; const limit: Integer = 2147483647): Integer; overload;
var
  n: Integer;
begin
  n := (Self + cValue);
  if (n > limit) then
    Result := limit
  else
    Result := n;
end;

{==============================================================================]
  <UpdatedMin>
  @action: Returns Self + cValue, ensuring the result is not below limit.
  @note: Does not modify Self.
[==============================================================================}
function TIntegerHelper.UpdatedMin(const cValue: Integer; const limit: Integer = -2147483648): Integer; overload;
var
  n: Integer;
begin
  n := (Self + cValue);
  if (n < limit) then
    Result := limit
  else
    Result := n;
end;

{==============================================================================]
  <UpdateMax>
  @action: Adjusts the integer by cValue, ensuring it does not exceed limit.
  @note: Returns True if the result was below or equal to limit (no clamping).
[==============================================================================}
function TIntegerHelper.UpdateMax(const cValue: Integer; const limit: Integer = 2147483647): Boolean; overload;
var
  n: Integer;
begin
  n := (Self + cValue);
  if (n > limit) then
    Self := limit
  else
    Self := n;
  Result := (n = Self);
end;

{==============================================================================]
  <UpdateMin>
  @action: Adjusts the integer by cValue, ensuring it does not fall below limit.
  @note: Returns True if the result was above or equal to limit (no clamping).
[==============================================================================}
function TIntegerHelper.UpdateMin(const cValue: Integer; const limit: Integer = -2147483648): Boolean; overload;
var
  n: Integer;
begin
  n := (Self + cValue);
  if (n < limit) then
    Self := limit
  else
    Self := n;
  Result := (n = Self);
end;

{==============================================================================]
  <X>
  @action: Returns the value of the integer multiplied by the specified factor `N`.
  @note:
    - Does not modify the original integer; returns the computed value.
    - If `N` is not specified, it defaults to 1 and returns the integer itself.
    - Equivalent to `Self * N`.
[==============================================================================}
function TIntegerHelper.X(const N: Integer = 1): Integer; overload;
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
function TIntegerHelper.X2(const N: Integer = 1): Integer; overload;
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
function TIntegerHelper.X3(const N: Integer = 1): Integer; overload;
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
function TIntegerHelper.X4(const N: Integer = 1): Integer; overload;
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
function TIntegerHelper.X10(const N: Integer = 1): Integer; overload;
begin
  Result := ((Self * 10) * N);
end;

{==============================================================================]
  <Dec2>
  @action: Decrements two variables by a specified value and returns their sum.
  @note: Operates directly on the passed variables (var). Defaults to subtracting 1.
         Returns the sum as Int64 to prevent overflow.
[==============================================================================}
function Dec2(var A, B: Integer; const N: Integer = 1): Int64; overload;
begin
  Dec(A, N);
  Dec(B, N);
  Result := (Int64(A) + Int64(B));
end;

{==============================================================================]
  <Dec3>
  @action: Decrements three variables by a specified value and returns their sum.
  @note: Operates directly on the passed variables (var). Defaults to subtracting 1.
         Returns the sum as Int64 to prevent overflow.
[==============================================================================}
function Dec3(var A, B, C: Integer; const N: Integer = 1): Int64; overload;
begin
  Dec(A, N);
  Dec(B, N);
  Dec(C, N);
  Result := (Int64(A) + Int64(B) + Int64(C));
end;

{==============================================================================]
  <Dec4>
  @action: Decrements four variables by a specified value and returns their sum.
  @note: Operates directly on the passed variables (var). Defaults to subtracting 1.
         Returns the sum as Int64 to prevent overflow.
[==============================================================================}
function Dec4(var A, B, C, D: Integer; const N: Integer = 1): Int64; overload;
begin
  Dec(A, N);
  Dec(B, N);
  Dec(C, N);
  Dec(D, N);
  Result := (Int64(A) + Int64(B) + Int64(C) + Int64(D));
end;

{==============================================================================]
  <DecGet>
  @action: Decrements val by N.
  @note: Returns the updated value after subtraction (prefix decrement semantics).
[==============================================================================}
function DecGet(var val: Integer; const N: Integer = 1): Integer; overload;
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
function DecGet(var val: Integer; const B: Boolean; const N: Integer = 1): Integer; overload;
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
function GetDec(var val: Integer; const N: Integer = 1): Integer; overload;
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
function GetDec(var val: Integer; const B: Boolean; const N: Integer = 1): Integer; overload;
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
function GetInc(var val: Integer; const N: Integer = 1): Integer; overload;
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
function GetInc(var val: Integer; const B: Boolean; const N: Integer = 1): Integer; overload;
begin
  Result := val;
  if B then
    val := (val + N);
end;

{==============================================================================]
  <Inc2>
  @action: Increments two variables by a specified value and returns their sum.
  @note: Operates directly on the passed variables (var). Defaults to adding 1.
         Returns the sum as Int64 to prevent overflow.
[==============================================================================}
function Inc2(var A, B: Integer; const N: Integer = 1): Int64; overload;
begin
  Inc(A, N);
  Inc(B, N);
  Result := (Int64(A) + Int64(B));
end;

{==============================================================================]
  <Inc3>
  @action: Increments three variables by a specified value and returns their sum.
  @note: Operates directly on the passed variables (var). Defaults to adding 1.
         Returns the sum as Int64 to prevent overflow.
[==============================================================================}
function Inc3(var A, B, C: Integer; const N: Integer = 1): Int64; overload;
begin
  Inc(A, N);
  Inc(B, N);
  Inc(C, N);
  Result := (Int64(A) + Int64(B) + Int64(C));
end;

{==============================================================================]
  <Inc4>
  @action: Increments four variables by a specified value and returns their sum.
  @note: Operates directly on the passed variables (var). Defaults to adding 1.
         Returns the sum as Int64 to prevent overflow.
[==============================================================================}
function Inc4(var A, B, C, D: Integer; const N: Integer = 1): Int64; overload;
begin
  Inc(A, N);
  Inc(B, N);
  Inc(C, N);
  Inc(D, N);
  Result := (Int64(A) + Int64(B) + Int64(C) + Int64(D));
end;

{==============================================================================]
  <IncGet>
  @action: Increments val by N.
  @note: Returns the updated value after addition (prefix increment semantics).
[==============================================================================}
function IncGet(var val: Integer; const N: Integer = 1): Integer; overload;
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
function IncGet(var val: Integer; const B: Boolean; const N: Integer = 1): Integer; overload;
begin
  if B then
    val := (val + N);
  Result := val;
end;

{==============================================================================]
  <X>
  @action: Multiplies the given integer variable `val` by the specified factor `N`
           and returns the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - If `N` is not specified, it defaults to 1 and `val` remains unchanged.
    - Equivalent to: `val := val * N`.
[==============================================================================}
function X(var val: Integer; const N: Integer = 1): Integer; overload;
begin
  val := (val * N);
  Result := val;
end;

{==============================================================================]
  <X2>
  @action: Multiplies the given integer variable `val` by 2 and further scales it by
           the specified factor `N`, returning the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - Equivalent to: `val := val * (2 * N)`.
    - If `N` is not specified, it defaults to 1 and `val` is multiplied by 2.
[==============================================================================}
function X2(var val: Integer; const N: Integer = 1): Integer; overload;
begin
  val := ((val * 2) * N);
  Result := val;
end;

{==============================================================================]
  <X3>
  @action: Multiplies the given integer variable `val` by 3 and further scales it by
           the specified factor `N`, returning the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - Equivalent to: `val := val * (3 * N)`.
    - If `N` is not specified, it defaults to 1 and `val` is multiplied by 3.
[==============================================================================}
function X3(var val: Integer; const N: Integer = 1): Integer; overload;
begin
  val := ((val * 3) * N);
  Result := val;
end;

{==============================================================================]
  <X4>
  @action: Multiplies the given integer variable `val` by 4 and further scales it by
           the specified factor `N`, returning the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - Equivalent to: `val := val * (4 * N)`.
    - If `N` is not specified, it defaults to 1 and `val` is multiplied by 4.
[==============================================================================}
function X4(var val: Integer; const N: Integer = 1): Integer; overload;
begin
  val := ((val * 4) * N);
  Result := val;
end;

{==============================================================================]
  <X10>
  @action: Multiplies the given integer variable `val` by 10 and further scales it by
           the specified factor `N`, returning the resulting value.
  @note:
    - The parameter `val` is modified in-place.
    - Equivalent to: `val := val * (10 * N)`.
    - If `N` is not specified, it defaults to 1 and `val` is multiplied by 10.
[==============================================================================}
function X10(var val: Integer; const N: Integer = 1): Integer; overload;
begin
  val := ((val * 10) * N);
  Result := val;
end;
{$ENDIF}
