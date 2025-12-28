{$IFDEF HELPERS}
function Flat: MArray; overload;
function Flatten: MArray; overload;
function Merge: MArray; overload;
function Merged: MArray; overload;
function TArray: MArray; overload;
function Unwrap: MArray; overload;
function To1D: MArray; overload;
function Linearize: MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Flat>
  @action: Merges 2D array to 1D.
  @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function M2DArrayHelper.Flat: MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    Result := Concat(Result, Self[i]);
end;

{==============================================================================]
  <Flatten>
  @action: Merges 2D array to 1D.
  @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function M2DArrayHelper.Flatten: MArray; overload;
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
  <To1D>
  @action: Merges 2D array to 1D.
  @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function M2DArrayHelper.To1D: MArray; overload;
var
  i, j, r: Integer;
  l: specialize TList<MType>;
begin
  l := specialize TList<MType>.Create;
  try
    for i := 0 to High(Self) do
      for j := 0 to High(Self[i]) do
        l.Add(Self[i][j]);
    SetLength(Result, l.Count);
    for r := 0 to (l.Count - 1) do
      Result[r] := l[r];
  finally
    l.Free;
  end;
end;

{==============================================================================]
  <Linearize>
  @action: Merges 2D array to 1D.
  @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function M2DArrayHelper.Linearize: MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    Result := (Result + Self[i]);
end;

{==============================================================================]
  <Merge>
  @action: Merges 2D array to 1D.
  @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function M2DArrayHelper.Merge: MArray; overload;
var
  i, j, l: Integer;
begin
  SetLength(Result, Self.Sized);
  l := Result.Length;
  if (l > 0) then
  for i := High(Self) downto 0 do
    for j := High(Self[i]) downto 0 do
      Result[l.Decrement] := Self[i][j];
end;

{==============================================================================]
  <Merged>
  @action: Merges 2D array to 1D.
  @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function M2DArrayHelper.Merged: MArray; overload;
var
  i, j, o, s: Integer;
begin
  SetLength(Result, 0);
  o := 0;
  for i := 0 to High(Self) do
  begin
    s := Self[i].Size;
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
  <TArray>
  @action: Merges 2D array to 1D.
  @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function M2DArrayHelper.TArray: MArray; overload;
var
  i, j, l: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    l := Result.Length;
    SetLength(Result, (l + Self[i].Size));
    for j := 0 to High(Self[i]) do
      Result[l + j] := Self[i][j];
  end;
end;

{==============================================================================]
  <Unwrap>
  @action: Merges 2D array to 1D.
  @note: For example [[1,2],[],[3,4,5],[],[],[6],[7,8],[],[9]] => [1,2,3,4,5,6,7,8,9].
[==============================================================================}
function M2DArrayHelper.Unwrap: MArray; overload;
var
  i, j: Integer;
begin
  Result := [];
  for i := 0 to High(Self) do
    for j := 0 to High(Self[i]) do
      Result := (Result + [Self[i][j]]);
end;
{$ENDIF}