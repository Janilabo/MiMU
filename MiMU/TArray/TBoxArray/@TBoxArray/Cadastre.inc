{$IFDEF HELPERS}
function Allotted: TBoxArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Allotted>
  @action: Returns Self as non-overlapping boxes covering exactly the same points.
  @note: Every point covered by Self is covered exactly once in the result.
         Earlier boxes stay whole, later boxes are cut around them (Partitum).
         Exception: an earlier box fully inside a later one is replaced by it.
         Result is not merged, so adjacent boxes that could be one are left apart.
[==============================================================================}
function TBoxArrayHelper.Allotted: TBoxArray; overload;
var
  s, p: TBoxArray;
  b: TBox;
  i, j: Integer;
  o: Boolean;
begin
  SetLength(Result, 0);
  SetLength(s, 0);
  for i := High(Self) downto 0 do
    s.Supply(Self[i]);
  while (s.Length > 0) do
  begin
    b := s[High(s)];
    SetLength(s, High(s));
    o := False;
    i := 0;
    while (i < Result.Length) do
    begin
      o := Result[i].Overlap(b);
      if o then
        Break;
      Inc(i);
    end;
    if not o then
    begin
      Result.Supply(b);
      Continue;
    end;
    if Result[i].Contains(b) then
      Continue;
    if b.Contains(Result[i]) then
    begin
      Result[i] := Result[High(Result)];
      SetLength(Result, High(Result));
      s.Supply(b);
      Continue;
    end;
    p := Result[i].Partitum(b);
    for j := 1 to High(p) do
      s.Supply(p[j]);
  end;
end;
{$ENDIF}
