{$IFDEF HELPERS}
function Alloc(const sSize: Integer = 1): Integer; overload;
function Census: Int64; overload;
function Fit: Integer; overload;
function Fit(const aSize: Integer): Integer; overload;
function Fit(const aBounds: TRange): Integer; overload;
function Inventory(var items: MArray): Int64; overload;
function Inventory: Int64; overload;
function Length: Integer; overload;
function Length(var lengths: TIntegerArray): Integer; overload;
function Population: Int64; overload;
function SetSize(const sSize: Integer = 1): Integer; overload;
function SetSize(const sSize: Integer; const iCreated: MArray): Integer; overload;
function SetSize(const sSize: Integer; const iCreated: MType): Integer; overload;
function Size: Integer; overload;
function Size(var sizes: TIntegerArray): Integer; overload;
function Sized(var lengths: TIntegerArray): Int64; overload;
function Sized: Int64; overload;
function Total: Int64; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Alloc>
  @action: Allocates memory for the outer dimension (rows) of the 2D dynamic array up to the specified row size.
  @note: Clears the array if sSize <= 0. Returns the highest valid row index,
         which is (sSize - 1), rather than the total row count.
[==============================================================================}
function M2DArrayHelper.Alloc(const sSize: Integer = 1): Integer; overload;
begin
  Result := (Self.SetSize(sSize) - 1);
end;

{==============================================================================]
  <Census>
  @action: Returns actual Length for 2D array.
  @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
function M2DArrayHelper.Census: Int64; overload;
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
      Inc(e, Self[i].Size);
      Result := Result + (e - s);
    end;
  end;
end;

{==============================================================================]
  <Fit>
  @action: Calculates and returns the current row capacity (total span of elements) of the 2D dynamic array.
  @note: Accounts for lower and upper index bounds, returning 0 if the array is empty.
[==============================================================================}
function M2DArrayHelper.Fit: Integer; overload;
begin
  Result := ((High(Self) - Low(Self)) + 1);
end;

{==============================================================================]
  <Fit>
  @action: Resizes the 2D dynamic array's outer dimension to a specified size and returns the new size.
  @note: Guarantees the size is non-negative using Max(). Safely handles 0 or 
         negative inputs by clearing the array.
[==============================================================================}
function M2DArrayHelper.Fit(const aSize: Integer): Integer; overload;
begin
  Result := Max(0, aSize);
  SetLength(Self, Result);
end;

{==============================================================================]
  <Fit>
  @action: Resizes the array to fit within the specified range.
  @note:
    - Returns the final array length.
    - If current length is below b.start → array grows to b.start.
    - If current length is above b.stop → array shrinks to b.stop.
    - If current length is within the range → no change.
    - Negative lengths are clamped to 0.
[==============================================================================}
function M2DArrayHelper.Fit(const aBounds: TRange): Integer; overload;
var
  l: Integer;
  b: TRange;
begin
  l := Self.Length;
  b := aBounds.Normalize.ClampMin(0);
  if (l < b.start) then
    Result := b.start
  else if (l > b.stop) then
    Result := b.stop
  else
    Result := l;	
  if (Result <> l) then
    SetLength(Self, Result);
end;

{==============================================================================]
  <Inventory>
  @action: Returns actual Length for 2D array.
  @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
         Stores 2D array items as 1D to items.
[==============================================================================}
function M2DArrayHelper.Inventory(var items: MArray): Int64; overload;
var
  i, j: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Inc(Result, Self[i].Size);
  SetLength(items, Result);
  if (Result > 0) then
  for i := High(Self) downto 0 do
    for j := High(Self[i]) downto 0 do
      items[Result.Decrement] := Self[i][j];
  Result := items.Size;
end;

{==============================================================================]
  <Inventory>
  @action: Returns actual Length for 2D array.
  @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
function M2DArrayHelper.Inventory: Int64; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Inc(Result, Self[i].Size);
end;

{==============================================================================]
  <Length>
  @action: System.Length()
  @note: None.
[==============================================================================}
function M2DArrayHelper.Length: Integer; overload;
begin
  Result := System.Length(Self);
end;

{==============================================================================]
 <Length>
 @action: System.Length()
 @note: Stores Lengths of 2D part.
[==============================================================================}
function M2DArrayHelper.Length(var lengths: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Length;
  SetLength(lengths, Result);
  for i := 0 to (Result - 1) do
    lengths[i] := Self[i].Length;
end;

{==============================================================================]
  <Population>
  @action: Returns actual Length for 2D array.
  @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
function M2DArrayHelper.Population: Int64; overload;
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
    e := (s + Self[i].Size);
    Result := (Result + (e - s));
  end;
end;

{==============================================================================]
  <SetSize>
  @action: Resizes the 2D dynamic array to the specified number of elements.
  @note: If sSize is 0 or negative, the array is cleared. Existing data is 
         preserved if the array is expanded. Uses Math unit for Max().
		 By default sets size as 1!
[==============================================================================}
function M2DArrayHelper.SetSize(const sSize: Integer = 1): Integer; overload;
begin
  SetLength(Self, Max(0, sSize));
  Result := Self.Length;
end;

{==============================================================================]
  <SetSize>
  @action: Resizes the 2D array to a specified number of rows and initializes all newly allocated elements using a provided 1D prototype array.
  @note: Automatically matches the inner column dimension to the length of the prototype array.
[==============================================================================}
function M2DArrayHelper.SetSize(const sSize: Integer; const iCreated: MArray): Integer; overload;
var
  h, i, c, s: Integer;
begin
  s := Self.Length;
  h := High(iCreated);
  for i := s to (Self.SetSize(Max(0, sSize)) - 1) do
    for c := 0 to (Self[i].SetSize(h + 1) - 1) do
      Self[i][c] := iCreated[c];
  Result := Self.Length;
end;

{==============================================================================]
  <SetSize>
  @action: Resizes the 2D array to a specified number of rows and initializes each newly added row as a single-element array containing the provided value.
  @note: Leverages the base single-parameter SetSize method within the loop boundary evaluation.
[==============================================================================}
function M2DArrayHelper.SetSize(const sSize: Integer; const iCreated: MType): Integer; overload;
var
  i, s: Integer;
begin
  s := Self.Length;
  for i := s to (Self.SetSize(Max(0, sSize)) - 1) do
    Self[i] := [iCreated];
  Result := Self.Length;
end;

{==============================================================================]
  <Size>
  @action: System.Length()
  @note: None.
[==============================================================================}
function M2DArrayHelper.Size: Integer; overload;
begin
  Result := ((High(Self) - Low(Self)) + 1);
end;

{==============================================================================]
 <Size>
 @action: System.Length()
 @note: Stores Lengths of 2D part.
[==============================================================================}
function M2DArrayHelper.Size(var sizes: TIntegerArray): Integer; overload;
var
  i: Integer;
begin
  Result := Self.Size;
  SetLength(sizes, Result);
  for i := 0 to (Result - 1) do
    sizes[i] := Self[i].Size;
end;

{==============================================================================]
 <Sized>
 @action: Returns actual Length for 2D array. Stores Length's of 2D part, of the arr, to lengths variable.
 @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
function M2DArrayHelper.Sized(var lengths: TIntegerArray): Int64; overload;
var
  i: Integer;
begin
  Result := 0;
  SetLength(lengths, Self.Length);
  for i := 0 to High(Self) do
  begin
    lengths[i] := Self[i].Length;
    Result := (Result + lengths[i]);
  end;
end;

{==============================================================================]
  <Sized>
  @action: Returns actual Length for 2D array.
  @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
function M2DArrayHelper.Sized: Int64; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result.Increase(Self[i].Size);
end;

{==============================================================================]
  <Total>
  @action: Returns actual Length for 2D array.
  @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => 9.
[==============================================================================}
function M2DArrayHelper.Total: Int64; overload;
var
  a: MArray;
begin
  Result := 0;
  for a in Self do
    Result.Increase(a.Length);
end;
{$ENDIF}
