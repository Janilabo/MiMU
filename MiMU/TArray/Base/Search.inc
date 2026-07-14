{$IFDEF HELPERS}
function Earliest(const sItem: MType): Integer; overload;
function Find(const ID: TRange; const item: MType): Integer; overload;
function Find(const ID: TIntegerArray; const item: MType): Integer; overload;
function Find(const ID: TRange; const items: MArray): Integer; overload;
function Find(const ID: TIntegerArray; const items: MArray): Integer; overload;
function FindNext(const item: MType; var current: Integer): Boolean; overload;
function FindPrevious(const item: MType; var current: Integer): Boolean; overload;
function First: Integer; overload;
function First(const item: MType): Integer; overload;
function First(const items: MArray): Integer; overload;
function IndexFor(const tItem: MType): Integer; overload;
function IndexFor(const tItems: MArray): Integer; overload;
function IndexOf(const item: MType; const ID: TRange): Integer; overload;
function Last: Integer; overload;
function Last(const item: MType): Integer; overload;
function Last(const items: MArray): Integer; overload;
function LastIndex(const sItem: MType): Integer; overload;
function Latest(const sItem: MType): Integer; overload;
function Loc(const item: MType; const index: Integer = 2147483647): Integer; overload;
function Loc(const items: MArray; const index: Integer = 2147483647): Integer; overload;
function Location(const item: MType; const index: Integer = 2147483647): Integer; overload;
function Location(const items: MArray; const index: Integer = 2147483647): Integer; overload;
function Pos(const item: MType; const index: Integer = 0): Integer; overload;
function Pos(const items: MArray; const index: Integer = 0): Integer; overload;
function Position(const item: MType; const index: Integer = 0): Integer; overload;
function Position(const items: MArray; const index: Integer = 0): Integer; overload;
function Range(const subArray: MArray; const index: Integer = 0): TRange; overload;
function Ranges(const subArray: MArray; const index: Integer = 0): TRangeArray; overload;
function Span: TRange; overload;
function Span(const subArray: MArray; const index: Integer = 2147483647): TRange; overload;
function Spans(const subArray: MArray; const index: Integer = 2147483647): TRangeArray; overload;
function SubarrayLocation(const pattern: MArray): Integer; overload;
function SubarrayPosition(const pattern: MArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Earliest>
  @action: Returns the 0-based index of the earliest (lowest-indexed) 
           occurrence of a value by scanning the array forward.
  @param: sItem The integer value to locate within the array.
  @return: The lowest index where the value matches; the length of the array 
           if the value is not found or if the array is empty.
  @note: Utilizes a short-circuit evaluation strategy to guard the boundary 
         check (Result < l) before performing the array lookup.
[==============================================================================}
function MArrayHelper.Earliest(const sItem: MType): Integer; overload;
var
  l: Integer;
begin
  l := Result.IO(0, Self.Length);
  while ((Result < l) and (Self[Result] <> sItem)) do
    Inc(Result);
end;

{==============================================================================]
  <Find>
  @action: Scans array for item by IDs. Returns position if found.
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Find(const ID: TRange; const item: MType): Integer; overload;
begin
  if Self.Populated then
  case ID.Asceal of
    True:
    for Result := ID.start to ID.stop do
      if (Self[Result] = item) then
        Exit;
    False:
    for Result := ID.start downto ID.stop do
      if (Self[Result] = item) then
        Exit;
  end;
  Result := -1;
end;

{==============================================================================]
  <Find>
  @action: Scans array for item by IDs. Returns position if found.
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Find(const ID: TIntegerArray; const item: MType): Integer; overload;
var
  i: Integer;
begin
  if Self.Populated then
  for i := 0 to High(ID) do
    if (Self[ID[i]] = item) then
      Exit(ID[i]);
  Result := -1;
end;

{==============================================================================]
  <Find>
  @action: Scans array for items by IDs. Returns position if found.
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Find(const ID: TRange; const items: MArray): Integer; overload;
begin
  if (Self.Populated and items.Populated) then
  case ID.Asceal of
    True:
    for Result := ID.start to ID.stop do
      if items.Contains(Self[Result]) then
        Exit;
    False:
    for Result := ID.start downto ID.stop do
      if items.Contains(Self[Result]) then
        Exit;
  end;
  Result := -1;
end;

{==============================================================================]
  <Find>
  @action: Scans array for items by IDs. Returns position if found.
  @note: Unsafe method! No safety checking.
[==============================================================================}
function MArrayHelper.Find(const ID: TIntegerArray; const items: MArray): Integer; overload;
var
  i: Integer;
begin
  if (Self.Populated and items.Populated) then
  for i := 0 to High(ID) do
    if items.Contains(Self[ID[i]]) then
      Exit(ID[i]);
  Result := -1;
end;

{==============================================================================]
  <FindNext>
  @action: Searches forward for the next occurrence of an item in the array, 
           starting from the position after the 'current' index. Updates 
           'current' to the found index.
  @note: Returns True if found, False otherwise. To find the first match or 
         use in a loop, initialize 'current' to -1.
[==============================================================================}
function MArrayHelper.FindNext(const item: MType; var current: Integer): Boolean; overload;
begin
  current := Self.Pos(item, (current + 1));
  Result := (current > -1);
end;

{==============================================================================]
  <FindPrevious>
  @action: Searches backward for the previous occurrence of an item in the array, 
           starting from the position before the 'current' index. Updates 
           'current' to the found index.
  @note: Returns True if found, False otherwise. To find the last match or 
         use in a loop, initialize 'current' to the length of the array.
[==============================================================================}
function MArrayHelper.FindPrevious(const item: MType; var current: Integer): Boolean; overload;
begin
  current := Self.Loc(item, (current - 1));
  Result := (current > -1);
end;

{==============================================================================]
  <First>
  @action: Returns the first index of arr.
  @note: With empty array result will be -1!
[==============================================================================}
function MArrayHelper.First: Integer; overload;
begin
  Result := IfThen(Self.Empty, -1, 0);
end;

{==============================================================================]
  <First>
  @action: Returns the first index that matches item in arr.
  @note: Unmatch will be -1!
[==============================================================================}
function MArrayHelper.First(const item: MType): Integer; overload;
begin
  for Result := 0 to High(Self) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <First>
  @action: Returns the first arr index that matches any of the items.
  @note: Unmatch will be -1!
[==============================================================================}
function MArrayHelper.First(const items: MArray): Integer; overload;
begin
  for Result := 0 to High(Self) do
    if items.Contains(Self[Result]) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <IndexFor>
  @action: Scans the array sequentially to locate the first occurrence of a 
           specified item and returns its 0-based index. Returns -1 if the 
           item is not found.
  @note: Optimized for execution speed using a 4-way loop unrolling strategy 
         to maximize CPU instruction pipeline efficiency and minimize branch 
         misprediction penalties.
[==============================================================================}
function MArrayHelper.IndexFor(const tItem: MType): Integer; overload;
var
  L: Integer;
begin
  L := Self.Length;
  if (L > 0) then
  begin
    Result := 0;
    while (Result <= (L - 4)) do
    begin
      if (Self[Result] = tItem) then
        Exit;
      if (Self[Result + 1] = tItem) then
        Exit(Result + 1);
      if (Self[Result + 2] = tItem) then
        Exit(Result + 2);
      if (Self[Result + 3] = tItem) then
        Exit(Result + 3);
      Result.Increase(4);
    end;
    while (Result < L) do
      if (Self[Result] = tItem) then
        Exit(Result)
      else
        Inc(Result);
  end;
  Result := -1;
end;

{==============================================================================]
  <IndexFor>
  @action: Scans the array sequentially to locate the first element that exists 
           within the specified target collection (tItems) and returns its 
           0-based index. Returns -1 if no matching element is found.
  @note: Optimized using a 4-way loop unrolling strategy to accelerate the 
         multi-item containment check (Contains) and reduce loop overhead.
[==============================================================================}
function MArrayHelper.IndexFor(const tItems: MArray): Integer; overload;
var
  L: Integer;
begin
  L := Self.Length;
  if ((L > 0) and (tItems.Length > 0)) then
  begin
    Result := 0;
    while (Result <= (L - 4)) do
    begin
      if tItems.Contains(Self[Result]) then
        Exit;
      if tItems.Contains(Self[Result + 1]) then
        Exit(Result + 1);
      if tItems.Contains(Self[Result + 2]) then
        Exit(Result + 2);
      if tItems.Contains(Self[Result + 3]) then
        Exit(Result + 3);
      Result.Increase(4);
    end;
    while (Result < L) do
      if tItems.Contains(Self[Result]) then
        Exit(Result)
      else
        Inc(Result);
  end;
  Result := -1;
end;

{==============================================================================]
  <IndexOf>
  @action: Performs a linear search for the first occurrence of <item> within the
           specified <TRange>. The traversal direction is determined by <ID.Ascending>.
  @warning: This function is unsafe. It does not validate whether <ID> lies
            within the valid index bounds of the array.
            It is the caller's responsibility to ensure that <ID> is a valid range.
  @note:
    - Returns the index of the first matching element encountered.
    - Returns -1 if the value is not found within the given range.
    - Search direction follows <ID.Ascending>.
    - Time complexity is O(n) relative to the size of the specified range.
    - Does not modify the array.
[==============================================================================}
function MArrayHelper.IndexOf(const item: MType; const ID: TRange): Integer; overload;
begin
  case ID.Asceal of
    True:
    for Result := ID.start to ID.stop do
      if (Self[Result] = item) then
        Exit;
    False:
    for Result := ID.start downto ID.stop do
      if (Self[Result] = item) then
        Exit;
  end;
  Result := -1;
end;

{==============================================================================]
  <Last>
  @action: Returns the last index of arr.
  @note: With empty array result will be -1!
[==============================================================================}
function MArrayHelper.Last: Integer; overload;
begin
  Result := IfThen(Self.Empty, -1, (Self.Size - 1));
end;

{==============================================================================]
  <Last>
  @action: Returns the 0-based index of the last occurrence of a value.
  @param: item The value to locate within the array.
  @return: The highest index where the value matches; -1 if not found.
  @note: Searches the array backward from the end using an optimized
         Result-driven iteration loop. Safely returns -1 for empty arrays.
[==============================================================================}
function MArrayHelper.Last(const item: MType): Integer; overload;
begin
  for Result := High(Self) downto 0 do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <Last>
  @action: Returns the last arr index that matches any of the items.
  @note: Unmatch will be -1!
[==============================================================================}
function MArrayHelper.Last(const items: MArray): Integer; overload;
begin
  for Result := High(Self) downto 0 do
    if items.Contains(Self[Result]) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <LastIndex>
  @action: Returns the 0-based index of the last occurrence of a value by 
           scanning the array backward.
  @param: sItem The value of type MType to locate within the array.
  @return: The highest index where a match is found; -1 if the value does 
           not exist or if the array is empty.
  @note: Uses an aggressive inline state-mutation approach. Result is 
         initialized to Length and safely pre-decremented into valid index 
         space within the loop conditional check.
[==============================================================================}
function MArrayHelper.LastIndex(const sItem: MType): Integer; overload;
begin
  Result := Self.Length;
  while (Result.Decrement > -1) do
    if (Self[Result] = sItem) then
      Exit;
end;

{==============================================================================]
  <Latest>
  @action: Returns the 0-based index of the most recent (highest-indexed) 
           occurrence of a value by scanning the array backward.
  @param: sItem The integer value to locate within the array.
  @return: The highest index where the value matches; -1 if the value is 
           not found or if the array is empty.
  @note: Utilizes a short-circuit evaluation strategy to guard the boundary 
         check (Result > -1) before performing the array lookup.
[==============================================================================}
function MArrayHelper.Latest(const sItem: MType): Integer; overload;
begin
  Result := High(Self);
  while ((Result > -1) and (Self[Result] <> sItem)) do
    Dec(Result);
end;

{==============================================================================]
  <Loc>
  @action: Returns last index position from arr which matched with item.
  @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function MArrayHelper.Loc(const item: MType; const index: Integer = 2147483647): Integer; overload;
begin
  for Result := Min(High(Self), index) downto 0 do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <Loc>
  @action: Returns index position from arr which matches with items.
  @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function MArrayHelper.Loc(const items: MArray; const index: Integer = 2147483647): Integer; overload;
var
  h, i: Integer;
begin
  h := High(items);
  if items.Populated then
  for Result := Min(High(Self), index) downto 0 do
    for i := 0 to h do
      if (Self[Result] = items[i]) then
        Exit;
  Result := -1;
end;

{==============================================================================]
  <Location>
  @action: Returns index position from arr which matched with item.
  @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function MArrayHelper.Location(const item: MType; const index: Integer = 2147483647): Integer; overload;
var
  l: Integer;
begin
  l := Self.Length;
  Result := Min(l, (index + 1));
  while (Result.Decrement > -1) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <Location>
  @action: Returns index position from arr which matches with items.
  @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function MArrayHelper.Location(const items: MArray; const index: Integer = 2147483647): Integer; overload;
var
  h, i, l: Integer;
begin
  if items.Populated then
  begin
    h := High(items);
    l := Self.Length;
    Result := Min(l, (index + 1));
    while (Result.Decrement > -1) do
      for i := 0 to h do
        if (Self[Result] = items[i]) then
          Exit;
  end;
  Result := -1;
end;

{==============================================================================]
  <Pos>
  @action: Returns index position from arr which matched with item.
  @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function MArrayHelper.Pos(const item: MType; const index: Integer = 0): Integer; overload;
begin
  for Result := Max(0, index) to High(Self) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <Pos>
  @action: Returns index position from arr which matches with items.
  @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function MArrayHelper.Pos(const items: MArray; const index: Integer = 0): Integer; overload;
var
  h, i: Integer;
begin
  h := High(items);
  if (h > -1) then
  for Result := Max(0, index) to High(Self) do
    for i := 0 to h do
      if (Self[Result] = items[i]) then
        Exit;
  Result := -1;
end;

{==============================================================================]
  <Position>
  @action: Returns index position from arr which matched with item.
  @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function MArrayHelper.Position(const item: MType; const index: Integer = 0): Integer; overload;
var
  l: Integer;
begin
  Result := Max(-1, (index - 1));
  l := Self.Length;
  while (Result.Increment < l) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
  <Position>
  @action: Returns index position from arr which matches with items.
  @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function MArrayHelper.Position(const items: MArray; const index: Integer = 0): Integer; overload;
var
  h, i, l: Integer;
begin
  if items.Populated then
  begin
    h := High(items);
    Result := Max(-1, (index - 1));
    l := Self.Length;
    while (Result.Increment < l) do
      for i := 0 to h do
        if (Self[Result] = items[i]) then
          Exit;
  end;
  Result := -1;
end;

{==============================================================================]
  <Range>
  @action: Returns the indexes as TRange where subArray exists in array (Self)
  @note: (-1, -1) if subArray is not found.
         Loops array from index to max.
[==============================================================================}
function MArrayHelper.Range(const subArray: MArray; const index: Integer = 0): TRange; overload;
var
  i, j, a, s, p: Integer;
  f: Boolean;
begin
  Result.start := -1;
  Result.stop  := -1;
  a := Self.Size;
  s := subArray.Size;
  if ((s = 0) or (a = 0) or (s > a) or (index >= a)) then
    Exit;
  p := Max(0, index);
  for i := p to (a - s) do
  begin
    f := True;
    for j := 0 to (s - 1) do
      if (Self[i + j] <> subArray[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
      Exit(Result.Construct(i, ((i + s) - 1)));
  end;
end;

{==============================================================================]
  <Ranges>
  @action: Returns the indexes as TRanges where subArray exists in array (Self)
  @note: [] if not a single subArray is not found.
         Loops array from index to max.
[==============================================================================}
function MArrayHelper.Ranges(const subArray: MArray; const index: Integer = 0): TRangeArray; overload;
var
  i, j, a, s, p, l: Integer;
  f: Boolean;
begin
  SetLength(Result, 0);
  a := Self.Size;
  s := subArray.Size;
  if ((s = 0) or (a = 0) or (s > a) or (index >= a)) then
    Exit;
  p := Max(0, index);
  l := 0;
  for i := p to (a - s) do
  begin
    f := True;
    for j := 0 to (s - 1) do
      if (Self[i + j] <> subArray[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
    begin
      SetLength(Result, l.Increment);
      Result[l - 1].Create(i, ((i + s) - 1));
    end;
  end;
end;

{==============================================================================]
  <Span>
  @action: -
  @note: -
[==============================================================================}
function MArrayHelper.Span: TRange; overload;
begin
  Result.stop := High(Self);
  Result.start := IfThen((Result.stop = -1), -1, 0);
end;

{==============================================================================]
  <Span>
  @action: Returns the indexes as TRange where subArray exists in array (Self)
  @note: (-1, -1) if subArray is not found.
         Loops array from index downto min.
[==============================================================================}
function MArrayHelper.Span(const subArray: MArray; const index: Integer = 2147483647): TRange; overload;
var
  i, j, a, s, p: Integer;
  f: Boolean;
begin
  Result.start := -1;
  Result.stop  := -1;
  a := Self.Size;
  s := subArray.Size;
  if ((s = 0) or (a = 0) or (s > a) or (index < 0)) then
    Exit;
  p := Min(index, (a - s));
  for i := p downto 0 do
  begin
    f := True;
    for j := 0 to (s - 1) do
      if (Self[i + j] <> subArray[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
      Exit(Result.Construct(i, ((i + s) - 1)));
  end;
end;

{==============================================================================]
  <Spans>
  @action: Returns the indexes as TRanges where subArray exists in array (Self)
  @note: [] if not a single subArray is not found.
         Loops array from index downto min.
[==============================================================================}
function MArrayHelper.Spans(const subArray: MArray; const index: Integer = 2147483647): TRangeArray; overload;
var
  i, j, a, s, p, l: Integer;
  f: Boolean;
begin
  SetLength(Result, 0);
  a := Self.Size;
  s := subArray.Size;
  if ((s = 0) or (a = 0) or (s > a) or (index < 0)) then
    Exit;
  p := Min(index, (a - s));
  l := 0;
  for i := p downto 0 do
  begin
    f := True;
    for j := 0 to (s - 1) do
      if (Self[i + j] <> subArray[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
    begin
      SetLength(Result, l.Increment);
      Result[l - 1].Create(i, ((i + s) - 1));
    end;
  end;
end;

{==============================================================================]
  <SubarrayLocation>
  @action: Returns subarray position in arr that match pattern exactly.
  @note: arr[0,1,2,0,1,2,3].([1,2]) => 4	
[==============================================================================}
function MArrayHelper.SubarrayLocation(const pattern: MArray): Integer; overload;
var
  i, j, l, s, p: Integer;
begin
  l := Self.Length;
  p := pattern.Size;
  if ((p > 0) and (p <= l)) then
  for i := (l - p) downto 0 do
  begin
    s := 0;
    for j := 0 to (p - 1) do
      if (Self[i + j] <> pattern[j]) then
        Break
      else
        s := (s + 1);
    if (s = p) then
      Exit(i);
  end;
  Result := -1;
end;

{==============================================================================]
  <SubarrayPosition>
  @action: Returns subarray position in arr that match pattern exactly.
  @note: arr[0,1,2,0,1,2,3].([1,2]) => 1	
[==============================================================================}
function MArrayHelper.SubarrayPosition(const pattern: MArray): Integer; overload;
var
  i, j, l, p: Integer;
  f: Boolean;
begin
  l := Self.Length;
  p := pattern.Size;
  if ((p > 0) and (p <= l)) then
  for i := 0 to (l - p) do
  begin
    f := True;
    for j := 0 to (p - 1) do
      if (Self[i + j] <> pattern[j]) then
      begin
        f := False;
        Break;
      end;
    if f then
      Exit(i);
  end;
  Result := -1;
end;
{$ENDIF}
