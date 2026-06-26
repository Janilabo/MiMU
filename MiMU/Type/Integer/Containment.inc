{$IFDEF HELPERS}
function Between(const aMin, aMax: Integer): Boolean; overload;
function Betweenish(const aMin, aMax: Integer): Boolean; overload;
function BoundedBy(const aMin, aMax: Integer): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Between>
  @action: Determines whether the integer falls inclusively between a min and max.
  @note: Fluent replacement for standard Delphi InRange function.
[==============================================================================}
function TIntegerHelper.Between(const aMin, aMax: Integer): Boolean; overload;
begin
  Result := not ((Self < aMin) or (Self > aMax));
end;

{==============================================================================]
  <Betweenish>
  @action: Determines whether the integer falls inclusively between a min and max.
  @note: Fluent replacement for standard Delphi InRange function.
[==============================================================================}
function TIntegerHelper.Betweenish(const aMin, aMax: Integer): Boolean; overload;
begin
  Result := ((Self >= aMin) and (Self <= aMax));
end;

{==============================================================================]
  <BoundedBy>
  @action: Determines whether the integer falls inclusively between a specified 
           minimum and maximum value.
  @note: Uses TIntegerHelper's internal Compare method to perform a safe 
         bounds check. Returns True if the value is equal to or greater than 
         aMin, and equal to or less than aMax.
[==============================================================================}
function TIntegerHelper.BoundedBy(const aMin, aMax: Integer): Boolean; overload;
begin
  Result := ((Self.Compare(aMin) >= 0) and (Self.Compare(aMax) <= 0));
end;
{$ENDIF}
