{$IFDEF HELPERS}
function Limit(const minimum, maximum: MType): MType; overload;
function LimitMax(const limit: MType): MType; overload;
function LimitMin(const limit: MType): MType; overload;

function Limitite(const minimum, maximum: MType): MType; overload;
function Maximite(const target: MType): MType; overload;
function Minimite(const target: MType): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Limit>
  @action: Clamps Self into the inclusive range [minimum, maximum].
  @note: Returns minimum if Self < minimum, maximum if Self > maximum, otherwise Self unchanged. Non-mutating.
[==============================================================================}
function MTypeHelper.Limit(const minimum, maximum: MType): MType; overload;
begin
  Result := EnsureRange(Self, minimum, maximum);
end;

{==============================================================================]
  <LimitMax>
  @action: Caps Self at limit, leaving it unchanged if already below.
  @note: Returns the lesser of Self and limit — a one-sided (upper-bound-only) clamp. Non-mutating.
[==============================================================================}
function MTypeHelper.LimitMax(const limit: MType): MType; overload;
begin
  Result := Min(Self, limit);
end;

{==============================================================================]
  <LimitMin>
  @action: Floors Self at limit, leaving it unchanged if already above.
  @note: Returns the greater of Self and limit — a one-sided (lower-bound-only) clamp. Non-mutating.
[==============================================================================}
function MTypeHelper.LimitMin(const limit: MType): MType; overload;
begin
  Result := Max(Self, limit);
end;

{==============================================================================]
  <Limitite>
  @action: Clamps Self into [minimum, maximum] if outside that range; returns the magnitude of the adjustment, or 0 if unchanged.
  @note: Mutating. Reports the surplus (if raised) or deficit (if lowered) applied. Contrast with `Limitate` (Boolean, reports only whether a change occurred).
[==============================================================================}
function MTypeHelper.Limitite(const minimum, maximum: MType): MType; overload;
begin
  if (Self < minimum) then
  begin
    Result := (minimum - Self);
    Self := minimum;
    Exit;
  end;
  if (Self > maximum) then
  begin
    Result := (Self - maximum);
    Self := maximum;
    Exit;
  end;
  Result := 0;
end;

{==============================================================================]
  <Maximite>
  @action: Raises Self to `target` if `target` exceeds Self; returns the magnitude of the increase, or 0 if unchanged.
  @note: Mutating. Reports the surplus applied. Contrast with `Maximate` (Boolean, reports only whether a change occurred).
[==============================================================================}
function MTypeHelper.Maximite(const target: MType): MType; overload;
begin
  if (target <= Self) then
    Exit(0);
  Result := (target - Self);
  Self := (Self + Result);
end;

{==============================================================================]
  <Minimite>
  @action: Lowers Self to `target` if `target` is smaller than Self; returns the magnitude of the decrease, or 0 if unchanged.
  @note: Mutating. Reports the deficit applied. Contrast with `Minimate` (Boolean, reports only whether a change occurred).
[==============================================================================}
function MTypeHelper.Minimite(const target: MType): MType; overload;
begin
  if (target >= Self) then
    Exit(0);
  Result := (Self - target);
  Self := (Self - Result);
end;
{$ENDIF}