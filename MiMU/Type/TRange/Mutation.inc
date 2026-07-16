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
  @action: Compresses the lower bounds of the range inward up to a specified threshold.
  @note: 
    - Moves the lower boundary (start for ascending, stop for descending) to match val.
    - Fails and returns False if val sits completely outside the internal bounds of the range.
[==============================================================================}
function TRange.Shrink(const val: Integer): Boolean; overload;
begin
  case Self.Descending of
    False:
    if ((val > Self.start) and (val <= Self.stop)) then
      Self.start := val
    else
      Exit(False);
    True:
    if ((val > Self.stop) and (val <= Self.start)) then
      Self.stop := val
    else
      Exit(False);
  end;
  Result := True;
end;
{$ENDIF}
