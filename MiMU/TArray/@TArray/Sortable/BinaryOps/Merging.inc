{$IFDEF HELPERS}
function BinaryCombine(const items: MArray; const aAscending: Boolean = True): MArray; overload;
function BinaryCombined(const items: MArray; const aAscending: Boolean = True): MArray; overload;
function BinaryCompound(const items: MArray; const oAscending: Boolean = True): MArray; overload;
function BinaryMerge(const items: MArray; const aAscending: Boolean = True): MArray; overload;
function BinaryMerged(const items: MArray; const aAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryCombine>
  @action: Merges two sorted arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function MArrayHelper.BinaryCombine(const items: MArray; const aAscending: Boolean = True): MArray; overload;
var
  k: Integer;
  s, i: TRange;
begin
  s.Create(0, High(Self));
  i.Create(0, High(items));
  k := Result.SetSize(Self.Length + items.Length);
  while ((s.start <= s.stop) and (i.start <= i.stop)) do
    if ((aAscending and (Self[s.stop] >= items[i.stop])) or ((not aAscending) and (Self[s.stop] <= items[i.stop]))) then
      Result[k.Decrement] := Self[s.stop.Decrease]
    else
      Result[k.Decrement] := items[i.stop.Decrease];
  while (s.start <= s.stop) do
    Result[k.Decrement] := Self[s.stop.Decrease];
  while (i.start <= i.stop) do
    Result[k.Decrement] := items[i.stop.Decrease];
end;

{==============================================================================]
  <BinaryCombined>
  @action: Merge two sorted arrays into one sorted array.
  @note: Both arrays must be sorted in the same order (ascending or descending).
         The result is a new array that combines both inputs, preserving order.
         Complexity: O(n + m)
[==============================================================================}
function MArrayHelper.BinaryCombined(const items: MArray; const aAscending: Boolean = True): MArray; overload;
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
end;

{==============================================================================]
  <BinaryCompound>
  @action: Merges two sorted arrays (Self and items) into a new sorted array,
           using TType.Compete for element comparison.
  @note:
    • Assumes both Self and items are already sorted according to oAscending.
    • Uses Compete rather than direct <=/>= comparison, so ordering follows
      whatever comparison semantics Compete defines for MType.
    • On equal elements (Compete = 0), Self's element is taken first,
      preserving stability toward Self — consistent with BinaryCombined
      and the original BinaryMerge comparison-operator variant.
    • If Result.SetSize returns < 1 (i.e. both arrays are empty), the
      function exits early with an empty Result.
    • Time complexity: O(n + m).
[==============================================================================}
function MArrayHelper.BinaryCompound(const items: MArray; const oAscending: Boolean = True): MArray; overload;
var
  i, j, k, s, o: Integer;
begin
  s := Self.Size;
  o := items.Size;
  if (Result.SetSize(s + o) < 1) then
    Exit;
  i := 0;
  j := 0;
  k := 0;
  while ((i < s) and (j < o)) do
  begin
    if (Self[i].Compete(items[j], oAscending) <= 0) then
      Result[k] := Self[i.Increase]
    else
      Result[k] := items[j.Increase];
    Inc(k);
  end;
  while (i < s) do
    Result[k.Increase] := Self[i.Increase];
  while (j < o) do
    Result[k.Increase] := items[j.Increase];
end;

{==============================================================================]
  <BinaryMerge>
  @action: Merges two sorted arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function MArrayHelper.BinaryMerge(const items: MArray; const aAscending: Boolean = True): MArray; overload;
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
  @action: Merges two sorted arrays (Self and items) into a new sorted array based on the specified order by aAscending.
  @note: Assumes both Self and items are already sorted in the same order.
[==============================================================================}
function MArrayHelper.BinaryMerged(const items: MArray; const aAscending: Boolean = True): MArray; overload;
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
{$ENDIF}
