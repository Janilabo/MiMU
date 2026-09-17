{$IFDEF HELPERS}
function BinaryTreeSort(const oAscending: Boolean = True): Integer; overload;
function BinarySortie(const oAscending: Boolean = True): TIntegerArray; overload;
function BrickSort(const oAscending: Boolean = True): Integer; overload;
function CoctailSort(const aAscending: Boolean = True): Integer; overload;
function CoctailSort2(const aAscending: Boolean = True): Integer; overload;
function CombSort(const aAscending: Boolean = True): Integer; overload;
function ExchangeSort(const oAscending: Boolean = True): Integer; overload;
function GnomeSort(const aAscending: Boolean = True): Integer; overload;
function GnomeSortOptimized(const aAscending: Boolean = True): Integer; overload;
function InsertionSort(const aAscending: Boolean = True): Integer; overload;
function PancakeSort(const aAscending: Boolean = True): Integer; overload;
function PancakeSort2(const oAscending: Boolean = True): Integer; overload;
function PartitionSort(const aAscending: Boolean = True): Integer; overload;
function ShakerSort(const oAscending: Boolean = True): Integer; overload;
function TreeSort(const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryTreeSort>
  @action: Sorts the array in-place using a preallocated Binary Search Tree.
  @note: Allocates full tree storage once (Length(Self)) before insertion.
         Avoids repeated SetLength calls during node insertion.
         Performs an in-order traversal to rewrite the array.
         Order behavior:
          - oAscending = True  -> left subtree contains smaller values
          - oAscending = False -> left subtree contains larger values
[==============================================================================}
function MArrayHelper.BinaryTreeSort(const oAscending: Boolean = True): Integer; overload;
type
  TTreeNode = record
    value: MType;
    left, right: Integer;
  end;
  TTree = array of TTreeNode;
var
  t: TTree;
  r, i, p, f: Integer;
  procedure InsertNode(const val: MType; var root: Integer);
  var
    c, n: Integer;
  begin
    n := f;
    Inc(f);
    t[n].value := val;
    t[n].left := -1;
    t[n].right := -1;
    if (root = -1) then
    begin
      root := n;
      Exit;
    end;
    c := root;
    while True do
    case (oAscending = (val < t[c].value)) of
      True:
      if (t[c].left = -1) then
      begin
        t[c].left := n;
        Break;
      end else
        c := t[c].left;
      False:
      if (t[c].right = -1) then
      begin
        t[c].right := n;
        Break;
      end else
        c := t[c].right;
    end;
  end;
  procedure TreeOrder(const index: Integer; var output: MArray; var position: Integer);
  begin
    if (index = -1) then
      Exit;
    TreeOrder(t[index].left, output, position);
    output[position] := t[index].value;
    Inc(position);
    TreeOrder(t[index].right, output, position);
  end;
begin
  Result := Self.Length;
  if (Result < 2) then
    Exit;
  SetLength(t, Result);
  r := -1;
  f := 0;
  for i := 0 to (Result - 1) do
    InsertNode(Self[i], r);
  p := 0;
  TreeOrder(r, Self, p);
end;

{==============================================================================]
  <BinarySortie>
  @action: Sorts Self in place via binary insertion sort and returns the
           index map needed to restore Self's original order.
  @note: Result[i] is where the element originally at index i now sits in
         the sorted Self, i.e. SelfSorted[Result[i]] = SelfOriginal[i].
         Uses binary search to pinpoint insertion locations; preserves
         original relative order for equal values. Ideal for small to
         medium-sized arrays.
[==============================================================================}
function MArrayHelper.BinarySortie(const oAscending: Boolean = True): TIntegerArray; overload;
var
  s, i, j, l, h, m, p: Integer;
  o: TIntegerArray;
  v: MType;
  function C(const indexA: Integer): Boolean;
  begin
    if (Self[indexA] = v) then
      Result := (o[indexA] < p)
    else if oAscending then
      Result := (Self[indexA] < v)
    else
      Result := (Self[indexA] > v);
  end;
begin
  s := Self.Length;
  if (s = 0) then
    Exit([]);
  if (s = 1) then
    Exit([0]);
  for i := 0 to o.Alloc(s) do
    o[i] := i;
  for i := 1 to (s - 1) do
  begin
    v := Self[i];
    p := o[i];
    l := 0;
    h := i;
    while (l < h) do
    begin
      m := ((l + h) shr 1);
      if C(m) then
        l := (m + 1)
      else
        h := m;
    end;
    for j := i downto (l + 1) do
    begin
      Self[j] := Self[j - 1];
      o[j] := o[j - 1];
    end;
    Self[l] := v;
    o[l] := p;
  end;
  for i := 0 to Result.Alloc(s) do
    Result[o[i]] := i;
end;

{==============================================================================]
  <BrickSort>
  @action: Sorts the array elements in ascending or descending order using an optimized multi-pass swap recording approach (Brick / Odd-Even Sort variant).
           Returns the total count of swap operations performed.
  @note: Allocates a temporary index buffer `s` to record out-of-order adjacent pairs in a single pass before batch-swapping them in reverse order.
         Operates with a time complexity of O(n) in the best case and O(n²) in the worst case.
[==============================================================================}
function MArrayHelper.BrickSort(const oAscending: Boolean = True): Integer; overload;
var
  h, i, c, l: Integer;
  s: TIntegerArray;
begin
  Result := 0;
  l := Self.Length;
  if (l < 2) then
    Exit;
  h := s.Alloc(l - 1);
  case oAscending of
    True:
    repeat
      c := 0;
      for i := 0 to h do
        if (Self[i] > Self[i + 1]) then
          s[c.Increase] := i;
      for i := (c - 1) downto 0 do
        Self.Switch(s[i], (s[i] + 1));
      Inc(Result, c);
    until (c = 0);
    False:
    repeat
      c := 0;
      for i := 0 to h do
        if (Self[i] < Self[i + 1]) then
          s[c.Increase] := i;
      for i := (c - 1) downto 0 do
        Self.Switch(s[i], (s[i] + 1));
      Inc(Result, c);
    until (c = 0);
  end;
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
  <ExchangeSort>
  @action: Sorts Self in place (ascending or descending) using adjacent-pair
           comparison; each pass buckets out-of-order pairs into `a` (the
           element that moved backward) and in-order elements into `b`, then
           reassembles Self as a+b via C(). Repeats until a pass makes no
           swaps (l = 0).
  @note: Ordered-only tier (uses <, > only — no arithmetic, so it generalizes
         to any comparable T). Allocates two full-length scratch arrays and
         does a full a+b reconstruction every pass, so it's O(n) extra space
         and heavier per-pass data movement than a true in-place exchange
         sort — no shrinking-bound optimization is applied (each pass rescans
         the full array). Correct for all inputs including length 0/1
         (early-exits before allocating).
[==============================================================================}
function MArrayHelper.ExchangeSort(const oAscending: Boolean = True): Integer; overload;
var
  i, l, r: Integer;
  a, b: MArray;
  procedure C(const left, right: Integer);
  var
    j: Integer;
  begin
    for j := 0 to (left - 1) do
      Self[j] := a[j];
    for j := 0 to (right - 1) do
      Self[j + left] := b[j];
  end;
begin
  Result := Self.Length;
  if (Result < 2) then
    Exit;
  SetLength(a, Result);
  SetLength(b, Result);
  case oAscending of
    True:
    repeat
      i := 0;
      l := 0;
      r := 0;
      while (i < Result) do
        if ((i < (Result - 1)) and (Self[i] > Self[i + 1])) then
        begin
          b[r.Increase] := Self[i];
          a[l.Increase] := Self[i + 1];
          Inc(i, 2);
        end else
          b[r.Increase] := Self[i.Increase];
      C(l, r);
    until (l = 0);
    False:
    repeat
      i := 0;
      l := 0;
      r := 0;
      while (i < Result) do
        if ((i < (Result - 1)) and (Self[i] < Self[i + 1])) then
        begin
          b[r.Increase] := Self[i];
          a[l.Increase] := Self[i + 1];
          Inc(i, 2);
        end else
          b[r.Increase] := Self[i.Increase];
      C(l, r);
    until (l = 0);
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
  <PancakeSort2>
  @action: Sorts the array in-place using the Pancake Sort algorithm and
           returns the total length of the array (Self.Length).
  @note: - Uses helper F(N) to reverse the sub-array from index 0 to N-1 (flip).
         - Uses helper B(X,Y) to select the maximum (ascending) or minimum
           (descending) element in the remaining unsorted section.
         - Complexity: O(n²) time complexity with up to 2n - 3 total flips;
           O(1) auxiliary space.
[==============================================================================}
function MArrayHelper.PancakeSort2(const oAscending: Boolean = True): Integer; overload;
procedure F(N: Integer);
var
  L, R: Integer;
begin
  L := 0;
  R := (N - 1);
  while (L < R) do
    Self.Switch(L.Increase, R.Decrease);
end;
function B(X, Y: MType): Boolean;
begin
  if oAscending then
    Result := (X > Y)
  else
    Result := (X < Y);
end;
var
  i, j, m, t: Integer;
begin
  Result := Self.Length;
  for i := (Result - 1) downto 1 do
  begin
    m := 0;
    for j := 1 to i do
      if B(Self[j], Self[m]) then
        m := j;
    if (m <> i) then
    begin
      if (m <> 0) then
        F(m + 1);
      F(i + 1);
    end;
  end;
end;

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
  <ShakerSort>
  @action: Sorts the elements of the array in-place in ascending or descending order using a custom bidirectional boundary-exchange algorithm.
@note: Uses mutating helper methods (Increment/Decrement) to contract left and right pointers
       while performing a single forward sweep per pass that swaps out-of-bounds elements with the active boundaries (l and r).
	   Returns the total count of elements in the array.
[==============================================================================}
function MArrayHelper.ShakerSort(const oAscending: Boolean = True): Integer; overload;
var
  i, l, r: Integer;
begin
  Result := Self.Length;
  if (Result < 2) then
    Exit;
  r := Result;
  l := -1;
  case oAscending of
    True:
    while (l.Increment < r.Decrement) do
      for i := l to (r - 1) do
        if (Self[i] < Self[l]) then
          Self.Switch(i, l)
        else if (Self[i] > Self[r]) then
          Self.Switch(i, r);
    False:
    while (l.Increment < r.Decrement) do
      for i := l to (r - 1) do
        if (Self[i] > Self[l]) then
          Self.Switch(i, l)
        else if (Self[i] < Self[r]) then
          Self.Switch(i, r);
  end;
end;

{==============================================================================]
  <TreeSort>
  @action: Sorts the array in-place using a dynamically growing Binary Search Tree.
  @note: Builds the tree incrementally using SetLength on each insertion.
         Performs an in-order traversal to rewrite the array.
         Order behavior:
          - oAscending = True  -> left subtree contains smaller values
          - oAscending = False -> left subtree contains larger values
[==============================================================================}
function MArrayHelper.TreeSort(const oAscending: Boolean = True): Integer; overload;
type
  TTreeNode = record
    value: MType;
    left, right: Integer;
  end;
  TTree = array of TTreeNode;
var
  t: TTree;
  r, i, p: Integer;
procedure InsertNode(var tree: TTree; const value: MType; var root: Integer);
var
  l, i, t: Integer;
begin
  if (root = -1) then
  begin
    SetLength(tree, 1);
    tree[0].value := value;
    tree[0].left := -1;
    tree[0].right := -1;
    root := 0;
    Exit;
  end;
  i := root;
  repeat
    t := i;
    case (oAscending = (value < tree[i].value)) of
      True:
      if (tree[i].left = -1) then
      begin
        l := System.Length(tree);
        SetLength(tree, (l + 1));
        tree[l].value := value;
        tree[l].left := -1;
        tree[l].right := -1;
        tree[t].left := l;
        Exit;
      end else
        i := tree[i].left;
      False:
      if (tree[i].right = -1) then
      begin
        l := System.Length(tree);
        SetLength(tree, (l + 1));
        tree[l].value := value;
        tree[l].left := -1;
        tree[l].right := -1;
        tree[t].right := l;
        Exit;
      end else
        i := tree[i].right;
    end;
  until False;
end;
procedure TreeOrder(const tree: TTree; const index: Integer; var output: MArray; var position: Integer);
begin
  if (Index = -1) then
    Exit;
  TreeOrder(tree, tree[index].left, output, position);
  Output[position] := tree[index].value;
  Inc(position);
  TreeOrder(tree, tree[index].right, output, position);
end;
begin
  Result := Self.Length;
  if (Result < 2) then
    Exit;
  r := -1;
  for i := 0 to (Result - 1) do
    InsertNode(t, Self[i], r);
  SetLength(Self, System.Length(t));
  p := 0;
  TreeOrder(t, r, Self, p);
end;
{$ENDIF}
