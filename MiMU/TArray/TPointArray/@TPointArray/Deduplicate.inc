{$IFDEF HELPERS}
function Undupe: TPointArray;
function Unduped: TPointArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Undupe>
  @action: Removes duplicates from arr.
  @note: Returns number of duplicate items that were removed from arr.
[==============================================================================}
function TPointArrayHelper.Undupe: TPointArray;
begin
  Result := Self.Copy;
  CPointArray.Unique(Result);
end;

{==============================================================================]
  <Unduped>
  @action: Returns arr without duplicates.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Unduped: TPointArray;
var
  i, r, w, h: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  r := 0;
  if Self.Exists then
  begin
    b := Self.Bounds(w, h);
    m := T2D.Create(False, w, h);
    SetLength(Result, Self.Size);
    for i := 0 to High(Self) do
      if m[Self[i].X - b.X1][Self[i].Y - b.Y1].Enable then
        Result[r.Increase] := Self[i];
    SetLength(m, 0);
  end;
  SetLength(Result, r);
end;
{$ENDIF}
