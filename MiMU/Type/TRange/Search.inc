{$IFDEF METHODS}
function Identifier(const val: Integer): Integer; overload;
function Identify(const val: Integer): Integer; overload;
function IndexBy(const val: Integer): Integer; overload;
function IndexFor(const val: Integer): Integer; overload;
function IndexFrom(const val: Integer): Integer; overload;
function IndexOf(const val: Integer): Integer; overload;
function Indexy(const val: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Identifier>
  @action: Calculates the zero-based relative index of a specific value within 
           the TRange using a single-line, branchless ordinal division formula.
  @note: Uses a wrapped denominator subtraction to safely compute a direction 
         vector (1 for Ascending, -1 for Descending). This vector divides the 
         raw distance from the start boundary, cleanly neutralizing negative 
         offsets for descending ranges without branching or absolute value calls.
[==============================================================================}
function TRange.Identifier(const val: Integer): Integer; overload;
begin
  if not Self.Contains(val) then
    Exit(-1);
  Result := ((val - Self.start) div (Ord(Self.Ascending) - Ord(not Self.Ascending)));
end;

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
  d := IfThen(Self.Ascending, 1, -1);
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
  case Self.Ascending of
    True: Result := (val - Self.start);
    False: Result := ((Self.Size - 1) - (val - Self.stop));
  end;
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
  Result := Abs(val - Self.start);
end;

{==============================================================================]
  <IndexFrom>
  @action: Returns the zero-based relative index of a specific value within
           the TRange using directional integer division.
  @note:   Validates containment, then divides the raw value-delta by the
           explicit directional step vector (1 or -1). This eliminates
           absolute value calls while remaining safe for descending ranges.
[==============================================================================}
function TRange.IndexFrom(const val: Integer): Integer; overload;
begin
  if not Self.Contains(val) then
    Exit(-1);
  Result := ((val - Self.start) div Ord(Self.Ascending) - Ord(not Self.Ascending));
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
  if Self.Ascending then
    Result := (val - Self.start)
  else
    Result := (Self.start - val);
end;

{==============================================================================]
  <Indexy>
  @action: Returns the zero-based relative index of a specific value within
           the TRange using a math-derived sign multiplier.
  @note:   Converts the Ascending boolean into a 1 or -1 multiplier via
           algebraic subtraction (True = 1, False = -1). Multiplying the raw
           distance by this factor ensures a positive index without branching.
[==============================================================================}
function TRange.Indexy(const val: Integer): Integer; overload;
begin
  if not Self.Contains(val) then
    Exit(-1);
  Result := ((val - Self.start) * ((Ord(Self.Ascending) * 2) - 1));
end;
{$ENDIF}
