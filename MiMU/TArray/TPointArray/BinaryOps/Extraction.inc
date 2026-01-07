{$IFDEF HELPERS}
function BinaryX: TIntegerArray; overload;
function BinaryXs(const unique: Boolean = True): TIntegerArray; overload;
function BinaryY: TIntegerArray; overload;
function BinaryYs(const unique: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryX>
  @action: Returns a sequence of X-values grouped by contiguous segments of equal Y within the TPointArray
          (which is assumed to be sorted by Y). For each block of points sharing the same Y value,
          the routine extracts the unique X values (unique within that Y-block)
          and inserts them into the output array in ascending order through binary growth.
  @note: The method performs a binary search on Y to locate each contiguous Y-block,
         then processes X values within the block. Uniqueness is enforced only within the same Y-group.
[==============================================================================}
function TPointArrayHelper.BinaryX: TIntegerArray; overload;
var
  h, i, y, m, k, x: Integer;
  s, r: TRange;
begin
  SetLength(Result, 0);
  h := High(Self);
  if (h < 0) then
    Exit;
  i := 0;
  while (i <= h) do
  begin
    y := Self[i].Y;
    r.Create(i, h);
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if (Self[m].Y > y) then
        r.stop := (m - 1)
      else
        r.start := (m + 1);
    end;
    s.Create(i, (r.start - 1));
    x := Low(Integer);
    for k := s.start to s.stop do
    begin
      if (x = Self[k].X) then
        Continue;
      x := Self[k].X;
      Result.BinaryGrow(x);
    end;
    i := (s.stop + 1);
  end;
end;

{==============================================================================]
  <BinaryXs>
  @action:
    Returns all X-values from the TPointArray, grouped by their Y-value.
    Optionally returns only unique X-values within each Y-group.
  @note:
    - The array must be sorted by Y ascending for correct grouping.
    - Uniqueness is applied *per Y-group* only.
    - If unique=True, repeated X-values within the same Y-group are ignored.
    - If unique=False, all X-values are preserved.
[==============================================================================}
function TPointArrayHelper.BinaryXs(const unique: Boolean = True): TIntegerArray; overload;
var
  h, i, y, m, k, x: Integer;
  r, s: TRange;
begin
  SetLength(Result, 0);
  h := High(Self);
  if (h < 0) then
    Exit;
  i := 0;
  while (i <= h) do
  begin
    y := Self[i].Y;
    r.Create(i, h);
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if (Self[m].Y > y) then
        r.stop := (m - 1)
      else
        r.start := (m + 1);
    end;
    s.Create(i, (r.start - 1));
    case unique of
      True:
      begin
        x := Low(Integer);
        for k := s.start to s.stop do
        begin
          if (Self[k].X = x) then
            Continue;
          x := Self[k].X;
          Result.BinaryGrow(x);
        end;
      end;
      False:
      for k := s.start to s.stop do
        Result.BinaryInsert(Self[k].X);
    end;
    i := (s.stop + 1);
  end;
end;

{==============================================================================]
  <BinaryY>
  @action: Returns a sequence of Y-values extracted from a TPointArray that is already sorted by Y.
           The method performs a run-length–style scan that groups contiguous points having non-decreasing Y values
           and emits one representative Y value for each such monotonic block.
  @note: The resulting array contains unique Y values only with respect to contiguous runs.
         Uniqueness is not guaranteed globally unless the underlying TPointArray is fully sorted by Y
         and contains no duplicated Y values in non-contiguous positions.
[==============================================================================}
function TPointArrayHelper.BinaryY: TIntegerArray; overload;
var
  h, i, y, m, l: Integer;
  r: TRange;
begin
  SetLength(Result, 0);
  h := High(Self);
  if (h < 0) then
    Exit;
  l := 0;
  i := 0;
  SetLength(Result, Self.Size);
  while (i <= h) do
  begin
    y := Self[i].Y;
    Result[l.Increase] := y;
    r.Create((i + 1), h);
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if (Self[m].Y > y) then
        r.stop := (m - 1)
      else
        r.start := (m + 1);
    end;
    i := r.start;
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <BinaryYs>
  @action:
    Returns all Y-values from the TPointArray, in the order they appear.
    Optionally returns only unique values (no duplicates).
  @note:
    - The array must be sorted by Y ascending for the unique option to work correctly.
    - If unique=True, repeated Y-values are ignored.
    - If unique=False, all Y-values including duplicates are returned.
[==============================================================================}
function TPointArrayHelper.BinaryYs(const unique: Boolean = True): TIntegerArray; overload;
var
  i, c: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  Result[0] := Self[0].Y;
  c := 1;
  case unique of
    True:
    for i := 1 to High(Self) do
      if (Self[i].Y <> Self[i - 1].Y) then
        Result[c.Increase] := Self[i].Y;
    False:
    for i := 1 to High(Self) do
      Result[c.Increase] := Self[i].Y;
  end;
  SetLength(Result, c);
end;
{$ENDIF}
