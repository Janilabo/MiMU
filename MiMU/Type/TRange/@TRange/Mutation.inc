{$IFDEF METHODS}
function Eat(const val: Integer): Boolean; overload;
function Feed(const val: Integer): Boolean; overload;
function Grow(const val: Integer): Boolean; overload;
function Grown(const val: Integer): TRange; overload;
function Restart(const vStart: Integer = 0): Boolean; overload;
function Restarted(const vStart: Integer = 0): TRange; overload;
function Restop(const vStop: Integer = 0): Boolean; overload;
function Restopped(const vStop: Integer = 0): TRange; overload;
function Shrink(const val: Integer): Boolean; overload;
function Shrunk(const val: Integer): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Eat>
  @action: Shrinks the range from the boundary closest to the specified value, provided the value lies within the range bounds.
  @note: Returns True if the range was successfully trimmed, or False if the range is empty (start equals stop) or if the value is outside the current range.
[==============================================================================}
function TRange.Eat(const val: Integer): Boolean; overload;
begin
  if (Self.start = Self.stop) then
    Exit(False);
  case (Self.start < Self.stop) of
    True:
    if ((val < Self.start) or (val > Self.stop)) then
      Exit(False)
    else if (val.Distance(Self.start) < val.Distance(Self.stop)) then
      Self.start := (val + 1)
    else
      Self.stop := (val - 1);
    False:
    if ((val < Self.stop) or (val > Self.start)) then
      Exit(False)
    else if (val.Distance(Self.start) < val.Distance(Self.stop)) then
      Self.start := (val - 1)
    else
      Self.stop := (val + 1);
  end;
  Result := True;
end;

{==============================================================================]
  <Feed>
  @action: Expands the range to include the specified value if it falls outside the current bounds.
  @note: Returns True if the range was modified, or False if the value is already within the range. Supports both ascending and descending ranges.
[==============================================================================}
function TRange.Feed(const val: Integer): Boolean; overload;
begin
  Result := (Self.start <= Self.stop);
  if ((Result and (val < Self.start)) or ((not Result) and (val > Self.start))) then
    Self.start := val
  else if ((Result and (val > Self.stop)) or ((not Result) and (val < Self.stop))) then
    Self.stop := val
  else
    Exit(False);
  Result := True;
end;

{==============================================================================]
  <Grow>
  @action: Expands the range boundaries to encompass an external target value.
  @note: 
    - Adjusts either the start or stop boundary depending on the trajectory (ascending vs. descending).
    - If the value is already contained within the range, no mutation occurs and returns False.
[==============================================================================}
function TRange.Grow(const val: Integer): Boolean; overload;
begin
  case Self.Descending of
    False:
    if (val < Self.start) then
      Self.start := val
    else if (val > Self.stop) then
      Self.stop := val
    else
      Exit(False);
    True:
    if (val < Self.stop) then
      Self.stop := val
    else if (val > Self.start) then
      Self.start := val
    else
      Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <Grown>
  @action: Returns a new range expanded to include an external value, preserving the original direction.
  @note: 
    - Pure function: Evaluates bounds using Self but leaves the caller instance unmodified.
    - Yields a newly constructed TRange if the value lies outside the existing boundaries.
    - Returns a direct copy of Self if the value is already safely enclosed.
[==============================================================================}
function TRange.Grown(const val: Integer): TRange; overload;
begin
  case Self.Descending of
    False:
    if (val < Self.start) then
      Exit(TRange.Construct(val, Self.stop))
    else if (val > Self.stop) then
      Exit(TRange.Construct(Self.start, val));
    True:
    if (val < Self.stop) then
      Exit(TRange.Construct(Self.start, val))
    else if (val > Self.start) then
      Exit(TRange.Construct(val, Self.stop));
  end;
  Result := Self;
end;

{==============================================================================]
  <Restart>
  @action: Replaces the range's start boundary in place, keeping stop unchanged.
  @note: Returns True if the start value actually changed. Returns False if
         vStart equals the current start (no mutation performed).
[==============================================================================}
function TRange.Restart(const vStart: Integer = 0): Boolean; overload;
begin
  Result := (Self.start <> vStart);
  Self.start := vStart;
end;

{==============================================================================]
  <Restarted>
  @action: Returns a new range with the start boundary replaced, stop unchanged.
  @note: Does not mutate Self. Mutating counterpart: Restart.
[==============================================================================}
function TRange.Restarted(const vStart: Integer = 0): TRange; overload;
begin
  Result.start := vStart;
  Result.stop := Self.stop;
end;

{==============================================================================]
  <Restop>
  @action: Replaces the range's stop boundary in place, keeping start unchanged.
  @note: Returns True if the stop value actually changed. Returns False if
         vStop equals the current stop (no mutation performed).
[==============================================================================}
function TRange.Restop(const vStop: Integer = 0): Boolean; overload;
begin
  Result := (Self.stop <> vStop);
  Self.stop := vStop;
end;

{==============================================================================]
  <Restopped>
  @action: Returns a new range with the stop boundary replaced, start unchanged.
  @note: Does not mutate Self. Mutating counterpart: Restopped.
[==============================================================================}
function TRange.Restopped(const vStop: Integer = 0): TRange; overload;
begin
  Result.start := Self.start;
  Result.stop := vStop;
end;

{==============================================================================]
  <Shrink>
  @action: Compresses the range inward by snapping the nearest boundary to a target value.
  @note: 
    - Requires the range to be plural (Size > 1) and contain the target value.
    - If the value matches an exact boundary, the opposite boundary snaps to it.
    - Otherwise, it dynamically updates whichever boundary (start or stop) is closer to val.
[==============================================================================}
function TRange.Shrink(const val: Integer): Boolean; overload;
begin
  Result := (Self.Plural and Self.Contains(val));
  if not Result then
    Exit;
  if (val = Self.start) then
    Self.stop := val
  else if (val = Self.stop) then
    Self.start := val
  else if (val.Distance(Self.start) < val.Distance(Self.stop)) then
    Self.start := val
  else
    Self.stop := val;
end;

{==============================================================================]
  <Shrunk>
  @action: Returns a new range collapsed inward by snapping the closest boundary to an internal value.
  @note: 
    - Pure function: Employs distance constraints to build an isolated, smaller range variant.
    - Automatically snaps to a single-point range (val, val) if the value matches an edge boundary.
    - Safely returns Self if the range is singular or does not contain the specified target.
[==============================================================================}
function TRange.Shrunk(const val: Integer): TRange; overload;
begin
  if not (Self.Plural and Self.Contains(val)) then
    Exit(Self);
  if Self.Employs(val) then
    Result.Create(val, val)
  else if (val.Distance(Self.start) < val.Distance(Self.stop)) then
    Result.Create(val, Self.stop)
  else
    Result.Create(Self.start, val);
end;
{$ENDIF}
