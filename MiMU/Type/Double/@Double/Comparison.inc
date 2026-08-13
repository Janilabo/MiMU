{$IFDEF HELPERS}
function Over(const target: Double): Boolean;
function Oversize(const limit: Double): Boolean;
function Precede(const target: Double; const aAscending: Boolean): Boolean; overload;
function Under(const target: Double): Boolean;
function Undersize(const limit: Double): Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Over>
  @action: Returns true if x is higher than target.
  @note: None
[==============================================================================}
function TDoubleHelper.Over(const target: Double): Boolean;
begin
  Result := not (target <= Self);
end;

{==============================================================================]
  <Oversize>
  @action: Returns true if x is higher than limit.
  @note: None
[==============================================================================}
function TDoubleHelper.Oversize(const limit: Double): Boolean;
begin
  Result := (Self > limit);
end;

{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TDoubleHelper.Precede(const target: Double; const aAscending: Boolean): Boolean; overload;
begin
  Result := ((aAscending and (Self <= target)) or ((not aAscending) and (Self >= target)));
end;

{==============================================================================]
  <Under>
  @action: Returns true if x is lower than target.
  @note: None
[==============================================================================}
function TDoubleHelper.Under(const target: Double): Boolean;
begin
  Result := not (target >= Self);
end;

{==============================================================================]
  <Undersize>
  @action: Returns true if x is lower than limit.
  @note: None
[==============================================================================}
function TDoubleHelper.Undersize(const limit: Double): Boolean;
begin
  Result := (Self < limit);
end;
{$ENDIF}
