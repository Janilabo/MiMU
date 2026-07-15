{$IFDEF METHODS}
function Ascency: Boolean; overload;
function Ascendal: Boolean; overload;
function Ascending: Boolean; overload;
function Ascends: Boolean; overload;
function Ascing: Boolean; overload;
function Descency: Boolean; overload;
function Descendal: Boolean; overload;
function Descending: Boolean; overload;
function Descends: Boolean; overload;
function Descing: Boolean; overload;
function IsAscending: Boolean; overload;
function IsDescending: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascency>
  @action: Determines if the range is strictly ascending using a sign-of-difference check.
  @note: Returns True if (stop - start) is positive. Only applicable to numeric range types.
[==============================================================================}
function TRange.Ascency: Boolean; overload;
begin
  Result := (Sign(Self.stop - Self.start) > 0);
end;

{==============================================================================]
  <Ascendal>
  @action: Determines if the range is strictly ascending (increasing).
  @note: Returns True only if the start boundary is strictly less than the stop boundary.
[==============================================================================}
function TRange.Ascendal: Boolean; overload;
begin
  Result := (Self.start.Compare(Self.stop) < 0);
end;

{==============================================================================]
  <Ascending>
  @action: Determines if the range is strictly ascending.
  @note: Returns True if the start value is strictly less than the stop value.
[==============================================================================}
function TRange.Ascending: Boolean; overload;
begin
  Result := (Self.start < Self.stop);
end;

{==============================================================================]
  <Ascends>
  @action: Determines if the range is strictly ascending by negating a greater-than-or-equal-to comparison.
  @note: Returns True if the start value is strictly less than the stop value. Logically equivalent to "not (start >= stop)".
[==============================================================================}
function TRange.Ascends: Boolean; overload;
begin
  Result := not (Self.start >= Self.stop);
end;

{==============================================================================]
  <Ascing>
  @action: Returns True if the range is oriented forward.
  @note: Strict inequality (Stop > Start).
         Returns False if the range is stationary (Start = Stop).
[==============================================================================}
function TRange.Ascing: Boolean; overload;
begin
  Result := (Self.stop > Self.start);
end;

{==============================================================================]
  <Descency>
  @action: Determines if the range is strictly descending using a sign-of-difference check.
  @note: Returns True if (start - stop) is positive. Only applicable to numeric range types.
[==============================================================================}
function TRange.Descency: Boolean; overload;
begin
  Result := (Sign(Self.start - Self.stop) > 0);
end;

{==============================================================================]
  <Descendal>
  @action: Determines if the range is strictly descending (decreasing).
  @note: Returns True only if the start boundary is strictly greater than the stop boundary.
[==============================================================================}
function TRange.Descendal: Boolean; overload;
begin
  Result := (Self.start.Compare(Self.stop) > 0);
end;

{==============================================================================]
  <Descending>
  @action: Returns True if the range is ordered in strictly descending order,
           i.e. the start value is greater than the stop value.
  @note: A range with equal start and stop values is not considered descending.
         This function is logically equivalent to not Ascending.
[==============================================================================}
function TRange.Descending: Boolean; overload;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <Descends>
  @action: Returns True if the range descends, meaning the start value is greater
           than the stop value.
  @note: This function is semantically equivalent to Descending and exists to
         support verb-style readability in conditional expressions.
[==============================================================================}
function TRange.Descends: Boolean; overload;
begin
  Result := not (Self.start <= Self.stop);
end;

{==============================================================================]
  <Descing>
  @action: Returns True if the range is oriented backward.
  @note: Strict inequality (Start > Stop).
         Returns False if the range is stationary (Start = Stop).
[==============================================================================}
function TRange.Descing: Boolean; overload;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <IsAscending>
  @action: Determines if the range is strictly ascending by checking if the start value is less than the stop value.
  @note: Returns True if (start - stop) is less than zero. Requires a numeric type that supports subtraction.
[==============================================================================}
function TRange.IsAscending: Boolean; overload;
begin
  Result := ((Self.start - Self.stop) < 0);
end;

{==============================================================================]
  <IsDescending>
  @action: Determines whether the range is in descending order.
  @note: Returns True if Start is greater than Stop.
         Useful for iteration or conditional logic that depends on direction.
[==============================================================================}
function TRange.IsDescending: Boolean; overload;
begin
  Result := ((Self.start - Self.stop) > 0);
end;
{$ENDIF}
