{$IFDEF HELPERS}
function Extract(const aBox: TBox): TPointArray; overload;
function Filter(const aBox: TBox): TPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <FilterBox>
  @action: Extracts all points from the TPointArray that lie inside aBox.
  @note: Bounds are inclusive. Preserves original order.
[==============================================================================}
function TPointArrayHelper.Extract(const aBox: TBox): TPointArray; overload;
var
  i, r, s: Integer;
begin
  r := 0;
  if (Self.Length > 0) then
  for i := 0 to Result.Alloc(Self.Length) do
    if ((Self[i].X >= aBox.X1) and (Self[i].X <= aBox.X2) and (Self[i].Y >= aBox.Y1) and (Self[i].Y <= aBox.Y2)) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;

{==============================================================================]
  <Filter>
  @action: Removes all points from the TPointArray that lie inside aBox (keeps points outside).
  @note: Bounds are inclusive. Preserves original order.
[==============================================================================}
function TPointArrayHelper.Filter(const aBox: TBox): TPointArray; overload;
var
  i, r, s: Integer;
begin
  r := 0;
  if (Self.Length > 0) then
  for i := 0 to Result.Alloc(Self.Length) do
    if not ((Self[i].X >= aBox.X1) and (Self[i].X <= aBox.X2) and (Self[i].Y >= aBox.Y1) and (Self[i].Y <= aBox.Y2)) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;
{$ENDIF}
