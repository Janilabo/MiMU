{$IFDEF HELPERS}
function BMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
function BMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryCombine(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryCombined(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BMerge>
  @action: Combines two sorted integer arrays (Self and items) into a new sorted array based on the specified order.
  @note: Assumes both Self and items are sorted in the same order (ascending if aAscending is True, descending otherwise).
[==============================================================================}
function TIntegerArrayHelper.BMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
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
    Move(Self[s.start], Result[l.Increase(s.Delta)], (s.Delta * SizeOf(Integer)));
  if (i.start < i.stop) then
    Move(items[i.start], Result[l], (i.Delta * SizeOf(Integer)));
end;

{==============================================================================]
  <BMerged>
  @action: Combines two sorted integer arrays (Self and items) into a new sorted array based on the specified order.
  @note: Assumes both Self and items are sorted in the same order (ascending if aAscending is True, descending otherwise).
[==============================================================================}
function TIntegerArrayHelper.BMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
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
    Move(Self[s.start], Result[l.Increase(s.Delta)], (s.Delta * SizeOf(Integer)));
  if (i.start < i.stop) then
    Move(items[i.start], Result[l], (i.Delta * SizeOf(Integer)));
end;

{==============================================================================]
  <BinaryMerge>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryMerge(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
var
  l: Integer;
  s, i: TRange;
begin
  l := 0;
  s.Create(0, Self.Size);
  i.Create(0, items.Size);
  SetLength(Result, (s.stop + i.stop));
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
  while (s.start < s.stop) do
    Result[l.Increase] := Self[s.start.Increase];
  while (i.start < i.stop) do
    Result[l.Increase] := items[i.start.Increase];
end;

{==============================================================================]
  <BinaryMerged>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryMerged(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
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
  while (s.start < s.stop) do
    Result[l.Increase] := Self[s.start.Increase];
  while (i.start < i.stop) do
    Result[l.Increase] := items[i.start.Increase];
end;

{==============================================================================]
  <BinaryCombine>
  @action: Merges two sorted integer arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function TIntegerArrayHelper.BinaryCombine(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
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
    SetLength(Result, l.Count);
    for r := 0 to (l.Count - 1) do
      Result[r] := l[r];
  finally
    l.Free;
  end;
end;

{==============================================================================]
  <BinaryCombined>
  @action: Merge two sorted arrays into one sorted array.
  @note: Both arrays must be sorted in the same order (ascending or descending).
         The result is a new array that combines both inputs, preserving order.
         Complexity: O(n + m)
[==============================================================================}
function TIntegerArrayHelper.BinaryCombined(const items: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, j, k, s, o: Integer;
begin
  s := Self.Size;
  o := items.Size;
  SetLength(Result, (s + o));
  i := 0;
  j := 0;
  k := 0;
  while ((i < s) and (j < o)) do
    if ((aAscending and (Self[i] <= items[j])) or ((not aAscending) and (Self[i] >= items[j]))) then
      Result[k.Increase] := Self[i.Increase]
    else
      Result[k.Increase] := items[j.Increase];
  while (i < s) do
    Result[k.Increase] := Self[i.Increase];
  while (j < o) do
    Result[k.Increase] := items[j.Increase];
  if (k < Result.Size) then
    SetLength(Result, k);
end;
{$ENDIF}
