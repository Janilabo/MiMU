{$IFDEF TYPES}
function Contains(const x: Integer): Boolean; overload; 
function Contains(const x: TRange): Boolean; overload;
function Holds(const val: Integer): Boolean; overload;
function Holds(const vals: TRange): Boolean; overload;
function Missing(const val: Integer): Boolean; overload;
function Missing(const vals: TRange): Boolean; overload;	
function Above(const target: Integer): Boolean; overload; 
function Above(const target: TRange): Boolean; overload; 
function Below(const target: Integer): Boolean; overload; 
function Below(const target: TRange): Boolean; overload;
function Digit(const x: Integer): Boolean; inline;
function Value(const x: Integer): Boolean; inline;
function Item(const x: Integer): Boolean; inline;
function Employs(const val: Integer): Boolean;
function Omits(const val: Integer): Boolean;
function Lacks(const x: Integer): Boolean; inline;
function Outside(const x: Integer): Boolean; inline;
{$ENDIF}

{$IFDEF HELPERS}

{$ENDIF}

{$IFDEF METHODS}

{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Contains>
  @action: Returns True if range contains x-value.
  @note: None.
[==============================================================================}
function TRange.Contains(const x: Integer): Boolean; overload;
begin
  Result := ((x >= Min(Self.start, Self.stop)) and (x <= Max(Self.stop, Self.start)));
end;

{==============================================================================]
  <Contains>
  @action: Returns True if range contains x.
  @note: Meaning x is completely part of range.
[==============================================================================}
function TRange.Contains(const x: TRange): Boolean; overload;
begin
  Result := ((Min(x.start, x.stop) >= Min(Self.start, Self.stop)) and (Max(x.start, x.stop) <= Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <Holds>
  @action: Determines whether a given integer value lies within the range.
  @note: Returns True if the value is greater than or equal to the lower bound
         and less than or equal to the upper bound, regardless of whether
         start > stop. Complementary to Missing.
[==============================================================================}
function TRange.Holds(const val: Integer): Boolean; overload;
begin
  Result := ((val >= Min(Self.start, Self.stop)) and (val <= Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <Holds>
  @action: Determines whether a given integer value lies within the range.
  @note: Returns True if the value is greater than or equal to the lower bound
         and less than or equal to the upper bound, regardless of whether
         start > stop. Complementary to Missing.
[==============================================================================}
function TRange.Holds(const vals: TRange): Boolean; overload;
begin
  Result := (Min(vals.start, vals.stop) >= Min(Self.start, Self.stop)) and (Max(vals.start, vals.stop) <= Max(Self.start, Self.stop));
end;

{==============================================================================]
  <Missing>
  @action: Determines whether a given integer value lies outside the range.
  @note: Returns True if the value is less than the lower bound or greater than
         the upper bound, regardless of start/stop order. Complementary to Holds.
[==============================================================================}
function TRange.Missing(const val: Integer): Boolean; overload;
begin
  Result := ((val < Min(Self.start, Self.stop)) or (val > Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <Missing>
  @action: Determines whether another range lies entirely outside this range.
  @note: Returns True if the input range is completely disjoint from this range,
         i.e., there is no overlap between the ranges. Works correctly for both
         ascending and descending ranges by normalizing start and stop values.
[==============================================================================}
function TRange.Missing(const vals: TRange): Boolean; overload;
begin
  Result := ((Max(vals.start, vals.stop) < Min(Self.start, Self.stop)) or (Min(vals.start, vals.stop) > Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <Above>
  @action: Returns True if range is above target.
  @note: None.
[==============================================================================}
function TRange.Above(const target: Integer): Boolean; overload;
begin
  Result := (Self.Minimum > target);
end;

function TRange.Above(const target: TRange): Boolean; overload;
begin
  Result := Self.Above(target.Maximum);
end;

{==============================================================================]
  <Below>
  @action: Returns True if range is below target.
  @note: None.
[==============================================================================}
function TRange.Below(const target: Integer): Boolean; overload;
begin
  Result := (Self.Maximum < target);
end;

function TRange.Below(const target: TRange): Boolean; overload;
begin
  Result := Self.Below(target.Minimum);
end;

{==============================================================================]
 <Digit>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRange.Digit(const x: Integer): Boolean; inline;
begin
  Result := (((x >= Self.start) and (x <= Self.stop)) or ((x >= Self.stop) and (x <= Self.start)));
end;

{==============================================================================]
 <Value>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRange.Value(const x: Integer): Boolean; inline;
begin
  Result := not (((x < Self.start) and (x < Self.stop)) or ((x > Self.stop) and (x > Self.start)));
end;

{==============================================================================]
 <Lacks>
 @action: Returns true if x-value is out of range.
 @note: None.
[==============================================================================}
function TRange.Lacks(const x: Integer): Boolean; inline;
begin
  Result := (((x < Self.start) and (x < Self.stop)) or ((x > Self.stop) and (x > Self.start)));
end;

{==============================================================================]
 <Outside>
 @action: Returns true if x-value is outside the range.
 @note: None.
[==============================================================================}
function TRange.Outside(const x: Integer): Boolean; inline;
begin
  Result := not (((x >= Self.start) and (x <= Self.stop)) or ((x >= Self.stop) and (x <= Self.start)));
end;

{==============================================================================]
 <Item>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRange.Item(const x: Integer): Boolean; inline;
begin
  if (Self.start <= Self.stop) then
    Result := ((x >= Self.start) and (x <= Self.stop))
  else
    Result := ((x >= Self.stop) and (x <= Self.start));
end;

{==============================================================================]
  <Employs>
  @action: Checks if the given integer value matches either the start or stop of the range.
  @note: Useful for quickly verifying if a value is an endpoint of the range.
[==============================================================================}
function TRange.Employs(const val: Integer): Boolean;
begin
  Result := ((Self.start = val) or (Self.stop = val));
end;

{==============================================================================]
  <Omits>
  @action: Checks if the given integer value is NOT present as either the start or stop of the range.
  @note: Logical inverse of TRange.Employs; returns True if the value is absent from the range endpoints.
[==============================================================================}
function TRange.Omits(const val: Integer): Boolean;
begin
  Result := not ((Self.start = val) or (Self.stop = val));
end;
{$ENDIF}