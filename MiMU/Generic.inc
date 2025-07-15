{$I Defines.inc}

{==============================================================================]
 <var.TArray(aSize: Integer): TArray>
 @action: Creates TArray with Self.
 @note: aSize will be Length of the created array.
[==============================================================================}
function XVarHelp.TArray(const aSize: Integer = 1): XArr; overload cdecl;
var
  i: Integer;
begin
  SetLength(Result, aSize);
  for i := 0 to High(Result) do
    Result[i] := Self;
end;

{==============================================================================]
 <var.T2DArray(size1D, size2D: Integer): T2DArray>
 @action: Creates 2D array with Self.
 @note: None.
[==============================================================================}
function XVarHelp.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): X2DArr; overload cdecl;
var
  i, j: Integer;
begin
  SetLength(Result, size1D);
  for i := 0 to High(Result) do
  begin
    SetLength(Result[i], size2D);
    for j := 0 to High(Result[i]) do
      Result[i][j] := Self;
  end;
end;

{==============================================================================]
 <arr.Add(item: VarType; duplicates: Boolean): TArray>
 @action: Appends arr with item. Returns the array with added item.
 @note: Adds item to the right side of the array.
[==============================================================================}
function XArrHelp.Add(const item: XVar; const duplicates: Boolean = True): XArr; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := Self[i];
  if ((not duplicates) and Self.Contains(item)) then
    SetLength(Result, l)
  else
    Result[l] := item;
end;

{==============================================================================]
 <arr.Add(items: TArray; duplicates: Boolean): TArray>
 @action: Appends arr with items. Returns the array with added items.
 @note: Adds item to the right side of the array.
[==============================================================================}
function XArrHelp.Add(const items: XArr; const duplicates: Boolean = True): XArr; overload; cdecl;
var
  a, h, i, l: Integer;
begin
  h := High(items);
  l := Length(Self);
  SetLength(Result, (l + (h + 1)));
  if ((h = -1) and (l = 0)) then
    Exit;
  for i := 0 to (l - 1) do
    Result[i] := Self[i];
  case duplicates of
    False:
	begin
	  a := 0;
	  for i := 0 to h do
	    if not Result.Contains(items[i]) then
          Result[l + a.Increase] := items[i];
      SetLength(Result, (l + a));
    end;
    True:
    for i := 0 to h do
      Result[l + i] := items[i];
  end;
end;

{==============================================================================]
 <arr.AllEqual: Boolean>
 @action: Returns true if all values in arr are equal (arr contains only equal values).
 @note: Returns FALSE with empty array!
[==============================================================================}
function XArrHelp.AllEqual: Boolean; overload; cdecl;
var
  h, i, l: Integer;
begin
  l := Low(Self);
  h := High(Self);
  for i := (l + 1) to h do
    if (Self[l] <> Self[i]) then
      Exit(False);
  Result := (Length(Self) > 0);
end;

{==============================================================================]
 <arr.AllSame: Boolean>
 @action: Returns true if all values in arr are the same (arr contains only equal values).
 @note: Returns FALSE with empty array!
[==============================================================================}
function XArrHelp.AllSame: Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[0] <> Self[i]) then
      Exit(False);
  Result := (Length(Self) > 0);
end;

{==============================================================================]
 <arr.AllUnique: Boolean>
 @action: Returns true if all values in arr are unique (arr contains ONLY unique values).
 @note: None
[==============================================================================}
function XArrHelp.AllUnique: Boolean; overload; cdecl;
var
  h, a, b: Integer;
begin
  h := High(Self);
  for a := 0 to (h - 1) do
    for b := (a + 1) to h do
      if (Self[a] = Self[b]) then
        Exit(False);
  Result := (h > -1);
end;

{==============================================================================]
 <arr.Append(item: VarType; duplicates: Boolean): TArray>
 @action: Appends arr with item. Returns the index of added item.
 @note: Adds item to the right side of the array.
[==============================================================================}
function XArrHelp.Append(const item: XVar; const duplicates: Boolean = True): XArr; overload; cdecl;
begin
  Result := Self.Copy;
  if ((not duplicates) and Self.Contains(item)) then
    Exit;
  SetLength(Result, (Length(Self) + 1));
  Result[Length(Self)] := item;
end;

{==============================================================================]
 <arr.Append(items: TArray; duplicates; Boolean): TArray>
 @action: Adds all items items to arr.
 @note: Returns the highest index in the end.
[==============================================================================}
function XArrHelp.Append(const items: XArr; const duplicates: Boolean = True): XArr; overload; cdecl;
var
  a, h, i: Integer;
begin
  Result := Self.Copy;
  h := High(items);
  if (h = -1) then
    Exit;
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
 <arr.Build(item: VarType; aSize: Integer): TArray> 
 @action: Creates array with item where aSize is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}
function XArrHelp.Build(const item: XVar; const aSize: Integer = 1): XArr; overload; cdecl;
begin
  Result := Self.Create(aSize, item);
end;

{==============================================================================]
 <arr.BuiltWith(allowed: TArray): Boolean> 
 @action: Checks if array arr contains only allowed items.
 @note: None.
[==============================================================================}
function XArrHelp.BuiltWith(const allowed: XArr): Boolean; overload; cdecl;
var
  i, x, y: Integer;
begin
  y := Length(allowed);
  i := High(Self);
  if ((i < 0) or (y < 1)) then
    Exit(False);
  repeat
    x := 0;
    repeat
      Result := (Self[i] = allowed[x]);
    until (Result or (x.Increment = y));
  until ((i.Decrement < 0) or (not Result));
end;

{==============================================================================]
 <arr.BuiltWithout(forbidden: TArray): Boolean> 
 @action: Checks if array arr does not have any forbidden items.
 @note: None.
[==============================================================================}
function XArrHelp.BuiltWithout(const forbidden: XArr): Boolean; overload; cdecl;
var
  i, x, y: Integer;
begin
  if (Length(Self) < 1) then
    Exit(False);
  y := Length(forbidden);
  if not (y < 1) then
  begin
    i := High(Self);
    repeat
       x := 0;
       repeat
         Result := not (Self[i] = forbidden[x]);
       until ((x.Increment = y) or (not Result));
    until ((i.Decrement < 0) or (not Result));
  end else
    Result := True;
end;

{==============================================================================]
  <arr.Clear: Boolean>
  @action: SetLength(arr, 0) and returns true if items existed before doing it.
  @note: None.
[==============================================================================}
function XArrHelp.Clear: Boolean; cdecl;
begin
  Result := (Length(Self) > 0);
  SetLength(Self, 0);
end;

{==============================================================================]
 <arr.Clone(index: Integer; count: Integer): TArray>
 @action: Returns copy of an array arr.
 @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}
function XArrHelp.Clone(const index: Integer = 0; const count: Integer = 2147483647): XArr; cdecl;
var
  i, s, c: Integer;
begin
  if (count > 0) then
  begin
    if (index < 0) then
      c := (index + count)
    else
      c := Min(count, (Length(Self) - index));
    s := Max(0, index);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[i - s] := Self[i];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <arr.Clone(ID: TIntegerArray): TArray>
 @action: Outputs array of items from arr by indexes (ID).
 @note: Ignores invalid ID's (doesn't include those to result, they will be left out).
[====================
==========================================================}
function XArrHelp.Clone(const ID: TIntegerArray): XArr; overload; cdecl;
var
  i, h, l, r: Integer;
begin
  r := 0;
  h := High(Self);
  l := Length(ID);
  if ((l > 0) and (h > -1)) then
  begin
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if ((ID[i] <= h) and (ID[i] > -1)) then
        Result[r.Increase] := Self[ID[i]];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Combine(b: TArray): TArray>
 @action: Combines arrays arr and b together as single array.
 @note: This is an alternative method. :)
[==============================================================================}
function XArrHelp.Combine(const b: XArr): XArr; overload; cdecl;
begin
  SetLength(Result, 0);
  Insert(Self, Result, 0);
  Insert(b, Result, Length(Self));
end;

{==============================================================================]
 <arr.Contains(item: VarType; index: Integer): Boolean>
 @action: Looks array for item starting from start index. If found, Result will be True.
 @note: None.
[==============================================================================}
function XArrHelp.Contains(const item: XVar; const index: Integer = 0): Boolean; cdecl;
var
  i: Integer;
begin
  for i := index to High(Self) do
    if (item = Self[i]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
 <arr.Copy(index: Integer; count: Integer): TArray>
 @action: Returns copy of an array arr.
 @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}
function XArrHelp.Copy(const index: Integer = 0; const count: Integer = 2147483647): XArr; overload; cdecl;
var
  i, c, l: Integer;
begin
  l := Length(Self);
  if (index < l) then
  begin
    i := Max(index, 0);
    c := count;
    if ((i + c) > l) then
      c := (l - i);
    SetLength(Result, c);
    for l := 0 to (c - 1) do
      Result[l] := Self[l + i];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <arr.Create(item: VarType): TArray> 
 @action: Creates array with item, size as 1. Returns old Self.
 @note: [item]
[==============================================================================}
function XArrHelp.Create(const item: XVar): XArr; overload; cdecl;
begin
  Result := Self.Clone;
  SetLength(Self, 1);
  Self[0] := item;
end;

{==============================================================================]
 <arr.Create(aSize: Integer; item: VarType): TArray> 
 @action: Creates array with item where aSize is length of the array. Returns old Self.
 @note: item is placed on every index in result.
[==============================================================================}
function XArrHelp.Create(const aSize: Integer; const item: XVar): XArr; overload; cdecl;
var
  i: Integer;
begin
  Result := Self.Clone;
  SetLength(Self, Max(0, aSize));
  for i := 0 to High(Self) do
    Self[i] := item;
end;

{==============================================================================]
 <arr.Delete(index: Integer): TArray>
 @action: Deletes array item from arr by index.
 @note: Returns true with success (index existed in arr).
[==============================================================================}
function XArrHelp.Delete(const index: Integer = 0): XArr; overload; cdecl;
var
  i, h: Integer;
begin
  h := High(Self);
  if not ((index <= h) and (index > -1)) then
    Exit(Self.Copy);
  SetLength(Result, h);
  for i := 0 to (index - 1) do
    Result[i] := Self[i];
  for i := index to (h - 1) do
    Result[i] := Self[i + 1];
end;

{==============================================================================]
 <arr.Delete(ID: TIntegerArray): Integer>
 @action: Deletes array items from arr by indexes (ID).
 @note: Returns amount of items that were deleted succesfully by ID's.
[==============================================================================}
function XArrHelp.Delete(const ID: TIntegerArray): XArr; overload; cdecl;
var
  i, l, r: Integer;
begin
  if (Length(ID) = 0) then
    Exit(Self.Copy);
  l := Length(Self);
  SetLength(Result, l);
  r := 0;
  for i := 0 to (l - 1) do
    if not ID.Contains(i) then
      Result[i - r] := Self[i]
    else
      r := (r + 1);
  SetLength(Result, (l - r));
end;

{==============================================================================]
 <arr.Differ(target: TArray): Boolean>
 @action: Returns true if arr differs from target.
 @note: None
[==============================================================================}
function XArrHelp.Differ(const target: XArr): Boolean; overload; cdecl;
var
  i: Integer;
begin
  Result := (Length(Self) <> Length(target));
  if not Result then
  for i := High(Self) downto 0 do
    if (Self[i] <> target[i]) then
      Exit(True);
end;

{==============================================================================]
 <arr.Distribute(parts: Integer): T2DArray>
 @action: Distributes array arr to 2D array by number of parts.
 @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5][6,7]
 [==============================================================================}
function XArrHelp.Distribute(const parts: Integer): X2DArr; overload; cdecl;
var
  l, p, b, r, i, j, s, c: Integer;
begin
  l := Length(Self);
  if ((parts > 0) and (l > 0)) then
  begin
    p := Min(parts, l);
    SetLength(Result, p);
    b := (l div p);
    r := (l mod p);
    s := 0;
    for i := 0 to (p - 1) do
    begin
      c := b;
      if (i < r) then
        Inc(c);
      SetLength(Result[i], c);
      for j := 0 to (c - 1) do
        Result[i][j] := Self[s.Increase];
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <TArray_Dump(items: TArray; index: Integer): TArray>
 @action: Deletes items from array, keeps others. Returns array length (after action).
 @note: Supports custom start index!
[==============================================================================}
function XArrHelp.Dump(const items: XArr; const index: Integer = 0): XArr; overload; cdecl;
var
  i, l, m, d: Integer;
begin
  l := Length(Self);
  if ((High(items) = -1) or (l = 0)) then
    Exit(Self.Copy);
  SetLength(Result, l);
  d := 0;
  m := Max(0, index);
  for i := 0 to (m - 1) do
    Result[i] := Self[i];
  for i := m to (l - 1) do
    if not items.Contains(Self[i]) then
      Result[i - d] := Self[i]
    else
      Inc(d);
  if (d > 0) then
    SetLength(Result, (l - d));
end;

{==============================================================================]
 <arr.Dupe: TArray>
 @action: Returns copy of an array arr.
 @note: None.
[==============================================================================}
function XArrHelp.Dupe: XArr; overload; cdecl;
var
  i, l, j: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  if ((l mod 2) <> 0) then
  begin
    j := (l div 2);
    Result[j] := Self[j];
  end;
  if (l > 1) then
  for i := 0 to ((l div 2) - 1) do
  begin
    j := ((l - i) - 1);
    Result[i] := Self[i];
    Result[j] := Self[j];
  end;
end;

{==============================================================================]
 <arr.Duplicate(xTimes: Integer): TArray>
 @action: Returns copy of an array arr.
 @note: None.
[==============================================================================}
function XArrHelp.Duplicate(const xTimes: Integer = 1): XArr; overload; cdecl;
var
  m, i, j, l: Integer;
begin
  l := Length(Self);
  m := Max(0, xTimes);
  SetLength(Result, (m * l));
  if (l > 0) then
  for i := 0 to (m - 1) do
    for j := 0 to (l - 1) do
      Result[(i * l) + j] := Self[j];
end;

{==============================================================================]
 <arr.Empty: Boolean>
 @action: Returns true if array is empty (Length = 0).
 @note: None.
[==============================================================================}
function XArrHelp.Empty: Boolean; overload; cdecl;
begin
  Result := (Length(Self) = 0);
end;

{==============================================================================]
 <arr.Equal(target: TArray): Boolean>
 @action: Returns true if arr equals target (identical arrays)
 @note: None
[==============================================================================}
function XArrHelp.Equal(const target: XArr): Boolean; overload; cdecl;
var
  i: Integer;
begin
  Result := (Length(Self) = Length(target));
  if Result then
  for i := High(Self) downto 0 do
    if (Self[i] <> target[i]) then
      Exit(False);
end;

{==============================================================================]
 <arr.Erase(item: VarType; index: Integer; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function XArrHelp.Erase(const item: XVar; const index: Integer = 2147483647; const all: Boolean = True): XArr; overload; cdecl;
var
  j, i, m, l, d: Integer;
  f: Boolean;
  r: TBooleanArray;
begin
  l := Length(Self);
  if not ((l = 0) or (index < 0)) then
  begin
    SetLength(r, l);
    m := Min(index, (l - 1));
	d := 0;
    for i := m downto 0 do
    begin
      f := False;
      if (Self[i] = item) then
      begin
        r[i] := True;
        Inc(d);
        f := True;
      end;
      if (f and (not all)) then
        Break;
    end;
    j := 0;
	SetLength(Result, (l - d));
    for i := 0 to (l - 1) do
      if not r[i] then
        Result[j.Increase] := Self[i];
    SetLength(Result, j);
  end else
    Result := Self.Copy;
end;

{==============================================================================]
 <arr.Erase(item: VarType; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed.
[==============================================================================}
function XArrHelp.Erase(const item: XVar; const all: Boolean): XArr; overload; cdecl;
begin
  Result := Self.Erase(item, 2147483647, all);
end;

{==============================================================================]
 <arr.Erase(items: TArray; index: Integer; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function XArrHelp.Erase(const items: XArr; const index: Integer = 2147483647; const all: Boolean = True): XArr; overload; cdecl;
var
  h, i, j, m, l, d: Integer;
  f: Boolean;
  r: TBooleanArray;
begin
  h := High(items);
  l := Length(Self); 
  if not ((l = 0) or (h < 0) or (index < 0)) then
  begin
    SetLength(r, l);
    m := Min(index, (l - 1));
	d := 0;
    for i := m downto 0 do
    begin
      f := False;
      for j := 0 to h do
        if (Self[i] = items[j]) then
        begin
          r[i] := True;
          Inc(d);
          f := True;
          Break;
        end;
      if (f and (not all)) then
        Break;
    end;
	j := 0;
	SetLength(Result, (l - d)); 
    for i := 0 to (l - 1) do
      if not r[i] then
        Result[j.Increase] := Self[i];
    SetLength(Result, j);
  end else
    Result := Self.Copy;
end;

{==============================================================================]
 <arr.Erase(items: TArray; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed.
[==============================================================================}
function XArrHelp.Erase(const items: XArr; const all: Boolean): XArr; overload; cdecl;
begin
  Result := Self.Erase(items, 2147483647, all);
end;

{==============================================================================]
 <arr.Excessive: Boolean>
 @action: Returns true if arr contains any duplicates in it.
 @note: None.
[==============================================================================}
function XArrHelp.Excessive: Boolean; overload; cdecl; 
type
  TDict = specialize TDictionary<XVar, Boolean>;
var
  d: TDict;
  i: Integer;
begin
  d := TDict.Create;
  try
    for i := Low(Self) to High(Self) do
      if not d.ContainsKey(Self[i]) then
        d.Add(Self[i], True)
      else
        Exit(True);
  finally
    d.Free;
  end;
  Result := False;
end;

{==============================================================================]
 <arr.Exch(aIndex, bIndex: Integer): Boolean>
 @action: Fast version of Exchange().
 @note: Unsafe, no checking.
[==============================================================================}
function XArrHelp.Exch(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
var
  c: XVar;
begin
  Result := (Self[aIndex] <> Self[bIndex]);
  c := Self[aIndex];
  Self[aIndex] := Self[bIndex];
  Self[bIndex] := c;
end;

{==============================================================================]
 <arr.Exchange(aIndex, bIndex: Integer): Boolean>
 @action: Swap items aIndex and bIndex in array arr.
 @note: Returns true with success.
[==============================================================================}
function XArrHelp.Exchange(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
var
  c: XVar;
  h: Integer;
begin
  h := High(Self);
  Result := ((h > 0) and (aIndex <> bIndex) and InRange(aIndex, 0, h) and InRange(bIndex, 0, h) and (Self[aIndex] <> Self[bIndex]));
  if Result then
  begin
    c := Self[aIndex];
    Self[aIndex] := Self[bIndex];
    Self[bIndex] := c;
  end;
end;

{==============================================================================]
 <arr.Exclude(items: TArray; index: Integer): TArray>
 @action: Returns a new array with elements from items excluded, up to and including the specified index.
 @note: Elements after index are copied without filtering. If index is out of bounds, it is clamped to the array length.
         The default index filters the entire array.
[==============================================================================}
function XArrHelp.Exclude(const items: XArr; const index: Integer = 2147483647): XArr; overload; cdecl;
var
  i, l, m, d: Integer;
begin
  l := Length(Self);
  if ((High(items) = -1) or (l = 0)) then
    Exit(Self.Copy);
  m := Min(index, (l - 1));
  SetLength(Result, l);
  d := 0;
  for i := 0 to m do
    if not items.Contains(Self[i]) then
      Result[i - d] := Self[i]
    else
      Inc(d);
  for i := (m + 1) to (l - 1) do
    Result[i - d] := Self[i];
  if (d > 0) then
    SetLength(Result, (l - d));
end;

{==============================================================================]
 <arr.Extend(item: VarType): TArray>
 @action: Extends arr with item. Returns it.
 @note: Places item to the left side of the array.
[==============================================================================}
function XArrHelp.Extend(const item: XVar): XArr; overload; cdecl;
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
 <arr.Extend(items: TArray): TArray>
 @action: Extends arr with items. Returns it.
 @note: Places items to the left side of the array.
[==============================================================================}
function XArrHelp.Extend(const items: XArr): XArr; overload; cdecl;
var
  i, h, l: Integer;
begin
  h := High(Self);
  l := Length(items);
  SetLength(Result, ((h + 1) + l));
  for i := 0 to h do
    Result[i + l] := Self[i];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;

{==============================================================================]
 <arr.Extract(item: VarType; index: Integer): TArray>
 @action: Keeps (extracts) all values in arr that are item. Starts scan from start index.
 @note: Returns the items.
[==============================================================================} 
function XArrHelp.Extract(const item: XVar; const index: Integer = 0): XArr; overload; cdecl;
var
  i, l, r: Integer;
begin
  l := Length(Self);
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (Self[i] = item) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Extract(items: TArray; index: Integer): TArray>
 @action: Keeps (extracts) all values in arr that are in items. Starts scan from start index.
 @note: Returns the items.
[==============================================================================}
function XArrHelp.Extract(const items: XArr; const index: Integer = 0): XArr; overload; cdecl;
var
  i, l, r: Integer;
begin
  r := 0;
  if (Length(items) > 0) then
  begin
    l := Length(Self);
    SetLength(Result, (l - index));
    for i := index to (l - 1) do
      if items.Contains(Self[i]) then
        Result[r.Increase] := Self[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.ExtractEvery(X: Integer; index: Integer): TArray>
 @action: Keeps (extracts) all X values from array. Starts scan from start index.
 @note: Returns the items.
[==============================================================================} 
function XArrHelp.ExtractEvery(const X: Integer = 1; const index: Integer = 0): XArr; overload; cdecl;
var
  i, h, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if (((i - index) mod X) = 0) then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
 <arr.Fill(item: VarType; index: Integer; count: Integer): TArray>
 @action: Fills whole arr with item.
 @note: Returns the filled array.
[==============================================================================}
function XArrHelp.Fill(const item: XVar; const index: Integer = 0; const count: Integer = 2147483647): XArr; overload; cdecl;
var
  h, i, s, t: Integer;
begin
  s := Max(0, index);
  h := High(Self);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := Self[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := item;
  for i := (t + 1) to h do
    Result[i] := Self[i];
end;

{==============================================================================]
 <arr.Fill(items: TArray; index: Integer; count: Integer): TArray>
 @action: Fills whole arr with items.
 @note: None
[==============================================================================}
function XArrHelp.Fill(const items: XArr; const index: Integer = 0; const count: Integer = 2147483647): XArr; overload; cdecl;
var
  h, i, s, t, l: Integer;
begin
  h := High(Self);
  l := Length(items);
  case l of
    0: Exit(Self.Copy);
    1: Exit(Self.Fill(items[0], index, count));
  end;
  s := Max(0, index);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := Self[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[(index + i) mod (l - 1)];
  for i := (t + 1) to h do
    Result[i] := Self[i];
end;

{==============================================================================]
 <arr.Filter(item: VarType; index: Integer): TArray>
 @action: Removes all values from arr that are found in items.
 @note: None
[==============================================================================}
function XArrHelp.Filter(const item: XVar; const index: Integer = 0): XArr; overload; cdecl;
var
  i, l, r: Integer;
begin
  l := Length(Self);
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (Self[i] <> item) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Filter(items: TArray; index: Integer): TArray>
 @action: Removes all values from arr that are found in items.
 @note: None
[==============================================================================}
function XArrHelp.Filter(const items: XArr; const index: Integer = 0): XArr; overload; cdecl;
var
  i, l, r: Integer;
begin
  l := Length(Self);
  if (Length(items) = 0) then
    Exit(Self.Copy(index, (l - index)));
  r := 0;
  SetLength(Result, (l - index));
  for i := index to (l - 1) do
    if not items.Contains(Self[i]) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.FilterEvery(X: Integer; index: Integer): TArray>
 @action: Filters every/each X item from arr.
 @note: Custom index
[==============================================================================}
function XArrHelp.FilterEvery(const X: Integer = 1; const index: Integer = 0): XArr; overload; cdecl;
var
  i, h, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if not (((i - index) mod X) = 0) then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
 <arr.Find(item: VarType; ID: TRange): Integer>
 @action: Scans array for item by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function XArrHelp.Find(const ID: TRange; const item: XVar): Integer; overload; cdecl;
begin
  if (High(Self) > -1) then
  case ID.Ascending of
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
 <arr.Find(item: VarType; ID: TIntegerArray): Integer>
 @action: Scans array for item by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function XArrHelp.Find(const ID: TIntegerArray; const item: XVar): Integer; overload; cdecl;
var
  i: Integer;
begin
  if (High(Self) > -1) then
  for i := 0 to High(ID) do
    if (Self[ID[i]] = item) then
      Exit(ID[i]);
  Result := -1;
end;

{==============================================================================]
 <arr.Find(items: TArray; ID: TRange): Integer>
 @action: Scans array for items by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function XArrHelp.Find(const ID: TRange; const items: XArr): Integer; overload; cdecl;
begin
  if ((High(Self) > -1) and (High(items) > -1)) then
  case ID.Ascending of
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
 <arr.Find(items: TArray; ID: TIntegerArray): Integer>
 @action: Scans array for items by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function XArrHelp.Find(const ID: TIntegerArray; const items: XArr): Integer; overload; cdecl;
var
  i: Integer;
begin
  if ((High(Self) > -1) and (High(items) > -1)) then
  for i := 0 to High(ID) do
    if items.Contains(Self[ID[i]]) then
      Exit(ID[i]);
  Result := -1;
end;

{==============================================================================]
 <arr.Flip: Boolean>
 @action: Reverses array arr.
 @note: Alternative for TArray_Reverse
[==============================================================================}
function XArrHelp.Flip: Boolean; overload; cdecl;
var
  i, l: Integer;
begin
  i := 0;
  l := (Length(Self) - 1);
  Result := (l > 0);
  while (i < l) do
    Exchange(i.Increase, l.Decrease);
end;

{==============================================================================]
 <arr.FromLeft(count, index): TArray>
 @action: Returns count of array items from left-side by index.
 @note: None
[==============================================================================}
function XArrHelp.FromLeft(const count: Integer; const index: Integer = 2147483647): XArr; overload; cdecl;
var
  m: Integer;
  a, r, i: TRange;
begin
  m := Min(High(Self), index);
  a.Build(0, High(Self));
  if ((count > 0) and a.Intersect(r.Create((m - count), (m - 1)), i)) then
    Result := Self.Copy(i.start, ((i.stop - i.start) + 1))
  else
    SetLength(Result, 0);
end;

{==============================================================================]
 <arr.FromRight(count, index): TArray>
 @action: Returns count of array items from right-side by index.
 @note: None
[==============================================================================}
function XArrHelp.FromRight(const count: Integer; const index: Integer = 0): XArr; overload; cdecl;
var
  m: Integer;
  a, r, i: TRange;
begin
  m := Max(0, index);
  a.Build(0, High(Self));
  if ((count > 0) and a.Intersect(r.Create((m + 1), (m + count)), i)) then
    Result := Self.Copy(i.start, ((i.stop - i.start) + 1))
  else
    SetLength(Result, 0);
end;

{==============================================================================]
 <arr.Get: TArray>
 @action: Copy of an array arr.
 @note: Just an alternative.
[==============================================================================}
function XArrHelp.Get: XArr; overload; cdecl;
var
  a: XVar;
  i: Integer;
begin
  SetLength(Result, Length(Self));
  i := 0;
  for a in Self do
    Result[i.Increase] := a;
 end;

{==============================================================================]
 <arr.Get(ID: TIntegerArray): TArray>
 @action: Outputs array of items from arr by indexes (IDs).
 @note: Unsafe method! No safety checking.
[==============================================================================}
function XArrHelp.Get(const ID: TIntegerArray): XArr; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(ID));
  for i := 0 to High(ID) do
    Result[i] := Self[ID[i]];
end;

{==============================================================================]
 <arr.Get(ID: TRange): TArray>
 @action: Outputs array of items from arr by indexes (IDs).
 @note: Unsafe method! No safety checking.
[==============================================================================}
function XArrHelp.Get(const ID: TRange): XArr; overload; cdecl;
var
  i, a: Integer;
begin
  SetLength(Result, ID.Size);
  a := 0;
  case ID.Ascending of
    True:
    for i := ID.start to ID.stop do
      Result[a.Increase] := Self[i];
	False:
    for i := ID.start downto ID.stop do
      Result[a.Increase] := Self[i];
  end;
end;

{==============================================================================]
 <arr.Group: T2DArray>
 @action: Groups array arr to 2D array by items.
 @note: ([1,2,1,2,3,1,2,3,4]) => [1,1,1][2,2,2][3,3][4]
[==============================================================================}
function XArrHelp.Group: X2DArr; overload; cdecl;
var
  a, h, i, r, g, l: Integer;
  f: Boolean;
begin
  h := High(Self);
  SetLength(Result, (h + 1));
  if (h = -1) then
    Exit;
  g := -1;
  for i := 0 to h do
  begin
    f := False;
    for r := 0 to g do
    begin
      f := (Self[i] = Result[r][0]);
      if f then
      begin
        l := Length(Result[r]);
        SetLength(Result[r], (l + 1));
        Result[r][l] := Self[i];
        Break;
      end;
    end;
    if not f then
    begin
      SetLength(Result[g.Increment], 1);
      Result[g][0] := Self[i];
    end;
  end;
  SetLength(Result, (g + 1));
end;

{==============================================================================]
 <arr.Holds(chain: TArray): Boolean>
 @action: Returns true if arr contains (holds) WHOLE chain of items in it.
 @note: Starting from any index and ending to any index!
[==============================================================================}
function XArrHelp.Holds(const chain: XArr): Boolean; overload; cdecl;
var
  a, b, x, y, z: Integer;
  n: Boolean;
begin
  z := High(Self);
  y := High(chain);
  if ((z < y) or (y = -1)) then
    Exit(False);
  a := -1;
  b := (z - y);
  repeat
    a := (a + 1);
    for x := 0 to y do
    begin
      n := (Self[a + x] <> chain[x]);
      if n then
        Break;
    end;
    Result := not n;
  until ((a = b) or Result);
end;

{==============================================================================]
 <arr.IDs(aAscending: Boolean): TIntegerArray>
 @action: Returns IDs of arr as TIntegerArray.
 @note: None.
[==============================================================================}
function XArrHelp.IDs(const aAscending: Boolean = True): TIntegerArray; overload; cdecl;
var
  h, i: Integer;
begin
  SetLength(Result, Length(Self));
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
 <arr.IDs(IDs: TIntegerArray): TArray>
 @action: Returns items from arr by IDs.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array.
[==============================================================================}
function XArrHelp.IDs(const ID: TIntegerArray): XArr; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(ID));
  for i := 0 to High(Result) do
    Result[i] := Self[ID[i]];
end;

{==============================================================================]
 <arr.IDs(IDs: TIntegerArray; item: VarType): TArray>
 @action: Returns arr with IDs replaced as item.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array.
[==============================================================================}
function XArrHelp.IDs(const ID: TIntegerArray; const item: XVar): XArr; overload; cdecl;
var
  i: Integer;
begin
  Result := Self.Copy;
  for i := 0 to High(ID) do
    Result[ID[i]] := item;
end;

{==============================================================================]
 <arr.IDs(IDs: TIntegerArray; items: TArray): TArray>
 @action: Returns arr with IDs replaced as items.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array and ALSO item[s].
[==============================================================================}
function XArrHelp.IDs(const ID: TIntegerArray; const items: XArr): XArr; overload; cdecl;
var
  i, l: Integer;
begin
  Result := Self.Copy;
  l := Length(items);
  for i := 0 to High(ID) do
    Result[ID[i]] := items[i mod l];
end;

{==============================================================================]
 <arr.Includes(item: VarType; index: Integer): Boolean>
 @action: Looks array for item starting from start index down to index 0. If found, Result will be True.
 @note: Alternative to TArray_Contains, but this scans in opposite direction.
[==============================================================================}
function XArrHelp.Includes(const item: XVar; const index: Integer = 2147483647): Boolean; cdecl;
var
  i: Integer;
begin
  for i := Min(High(Self), index) downto 0 do
    if (item = Self[i]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
 <arr.Keep(items: TArray; index: Integer): TArray>
 @action: Keeps items in array, removes others.
 @note: Supports custom start index! Returns the modified arr.
[==============================================================================}
function XArrHelp.Keep(const items: XArr; const index: Integer = 0): XArr; overload; cdecl;
var
  m, i, l, r: Integer;
begin
  l := Length(Self);
  m := Max(0, index);
  case ((High(items) > -1) and (m < l)) of
    True:
    begin
      r := 0;
	  SetLength(Result, l);
	  for i := 0 to (m - 1) do
	    Result[i] := Self[i];
      for i := m to (l - 1) do
        if items.Contains(Self[i]) then
          Result[i - r] := Self[i]
        else
          Inc(r);
	  SetLength(Result, (l - r));
    end;
    False: Result := Self.Copy;
  end;
end;

{==============================================================================]
 <arr.LeastFrequent: VarType> 
 @action: Returns the least frequent arr item.
 @note: None.
[==============================================================================}
function XArrHelp.LeastFrequent: XVar; overload; cdecl;
var
  i, j, c, m: Integer;
  f: Boolean;
begin
  if (Length(Self) = 0) then
    Exit;
  m := 2147483647;
  Result := Self[0];
  for i := 0 to High(Self) do
  begin
    f := False;
    for j := 0 to (i - 1) do
      if (Self[j] = Self[i]) then
      begin
        f := True;
        Break;
      end;
    if f then
      Continue;
    c := 1;
    for j := (i + 1) to High(Self) do
      if (Self[j] = Self[i]) then
        Inc(c);
    if (c < m) then
    begin
      m := c;
      Result := Self[i];
    end;
  end;
end;

{==============================================================================]
 <arr.Len: Integer>
 @action: Simply Result := Length(arr);
 @note: None.
[==============================================================================}
function XArrHelp.Len: Integer; overload; cdecl;
begin
  Result := Length(Self);
end;

{==============================================================================]
 <arr.Loc(item: VarType; index: Integer): Integer>
 @action: Returns last index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function XArrHelp.Loc(const item: XVar; const index: Integer = 2147483647): Integer; overload; cdecl;
begin
  for Result := Min(High(Self), index) downto 0 do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Loc(items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function XArrHelp.Loc(const items: XArr; const index: Integer = 2147483647): Integer; overload; cdecl;
var
  h, i: Integer;
begin
  h := High(items);
  if (h > -1) then
  for Result := Min(High(Self), index) downto 0 do
    for i := 0 to h do
      if (Self[Result] = items[i]) then
        Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Location(item: VarType; index: Integer): Integer>
 @action: Returns index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function XArrHelp.Location(const item: XVar; const index: Integer = 2147483647): Integer; overload; cdecl;
var
  l: Integer;
begin
  l := Length(Self);
  Result := Min(l, (index + 1));
  while (Result.Decrement > -1) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Location(items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function XArrHelp.Location(const items: XArr; const index: Integer = 2147483647): Integer; overload; cdecl;
var
  h, i, l: Integer;
begin
  h := High(items);
  if (h > -1) then
  begin
    l := Length(Self);
    Result := Min(l, (index + 1));
    while (Result.Decrement > -1) do
      for i := 0 to h do
        if (Self[Result] = items[i]) then
          Exit;
  end;
  Result := -1;
end;

{==============================================================================]
 <arr.Locations(item: VarType; index: Integer): TIntegerArray>
 @action: Returns last index positions from arr which matched with item.
 @note: None.
[==============================================================================}
function XArrHelp.Locations(const item: XVar; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(Self);
  s := Min(index, h);
  if ((h > -1) and (s > -1)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if (Self[i] = item) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Locations(items: TArray; index: Integer): TIntegerArray>
 @action: Returns last index positions from arr which matches with items.
 @note: None.
[==============================================================================}
function XArrHelp.Locations(const items: XArr; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(Self);
  s := Min(index, h);
  if ((h > -1) and (s > -1) and (Length(items) > 0)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if items.Contains(Self[i]) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Mix(shuffles: Integer): Boolean>
 @action: Ramdomizes array with custom shuffles.
 @note: None.
[==============================================================================}
function XArrHelp.Mix(const shuffles: Integer = 1): Boolean; overload; cdecl;
var
  l, i, s: Integer;
begin
  l := Length(Self);
  Result := ((l > 1) and (shuffles > 0));
  if not Result then
    Exit;
  for s := 1 to shuffles do
    for i := 0 to (l - 1) do
      Exchange(Random(l), Random(l));
end;

{==============================================================================]
 <arr.MostFrequent: VarType> 
 @action: Returns the most frequent arr item.
 @note: None.
[==============================================================================}
function XArrHelp.MostFrequent: XVar; overload; cdecl;
var
  i, j, c, m: Integer;
begin
  if (High(Self) = -1) then
    Exit;
  m := 0;
  Result := Self[0];
  for i := 0 to High(Self) do
  begin
    c := 1;
    for j := (i + 1) to High(Self) do
      if (Self[j] = Self[i]) then
        Inc(c);
    if (c > m) then
    begin
      m := c;
      Result := Self[i];
    end;
  end;
end;

{==============================================================================]
 <arr.Move(oldIndex, newIndex: Integer): Boolean>
 @action: Moves item from oldIndex to newIndex in array arr.
 @note: Returns true with success.
[==============================================================================}
function XArrHelp.Move(const oldIndex, newIndex: Integer): Boolean; overload; cdecl;
var
  s: XVar;
  h, i: Integer;
begin
  h := High(Self);
  Result := ((h > 0) and (oldIndex <> newIndex) and InRange(oldIndex, 0, h) and InRange(newIndex, 0, h));
  if Result then
  begin
    s := Self[oldIndex];
    case (oldIndex > newIndex) of
      True:
      for i := oldIndex downto (newIndex + 1) do
        Self[i] := Self[i - 1];
      False:
      for i := oldIndex to (newIndex - 1) do
        Self[i] := Self[i + 1];
    end;
    Self[newIndex] := s;
  end;
end;

{==============================================================================]
 <arr.Next(index: Integer; count: Integer): TArray>
 @action: Returns next items from array by index and count.
 @note: None.	
[==============================================================================}
function XArrHelp.Next(const index: Integer; const count: Integer = 2147483647): XArr; overload; cdecl;
var
  m, i: Integer;
begin
  if ((index >= 0) and (index < (Length(Self) - 1)) and (count > 0)) then
  begin
    m := Min((Length(Self) - (index + 1)), count);
    SetLength(Result, m);
    for i := 0 to (m - 1) do
      Result[i] := Self[(index + 1) + i];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <arr.Oversize(limit: Integer): Boolean>
 @action: Returns true if size of arr is OVER the limit.
 @note: None.	
[==============================================================================}
function XArrHelp.Oversize(const limit: Integer): Boolean; overload; cdecl;
begin
  Result := (Length(Self) > limit);
end;

{==============================================================================]
 <arr.Partition(pSize: Integer): T2DArray>
 @action: Partitions array arr to 2D array by size of parts.
 @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5,6][7]
[==============================================================================}
function XArrHelp.Partition(const pSize: Integer): X2DArr; overload; cdecl;
var
  p, i, j, s, r, l: Integer;
begin
  l := Length(Self);
  if ((pSize > 0) and (l > 0)) then
  begin
    p := ((l + (pSize - 1)) div pSize);
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      s := (i * pSize);
      if ((s + pSize) > l) then
        r := (l - s)
      else
        r := pSize;
      SetLength(Result[i], r);
      for j := 0 to (r - 1) do
        Result[i][j] := Self[s + j];
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <arr.Pick(items: TArray; index: Integer): TArray>
 @action: Alternative method for arr.Keep
 @note: None.
[==============================================================================}
function XArrHelp.Pick(const items: XArr; const index: Integer = 0): XArr; overload; cdecl;
var
  i, m, l: Integer;
begin
  l := Length(Self);
  m := Max(0, index);
  case ((High(items) > -1) and (m < l)) of
    True:
    begin
      SetLength(Result, m);
      for i := 0 to (m - 1) do
        Result[i] := Self[i];
      for i := m to (l - 1) do
        if items.Contains(Self[i]) then
        begin
          SetLength(Result, (Length(Result) + 1));
          Result[High(Result)] := Self[i];
        end;
    end;
    False: Result := Self.Copy;
  end;
end;

{==============================================================================]
 <arr.Pop: VarType>
 @action: Returns and removes item from highest array index from arr.
 @note: UNSAFE! Make sure array has enough items..
[==============================================================================}
function XArrHelp.Pop: XVar; overload; cdecl;
var
  h: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit;
  Result := Self[h];
  SetLength(Self, h);
end;

{==============================================================================]
 <arr.Pop(null: VarType): VarType>
 @action: Returns and removes item from highest array index from arr.
 @note: Returns null if array contains no items.
[==============================================================================}
function XArrHelp.Pop(const null: XVar): XVar; overload; cdecl;
var
  h: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit(null);
  Result := Self[h];
  SetLength(Self, h);
end;

{==============================================================================]
 <arr.Populate(items: TArray; times: Integer): Boolean>
 @action: Populates array with items, x-times.
 @note: Returns true if items is not empty and times is more than 0.
[==============================================================================}
function XArrHelp.Populate(const items: XArr; const times: Integer = 1): Boolean; overload; cdecl;
var
  i, j, l: Integer;
begin
  l := Length(items);
  SetLength(Self, (l * times));
  Result := (Length(Self) > 0);
  if Result then
  for i := 0 to (l - 1) do
    for j := 0 to (times - 1) do
      Self[i + (j * l)] := items[i];
end;

{==============================================================================]
 <arr.Populate(item: VarType; times: Integer): Boolean>
 @action: Populates array with item, x-times.
 @note: Returns true if times is more than 0.
[==============================================================================}
function XArrHelp.Populate(const item: XVar; const times: Integer = 1): Boolean; overload; cdecl;
var
  i: Integer;
begin;
  SetLength(Self, times);
  Result := (Length(Self) > 0);
  if Result then
  for i := 0 to (times - 1) do
    Self[i] := item;
end;  

{==============================================================================]
 <arr.Pos(item: VarType; index: Integer): Integer>
 @action: Returns index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function XArrHelp.Pos(const item: XVar; const index: Integer = 0): Integer; overload; cdecl;
begin
  for Result := Max(0, index) to High(Self) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Pos(items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function XArrHelp.Pos(const items: XArr; const index: Integer = 0): Integer; overload; cdecl;
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
 <arr.Position(item: VarType; index: Integer): Integer>
 @action: Returns index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function XArrHelp.Position(const item: XVar; const index: Integer = 0): Integer; overload; cdecl;
var
  l: Integer;
begin
  Result := Max(-1, (index - 1));
  l := Length(Self);
  while (Result.Increment < l) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Position(items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
function XArrHelp.Position(const items: XArr; const index: Integer = 0): Integer; overload; cdecl;
var
  h, i, l: Integer;
begin
  h := High(items);
  if (h > -1) then
  begin
    Result := Max(-1, (index - 1));
    l := Length(Self);
    while (Result.Increment < l) do
      for i := 0 to h do
        if (Self[Result] = items[i]) then
          Exit;
  end;
  Result := -1;
end;

{==============================================================================]
 <arr.Positions(item: VarType; index: Integer): TIntegerArray>
 @action: Returns index positions from arr which matched with item.
 @note: None.
[==============================================================================}
function XArrHelp.Positions(const item: XVar; const index: Integer = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(Self);
  s := Max(0, index);
  if ((h > -1) and (s <= h)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if (Self[i] = item) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Positions(items: TArray; index: Integer): TIntegerArray>
 @action: Returns index positions from arr which matches with items.
 @note: None.
[==============================================================================}
function XArrHelp.Positions(const items: XArr; const index: Integer = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(Self);
  s := Max(0, index);
  if ((h > -1) and (s <= h) and (Length(items) > 0)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if items.Contains(Self[i]) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Previous(index: Integer; count: Integer): TIntegerArray>
 @action: Returns previous array items from index by count.
 @note: None.
[==============================================================================}
function XArrHelp.Previous(const index: Integer; const count: Integer = 2147483647): XArr; overload; cdecl;
var
  m, l, i: Integer;
begin
  if ((index > 0) and (index < Length(Self)) and (count > 0)) then
  begin
    m := Max(0, (index - count));
    l := (((index - 1) - m) + 1);
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      Result[i] := Self[m + i];
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <arr.Put(ID: TIntegerArray; item: VarType): TArray>
 @action: Returns array arr filled with item to indexes (ID).
 @note: Unsafe method! No safety checking.
[==============================================================================}
function XArrHelp.Put(const ID: TIntegerArray; const item: XVar): XArr; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  for i := 0 to High(ID) do
    Result[ID[i]] := item;
end;

{==============================================================================]
 <arr.Put(ID: TIntegerArray; items: TArray): TArray>
 @action: Returns array arr filled with items to indexes (ID).
 @note: Unsafe method! No safety checking.
[==============================================================================}
function XArrHelp.Put(const ID: TIntegerArray; const items: XArr): XArr; overload; cdecl;
var
  i, l: Integer;
begin
  SetLength(Result, Length(Self));
  l := Length(items);
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  for i := 0 to High(ID) do
    Result[ID[i]] := items[i mod l];
end;

{==============================================================================]
 <arr.Put(index: Integer; items: TArray): TArray>
 @action: Returns array arr filled with items to starting from custom start index.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function XArrHelp.Put(const index: Integer; const items: XArr): XArr; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  for i := 0 to High(items) do
    Result[index + i] := items[i];
end;

{==============================================================================]
 <arr.Push(item: VarType): Integer>
 @action: Places item in array with arr.
 @note: Returns array (arr+item) length.
[==============================================================================}
function XArrHelp.Push(const item: XVar): XArr; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := Self[i];
  Result[l] := item;
end;

{==============================================================================]
 <arr.Push(items: TArray): Integer>
 @action: Places items in array with arr.
 @note: Returns array (arr+item) length.
[==============================================================================}
function XArrHelp.Push(const items: XArr): XArr; overload; cdecl;
var
  h, i, l: Integer;
begin
  h := High(items);
  l := Length(Self);
  SetLength(Result, (l + (h + 1)));
  for i := 0 to (l - 1) do
    Result[i] := Self[i];
  for i := 0 to h do
    Result[l + i] := items[i];
end;

{==============================================================================]
 <arr.Reject(items: TArray; index: Integer): TArray>
 @action: Returns a new array with elements from items excluded, up to and including the specified index.
 @note: Elements after index are copied without filtering. If index is out of bounds, it is clamped to the array length.
         The default index filters the entire array.
[==============================================================================}
function XArrHelp.Reject(const items: XArr; const index: Integer = 2147483647): XArr; overload; cdecl;
var
  i, l, m, c: Integer;
begin
  l := Length(Self);
  if ((High(items) = -1) or (l = 0)) then
    Exit(Self.Copy);
  m := Min(index, (l - 1));
  c := 0;
  for i := 0 to m do
    if not items.Contains(Self[i]) then
      Inc(c);
  SetLength(Result, (c + (l - (m + 1))));
  c := 0;
  for i := 0 to m do
    if not items.Contains(Self[i]) then
      Result[c.Increase] := Self[i];
  for i := (m + 1) to (l - 1) do
    Result[c.Increase] := Self[i];
end;


{==============================================================================]
 <arr.Remove(item: VarType; index: Integer; all: Boolean): Integer>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function XArrHelp.Remove(const item: XVar; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
var
  l, i, r, m: Integer;
  s: Boolean;
begin
  l := Length(Self);
  if ((l = 0) or (index >= l)) then
    Exit(0);
  m := Max(0, index);
  s := False;
  r := 0;
  for i := m to (l - 1) do
    if (s or (Self[i] <> item)) then
      Self[r.Increase + m] := Self[i]
    else
      s := not all;
  SetLength(Self, (r + m));
  Result := (l - Length(Self));
end;

{==============================================================================]
 <arr.Remove(item: VarType; all: Boolean): Integer>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed.
[==============================================================================}
function XArrHelp.Remove(const item: XVar; const all: Boolean): Integer; overload; cdecl;
begin
  Result := Self.Remove(item, 0, all);
end;

{==============================================================================]
 <arr.Remove(items: TArray; index: Integer; all: Boolean): Integer>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function XArrHelp.Remove(const items: XArr; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
var
  a, b, l, i, r, m: Integer;
  d, s: Boolean;
begin
  l := Length(Self);
  b := High(items);
  if ((l = 0) or (index >= l) or (b = -1)) then
    Exit(0);
  m := Max(0, index);
  r := 0;
  s := False;
  for i := m to (l - 1) do
  begin
    if not s then
    for a := 0 to b do
    begin
      d := (Self[i] = items[a]);
      if d then
      begin
        s := not all;
        Break;
      end;
    end;
    if not d then
      Self[r.Increase + m] := Self[i]
    else
      d := not s;
  end;
  SetLength(Self, (r + m));
  Result := (l - Length(Self));
end;

{==============================================================================]
 <arr.Remove(items: TArray; all: Boolean): Integer>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed.
[==============================================================================}
function XArrHelp.Remove(const items: XArr; const all: Boolean): Integer; overload; cdecl;
begin
  Result := Self.Remove(items, 0, all);
end;

{==============================================================================]
 <arr.Resize(aChange: Integer): Integer>
 @action: Updates's arr length with aChange.
 @note: aChange > 0 => Result will give how many elements were added
        aChange < 0 => Result will give how many elements got deleted (it will be negative value!)
		aChange = 0 => Returns 0.
[==============================================================================}
function XArrHelp.Resize(const aChange: Integer): Integer; overload; cdecl;
var
  l: Integer;
begin
  l := Length(Self);
  SetLength(Self, (l + aChange));
  Result := (Length(Self) - l);
end;

{==============================================================================]
 <arr.Resize(aChange: Integer; null: VarType): Integer>
 @action: Updates's arr length with aChange.
 @note: aChange > 0 => Result will give how many elements were added
        aChange < 0 => Result will give how many elements got deleted (it will be negative value!)
		aChange = 0 => Returns 0.
		Supports null for filling created indexes.
[==============================================================================}
function XArrHelp.Resize(const aChange: Integer; const null: XVar): Integer; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Self, aChange);
  Result := (Length(Self) - l);
  for i := 0 to (Result - 1) do
    Self[l + i] := null;
end;

{==============================================================================]
 <arr.Reverse: Boolean>
 @action: Reverses items in array.
 @note: Returns true with success (array contains 2 or more items)
[==============================================================================}
function XArrHelp.Reverse: Boolean; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Exchange(i, ((l - i) - 1));
end;

{==============================================================================]
 <arr.Reversed: TArray>
 @action: Returns reversed version of array arr.
 @note: None.
[==============================================================================}
function XArrHelp.Reversed: XArr; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := Self[(l - i) - 1];
end;

{==============================================================================]
 <arr.Scan(item: VarType; ID: TRange; limit: Integer): TIntegerArray>
 @action: Scans array for item by ID. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function XArrHelp.Scan(const ID: TRange; const item: XVar; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r: Integer;
begin
  r := 0;
  if (High(Self) > -1) then
  begin
    SetLength(Result, ID.Size);
    case ID.Ascending of
      True:
      for i := ID.start to ID.stop do
	    if (r >= limit) then
		  Break
		else
          if (Self[i] = item) then
            Result[r.Increase] := i;
      False:
      for i := ID.start downto ID.stop do
	    if (r >= limit) then
		  Break
		else
          if (Self[i] = item) then
		    Result[r.Increase] := i;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Scan(item: VarType; ID: TIntegerArray): TIntegerArray>
 @action: Scans array for item by ID. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function XArrHelp.Scan(const ID: TIntegerArray; const item: XVar; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r: Integer;
begin
  r := 0;
  if (High(Self) > -1) then
  begin
    SetLength(Result, Length(ID));
    for i := 0 to High(ID) do
	  if (r >= limit) then
	    Break
	  else
        if (Self[ID[i]] = item) then
	      Result[r.Increase] := ID[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Scan(items: TArray; ID: TRange; limit: Integer): TIntegerArray>
 @action: Scans array for items by ID. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function XArrHelp.Scan(const ID: TRange; const items: XArr; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r: Integer;
begin
  r := 0;
  if ((High(Self) > -1) and (High(items) > -1)) then
  begin
    SetLength(Result, ID.Size);
    case ID.Ascending of
      True:
      for i := ID.start to ID.stop do
        if (r >= limit) then
          Break
        else
          if items.Contains(Self[i]) then
            Result[r.Increase] := i;
      False:
      for i := ID.start downto ID.stop do
        if (r >= limit) then
          Break
        else
          if items.Contains(Self[i]) then
            Result[r.Increase] := i;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Scan(item: VarType; ID: TIntegerArray): TIntegerArray>
 @action: Scans array for items by ID. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function XArrHelp.Scan(const ID: TIntegerArray; const items: XArr; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r: Integer;
begin
  r := 0;
  if ((High(Self) > -1) and (High(items) > -1)) then
  begin
    SetLength(Result, Length(ID));
    for i := 0 to High(ID) do
      if (r >= limit) then
        Break
      else
        if items.Contains(Self[ID[i]]) then
	  Result[r.Increase] := ID[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Shift: VarType>
 @action: Shortens the array with first element.
 @note: Returns the removed arr[0].
[==============================================================================}
function XArrHelp.Shift: XVar; overload; cdecl;
var
  i, l: Integer;
begin
  l := (Length(Self) - 1);
  if (l < 0) then
    Exit;
  Result := Self[0];
  for i := 0 to (l - 1) do
    Self[i] := Self[i + 1];
  SetLength(Self, l);
end;

{==============================================================================]
 <arr.Shift(sCount: Integer): TArray>
 @action: Shortens the array with first SCOUNT element(s).
 @note: Returns the removed arr[x]s.
[==============================================================================}
function XArrHelp.Shift(const sCount: Integer): XArr; overload; cdecl;
var
  i, l, s: Integer;
begin
  l := Length(Self);
  s := Max(0, Min(sCount, l));
  SetLength(Result, s);
  if (l = 0) then
    Exit;
  for i := 0 to (s - 1) do
    Result[i] := Self[i];
  for i := s to High(Self) do
    Self[i - s] := Self[i];
  SetLength(Self, (Length(Self) - s));
end;

{==============================================================================]
 <arr.Size: Integer> 
 @action: Returns array length.
 @note: Simply Result := Length(arr);
[==============================================================================}
function XArrHelp.Size: Integer; overload; cdecl;
begin
  Result := Length(Self);
end;

{==============================================================================]
 <arr.Size(aSize: Integer): TArray>
 @action: Set's arr length to aSize.
 @note: None.
[==============================================================================}
function XArrHelp.Size(const aSize: Integer): XArr; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, aSize);
  for i := 0 to (Min(l, aSize) - 1) do
    Result[i] := Self[i];
end;

{==============================================================================]
 <arr.Size(arr: TArray; aSize: Integer; null: VarType): TArray>
 @action: Set's arr length to size.
 @note: Uses null for created indexes.
[==============================================================================}
function XArrHelp.Size(const aSize: Integer; const null: XVar): XArr; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, aSize);
  for i := 0 to (Min(l, aSize) - 1) do
    Result[i] := Self[i];
  for i := l to (aSize - 1) do
    Result[i] := null;
end;

{==============================================================================]
 <arr.SizeBetween(arr: TArray; sMin, sMax: Integer): Boolean>
 @action: Returns true if size is at equal/greater than sMin and equal/lesser than sMax.
 @note: 	
[==============================================================================}
function XArrHelp.SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl;
begin
  Result := InRange(Length(Self), sMin, sMax);
end;

{==============================================================================]
 <arr.SizeMax(target: Integer): Boolean>
 @action: Returns true if size is at equal/lesser than target.
 @note: 	
[==============================================================================}
function XArrHelp.SizeMax(const target: Integer): Boolean; overload; cdecl;
begin
  Result := (Length(Self) <= target);
end;

{==============================================================================]
 <arr.SizeMin(target: Integer): Boolean>
 @action: Returns true if size is at equal/greater than target.
 @note: 	
[==============================================================================}
function XArrHelp.SizeMin(const target: Integer): Boolean; overload; cdecl;
begin
  Result := (Length(Self) >= target);
end;

{==============================================================================]
 <arr.SubarrayLocation(pattern: TArray): Integer>
 @action: Returns subarray position in arr that match pattern exactly.
 @note: arr[0,1,2,0,1,2,3].([1,2]) => 4	
[==============================================================================}
function XArrHelp.SubarrayLocation(const pattern: XArr): Integer; overload; cdecl;
var
  i, j, l, s, p: Integer;
begin
  l := Length(Self);
  p := Length(pattern);
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
 <arr.SubarrayLocations(pattern: TArray): TIntegerArray>
 @action: Returns subarray positions in arr that match pattern exactly.
 @note: arr[0,1,2,0,1,2,3].([1,2]) => [4,1]	
[==============================================================================}
function XArrHelp.SubarrayLocations(const pattern: XArr): TIntegerArray; overload; cdecl;
var
  i, j, l, s, r, p: Integer;
begin
  l := Length(Self);
  p := Length(pattern);
  SetLength(Result, 0);
  r := 0;
  if ((p > 0) and (p <= l)) then
  begin
    SetLength(Result, ((l - p) + 1));
    for i := (l - p) downto 0 do
    begin
      s := 0;
      for j := 0 to (p - 1) do
        if (Self[i + j] <> pattern[j]) then
          Break
        else
          s := (s + 1);
      if (s = p) then
        Result[r.Increase] := i;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.SubarrayPosition(pattern: TArray): Integer>
 @action: Returns subarray position in arr that match pattern exactly.
 @note: arr[0,1,2,0,1,2,3].([1,2]) => 1	
[==============================================================================}
function XArrHelp.SubarrayPosition(const pattern: XArr): Integer; overload; cdecl;
var
  i, j, l, p: Integer;
  f: Boolean;
begin
  l := Length(Self);
  p := Length(pattern);
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

{==============================================================================]
 <arr.SubarrayPositions(pattern: TArray): TIntegerArray>
 @action: Returns subarray positions in arr that match pattern exactly.
 @note: arr[0,1,2,0,1,2,3].([1,2]) => [1,4]	
[==============================================================================}
function XArrHelp.SubarrayPositions(const pattern: XArr): TIntegerArray; overload; cdecl;
var
  i, j, l, p, r: Integer;
  f: Boolean;
begin
  l := Length(Self);
  p := Length(pattern);
  SetLength(Result, 0);
  r := 0;
  if ((p > 0) and (p <= l)) then
  begin
    SetLength(Result, ((l - p) + 1));
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
        Result[r.Increase] := i;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Swap(b: TArray): Integer> 
 @action: Swaps array arr and array b.
 @note: arr will be b and b will be arr.
[==============================================================================}
function XArrHelp.Swap(var b: XArr): Integer; overload; cdecl;
var
  a: XArr;
begin
  Result := (Length(Self) + Length(b));
  if (Result = 0) then
    Exit;
  a := Self.Dupe;
  Self := b.Dupe;
  b := a.Dupe;
  SetLength(a, 0);
end;

{==============================================================================]
 <arr.Trade(b: TArray): Integer> 
 @action: Swaps array arr and array b.
 @note: arr will be b and b will be arr.
[==============================================================================}
function XArrHelp.Trade(var b: XArr): Integer; overload; cdecl;
var
  a: XArr;
begin
  Result := (Length(Self) + Length(b));
  if (Result > 0) then
  begin
    a := Self.Copy;
    Self := b.Copy;
    b := a.Copy;
    SetLength(a, 0);
  end;
end;

{==============================================================================]
 <arr.Undersize(limit: Integer): Boolean>
 @action: Returns true if size of arr is UNDER the limit.
 @note: None.	
[==============================================================================} 
function XArrHelp.Undersize(const limit: Integer): Boolean; overload; cdecl;
begin
  Result := (Length(Self) < limit);
end;

{==============================================================================]
 <arr.Unduplicate: Integer>
 @action: Removes all duplicates from arr.
 @note: Returns the number of items that were removed.
[==============================================================================}
function XArrHelp.Unduplicate: XArr; overload; cdecl;
type
  TDict = specialize TDictionary<XVar, Boolean>;
var
  d: TDict;
  r, i, l: Integer;
begin
  l := Length(Self);
  if (l < 2) then
    Exit(Self.Copy);
  d := TDict.Create;
  try
    SetLength(Result, l);
    r := 0;
    for i := 0 to (l - 1) do
      if not d.ContainsKey(Self[i]) then
      begin
        d.Add(Self[i], True);
        Result[r.Increase] := Self[i];
      end;
    if ((l - r) > 0) then
      SetLength(Result, r);
  finally
    d.Free;
  end;
end;

{==============================================================================]
 <arr.Unique: TArray>
 @action: Removes all duplicates from arr.
 @note: Returns the number of items that were removed.
[==============================================================================}
function XArrHelp.Unique: XArr; overload; cdecl;
var
  a, l, i, j: Integer;
  m: Boolean;
begin
  Result := Self.Copy;
  l := Length(Result);
  if (l < 2) then
    Exit;
  a := 0;
  for i := 1 to (l - 1) do
  begin
    for j := 0 to a do
    begin
      m := (Result[i] = Result[j]);
      if m then
        Break;
    end;
    if m then
      Continue;
    Result[a.Increment] := Result[i];
  end;
  if ((l - (a + 1)) > 0) then
    SetLength(Result, (a + 1));
end;

{==============================================================================]
 <arr.Uniqued: TArray>
 @action: Removes all duplicates from arr.
 @note: Returns the unique version of arr.
[==============================================================================}
function XArrHelp.Uniqued: XArr; overload; cdecl;
var
  i, j, l, c: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  if (l > 0) then
  begin
    c := 0;
    for i := 0 to (l - 1) do
    begin
      j := 0;
      repeat
        if (Self[i] <> Result[j]) then
          j := (j + 1)
        else
          j := 0;
      until ((j = 0) or (j > c));
      if (j > 0) then
        Result[c.Increase] := Self[i];
    end;
    SetLength(Result, c);
  end;
end;

{==============================================================================]
 <arr.Uniques: TIntegerArray>
 @action: Returns the indexes of unique array (arr) items.
 @note: None.
[==============================================================================}
function XArrHelp.Uniques: TIntegerArray; overload; cdecl;
var
  h, r, x, y: Integer;
  m: Boolean;
begin
  h := High(Self);
  SetLength(Result, (h + 1));
  if (h > 0) then
  begin
    r := 0;
    for x := 0 to h do
    begin
      for y := 0 to h do
      begin
        m := ((y <> x) and (Self[x] = Self[y]));
        if m then
          Break;
      end;
      if not m then
        Result[r.Increase] := x;
    end;
    SetLength(Result, r);
  end;
  if (h = 0) then
    Result[0] := 0;
end;

{==============================================================================]
 <arr.Unshift(item: VarType): TArray>
 @action: Grows arr with item.
 @note: Adds item to the left side of the array. (Opposite to TArray_Append!
[==============================================================================}
function XArrHelp.Unshift(const item: XVar): XArr; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, (l + 1));
  for i := l downto 1 do
    Result[i] := Self[i - 1];
  Result[0] := item;
end;

{==============================================================================]
 <arr.Unshift(items: TArray): TArray>
 @action: Grows arr with items. Returns the index of last added item.
 @note: Adds item to the left side of the array. (Opposite to TArray_Append!
[==============================================================================}
function XArrHelp.Unshift(const items: XArr): XArr; overload; cdecl;
var
  h, l, i, r: Integer;
begin
  l := Length(items);
  if (l = 0) then
    Exit(Self.Copy);
  r := (Length(Self) + l);
  SetLength(Result, r);
  for i := (r - 1) downto l do
    Result[i] := Self[i - l];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;

{==============================================================================]
 <arr.Waste: Integer>
 @action: Returns total count of Duplicates in array, which is "Waste"
 @note: None.
[==============================================================================}
function XArrHelp.Waste: Integer; overload; cdecl;
type
  TDict = specialize TDictionary<XVar, Integer>;
var
  d: TDict;
  i: Integer;
  v: XVar;
begin
  Result := 0;
  if (Length(Self) < 1) then
    Exit;
  d := TDict.Create;
  try
    for v in Self do
      if d.ContainsKey(v) then
        d[v] := (d[v] + 1)
      else
        d.Add(v, 1);
    for i in d.Values do
      if (i > 1) then
        Result := (Result + (i - 1));
  finally
    d.Free;
  end;
end;

{==============================================================================]
 <arr.Blank(parts: Integer): T2DArray>
 @action: Returns true if array is blank (no inventory, only empty indexes of []).
 @note: Blank array could be for example [[], [], []]. Returns false if array contains any items.
        NOTE: Returns false if array is empty (1D Length = 0)!
 [==============================================================================}
function X2DArrHelp.Blank: Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if (Length(Self[i]) > 0) then
	  Exit(False);
  Result := (Length(Self) > 0);
end;

{==============================================================================]
 <T2D.Create(size1D, size2D: Integer; item: VarType)>
 @action: Creates array with item where size is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}
class function T2D.Create(const size1D, size2D: Integer; const item: XVar): X2DArr; overload; cdecl;
var
  i, j, s: Integer;
begin
  s := (Max(0, size2D) - 1);
  SetLength(Result, Max(0, size1D), (s + 1));
  for i := 0 to High(Result) do
    for j := 0 to s do
      Result[i][j] := item;
end;

{==============================================================================]
 <arr.Empty: Boolean>
 @action: Returns true if array is empty (Length = 0).
 @note: None.
[==============================================================================}
function X2DArrHelp.Empty: Boolean; overload; cdecl;
begin
  Result := (Length(Self) = 0);
end;

{==============================================================================]
 <arr.Size(lengths: TIntegerArray): Int64>
 @action: Returns actual Length for 2D array. Stores Length's of 2D part, of the arr, to lengths variable.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
function X2DArrHelp.Size(var lengths: TIntegerArray): Int64; overload; cdecl;
var
  i: Integer;
begin
  Result := 0;
  SetLength(lengths, Length(Self));
  for i := 0 to High(Self) do
  begin
    lengths[i] := Length(Self[i]);
    Result := (Result + lengths[i]);
  end;
end;

{==============================================================================]
 <arr.Size: Int64>
 @action: Returns actual Length for 2D array.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
function X2DArrHelp.Size: Int64; overload; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := (Result + Length(Self[i]));
end;

{==============================================================================]
 <arr.Merge: TArray>
 @action: Merges 2D array to 1D.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function X2DArrHelp.Merge: XArr; overload; cdecl;
var
  i, j, l: Integer;
begin
  SetLength(Result, Self.Size);
  l := Length(Result);
  if (l > 0) then
  for i := High(Self) downto 0 do
    for j := High(Self[i]) downto 0 do
      Result[l.Decrement] := Self[i][j];
end;

{==============================================================================]
 <arr.TArray: TArray>
 @action: Merges 2D array to 1D.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function X2DArrHelp.TArray: XArr; overload; cdecl;
var
  i, j, l: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    l := Length(Result);
    SetLength(Result, (l + Length(Self[i])));
    for j := 0 to High(Self[i]) do
      Result[l + j] := Self[i][j];
  end;
end;

{==============================================================================]
 <arr.Flat: TArray>
 @action: Merges 2D array to 1D.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function X2DArrHelp.Flat: XArr; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    Result := Concat(Result, Self[i]);
end;
