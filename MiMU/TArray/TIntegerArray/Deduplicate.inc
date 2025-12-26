{$IFDEF HELPERS}
function Undupe: TIntegerArray;
function Unduped: TIntegerArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Undupe>
  @action: Removes duplicates from array arr and returns the count of deleted items.
  @note: Not recommended with very large arrays
[==============================================================================}
function TIntegerArrayHelper.Undupe: TIntegerArray;
begin
  Result := Self.Copy;
  TIA.Unique(Result);
end;

{==============================================================================]
  <Unduped>
  @action: Removes duplicates from array arr and returns it.
  @note: Not recommended with very large arrays
[==============================================================================}
function TIntegerArrayHelper.Unduped: TIntegerArray;
var
  i, l: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  l := 0;
  if Self.Exists then
  begin
    SetLength(Result, Self.Size);
    r := Self.Bounds;
	b.Create(r.Size, False);
    for i := 0 to High(Self) do
      if b[Self[i] - r.start].Enable then
        Result[l.Increase] := Self[i];
    SetLength(b, 0);
  end;
  SetLength(Result, l);
end;
{$ENDIF}
