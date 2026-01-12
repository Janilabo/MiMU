{$IFDEF HELPERS}
function MergeSortPair(var partner: MArray; const aAscending: Boolean = True): Integer; overload;
function MergeSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
function MergeSort(const aAscending: Boolean = True): Integer; overload;
function MergeSortBU(const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
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

{==============================================================================]
  <MergeSort>
  @action: MergeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.MergeSort(const aAscending: Boolean = True): Integer; overload;
  procedure Merge(var arr, tmp: MArray; const Lo, Hi: Integer; const aAscending: Boolean = True);
  var
    l, r, i, m, o: Integer;
  begin
    if (Lo >= Hi) then
      Exit;
    o := aAscending.Select(-1, 1);
    m := (Lo + ((Hi - Lo) div 2));
    Merge(arr, tmp, Lo, m, aAscending);
    Merge(arr, tmp, (m + 1), Hi, aAscending);
    l := Lo;
    r := (m + 1);
    for i := Lo to Hi do
      tmp[i] := arr[i];
    for i := Lo to Hi do
      if (L > m) then
        arr[i] := tmp[r.Increase]
      else
        if (R > Hi) then
          arr[i] := tmp[l.Increase]
        else
          if (Sign(tmp[r].Compare(tmp[l])) = o) then
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
    Merge(Self, t, 0, Result, aAscending);
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
        while (l.Ascending and r.Ascending) do
		  if ((aAscending and (t[l.start] <= t[r.start])) or (not aAscending and (t[l.start] >= t[r.start]))) then
            Self[s.Increase] := t[l.start.Increase]
          else
            Self[s.Increase] := t[r.start.Increase];
        while l.Ascending do
          Self[s.Increase] := t[l.start.Increase];
        while r.Ascending do
          Self[s.Increase] := t[r.start.Increase];
        i.Increase(2 * w);
      end;
      w := (w * 2);
    end;
  end;
end;
{$ENDIF}