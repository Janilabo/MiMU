{$IFDEF HELPERS}
function Piles(const oAscending: Boolean = True): M2DArray; overload;
function ToPiles(const oAscending: Boolean = True): M2DArray; overload;
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

{==============================================================================]
  <ToPiles>
  @action: Partitions the array into non-increasing or non-decreasing runs via patience sorting and tracks subsequence tails to identify monotonic sequences.
  @note: Uses binary search in O(n log n) time to place elements into active sorted buckets/runs based on the specified sort order.
[==============================================================================}
function MArrayHelper.ToPiles(const oAscending: Boolean = True): M2DArray; overload;
var
  i, s, g, l, h, m, p: Integer;
begin
  s := Self.Length;
  if (s < 2) then
    Exit([Self.Cloned]);
  SetLength(Result, (s + 1));
  Result[0] := [Self[0]];
  SetLength(Result[s], s);
  Result[s][0] := Self[0];
  g := 0;
  for i := 1 to (s - 1) do
  begin
    l := 0;
    h := g;
    p := (g + 1);
    while (l <= h) do
    begin
      m := ((l + h) div 2);
      if ((oAscending and (Self[i] >= Result[s][m])) or ((not oAscending) and (Self[i] <= Result[s][m]))) then
      begin
        p := m;
        h := (m - 1);
      end else
        l := (m + 1);
    end;
    if (p <= g) then
    begin
      Result[p].Supply(Self[i]);
      Result[s][p] := Self[i];
    end else
    begin
      Inc(g);
      Result[g] := [Self[i]];
      Result[s][g] := Self[i];
    end;
  end;
  SetLength(Result, (g + 1));
end;
{$ENDIF}
