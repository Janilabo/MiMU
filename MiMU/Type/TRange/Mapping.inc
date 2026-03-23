{$IFDEF METHODS}
function Closest(const val: Integer): Integer; overload;
function Distal(const val: Integer): Integer; overload;
function Farthest(const val: Integer): Integer; overload;
function Remap(const val: Integer; const target: TRange): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Closest>
  @action: Returns the value within the range that is closest to the specified value.
  @note:
    - If `val` lies within the range, it is returned unchanged.
    - If `val` is below the range, returns `Minimum`.
    - If `val` is above the range, returns `Maximum`.
    - Effectively clamps `val` to the inclusive range [Minimum, Maximum].
    - Works independently of the original ordering of the range.
[==============================================================================}
function TRange.Closest(const val: Integer): Integer; overload;
begin
  Result := Max(Self.Minimum, Min(Self.Maximum, val));
end;

{==============================================================================]
  <Distal>
  @action: Returns the endpoint of the range that is farthest from the specified value.
  @note:
    - Compares the distance from `val` to both `Minimum` and `Maximum`.
    - Returns the endpoint with the greater absolute distance.
    - If distances are equal, `Maximum` is returned.
    - Useful for selecting the extreme opposite bound relative to a value.
[==============================================================================}
function TRange.Distal(const val: Integer): Integer; overload;
var
  l, h: Integer;
begin
  l := Self.Minimum;
  h := Self.Maximum;
  Result := IfThen((Abs(val - l) > Abs(val - h)), l, h);
end;

{==============================================================================]
  <Farthest>
  @action: Returns the endpoint of the range that is farthest from the specified value.
  @note:
    - Compares `val` to the midpoint of the range.
    - If `val` is greater than the midpoint, returns `Minimum`.
    - If `val` is less than or equal to the midpoint, returns `Maximum`.
    - Equivalent to selecting the endpoint with the greatest distance from `val`.
    - If `val` is exactly at the midpoint, `Maximum` is returned.
    - Works for both ascending and descending ranges.
[==============================================================================}
function TRange.Farthest(const val: Integer): Integer; overload;
begin
  if (val > ((Self.start + Self.stop) / 2)) then
    Result := Self.Minimum
  else
    Result := Self.Maximum;
end;

{==============================================================================]
  <Remap>
  @action: Maps a value from the current range to a corresponding value in the
           target range using linear interpolation.
  @note:
    - Computes the relative position of `val` within the source range and applies
      it to the `target` range.
    - Equivalent to linear interpolation between `target.Minimum` and
      `target.Maximum`.
    - The result is rounded to the nearest Integer.
    - Works for both ascending and descending ranges.
[==============================================================================}
function TRange.Remap(const val: Integer; const target: TRange): Integer; overload;
var
  p: Double;
begin
  Result := Self.Minimum;
  p := ((val - Result) / (Self.Maximum - Result));
  Result := target.Minimum;
  Result := Round(Result + (p * (target.Maximum - Result)));
end;
{$ENDIF}
