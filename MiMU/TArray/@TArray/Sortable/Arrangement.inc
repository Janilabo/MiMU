{$IFDEF HELPERS}
function Funnelled(const origins: TIntegerArray): MArray; overload;

function Tacks(const oAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Funnelled>
  @action: Returns Self with its pre-sorted runs merged into one ascending array.
  @note: origins holds the first index of each run, ascending, with origins[0] = 0.
         Every run must already be sorted ascending. Merges are stable (ties
         come from the earlier run). Self is left unchanged.
[==============================================================================}
function MArrayHelper.Funnelled(const origins: TIntegerArray): MArray; overload;
var
  i, n, z, w, k, l, c, h, m, a, b, o: Integer;
  s: TIntegerArray;
  p, q, r: MArray;
  f: Boolean;
begin
  Result := Self.Copy;
  z := origins.Length;
  if (z < 2) then
    Exit;
  n := Self.Length;
  SetLength(s, (z + 1));
  for i := 0 to (z - 1) do
    s[i] := origins[i];
  s[z] := n;
  SetLength(p, n);
  if (z > 2) then
    SetLength(q, n);
  f := False;
  w := 1;
  while (w < z) do
  begin
    if f then
      r := q
    else
      r := p;
    k := 0;
    while (k < z) do
    begin
      l := s[k];
      m := (k + w);
      if (m > z) then
        m := z;
      c := s[m];
      m := (k + 2 * w);
      if (m > z) then
        m := z;
      h := s[m];
      a := l;
      b := c;
      o := l;
      while ((a < c) and (b < h)) do
        if (Result[b] < Result[a]) then
          r[o.Increase] := Result[b.Increase]
        else
          r[o.Increase] := Result[a.Increase];
      while (a < c) do
        r[o.Increase] := Result[a.Increase];
      while (b < h) do
        r[o.Increase] := Result[b.Increase];
      Inc(k, (2 * w));
    end;
    Result := r;
    f := not f;
    w := (w * 2);
  end;
end; 

{==============================================================================]
  <Tacks>
  @action: Returns the first index of every sorted run in the array.
  @note: oAscending = True:  a new run starts wherever Self[i] < Self[i - 1].
         oAscending = False: a new run starts wherever Self[i] > Self[i - 1].
         Equal neighbours stay in the same run. Returns an empty array if Self
         is empty. The result is a valid origins parameter for Marshalled
         with the same oAscending.
[==============================================================================}
function MArrayHelper.Tacks(const oAscending: Boolean = True): TIntegerArray; overload;
var
  i, s, r: Integer;
begin
  s := Self.Length;
  SetLength(Result, s);
  if (s = 0) then
    Exit;
  Result[0] := 0;
  r := 1;
  case oAscending of
    True:
    for i := 1 to (s - 1) do
      if (Self[i] < Self[i - 1]) then
        Result[r.Increase] := i;
    False:
    for i := 1 to (s - 1) do
      if (Self[i] > Self[i - 1]) then
        Result[r.Increase] := i;
  end;
  SetLength(Result, r);
end;
{$ENDIF}
