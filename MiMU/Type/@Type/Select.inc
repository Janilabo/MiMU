{$IFDEF HELPERS}
function All(const conditions: TBooleanArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Allowed(const conditions: TBooleanArray; const target: Integer; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Any(const conditions: TBooleanArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Balanced(const conditions: TBooleanArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Both(const A, B: Boolean; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Compliant(const conditions: TBooleanArray; const target: TRange; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Concur(const A, B: Boolean; const fallback: MType): MType; overload;
function Discord(const A, B: Boolean; const fallback: MType): MType; overload;
function Either(const A, B: Boolean; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Implies(const A, B: Boolean; const fallback: MType): MType; overload;
function Majority(const conditions: TBooleanArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Neither(const A, B: Boolean; const fallback: MType; const wanted: Boolean = True): MType; overload;
function None(const conditions: TBooleanArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Only(const conditions: TBooleanArray; const fallback: MType; const target: UInt32 = 1; const wanted: Boolean = True): MType; overload;
function Quota(const conditions: TBooleanArray; const target: Integer; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Required(const conditions: TBooleanArray; const target: Integer; const fallback: MType; const wanted: Boolean = True): MType; overload;
function When(const condition: Boolean; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Which(const A, B: MType): Integer; overload;
function Which(const A, B, C: MType): Integer; overload;
function Which(const A, B, C, D: MType): Integer; overload;
function Which(const N: MArray; const fallback: Integer = -1): Integer; overload;
function Unless(const condition: Boolean; const fallback: MType): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <All>
  @action: Enforces uniform compliance across a dynamic array of conditions. 
           Returns 'Self' if EVERY single boolean in the array matches the 
           'wanted' target state; immediately exits and returns 'fallback' if 
           even one condition fails the match.
  @note: Replaces fixed dual-variable gates ('Both') to scale across any number 
         of constraints. When 'wanted' is True (default), it acts as a global 
         AND gate. When 'wanted' is False, it acts as a global NOR gate (asserting 
         that absolutely nothing in the array has failed or triggered).
[==============================================================================}
function MTypeHelper.All(const conditions: TBooleanArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
var
  c: Boolean;
begin
  Result := Self;
  for c in conditions do
    if (c <> wanted) then
      Exit(fallback);
end;

{==============================================================================]
  <Allowed>
  @action: Enforces a maximum tolerance ceiling on matching conditions. Returns 
           'fallback' the exact moment the quantity of booleans matching 
           'wanted' exceeds the permitted 'target' threshold; otherwise, 
           returns 'Self'.
  @note: Implements a defensive dual-layer short-circuit optimization. It 
         pre-checks the array bounds to instantly pass if the ceiling cannot 
         be reached, and utilizes a predictive look-ahead inside the iteration 
         loop to bail out early with a 'Self' success the millisecond it 
         becomes mathematically certain that even if all remaining unexamined 
         elements match 'wanted', the total count will never breach the 
         allowed threshold.
[==============================================================================}
function MTypeHelper.Allowed(const conditions: TBooleanArray; const target: Integer; const fallback: MType; const wanted: Boolean = True): MType; overload;
var
  i, m, l: Integer;
begin
  if (target < 0) then
    Exit(fallback);
  l := conditions.Length;
  if (target >= l) then
    Exit(Self);
  m := 0;
  for i := 0 to (l - 1) do
  begin
    if ((conditions[i] = wanted) and (m.Increment > target)) then
      Exit(fallback);
    if ((m + (l - 1 - i)) <= target) then
      Exit(Self);
  end;
  Result := Self;
end;

{==============================================================================]
  <Any>
  @action: Seeks a single matching signal within a dynamic array of conditions. 
           Returns 'Self' the moment it encounters the first boolean that matches 
           the 'wanted' target state; if the entire array is scanned without a 
           single match, it returns 'fallback'.
  @note: Replaces fixed dual-variable gates ('Either') for dynamic arrays, utilizing 
         short-circuit evaluation for maximum performance. When 'wanted' is True 
         (default), it acts as a global OR gate. When 'wanted' is False, it acts 
         as a global NAND gate (passing Self if there is at least one safe state).
[==============================================================================}
function MTypeHelper.Any(const conditions: TBooleanArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
var
  c: Boolean;
begin
  for c in conditions do
    if (c = wanted) then
      Exit(Self);
  Result := fallback;
end;

{==============================================================================][
  <Balanced>
  @action: Returns `Self` if the array contains an even number of elements and an 
           equal split of `wanted` (defaults to `True`) and opposite boolean values; 
           otherwise returns `fallback`.
  @note: Short-circuits early if array length is odd, or as soon as either matching 
         or opposing element counts exceed half the total elements.
[==============================================================================}
function MTypeHelper.Balanced(const conditions: TBooleanArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
var
  i, m, t, l: Integer;
begin
  l := conditions.Length;
  if l.Odd then
    Exit(fallback);
  t := (l div 2);
  m := 0;
  for i := 0 to (l - 1) do
  case (conditions[i] = wanted) of 
    True:
    if (m.Increment > t) then
      Exit(fallback);
    False:
	if ((m + (l - 1 - i)) < t) then
      Exit(fallback);
  end;
  Result := Self.When((m = t), fallback);
end;

{==============================================================================]
  <Both>
  @action: Asserts that BOTH boolean conditions ('A' and 'B') uniformly match 
           the target 'wanted' state. Returns the current 'MType' instance 
           ('Self') only if both criteria are perfectly met; otherwise, routes 
           to the specified 'fallback' value.
  @note: Acts as a strict dual-matching gatekeeper. When 'wanted' is True 
         (default), it behaves as a logical AND (both must be True). When 
         'wanted' is False, it behaves as a logical NOR (both must be False), 
         making it highly adaptable for enforcing complete compliance across 
         dual-key states.
[==============================================================================}
function MTypeHelper.Both(const A, B: Boolean; const fallback: MType; const wanted: Boolean = True): MType; overload;
begin
  if ((A = wanted) and (B = wanted)) then
    Result := Self
  else
    Result := fallback;
end;

{==============================================================================]
  <Compliant>
  @action: Returns `Self` if the total count of matching boolean conditions falls 
           within the specified range; otherwise returns `fallback`.
  @note: Normalizes the range first and short-circuits with `fallback` early if 
         matches exceed `target.Stop` or if remaining elements cannot reach `target.Start`.
[==============================================================================}
function MTypeHelper.Compliant(const conditions: TBooleanArray; const target: TRange; const fallback: MType; const wanted: Boolean = True): MType; overload;
var
  i, m, l: Integer;
  t: TRange;
begin
  l := conditions.Length;
  t := target.Normalize;
  if ((t.start < 0) or (t.start > l)) then
    Exit(fallback);
  m := 0;
  for i := 0 to (l - 1) do
    if (((conditions[i] = wanted) and (m.Increment > t.stop)) or ((m + (l - 1 - i)) < t.start)) then
      Exit(fallback);
  Result := Self.When((m >= t.start), fallback);
end;

{==============================================================================]
  <Concur>
  @action: Returns `Self` if two boolean conditions are identical (both True or both False); otherwise returns `fallback`.
  @note: Acts as a logical equivalence (XNOR) gate, evaluating agreement between two states.
[==============================================================================}
function MTypeHelper.Concur(const A, B: Boolean; const fallback: MType): MType; overload;
begin
  Result := Self.When((A = B), fallback);
end;

{==============================================================================]
  <Discord>
  @action: Returns `Self` if two boolean conditions differ (one True and one False); otherwise returns `fallback`.
  @note: Acts as an exclusive OR (XOR) gate, evaluating disagreement/conflict between two states.
[==============================================================================}
function MTypeHelper.Discord(const A, B: Boolean; const fallback: MType): MType; overload;
begin
  Result := Self.When((A <> B), fallback);
end;

{==============================================================================]
  <Either>
  @action: Compares two boolean conditions ('A' and 'B') against a target state 
           ('wanted'). Returns the current 'MType' instance ('Self') if either 
           condition matches the target; otherwise, returns the 'fallback' 
           'MType' instance.
  @note: Provides fluent conditional branching for 'MType' objects. When 'wanted' 
         is True (default), it passes 'Self' if either condition is met. When 
         'wanted' is False, it acts as an escape filter, passing 'Self' if at 
         least one condition is absent and dropping to 'fallback' only when both 
         conditions are locked in the undesired True state.
[==============================================================================}
function MTypeHelper.Either(const A, B: Boolean; const fallback: MType; const wanted: Boolean = True): MType; overload;
begin
  if ((A = wanted) or (B = wanted)) then
    Result := Self
  else
    Result := fallback;
end;

{==============================================================================][
  <Implies>
  @action: Returns `Self` if boolean condition `A` material implies condition `B` 
           (`not A or B`); otherwise returns `fallback`.
  @note: Implements material implication (A → B). Returns `fallback` only in 
         the single failure case where `A` is True and `B` is False.
[==============================================================================}
function MTypeHelper.Implies(const A, B: Boolean; const fallback: MType): MType; overload;
begin
  Result := Self.When(((not A) or B), fallback);
end;

{==============================================================================]
  <Majority>
  @action: Returns `Self` if more than 50% of the boolean conditions match `wanted`; 
           otherwise returns `fallback`.
  @note: Delegates evaluation to `Required`, calculating the minimum threshold 
         as `(Length div 2) + 1` (strict simple majority).
[==============================================================================}
function MTypeHelper.Majority(const conditions: TBooleanArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
begin
  Result := Self.Required(conditions, ((conditions.Length div 2) + 1), fallback, wanted);
end;

{==============================================================================]
  <Neither>
  @action: Asserts that neither condition matches the target 'wanted' state. 
           Returns the current 'MType' instance ('Self') only if both conditions 
           fail the match; otherwise, returns the 'fallback' value.
  @note: Acts as a dynamic inversion gate. When 'wanted' is True (default), it 
         behaves as a logical NOR (returns Self only if both A and B are False). 
         When 'wanted' is False, it flips into a logical AND (returns Self only 
         if both A and B are True), asserting that neither variable is False.
[==============================================================================}
function MTypeHelper.Neither(const A, B: Boolean; const fallback: MType; const wanted: Boolean = True): MType; overload;
begin
  if (not (A = wanted) and not (B = wanted)) then
    Result := Self
  else
    Result := fallback;
end;

{==============================================================================]
  <None>
  @action: Enforces total exclusion across a dynamic array of conditions. 
           Returns 'Self' only if ABSOLUTELY NO boolean in the array matches 
           the 'wanted' target state; immediately exits and returns 'fallback' 
           the moment a single match is found.
  @note: Provides an elegant short-circuiting exclusion gate for arrays. When 
         'wanted' is True (default), it acts as a global NOR gate (passing Self 
         only if all conditions are False). When 'wanted' is False, it acts as 
         a global AND gate (passing Self only if all conditions are True, meaning 
         none of them are False).
[==============================================================================}
function MTypeHelper.None(const conditions: TBooleanArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
var
  c: Boolean;
begin
  for c in conditions do
    if (c = wanted) then
      Exit(fallback);
  Result := Self;
end;

{==============================================================================]
  <Only>
  @action: Returns `Self` if the number of matching boolean conditions in `conditions` 
           equals `target` (defaulting to exactly 1); otherwise returns `fallback`.
  @note: A specialized shortcut for exact-count matching with early-exit 
         short-circuiting when matches exceed `target` or remaining elements fall short.
[==============================================================================}
function MTypeHelper.Only(const conditions: TBooleanArray; const fallback: MType; const target: UInt32 = 1; const wanted: Boolean = True): MType; overload;
var
  i, m, l: Integer;
begin
  l := conditions.Length;
  if (target > l) then
    Exit(fallback);
  m := 0;
  for i := 0 to (l - 1) do
    if (((conditions[i] = wanted) and (m.Increment > target)) or ((m + (l - 1 - i)) < target)) then
      Exit(fallback);
  Result := Self.When((m = target), fallback);
end;

{==============================================================================]
  <Quota>
  @action: Returns `Self` if the number of matches in `conditions` strictly 
           equals `target`; otherwise, returns `fallback` early (or at the end).
  @note: Uses early-exit short-circuiting when it becomes mathematically 
         impossible for the remaining array elements to meet or equal the target.
[==============================================================================}
function MTypeHelper.Quota(const conditions: TBooleanArray; const target: Integer; const fallback: MType; const wanted: Boolean = True): MType; overload;
var
  i, m, l: Integer;
begin
  if ((target < 0) or (target > conditions.Length)) then
    Exit(fallback);
  l := conditions.Length;
  m := 0;
  for i := 0 to (l - 1) do
    if ((conditions[i] = wanted) and (m.Increment > target)) then
      Exit(fallback)
    else if ((m + (l - 1 - i)) < target) then
      Exit(fallback);
  Result := Self.When((m = target), fallback);
end;

{==============================================================================]
  <Required>
  @action: Enforces a mandatory minimum floor of matching conditions. Returns 
           'Self' the exact moment the quantity of booleans matching 'wanted' 
           reaches the 'target' threshold; otherwise, redirects to 'fallback'.
  @note: Implements an aggressive dual-layer short-circuit optimization. It 
         pre-checks the array bounds to instantly catch structural failures, 
         and utilizes a predictive look-ahead inside the iteration loop to 
         bail out with a 'fallback' failure the millisecond it becomes 
         mathematically impossible for the remaining unexamined elements to 
         satisfy the required target count.
[==============================================================================}
function MTypeHelper.Required(const conditions: TBooleanArray; const target: Integer; const fallback: MType; const wanted: Boolean = True): MType; overload;
var
  i, m, l: Integer;
begin
  if (target <= 0) then
    Exit(Self);
  l := conditions.Length;
  if (target > l) then
    Exit(fallback);
  m := 0;
  for i := 0 to (l - 1) do
  begin
    if ((conditions[i] = wanted) and (m.Increment >= target)) then
      Exit(Self);
    if ((m + (l - 1 - i)) < target) then
      Exit(fallback);
  end;
  Result := fallback;
end;

{==============================================================================]
  <When>
  @action: Returns `Self` if `condition` matches `wanted` (defaults to `True`); 
           otherwise returns `fallback`.
  @note: Streamlines inline fluent conditional evaluations, replacing clunky 
         ternary simulations or verbose if/then blocks.
[==============================================================================}
function MTypeHelper.When(const condition: Boolean; const fallback: MType; const wanted: Boolean = True): MType; overload;
begin
  if (condition = wanted) then 
    Result := Self 
  else 
    Result := fallback;
end;

{==============================================================================]
  <Which>
  @action: Returns the zero-based index of Self among two options (A=0, B=1), or -1 if unmapped.
  @note: Evaluates sequentially from left to right and returns on the first match.
[==============================================================================}
function MTypeHelper.Which(const A, B: MType): Integer; overload;
begin
  if (Self = A) then
    Result := 0
  else if (Self = B) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
  <Which>
  @action: Returns the zero-based index of Self among three options (A=0, B=1, C=2), or -1 if unmapped.
  @note: Evaluates sequentially from left to right and returns on the first match.
[==============================================================================}
function MTypeHelper.Which(const A, B, C: MType): Integer; overload;
begin
  if (Self = A) then
    Result := 0
  else if (Self = B) then
    Result := 1
  else if (Self = C) then
    Result := 2
  else
    Result := -1;
end;

{==============================================================================]
  <Which>
  @action: Returns the zero-based index of Self among four options (A=0, B=1, C=2, D=3), or -1 if unmapped.
  @note: Evaluates sequentially from left to right and returns on the first match.
[==============================================================================}
function MTypeHelper.Which(const A, B, C, D: MType): Integer; overload;
begin
  if (Self = A) then
    Result := 0
  else if (Self = B) then
    Result := 1
  else if (Self = C) then
    Result := 2
  else if (Self = D) then
    Result := 3
  else
    Result := -1;
end;

{==============================================================================]
  <Which>
  @action: Searches for Self within an array of targets and returns its zero-based index.
  @note: Returns the specified fallback value (defaulting to -1) if no matching element is found.
[==============================================================================}
function MTypeHelper.Which(const N: MArray; const fallback: Integer = -1): Integer; overload;
begin
  for Result := 0 to High(N) do
    if (Self = N[Result]) then
	  Exit;
  Result := fallback;
end;

{==============================================================================]
  <Unless>
  @action: Returns Self unless the condition prevents it (True), in which 
           case it returns the specified fallback value (fallback).
  @note: Pairs perfectly with 'When' to evaluate negative assertions without 
         forcing the developer to clutter expressions with 'not' operators.
[==============================================================================}
function MTypeHelper.Unless(const condition: Boolean; const fallback: MType): MType; overload;
begin
  if not condition then 
    Result := Self 
  else
    Result := fallback;
end;
{$ENDIF}
