{$IFDEF HELPERS}
function CloserThan(const target, than: Integer): Boolean; overload;
function CloserTo(const target, than: Integer): Boolean; overload;
function FartherFrom(const target, than: Integer): Boolean; overload;
function FartherThan(const target, than: Integer): Boolean; overload;
function Noncloser(const target, than: Integer): Boolean; overload;
function Nonfarther(const target, than: Integer): Boolean; overload;
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
function TIntegerHelper.CloserThan(const target, than: Integer): Boolean; overload;
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
function TIntegerHelper.CloserTo(const target, than: Integer): Boolean; overload;
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
function TIntegerHelper.FartherFrom(const target, than: Integer): Boolean; overload;
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
function TIntegerHelper.FartherThan(const target, than: Integer): Boolean; overload;
begin
  Result := (Sign(Abs(Self - target) - Abs(Self - than)) = 1);
end;

{==============================================================================]
  <Noncloser>
  @action: Determines whether the numerical distance from Self to target is
           greater than or equal to the distance from Self to than.
  @note: Evaluates relative remoteness. Returns True if target is at least as far
         away from Self as than is (or farther). This complements Nonfarther by
         inverting the sign evaluation of the absolute distance delta.
[==============================================================================}
function TIntegerHelper.Noncloser(const target, than: Integer): Boolean; overload;
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
function TIntegerHelper.Nonfarther(const target, than: Integer): Boolean; overload;
begin
  Result := (Sign(Abs(Self - target) - Abs(Self - than)) <= 0);
end;
{$ENDIF}