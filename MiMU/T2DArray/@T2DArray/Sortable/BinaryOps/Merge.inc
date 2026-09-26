{$IFDEF HELPERS}
function BinaryCollated(const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryCollated>
  @action: Performs a binary-search-driven K-way merge across outer array rows.
  @note: Employs an ordered head-index priority queue updated via O(log K) binary search.
[==============================================================================}
function M2DArrayHelper.BinaryCollated(const oAscending: Boolean = True): MArray; overload;
var
  z, t, r: TIntegerArray;
  s, n, i, j, k, l, h, m, c: Integer;
  function A(p, q: Integer): Boolean;
  begin
    if oAscending then
      Result := (Self[p][z[p]] < Self[q][z[q]])
    else
      Result := (Self[p][z[p]] > Self[q][z[q]]);
  end;
begin
  s := Self.Length;
  n := 0;
  k := 0;
  for i := 0 to t.Alloc(s) do
  begin
    t[i] := Self[i].Length;
    if (t[i] > 0) then
    begin
      Inc(n, t[i]);
      Inc(k);
    end;
  end;
  if (n = 0) then
    Exit([]);
  for i := 0 to z.Alloc(s) do
    z[i] := 0;
  SetLength(r, k);
  k := 0;
  for i := 0 to (s - 1) do
    if (t[i] > 0) then
      r[k.Increase] := i;
  for i := 1 to (k - 1) do
  begin
    c := r[i];
    j := (i - 1);
    while (j >= 0) do
    begin
      if not A(c, r[j]) then
        Break;
      r[j + 1] := r[j];
      Dec(j);
    end;
    r[j + 1] := c;
  end;
  for j := 0 to Result.Alloc(n) do
  begin
    c := r[0];
    Result[j] := Self[c][z[c]];
    case (z[c].Increment >= t[c]) of
      False:
      begin
        l := 1;
        h := (k - 1);
        while (l <= h) do
        begin
          m := (l + (h - l) div 2);
          if A(c, r[m]) then
            h := (m - 1)
          else
            l := (m + 1);
        end;
        for i := 1 to (l - 1) do
          r[i - 1] := r[i];
        r[l - 1] := c;
      end;
      True:
      begin
        for i := 0 to (k - 2) do
          r[i] := r[i + 1];
        Dec(k);
      end;
    end;
  end;
end;
{$ENDIF}
