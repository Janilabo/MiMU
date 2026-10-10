{$IFDEF HELPERS}
function Polarize(const oAscending: Boolean = True): Integer; overload;
function Polarized(const oAscending: Boolean = True): TBooleanArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Polarize>
  @action: In-place O(N) linear partition of a boolean array using opposing two-pointer swaps.
  @note: Destructive function. Mutates Self directly with O(1) extra space.
[==============================================================================}
function TBooleanArrayHelper.Polarize(const oAscending: Boolean = True): Integer; overload;
var
  l, r: Integer;
begin
  Result := Self.Length;
  if (Result < 2) then
    Exit;
  l := 0;
  r := (Result - 1);
  case oAscending of
    True:
    while (l < r) do
    begin
      while ((l < r) and (not Self[l])) do
        Inc(l);
      while ((l < r) and Self[r]) do
        Dec(r);
      if (l < r) then
        Self.Switch(l.Increase, r.Decrease);
    end;
    False:
    while (l < r) do
    begin
      while ((l < r) and Self[l]) do
        Inc(l);
      while ((l < r) and (not Self[r])) do
        Dec(r);
      if (l < r) then
        Self.Switch(l.Increase, r.Decrease);
    end;
  end;
end;

{==============================================================================]
  <Polarized>
  @action: Returns a sorted copy of a boolean array in O(N) linear time using a dual-pointer partition sweep.
  @note: Non-destructive function. Automatically separates False and True values into ordered bounds in a single pass.
[==============================================================================}
function TBooleanArrayHelper.Polarized(const oAscending: Boolean = True): TBooleanArray; overload;
var
  i, s, l, r: Integer;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([])
  else if (s = 1) then
	Exit([Self[0]]);
  l := 0;
  r := High(Self);
  case oAscending of
    True:
    for i := 0 to Result.Alloc(s) do
      if Self[i] then
        Result[r.Decrease] := Self[i]
      else
        Result[l.Increase] := Self[i];
    False:
    for i := 0 to Result.Alloc(s) do
      if Self[i] then
        Result[l.Increase] := Self[i]
      else
        Result[r.Decrease] := Self[i];
  end;
end;
{$ENDIF}
