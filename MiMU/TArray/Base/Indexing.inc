{$IFDEF HELPERS}
function ID(const aAscending: Boolean = True): TIntegerArray; overload;
function IDs(const aAscending: Boolean = True): TIntegerArray; overload;
function IDs(const ID: TIntegerArray): MArray; overload;
function IDs(const ID: TIntegerArray; const item: MType): MArray; overload;
function IDs(const ID: TIntegerArray; const items: MArray): MArray; overload;
function Indexed(const aAscending: Boolean = True): TIntegerArray; overload;
function Indexes(const aAscending: Boolean = True): TIntegerArray; overload;
function Indexing(const aAscending: Boolean = True): TIntegerArray; overload;
function Indices(const aAscending: Boolean = True): TIntegerArray; overload;
function Indiced(const aAscending: Boolean = True): TIntegerArray; overload;
function Slots: TIntegerArray; overload;
function ToIndexes: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <ID>
  @action: Returns indexes of arr as TIntegerArray.
  @note: None.
[==============================================================================}
function MArrayHelper.ID(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, l, b, s: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  b := (Integer(not aAscending) * (l - 1));
  s := IfThen(aAscending, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := (b + (s * i));
end;

{==============================================================================]
  <IDs>
  @action: Returns IDs of arr as TIntegerArray.
  @note: None.
[==============================================================================}
function MArrayHelper.IDs(const aAscending: Boolean = True): TIntegerArray; overload;
var
  h, i: Integer;
begin
  SetLength(Result, Self.Size);
  h := High(Self);
  case aAscending of
    True:
    for i := 0 to h do
      Result[i] := i;
    False:
    for i := h downto 0 do
      Result[h - i] := i;
  end;
end;

{==============================================================================]
  <IDs>
  @action: Returns items from arr by IDs.
  @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array.
[==============================================================================}
function MArrayHelper.IDs(const ID: TIntegerArray): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, ID.Size);
  for i := 0 to High(Result) do
    Result[i] := Self[ID[i]];
end;

{==============================================================================]
  <IDs>
  @action: Returns arr with IDs replaced as item.
  @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array.
[==============================================================================}
function MArrayHelper.IDs(const ID: TIntegerArray; const item: MType): MArray; overload;
var
  i: Integer;
begin
  Result := Self.Copy;
  for i := 0 to High(ID) do
    Result[ID[i]] := item;
end;

{==============================================================================]
  <IDs>
  @action: Returns arr with IDs replaced as items.
  @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array and ALSO item[s].
[==============================================================================}
function MArrayHelper.IDs(const ID: TIntegerArray; const items: MArray): MArray; overload;
var
  i, l: Integer;
begin
  Result := Self.Copy;
  l := items.Length;
  for i := 0 to High(ID) do
    Result[ID[i]] := items[i mod l];
end;

{==============================================================================]
  <Indexed>
  @action: Returns IDs of arr as TIntegerArray.
  @note: None.
[==============================================================================}
function MArrayHelper.Indexed(const aAscending: Boolean = True): TIntegerArray; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if Self.Populated then
  case aAscending of
    True:
    while (l.Decrement > -1) do
      Result[l] := l;
    False:
    while (l.Decrement > -1) do
      Result[(Self.Size - l) - 1] := l;
  end;
end;

{==============================================================================]
  <Indexes>
  @action: Returns IDs of arr as TIntegerArray.
  @note: None.
[==============================================================================}
function MArrayHelper.Indexes(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := IfThen(aAscending, i, ((l - i) - 1));
end;

{==============================================================================]
  <Indexing>
  @action: Returns an array of all valid indexes of the dynamic array.
           Supports ascending or descending order.
  @note:
    - Ascending: [0..Length(Self)-1]
    - Descending: [Length(Self)-1..0]
    - Uses efficient two-pointer approach for small/medium arrays.
    - Optional divide-and-conquer recursive variant can be used for huge arrays.
[==============================================================================}
function MArrayHelper.Indexing(const aAscending: Boolean = True): TIntegerArray; overload;
procedure RI(var return: TIntegerArray; const L, R: Integer);
var
  M: Integer;
begin
  if (L > R) then
    Exit;
  if (L = R) then
  begin
    if aAscending then
      return[L] := L
    else
      return[L] := (High(return) - L);
    Exit;
  end;
  M := (L + ((R - L) div 2));
  RI(return, L, M);
  RI(return, (M + 1), R);
end;
begin
  SetLength(Result, Self.Size);
  if (Result.Size >  0) then
    RI(Result, 0, High(Self));
end;

{==============================================================================]
  <Indices>
  @action: Returns IDs of arr as TIntegerArray.
  @note: None.
[==============================================================================}
function MArrayHelper.Indiced(const aAscending: Boolean = True): TIntegerArray; overload;
var
  r: TRange;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  r.Create(0, High(Self));
  case aAscending of
    True:
    repeat
      Result[r.start] := r.start;
      Result[r.stop] := r.stop;
    until (r.start.Increment > r.stop.Decrement);
    False:
    repeat
      Result[r.start] := r.stop;
      Result[r.stop] := r.start;
    until (r.start.Increment > r.stop.Decrement);
  end;
end;

{==============================================================================]
  <Indices>
  @action: Returns IDs of arr as TIntegerArray.
  @note: None.
[==============================================================================}
function MArrayHelper.Indices(const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, l, h: Integer;
begin
  l := Low(Self);
  h := High(Self);
  SetLength(Result, ((h - l) + 1));
  case aAscending of
    False:
    for i := l to h do
      Result[h - i] := i;
	True:
    for i := l to h do
      Result[i - l] := i;
  end;
end;

{==============================================================================]
  <Slots>
  @action: Returns indexes of array.
  @note: None.
[==============================================================================}
function MArrayHelper.Slots: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to (Self.Size - 1) do
    Result[i] := i;
end;

{==============================================================================]
  <ToIndexes>
  @action: Returns indexes of array.
  @note: None.
[==============================================================================}
function MArrayHelper.ToIndexes: TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Length);
  l := Low(Self);
  for i := l to High(Self) do
    Result[i - l] := i;
end;
{$ENDIF}