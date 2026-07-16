{$IFDEF HELPERS}
function BinaryScan(const area: TBox): TIntegerArray; overload;
function BinaryScanned(const area: TBox): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryScan>
  @action: Performs a vertical binary scan on a Y-sorted point array to locate
           all points whose coordinates lie within the specified TBox.
  @note:   Array must be sorted by Y ascending. Uses binary search on Y to find
           the vertical range and linearly filters by X within that range.
           Returns indexes of all matching points.
[==============================================================================}
function TPointArrayHelper.BinaryScan(const area: TBox): TIntegerArray; overload;
var
  M, i: Integer;
  s, r: TRange;
begin
  SetLength(Result, 0);
  s.Create(0, High(Self));
  if ((s.stop = -1) or (area.Y2 < Self[s.start].Y) or (area.Y1 > Self[s.stop].Y)) then
    Exit;
  r.Create(-1);
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case (Self[M].Y < area.Y1) of
      False:
      begin
        r.start := M;
        s.stop := (M - 1);
      end;
      True: s.start := (M + 1);
    end;
  end;
  if (r.start = -1) then
    Exit;
  s.start := r.start;
  s.stop := High(Self);
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case (Self[M].Y > area.Y2) of
      False:
      begin
        r.stop := M;
        s.start := (M + 1);
      end;
      True: s.stop := (M - 1);
    end;
  end;
  if (r.stop = -1) then
    Exit;
  for i := r.start to r.stop do
    if ((Self[i].X >= area.X1) and (Self[i].X <= area.X2)) then
      Result.Supply(i);
end;

{==============================================================================]
  <BinaryScanned>
  @action: Performs a vertical binary scan on a Y-sorted point array to locate
           all point indexes lying within the specified TBox.
  @note: - The array must be sorted in ascending order by the Y coordinate.
         - Uses binary search on Y to find the vertical range (Y1..Y2),
           then linearly filters points whose X coordinate also lies within
           X1..X2.
         - Returns an index list (TIntegerArray) of all points inside the box.
         - Ideal for spatial lookups or clipping operations in sorted sets.
[==============================================================================}
function TPointArrayHelper.BinaryScanned(const area: TBox): TIntegerArray;
var
  M, i, S: Integer;
  o, r: TRange;
begin
  SetLength(Result, 0);
  o.Create(0, High(Self));
  if ((o.stop = -1) or (area.Y2 < Self[O.start].Y) or (area.Y1 > Self[o.stop].Y)) then
    Exit;
  S := o.stop;
  r.Create(-1);
  while (o.start <= o.stop) do
  begin
    M := o.Pivot;
    case ((Self[M].Y >= area.Y1) and (Self[M].Y <= area.Y2)) of
      True:
      begin
        r.Create(M);
        while ((r.start > 0) and (Self[r.start - 1].Y >= area.Y1)) do
          Dec(r.start);
        while ((r.stop < S) and (Self[r.stop + 1].Y <= area.Y2)) do
          Inc(r.stop);
        Break;
      end;
      False:
      if (Self[M].Y > area.Y2) then
        o.stop := (M - 1)
      else
        o.start := (M + 1);
    end;
  end;
  if not r.Employs(-1) then
  for i := r.start to r.stop do
    if ((Self[i].X >= area.X1) and (Self[i].X <= area.X2)) then
      Result.Supply(i);
end;
{$ENDIF}
