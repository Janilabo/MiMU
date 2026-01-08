{$IFDEF HELPERS}
function Descend: MArray; overload; cdecl;
function Ascend: MArray; overload; cdecl;
function Uniq(const sSorted: Boolean = False): MArray; overload; cdecl;
function Unionize(const items: MArray; const oAscending: Boolean = True): MArray; overload; cdecl;
function Subtract(const items: MArray; const oAscending: Boolean = True): MArray; overload; cdecl;
function Intersect(const items: MArray; const oAscending: Boolean = True): MArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascend>
  @action: Returns array arr sorted to asscending order.
  @note: None.
[==============================================================================}
function MArrayHelper.Ascend: MArray; overload; cdecl;
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
  if (Result.Size > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <Descend>
  @action: Returns array arr sorted to descending order.
  @note: None.
[==============================================================================}
function MArrayHelper.Descend: MArray; overload; cdecl;
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
  if (Result.Size > 1) then
    QS(Result, 0, High(Result));
end;

{==============================================================================]
  <Uniq>
  @action: Unique method for sortable types.
  @note: None.
[==============================================================================}
function MArrayHelper.Uniq(const sSorted: Boolean = False): MArray; overload; cdecl;
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
  <Unionize>
  @action: Produces the sorted set-union of two integer arrays, eliminating
           duplicates while preserving the requested ordering direction.
  @note: Both source arrays must already be sorted in the same direction
         (ascending or descending). The result is returned as a newly
         allocated array sized exactly to the number of distinct merged
         elements.
[==============================================================================}
function MArrayHelper.Unionize(const items: MArray; const oAscending: Boolean = True): MArray; overload; cdecl;
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
function MArrayHelper.Subtract(const items: MArray; const oAscending: Boolean = True): MArray; overload; cdecl;
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
  <Intersect>
  @action: Returns a new array containing all elements that appear in BOTH this
           array and `items`. The result is sorted according to `oAscending`
           and contains no duplicates.
  @note: Both arrays must be sorted in the same order specified by `oAscending`.
         This implementation uses a linear merge approach with O(m + n) time
         complexity, which is optimal for this operation.
[==============================================================================}
function MArrayHelper.Intersect(const items: MArray; const oAscending: Boolean = True): MArray; overload; cdecl;
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
{$ENDIF}