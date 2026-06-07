{$IFDEF METHODS}
function Standard: TRange; overload;
function Standarded: TRange; overload;
function Standardified: TRange; overload;
function Standardify: TRange; overload;
function Standardize: TRange; overload;
function Standardized: TRange; overload;
function Standardo: TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Standard>
  @action: Creates a zero-indexed normalized copy of the TRange, shifting the 
           origin to 0 while preserving its exact size/span.
  @note: Optimized to utilize the internal Size property minus one to determine 
         the new relative upper bound, eliminating the need for boundary 
         min/max evaluations.
[==============================================================================}
function TRange.Standard: TRange; overload;
begin
  Result := TRange.Construct(0, (Self.Size - 1));
end;

{==============================================================================]
  <Standarded>
  @action: Creates a normalized copy of the TRange anchored at 0, where the upper
           bound equals the absolute span (distance) between the original range's
           endpoints, irrespective of direction.
  @note: This method relies on the `Span` property, which returns the non‑negative
         absolute difference `Abs(stop - start)`. The resulting range is always
         ascending (or zero‑length) and has the same magnitude as the original.
[==============================================================================}
function TRange.Standarded: TRange; overload;
begin
  Result := TRange.Construct(0, Self.Span);
end;

{==============================================================================]
  <Standardified>
  @action: Creates a zero-indexed normalized copy of the TRange starting at 0, 
           determining the positive upper bound via inline conditional subtraction.
  @note: Evaluates whether the range is descending (start > stop) to safely 
         subtract the lower bound from the upper bound. This guarantees a 
         positive span for the new stop boundary without relying on an absolute 
         value function.
[==============================================================================}
function TRange.Standardified: TRange; overload;
begin
  Result := TRange.Construct(0, IfThen((Self.start > Self.stop), (Self.start - Self.stop), (Self.stop - Self.start)));
end;

{==============================================================================]
  <Standardify>
  @action: Transforms the range into a standardized, zero-indexed template by 
           re-aligning the coordinate space to originate strictly at 0.
  @note: Leverages an internal Normalize method call to establish a baseline, 
         then explicitly forces the start boundary to 0 while calculating 
         the absolute span delta for the stop boundary.
[==============================================================================}
function TRange.Standardify: TRange; overload;
var
  n: TRange;
begin
  n := Self.Normalize;
  Result.start := 0;
  Result.stop := (-n.start + n.stop);
end;

{==============================================================================]
  <Standardize>
  @action: Creates a new TRange with the same span/magnitude, but shifted to
           begin at a standard baseline of 0.
  @note: Maintains the absolute scale of the range by utilizing the delta
         between Maximum and Minimum boundaries, anchoring the new start at 0.
[==============================================================================}
function TRange.Standardize: TRange; overload;
begin
  Result := TRange.Construct(0, (Self.Maximum - Self.Minimum));
end;

{==============================================================================]
  <Standardized>
  @action: Creates a normalized copy of the TRange anchored at 0, where the upper
           bound equals the absolute span (length) of the original range, preserving
           magnitude but discarding direction.
  @note: If the original range is descending (start > stop), the function swaps
         the endpoints to ensure the resulting range has a non‑negative span
         (stop' = start - stop). The standardized range is always ascending
         or zero‑length.
[==============================================================================}
function TRange.Standardized: TRange; overload;
begin
  if Self.Ascending then
    Result := TRange.Construct(0, (Self.stop - Self.start))
  else
    Result := TRange.Construct(0, (Self.start - Self.stop));
end;

{==============================================================================]
  <Standardo>
  @action: Creates a zero-indexed normalized copy of the TRange starting at 0, 
           resolving the positive upper bound via branchless boolean arithmetic.
  @note: Uses a clever algebraic sign-multiplier generated from the ordinal 
         values of the Ascending state (1 for True, -1 for False). This multiplier 
         is applied directly to the boundary delta, ensuring a positive span 
         without introducing CPU branch misprediction penalties.
[==============================================================================}
function TRange.Standardo: TRange; overload;
begin
  Result := TRange.Construct(0, (Ord(Self.Ascending) - Ord(not Self.Ascending)) * (Self.stop - Self.start));
end;
{$ENDIF}
