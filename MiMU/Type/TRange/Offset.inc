{$IFDEF METHODS}
function Back(const N: Integer = 1): TRange; overload;
function Backed(const N: Integer = 1): TRange; overload;
function Decrease(const N: Integer = 1): TRange; overload;
function Decrement(const N: Integer = 1): TRange; overload;
function Increase(const N: Integer = 1): TRange; overload;
function Increment(const N: Integer = 1): TRange; overload;
function Offset(const sDelta: Integer): TRange; overload;
function Offset(const dStart, dStop: Integer): TRange; overload;
function Shift(const N: Integer = 1): TRange; overload;
function Shifted(const N: Integer = 1): TRange; overload;
function ShiftStart(const N: Integer = 1): Integer; overload;
function ShiftStop(const N: Integer = 1): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Back>
  @action: Subtracts the given offset N from both Start and Stop of the range,
           modifying Self in place. Returns a copy of the original range
           before the backward shift.
  @note:   Default offset = 1. Useful when you need the previous state while
           moving the range backward.
[==============================================================================}
function TRange.Back(const N: Integer = 1): TRange; overload;
begin
  Result := Self;
  Dec(Self.start, N);
  Dec(Self.stop, N);
end;

{==============================================================================]
  <Backed>
  @action: Returns a new TRange shifted backward by the given offset N, without
           modifying Self.
  @note:   Default offset = 1. Functional style; Self remains unchanged. Can
           be used for expression-style or fluent programming.
[==============================================================================}
function TRange.Backed(const N: Integer = 1): TRange; overload;
begin
  Result.start := (Self.start - N);
  Result.stop := (Self.stop - N);
end;

{==============================================================================]
  <Decrease>
  @action: Subtracts the given amount (default = 1) from both Start and Stop of the range,
           modifying Self in place. Returns a copy of the original range
           before the decrease.
  @note:   Useful when you want to capture the previous state while mutating the range backward.
[==============================================================================}
function TRange.Decrease(const N: Integer = 1): TRange; overload;
begin
  Result := Self;
  Self.start := (Self.start - N);
  Self.stop := (Self.stop - N);
end;

{==============================================================================]
  <Decrement>
  @action: Subtracts the given amount (default = 1) from both Start and Stop of the range,
           modifying Self in place. Returns the updated range after the decrease.
  @note:   Functional-style usage: Self is modified, and the returned range reflects the new values.
[==============================================================================}
function TRange.Decrement(const N: Integer = 1): TRange; overload;
begin
  Self.start := (Self.start - N);
  Self.stop := (Self.stop - N);
  Result := Self;
end;

{==============================================================================]
  <Increase>
  @action: Adds the given amount (default = 1) to both Start and Stop of the range,
           modifying Self in place. Returns a copy of the original range
           before the increase.
  @note:   Useful when you want to capture the previous state while mutating the range forward.
[==============================================================================}
function TRange.Increase(const N: Integer = 1): TRange; overload;
begin
  Result := Self;
  Self.start := (Self.start + N);
  Self.stop := (Self.stop + N);
end;

{==============================================================================]
  <Increment>
  @action: Adds the given amount (default = 1) to both Start and Stop of the range,
           modifying Self in place. Returns the updated range after the increase.
  @note:   Functional-style usage: Self is modified, and the returned range reflects the new values.
[==============================================================================}
function TRange.Increment(const N: Integer = 1): TRange; overload;
begin
  Self.start := (Self.start + N);
  Self.stop := (Self.stop + N);
  Result := Self;
end;

{==============================================================================]
  <Offset>
  @action: Returns shift of range r by delta.
  @note: None.
[==============================================================================}
function TRange.Offset(const sDelta: Integer): TRange; overload;
begin
  Result.Create((Self.start + sDelta), (Self.stop + sDelta));
end;

{==============================================================================]
  <Offset>
  @action: Returns shift of range r by delta starting/stopping.
  @note: None.
[==============================================================================}
function TRange.Offset(const dStart, dStop: Integer): TRange; overload;
begin
  Result.start := (Self.start + dStart);
  Result.stop := (Self.stop + dStop);
end;

{==============================================================================]
  <Shift>
  @action: Adds the given offset N to both Start and Stop of the range,
           modifying Self in place. Returns a copy of the original range
           before the shift.
  @note:   Useful when you need the previous state while mutating the range.
[==============================================================================}
function TRange.Shift(const N: Integer = 1): TRange; overload;
begin
  Result := Self;
  Inc(Self.start, N);
  Inc(Self.stop, N);
end;

{==============================================================================]
  <Shifted>
  @action: Returns a new TRange offset N by the given value, without modifying Self.
  @note:   Functional style; Self remains unchanged. Can be used for expression-style
           or fluent programming.
[==============================================================================}
function TRange.Shifted(const N: Integer = 1): TRange; overload;
begin
  Result.start := (Self.start + N);
  Result.stop := (Self.stop + N);
end;

{==============================================================================]
  <ShiftStart>
  @action: Computes a directional offset value from the start boundary of the range.
  @note: Does not mutate Self. Direction is inverted when Descending is true;
         otherwise normal forward stepping is applied.
[==============================================================================}
function TRange.ShiftStart(const N: Integer = 1): Integer; overload;
begin
  if Self.Descending then
    Result := Self.start.Increment(N)
  else
    Result := Self.start.Decrement(N);
end;

{==============================================================================]
  <ShiftStop>
  @action: Computes a directional offset value from the stop boundary of the range.
  @note: Does not mutate Self. Uses Descending flag to invert increment/decrement behavior.
[==============================================================================}
function TRange.ShiftStop(const N: Integer = 1): Integer; overload;
begin
  if Self.Descending then
    Result := Self.stop.Decrement(N)
  else
    Result := Self.stop.Increment(N);
end;
{$ENDIF}
