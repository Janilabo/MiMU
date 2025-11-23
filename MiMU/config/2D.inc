{$I Defines.inc}

{$IFDEF INTERFACE}
{$ENDIF}

{$IFDEF HELPERS}
function Blank: Boolean; overload;
function Empty: Boolean; overload;
function Flat: TArr; overload;
function Flatten: TArr; overload;
function Irregular: Boolean; overload;
function Jagged: Boolean; overload;
function Merge: TArr; overload;
function Merged: TArr; overload;
function Ragged: Boolean; overload;
function Fit: Integer; overload;
function Fit(const aSize: Integer): Integer; overload;
function Fit(const aBounds: TRange): Integer; overload;
function Size(var lengths: TIntegerArray): Int64; overload;
function Size: Int64; overload;
function Total: Int64; overload;
function Population: Int64; overload;
function Census: Int64; overload;
function Inventory(var items: TArr): Int64; overload;
function Inventory: Int64; overload;
function TArray: TArr; overload;
function Unwrap: TArr; overload;
function Kill: Integer; overload;
function Kill(const k2D: TIntegerArray): Int64; overload;
function Free: Int64; overload;
function Recreate(const arrSize: Integer): Boolean; overload;
function Reset: Int64; overload;
function Reverse: Boolean; overload;
function Reversed: T2DArr; overload;
function Reversify: Boolean; overload;
function Destroy: Int64; overload;
function Pull: T2DArr; overload;
function To1D: TArr; overload;
function Linearize: TArr; overload;
function Squeeze: Integer; overload;
function Squeezed: T2DArr; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
 <arr.Blank(parts: Integer): T2DArray>
 @action: Returns true if array is blank (no inventory, only empty indexes of []).
 @note: Blank array could be for example [[], [], []]. Returns false if array contains any items.
        NOTE: Returns false if array is empty (1D Length = 0)!
 [==============================================================================}
function H2DArr.Blank: Boolean; overload;
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
function H2DArr.Empty: Boolean; overload;
begin
  Result := (Length(Self) = 0);
end;

{==============================================================================]
 <arr.Flat: TArray>
 @action: Merges 2D array to 1D.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function H2DArr.Flat: TArr; overload;
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
function H2DArr.Flatten: TArr; overload;
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
function H2DArr.To1D: TArr; overload;
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
function H2DArr.Linearize: TArr; overload;
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
function H2DArr.Irregular: Boolean; overload;
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
function H2DArr.Jagged: Boolean; overload;
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
function H2DArr.Merge: TArr; overload;
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
function H2DArr.Merged: TArr; overload;
var
  i, j, o, s: Integer;
begin
  SetLength(Result, 0);
  o := 0;
  for i := 0 to High(Self) do
  begin
    s := Length(Self[i]);
    if (s > 0) then
    begin
      SetLength(Result, (o + s));
      for j := 0 to (s - 1) do
        Result[o + j] := Self[i][j];
      Inc(o, s);
    end;
  end;
end;

{==============================================================================]
 <arr.Ragged: Boolean>
 @action: Returns true if array contains arrays with different lengths (array not symmetrict)
 @note: [[1,2],[3,4],[5,6]] = False | [[1,2],[3],[4,5,6]] = True
[==============================================================================}
function H2DArr.Ragged: Boolean; overload;
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
function H2DArr.Fit: Integer; overload;
begin
  Result := ((High(Self) - Low(Self)) + 1);
end;

{==============================================================================]
 <arr.Fit: Integer>
  @action: Resizes the array to aSize (sets length safely).
  @note: Returns the length that was set to Self. Negative sizes are clamped to 0.
[==============================================================================}
function H2DArr.Fit(const aSize: Integer): Integer; overload;
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
function H2DArr.Fit(const aBounds: TRange): Integer; overload;
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
function H2DArr.Size(var lengths: TIntegerArray): Int64; overload;
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
function H2DArr.Size: Int64; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result.Increase(Length(Self[i]));
end;

{==============================================================================]
 <arr.Total: Int64>
 @action: Returns actual Length for 2D array.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
function H2DArr.Total: Int64; overload;
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
function H2DArr.Population: Int64; overload;
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
function H2DArr.Inventory(var items: TArr): Int64; overload;
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
function H2DArr.Inventory: Int64; overload;
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
function H2DArr.Census: Int64; overload;
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
function H2DArr.TArray: TArr; overload;
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
function H2DArr.Unwrap: TArr; overload;
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
function H2DArr.Kill: Integer; overload;
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
function H2DArr.Kill(const k2D: TIntegerArray): Int64; overload;
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
function H2DArr.Destroy: Int64; overload;
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
function H2DArr.Free: Int64; overload;
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
function H2DArr.Recreate(const arrSize: Integer): Boolean; overload;
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
function H2DArr.Reset: Int64; overload;
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
 <arr2d.Reverse>
  @action: Reverses the 2D array in place.
  @note: Returns True only if the array contained 2 or more elements.
         Returns False if Length < 2 (no operation performed).
[==============================================================================}
function H2DArr.Reverse: Boolean; overload;
var
  r: TRange;
begin
  Result := (Length(Self) > 1);
  if not Result then
    Exit;
  r.create(0, High(Self));
  while (r.start < r.stop) do
    Self[r.start.Increase].Swapped(Self[r.stop.Decrease]);
end;

{==============================================================================]
 <arr.Reversify>
  @action: Reverses the order of elements in a 2D array.
           Works by creating a temporary array and copying elements in reverse order.
  @note: - The operation modifies Self in place.
         - Returns True if the array had 2 or more elements (reversal performed).
         - Returns False if the array had 0 or 1 element (nothing changed).
[==============================================================================}
function H2DArr.Reversed: T2DArr; overload;
var
  i, l: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := Self[(l - 1) - i];
end;

{==============================================================================]
 <arr.Reversify>
  @action: Reverses the order of elements in a 2D array.
           Works by creating a temporary array and copying elements in reverse order.
  @note: - The operation modifies Self in place.
         - Returns True if the array had 2 or more elements (reversal performed).
         - Returns False if the array had 0 or 1 element (nothing changed).
[==============================================================================}
function H2DArr.Reversify: Boolean; overload;
var
  s: T2DArr;
  i, l: Integer;
begin
  l := Length(Self);
  Result := (l > 1);
  if not Result then
    Exit;
  SetLength(s, l);
  for i := 0 to (l - 1) do
    s[i] := Self[(l - 1) - i];
  Self := s;
end;

{==============================================================================]
 <arr.Pull: T2DArr>
 @action: Returns the contents of the array and leaves it empty.
 @note: After calling Pull, Self.Length = 0.
[==============================================================================}
function H2DArr.Pull: T2DArr; overload;
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
 <arr.Squeeze>
 @action: Removes empty subarrays from the current 2D point array (in place).
 @note: Returns the number of removed (empty) subarrays; the array itself is resized.
[==============================================================================}
function H2DArr.Squeeze: Integer; overload;
var
  i, r, l: Integer;
begin
  l := Length(Self);
  r := 0;
  for i := 0 to High(Self) do
    if (Length(Self[i]) > 0) then
      Self[r.Increase] := Self[i];
  Result := (l - r);
  if (Result > 0) then
    SetLength(Self, r);
end;

{==============================================================================]
 <arr.Squeezed>
 @action: Creates and returns a copy of the array with all empty subarrays removed.
 @note: The original array remains unchanged; the result is the squeezed copy.
[==============================================================================}
function H2DArr.Squeezed: T2DArr; overload;
var
  i, r: Integer;
begin
  SetLength(Result, Length(Self));
  if Result.Empty then
    Exit;
  r := 0;
  for i := 0 to High(Self) do
    if (Length(Self[i]) > 0) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
 <T2D.Create(item: VarType; size1D, size2D: Integer)>
 @action: Creates array with item where size is length of the array.
 @note: item is placed on every index in result.
[==============================================================================}
class function T2D.Create(const item: TVar; const size1D: Integer = 1; const size2D: Integer = 1): T2DArr; overload;
var
  i, j, s: Integer;
begin
  s := (Max(0, size2D) - 1);
  SetLength(Result, Max(0, size1D), (s + 1));
  for i := 0 to High(Result) do
    for j := 0 to s do
      Result[i][j] := item;
end;
{$ENDIF}