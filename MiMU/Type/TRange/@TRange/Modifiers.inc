{$IFDEF METHODS}
function Apogee(const val: Integer = 0): TRange; overload;
function Nadir(const val: Integer = 0): TRange; overload;
function Perigee(const val: Integer = 0): TRange; overload;
function SetStart(const val: Integer = 0): TRange; overload;
function SetStop(const val: Integer = 0): TRange; overload;
function Zenith(const val: Integer = 0): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Apogee>
  @action: Sets the higher-valued endpoint of the range to val, regardless of
           whether that endpoint is currently start or stop, and returns the
           mutated range.
  @note: Uses stop >= start (rather than strict >) to decide direction, so a
         degenerate point-range (start = stop) is treated as ascending and
         val is assigned to stop. Unlike Zenith, this has no special-case
         rebuild for degenerate ranges — it's a direct two-branch assignment.
[==============================================================================}
function TRange.Apogee(const val: Integer = 0): TRange; overload;
begin
  if Self.Ascual then
    Self.stop := val
  else
    Self.start := val;
  Result := Self;
end;

{==============================================================================]
  <Nadir>
  @action: Sets the minimum (lower-valued) bound of the range to val, returning
           the mutated range.
  @note: If the range is degenerate (start = stop), re-constructs it as a zero-length
         point range at (val, val). For non-degenerate ranges, updates start if
         ascending (stop > start) or stop if descending.
[==============================================================================}
function TRange.Nadir(const val: Integer = 0): TRange; overload;
begin
  if Self.Singular then
    Self := TRange.Construct(val, val)
  else if Self.Ascending then
    Self.start := val
  else
    Self.stop := val;
  Result := Self;
end;

{==============================================================================]
  <Perigee>
  @action: Sets the lower-valued endpoint of the range to val, regardless of
           whether that endpoint is currently start or stop, and returns the
           mutated range.
  @note: Uses stop >= start (rather than strict >) to decide direction, so a
         degenerate point-range (start = stop) is treated as ascending and
         val is assigned to start. Unlike Nadir, this has no special-case
         rebuild for degenerate ranges — it's a direct two-branch assignment.
[==============================================================================}
function TRange.Perigee(const val: Integer = 0): TRange; overload;
begin
  if Self.Ascual then
    Self.start := val
  else
    Self.stop := val;
  Result := Self;
end;

{==============================================================================]
  <SetStart>
  @action: Sets the start boundary of the range to val and returns the mutated
           range to support method chaining.
  @note: Directly modifies the start field without altering stop or enforcing
         ordering, regardless of whether the resulting range is ascending,
         descending, or degenerate.
[==============================================================================}
function TRange.SetStart(const val: Integer = 0): TRange; overload;
begin
  Self.start := val;
  Result := Self;
end;

{==============================================================================]
  <SetStop>
  @action: Sets the stop boundary of the range to val and returns the mutated
           range to support method chaining.
  @note: Directly modifies the stop field without altering start or enforcing
         ordering, regardless of whether the resulting range is ascending,
         descending, or degenerate.
[==============================================================================}
function TRange.SetStop(const val: Integer = 0): TRange; overload;
begin
  Self.stop := val;
  Result := Self;
end;

{==============================================================================]
  <Zenith>
  @action: Sets the maximum (higher-valued) bound of the range to val, returning
           the mutated range.
  @note: If the range is degenerate (start = stop), re-constructs it as a zero-length
         point range at (val, val). For non-degenerate ranges, updates stop if
         ascending (stop > start) or start if descending.
[==============================================================================}
function TRange.Zenith(const val: Integer = 0): TRange; overload;
begin
  if Self.Singular then
    Self := TRange.Construct(val, val)
  else if Self.Ascending then
    Self.stop := val
  else
    Self.start := val;
  Result := Self;
end;
{$ENDIF}
