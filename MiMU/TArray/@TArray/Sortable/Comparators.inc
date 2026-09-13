{$IFDEF HELPERS}
function Precedes(const indexA, indexB: Integer; const oAscending: Boolean = True): Boolean; overload;
function Succeeds(const indexA, indexB: Integer; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Precedes>
  @action: Returns True if element at indexA should come BEFORE indexB.
  @note: Guarantees sort stability by preserving original relative order on equality.
[==============================================================================}
function MArrayHelper.Precedes(const indexA, indexB: Integer; const oAscending: Boolean = True): Boolean; overload;
begin
  if (Self[indexA] = Self[indexB]) then
    Result := (indexA < indexB)
  else if oAscending then
    Result := (Self[indexA] < Self[indexB])
  else
    Result := (Self[indexA] > Self[indexB]);
end;

{==============================================================================]
  <Succeeds>
  @action: Returns True if element at indexA should come AFTER indexB.
  @note: Inverse of Precedes; maintains consistent stability rules.
[==============================================================================}
function MArrayHelper.Succeeds(const indexA, indexB: Integer; const oAscending: Boolean = True): Boolean; overload;
begin
  if (Self[indexA] = Self[indexB]) then
    Result := (indexA > indexB)
  else if oAscending then
    Result := (Self[indexA] > Self[indexB])
  else
    Result := (Self[indexA] < Self[indexB]);
end;
{$ENDIF}
