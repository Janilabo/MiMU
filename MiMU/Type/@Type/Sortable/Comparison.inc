{$IFDEF HELPERS}
function Battle(const target: MType; const oAscending: Boolean = True): Integer; overload;
function Compete(const target: MType; const oAscending: Boolean = True): Integer; overload;
function Contest(const target: MType; const oAscending: Boolean = True): Integer; overload;
function Clash(const target: MType; const oAscending: Boolean = True): Integer; overload;
function Duel(const target: MType; const oAscending: Boolean = True): Integer; overload;
function Trial(const target: MType; const oAscending: Boolean = True): Integer; overload;
function Versus(const target: MType; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Battle>
  @action: Compares Self against target, honoring sort direction.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if equal.
         When oAscending is False, the comparison sign is inverted.
[==============================================================================}
function MTypeHelper.Battle(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if (Self = target) then
    Result := 0
  else if oAscending then
    Result := IfThen((Self > target), 1, -1)
  else
    Result := IfThen((Self > target), -1, 1);
end;

{==============================================================================]
  <Clash>
  @action: Compares Self against target, honoring sort direction.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if equal.
         When oAscending is False, the comparison sign is inverted.
[==============================================================================}
function MTypeHelper.Clash(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if (Self = target) then
    Result := 0
  else if (Self > target) then
    Result := ((Ord(oAscending) * 2) - 1)
  else
    Result := -((Ord(oAscending) * 2) - 1);
end;

{==============================================================================]
  <Compete>
  @action: Compares Self against target, honoring sort direction.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if equal.
         When oAscending is False, the comparison sign is inverted.
[==============================================================================}
function MTypeHelper.Compete(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := (oAscending.Sign * Self.Compare(target));
end;

{==============================================================================]
  <Contest>
  @action: Compares Self against target, honoring sort direction.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if equal.
         When oAscending is False, the comparison sign is inverted.
[==============================================================================}
function MTypeHelper.Contest(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if (Self = target) then
    Exit(0);
  if oAscending then
    if (Self > target) then
	  Exit(1)
	else
      Exit(-1);
  if (Self < target) then
    Exit(1);
  Result := -1;
end;

{==============================================================================]
  <Duel>
  @action: Compares two items honoring sort direction.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if both items are equal.
         When oAscending is False, the comparison sign is inverted.
[==============================================================================}
function MTypeHelper.Duel(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  Result := (Ord(Self > target) - Ord(Self < target));
  if not oAscending then
    Result := -Result;
end;

{==============================================================================]
  <Trial>
  @action: Compares Self against target, honoring sort direction.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if equal.
         When oAscending is False, the comparison sign is inverted.
[==============================================================================}
function MTypeHelper.Trial(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if (Self = target) then
    Exit(0);
  if ((oAscending and (Self > target)) or ((not oAscending) and (Self < target))) then
    Exit(1);
  Result := -1;
end;

{==============================================================================]
  <Versus>
  @action: Compares Self against target, honoring sort direction.
  @note: Returns -1 if Self < target, 1 if Self > target, and 0 if equal.
         When oAscending is False, the comparison sign is inverted.
[==============================================================================}
function MTypeHelper.Versus(const target: MType; const oAscending: Boolean = True): Integer; overload;
begin
  if (Self = target) then
    Result := 0
  else if ((Self > target) xor (not oAscending)) then
    Result := 1
  else
    Result := -1;
end;
{$ENDIF}
