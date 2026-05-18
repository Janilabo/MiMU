{$IFDEF METHODS}
function Any: TPoint; overload;
function Mixed(const mixings: Integer = 1): TPointArray; overload;
function Shake(const shakes: Integer = 1): TPointArray; overload;
function Shuffle(const shuffles: Integer = 1): TPointArray; overload;
function Shuffled: TPointArray; overload;
function Some: TPointArray; overload;
function Some(const amount: Integer): TPointArray; overload;
function Stepped(const sStep: Integer = 1): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Any>
  @action: Returns random TBox point.
  @note: None.
[==============================================================================}
function TBox.Any: TPoint; overload;
begin
  Result := Point((Self.X1 + Random(Self.Width)), (Self.X1 + Random(Self.Height)));
end;

{==============================================================================]
  <Mixed>
  @action: Returns TBox randomly mixed as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Mixed(const mixings: Integer = 1): TPointArray; overload;
var
  i, m: Integer;
begin
  Result := Self.Points;
  if (Result.Size > 1) then
  for m := 1 to mixings do
    for i := 0 to High(Result) do
      Swap(Result[Random(Result.Size)], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <Shake>
  @action: Returns TBox randomly shaked as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Shake(const shakes: Integer = 1): TPointArray; overload;
var
  i, s: Integer;
begin
  Result := Self.Points;
  if (Result.Size > 1) then
  for s := 1 to shakes do
    for i := 0 to Random(Result.Size) do
      Swap(Result[i], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <Shuffle>
  @action: Returns TBox randomly shuffled as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Shuffle(const shuffles: Integer = 1): TPointArray; overload;
var
  i, s: Integer;
begin
  Result := Self.Points;
  if (Result.Size > 1) then
  for s := 1 to shuffles do
    for i := 0 to High(Result) do
      Swap(Result[i], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <Shuffled>
  @action: Generates an array containing every coordinate point within the TBox, arranged in a randomized (shuffled) order.
  @note: Creates a flat index array, randomizes it using a Fisher-Yates shuffle variant via an `Exchange` helper,
         and then maps those randomized indices back to 2D TBox coordinates.
[==============================================================================}
function TBox.Shuffled: TPointArray; overload;
var
  s: TIntegerArray;
  i, w: Integer;
begin
  w := Self.Width;
  SetLength(s, (w * Self.Height));
  for i := 0 to High(s) do
    s[i] := i;
  for i := High(s) downto 1 do
    s.Exchange(i, Random(i + 1));
  SetLength(Result, s.Length);
  for i := 0 to High(s) do
    Result[i] := Point((Self.X1 + (s[i] mod w)), (Self.Y1 + (s[i] div w)));
end;

{==============================================================================]
  <Some>
  @action: Returns random amount of random TBox points.
  @note: Does not return empty arrays.
[==============================================================================}
function TBox.Some: TPointArray; overload;
begin
  Result := Copy(Self.Shuffle, 0, Max(Random(Self.Area + 1), 1));
end;

{==============================================================================]
  <Some>
  @action: Returns random amount of random TBox points.
  @note: Does not return empty arrays.
[==============================================================================}
function TBox.Some(const amount: Integer): TPointArray; overload;
begin
  Result := Copy(Self.Shuffle, 0, Max(1, Min(amount, Self.Area)));
end;

{==============================================================================]
  <Stepped>
  @action: Returns a sampled subset of points (e.g., every Nth point).
  @note: Useful for large boxes when full enumeration isn't needed.
[==============================================================================}
function TBox.Stepped(const sStep: Integer = 1): TPointArray; overload;
var
  h, v, r, s: Integer;
begin
  s := Max(1, sStep);
  SetLength(Result, ((Self.Area + s - 1) div s));
  r := 0;
  v := Self.Y1;
  while (v <= Self.Y2) do
  begin
    h := Self.X1;
    while (h <= Self.X2) do
      Result[r.Increase] := Point(h.Increase(s), v);
    Inc(v, s);
  end;
  SetLength(Result, r);
end;
{$ENDIF}
