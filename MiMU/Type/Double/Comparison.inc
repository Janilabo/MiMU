{$IFDEF HELPERS}
function Ascending(const target: Double): Boolean; inline;
function Cmpr(const target: Double): Integer;
function Compare(const target: Double): Integer; inline;
function Compared(const target: Double; const oAscending: Boolean = True): Integer;
function CompareTo(const target: Double; const oAscending: Boolean = True): Integer;
function CompareWith(const target: Double; const oAscending: Boolean = True): Integer;
function Descending(const target: Double): Boolean; inline;
function Over(const target: Double): Boolean; inline;
function Oversize(const limit: Double): Boolean;
function Precede(const target: Double; const aAscending: Boolean): Boolean; overload;
function Sign(const target: Double = 0): Integer; inline;
function Under(const target: Double): Boolean; inline;
function Undersize(const limit: Double): Boolean;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Comparison(const A, B: Double): Integer; overload; 
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascending>
  @action  Returns True if the helper’s value is less than or equal to         
           the given target value. Useful as a comparison predicate when        
           sorting or merging arrays in ascending order.
  @note: This method does not modify either value; it simply performs a <= comparison.
[==============================================================================}
function TDoubleHelper.Ascending(const target: Double): Boolean; inline;
begin
  Result := (Self <= target);
end;

{==============================================================================]
  <Cmpr>
  @action: Compares x with target target.
           Results: 0=EQUAL, 1=x>target, -1=x<target
  @note: None
[==============================================================================}
function TDoubleHelper.Cmpr(const target: Double): Integer; inline;
begin
  Result := (Ord(Self > target) - Ord(Self < target));
end;

{==============================================================================]
  <Compare>
  @action: Compares x with target target.
           Results: 0=EQUAL, 1=x>target, -1=x<target
  @note: None
[==============================================================================}
function TDoubleHelper.Compare(const target: Double): Integer; inline;
begin
  if (Self = target) then
    Exit(0);
  if (Self > target) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
  <Compared>
  @action: Compares x with target value.
           Results: 0=EQUAL
  @note: Supports ascending/descending
[==============================================================================}
function TDoubleHelper.Compared(const target: Double; const oAscending: Boolean = True): Integer;
begin
  Result := (Ord(Self > target) - Ord(Self < target));
  if not oAscending then
    Result := -Result;
end;

{==============================================================================]
  <CompareTo>
  @action: Compares x with target value.
           Results: 0=EQUAL
  @note: Supports ascending/descending
[==============================================================================}
function TDoubleHelper.CompareTo(const target: Double; const oAscending: Boolean = True): Integer;
begin
  if (Self = target) then
    Exit(0);
  if oAscending then
    Result := ((Ord(Self > target) * 2) - 1)
  else
    Result := ((Ord(target > Self) * 2) - 1);
end;

{==============================================================================]
  <CompareWith>
  @action: Compares x with target value.
           Results: 0=EQUAL
  @note: Supports ascending/descending
[==============================================================================}
function TDoubleHelper.CompareWith(const target: Double; const oAscending: Boolean = True): Integer;
begin
  if (Self = target) then
    Exit(0);
  if oAscending then
    Result := IfThen((Self > target), 1, -1)
  else
    Result := IfThen((target > Self), 1, -1);
end;

{==============================================================================]
  <Descending>
  @action: Returns True if the helper’s value is greater than or equal to
           the given target value. Use as a comparison predicate when
           sorting or merging arrays in descending order.
  @note: Pure comparison only; equivalent to Self >= target.
[==============================================================================}
function TDoubleHelper.Descending(const target: Double): Boolean; inline;
begin
  Result := (Self >= target);
end;

{==============================================================================]
  <Over>
  @action: Returns true if x is higher than target.
  @note: None
[==============================================================================}
function TDoubleHelper.Over(const target: Double): Boolean; inline;
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
function TDoubleHelper.Sign(const target: Double = 0): Integer; inline;
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
function TDoubleHelper.Under(const target: Double): Boolean; inline;
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

function Comparison(const A, B: Double): Integer; overload;
begin
  if (A < B) then
    Exit(-1);
  if (A > B) then
    Exit(1);
  Result := 0;
end;
{$ENDIF}