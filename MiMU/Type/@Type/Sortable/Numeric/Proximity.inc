{$IFDEF HELPERS}
function CloserThan(const target, than: MType): Boolean; overload;
function CloserTo(const target, than: MType): Boolean; overload;
function FartherFrom(const target, than: MType): Boolean; overload;
function FartherThan(const target, than: MType): Boolean; overload;
function Furthen(const A, B: MType): Boolean; overload;
function Further(const A, B: MType): Boolean; overload;
function Furthest(const A, B: MType): MType; overload;
function Nearen(const A, B: MType): Boolean; overload;
function Nearer(const A, B: MType): Boolean; overload;
function Nearest(const A, B: MType): MType; overload;
function Noncloser(const target, than: MType): Boolean; overload;
function Nonfarther(const target, than: MType): Boolean; overload;
function Reachable(const target: MType; const radius: MType = 1): Boolean; overload;
function Within(const target: MType; const radius: MType = 1): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <CloserThan>
  @action: Determines whether the numerical distance from Self to target is
           less than or equal to the distance from Self to than.
  @note: Evaluates relative proximity. Returns True if target is at least as close
         to Self as than is (or closer). By evaluating the mathematical sign of
         the distance differential, it creates a clean, relational proximity
         check without nested logical branching.
[==============================================================================}
function MTypeHelper.CloserThan(const target, than: MType): Boolean; overload;
begin
  Result := (Sign(Abs(Self - target) - Abs(Self - than)) = -1);
end;

{==============================================================================]
  <CloserTo>
  @action: Returns True if the absolute distance from Self to target is
           strictly less than the absolute distance from Self to than.
           (i.e., target is nearer to Self than than is)
  @note: Returns False if distances are equal or if target is farther.
         Equivalent to |Self - target| < |Self - than|
[==============================================================================}
function MTypeHelper.CloserTo(const target, than: MType): Boolean; overload;
begin
  Result := (Abs(Self - target) < Abs(Self - than));
end;


{==============================================================================]
  <FartherFrom>
  @action: Returns True if the absolute distance from Self to target is
           strictly greater than the absolute distance from Self to than.
           (i.e., target is more distant from Self than than is)
  @note: Returns False if distances are equal or if target is closer.
         Equivalent to |Self - target| > |Self - than|
[==============================================================================}
function MTypeHelper.FartherFrom(const target, than: MType): Boolean; overload;
begin
  Result := (Abs(Self - target) > Abs(Self - than));
end;

{==============================================================================]
  <FartherThan>
  @action: Determines whether the numerical distance from Self to target is
           greater than or equal to the distance from Self to than.
  @note: Evaluates relative remoteness. Returns True if target is at least as far
         away from Self as than is (or farther). This complements Nonfarther by
         inverting the sign evaluation of the absolute distance delta.
[==============================================================================}
function MTypeHelper.FartherThan(const target, than: MType): Boolean; overload;
begin
  Result := (Sign(Abs(Self - target) - Abs(Self - than)) = 1);
end;

{==============================================================================]
  <Furthen>
  @action: Sets Self to whichever of `A` or `B` is farther from Self. Ties resolve to `A`. Returns True if Self changed.
  @note: Mutating. Companion to `Furthest` — applies the result rather than merely reporting it.
[==============================================================================}
function MTypeHelper.Furthen(const A, B: MType): Boolean; overload;
var
  s: MType;
begin
  s := Self;
  Self := Self.Furthest(A, B);
  Result := (Self <> s);
end;

{==============================================================================]
  <Further>
  @action: Returns True if `A` is farther from Self than `B` is. Ties return False.
  @note: Non-mutating. Predicate form of the Proximity family — mirrors `Nearer`.
[==============================================================================}
function MTypeHelper.Further(const A, B: MType): Boolean; overload;
begin
  Result := (Self.Distance(A) > Self.Distance(B));
end;

{==============================================================================]
  <Furthest>
  @action: Returns whichever of `A` or `B` is farther from Self. Ties resolve to `A`.
  @note: Non-mutating. Pure comparison by absolute distance; mirrors `Nearest`.
[==============================================================================}
function MTypeHelper.Furthest(const A, B: MType): MType; overload;
begin
  if (Self.Distance(A) >= Self.Distance(B)) then
    Result := A
  else
    Result := B;
end;

{==============================================================================]
  <Nearen>
  @action: Sets Self to whichever of `A` or `B` is closer to Self. Ties resolve to `A`. Returns True if Self changed.
  @note: Mutating. Companion to `Nearest` — applies the result rather than merely reporting it.
[==============================================================================}
function MTypeHelper.Nearen(const A, B: MType): Boolean; overload;
var
  s: MType;
begin
  s := Self;
  Self := Self.Nearest(A, B);
  Result := (Self <> s);
end;

{==============================================================================]
  <Nearer>
  @action: Returns True if `A` is closer to Self than `B` is. Ties return False.
  @note: Non-mutating. Predicate form of the Proximity family — answers "is A closer?" rather than "which is closer?" (see `Nearest`).
[==============================================================================}
function MTypeHelper.Nearer(const A, B: MType): Boolean; overload;
begin
  Result := (Self.Distance(A) < Self.Distance(B));
end;

{==============================================================================]
  <Nearest>
  @action: Returns whichever of `A` or `B` is closer to Self. Ties resolve to `A`.
  @note: Non-mutating. Pure comparison by absolute distance; does not alter Self.
[==============================================================================}
function MTypeHelper.Nearest(const A, B: MType): MType; overload;
begin
  if (Self.Distance(A) <= Self.Distance(B)) then
    Result := A
  else
    Result := B;
end;

{==============================================================================]
  <Noncloser>
  @action: Determines whether the numerical distance from Self to target is
           greater than or equal to the distance from Self to than.
  @note: Evaluates relative remoteness. Returns True if target is at least as far
         away from Self as than is (or farther). This complements Nonfarther by
         inverting the sign evaluation of the absolute distance delta.
[==============================================================================}
function MTypeHelper.Noncloser(const target, than: MType): Boolean; overload;
begin
  Result := (Sign(Abs(Self - target) - Abs(Self - than)) >= 0);
end;

{==============================================================================]
  <Nonfarther>
  @action: than or equal to the distance from Self to than.
  @note: Evaluates relative proximity. Returns True if target is at least as close
         to Self as than is (or closer). By evaluating the mathematical sign of
         the distance differential, it creates a clean, relational proximity
         check without nested logical branching.
[==============================================================================}
function MTypeHelper.Nonfarther(const target, than: MType): Boolean; overload;
begin
  Result := (Sign(Abs(Self - target) - Abs(Self - than)) <= 0);
end;

{==============================================================================]
  <Reachable>
  @action: Determines whether the current value falls within a maximum
           allowable radius (tolerance window) centered around a target value.
  @note: Evaluates True if Self is trapped between (target - radius) and 
         (target + radius). If radius is 0, it skips the bounds calculation 
         and performs a strict equality check (Self = target).
[==============================================================================}
function MTypeHelper.Reachable(const target: MType; const radius: MType = 1): Boolean; overload;
var
  r: MType;
begin
  if (radius = 0) then
    Exit(Self = target); 
  r := radius;
  Result := ((Self >= (target - r)) and (Self <= (target + r)));
end;

{==============================================================================]
  <Approachable>
  @action: Determines whether the current value falls within an acceptable 
           radius (tolerance zone) centered around the target value.
  @note: Uses an absolute distance calculation. A radius of 0 requires 
         exact equality (Self = target).
[==============================================================================}
function MTypeHelper.Within(const target: MType; const radius: MType = 1): Boolean; overload;
begin
  Result := (Abs(Self - target) <= radius);
end;
{$ENDIF}
