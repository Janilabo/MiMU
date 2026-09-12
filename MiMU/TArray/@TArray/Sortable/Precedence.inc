{$IFDEF HELPERS}
function Orderify(const oAscending: Boolean = True): TIntegerArray; overload;
function Orderium(const oAscending: Boolean = True): TIntegerArray; overload;
function Orderize(const oAscending: Boolean = True): TIntegerArray; overload;
function Orderwise(const oAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Orderify>
  @action: Returns an array of element indexes sorted stably by their values.
  @note: Preserves the original relative order of equal elements (O(N log N) time).
[==============================================================================}
function MArrayHelper.Orderify(const oAscending: Boolean = True): TIntegerArray; overload;
var
  a, b, s, w, l, m, r, i, j, k: Integer;
  t: TIntegerArray;
  function C(const indexA, indexB: Integer): Boolean;
  begin
    if (Self[indexA] = Self[indexB]) then
      Result := (indexA < indexB)
    else if oAscending then
      Result := (Self[indexA] < Self[indexB])
    else
      Result := (Self[indexA] > Self[indexB]);
  end;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  if (s = 1) then
    Exit([0]);
  for i := 0 to Result.Alloc(s) do
    Result[i] := i;
  SetLength(t, s);
  w := 1;
  while (w < s) do
  begin
    l := 0;
    while (l < s) do
    begin
      m := (l + w);
      if (m >= s) then
        m := s;
      r := (l + (w * 2));
      if (r >= s) then
        r := s;
      a := l;
      b := m;
      k := l;
      while ((a < m) and (b < r)) do
        if C(Result[a], Result[b]) then
          t[k.Increase] := Result[a.Increase]
        else
          t[k.Increase] := Result[b.Increase];
      while (a < m) do
        t[k.Increase] := Result[a.Increase];
      while (b < r) do
        t[k.Increase] := Result[b.Increase];
      Inc(l, (w * 2));
    end;
    for i := 0 to (s - 1) do
      Result[i] := t[i];
    w := (w * 2);
  end;
end;

{==============================================================================]
  <Orderium>
  @action: Returns an array of element indexes sorted stably using binary insertion sort.
  @note: Uses binary search to pinpoint insertion locations; preserves original index 
         order for equal values. Ideal for small to medium-sized arrays.
[==============================================================================}
function MArrayHelper.Orderium(const oAscending: Boolean = True): TIntegerArray; overload;
var
  s, i, j, l, h, m, r: Integer;
  function C(const indexA, indexB: Integer): Boolean;
  begin
    if (Self[indexA] = Self[indexB]) then
      Result := (indexA < indexB)
    else if oAscending then
      Result := (Self[indexA] < Self[indexB])
    else
      Result := (Self[indexA] > Self[indexB]);
  end;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  if (s = 1) then
    Exit([0]);
  for i := 0 to Result.Alloc(s) do
    Result[i] := i;
  for i := 1 to (s - 1) do
  begin
    r := Result[i];
    l := 0;
    h := i;
    while (l < h) do
    begin
      m := ((l + h) shr 1);
      if C(Result[m], r) then
        l := (m + 1)
      else
        h := m;
    end;
    for j := i downto (l + 1) do
      Result[j] := Result[j - 1];
    Result[l] := r;
  end;
end;

{==============================================================================]
  <Orderize>
  @action: Quicksort on indexes using Hoare partitioning.
  @note: Average O(N log N), no allocation, in-place. Worst case O(N^2) on
         adversarial input; stability is a side effect of C()'s index
         tiebreak, not an algorithmic guarantee.
[==============================================================================}
function MArrayHelper.Orderize(const oAscending: Boolean = True): TIntegerArray; overload;
var
  s, i: Integer;
  function C(const indexA, indexB: Integer): Boolean;
  begin
    if (Self[indexA] = Self[indexB]) then
      Result := (indexA < indexB)
    else if oAscending then
      Result := (Self[indexA] < Self[indexB])
    else
      Result := (Self[indexA] > Self[indexB]);
  end;
  procedure Q(const iLow, iHigh: Integer);
  var
    l, r, p: Integer;
  begin
    if (iLow >= iHigh) then
      Exit;
    l := iLow;
    r := iHigh;
    p := Result[(iLow + iHigh) shr 1];
    while (l <= r) do
    begin
      while C(Result[l], p) do
        Inc(l);
      while C(p, Result[r]) do
        Dec(r);
      if (l <= r) then
        Result.Switch(l.Increase, r.Decrease);
    end;
    Q(iLow, r);
    Q(l, iHigh);
  end;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  if (s = 1) then
    Exit([0]);
  for i := 0 to Result.Alloc(s) do
    Result[i] := i;
  Q(0, (s - 1));
end;

{==============================================================================]
  <Orderwise>
  @action: Heapsort on indexes.
  @note: O(N log N) worst case, O(1) extra space, no allocation. Not
         algorithmically stable, but produces stable output here because
         C()'s index tiebreak resolves every comparison uniquely — flag this
         in documentation since "stable" describes the outcome, not the
         mechanism.
[==============================================================================}
function MArrayHelper.Orderwise(const oAscending: Boolean = True): TIntegerArray; overload;
var
  s, i, e: Integer;
  function C(const indexA, indexB: Integer): Boolean;
  begin
    if (Self[indexA] = Self[indexB]) then
      Result := (indexA < indexB)
    else if oAscending then
      Result := (Self[indexA] < Self[indexB])
    else
      Result := (Self[indexA] > Self[indexB]);
  end;
  procedure SiftDown(iRoot, iLimit: Integer);
  var
    r, t: Integer;
  begin
    while (((iRoot * 2) + 1) < iLimit) do
    begin
      r := ((iRoot * 2) + 1);
      t := iRoot;
      if C(Result[t], Result[r]) then
        t := r;
      if (((r + 1) < iLimit) and C(Result[t], Result[r + 1])) then
        t := (r + 1);
      if (t = iRoot) then
        Exit;
      Result.Switch(iRoot, t);
      iRoot := t;
    end;
  end;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  if (s = 1) then
    Exit([0]);
  for i := 0 to Result.Alloc(s) do
    Result[i] := i;
  for i := ((s div 2) - 1) downto 0 do
    SiftDown(i, s);
  e := (s - 1);
  while (e > 0) do
  begin
    Result.Switch(0, e);
    SiftDown(0, e.Decrease);
  end;
end;
{$ENDIF}
