{$IFDEF HELPERS}
function PatienceSorted(const oAscending: Boolean = True): MArray; overload;
function PatiencySorted(const oAscending: Boolean = True): MArray; overload;
function PatientSorted(const oAscending: Boolean = True): MArray; overload;

function PatienceSortition(const oAscending: Boolean = True): T2DIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <PatienceSorted>
  @action: Returns a sorted copy using LIFO stack-draining (pops elements from the top/tail of piles backward).
  @note: Drains index piles from High to Low into the output array in reverse order; supports ascending/descending order.
[==============================================================================}
function MArrayHelper.PatienceSorted(const oAscending: Boolean = True): MArray; overload;
var
  s: T2DIntegerArray;
  i, j, l, g, b: Integer;
  f: Boolean;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Copy);
  SetLength(s, l);
  s[0] := [0];
  g := 0;
  for i := 1 to (l - 1) do
  begin
    f := False;
    for j := 0 to g do
      if ((oAscending and (Self[i] >= Self[s[j][High(s[j])]]) or ((not oAscending) and (Self[i] <= Self[s[j][High(s[j])]])))) then
      begin
        f := True;
		s[j].Supply(i);
        Break;
      end;
    if not f then
      s[g.Increment] := [i];
  end;
  for i := Result.Alloc(l) downto 0 do
  begin
    b := -1;
    for j := g downto 0 do
      if (s[j].Length > 0) then
        if ((b = -1) or (oAscending and (Self[s[j][High(s[j])]] >= Self[s[b][High(s[b])]])) or ((not oAscending) and (Self[s[j][High(s[j])]] <= Self[s[b][High(s[b])]]))) then
          b := j;
    Result[i] := Self[s[b][High(s[b])]];
    SetLength(s[b], (s[b].Length - 1));
  end;
end;

{==============================================================================]
  <PatiencySorted>
  @action: Returns a sorted copy using forward cursor tracking across piles (zero-allocation merge).
  @note: Uses a parallel cursor array `c` to iterate forward through piles without array reallocations or `Delete` calls.
[==============================================================================}
function MArrayHelper.PatiencySorted(const oAscending: Boolean = True): MArray; overload;
var
  s: T2DIntegerArray;
  c: TIntegerArray;
  i, j, l, g, b: Integer;
  f: Boolean;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Cloned);
  SetLength(s, l);
  s[0] := [0];
  g := 0;
  for i := 1 to (l - 1) do
  begin
    f := False;
    for j := 0 to g do
      if ((oAscending and (Self[i] >= Self[s[j][High(s[j])]]) or ((not oAscending) and (Self[i] <= Self[s[j][High(s[j])]])))) then
      begin
        f := True;
		s[j].Supply(i);
        Break;
      end;
    if not f then
      s[g.Increment] := [i];
  end;
  SetLength(c, (g + 1));
  for i := 0 to Result.Alloc(l) do
  begin
    b := -1;
    for j := 0 to g do
      if (c[j] < s[j].Length) then
        if ((b = -1) or (oAscending and (Self[s[j][c[j]]] < Self[s[b][c[b]]])) or ((not oAscending) and (Self[s[j][c[j]]] > Self[s[b][c[b]]]))) then
          b := j;
    Result[i] := Self[s[b][c[b].Increase]];
  end;
end;

{==============================================================================]
  <PatientSorted>
  @action: Returns a sorted copy using FIFO queue-draining (shifts elements from the head/front of piles).
  @note: Extracts the minimum/maximum candidate from pile heads and mutates piles via `System.Delete`.
[==============================================================================}
function MArrayHelper.PatientSorted(const oAscending: Boolean = True): MArray; overload;
var
  s: T2DIntegerArray;
  i, j, l, g, b: Integer;
  f: Boolean;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Copy);
  SetLength(s, l);
  s[0] := [0];
  g := 0;
  for i := 1 to (l - 1) do
  begin
    f := False;
    for j := 0 to g do
      if ((oAscending and (Self[i] >= Self[s[j][High(s[j])]]) or ((not oAscending) and (Self[i] <= Self[s[j][High(s[j])]])))) then
      begin
        f := True;
		s[j].Supply(i);
        Break;
      end;
    if not f then
      s[g.Increment] := [i];
  end;
  for i := 0 to Result.Alloc(l) do
  begin
    b := -1;
    for j := 0 to g do
      if (s[j].Length > 0) then
        if ((b = -1) or (oAscending and (Self[s[j][0]] < Self[s[b][0]])) or ((not oAscending) and (Self[s[j][0]] > Self[s[b][0]]))) then
          b := j;
    Result[i] := Self[s[b][0]];
    System.Delete(s[b], 0, 1);
  end;
end;

{==============================================================================]
  <PatienceSortition>
  @action: Partitions the array element indices into sorted piles based on patience sorting rules.
  @note: Returns a 2D array of integer indices (T2DIntegerArray) matching each pile's elements. Operates in O(n * k) time via sequential pile scanning.
[==============================================================================}
function MArrayHelper.PatienceSortition(const oAscending: Boolean = True): T2DIntegerArray; overload;
var
  i, j, l, g: Integer;
  f: Boolean;
begin
  l := Self.Length;
  if (l < 2) then
    Exit([[0]]);
  SetLength(Result, l);
  Result[0] := [0];
  g := 0;
  for i := 1 to (l - 1) do
  begin
    f := False;
    for j := 0 to g do
      if ((oAscending and (Self[i] >= Self[Result[j][High(Result[j])]])) or ((not oAscending) and (Self[i] <= Self[Result[j][High(Result[j])]]))) then
      begin
        f := True;
        Result[j].Supply(i);
        Break;
      end;
    if not f then
      Result[g.Increment] := [i];
  end;
  SetLength(Result, (g + 1));
end;
{$ENDIF}