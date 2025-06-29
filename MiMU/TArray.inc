{==============================================================================]
 <var.TArray(aSize: Integer): TArray>
 @action: Creates TArray with Self.
 @note: aSize will be Length of the created array.
[==============================================================================}
{$IFDEF var_TArray}
var
  i: Integer;
begin
  SetLength(Result, aSize);
  for i := 0 to High(Result) do
    Result[i] := Self;
end;
{$ENDIF}

{==============================================================================]
 <arr.Add(item: VarType; duplicates: Boolean): TArray>
 @action: Appends arr with item. Returns the array with added item.
 @note: Adds item to the right side of the array.
[==============================================================================}
{$IFDEF TArray_Add1}
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
{$ENDIF}

{==============================================================================]
 <arr.Add(items: TArray; duplicates: Boolean): TArray>
 @action: Appends arr with items. Returns the array with added items.
 @note: Adds item to the right side of the array.
[==============================================================================}
{$IFDEF TArray_Add2}
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
{$ENDIF}

{==============================================================================]
 <arr.AllEqual: Boolean>
 @action: Returns true if all values in arr are equal (arr contains only equal values).
 @note: Returns FALSE with empty array!
[==============================================================================}
{$IFDEF TArray_AllEqual}
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
{$ENDIF}

{==============================================================================]
 <arr.AllSame: Boolean>
 @action: Returns true if all values in arr are the same (arr contains only equal values).
 @note: Returns FALSE with empty array!
[==============================================================================}
{$IFDEF TArray_AllSame}
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[0] <> Self[i]) then
      Exit(False);
  Result := (Length(Self) > 0);
end;
{$ENDIF}

{==============================================================================]
 <arr.AllUnique: Boolean>
 @action: Returns true if all values in arr are unique (arr contains ONLY unique values).
 @note: None
[==============================================================================}
{$IFDEF TArray_AllUnique}
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
{$ENDIF}

{==============================================================================]
 <arr.Append(item: VarType; duplicates: Boolean): Integer>
 @action: Appends arr with item. Returns the index of added item.
 @note: Adds item to the right side of the array.
[==============================================================================}
{$IFDEF TArray_Append1}
begin
  if ((not duplicates) and Self.Contains(item)) then
    Exit(High(Self));
  Result := Length(Self);
  SetLength(Self, (Result + 1));
  Self[Result] := item;
end;
{$ENDIF}

{==============================================================================]
 <arr.Append(items: TArray; duplicates; Boolean): Integer>
 @action: Adds all items items to arr.
 @note: Returns the highest index in the end.
[==============================================================================}
{$IFDEF TArray_Append2}
var
  h, i: Integer;
begin
  h := High(items);
  Result := High(Self);
  if (h = -1) then
    Exit;
  SetLength(Self, ((Result + h) + 2));
  case duplicates of
    False:
    begin
      for i := 0 to h do
        if not Self.Contains(items[i]) then
          Self[(Result.Increment)] := items[i];
      SetLength(Self, (Result + 1));
    end;
    True:
    for i := 0 to h do
      Self[Result.Increment] := items[i];
  end;
end;
{$ENDIF}

{==============================================================================]
 <arr.Build(item: VarType; aSize: Integer): TArray> 
 @action: Creates array with item where aSize is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}
{$IFDEF TArray_Build}
begin
  Result := Self.Create(aSize, item);
end;
{$ENDIF}

{==============================================================================]
 <arr.BuiltWith(allowed: TArray): Boolean> 
 @action: Checks if array arr contains only allowed items.
 @note: None.
[==============================================================================}
{$IFDEF TArray_BuiltWith}
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
       x := (x + 1);
     until (Result or (x = y));
     i := (i - 1);
  until ((i < 0) or (not Result));
end;
{$ENDIF}

{==============================================================================]
 <arr.BuiltWithout(forbidden: TArray): Boolean> 
 @action: Checks if array arr does not have any forbidden items.
 @note: None.
[==============================================================================}
{$IFDEF TArray_BuiltWithout}
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
         x := (x + 1);
       until ((x = y) or (not Result));
       i := (i - 1);
    until ((i < 0) or (not Result));
  end else
    Result := True;
end;
{$ENDIF}

{==============================================================================]
  <arr.Clear: Boolean>
  @action: SetLength(arr, 0) and returns true if items existed before doing it.
  @note: None.
[==============================================================================}
{$IFDEF TArray_Clear}
begin
  Result := (Length(Self) > 0);
  SetLength(Self, 0);
end;
{$ENDIF}

{==============================================================================]
 <arr.Clone(index: Integer; count: Integer): TArray>
 @action: Returns copy of an array arr.
 @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}
{$IFDEF TArray_Clone1}
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
{$ENDIF}

{==============================================================================]
 <arr.Clone(ID: TIntegerArray): TArray>
 @action: Outputs array of items from arr by indexes (ID).
 @note: Ignores invalid ID's (doesn't include those to result, they will be left out).
[====================
==========================================================}
{$IFDEF TArray_Clone2}
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
{$ENDIF}

{==============================================================================]
 <arr.Combine(b: TArray): TArray>
 @action: Combines arrays arr and b together as single array.
 @note: This is an alternative method. :)
[==============================================================================}
{$IFDEF TArray_Combine}
begin
  SetLength(Result, 0);
  Insert(Self, Result, 0);
  Insert(b, Result, Length(Self));
end;
{$ENDIF}

{==============================================================================]
 <arr.Contains(item: VarType; index: Integer): Boolean>
 @action: Looks array for item starting from start index. If found, Result will be True.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Contains}
var
  i: Integer;
begin
  for i := index to High(Self) do
    if (item = Self[i]) then
      Exit(True);
  Result := False;
end;
{$ENDIF}

{==============================================================================]
 <arr.Copy(index: Integer; count: Integer): TArray>
 @action: Returns copy of an array arr.
 @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}
{$IFDEF TArray_Copy}
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
{$ENDIF}

{==============================================================================]
 <arr.Create(item: VarType): TArray> 
 @action: Creates array with item, size as 1. Returns old Self.
 @note: [item]
[==============================================================================}
{$IFDEF TArray_Create1}
begin
  Result := Self.Clone;
  SetLength(Self, 1);
  Self[0] := item;
end;
{$ENDIF}

{==============================================================================]
 <arr.Create(aSize: Integer; item: VarType): TArray> 
 @action: Creates array with item where aSize is length of the array. Returns old Self.
 @note: item is placed on every index in result.
[==============================================================================}
{$IFDEF TArray_Create2}
var
  i: Integer;
begin
  Result := Self.Clone;
  SetLength(Self, Max(0, aSize));
  for i := 0 to High(Self) do
    Self[i] := item;
end;
{$ENDIF}

{==============================================================================]
 <arr.Delete(index: Integer): Boolean>
 @action: Deletes array item from arr by index.
 @note: Returns true with success (index existed in arr).
[==============================================================================}
{$IFDEF TArray_Delete1}
var
  i, h: Integer;
begin
  h := High(Self);
  Result := ((index <= h) and (index > -1));
  if not Result then
    Exit;
  for i := index to (h - 1) do
    Self[i] := Self[i + 1];
  SetLength(Self, h);
end;
{$ENDIF}

{==============================================================================]
 <arr.Delete(ID: TIntegerArray): Integer>
 @action: Deletes array items from arr by indexes (ID).
 @note: Returns amount of items that were deleted succesfully by ID's.
[==============================================================================}
{$IFDEF TArray_Delete2}
var
  i, l: Integer;
begin
  l := Length(Self);
  Result := 0;
  for i := 0 to (l - 1) do
    if not ID.Contains(i) then
      Self[i - Result] := Self[i]
    else
      Result := (Result + 1);
  SetLength(Self, (l - Result));
end;
{$ENDIF}

{==============================================================================]
 <arr.Differ(target: TArray): Boolean>
 @action: Returns true if arr differs from target.
 @note: None
[==============================================================================}
{$IFDEF TArray_Differ}
var
  i: Integer;
begin
  Result := (Length(Self) <> Length(target));
  if not Result then
  for i := High(Self) downto 0 do
    if (Self[i] <> target[i]) then
      Exit(True);
end;
{$ENDIF}

{==============================================================================]
 <arr.Distribute(parts: Integer): T2DArray>
 @action: Distributes array arr to 2D array by number of parts.
 @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5][6,7]
 [==============================================================================}
{$IFDEF TArray_Distribute}
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
{$ENDIF}

{==============================================================================]
 <TArray_Dump(items: TArray; index: Integer): Integer>
 @action: Deletes items from array, keeps others. Returns array length (after action).
 @note: Supports custom start index!
[==============================================================================}
{$IFDEF TArray_Dump}
var
  i, l: Integer;
begin
  l := Length(Self);
  Result := 0;
  if (High(items) > -1) then
  for i := Max(0, index) to (l - 1) do
    if not items.Contains(Self[i]) then
      Self[i - Result] := Self[i]
    else
      Inc(Result);
  Result := (l - Result);
  if (Result < l) then
    SetLength(Self, Result);
end;
{$ENDIF}

{==============================================================================]
 <arr.Dupe: TArray>
 @action: Returns copy of an array arr.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Dupe}
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
{$ENDIF}

{==============================================================================]
 <arr.Duplicate(xTimes: Integer): TArray>
 @action: Returns copy of an array arr.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Duplicate}
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
{$ENDIF}

{==============================================================================]
 <arr.Empty: Boolean>
 @action: Returns true if array is empty (Length = 0).
 @note: None.
[==============================================================================}
{$IFDEF TArray_Empty1}
begin
  Result := (Length(Self) = 0);
end;
{$ENDIF}

{==============================================================================]
 <arr.Equal(target: TArray): Boolean>
 @action: Returns true if arr equals target (identical arrays)
 @note: None
[==============================================================================}
{$IFDEF TArray_Equal}
var
  i: Integer;
begin
  Result := (Length(Self) = Length(target));
  if Result then
  for i := High(Self) downto 0 do
    if (Self[i] <> target[i]) then
      Exit(False);
end;
{$ENDIF}

{==============================================================================]
 <arr.Exch(aIndex, bIndex: Integer): Boolean>
 @action: Fast version of Exchange().
 @note: Unsafe, no checking.
[==============================================================================}
{$IFDEF TArray_Exch}
begin
  Result := (Self[aIndex] <> Self[bIndex]);
  c := Self[aIndex];
  Self[aIndex] := Self[bIndex];
  Self[bIndex] := c;
end;
{$ENDIF}

{==============================================================================]
 <arr.Exchange(aIndex, bIndex: Integer): Boolean>
 @action: Swap items aIndex and bIndex in array arr.
 @note: Returns true with success.
[==============================================================================}
{$IFDEF TArray_Exchange}
var
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
{$ENDIF}

{==============================================================================]
 <arr.Extend(item: VarType): TArray>
 @action: Extends arr with item. Returns it.
 @note: Places item to the left side of the array.
[==============================================================================}
{$IFDEF TArray_Extend1}
var
  i, h: Integer;
begin
  h := High(Self);
  SetLength(Result, (h + 2));
  for i := 0 to h do
    Result[i + 1] := Self[i];
  Result[0] := item;
end;
{$ENDIF}

{==============================================================================]
 <arr.Extend(items: TArray): TArray>
 @action: Extends arr with items. Returns it.
 @note: Places items to the left side of the array.
[==============================================================================}
{$IFDEF TArray_Extend2}
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
{$ENDIF}

{==============================================================================]
 <arr.Extract(item: VarType; index: Integer): TArray>
 @action: Keeps (extracts) all values in arr that are item. Starts scan from start index.
 @note: Returns the items.
[==============================================================================} 
{$IFDEF TArray_Extract1}
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
{$ENDIF}

{==============================================================================]
 <arr.Extract(items: TArray; index: Integer): TArray>
 @action: Keeps (extracts) all values in arr that are in items. Starts scan from start index.
 @note: Returns the items.
[==============================================================================}
{$IFDEF TArray_Extract2}
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
{$ENDIF}

{==============================================================================]
 <arr.ExtractEvery(X: Integer; index: Integer): TArray>
 @action: Keeps (extracts) all X values from array. Starts scan from start index.
 @note: Returns the items.
[==============================================================================} 
{$IFDEF TArray_ExtractEvery}
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
{$ENDIF}

{==============================================================================]
 <arr.Fill(item: VarType; index: Integer; count: Integer): TArray>
 @action: Fills whole arr with item.
 @note: Returns the filled array.
[==============================================================================}
{$IFDEF TArray_Fill1}
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
{$ENDIF}

{==============================================================================]
 <arr.Fill(items: TArray; index: Integer; count: Integer): TArray>
 @action: Fills whole arr with items.
 @note: None
[==============================================================================}
{$IFDEF TArray_Fill2}
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
{$ENDIF}

{==============================================================================]
 <arr.Filter(item: VarType; index: Integer): TArray>
 @action: Removes all values from arr that are found in items.
 @note: None
[==============================================================================}
{$IFDEF TArray_Filter1}
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
{$ENDIF}

{==============================================================================]
 <arr.Filter(items: TArray; index: Integer): TArray>
 @action: Removes all values from arr that are found in items.
 @note: None
[==============================================================================}
{$IFDEF TArray_Filter2}
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
{$ENDIF}

{==============================================================================]
 <arr.FilterEvery(X: Integer; index: Integer): TArray>
 @action: Filters every/each X item from arr.
 @note: Custom index
[==============================================================================}
{$IFDEF TArray_FilterEvery}
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
{$ENDIF}

{==============================================================================]
 <arr.Find(item: VarType; ID: TRange): Integer>
 @action: Scans array for item by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Find1}
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
{$ENDIF}

{==============================================================================]
 <arr.Find(item: VarType; ID: TIntegerArray): Integer>
 @action: Scans array for item by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Find2}
var
  i: Integer;
begin
  if (High(Self) > -1) then
  for i := 0 to High(ID) do
    if (Self[ID[i]] = item) then
      Exit(ID[i]);
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <arr.Find(items: TArray; ID: TRange): Integer>
 @action: Scans array for items by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Find3}
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
{$ENDIF}

{==============================================================================]
 <arr.Find(items: TArray; ID: TIntegerArray): Integer>
 @action: Scans array for items by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Find4}
var
  i: Integer;
begin
  if ((High(Self) > -1) and (High(items) > -1)) then
  for i := 0 to High(ID) do
    if items.Contains(Self[ID[i]]) then
      Exit(ID[i]);
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <arr.Flip: Boolean>
 @action: Reverses array arr.
 @note: Alternative for TArray_Reverse
[==============================================================================}
{$IFDEF TArray_Flip}
var
  i, l: Integer;
begin
  i := 0;
  l := (Length(Self) - 1);
  Result := (l > 0);
  while (i < l) do
    Exchange(i.Increase, l.Decrease);
end;
{$ENDIF}

{==============================================================================]
 <arr.FromLeft(count, index): TArray>
 @action: Returns count of array items from left-side by index.
 @note: None
[==============================================================================}
{$IFDEF TArray_FromLeft}
var
  m: Integer;
  a, r, i: TRange;
begin
  m := Min(High(Self), index);
  a.Build(0, High(Self));
  if ((count > 0) and a.Intersect(r.Build((m - count), (m - 1)), i)) then
    Result := Self.Copy(i.start, ((i.stop - i.start) + 1))
  else
    SetLength(Result, 0);
end;
{$ENDIF}

{==============================================================================]
 <arr.FromRight(count, index): TArray>
 @action: Returns count of array items from right-side by index.
 @note: None
[==============================================================================}
{$IFDEF TArray_FromRight}
var
  m: Integer;
  a, r, i: TRange;
begin
  m := Max(0, index);
  a.Build(0, High(Self));
  if ((count > 0) and a.Intersect(r.Build((m + 1), (m + count)), i)) then
    Result := Self.Copy(i.start, ((i.stop - i.start) + 1))
  else
    SetLength(Result, 0);
end;
{$ENDIF}

{==============================================================================]
 <arr.Get: TArray>
 @action: Copy of an array arr.
 @note: Just an alternative.
[==============================================================================}
{$IFDEF TArray_Get1}
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  i := 0;
  for a in Self do
    Result[i.Increase] := a;
 end;  
{$ENDIF}

{==============================================================================]
 <arr.Get(ID: TIntegerArray): TArray>
 @action: Outputs array of items from arr by indexes (IDs).
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Get2}
var
  i: Integer;
begin
  SetLength(Result, Length(ID));
  for i := 0 to High(ID) do
    Result[i] := Self[ID[i]];
end;
{$ENDIF}

{==============================================================================]
 <arr.Get(ID: TRange): TArray>
 @action: Outputs array of items from arr by indexes (IDs).
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Get3}
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
{$ENDIF}

{==============================================================================]
 <arr.Group: T2DArray>
 @action: Groups array arr to 2D array by items.
 @note: ([1,2,1,2,3,1,2,3,4]) => [1,1,1][2,2,2][3,3][4]
[==============================================================================}
{$IFDEF TArray_Group}
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
{$ENDIF}

{==============================================================================]
 <arr.Holds(chain: TArray): Boolean>
 @action: Returns true if arr contains (holds) WHOLE chain of items in it.
 @note: Starting from any index and ending to any index!
[==============================================================================}
{$IFDEF TArray_Holds}
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
      n := (Self[(a + x)] <> chain[x]);
      if n then
        Break;
    end;
    Result := not n;
  until ((a = b) or Result);
end;
{$ENDIF}

{==============================================================================]
 <arr.IDs(ascending: Boolean): TIntegerArray>
 @action: Returns IDs of arr as TIntegerArray.
 @note: None.
[==============================================================================}
{$IFDEF TArray_IDs1}
var
  h, i: Integer;
begin
  SetLength(Result, Length(Self));
  h := High(Self);
  case ascending of
    True:
    for i := 0 to h do
      Result[i] := i;
    False:
    for i := h downto 0 do
      Result[(h - i)] := i;
  end;
end;
{$ENDIF}

{==============================================================================]
 <arr.IDs(IDs: TIntegerArray): TArray>
 @action: Returns items from arr by IDs.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array.
[==============================================================================}
{$IFDEF TArray_IDs2}
var
  i: Integer;
begin
  SetLength(Result, Length(ID));
  for i := 0 to High(Result) do
    Result[i] := Self[ID[i]];
end;
{$ENDIF}

{==============================================================================]
 <arr.IDs(IDs: TIntegerArray; item: VarType): TArray>
 @action: Returns arr with IDs replaced as item.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array.
[==============================================================================}
{$IFDEF TArray_IDs3}
var
  i: Integer;
begin
  Result := Self.Copy;
  for i := 0 to High(ID) do
    Result[ID[i]] := item;
end;
{$ENDIF}

{==============================================================================]
 <arr.IDs(IDs: TIntegerArray; items: TArray): TArray>
 @action: Returns arr with IDs replaced as items.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array and ALSO item[s].
[==============================================================================}
{$IFDEF TArray_IDs4}
var
  i, l: Integer;
begin
  Result := Self.Copy;
  l := Length(items);
  for i := 0 to High(ID) do
    Result[ID[i]] := items[i mod l];
end;
{$ENDIF}

{==============================================================================]
 <arr.Includes(item: VarType; index: Integer): Boolean>
 @action: Looks array for item starting from start index down to index 0. If found, Result will be True.
 @note: Alternative to TArray_Contains, but this scans in opposite direction.
[==============================================================================}
{$IFDEF TArray_Includes}
var
  i: Integer;
begin
  for i := Min(High(Self), index) downto 0 do
    if (item = Self[i]) then
      Exit(True);
  Result := False;
end;
{$ENDIF}

{==============================================================================]
 <arr.Keep(items: TArray; index: Integer): Integer>
 @action: Keeps items in array, removes others. Returns array length (after action).
 @note: Supports custom start index!
[==============================================================================}
{$IFDEF TArray_Keep}
var
  i, l: Integer;
begin
  l := Length(Self);
  case (High(items) > -1) of
    True:
    begin
      Result := 0;
      for i := Max(0, index) to (l - 1) do
        if items.Contains(Self[i]) then
          Self[i - Result] := Self[i]
        else
          Inc(Result);
    end;
    False: Result := (l - Max(0, index));
  end;
  Result := (l - Result);
  if (Result < l) then
    SetLength(Self, Result);
end;
{$ENDIF}

{==============================================================================]
 <arr.LeastFrequent: VarType> 
 @action: Returns the least frequent arr item.
 @note: None.
[==============================================================================}
{$IFDEF TArray_LeastFrequent}
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
{$ENDIF}

{==============================================================================]
 <arr.Len: Integer>
 @action: Simply Result := Length(arr);
 @note: None.
[==============================================================================}
{$IFDEF TArray_Len1}
begin
  Result := Length(Self);
end;
{$ENDIF}

{==============================================================================]
 <arr.Len(aSize: Integer): Integer>
 @action: Set's arr length to aSize.
 @note: aSize > Length(arr) => Result will give how many elements were added
        aSize < Length(arr) => Result will give how many elements got deleted (it will be negative value!)
		aSize = Length(arr) => Returns 0.
[==============================================================================}
{$IFDEF TArray_Len2}
var
  l: Integer;
begin
  l := Length(Self);
  SetLength(Self, aSize);
  Result := (Length(Self) - l);
end;
{$ENDIF}

{==============================================================================]
 <arr.Len(arr: TArray; aSize: Integer; null: VarType): Integer>
 @action: Set's arr length to size.
 @note: Uses null for created indexes.
[==============================================================================}
{$IFDEF TArray_Len3}
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Self, aSize);
  Result := (Length(Self) - l);
  for i := 0 to (Result - 1) do
    Self[l + i] := null;
end;
{$ENDIF}

{==============================================================================]
 <arr.Loc(item: VarType; index: Integer): Integer>
 @action: Returns last index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
{$IFDEF TArray_Loc1}
begin
  for Result := Min(High(Self), index) downto 0 do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <arr.Loc(items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
{$IFDEF TArray_Loc2}
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
{$ENDIF}

{==============================================================================]
 <arr.Location(item: VarType; index: Integer): Integer>
 @action: Returns index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
{$IFDEF TArray_Location1}
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
{$ENDIF}

{==============================================================================]
 <arr.Location(items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
{$IFDEF TArray_Location2}
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
{$ENDIF}

{==============================================================================]
 <arr.Locations(item: VarType; index: Integer): TIntegerArray>
 @action: Returns last index positions from arr which matched with item.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Locations1}
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
{$ENDIF}

{==============================================================================]
 <arr.Locations(items: TArray; index: Integer): TIntegerArray>
 @action: Returns last index positions from arr which matches with items.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Locations2}
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
{$ENDIF}

{==============================================================================]
 <arr.Mix(shuffles: Integer): Boolean>
 @action: Ramdomizes array with custom shuffles.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Mix}
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
{$ENDIF}

{==============================================================================]
 <arr.MostFrequent: VarType> 
 @action: Returns the most frequent arr item.
 @note: None.
[==============================================================================}
{$IFDEF TArray_MostFrequent}
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
{$ENDIF}

{==============================================================================]
 <arr.Move(oldIndex, newIndex: Integer): Boolean>
 @action: Moves item from oldIndex to newIndex in array arr.
 @note: Returns true with success.
[==============================================================================}
{$IFDEF TArray_Move}
var
  h, i: Integer;
begin
  h := High(Self);
  Result := ((h > 0) and (oldIndex <> newIndex) and InRange(oldIndex, 0, h) and InRange(newIndex, 0, h));
  if Result then
  begin
    t := Self[oldIndex];
    case (oldIndex > newIndex) of
      True:
      for i := oldIndex downto (newIndex + 1) do
        Self[i] := Self[(i - 1)];
      False:
      for i := oldIndex to (newIndex - 1) do
        Self[i] := Self[(i + 1)];
    end;
    Self[newIndex] := t;
  end;
end;
{$ENDIF}

{==============================================================================]
 <arr.Next(index: Integer; count: Integer): TArray>
 @action: Returns next items from array by index and count.
 @note: None.	
[==============================================================================}
{$IFDEF TArray_Next}
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
{$ENDIF}

{==============================================================================]
 <arr.Oversize(limit: Integer): Boolean>
 @action: Returns true if size of arr is OVER the limit.
 @note: None.	
[==============================================================================}
{$IFDEF TArray_Oversize}
begin
  Result := (Length(Self) > limit);
end;
{$ENDIF}

{==============================================================================]
 <arr.Partition(pSize: Integer): T2DArray>
 @action: Partitions array arr to 2D array by size of parts.
 @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5,6][7]
[==============================================================================}
{$IFDEF TArray_Partition}
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
{$ENDIF}

{==============================================================================]
 <arr.Pick(ID: TIntegerArray): TArray>
 @action: Outputs items with indexes (ID) from arr and deletes while picking em.
 @note: Ignores invalid ID's (doesn't include those to output, they will be left out).
        DYNAMIC - you might need to set indexes in reversed order, in order to get em correctly!
[==============================================================================}
{$IFDEF TArray_Pick}
var
  l, h, t, i, r: Integer;
begin
  h := High(Self);
  l := Length(ID);
  r := 0;
  if ((h > -1) and (l > 0)) then
  begin
    SetLength(Result, (h + 1));
    i := -1;
    repeat
      i := (i + 1);
      if ((ID[i] > h) or (ID[i] < 0)) then
        Continue;
      Result[r.Increase] := Self[ID[i]];
      for t := ID[i] to (h - 1) do
        Self[t] := Self[t + 1];
      Dec(h);
    until ((i = (l - 1)) or (h < 0));
    SetLength(Self, (h + 1));
  end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <arr.Pop: VarType>
 @action: Returns and removes item from highest array index from arr.
 @note: UNSAFE! Make sure array has enough items..
[==============================================================================}
{$IFDEF TArray_Pop1}
var
  h: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit;
  Result := Self[h];
  SetLength(Self, h);
end;
{$ENDIF}

{==============================================================================]
 <arr.Pop(null: VarType): VarType>
 @action: Returns and removes item from highest array index from arr.
 @note: Returns null if array contains no items.
[==============================================================================}
{$IFDEF TArray_Pop2}
var
  h: Integer;
begin
  h := High(Self);
  if (h = -1) then
    Exit(null);
  Result := Self[h];
  SetLength(Self, h);
end;
{$ENDIF}

{==============================================================================]
 <arr.Pos(item: VarType; index: Integer): Integer>
 @action: Returns index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
{$IFDEF TArray_Pos1}
begin
  for Result := Max(0, index) to High(Self) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <arr.Pos(items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
{$IFDEF TArray_Pos2}
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
{$ENDIF}

{==============================================================================]
 <arr.Position(item: VarType; index: Integer): Integer>
 @action: Returns index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
{$IFDEF TArray_Position1}
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
{$ENDIF}

{==============================================================================]
 <arr.Position(items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
{$IFDEF TArray_Position2}
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
{$ENDIF}

{==============================================================================]
 <arr.Positions(item: VarType; index: Integer): TIntegerArray>
 @action: Returns index positions from arr which matched with item.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Positions1}
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
{$ENDIF}

{==============================================================================]
 <arr.Positions(items: TArray; index: Integer): TIntegerArray>
 @action: Returns index positions from arr which matches with items.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Positions2}
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
{$ENDIF}

{==============================================================================]
 <arr.Previous(index: Integer; count: Integer): TIntegerArray>
 @action: Returns previous array items from index by count.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Previous}
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
{$ENDIF}

{==============================================================================]
 <arr.Put(ID: TIntegerArray; item: VarType): TArray>
 @action: Returns array arr filled with item to indexes (ID).
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Put1}
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  for i := 0 to High(ID) do
    Result[ID[i]] := item;
end;
{$ENDIF}

{==============================================================================]
 <arr.Put(ID: TIntegerArray; items: TArray): TArray>
 @action: Returns array arr filled with items to indexes (ID).
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Put2}
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
{$ENDIF}

{==============================================================================]
 <arr.Put(index: Integer; items: TArray): TArray>
 @action: Returns array arr filled with items to starting from custom start index.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Put3}
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  for i := 0 to High(items) do
    Result[index + i] := items[i];
end;
{$ENDIF}

{==============================================================================]
 <arr.Push(item: VarType): Integer>
 @action: Places item in array with arr.
 @note: Returns array (arr+item) length.
[==============================================================================}
{$IFDEF TArray_Push1}
begin
  Result := (Length(Self) + 1);
  SetLength(Self, Result);
  Self[Result - 1] := item;
end;
{$ENDIF}

{==============================================================================]
 <arr.Push(items: TArray): Integer>
 @action: Places items in array with arr.
 @note: Returns array (arr+item) length.
[==============================================================================}
{$IFDEF TArray_Push2}
var
  h, i, l: Integer;
begin
  h := High(items);
  l := Length(Self);
  Result := (l + (h + 1));
  if (h < 0) then
    Exit;
  SetLength(Self, Result);
  for i := 0 to h do
    Self[l + i] := items[i];
end;
{$ENDIF}

{==============================================================================]
 <arr.Remove(item: VarType; index: Integer; all: Boolean): Integer>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
{$IFDEF TArray_Remove1}
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
{$ENDIF}

{==============================================================================]
 <arr.Remove(item: VarType; all: Boolean): Integer>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed.
[==============================================================================}
{$IFDEF TArray_Remove2}
begin
  Result := Self.Remove(item, 0, all);
end;
{$ENDIF}

{==============================================================================]
 <arr.Remove(items: TArray; index: Integer; all: Boolean): Integer>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
{$IFDEF TArray_Remove3}
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
      Self[(r.Increase + m)] := Self[i]
    else
      d := not s;
  end;
  SetLength(Self, (r + m));
  Result := (l - Length(Self));
end;
{$ENDIF}

{==============================================================================]
 <arr.Remove(items: TArray; all: Boolean): Integer>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed.
[==============================================================================}
{$IFDEF TArray_Remove4}
begin
  Result := Self.Remove(items, 0, all);
end;
{$ENDIF}

{==============================================================================]
 <arr.Resize(aChange: Integer): Integer>
 @action: Updates's arr length with aChange.
 @note: aChange > 0 => Result will give how many elements were added
        aChange < 0 => Result will give how many elements got deleted (it will be negative value!)
		aChange = 0 => Returns 0.
[==============================================================================}
{$IFDEF TArray_Resize1}
var
  l: Integer;
begin
  l := Length(Self);
  SetLength(Self, (l + aChange));
  Result := (Length(Self) - l);
end;
{$ENDIF}

{==============================================================================]
 <arr.Resize(aChange: Integer; null: VarType): Integer>
 @action: Updates's arr length with aChange.
 @note: aChange > 0 => Result will give how many elements were added
        aChange < 0 => Result will give how many elements got deleted (it will be negative value!)
		aChange = 0 => Returns 0.
		Supports null for filling created indexes.
[==============================================================================}
{$IFDEF TArray_Resize2}
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Self, aChange);
  Result := (Length(Self) - l);
  for i := 0 to (Result - 1) do
    Self[l + i] := null;
end;
{$ENDIF}

{==============================================================================]
 <arr.Reverse: Boolean>
 @action: Reverses items in array.
 @note: Returns true with success (array contains 2 or more items)
[==============================================================================}
{$IFDEF TArray_Reverse}
var
  i, l: Integer;
begin
  l := Length(Self);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Exchange(i, ((l - i) - 1));
end;
{$ENDIF}

{==============================================================================]
 <arr.Reversed: TArray>
 @action: Returns reversed version of array arr.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Reversed}
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := Self[(l - i) - 1];
end;
{$ENDIF}

{==============================================================================]
 <arr.Scan(item: VarType; ID: TRange; limit: Integer): TIntegerArray>
 @action: Scans array for item by ID. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Scan1}
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
{$ENDIF}

{==============================================================================]
 <arr.Scan(item: VarType; ID: TIntegerArray): TIntegerArray>
 @action: Scans array for item by ID. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Scan2}
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
{$ENDIF}

{==============================================================================]
 <arr.Scan(items: TArray; ID: TRange; limit: Integer): TIntegerArray>
 @action: Scans array for items by ID. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Scan3}
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
{$ENDIF}

{==============================================================================]
 <arr.Scan(item: VarType; ID: TIntegerArray): TIntegerArray>
 @action: Scans array for items by ID. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Scan4}
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
{$ENDIF}

{==============================================================================]
 <arr.Shift: VarType>
 @action: Shortens the array with first element.
 @note: Returns the removed arr[0].
[==============================================================================}
{$IFDEF TArray_Shift1}
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
{$ENDIF}

{==============================================================================]
 <arr.Shift(sCount: Integer): TArray>
 @action: Shortens the array with first SCOUNT element(s).
 @note: Returns the removed arr[x]s.
[==============================================================================}
{$IFDEF TArray_Shift2}
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
{$ENDIF}

{==============================================================================]
 <arr.Size(aSize: Integer): Integer> 
 @action: Sets array size as aSize and then returns the size using Length call.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Size1}
begin
  SetLength(Self, aSize);
  Result := Length(Self);
end;
{$ENDIF}

{==============================================================================]
 <arr.Size: Integer> 
 @action: Returns array length.
 @note: Simply Result := Length(arr);
[==============================================================================}
{$IFDEF TArray_Size2}
begin
  Result := Length(Self);
end;
{$ENDIF}

{==============================================================================]
 <arr.SizeBetween(arr: TArray; sMin, sMax: Integer): Boolean>
 @action: Returns true if size is at equal/greater than sMin and equal/lesser than sMax.
 @note: 	
[==============================================================================}
{$IFDEF TArray_SizeBetween}
begin
  Result := InRange(Length(Self), sMin, sMax);
end;      
{$ENDIF}

{==============================================================================]
 <arr.SizeMax(target: Integer): Boolean>
 @action: Returns true if size is at equal/lesser than target.
 @note: 	
[==============================================================================}
{$IFDEF TArray_SizeMax}
begin
  Result := (Length(Self) <= target);
end;    
{$ENDIF}

{==============================================================================]
 <arr.SizeMin(target: Integer): Boolean>
 @action: Returns true if size is at equal/greater than target.
 @note: 	
[==============================================================================}
{$IFDEF TArray_SizeMin}
begin
  Result := (Length(Self) >= target);
end;   
{$ENDIF}

{==============================================================================]
 <arr.SubarrayLocation(pattern: TArray): Integer>
 @action: Returns subarray position in arr that match pattern exactly.
 @note: arr[0,1,2,0,1,2,3].([1,2]) => 4	
[==============================================================================}
{$IFDEF TArray_SubarrayLocation}
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
        s := s + 1;
    if (s = p) then
      Exit(i);
  end;
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <arr.SubarrayLocations(pattern: TArray): TIntegerArray>
 @action: Returns subarray positions in arr that match pattern exactly.
 @note: arr[0,1,2,0,1,2,3].([1,2]) => [4,1]	
[==============================================================================}
{$IFDEF TArray_SubarrayLocations}
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
          s := s + 1;
      if (s = p) then
        Result[r.Increase] := i;
    end;
  end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <arr.SubarrayPosition(pattern: TArray): Integer>
 @action: Returns subarray position in arr that match pattern exactly.
 @note: arr[0,1,2,0,1,2,3].([1,2]) => 1	
[==============================================================================}
{$IFDEF TArray_SubarrayPosition}
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
{$ENDIF}

{==============================================================================]
 <arr.SubarrayPositions(pattern: TArray): TIntegerArray>
 @action: Returns subarray positions in arr that match pattern exactly.
 @note: arr[0,1,2,0,1,2,3].([1,2]) => [1,4]	
[==============================================================================}
{$IFDEF TArray_SubarrayPositions}
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
{$ENDIF}

{==============================================================================]
 <arr.Swap(b: TArray): Integer> 
 @action: Swaps array arr and array b.
 @note: arr will be b and b will be arr.
[==============================================================================}
{$IFDEF TArray_Swap}
begin
  Result := (Length(Self) + Length(b));
  if (Result = 0) then
    Exit;
  a := Self.Dupe;
  Self := b.Dupe;
  b := a.Dupe;
  SetLength(a, 0);
end; 
{$ENDIF}

{==============================================================================]
 <arr.Trade(b: TArray): Integer> 
 @action: Swaps array arr and array b.
 @note: arr will be b and b will be arr.
[==============================================================================}
{$IFDEF TArray_Trade}
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
{$ENDIF}

{==============================================================================]
 <arr.Undersize(limit: Integer): Boolean>
 @action: Returns true if size of arr is UNDER the limit.
 @note: None.	
[==============================================================================} 
{$IFDEF TArray_Undersize}
begin
  Result := (Length(Self) < limit);
end;
{$ENDIF}

{==============================================================================]
 <arr.Unique: Integer>
 @action: Removes all duplicates from arr.
 @note: Returns the number of items that were removed.
[==============================================================================}
{$IFDEF TArray_Unique}
var
  a, l, i, j: Integer;
  m: Boolean;
begin
  l := Length(Self);
  if (l < 2) then
    Exit(0);
  a := 0;
  for i := 1 to (l - 1) do
  begin
    for j := 0 to a do
    begin
      m := (Self[i] = Self[j]);
      if m then
        Break;
    end;
    if m then
      Continue;
    Self[a.Increment] := Self[i];
  end;
  Result := (l - (a + 1));
  if (Result > 0) then
    SetLength(Self, (a + 1));
end;
{$ENDIF}

{==============================================================================]
 <arr.Uniqued: TArray>
 @action: Removes all duplicates from arr.
 @note: Returns the unique version of arr.
[==============================================================================}
{$IFDEF TArray_Uniqued}
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
{$ENDIF}

{==============================================================================]
 <arr.Uniques: TIntegerArray>
 @action: Returns the indexes of unique array (arr) items.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Uniques}
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
{$ENDIF}

{==============================================================================]
 <arr.Unshift(item: VarType): Integer>
 @action: Grows arr with item. Returns the index of added item.
 @note: Adds item to the left side of the array. (Opposite to TArray_Append!
[==============================================================================}
{$IFDEF TArray_Unshift1}
var
  i: Integer;
begin
  Result := Length(Self);
  SetLength(Self, (Result + 1));
  for i := Result downto 1 do
    Self[i] := Self[i - 1];
  Self[0] := item;
end;
{$ENDIF}

{==============================================================================]
 <arr.Unshift(items: TArray): Integer>
 @action: Grows arr with items. Returns the index of last added item.
 @note: Adds item to the left side of the array. (Opposite to TArray_Append!
[==============================================================================}
{$IFDEF TArray_Unshift2}
var
  h, l, i: Integer;
begin
  h := High(items);
  if (h = -1) then
    Exit(High(Self));
  l := Length(Self);
  Result := (l + h);
  SetLength(Self, (Result + 1));
  for i := Result downto (h + 1) do
    Self[i] := Self[i - (h + 1)];
  for i := 0 to h do
    Self[i] := items[i];
end;
{$ENDIF}
