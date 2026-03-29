{$IFDEF HELPERS}
function SortByMaximum(const oAscending: Boolean = True): Integer; overload;
function SortByMinimum(const oAscending: Boolean = True): Integer; overload;
function SortBySize(const oAscending: Boolean = True): Integer; overload;
function SortByStart(const oAscending: Boolean = True): Integer; overload;
function SortByStop(const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <SortByMaximum>
  @action: Sorts array in-place by `Maximum` using QuickSort (asc/desc).
  @note: In-place, not stable. Avg O(n log n), worst O(n^2). Mid pivot ((l+r) div 2).
         Bidirectional partition (i/j). Swap uses Increase/Decrease side-effects.
         Depends on `Maximum` accessor (e.g. normalized upper bound).
         Modifies Self directly. Recursion depth depends on distribution.
         Many equal keys may degrade performance. Returns Length.
[==============================================================================}
function TRangeArrayHelper.SortByMaximum(const oAscending: Boolean = True): Integer; overload;
  procedure QS(l, r: Integer);
  var
    i, j, p: Integer;
  begin
    i := l;
    j := r;
    p := Self[(l + r) div 2].Maximum;
    repeat
      while ((oAscending and (Self[i].Maximum < p)) or ((not oAscending) and (Self[i].Maximum > p))) do
        Inc(i);
      while ((oAscending and (Self[j].Maximum > p)) or ((not oAscending) and (Self[j].Maximum < p))) do
        Dec(j);
      if (i <= j) then
        Swap(Self[i.Increase], Self[j.Decrease]);
    until (i > j);
    if (l < j) then
      QS(l, j);
    if (i < r) then
      QS(i, r);
  end;
begin
  Result := Self.Length;
  if (Result > 1) then
    QS(0, (Result - 1));
end;

{==============================================================================]
  <SortByMinimum>
  @action: Sorts array in-place by `Minimum` using QuickSort (asc/desc).
  @note: In-place, not stable. Avg O(n log n), worst O(n^2). Mid pivot ((l+r) div 2).
         Bidirectional partition (i/j). Swap uses Increase/Decrease side-effects.
         Depends on `Minimum` accessor (e.g. normalized lower bound).
         Modifies Self directly. Recursion depth depends on distribution.
         Many equal keys may degrade performance. Returns Length.
[==============================================================================}
function TRangeArrayHelper.SortByMinimum(const oAscending: Boolean = True): Integer; overload;
  procedure QS(l, r: Integer);
  var
    i, j, p: Integer;
  begin
    i := l;
    j := r;
    p := Self[(l + r) div 2].Minimum;
    repeat
      while ((oAscending and (Self[i].Minimum < p)) or ((not oAscending) and (Self[i].Minimum > p))) do
        Inc(i);
      while ((oAscending and (Self[j].Minimum > p)) or ((not oAscending) and (Self[j].Minimum < p))) do
        Dec(j);
      if (i <= j) then
        Swap(Self[i.Increase], Self[j.Decrease]);
    until (i > j);
    if (l < j) then
      QS(l, j);
    if (i < r) then
      QS(i, r);
  end;
begin
  Result := Self.Length;
  if (Result > 1) then
    QS(0, (Result - 1));
end;

{==============================================================================]
  <SortBySize>
  @action: Sorts the TRangeArray in-place by the size of its elements.
           The sorting order is determined by the oAscending parameter:
             - True: ascending (smallest to largest)
             - False: descending (largest to smallest)
  @note: Returns the number of elements in the array.
         If the array has fewer than 2 elements, no sorting is performed.
[==============================================================================}
function TRangeArrayHelper.SortBySize(const oAscending: Boolean = True): Integer; overload;
begin
  Result := Self.Length;
  if (Result > 1) then
  case oAscending of
    True: Result := specialize QuickSort<TRange>(Self, @TRange.CompareSizeAscending);
    False: Result := specialize QuickSort<TRange>(Self, @TRange.CompareSizeDescending);
  end;
end;

{==============================================================================]
  <SortByStart>
  @action: Sorts array in-place by `start` using QuickSort (asc/desc).
  @note: In-place, not stable. Avg O(n log n), worst O(n^2). Mid pivot ((l+r) div 2).
         Bidirectional partition (i/j). Swap uses Increase/Decrease side-effects.
         Modifies Self directly. Recursion depth depends on data distribution.
         Many equal keys may degrade performance. Returns Length.
[==============================================================================}
function TRangeArrayHelper.SortByStart(const oAscending: Boolean = True): Integer; overload;
  procedure QS(l, r: Integer);
  var
    i, j, p: Integer;
  begin
    i := l;
    j := r;
    p := Self[(l + r) div 2].start;
    repeat
      while ((oAscending and (Self[i].start < p)) or ((not oAscending) and (Self[i].start > p))) do
        Inc(i);
      while ((oAscending and (Self[j].start > p)) or ((not oAscending) and (Self[j].start < p))) do
        Dec(j);
      if (i <= j) then
        Swap(Self[i.Increase], Self[j.Decrease]);
    until (i > j);
    if (l < j) then
      QS(l, j);
    if (i < r) then
      QS(i, r);
  end;
begin
  Result := Self.Length;
  if (Result > 1) then
    QS(0, (Result - 1));
end;

{==============================================================================]
  <SortByStop>
  @action: Sorts array in-place by `stop` using QuickSort (asc/desc).
  @note: In-place, not stable. Avg O(n log n), worst O(n^2). Mid pivot ((l+r) div 2).
         Bidirectional partition (i/j). Swap uses Increase/Decrease side-effects.
         Modifies Self directly. Recursion depth depends on data distribution.
         Many equal keys may degrade performance. Returns Length.
[==============================================================================}
function TRangeArrayHelper.SortByStop(const oAscending: Boolean = True): Integer; overload;
  procedure QS(l, r: Integer);
  var
    i, j, p: Integer;
  begin
    i := l;
    j := r;
    p := Self[(l + r) div 2].stop;
    repeat
      while ((oAscending and (Self[i].stop < p)) or ((not oAscending) and (Self[i].stop > p))) do
        Inc(i);
      while ((oAscending and (Self[j].stop > p)) or ((not oAscending) and (Self[j].stop < p))) do
        Dec(j);
      if (i <= j) then
        Swap(Self[i.Increase], Self[j.Decrease]);
    until (i > j);
    if (l < j) then
      QS(l, j);
    if (i < r) then
      QS(i, r);
  end;
begin
  Result := Self.Length;
  if (Result > 1) then
    QS(0, (Result - 1));
end;
{$ENDIF}
