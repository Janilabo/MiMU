{$IFDEF METHODS}
function Blanco: TRange;
function Centered(const rCenter: Integer): TRange; overload;
function Frame(var rSize: Integer): TRange; overload;
function Frame: TRange; overload;
function Localize: Integer;
function Localized: TRange;
function Split(var rLeft, rRight: TRange): Integer;
function Template: TRange;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Blanco>
  @action: Returns a copy of the range translated so that its minimum endpoint
           lies at zero.
  @note: Non-mutating. Preserves the range length and direction (ascending
         or descending). Equivalent to translating the range by
         -min(start, stop).
[==============================================================================}
function TRange.Blanco: TRange;
var
  o: Integer;
begin
  o := -Min(Self.start, Self.stop);
  Result.Create((Self.start + o), (Self.stop + o));
end;

{==============================================================================]
  <Centered>
  @action: Returns a new TRange that has the same length as Self but is
           repositioned so that its midpoint equals the specified Center value.
           Self remains unchanged.
  @note:   Direction-aware; preserves ascending or descending order.
           Useful for geometric or data range realignment.
[==============================================================================}
function TRange.Centered(const rCenter: Integer): TRange; overload;
var
  h: Integer;
begin
  h := Self.Half;
  if Self.Ascending then
    Result.Create((rCenter - h), (rCenter + h))
  else
    Result.Create((rCenter + h), (rCenter - h));
end;

{==============================================================================]
  <Frame>
  @action Returns a TRange covering the full extent of this instance,
          starting at 0 and ending at Size - 1.
  @note   None.
[==============================================================================}
function TRange.Frame(var rSize: Integer): TRange; overload;
begin
  rSize := Self.Size;
  Result := Range(0, (rSize - 1));
end;

{==============================================================================]
  <Frame>
  @action Returns a TRange covering the full extent of this instance,
          starting at 0 and ending at Size - 1.
  @note   None.
[==============================================================================}
function TRange.Frame: TRange; overload;
begin
  Result := Range(0, (Self.Size - 1));
end;

{==============================================================================]
  <Localize>
  @action: Converts the range in place to local (zero-based) coordinates and
           returns the original offset.
  @note: Mutating operation. After the call, one endpoint is zero and the
         other represents the range length. The returned value can be used
         to restore or reapply the original position.
[==============================================================================}
function TRange.Localize: Integer;
begin
  case Self.Ascending of
    True:
    begin
      Result := Self.start;
      Dec(Self.stop, Result);
      Self.start := 0;
    end;
    False:
    begin
      Result := Self.stop;
      Dec(Self.start, Result);
      Self.stop := 0;
    end;
  end;
end; 

{==============================================================================]
  <Localized>
  @action: Returns a zero-based copy of the range with identical length and
           direction.
  @note: Non-mutating. The lowest (or highest, for descending ranges)
         endpoint is moved to zero while preserving orientation.
[==============================================================================}
function TRange.Localized: TRange;
begin
  Result := Self;
  case Self.Ascending of
    True:
    begin
      Dec(Result.stop, Result.start);
      Result.start := 0;
    end;
    False:
    begin
      Dec(Result.start, Result.stop);
      Result.stop := 0;
    end;
  end;
end;

{==============================================================================]
  <Split>
  @action: Normalizes the range and splits it into two contiguous subranges of
           approximately equal size.
           If the range is singular (Start = Stop), both output ranges are set to
           the normalized range and no split is performed.
           Otherwise, the range is split at the midpoint:
           - mLeft covers Start .. Midpoint
           - mRight covers (Midpoint + 1) .. Stop
  @note:
    - The method always normalizes Self before splitting.
    - Both rLeft and rRight are assigned in all cases.
    - The function result is the split point (midpoint). For a singular range,
      the Start value is returned.
    - Integer division is used when calculating the midpoint.
[==============================================================================}
function TRange.Split(var rLeft, rRight: TRange): Integer;
var
  n: TRange;
begin
  n := Self.Normalize;
  rLeft := n;
  rRight := n;
  if n.Singular then
    Exit(n.start);
  Result := (n.Combined div 2);
  rLeft.stop := Result;
  rRight.start := (Result + 1);
end;

{==============================================================================]
  <Template>
  @action: Returns a zero-based range representing only the magnitude of the
           original range.
  @note: Position is discarded while direction is preserved. The result
         spans from 0 to Length for ascending ranges, or Length to 0 for
         descending ranges. Non-mutating.
[==============================================================================}
function TRange.Template: TRange;
begin
  if Self.Ascending then
    Result.Create(0, (Self.Maximum - Self.Minimum))
  else
    Result.Create((Self.Maximum - Self.Minimum), 0);
end;
{$ENDIF}
