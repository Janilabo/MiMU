{$IFDEF METHODS}
function Grow(const val: Integer): Boolean; overload;
function Shrink(const val: Integer): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}
