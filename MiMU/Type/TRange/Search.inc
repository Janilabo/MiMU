{$IFDEF METHODS}
function Identify(const val: Integer): Integer; overload;
function IndexBy(const val: Integer): Integer; overload;
function IndexFor(const val: Integer): Integer; overload;
function IndexFrom(const val: Integer): Integer; overload;
function IndexOf(const val: Integer): Integer; overload;
function Indexy(const val: Integer): Integer; overload;
function Proj(const val: Integer): Integer; overload;
function Project(const val: Integer): Integer; overload;
function Projecta(const val: Integer): Integer; overload;
function Projected(const val: Integer): Integer; overload;
function Projectify(const val: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Identify>
  @action: Searches for a specific value within the TRange and returns its 
           zero-based relative index, or -1 if the value is not found.
  @note: Performs a safe linear simulation of the range iteration. By tracking 
         a directional step value (d) against an offset baseline (s), the loop 
         counter (Result) naturally locks onto the exact index matching the 
         target value without requiring an absolute difference calculation.
[==============================================================================}
function TRange.Identify(const val: Integer): Integer; overload;
var
  s, d: Integer;
begin
  if not Self.Contains(val) then
    Exit(-1);
  d := IfThen(Self.Asceal, 1, -1);
  s := (Self.start - d);
  for Result := 0 to (Self.Size - 1) do
    if (s.Increment(d) = val) then
      Exit;
end;

{==============================================================================]
  <IndexBy>
  @action: Returns the zero-based relative index of a specific value within
           the TRange by calculating its offset from the structural minimum boundary.
  @note:   Flattens directionality by resolving the true mathematical floor
           of the range using an inline conditional. For descending ranges,
           it mirrors the offset relative to the maximum size.
[==============================================================================}
function TRange.IndexBy(const val: Integer): Integer; overload;
begin
  if not Self.Contains(val) then
    Exit(-1);
  Result := Self.Projecta(val);
end;

{==============================================================================]
  <IndexFor>
  @action: Returns the zero-based relative index of a specific value within 
           the TRange, or -1 if the value is out of bounds.
  @note: Validates containment using Self.Contains before calculating the
         absolute distance from the range's starting boundary. This ensures 
         a reliable, zero-indexed offset map for both ascending and descending 
         coordinate spaces.
[==============================================================================}
function TRange.IndexFor(const val: Integer): Integer; overload;
begin
  if not Self.Contains(val) then
    Exit(-1);
  Result := Self.Proj(val);
end;

{==============================================================================]
  <IndexFrom>
  @action: Returns the zero-based relative index of a specific value within
           the TRange using directional integer division.
  @note: Validates containment, then divides the raw value-delta by the
         explicit directional step vector (1 or -1). This eliminates
         absolute value calls while remaining safe for descending ranges.
[==============================================================================}
function TRange.IndexFrom(const val: Integer): Integer; overload;
begin
  if not Self.Contains(val) then
    Exit(-1);
  Result := Self.Project(val);
end;

{==============================================================================]
  <IndexOf>
  @action: Returns the zero-based index of value val within the range.
  @note: - Returns -1 if v is not contained in the range.
         - O(1) — computed directly from start and direction, no iteration.
         - Respects direction: index 0 is always Self.start regardless
           of whether the range is ascending or descending.
[==============================================================================}
function TRange.IndexOf(const val: Integer): Integer; overload;
begin
  if not Self.Contains(val) then
    Exit(-1);
  Result := Self.Projected(val);
end;

{==============================================================================]
  <Indexy>
  @action: Returns the zero-based relative index of a specific value within
           the TRange using a math-derived sign multiplier.
  @note: Converts the Ascending boolean into a 1 or -1 multiplier via
         algebraic subtraction (True = 1, False = -1). Multiplying the raw
         distance by this factor ensures a positive index without branching.
[==============================================================================}
function TRange.Indexy(const val: Integer): Integer; overload;
begin
  if not Self.Contains(val) then
    Exit(-1);
  Result := Self.Projectify(val);
end;

{==============================================================================]
  <Proj>
  @action: Projects an integer value onto the TRange coordinate space as an 
           absolute, infinite distance offset from the starting boundary.
  @note: Utilizes the Abs function to instantly resolve the distance vector 
         from Self.start. This creates a branchless projection that treats 
         offsets symmetrically on both sides of the origin, bypassing 
         directional tracking logic entirely.
[==============================================================================}
function TRange.Proj(const val: Integer): Integer; overload;
begin
  Result := Abs(val - Self.start);
end;

{==============================================================================]
  <Project>
  @action: Projects a value onto the TRange linear coordinate space, returning
           negative indices for undershoot and greater-than-size indices for overshoot.
  @note: Removes boundary containment constraints entirely. Uses a branchless
         direction vector divisor to project an infinite local coordinate system
         running continuously through both sides of the range bounds.
[==============================================================================}
function TRange.Project(const val: Integer): Integer; overload;
begin
  Result := ((val - Self.start) div (Ord(Self.Asceal) - Ord(not Self.Asceal)));
end;

{==============================================================================]
  <Projecta>
  @action: Returns the zero-based relative index of a specific value within
           the TRange by calculating its offset from the structural minimum boundary.
  @note: Flattens directionality by resolving the true mathematical floor
         of the range using an inline conditional. For descending ranges,
         it mirrors the offset relative to the maximum size.
[==============================================================================}
function TRange.Projecta(const val: Integer): Integer; overload;
begin
  if not Self.Contains(val) then
    Exit(-1);
  case Self.Asceal of
    True: Result := (val - Self.start);
    False: Result := ((Self.Size - 1) - (val - Self.stop));
  end;
end;

{==============================================================================]
  <Projected>
  @action: Projects an integer value onto the TRange coordinate space as an 
           absolute, infinite distance offset from the starting boundary.
  @note: Utilizes the Abs function to instantly resolve the distance vector 
         from Self.start. This creates a branchless projection that treats 
         offsets symmetrically on both sides of the origin, bypassing 
         directional tracking logic entirely.
[==============================================================================}
function TRange.Projected(const val: Integer): Integer; overload;
begin
  if Self.Asceal then
    Result := (val - Self.start)
  else
    Result := (Self.start - val);
end;

{==============================================================================]
  <Projectify>
  @action: Projects an integer value onto an infinite, directional index 
           coordinate system relative to the TRange's orientation.
  @note: Uses a branchless algebraic formula to calculate a 1 or -1 direction 
         multiplier directly from the Ascending state. This scales the raw 
         distance from the start boundary out into infinity, allowing for 
         negative indices on undershoots and size-exceeding indices on overshoots.
[==============================================================================}
function TRange.Projectify(const val: Integer): Integer; overload;
begin
  Result := ((val - Self.start) * ((Ord(Self.Asceal) * 2) - 1));
end;
{$ENDIF}
