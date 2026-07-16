{$IFDEF FUNCTIONS}
function Med3(const A, B, C: MType): MType; overload;
function Median3(const A, B, C: MType): MType; overload;
function Mid3(const A, B, C: MType): MType; overload;
function Middle3(const A, B, C: MType): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Med3>
  @action: Determines and returns the median (middle/median value) among three inputs (A, B, and C).
  @note: Implements a classic algebraic median filter using nested `Min` and `Max` operations. 
         * `Min(A, B)` isolates the smaller of the first two elements.
         * `Min(Max(A, B), C)` ensures that if `C` is smaller than the largest of `A` and `B`, it is capped.
         * The outer `Max` combines these boundaries to yield the exact middle element.
         * This approach is highly efficient as it eliminates branching mispredictions, assuming `Min` 
           and `Max` are optimized.
[==============================================================================}
function Med3(const A, B, C: MType): MType; overload;
begin
  Result := Max(Min(A, B), Min(Max(A, B), C));
end;

{==============================================================================]
  <Median3>
  @action: Returns the median of three items.
  @note: None.
[==============================================================================}
function Median3(const A, B, C: MType): MType; overload;
begin
  if (((B < A) and (C > A)) or ((C < A) and (B > A))) then
    Result := A
  else if (((A < B) and (C > B)) or ((C < B) and (A > B))) then
    Result := B
  else
    Result := C;
end;

{==============================================================================]
  <Mid3>
  @action: Compares three items (A, B, and C) and returns the median (middle) value.
  @note: Implements a decision-tree algorithm using a combination of a boolean `case` statement
         and nested `if-then-else` blocks.
         * The `True` branch handles scenarios where $A > B$, reducing the remaining checks to
           positioning `C` relative to `A` and `B`.
         * The `False` branch handles scenarios where $A \le B$, swapping the logic accordingly.
         * While this layout introduces nested branching paths, it executes a maximum of only two
           comparisons per call, making it highly computationally efficient.
[==============================================================================}
function Mid3(const A, B, C: MType): MType; overload;
begin
  case (A > B) of
    True:
    if (B > C) then
      Result := B
    else if (A > C) then
      Result := C
    else
      Result := A;
    False:
    if (A > C) then
      Result := A
    else if (B > C) then
      Result := C
    else
      Result := B;
  end;
end;

{==============================================================================]
  <Middle3>
  @action: Evaluates three inputs (A, B, and C) of type `MType` and returns the median (middle) value.
  @note: Uses explicit compound boolean logic to check if an element sits between the other two 
         (e.g., checking if $B < A < C$ or $C < A < B$). 
         * This method is highly readable because it maps out every permutation directly.
         * The final `else` branch acts as a fallback default, returning `A` if none of the explicit 
           middle conditions are met (which handles cases where two or all three values are equal).
         * Because it uses complex logical statements, it may execute up to 4 comparisons per block 
           if short-circuiting doesn't exit early, making it slightly more intensive than a decision tree.
[==============================================================================}
function Middle3(const A, B, C: MType): MType; overload;
begin
  if (((B < A) and (C > A)) or ((C < A) and (B > A))) then
    Result := A
  else if (((A < B) and (C > B)) or ((C < B) and (A > B))) then
    Result := B
  else if (((A < C) and (B > C)) or ((B < C) and (A > C))) then
    Result := C
  else
    Result := A;
end;
{$ENDIF}
