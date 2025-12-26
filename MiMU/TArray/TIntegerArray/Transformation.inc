{$IFDEF HELPERS}
function Reflected: TIntegerArray; overload;
function Reflect: Integer; overload;
function Invert: TIntegerArray;
function Inverted(const arrBounds: TRange): TIntegerArray; overload;
function Inverted: TIntegerArray; overload;
function Inverse(const arrBounds: TRange): TIntegerArray; overload;
function Inverse: TIntegerArray; overload;
function Mirror: Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Reflect>
  @action: Returns reversed array
  @note: None.
[==============================================================================}
function TIntegerArrayHelper.Reflected: TIntegerArray; overload;
var
  i: Integer;
  s: SizeInt;
begin
  SetLength(Result, Self.Size);
  s := SizeOf(Integer);
  for i := 0 to High(Self) do
    Move(Self[High(Self) - i], Result[i], s);
end;

{==============================================================================]
  <Reflect>
  @action: Reverses array.
  @note: Returns Length(Self)
[==============================================================================}
function TIntegerArrayHelper.Reflect: Integer; overload;
var
  r: TRange;
  s: SizeInt;
  b: array of Byte;
  x, y: PByte;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  s := SizeOf(Integer);
  SetLength(b, s);
  r.Create(-1, Result);
  x := PByte(@Self[r.start + 1]);
  y := PByte(@Self[r.stop - 1]);
  while (r.start.Increment < r.stop.Decrement) do
  begin
    Move(x^, b[0], s);
    Move(y^, x^, s);
    Move(b[0], y^, s);
    Inc(x, s);
    Dec(y, s);
  end;
end;

{==============================================================================]
  <Invert>
  @action: Returns inverted arr.
  @note: Arr = [0,2,4,6,8,10] => Result := [1, 3, 5, 7, 9]
[==============================================================================}
function TIntegerArrayHelper.Invert: TIntegerArray;
var
  c, l, i, x, r: Integer;
  b: TBooleanArray;
  a: TRange;
begin
  r := 0;
  if Self.Exists then
  begin
    a := Self.Bounds;
    if (a.start <> a.stop) then
    begin
      c := 0;
      l := a.Size;
      b.Create(l, False);
      for x := 0 to High(Self) do
        if b[Self[x] - a.start].Enable then
          Inc(c);
      SetLength(Result, (l - c));
      if (Result.Size > 0) then
      for i := 0 to (l - 1) do
        if not b[i] then
          Result[r.Increase] := (i + a.start);
      SetLength(b, 0);
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Inverted>
  @action: Returns inverted arr.
  @note: Arr = [0,2,4,6,8,10] => Result := [1, 3, 5, 7, 9]
         Supports custom bounds!
[==============================================================================}
function TIntegerArrayHelper.Inverted(const arrBounds: TRange): TIntegerArray; overload;
var
  i, r: Integer;
  b: TRange;
begin
  b := arrBounds.Normalize;
  SetLength(Result, b.Size);
  r := 0;
  for i := b.Start to b.Stop do
    if not Self.Contains(i) then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;

function TIntegerArrayHelper.Inverted: TIntegerArray; overload;
begin
  Result := Self.Inverted(Self.Bounds);
end;

{==============================================================================]
  <Inverse>
  @action: Returns inverted arr.
  @note: Arr = [0,2,4,6,8,10] => Result := [1, 3, 5, 7, 9]
         Supports custom bounds!
[==============================================================================}
function TIntegerArrayHelper.Inverse(const arrBounds: TRange): TIntegerArray; overload;
var
  l, i: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  r := arrBounds.Normalize;
  b.Create(arrBounds.Size, False);
  for i := 0 to High(Self) do
    if not ((Self[i] < r.start) or (Self[i] > r.stop)) then
      b[Self[i] - r.start] := True;
  l := 0;
  SetLength(Result, b.Size);
  for i := r.start to r.stop do
    if not b[i - r.start] then
      Result[l.Increase] := i;
  SetLength(Result, l);
end;

function TIntegerArrayHelper.Inverse: TIntegerArray; overload;
begin
  if (Self.Size > 1) then
    Result := Self.Inverse(Self.Bounds)
  else
    SetLength(Result, 0);
end;

{==============================================================================]
 <Mirror>
 @action: Mirrors arr
 @note: None.
[==============================================================================}
function TIntegerArrayHelper.Mirror: Boolean;
var
  i, l: Integer;
begin
  l := Self.Length;
  Result := (l > 1);
  if not Result then
    Exit;
  i := -1;
  while (i.Increment < l.Decrement) do
  begin
    Self[i] := (Self[i] xor Self[l]);
    Self[l] := (Self[i] xor Self[l]);
    Self[i] := (Self[i] xor Self[l]);
  end;
end;
{$ENDIF}
