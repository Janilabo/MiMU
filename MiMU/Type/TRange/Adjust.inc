{$IFDEF METHODS}
function Modified(const mStart, mStop: Integer): TRange; overload;
function Modify(const mStart, mStop: Integer): TRange; overload;
procedure Scale(const sFactor: Integer);
function Scaled(const sFactor: Integer): TRange;
procedure Translate(const tDelta: Integer);
function Translated(const tDelta: Integer): TRange;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Modified>
  @action: Returns a new TRange with Start and Stop adjusted by the specified
           mStart and mStop offsets, without modifying Self.
  @note:   Functional version of Modify. Useful for expression-style or
           fluent programming where immutability is preferred.
[==============================================================================}
function TRange.Modified(const mStart, mStop: Integer): TRange; overload;
begin
  Result.start := (Self.start + mStart);
  Result.stop := (Self.stop + mStop);
end;

{==============================================================================]
  <Modify>
  @action: Adds the given mStart and mStop offsets to the current range bounds,
           modifying Self in place. Returns the original range before modification.
  @note:   Used internally by operations like Contract or Expand for direct bound
           adjustment while preserving the previous state.
[==============================================================================}
function TRange.Modify(const mStart, mStop: Integer): TRange; overload;
begin
  Result := Self;
  Self.start := (Self.start + mStart);
  Self.stop := (Self.stop + mStop);
end;

{==============================================================================]
  <Scale>
  @action: Scales the range in place by the given factor.
  @note: This is a mutating operation. Scaling is relative to the origin (0).
         Both endpoints are multiplied by sFactor.
[==============================================================================}
procedure TRange.Scale(const sFactor: Integer);
begin
  Self.start := (Self.start * sFactor);
  Self.stop  := (Self.stop  * sFactor);
end;

{==============================================================================]
  <Scaled>
  @action: Returns a copy of the range scaled by the given factor.
  @note: Scaling is performed relative to the origin (0). Both endpoints are
         multiplied by sFactor. Direction is preserved for positive factors
         and inverted for negative factors.
[==============================================================================}
function TRange.Scaled(const sFactor: Integer): TRange;
begin
  Result.start := (Self.start * sFactor);
  Result.stop  := (Self.stop  * sFactor);
end;

{==============================================================================]
  <Translate>
  @action: Translates the range in place by the given delta.
  @note: This is a mutating operation. Both endpoints are shifted by tDelta,
         preserving the range’s length, direction, and ordering.
         Equivalent to adding tDelta to both start and stop.
[==============================================================================}
procedure TRange.Translate(const tDelta: Integer);
begin
  Inc(Self.start, tDelta);
  Inc(Self.stop, tDelta);
end;

{==============================================================================]
  <Translated>
  @action: Returns a copy of the range translated by the given delta.
  @note: This is a non-mutating operation. Both endpoints of the resulting
         range are shifted by tDelta. Length and direction are preserved.
[==============================================================================}
function TRange.Translated(const tDelta: Integer): TRange;
begin
  Result.start := (Self.start + tDelta);
  Result.stop  := (Self.stop + tDelta);
end;
{$ENDIF}