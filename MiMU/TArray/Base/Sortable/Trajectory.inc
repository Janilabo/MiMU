{$IFDEF HELPERS}
function Trajectored: Integer; overload;
function Trajectoring: Integer; overload;
function Trajectory: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Trajectored>
  @action: Classifies the complete movement profile of the array in a single pass.
  @return:  1 = Upward Trajectory (Monotonically increasing / rising)
           -1 = Downward Trajectory (Monotonically decreasing / falling)
            0 = Flat / Static (All elements are equal, empty, or single element)
            2 = Mixed / Fluctuating (Data changes direction at least once)
  @note: Highly optimized state-machine approach using `Result` as the state holder.
         Short-circuits immediately with `Exit(2)` on the very first directional flip.
[==============================================================================}
function MArrayHelper.Trajectored: Integer; overload;
var
  i: Integer;
begin
  Result := 0;
  if (Self.Length < 2) then
    Exit(0);
  for i := 1 to High(Self) do
  case (Self[i] > Self[i - 1]) of
    True:
    if (Result = 0) then
      Result := 1
    else if (Result = -1) then
      Exit(2);
    False:
    if (Self[i] < Self[i - 1]) then
      if (Result = 0) then
        Result := -1
      else if (Result = 1) then
        Exit(2);
  end;
end;

{==============================================================================]
  <Trajectoring>
  @action: Classifies the data sequence profile by filtering out stationary states.
  @return:  1 = Monotonically increasing trend (Upward).
           -1 = Monotonically decreasing trend (Downward).
            0 = Stationary trend (Flat line, empty, or single element).
            2 = Erratic / Fluctuating trend (Mixed direction).
  @note: Delegates flatline detection to `Stationary` as an early exit strategy.
         Utilizes separate tracking loops that fall through to a default mixed state.
[==============================================================================}
function MArrayHelper.Trajectoring: Integer; overload;
var
  h, i: Integer;
  e: Boolean;
begin
  if Self.Stationary then
    Exit(0);
  h := High(Self);
  for i := 1 to h do
    if (Self[i] < Self[i - 1]) then
      Break
    else if (i = h) then
      Exit(1);
  for i := 1 to h do
    if (Self[i] > Self[i - 1]) then
      Break
    else if (i = h) then
      Exit(-1);
  Result := 2;
end;

{==============================================================================]
  <Trajectory>
  @action: Classifies the complete structural behavior of the array's movement.
  @return:  1 = Monotonically Increasing (Upward trend)
           -1 = Monotonically Decreasing (Downward trend)
            0 = Flat, Empty, or Single Element
            2 = Mixed / Fluctuating (Changes direction multiple times)
[==============================================================================}
function MArrayHelper.Trajectory: Integer; overload;
var
  h, i: Integer;
  u, d: Boolean;
begin
  h := High(Self);
  if (h < 1) then
    Exit(0);
  u := False;
  d := False;
  for i := 1 to h do
  begin
    if (Self[i] > Self[i - 1]) then
      u := True
    else if (Self[i] < Self[i - 1]) then
      d := True;
    if (u and d) then
      Exit(2);
  end;
  if u then
    Exit(1);
  if d then
    Exit(-1);
  Result := 0;
end;
{$ENDIF}
