{$IFDEF METHODS}
function Modified(const mStart, mStop: Integer): TRange; overload;
function Modify(const mStart, mStop: Integer): TRange; overload;
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
{$ENDIF}