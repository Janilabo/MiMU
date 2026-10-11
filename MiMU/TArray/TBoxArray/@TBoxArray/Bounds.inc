{$IFDEF HELPERS}
function Boundaries: TBox; overload;
function Bounds: TBox; overload;
function Boundz: TBox; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Boundaries>
  @action: Returns bounds of all boxes in array
  @note: None.
[==============================================================================}
function TBoxArrayHelper.Boundaries: TBox; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  Result := Self[0];
  for i := 1 to High(Self) do
  begin
    if (Result.X1 > Self[i].X1) then
      Result.X1 := Self[i].X1;
    if (Result.Y1 > Self[i].Y1) then
      Result.Y1 := Self[i].Y1;
    if (Result.X2 < Self[i].X2) then
      Result.X2 := Self[i].X2;
    if (Result.Y2 < Self[i].Y2) then
      Result.Y2 := Self[i].Y2;
  end;
end;

{==============================================================================]
  <Bounds>
  @action: Returns bounds of all boxes in array
  @note: None.
[==============================================================================}
function TBoxArrayHelper.Bounds: TBox; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  Result := Self[0];
  for i := 1 to High(Self) do
  begin
    Result.X1 := Min(Self[i].X1, Result.X1);
    Result.Y1 := Min(Self[i].Y1, Result.Y1);
    Result.X2 := Max(Self[i].X2, Result.X2);
    Result.Y2 := Max(Self[i].Y2, Result.Y2);
  end;
end;

{==============================================================================
  <Boundz>
  @action: Returns bounds of all boxes in array using pointer arithmetic
  @note: Fast alternative.
[==============================================================================}
function TBoxArrayHelper.Boundz: TBox; overload;
var
  p, e: PBox;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  p := @Self[0];
  e := (p + Self.Length);
  Result := p^;
  Inc(p);
  while (p < e) do
  begin
    Result.X1 := Min(p^.X1, Result.X1);
    Result.Y1 := Min(p^.Y1, Result.Y1);
    Result.X2 := Max(p^.X2, Result.X2);
    Result.Y2 := Max(p^.Y2, Result.Y2);
    Inc(p);
  end;
end;
{$ENDIF}
