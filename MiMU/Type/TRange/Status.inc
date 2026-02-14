{$IFDEF METHODS}
function Ahead(const val: Integer): Boolean; overload;
function Behind(const val: Integer): Boolean; overload;
function Precedes(const val: Integer): Boolean; overload;
function Succeeds(const val: Integer): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ahead>
  @action: Returns True if the given value is **beyond the end of the interval**.
           Works correctly for ascending or descending ranges.
  @note: Equivalent to checking if the value lies strictly after Self.Stop
         in the range’s directional sense.
[==============================================================================}
function TRange.Ahead(const val: Integer): Boolean; overload;
begin
  Result := ((Self.Ascending and (val > Self.stop)) or (Self.Descending and (val < Self.stop)));
end;

{==============================================================================]
  <Behind>
  @action: Returns True if the given value is **before the start of the interval**.
           Works correctly for ascending or descending ranges.
  @note: Equivalent to checking if the value lies strictly before Self.Start
         in the range’s directional sense.
[==============================================================================}
function TRange.Behind(const val: Integer): Boolean; overload;
begin
  Result := ((Self.Ascending and (val < Self.start)) or (Self.Descending and (val > Self.start)));
end;

{==============================================================================]
  <Precedes>
  @action: Returns True if the given value is **before the origin/start** 
           in the direction of travel.
  @note: Logical complement of Succeeds. Tests only start-relative half-line.
[==============================================================================}
function TRange.Precedes(const val: Integer): Boolean; overload;
begin
  Result := not Self.Succeeds(val);
end;

{==============================================================================]
  <Succeeds>
  @action: Returns True if the given value is **at or beyond the origin/start**
           in the direction of travel.
  @note: Start-relative predicate. Works for ascending or descending ranges.
         Logical complement of Precedes.
[==============================================================================}
function TRange.Succeeds(const val: Integer): Boolean; overload;
begin
  Result := (Self.Singular or (Self.Ascending and (val >= Self.start)) or (Self.Descending and (val <= Self.start)));
end;
{$ENDIF}