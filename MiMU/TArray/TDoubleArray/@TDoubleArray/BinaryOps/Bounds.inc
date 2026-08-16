{$IFDEF HELPERS}
function BinaryFindFirst(const range: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryFindLast(const range: TRange; const oAscending: Boolean = True): Integer; overload;
function BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer;
function BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryFindFirst>
  @action: Executes a binary search to locate the first element within the
           specified numeric range (`range.start`..`range.stop`) and returns its
           index. Returns -1 if no element falls within that range.

  @note:   The comparison is against element values, not array index positions.
           The search space is the full array; `range` specifies the acceptable
           value interval. The array must be sorted according to `oAscending`.
[==============================================================================}
function TDoubleArrayHelper.BinaryFindFirst(const range: TRange; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  N, R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  if (R.stop > -1) then
  begin
    N := range.Normalize;
    case oAscending of
      True:
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] < N.start) of
          False:
          begin
            R.stop := (M - 1);
            if InRange(Self[M], N.start, N.stop) then
              Result := M;
          end;
          True: R.start := (M + 1);
        end;
      end;
      False:
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] > N.stop) of
          False:
          begin
            R.stop := (M - 1);
            if InRange(Self[M], N.start, N.stop) then
              Result := M;
          end;
          True: R.start := (M + 1);
        end;
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryFindLast>
  @action: Executes a binary search to locate the last element whose value falls
           within the given numeric range (`range.start`..`range.stop`) and
           returns its index. Returns -1 when no element matches.

  @note:   Elements are evaluated by their value, not their position. The array
           must be sorted in accordance with `oAscending`. The overload identifies
           the last qualifying value relative to the sorted order.
[==============================================================================}
function TDoubleArrayHelper.BinaryFindLast(const range: TRange; const oAscending: Boolean = True): Integer; overload;
var
  M: Integer;
  N, R: TRange;
begin
  Result := -1;
  R.Create(0, High(Self));
  if (R.stop > -1) then
  begin
    N := range.Normalize;
    case oAscending of
      True:
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] > N.stop) of
          False:
          begin
            R.start := (M + 1);
            if InRange(Self[M], N.start, N.stop) then
              Result := M;
          end;
          True: R.stop := (M - 1);
        end;
      end;
      False:
      while (R.start <= R.stop) do
      begin
        M := R.Pivot;
        case (Self[M] < N.start) of
          False:
          begin
            R.start := (M + 1);
            if InRange(Self[M], N.start, N.stop) then
              Result := M;
          end;
          True: R.stop := (M - 1);
        end;
      end;
    end;
  end;
end;

{==============================================================================]
  <BinarySearchF>
  @action: Binary Search which supports TRange search, uses first match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer;
var
  m, o: Integer;
  f, r: TRange;
begin
  Result := -1;
  f := x.Normalize;
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while r.Asceal do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * f.start)) then
      r.start := (m + 1)
    else if ((o * Self[m]) > (o * f.stop)) then
      r.stop := (m - 1)
    else
    begin
      Result := m;
      r.stop := (m - 1);
    end;
  end;
end;

{==============================================================================]
  <BinarySearchL>
  @action: Binary Search which supports TRange search, uses last match from x-range.
  @note: Works with sorted arrays! (aAscending or descending)
[==============================================================================}
function TDoubleArrayHelper.BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer;
var
  m, o: Integer;
  f, r: TRange;
begin
  Result := -1;
  f := x.Normalize;
  o := aAscending.Select(1, -1);
  r.Create(0, High(Self));
  while r.Asceal do
  begin
    m := r.Pivot;
    if ((o * Self[m]) < (o * f.start)) then
      r.start := (m + 1)
    else if ((o * Self[m]) > (o * f.stop)) then
      r.stop := (m - 1)
    else
    begin
      Result := m;
      r.start := (m + 1);
    end;
  end;
end;
{$ENDIF}
