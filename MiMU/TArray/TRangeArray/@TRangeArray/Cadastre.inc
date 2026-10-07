{$IFDEF HELPERS}
function Allotted: TRangeArray; overload;
function Disjoined: TRangeArray; overload;
function Disjunctum: TRangeArray; overload;
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

{==============================================================================]
  <Disjoined>
  @action: Returns Self as non-overlapping ranges covering exactly the same points.
  @note: Every point covered by Self is covered exactly once in the result.
         Earlier ranges always stay whole, later ranges are cut around them (Excised).
         Pieces cut from a range keep that range's direction.
         Result keeps input order: each range's surviving pieces follow the earlier ranges.
         Result is not merged, so adjacent ranges that could be one are left apart.
[==============================================================================}
function TRangeArrayHelper.Disjoined: TRangeArray; overload;
var
  i, j, k, l: Integer;
  r, q, p: TRangeArray;
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
  @action: Returns Self as non-overlapping ranges covering exactly the same points.
  @note: Every point covered by Self is covered exactly once in the result.
         Earlier ranges always stay whole, later ranges are cut around them.
         Pieces cut from a range keep that range's direction.
         Result keeps input order: each range's surviving pieces follow the earlier ranges.
         Result is not merged, so adjacent ranges that could be one are left apart.
[==============================================================================}
function TRangeArrayHelper.Disjunctum: TRangeArray; overload;
var
  i, j, k, l: Integer;
  r, q, p: TRangeArray;
  c, b: TRange;
  a: Boolean;
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
          a := (c.start <= c.stop);
          if (c.Minimum < b.Minimum) then
            q.Supply(RangeEx(c.Minimum, (b.Minimum - 1), a));
          if (c.Maximum > b.Maximum) then
            q.Supply(RangeEx((b.Maximum + 1), c.Maximum, a));
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
