{$IFDEF HELPERS}
function BinaryFusion(const items: MArray; const aAscending: Boolean = True): MArray; overload;
function BMerge(const items: MArray; const aAscending: Boolean = True): MArray; overload;
function BMerged(const items: MArray; const aAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryFusion>
  @action: Merges two sorted arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function MArrayHelper.BinaryFusion(const items: MArray; const aAscending: Boolean = True): MArray; overload;
var
  l: specialize TFPGList<MType>;
  r: Integer;
  s, i: TRange;
begin
  l := specialize TFPGList<MType>.Create;
  try
    i.Create(0, items.Size);
    s.Create(0, Self.Size);
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if ((aAscending and (Self[s.start] <= items[i.start])) or ((not aAscending) and (Self[s.start] >= items[i.start]))) then
        l.Add(Self[s.start.Increase])
      else
        l.Add(items[i.start.Increase]);
    while (s.start < s.stop) do
      l.Add(Self[s.start.Increase]);
    while (i.start < i.stop) do
      l.Add(items[i.start.Increase]);
    for r := 0 to Result.Alloc(l.Count) do
      Result[r] := l[r];
  finally
    l.Free;
  end;
end;

{==============================================================================]
  <BMerge>
  @action: Combines two sorted arrays (Self and items) into a new sorted array based on the specified order.
  @note: Assumes both Self and items are sorted in the same order (ascending if aAscending is True, descending otherwise).
[==============================================================================}
function MArrayHelper.BMerge(const items: MArray; const aAscending: Boolean = True): MArray; overload;
var
  l: Integer;
  s, i: TRange;
begin
  l := 0;
  i.Create(0, items.Size);
  s.Create(0, Self.Size);
  SetLength(Result, (i.stop + s.stop));
  case aAscending of
    True:
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if (Self[s.start] <= items[i.start]) then
        Result[l.Increase] := Self[s.start.Increase]
      else
        Result[l.Increase] := items[i.start.Increase];
    False:
    while ((s.start < s.stop) and (i.start < i.stop)) do
      if (Self[s.start] >= items[i.start]) then
        Result[l.Increase] := Self[s.start.Increase]
      else
        Result[l.Increase] := items[i.start.Increase];
  end;
  if (s.start < s.stop) then
    Move(Self[s.start], Result[l.Increase(s.Delta)], (s.Delta * SizeOf(MType)));
  if (i.start < i.stop) then
    Move(items[i.start], Result[l], (i.Delta * SizeOf(MType)));
end;

{==============================================================================]
  <BMerged>
  @action: Combines two sorted arrays (Self and items) into a new sorted array based on the specified order.
  @note: Assumes both Self and items are sorted in the same order (ascending if aAscending is True, descending otherwise).
[==============================================================================}
function MArrayHelper.BMerged(const items: MArray; const aAscending: Boolean = True): MArray; overload;
var
  l: Integer;
  s, i: TRange;
begin
  l := 0;
  s.Create(0, Self.Size);
  i.Create(0, items.Size);
  SetLength(Result, (s.stop + i.stop));
  while ((s.start < s.stop) and (i.start < i.stop)) do
    if Self[s.start].Precede(items[i.start], aAscending) then
      Result[l.Increase] := Self[s.start.Increase]
    else
      Result[l.Increase] := items[i.start.Increase];
  if (s.start < s.stop) then
    Move(Self[s.start], Result[l.Increase(s.Delta)], (s.Delta * SizeOf(MType)));
  if (i.start < i.stop) then
    Move(items[i.start], Result[l], (i.Delta * SizeOf(MType)));
end;
{$ENDIF}
