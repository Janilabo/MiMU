{$IFDEF HELPERS}
function QuickSortByX1(const aAscending: Boolean = True): Integer; overload;
function QuickSortByY1(const aAscending: Boolean = True): Integer; overload;
function QuickSortByX2(const aAscending: Boolean = True): Integer; overload;
function QuickSortByY2(const aAscending: Boolean = True): Integer; overload;

function QuickSortedByX1(const aAscending: Boolean = True): TBoxArray; overload;
function QuickSortedByY1(const aAscending: Boolean = True): TBoxArray; overload;
function QuickSortedByX2(const aAscending: Boolean = True): TBoxArray; overload;
function QuickSortedByY2(const aAscending: Boolean = True): TBoxArray; overload;

function SortByColumn(const aAscending: Boolean = True): Integer; overload;
function SortByRow(const aAscending: Boolean = True): Integer; overload;

function SortByAreas(var rAreas: TIntegerArray; const oAscending: Boolean): Integer; overload;
function SortByAreal(const oAscending: Boolean): Integer; overload;
function SortedByArea(const rAscending: Boolean): TBoxArray; overload;
function SortedWithArea(const rAscending: Boolean): TBoxArray; overload;
function SortingByArea(const oAscending: Boolean): Integer; overload;
function SortWithArea(const oAscending: Boolean): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <QuickSortByX1>
  @action: Sorts all boxes based on their left edge (X1) coordinate.
  @note: Uses an in-place recursive QuickSort. Does not guarantee stability
         for equal X1 values. Complexity is O(n log n) on average.
[==============================================================================}
function TBoxArrayHelper.QuickSortByX1(const aAscending: Boolean = True): Integer; overload;
  procedure QSX1(var arr: TBoxArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p: TBox;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and (arr[i].X1 < p.X1)) or ((not A) and (arr[i].X1 > p.X1))) do
        Inc(i);
      while ((A and (arr[j].X1 > p.X1)) or ((not A) and (arr[j].X1 < p.X1))) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSX1(arr, L, j, A);
    if (i < R) then
      QSX1(arr, i, R, A);
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    QSX1(Self, 0, (Result - 1), aAscending);
end;

{==============================================================================]
  <QuickSortByY1>
  @action: Sorts all boxes based on their top edge (Y1) coordinate.
  @note: In-place recursive QuickSort implementation. Equal Y1 values are not
         guaranteed to preserve original order (unstable sort).
[==============================================================================}
function TBoxArrayHelper.QuickSortByY1(const aAscending: Boolean = True): Integer; overload;
  procedure QSY1(var arr: TBoxArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p: TBox;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and (arr[i].Y1 < p.Y1)) or ((not A) and (arr[i].Y1 > p.Y1))) do
        Inc(i);
      while ((A and (arr[j].Y1 > p.Y1)) or ((not A) and (arr[j].Y1 < p.Y1))) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSY1(arr, L, j, A);
    if (i < R) then
      QSY1(arr, i, R, A);
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    QSY1(Self, 0, (Result - 1), aAscending);
end;

{==============================================================================]
  <QuickSortByX2>
  @action: Sorts all boxes based on their right edge (X2) coordinate.
  @note: Uses an in-place recursive QuickSort. Does not guarantee stability
         for equal X2 values. Complexity is O(n log n) on average.
[==============================================================================}
function TBoxArrayHelper.QuickSortByX2(const aAscending: Boolean = True): Integer; overload;
  procedure QSX2(var arr: TBoxArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p: TBox;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and (arr[i].X2 < p.X2)) or ((not A) and (arr[i].X2 > p.X2))) do
        Inc(i);
      while ((A and (arr[j].X2 > p.X2)) or ((not A) and (arr[j].X2 < p.X2))) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSX2(arr, L, j, A);
    if (i < R) then
      QSX2(arr, i, R, A);
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    QSX2(Self, 0, (Result - 1), aAscending);
end;

{==============================================================================]
  <QuickSortByY2>
  @action: Sorts all boxes based on their bottom edge (Y2) coordinate.
  @note: In-place recursive QuickSort implementation. Equal Y2 values are not
         guaranteed to preserve original order (unstable sort).
[==============================================================================}
function TBoxArrayHelper.QuickSortByY2(const aAscending: Boolean = True): Integer; overload;
  procedure QSY2(var arr: TBoxArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p: TBox;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and (arr[i].Y2 < p.Y2)) or ((not A) and (arr[i].Y2 > p.Y2))) do
        Inc(i);
      while ((A and (arr[j].Y2 > p.Y2)) or ((not A) and (arr[j].Y2 < p.Y2))) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSY2(arr, L, j, A);
    if (i < R) then
      QSY2(arr, i, R, A);
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    QSY2(Self, 0, (Result - 1), aAscending);
end;

{==============================================================================]
  <QuickSortedByX1>
  @action: Returns a new copy of the box array sorted by left edge (X1)
           coordinate.
  @note: Non-mutating; Self is left untouched. Extracts X1 keys via Self.X1s
         and delegates to QuickSorted. Equal X1 values are not guaranteed to
         preserve original order (unstable sort).
[==============================================================================}
function TBoxArrayHelper.QuickSortedByX1(const aAscending: Boolean = True): TBoxArray; overload;
begin
  Result := Self.QuickSorted(Self.X1s, aAscending); 
end;

{==============================================================================]
  <QuickSortedByY1>
  @action: Returns a new copy of the box array sorted by top edge (Y1)
           coordinate.
  @note: Non-mutating; Self is left untouched. Extracts Y1 keys via Self.Y1s
         and delegates to QuickSorted. Equal Y1 values are not guaranteed to
         preserve original order (unstable sort).
[==============================================================================}
function TBoxArrayHelper.QuickSortedByY1(const aAscending: Boolean = True): TBoxArray; overload;
begin
  Result := Self.QuickSorted(Self.Y1s, aAscending);
end;

{==============================================================================]
  <QuickSortedByX2>
  @action: Returns a new copy of the box array sorted by right edge (X2)
           coordinate.
  @note: Non-mutating; Self is left untouched. Extracts X2 keys via Self.X2s
         and delegates to QuickSorted. Equal X2 values are not guaranteed to
         preserve original order (unstable sort).
[==============================================================================}
function TBoxArrayHelper.QuickSortedByX2(const aAscending: Boolean = True): TBoxArray; overload;
begin
  Result := Self.QuickSorted(Self.X2s, aAscending);
end;

{==============================================================================]
  <QuickSortedByY2>
  @action: Returns a new copy of the box array sorted by bottom edge (Y2)
           coordinate.
  @note: Non-mutating; Self is left untouched. Extracts Y2 keys via Self.Y2s
         and delegates to QuickSorted. Equal Y2 values are not guaranteed to
         preserve original order (unstable sort).
[==============================================================================}
function TBoxArrayHelper.QuickSortedByY2(const aAscending: Boolean = True): TBoxArray; overload;
begin
  Result := Self.QuickSorted(Self.Y2s, aAscending);
end;

{==============================================================================]
  <SortByColumn>
  @action: Sorts all boxes in column-major order (primarily by X1, then by Y1
           for boxes sharing the same left edge).
  @note: Uses an in-place recursive dual-key QuickSort with O(n log n) average
         complexity. Not stable for boxes with identical (X1, Y1) coordinates.
[==============================================================================}
function TBoxArrayHelper.SortByColumn(const aAscending: Boolean = True): Integer; overload;
  procedure QSC(var arr: TBoxArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p: TBox;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and ((arr[i].X1 < p.X1) or ((arr[i].X1 = p.X1) and (arr[i].Y1 < p.Y1)))) or ((not A) and ((arr[i].X1 > p.X1) or ((arr[i].X1 = p.X1) and (arr[i].Y1 > p.Y1))))) do
        Inc(i);
      while ((A and ((arr[j].X1 > p.X1) or ((arr[j].X1 = p.X1) and (arr[j].Y1 > p.Y1)))) or ((not A) and ((arr[j].X1 < p.X1) or ((arr[j].X1 = p.X1) and (arr[j].Y1 < p.Y1))))) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSC(arr, L, j, A);
    if (i < R) then
      QSC(arr, i, R, A);
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    QSC(Self, 0, (Result - 1), aAscending);
end;

{==============================================================================]
  <SortByRow>
  @action: Sorts all boxes in row-major order (primarily by Y1, then by X1
           for boxes sharing the same top edge).
  @note: Uses an in-place recursive dual-key QuickSort with O(n log n) average
         complexity. Not stable for boxes with identical (X1, Y1) coordinates.
[==============================================================================}
function TBoxArrayHelper.SortByRow(const aAscending: Boolean = True): Integer; overload;
  procedure QSR(var arr: TBoxArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p: TBox;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and ((arr[i].Y1 < p.Y1) or ((arr[i].Y1 = p.Y1) and (arr[i].X1 < p.X1)))) or ((not A) and ((arr[i].Y1 > p.Y1) or ((arr[i].Y1 = p.Y1) and (arr[i].X1 > p.X1))))) do
        Inc(i);
      while ((A and ((arr[j].Y1 > p.Y1) or ((arr[j].Y1 = p.Y1) and (arr[j].X1 > p.X1)))) or ((not A) and ((arr[j].Y1 < p.Y1) or ((arr[j].Y1 = p.Y1) and (arr[j].X1 < p.X1))))) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSR(arr, L, j, A);
    if (i < R) then
      QSR(arr, i, R, A);
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    QSR(Self, 0, (Result - 1), aAscending);
end;

{==============================================================================]
  <SortByAreas>
  @action: Sorts the box array in-place based on a parallel array of area values using Least Significant Digit (LSD) Radix Sort.
  @note: Validates that the array length matches the area array length; reverses the output if oAscending is False.
[==============================================================================}
function TBoxArrayHelper.SortByAreas(var rAreas: TIntegerArray; const oAscending: Boolean): Integer; overload;
var
  r: TBoxArray;
  a: TIntegerArray;
  h, i, e, d, m: Integer;
  c: array[0..9] of Integer;
begin
  Result := Self.Length;
  h := High(rAreas);
  if ((Result < 2) or (Result <> (h + 1))) then
    Exit;
  m := 0;
  for i := 0 to h do
    if (rAreas[i] > m) then
      m := rAreas[i];
  e := 1;
  r.SetSize(a.SetSize(Result));
  while ((m div e) > 0) do
  begin
    for i := 0 to 9 do
      c[i] := 0;
    for i := 0 to h do
      Inc(c[(rAreas[i] div e) mod 10]);
    for i := 1 to 9 do
      Inc(c[i], c[i - 1]);
    for i := h downto 0 do
    begin
      d := ((rAreas[i] div e) mod 10);
      Dec(c[d]);
      r[c[d]] := Self[i];
      a[c[d]] := rAreas[i];
    end;
    for i := 0 to h do
    begin
      Self[i] := r[i];
      rAreas[i] := a[i];
    end;
    e := (e * 10);
  end;
  if not oAscending then
  for i := 0 to ((Result div 2) - 1) do
  begin
    d := (Result - 1 - i);
    r[i] := Self[i];
    a[i] := rAreas[i];
    Self[i] := Self[d];
    rAreas[i] := rAreas[d];
    Self[d] := r[i];
    rAreas[d] := a[i];
  end;
end;

{==============================================================================]
  <SortByAreal>
  @action: Sorts the box array in-place by box area using an insertion sort algorithm.
  @note: Efficient for small arrays or nearly sorted data; respects the oAscending direction parameter.
[==============================================================================}
function TBoxArrayHelper.SortByAreal(const oAscending: Boolean): Integer; overload;
var
  i, j, s: Integer;
  r: TBox;
begin
  Result := Self.Length;
  for i := 1 to (Result - 1) do
  begin
    r := Self[i];
    s := r.Area;
    j := (i - 1);
    while ((j >= 0) and ((oAscending and (Self[j].Area > s)) or ((not oAscending) and (Self[j].Area < s)))) do
    begin
      Self[j + 1] := Self[j];
      Dec(j);
    end;
    Self[j + 1] := r;
  end;
end;

{==============================================================================]
  <SortedByArea>
  @action: Returns a new, non-mutating copy of the box array sorted by area using Radix Sort.
  @note: Computes box areas on the fly and utilizes a counting mechanism; reverses the result if rAscending is False.
[==============================================================================}
function TBoxArrayHelper.SortedByArea(const rAscending: Boolean): TBoxArray; overload;
var
  r: TBoxArray;
  a: TIntegerArray;
  h, m, e, i, l: Integer;
  c: array[0..9] of Integer;
begin
  l := Self.Length;
  Result := Self.Copy;
  if (l = 0) then
    Exit;
  m := 0;
  h := r.Alloc(a.SetSize(l));
  for i := 0 to h do
  begin
    a[i] := Result[i].Area;
    if (a[i] > m) then
      m := a[i];
  end;
  e := 1;
  while ((m div e) > 0) do
  begin
    for i := 0 to 9 do
      c[i] := 0;
    for i := 0 to h do
      Inc(c[(a[i] div e) mod 10]);
    for i := 1 to 9 do
      Inc(c[i], c[i - 1]);
    for i := h downto 0 do
      r[c[(a[i] div e) mod 10].Decrement] := Result[i];
    for i := 0 to h do
      Result[i] := r[i];
    for i := 0 to h do
      a[i] := Result[i].Area;
    e := (e * 10);
  end;
  if not rAscending then
    Result.Reverse;
end; 

{==============================================================================]
  <SortedWithArea>
  @action: Returns a new, non-mutating copy of the box array sorted by area using Radix Sort with explicit bucket decrement logic.
  @note: Handles empty inputs cleanly by returning an empty array; respects the rAscending direction parameter.
[==============================================================================}
function TBoxArrayHelper.SortedWithArea(const rAscending: Boolean): TBoxArray; overload;
var
  r: TBoxArray;
  a: TIntegerArray;
  h, m, e, i, d, l: Integer;
  c: array[0..9] of Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  Result := Self.Copy;
  m := 0;
  h := r.Alloc(a.SetSize(l));
  for i := 0 to h do
  begin
    a[i] := Result[i].Area;
    if (a[i] > m) then
      m := a[i];
  end;
  e := 1;
  while ((m div e) > 0) do
  begin
    for i := 0 to 9 do
      c[i] := 0;
    for i := 0 to h do
      Inc(c[(a[i] div e) mod 10]);
    for i := 1 to 9 do
      Inc(c[i], c[i - 1]);
    for i := h downto 0 do
    begin
      d := ((a[i] div e) mod 10);
      Dec(c[d]);
      r[c[d]] := Result[i];
    end;
    for i := 0 to h do
      Result[i] := r[i];
    for i := 0 to h do
      a[i] := Result[i].Area;
    e := (e * 10);
  end;
  if not rAscending then
    Result.Reverse;
end;

{==============================================================================]
  <SortingByArea>
  @action: Sorts the box array in-place by area using a recursive Merge Sort implementation.
  @note: Operates directly on Self without an auxiliary temporary array buffer, adjusting indices during the merge phase.
[==============================================================================}
function TBoxArrayHelper.SortingByArea(const oAscending: Boolean): Integer; overload;
procedure MA(var arr: TBoxArray; left, mid, right: Integer; const oAscending: Boolean);
var
  i, j, k: Integer;
  a: TBox;
begin
  i := left;
  j := (mid + 1);
  while ((i <= mid) and (j <= right)) do
  begin
    if not ((oAscending and (arr[i].Area <= arr[j].Area)) or ((not oAscending) and (arr[i].Area >= arr[j].Area))) then
    begin
      a := arr[j];
      for k := j downto (i + 1) do
        arr[k] := arr[k - 1];
      arr[i] := a;
      Inc(j);
      Inc(mid);
    end;
    Inc(i);
  end;
end;
procedure MSA(var arr: TBoxArray; left, right: Integer; const oAscending: Boolean);
var
  m: Integer;
begin
  if (left >= right) then
    Exit;
  m := ((left + right) div 2);
  MSA(arr, left, m, oAscending);
  MSA(arr, (m + 1), right, oAscending);
  MA(arr, left, m, right, oAscending);
end;
begin
  Result := Self.Length;
  if (Result > 0) then
    MSA(Self, 0, (Result - 1), oAscending);
end;

{==============================================================================]
  <SortWithArea>
  @action: Sorts the box array in-place by area using a Merge Sort algorithm backed by a temporary buffer array.
  @note: Allocates a temporary array to optimize the merge step performance for larger box collections.
[==============================================================================}
function TBoxArrayHelper.SortWithArea(const oAscending: Boolean): Integer; overload;
procedure MA(var arr: TBoxArray; var temp: TBoxArray; left, mid, right: Integer; const oAscending: Boolean);
var
  i, j, k: Integer;
begin
  i := left;
  j := (mid + 1);
  k := left;
  while ((i <= mid) and (j <= right)) do
    if ((oAscending and (arr[i].Area <= arr[j].Area)) or ((not oAscending) and (arr[i].Area >= arr[j].Area))) then
      temp[k.Increase] := arr[i.Increase]
    else
      temp[k.Increase] := arr[j.Increase];
  while i <= mid do
    temp[k.Increase] := arr[i.Increase];
  while j <= right do
    temp[k.Increase] := arr[j.Increase];
  for i := left to right do
    arr[i] := temp[i];
end;
procedure MSA(var arr: TBoxArray; var temp: TBoxArray; left, right: Integer; const oAscending: Boolean);
var
  m: Integer;
begin
  if (left >= right) then
    Exit;
  m := ((left + right) div 2);
  MSA(arr, temp, left, m, oAscending);
  MSA(arr, temp, (m + 1), right, oAscending);
  MA(arr, temp, left, m, right, oAscending);
end;
var
  t: TBoxArray;
begin
  Result := Self.Length;
  if (Result < 2) then
    Exit;
  SetLength(t, Result);
  MSA(Self, t, 0, (Result - 1), oAscending);
end;
{$ENDIF}
