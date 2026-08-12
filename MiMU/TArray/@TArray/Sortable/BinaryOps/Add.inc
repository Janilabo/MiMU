{$IFDEF HELPERS}
function BinaryFeed(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryGive(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryInclude(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryInsert(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryInserta(const item: MType; const allowDuplicates: Boolean = True): Integer; overload;
function BinaryInsertion(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySupply(const item: MType; const aAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryFeed>
  @action: Inserts item into Self while maintaining sorted order. Works with
           ascending or descending order based on oAscending.
  @note: Returns True if item was inserted, False if it already exists.
[==============================================================================}
function MArrayHelper.BinaryFeed(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  m, i: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  while r.Asceal do
  begin
    m := r.Pivot;
    if (oAscending = (Self[m] < item)) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := ((Self.Length = r.start) or (Self[r.start] <> item));
  if not Result then
    Exit;
  SetLength(Self, (Self.Length + 1));
  for i := High(Self) downto (r.start + 1) do
    Self[i] := Self[i - 1];
  Self[r.start] := item;
end;

{==============================================================================]
  <BinaryGive>
  @action: Inserts item into Self while maintaining sorted order. Works with
           ascending or descending order based on oAscending.
  @note: Returns True if item was inserted, False if it already exists.
[==============================================================================}
function MArrayHelper.BinaryGive(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  l, h, m, i: Integer;
begin
  l := 0;
  h := High(Self);
  while (l <= h) do
  begin
    m := (l + ((h - l) div 2));
    if (Self[m] = item) then
      Exit(False);
    if ((oAscending and (Self[m] < item)) or (not oAscending and (Self[m] > item))) then
      l := (m + 1)
    else
      h := (m - 1);
  end;
  for i := Self.Alloc(Self.Length + 1) downto (l + 1) do
    Self[i] := Self[i - 1];
  Self[l] := item;
  Result := True;
end;

{==============================================================================]
  <BinaryInclude>
  @action: Inserts item into Self while maintaining sorted order. Works with
           ascending or descending order based on oAscending.
  @note: Returns True if item was inserted, False if it already exists.
[==============================================================================}
function MArrayHelper.BinaryInclude(const item: MType; const oAscending: Boolean = True): Boolean; overload;
var
  m: Integer;
  r: TRange;
begin
  r := TRange.Construct(0, High(Self));
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    if (Self[m] = item) then
      Exit(False);
    if ((oAscending and (Self[m] < item)) or (not oAscending and (Self[m] > item))) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Insert(item, Self, r.start);
  Result := True;
end;

{==============================================================================]
  <BinaryInsert>
  @action: Insert an item (x) into a sorted array using binary search, preserving order.
  @note: Returns the index where the element was inserted. Supports ascending or descending order.
[==============================================================================}
function MArrayHelper.BinaryInsert(const x: MType; const aAscending: Boolean = True): Integer; overload;
var
  m, i: Integer;
  r: TRange;
begin
  Result := Self.Length;
  if (Self.SetSize(Result + 1) > 1) then
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
  <BinaryInserta>
  @action: Inserts a specified item into a sorted array while maintaining order.
  @note: - If allowDuplicates = False, no insertion occurs if the item already exists.
         - Returns the index of the inserted or existing item.
[==============================================================================}
function MArrayHelper.BinaryInserta(const item: MType; const allowDuplicates: Boolean = True): Integer; overload;
var
  H, M: Integer;
begin
  Result := 0;
  H := High(Self);
  while (Result <= H) do
  begin
    M := ((Result + H) div 2);
    case Self[M].Compare(item) of
      -1: Result := (M + 1);
      1: H := (M - 1);
      0:
      if allowDuplicates then
        Result := (M + 1)
      else
        Exit(M);
    end;
  end;
  Insert(item, Self, Result);
end;

{==============================================================================]
  <BinaryInsertion>
  @action: Inserts an item into a sorted array while preserving order.
  @note: Array must already be sorted.
         oAscending = True  -> ascending order assumed
         oAscending = False -> descending order assumed
         Returns index where the element was inserted.
[==============================================================================}
function MArrayHelper.BinaryInsertion(const item: MType; const oAscending: Boolean = True): Integer; overload;
procedure I(var arr: MArray; const index: Integer; const value: MType);
var
  a, N: Integer;
begin
  N := System.Length(arr);
  SetLength(arr, (N + 1));
  for a := N downto (index + 1) do
    arr[a] := arr[a - 1];
  arr[index] := value;
end;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if ((oAscending and (Self[M] < item)) or ((not oAscending) and (Self[M] > item))) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  Result := R.start;
  I(Self, Result, item);
end;

{==============================================================================]
  <BinarySupply>
  @action: Inserts the item x into the array at the correct position to maintain
           sorted order. Supports both ascending and descending order.
  @note:
    • The array must already be sorted according to aAscending.  
    • If aAscending = True, ascending order is assumed;  
      if aAscending = False, descending order is assumed.  
    • The value is not inserted if it already exists in the array.  
    • Returns True if the value was inserted, False if it already exists.  
    • Search complexity: O(log n).  
    • Insertion (element shift) complexity: O(n).  
    • Overall complexity: O(n).  
    • The array is resized when insertion occurs.
[==============================================================================}
function MArrayHelper.BinarySupply(const item: MType; const aAscending: Boolean = True): Boolean; overload;
var
  m, i, o: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  o := aAscending.Select(1, -1);
  while r.Asceal do
  begin
    m := r.Pivot;
    if ((aAscending and (Self[m] < item)) or ((not aAscending) and (Self[m] > item))) then
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
{$ENDIF}
