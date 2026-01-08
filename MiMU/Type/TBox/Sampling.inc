{$IFDEF METHODS}
function Any: TPoint; cdecl;
function Mixed(const mixings: Integer = 1): TPointArray; cdecl;
function Shake(const shakes: Integer = 1): TPointArray; cdecl;
function Shuffle(const shuffles: Integer = 1): TPointArray; cdecl;
function Some: TPointArray; overload; cdecl;
function Some(const amount: Integer): TPointArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Any>
  @action: Returns random TBox point.
  @note: None.
[==============================================================================}
function TBox.Any: TPoint; cdecl;
begin
  Result := Point((Self.X1 + Random(Self.Width)), (Self.X1 + Random(Self.Height)));
end;

{==============================================================================]
  <Mixed>
  @action: Returns TBox randomly mixed as TPointArray.
  @note: None.
[==============================================================================}
function TBox.Mixed(const mixings: Integer = 1): TPointArray; cdecl;
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
function TBox.Shake(const shakes: Integer = 1): TPointArray; cdecl;
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
function TBox.Shuffle(const shuffles: Integer = 1): TPointArray; cdecl;
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
  <Some>
  @action: Returns random amount of random TBox points.
  @note: Does not return empty arrays.
[==============================================================================}
function TBox.Some: TPointArray; overload; cdecl;
begin
  Result := Copy(Self.Shuffle, 0, Max(Random(Self.Area + 1), 1));
end;

{==============================================================================]
  <Some>
  @action: Returns random amount of random TBox points.
  @note: Does not return empty arrays.
[==============================================================================}
function TBox.Some(const amount: Integer): TPointArray; overload; cdecl;
begin
  Result := Copy(Self.Shuffle, 0, Max(1, Min(amount, Self.Area)));
end;
{$ENDIF}