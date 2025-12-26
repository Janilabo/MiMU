{$IFDEF HELPERS}
function Blobs(const xRadius, yRadius: Integer): T2DPointArray; overload;
function Blobs(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
function Blobs(const radius: Double = 1.0): T2DPointArray; overload;
function Blobify(const xRadius, yRadius: Integer): T2DPointArray; overload;
function Blobify(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
function Blobify(const radius: Double = 1.0): T2DPointArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Blobs>
  @action: Groups the points in the array into contiguous spatial clusters ("blobs")
           based on the specified xRadius and yRadius. Each blob is a TPointArray
           containing points that are all within the proximity ranges of each other.
  @note: Uses a breadth-first search style traversal combined with binary range
         searches on sorted X/Y arrays for efficiency. The result is a T2DPointArray,
         where each element represents a blob. Empty or single-element arrays are
         handled specially. This method may allocate intermediate arrays.
[==============================================================================}
function TPointArrayHelper.Blobs(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, p, g, t, z, l: Integer;
  h, v, r, c: TRange;
  x: T2DIntegerArray;
  y: TIntegerArray;
  q: TPointArray;
  a, n: TPoint;
  m: TBooleanArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  x := Self.X2D(y);
  SetLength(Result, l);
  SetLength(m, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if m[i] then
      Continue;
    SetLength(q, 1);
    q[0] := Self[i];
    m[i] := True;
    t := 0;
    while (t < q.Size) do
    begin
      a := q[t.Increase];
      SetLength(Result[g], (Result[g].Size + 1));
      Result[g][High(Result[g])] := a;
      h.Create((a.X - xRadius), (a.X + xRadius));
      v.Create((a.Y - yRadius), (a.Y + yRadius));
      r := y.BinaryRange(v);
      if r.Employs(-1) then
        Continue;
      for j := r.start to r.stop do
      begin
        c := x[j].BinaryRange(h);
        if c.Employs(-1) then
          Continue;
        for p := c.start to c.stop do
        begin
          n.Create(x[j][p], y[j]);
          for z := 0 to l - 1 do
            if (Self[z] = n) then
              Break;
          if ((z < l) and (not m[z])) then
          begin
            m[z] := True;
            SetLength(q, (q.Size + 1));
            q[High(q)] := n;
          end;
        end;
      end;
    end;
    if (Result[g].Size > 0) then
      Inc(g);
  end;
  SetLength(Result, g);
end;

function TPointArrayHelper.Blobs(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  i, j, p, g, t, z, l, d: Integer;
  h, v, r, c: TRange;
  x: T2DIntegerArray;
  y: TIntegerArray;
  q: TPointArray;
  a, n: TPoint;
  m: TBooleanArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  d := Trunc(radius);
  x := Self.X2D(y);
  SetLength(Result, l);
  SetLength(m, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if m[i] then
      Continue;
    SetLength(q, 1);
    q[0] := Self[i];
    m[i] := True;
    t := 0;
    while (t < q.Size) do
    begin
      a := q[t.Increase];
      SetLength(Result[g], (Result[g].Size + 1));
      Result[g][High(Result[g])] := a;
      h.Create((a.X - d), (a.X + d));
      v.Create((a.Y - d), (a.Y + d));
      r := y.BinaryRange(v);
      if r.Employs(-1) then
        Continue;
      for j := r.start to r.stop do
      begin
        c := x[j].BinaryRange(h);
        if c.Employs(-1) then
	      Continue;
        for p := c.start to c.stop do
        begin
          n.Create(x[j][p], y[j]);
          for z := 0 to (l - 1) do
            if (Self[z] = n) then
	          Break;
          if ((z < l) and (not m[z]) and a.Within(n, radius, distFunc)) then
          begin
            m[z] := True;
            SetLength(q, (q.Size + 1));
            q[High(q)] := n;
          end;
        end;
      end;
    end;
    if (Result[g].Size > 0) then
      Inc(g);
  end;
  SetLength(Result, g);
end;

function TPointArrayHelper.Blobs(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Blobs(radius, @Euclidean);
end;

{==============================================================================]
  <Blobify>
  @action: Similar to Blobs, but optimized with a pre-allocated queue to reduce
           repeated memory allocations. Groups the points into spatially connected
           blobs based on xRadius and yRadius.
  @note: Uses a breadth-first traversal combined with binary range searches on
         sorted X/Y arrays. Internal queue is pre-sized for better performance.
         Returns a T2DPointArray of blobs. Handles empty or single-element arrays
         correctly. Consider using this version when processing large point sets
         for efficiency.
[==============================================================================}
function TPointArrayHelper.Blobify(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, p, g, z, l: Integer;
  h, v, r, c, k: TRange;
  x: T2DIntegerArray;
  y: TIntegerArray;
  q: TPointArray;
  a, n: TPoint;
  m: TBooleanArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  x := Self.X2D(y);
  SetLength(Result, l);
  SetLength(m, l);
  SetLength(q, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if m[i] then
      Continue;
    k.Create(0, 1);
    q[0] := Self[i];
    m[i] := True;
    SetLength(Result[g], 0);
    while (k.start < k.stop) do
    begin
      a := q[k.start.Increase];
      SetLength(Result[g], (Result[g].Size + 1));
      Result[g][High(Result[g])] := a;
      h.Create((a.X - xRadius), (a.X + xRadius));
      v.Create((a.Y - yRadius), (a.Y + yRadius));
      r := y.BinaryRange(v);
      if r.Employs(-1) then
        Continue;
      for j := r.start to r.stop do
      begin
        c := x[j].BinaryRange(h);
        if c.Employs(-1) then
          Continue;
        for p := c.start to c.stop do
        begin
          n.Create(x[j][p], y[j]);
          for z := 0 to (l - 1) do
            if (Self[z] = n) then
              Break;
          if ((z < l) and (not m[z])) then
          begin
            m[z] := True;
            q[k.stop.Increase] := n;
          end;
        end;
      end;
    end;
    if (Result[g].Size > 0) then
      Inc(g);
  end;
  SetLength(Result, g);
end;

function TPointArrayHelper.Blobify(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  i, j, p, g, z, l, d: Integer;
  h, v, r, c, k: TRange;
  x: T2DIntegerArray;
  y: TIntegerArray;
  q: TPointArray;
  a, n: TPoint;
  m: TBooleanArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  d := Trunc(radius);
  x := Self.X2D(y);
  SetLength(Result, l);
  SetLength(m, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if m[i] then
      Continue;
    SetLength(q, (l * 2));
    q[0] := Self[i];
    m[i] := True;
    k.Create(0, 1);
    SetLength(Result[g], 0);
    while (k.start < k.stop) do
    begin
      a := q[k.start.Increase];
      SetLength(Result[g], (Result[g].Size + 1));
      Result[g][High(Result[g])] := a;
      h.Create((a.X - d), (a.X + d));
      v.Create((a.Y - d), (a.Y + d));
      r := y.BinaryRange(v);
      if r.Employs(-1) then
        Continue;
      for j := r.start to r.stop do
      begin
        c := x[j].BinaryRange(h);
        if c.Employs(-1) then
		  Continue;
        for p := c.start to c.stop do
        begin
          n.Create(x[j][p], y[j]);
          for z := 0 to (l - 1) do
            if (Self[z] = n) then
              Break;
          if ((z < l) and (not m[z]) and a.Within(n, radius, distFunc)) then
          begin
            m[z] := True;
            if (k.stop >= q.Size) then
              SetLength(q, (q.Size * 2));
            q[k.stop.Increase] := n;
          end;
        end;
      end;
    end;
    if (Result[g].Size > 0) then
      Inc(g);
  end;
  SetLength(Result, g);
end;

function TPointArrayHelper.Blobify(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Blobify(radius, @Euclidean);
end;
{$ENDIF}
