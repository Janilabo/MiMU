{$IFDEF HELPERS}
function Add(const item: MType; const duplicates: Boolean = True): MArray; overload;
function Add(const items: MArray; const duplicates: Boolean = True): MArray; overload;
function Append(const item: MType; const duplicates: Boolean = True): MArray; overload;
function Append(const items: MArray; const duplicates: Boolean = True): MArray; overload;
function Blit(const items: MArray; const index: Integer = 0): Integer; overload;
function Emplace(const item: MType; const index: Integer = 0): Integer; overload;
function Extend(const item: MType): MArray; overload;
function Extend(const items: MArray): MArray; overload;
function Feed(const item: MType; const allowDuplicates: Boolean = False): Integer; overload;
function Grow(const item: MType; const allowDuplicates: Boolean = False): Integer; overload;
function Inject(const items: MArray; const index: Integer = 2147483647): Integer; overload;
function Prepend(const items: MArray; const index: Integer = 0): Integer; overload;
function Push(const item: MType): MArray; overload;
function Push(const items: MArray): MArray; overload;
function Put(const ID: TIntegerArray; const item: MType): MArray; overload;
function Put(const ID: TIntegerArray; const items: MArray): MArray; overload;
function Put(const index: Integer; const items: MArray): MArray; overload;
function Supply(const item: MType): Integer; overload;
function Supply(const items: MArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Add>
  @action: Appends arr with item. Returns the array with added item.
  @note: Adds item to the right side of the array.
[==============================================================================}
function MArrayHelper.Add(const item: MType; const duplicates: Boolean = True): MArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := Self[i];
  if ((not duplicates) and Self.Contains(item)) then
    SetLength(Result, l)
  else
    Result[l] := item;
end;

{==============================================================================]
  <Add>
  @action: Appends arr with items. Returns the array with added items.
  @note: Adds item to the right side of the array.
[==============================================================================}
function MArrayHelper.Add(const items: MArray; const duplicates: Boolean = True): MArray; overload;
var
  a, h, i, s: Integer;
begin
  s := Self.Length;
  i := items.Length;
  SetLength(Result, (s + i));
  if ((i = 0) and (s = 0)) then
    Exit;
  h := High(items);
  for i := 0 to (s - 1) do
    Result[i] := Self[i];
  case duplicates of
    False:
    begin
      a := 0;
      for i := 0 to h do
        if not Result.Contains(items[i]) then
          Result[s + a.Increase] := items[i];
      SetLength(Result, (s + a));
    end;
    True:
    for i := 0 to h do
      Result[i] := items[i];
  end;
end;

{==============================================================================]
  <Append>
  @action: Appends arr with item. Returns the index of added item.
  @note: Adds item to the right side of the array.
[==============================================================================}
function MArrayHelper.Append(const item: MType; const duplicates: Boolean = True): MArray; overload;
begin
  Result := Self.Copy;
  if ((not duplicates) and Self.Contains(item)) then
    Exit;
  SetLength(Result, (Self.Size + 1));
  Result[Self.Size] := item;
end;

{==============================================================================]
  <Append>
  @action: Adds all items items to arr.
  @note: Returns the highest index in the end.
[==============================================================================}
function MArrayHelper.Append(const items: MArray; const duplicates: Boolean = True): MArray; overload;
var
  a, h, i: Integer;
begin
  Result := Self.Copy;
  if Items.Empty then
    Exit;
  h := High(items);
  a := High(Self);
  SetLength(Result, ((a + h) + 2));
  case duplicates of
    False:
    begin
      for i := 0 to h do
        if not Self.Contains(items[i]) then
          Result[a.Increment] := items[i];
      SetLength(Result, (a + 1));
    end;
    True:
    for i := 0 to h do
      Result[a.Increment] := items[i];
  end;
end;

{==============================================================================]
  <Blit>
  @action: Simply puts items to array index, fast.
  @note: No safety checks. Make sure buffer is enough!
[==============================================================================}
function MArrayHelper.Blit(const items: MArray; const index: Integer = 0): Integer; overload;
var
  i: Integer;
begin
  Result := (index + items.Size);
  for i := 0 to High(items) do
    Self[index + i] := items[i]; 
end;

{==============================================================================]
  <Emplace>
  @action: Inserts item to index in arr. Returns the index it was inserted to.
  @note: Alternative for Insert().
[==============================================================================}
function MArrayHelper.Emplace(const item: MType; const index: Integer = 0): Integer; overload;
var
  i: Integer;
begin
  SetLength(Self, (Self.Size + 1));
  Result := index.Clamp(0, High(Self));
  for i := High(Self) downto (Result + 1) do
    Self[i] := Self[i - 1];
  Self[Result] := item;
end;

{==============================================================================]
  <Extend>
  @action: Extends arr with item. Returns it.
  @note: Places item to the left side of the array.
[==============================================================================}
function MArrayHelper.Extend(const item: MType): MArray; overload;
var
  i, h: Integer;
begin
  h := High(Self);
  SetLength(Result, (h + 2));
  for i := 0 to h do
    Result[i + 1] := Self[i];
  Result[0] := item;
end;

{==============================================================================]
  <Extend>
  @action: Extends arr with items. Returns it.
  @note: Places items to the left side of the array.
[==============================================================================}
function MArrayHelper.Extend(const items: MArray): MArray; overload;
var
  i, h, l: Integer;
begin
  h := High(Self);
  l := items.Length;
  SetLength(Result, ((h + 1) + l));
  for i := 0 to h do
    Result[i + l] := Self[i];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;

{==============================================================================]
  <Feed>
  @action: Feeds item to array and returns the index position it was added to.
  @note: Returns -1 if duplicates are not allowed and array already includes item.
[==============================================================================}
function MArrayHelper.Feed(const item: MType; const allowDuplicates: Boolean = False): Integer; overload;
begin
  if ((not allowDuplicates) and Self.Includes(item)) then
    Exit(-1);
  Result := Self.Size;
  SetLength(Self, (Result + 1));
  Self[Result] := item;
end;

{==============================================================================]
  <Grow>
  @action: Feeds item to array and returns the index position it was added to.
  @note: Returns -1 if duplicates are not allowed and array already contains item.
[==============================================================================}
function MArrayHelper.Grow(const item: MType; const allowDuplicates: Boolean = False): Integer; overload;
begin
  if ((not allowDuplicates) and Self.Contains(item)) then
    Exit(-1);
  Result := Self.Size;
  SetLength(Self, (Result + 1));
  Self[Result] := item;
end;

{==============================================================================]
  <Inject>
  @action: Inserts the specified items into the current array at the given index.
           Elements at and after that index are shifted to make room for the
           inserted items.
  @note: If the index exceeds the current length, the items are appended.
         If the index is less than zero, insertion occurs at the beginning.
         Passing an empty array leaves the original array unchanged.
         Returns the new total number of elements after insertion.
[==============================================================================}
function MArrayHelper.Inject(const items: MArray; const index: Integer = 2147483647): Integer; overload;
var
  i, s, l, p: Integer;
begin
  s := Self.Size;
  l := items.Length;
  if (l = 0) then
    Exit(s);
  p := Max(Min(s, index), 0);
  SetLength(Self, (s + l));
  for i := (s - 1) downto p do
    Self[i + l] := Self[i];
  for i := 0 to (l - 1) do
    Self[p + i] := items[i];
end;

{==============================================================================]
  <Prepend>
  @action: Inserts the specified items into the current array starting at the
           given index (default = 0). Elements at and after that index are
           shifted to follow the newly inserted items.
  @note: If the index is less than 0, insertion occurs at the beginning.
         If the index exceeds the array length, the items are appended.
         Returns the new total number of elements after insertion.
[==============================================================================}
function MArrayHelper.Prepend(const items: MArray; const index: Integer = 0): Integer; overload;
var
  i: Integer;
begin
  i := Max(Min(index, Self.Size), 0);
  Self := (Self.Copy(0, i) + items + Self.Copy(i, (Self.Size - i)));
  Result := Self.Size;
end;

{==============================================================================]
  <Push>
  @action: Places item in array with arr.
  @note: Returns array (arr+item) length.
[==============================================================================}
function MArrayHelper.Push(const item: MType): MArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := Self[i];
  Result[l] := item;
end;

{==============================================================================]
  <Push>
  @action: Places items in array with arr.
  @note: Returns array (arr+item) length.
[==============================================================================}
function MArrayHelper.Push(const items: MArray): MArray; overload;
var
  h, i, l: Integer;
begin
  h := High(items);
  l := Self.Length;
  SetLength(Result, (l + (h + 1)));
  for i := 0 to (l - 1) do
    Result[i] := Self[i];
  for i := 0 to h do
    Result[l + i] := items[i];
end;

{==============================================================================]
  <Put>
  @action: Returns array arr filled with item to indexes (ID).
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Put(const ID: TIntegerArray; const item: MType): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  for i := 0 to High(ID) do
    Result[ID[i]] := item;
end;

{==============================================================================]
  <Put>
  @action: Returns array arr filled with items to indexes (ID).
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Put(const ID: TIntegerArray; const items: MArray): MArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Self.Size);
  l := items.Length;
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  for i := 0 to High(ID) do
    Result[ID[i]] := items[i mod l];
end;

{==============================================================================]
  <Put>
  @action: Returns array arr filled with items to starting from custom start index.
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Put(const index: Integer; const items: MArray): MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  for i := 0 to High(items) do
    Result[index + i] := items[i];
end;

{==============================================================================]
  <Supply>
  @action: Adds item to the end of the array.
  @note: Returns the index where item was inserted.
[==============================================================================}
function MArrayHelper.Supply(const item: MType): Integer; overload;
begin
  Result := Self.Size;
  SetLength(Self, (Result + 1));
  Self[Result] := item;
end;

{==============================================================================]
  <Supply>
  @action: Adds items to the end of the array.
  @note: Returns the index where items were inserted.
[==============================================================================}
function MArrayHelper.Supply(const items: MArray): Integer; overload;
var
  i: Integer;
begin
  if items.Empty then
    Exit(-1);
  Result := Self.Size;
  SetLength(Self, (Result + items.Size));
  for i := 0 to High(items) do
    Self[Result + i] := items[i];
end;
{$ENDIF}