{$IFDEF HELPERS}
function Blank: Boolean; overload;
function Empty: Boolean; overload;
function Irregular: Boolean; overload;
function Jagged: Boolean; overload;
function Ragged: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Blank>
  @action: Returns true if array is blank (no inventory, only empty indexes of []).
  @note: Blank array could be for example [[], [], []]. Returns false if array contains any items.
         NOTE: Returns false if array is empty (1D Length = 0)!
[==============================================================================}
function M2DArrayHelper.Blank: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if Self[i].Populated then
      Exit(False);
  Result := (Self.Length > 0);
end;

{==============================================================================]
  <Empty>
  @action: Returns true if array is empty (Length = 0).
  @note: None.
[==============================================================================}
function M2DArrayHelper.Empty: Boolean; overload;
begin
  Result := (Self.Length = 0);
end;

{==============================================================================]
  <Irregular>
  @action: Returns true if array contains arrays with different lengths (array not symmetrict)
  @note: [[1,2],[3,4],[5,6]] = False | [[1,2],[3],[4,5,6]] = True
[==============================================================================}
function M2DArrayHelper.Irregular: Boolean; overload;
var
  i, a, l, h: Integer;
begin
  if Self.Empty then
    Exit(False);
  l := Self[0].Length;
  h := l;
  for i := 1 to High(Self) do
  begin
    a := Self[i].Length;
    if (a < l) then
      l := a
	else if (a > h) then
      h := a;
    if (l <> h) then
      Exit(True);
  end;
  Result := False;
end;

{==============================================================================]
  <Jagged>
  @action: Returns true if array contains arrays with different lengths (array not symmetrict)
  @note: [[1,2],[3,4],[5,6]] = False | [[1,2],[3],[4,5,6]] = True
[==============================================================================}
function M2DArrayHelper.Jagged: Boolean; overload;
var
  i, l: Integer;
begin
  if (Self.Length > 0) then
    l := Self[0].Length;
  for i := 1 to High(Self) do
    if (Self[i].Length <> l) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Ragged>
  @action: Returns true if array contains arrays with different lengths (array not symmetrict)
  @note: [[1,2],[3,4],[5,6]] = False | [[1,2],[3],[4,5,6]] = True
[==============================================================================}
function M2DArrayHelper.Ragged: Boolean; overload;
var
  i: Integer;
  h: specialize THashSet<Integer>;
begin
  h := specialize THashSet<Integer>.Create;
  try
    for i := 0 to High(Self) do
      if (h.Count < 2) then
        h.Add(Self[i].Size)
      else
        Exit(True);
  finally
    h.Free;
  end;
  Result := False;
end;
{$ENDIF}