{$IFDEF HELPERS}
function Fit: Integer; overload;
function Fit(const aSize: Integer): Integer; overload;
function Fit(const aBounds: TRange): Integer; overload;
function Length: Integer; overload;
function Length(var lengths: TIntegerArray): Integer; overload;
function Size: Integer; overload;
function Size(var sizes: TIntegerArray): Integer; overload;
function Sized(var lengths: TIntegerArray): Int64; overload;
function Sized: Int64; overload;
function Total: Int64; overload;
function Population: Int64; overload;
function Census: Int64; overload;
function Inventory(var items: MArray): Int64; overload;
function Inventory: Int64; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Fit>
  @action: Returns array length.
  @note: Alternative.
[==============================================================================}
function M2DArrayHelper.Fit: Integer; overload;
begin
  Result := ((High(Self) - Low(Self)) + 1);
end;

{==============================================================================]
  <Fit>
  @action: Resizes the array to aSize (sets length safely).
  @note: Returns the length that was set to Self. Negative sizes are clamped to 0.
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
  else
    if (l > b.stop) then
      Result := b.stop
    else
      Result := l;	
  if (Result <> l) then
    SetLength(Self, Result);
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
{$ENDIF}