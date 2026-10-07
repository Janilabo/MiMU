{$IFDEF HELPERS}
function Allotted: TBoxArray; overload;
function Disjoined: TBoxArray; overload;
function Disjunctum: TBoxArray; overload;
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

{==============================================================================]
  <Disjoined>
  @action: Returns Self as non-overlapping boxes covering exactly the same points.
  @note: Every point covered by Self is covered exactly once in the result.
         Earlier boxes always stay whole, later boxes are cut around them (Excised).
         Result keeps input order: each box's surviving pieces follow the earlier boxes.
         Result is not merged, so adjacent boxes that could be one are left apart.
[==============================================================================}
function TBoxArrayHelper.Disjoined: TBoxArray; overload;
var
  i, j, k, l: Integer;
  r, q, p: TBoxArray;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    SetLength(r, 0);
    r.Supply(Self[i]);
    for j := 0 to High(Result) do
    begin
      SetLength(q, 0);
      for k := 0 to High(r) do
      begin
        p := r[k].Excised(Result[j]);
        for l := 0 to High(p) do
          q.Supply(p[l]);
      end;
      r := q;
      if (r.Length = 0) then
        Break;
    end;
    for k := 0 to High(r) do
      Result.Supply(r[k]);
  end;
end;

{==============================================================================]
  <Disjunctum>
  @action: Returns Self as non-overlapping boxes covering exactly the same points.
  @note: Every point covered by Self is covered exactly once in the result.
         Earlier boxes always stay whole, later boxes are cut around them.
         Result keeps input order: each box's surviving pieces follow the earlier boxes.
         Result is not merged, so adjacent boxes that could be one are left apart.
[==============================================================================}
function TBoxArrayHelper.Disjunctum: TBoxArray; overload;
var
  i, j, k, l: Integer;
  r, q, p: TBoxArray;
  c, b: TBox;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    SetLength(r, 0);
    r.Supply(Self[i]);
    for j := 0 to High(Result) do
    begin
      b := Result[j];
      SetLength(q, 0);
      for k := 0 to High(r) do
      begin
        c := r[k];
        if not c.Overlap(b) then
          q.Supply(c)
        else if b.Contains(c) then
          Continue
        else if c.Contains(b) then
        begin
          if (c.Y1 < b.Y1) then
            q.Supply(c.X1, c.Y1, c.X2, (b.Y1 - 1));
          if (c.Y2 > b.Y2) then
            q.Supply(c.X1, (b.Y2 + 1), c.X2, c.Y2);
          if (c.X1 < b.X1) then
            q.Supply(c.X1, b.Y1, (b.X1 - 1), b.Y2);
          if (c.X2 > b.X2) then
            q.Supply((b.X2 + 1), b.Y1, c.X2, b.Y2);
        end else
        begin
          p := b.Partitum(c);
          for l := 1 to High(p) do
            q.Supply(p[l]);
        end;
      end;
      r := q;
      if (r.Length = 0) then
        Break;
    end;
    for k := 0 to High(r) do
      Result.Supply(r[k]);
  end;
end;
{$ENDIF}
