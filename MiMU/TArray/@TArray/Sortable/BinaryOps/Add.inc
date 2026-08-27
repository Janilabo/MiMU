{$IFDEF HELPERS}
function BinaryAdd(const item: MType; const aAscending: Boolean = True): MArray; overload;
function BinaryAddendum(const item: MType; const allowDuplicates: Boolean = True; const oAscending: Boolean = True): Integer; overload;
function BinaryAnnex(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryAppend(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryFeed(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryGive(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryInclude(const item: MType; const oAscending: Boolean = True): Boolean; overload;
function BinaryInsert(const x: MType; const aAscending: Boolean = True): Integer; overload;
function BinaryInserta(const item: MType; const allowDuplicates: Boolean = True; const oAscending: Boolean = True): Integer; overload;
function BinaryInsertion(const item: MType; const oAscending: Boolean = True): Integer; overload;
function BinarySupply(const item: MType; const aAscending: Boolean = True): Boolean; overload;
function BinarySupply(const items: MArray; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryAdd>
  @action: Creates a new array with item inserted into its correctly sorted
           position, without modifying Self.
  @note:
    - Self must already be sorted according to aAscending.
    - Duplicate values are permitted; the item is inserted at the first
      valid position consistent with sort order.
[==============================================================================}
function MArrayHelper.BinaryAdd(const item: MType; const aAscending: Boolean = True): MArray; overload;
var
  m, i: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  while r.Asceal do
  begin
    m := r.Pivot;
    if ((aAscending and (Self[m] < item)) or ((not aAscending) and (Self[m] > item))) then
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
  <BinaryAddendum>
  @action: Inserts an item into the array while maintaining sorted order,
           using a fast-path optimization: if the array is empty or item
           belongs at the tail (i.e. sorts after the current last element),
           it is appended directly rather than going through a full binary
           search and shift. Otherwise falls back to BinaryInsert for the
           general case.
  @note:
    - Self must already be sorted according to oAscending.
    - allowDuplicates controls whether an existing equal value blocks
      insertion — behavior for equal values is delegated to BinaryInsert
      in the non-fast-path case.
    - Returns the index at which the item was inserted.
    - Best case O(1) amortized (tail append); worst case matches
      BinaryInsert's complexity (binary search + shift).
[==============================================================================}
function MArrayHelper.BinaryAddendum(const item: MType; const allowDuplicates: Boolean = True; const oAscending: Boolean = True): Integer; overload;
begin
  if not (Self.Empty or (Self[High(Self)].Contest(item, oAscending) < 0)) then
    Exit(Self.BinaryInserta(item, allowDuplicates, oAscending));
  Result := Self.Size;
  Self.Supply(item);
end;

{==============================================================================]
  <BinaryAnnex>
  @action: Inserts item into the array at its correct sorted position,
           determined via BinaryLeftpos, and shifts subsequent elements
           right to make room. Modifies Self in place.
  @note:
    - Self must already be sorted according to oAscending.
    - Duplicates are permitted; item is inserted before any existing
      equal elements (leftmost valid position, per BinaryLeftpos).
    - Returns the index at which item was inserted.
    - Uses element-wise assignment for the shift, safe for both managed
      (e.g. String) and unmanaged MType instantiations.
[==============================================================================}
function MArrayHelper.BinaryAnnex(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  i: Integer;
begin
  Result := Self.BinaryLeftpos(item, oAscending);
  for i := Self.Alloc(Self.Size + 1) downto (Result + 1) do
    Self[i] := Self[i - 1];
  Self[Result] := item;
end;

{==============================================================================]
  <BinaryAppend>
  @action: Inserts an item into the array while maintaining sorted order.
           Locates the correct index via binary search and shifts elements
           to make room. Modifies Self in place.
  @note:
    - Self must already be sorted according to oAscending.
    - Returns the index at which the item was inserted.
    - Duplicate values are permitted; the item is inserted at the first
      valid position consistent with sort order.
[==============================================================================}
function MArrayHelper.BinaryAppend(const item: MType; const oAscending: Boolean = True): Integer; overload;
var
  m, i: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
  while r.Asceal do
  begin
    m := r.Pivot;
    if ((oAscending and (Self[m] < item)) or ((not oAscending) and (Self[m] > item))) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
  Result := r.start;
  SetLength(Self, (Self.Length + 1));
  for i := (High(Self) - 1) downto Result do
    Self[i + 1] := Self[i];
  Self[Result] := item;
end;

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
function MArrayHelper.BinaryInserta(const item: MType; const allowDuplicates: Boolean = True; const oAscending: Boolean = True): Integer; overload;
var
  H, M: Integer;
begin
  Result := 0;
  H := High(Self);
  while (Result <= H) do
  begin
    M := ((Result + H) div 2);
    case Self[M].Contest(item, oAscending) of
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
  m, i: Integer;
  r: TRange;
begin
  r.Create(0, High(Self));
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

{==============================================================================]
  <BinarySupply>
  @action: Merges the sorted, deduplicated complement of `items` — the values
           not already present in Self — into Self in place, preserving sort
           order (`oAscending`). Returns the count of values actually added.
           Empty `items` is a no-op; an empty Self is simply replaced by the
           sorted, deduplicated `items`.
  @note: Assumes Self is already sorted per `oAscending` in the general path;
         `BinaryFind` correctness depends on this and it is never checked.
[==============================================================================}
function MArrayHelper.BinarySupply(const items: MArray; const oAscending: Boolean = True): Integer; overload;
var
  a, b, i, s, l, z: Integer;
  c, t: MArray;
begin
  if items.Empty then
    Exit(0);
  if Self.Empty then
  begin
    Self := items.QuickSorted(oAscending).Compacted;
    Exit(Self.Length);
  end;
  c := items.QuickSorted(oAscending);
  a := 0;
  for i := 1 to High(c) do
    if (c[i] <> c[a]) then
      c[a.Increment] := c[i];
  Result := 0;
  for i := 0 to c.Alloc(a + 1) do
    if (Self.BinaryFind(c[i], oAscending) = -1) then
      c[Result.Increase] := c[i];
  SetLength(c, Result);
  t := Self.Clone;
  l := c.Length;
  s := t.Length;
  SetLength(Self, (s + l));
  a := 0;
  b := 0;
  z := 0;
  while ((a < s) and (b < l)) do
    if ((oAscending and (t[a] < c[b])) or ((not oAscending) and (t[a] > c[b]))) then
      Self[z.Increase] := t[a.Increase]
    else
      Self[z.Increase] := c[b.Increase];
  for i := a to High(t) do
    Self[z.Increase] := t[i];
  for i := b to High(c) do
    Self[z.Increase] := c[i];
end;
{$ENDIF}
