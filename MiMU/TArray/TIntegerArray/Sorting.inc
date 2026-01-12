{$IFDEF HELPERS}
function CountingSort(const aAscending: Boolean = True): Integer;
function RadixSort(const aAscending: Boolean = True): Integer;
function SegmentedCountingSort(const aAscending: Boolean = True; const bucketSize: Integer = 1024): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <CountingSort>
  @action: Sorts the integer array using the classical counting sort algorithm.
           Works efficiently when the range of integer values is relatively small.
  @note:
    - This method handles negative and positive integers.
    - The algorithm counts the occurrences of each integer and writes them back
      in sorted order.
    - Always sorts in ascending order; descending order is not supported in this version.
    - Counting array size is based on the range of values in the array, so large
      ranges may use significant memory.
[==============================================================================}
function TIntegerArrayHelper.CountingSort(const aAscending: Boolean = True): Integer;
var
  c: TIntegerArray;
  i, j, s, o: Integer;
  m: TRange;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  m := Self.Bounds;
  o := -m.start;
  SetLength(c, m.Size);
  for i := 0 to High(Self) do
    Inc(c[Self[i] + o]);
  s := 0;
  for i := 0 to m.Span do
    for j := 1 to c[i] do
      Self[s.Increase] := (i - o);
  if not aAscending then
    Self.Reverse;
end;

{==============================================================================]
  <RadixSort>
  @action: RadixSort for TIntegerArrays.
  @note: Returns High(arr).
[==============================================================================}
function TIntegerArrayHelper.RadixSort(const aAscending: Boolean = True): Integer;
var
  a, n: TIntegerArray;
  c: array[0..9] of Integer;
  x, y, i, j, m, e: Integer;
begin
  Result := High(Self);
  if (Result < 1) then
    Exit;
  SetLength(n, (Result + 1));
  SetLength(a, (Result + 1));
  x := 0;
  y := 0;
  for i := 0 to Result do
    if (Self[i] < 0) then
      n[x.Increase] := -Self[i]
    else
      a[y.Increase] := Self[i];
  SetLength(n, x);
  SetLength(a, y);
  if (x > 0) then
  begin
    m := n[0];
    for i := 1 to (x - 1) do
      if (n[i] > m) then
        m := n[i];
    e := 1;
    while ((m div e) > 0) do
    begin
      for j := 0 to 9 do
        c[j] := 0;
      for i := 0 to (x - 1) do
        Inc(c[(n[i] div e) mod 10]);
      for j := 8 downto 0 do
        c[j] := (c[j] + c[j + 1]);
      SetLength(Self, x);
      for i := (x - 1) downto 0 do
        Self[c[((n[i] div e) mod 10)].Decrement] := n[i];
      for i := 0 to (x - 1) do
        n[i] := Self[i];
      e := (e * 10);
    end;
    for i := 0 to (x - 1) do
      n[i] := -n[i];
  end;
  if (y > 0) then
  begin
    m := a[0];
    for i := 1 to (y - 1) do
      if (a[i] > m) then
        m := a[i];
    e := 1;
    while ((m div e) > 0) do
    begin
      for j := 0 to 9 do
        c[j] := 0;
      for i := 0 to (y - 1) do
        Inc(c[(a[i] div e) mod 10]);
      for j := 1 to 9 do
        c[j] := (c[j] + c[j - 1]);
      SetLength(Self, y);
      for i := (y - 1) downto 0 do
        Self[c[(a[i] div e) mod 10].Decrement] := a[i];
      for i := 0 to (y - 1) do
        a[i] := Self[i];
      e := (e * 10);
    end;
  end;
  if aAscending then
    Self := (n + a)
  else
    Self := (a.Reversed + n.Reversed);
end;

{==============================================================================]
 <SegmentedCountingSort>
 @action: Performs a counting sort over the integer array using a small
          bucket-based approach. Supports ascending or descending order.
 @note:   Returns the number of elements in the array (Length(Self)).
          Sorting is done in-place using an auxiliary array.
          Efficient for moderate-sized integer ranges with many repeated values.
[==============================================================================}
function TIntegerArrayHelper.SegmentedCountingSort(const aAscending: Boolean = True; const bucketSize: Integer = 1024): Integer;
var
  i, l: Integer;
  c, s: TIntegerArray;
  m, r: TRange;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  m := Self.Bounds;
  SetLength(s, Self.Size);
  l := 0;
  if aAscending then
  begin
    r.start := m.start;
    while (r.start <= m.stop) do
    begin
      r.stop := Integer((r.start + bucketSize) - 1).ClampMax(m.stop);
      SetLength(c, ((r.stop - r.start) + 1));
      for i := 0 to High(Self) do
        if (Self[i] >= r.start) and (Self[i] <= r.stop) then
          Inc(c[Self[i] - r.start]);
      for i := 0 to High(c) do
        while c[i].AdjustMin(-1, 0) do
          s[l.Increase] := (r.start + i);
      Inc(r.start, bucketSize);
    end;
  end
  else
  begin
    r.start := m.stop;
    while (r.start >= m.start) do
    begin
      r.stop := Integer((r.start - bucketSize) + 1).ClampMin(m.start);
      SetLength(c, ((r.start - r.stop) + 1));
      for i := 0 to High(Self) do
        if (Self[i] >= r.stop) and (Self[i] <= r.start) then
          Inc(c[Self[i] - r.stop]);
      for i := High(c) downto 0 do
        while c[i].AdjustMin(-1, 0) do
          s[l.Increase] := (r.stop + i);
      Dec(r.start, bucketSize);
    end;
  end;
  for i := 0 to High(Self) do
    Self[i] := s[i];
end;
{$ENDIF}
