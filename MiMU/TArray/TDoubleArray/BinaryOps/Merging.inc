{$IFDEF HELPERS}
function BinaryMerge(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
function BinaryMerged(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
function BinaryCombine(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
function BinaryCombined(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function TDoubleArrayHelper.BinaryMerge(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
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

function TDoubleArrayHelper.BinaryMerged(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
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

function TDoubleArrayHelper.BinaryCombine(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
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
function TDoubleArrayHelper.BinaryCombined(const items: TDoubleArray; const aAscending: Boolean = True): TDoubleArray; overload;
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
