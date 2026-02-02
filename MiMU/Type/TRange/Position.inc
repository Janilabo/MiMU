{$IFDEF METHODS}
function Interpolate(const F: Double): Double; overload;
function Percentile(const F: Double): Double; overload;
function Q1: Double; overload;
function Q2: Double; overload;
function Q3: Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Interpolate>
  @action: Computes the value at a relative fraction along the range,
           preserving the direction from start to stop.
  @note: F = 0 returns Start, F = 1 returns Stop.
         Works with ascending and descending ranges.
         Useful for linear interpolation, animation, or parameterization.
[==============================================================================}
function TRange.Interpolate(const F: Double): Double; overload;
begin
  Result := (Self.start + ((Self.stop - Self.start) * F));
end;

{==============================================================================]
  <Percentile>
  @action: Computes the value at a given fractional position within the range,
           ignoring direction. The range is treated as ordered from min to max.
  @note: F = 0 returns the smaller of Start/Stop, F = 1 returns the larger.
         Useful for statistical calculations such as percentiles and quartiles.
[==============================================================================}
function TRange.Percentile(const F: Double): Double; overload;
var
  A, B: Double;
begin
  A := Min(Self.start, Self.stop);
  B := Max(Self.start, Self.stop);
  Result := (A + ((B - A) * F));
end;

{==============================================================================]
  <Q1>
  @action: Returns the first quartile (25th percentile) of the range.
  @note: Uses Percentile(0.25). Direction of the range is ignored.
         Represents the value one quarter of the way from the minimum to the maximum.
[==============================================================================}
function TRange.Q1: Double; overload;
begin
  Result := Self.Percentile(0.25);
end;

{==============================================================================]
  <Q2>
  @action: Returns the second quartile (50th percentile / median) of the range.
  @note: Uses Percentile(0.5). Equivalent to the midpoint when the range is symmetric.
         Direction of the range is ignored.
[==============================================================================}
function TRange.Q2: Double; overload;
begin
  Result := Self.Percentile(0.5);
end;

{==============================================================================]
  <Q3>
  @action: Returns the third quartile (75th percentile) of the range.
  @note: Uses Percentile(0.75). Direction of the range is ignored.
         Represents the value three quarters of the way from the minimum to the maximum.
[==============================================================================}
function TRange.Q3: Double; overload;
begin
  Result := Self.Percentile(0.75);
end;
{$ENDIF}