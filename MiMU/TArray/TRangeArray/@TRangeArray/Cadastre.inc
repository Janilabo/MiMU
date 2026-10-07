{$IFDEF HELPERS}
function Allotted: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Allotted>
  @action: Returns Self as non-overlapping ranges covering exactly the same digits.
  @note: Every digit covered by Self is covered exactly once in the result.
         Earlier ranges stay whole, later ranges are cut around them (Partitum).
         Exception: an earlier range fully inside a later one is replaced by it.
         Each range keeps its own direction, and pieces cut from a range keep its direction.
         Result is not merged, so adjacent ranges that could be one are left apart.
[==============================================================================}
function TRangeArrayHelper.Allotted: TRangeArray; overload;
var
  s, p: TRangeArray;
  r: TRange;
  i, j: Integer;
  o: Boolean;
begin
  SetLength(Result, 0);
  SetLength(s, 0);
  for i := High(Self) downto 0 do
    s.Supply(Self[i]);
  while (s.Length > 0) do
  begin
    r := s[High(s)];
    SetLength(s, High(s));
    o := False;
    i := 0;
    while (i < Result.Length) do
    begin
      o := Result[i].Overlap(r);
      if o then
        Break;
      Inc(i);
    end;
    if not o then
    begin
      Result.Supply(r);
      Continue;
    end;
    if Result[i].Contains(r) then
      Continue;
    if r.Contains(Result[i]) then
    begin
      Result[i] := Result[High(Result)];
      SetLength(Result, High(Result));
      s.Supply(r);
      Continue;
    end;
    p := Result[i].Partitum(r);
    for j := 1 to High(p) do
      s.Supply(p[j]);
  end;
end;
{$ENDIF}
