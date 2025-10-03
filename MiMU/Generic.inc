{$I config\Defines.inc}

{==============================================================================]
 <var.TArray(aSize: Integer): TArray>
 @action: Creates TArray with Self.
 @note: aSize will be Length of the created array.
[==============================================================================}
function HVar.TArray(const aSize: Integer = 1): TArr; overload cdecl;
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
function HVar.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DArr; overload cdecl;
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
function HArr.Add(const item: TVar; const duplicates: Boolean = True): TArr; overload; cdecl;
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
function HArr.Add(const items: TArr; const duplicates: Boolean = True): TArr; overload; cdecl;
var
  a, h, i, s: Integer;
begin
  s := Length(Self);
  i := Length(items);
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
 <arr.AllEqual: Boolean>
 @action: Returns true if all values in arr are equal (arr contains only equal values).
 @note: Returns FALSE with empty array!
[==============================================================================}
function HArr.AllEqual: Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[0] <> Self[i]) then
      Exit(False);
  Result := (Length(Self) > 0);
end;

{==============================================================================]
 <arr.AllSame: Boolean>
 @action: Returns true if all values in arr are the same (arr contains only equal values).
 @note: Returns FALSE with empty array!
[==============================================================================}
function HArr.AllSame: Boolean; overload; cdecl;
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
function HArr.AllUnique: Boolean; overload; cdecl;
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
  <arr.Any>
  @action: Returns random array item from Self.
  @note: Returns null with empty arrays.
[==============================================================================}
function HArr.Any(const null: TVar): TVar; overload; cdecl;
begin
  if Self.Empty then
    Exit(null);
  Result := Self[Random(Self.Size)];
end;

{==============================================================================]
  <arr.Any>
  @action: Returns random array item from Self.
  @note: Make sure array has at least 1 item! This one is unsafe and returns error else.
[==============================================================================}
function HArr.Any: TVar; overload; cdecl;
begin
  Result := Self[Low(Self) + Random(Self.Size)];
end;

{==============================================================================]
 <arr.Append(item: VarType; duplicates: Boolean): TArray>
 @action: Appends arr with item. Returns the index of added item.
 @note: Adds item to the right side of the array.
[==============================================================================}
function HArr.Append(const item: TVar; const duplicates: Boolean = True): TArr; overload; cdecl;
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
function HArr.Append(const items: TArr; const duplicates: Boolean = True): TArr; overload; cdecl;
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
 <arr.As2D(rows, columns: Integer): T2DArray>
 @action: Converts 1D array to 2D by rows and columns.
 @note: TIA := [1,2,3,4,5,6];
		TIA.To2D(2, 3) = [[1, 2, 3], [4, 5, 6]]
        TIA.To2D(3, 2) = [[1, 2], [3, 4], [5, 6]]
[==============================================================================}
function HArr.As2D(const rows, columns: Integer): T2DArr; overload;
var
  l, i: Integer;
begin
  l := Length(Self);
  SetLength(Result, rows, columns);
  for i := 0 to ((rows * columns) - 1) do
    if (i < l) then
      Result[i div columns][i mod columns] := Self[i];
end;

{==============================================================================]
 <arr.As2D(width: Integer): T2DArray>
 @action: Converts 1D array to 2D by width.
 @note: None.
[==============================================================================}
function HArr.As2D(const width: Integer): T2DArr; overload;
var
  l, h, i, r, c: Integer;
begin
  l := Length(Self);
  h := Ceil(l / width);
  SetLength(Result, h, width);
  i := 0;
  for r := 0 to (h - 1) do
    for c := 0 to (width - 1) do
      if (i < l) then
        Result[r][c] := Self[i.Increase];
end;

{==============================================================================]
 <arr.Backwards: TArray>
 @action: Returns arr as reversed.
 @note: Alternative for Reversed methods
[==============================================================================}
function HArr.Backwards: TArr; overload; cdecl;
var
  l, i: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  i := 0;
  while (l > 0) do
    Result[i.Increase] := Self[l.Decrement];
end;

{==============================================================================]
 <arr.Blit(items: TArray; index: Integer: Integer>
 @action: Simply puts items to array index, fast.
 @note: No safety checks. Make sure buffer is enough!
[==============================================================================}
function HArr.Blit(const items: TArr; const index: Integer = 0): Integer; overload; cdecl;
var
  i: Integer;
begin
  Result := (index + Length(items));
  for i := 0 to High(items) do
    Self[index + i] := items[i]; 
end;

{==============================================================================]
 <arr.Build(item: VarType; aSize: Integer): TArray> 
 @action: Creates array with item where aSize is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}
function HArr.Build(const item: TVar; const aSize: Integer = 1): TArr; overload; cdecl;
begin
  Result := Self.Create(aSize, item);
end;

{==============================================================================]
 <arr.MadeOf(allowed: TArray): Boolean> 
 @action: Checks if array arr contains only allowed items.
 @note: None.
[==============================================================================}
function HArr.MadeOf(const allowed: TArr): Boolean; overload; cdecl;
var
  a, s: TRange;
  i: Integer;
begin
  if (Self.Empty or allowed.Empty) then
    Exit(False);
  s.Create(0, High(Self));
  a.Create(0, High(allowed));
  repeat
    i := a.start;
    repeat
      Result := (Self[s.stop] = allowed[i]);
    until (Result or (i.Increment > a.stop));
  until ((not Result) or (s.stop.Decrement < s.start));
end;

{==============================================================================]
 <arr.FreeOf(forbidden: TArray): Boolean> 
 @action: Checks if array arr does not have any forbidden items.
 @note: None.
[==============================================================================}
function HArr.FreeOf(const forbidden: TArr): Boolean; overload; cdecl;
var
  s, f: TRange;
  i: Integer;
begin
  if (Self.Empty or forbidden.Empty) then
    Exit(True);
  s.Create(0, High(Self));
  f.Create(0, High(forbidden));	
  repeat
    i := f.start;
    repeat
      Result := not (Self[s.stop] = forbidden[i]);
    until ((i.Increment > f.stop) or (not Result));
  until ((not Result) or (s.stop.Decrement < s.start));
end;

{==============================================================================]
 <arr.Blend(items: TArray; index: Integer): TArray> 
 @action: Blends items with array, cleverly.
 @note: None.
[==============================================================================}
function Harr.Blend(const items: TArr; const index: Integer = 2147483647): TArr; overload; cdecl;
var
  s, l, p, r, i: Integer;
begin
  s := Length(Self);
  if (s = 0) then
    Exit(items.Copy);
  l := Length(items);
  if (l = 0) then
    Exit(Self.Copy);
  case (index > 0) of
    True:
    begin
      p := index;
      if (p > s) then
        p := s;
      r := (p + l);
      SetLength(Result, r);
      for i := 0 to (p - 1) do
        Result[i] := Self[i];
      for i := 0 to (l - 1) do
        Result[p + i] := items[i];
    end;
	False:
    begin
      p := ((s + index) - 1);
      if (p < 0) then
        p := 0;
      r := (l + (s - p));
      SetLength(Result, r);
      for i := 0 to (l - 1) do
        Result[i] := items[i];
      for i := p to (s - 1) do
        Result[l + (i - p)] := Self[i];
    end;
  end;
end;

{==============================================================================]
 <arr.BuiltWithout(forbidden: TArray): Boolean> 
 @action: Checks if array arr does not have any forbidden items.
 @note: None.
[==============================================================================}
function HArr.BuiltWithout(const forbidden: TArr): Boolean; overload; cdecl;
var
  i, j: Integer;
begin
  if not (Self.Empty or forbidden.Empty) then
  for i := 0 to High(Self) do
    for j := 0 to High(forbidden) do
      if (Self[i] = forbidden[j]) then
        Exit(False);
  Result := True;
end;

{==============================================================================]
  <arr.BuiltWith(blocks TArray): Boolean>
  @action: Returns true is arr is built with blocks.
  @note: This function requires blocks array to be unique (no duplicates allowed for it).
[==============================================================================}
function HArr.BuiltWith(const blocks: TArr): Boolean; cdecl;
var
  i, p: Integer;
  u: TBooleanArray;
begin
  if (Self.Empty or blocks.Empty) then
    Exit(False);
  SetLength(u, Length(blocks));
  for i := 0 to High(Self) do
  begin
    p := blocks.Pos(Self[i]);
    if (p = -1) then
      Exit(False);
    u[p] := True;
  end;
  for i := 0 to High(blocks) do
    if not u[i] then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <TArray.Classes: T2DArray>
  @action: Groups consecutive identical array items into sub-arrays (classes).
  @note: Works on any array. Each run of identical values becomes a class; 
         duplicate classes can exist if values repeat non-consecutively.
[==============================================================================}
function HArr.Classes: T2DArr; overload; cdecl;
var
  i, g: Integer;
  v: TVar;
begin
  if Self.Empty then
    Exit([]);
  g := 0;
  v := Self[0];
  SetLength(Result, 1);
  SetLength(Result[0], 0);
  for i := 0 to High(Self) do
  begin
    if not (Self[i] = v) then
    begin
      v := Self[i];
      SetLength(Result, (g.Increment + 1));
      SetLength(Result[g], 0);
    end;
    SetLength(Result[g], (Length(Result[g]) + 1));
    Result[g][High(Result[g])] := Self[i];
  end;
end;

{==============================================================================]
  <TArray.Classes: T2DArray>
  @action: Groups consecutive identical array items into sub-arrays (classes).
  @note: Works on any array. Each run of identical values becomes a class; 
         duplicate classes can exist if values repeat non-consecutively.
		 Custom weight.
[==============================================================================}
function HArr.Classes(const weight: TIntegerArray): T2DArr; overload; cdecl; var w: Integer; {$DEFINE Skeleton_Classes}{$I config\Skeletons.inc}{$UNDEF Skeleton_Classes}
function HArr.Classes(const weight: TDoubleArray): T2DArr; overload; cdecl; var w: Double; {$DEFINE Skeleton_Classes}{$I config\Skeletons.inc}{$UNDEF Skeleton_Classes}


{==============================================================================]
  <TArray.Classify: T2DArray>
  @action: Groups consecutive identical array items into sub-arrays (classes).
  @note: Works on any array. Each run of identical values becomes a class; 
         duplicate classes can exist if values repeat non-consecutively.
[==============================================================================}
function HArr.Classify: T2DArr; overload; cdecl;
var
  i, h, g, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  SetLength(Result[0], l);
  Result[0][0] := Self[0];
  g := 0;
  h := 0;
  for i := 1 to High(Self) do
  case (Self[i] = Result[g][0]) of
    False:
    begin
      SetLength(Result[g], (h + 1));
      Result[g][h] := Result[g][0];
      h := 0;
      SetLength(Result[g.Increment], (l - i));
      Result[g][0] := Self[i];
    end;
	True: Result[g][h.Increase] := Self[i];
  end;
  SetLength(Result[g], (h + 1));
  SetLength(Result, (g + 1));
end;

{==============================================================================]
  <TArray.Classify: T2DArray>
  @action: Groups consecutive identical array items into sub-arrays (classes).
  @note: Works on any array. Each run of identical values becomes a class; 
         duplicate classes can exist if values repeat non-consecutively.
		 Custom weight.
[==============================================================================}
function HArr.Classify(const weight: TIntegerArray): T2DArr; overload; cdecl; var w: Integer; {$DEFINE Skeleton_Classify}{$I config\Skeletons.inc}{$UNDEF Skeleton_Classify}
function HArr.Classify(const weight: TDoubleArray): T2DArr; overload; cdecl; var w: Double; {$DEFINE Skeleton_Classify}{$I config\Skeletons.inc}{$UNDEF Skeleton_Classify}

{==============================================================================]
  <arr.Clear: Boolean>
  @action: SetLength(arr, 0) and returns true if items existed before doing it.
  @note: None.
[==============================================================================}
function HArr.Clear: Boolean; overload; cdecl;
begin
  Result := (Length(Self) > 0);
  SetLength(Self, 0);
end;

{==============================================================================]
 <arr.Clone(index: Integer; count: Integer): TArray>
 @action: Returns copy of an array arr.
 @note: Contains support for starting index and count. -1 count uses Length(arr)!
[==============================================================================}
function HArr.Clone(const index: Integer = 0; const count: Integer = 2147483647): TArr; overload; cdecl;
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
function HArr.Clone(const ID: TIntegerArray): TArr; overload; cdecl;
var
  i, h, l, r: Integer;
begin
  r := 0;
  if (ID.Populated and Self.Populated) then
  begin
    h := High(Self);
    l := Length(ID);
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      if ((ID[i] <= h) and (ID[i] > -1)) then
        Result[r.Increase] := Self[ID[i]];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Compact: Integer>
 @action: Removes adjacent duplicates.
 @note: Original order is preserved and non-adjacent duplicates remain.
[==============================================================================}
function HArr.Compact: Integer; overload; cdecl;
var
  i: Integer;
begin
  if (Length(Self) < 2) then
    Exit(Length(Self));
  Result := 1;
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;

{==============================================================================]
 <arr.Compacted: TArray>
 @action: Removes adjacent duplicates and returns a new compacted array.
 @note: Original order is preserved and non-adjacent duplicates remain.
[==============================================================================}
function HArr.Compacted: TArr; overload; cdecl;
var
  i: Integer;
begin
  if (Length(Self) = 0) then
    Exit([]);
  SetLength(Result, 1);
  Result[0] := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
	  Result.Supply(Self[i]);
end;

{==============================================================================]
 <arr.Compacted: TArray>
 @action: Removes adjacent duplicates and returns a new compacted array.
 @note: Custom threshold possibility.
[==============================================================================}
function HArr.Compacted(const threshold: Integer): TArr; overload; cdecl;
var
  i, j: Integer;
  k: Boolean;
  r: Integer;
begin
  if (Self.Empty or (threshold < 1)) then
    Exit(Self.Copy);
  r := 0;
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    k := True;
    for j := Max(0, (r - threshold)) to (r - 1) do
      if (Result[j] = Self[i]) then
      begin
        k := False;
        Break;
      end;
    if k then
    begin
      if (Length(Result) <= r) then
        SetLength(Result, (r + 1));
      Result[r.Increase] := Self[i];
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Combine(b: TArray): TArray>
 @action: Combines arrays arr and b together as single array.
 @note: This is an alternative method. :)
[==============================================================================}
function HArr.Combine(const b: TArr): TArr; overload; cdecl;
begin
  SetLength(Result, 0);
  Insert(Self, Result, 0);
  Insert(b, Result, Length(Self));
end;

{==============================================================================]
 <arr.Compressed: TArray>
 @action: Produces a new array by removing all immediately repeated values,
          effectively run-length–compressing the input.
 @note: Only consecutive duplicates are removed; values separated by others
        are left untouched. The relative order of the remaining elements
        is unchanged.
[==============================================================================}
function HArr.Compressed: TArr; overload; cdecl;
var
  r, i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  Result[0] := Self[0];
  if (l > 1) then
  begin
    r := 0;
    for i := 1 to (l - 1) do
      if not (Self[i] = Result[r]) then
        Result[r.Increment] := Self[i];
    SetLength(Result, (r + 1));
  end;
end;

{==============================================================================]
 <arr.Compressed: TArray>
 @action: Produces a new array by removing all immediately repeated values,
          effectively run-length–compressing the input.
 @note: Custom threshold possibility.
[==============================================================================}
function HArr.Compressed(const threshold: Integer): TArr; overload; cdecl;
var
  w, r, i: Integer;
  d: Boolean;
begin
  Result := Self.Copy;
  if (Self.Empty or (threshold < 1)) then
    Exit;
  w := 0;
  for r := 0 to High(Result) do
  begin
    d := False;
    for i := Max(0, (w - threshold)) to (w - 1) do
      if (Result[i] = Result[r]) then
      begin
        d := True;
        Break;
      end;
    if not d then
      Result[w.Increase] := Result[r];
  end;
  SetLength(Result, w);
end;

{==============================================================================]
 <arr.Compress: Integer>
 @action: Removes all immediately repeated values,
          effectively run-length–compressing the input.
 @note: Only consecutive duplicates are removed; values separated by others
        are left untouched. The relative order of the remaining elements
        is unchanged.
[==============================================================================}
function HArr.Compress: Integer; overload; cdecl;
var
  i: Integer;
begin
  if (Length(Self) < 2) then
    Exit(Length(Self));
  Result := 1;
  for i := 1 to High(Self) do
    if not (Self[i] = Self[Result - 1]) then
      Self[Result.Increase] := Self[i];
  SetLength(Self, Result);
end;

{==============================================================================]
 <arr.Comprised(items: TArray): Boolean>
 @action: Returns true if arr is built of items only.
 @note: 
[==============================================================================}
function HArr.Comprised(const items: TArr): Boolean; overload; cdecl;
var
  l: Integer;
begin
  l := Length(Self);
  Result := (l > 0);
  while (Result and (l.Decrease > 0)) do
    Result := items.Contains(Self[l]);
end;

{==============================================================================]
 <arr.Constant(item: VarType): Boolean>
 @action: Returns true if arr consists of item ONLY.
 @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function HArr.Constant(const item: TVar): Boolean; overload; cdecl;
var
  l: Integer;
begin
  l := Length(Self);
  Result := (l > 0);
  while (Result and (l.Decrease > 0)) do
    Result := (Self[l] = item);
end;

{==============================================================================]
 <arr.Constant: Boolean>
 @action: Returns true if arr consists of ONLY same items.
 @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function HArr.Constant: Boolean; overload; cdecl;
begin
  Result := ((Length(Self) > 0) and Constant(Self[0]));
end;

{==============================================================================]
 <arr.Contains(item: VarType; index: Integer): Boolean>
 @action: Looks array for item starting from start index. If found, Result will be True.
 @note: None.
[==============================================================================}
function HArr.Contains(const item: TVar; const index: Integer = 0): Boolean; cdecl;
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
function HArr.Copy(const index: Integer = 0; const count: Integer = 2147483647): TArr; overload; cdecl;
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
function HArr.Create(const item: TVar): TArr; overload; cdecl;
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
function HArr.Create(const aSize: Integer; const item: TVar): TArr; overload; cdecl;
var
  i: Integer;
begin
  Result := Self.Clone;
  SetLength(Self, Max(0, aSize));
  for i := 0 to High(Self) do
    Self[i] := item;
end;

{==============================================================================]
 <arr.Deduplicated: TArray>
 @action: Removes adjacent duplicates and returns a new compacted array.
 @note: Original order is preserved and non-adjacent duplicates remain.
[==============================================================================}
function HArr.Deduplicated: TArr; overload; cdecl;
var
  i, l: Integer;
begin
  SetLength(Result, Length(Self));
  if Self.Empty then
    Exit();
  l := 0;
  for i := 0 to High(Self) do
    if ((i = 0) or (Self[i] <> Self[i - 1])) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
 <arr.Delete(index: Integer): TArray>
 @action: Deletes array item from arr by index.
 @note: Returns true with success (index existed in arr).
[==============================================================================}
function HArr.Delete(const index: Integer = 0): TArr; overload; cdecl;
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
function HArr.Delete(const ID: TIntegerArray): TArr; overload; cdecl;
var
  i, l, r: Integer;
begin
  if ID.Empty then
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
function HArr.Differ(const target: TArr): Boolean; overload; cdecl;
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
 <arr.Distinct>
 @action: Returns the number of unique elements in array 
 @note: None.
 [==============================================================================}
function HArr.Distinct: Integer; overload; cdecl;
var
  i, j: Integer;
  u: Boolean;
begin
  Result := 0;
  if Self.Empty then
    Exit;
  for i := 0 to High(Self) do
  begin
    u := True;
    for j := 0 to (i - 1) do
      if (Self[i] = Self[j]) then
      begin
        u := False;
        Break;
      end;
    if u then
      Inc(Result);
  end;
end;

{==============================================================================]
 <arr.Disordered>
 @action: Returns array with randomized order (disorder)
 @note: [1,2,3] => [1,3,2] | [2,1,3] | [2,3,1] | [3,2,1] ...
 [==============================================================================}
function HArr.Disordered: TArr; overload; cdecl;
var
  m: TBooleanArray;
  i, r, l: Integer;
begin
  l := Length(Self);
  if (l < 2) then
    Exit(Self.Copy);
  SetLength(Result, l);
  m.Create(l, False);
  for i := 0 to (l - 1) do
  begin
    repeat
      r := Random(l);
    until (not m[r]);
    Result[i] := Self[r];
    m[r] := True;
  end;
end;

{==============================================================================]
 <arr.Distribute(parts: Integer): T2DArray>
 @action: Distributes array arr to 2D array by number of parts.
 @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5][6,7]
 [==============================================================================}
function HArr.Distribute(const parts: Integer): T2DArr; overload; cdecl;
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
 <arr.Diversified: TArray>
 @action: Alternative for Unique methods
 @note: None.
 [==============================================================================}
function HArr.Diversified: TArr; overload; cdecl;
var
  d: specialize TDictionary<TVar, Boolean>;
  i: Integer;
  k: TVar;
begin
  d := specialize TDictionary<TVar, Boolean>.Create;
  try
    for i := 0 to High(Self) do
      if not d.ContainsKey(Self[i]) then
        d.Add(Self[i], True);
    SetLength(Result, d.Count);
    i := 0;
    for k in d.Keys do
      Result[i.Increase] := k;
  finally
    d.Free;
  end;
end;

{==============================================================================]
 <arr.DiversifiedEx: TArray>
 @action: Alternative for Unique methods
 @note: None.
 [==============================================================================}
function HArr.DiversifiedEx(const dAscending: Boolean = True): TArr; overload; cdecl;
var
  l: specialize TList<TVar>;
  d: specialize TDictionary<TVar, Boolean>;
  i: Integer;
begin
  l := specialize TList<TVar>.Create;
  d := specialize TDictionary<TVar, Boolean>.Create;
  try
    case dAscending of
      True:
      for i := 0 to High(Self) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
          l.Add(Self[i]);
        end;
      False:
      for i := High(Self) downto 0 do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
          l.Add(Self[i]);
        end;
    end;
    Result := l.ToArray;
  finally
    d.Free;
    l.Free;
  end;
end;

{==============================================================================]
 <arr.Domain: TRange>
  @action: Returns the valid index range of the array.
  @note: 
    - If the array is empty, start and stop are set to -1.
    - Otherwise, start = 0 and stop = Length(Self) - 1.
[==============================================================================}
function HArr.Domain: TRange; overload; cdecl;
begin
  Result.stop := (Length(Self) - 1);
  if (Result.stop = -1) then
    Result.start := -1
  else
    Result.start := 0;
end;

{==============================================================================]
 <arr.Drop(item: VarType; eraseDuplicates: Boolean): TArray>
 @action: Removes item(s) from arr and returns it.
 @note: 	
[==============================================================================}
function HArr.Drop(const item: TVar; const eraseDuplicates: Boolean = True): TArr; overload; cdecl;
var
  p: TIntegerArray;
  r: TRange;
begin
  if Self.Empty then
    Exit([]);
  if eraseDuplicates then
    p := Self.Positions(item)
  else
    p := [Self.Pos(item)];
  r.Create(0, High(Self));
  Result := Self.Get(p.Inverted(r));
end;

{==============================================================================]
 <TArray_Dump(items: TArray; index: Integer): TArray>
 @action: Deletes items from array, keeps others. Returns array length (after action).
 @note: Supports custom start index!
[==============================================================================}
function HArr.Dump(const items: TArr; const index: Integer = 0): TArr; overload; cdecl;
var
  i, l, m, d: Integer;
begin
  if (items.Empty or Self.Empty) then
    Exit(Self.Copy);
  l := Length(Self);
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
function HArr.Dupe: TArr; overload; cdecl;
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
function HArr.Duplicate(const xTimes: Integer = 1): TArr; overload; cdecl;
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
 <arr.Elements(returnIDs: Integer): TArray>
 @action: Returns copy of an array arr.
 @note: None.
[==============================================================================}
function HArr.Elements(const returnIDs: TIntegerArray; const returnSort: Boolean = True): TArr; overload; cdecl;
var
  h, i, j, l, c, s: Integer;
  r: TIntegerArray;
begin
  if (Self.Empty or returnIDs.Empty) then
    Exit([]);
  if returnSort then
    r := returnIDs.QuickSorted
  else
    r := returnIDs.Copy;
  h := High(r);
  s := High(Self);
  SetLength(Result, Length(Self));
  l := 0;
  c := 0;
  for i := 0 to s do
  case ((c > h) or (r[c] > s)) of
    False:
    for j := c to h do
      if not (r[j] = i) then
      begin
        c := (j + IfThen((r[j] < 0), 1, 0));
        Break;
      end else
        Result[l.Increase] := Self[i];
    True: Break;
  end;
  SetLength(Result, l);
end;

{==============================================================================]
 <arr.Emplace(item: VarType; index: Integer): Integer>
 @action: Inserts item to index in arr. Returns the index it was inserted to.
 @note: Alternative for Insert().
[==============================================================================}
function HArr.Emplace(const item: TVar; const index: Integer = 0): Integer; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Self, (Length(Self) + 1));
  Result := index.Clamp(0, High(Self));
  for i := High(Self) downto (Result + 1) do
    Self[i] := Self[i - 1];
  Self[Result] := item;
end;

{==============================================================================]
 <arr.Empty: Boolean>
 @action: Returns true if array is empty (Length = 0).
 @note: None.
[==============================================================================}
function HArr.Empty: Boolean; overload; cdecl;
begin
  Result := (Length(Self) = 0);
end;

{==============================================================================]
 <arr.Equal(target: TArray): Boolean>
 @action: Returns true if arr equals target (identical arrays)
 @note: None
[==============================================================================}
function HArr.Equal(const target: TArr): Boolean; overload; cdecl;
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
function HArr.Erase(const item: TVar; const index: Integer = 2147483647; const all: Boolean = True): TArr; overload; cdecl;
var
  j, i, m, l, d: Integer;
  f: Boolean;
  r: TBooleanArray;
begin
  if not (Self.Empty or (index < 0)) then
  begin
    l := Length(Self);
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
function HArr.Erase(const item: TVar; const all: Boolean): TArr; overload; cdecl;
begin
  Result := Self.Erase(item, 2147483647, all);
end;

{==============================================================================]
 <arr.Erase(items: TArray; index: Integer; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function HArr.Erase(const items: TArr; const index: Integer = 2147483647; const all: Boolean = True): TArr; overload; cdecl;
var
  h, i, j, m, l, d: Integer;
  f: Boolean;
  r: TBooleanArray;
begin 
  if (Self.Populated and items.Populated and (index >= 0)) then
  begin
    h := High(items);
    l := Length(Self);
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
function HArr.Erase(const items: TArr; const all: Boolean): TArr; overload; cdecl;
begin
  Result := Self.Erase(items, 2147483647, all);
end;

{==============================================================================]
 <arr.Exact(items: TArray): Boolean>
 @action: Returns true if arr consists of items.
 @note: arr must contain ALL the items for this function to return True.
        Any extra items will cause Result to be False also.
		items[1,2,3]
		arr[1,2,3,1,2,3] => True
		arr[2,3,2,3] => False
		arr[2,1,3,4] => False
		This function requires items array to be unique. No duplicates allowed for it!
[==============================================================================}
function HArr.Exact(const items: TArr): Boolean; overload; cdecl;
var
  i, j: Integer;
  f: TBooleanArray;
begin
  if (Length(items) = 0) then
    Exit(Length(Self) = 0);
  SetLength(f, Length(items));
  f.Create(Length(items), False);
  for i := 0 to High(Self) do
  begin
    j := items.Pos(Self[i]);
    if (j = -1) then
      Exit(False);
    f[j] := True;
  end;
  Result := f.Uniform(True);
end;

{==============================================================================]
 <arr.Excessive: Boolean>
 @action: Returns true if arr contains any duplicates in it.
 @note: None.
[==============================================================================}
function HArr.Excessive: Boolean; overload; cdecl; 
type
  TDict = specialize TDictionary<TVar, Boolean>;
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
function HArr.Exch(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
var
  c: TVar;
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
function HArr.Exchange(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
var
  c: TVar;
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
 <arr.Exchange(b: TArray): Integer> 
 @action: Swaps array arr and array b.
 @note: arr will be b and b will be arr.
[==============================================================================}
function HArr.Exchange(var b: TArr): Integer; overload; cdecl;
var
  a: TArr;
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
 <arr.Exclude(items: TArray; index: Integer): TArray>
 @action: Returns a new array with elements from items excluded, up to and including the specified index.
 @note: Elements after index are copied without filtering. If index is out of bounds, it is clamped to the array length.
         The default index filters the entire array.
[==============================================================================}
function HArr.Exclude(const items: TArr; const index: Integer = 2147483647): TArr; overload; cdecl;
var
  i, l, m, d: Integer;
begin
  if (items.Empty or Self.Empty) then
    Exit(Self.Copy);
  l := Length(Self);
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
 <arr.Exists: Boolean>
 @action: Returns true if array length is not 0.
 @note: Alternative for arr.Populated.
[==============================================================================}
function HArr.Exists: Boolean; overload; cdecl;
begin
  Result := (Length(Self) > 0);
end;

{==============================================================================]
 <arr.Extend(item: VarType): TArray>
 @action: Extends arr with item. Returns it.
 @note: Places item to the left side of the array.
[==============================================================================}
function HArr.Extend(const item: TVar): TArr; overload; cdecl;
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
function HArr.Extend(const items: TArr): TArr; overload; cdecl;
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
function HArr.Extract(const item: TVar; const index: Integer = 0): TArr; overload; cdecl;
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
function HArr.Extract(const items: TArr; const index: Integer = 0): TArr; overload; cdecl;
var
  i, l, r: Integer;
begin
  r := 0;
  if items.Populated then
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
function HArr.ExtractEvery(const X: Integer = 1; const index: Integer = 0): TArr; overload; cdecl;
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
 <arr.ExtractIDs(allowed: TIntegerArray): TArray>
 @action: Keeps (extracts) all allowed index values from array.
 @note: None.
[==============================================================================}
function HArr.ExtractIDs(const allowed: TIntegerArray): TArr; overload; cdecl;
var
  h, i, l: Integer;
  m: TBooleanArray;
begin
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  m.Create(l, False);
  for i := 0 to High(allowed) do
    if ((allowed[i] > -1) and (allowed[i] < l)) then
      m[allowed[i]] := True;
  h := 0;
  for i := 0 to (l - 1) do
    if m[i] then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
 <arr.ExtractIndexes(allowed: TIntegerArray; aSorted: Boolean): TArray>
 @action: Keeps (extracts) all allowed index values from array.
 @note: If allowed is not in ascending order, aSorted needs to be False.
[==============================================================================}
function HArr.ExtractIndexes(const allowed: TIntegerArray; const aSorted: Boolean = False): TArr; overload; cdecl;
var
  h, i, l: Integer;
  a: TIntegerArray;
begin
  l := Length(Self);
  if ((l = 0) or allowed.Empty) then
    Exit([]);
  SetLength(Result, l);
  if not aSorted then
    a := allowed.QuickSorted
  else
    a := allowed.Copy;
  h := 0;
  for i := 0 to (l - 1) do
    if a.BinaryContains(i) then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
 <arr.Feed(item: VarType; allowDuplicates: Boolean): Integer>
 @action: Feeds item to array and returns the index position it was added to.
 @note: Returns -1 if duplicates are not allowed and array already includes item.
[==============================================================================}
function HArr.Feed(const item: TVar; const allowDuplicates: Boolean = False): Integer; overload; cdecl;
begin
  if ((not allowDuplicates) and Self.Includes(item)) then
    Exit(-1);
  Result := Length(Self);
  SetLength(Self, (Result + 1));
  Self[Result] := item;
end;

{==============================================================================]
 <arr.Fill(item: VarType; index: Integer; count: Integer): TArray>
 @action: Fills whole arr with item.
 @note: Returns the filled array.
[==============================================================================}
function HArr.Fill(const item: TVar; const index: Integer = 0; const count: Integer = 2147483647): TArr; overload; cdecl;
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
function HArr.Fill(const items: TArr; const index: Integer = 0; const count: Integer = 2147483647): TArr; overload; cdecl;
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
function HArr.Filter(const item: TVar; const index: Integer = 0): TArr; overload; cdecl;
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
function HArr.Filter(const items: TArr; const index: Integer = 0): TArr; overload; cdecl;
var
  i, l, r: Integer;
begin
  l := Length(Self);
  if items.Empty then
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
function HArr.FilterEvery(const X: Integer = 1; const index: Integer = 0): TArr; overload; cdecl;
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
 <arr.FilterIDs(forbidden: TIntegerArray): TArray>
 @action: Returns the array without values from forbidden indexes.
 @note: None.
[==============================================================================}
function HArr.FilterIDs(const forbidden: TIntegerArray): TArr; overload; cdecl;
var
  h, i, l: Integer;
  m: TBooleanArray;
begin
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  m.Create(l, False);
  for i := 0 to High(forbidden) do
    if ((forbidden[i] > -1) and (forbidden[i] < l)) then
      m[forbidden[i]] := True;
  h := 0;
  for i := 0 to (l - 1) do
    if not m[i] then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
 <arr.FilterIndexes(forbidden: TIntegerArray; fSorted: Boolean): TArray>
 @action: Returns the array without values from forbidden indexes.
 @note: If forbidden is not in ascending order, fSorted needs to be False.
[==============================================================================}
function HArr.FilterIndexes(const forbidden: TIntegerArray; const fSorted: Boolean = False): TArr; overload; cdecl;
var
  h, i, l: Integer;
  f: TIntegerArray;
begin
  if forbidden.Empty then
    Exit(Self.Copy);
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  if not fSorted then
    f := forbidden.QuickSorted
  else
    f := forbidden.Copy;
  h := 0;
  for i := 0 to (l - 1) do
    if not f.BinaryContains(i) then
      Result[h.Increase] := Self[i];
  SetLength(Result, h);
end;

{==============================================================================]
 <arr.Find(item: VarType; ID: TRange): Integer>
 @action: Scans array for item by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Find(const ID: TRange; const item: TVar): Integer; overload; cdecl;
begin
  if Self.Populated then
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
function HArr.Find(const ID: TIntegerArray; const item: TVar): Integer; overload; cdecl;
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
 <arr.Find(items: TArray; ID: TRange): Integer>
 @action: Scans array for items by IDs. Returns position if found.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Find(const ID: TRange; const items: TArr): Integer; overload; cdecl;
begin
  if (Self.Populated and items.Populated) then
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
function HArr.Find(const ID: TIntegerArray; const items: TArr): Integer; overload; cdecl;
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
 <arr.First: Integer>
 @action: Returns the first index of arr.
 @note: With empty array result will be -1!
[==============================================================================}
function HArr.First: Integer; overload; cdecl;
begin
  Result := IfThen(Self.Empty, -1, 0);
end;

{==============================================================================]
 <arr.First(item: VarType): Integer>
 @action: Returns the first index that matches item in arr.
 @note: Unmatch will be -1!
[==============================================================================}
function HArr.First(const item: TVar): Integer; overload; cdecl;
begin
  for Result := 0 to High(Self) do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.First(items: TArray): Integer>
 @action: Returns the first arr index that matches any of the items.
 @note: Unmatch will be -1!
[==============================================================================}
function HArr.First(const items: TArr): Integer; overload; cdecl;
begin
  for Result := 0 to High(Self) do
    if items.Contains(Self[Result]) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Fit: Integer>
  @action: Returns array length.
  @note: Alternative.
[==============================================================================}
function HArr.Fit: Integer; overload; cdecl;
begin
  Result := ((High(Self) - Low(Self)) + 1);
end;

{==============================================================================]
 <arr.Fit: Integer>
  @action: Resizes the array to aSize (sets length safely).
  @note: Returns the length that was set to Self. Negative sizes are clamped to 0.
[==============================================================================}
function HArr.Fit(const aSize: Integer): Integer; overload; cdecl;
begin
  Result := Max(0, aSize);
  SetLength(Self, Result);
end;

{==============================================================================]
 <arr.Fit: Integer>
  @action: Resizes the array to fit within the specified range.
  @note: 
    - Returns the final array length. 
    - If current length is below b.start → array grows to b.start.
    - If current length is above b.stop → array shrinks to b.stop.
    - If current length is within the range → no change.
    - Negative lengths are clamped to 0.
[==============================================================================}
function HArr.Fit(const aBounds: TRange): Integer; overload; cdecl;
var
  l: Integer;
  b: TRange;
begin
  l := Length(Self);
  b := aBounds.Normalize.ClampMin(0);
  if (l < b.start) then
    Result := b.start
  else
    if (l > b.stop) then
      Result := b.stop
    else
      Result := l;	
  if (Result <> l) then
    SetLength(Self, Result);
end;

{==============================================================================]
 <arr.Fits(maxValue: Integer): Integer>
 @action: Returns true if arr size is at maximum maxValue.
 @note: None.
[==============================================================================}
function HArr.Fits(const maxValue: Integer): Boolean; overload; cdecl;
begin
  Result := (Length(Self) <= maxValue);
end;

{==============================================================================]
 <arr.Fits(target: TRange): Integer>
 @action: Returns true if arr size is between target start and stop.
 @note: None.
[==============================================================================}
function HArr.Fits(const target: TRange): Boolean; overload; cdecl;
begin
  Result := not ((Length(Self) < Min(target.start, target.stop)) or (Length(Self) > Max(target.start, target.stop)));
end;

{==============================================================================]
 <arr.Flip: Boolean>
 @action: Reverses array arr.
 @note: Alternative for TArray_Reverse
[==============================================================================}
function HArr.Flip: Boolean; overload; cdecl;
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
 <arr.Free: Integer>
 @action: Result := Length(Self) + SetLength(Self, 0) combo. 
 @note: None.
[==============================================================================}
function HArr.Free: Integer; overload; cdecl;
begin
  Result := Length(Self);
  SetLength(Self, 0);
end;

{==============================================================================]
 <arr.FromLeft(count, index): TArray>
 @action: Returns count of array items from left-side by index.
 @note: None
[==============================================================================}
function HArr.FromLeft(const count: Integer; const index: Integer = 2147483647): TArr; overload; cdecl;
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
function HArr.FromRight(const count: Integer; const index: Integer = 0): TArr; overload; cdecl;
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
function HArr.Get: TArr; overload; cdecl;
var
  a: TVar;
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
function HArr.Get(const ID: TIntegerArray): TArr; overload; cdecl;
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
function HArr.Get(const ID: TRange): TArr; overload; cdecl;
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
function HArr.Group: T2DArr; overload; cdecl;
var
  h, i, r, g, l: Integer;
  f: Boolean;
begin
  if Self.Empty then
    Exit([]);
  g := -1;
  h := High(Self);
  SetLength(Result, (h + 1));
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
      Result[g.Increment] := [Self[i]];
  end;
  SetLength(Result, (g + 1));
end;

{==============================================================================]
 <arr.Group: T2DArray>
 @action: Groups array arr to 2D array by items.
 @note: ([1,2,1,2,3,1,2,3,4]) => [1,1,1][2,2,2][3,3][4]
[==============================================================================}
function HArr.Group(const weight: TIntegerArray; const wSorted: Boolean = False): T2DArr; overload; cdecl; var w: TIntegerArray; {$DEFINE Skeleton_Group}{$I config\Skeletons.inc}{$UNDEF Skeleton_Group}
function HArr.Group(const weight: TDoubleArray; const wSorted: Boolean = False): T2DArr; overload; cdecl; var w: TDoubleArray; {$DEFINE Skeleton_Group}{$I config\Skeletons.inc}{$UNDEF Skeleton_Group}

{==============================================================================]
 <arr.Grow(item: VarType; allowDuplicates: Boolean): Integer>
 @action: Feeds item to array and returns the index position it was added to.
 @note: Returns -1 if duplicates are not allowed and array already contains item.
[==============================================================================}
function HArr.Grow(const item: TVar; const allowDuplicates: Boolean = False): Integer; overload; cdecl;
begin
  if ((not allowDuplicates) and Self.Contains(item)) then
    Exit(-1);
  Result := Length(Self);
  SetLength(Self, (Result + 1));
  Self[Result] := item;
end;

{==============================================================================]
 <arr.Holds(chain: TArray): Boolean>
 @action: Returns true if arr contains (holds) WHOLE chain of items in it.
 @note: Starting from any index and ending to any index!
[==============================================================================}
function HArr.Holds(const chain: TArr): Boolean; overload; cdecl;
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
 <arr.Homogeneous(item: VarType): Boolean>
 @action: Returns true if arr consists of ONLY same items.
 @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function HArr.Homogeneous(const item: TVar): Boolean; overload; cdecl;
var
  h, i: Integer;
begin
  i := -1;
  h := High(Self);
  Result := (h > -1);
  while (Result and (i.Increase < h)) do
    Result := (Self[i] = item);
end;

{==============================================================================]
 <arr.Homogeneous: Boolean>
 @action: Returns true if arr consists of ONLY same items.
 @note: Requires at least single item. Otherwise returns False. (With empty arrays)
[==============================================================================}
function HArr.Homogeneous: Boolean; overload; cdecl;
begin
  Result := ((Length(Self) > 0) and Homogeneous(Self[0]));
end;

{==============================================================================]
 <arr.ID(aAscending: Boolean): TIntegerArray>
 @action: Returns indexes of arr as TIntegerArray.
 @note: None.
[==============================================================================}
function HArr.ID(const aAscending: Boolean = True): TIntegerArray; overload; cdecl;
var
  i, l, b, s: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  b := (Integer(not aAscending) * (l - 1));
  s := IfThen(aAscending, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := (b + (s * i));
end;

{==============================================================================]
 <arr.IDs(aAscending: Boolean): TIntegerArray>
 @action: Returns IDs of arr as TIntegerArray.
 @note: None.
[==============================================================================}
function HArr.IDs(const aAscending: Boolean = True): TIntegerArray; overload; cdecl;
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
function HArr.IDs(const ID: TIntegerArray): TArr; overload; cdecl;
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
function HArr.IDs(const ID: TIntegerArray; const item: TVar): TArr; overload; cdecl;
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
function HArr.IDs(const ID: TIntegerArray; const items: TArr): TArr; overload; cdecl;
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
function HArr.Includes(const item: TVar; const index: Integer = 2147483647): Boolean; cdecl;
var
  i: Integer;
begin
  for i := Min(High(Self), index) downto 0 do
    if (item = Self[i]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
 <arr.Indexed(aAscending: Boolean): TIntegerArray>
 @action: Returns IDs of arr as TIntegerArray.
 @note: None.
[==============================================================================}
function HArr.Indexed(const aAscending: Boolean = True): TIntegerArray; overload; cdecl;
var
  l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  if Self.Populated then
  case aAscending of
    True:
    while (l.Decrement > -1) do
      Result[l] := l;
    False:
    while (l.Decrement > -1) do
      Result[(Length(Self) - l) - 1] := l;
  end;
end;

{==============================================================================]
 <arr.Indexes(aAscending: Boolean): TIntegerArray>
 @action: Returns IDs of arr as TIntegerArray.
 @note: None.
[==============================================================================}
function HArr.Indexes(const aAscending: Boolean = True): TIntegerArray; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := IfThen(aAscending, i, ((l - i) - 1));
end;

{==============================================================================]
 <arr.Indices(aAscending: Boolean): TIntegerArray>
 @action: Returns IDs of arr as TIntegerArray.
 @note: None.
[==============================================================================}
function HArr.Indices(const aAscending: Boolean = True): TIntegerArray; overload; cdecl;
var
  i, l, h: Integer;
begin
  l := Low(Self);
  h := High(Self);
  SetLength(Result, ((h - l) + 1));
  case aAscending of
    False:  
    for i := l to h do
      Result[h - i] := i;
	True:
    for i := l to h do
      Result[i - l] := i;
  end;
end;    

{==============================================================================]
 <arr.Keep(items: TArray; index: Integer): TArray>
 @action: Keeps items in array, removes others.
 @note: Supports custom start index! Returns the modified arr.
[==============================================================================}
function HArr.Keep(const items: TArr; const index: Integer = 0): TArr; overload; cdecl;
var
  m, i, l, r: Integer;
begin
  l := Length(Self);
  m := Max(0, index);
  case (items.Populated and (m < l)) of
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
 <arr.Kill: Integer>
 @action: Combination of Length(arr) + SetLength(arr, 0).
 @note: Returns the length of the arr!
[==============================================================================}
function HArr.Kill: Integer; overload; cdecl;
begin
  Result := Length(Self);
  SetLength(Self, 0);
end;

{==============================================================================]
 <arr.Last: Integer>
 @action: Returns the last index of arr.
 @note: With empty array result will be -1!
[==============================================================================}
function HArr.Last: Integer; overload; cdecl;
begin
  Result := IfThen(Self.Empty, -1, (Self.Size - 1));
end;

{==============================================================================]
 <arr.Last(item: VarType): Integer>
 @action: Returns the last index that matches item in arr.
 @note: Unmatch will be -1!
[==============================================================================}
function HArr.Last(const item: TVar): Integer; overload; cdecl;
begin
  for Result := High(Self) downto 0 do
    if (Self[Result] = item) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.Last(items: TArray): Integer>
 @action: Returns the last arr index that matches any of the items.
 @note: Unmatch will be -1!
[==============================================================================}
function HArr.Last(const items: TArr): Integer; overload; cdecl;
begin
  for Result := High(Self) downto 0 do
    if items.Contains(Self[Result]) then
      Exit;
  Result := -1;
end;

{==============================================================================]
 <arr.LeastCommon>
 @action: Returns the least common array item.
 @note: None
[==============================================================================}
function HArr.LeastCommon: TVar; overload; cdecl;
var
  d: specialize TDictionary<TVar, Integer>;
  c, m, i: Integer;
begin
  if Self.Empty then
    Exit(Default(TVar));
  Result := Self[0];
  m := MaxInt;
  d := specialize TDictionary<TVar, Integer>.Create;
  try
    for i := 0 to High(Self) do
      if d.TryGetValue(Self[i], c) then
        d[Self[i]] := (c + 1)
      else
        d.Add(Self[i], 1);
    for i := 0 to High(Self) do
      if (d[Self[i]] < m) then
      begin
        m := d[Self[i]];
        Result := Self[i];
      end;
  finally
    d.Free;
  end;
end;

{==============================================================================]
 <arr.LeastFrequent: VarType> 
 @action: Returns the least frequent arr item.
 @note: None.
[==============================================================================}
function HArr.LeastFrequent: TVar; overload; cdecl;
var
  i, j, c, m: Integer;
  f: Boolean;
begin
  if Self.Empty then
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
function HArr.Len: Integer; overload; cdecl;
begin
  Result := Length(Self);
end;

{==============================================================================]
 <arr.Loc(item: VarType; index: Integer): Integer>
 @action: Returns last index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function HArr.Loc(const item: TVar; const index: Integer = 2147483647): Integer; overload; cdecl;
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
function HArr.Loc(const items: TArr; const index: Integer = 2147483647): Integer; overload; cdecl;
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
 <arr.Location(item: VarType; index: Integer): Integer>
 @action: Returns index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function HArr.Location(const item: TVar; const index: Integer = 2147483647): Integer; overload; cdecl;
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
function HArr.Location(const items: TArr; const index: Integer = 2147483647): Integer; overload; cdecl;
var
  h, i, l: Integer;
begin
  if items.Populated then
  begin
    h := High(items);
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
function HArr.Locations(const item: TVar; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
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
function HArr.Locations(const items: TArr; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
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
 <arr.Locations: TIntegerArray>
 @action: Simply returns arr indexes.
 @note: None.
[==============================================================================}
function HArr.Locations: TIntegerArray; overload; cdecl;
var
  i, r: Integer;
begin
  SetLength(Result, Length(Self));
  r := 0;
  for i := High(Result) downto 0 do
    Result[r.Increase] := i;  
end;

{==============================================================================]
 <arr.Mix(mixings: Integer): Boolean>
 @action: Ramdomizes array with custom mixings.
 @note: None.
[==============================================================================}
function HArr.Mix(const mixings: Integer = 1): Boolean; overload; cdecl;
var
  l, i, m: Integer;
begin
  Result := ((mixings > 0) and Self.Populated);
  if not Result then
    Exit;
  l := Length(Self);
  if (l > 1) then
  for m := 1 to mixings do
    for i := 0 to (l - 1) do
      Exchange(Random(l), Random(l));
end;

{==============================================================================]
 <arr.Mixed(mixings: Integer): TArray>
 @action: Returns ramdomized array by mixing.
 @note: None.
[==============================================================================}
function HArr.Mixed(const mixings: Integer = 1): TArr; overload; cdecl;
var
  l, i, m: Integer;
begin
  l := Length(Self);
  Result := Self.Copy;
  if (l > 1) then
  for m := 1 to mixings do
    for i := 0 to (l - 1) do
      Swap(Result[Random(l)], Result[Random(l)]);
end;

{==============================================================================]
 <arr.MostCommon>
 @action: Returns the most common array item.
 @note: None
[==============================================================================}
function HArr.MostCommon: TVar; overload; cdecl;
var
  d: specialize TDictionary<TVar, Integer>;
  c, m, i: Integer;
begin
  if Self.Empty then
    Exit(Default(TVar));
  Result := Self[0];
  m := 0;
  d := specialize TDictionary<TVar, Integer>.Create;
  try
    for i := 0 to High(Self) do
      if d.TryGetValue(Self[i], c) then
        d[Self[i]] := (c + 1)
      else
        d.Add(Self[i], 1);
    for i := 0 to High(Self) do
      if (d[Self[i]] > m) then
      begin
        m := d[Self[i]];
        Result := Self[i];
      end;
  finally
    d.Free;
  end;
end;

{==============================================================================]
 <arr.MostFrequent: VarType> 
 @action: Returns the most frequent arr item.
 @note: None.
[==============================================================================}
function HArr.MostFrequent: TVar; overload; cdecl;
var
  i, j, c, m: Integer;
begin
  if Self.Empty then
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
 <arr.Multi(threshold: Integer): Boolean>
 @action: Returns true if array contains at least threshold of items in it.
 @note: None.	
[==============================================================================}
function HArr.Multi(const threshold: Integer = 2): Boolean; overload; cdecl;
begin
  Result := (Length(Self) >= threshold);
end;

{==============================================================================]
 <arr.Multi(threshold: Integer): Boolean>
 @action: Returns true if array contains at least threshold of items in it.
 @note: None.	
[==============================================================================}
function HArr.Multi(const threshold: TRange): Boolean; overload; cdecl;
var
  r: TRange;
begin
  r:= threshold.Normalize;
  Result := InRange(Length(Self), r.start, r.stop);
end;

{==============================================================================]
 <arr.Next(index: Integer; count: Integer): TArray>
 @action: Returns next items from array by index and count.
 @note: None.	
[==============================================================================}
function HArr.Next(const index: Integer; const count: Integer = 2147483647): TArr; overload; cdecl;
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
 <arr.Occurs(item: VarType; occurrence: Integer): Boolean>
 @action: Returns true item exists in arr EXACTLY(!) occurrence amount of times.
 @note: Supports lookup for 0 items. Loops array through from beginning to end.	
[==============================================================================}
function HArr.Occurs(const item: TVar; const occurrence: Integer = 1): Boolean; overload; cdecl;
var
  o, p: Integer;
begin
  if (occurrence < 0) then
    Exit(False);
  case (occurrence = 0) of
    False:
    begin
      o := 0;
      p := -1;
      while (o <= occurrence) do
      begin
        p := Self.Pos(item, (p + 1));
        if (p = -1) then
          Break;
        o := (o + 1);
      end;
      Result := (o = occurrence);
    end;
    True: Result := (Self.Pos(item) = -1);
  end;
end;

{==============================================================================]
 <arr.Overlay(items: TArray; index: Integer; init: VarType): TArray>
 @action: Overlays items to array index.
 @note: Returns the array with overlay action.		
[==============================================================================}
function HArr.Overlay(const items: TArr; const index: Integer; const init: TVar): TArr; overload; cdecl;
var
  s, l, r, i, a, j: Integer;
begin
  l := Length(items);
  if (l = 0) then
    Exit(Self.Copy);
  s := Length(Self);
  r := IfThen((index < 0), Max((Abs(index) + s), l), Max(s, (index + l)));
  SetLength(Result, r);
  for i := 0 to (r - 1) do
    if not ((index <= 0) and (i < l)) then
    begin
      j := (i - index);
      if not ((index >= 0) and (j >= 0) and (j < l)) then
      begin
        a := IfThen((index < 0), (i - Abs(index)), i);
        if ((a >= 0) and (a < s)) then
          Result[i] := Self[a]
        else
          Result[i] := init;
      end else
        Result[i] := items[j];
    end else
      Result[i] := items[i];
end;

function HArr.Overlay(const items: TArr; const index: Integer = 0): TArr; overload; cdecl;
begin
  Result := Self.Overlay(items, index, Default(TVar));
end;

{==============================================================================]
 <arr.Oversize(limit: Integer): Boolean>
 @action: Returns true if size of arr is OVER the limit.
 @note: None.	
[==============================================================================}
function HArr.Oversize(const limit: Integer): Boolean; overload; cdecl;
begin
  Result := (Length(Self) > limit);
end;

{==============================================================================]
 <arr.Partition(pSize: Integer): T2DArray>
 @action: Partitions array arr to 2D array by size of parts.
 @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5,6][7]
[==============================================================================}
function HArr.Partition(const pSize: Integer): T2DArr; overload; cdecl;
var
  p, i, j, s, r, l: Integer;
begin
  if ((pSize > 0) and Self.Populated) then
  begin
    l := Length(Self);
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
 <arr.Patch(index: Integer; items: TArray): Integer>
 @action: Simply puts items to array index.
 @note: Uses SetLength incase index + items goes over the current length.
        If index is below 0 it will automatically set max length.
[==============================================================================}
function HArr.Patch(const index: Integer; const items: TArr): Integer; overload; cdecl;
var
  j, i: Integer;
begin
  if items.Empty then
    Exit(index);
  i := IfThen((index < 0), Length(Self), index);
  Result := (i + Length(items));
  if (Result > Length(Self)) then
    SetLength(Self, Result);
  for j := 0 to High(items) do
    Self[i + j] := items[j];
end;

{==============================================================================]
 <arr.Pick(items: TArray; index: Integer): TArray>
 @action: Alternative method for arr.Keep
 @note: None.
[==============================================================================}
function HArr.Pick(const items: TArr; const index: Integer = 0): TArr; overload; cdecl;
var
  i, m, l: Integer;
begin
  l := Length(Self);
  m := Max(0, index);
  case (items.Populated and (m < l)) of
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
 <arr.Plain: Boolean>
 @action: Returns true if all array items are identical.
 @note: None.
[==============================================================================}
function HArr.Plain: Boolean; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  if (l <= 1) then
    Exit(True);
  for i := 1 to (l - 1) do
    if (Self[i] <> Self[i - 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
 <arr.Pop: VarType>
 @action: Returns and removes item from highest array index from arr.
 @note: UNSAFE! Make sure array has enough items..
[==============================================================================}
function HArr.Pop: TVar; overload; cdecl;
var
  h: Integer;
begin
  if Self.Empty then
    Exit;
  h := High(Self);
  Result := Self[h];
  SetLength(Self, h);
end;

{==============================================================================]
 <arr.Pop(null: VarType): VarType>
 @action: Returns and removes item from highest array index from arr.
 @note: Returns null if array contains no items.
[==============================================================================}
function HArr.Pop(const null: TVar): TVar; overload; cdecl;
var
  h: Integer;
begin
  if Self.Empty then
    Exit(null);
  h := High(Self);
  Result := Self[h];
  SetLength(Self, h);
end;

{==============================================================================]
 <arr.Populate(items: TArray; times: Integer): Boolean>
 @action: Populates array with items, x-times.
 @note: Returns true if items is not empty and times is more than 0.
[==============================================================================}
function HArr.Populate(const items: TArr; const times: Integer = 1): Boolean; overload; cdecl;
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
function HArr.Populate(const item: TVar; const times: Integer = 1): Boolean; overload; cdecl;
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
 <arr.Populated(population: TRange): Boolean>
 @action: Returns true if arr Length is between population TRange (start, stop).
 @note: None.
[==============================================================================}
function HArr.Populated(const population: TRange): Boolean; overload; cdecl;
begin
  Result := InRange(Length(Self), population.Minimum, population.Maximum);
end;

{==============================================================================]
 <arr.Populated(populationMin, populationMax: Integer): Boolean>
 @action: Returns true if arr Length is between populationMin and populationMax.
 @note: Strict! Min should NOT be higher than Max.
[==============================================================================}
function HArr.Populated(const populationMin: Integer = 1; const populationMax: Integer = 2147483647): Boolean; overload; cdecl;
begin
  Result := InRange(Length(Self), populationMin, populationMax);
end;  

{==============================================================================]
 <arr.Pos(item: VarType; index: Integer): Integer>
 @action: Returns index position from arr which matched with item.
 @note: Returns -1 if any of arr items doesnt match with item!
[==============================================================================}
function HArr.Pos(const item: TVar; const index: Integer = 0): Integer; overload; cdecl;
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
function HArr.Pos(const items: TArr; const index: Integer = 0): Integer; overload; cdecl;
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
function HArr.Position(const item: TVar; const index: Integer = 0): Integer; overload; cdecl;
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
function HArr.Position(const items: TArr; const index: Integer = 0): Integer; overload; cdecl;
var
  h, i, l: Integer;
begin
  if items.Populated then
  begin
    h := High(items);
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
function HArr.Positions(const item: TVar; const index: Integer = 0): TIntegerArray; overload; cdecl;
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
function HArr.Positions(const items: TArr; const index: Integer = 0): TIntegerArray; overload; cdecl;
var
  i, r, h, s: Integer;
begin
  r := 0;
  h := High(Self);
  s := Max(0, index);
  if ((h > -1) and (s <= h) and items.Populated) then
  begin
    SetLength(Result, ((h + 1) - s));
    for i := s to h do
      if items.Contains(Self[i]) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
 <arr.Positions: TIntegerArray>
 @action: Simply returns arr indexes.
 @note: None.
[==============================================================================}
function HArr.Positions: TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Result) do
    Result[i] := i;  
end;

{==============================================================================]
 <arr.Presence(item: VarType; occurrence: Integer): Boolean>
 @action: Returns true item exists in arr EXACTLY(!) occurrence amount of times.
 @note: Supports lookup for 0 items. Loops array through from end to beginning.	
[==============================================================================}
function HArr.Presence(const item: TVar; const occurrence: Integer = 1): Boolean; overload; cdecl;
var
  l, o: Integer;
begin
  if (occurrence < 0) then
    Exit(False);
  case (occurrence = 0) of
    False:
    begin
      o := 0;
      l := Length(Self);
      while (o <= occurrence) do
      begin
        l := Self.Loc(item, (l - 1));
        if (l = -1) then
          Break;
        o := (o + 1);
      end;
      Result := (o = occurrence);
    end;
    True: Result := (Self.Loc(item) = -1);
  end;
end;

{==============================================================================]
 <arr.Previous(index: Integer; count: Integer): TIntegerArray>
 @action: Returns previous array items from index by count.
 @note: None.
[==============================================================================}
function HArr.Previous(const index: Integer; const count: Integer = 2147483647): TArr; overload; cdecl;
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
 <arr.Pruned: TArray>
 @action: Produces a new array by removing all immediately repeated values,
          effectively run-length–compressing the input.
 @note: Only consecutive duplicates are removed; values separated by others
        are left untouched. The relative order of the remaining elements
        is unchanged.
[==============================================================================}
function HArr.Pruned: TArr; overload; cdecl;
var
  i, l, r: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  Result[0] := Self[0];
  if (l = 1) then
    Exit;
  r := 0;
  for i := 1 to High(Self) do
    if not (Self[i] = Self[i - 1]) then
      Result[r.Increment] := Self[i];
  SetLength(Result, (r + 1));
end;

{==============================================================================]
 <arr.Pruned: TArray>
 @action: Produces a new array by removing all immediately repeated values,
          effectively run-length–compressing the input.
 @note: Custom threshold possibility.
[==============================================================================}
function HArr.Pruned(const threshold: Integer): TArr; overload; cdecl;
var
  w: TArr;
  e: TVar;
  h, t, c, i, j: Integer;
  d: Boolean;
begin
  if (Self.Empty or (threshold < 1)) then
    Exit(Self.Copy);
  SetLength(Result, 0);
  SetLength(w, threshold);
  h := 0;
  t := 0;
  c := 0;
  for i := 0 to High(Self) do
  begin
    e := Self[i];
    d := False;
    for j := 0 to (c - 1) do
      if (w[(h + j) mod threshold] = e) then
      begin
        d := True;
        Break;
      end;
    if not d then
    begin
      SetLength(Result, (Length(Result) + 1));
      Result[High(Result)] := e;
      w[t] := e;
      t := ((t + 1) mod threshold);
      if (c < threshold) then
        Inc(c)
      else
        h := ((h + 1) mod threshold);
    end;
  end;
end;

{==============================================================================]
 <arr.Prune: Integer>
 @action: Removes all immediately repeated values,
          effectively run-length–compressing the input.
 @note: Only consecutive duplicates are removed; values separated by others
        are left untouched. The relative order of the remaining elements
        is unchanged.
[==============================================================================}
function HArr.Prune: Integer; overload; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 1 to High(Self) do
    if (Self[i] <> Self[Result]) then
      Self[Result.Increment] := Self[i];
  if not Self.Empty then
    SetLength(Self, Result.Increment);
end; 

{==============================================================================]
 <arr.Pull: TArr>
 @action: Returns the contents of the array and leaves it empty.
 @note: After calling Pull, Self.Length = 0.
[==============================================================================}
function HArr.Pull: TArr; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i];
  SetLength(Self, 0);
end;

{==============================================================================]
 <arr.Purified: TArr>
 @action: Returns array with unique items
 @note: None.
[==============================================================================}
function HArr.Purified(const dAscending: Boolean = True): TArr; overload; cdecl;
var
  d: specialize TDictionary<TVar, Boolean>;
  l: specialize TList<TVar>;
  i: Integer;
begin
  d := specialize TDictionary<TVar, Boolean>.Create;
  l := specialize TList<TVar>.Create;
  try
    case dAscending of
      True:
      for i := 0 to High(Self) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
          l.Add(Self[i]);
        end;
      False:
      for i := High(Self) downto 0 do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
          l.Add(Self[i]);
        end;
    end;
    Result := l.ToArray;
  finally
    d.Free;
    l.Free;
  end;
end;

{==============================================================================]
 <arr.Purify: Integer>
 @action: Removes duplicates
 @note: None
[==============================================================================}
function HArr.Purify(const dAscending: Boolean = True): Integer; overload; cdecl;
var
  d: specialize TDictionary<TVar, Boolean>;
  c: TArr;
  i: Integer;
begin
  d := specialize TDictionary<TVar, Boolean>.Create;
  Result := 0;
  try
    case dAscending of
      True:
      for i := 0 to High(Self) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], True);
	  Self[Result.Increase] := Self[i];
        end;
      False:
      begin
        c := Self.Copy;
        for i := High(c) downto 0 do
          if not d.ContainsKey(c[i]) then
          begin
            d.Add(c[i], True);
	    Self[Result.Increase] := c[i];
          end;
      end;
    end;
  finally
    d.Free;
  end;
  SetLength(Self, Result);
end;

{==============================================================================]
 <arr.Put(ID: TIntegerArray; item: VarType): TArray>
 @action: Returns array arr filled with item to indexes (ID).
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Put(const ID: TIntegerArray; const item: TVar): TArr; overload; cdecl;
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
function HArr.Put(const ID: TIntegerArray; const items: TArr): TArr; overload; cdecl;
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
function HArr.Put(const index: Integer; const items: TArr): TArr; overload; cdecl;
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
function HArr.Push(const item: TVar): TArr; overload; cdecl;
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
function HArr.Push(const items: TArr): TArr; overload; cdecl;
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
  <HArr.QuickSorted(weight: TIntegerArray/TDoubleArray; aAscending: Boolean): TArray>
  @action: Returns arr sorted by weight, based on QuickSort algorithm.
  @note: Weight and arr must be the same length! Otherwise returns empty array.
[==============================================================================}
function HArr.QuickSorted(const weight: TIntegerArray; const aAscending: Boolean = True): TArr; overload; cdecl; var w: Integer; {$DEFINE Skeleton_QuickSorted}{$I config\Skeletons.inc}{$UNDEF Skeleton_QuickSorted}
function HArr.QuickSorted(const weight: TDoubleArray; const aAscending: Boolean = True): TArr; overload; cdecl; var w: Double; {$DEFINE Skeleton_QuickSorted}{$I config\Skeletons.inc}{$UNDEF Skeleton_QuickSorted}

{==============================================================================]
  <arr.Randomized>
  @action: Returns randomized copy of array
  @note: None.
[==============================================================================}
function HArr.Randomized: TArr; overload; cdecl;
var
  s, l, r: Integer;
  i: TIntegerArray;
begin
  l := Length(Self);
  if (l < 2) then
    Exit(Self.Copy);
  SetLength(Result, l);
  i := Self.Indexes;
  for s := 0 to High(Self) do
  begin
    r := Random(l);
    Result[i[r]] := Self[s];
    i[r] := i[l.Decrement];
  end;
end;

{==============================================================================]
  <arr.Range>
  @action: Returns the indexes as TRange where subArray exists in array (Self)
  @note: (-1, -1) if subArray is not found.
         Loops array from index to max.
[==============================================================================}
function HArr.Range(const subArray: TArr; const index: Integer = 0): TRange; overload; cdecl;
var
  i, j, a, s, p: Integer;
  f: Boolean;
begin
  Result.start := -1;
  Result.stop  := -1;
  a := Length(Self);
  s := Length(subArray);
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
  <arr.Ranges>
  @action: Returns the indexes as TRanges where subArray exists in array (Self)
  @note: [] if not a single subArray is not found.
         Loops array from index to max.
[==============================================================================}
function HArr.Ranges(const subArray: TArr; const index: Integer = 0): TRangeArray; overload; cdecl;
var
  i, j, a, s, p, l: Integer;
  f: Boolean;
begin
  SetLength(Result, 0);
  a := Length(Self);
  s := Length(subArray);
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
 <arr.Recreate: Boolean>
 @action: Clear the array and reallocate to arrSize (negative = previous length).
 @note: Returns True if array was non-empty and arrSize <> 0.
[==============================================================================}
function HArr.Recreate(const arrSize: Integer): Boolean; overload; cdecl;
var
  l: Integer;
begin
  l := Length(Self);
  Result := ((Length(Self) > 0) or (arrSize <> 0));
  SetLength(Self, 0);
  if Result then
    if (arrSize < 0) then
      SetLength(Self, l)
    else
      SetLength(Self, arrSize);
end;

{==============================================================================]
 <arr.Reject(items: TArray; index: Integer): TArray>
 @action: Returns a new array with elements from items excluded, up to and including the specified index.
 @note: Elements after index are copied without filtering. If index is out of bounds, it is clamped to the array length.
         The default index filters the entire array.
[==============================================================================}
function HArr.Reject(const items: TArr; const index: Integer = 2147483647): TArr; overload; cdecl;
var
  i, l, m, c: Integer;
begin
  if (items.Empty or Self.Empty) then
    Exit(Self.Copy);
  l := Length(Self);
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
 <arr.Remove(item: VarType; index: Integer; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function HArr.Remove(const item: TVar; const index: Integer = 0; const all: Boolean = True): TArr; overload; cdecl;
var
  l, i, r, m: Integer;
  s: Boolean;
begin
  l := Length(Self);
  if ((l = 0) or (index >= l)) then
    Exit(Self.Copy);
  m := Max(0, index);
  s := False;
  r := 0;
  SetLength(Result, l);
  for i := 0 to (m - 1) do
    Result[i] := Self[i];
  for i := m to (l - 1) do
    if (s or (Self[i] <> item)) then
      Result[r.Increase + m] := Self[i]
    else
      s := not all;
  SetLength(Result, (r + m));
end;

{==============================================================================]
 <arr.Remove(item: VarType; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed.
[==============================================================================}
function HArr.Remove(const item: TVar; const all: Boolean): TArr; overload; cdecl;
begin
  Result := Self.Remove(item, 0, all);
end;

{==============================================================================]
 <arr.Remove(items: TArray; index: Integer; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed. Supports start index position.
[==============================================================================}
function HArr.Remove(const items: TArr; const index: Integer = 0; const all: Boolean = True): TArr; overload; cdecl;
var
  a, b, l, i, r, m: Integer;
  d, s: Boolean;
begin
  l := Length(Self);
  b := High(items);
  if ((l = 0) or (index >= l) or (b = -1)) then
    Exit(Self.Copy);
  m := Max(0, index);
  r := 0;
  s := False;
  SetLength(Result, l);
  for i := 0 to (m - 1) do
    Result[i] := Self[i];
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
      Result[r.Increase + m] := Self[i]
    else
      d := not s;
  end;
  SetLength(Result, (r + m));
end;

{==============================================================================]
 <arr.Remove(items: TArray; all: Boolean): TArray>
 @action: Deletes item(s) from array arr. Only 1 if all is set as False.
 @note: Returns amount of items that were removed.
[==============================================================================}
function HArr.Remove(const items: TArr; const all: Boolean): TArr; overload; cdecl;
begin
  Result := Self.Remove(items, 0, all);
end;

{==============================================================================]
 <arr.Reposition(oldIndex, newIndex: Integer): Boolean>
 @action: Moves item from oldIndex to newIndex in array arr.
 @note: Returns true with success.
[==============================================================================}
function HArr.Reposition(const oldIndex, newIndex: Integer): Boolean; overload; cdecl;
var
  s: TVar;
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
 <arr.Reset: Integer>
 @action: Resets all elements of the array to default values while preserving its structure.
 @note: Returns the number of elements that were reset.
[==============================================================================}
function HArr.Reset: Integer; overload; cdecl;
begin
  Result := Length(Self);
  SetLength(Self, 0);
  SetLength(Self, Result);
end; 

{==============================================================================]
 <arr.Resize(aChange: Integer): Integer>
 @action: Updates's arr length with aChange.
 @note: aChange > 0 => Result will give how many elements were added
        aChange < 0 => Result will give how many elements got deleted (it will be negative value!)
		aChange = 0 => Returns 0.
[==============================================================================}
function HArr.Resize(const aChange: Integer): Integer; overload; cdecl;
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
function HArr.Resize(const aChange: Integer; const null: TVar): Integer; overload; cdecl;
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
function HArr.Reverse: Boolean; overload; cdecl;
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
function HArr.Reversed: TArr; overload; cdecl;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := Self[(l - i) - 1];
end;

{==============================================================================]
 <arr.Sample(sSize): TArray>
 @action: Returns sample from array by sSize.
 @note: None.
[==============================================================================}
function HArr.Sample(const sSize: Integer): TArr; overload; cdecl;
var
  i: Integer;
  s: TRange;
  r: TIntegerArray;
begin
  if Self.Empty then
    Exit([]);
  s.Create(0, High(Self));
  r := s.Sample(sSize);
  SetLength(Result, Length(r));
  for i := 0 to High(Result) do
    Result[i] := Self[r[i]];
end;

{==============================================================================]
 <arr.Scan(item: VarType; ID: TRange; limit: Integer): TIntegerArray>
 @action: Scans array for item by ID. Returns all the positions.
 @note: Unsafe method! No safety checking.
[==============================================================================}
function HArr.Scan(const ID: TRange; const item: TVar; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r: Integer;
begin
  r := 0;
  if Self.Populated then
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
function HArr.Scan(const ID: TIntegerArray; const item: TVar; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r: Integer;
begin
  r := 0;
  if Self.Empty then
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
function HArr.Scan(const ID: TRange; const items: TArr; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r: Integer;
begin
  r := 0;
  if (Self.Populated and items.Populated) then
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
function HArr.Scan(const ID: TIntegerArray; const items: TArr; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
var
  i, r: Integer;
begin
  r := 0;
  if (Self.Populated and items.Populated) then
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
 <arr.Scramble: TIntegerArray>
 @action: Returns scrambled array, that is randomized with offset and swapping. 
 @note: Supports custom swaps.
[==============================================================================}
function HArr.Scramble(const swaps: Integer = -1): TArr; overload; cdecl;
var
  o, i, l, s: Integer;
begin
  l := Length(Self);
  o := Random(l);
  s := IfThen((swaps < 0), l, swaps);
  Result := Self.Copy(o, (l - o)) + Self.Copy(0, o);
  for i := 1 to s do
    Swap(Result[Random(l)], Result[Random(l)]);
end;

{==============================================================================]
 <arr.Shake: TArray>
 @action: Returns array as randomized with shaking it.
 @note: None.
[==============================================================================}
function HArr.Shake(const shakes: Integer = 1): TArr; overload; cdecl;
var
  i, s: Integer;
begin
  Result := Self.Copy;
  if (Result.Size > 1) then
  for s := 1 to shakes do
    for i := 0 to Random(Self.Size) do
      Swap(Result[i], Result[Random(Self.Size)]);
end;

{==============================================================================]
 <arr.Shift: VarType>
 @action: Shortens the array with first element.
 @note: Returns the removed arr[0].
[==============================================================================}
function HArr.Shift: TVar; overload; cdecl;
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
function HArr.Shift(const sCount: Integer): TArr; overload; cdecl;
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
 <arr.Shuffle: TArray>
 @action: Returns array as randomized with shuffling it.
 @note: None.
[==============================================================================}
function HArr.Shuffle(const shuffles: Integer = 1): TArr; overload; cdecl;
var
  i, s: Integer;
begin
  Result := Self.Copy;
  if (Result.Size > 1) then
  for s := 1 to shuffles do
    for i := 0 to High(Result) do
      Swap(Result[i], Result[Random(Self.Size)]);
end;

{==============================================================================]
 <arr.Singular: Boolean>
 @action: Returns true if all array items are identical.
 @note: None.
[==============================================================================}
function HArr.Singular: Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
      Exit(False);
  Result := True;
end; 

{==============================================================================]
 <arr.Size: Integer> 
 @action: Returns array length.
 @note: Simply Result := Length(arr);
[==============================================================================}
function HArr.Size: Integer; overload; cdecl;
begin
  Result := Length(Self);
end;

{==============================================================================]
 <arr.Size(aSize: Integer): TArray>
 @action: Set's arr length to aSize.
 @note: None.
[==============================================================================}
function HArr.Size(const aSize: Integer): TArr; overload; cdecl;
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
function HArr.Size(const aSize: Integer; const null: TVar): TArr; overload; cdecl;
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
function HArr.SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl;
begin
  Result := InRange(Length(Self), sMin, sMax);
end;

{==============================================================================]
 <arr.SizeMax(target: Integer): Boolean>
 @action: Returns true if size is at equal/lesser than target.
 @note: 	
[==============================================================================}
function HArr.SizeMax(const target: Integer): Boolean; overload; cdecl;
begin
  Result := (Length(Self) <= target);
end;

{==============================================================================]
 <arr.SizeMin(target: Integer): Boolean>
 @action: Returns true if size is at equal/greater than target.
 @note: 	
[==============================================================================}
function HArr.SizeMin(const target: Integer): Boolean; overload; cdecl;
begin
  Result := (Length(Self) >= target);
end;

{==============================================================================]
 <arr.Slice>
 @action: Returns array slice with TRange r.
 @note: Make sure you use correct indexes and there is enough buffer in array!
        No safety checks for this function. 
[==============================================================================}
function HArr.Slice(const r: TRange): TArr; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, r.Size);
  case r.Ascending of
    True:
    for i := r.start to r.stop do
      Result[i - r.start] := Self[i];
    False:
    for i := r.start downto r.stop do
      Result[i - r.start] := Self[i];
  end;
end;

{==============================================================================]
 <arr.Slice>
 @action: Returns array slice with multiple TRanges by r.
 @note: Make sure you use correct indexes and there is enough buffer in array!
        No safety checks for this function. 
[==============================================================================}
function HArr.Slice(const r: TRangeArray): TArr; overload; cdecl;
var
  i, j, l: Integer;
begin
  if r.Empty then
    Exit([]);
  l := 0;
  for i := 0 to High(r) do
    l := (l + r[i].Size);
  SetLength(Result, l);
  for i := High(r) downto 0 do
  case r[i].Ascending of
    True:
    for j := r[i].stop downto r[i].start do
      Result[l.Decrement] := Self[j];
    False:
    for j := r[i].stop to r[i].start do
      Result[l.Decrement] := Self[j];
  end;
end;

{==============================================================================]
 <arr.Slots: TIntegerArray>
 @action: Returns indexes of array.
 @note: None.
[==============================================================================}
function HArr.Slots: TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to (Length(Self) - 1) do
    Result[i] := i;
end;

{==============================================================================]
  <arr.Some>
  @action: Returns random amount of random array items from Self.
  @note: Does not return empty arrays.
[==============================================================================}
function HArr.Some: TArr; overload; cdecl;
begin
  Result := Self.Shuffle.Copy(0, Max(Random(Self.Size + 1), 1));
end;

{==============================================================================]
  <arr.Some>
  @action: Returns amount of random array items from Self.
  @note: Does not return empty arrays.
[==============================================================================}
function HArr.Some(const amount: Integer): TArr; overload; cdecl;
begin
  Result := Self.Shuffle.Copy(0, Max(1, Min(amount, Self.Size)));
end;

{==============================================================================]
  <arr.Span>
  @action: Returns the indexes as TRange where subArray exists in array (Self)
  @note: (-1, -1) if subArray is not found.
         Loops array from index downto min.
[==============================================================================}
function HArr.Span(const subArray: TArr; const index: Integer = 2147483647): TRange; overload; cdecl;
var
  i, j, a, s, p: Integer;
  f: Boolean;
begin
  Result.start := -1;
  Result.stop  := -1;
  a := Length(Self);
  s := Length(subArray);
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
  <arr.Spans>
  @action: Returns the indexes as TRanges where subArray exists in array (Self)
  @note: [] if not a single subArray is not found.
         Loops array from index downto min.
[==============================================================================}
function HArr.Spans(const subArray: TArr; const index: Integer = 2147483647): TRangeArray; overload; cdecl;
var
  i, j, a, s, p, l: Integer;
  f: Boolean;
begin
  SetLength(Result, 0);
  a := Length(Self);
  s := Length(subArray);
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
 <arr.Strip(item: VarType; eraseDuplicates: Boolean): TArray>
 @action: Removes item(s) from arr and returns it.
 @note: 	
[==============================================================================}
function HArr.Strip(const item: TVar; const eraseDuplicates: Boolean = True): TArr; overload; cdecl;
var
  p: TIntegerArray;
  r: TRange;
begin
  if Self.Empty then
    Exit([]);
  if eraseDuplicates then
    p := Self.Locations(item)
  else
    p := [Self.Loc(item)];
  r.Create(0, High(Self));
  Result := Self.Get(p.Inverted(r));
end;

{==============================================================================]
 <arr.SubarrayLocation(pattern: TArray): Integer>
 @action: Returns subarray position in arr that match pattern exactly.
 @note: arr[0,1,2,0,1,2,3].([1,2]) => 4	
[==============================================================================}
function HArr.SubarrayLocation(const pattern: TArr): Integer; overload; cdecl;
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
function HArr.SubarrayLocations(const pattern: TArr): TIntegerArray; overload; cdecl;
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
function HArr.SubarrayPosition(const pattern: TArr): Integer; overload; cdecl;
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
function HArr.SubarrayPositions(const pattern: TArr): TIntegerArray; overload; cdecl;
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
 <arr.Subset(items: TArray): Boolean>
 @action: Returns true if arr is subset of items.
 @note: None.
[==============================================================================}
function HArr.Subset(const items: TArr): Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not items.Contains(Self[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
 <arr.Supply(item: VarType): Integer>
 @action: Adds item to the end of the array.
 @note: Returns the index where item was inserted.
[==============================================================================}
function HArr.Supply(const item: TVar): Integer; overload; cdecl;
begin
  Result := Length(Self);
  SetLength(Self, (Result + 1));
  Self[Result] := item;
end;

{==============================================================================]
 <arr.Supply(item: TArray): Integer>
 @action: Adds items to the end of the array.
 @note: Returns the index where items were inserted.
[==============================================================================}
function HArr.Supply(const items: TArr): Integer; overload; cdecl;
var
  i: Integer;
begin
  if items.Empty then
    Exit(-1);
  Result := Length(Self);
  SetLength(Self, (Result + Length(items)));
  for i := 0 to High(items) do
    Self[Result + i] := items[i];
end;

{==============================================================================]
 <arr.To2D(rows, columns: Integer): T2DArray>
 @action: Converts 1D array to 2D by rows and columns.
 @note: Make sure Length(array) equals rows*columns (otherwise returns [])! Working examples below.
		TIA := [1,2,3,4,5,6];
		TIA.To2D(2, 3) = [[1, 2, 3], [4, 5, 6]]
        TIA.To2D(3, 2) = [[1, 2], [3, 4], [5, 6]]
[==============================================================================}
function HArr.To2D(const rows, columns: Integer): T2DArr; overload; cdecl;
var
  i, r, c, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, rows, columns);
  i := 0;
  for r := 0 to (rows - 1) do
    for c := 0 to (columns - 1) do
      if (i < l) then
        Result[r][c] := Self[i.Increase];
end;

{==============================================================================]
 <arr.To2D(height: Integer): T2DArray>
 @action: Converts 1D array to 2D by height.
 @note: 
[==============================================================================}
function HArr.To2D(const height: Integer): T2DArr; overload;
var
  l, w, i, r, c: Integer;
begin
  l := Length(Self);
  w := Ceil(l / height);
  SetLength(Result, height, w);
  i := 0;
  for r := 0 to (height - 1) do
    for c := 0 to (w - 1) do
      if (i < l) then
        Result[r][c] := Self[i.Increase];
end;

{==============================================================================]
 <arr.ToIndexes: TIntegerArray>
 @action: Returns indexes of array.
 @note: None.
[==============================================================================}
function HArr.ToIndexes: TIntegerArray; overload; cdecl;
var
  i, l: Integer;
begin
  SetLength(Result, Length(Self));
  l := Low(Self);
  for i := l to High(Self) do
    Result[i - l] := i;
end;

{==============================================================================]
 <arr.Trade(b: TArray): Integer> 
 @action: Swaps array arr and array b.
 @note: arr will be b and b will be arr.
[==============================================================================}
function HArr.Trade(var b: TArr): Integer; overload; cdecl;
var
  a: TArr;
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
function HArr.Undersize(const limit: Integer): Boolean; overload; cdecl;
begin
  Result := (Length(Self) < limit);
end;

{==============================================================================]
 <arr.Uncluttered: TArray>
 @action: Removes all duplicates from arr.
 @note: Returns the number of items that were removed.
[==============================================================================}
function HArr.Uncluttered: TArr; overload; cdecl;
type
  TDict = specialize TDictionary<TVar, Boolean>;
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
 <arr.Uniform: Boolean>
 @action: Returns true if arr is consistent with only 1 item.
 @note: Returns True with empty arrays!
[==============================================================================}
function HArr.Uniform: Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i] <> Self[0]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
 <arr.Uniform(item: VarType): Boolean>
 @action: Returns true if arr is consistent with only custom item.
 @note: Returns True with empty arrays!
[==============================================================================}
function HArr.Uniform(const item: TVar): Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if (Self[i] <> item) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
 <arr.Uniformity>
 @action: Returns 1.0 if all elements equal, 0.0 if all different,
          or something in between based on unique-value ratio. 
 @note: None.
 [==============================================================================}
function HArr.Uniformity: Double; overload; cdecl;
begin
  if not Self.Empty then
    Result := (1.0 / Self.Distinct)
  else
    Result := 0.0;
end;

{==============================================================================]
 <arr.Unified>
 @action: Uniques array
 @note: None.
 [==============================================================================}
function HArr.Unified(const dAscending: Boolean = True): TArr; overload; cdecl;
var
  d: specialize TDictionary<TVar, Byte>;
  i, n: Integer;
begin
  d := specialize TDictionary<TVar, Byte>.Create;
  try
    SetLength(Result, Length(Self));
    n := 0;
    case dAscending of
      True:
      for i := 0 to High(Self) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], 0);
          Result[n.Increase] := Self[i];
        end;
      False:
      for i := High(Self) downto 0 do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], 0);
          Result[n.Increase] := Self[i];
        end;
    end;
    SetLength(Result, n);
  finally
    d.Free;
  end;
end;

{==============================================================================]
 <arr.Unify>
 @action: Uniques array
 @note: None.
 [==============================================================================}
function HArr.Unify(const dAscending: Boolean = True): Integer; overload; cdecl;
var
  s: TArr;
  d: specialize TDictionary<TVar, Byte>;
  l, i: Integer;
begin
  d := specialize TDictionary<TVar, Byte>.Create;
  Result := 0;
  try
    l := Length(Self);
    case dAscending of
      False:
      begin
        s := Self.Copy;
        for i := (l - 1) downto 0 do
          if not d.ContainsKey(Self[i]) then
          begin
            d.Add(Self[i], 0);
            Self[Result.Increase] := s[i];
          end;
      end;
      True:
      for i := 0 to (l - 1) do
        if not d.ContainsKey(Self[i]) then
        begin
          d.Add(Self[i], 0);
          Self[Result.Increase] := Self[i];
        end;
    end;
    SetLength(Self, Result);
  finally
    d.Free;
  end;
end;

{==============================================================================]
 <arr.Unduplicated: TArray>
 @action: Removes all duplicates from arr.
 @note: Returns the number of items that were removed.
[==============================================================================}
function HArr.Unduplicated: TArr; overload; cdecl;
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
function HArr.Uniqued: TArr; overload; cdecl;
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
function HArr.Uniques: TIntegerArray; overload; cdecl;
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
function HArr.Unshift(const item: TVar): TArr; overload; cdecl;
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
function HArr.Unshift(const items: TArr): TArr; overload; cdecl;
var
  l, i, r: Integer;
begin
  if items.Empty then
    Exit(Self.Copy);
  l := Length(items);
  r := (Length(Self) + l);
  SetLength(Result, r);
  for i := (r - 1) downto l do
    Result[i] := Self[i - l];
  for i := 0 to (l - 1) do
    Result[i] := items[i];
end;

{==============================================================================]
 <arr.Void: Boolean>
 @action: Returns true if array is void (empty)
 @note: Alternative for Empty.
[==============================================================================}
function HArr.Void: Boolean; overload; cdecl;
begin
  Result := (Low(Self) > High(Self));
end;

{==============================================================================]
 <arr.Waste: Integer>
 @action: Returns total count of Duplicates in array, which is "Waste"
 @note: None.
[==============================================================================}
function HArr.Waste: Integer; overload; cdecl;
type
  TDict = specialize TDictionary<TVar, Integer>;
var
  d: TDict;
  i: Integer;
  v: TVar;
begin
  Result := 0;
  if Self.Empty then
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
function H2DArr.Blank: Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if Self[i].Populated then
      Exit(False);
  Result := (Length(Self) > 0);
end;

{==============================================================================]
 <arr.Empty: Boolean>
 @action: Returns true if array is empty (Length = 0).
 @note: None.
[==============================================================================}
function H2DArr.Empty: Boolean; overload; cdecl;
begin
  Result := (Length(Self) = 0);
end;

{==============================================================================]
 <arr.Flat: TArray>
 @action: Merges 2D array to 1D.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function H2DArr.Flat: TArr; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    Result := Concat(Result, Self[i]);
end;

{==============================================================================]
 <arr.Flatten: TArray>
 @action: Merges 2D array to 1D.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function H2DArr.Flatten: TArr; overload; cdecl;
var
  i, j, l: Integer;
begin
  SetLength(Result, Self.Total);
  l := 0;
  for i := 0 to High(Self) do
    for j := 0 to High(Self[i]) do
      Result[l.Increase] := Self[i][j];
end;

{==============================================================================]
 <arr.To1D: TArray>
 @action: Merges 2D array to 1D.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function H2DArr.To1D: TArr; overload; cdecl;
var
  i, j: Integer;
  l: specialize TList<TVar>;
begin
  l := specialize TList<TVar>.Create;
  try
    for i := 0 to High(Self) do
      for j := 0 to High(Self[i]) do
        l.Add(Self[i][j]);
    Result := l.ToArray;
  finally
    l.Free;
  end;
end;

{==============================================================================]
 <arr.Linearize: TArray>
 @action: Merges 2D array to 1D.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function H2DArr.Linearize: TArr; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    Result := (Result + Self[i]);
end;

{==============================================================================]
 <arr.Irregular: Boolean>
 @action: Returns true if array contains arrays with different lengths (array not symmetrict)
 @note: [[1,2],[3,4],[5,6]] = False | [[1,2],[3],[4,5,6]] = True
[==============================================================================}
function H2DArr.Irregular: Boolean; overload; cdecl;
var
  i, a, l, h: Integer;
begin
  if Self.Empty then
    Exit(False);
  l := Length(Self[0]);
  h := l;
  for i := 1 to High(Self) do
  begin
    a := Length(Self[i]);
    if (a < l) then
      l := a
	else
      if (a > h) then
        h := a;
    if (l <> h) then
      Exit(True);
  end;
  Result := False;
end;

{==============================================================================]
 <arr.Jagged: Boolean>
 @action: Returns true if array contains arrays with different lengths (array not symmetrict)
 @note: [[1,2],[3,4],[5,6]] = False | [[1,2],[3],[4,5,6]] = True
[==============================================================================}
function H2DArr.Jagged: Boolean; overload; cdecl;
var
  i, l: Integer;
begin
  if (Length(Self) > 0) then
    l := Length(Self[0]);
  for i := 1 to High(Self) do
    if (Length(Self[i]) <> l) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
 <arr.Merge: TArray>
 @action: Merges 2D array to 1D.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function H2DArr.Merge: TArr; overload; cdecl;
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
 <arr.Merged: TArray>
 @action: Merges 2D array to 1D.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function H2DArr.Merged: TArr; overload; cdecl;
var
  i, r, s: Integer;
  a: TArr;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    s := Length(Self[i]);
    if (s > 0) then
    begin
      a := Copy(Self[i], 0, s);
      r := Length(Result);
      SetLength(Result, (r + s));
      Move(a[0], Result[r], (s * SizeOf(TVar)));
    end;
  end;
end;

{==============================================================================]
 <arr.Ragged: Boolean>
 @action: Returns true if array contains arrays with different lengths (array not symmetrict)
 @note: [[1,2],[3,4],[5,6]] = False | [[1,2],[3],[4,5,6]] = True
[==============================================================================}
function H2DArr.Ragged: Boolean; overload; cdecl;
var
  i: Integer;
  h: specialize THashSet<Integer>;
begin
  h := specialize THashSet<Integer>.Create;
  try
    for i := 0 to High(Self) do
      if (h.Count < 2) then
        h.Add(Length(Self[i]))
      else
        Exit(True);
  finally
    h.Free;
  end;
  Result := False;
end;

{==============================================================================]
 <arr.Fit: Integer>
  @action: Returns array length.
  @note: Alternative.
[==============================================================================}
function H2DArr.Fit: Integer; overload; cdecl;
begin
  Result := ((High(Self) - Low(Self)) + 1);
end;

{==============================================================================]
 <arr.Fit: Integer>
  @action: Resizes the array to aSize (sets length safely).
  @note: Returns the length that was set to Self. Negative sizes are clamped to 0.
[==============================================================================}
function H2DArr.Fit(const aSize: Integer): Integer; overload; cdecl;
begin
  Result := Max(0, aSize);
  SetLength(Self, Result);
end;

{==============================================================================]
 <arr.Fit: Integer>
  @action: Resizes the array to fit within the specified range.
  @note: 
    - Returns the final array length. 
    - If current length is below b.start → array grows to b.start.
    - If current length is above b.stop → array shrinks to b.stop.
    - If current length is within the range → no change.
    - Negative lengths are clamped to 0.
[==============================================================================}
function H2DArr.Fit(const aBounds: TRange): Integer; overload; cdecl;
var
  l: Integer;
  b: TRange;
begin
  l := Length(Self);
  b := aBounds.Normalize.ClampMin(0);
  if (l < b.start) then
    Result := b.start
  else
    if (l > b.stop) then
      Result := b.stop
    else
      Result := l;	
  if (Result <> l) then
    SetLength(Self, Result);
end;

{==============================================================================]
 <arr.Size(lengths: TIntegerArray): Int64>
 @action: Returns actual Length for 2D array. Stores Length's of 2D part, of the arr, to lengths variable.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
function H2DArr.Size(var lengths: TIntegerArray): Int64; overload; cdecl;
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
function H2DArr.Size: Int64; overload; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := (Result + Length(Self[i]));
end;

{==============================================================================]
 <arr.Total: Int64>
 @action: Returns actual Length for 2D array.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
function H2DArr.Total: Int64; overload; cdecl;
var
  a: TArr;
begin
  Result := 0;
  for a in Self do
    Result.Increase(Length(a));
end;

{==============================================================================]
 <arr.Population: Int64>
 @action: Returns actual Length for 2D array.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
function H2DArr.Population: Int64; overload; cdecl;
var
  i: Integer;
  s, e: PInteger;
begin
  Result := 0;
  for i := 0 to High(Self) do
  begin
    if Self[i].Empty then
      Continue;
    s := PInteger(Self[i]);
    e := (s + Length(Self[i]));
    Result := (Result + (e - s));
  end;
end;

{==============================================================================]
 <arr.Inventory(items: TArray): Int64>
 @action: Returns actual Length for 2D array.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
        Stores 2D array items as 1D to items.
[==============================================================================}
function H2DArr.Inventory(var items: TArr): Int64; overload; cdecl;
var
  i, j: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Inc(Result, Length(Self[i]));
  SetLength(items, Result);
  if (Result > 0) then
  for i := High(Self) downto 0 do
    for j := High(Self[i]) downto 0 do
      items[Result.Decrement] := Self[i][j];
  Result := Length(items);
end;

{==============================================================================]
 <arr.Inventory: Int64>
 @action: Returns actual Length for 2D array.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
function H2DArr.Inventory: Int64; overload; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Inc(Result, Length(Self[i]));
end;

{==============================================================================]
 <arr.Census: Int64>
 @action: Returns actual Length for 2D array.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
function H2DArr.Census: Int64; overload; cdecl;
var
  i: Integer;
  s, e: PInteger;
begin
  Result := 0;
  for i := 0 to High(Self) do
  begin
    s := PInteger(Self[i]);
    if (s <> nil) then
    begin
      e := s;
      Inc(e, Length(Self[i]));
      Result := Result + (e - s);
    end;
  end;
end; 

{==============================================================================]
 <arr.TArray: TArray>
 @action: Merges 2D array to 1D.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function H2DArr.TArray: TArr; overload; cdecl;
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
 <arr.TArray: TArray>
 @action: Merges 2D array to 1D.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function H2DArr.Unwrap: TArr; overload; cdecl;
var
  i, j: Integer;
begin
  Result := [];
  for i := 0 to High(Self) do
    for j := 0 to High(Self[i]) do
      Result := (Result + [Self[i][j]]);
end;

{==============================================================================]
 <arr.Kill: Integer>
 @action: Combination of Length(arr) + SetLength(arr, 0).
 @note: Returns the length of main array (1st dimension)!
[==============================================================================}
function H2DArr.Kill: Integer; overload; cdecl;
begin
  Result := Length(Self);
  SetLength(Self, 0);
end;

{==============================================================================]
 <arr.Kill(k2D: TIntegerArray): Int64>
 @action: Combination of Length(arr) + SetLength(arr, 0) for array indexes by k2D.
 @note: Supports custom start index! Returns the modified arr.
        Unsafe, simply goes through the given indexes, no safety checks!
		Use with caution, correctly.
[==============================================================================}
function H2DArr.Kill(const k2D: TIntegerArray): Int64; overload; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(k2D) do
  begin
    Result := (Result + Length(Self[k2D[i]]));
    SetLength(Self[k2D[i]], 0);	
  end;
end;

{==============================================================================]
 <arr.Destroy(k2D: TIntegerArray): Int64>
 @action: Combination of Length(arr) + SetLength(arr, 0) for array indexes by k2D.
 @note: Completely wipes the array.
[==============================================================================}
function H2DArr.Destroy: Int64; overload; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
  begin
    Result := (Result + Length(Self[i]));
    SetLength(Self[i], 0);	
  end;
  SetLength(Self, 0);
end;

{==============================================================================]
 <arr.Free: Int64>
 @action: Result := Length(Self) + SetLength(Self, 0) combo for 2D array
 @note: None.
[==============================================================================}
function H2DArr.Free: Int64; overload; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := (Result + Length(Self[i]));
  SetLength(Self, 0);
end;

{==============================================================================]
 <arr.Recreate: Int64>
 @action: Clear the array and reallocate to arrSize (negative = previous length).
 @note: Returns True if array was non-empty and/or arrSize <> 0.
[==============================================================================}
function H2DArr.Recreate(const arrSize: Integer): Boolean; overload; cdecl;
var
  l: Integer;
begin
  l := Length(Self);
  Result := ((Length(Self) > 0) or (arrSize <> 0));
  SetLength(Self, 0);
  if Result then
    if (arrSize < 0) then
      SetLength(Self, l)
    else
      SetLength(Self, arrSize);
end;

{==============================================================================]
 <arr.Reset: Int64>
 @action: Resets all elements of the array to default values while preserving its structure.
 @note: Returns the number of elements that were reset.
[==============================================================================}
function H2DArr.Reset: Int64; overload; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
  begin
    Result := (Result + Length(Self[i]));
    SetLength(Self[i], 0);
  end;
end;

{==============================================================================]
 <arr.Pull: T2DArr>
 @action: Returns the contents of the array and leaves it empty.
 @note: After calling Pull, Self.Length = 0.
[==============================================================================}
function H2DArr.Pull: T2DArr; overload; cdecl;
var
  i, j: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
  begin
    SetLength(Result[i], Length(Self[i]));
    for j := 0 to High(Self[i]) do
      Result[i][j] := Self[i][j];
  end;
  SetLength(Self, 0);
end;

{==============================================================================]
 <T1D.Create(item: VarType; aSize: Integer)>
 @action: Creates array with item where size is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}
class function T1D.Create(const item: TVar; const aSize: Integer = 1): TArr; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Max(0, aSize));
  for i := 0 to High(Result) do
    Result[i] := item;
end;

{==============================================================================]
 <T2D.Create(item: VarType; size1D, size2D: Integer)>
 @action: Creates array with item where size is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}
class function T2D.Create(const item: TVar; const size1D: Integer = 1; const size2D: Integer = 1): T2DArr; overload; cdecl;
var
  i, j, s: Integer;
begin
  s := (Max(0, size2D) - 1);
  SetLength(Result, Max(0, size1D), (s + 1));
  for i := 0 to High(Result) do
    for j := 0 to s do
      Result[i][j] := item;
end;
