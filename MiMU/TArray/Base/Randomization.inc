{$IFDEF HELPERS}
function Any(const null: MType): MType; overload; cdecl;
function Any: MType; overload; cdecl;
function Disordered: MArray; overload; cdecl;
function Mix(const mixings: Integer = 1): Boolean; overload; cdecl;
function Mixed(const mixings: Integer = 1): MArray; overload; cdecl;
function Randomized: MArray; overload; cdecl;
function Scramble(const swaps: Integer = -1): MArray; overload; cdecl;
function Shake(const shakes: Integer = 1): MArray; overload; cdecl;
function Shuffle(const shuffles: Integer = 1): MArray; overload; cdecl;
function Some: MArray; overload; cdecl;
function Some(const amount: Integer): MArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Any>
  @action: Returns random array item from Self.
  @note: Returns null with empty arrays.
[==============================================================================}
function MArrayHelper.Any(const null: MType): MType; overload; cdecl;
begin
  if Self.Empty then
    Exit(null);
  Result := Self[Random(Self.Size)];
end;

{==============================================================================]
  <Any>
  @action: Returns random array item from Self.
  @note: Make sure array has at least 1 item! This one is unsafe and returns error else.
[==============================================================================}
function MArrayHelper.Any: MType; overload; cdecl;
begin
  Result := Self[Low(Self) + Random(Self.Size)];
end;

{==============================================================================]
  <Disordered>
  @action: Returns array with randomized order (disorder)
  @note: [1,2,3] => [1,3,2] | [2,1,3] | [2,3,1] | [3,2,1] ...
[==============================================================================}
function MArrayHelper.Disordered: MArray; overload; cdecl;
var
  m: TBooleanArray;
  i, r, l: Integer;
begin
  l := Self.Length;
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
  <Mix>
  @action: Ramdomizes array with custom mixings.
  @note: None.
[==============================================================================}
function MArrayHelper.Mix(const mixings: Integer = 1): Boolean; overload; cdecl;
var
  l, i, m: Integer;
begin
  Result := ((mixings > 0) and Self.Populated);
  if not Result then
    Exit;
  l := Self.Length;
  if (l > 1) then
  for m := 1 to mixings do
    for i := 0 to (l - 1) do
      Exchange(Random(l), Random(l));
end;

{==============================================================================]
  <Mixed>
  @action: Returns ramdomized array by mixing.
  @note: None.
[==============================================================================}
function MArrayHelper.Mixed(const mixings: Integer = 1): MArray; overload; cdecl;
var
  l, i, m: Integer;
begin
  l := Self.Length;
  Result := Self.Copy;
  if (l > 1) then
  for m := 1 to mixings do
    for i := 0 to (l - 1) do
      Swap(Result[Random(l)], Result[Random(l)]);
end;

{==============================================================================]
  <Randomized>
  @action: Returns randomized copy of array
  @note: None.
[==============================================================================}
function MArrayHelper.Randomized: MArray; overload; cdecl;
var
  s, l, r: Integer;
  i: TIntegerArray;
begin
  l := Self.Length;
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
  <Scramble>
  @action: Returns scrambled array, that is randomized with offset and swapping. 
  @note: Supports custom swaps.
[==============================================================================}
function MArrayHelper.Scramble(const swaps: Integer = -1): MArray; overload; cdecl;
var
  o, i, l, s: Integer;
begin
  l := Self.Length;
  o := Random(l);
  s := IfThen((swaps < 0), l, swaps);
  Result := Self.Copy(o, (l - o)) + Self.Copy(0, o);
  for i := 1 to s do
    Swap(Result[Random(l)], Result[Random(l)]);
end;

{==============================================================================]
  <Shake>
  @action: Returns array as randomized with shaking it.
  @note: None.
[==============================================================================}
function MArrayHelper.Shake(const shakes: Integer = 1): MArray; overload; cdecl;
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
  <Shuffle>
  @action: Returns array as randomized with shuffling it.
  @note: None.
[==============================================================================}
function MArrayHelper.Shuffle(const shuffles: Integer = 1): MArray; overload; cdecl;
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
  <Some>
  @action: Returns random amount of random array items from Self.
  @note: Does not return empty arrays.
[==============================================================================}
function MArrayHelper.Some: MArray; overload; cdecl;
begin
  Result := Self.Shuffle.Copy(0, Max(Random(Self.Size + 1), 1));
end;

{==============================================================================]
  <Some>
  @action: Returns amount of random array items from Self.
  @note: Does not return empty arrays.
[==============================================================================}
function MArrayHelper.Some(const amount: Integer): MArray; overload; cdecl;
begin
  Result := Self.Shuffle.Copy(0, Max(1, Min(amount, Self.Size)));
end;
{$ENDIF}