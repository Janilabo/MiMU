{$IFDEF HELPERS}
function Degrees: Double;
function FixDegrees: Double;
function FixRadians: Double;
function Radians(const compass: Boolean = False): Double;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Degrees>
  @action: Converts Radians to Degrees.
  @note: None
[==============================================================================} 
function TDoubleHelper.Degrees: Double;
var
  r: Double;
begin
  r := (Self * (180.0 / Pi));
  Result := r.FixDegrees;
end;

{==============================================================================]
  <FixDegrees>
  @action: 365 => 5 | 722 => 2 | 359.9 => 359.9 | 360 => 0
  @note: None
[==============================================================================}
function TDoubleHelper.FixDegrees: Double;
var
  t: Integer;
begin
  t := -1;
  if (Self > -1) then
    t := Abs(t);
  Result := Abs(Self);
  Result := ((Floor(Result) mod 360 + Frac(Result)) * t);
  if (Result < 0) then
    Result := (Result + 360.0);
end;

{==============================================================================]
  <FixRadians>
  @action: 365 => 5 | 722 => 2 | 359.9 => 359.9 | 360 => 0
  @note: None
[==============================================================================}
function TDoubleHelper.FixRadians: Double;
var
  r: Double;
begin
  r := (Self * (180.0 / Pi));
  Result := (r.FixDegrees * (Pi / 180.0));
end;

{==============================================================================]
  <Radians>
  @action: Converts Degrees or Compass (degrees) to Radians.
  @note: Supports compass.
[==============================================================================}
function TDoubleHelper.Radians(const compass: Boolean = False): Double;
var
  d: Double;
begin
  if not compass then
    d := (Self * (Pi / 180.0))
  else
    d := ((Self - 90.0) * (Pi / 180.0));
  Result := d.FixRadians;
end;
{$ENDIF}