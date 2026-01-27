{$IFDEF METHODS}
function Progress(const pPercent: Double): Integer;
function Reserve: TIntegerArray; overload;
function Reserve(var aRange: TIntegerArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Progress>
  @action: Returns a position within the range corresponding to the given progress
          ratio.
          The position is calculated by linearly interpolating between Start and Stop
		  using pPercent, then rounding to the nearest integer.
  @note:
    - pPercent is expected to be in the range 0.0 .. 1.0, where:
        0.0 returns Start
        1.0 returns Stop
    - Values outside this range will extrapolate beyond the bounds.
    - No normalization is performed; Start and Stop are used as-is.
    - Rounding is applied after interpolation and may bias the result.
    - For a singular range (Start = Stop), the result equals Start regardless
      of pPercent.
[==============================================================================}
function TRange.Progress(const pPercent: Double): Integer;
begin
  Result := (Self.start + Round((Self.stop - Self.start) * pPercent));
end;

{==============================================================================]
  <Reserve>
  @action: Allocate an integer array sized to fit the full range.
  @note: The array is preallocated with the correct length but is not filled
         with values from start..stop. Elements are default-initialized to 0.
[==============================================================================}
function TRange.Reserve: TIntegerArray; overload;
begin
  SetLength(Result, Self.Size);
end;

{==============================================================================]
  <Reserve>
  @action: Allocate an integer array sized to fit the full range.
  @note: The array is preallocated with the correct length but is not filled
         with values from start..stop. Elements are default-initialized to 0.
[==============================================================================}
function TRange.Reserve(var aRange: TIntegerArray): Integer; overload;
begin
  Result := Self.Size;
  SetLength(aRange, Result);
end;
{$ENDIF}
