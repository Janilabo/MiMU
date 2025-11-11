{$I config\Defines.inc}

{==============================================================================]
  <HArr.Sortable>
  @action: Checks whether the array contains at least two different elements.
           Returns True if sorting would change the array order.
  @note: Arrays with all equal elements, a single element, or empty arrays
         return False.
[==============================================================================}
function HArr.Sortable: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i] <> Self[i - 1]) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <HArr.Sorted>
  @action: Returns true if array arr is in ascending/descending order by aAscending.
  @note: By default checking for ascending order.
[==============================================================================}
function HArr.Sorted(const aAscending: Boolean = True): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to (High(Self) - 1) do
    if (aAscending and (Self[i] > Self[i + 1])) or ((not aAscending) and (Self[i] < Self[i + 1])) then
      Exit(False);
  Result := (not Self.Empty);
end;

{==============================================================================]
 <arr.IsSorted>
 @action: Checks whether the entire array is sorted in ascending or descending order.
 @note:   Returns True if all elements are in the correct order according to aAscending.
[==============================================================================}
function HArr.IsSorted(const aAscending: Boolean = True): Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if ((aAscending and (Self[i] < Self[i - 1])) or ((not aAscending) and (Self[i] > Self[i - 1]))) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
 <arr.IsSorted>
 @action: Checks whether the elements between iStart and iStop are in correct
          ascending or descending order.
 @note: The range [iStart..iStop] is automatically normalized and clamped to
        valid array bounds. Returns True if all elements within the range
        follow the specified order.
[==============================================================================}
function HArr.IsSorted(const iStart, iStop: Integer; const aAscending: Boolean = True): Boolean; overload;
var
  i, s, e, h: Integer;
begin
  h := High(Self);
  if (h <= 0) then
    Exit(True);
  s := Max(0, Min(iStart, iStop));
  e := Min(Max(iStart, iStop), h);
  if (s >= e) then
    Exit(True);
  for i := (s + 1) to e do
    if ((aAscending and (Self[i] < Self[i - 1])) or ((not aAscending) and (Self[i] > Self[i - 1]))) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
 <arr.IsSorted>
 @action: Determines whether the array elements within the specified range
          (given as TRange) are ordered in ascending or descending order.
 @note: Internally calls the (iStart, iStop) overload. The range is
        automatically normalized and clamped to valid array bounds.
        Returns True if all elements within the range follow the specified order.
[==============================================================================}
function HArr.IsSorted(const indexes: TRange; const aAscending: Boolean = True): Boolean; overload;
begin
  Result := Self.IsSorted(indexes.start, indexes.stop, aAscending);
end;

{==============================================================================]
 <arr.IsSorted>
 @action: Checks whether the element at the specified index is correctly
          positioned relative to its immediate neighbors according to
          ascending or descending order.
 @note: Returns True if the element at the given index maintains proper
        order with adjacent elements. Boundary or single-element arrays are
        considered sorted. Returns False for out-of-range indices.
[==============================================================================}
function HArr.IsSorted(const index: Integer; const aAscending: Boolean = True): Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  if (index < 0) or (index > h) then
    Exit(False);
  if (h = 0) then
    Exit(True);
  if ((index < h) and (aAscending and (Self[index] > Self[index + 1])) or ((not aAscending) and (Self[index] < Self[index + 1]))) then
    Exit(False);
  if ((index > 0) and (aAscending and (Self[index] < Self[index - 1])) or ((not aAscending) and (Self[index] > Self[index - 1]))) then
    Exit(False);
  Result := True;
end; 

{==============================================================================]
  <HArr.InOrder>
  @action: Returns true if array arr is in ascending/descending order by aAscending.
  @note: By default checking for ascending order.
[==============================================================================}
function HArr.InOrder(const aAscending: Boolean = True): Boolean; overload;
var
  i, l: Integer;
begin
  i := -1;
  l := Length(Self);
  Result := (l > 0);
  if (l > 1) then
  case aAscending of
    True:
    while (i.Increment < l.Decrement) do
      if ((Self[i] > Self[i + 1]) or (Self[l - 1] > Self[l])) then
        Exit(False);
    False:
    while (i.Increment < l.Decrement) do
      if ((Self[i] < Self[i + 1]) or (Self[l - 1] < Self[l])) then
        Exit(False);
  end;
end;

{==============================================================================]
  <HArr.Orderly>
  @action: Returns true if array arr is in ascending AND/OR descending order.
  @note: None.
[==============================================================================}
function HArr.Orderly: Boolean; overload;
var
  i: Integer;
  a, d: Boolean;
begin
  a := True;
  d := True;
  for i := 0 to (High(Self) - 1) do
  begin
    if (Self[i] > Self[i + 1]) then
      a := False;
    if (Self[i] < Self[i + 1]) then
      d := False;
    if not (a or d) then
      Break;
  end;
  Result := (a or d);
end;

{==============================================================================]
  <HArr.Ordered>
  @action: Returns true if array arr is in ascending AND/OR descending order by aAscending.
  @note: Recursive alternative.
[==============================================================================}
function HArr.Ordered(const aAscending: Boolean = True; const index: Integer = 0): Boolean; overload;
begin
  if (index >= High(Self)) then
    Exit(True);
  if ((aAscending and (Self[index] > Self[index + 1])) or ((not aAscending) and (Self[index] < Self[index + 1]))) then
    Exit(False);
  Result := Self.Ordered(aAscending, (index + 1));
end;

{==============================================================================]
  <HArr.Order>
  @action: Returns the direction which way array goes
  @note: -1 = DESCENDING, 0=NO ORDER OR MIXED ARRAY, 1=ASCENDING
         [1,2,3] => 1 [1,1,1] => 1 [1,0,1] => 0 [3,2,1] => -1
[==============================================================================}
function HArr.Order: Integer; overload;
var
  i, l: Integer;
  a, d: Boolean;
begin
  l := Length(Self);
  case l of
    0: Exit(0);
	1: Exit(1);
  end;
  a := True;
  d := True;
  for i := 1 to (l - 1) do
  begin
    if (Self[i] < Self[i - 1]) then
      a := False
    else
      if (Self[i] > Self[i - 1]) then
        d := False;
    if not (a or d) then
      Exit(0);
  end;
  if a then
    Result := 1
  else
    if d then
      Result := -1
    else
      Result := 0;
end;

{==============================================================================]
  <HArr.Orientation>
  @action: Returns the direction which way array goes
  @note: -1 = DESCENDING, 0=NO ORDER OR MIXED ARRAY, 1=ASCENDING
         [1,2,3] => 1 [1,1,1] => 0 [1,0,1] => 0 [3,2,1] => -1
[==============================================================================}
function HArr.Orientation: Integer; overload;
var
  i: Integer;
  a, d: Boolean;
begin
  if not Self.Multi then
    Exit(0);
  a := True;
  d := True;
  for i := 1 to High(Self) do
  begin
    if (Self[i] < Self[i - 1]) then
      a := False
    else
      if (Self[i] > Self[i - 1]) then
        d := False;
    if not (a or d) then
      Exit(0);
  end;
  if a then
    Result := 1
  else
    if d then
      Result := -1
    else
      Result := 0;
end;

{==============================================================================]
  <HArr.Ascend>
  @action: Returns array arr sorted to asscending order.
  @note: None.
[==============================================================================}
function HArr.Ascend: TArr; overload;
procedure QS(var arr: TArr; const valLow, valHigh: Integer);
var
  p: TVar;
  r: TRange;
begin
  r.Create(valLow, valHigh);
  p := arr[r.Middle];
  repeat
    while (arr[r.start] < p) do
      Inc(r.start);
    while (arr[r.stop] > p) do
      Dec(r.stop);
    if r.Ascending then
      arr.Exchange(r.start.Increase, r.stop.Decrease);
  until (r.start > r.stop);
  if (valLow < r.stop) then
    QS(arr, valLow, r.stop);
  if (r.start < valHigh) then
    QS(arr, r.start, valHigh);
end;
begin
  Result := Self.Copy;
  if (Length(Result) > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <HArr.Descend>
  @action: Returns array arr sorted to descending order.
  @note: None.
[==============================================================================}
function HArr.Descend: TArr; overload;
procedure QS(var arr: TArr; const valLow, valHigh: Integer);
var
  p, s: TVar;
  r: TRange;
begin
  r.Create(valLow, valHigh);
  p := arr[r.Middle];
  repeat
    while (arr[r.start] > p) do
      Inc(r.start);
    while (arr[r.stop] < p) do
      Dec(r.stop);
    if r.Ascending then
      arr.Exchange(r.start.Increase, r.stop.Decrease);
  until (r.start > r.stop);
  if (valLow < r.stop) then
    QS(arr, valLow, r.stop);
  if (r.start < valHigh) then
    QS(arr, r.start, valHigh);
end;
begin
  Result := Self.Copy;
  if (Length(Result) > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <HArr.Descending>
  @action: Returns true if array arr is in descending order.
  @note: [0,1] = False | [0,0] = False | [1,0] = True |
[==============================================================================}
function HArr.Descending: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i - 1] < Self[i]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <HArr.Ascending>
  @action: Returns true if array arr is in asscending order.
  @note: [0,1] = True | [0,0] = False | [1,0] = False |
[==============================================================================}
function HArr.Ascending: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i - 1] > Self[i]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <HArr.Decreasing>
  @action: Returns true if array arr is in descending order.
  @note: [0,1] = False | [0,0] = True | [1,0] = True |
[==============================================================================}
function HArr.Decreasing: Boolean; overload;
var
  i: Integer;
begin
  for i := High(Self) downto 1 do
    if (Self[i] > Self[i - 1]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <HArr.Increasing>
  @action: Returns true if array arr is in asscending order.
  @note: [0,1] = True | [0,0] = True | [1,0] = False |
[==============================================================================}
function HArr.Increasing: Boolean; overload;
var
  i: Integer;
begin
  for i := High(Self) downto 1 do
    if (Self[i] < Self[i - 1]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <HArr.Downward>
  @action: Returns true if array arr is in descending order.
  @note: Returns true with empty []array! Unlike Descending, Decreasing.
[==============================================================================}
function HArr.Downward: Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  while (h.Decrement > -1) do
    if (Self[h] < Self[h + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <HArr.Upward>
  @action: Returns true if array arr is in ascending order.
  @note: Returns true with empty [] array! Unlike Ascending, Increasing.
[==============================================================================}
function HArr.Upward: Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  while (h.Decrement > -1) do
    if (Self[h] > Self[h + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <HArr.Lowest>
  @action: Returns array minimum value.
  @note: None.
[==============================================================================}
function HArr.Lowest: TVar; overload;
var
  i: Integer;
begin
  if (High(Self) > -1) then
    Result := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] < Result) then
      Result := Self[i];
end;

{==============================================================================]
  <HArr.Highest>
  @action: Returns array maximum value.
  @note: None.
[==============================================================================}
function HArr.Highest: TVar; overload;
var
  i: Integer;
begin
  if (High(Self) > -1) then
    Result := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] < Result) then
      Result := Self[i];
end;

{==============================================================================]
  <HArr.Mini>
  @action: Returns array INDEX with minimum value.
  @note: Supports reversed order (last min index) with aAscending as False.
[==============================================================================}
function HArr.Mini(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload;
var
  h, i: Integer;
begin
  h := High(Self);
  if ((h = -1) or (aAscending and (start > h)) or ((not aAscending) and (start < 0))) then
    Exit(-1);
  case aAscending of
    True:
    begin
      Result := Max(0, start);
      for i := (Result + 1) to h do
        if (Self[i] < Self[Result]) then
          Result := i;
    end;
    False:
    begin
      Result := Min(h, start);
      for i := (Result - 1) downto 0 do
        if (Self[i] < Self[Result]) then
          Result := i;
    end;
  end;
end;

function HArr.Mini(const start: Integer; const aAscending: Boolean = True): Integer; overload;
begin
  Result := Self.Mini(aAscending, start);
end;

{==============================================================================]
  <HArr.Maxi>
  @action: Returns array INDEX with maximum value.
  @note: Supports reversed order (last max index) with aAscending as False.
[==============================================================================}
function HArr.Maxi(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload;
var
  h, i: Integer;
begin
  h := High(Self);
  if ((h = -1) or (aAscending and (start > h)) or ((not aAscending) and (start < 0))) then
    Exit(-1);
  case aAscending of
    True:
    begin
      Result := Max(0, start);
      for i := (Result + 1) to h do
        if (Self[i] > Self[Result]) then
          Result := i;
    end;
    False:
    begin
      Result := Min(h, start);
      for i := (Result - 1) downto 0 do
        if (Self[i] > Self[Result]) then
          Result := i;
    end;
  end;
end;

function HArr.Maxi(const start: Integer; const aAscending: Boolean = True): Integer; overload;
begin
  Result := Self.Maxi(aAscending, start);
end;

{==============================================================================]
 <HArr.Mode>
 @action: The value that occurs most frequently in arr.
 @note: None
[==============================================================================}
function HArr.Mode: TVar; overload;
var
  a: TArr;
  c: TIntegerArray;
  h, i, j, l: Integer;
begin
  h := High(Self);
  if (h > -1) then
  case (h = 0) of
    False:
    begin
      SetLength(c, 0);
      SetLength(a, 0);
      for i := 0 to High(Self) do
      begin
        l := -1;
        for j := 0 to High(a) do
          if (Self[i] = a[j]) then
          begin
            l := j;
            Break;
          end;
        if (l = -1) then
        begin
          a := a.Append(Self[i]);
          c := c.Append(1);
        end else
          Inc(c[l]);
      end;
      Result := a[c.Maxi];
    end;
    True: Result := Self[0];
  end;
end;

{==============================================================================]
 <HArr.Center>
 @action: The value at the center position of a sorted or unsorted arr.
 @note: None
[==============================================================================}
function HArr.Center: TVar; overload;
begin
  if (Length(Self) > 0) then
    Result := Self[Length(Self) div 2];
end;

{==============================================================================]
  <arr.MergeSortIndexed>
  @action: Sorts the current integer array (Self) using merge sort while
           tracking the original indices of each element.
  @note: - Returns an array of indices representing the order of elements in the sorted array.
         - The original array (Self) is modified in-place.
         - Sorting is stable (preserves order of equal elements).
         - Useful for retrieving both sorted data and their original positions.
[==============================================================================}
function HArr.MergeSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
  procedure MSI(var arr: TArr; var indexes: TIntegerArray; const L, R: Integer);
  var
    s: TArr;
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
  SetLength(Result, Length(Self));
  for i := 0 to High(Result) do
    Result[i] := i;
  if (Length(Self) > 1) then
    MSI(Self, Result, 0, High(Result));
end;

{==============================================================================]
 <arr.MergeSortPair>
 @action: Performs an in-place merge sort on the current array (Self),
          reordering both Self and its associated partner array so that the
          elements of partner remain paired with their corresponding elements
          in Self. Sorting is based on the values in Self.
 @note: - Self and partner must have the same length.
        - Sorting is stable: equal values in Self preserve their original order.
        - Returns Length(Self).
        - Set aAscending = False for descending order.
[==============================================================================}
function HArr.MergeSortPair(var partner: TArr; const aAscending: Boolean = True): Integer; overload;
  procedure MSP(var arr, prt: TArr; const L, R: Integer);
  var
    s, p: TArr;
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
  Result := Length(Self);
  if (Result > 1) then
    MSP(Self, partner, 0, (Result - 1));
end;

{==============================================================================]
  <arr.QuickSortPair>
  @action: Sorts the array in-place while simultaneously reordering a partner array 
           to maintain element correspondence. Supports ascending or descending order.
  @note: Useful when you have a key array and a related value array that must stay paired.
         The method returns the length of the array.
[==============================================================================}
function HArr.QuickSortPair(var partner: TArr; const aAscending: Boolean = True): Integer; overload;
  procedure QS2(var A, B: TArr; const L, R: Integer);
  var
    p: TVar;
    i, j: Integer;
  begin
    i := L;
    j := R;
    p := A[(L + R) div 2];
    case aAscending of
      True:
      repeat
        while (A[i] < p) do
          Inc(i);
        while (A[j] > p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(A[i], A[j]);
          Swap(B[i], B[j]);
          Inc(i);
          Dec(j);
        end;
      until (i > j);
      False:
      repeat
        while (A[i] > p) do
          Inc(i);
        while (A[j] < p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(A[i], A[j]);
          Swap(B[i], B[j]);
          Inc(i);
          Dec(j);
        end;
      until (i > j);
    end;
    if (L < j) then
      QS2(A, B, L, j);
    if (i < R) then
      QS2(A, B, i, R);
  end;
begin
  Result := Length(Self);
  if (Result > 0) then
    QS2(Self, partner, 0, (Result - 1));
end;

{==============================================================================]
  <arr.PartitionSort>
  @action: Sorts the array (Self) in ascending or descending order using a
           stable partition-based recursive sorting algorithm.
  @note:   - Returns Length(Self)
           - The algorithm is conceptually similar to QuickSort but uses
             stable partitioning (no in-place swaps).
           - Equal elements preserve their original order (stable).
           - Uses auxiliary arrays, trading memory for stability.
           - Also known as "Stable QuickSort".
[==============================================================================}
function HArr.PartitionSort(const aAscending: Boolean = True): Integer; overload;
  procedure PS(var A: TArr; const L, R: Integer);
  var
    p: TVar;
	i, t: Integer;
    s, e, b: TArr;
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
    if (Length(s) > 1) then
      PS(s, 0, High(s));
    if (Length(b) > 1) then
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
  Result := Length(Self);
  if (Result > 1) then
    PS(Self, 0, (Result - 1));
end;

{==============================================================================]
  <arr.QuickSortSwapped>
  @action: Sorts the array in ascending or descending order and records all swaps performed.
  @note: Returns a dynamic array of TConnection records, each representing the indices of elements swapped during the sort.
         Useful for visualizations or undoing the sort.
[==============================================================================}
function HArr.QuickSortSwapped(const aAscending: Boolean = True): TConnectionArray; overload;
  procedure QuickSortRec(const L, R: Integer; var swaps: TConnectionArray);
  var
    p: TVar;
    i, j: Integer;
  begin
    i := L;
    j := R;
    p := Self[(L + R) div 2];
    case aAscending of
      True:
      repeat
        while (Self[i] < p) do
          Inc(i);
        while (Self[j] > p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(Self[i], Self[j]);
          SetLength(swaps, (Length(swaps) + 1));
          swaps[High(swaps)].Create(i.Increase, j.Decrease);
        end;
      until (i > j);
      False:
      repeat
        while (Self[i] > p) do
          Inc(i);
        while (Self[j] < p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(Self[i], Self[j]);
          SetLength(swaps, (Length(swaps) + 1));
          swaps[High(swaps)].Create(i.Increase, j.Decrease);
        end;
      until (i > j);
    end;
    if (L < j) then
      QuickSortRec(L, j, swaps);
    if (i < R) then
      QuickSortRec(i, R, swaps);
  end;
begin
  SetLength(Result, 0);
  if Length(Self) > 1 then
    QuickSortRec(0, High(Self), Result);
end;

{==============================================================================]
  <arr.QuickSortIndexed>
  @action: Sorts the array while tracking the original indices.
  @note: Returns an array of indices representing the order of elements in the sorted array.
         The original array is modified.
         Useful when you want to know how elements move rather than just sorting the values.
[==============================================================================}
function HArr.QuickSortIndexed(const aAscending: Boolean = True): TIntegerArray; overload;
  procedure QuickSortRec(const L, R: Integer; var indexes: TIntegerArray);
  var
    p: TVar;
    i, j: Integer;
  begin
    i := L;
    j := R;
    p := Self[(L + R) div 2];
    case aAscending of
      True:
      repeat
        while (Self[i] < p) do
          Inc(i);
        while (Self[j] > p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(Self[i], Self[j]);
          Swap(indexes[i.Increase], indexes[j.Decrease]);
        end;
      until (i > j);
      False:
      repeat
        while (Self[i] > p) do
          Inc(i);
        while (Self[j] < p) do
          Dec(j);
        if (i <= j) then
        begin
          Swap(Self[i], Self[j]);
          Swap(indexes[i.Increase], indexes[j.Decrease]);
        end;
      until (i > j);
    end;
    if (L < j) then
      QuickSortRec(L, j, indexes);
    if (i < R) then
      QuickSortRec(i, R, indexes);
  end;
var
  l, i: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := i;
  if (l > 1) then
    QuickSortRec(0, (l - 1), Result);
end;

{==============================================================================]
  <arr.QuickSortedly>
  @action: Returns the indices of the array elements in sorted order without modifying the original array.
  @note: Purely functional: the original array stays unchanged.
         The result is an array of indices indicating the sorted order.
[==============================================================================}
function HArr.QuickSortedly(const aAscending: Boolean = True): TIntegerArray; overload;
  procedure QuickSortIndexedHelper(const arr: TArr; var indexes: TIntegerArray; const L, R: Integer; const aAscending: Boolean);
  var
    p: TVar;
    i, j: Integer;
  begin
    i := L;
    j := R;
    p := arr[indexes[(L + R) div 2]];
    case aAscending of
      True:
      repeat
        while (arr[indexes[i]] < p) do
          Inc(i);
        while (arr[indexes[j]] > p) do
          Dec(j);
        if (i <= j) then
          Swap(indexes[i.Increase], indexes[j.Decrease]);
      until (i > j);
      False:
      repeat
        while (arr[indexes[i]] > p) do
          Inc(i);
        while (arr[indexes[j]] < p) do
          Dec(j);
        if (i <= j) then
          Swap(indexes[i.Increase], indexes[j.Decrease]);
      until (i > j);
    end;
    if (L < j) then
      QuickSortIndexedHelper(arr, indexes, L, j, aAscending);
    if (i < R) then
      QuickSortIndexedHelper(arr, indexes, i, R, aAscending);
  end;
var
  l, i: Integer;
begin
  l := Length(Self);
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := i;
  QuickSortIndexedHelper(Self, Result, 0, (l - 1), aAscending);
end;

{==============================================================================]
  <HArr.QuickSorted(aAscending: Boolean): TArr>
  @action: Returns array sorted by its own values, based on QuickSort algorithm.
  @note: None.
[==============================================================================}
function HArr.QuickSorted(const aAscending: Boolean = True): TArr; overload;
  procedure QS(var arr: TArr; const L, R: Integer);
  var
    i, j: Integer;
    p: TVar;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while (aAscending and (arr[i] < p)) or ((not aAscending) and (arr[i] > p)) do
        Inc(i);
      while (aAscending and (arr[j] > p)) or ((not aAscending) and (arr[j] < p)) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QS(arr, L, j);
    if (i < R) then
      QS(arr, i, R);
  end;
var
  a: Integer;
begin
  a := Length(Self);
  Result := Self.Copy(0, a);
  if (a > 1) then
    QS(Result, 0, (a - 1));
end;

{==============================================================================]
  <arr.QuickSort>
  @action: QuickSort algorithm that is NOT based on recursion.
  @note: non-recursive. Returns High(arr).
[==============================================================================}
function HArr.QuickSort(const aAscending: Boolean = True): Integer; overload;
var
  p: TVar;
  t, o: Integer;
  s: TRangeArray;
  x, r: TRange;
  procedure qsPush(const start, stop: Integer);
  begin
    SetLength(s, (t.Increment + 1));
    s[t].start := start;
    s[t].stop := stop;
  end;
  function qsPop(out start, stop: Integer): Boolean;
  begin
    Result := (t >= 0);
    if not Result then
      Exit;
    start := s[t].start;
    stop := s[t].stop;
    Dec(t); 
  end;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    t := -1;
    qsPush(0, Result);
    r.Create(0, Result);
    while qsPop(r.start, r.stop) do
      while r.Growing do
      begin
        x := r;
        p := Self[r.Middle];
        while x.Ascending do
        begin
          while (Sign(Self[x.start].Compare(p)) = o) do
            Inc(x.start);
          while (Sign(Self[x.stop].Compare(p)) = -o) do
            Dec(x.stop);
          if x.Ascending then
            Exchange(x.start.Increase, x.stop.Decrease);
        end;
        if ((x.stop - r.start) < (r.stop - x.start)) then
        begin
          if (x.start < r.stop) then
            qsPush(x.start, r.stop);
          r.stop := x.stop;
        end else
        begin
          if (r.start < x.stop) then
            qsPush(r.start, x.stop);
          r.start := x.start;
        end;
      end;
  end;
end;

{==============================================================================]
  <arr.QuickSort3W>
  @action: 3-way QuickSort algorithm that is NOT based on recursion.
  @note: recursive. Returns High(arr).
[==============================================================================}
function HArr.QuickSort3W(const aAscending: Boolean = True): Integer; overload;
  procedure SortLH(var arr: TArr; const L, H: Integer; const aAscending: Boolean = True);
  var
    a: TVar;
    p, o: Integer;
    r: TRange;
  begin
    if (L >= H) then
      Exit;
    o := aAscending.Select(-1, 1);
    a := arr[L];
	r.Create(L, H);
    p := (L + 1);
    while (p <= r.stop) do
      if (Sign(arr[p].Compare(a)) = o) then
        Exchange(r.start.Increase, p.Increase)
      else
        if (Sign(arr[p].Compare(a)) = -o) then
          Exchange(r.stop.Decrease, p)
        else
          Inc(p);
    SortLH(arr, L, (r.start - 1), aAscending);
    SortLH(arr, (r.stop + 1), H, aAscending);
  end;
begin
  Result := High(Self);
  if (Result > 0) then
    SortLH(Self, 0, Result, aAscending);
end;

{==============================================================================]
  <arr.QSort>
  @action: QuickSort algorithm that IS based on recursion.
  @note: recursive. Returns High(arr).
[==============================================================================}
function HArr.QSort(const aAscending: Boolean = True): Integer; overload;
  procedure _QuickSort(var arr: TArr; const start, stop: Integer; const aAscending: Boolean = True);
  var
    p: TVar;
	o: Integer;
    s: TRange;
  begin
    if (start < stop) then
    begin
      o := aAscending.Select(-1, 1);
	  s.Create(start, stop);
      p := arr[s.Middle];
      repeat
        while (Sign(arr[s.start].Compare(p)) = o) do
          Inc(s.start);
        while (Sign(arr[s.stop].Compare(p)) = -o) do
          Dec(s.stop);
        if (s.start <= s.stop) then
          Exchange(s.start.Increase, s.stop.Decrease);
      until (s.start > s.stop);
      if (start < s.stop) then
        _QuickSort(arr, start, s.stop, aAscending);
      if (s.start < stop) then
        _QuickSort(arr, s.start, stop, aAscending);
    end;
  end;
begin
  Result := High(Self);
  if (Result > 0) then
    _QuickSort(Self, 0, Result, aAscending);
end;

{==============================================================================]
  <arr.CoctailSort>
  @action: CoctailSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.CoctailSort(const aAscending: Boolean = True): Integer; overload;
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
  <arr.CoctailSort2>
  @action: CoctailSort algorithm.
  @note: CoctailSort v2. Returns High(arr).
[==============================================================================}
function HArr.CoctailSort2(const aAscending: Boolean = True): Integer; overload;
var
  b, e, i, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    b := -1;
    e := (Length(Self) - 2);
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
  <arr.GnomeSort>
  @action: GnomeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.GnomeSort(const aAscending: Boolean = True): Integer; overload;
var
  o, p, t: Integer;
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
  <arr.GnomeSortOptimized>
  @action: Optimized GnomeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.GnomeSortOptimized(const aAscending: Boolean = True): Integer; overload;
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
  <arr.PancakeSort>
  @action: PancakeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.PancakeSort(const aAscending: Boolean = True): Integer; overload;
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
  <HArr.BubbleSort>
  @action: Sorts arr with BubbleSort algorithm
  @note: Supports sorting to aAscending and descending order. Returns High(arr)!
[==============================================================================}
function HArr.BubbleSort(const aAscending: Boolean = True): Integer; overload;
var
  i, j: Integer;
begin
  Result := High(Self);
  for i := Result downto 1 do
    for j := 0 to (i - 1) do
      if ((aAscending and (Self[j] > Self[j + 1])) or ((not aAscending) and (Self[j] < Self[j + 1]))) then
        Exchange(j, (j + 1));
end;

{==============================================================================]
  <arr.BubbleSort2>
  @action: Sorts arr with BubbleSort algorithm - contains some optimization.
  @note: Supports sorting to aAscending and descending order. Returns High(arr)!
[==============================================================================}
function HArr.BubbleSort2(const aAscending: Boolean = True): Integer; overload;
var
  a, b, o: Integer;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    for a := 0 to (Result - 1) do
      for b := 1 to (Result - a) do
        if (Sign(Self[b].Compare(Self[b - 1])) = o) then
          Exchange(b, (b - 1));
  end;
end;

{==============================================================================]
  <HArr.BubbleSortOptimized>
  @action: Sorts arr with optimized BubbleSort algorithm
  @note: Supports sorting to aAscending and descending order. Returns High(arr)!
[==============================================================================}
function HArr.BubbleSortOptimized(const aAscending: Boolean = True): Integer; overload;
var
  i, j: Integer;
  s: Boolean;
begin
  Result := High(Self);
  for i := Result downto 1 do
  begin
    s := False;
    for j := 0 to (i - 1) do
      if ((aAscending and (Self[j] > Self[j + 1])) or ((not aAscending) and (Self[j] < Self[j + 1]))) then
      begin
        Exchange(j, (j + 1));
        s := True;
      end;
    if not s then
      Break;
  end;
end;

{==============================================================================]
  <arr.CombSort>
  @action: CombSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.CombSort(const aAscending: Boolean = True): Integer; overload;
var
  i, g, o: Integer;
  s: Boolean;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    o := aAscending.Select(-1, 1);
    g := Length(Self);
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
  <arr.HeapSort>
  @action: HeapSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.HeapSort(const aAscending: Boolean = True): Integer; overload;
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
  <arr.InsertionSort>
  @action: InsertionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.InsertionSort(const aAscending: Boolean = True): Integer; overload;
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
  <arr.SelectionSort>
  @action: SelectionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.SelectionSort(const aAscending: Boolean = True): Integer; overload;
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
  <arr.SelectionSortBidirectional>
  @action: Bidirectional SelectionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.SelectionSortBidirectional(const aAscending: Boolean = True): Integer; overload;
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
        else
          if (Sign(Self[s].Compare(Self[x.stop])) = -o) then
            x.stop := s;
      if (x.start <> y.start) then
        Exchange(y.start, x.start);
      if (x.stop <> y.stop) then
        Exchange(y.stop, x.stop);
    end;
  end;
end;

{==============================================================================]
  <arr.SelectionSortBidirectional2>
  @action: Bidirectional SelectionSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.SelectionSortBidirectional2(const aAscending: Boolean = True): Integer; overload;
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
        else
          if (Sign(Self[s].Compare(Self[r.stop])) = -o) then
            Exchange(s, r.stop);
      end;
  end;
end;

{==============================================================================]
  <arr.ShellSort>
  @action: ShellSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.ShellSort(const aAscending: Boolean = True): Integer; overload;
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
        l := Length(Self);
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

{==============================================================================]
  <arr.MergeSort>
  @action: MergeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.MergeSort(const aAscending: Boolean = True): Integer; overload;
  procedure Merge(var arr, tmp: TArr; const Lo, Hi: Integer; const aAscending: Boolean = True);
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
  t: TArr;
begin
  Result := High(Self);
  if (Result > 0) then
  begin
    SetLength(t, (Result + 1));
    Merge(Self, t, 0, Result, aAscending);
  end;
end;

{==============================================================================]
  <arr.MergeSortBU>
  @action: Bottom-up MergeSort algorithm.
  @note: Returns High(arr).
[==============================================================================}
function HArr.MergeSortBU(const aAscending: Boolean = True): Integer; overload;
var
  t: TArr;
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

{==============================================================================]
  <arr.HybridSort>
  @action: Sorts the integer array (Self) in ascending or descending order
           using algorithm close to TimSort — a stable hybrid sorting method that
           combines insertion sort and merge sort for optimal performance.
  @note:   - Returns Length(Self)
           - Stable (preserves equal element order)
[==============================================================================}
function HArr.HybridSort(const aAscending: Boolean = True): Integer; overload;
const
  RUN_SIZE = 32;
  procedure INS(var arr: TArr; const L, R: Integer);
  var
    t: TVar;
    i, j: Integer;
  begin
    for i := (L + 1) to R do
    begin
      t := arr[i];
      j := (i - 1);
      while ((j >= L) and ((aAscending and (arr[j] > t)) or ((not aAscending) and (arr[j] < t)))) do
      begin
	    arr[j + 1] := arr[j];
		Dec(j);
	  end;
      arr[j + 1] := t;
    end;
  end;
  procedure MRG(var arr: TArr; const L, M, R: Integer);
  var
    a, b, i, j, k: Integer;
    x, y: TArr;
  begin
    a := ((M - L) + 1);
    b := (R - M);
    SetLength(x, a);
    SetLength(y, b);
    for i := 0 to (a - 1) do
      x[i] := arr[L + i];
    for i := 0 to (b - 1) do
      y[i] := arr[(M + 1) + i];
    i := 0;
    j := 0;
    k := L;
    while ((i < a) and (j < b)) do
      if ((aAscending and (x[i] <= y[j])) or ((not aAscending) and (x[i] >= y[j]))) then
        arr[k.Increase] := x[i.Increase]
      else
        arr[k.Increase] := y[j.Increase];
    while (i < a) do
      arr[k.Increase] := x[i.Increase];
    while (j < b) do
      arr[k.Increase] := y[j.Increase];
  end;
var
  i, s, l, m, r: Integer;
begin
  Result := Length(Self);
  if (Result < 2) then
    Exit;
  i := 0;
  while (i < Result) do
  begin
    if (((i + RUN_SIZE) - 1) < Result) then
      INS(Self, i, ((i + RUN_SIZE) - 1))
    else
      INS(Self, i, (Result - 1));
    Inc(i, RUN_SIZE);
  end;
  s := RUN_SIZE;
  while (s < Result) do
  begin
    l := 0;
    while (l < (Result - 1)) do
    begin
      m := ((l + s) - 1);
      r := ((l + (2 * s)) - 1);
      if (r >= Result) then
        r := (Result - 1);
      if (m < r) then
        MRG(Self, l, m, r);
      Inc(l, (2 * s));
    end;
    s := (s * 2);
  end;
end;

{==============================================================================]
  <HArr.Uniq: TArr>
  @action: Unique method for sortable types.
  @note: None.
[==============================================================================}
function HArr.Uniq(const sSorted: Boolean = False): TArr; overload;
begin
  if Self.Empty then
    SetLength(Result, 0)
  else
    if not sSorted then
      Result := Self.QuickSorted.Pruned
    else
      Result := Self.Pruned;
end;

{==============================================================================]
  <arr.Downtrending>
  @action: Returns True if the first element of the array is greater than the last element.
  @note: Only meaningful for arrays with at least 2 elements. Indicates a “falling” trend.
[==============================================================================}
function HArr.Downtrending: Boolean; overload;
begin
  Result := ((Length(Self) > 1) and (Self[Low(Self)] > Self[High(Self)]));
end;

{==============================================================================]
  <arr.Uptrending>
  @action: Returns True if the first element of the array is less than the last element.
  @note: Only meaningful for arrays with at least 2 elements. Indicates a “rising” trend.
[==============================================================================}
function HArr.Uptrending: Boolean; overload;
begin
  Result := ((Length(Self) > 1) and (Self[Low(Self)] < Self[High(Self)]));
end;

{==============================================================================]
  <arr.Notrending>
  @action: Returns True if the first element of the array is equal to the last element.
  @note: Only meaningful for arrays with at least 2 elements. Indicates no significant trend.
[==============================================================================}
function HArr.Notrending: Boolean; overload;
begin
  Result := ((Length(Self) > 1) and (Self[Low(Self)] = Self[High(Self)]));
end;

{==============================================================================]
  <arr.Trend>
  @action: Returns the trend of the array’s endpoints:
            1 = Uptrend (first < last),
           -1 = Downtrend (first > last),
            0 = Notrend (first = last or array too short).
  @note: Only meaningful for arrays with at least 2 elements.
         Comparison is done between the first and last elements only.
[==============================================================================}
function HArr.Trend: Integer; overload;
begin
  if ((Length(Self) < 2) or (Self[Low(Self)] = Self[High(Self)])) then
    Result := 0
  else
    if (Self[Low(Self)] > Self[High(Self)]) then
      Result := -1
    else
      Result := 1;
end;

{==============================================================================]
  <arr.Trending>
  @action: Returns True if the array is either Uptrending or Downtrending.
  @note: Only meaningful for arrays with at least 2 elements.
         Returns False if the array has no trend (Notrending).
[==============================================================================}
function HArr.Trending: Boolean; overload;
begin
  Result := (Self.Trend <> 0);
end;

{==============================================================================]
  <arr.Rising>
  @action: Returns True if the array is monotonically non-decreasing,
           i.e., each element is less than or equal to the next.
  @note: Arrays with 0 or 1 element are considered Rising by default.
         Checks all elements, not just the first and last.
[==============================================================================}
function HArr.Rising: Boolean; overload;
var
  i: Integer;
begin
  for i := Low(Self) to (High(Self) - 1) do
    if (Self[i] > Self[i + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <arr.Falling>
  @action: Returns True if the array is monotonically non-increasing,
           i.e., each element is greater than or equal to the next.
  @note: Arrays with 0 or 1 element are considered Falling by default.
         Checks all elements, not just the first and last.
[==============================================================================}
function HArr.Falling: Boolean; overload;
var
  i: Integer;
begin
  for i := Low(Self) to (High(Self) - 1) do
    if (Self[i] < Self[i + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <arr.Direction>
  @action: Returns numeric trend across the entire array:
           1 = Rising (monotonically non-decreasing),
          -1 = Falling (monotonically non-increasing),
           0 = Notrending (mixed sequence or empty/single element).
  @note: Checks all elements. Inclusive comparisons (≤ / ≥).
[==============================================================================}
function HArr.Direction: Integer; overload;
begin
  if Self.Notrending then
    Result := 0
  else
    if Rising then
      Result := 1
    else
      Result := -1;
end;

{==============================================================================]
  <arr.TrendFalling>
  @action: Returns True if the first element of the array is greater than or equal to the last element,
           indicating a non-increasing trend from start to end.
  @note: Only meaningful for arrays with at least 2 elements.
         This checks only the first and last elements, not the full array.
[==============================================================================}
function HArr.TrendFalling: Boolean; overload;
begin
  Result := ((Length(Self) > 1) and (Self[Low(Self)] >= Self[High(Self)]));
end;

{==============================================================================]
  <arr.TrendRising>
  @action: Returns True if the first element of the array is less than or equal to the last element,
           indicating a non-decreasing trend from start to end.
  @note: Only meaningful for arrays with at least 2 elements.
         This checks only the first and last elements, not the full array.
[==============================================================================}
function HArr.TrendRising: Boolean; overload;
begin
  Result := ((Length(Self) > 1) and (Self[Low(Self)] <= Self[High(Self)]));
end;

{==============================================================================]
 <arr.BinaryInsertionSort>
 @action: Sorts the array in ascending or descending order using binary
          insertion sort, which combines binary search and insertion.
 @note: This algorithm runs in O(n²) time in the worst case but uses binary
        search to minimize comparisons. It performs well on small or
        partially sorted datasets. Returns the number of elements sorted.
[==============================================================================}
function HArr.BinaryInsertionSort(const aAscending: Boolean = True): Integer; overload;
  function BP(const value: TVar; const hIndex: Integer): Integer;
  var
    L, R, M: Integer;
  begin
    L := 0;
    R := hIndex;
    while (L <= R) do
    begin
      M := ((L + R) div 2);
      if ((aAscending and (Self[M] > value)) or ((not aAscending) and (Self[M] < value))) then
        R := (M - 1)
      else
        L := (M + 1);
    end;
    Result := L;
  end;
var
  k: TVar;
  i, j, p: Integer;
begin
  Result := Length(Self);
  if (Result < 2) then
    Exit;
  for i := 1 to (Result - 1) do
  begin
    k := Self[i];
    p := BP(k, (i - 1));
    j := (i + 1);
    while (j.Decrement > p) do
      Self[j] := Self[j - 1];
    Self[p] := k;
  end;
end;

{==============================================================================]
  <arr.Sortedness>
  @action: Checks whether the array is monotonic (either ascending or descending).
           Performs a two-phase check: a fast global trend detection from both ends,
           followed by a full local adjacency check to ensure strict monotonicity.
  @note: Returns True for arrays of length 0 or 1.
         Uses Integer_Sign(Self[L], Self[R]) to detect initial trend.
         Efficient for large arrays due to early exit if disorder is detected.
         This version checks every element in both phases.
[==============================================================================}
function HArr.Sortedness: Boolean; overload;
var
  L, R, D: Integer;
begin
  L := 0;
  R := High(Self);
  Result := True;
  if (R <= L) then
    Exit;
  D := 0;
  repeat
    case D of
      0: D := Self[L].Sign(Self[R]);
      1: Result := (Self[L] <= Self[R]);
      -1: Result := (Self[L] >= Self[R]);
    end;
  until ((not Result) or ((L.Increment > R.Decrement)));
  if (not Result) then
    Exit;
  L := -1;
  case (D > 0) of
    False:
    while (L.Increment < R) do
      if (Self[L] < Self[L + 1]) then
        Exit(False);
    True:
    while (L.Increment < R) do
      if (Self[L] > Self[L + 1]) then
        Exit(False);
  end;
end;

{==============================================================================]
  <arr.SortednessEx>
  @action: Enhanced version of Sortedness with configurable stride.
           Performs a subsampled global trend check (using left and right indices
           at intervals of "stride") to quickly detect gross disorder,
           followed by a full local adjacency check if the array passes the global phase.
  @note: Default stride = 16; larger values reduce global comparisons but may delay detection
         of small local disorder. Returns True for arrays of length 0 or 1.
         Useful for extremely large arrays where global trend violation is likely.
[==============================================================================}
function HArr.SortednessEx(const stride: Integer = 16): Boolean; overload;
var
  L, R, D: Integer;
begin
  L := 0;
  R := High(Self);
  Result := True;
  if (R <= L) then
    Exit;
  D := 0;
  repeat
    case D of
      0: D := Self[L].Sign(Self[R]);
      1: Result := (Self[L] <= Self[R]);
      -1: Result := (Self[L] >= Self[R]);
    end;
  until ((not Result) or (L.Increment(stride) >= R.Decrement(stride)));
  if not Result then
    Exit;
  L := -1;
  R := High(Self);
  case (D >= 0) of
    False:
    while (L.Increment < R) do
      if (Self[L] < Self[L + 1]) then
        Exit(False);
    True:
    while (L.Increment < R) do
      if (Self[L] > Self[L + 1]) then
        Exit(False);
  end;
end;

{==============================================================================]
  <arr.Monotonic>
  @action: Checks whether the array is globally monotonic by simultaneously comparing
           elements from both ends toward the center, while also validating adjacent pairs.
           Detects ascending or descending trends dynamically based on endpoints.
  @note: Returns True for arrays of length 0 or 1.
         This approach may detect global disorder slightly earlier than adjacent-only checks.
         Performs both global and local comparisons in a single loop.
         Uses Integer_Increment and Integer_Decrement for safe index movement.
[==============================================================================}
function HArr.Monotonic: Boolean; overload;
var
  L, R: Integer;
begin
  L := -1;
  R := Length(Self);
  if (R > 1) then
  case (Self[L + 1] <= Self[R - 1]) of
    True:
    while (L.Increment < R.Decrement) do
      if ((Self[R] < Self[L]) or (Self[L] > Self[L + 1]) or (Self[R - 1] > Self[R])) then
        Exit(False);
    False:
    while (L.Increment < R.Decrement) do
      if ((Self[R] > Self[L]) or (Self[L] < Self[L + 1]) or (Self[R - 1] < Self[R])) then
        Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <arr.Monotone>
  @action: Checks whether the array is monotonic (ascending or descending) by performing
           a symmetric two-way scan from both ends toward the middle.
           Repeatedly evaluates adjacent pairs and global trend to determine monotonicity.
  @note: Returns True for arrays of length 0 or 1.
         Uses a repeat-until loop with early exit if a violation is detected.
         This function is a slightly simpler alternative to Sortedness, but checks both
         global and local conditions for each iteration.
[==============================================================================}
function HArr.Monotone: Boolean; overload;
var
  L, R: Integer;
begin
  L := 0;
  R := High(Self);
  if (R <= L) then
    Exit(True);
  case (Self[L] <= Self[R]) of
    True:
    repeat
      Result := not ((Self[L] > Self[L + 1]) or (Self[R - 1] > Self[R]));
    until ((not Result) or ((L.Increment > R.Decrement)));
    False:
    repeat
      Result := not ((Self[L] < Self[L + 1]) or (Self[R - 1] < Self[R]));
    until ((not Result) or ((L.Increment > R.Decrement)));
  end;
end;

{==============================================================================]
  <arr.IsMonotone>
  @action: Determines whether the array is monotone — that is, entirely non-decreasing
           or non-increasing throughout its elements.
           Returns True if the array’s values either never decrease (monotone ascending)
           or never increase (monotone descending). Equal adjacent values are allowed.
           Returns False if the array changes direction (both rises and falls occur).
  @note:
    • Works correctly for arrays of any length.
      (Empty or single-element arrays are considered monotone.)
    • The function short-circuits for efficiency — exits early once a
      non-monotone pattern is detected.
[==============================================================================}
function HArr.IsMonotone: Boolean; overload;
var
  i: Integer;
  A, D: Boolean;
begin
  A := True;
  D := True;
  for i := 1 to High(Self) do
  begin
    case Self[i].Sign(Self[i - 1]) of
      0: Continue;
      1: D := False;
      -1: A := False;
    end;
    if not (A or D) then
      Exit(False);
  end;
  Result := (A or D);
end;

{==============================================================================]
  <arr.Monotonious>
  @action:
    Determines whether the integer array is monotone — that is, entirely
    non-decreasing or entirely non-increasing.

    The function iterates through the array, comparing each element with its
    predecessor. Two variables track whether any increases (`h`) or decreases
    (`l`) have been observed. If both an increase and a decrease occur, the
    array is not monotone, and the function immediately returns False. Otherwise,
    it returns True.

  @note:
    • Empty or single-element arrays are considered monotone (trivially True).
    • Equal adjacent elements do not affect monotonicity.
    • Uses two integer flags (`h` for increases, `l` for decreases) instead of
      a single accumulator or Boolean pair.
    • Short-circuits for efficiency — exits as soon as both directions are seen.
    • This is functionally equivalent to other “direction-lock” or “accumulator”
      implementations but tracks high/low separately.
[==============================================================================}
function HArr.Monotonious: Boolean; overload;
var
  i, h, l: Integer;
begin
  l := 0;
  h := 0;
  for i := 1 to High(Self) do
  begin
    if (Self[i] = Self[i - 1]) then
      Continue;
    if (Self[i] > Self[i - 1]) then
      h := 1
    else if (Self[i] < Self[i - 1]) then
      l := -1;
    if ((h = 1) and (l = -1)) then
      Exit(False);
  end;
  Result := True;
end;