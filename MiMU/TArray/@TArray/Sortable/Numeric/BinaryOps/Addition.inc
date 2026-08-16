{$IFDEF HELPERS}
function BinaryAddition(const item: MType; const aAscending: Boolean = True): MArray; overload;
function BinaryAppendix(const item: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryGrow(const item: MType; const aAscending: Boolean = True): Boolean; overload;
function BinaryPlacement(const item: MType; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryAddition>
  @action: Binary Add method, adds item to the arr and keeps it in order. Locates right index with Binary Search.
           Returns the arr with item.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function MArrayHelper.BinaryAddition(const item: MType; const aAscending: Boolean = True): MArray; overload;
var
  m, i, o: Integer;
  r: TRange;
begin
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while r.Asceal do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * item)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  SetLength(Result, (Self.Size + 1));
  for i := 0 to (r.start - 1) do
    Result[i] := Self[i];
  Result[r.start] := item;
  for i := r.start to High(Self) do
    Result[i + 1] := Self[i];
end;

{==============================================================================]
  <BinaryAppendix>
  @action: Binary Append method, adds item to the arr and keeps it in order.
           Locates right index with Binary Search. Returns the index x was added to.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function MArrayHelper.BinaryAppendix(const item: MType; const aAscending: Boolean = True): Integer; overload;
var
  m, i, o: Integer;
  r: TRange;
begin
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while r.Asceal do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * item)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := r.start;
  SetLength(Self, (Self.Size + 1));
  for i := High(Self) downto (Result + 1) do
    Self[i] := Self[i - 1];
  Self[Result] := item;
end;

{==============================================================================]
  <BinaryGrow>
  @action: Inserts an item into the array while maintaining sorted order.
           Works with ascending or descending order based on aAscending.
  @note: Returns True if the value was inserted, False if it already exists.
[==============================================================================}
function MArrayHelper.BinaryGrow(const item: MType; const aAscending: Boolean = True): Boolean; overload;
var
  m, i, o: Integer;
  z: MType;
  r: TRange;
begin
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  z := (o * item);
  while r.Asceal do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < z) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := ((Self.Size = r.start) or (Self[r.start] <> item));
  if not Result then
    Exit;
  SetLength(Self, (Self.Size + 1));
  for i := High(Self) downto (r.start + 1) do
    Self[i] := Self[i - 1];
  Self[r.start] := item;
end;

{==============================================================================]
  <BinaryPlacement>
  @action: Inserts an item into a sorted array while preserving order.
  @note: Array must already be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns: index where the element was inserted
[==============================================================================}
function MArrayHelper.BinaryPlacement(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  M, S: Integer;
  R: TRange;
begin
  S := Self.Length;
  R.Create(0, (S - 1));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := R.start;
  SetLength(Self, (S + 1));
  if (Result < S) then
    Move(Self[Result], Self[Result + 1], ((S - Result) * SizeOf(MType)));
  Self[Result] := item;
end;
{$ENDIF}
