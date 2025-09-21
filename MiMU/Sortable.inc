{$I config\Defines.inc}

{==============================================================================]
  <HArr.Sorted>
  @action: Returns true if array arr is in ascending/descending order by aAscending.
  @note: By default checking for ascending order.
[==============================================================================}
function HArr.Sorted(const aAscending: Boolean = True): Boolean; overload; cdecl;
var
  h, i: Integer;
begin
  h := High(Self);
  for i := 0 to (h - 1) do
    if (aAscending and (Self[i] > Self[i + 1])) or ((not aAscending) and (Self[i] < Self[i + 1])) then
      Exit(False);
  Result := (h > -1);
end;

{==============================================================================]
  <HArr.InOrder>
  @action: Returns true if array arr is in ascending/descending order by aAscending.
  @note: By default checking for ascending order.
[==============================================================================}
function HArr.InOrder(const aAscending: Boolean = True): Boolean; overload; cdecl;
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
function HArr.Orderly: Boolean; overload; cdecl;
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
  <HArr.Ascend>
  @action: Returns true if array arr is in descending order.
  @note: None.
[==============================================================================}
function HArr.Ascend: TArr; overload; cdecl;
procedure QS(var arr: TArr; const valLow, valHigh: Integer);
var
  i, j: Integer;
  p, s: TVar;
begin
  i := valLow;
  j := valHigh;
  p := arr[(valLow + valHigh) div 2];
  repeat
    while (arr[i] < p) do
      Inc(i);
    while (arr[j] > p) do
      Dec(j);
    if (i <= j) then
    begin
      s := arr[i];
      arr[i.Increase] := arr[j];
      arr[j.Decrease] := s;
    end;
  until (i > j);
  if (valLow < j) then
    QS(arr, valLow, j);
  if (i < valHigh) then
    QS(arr, i, valHigh);
end;
begin
  Result := Self.Copy;
  if (Length(Result) > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <HArr.Descend>
  @action: Returns array arr sorted to ascending order.
  @note: None.
[==============================================================================}
function HArr.Descend: TArr; overload; cdecl;
procedure QS(var arr: TArr; const valLow, valHigh: Integer);
var
  i, j: Integer;
  p, s: TVar;
begin
  i := valLow;
  j := valHigh;
  p := arr[(valLow + valHigh) div 2];
  repeat
    while (arr[i] > p) do
      Inc(i);
    while (arr[j] < p) do
      Dec(j);
    if (i <= j) then
    begin
      s := arr[i];
      arr[i.Increase] := arr[j];
      arr[j.Decrease] := s;
    end;
  until (i > j);
  if (valLow < j) then
    QS(arr, valLow, j);
  if (i < valHigh) then
    QS(arr, i, valHigh);
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
function HArr.Descending: Boolean; overload; cdecl;
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
function HArr.Ascending: Boolean; overload; cdecl;
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
function HArr.Decreasing: Boolean; overload; cdecl;
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
function HArr.Increasing: Boolean; overload; cdecl;
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
function HArr.Downward: Boolean; overload; cdecl;
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
function HArr.Upward: Boolean; overload; cdecl;
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
function HArr.Lowest: TVar; overload; cdecl;
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
function HArr.Highest: TVar; overload; cdecl;
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
function HArr.Mini(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload; cdecl;
var
  h, i, s: Integer;
begin
  h := High(Self);
  if ((h = -1) or (aAscending and (start > h)) or ((not aAscending) and (start < 0))) then
    Exit(-1);
  case aAscending of
    True:
    begin
      s := Max(0, start);
      Result := s;
      for i := (s + 1) to h do
        if (Self[i] < Self[Result]) then
          Result := i;
    end;
    False:
    begin
      s := Min(h, start);
      Result := s;
      for i := (s - 1) downto 0 do
        if (Self[i] < Self[Result]) then
          Result := i;
    end;
  end;
end;

function HArr.Mini(const start: Integer; const aAscending: Boolean = True): Integer; overload; cdecl;
begin
  Result := Self.Mini(aAscending, start);
end;

{==============================================================================]
  <HArr.Maxi>
  @action: Returns array INDEX with maximum value.
  @note: Supports reversed order (last max index) with aAscending as False.
[==============================================================================}
function HArr.Maxi(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload; cdecl;
var
  h, i, s: Integer;
begin
  h := High(Self);
  if ((h = -1) or (aAscending and (start > h)) or ((not aAscending) and (start < 0))) then
    Exit(-1);
  case aAscending of
    True:
    begin
      s := Max(0, start);
      Result := s;
      for i := (s + 1) to h do
        if (Self[i] > Self[Result]) then
          Result := i;
    end;
    False:
    begin
      s := Min(h, start);
      Result := s;
      for i := (s - 1) downto 0 do
        if (Self[i] > Self[Result]) then
          Result := i;
    end;
  end;
end;

function HArr.Maxi(const start: Integer; const aAscending: Boolean = True): Integer; overload; cdecl;
begin
  Result := Self.Maxi(aAscending, start);
end;

{==============================================================================]
 <HArr.Mode>
 @action: The value that occurs most frequently in arr.
 @note: None
[==============================================================================}
function HArr.Mode: TVar; overload; cdecl;
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
          a.Append(Self[i]);
          c.Append(1);
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
function HArr.Center: TVar; overload; cdecl;
begin
  if (Length(Self) > 0) then
    Result := Self[Length(Self) div 2];
end;

{==============================================================================]
  <HArr.BubbleSort>
  @action: Sorts arr with BubbleSort algorithm
  @note: Supports sorting to aAscending and descending order. Returns High(arr)!
[==============================================================================}
function HArr.BubbleSort(const aAscending: Boolean = True): Integer; overload; cdecl;
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
  <HArr.BubbleSortOptimized>
  @action: Sorts arr with optimized BubbleSort algorithm
  @note: Supports sorting to aAscending and descending order. Returns High(arr)!
[==============================================================================}
function HArr.BubbleSortOptimized(const aAscending: Boolean = True): Integer; overload; cdecl;
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
  <HArr.QuickSorted(aAscending: Boolean): TArr>
  @action: Returns array sorted by its own values, based on QuickSort algorithm.
  @note: None.
[==============================================================================}
function HArr.QuickSorted(const aAscending: Boolean = True): TArr; overload; cdecl;
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
  <HArr.Uniq: TArr>
  @action: Unique method for sortable types.
  @note: None.
[==============================================================================}
function HArr.Uniq(const sSorted: Boolean = False): TArr; overload; cdecl;
begin
  if Self.Empty then
    SetLength(Result, 0)
  else
    if not sSorted then
      Result := Self.QuickSorted.Compress
    else
      Result := Self.Compress;
end;
