{$IFDEF HELPERS}
function Gaps: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function TRangeArrayHelper.Gaps: TRangeArray; overload;
var
  i, g: Integer;
  n: TRangeArray;
  a, b: Integer;
  procedure SortNormRanges(var r: TRangeArray);
  var
    a, b: Integer;
  begin
    for a := 0 to (High(r) - 1) do
      for b := (a + 1) to High(r) do
        if (r[a].start > r[b].start) then
	  Swap(r[a], r[b])
  end;
begin
  g := 0;
  if (Self.Size > 1) then
  begin
    SetLength(n, Self.Size);
    n := Self.Normalized;
    SortNormRanges(n);
    SetLength(Result, (Self.Size - 1));
    for i := 0 to (High(n) - 1) do
    begin
      a := (n[i].stop + 1);
      b := (n[i + 1].start - 1);
      if (a <= b) then
        Result[g.Increase].Create(a, b);
    end;
  end;
  SetLength(Result, g);
end;
{$ENDIF}
