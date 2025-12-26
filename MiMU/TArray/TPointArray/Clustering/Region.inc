{$IFDEF HELPERS}
function Regionize(const xRadius, yRadius: Integer): T2DPointArray; overload;
function Regionize(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
function Regionize(const radius: Double = 1.0): T2DPointArray; overload;
function Segment(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
function Segment(const radius: Double = 1.0): T2DPointArray; overload;
function Segment(const xRadius, yRadius: Integer): T2DPointArray; overload;
function Fragment(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
function Fragment(const radius: Double = 1.0): T2DPointArray; overload;
function Fragment(const xRadius, yRadius: Integer): T2DPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Regionize>
  @action: Groups points in the array into clusters based on rectangular neighborhoods
           defined by X and Y radii.
  @note: Clusters are formed by examining a box of size XRadius x YRadius around each
         point. Points within the same box are grouped together. This version does not
         use a distance function; it is grid/box-based.
[==============================================================================}
function TPointArrayHelper.Regionize(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  x, y, i, l, r, c, t, f: Integer;
  g, d: TStringList;
  p, n: TPoint;
  q: TPointArray;
  k: string;
  a, b: TBox;
  function KeyStr(const p: TPoint): string; inline;
  begin
    Result := (IntToStr(p.X) + ',' + IntToStr(p.Y));
  end;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  b := Self.Bounds;
  g := TStringList.Create;
  g.Sorted := False;
  g.Duplicates := dupIgnore;
  d := TStringList.Create;
  d.Sorted := True;
  d.Duplicates := dupIgnore;
  r := 0;
  SetLength(Result, l);
  try
    for i := 0 to (l - 1) do
      g.Add(KeyStr(Self[i]));
    g.Sorted := True;
    g.Sort;
    for i := 0 to (l - 1) do
    begin
      if d.Find(KeyStr(Self[i]), f) then
        Continue;
      SetLength(Result[r], 0);
      SetLength(q, 1);
      q[0] := Self[i];
      t := 0;
      c := 1;
      while (t < c) do
      begin
        p := q[t.Increase];
        k := KeyStr(p);
        if d.Find(k, f) then
          Continue;
        d.Add(k);
        SetLength(Result[r], (Result[r].Size + 1));
        Result[r][High(Result[r])] := p;
        a := p.Boxed(xRadius, yRadius).Clamp(b);
        for y := a.Y1 to a.Y2 do
          for x := a.X1 to a.X2 do
          begin
            n := Point(x, y);
            k := KeyStr(n);
            if (g.Find(k, f) and (not d.Find(k, f))) then
            begin
              SetLength(q, (c + 1));
              q[c.Increase] := n;
            end;
          end;
      end;
      if (Result[r].Size > 0) then
        Inc(r);
    end;
  finally
    g.Free;
    d.Free;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Regionize>
  @action: Groups points in the array into clusters based on a distance threshold.
  @note: Clusters are formed by examining all points within the array using the
         provided distance function. Points within the specified radius (Double)
         of any cluster member are added to the same cluster. This version supports
         arbitrary distance metrics via the TDistance parameter.
[==============================================================================}
function TPointArrayHelper.Regionize(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  i, j, l, r, c, t, f: Integer;
  g, d: TStringList;
  p: TPoint;
  q: TPointArray;
  k: string;
  function KeyStr(const p: TPoint): string; inline;
  begin
    Result := (IntToStr(p.X) + ',' + IntToStr(p.Y));
  end;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  g := TStringList.Create;
  g.Sorted := False;
  g.Duplicates := dupIgnore;
  d := TStringList.Create;
  d.Sorted := True;
  d.Duplicates := dupIgnore;
  r := 0;
  SetLength(Result, l);
  try
    for i := 0 to (l - 1) do
      g.Add(KeyStr(Self[i]));
    g.Sorted := True;
    g.Sort;
    for i := 0 to (l - 1) do
    begin
      if d.Find(KeyStr(Self[i]), f) then
        Continue;
      SetLength(Result[r], 0);
      SetLength(q, 1);
      q[0] := Self[i];
      t := 0;
      c := 1;
      while (t < c) do
      begin
        p := q[t.Increase];
        k := KeyStr(p);
        if d.Find(k, f) then
          Continue;
        d.Add(k);
        SetLength(Result[r], (Result[r].Size + 1));
        Result[r][High(Result[r])] := p;
        for j := 0 to (l - 1) do
          if ((not d.Find(KeyStr(Self[j]), f)) and p.Within(Self[j], radius, distFunc)) then
          begin
            SetLength(q, (c + 1));
            q[c.Increase] := Self[j];
          end;
      end;
      if (Result[r].Size > 0) then
        Inc(r);
    end;
  finally
    g.Free;
    d.Free;
  end;
  SetLength(Result, r);
end;

function TPointArrayHelper.Regionize(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Regionize(radius, @Euclidean);
end;

{==============================================================================]
  <Segment>
  @action: Splits TPointArray to groups by radius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Segment(const radius: Double; const distFunc: TDistance): T2DPointArray; overload; 
var
  b, f, l, i, j, k, p, r, c: Integer;
  v: TBooleanArray;
  q: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(v, l);
  for i := 0 to (l - 1) do
    v[i] := False;
  SetLength(Result, l);
  r := 0;
  p := 0;
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    SetLength(q, l);
    f := 0;
    b := 0;
    q[b.Increase] := i;
    v[i] := True;
    c := 0;
    SetLength(Result[r], (l - p));
    while (f < b) do
    begin
      j := q[f.Increase];
      Result[r][c.Increase] := Self[j];
      for k := 0 to (l - 1) do
        if ((not v[k]) and Self[j].Within(Self[k], radius, distFunc)) then
        begin
          v[k] := True;
          q[b.Increase] := k;
        end;
    end;
    Inc(p, c);
    SetLength(Result[r.Increase], c);
  end;
  SetLength(Result, r);
end;

function TPointArrayHelper.Segment(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Segment(radius, @HypotEuclidean);
end;

{==============================================================================]
  <Segment>
  @action: Splits TPointArray to groups by xRadius and yRadius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Segment(const xRadius, yRadius: Integer): T2DPointArray; overload; 
var
  b, f, l, i, j, k, p, r, c: Integer;
  v: TBooleanArray;
  q: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(v, l);
  for i := 0 to (l - 1) do
    v[i] := False;
  SetLength(Result, l);
  r := 0;
  p := 0;
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    SetLength(q, l);
    f := 0;
    b := 0;
    q[b.Increase] := i;
    v[i] := True;
    c := 0;
    SetLength(Result[r], (l - p));
    while (f < b) do
    begin
      j := q[f.Increase];
      Result[r][c.Increase] := Self[j];
      for k := 0 to (l - 1) do
        if ((not v[k]) and Self[j].Within(Self[k], xRadius, yRadius)) then
        begin
          v[k] := True;
          q[b.Increase] := k;
        end;
    end;
    Inc(p, c);
    SetLength(Result[r.Increase], c);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Fragment>
  @action: Splits TPointArray to groups by radius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Fragment(const radius: Double; const distFunc: TDistance): T2DPointArray; overload; 
var
  h, l, i, j, k, r, p, c: Integer;
  v: TBooleanArray;
  s: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(v, l);
  for i := 0 to (l - 1) do
    v[i] := False;
  SetLength(Result, l);
  r := 0;
  p := 0;
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    SetLength(s, l);
    h := 0;
    s[h.Increase] := i;
    v[i] := True;
    c := 0;
    SetLength(Result[r], (l - p));
    while (h > 0) do
    begin
      j := s[h.Decrement];
      Result[r][c.Increase] := Self[j];
      for k := 0 to (l - 1) do
        if ((not v[k]) and Self[j].Within(Self[k], radius, distFunc)) then
        begin
          v[k] := True;
          s[h.Increase] := k;
        end;
    end;
    Inc(p, c);
    SetLength(Result[r.Increase], c);
  end;
  SetLength(Result, r);
end;

function TPointArrayHelper.Fragment(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Fragment(radius, @HypotEuclidean);
end;

{==============================================================================]
  <Fragment>
  @action: Splits TPointArray to groups by xRadius and yRadius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Fragment(const xRadius, yRadius: Integer): T2DPointArray; overload; 
var
  h, l, i, j, k, r, p, c: Integer;
  v: TBooleanArray;
  s: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(v, l);
  for i := 0 to (l - 1) do
    v[i] := False;
  SetLength(Result, l);
  r := 0;
  p := 0;
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    SetLength(s, l);
    h := 0;
    s[h.Increase] := i;
    v[i] := True;
    c := 0;
    SetLength(Result[r], (l - p));
    while (h > 0) do
    begin
      j := s[h.Decrement];
      Result[r][c.Increase] := Self[j];
      for k := 0 to (l - 1) do
        if ((not v[k]) and Self[j].Within(Self[k], xRadius, yRadius)) then
        begin
          v[k] := True;
          s[h.Increase] := k;
        end;
    end;
    Inc(p, c);
    SetLength(Result[r.Increase], c);
  end;
  SetLength(Result, r);
end;
{$ENDIF}
