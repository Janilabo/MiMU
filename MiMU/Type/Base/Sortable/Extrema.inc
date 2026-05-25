{$IFDEF FUNCTIONS}
function Max3(const A, B, C: MType): MType; overload;
function MaxBy(const A, B, C: MType): MType; overload;
function Maximal(const A, B, C: MType): MType; overload;
function Maxim(const A, B, C: MType): MType; overload;
function MaximumOf(const A, B, C: MType): MType; overload;
function Min3(const A, B, C: MType): MType; overload;
function MinBy(const A, B, C: MType): MType; overload;
function Minimal(const A, B, C: MType): MType; overload;
function Minim(const A, B, C: MType): MType; overload;
function MinimumOf(const A, B, C: MType): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Max3>
  @action: Returns the highest value among three items using left-associative nesting.
  @note: Groups the first two elements first: Max(Max(A, B), C). Clean, highly readable representation of extreme upper bounds.
[==============================================================================}
function Max3(const A, B, C: MType): MType; overload;
begin
  Result := Max(Max(A, B), C);
end;

{==============================================================================]
  <MaxBy>
  @action: Returns the highest value among three items using right-associative nesting.
  @note: Groups the last two elements first: Max(A, Max(B, C)). Useful choice if the upper extremes tend to cluster toward the trailing arguments.
[==============================================================================}
function MaxBy(const A, B, C: MType): MType; overload;
begin
  Result := Max(A, Max(B, C));
end;

{==============================================================================]
  <Maximal>
  @action: Returns the largest (maximum) value among three provided items (A, B, and C).
  @note: Relies on nested `IfThen` Because 
         `IfThen` does not support short-circuit evaluation, all branch expressions are eagerly 
         evaluated. Since it is marked as `overload`, ensure that other variations of this function 
         (e.g., for Int64 or Double) have distinct parameter types.
[==============================================================================}
function Maximal(const A, B, C: MType): MType; overload;
begin
  Result := IfThen((A > B), IfThen((A > C), A, C), IfThen((B > C), B, C));
end;

{==============================================================================]
  <Maxim>
  @action: Determines the maximum of three items using a single conditional branch combined with a nested Max call.
  @note: Reduces overhead by evaluating the relationship between A and B prior to isolating the absolute maximum against C.
[==============================================================================}
function Maxim(const A, B, C: MType): MType; overload;
begin
  if (A > B) then
    Result := Max(A, C)
  else
    Result := Max(B, C);
end;

{==============================================================================]
  <MaximumOf>
  @action: Determines the maximum of three integers using pure manual conditional logic wrapped in a boolean case block.
  @note: Completely independent of external Math dependencies. Guarantees exactly 2 comparisons under every scenario via hardcoded decision paths.
[==============================================================================}
function MaximumOf(const A, B, C: MType): MType; overload;
begin
  case (A > B) of
    True:
    if (A > C) then
      Result := A
    else
      Result := C;
    False:
    if (B > C) then
      Result := B
    else
      Result := C;
  end;
end;

{==============================================================================]
  <Min3>
  @action: Returns the lowest value among three items using left-associative nesting.
  @note: Groups the first two elements first: Min(Min(A, B), C).
         Clear and readable, though requires up to 3 comparisons depending on compiler optimization.
[==============================================================================}
function Min3(const A, B, C: MType): MType; overload;
begin
  Result := Min(Min(A, B), C);
end;

{==============================================================================]
  <MinBy>
  @action: Returns the lowest value among three items using right-associative nesting.
  @note: Groups the last two elements first: Min(A, Min(B, C)).
         Functionally identical to Min3, optimized if the final parameters are more likely to contain the minimum.
[==============================================================================}
function MinBy(const A, B, C: MType): MType; overload;
begin
  Result := Min(A, Min(B, C));
end;

{==============================================================================]
  <Minimal>
  @action: Returns the smallest (minimum) value among three provided items (A, B, and C).
  @note: Uses nested ternary-like `IfThen` functions for conditional evaluation.
         `IfThen` is a function, meaning all arguments (including both the True and False expressions) 
         are evaluated before the function is called. This can have minor performance implications 
         compared to traditional `if-then-else` statements, though negligible for simple types.
[==============================================================================}
function Minimal(const A, B, C: MType): MType; overload;
begin
  Result := IfThen((A < B), IfThen((A < C), A, C), IfThen((B < C), B, C));
end;

{==============================================================================]
  <Minim>
  @action: Determines the minimum of three items using a single conditional branch combined with a nested Min call.
  @note: Drops the worst-case comparison count by checking the relationship between A and B first, then comparing the survivor against C.
[==============================================================================}
function Minim(const A, B, C: MType): MType; overload;
begin
  if (A < B) then
    Result := Min(A, C)
  else
    Result := Min(B, C);
end;

{==============================================================================]
  <MinimumOf>
  @action: Determines the minimum of three items using pure manual conditional logic wrapped in a boolean case block.
  @note: Zero reliance on external Math unit functions. Guarantees exactly 2 comparisons in all execution paths via manual decision-tree routing.
[==============================================================================}
function MinimumOf(const A, B, C: MType): MType; overload;
begin
  case (A < B) of
    True:
    if (A < C) then
      Result := A
    else
      Result := C;
    False:
    if (B < C) then
      Result := B
    else
      Result := C;
  end;
end;
{$ENDIF}