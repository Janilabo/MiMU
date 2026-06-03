{$IFDEF HELPERS}
function All(const conditions: TBooleanArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Any(const conditions: TBooleanArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Both(const A, B: Boolean; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Either(const A, B: Boolean; const fallback: MType; const wanted: Boolean = True): MType; overload;
function Neither(const A, B: Boolean; const fallback: MType; const wanted: Boolean = True): MType; overload;
function None(const conditions: TBooleanArray; const fallback: MType; const wanted: Boolean = True): MType; overload;
function When(const condition: Boolean; const fallback: MType): MType; overload;
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
  <When>
  @action: Returns Self if the condition is met (True), otherwise returns 
           the specified fallback value.
  @note: Streamlines inline fluent conditional evaluations, replacing clunky 
         ternary simulations or verbose if/then blocks.
[==============================================================================}
function MTypeHelper.When(const condition: Boolean; const fallback: MType): MType; overload;
begin
  if condition then 
    Result := Self 
  else 
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
