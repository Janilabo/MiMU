{$IFDEF HELPERS}
function Catalog: T2DIntegerArray; overload;
function Cataloged: T2DIntegerArray; overload;
function Catalogify: T2DIntegerArray; overload;
function Catalogment: T2DIntegerArray; overload;
function Catalogue: T2DIntegerArray; overload;
function Catalogued: T2DIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Catalog>
  @action: Returns a T2DIntegerArray where each row has been replaced by its 
           own index sequence (via Indexes) from that row's own length.
  @note: Uses a self-decrementing counter (r.Decrement) as both the loop 
         condition and the index into Result, walking backward from the 
         last row to the first.
[==============================================================================}
function M2DArrayHelper.Catalog: T2DIntegerArray; overload;
var
  r: Integer;
begin
  r := Result.SetSize(Self.Length);
  while (r.Decrement > -1) do
    Result[r] := Self[r].Indexes;
end;

{==============================================================================]
  <Cataloged>
  @action: Returns a T2DIntegerArray where each row has been replaced by its 
           own index sequence (via Indexes) from that row's own length.
  @note: Manually unrolls the fill loop by 4 rows per iteration, processing 
         the bulk of the array in 4-wide batches before a trailing loop 
         handles the remainder.
[==============================================================================}
function M2DArrayHelper.Cataloged: T2DIntegerArray; overload;
var
  i, l: Integer;
begin
  l := Result.SetSize(Self.Length);
  i := -4;
  while (i.Increment(4) <= (l - 4)) do
  begin
    Result[i] := Self[i].Indexes;
    Result[i + 1] := Self[i + 1].Indexes;
    Result[i + 2] := Self[i + 2].Indexes;
    Result[i + 3] := Self[i + 3].Indexes;
  end;
  for i := i to (l - 1) do
    Result[i] := Self[i].Indexes;
end;

{==============================================================================]
  <Catalogify>
  @action: Returns a T2DIntegerArray where each row has been replaced by its 
           own index sequence (via Indexes) from that row's own length.
  @note: Uses a pointer walk over Result rather than indexed assignment, 
         advancing P after each row is written.
[==============================================================================}
function M2DArrayHelper.Catalogify: T2DIntegerArray; overload;
var
  i: Integer;
  P: ^TIntegerArray;
begin;
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  P := @Result[0];
  for i := 0 to High(Result) do
  begin
    P^ := Self[i].Indexes;
    Inc(P);
  end;
end;

{==============================================================================]
  <Catalogment>
  @action: Returns a T2DIntegerArray where each row has been replaced by its 
           own index sequence (via Indexes) from that row's own length.
  @note: Constructs a TRange over the row bounds and iterates its start/stop 
         fields directly, rather than using a plain integer loop variable.
[==============================================================================}
function M2DArrayHelper.Catalogment: T2DIntegerArray; overload;
var
  r: TRange;
begin
  r := Self.Envelope;
  if (Result.SetSize(r.stop + 1) > 0) then
  repeat
    Result[r.start] := Self[r.start].Indexes;
  until (r.start.Increment > r.stop);
end;

{==============================================================================]
  <Catalogue>
  @action: Returns a T2DIntegerArray where each row has been replaced by its 
           own index sequence (via Indexes) from that row's own length.
  @note: Uses Result.Alloc to size and obtain the high bound in one step, 
         then fills forward via a plain ascending loop.
[==============================================================================}
function M2DArrayHelper.Catalogue: T2DIntegerArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Length) do
    Result[i] := Self[i].Indexes;
end;

{==============================================================================]
  <Catalogued>
  @action: Returns a T2DIntegerArray where each row has been replaced by its
           own index sequence (via Indexes) from that row's own length.
  @note: Walks two converging indices (l upward, r downward) simultaneously,
         writing both Result[l] and Result[r] each iteration.
[==============================================================================}
function M2DArrayHelper.Catalogued: T2DIntegerArray; overload;
var
  l, r: Integer;
begin
  r := Result.SetSize(Self.Length);
  l := -1;
  while (l.Increment <= r.Decrement) do
  begin
    Result[l] := Self[l].Indexes;
    Result[r] := Self[r].Indexes;
  end;
end;
{$ENDIF}
