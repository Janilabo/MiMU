{$IFDEF HELPERS}
function AsPiles(const oAscending: Boolean = True): M2DArray; overload;
function Piles(const oAscending: Boolean = True): M2DArray; overload;
function ToPiles(const oAscending: Boolean = True): M2DArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsPiles>
  @action: Splits the array into a 2D array (piles) of ordered subsequences, greedily grouped into non-decreasing or non-increasing order.
  @note: In each pass, it forms a pile by scanning left-to-right and extracting elements that maintain the chosen sorting order (based on oAscending).
         Skipped elements are pushed to the next pass. The worst-case time complexity is O(N^2) if the array is perfectly reversed relative to the desired order.
[==============================================================================}
function MArrayHelper.AsPiles(const oAscending: Boolean = True): M2DArray; overload;
var
  h, i, j, l, g, r, k: Integer;
  s: TIntegerArray;
begin
  l := Self.Length;
  if (l < 2) then
    Exit([Self.Cloned]);
  SetLength(Result, l);
  s := Self.Indexes;
  r := 0;
  while (l > 0) do
  begin
    SetLength(Result[r], l);
    l := 0;
    h := -1;
    for i := 0 to High(Result[r]) do
      if ((h = -1) or ((oAscending and (Self[s[i]] >= Result[r][h])) or ((not oAscending) and (Self[s[i]] <= Result[r][h])))) then
        Result[r][h.Increment] := Self[s[i]]
      else
        s[l.Increase] := s[i];
    SetLength(Result[r.Increase], (h + 1));
  end;
  SetLength(Result, r);
end;

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
