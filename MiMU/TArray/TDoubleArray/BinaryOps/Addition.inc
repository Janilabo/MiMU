{$IFDEF HELPERS}
function BinaryAppend(const x: Double; const aAscending: Boolean = True): Integer;
function BinaryAdd(const x: Double; const aAscending: Boolean = True): TDoubleArray;
function BinaryGrow(const x: Double; const aAscending: Boolean = True): Boolean;
function BinaryInsert(const x: Double; const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryAppend>
  @action: Binary Append method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the index x was added to.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryAppend(const x: Double; const aAscending: Boolean = True): Integer;
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
  <BinaryAdd>
  @action: Binary Add method, adds x to the arr and keeps it in order. Locates right index with Binary Search. Returns the arr with x.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinaryAdd(const x: Double; const aAscending: Boolean = True): TDoubleArray;
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
  <BinaryInsert>
  @action: Insert an double into a sorted array using binary search, preserving order.
  @note: Returns the index where the element was inserted. Supports ascending or descending order.
[==============================================================================}
function TDoubleArrayHelper.BinaryInsert(const x: Double; const aAscending: Boolean = True): Integer; overload;
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
  <BinaryGrow>
  @action: Inserts an integer x into the array while maintaining sorted order.
           Works with ascending or descending order based on aAscending.
  @note: Returns True if the value was inserted, False if it already exists.
[==============================================================================}
function TDoubleArrayHelper.BinaryGrow(const x: Double; const aAscending: Boolean = True): Boolean;
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
{$ENDIF}
