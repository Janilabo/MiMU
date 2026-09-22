{$IFDEF HELPERS}
function Piles(const oAscending: Boolean = True): M2DArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Piles>
  @action: Partitions the array into non-decreasing (or non-increasing) 2D element piles based on Patience Sorting distribution logic.
  @note: Directly stores array values (rather than indices) in sub-arrays; automatically trims unused tail allocations before returning.
[==============================================================================}
function MArrayHelper.Piles(const oAscending: Boolean = True): M2DArray; overload;
var
  i, j, l, g: Integer;
  f: Boolean;
begin
  l := Self.Length;
  if (l < 2) then
    Exit([Self.Cloned]);
  SetLength(Result, l);
  Result[0] := [Self[0]];
  g := 0;
  for i := 1 to (l - 1) do
  begin
    f := False;
    for j := 0 to g do
      if ((oAscending and (Self[i] >= Result[j][High(Result[j])])) or ((not oAscending) and (Self[i] <= Result[j][High(Result[j])]))) then
      begin
        f := True;
		Result[j].Supply(Self[i]);
        Break;
      end;
    if not f then
      Result[g.Increment] := [Self[i]];
  end;
  SetLength(Result, (g + 1));
end;
{$ENDIF}
