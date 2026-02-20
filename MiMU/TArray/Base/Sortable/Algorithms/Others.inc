{$IFDEF HELPERS}
function PartitionSort(const aAscending: Boolean = True): Integer; overload;
function CoctailSort(const aAscending: Boolean = True): Integer; overload;
function CoctailSort2(const aAscending: Boolean = True): Integer; overload;
function GnomeSort(const aAscending: Boolean = True): Integer; overload;
function GnomeSortOptimized(const aAscending: Boolean = True): Integer; overload;
function PancakeSort(const aAscending: Boolean = True): Integer; overload;
function CombSort(const aAscending: Boolean = True): Integer; overload;
function HeapifySort(const oAscending: Boolean = True): Integer; overload;
function HeapSort(const aAscending: Boolean = True): Integer; overload;
function InsertionSort(const aAscending: Boolean = True): Integer; overload;
function ShellSort(const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <PartitionSort>
  @action: Sorts the array (Self) in ascending or descending order using a
           stable partition-based recursive sorting algorithm.
  @note:   - Returns Length(Self)
           - The algorithm is conceptually similar to QuickSort but uses
             stable partitioning (no in-place swaps).
           - Equal elements preserve their original order (stable).
           - Uses auxiliary arrays, trading memory for stability.
           - Also known as "Stable QuickSort".
[==============================================================================}
function MArrayHelper.PartitionSort(const aAscending: Boolean = True): Integer; overload;
  procedure PS(var A: MArray; const L, R: Integer);
  var
    p: MType;
    i, t: Integer;
    s, e, b: MArray;
  begin
    if (L >= R) then
      Exit;
    p := A[(L + R) div 2];
    SetLength(s, 0);
    SetLength(e, 0);
    SetLength(b, 0);
    for i := L to R do
    case A[i].Compare(p) of
      -1:
      if aAscending then
        s.Supply(A[i])
      else
        b.Supply(A[i]);
      1:
      if aAscending then
        b.Supply(A[i])
      else
        s.Supply(A[i]);
      0: e.Supply(A[i]);
    end;
    if (s.Size > 1) then
      PS(s, 0, High(s));
    if (b.Size > 1) then
      PS(b, 0, High(b));
    t := L;
    for i := 0 to High(s) do
      A[t.Increase] := s[i];
    for i := 0 to High(e) do
      A[t.Increase] := e[i];
    for i := 0 to High(b) do
      A[t.Increase] := b[i];
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    PS(Self, 0, (Result - 1));
end;

{==============================================================================]
  <CoctailSort>
  @action: CoctailSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.CoctailSort(const aAscending: Boolean = True): Integer; overload;
var
  i, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    repeat
      s := False;
      for i := 0 to (Result - 1) do
        if (Sign(Self[i + 1].Compare(Self[i])) = o) then
        begin
          Exchange(i, (i + 1));
          s := True;
        end;
      if not s then
        Break;
      s := False;
      for i := (Result - 1) downto 0 do
         if (Sign(Self[i + 1].Compare(Self[i])) = o) then
        begin
          Exchange(i, (i + 1));
          s := True;
        end;
    until not s;
  end;
end;

{==============================================================================]
  <CoctailSort2>
  @action: CoctailSort algorithm.
  @note: CoctailSort v2. Returns High(arr).
[==============================================================================}
function MArrayHelper.CoctailSort2(const aAscending: Boolean = True): Integer; overload;
var
  b, e, i, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    b := -1;
    e := (Self.Size - 2);
    repeat
      s := False;
      Inc(b);
      for i := b to e do
        if not (Sign(Self[i].Compare(Self[i + 1])) = o) then
        begin
          Exchange(i, (i + 1));
          s := True;
        end;
      if not s then
        Break;
      s := False;
      Dec(e);
      for i := e downto b do
        if not (Sign(Self[i].Compare(Self[i + 1])) = o) then
        begin
          Exchange(i, (i + 1));
          s := True;
        end;
    until not s;
  end;
end;

{==============================================================================]
  <GnomeSort>
  @action: GnomeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.GnomeSort(const aAscending: Boolean = True): Integer; overload;
var
  o, p: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    p := 1;
    while (p <= Result) do
      if (Sign(Self[p].Compare(Self[p - 1])) = o) then
      begin
        Exchange(p, (p - 1));
        if (p > 1) then
          Dec(p);
      end else
        Inc(p);
  end;
end;

{==============================================================================]
  <GnomeSortOptimized>
  @action: Optimized GnomeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.GnomeSortOptimized(const aAscending: Boolean = True): Integer; overload;
var
  p, l, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    p := 1;
    l := 0;
    while (p <= Result) do
      if (Sign(Self[p].Compare(Self[p - 1])) = o) then
      begin
        Exchange(p, (p - 1));
        if (p > 1) then
        begin
          if (l <> 0) then
            l := p
          else
            Dec(p);
        end else
          Inc(p);
      end else
        if (l <> 0) then
        begin
          p := l;
          l := 0;
        end else
          Inc(p);
  end;
end;

{==============================================================================]
  <PancakeSort>
  @action: PancakeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.PancakeSort(const aAscending: Boolean = True): Integer; overload;
var
  i, j, l, m, x, o: Integer;
begin
  Result := High(Self);
  if (Result > 0 )then
  begin
    o := aAscending.Select(-1, 1);
    l := 0;
    for i := Result downto l do
    begin
      m := i;
      for j := l to (i - 1) do
        if (Sign(Self[m].Compare(Self[j])) = o) then
          m := j;
      if (m = i) then
        Continue;
      if (m <> l) then
      for x := l to (((m - l) - 1) div 2) do
        Exchange(x, (m - (x - l)));
      for x := l to (((i - l) - 1) div 2) do
        Exchange(x, (i - (x - l)));
    end;
  end;
end;

{==============================================================================]
  <CombSort>
  @action: CombSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.CombSort(const aAscending: Boolean = True): Integer; overload;
var
  i, g, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    g := Self.Size;
    s := True;
    while ((g > 1) or s) do
    begin
      g := Trunc(g / 1.3);
      if (g < 1) then
        g := 1;
      s := False;
      for i := 0 to (Result - g) do
        if (Sign(Self[i + g].Compare(Self[i])) = o) then
        begin
          Exchange(i, (i + g));
          s := True;
        end;
    end;
  end;
end;

{==============================================================================]
  <HeapifySort>
  @action: Performs an in-place sort of the array using a binary heap structure.
  @note: Guarantees O(n log n) time complexity. Memory efficient with O(1) 
         space. Uses an iterative "sinking" method to prevent stack overflow.
[==============================================================================}
function MArrayHelper.HeapifySort(const oAscending: Boolean = True): Integer; overload;
procedure MaxHeapify(var arr: MArray; index, heap: Integer);
var
  m, l, r: Integer;
begin
  while True do
  begin
    l := ((2 * index) + 1);
    r := ((2 * index) + 2);
    m := index;
    if ((l < heap) and (oAscending = (arr[l] > arr[m]))) then
      m := l;
    if ((r < heap) and (oAscending = (arr[r] > arr[m]))) then
      m := r;
    if (m = index) then
      Break;
    Swap(arr[index], arr[m]);
    index := m;
  end;
end;
procedure BuildMaxHeap(var arr: MArray);
var
  i, l: Integer;
begin
  l := arr.Length;
  for i := ((l div 2) - 1) downto 0 do
    MaxHeapify(arr, i, l);
end;
var
  i: Integer;
begin
  Result := High(Self);
  if (Result < 1) then
    Exit;
  BuildMaxHeap(Self);
  for i := Result downto 1 do
  begin
    Swap(Self[0], Self[i]);
    MaxHeapify(Self, 0, i);
  end;
end;

{==============================================================================]
  <HeapSort>
  @action: HeapSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.HeapSort(const aAscending: Boolean = True): Integer; overload;
var
  a, b, r, c, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    a := (Result div 2);
    b := Result;
    while (a >= 0) do
    begin
      r := a;
      while (((r * 2) + 1) <= Result) do
      begin
        c := ((r * 2) + 1);
        if ((c < Result) and (Sign(Self[c].Compare(Self[c + 1])) = o)) then
          c := (c + 1);
        if (Sign(Self[r].Compare(Self[c])) = o) then
        begin
          Exchange(r, c);
          r := c;
        end else
          Break;
      end;
      a := (a - 1);
    end;
    while (b > 0) do
    begin
      Exchange(0, b);
      b := (b - 1);
      r := 0;
      while (((r * 2) + 1) <= b) do
      begin
        c := ((r * 2) + 1);
        if ((c < b) and (Sign(Self[c].Compare(Self[c + 1])) = o)) then
          c := (c + 1);
        if (Sign(Self[r].Compare(Self[c])) = o) then
        begin
          Exchange(r, c);
          r := c;
        end else
          Break;
      end;
    end;
  end;
end;

{==============================================================================]
  <InsertionSort>
  @action: InsertionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.InsertionSort(const aAscending: Boolean = True): Integer; overload;
var
  a, b, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for a := 1 to Result do
      for b := a downto 1 do
        if (Sign(Self[b].Compare(Self[b - 1])) = o) then
		  Exchange(b, (b - 1))
		else
          Break;
  end;
end;

{==============================================================================]
  <ShellSort>
  @action: ShellSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.ShellSort(const aAscending: Boolean = True): Integer; overload;
var
  x, a, b, l, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    case (Result > 1) of
      True:
      begin
        l := Self.Length;
        x := 0;
        while (x < (l div 3)) do
          x := ((x * 3) + 1);
        while (x >= 1) do
        begin
          for a := x to (l - 1) do
          begin
            b := a;
            while ((b >= x) and (Sign(Self[b].Compare(Self[b - x])) = o)) do
	    begin
              Exchange(b, (b - x));
	      b.Decrease(x);
	    end;
          end;
          x := (x div 3);
        end;
      end;
      False:
      if (Sign(Self[1].Compare(Self[0])) = o) then
        Exchange(0, 1);
    end;
  end;
end;
{$ENDIF}
