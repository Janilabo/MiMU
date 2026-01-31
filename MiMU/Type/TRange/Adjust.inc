{$IFDEF METHODS}
function Modified(const mStart, mStop: Integer): TRange; overload;
function Modify(const mStart, mStop: Integer): TRange; overload;
procedure Scale(const sFactor: Integer); overload;
function Scaled(const sFactor: Integer): TRange; overload;
function Starting(const val: Integer): TRange; overload;
function Stopping(const val: Integer): TRange; overload;
procedure Translate(const tDelta: Integer); overload;
function Translated(const tDelta: Integer): TRange; overload;
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
procedure TRange.Scale(const sFactor: Integer); overload;
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
function TRange.Scaled(const sFactor: Integer): TRange; overload;
begin
  Result.start := (Self.start * sFactor);
  Result.stop  := (Self.stop  * sFactor);
end;

{==============================================================================]
  <Starting>
  @action: Returns a new TRange with its start value replaced by the given value.
  @note: This method does not modify the current instance; it produces a copy
         with an updated start while preserving the existing stop value.
[==============================================================================}
function TRange.Starting(const val: Integer): TRange; overload;
begin
  Result.start := val;
  Result.stop := Self.stop;
end;

{==============================================================================]
  <Stopping>
  @action: Returns a new TRange with its stop value replaced by the given value.
  @note: This method does not modify the current instance; it produces a copy
         with an updated stop while preserving the existing start value.
[==============================================================================}
function TRange.Stopping(const val: Integer): TRange; overload;
begin
  Result.start := Self.start;
  Result.stop := val;
end;

{==============================================================================]
  <Translate>
  @action: Translates the range in place by the given delta.
  @note: This is a mutating operation. Both endpoints are shifted by tDelta,
         preserving the range’s length, direction, and ordering.
         Equivalent to adding tDelta to both start and stop.
[==============================================================================}
procedure TRange.Translate(const tDelta: Integer); overload;
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
function TRange.Translated(const tDelta: Integer): TRange; overload;
begin
  Result.start := (Self.start + tDelta);
  Result.stop  := (Self.stop + tDelta);
end;
{$ENDIF}