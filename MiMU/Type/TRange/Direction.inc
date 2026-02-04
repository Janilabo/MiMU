{$IFDEF METHODS}
function Direction: Integer;
function Orientation: Integer;
function Signum: Integer;
function Slope: Integer;
function Step: Integer; overload;
function Step(const index: Integer): Integer; overload;
function Stepping: Integer; overload;
function Stride: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Direction>
  @action: Returns the orientation of the range.
  @note: 1  => descending (stop > start)
        -1  => ascending  (start > stop)
         0  => degenerate (start = stop)
[==============================================================================}
function TRange.Direction: Integer;
begin
  Result := Sign(Self.Delta);
end;

{==============================================================================]
  <Orientation>
  @action: Returns +1 if the range is ascending or degenerate (Stop >= Start),
           and -1 if the range is descending (Stop < Start).
  @note: Useful for determining iteration direction or orientation of the range.
[==============================================================================}
function TRange.Orientation: Integer;
begin
  Result := IfThen((Self.Stop < Self.Start), -1, 1);
end;

{==============================================================================]
  <Signum>
  @action: Returns the directional sign of the range.
           +1 if the range is ascending (stop > start),
           -1 if descending (stop < start),
           0 if start = stop.
  @note: Useful for determining the trend or direction of the range without
         caring about the magnitude. Does not include endpoints count.
[==============================================================================}
function TRange.Signum: Integer;
begin
  if Self.Singular then
    Result := 0
  else
    Result := ((Self.stop - Self.start) div Abs(Self.start - Self.stop));
end;

{==============================================================================]
  <Slope>
  @action: Returns the slope (direction) of the range.
           +1 if the range is ascending (stop > start),
           -1 if descending (stop < start),
           0 if start = stop.
  @note: Useful for determining the trend of the range without considering magnitude.
         Equivalent to Signum in behavior; purely indicates direction.
[==============================================================================}
function TRange.Slope: Integer;
begin
  if Self.Singular then
    Result := 0
  else if (Self.stop > Self.start) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
  <Step>
  @action: Returns the step direction of the range.
           The result is always either +1 or -1 and specifies the
		   direction in which the range progresses when iterated or indexed.
           +1  — ascending or single-element range (start <= stop)
           -1  — descending range (start > stop)
  @note: TRange instances are inclusive and never empty. Both ascending and
         descending ranges are valid.
         This function exists to provide a clear, readable representation of the
         range direction and is typically used by iteration, indexing (At),
         enumeration, and expansion logic.
  @seealso: Stride
[==============================================================================}
function TRange.Step: Integer; overload;
begin
  if Self.Descending then
    Exit(-1);
  Result := 1;
end;

{==============================================================================]
  <Step>
  @action: Returns the value at the specified index in the range, computed using
           the range's direction and step.
           If the index is out of bounds (index < 0 or index >= Size), the function
           returns -2147483648 (Integer.MinValue) as a sentinel value.
  @note: This function combines the range's start value, stride, and index to
         produce the element at the requested position:
         Result = start + index * (Stride - 1)
         This function is typically used for indexed access without allocating
         an array. 
[==============================================================================}
function TRange.Step(const index: Integer): Integer; overload;
begin
  if ((index < 0) or (index >= Self.Size)) then
    Exit(-2147483648);
  Result := ((Self.start + Index) * (Self.Stride - 1));
end;

{==============================================================================]
  <Stepping>
  @action: Returns the step value for iterating over the range.
           - Returns 1 if the range is ascending.
           - Returns -1 if the range is descending.
  @note: The stepping is determined solely by the Descending property of the range.
         This method is useful when looping or performing arithmetic over the range.
[==============================================================================}
function TRange.Stepping: Integer; overload;
begin
  Result := IfThen(Self.Descending, -1, 1);
end;

{==============================================================================]
  <Stride>
  @action: Returns the stride of the range as a signed unit value.
           The result is always either +1 or -1 and represents the signed increment
           applied when moving from one element of the range to the next.
           +1  — ascending or single-element range (start <= stop)
           -1  — descending range (start > stop)
  @note: This function is functionally equivalent to Step but implemented in a
         branch-free form suitable for low-level or performance-critical code.
         The stride value is intended for use in arithmetic expressions such as:
         start + Index * Stride
         TRange instances are inclusive and never empty.
  @seealso: Step
[==============================================================================}
function TRange.Stride: Integer; overload;
begin
  Result := ((Ord(Self.Ascending) * 2) - 1);
end;
{$ENDIF}