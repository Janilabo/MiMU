{$IFDEF HELPERS}
function SpaceAround(const margin: Integer): TRangeArray; overload;
{$ENDIF}

{$IFDEF METHODS}
function Vacuum(const target: TRange): TRange; overload;
function Void(const target: TRange): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <SpaceAround>
  @action: Generates two ranges representing the "padding" or "margins" 
           immediately outside the current range boundaries.
  @note: 
    - Result[0] is the "Lead" space (before start).
    - Result[1] is the "Trail" space (after stop).
    - Orientation: Both generated ranges inherit Self's Ascending/Descending 
      direction.
[==============================================================================}
function TRangeHelper.SpaceAround(const margin: Integer): TRangeArray; overload;
var
  o: Integer;
begin
  o := IfThen(Self.Ascending, 1, -1);
  Result := [TRange.Construct((Self.start - (o * margin)), (Self.start - o)), TRange.Construct((Self.stop + o), (Self.stop + (o * margin)))];
end;

{==============================================================================]
  <Vacuum>
  @action: Returns the TRange representing the empty "suction" space between 
           Self and a target range.
  @note: 
    - Logical Flow: The result starts at Self's boundary and ends at Target's 
      boundary.
    - Result: Returns TRange.Null if the ranges overlap or are touching, 
      as no vacuum exists between them.
[==============================================================================}
function TRange.Vacuum(const target: TRange): TRange; overload;
begin
  if Self.Under(target) then
    Result := TRange.Construct((Self.Maximum + 1), (target.Minimum - 1))
  else if Self.Over(target) then
    Result := TRange.Construct((Self.Minimum - 1), (target.Maximum + 1))
  else
    Result := TRange.Null;
end;

{==============================================================================]
  <Void>
  @action: Identifies the gap between Self and a target range.
  @note: 
    - Directional: The resulting range always starts at the edge of Self 
      and ends at the edge of the Target.
    - If the ranges touch or overlap, TRange.Null is returned.
[==============================================================================}
function TRange.Void(const target: TRange): TRange; overload;
begin
  if (Self.Intersects(target) or Self.Abuts(target)) then
    Result := TRange.Null
  else if Self.Under(target) then
    Result := TRange.Construct((Self.Maximum + 1), (target.Minimum - 1))
  else
    Result := TRange.Construct((Self.Minimum - 1), (target.Maximum + 1));
end;
{$ENDIF}
