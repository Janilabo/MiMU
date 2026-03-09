{$IFDEF HELPERS}
function BinaryAdd(const x: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryAppend(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryGrow(const x: Integer; const aAscending: Boolean = True): Boolean; overload;
function BinaryInsert(const x: Integer; const aAscending: Boolean = True): Integer; overload;
function BinaryPlacement(const item: Integer; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryAdd>
  @action: Binary Add method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the arr with x.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryAdd(const x: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
var
  m, i, o: Integer;
  r: TRange;
begin
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while r.Ascending do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  SetLength(Result, (Self.Size + 1));
  for i := 0 to (r.start - 1) do
    Result[i] := Self[i];
  Result[r.start] := x;
  for i := r.start to High(Self) do
    Result[i + 1] := Self[i];
end;

{==============================================================================]
  <BinaryAppend>
  @action: Binary Append method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the index x was added to.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TIntegerArrayHelper.BinaryAppend(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  m, i, o: Integer;
  r: TRange;
begin
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while r.Ascending do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := r.start;
  SetLength(Self, (Self.Size + 1));
  for i := High(Self) downto (Result + 1) do
    Self[i] := Self[i - 1];
  Self[Result] := x;
end;

{==============================================================================]
  <BinaryGrow>
  @action: Inserts an integer x into the array while maintaining sorted order.
           Works with ascending or descending order based on aAscending.
  @note: Returns True if the value was inserted, False if it already exists.
[==============================================================================}
function TIntegerArrayHelper.BinaryGrow(const x: Integer; const aAscending: Boolean = True): Boolean; overload;
var
  m, i, o: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Ascending do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * x)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := ((Self.Size = r.start) or (Self[r.start] <> x));
  if not Result then
    Exit;
  SetLength(Self, (Self.Size + 1));
  for i := High(Self) downto (r.start + 1) do
    Self[i] := Self[i - 1];
  Self[r.start] := x;
end;

{==============================================================================]
  <BinaryInsert>
  @action: Insert an integer into a sorted array using binary search, preserving order.
  @note: Returns the index where the element was inserted. Supports ascending or descending order.
[==============================================================================}
function TIntegerArrayHelper.BinaryInsert(const x: Integer; const aAscending: Boolean = True): Integer; overload;
var
  m, i: Integer;
  r: TRange;
begin
  Result := Self.Size;
  SetLength(Self, (Result + 1));
  if (Result > 0) then
  begin
    r.Create(0, (Result - 1));
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if ((aAscending and (Self[m] >= x)) or ((not aAscending) and (Self[m] <= x))) then
      begin
        Result := m;
        r.stop := (m - 1);
      end else
        r.start := (m + 1);
    end;
    for i := High(Self) downto (Result + 1) do
      Self[i] := Self[i - 1];
    Self[Result] := x;
  end else
    Self[0] := x;
end;

{==============================================================================]
  <BinaryPlacement>
  @action: Inserts an item into a sorted array while preserving order.
  @note: Array must already be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns: index where the element was inserted
[==============================================================================}
function TIntegerArrayHelper.BinaryPlacement(const item: Integer; const oAscending: Boolean = True): Integer; overload;
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
    Move(Self[Result], Self[Result + 1], ((S - Result) * SizeOf(Integer)));
  Self[Result] := item;
end;
{$ENDIF}
