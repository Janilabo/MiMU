{==============================================================================]
 <TArray_Add(const arr: TArray; item: VarType; duplicates: Boolean): TArray>
 @action: Appends arr with item. Returns the array with added item.
 @note: Adds item to the right side of the array.
[==============================================================================}
{$IFDEF TArray_Add1}
var
  i, l: Integer;
begin
  l := Length(arr);
  SetLength(Result, (l + 1));
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  if ((not duplicates) and TArray_Contains(arr, item)) then
    SetLength(Result, l)
  else
    Result[l] := item;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Add(const arr: TArray; items: TArray; duplicates: Boolean): TArray>
 @action: Appends arr with items. Returns the array with added items.
 @note: Adds item to the right side of the array.
[==============================================================================}
{$IFDEF TArray_Add2}
var
  a, h, i, l: Integer;
begin
  h := High(items);
  l := Length(arr);
  SetLength(Result, (l + (h + 1)));
  if ((h = -1) and (l = 0)) then
    Exit;
  for i := 0 to (l - 1) do
    Result[i] := arr[i];
  case duplicates of
    False:
	begin
	  a := 0;
	  for i := 0 to h do
	    if not TArray_Contains(Result, items[i]) then
        Result[(l + Integer_Inc(a))] := items[i];
      SetLength(Result, (l + a));
    end;
    True:
    for i := 0 to h do
      Result[(l + i)] := items[i];
  end;
end;
{$ENDIF}

{==============================================================================]
 <TArray_AllEqual(arr: TArray): Boolean>
 @action: Returns true if all values in arr are equal (arr contains only equal values).
 @note: None
[==============================================================================}
{$IFDEF TArray_AllEqual}
var
  h, i, l: Integer;
begin
  l := Low(arr);
  h := High(arr);
  for i := (l + 1) to h do
    if (arr[l] <> arr[i]) then
      Exit(False);
  Result := (Length(arr) > 0);
end;
{$ENDIF}

{==============================================================================]
 <TArray_AllSame(arr: TArray): Boolean>
 @action: Returns true if all values in arr are the same (arr contains only equal values).
 @note: None
[==============================================================================}
{$IFDEF TArray_AllSame}
var
  i: Integer;
begin
  for i := 1 to High(arr) do
    if (arr[0] <> arr[i]) then
      Exit(False);
  Result := (Length(arr)  > 0);
end;
{$ENDIF}

{==============================================================================]
 <TArray_AllUnique(arr: TArray): Boolean>
 @action: Returns true if all values in arr are unique (arr contains ONLY unique values).
 @note: None
[==============================================================================}
{$IFDEF TArray_AllUnique}
var
  h, a, b: Integer;
begin
  h := High(arr);
  for a := 0 to (h - 1) do
    for b := (a + 1) to h do
      if (arr[a] = arr[b]) then
        Exit(False);
  Result := (h > -1);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Append(arr: TArray; item: VarType; duplicates: Boolean): Integer>
 @action: Appends arr with item. Returns the index of added item.
 @note: Adds item to the right side of the array.
[==============================================================================}
{$IFDEF TArray_Append1}
begin
  if ((not duplicates) and TArray_Contains(arr, item)) then
    Exit(High(arr));
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  arr[Result] := item;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Append(arr: TArray; items: TArray; duplicates; Boolean): Integer>
 @action: Adds all items items to arr.
 @note: Returns the highest index in the end.
[==============================================================================}
{$IFDEF TArray_Append2}
var
  h, i: Integer;
begin
  h := High(items);
  Result := High(arr);
  if (h = -1) then
    Exit;
  SetLength(arr, ((Result + h) + 2));
  case duplicates of
    False:
	  begin
	    for i := 0 to h do
	      if not TArray_Contains(arr, items[i]) then
          arr[(Integer_Incr(Result))] := items[i];
      SetLength(arr, (Result + 1));
    end;
    True:
  	for i := 0 to h do
      arr[Integer_Incr(Result)] := items[i];
  end;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Build(item: VarType; size: Integer): TArray> 
 @action: Creates array with item where size is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}
{$IFDEF TArray_Build}
begin
  Result := TArray_Create(size, item);
end;
{$ENDIF}

{==============================================================================]
 <TArray_BuiltWith(arr, allowed: TArray): Boolean> 
 @action: Checks if array arr contains only allowed items.
 @note: None.
[==============================================================================}
{$IFDEF TArray_BuiltWith}
var
  i, x, y: Integer;
begin
  y := Length(allowed);
  i := High(arr);
  if ((i < 0) or (y < 1)) then
    Exit(False);
  repeat
     x := 0;
     repeat
       Result := (arr[i] = allowed[x]);
       x := (x + 1);
     until (Result or (x = y));
     i := (i - 1);
  until ((i < 0) or (not Result));
end;
{$ENDIF}

{==============================================================================]
 <TArray_BuiltWithout(arr, forbidden: TArray): Boolean> 
 @action: Checks if array arr does not have any forbidden items.
 @note: None.
[==============================================================================}
{$IFDEF TArray_BuiltWithout}
var
  i, x, y: Integer;
begin
  if (Length(arr) < 1) then
    Exit(False);
  y := Length(forbidden);
  if not (y < 1) then
  begin
    i := High(arr);
    repeat
       x := 0;
       repeat
         Result := not (arr[i] = forbidden[x]);
         x := (x + 1);
       until ((x = y) or (not Result));
       i := (i - 1);
    until ((i < 0) or (not Result));
  end else
    Result := True;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Clone(arr: TArray; index: Integer; count: Integer): TArray>
 @action: Returns copy of an array arr.
 @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}
{$IFDEF TArray_Clone}
var
  i, s, c: Integer;
begin
  if (count > 0) then
  begin
    if (index < 0) then
      c := (index + count)
    else
      c := Min(count, (Length(arr) - index));
    s := Max(0, index);
    SetLength(Result, c);
    for i := s to ((s + c) - 1) do
      Result[(i - s)] := arr[i];
  end else
    SetLength(Result, 0);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Combine(a, b: TArray): TArray>
 @action: Combines arrays a and b together as single array.
 @note: This is an alternative method. :)
[==============================================================================}
{$IFDEF TArray_Combine}
begin
  SetLength(Result, 0);
  Insert(a, Result, 0);
  Insert(b, Result, Length(a));
end;
{$ENDIF}

{==============================================================================]
 <TArray_Contains(arr: TArray; item: VarType; index: Integer): Boolean>
 @action: Looks array for item starting from start index. If found, Result will be True.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Contains}
var
  i: Integer;
begin
  for i := index to High(arr) do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Copy(arr: TArray; index: Integer; count: Integer): TArray>
 @action: Returns copy of an array arr.
 @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}
{$IFDEF TArray_Copy1}
begin
  Result := Copy(arr, index, count);  
end;
{$ENDIF}

{==============================================================================]
 <TArray_Copy(arr: TArray; IDs: TIntegerArray): TArray>
 @action: Outputs array of items from arr by indexes (IDs).
 @note: Ignores invalid ID's (doesn't include those to result, they will be left out).
[====================
==========================================================}
{$IFDEF TArray_Copy2}
var
  i, h, l, r: Integer;
begin
  r := 0;
  h := High(arr);
  l := Length(IDs);
  if ((l > 0) and (h > -1)) then
  begin
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if ((IDs[i] <= h) and (IDs[i] > -1)) then
      begin
        Result[r] := arr[IDs[i]];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Create(item: VarType): TArray> 
 @action: Creates array with item, size as 1.
 @note: [item]
[==============================================================================}
{$IFDEF TArray_Create1}
begin
  SetLength(Result, 1);
  Result[0] := item;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Create(size: Integer; item: VarType): TArray> 
 @action: Creates array with item where size is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}
{$IFDEF TArray_Create2}
var
  i: Integer;
begin
  SetLength(Result, Max(0, size));
  for i := 0 to High(Result) do
    Result[i] := item;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Delete(arr: TArray; index: Integer): Boolean>
 @action: Deletes array item from arr by index.
 @note: Returns true with success (index existed in arr).
[==============================================================================}
{$IFDEF TArray_Delete1}
var
  i, h: Integer;
begin
  h := High(arr);
  Result := ((index <= h) and (index > -1));
  if not Result then
    Exit;
  for i := index to (h - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, h);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Delete(arr: TArray; IDs: TIntegerArray): Integer>
 @action: Deletes array items from arr by indexes (IDs).
 @note: Returns amount of items that were deleted succesfully by IDs.
[==============================================================================}
{$IFDEF TArray_Delete2}
var
  i, l: Integer;
begin
  l := Length(arr);
  Result := 0;
  for i := 0 to (l - 1) do
    if not TArray_Contains(IDs, i) then
      arr[(i - Result)] := arr[i]
    else
      Result := (Result + 1);
  SetLength(arr, (l - Result));
end;
{$ENDIF}

{==============================================================================]
 <TArray_Differ(arr, target: TArray): Boolean>
 @action: Returns true if arr differs from target.
 @note: None
[==============================================================================}
{$IFDEF TArray_Differ}
var
  i: Integer;
begin
  Result := (Length(arr) <> Length(target));
  if not Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(True);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Distribute(arr: TArray; parts: Integer): T2DArray>
 @action: Distributes array arr to 2D array by number of parts.
 @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5][6,7]
 [==============================================================================}
{$IFDEF TArray_Distribute}
var
  l, p, b, r, i, j, s, c: Integer;
begin
  l := Length(arr);
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
      begin
        Result[i][j] := arr[s];
        Inc(s);
      end;
    end;
  end else
    SetLength(Result, 0);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Dump(arr: TArray; items: TArray; index: Integer): Integer>
 @action: Deletes items from array, keeps others. Returns array length (after action).
 @note: Supports custom start index!
[==============================================================================}
{$IFDEF TArray_Dump}
var
  i, l: Integer;
begin
  l := Length(arr);
  Result := 0;
  if (High(items) > -1) then
  for i := Max(0, index) to (l - 1) do
    if not TArray_Contains(items, arr[i]) then
      arr[(i - Result)] := arr[i]
    else
      Inc(Result);
  Result := (l - Result);
  if (Result < l) then
    SetLength(arr, Result);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Dupe(arr: TArray): TArray>
 @action: Returns copy of an array arr.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Dupe}
var
  i, l, j: Integer;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    if ((l mod 2) <> 0) then
    begin
      j := (l div 2);
      Result[j] := arr[j];
    end;
    if (l = 1) then
	  Exit;
    for i := 0 to ((l div 2) - 1) do
    begin
      j := ((l - i) - 1);
      Result[i] := arr[i];
      Result[j] := arr[j];
    end;
  end;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Empty(arr: TArray): Boolean>
 @action: Returns true if array is empty (Length = 0).
 @note: None.
[==============================================================================}
{$IFDEF TArray_Empty}
begin
  Result := (Length(arr) = 0);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Equal(arr, target: TArray): Boolean>
 @action: Returns true if arr equals target (identical arrays)
 @note: None
[==============================================================================}
{$IFDEF TArray_Equal}
var
  i: Integer;
begin
  Result := (Length(arr) = Length(target));
  if Result then
  for i := High(arr) downto 0 do
    if (arr[i] <> target[i]) then
      Exit(False);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Extend(arr: TArray; item: VarType): TArray>
 @action: Extends arr with item. Returns it.
 @note: Places item to the left side of the array.
[==============================================================================}
{$IFDEF TArray_Extend1}
var
  i, h: Integer;
begin
  h := High(arr);
  SetLength(Result, (h + 2));
  for i := 0 to h do
    Result[(i + 1)] := arr[i];
  Result[0] := item;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Extend(arr, items: TArray): TArray>
 @action: Extends arr with items. Returns it.
 @note: Places items to the left side of the array.
[==============================================================================}
{$IFDEF TArray_Extend2}
var
  i, h, l: Integer;
begin
  h := High(arr);
  l := Length(items);
  SetLength(Result, ((h + 1) + l));
  for i := 0 to h do
    Result[(i + l)] := arr[i];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;
{$ENDIF}

{==============================================================================]
 <TArray_Extract(arr: TArray; item: VarType; index: Integer): TArray>
 @action: Keeps (extracts) all values in arr that are item. Starts scan from start index.
 @note: Returns the items.
[==============================================================================} 
{$IFDEF TArray_Extract1}
var
  i, l, r: Integer;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (arr[i] = item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Extract(arr, items: TArray; index: Integer): TArray>
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
    l := Length(arr);
    SetLength(Result, (l - index));
    for i := index to (l - 1) do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := arr[i];
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <TArray_ExtractEvery(arr: TArray; X: Integer; index: Integer): TArray>
 @action: Keeps (extracts) all X values from array. Starts scan from start index.
 @note: Returns the items.
[==============================================================================} 
{$IFDEF TArray_ExtractEvery}
var
  i, h, l: Integer;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Fill(arr: TArray; item: VarType; index: Integer; count: Integer): TArray>
 @action: Fills whole arr with item.
 @note: None
[==============================================================================}
{$IFDEF TArray_Fill1}
var
  h, i, s, t: Integer;
begin
  s := Max(0, index);
  h := High(arr);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := item;
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;
{$ENDIF}

{==============================================================================]
 <TArray_Fill(arr, items: TArray; index: Integer; count: Integer): TArray>
 @action: Fills whole arr with items.
 @note: None
[==============================================================================}
{$IFDEF TArray_Fill2}
var
  h, i, s, t, l: Integer;
begin
  h := High(arr);
  l := Length(items);
  case l of
    0: Exit(Copy(arr, 0, (h + 1)));
    1: Exit(TArray_Fill(arr, items[0], index, count));
  end;
  s := Max(0, index);
  SetLength(Result, (h + 1));
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  t := Min(h, (s + (count - 1)));
  for i := s to t do
    Result[i] := items[((index + i) mod (l - 1))];
  for i := (t + 1) to h do
    Result[i] := arr[i];
end;
{$ENDIF}

{==============================================================================]
 <TArray_Filter(arr: TArray; item: VarType; index: Integer): TArray>
 @action: Removes all values from arr that are found in items.
 @note: None
[==============================================================================}
{$IFDEF TArray_Filter1}
var
  i, l, r: Integer;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  r := 0;
  for i := index to (l - 1) do
    if (arr[i] <> item) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Filter(arr, items: TArray; index: Integer): TArray>
 @action: Removes all values from arr that are found in items.
 @note: None
[==============================================================================}
{$IFDEF TArray_Filter2}
var
  i, l, r: Integer;
begin
  l := Length(arr);
  if (Length(items) = 0) then
    Exit(Copy(arr, index, (l - index)));
  r := 0;
  SetLength(Result, (l - index));
  for i := index to (l - 1) do
    if not TArray_Contains(items, arr[i]) then
    begin
      Result[r] := arr[i];
      Inc(r);
    end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <TArray_FilterEvery(arr: TArray; X: Integer; index: Integer): TArray>
 @action: Filters every/each X item from arr.
 @note: Custom index
[==============================================================================}
{$IFDEF TArray_FilterEvery}
var
  i, h, l: Integer;
begin
  l := Length(arr);
  SetLength(Result, (l - index));
  if ((l - index) < 1) then
    Exit;
  h := 0;
  for i := index to (l - 1) do
    if not (((i - index) mod X) = 0) then
    begin
      Result[h] := arr[i];
      Inc(h);
    end;
  SetLength(Result, h);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Find(arr: TArray; item: VarType; IDs: TRange): Integer>
 @action: Scans array for item by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Find1}
begin
  if (High(arr) > -1) then
  case TRange_Ascending(IDs) of
    True:
    for Result := IDs.start to IDs.stop do
      if (arr[Result] = item) then
        Exit;
    False:
    for Result := IDs.start downto IDs.stop do
      if (arr[Result] = item) then
        Exit;
  end;
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Find(arr: TArray; item: VarType; IDs: TIntegerArray): Integer>
 @action: Scans array for item by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Find2}
var
  i: Integer;
begin
  if (High(arr) > -1) then
  for i := 0 to High(IDs) do
    if (arr[IDs[i]] = item) then
      Exit(IDs[i]);
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Find(arr: TArray; items: TArray; IDs: TRange): Integer>
 @action: Scans array for items by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Find3}
begin
  if ((High(arr) > -1) and (High(items) > -1)) then
  case TRange_Ascending(IDs) of
    True:
    for Result := IDs.start to IDs.stop do
      if TArray_Contains(items, arr[Result]) then
        Exit;
    False:
    for Result := IDs.start downto IDs.stop do
      if TArray_Contains(items, arr[Result]) then
        Exit;
  end;
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Find(arr: TArray; items: TArray; IDs: TIntegerArray): Integer>
 @action: Scans array for items by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Find4}
var
  i: Integer;
begin
  if ((High(arr) > -1) and (High(items) > -1)) then
  for i := 0 to High(IDs) do
    if TArray_Contains(items, arr[IDs[i]]) then
      Exit(IDs[i]);
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Flip(arr: TArray): Boolean>
 @action: Reverses array arr.
 @note: Alternative for TArray_Reverse
[==============================================================================}
{$IFDEF TArray_Flip}
var
  i, l: Integer;
begin
  i := 0;
  l := (Length(arr) - 1);
  Result := (l > 0);
  while (i < l) do
  begin
    Swap(arr[i], arr[l]);
    Inc(i);
    Dec(l);
  end;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Get(arr: TArray): TArray>
 @action: Copy of an array arr.
 @note: Just an alternative.
[==============================================================================}
{$IFDEF TArray_Get1}
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
end;
{$ENDIF}

{==============================================================================]
 <TArray_Get>
 @action: Outputs array of items from arr by indexes (IDs).
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Get2}
var
  i: Integer;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(IDs) do
    Result[i] := arr[IDs[i]];
end;
{$ENDIF}

{==============================================================================]
 <TArray_Group(arr: TArray): T2DArray>
 @action: Groups array arr to 2D array by items.
 @note: ([1,2,1,2,3,1,2,3,4]) => [1,1,1][2,2,2][3,3][4]
[==============================================================================}
{$IFDEF TArray_Group}
var
  a, h, i, r, g, l: Integer;
  f: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h = -1) then
    Exit;
  g := -1;
  for i := 0 to h do
  begin
    f := False;
    for r := 0 to g do
    begin
      f := (arr[i] = Result[r][0]);
      if f then
      begin
        l := Length(Result[r]);
        SetLength(Result[r], (l + 1));
        Result[r][l] := arr[i];
        Break;
      end;
    end;
    if not f then
    begin
      g := (g + 1);
      SetLength(Result[g], 1);
      Result[g][0] := arr[i];
    end;
  end;
  SetLength(Result, (g + 1));
end;
{$ENDIF}

{==============================================================================]
 <TArray_Holds(arr, chain: TArray): Boolean>
 @action: Returns true if arr contains (holds) WHOLE chain of items in it.
 @note: Starting from any index and ending to any index!
[==============================================================================}
{$IFDEF TArray_Holds}
var
  a, b, x, y, z: Integer;
  n: Boolean;
begin
  z := High(arr);
  y := High(chain);
  if ((z < y) or (y = -1)) then
    Exit(False);
  a := -1;
  b := (z - y);
  repeat
    a := (a + 1);
    for x := 0 to y do
    begin
      n := (arr[(a + x)] <> chain[x]);
      if n then
        Break;
    end;
    Result := not n;
  until ((a = b) or Result);
end;
{$ENDIF}

{==============================================================================]
 <TArray_IDs(arr: TArray): TIntegerArray>
 @action: Returns IDs of arr as TIntegerArray.
 @note: None.
[==============================================================================}
{$IFDEF TArray_IDs1}
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := i;
end;
{$ENDIF}

{==============================================================================]
 <TArray_IDs(arr: TArray; IDs: TIntegerArray): TArray>
 @action: Returns items from arr by IDs.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array.
[==============================================================================}
{$IFDEF TArray_IDs2}
var
  i: Integer;
begin
  SetLength(Result, Length(IDs));
  for i := 0 to High(Result) do
    Result[i] := arr[IDs[i]];
end;
{$ENDIF}

{==============================================================================]
 <TArray_IDs(arr: TArray; IDs: TIntegerArray; item: VarType): TArray>
 @action: Returns arr with IDs replaced as item.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array.
[==============================================================================}
{$IFDEF TArray_IDs3}
var
  i: Integer;
begin
  Result := TArray_Get(arr);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;
{$ENDIF}

{==============================================================================]
 <TArray_IDs(arr: TArray; IDs: TIntegerArray; items: TArray): TArray>
 @action: Returns arr with IDs replaced as items.
 @note: UNSAFE! No failsafes, so make sure you use correct indexes in IDs array and ALSO item[s].
[==============================================================================}
{$IFDEF TArray_IDs4}
var
  i, l: Integer;
begin
  Result := TArray_Get(arr);
  l := Length(items);
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;
{$ENDIF}

{==============================================================================]
 <TArray_Includes(arr: TArray; item: VarType; index: Integer): Boolean>
 @action: Looks array for item starting from start index down to index 0. If found, Result will be True.
 @note: Alternative to TArray_Contains, but this scans in opposite direction.
[==============================================================================}
{$IFDEF TArray_Includes}
var
  i: Integer;
begin
  for i := Min(High(arr), index) downto 0 do
    if (item = arr[i]) then
      Exit(True);
  Result := False;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Keep(arr, items: TArray; index: Integer): Integer>
 @action: Keeps items in array, removes others. Returns array length (after action).
 @note: Supports custom start index!
[==============================================================================}
{$IFDEF TArray_Keep}
var
  i, l: Integer;
begin
  l := Length(arr);
  case (High(items) > -1) of
    True:
    begin
      Result := 0;
      for i := Max(0, index) to (l - 1) do
        if TArray_Contains(items, arr[i]) then
          arr[(i - Result)] := arr[i]
        else
          Inc(Result);
    end;
    False: Result := (l - Max(0, index));
  end;
  Result := (l - Result);
  if (Result < l) then
    SetLength(arr, Result);
end;
{$ENDIF}

{==============================================================================]
 <TArray_LeastFrequent(arr: TArray): VarType> 
 @action: Returns the least frequent arr item.
 @note: None.
[==============================================================================}
{$IFDEF TArray_LeastFrequent}
var
  i, j, c, m: Integer;
  f: Boolean;
begin
  if (Length(arr) = 0) then
    Exit;
  m := 2147483647;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    f := False;
    for j := 0 to (i - 1) do
      if (arr[j] = arr[i]) then
      begin
        f := True;
        Break;
      end;
    if f then
      Continue;
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c < m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Length(arr: TArray, size: Integer): Integer> 
 @action: Returns size and sets it as size of arr.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Length1}
begin
  Result := size;
  SetLength(arr, size);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Length(arr: TArray: TArray): Integer> 
 @action: Returns array length.
 @note: Simply Result := Length(arr);
[==============================================================================}
{$IFDEF TArray_Length2}
begin
  Result := Length(arr);
end;
{$ENDIF}

{==============================================================================]
 <TArray_MostFrequent(arr: TArray): VarType> 
 @action: Returns the most frequent arr item.
 @note: None.
[==============================================================================}
{$IFDEF TArray_MostFrequent}
var
  i, j, c, m: Integer;
begin
  if (High(arr) = -1) then
    Exit;
  m := 0;
  Result := arr[0];
  for i := 0 to High(arr) do
  begin
    c := 1;
    for j := (i + 1) to High(arr) do
      if (arr[j] = arr[i]) then
        Inc(c);
    if (c > m) then
    begin
      m := c;
      Result := arr[i];
    end;
  end;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Move(arr: TArray; oldIndex, newIndex: Integer): Boolean>
 @action: Moves item from oldIndex to newIndex in array arr.
 @note: Returns true with success.
[==============================================================================}
{$IFDEF TArray_Move}
var
  h, i: Integer;
begin
  h := High(arr);
  Result := ((h > 0) and (oldIndex <> newIndex) and InRange(oldIndex, 0, h) and InRange(newIndex, 0, h));
  if Result then
  begin
    t := arr[oldIndex];
    case (oldIndex > newIndex) of
      True:
      for i := oldIndex downto (newIndex + 1) do
        arr[i] := arr[(i - 1)];
      False:
      for i := oldIndex to (newIndex - 1) do
        arr[i] := arr[(i + 1)];
    end;
    arr[newIndex] := t;
  end;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Oversize(arr: TArray; limit: Integer): Boolean>
 @action: Returns true if size of arr is OVER the limit.
 @note: None.	
[==============================================================================}
{$IFDEF TArray_Oversize}
begin
  Result := (Length(arr) > limit);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Partition(arr: TArray; size: Integer): T2DArray>
 @action: Partitions array arr to 2D array by size of parts.
 @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5,6][7]
[==============================================================================}
{$IFDEF TArray_Partition}
var
  p, i, j, s, r, l: Integer;
begin
  l := Length(arr);
  if ((size > 0) and (l > 0)) then
  begin
    p := ((l + (size - 1)) div size);
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      s := (i * size);
      if ((s + size) > l) then
        r := (l - s)
      else
        r := size;
      SetLength(Result[i], r);
      for j := 0 to (r - 1) do
        Result[i][j] := arr[(s + j)];
    end;
  end else
    SetLength(Result, 0);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Pick(arr: TArray; IDs: TIntegerArray): TArray>
 @action: Outputs items with indexes (IDs) from arr and deletes while picking em.
 @note: Ignores invalid ID's (doesn't include those to output, they will be left out).
        DYNAMIC - you might need to set indexes in reversed order, in order to get em correctly!
[==============================================================================}
{$IFDEF TArray_Pick}
var
  l, h, t, i, r: Integer;
begin
  h := High(arr);
  l := Length(IDs);
  r := 0;
  if ((h > -1) and (l > 0)) then
  begin
    SetLength(Result, (h + 1));
    i := -1;
    repeat
      i := (i + 1);
      if ((IDs[i] > h) or (IDs[i] < 0)) then
        Continue;
      Result[r] := arr[IDs[i]];
      Inc(r);
      for t := IDs[i] to (h - 1) do
        arr[t] := arr[(t + 1)];
      Dec(h);
    until ((i = (l - 1)) or (h < 0));
    SetLength(arr, (h + 1));
  end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Pop(arr: TArray): VarType>
 @action: Returns and removes item from highest array index from arr.
 @note: UNSAFE! Make sure array has enough items..
[==============================================================================}
{$IFDEF TArray_Pop1}
var
  h: Integer;
begin
  h := High(arr);
  if (h = -1) then
    Exit;
  Result := arr[h];
  SetLength(arr, h);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Pop(arr: TArray; null: VarType): VarType>
 @action: Returns and removes item from highest array index from arr.
 @note: Returns null if array contains no items.
[==============================================================================}
{$IFDEF TArray_Pop2}
var
  h: Integer;
begin
  h := High(arr);
  if (h = -1) then
    Exit(null);
  Result := arr[h];
  SetLength(arr, h);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Pos(arr: TArray; item: VarType; index: Integer): Integer>
 @action: Returns index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
{$IFDEF TArray_Pos1}
begin
  for Result := index to High(arr) do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Pos(arr: TArray; items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
{$IFDEF TArray_Pos2}
var
  h, i: Integer;
begin
  h := High(items);
  for Result := index to High(arr) do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Position(arr: TArray; item: VarType; index: Integer): Integer>
 @action: Returns index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
{$IFDEF TArray_Position1}
begin
  for Result := Max(0, index) to High(arr) do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Position(arr: TArray; items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
{$IFDEF TArray_Position2}
var
  h, i: Integer;
begin
  h := High(items);
  if (h > -1) then
  for Result := Max(0, index) to High(arr) do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Positions(arr: TArray; item: VarType; index: Integer): TIntegerArray>
 @action: Returns index positions from arr which matched with item.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Positions1}
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Positions(arr: TArray; items: TArray; index: Integer): TIntegerArray>
 @action: Returns index positions from arr which matches with items.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Positions2}
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(arr);
  s := Max(0, index);
  if ((h > -1) and (s <= h) and (Length(items) > 0)) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <TArray_PosLast(arr: TArray; item: VarType; index: Integer): Integer>
 @action: Returns last index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
{$IFDEF TArray_PosLast1}
begin
  for Result := Min(High(arr), index) downto 0 do
    if (arr[Result] = item) then
      Exit;
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Pos(arr: TArray; items: TArray; index: Integer): Integer>
 @action: Returns index position from arr which matches with items.
 @note: Returns -1 if any of arr items doesnt match with items!
[==============================================================================}
{$IFDEF TArray_PosLast2}
var
  h, i: Integer;
begin
  h := High(items);
  for Result := Min(High(arr), index) downto 0 do
    for i := 0 to h do
      if (arr[Result] = items[i]) then
        Exit;
  Result := -1;
end;
{$ENDIF}

{==============================================================================]
 <TArray_PosLasts(arr: TArray; item: VarType; index: Integer): TIntegerArray>
 @action: Returns last index positions from arr which matched with item.
 @note: None.
[==============================================================================}
{$IFDEF TArray_PosLasts1}
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(arr);
  s := Min(index, h);
  if ((h > -1) and (s > -1)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if (arr[i] = item) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <TArray_PosLasts(arr: TArray; items: TArray; index: Integer): TIntegerArray>
 @action: Returns last index positions from arr which matches with items.
 @note: None.
[==============================================================================}
{$IFDEF TArray_PosLasts2}
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(arr);
  s := Min(index, h);
  if ((h > -1) and (s > -1) and (Length(items) > 0)) then
  begin
    SetLength(Result, (s + 1));
    for i := s downto 0 do
      if TArray_Contains(items, arr[i]) then
      begin
        Result[r] := i;
        Inc(r);
      end;
  end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Push(arr: TArray; item: VarType): Integer>
 @action: Places item in array with arr.
 @note: Returns array (arr+item) length.
[==============================================================================}
{$IFDEF TArray_Push1}
begin
  Result := (Length(arr) + 1);
  SetLength(arr, Result);
  arr[(Result - 1)] := item;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Push(arr: TArray; items: TArray): Integer>
 @action: Places items in array with arr.
 @note: Returns array (arr+item) length.
[==============================================================================}
{$IFDEF TArray_Push2}
var
  h, i, l: Integer;
begin
  h := High(items);
  l := Length(arr);
  Result := (l + (h + 1));
  if (h < 0) then
    Exit;
  SetLength(arr, Result);
  for i := 0 to h do
    arr[(l + i)] := items[i];
end;
{$ENDIF}

{==============================================================================]
 <TArray_Randomize(arr: TArray): Boolean>
 @action: Ramdomizes array with custom shuffles.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Randomize}
var
  l, i, s, x, y: Integer;
begin
  l := Length(arr);
  Result := ((l > 1) and (shuffles > 0));
  if not Result then
    Exit;
  for s := 1 to shuffles do
    for i := 0 to (l - 1) do
    begin
      x := Random(l);
      y := Random(l);
	  Swap(arr[x], arr[y]);
    end;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Remove(arr: TArray; item: VarType; index: Integer; all: Boolean): Integer>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
{$IFDEF TArray_Remove1}
var
  l, i, r, m: Integer;
  s: Boolean;
begin
  l := Length(arr);
  if ((l = 0) or (index >= l)) then
    Exit(0);
  m := Max(0, index);
  s := False;
  r := 0;
  for i := m to (l - 1) do
    if (s or (arr[i] <> item)) then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      s := not all;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;
{$ENDIF}

{==============================================================================]
 <TArray_Remove(arr: TArray; item: VarType; all: Boolean): Integer>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed.
[==============================================================================}
{$IFDEF TArray_Remove2}
begin
  Result := TArray_Remove(arr, item, 0, all);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Remove(arr: TArray; items: TArray; index: Integer; all: Boolean): Integer>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
{$IFDEF TArray_Remove3}
var
  a, b, l, i, r, m: Integer;
  d, s: Boolean;
begin
  l := Length(arr);
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
      d := (arr[i] = items[a]);
      if d then
      begin
        s := not all;
        Break;
      end;
    end;
    if not d then
    begin
      arr[(r + m)] := arr[i];
      Inc(r);
    end else
      d := not s;
  end;
  SetLength(arr, (r + m));
  Result := (l - Length(arr));
end;
{$ENDIF}

{==============================================================================]
 <TArray_Remove(arr: TArray; items: TArray; all: Boolean): Integer>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed.
[==============================================================================}
{$IFDEF TArray_Remove4}
begin
  Result := TArray_Remove(arr, items, 0, all);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Reverse(arr: TArray): Boolean>
 @action: Reverses items in array.
 @note: Returns true with success (array contains 2 or more items)
[==============================================================================}
{$IFDEF TArray_Reverse}
var
  i, l: Integer;
begin
  l := Length(arr);
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Swap(arr[i], arr[((l - i) - 1)]);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Reversed(arr: TArray): TArray>
 @action: Returns reversed version of array arr.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Reversed}
var
  i, l: Integer;
begin
  l := Length(arr);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := arr[((l - i) - 1)];
end;
{$ENDIF}

{==============================================================================]
 <TArray_Scan(arr: TArray; item: VarType; IDs: TRange; limit: Integer): TIntegerArray>
 @action: Scans array for item by IDs. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Scan1}
var
  i, r: Integer;
begin
  r := 0;
  if (High(arr) > -1) then
  begin
    SetLength(Result, TRange_Size(IDs));
    case TRange_Ascending(IDs) of
      True:
      for i := IDs.start to IDs.stop do
	    if (r >= limit) then
		  Break
		else
          if (arr[i] = item) then
            Result[Integer_Inc(r)] := i;
      False:
      for i := IDs.start downto IDs.stop do
	    if (r >= limit) then
		  Break
		else
          if (arr[i] = item) then
		    Result[Integer_Inc(r)] := i;
    end;
  end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Scan(arr: TArray; item: VarType; IDs: TIntegerArray): TIntegerArray>
 @action: Scans array for item by IDs. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Scan2}
var
  i, r: Integer;
begin
  r := 0;
  if (High(arr) > -1) then
  begin
    SetLength(Result, Length(IDs));
    for i := 0 to High(IDs) do
	  if (r >= limit) then
	    Break
	  else
        if (arr[IDs[i]] = item) then
	      Result[Integer_Inc(r)] := IDs[i];
  end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Scan(arr: TArray; items: TArray; IDs: TRange; limit: Integer): TIntegerArray>
 @action: Scans array for items by IDs. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Scan3}
var
  i, r: Integer;
begin
  r := 0;
  if ((High(arr) > -1) and (High(items) > -1)) then
  begin
    SetLength(Result, TRange_Size(IDs));
    case TRange_Ascending(IDs) of
      True:
      for i := IDs.start to IDs.stop do
	    if (r >= limit) then
		  Break
		else
          if TArray_Contains(items, arr[i]) then
            Result[Integer_Inc(r)] := i;
      False:
      for i := IDs.start downto IDs.stop do
	    if (r >= limit) then
		  Break
		else
          if TArray_Contains(items, arr[i]) then
		    Result[Integer_Inc(r)] := i;
    end;
  end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Scan(arr: TArray; item: VarType; IDs: TIntegerArray): TIntegerArray>
 @action: Scans array for items by IDs. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Scan4}
var
  i, r: Integer;
begin
  r := 0;
  if ((High(arr) > -1) and (High(items) > -1)) then
  begin
    SetLength(Result, Length(IDs));
    for i := 0 to High(IDs) do
	  if (r >= limit) then
	    Break
	  else
        if TArray_Contains(items, arr[IDs[i]]) then
	      Result[Integer_Inc(r)] := IDs[i];
  end;
  SetLength(Result, r);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Set(arr: TArray; IDs: TIntegerArray; item: VarType): TArray>
 @action: Returns array arr filled with item to indexes (IDs).
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Set1}
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := item;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Set(arr: TArray; IDs: TIntegerArray; items: TArray): TArray>
 @action: Returns array arr filled with items to indexes (IDs).
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Set2}
var
  i, l: Integer;
begin
  SetLength(Result, Length(arr));
  l := Length(items);
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(IDs) do
    Result[IDs[i]] := items[(i mod l)];
end;
{$ENDIF}

{==============================================================================]
 <TArray_Set(arr: TArray; index: Integer; items: TArray): TArray>
 @action: Returns array arr filled with items to starting from custom start index.
 @note: Unsafe method! No safety checking.
[==============================================================================}
{$IFDEF TArray_Set3}
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := arr[i];
  for i := 0 to High(items) do
    Result[(index + i)] := items[i];
end;
{$ENDIF}

{==============================================================================]
 <TArray_Shift(arr: TArray): VarType>
 @action: Shortens the array with first element.
 @note: Returns the removed arr[0].
[==============================================================================}
{$IFDEF TArray_Shift1}
var
  i, l: Integer;
begin
  l := (Length(arr) - 1);
  if (l < 0) then
    Exit;
  Result := arr[0];
  for i := 0 to (l - 1) do
    arr[i] := arr[(i + 1)];
  SetLength(arr, l);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Shift(arr: TArray; shift: Integer): TArray>
 @action: Shortens the array with first SHIFT element(s).
 @note: Returns the removed arr[x]s.
[==============================================================================}
{$IFDEF TArray_Shift2}
var
  i, l, s: Integer;
begin
  l := Length(arr);
  s := Max(0, Min(shift, l));
  SetLength(Result, s);
  if (l = 0) then
    Exit;
  for i := 0 to (s - 1) do
    Result[i] := arr[i];
  for i := s to High(arr) do
    arr[(i - s)] := arr[i];
  SetLength(arr, (Length(arr) - s));
end;
{$ENDIF}

{==============================================================================]
 <TArray_Size(arr: TArray; size: Integer): Integer>
 @action: Set's arr length to size.
 @note: size > Length(arr) => Result will give how many elements were added
        size < Length(arr) => Result will give how many elements got deleted (it will be negative value!)
		size = Length(arr) => Returns 0.
[==============================================================================}
{$IFDEF TArray_Size1}
var
  l: Integer;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Size(arr: TArray; size: Integer; null: VarType): Integer>
 @action: Set's arr length to size.
 @note: Uses null for created indexes.
[==============================================================================}
{$IFDEF TArray_Size2}
var
  i, l: Integer;
begin
  l := Length(arr);
  SetLength(arr, size);
  Result := (Length(arr) - l);
  for i := 0 to (Result - 1) do
    arr[(l + i)] := null;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Size(arr: TArray): Integer>
 @action: Returns array length.
 @note: Just normal Length() for this last one, with single parameter.		
[==============================================================================}
{$IFDEF TArray_Size3}
begin
  Result := Length(arr);
end; 
{$ENDIF}

{==============================================================================]
 <TArray_SizeBetween(arr: TArray; x, y: Integer): Boolean>
 @action: Returns true if size is at equal/greater than x and equal/lesser than y.
 @note: 	
[==============================================================================}
{$IFDEF TArray_SizeBetween}
begin
  Result := ((Length(arr) >= x) and (Length(arr) <= y));
end;      
{$ENDIF}

{==============================================================================]
 <TArray_SizeMax(arr: TArray; y: Integer): Boolean>
 @action: Returns true if size is at equal/lesser than y.
 @note: 	
[==============================================================================}
{$IFDEF TArray_SizeMax}
begin
  Result := (Length(arr) <= y);
end;    
{$ENDIF}

{==============================================================================]
 <TArray_SizeMin(arr: TArray; x: Integer): Boolean>
 @action: Returns true if size is at equal/greater than x.
 @note: 	
[==============================================================================}
{$IFDEF TArray_SizeMin}
begin
  Result := (Length(arr) >= x);
end;   
{$ENDIF}

{==============================================================================]
 <TArray_Swap(a, b: TArray): Integer> 
 @action: Swaps array a and array b.
 @note: a will be b and b will be a.
[==============================================================================}
{$IFDEF TArray_Swap}
begin
  Result := (Length(a) + Length(b));
  if (Result = 0) then
    Exit;
  c := TArray_Dupe(a);
  a := TArray_Dupe(b);
  b := TArray_Dupe(c);
  SetLength(c, 0);
end; 
{$ENDIF}

{==============================================================================]
 <TArray_Trade(a, b: TArray): Integer> 
 @action: Swaps array a and array b.
 @note: a will be b and b will be a.
[==============================================================================}
{$IFDEF TArray_Trade}
var
  x, y: Integer;
begin
  x := Length(a);
  y := Length(b);
  Result := (x + y);
  if (Result > 0) then
  begin
    c := Copy(a, 0, x);
    a := Copy(b, 0, y);
    b := Copy(c, 0, x);
    SetLength(c, 0);
  end;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Undersize(arr: TArray; limit: Integer): Boolean>
 @action: Returns true if size of arr is UNDER the limit.
 @note: None.	
[==============================================================================} 
{$IFDEF TArray_Undersize}
begin
  Result := (Length(arr) < limit);
end;
{$ENDIF}

{==============================================================================]
 <TArray_Unique(arr: TArray): Integer>
 @action: Removes all duplicates from arr.
 @note: Returns the number of items that were removed.
[==============================================================================}
{$IFDEF TArray_Unique}
var
  a, l, i, j: Integer;
  m: Boolean;
begin
  l := Length(arr);
  if (l < 2) then
    Exit(0);
  a := 0;
  for i := 1 to (l - 1) do
  begin
    for j := 0 to a do
    begin
      m := (arr[i] = arr[j]);
      if m then
        Break;
    end;
    if m then
      Continue;
    a := (a + 1);
    arr[a] := arr[i];
  end;
  Result := (l - (a + 1));
  if (Result > 0) then
    SetLength(arr, (a + 1));
end;
{$ENDIF}

{==============================================================================]
 <TArray_Uniqued(arr: TArray): TArray>
 @action: Removes all duplicates from arr.
 @note: Returns the unique version of arr.
[==============================================================================}
{$IFDEF TArray_Uniqued}
var
  i, j, l, c: Integer;
begin
  l := Length(arr);
  SetLength(Result, l);
  if (l > 0) then
  begin
    c := 0;
    for i := 0 to (l - 1) do
    begin
      j := 0;
      repeat
        if (arr[i] <> Result[j]) then
          j := (j + 1)
        else
          j := 0;
      until ((j = 0) or (j > c));
      if (j > 0) then
      begin
        Result[c] := arr[i];
        Inc(c);
      end;
    end;
    SetLength(Result, c);
  end;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Uniques(arr: TArray): TIntegerArray>
 @action: Returns the indexes of unique array (arr) items.
 @note: None.
[==============================================================================}
{$IFDEF TArray_Uniques}
var
  h, r, x, y: Integer;
  m: Boolean;
begin
  h := High(arr);
  SetLength(Result, (h + 1));
  if (h > 0) then
  begin
    r := 0;
    for x := 0 to h do
    begin
      for y := 0 to h do
      begin
        m := ((y <> x) and (arr[x] = arr[y]));
        if m then
          Break;
      end;
      if not m then
      begin
        Result[r] := x;
        Inc(r);
      end;
    end;
    SetLength(Result, r);
  end;
  if (h = 0) then
    Result[0] := 0;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Unshift(arr: TArray; item: VarType): Integer>
 @action: Grows arr with item. Returns the index of added item.
 @note: Adds item to the left side of the array. (Opposite to TArray_Append!
[==============================================================================}
{$IFDEF TArray_Unshift1}
var
  i: Integer;
begin
  Result := Length(arr);
  SetLength(arr, (Result + 1));
  for i := Result downto 1 do
    arr[i] := arr[(i - 1)];
  arr[0] := item;
end;
{$ENDIF}

{==============================================================================]
 <TArray_Unshift(arr: TArray; items: TArray): Integer>
 @action: Grows arr with items. Returns the index of last added item.
 @note: Adds item to the left side of the array. (Opposite to TArray_Append!
[==============================================================================}
{$IFDEF TArray_Unshift2}
var
  h, l, i: Integer;
begin
  h := High(items);
  if (h = -1) then
    Exit(High(arr));
  l := Length(arr);
  Result := (l + h);
  SetLength(arr, (Result + 1));
  for i := Result downto (h + 1) do
    arr[i] := arr[(i - (h + 1))];
  for i := 0 to h do
    arr[i] := items[i];
end;
{$ENDIF}