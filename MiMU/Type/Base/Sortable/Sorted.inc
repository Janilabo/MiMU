{$IFDEF FUNCTIONS}
function InOrder3(const A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
function IsSorted3(const A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <InOrder3>
  @action: Determines whether three values are arranged in a specific sorted order.
  @note: Evaluates if A <= B <= C (when oAscending is True) or A >= B >= C (when oAscending is False).
[==============================================================================}
function InOrder3(const A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((oAscending and ((A <= B) and (B <= C))) or ((not oAscending) and ((A >= B) and (B >= C))));
end;

{==============================================================================]
  <IsSorted3>
  @action: Determines whether three values are sorted by using negated logical checks.
  @note: Uses De Morgan's laws to verify sorting. 
         If oAscending is True, it ensures neither A > B nor B > C is true (equivalent to A <= B <= C).
         If oAscending is False, it ensures neither A < B nor B < C is true (equivalent to A >= B >= C).
[==============================================================================}
function IsSorted3(const A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
begin
  if oAscending then
    Result := not ((A > B) or (B > C))
  else
    Result := not ((A < B) or (B < C));
end;
{$ENDIF}
