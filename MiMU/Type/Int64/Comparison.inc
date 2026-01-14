{$IFDEF HELPERS}
function Compare(const target: Int64): Integer;
function Over(const target: Int64): Boolean;
function Oversize(const limit: Int64): Boolean;
function Precede(const target: Int64; const aAscending: Boolean): Boolean; overload;
function Sign(const target: Int64 = 0): Integer;
function Under(const target: Int64): Boolean;
function Undersize(const limit: Int64): Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Compare>
  @action: Compares x with target target.
           Results: 0=EQUAL, 1=x>target, -1=x<target
  @note: None
[==============================================================================}
function TInt64Helper.Compare(const target: Int64): Integer;
begin
  if (Self = target) then
    Exit(0);
  if (Self > target) then
    Result := 1
  else
    Result := -1;
end;

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
  <Sign>
  @action: Compares the current double (Self) with a target double and returns
           a directional sign indicating whether the target is greater, equal,
           or smaller than Self.
  @note: Returns:
         1  if Self < target (target is larger → ascending)
         0  if Self = target (no change)
         -1  if Self > target (target is smaller → descending)
         Useful for detecting sequence direction, ordering, or range computation.
[==============================================================================}
function TInt64Helper.Sign(const target: Int64 = 0): Integer;
begin
  if (Self = target) then
    Result := 0
  else if (Self < target) then
    Result := 1
  else
    Result := -1;
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