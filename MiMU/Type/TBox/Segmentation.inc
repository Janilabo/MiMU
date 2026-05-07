{$IFDEF METHODS}
function Batched(const batchSize: Integer = 2): T2DPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Batched>
  @action: Returns points in batches for memory-constrained environments.
  @note: Generator pattern, yields points in chunks.
[==============================================================================}
function TBox.Batched(const batchSize: Integer = 2): T2DPointArray; overload;
var
  p, i, j, x, y, b: Integer;
begin
  p := Self.Area;
  SetLength(Result, ((p + batchSize - 1) div batchSize));
  b := 0;
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
    begin
      j := (b mod BatchSize);
      if (j = 0) then
        SetLength(Result[b div batchSize], Min(batchSize, (p - b)));
      Result[b.Increase div batchSize][j] := Point(x, y);
    end;
end;
{$ENDIF}
