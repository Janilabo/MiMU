{$IFDEF HELPERS}
function Ascend: MArray; overload;
function Canonical(const oAscending: Boolean = True): MArray; overload;
function Descend: MArray; overload;
function Intersect(const items: MArray; const oAscending: Boolean = True): MArray; overload;
function Intersectify(const items: MArray; const oAscending: Boolean = True): MArray; overload;
function Intersection(const items: MArray; const oAscending: Boolean = True): MArray; overload;
function Subtract(const items: MArray; const oAscending: Boolean = True): MArray; overload;
function Unionize(const items: MArray; const oAscending: Boolean = True): MArray; overload;
function Uniq(const sSorted: Boolean = False): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascend>
  @action: Returns array arr sorted to asscending order.
  @note: None.
[==============================================================================}
function MArrayHelper.Ascend: MArray; overload;
procedure QS(var arr: MArray; const valLow, valHigh: Integer);
var
  p: MType;
  r: TRange;
begin
  r.Create(valLow, valHigh);
  p := arr[r.Middle];
  repeat
    while (arr[r.start] < p) do
      Inc(r.start);
    while (arr[r.stop] > p) do
      Dec(r.stop);
    if r.Asceal then
      arr.Exchange(r.start.Increase, r.stop.Decrease);
  until (r.start > r.stop);
  if (valLow < r.stop) then
    QS(arr, valLow, r.stop);
  if (r.start < valHigh) then
    QS(arr, r.start, valHigh);
end;
begin
  Result := Self.Copy;
  if (Result.Size > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <Canonical>
  @action: Returns a canonical representation of the array: a sorted, duplicate-free
           copy of Self.
  @note:
    - Non-mutating: the source array remains unchanged.
    - Elements are ordered according to oAscending.
    - Duplicate values are removed after sorting.
    - If Length < 2, a copy of Self is returned.
    - The result is deterministic for a given input and sort order.
[==============================================================================}
function MArrayHelper.Canonical(const oAscending: Boolean = True): MArray; overload;
begin
  if (Self.Length < 2) then
    Exit(Self.Copy);
  Result := Self.QuickSorted(oAscending).Pruned;
end;

{==============================================================================]
  <Descend>
  @action: Returns array arr sorted to descending order.
  @note: None.
[==============================================================================}
function MArrayHelper.Descend: MArray; overload;
procedure QS(var arr: MArray; const valLow, valHigh: Integer);
var
  p: MType;
  r: TRange;
begin
  r.Create(valLow, valHigh);
  p := arr[r.Middle];
  repeat
    while (arr[r.start] > p) do
      Inc(r.start);
    while (arr[r.stop] < p) do
      Dec(r.stop);
    if r.Asceal then
      arr.Exchange(r.start.Increase, r.stop.Decrease);
  until (r.start > r.stop);
  if (valLow < r.stop) then
    QS(arr, valLow, r.stop);
  if (r.start < valHigh) then
    QS(arr, r.start, valHigh);
end;
begin
  Result := Self.Copy;
  if (Result.Size > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <Intersect>
  @action: Returns a new array containing all elements that appear in BOTH this
           array and `items`. The result is sorted according to `oAscending`
           and contains no duplicates.
  @note: Both arrays must be sorted in the same order specified by `oAscending`.
         This implementation uses a linear merge approach with O(m + n) time
         complexity, which is optimal for this operation.
[==============================================================================}
function MArrayHelper.Intersect(const items: MArray; const oAscending: Boolean = True): MArray; overload;
var
  v: MType;
  i, j, l, a, b: Integer;
  e: Boolean;
begin
  a := Self.Size;
  b := items.Size;
  SetLength(Result, Min(a, b));
  i := 0;
  j := 0;
  l := 0;
  e := False;
  while ((i < a) and (j < b)) do
  case (Self[i] = items[j]) of
    True:
    begin
      if ((not e) or (Self[i] <> v)) then
      begin
        v := Self[i];
        Result[l.Increase] := v;
        e := True;
      end;
      Inc(i);
      Inc(j);
    end;
    False:
    if ((oAscending and (Self[i] < items[j])) or ((not oAscending) and (Self[i] > items[j]))) then
      Inc(i)
    else
      Inc(j);
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <Intersectify>
  @action: Computes the set intersection of two pre-sorted arrays in a single pass.
  @note: Requires both Self and items to be pre-sorted according to oAscending.
         Advances both array pointers on match, executing in O(N + M) time.
[==============================================================================}
function MArrayHelper.Intersectify(const items: MArray; const oAscending: Boolean = True): MArray; overload;
var
  a, b, t, i, s: Integer;
begin
  i := items.Length;
  s := Self.Length;
  if (Result.SetSize(Min(s, i)) = 0) then
    Exit;
  a := 0;
  b := 0;
  t := 0;
  while ((a < s) and (b < i)) do
  begin
    if (Self[a] = items[b]) then
    begin
      Result[t.Increase] := items[b];
      Inc(a);
      Inc(b);
    end else if ((oAscending and (Self[a] < items[b])) or ((not oAscending) and (Self[a] > items[b]))) then
      Inc(a)
    else
      Inc(b);
  end;
  SetLength(Result, t);
end;

{==============================================================================]
  <Intersection>
  @action: Returns the set intersection of two arrays.
  @note: Requires Self to be pre-sorted according to oAscending. Preserves the
         original relative order of items while filtering out elements not present in Self.
[==============================================================================}
function MArrayHelper.Intersection(const items: MArray; const oAscending: Boolean = True): MArray; overload;
var
  s: TIntegerArray;
  m: TBooleanArray;
  h, l, a, b, i, t: Integer;
begin
  l := Self.Length;
  h := High(items);
  if ((l = 0) or (h = -1)) then
    Exit([]);
  s := items.QuickSortition(oAscending);
  for i := 0 to m.Alloc(h + 1) do
    m[i] := False;
  a := 0;
  b := 0;
  while ((a < l) and (b <= h)) do
    if (Self[a] = items[s[b]]) then
      m[s[b.Increase]] := True
    else if ((oAscending and (Self[a] < items[s[b]])) or ((not oAscending) and (Self[a] > items[s[b]]))) then
      Inc(a)
    else
      Inc(b);
  t := 0;
  for i := 0 to Result.Alloc(h + 1) do
    if m[i] then
      Result[t.Increase] := items[i];
  SetLength(Result, t);
end;

{==============================================================================]
  <Subtract>
  @action: Constructs and returns a new array representing the set difference
           of this array minus `items`. Only values present in this array and
           absent from `items` are included. The output is sorted according to
           `oAscending` and contains no duplicate values.
  @note: Both input arrays must be pre-sorted in the same direction specified
         by `oAscending`. The implementation performs a linear pass over both
         arrays and executes in O(m + n) time, where m and n are their
         respective lengths. This is the standard A − B set-difference
         operation.
[==============================================================================}
function MArrayHelper.Subtract(const items: MArray; const oAscending: Boolean = True): MArray; overload;
var
  v: MType;
  i, j, l: Integer;
  a, b: Integer;
  e: Boolean;
begin
  a := Self.Size;
  b := items.Size;
  SetLength(Result, a);
  i := 0;
  j := 0;
  l := 0;
  e := False;
  while (i < a) do
  begin
    while ((j < b) and ((oAscending and (items[j] < Self[i])) or ((not oAscending) and (items[j] > Self[i])))) do
      Inc(j);
    if (((j >= b) or ((oAscending and (Self[i] < items[j])) or ((not oAscending) and (Self[i] > items[j])))) and ((not e) or (Self[i] <> v))) then
    begin
      v := Self[i];
      Result[l.Increase] := v;
      e := True;
    end;
    Inc(i);
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <Unionize>
  @action: Produces the sorted set-union of two integer arrays, eliminating
           duplicates while preserving the requested ordering direction.
  @note: Both source arrays must already be sorted in the same direction
         (ascending or descending). The result is returned as a newly
         allocated array sized exactly to the number of distinct merged
         elements.
[==============================================================================}
function MArrayHelper.Unionize(const items: MArray; const oAscending: Boolean = True): MArray; overload;
var
  v: MType;
  i, j, l, a, b: Integer;
  e: Boolean;
begin
  a := Self.Size;
  b := items.Size;
  SetLength(Result, (a + b));
  i := 0;
  j := 0;
  l := 0;
  e := False;
  while ((i < a) and (j < b)) do
  begin
    case ((oAscending and (Self[i] < items[j])) or ((not oAscending) and (Self[i] > items[j]))) of
      True:
      begin
        if ((not e) or (Self[i] <> v)) then
        begin
          v := Self[i];
          Result[l.Increase] := v;
          e := True;
        end;
        Inc(i);
      end;
      False:
      case ((oAscending and (Self[i] > items[j])) or ((not oAscending) and (Self[i] < items[j]))) of
        True:
        begin
          if ((not e) or (items[j] <> v)) then
          begin
            v := items[j];
            Result[l.Increase] := v;
            e := True;
          end;
          Inc(j);
        end;
        False:
        begin
          if ((not e) or (Self[i] <> v)) then
          begin
            v := Self[i];
            Result[l.Increase] := v;
            e := True;
          end;
          Inc(i);
          Inc(j);
        end;
      end;
    end;
  end;
  while (i < a) do
  begin
    if ((not e) or (Self[i] <> v)) then
    begin
      v := Self[i];
      Result[l.Increase] := v;
      e := True;
    end;
    Inc(i);
  end;
  while (j < b) do
  begin
    if ((not e) or (items[j] <> v)) then
    begin
      v := items[j];
      Result[l.Increase] := v;
      e := True;
    end;
    Inc(j);
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <Uniq>
  @action: Unique method for sortable types.
  @note: None.
[==============================================================================}
function MArrayHelper.Uniq(const sSorted: Boolean = False): MArray; overload;
begin
  if Self.Empty then
    SetLength(Result, 0)
  else if not sSorted then
    Result := Self.QuickSorted.Pruned
  else
    Result := Self.Pruned;
end;
{$ENDIF}
