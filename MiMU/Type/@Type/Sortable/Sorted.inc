{$IFDEF FUNCTIONS}
function InAscending3(const A, B, C: MType; const strictly: Boolean = False): Boolean; overload;
function InDescending3(const A, B, C: MType; const strictly: Boolean = False): Boolean; overload;
function InOrder3(const A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
function IsAscending3(const A, B, C: MType; const strictly: Boolean = False): Boolean; overload;
function IsDescending3(const A, B, C: MType; const strictly: Boolean = False): Boolean; overload;
function IsMonotonic3(const A, B, C: MType): Boolean; overload;
function IsSorted3(const A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
function IsStrictlyMonotonic3(const A, B, C: MType): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <InAscending3>
  @action: Determines whether three items are arranged in ascending order.
  @note: If strictly is True, it evaluates for a strict increase (A < B < C).
         If strictly is False (default), it allows equal values (A <= B <= C).
[==============================================================================}
function InAscending3(const A, B, C: MType; const strictly: Boolean = False): Boolean; overload;
begin
  if strictly then
    Exit((A < B) and (B < C));
  Result := ((A <= B) and (B <= C));
end;

{==============================================================================]
  <InDescending3>
  @action: Determines whether three items are arranged in descending order.
  @note: If strictly is True, it evaluates for a strict decrease (A > B > C).
         If strictly is False (default), it allows equal values (A >= B >= C).
[==============================================================================}
function InDescending3(const A, B, C: MType; const strictly: Boolean = False): Boolean; overload;
begin
  if strictly then
    Exit((A > B) and (B > C));
  Result := ((A >= B) and (B >= C));
end;

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
  <IsAscending3>
  @action: Determines whether three items are arranged in ascending order using negated logical checks.
  @note: Uses De Morgan's laws to verify ascending order.
         If strictly is True, it ensures neither A >= B nor B >= C is true (equivalent to A < B < C).
         If strictly is False (default), it ensures neither A > B nor B > C is true (equivalent to A <= B <= C).
[==============================================================================}
function IsAscending3(const A, B, C: MType; const strictly: Boolean = False): Boolean; overload;
begin
  if strictly then
    Exit(not ((A >= B) or (B >= C)));
  Result := not ((A > B) or (B > C));
end;

{==============================================================================]
  <IsDescending3>
  @action: Determines whether three items are arranged in descending order using negated logical checks.
  @note: Uses De Morgan's laws to verify descending order.
         If strictly is True, it ensures neither A <= B nor B <= C is true (equivalent to A > B > C).
         If strictly is False (default), it ensures neither A < B nor B < C is true (equivalent to A >= B >= C).
[==============================================================================}
function IsDescending3(const A, B, C: MType; const strictly: Boolean = False): Boolean; overload;
begin
  if strictly then
    Exit(not ((A <= B) or (B <= C)));
  Result := not ((A < B) or (B < C));
end;

{==============================================================================]
  <IsMonotonic3>
  @action: Checks if the sequence of three values (A, B, C) is monotonic.
  @note: Returns True if the values are entirely non-decreasing (A <= B <= C) or entirely non-increasing (A >= B >= C). Platonic plateaus (equal adjacent values) are allowed.
[==============================================================================}
function IsMonotonic3(const A, B, C: MType): Boolean; overload;
begin
  Result := ((A <= B) and (B <= C)) or ((A >= B) and (B >= C));
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

{==============================================================================]
  <IsStrictlyMonotonic3>
  @action: Checks if the sequence of three values (A, B, C) is strictly monotonic.
  @note: Returns True if the values are strictly increasing (A < B < C) or strictly decreasing (A > B > C). Flat plateaus or equal adjacent values will cause this to return False.
[==============================================================================}
function IsStrictlyMonotonic3(const A, B, C: MType): Boolean; overload;
begin
  Result := ((A < B) and (B < C)) or ((A > B) and (B > C));
end;
{$ENDIF}
