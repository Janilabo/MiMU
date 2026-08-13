{$IFDEF HELPERS}
function Over(const target: Int64): Boolean;
function Oversize(const limit: Int64): Boolean;
function Precede(const target: Int64; const aAscending: Boolean): Boolean; overload;
function Under(const target: Int64): Boolean;
function Undersize(const limit: Int64): Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Over>
  @action: Returns true if x is higher than target.
  @note: None
[==============================================================================}
function TInt64Helper.Over(const target: Int64): Boolean;
begin
  Result := not (target <= Self);
end;

{==============================================================================]
  <Oversize>
  @action: Returns true if x is higher than limit.
  @note: None
[==============================================================================}
function TInt64Helper.Oversize(const limit: Int64): Boolean;
begin
  Result := (Self > limit);
end;

{==============================================================================]
  <Precede>
  @action: Determines whether the current item should precede or equal the target item in a sorted sequence based on the specified order.
  @note: Returns True if Self <= target for ascending order or Self >= target for descending order. Useful for sorting or merging operations.
[==============================================================================}
function TInt64Helper.Precede(const target: Int64; const aAscending: Boolean): Boolean; overload;
begin
  Result := ((aAscending and (Self <= target)) or ((not aAscending) and (Self >= target)));
end;

{==============================================================================]
  <Under>
  @action: Returns true if x is lower than target.
  @note: None
[==============================================================================}
function TInt64Helper.Under(const target: Int64): Boolean;
begin
  Result := not (target >= Self);
end;

{==============================================================================]
  <Undersize>
  @action: Returns true if x is lower than limit.
  @note: None
[==============================================================================}
function TInt64Helper.Undersize(const limit: Int64): Boolean;
begin
  Result := (Self < limit);
end;
{$ENDIF}