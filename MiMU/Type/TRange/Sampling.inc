{$IFDEF METHODS}
function Any: Integer; cdecl;
function Mixed(const mixings: Integer = 1): TIntegerArray; cdecl;  
function Sample(const sSize: Integer): TIntegerArray; overload; cdecl;
function Shake(const shakes: Integer = 1): TIntegerArray; cdecl;
function Shuffle(const shuffles: Integer = 1): TIntegerArray; cdecl;
function Some: TIntegerArray; overload; cdecl;
function Some(const amount: Integer): TIntegerArray; overload; cdecl;
function Zigzag(const zAscending: Boolean = True): TIntegerArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Any>
  @action: Returns random TRange item.
  @note: None.
[==============================================================================}
function TRange.Any: Integer; cdecl;
begin
  Result := ((Self.Start + Random(Self.Size)) * IfThen(Self.Ascending, 1, -1));
end;

{==============================================================================]
  <Mixed>
  @action: Returns TRange randomly mixed as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Mixed(const mixings: Integer = 1): TIntegerArray; cdecl;
var
  i, s, r: Integer;
begin
  s := IfThen(Self.Ascending, 1, -1);
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := ((Self.Start + i) * s);
  if (Result.Size > 1) then
  for r := 1 to mixings do
    for i := High(Result) downto 0 do
      Swap(Result[Random(Result.Size)], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <Sample>
  @action: Return evenly spaced integer samples across the range.
  @note: Always includes both start and stop values of the range (if sSize > 1).
         Uses rounding to map floating step positions to integers.
         If sSize = 1, returns only the start value.
[==============================================================================}
function TRange.Sample(const sSize: Integer): TIntegerArray; overload; cdecl;
var
  i: Integer;
  s: Double;
begin
  if (sSize < 1) then
    Exit([]);
  SetLength(Result, sSize);
  s := (Self.Delta / (sSize - 1));
  for i := 0 to (sSize - 1) do
    Result[i] := Round(Self.start + (i * s));
end;

{==============================================================================]
  <Shake>
  @action: Returns TRange randomly shaked as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Shake(const shakes: Integer = 1): TIntegerArray; cdecl;
var
  i, s, r: Integer;
begin
  s := IfThen(Self.Ascending, 1, -1);
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := ((Self.Start + i) * s);
  if (Result.Size > 1) then
  for r := 1 to shakes do
    for i := Random(Result.Size) downto 0 do
      Swap(Result[i], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <Shuffle>
  @action: Returns TRange randomly shuffled as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Shuffle(const shuffles: Integer = 1): TIntegerArray; cdecl;
var
  i, s, r: Integer;
begin
  s := IfThen(Self.Ascending, 1, -1);
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := ((Self.Start + i) * s);
  if (Result.Size > 1) then
  for r := 1 to shuffles do
    for i := High(Result) downto 0 do
      Swap(Result[i], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <Some>
  @action: Returns random amount of random TRange items.
  @note: Does not return empty arrays.
[==============================================================================}
function TRange.Some: TIntegerArray; overload; cdecl;
begin
  Result := Copy(Self.Shuffle, 0, Max(Random(Self.Size + 1), 1))
end;

{==============================================================================]
  <Some>
  @action: Returns random amount of random TRange items.
  @note: Does not return empty arrays.
[==============================================================================}
function TRange.Some(const amount: Integer): TIntegerArray; overload; cdecl;
begin
  Result := Copy(Self.Shuffle, 0, Max(1, Min(amount, Self.Size)));
end;

{==============================================================================]
  <Zigzag>
  @action: Returns the integer values of the range in an alternating “zig-zag” order,
           taking elements from the start and end of the range alternately.
           For example, for a range 1..5, the result is [1,5,2,4,3].
  @note:   Works for ascending and descending ranges. 
           If the range contains a single value, returns an array with that single value.
           Internally uses two arrays (ascending and reversed) to construct the pattern.
[==============================================================================}
function TRange.Zigzag(const zAscending: Boolean = True): TIntegerArray; overload; cdecl;
var
  a, d: TIntegerArray;
  l, i, j, r, z: Integer;
begin
  if (Self.start = Self.stop) then
    Exit([Self.start]);
  a := Self.ToArray;
  d := a.Reversed;
  l := a.Length;
  SetLength(Result, l);
  i := 0;
  j := 0;
  r := -1;
  z := IfThen(zAscending, 0, 1);
  while ((i + j) < l) do
    if ((r.Increment mod 2) = z) then
      Result[r] := a[i.Increase]
    else
      Result[r] := d[j.Increase];
end;
{$ENDIF}