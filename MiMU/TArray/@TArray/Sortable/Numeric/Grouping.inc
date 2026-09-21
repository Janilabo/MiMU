{$IFDEF HELPERS}
function Formation(const diff: MType; const oAscending: Boolean = True): M2DArray; overload;
function Muster(const diff: MType; const oAscending: Boolean = True): M2DArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Formation>
  @action: Groups elements into clusters based on whether their absolute difference from each group's baseline element is within a specified threshold (`diff`), after sorting the array.
  @note: Sorts the array via `ShellSorted` first, guaranteeing contiguous progression. Each new group measures candidates solely against the first element (`Result[r][0]`) of that active cluster.
         Truncates `Result` to the exact count of formed clusters.
[==============================================================================}
function MArrayHelper.Formation(const diff: MType; const oAscending: Boolean = True): M2DArray; overload;
var
  s: MArray;
  i, r, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  if (l = 1) then
  begin
    Result[0] := [Self[0]];
    Exit;
  end;
  s := Self.ShellSorted(oAscending);
  SetLength(Result, l);
  Result[0] := [s[0]];
  r := 0;
  for i := 1 to (l - 1) do
    if (Abs(s[i] - Result[r][0]) <= diff) then
      Result[r].Supply(s[i])
    else
      Result[r.Increment] := [s[i]];
  SetLength(Result, (r + 1));
end;

{==============================================================================]
  <Muster>
  @action: Groups elements into clusters based on proximity (`diff`) without sorting or modifying the original array order.
  @note: Iterates sequentially through elements and places each into the first existing group whose head element (`Result[s][0]`) satisfies `Abs(Self[i] - Head) <= diff`.
         Creates a new cluster if no matching group is found. Preserves insertion order relative to cluster heads.
[==============================================================================}
function MArrayHelper.Muster(const diff: MType; const oAscending: Boolean = True): M2DArray; overload;
var
  i, r, l, s: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  Result[0] := [Self[0]];
  if (l = 1) then
    Exit;
  r := 0;
  for i := 1 to (l - 1) do
  begin
    s := 0;
    while (s <= r) do
      if (Abs(Self[i] - Result[s][0]) <= diff) then
        Break
      else
        s := (s + 1);
    if (s > r) then
      r := s;
    Result[s].Supply(Self[i]);
  end;
  SetLength(Result, (r + 1));
end;
{$ENDIF}
