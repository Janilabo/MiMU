{$IFDEF HELPERS}
function SelectedSort(const oAscending: Boolean = True): MArray; overload;
function SelectionSort(const aAscending: Boolean = True): Integer; overload;
function SelectionSortBidirectional(const aAscending: Boolean = True): Integer; overload;
function SelectionSortBidirectional2(const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <SelectedSort>
  @action: Returns a new allocated array containing the sorted elements using a
           hybrid pre-filtering phase followed by Selection Sort.
  @note: - Allocates memory for the target result array using `Result.Alloc`.
         - Phase 1: Uses a two-pointer pass (`l`, `r`) and helper `S` to copy
           pairs from outer edges into the `Result` array in preliminary
           min/max relative order.
         - Phase 2: Performs standard Selection Sort on the `Result` array
           by repeatedly scanning for the extremum (minimum for ascending,
           maximum for descending) and placing it via `Result.Switch`.
         - Complexity: O(N²) time complexity dominated by the Selection Sort
           loops; O(N) auxiliary space for the allocated result array.
[==============================================================================}
function MArrayHelper.SelectedSort(const oAscending: Boolean = True): MArray; overload;
var
  h, i, l, r, k, j: Integer;
procedure S(const left, right: MType);
begin
  Result[l.Increase] := left;
  Result[r.Decrease] := right;
end;
begin
  h := Result.Alloc(Self.Length);
  if (h = -1) then
    Exit;
  r := h;
  l := 0;
  case oAscending of
    True:
    begin
      while (l <= r) do
        if (Self[l] > Self[r]) then
          S(Self[r], Self[l])
        else
          S(Self[l], Self[r]);
      for i := 0 to (h - 1) do
      begin
        k := i;
        for j := (i + 1) to h do
          if (Result[j] < Result[k]) then
            k := j;
        if (k <> i) then
          Result.Switch(i, k);
      end;
    end;
    False:
    begin
      while (l <= r) do
        if (Self[l] < Self[r]) then
          S(Self[r], Self[l])
        else
          S(Self[l], Self[r]);
      for i := 0 to (h - 1) do
      begin
        k := i;
        for j := (i + 1) to h do
          if (Result[j] > Result[k]) then
            k := j;
        if (k <> i) then
          Result.Switch(i, k);
      end;
    end;
  end;
end;

{==============================================================================]
  <SelectionSort>
  @action: SelectionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.SelectionSort(const aAscending: Boolean = True): Integer; overload;
var
  c, t, m, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for c := 0 to Result do
    begin
      m := c;
      for t := (c + 1) to Result do
        if (Sign(Self[t].Compare(Self[m])) = o) then
          m := t;
      Exchange(m, c);
    end;
  end;
end;

{==============================================================================]
  <SelectionSortBidirectional>
  @action: Bidirectional SelectionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.SelectionSortBidirectional(const aAscending: Boolean = True): Integer; overload;
var
  i, s, o: Integer;
  x, y: TRange;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for i := 0 to (Result div 2) do
    begin
      y := x.Init(i, (Result - i));
      if (Sign(Self[x.start].Compare(Self[x.stop])) = -o) then
        Exchange(x.stop, x.start);
      for s := (y.start + 1) to (y.stop - 1) do
        if (Sign(Self[s].Compare(Self[x.start])) = o) then
          x.start := s
        else if (Sign(Self[s].Compare(Self[x.stop])) = -o) then
          x.stop := s;
      if (x.start <> y.start) then
        Exchange(y.start, x.start);
      if (x.stop <> y.stop) then
        Exchange(y.stop, x.stop);
    end;
  end;
end;

{==============================================================================]
  <SelectionSortBidirectional2>
  @action: Bidirectional SelectionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function MArrayHelper.SelectionSortBidirectional2(const aAscending: Boolean = True): Integer; overload;
var
  s, i, o: Integer;
  r: TRange;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for i := 0 to (Result div 2) do
    begin
      r.Create(i, (Result - i));
      if (Sign(Self[r.stop].Compare(Self[r.start])) = o) then
        Exchange(r.start, r.stop);
      for s := (r.start + 1) to (r.stop - 1) do
        if (Sign(Self[s].Compare(Self[r.start])) = o) then
          Exchange(r.start, s)
        else if (Sign(Self[s].Compare(Self[r.stop])) = -o) then
          Exchange(s, r.stop);
      end;
  end;
end;
{$ENDIF}