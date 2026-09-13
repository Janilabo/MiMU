{$IFDEF HELPERS}
function HeapifySort(const oAscending: Boolean = True): Integer; overload;
function HeapSort(const aAscending: Boolean = True): Integer; overload;
function HeapSortie(const oAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <HeapSortie>
  @action: Heapsorts Self in place and returns the index map needed to
           restore Self's original order.
  @note: Result[i] is where the element originally at index i now sits in
         the sorted Self, i.e. SelfSorted[Result[i]] = SelfOriginal[i].
         O(N log N) worst case, O(1) extra space beyond the tracked-origin
         array. Not algorithmically stable, but the origin-index tiebreak in
         C() forces a strict total order, so equal values still end up in
         their original relative order.
[==============================================================================}
function MArrayHelper.HeapSortie(const oAscending: Boolean = True): TIntegerArray; overload;
var
  s, i, e, t: Integer;
  o: TIntegerArray;
  function C(const indexA, indexB: Integer): Boolean;
  begin
    if (Self[indexA] = Self[indexB]) then
      Result := (o[indexA] < o[indexB])
    else if oAscending then
      Result := (Self[indexA] < Self[indexB])
    else
      Result := (Self[indexA] > Self[indexB]);
  end;
  procedure F(const iA, iB: Integer);
  begin
    Self.Switch(iA, iB);
    t := o[iA];
    o[iA] := o[iB];
    o[iB] := t;
  end;
  procedure D(iRoot, iLimit: Integer);
  var
    r, m: Integer;
  begin
    while (((iRoot * 2) + 1) < iLimit) do
    begin
      r := ((iRoot * 2) + 1);
      m := iRoot;
      if C(m, r) then
        m := r;
      if (((r + 1) < iLimit) and C(m, r + 1)) then
        m := (r + 1);
      if (m = iRoot) then
        Exit;
      F(iRoot, m);
      iRoot := m;
    end;
  end;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  if (s = 1) then
    Exit([0]);
  for i := 0 to o.Alloc(s) do
    o[i] := i;
  for i := ((s div 2) - 1) downto 0 do
    D(i, s);
  e := (s - 1);
  while (e > 0) do
  begin
    F(0, e);
    D(0, e.Decrease);
  end;
  for i := 0 to Result.Alloc(s) do
    Result[o[i]] := i;
end;
{$ENDIF}