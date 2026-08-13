{$IFDEF HELPERS}
function Clamp(const minimum, maximum: MType): MType; overload;
function ClampMax(const limit: MType): MType; overload;
function ClampMin(const limit: MType): MType; overload;
function Constraint(const minimum, maximum: MType): Boolean; overload;
function ConstraintMax(const limit: MType): Boolean; overload;
function ConstraintMin(const limit: MType): Boolean; overload;

function Cap(const sMinimum, sMaximum: MType): Boolean; overload;
function CapMax(const sMaximum: MType): Boolean; overload;
function CapMin(const sMinimum: MType): Boolean; overload;
function Capped(const sMinimum, sMaximum: MType): MType; overload;
function CappedMax(const sMaximum: MType): MType; overload;
function CappedMin(const sMinimum: MType): MType; overload;
function Confine(const sMinimum, sMaximum: MType): MType; overload;
function Confined(const sMinimum, sMaximum: MType): MType; overload;
function Extremate(const item: MType): Boolean; overload;
function Extremify(const item: MType): Boolean; overload;
function Guard(const gLow, gHigh, fallback: MType): MType; overload;
function Maxate(const item: MType): Boolean; overload;
function Maxify(const item: MType): Boolean; overload;
function Maximate(const target: MType): Boolean; overload;
function Minate(const item: MType): Boolean; overload;
function Minify(const item: MType): Boolean; overload;
function Minimate(const target: MType): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Clamp>
  @action: Restricts the current instance to the closed interval defined by [minimum, maximum].
  @note: Pure method. Returns minimum if Self < minimum, maximum if Self > maximum, otherwise returns Self.
[==============================================================================}
function MTypeHelper.Clamp(const minimum, maximum: MType): MType; overload;
begin
  if (Self < minimum) then
    Result := minimum
  else if (Self > maximum) then
    Result := maximum
  else
    Result := Self;
end;

{==============================================================================]
  <ClampMax>
  @action: Caps the current instance so it does not exceed the upper limit.
  @note: Pure method. Returns limit if Self > limit, otherwise returns Self.
[==============================================================================}
function MTypeHelper.ClampMax(const limit: MType): MType; overload;
begin
  if (Self > limit) then
    Result := limit
  else
    Result := Self;
end;

{==============================================================================]
  <ClampMin>
  @action: Floors the current instance so it does not fall below the lower limit.
  @note: Pure method. Returns limit if Self < limit, otherwise returns Self.
[==============================================================================}
function MTypeHelper.ClampMin(const limit: MType): MType; overload;
begin
  if (Self < limit) then
    Result := limit
  else
    Result := Self;
end;

{==============================================================================]
  <Constraint>
  @action: Constrains the current instance in-place to the [minimum, maximum] range.
  @note: Mutates Self if it falls outside the range and returns True if Self was modified.
[==============================================================================}
function MTypeHelper.Constraint(const minimum, maximum: MType): Boolean; overload;
begin
  Result := (Self.ConstraintMin(minimum) or Self.ConstraintMax(maximum));
end;

{==============================================================================]
  <ConstraintMax>
  @action: Constrains the current instance in-place to not exceed an upper limit.
  @note: Mutates Self to limit if Self > limit and returns True; otherwise leaves Self unchanged and returns False.
[==============================================================================}
function MTypeHelper.ConstraintMax(const limit: MType): Boolean; overload;
begin
  Result := (Self > limit);
  if Result then
    Self := limit;
end;

{==============================================================================]
  <ConstraintMin>
  @action: Constrains the current instance in-place to not fall below a lower limit.
  @note: Mutates Self to limit if Self < limit and returns True; otherwise leaves Self unchanged and returns False.
[==============================================================================}
function MTypeHelper.ConstraintMin(const limit: MType): Boolean; overload;
begin
  Result := (Self < limit);
  if Result then
    Self := limit;
end;

{==============================================================================]
  <Cap>
  @action: Constrains the instance item within a specified minimum and maximum range, modifying the value in-place.
  @note: Returns True if the value was altered to fit within the boundaries, or False if no changes were made.
[==============================================================================}
function MTypeHelper.Cap(const sMinimum, sMaximum: MType): Boolean; overload;
var
  s: MType;
begin
  s := Self;
  if (Self < sMinimum) then
    Self := sMinimum
  else if (Self > sMaximum) then
    Self := sMaximum;
  Result := (s <> Self);
end;

{==============================================================================]
  <CapMax>
  @action: Constrains the instance item within a specified maximum range, modifying the value in-place.
  @note: Returns True if the value was altered to fit within the boundaries, or False if no changes were made.
[==============================================================================}
function MTypeHelper.CapMax(const sMaximum: MType): Boolean; overload;
var
  s: MType;
begin
  s := Self;
  if (Self > sMaximum) then
    Self := sMaximum;
  Result := (s <> Self);
end;

{==============================================================================]
  <CapMin>
  @action: Constrains the instance item within a specified minimum range, modifying the value in-place.
  @note: Returns True if the value was altered to fit within the boundaries, or False if no changes were made.
[==============================================================================}
function MTypeHelper.CapMin(const sMinimum: MType): Boolean; overload;
var
  s: MType;
begin
  s := Self;
  if (Self < sMinimum) then
    Self := sMinimum;
  Result := (s <> Self);
end;

{==============================================================================]
  <Capped>
  @action: Returns a copy of the item constrained within a specified minimum and maximum range.
  @note: Returns the minimum boundary if Self is lower, or the maximum if Self is higher.
[==============================================================================}
function MTypeHelper.Capped(const sMinimum, sMaximum: MType): MType; overload;
begin
  if (Self < sMinimum) then
    Exit(sMinimum);
  if (Self > sMaximum) then
    Exit(sMaximum);
  Result := Self;
end;

{==============================================================================]
  <CappedMax>
  @action: Returns a copy of the item constrained within a specified maximum range.
  @note: Returns the minimum boundary if Self is lower, or the maximum if Self is higher.
[==============================================================================}
function MTypeHelper.CappedMax(const sMaximum: MType): MType; overload;
begin
  if (Self > sMaximum) then
    Exit(sMaximum);
  Result := Self;
end;

{==============================================================================]
  <CappedMin>
  @action: Returns a copy of the item constrained within a specified minimum range.
  @note: Returns the minimum boundary if Self is lower, or the maximum if Self is higher.
[==============================================================================}
function MTypeHelper.CappedMin(const sMinimum: MType): MType; overload;
begin
  if (Self < sMinimum) then
    Exit(sMinimum);
  Result := Self;
end;

{==============================================================================]
  <Confine>
  @action: Clamps the current instance value between a minimum and maximum threshold, 
           modifying the instance in-place and returning the updated value.
  @note: This is a mutating operation. If the current value is outside the bounds, 
         'Self' is permanently updated to the breached boundary.
[==============================================================================}
function MTypeHelper.Confine(const sMinimum, sMaximum: MType): MType; overload;
begin
  if (Self < sMinimum) then
    Self := sMinimum
  else if (Self > sMaximum) then
    Self := sMaximum;
  Result := Self;
end;

{==============================================================================]
  <Confined>
  @action: Returns the current value restricted within the specified minimum and 
           maximum limits without altering the original instance.
  @note: This is a non-mutating, read-only operation. 'Self' remains unchanged, 
         making it safe for functional-style chaining or passing to expressions.
[==============================================================================}
function MTypeHelper.Confined(const sMinimum, sMaximum: MType): MType; overload;
begin
  if (Self < sMinimum) then
    Result := sMinimum
  else if (Self > sMaximum) then
    Result := sMaximum
  else
    Result := Self;
end;

{==============================================================================]
  <Extremate>
  @action: Conditionally replaces Self with item if item differs from Self in either direction.
  @note: Returns True if item is either lower or higher than Self (i.e. not equal),
         in which case Self is updated to item via Minate or Maxate.
		 Otherwise Self is left unchanged and False is returned.
[==============================================================================}
function MTypeHelper.Extremate(const item: MType): Boolean; overload;
begin
  Result := (Self.Minate(item) or Self.Maxate(item));
end;

{==============================================================================]
  <Extremify>
  @action: Expands this instance's range boundaries to include the passed item.
  @note: Conditionally updates Self to the new absolute minimum or maximum 
         boundary, returning True if either boundary changed.
[==============================================================================}
function MTypeHelper.Extremify(const item: MType): Boolean; overload;
begin
  Result := (Self.Minify(item) or Self.Maxify(item));
end;

{==============================================================================]
  <Guard>
  @action: Returns Self if it falls within the inclusive range of [Min..Max]; 
           otherwise, returns the specified fallback value.
  @note: High-speed O(1) range-validation pipeline. Acts as an assertive 
         boundary filter, ensuring data integrity by instantly discarding 
         out-of-bounds values in favor of a safe alternative.
[==============================================================================}
function MTypeHelper.Guard(const gLow, gHigh, fallback: MType): MType; overload;
begin
  if ((Self >= gLow) and (Self <= gHigh)) then
    Result := Self
  else
    Result := fallback;
end;

{==============================================================================]
  <Maxate>
  @action: Conditionally replaces Self with item if item is higher.
  @note: Returns True if item > Self, in which case Self is updated to item.
         Otherwise Self is left unchanged and False is returned.
[==============================================================================}
function MTypeHelper.Maxate(const item: MType): Boolean; overload;
begin
  Result := (item > Self);
  if Result then
    Self := item;
end;

{==============================================================================]
  <Maxify>
  @action: Restricts this instance to a minimum lower bound.
  @note: If the passed item is larger than the current value, 
         updates Self to the item and returns True (indicating a change).
[==============================================================================}
function MTypeHelper.Maxify(const item: MType): Boolean; overload;
var
  s: MType;
begin
  s := Self;
  if (item > Self) then
    Self := item;
  Result := (Self <> s);
end;

{==============================================================================]
  <Maximate>
  @action: Raises Self to `target` if `target` is greater; returns True if changed.
  @note: Mutating. Equivalent to `Self := Max(Self, target)`, reporting whether an update occurred.
[==============================================================================}
function MTypeHelper.Maximate(const target: MType): Boolean; overload;
var
  s: MType;
begin
  s := Self;
  Self := Max(Self, target);
  Result := (Self <> s);
end;

{==============================================================================]
  <Minate>
  @action: Conditionally replaces Self with item if item is lower.
  @note: Returns True if item < Self, in which case Self is updated to item.
         Otherwise Self is left unchanged and False is returned.
[==============================================================================}
function MTypeHelper.Minate(const item: MType): Boolean; overload;
begin
  Result := (item < Self);
  if Result then
    Self := item;
end;

{==============================================================================]
  <Minify>
  @action: Restricts this instance to a maximum upper bound.
  @note: If the passed item is smaller than the current value, 
         updates Self to the item and returns True (indicating a change).
[==============================================================================}
function MTypeHelper.Minify(const item: MType): Boolean; overload;
var
  s: MType;
begin
  s := Self;
  if (item < Self) then
    Self := item;
  Result := (Self <> s);
end;

{==============================================================================]
  <Minimate>
  @action: Lowers Self to `target` if `target` is smaller; returns True if changed.
  @note: Mutating. Equivalent to `Self := Min(Self, target)`, reporting whether an update occurred.
[==============================================================================}
function MTypeHelper.Minimate(const target: MType): Boolean; overload;
var
  s: MType;
begin
  s := Self;
  Self := Min(Self, target);
  Result := (Self <> s);
end;
{$ENDIF}
