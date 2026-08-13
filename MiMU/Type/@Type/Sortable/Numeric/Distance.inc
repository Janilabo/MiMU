{$IFDEF HELPERS}
function Difference(const target: MType): MType; overload;
function Dist2(const target: MType): MType; overload;
function Distance(const target: MType): MType; overload;
function Distantia(const target: MType): MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Difference>
  @action: Calculates the directed scalar change required to transition from the current instance to the target.
  @note: Returns (target - Self). The result is positive when target > Self, negative when target < Self, and zero when equal.
[==============================================================================}
function MTypeHelper.Difference(const target: MType): MType; overload;
begin
  Result := (target - Self);
end;

{==============================================================================]
  <Distance>
  @action: Calculates the absolute scalar magnitude between the current instance and the target.
  @note: Returns Abs(target - Self). The result is non-directional and always non-negative.
[==============================================================================}
function MTypeHelper.Distance(const target: MType): MType; overload;
begin
  Result := Abs(target - Self);
end;

{==============================================================================]
  <Dist2>
  @action: Calculates the absolute distance between Self and another value by subtracting the smaller value from the larger value.
  @note: Uses a branch-based comparison method (Max/Min) to guarantee a non-negative result without relying on the Abs() function.
[==============================================================================}
function MTypeHelper.Dist2(const target: MType): MType; overload;
begin
  Result := (Max(Self, target) - Min(Self, target));
end;

{==============================================================================]
  <Distantia>
  @action: Calculates the absolute distance between Self and another value using conditional branching.
  @note: Uses a manual greater-than check to subtract the smaller value from the larger value, avoiding external function calls.
[==============================================================================}
function MTypeHelper.Distantia(const target: MType): MType; overload;
begin
  if (Self > target) then
    Result := (Self - target)
  else
    Result := (target - Self);
end;
{$ENDIF}