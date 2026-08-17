{$IFDEF HELPERS}
function Combat(const target: MType; const aAscending: Boolean = True): Integer; overload;
function Fight(const target: MType; const aAscending: Boolean = True): Integer; overload;
function Race(const target: MType; const aAscending: Boolean = True): Integer; overload;
function Skirmish(const target: MType; const aAscending: Boolean = True): Integer; overload;
function Strife(const target: MType; const aAscending: Boolean = True): Integer; overload;
function Wrestle(const target: MType; const aAscending: Boolean = True): Integer; overload;

function Comp(const target: MType): Integer; overload;
function CompareEx(const target: MType; const tolerance: MType = 0): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Combat>
  @action: Computes a direction-aware three-way comparison between Self and a
           target value, using the sign of their mathematical difference.
  @note: Returns -1 if Self should sort before target, 1 if Self should sort
         after target, and 0 if equal, given the specified aAscending
         direction. Equivalent to Comp(target) under ascending order, and its
         negation under descending order. MType must be numeric (supports
         subtraction); use an ordered-only variant for non-numeric MType.
[==============================================================================}
function MTypeHelper.Combat(const target: MType; const aAscending: Boolean = True): Integer; overload;
begin
  Result := (aAscending.Select(1, -1) * Sign(Self - target));
end;

{==============================================================================]
  <Fight>
  @action: Computes a direction-aware three-way comparison between Self and a
           target value, using the sign of their mathematical difference.
  @note: Returns -1 if Self should sort before target, 1 if Self should sort
         after target, and 0 if equal, given the specified aAscending
         direction. Under descending order, the operands are swapped rather
         than the result negated, so Sign only ever evaluates a
         direction-correct delta. MType must be numeric (supports
         subtraction).
[==============================================================================}
function MTypeHelper.Fight(const target: MType; const aAscending: Boolean = True): Integer; overload;
begin
  if aAscending then
    Result := Sign(Self - target)
  else
    Result := Sign(target - Self);
end;

{==============================================================================]
  <Race>
  @action: Computes a direction-aware three-way comparison between Self and a
           target value, using boolean-ordinal differencing rather than
           subtraction of the values themselves.
  @note: Returns -1 if Self should sort before target, 1 if Self should sort
         after target, and 0 if equal, given the specified aAscending
         direction. Unlike Combat/Fight, does not subtract Self and target
         directly (avoids Sign and any subtraction-overflow or floating-point
         edge cases such as -0.0 or NaN); only < and > are used on the raw
         values, with direction applied via a scaling multiplier.
[==============================================================================}
function MTypeHelper.Race(const target: MType; const aAscending: Boolean = True): Integer; overload;
begin
  Result := (aAscending.Select(1, -1) * (Ord(Self > target) - Ord(Self < target)));
end;

{==============================================================================]
  <Skirmish>
  @action: Computes a direction-aware three-way comparison between Self and a
           target value, using the sign of their mathematical difference.
  @note: Returns -1 if Self should sort before target, 1 if Self should sort
         after target, and 0 if equal, given the specified aAscending
         direction. Mechanically equivalent to Combat, but derives the ±1
         direction multiplier from Ord(aAscending) arithmetic rather than a
         Select call. MType must be numeric (supports subtraction).
[==============================================================================}
function MTypeHelper.Skirmish(const target: MType; const aAscending: Boolean = True): Integer; overload;
begin
  Result := ((2 * Ord(aAscending) - 1) * Sign(Self - target));
end;

{==============================================================================]
  <Strife>
  @action: Computes a direction-aware three-way comparison between Self and a
           target value, delegating to Comp for the base comparison and
           negating the result under descending order.
  @note: Returns -1 if Self should sort before target, 1 if Self should sort
         after target, and 0 if equal, given the specified aAscending
         direction. Unlike Combat/Fight/Race/Wrestle/Skirmish, this does not
         reimplement the comparison — it composes on top of Comp, so any
         future change to Comp's behavior (e.g. how it handles edge cases
         like -0.0 or NaN) propagates here automatically. MType must satisfy
         whatever constraint Comp itself requires (currently numeric, since
         Comp uses Sign(Self - target)).
[==============================================================================}
function MTypeHelper.Strife(const target: MType; const aAscending: Boolean = True): Integer; overload;
begin
  Result := Self.Comp(target);
  if not aAscending then
    Result := -Result;
end;

{==============================================================================]
  <Wrestle>
  @action: Computes a direction-aware three-way comparison between Self and a
           target value, using the sign of their mathematical difference.
  @note: Returns -1 if Self should sort before target, 1 if Self should sort
         after target, and 0 if equal, given the specified aAscending
         direction. Unlike Combat (negates the final Sign result) and Fight
         (swaps operands), direction is applied by negating the delta itself
         before it reaches Sign. MType must be numeric (supports subtraction
         and unary negation).
[==============================================================================}
function MTypeHelper.Wrestle(const target: MType; const aAscending: Boolean = True): Integer; overload;
var
  d: MType;
begin
  d := (Self - target);
  if not aAscending then
    d := -d;
  Result := Sign(d);
end;

{==============================================================================]
  <Comp>
  @action: Computes a clean three-way comparison between Self and a target 
           value using the sign of their mathematical difference.
  @note: Returns -1 if Self is less than target, 1 if greater, and 0 if equal. 
         By passing the arithmetic delta directly to the Sign function, this 
         method achieves zero-branch evaluation without the overhead of 
         lookup tables or conditional wrappers.
[==============================================================================}
function MTypeHelper.Comp(const target: MType): Integer; overload;
begin
  Result := Sign(Self - target);
end;

{==============================================================================]
  <CompareEx>
  @action: Returns True if the helper’s value is less than or equal to
           the given target value. Useful as a comparison predicate when
           sorting or merging arrays in ascending order.
  @note: This method does not modify either value; it simply performs a <= comparison.
[==============================================================================}
function MTypeHelper.CompareEx(const target: MType; const tolerance: MType = 0): Integer; overload;
begin
  if (Abs(Self - target) <= tolerance) then
    Result := 0
  else if (Self < target) then
    Result := -1
  else
    Result := 1;
end;
{$ENDIF}
