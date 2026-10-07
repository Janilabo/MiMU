{$IFDEF METHODS}
function Batched(const batchSize: Integer = 2): T2DPointArray; overload;
{$ENDIF}

{$IFDEF HELPERS}
function Excised(const b: TBox): TBoxArray; overload;
function Partitum(const b: TBox): TBoxArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Batched>
  @action: Returns points in batches for memory-constrained environments.
  @note: Generator pattern, yields points in chunks.
[==============================================================================}
function TBox.Batched(const batchSize: Integer = 2): T2DPointArray; overload;
var
  p, i, h, v, b: Integer;
begin
  p := Self.Area;
  SetLength(Result, ((p + batchSize - 1) div batchSize));
  b := 0;
  for v := Self.Y1 to Self.Y2 do
    for h := Self.X1 to Self.X2 do
    begin
      i := (b mod BatchSize);
      if (i = 0) then
        SetLength(Result[b div batchSize], Min(batchSize, (p - b)));
      Result[b.Increase div batchSize][i] := Point(h, v);
    end;
end;

{==============================================================================]
  <Excised>
  @action: Returns Self with the area of b cut out, as non-overlapping boxes.
  @note: Not overlapping: returns [Self].
         Fully covered by b: returns an empty array.
         Otherwise: up to 4 pieces (top, bottom, left, right), all inside Self.
[==============================================================================}
function TBoxHelper.Excised(const b: TBox): TBoxArray; overload;
var
  l, h: Integer;
begin
  if not Self.Overlap(b) then
    Exit([Self]);
  SetLength(Result, 0);
  if (Self.Y1 < b.Y1) then
    Result.Supply(Self.X1, Self.Y1, Self.X2, (b.Y1 - 1));
  if (Self.Y2 > b.Y2) then
    Result.Supply(Self.X1, (b.Y2 + 1), Self.X2, Self.Y2);
  l := Max(Self.Y1, b.Y1);
  h := Min(Self.Y2, b.Y2);
  if (Self.X1 < b.X1) then
    Result.Supply(Self.X1, l, (b.X1 - 1), h);
  if (Self.X2 > b.X2) then
    Result.Supply((b.X2 + 1), l, Self.X2, h);
end;

{==============================================================================]
  <Partitum>
  @action: Cuts Self and b into non-overlapping boxes covering the same area.
  @note: Not overlapping: returns both as-is.
         One inside the other: returns the single outer box.
         Otherwise: returns Self whole + up to 4 pieces of b.
[==============================================================================}
function TBoxHelper.Partitum(const b: TBox): TBoxArray; overload;
var
  l, h: Integer;
begin
  if Self.Contains(b) then
    Exit([Self]);
  if b.Contains(Self) then
    Exit([b]);
  if not Self.Overlap(b) then
    Exit([Self, b]);
  Result := [Self];
  if (b.Y1 < Self.Y1) then
    Result.Supply(b.X1, b.Y1, b.X2, (Self.Y1 - 1));
  if (b.Y2 > Self.Y2) then
    Result.Supply(b.X1, (Self.Y2 + 1), b.X2, b.Y2);
  l := Max(b.Y1, Self.Y1);
  h := Min(b.Y2, Self.Y2);
  if (b.X1 < Self.X1) then
    Result.Supply(b.X1, l, (Self.X1 - 1), h);
  if (b.X2 > Self.X2) then
    Result.Supply((Self.X2 + 1), l, b.X2, h);
end;
{$ENDIF}
