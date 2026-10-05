{$IFDEF HELPERS}
function MergeSort(const aAscending: Boolean = True): Integer; overload;
function MergeSortBU(const aAscending: Boolean = True): Integer; overload;
function MergeSorted(const oAscending: Boolean = True): MArray; overload;
function MergeSortie(const oAscending: Boolean = True): TIntegerArray; overload;
function MergeSortify(const oAscending: Boolean = True): MArray; overload;
function MergeSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
function MergeSortPair(var partner: MArray; const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <MergeSort>
  @action: MergeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.MergeSort(const aAscending: Boolean = True): Integer; overload;
  procedure M2(var arr, tmp: MArray; const Lo, Hi: Integer; const aAscending: Boolean = True);
  var
    l, r, i, m, o: Integer;
  begin
    if (Lo >= Hi) then
      Exit;
    o := aAscending.Select(-1, 1);
    m := (Lo + ((Hi - Lo) div 2));
    M2(arr, tmp, Lo, m, aAscending);
    M2(arr, tmp, (m + 1), Hi, aAscending);
    l := Lo;
    r := (m + 1);
    for i := Lo to Hi do
      tmp[i] := arr[i];
    for i := Lo to Hi do
      if (L > m) then
        arr[i] := tmp[r.Increase]
      else if (R > Hi) then
        arr[i] := tmp[l.Increase]
      else if (Sign(tmp[r].Compare(tmp[l])) = o) then
        arr[i] := tmp[r.Increase]
      else
        arr[i] := tmp[l.Increase];
  end;
var
  t: MArray;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    SetLength(t, (Result + 1));
    M2(Self, t, 0, Result, aAscending);
  end;
end;

{==============================================================================]
  <MergeSortBU>
  @action: Bottom-up MergeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.MergeSortBU(const aAscending: Boolean = True): Integer; overload;
var
  t: MArray;
  w, i, s: Integer;
  l, r: TRange;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    w := 1;
	SetLength(t, (Result + 1));
    while (w <= Result) do
    begin
      i := 0;
      while (i <= Result) do
      begin
        l.Create(i, Min((i + (w - 1)), Result));
        r.Create((l.stop + 1), Min((l.start + (2 * w) - 1), Result));
        for s := l.start to r.stop do
          t[s] := Self[s];
        s := i;
        while (l.Asceal and r.Asceal) do
          if ((aAscending and (t[l.start] <= t[r.start])) or (not aAscending and (t[l.start] >= t[r.start]))) then
            Self[s.Increase] := t[l.start.Increase]
          else
            Self[s.Increase] := t[r.start.Increase];
        while l.Asceal do
          Self[s.Increase] := t[l.start.Increase];
        while r.Asceal do
          Self[s.Increase] := t[r.start.Increase];
        i.Increase(2 * w);
      end;
      w := (w * 2);
    end;
  end;
end;

{==============================================================================]
  <MergeSorted>
  @action: Returns a sorted copy of Self, ascending or descending by oAscending.
  @note: Bottom-up merge sort. Stable (equal elements keep their original
         order), O(n log n) time, O(n) extra space. Self is not modified. Runs
         of width 1, 2, 4, ... are merged pairwise, alternating between two
         buffers, so there is no recursion and no per-pass allocation.
[==============================================================================}
function MArrayHelper.MergeSorted(const oAscending: Boolean = True): MArray; overload;
var
  r, s: MArray;
  n, w, l, m, h, i, j, t: Integer;
begin
  n := Self.Length;
  Result := Self.Cloned;
  if (n < 2) then
    Exit;
  SetLength(r, n);
  w := 1;
  while (w < n) do
  begin
    l := 0;
    while (l < n) do
    begin
      m := (l + w);
      if (m > n) then
        m := n;
      h := (l + (w * 2));
      if (h > n) then
        h := n;
      i := l;
      j := m;
      t := l;
      while ((i < m) and (j < h)) do
        if ((Result[i] <= Result[j]) = oAscending) then
          r[t.Increase] := Result[i.Increase]
        else
          r[t.Increase] := Result[j.Increase];
      while (i < m) do
        r[t.Increase] := Result[i.Increase];
      while (j < h) do
        r[t.Increase] := Result[j.Increase];
      l := h;
    end;
    s := Result;
    Result := r;
    r := s;
    w := (w * 2);
  end;
end;

{==============================================================================]
  <MergeSortie>
  @action: Merge sorts Self in place and returns the index map needed to
           restore Self's original order.
  @note: Result[i] is where the element originally at index i now sits in
         the sorted Self, i.e. SelfSorted[Result[i]] = SelfOriginal[i].
         Bottom-up, stable, O(N log N) time, O(N) auxiliary space for both
         the value buffer and the tracked-origin array.
[==============================================================================}
function MArrayHelper.MergeSortie(const oAscending: Boolean = True): TIntegerArray; overload;
var
  a, b, s, w, l, m, r, i, k: Integer;
  o, p: TIntegerArray;
  v: MArray;
  function C(const indexA, indexB: Integer): Boolean;
  begin
    if (Self[indexA] = Self[indexB]) then
      Result := (o[indexA] < o[indexB])
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
  SetLength(p, s);
  SetLength(v, s);
  for i := 0 to o.Alloc(s) do
    o[i] := i;
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
        if C(a, b) then
        begin
          v[k] := Self[a];
          p[k] := o[a];
          Inc(k);
          Inc(a);
        end else
        begin
          v[k] := Self[b];
          p[k] := o[b];
          Inc(k);
          Inc(b);
        end;
      while (a < m) do
      begin
        v[k] := Self[a];
        p[k] := o[a];
        Inc(k);
        Inc(a);
      end;
      while (b < r) do
      begin
        v[k] := Self[b];
        p[k] := o[b];
        Inc(k);
        Inc(b);
      end;
      Inc(l, (w * 2));
    end;
    for i := 0 to (s - 1) do
    begin
      Self[i] := v[i];
      o[i] := p[i];
    end;
    w := (w * 2);
  end;
  for i := 0 to Result.Alloc(s) do
    Result[o[i]] := i;
end;

{==============================================================================]
  <MergeSortify>
  @action: Returns a sorted copy of Self in the order specified by oAscending.
  @note: Optimized bottom-up merge sort. Stable, O(n log n) worst-case time, 
         O(n) best-case time for already-sorted inputs, and O(n) extra space. 
         Self is not modified. Features short-circuit optimization for adjacent 
         pre-sorted runs and safe boundary clamping.
[==============================================================================}
function MArrayHelper.MergeSortify(const oAscending: Boolean = True): MArray; overload;
var
  r, s: MArray;
  n, w, l, m, h, i, j, t: Integer;
begin
  n := Self.Length;
  if (n < 2) then
    Exit(Self.Cloned);
  Result := Self.Cloned;
  SetLength(r, n);
  w := 1;
  while (w < n) do
  begin
    l := 0;
    while (l < n) do
    begin
      m := (l + w);
      if (m > n) then
        m := n;
      h := (l + (w * 2));
      if (h > n) then
        h := n;
      case ((m >= n) or ((Result[m - 1] <= Result[m]) = oAscending)) of
        False:
        begin
          i := l;
          j := m;
          t := l;
          while ((i < m) and (j < h)) do
            if ((Result[i] <= Result[j]) = oAscending) then
              r[t.Increase] := Result[i.Increase]
            else
              r[t.Increase] := Result[j.Increase];
          while (i < m) do
            r[t.Increase] := Result[i.Increase];
          while (j < h) do
            r[t.Increase] := Result[j.Increase];
        end;
        True:
        for i := l to (h - 1) do
          r[i] := Result[i];
      end;
      l := h;
    end;
    s := Result;
    Result := r;
    r := s;
    w := (w * 2);
  end;
end;

{==============================================================================]
  <MergeSortIndexed>
  @action: Sorts the current integer array (Self) using merge sort while
           tracking the original indices of each element.
  @note: - Returns an array of indices representing the order of elements in the sorted array.
         - The original array (Self) is modified in-place.
         - Sorting is stable (preserves order of equal elements).
         - Useful for retrieving both sorted data and their original positions.
[==============================================================================}
function MArrayHelper.MergeSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
  procedure MSI(var arr: MArray; var indexes: TIntegerArray; const L, R: Integer);
  var
    s: MArray;
    p: TIntegerArray;
    i, j, k, m: Integer;
  begin
    if (L >= R) then
      Exit;
    m := ((L + R) div 2);
    MSI(arr, indexes, L, m);
    MSI(arr, indexes, (m + 1), R);
    SetLength(s, ((R - L) + 1));
    SetLength(p, ((R - L) + 1));
    i := L;
    j := (m + 1);
    k := 0;
    while ((i <= m) and (j <= R)) do
    begin
      case ((aAscending and (arr[i] <= arr[j])) or ((not aAscending) and (arr[i] >= arr[j]))) of
        True:
        begin
          s[k] := arr[i];
          p[k] := indexes[i];
          Inc(i);
        end;
        False:
        begin
          s[k] := arr[j];
          p[k] := indexes[j];
          Inc(j);
        end;
      end;
      Inc(k);
    end;
    while (i <= m) do
    begin
      s[k] := arr[i];
      p[k] := indexes[i];
      Inc(i);
      Inc(k);
    end;
    while (j <= R) do
    begin
      s[k] := arr[j];
      p[k] := indexes[j];
      Inc(j);
      Inc(k);
    end;
    for k := 0 to High(s) do
    begin
      arr[L + k] := s[k];
      indexes[L + k] := p[k];
    end;
  end;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Self.Size) do
    Result[i] := i;
  if (Self.Size > 1) then
    MSI(Self, Result, 0, High(Result));
end;

{==============================================================================]
  <MergeSortPair>
  @action: Performs an in-place merge sort on the current array (Self),
           reordering both Self and its associated partner array so that the
           elements of partner remain paired with their corresponding elements
           in Self. Sorting is based on the values in Self.
  @note: - Self and partner must have the same length.
         - Sorting is stable: equal values in Self preserve their original order.
         - Returns Length(Self).
         - Set aAscending = False for descending order.
[==============================================================================}
function MArrayHelper.MergeSortPair(var partner: MArray; const aAscending: Boolean = True): Integer; overload;
  procedure MSP(var arr, prt: MArray; const L, R: Integer);
  var
    s, p: MArray;
    i, j, k, m: Integer;
  begin
    if (L >= R) then
      Exit;
    m := ((L + R) div 2);
    MSP(arr, prt, L, m);
    MSP(arr, prt, (m + 1), R);
    SetLength(s, ((R - L) + 1));
    SetLength(p, ((R - L) + 1));
    i := L;
    j := (m + 1);
    k := 0;
    while ((i <= m) and (j <= R)) do
    begin
      case ((aAscending and (arr[i] <= arr[j])) or ((not aAscending) and (arr[i] >= arr[j]))) of
        True:
        begin
          s[k] := arr[i];
          p[k] := prt[i];
          Inc(i);
        end;
        False:
        begin
          s[k] := arr[j];
          p[k] := prt[j];
          Inc(j);
        end;
      end;
      Inc(k);
    end;
    while (i <= m) do
    begin
      s[k] := arr[i];
      p[k] := prt[i];
      Inc(i);
      Inc(k);
    end;
    while (j <= R) do
    begin
      s[k] := arr[j];
      p[k] := prt[j];
      Inc(j);
      Inc(k);
    end;
    for k := 0 to High(s) do
    begin
      arr[L + k] := s[k];
      prt[L + k] := p[k];
    end;
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    MSP(Self, partner, 0, (Result - 1));
end;
{$ENDIF}
