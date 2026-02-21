{$IFDEF HELPERS}
function BinaryClamp(const allowed: TRange; const oAscending: Boolean = True): Integer; overload;
function BinaryClampMaximum(const aMax: Integer; const oAscending: Boolean = True): Integer; overload;
function BinaryClampMinimum(const aMin: Integer; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryClamp>
  @action: Trims the array in-place so that only elements within the specified allowed
           range remain. The method assumes the array is sorted (ascending or descending
           as specified by oAscending) and uses a range-aware approach for efficiency.
  @note:
    • The allowed range is first normalized and then clamped to the array’s actual
      range (from Self[0] to Self[Length-1]).
    • If there is no overlap between the allowed range and the array’s range, the
      array is cleared and the return value equals the original length.
    • Elements outside the clamped range at the start and end are removed.
    • Returns the number of elements removed from the array.
    • If the array is empty, the function returns 0 and leaves the array unchanged.
    • oAscending must correctly reflect the array’s sort order; otherwise the
      trimming may produce incorrect results.
    • This method performs in-place modification and provides O(n) efficiency
      while leveraging the sorted property of the array.
[==============================================================================}
function TIntegerArrayHelper.BinaryClamp(const allowed: TRange; const oAscending: Boolean = True): Integer; overload;
var
  c, i, l: Integer;
  s, a, r: TRange;
begin
  Result := 0;
  l := Self.Length;
  if (l = 0) then
    Exit;
  a := allowed.Normalize;
  s.Create(Self[0], Self[l - 1]);
  r.Create(0, (l - 1));
  if not a.Overlap(s) then
  begin
    SetLength(Self, 0);
    Exit(l);
  end;
  a := a.Clamp(s);
  while (r.start < l) do
    if ((oAscending and (Self[r.start] < a.start)) or ((not oAscending) and (Self[r.start] > a.stop))) then
      Inc(r.start)
    else
      Break;
  if (r.start > l) then
  begin
    SetLength(Self, 0);
    Exit(l);
  end;
  while (r.stop > -1) do
    if ((oAscending and (Self[r.stop] > a.stop)) or ((not oAscending) and (Self[r.stop] < a.start))) then
      Dec(r.stop)
    else
      Break;
  if (r.stop = -1) then
  begin
    SetLength(Self, 0);
    Exit(l);
  end;
  c := r.Size;
  Result := (l - c);
  if (Result > 0) then
  for i := 0 to (l - Result) do
    Self[i] := Self[i + r.start];
  SetLength(Self, c);
end;

{==============================================================================]
  <BinaryClampMaximum>
  @action: Removes all elements greater than aMax from a sorted array using
           binary boundary detection. The array is modified in place and
           truncated to contain only values <= aMax.
  @note:
    • The array must already be sorted according to oAscending.
    • Ascending order:
        Uses BinaryUpperBound to locate the first element > aMax.
        Elements on the right side are truncated.
    • Descending order:
        Uses BinaryLowerBound (descending mode) to locate the first
        element <= aMax. The valid tail segment is shifted to the
        beginning of the array before truncation.
    • Time complexity: O(log n + k), where k is the number of
      retained elements that must be shifted (descending case).
    • Returns the number of elements removed.
    • If no elements exceed aMax, the array remains unchanged
      and the function returns 0.
[==============================================================================}
function TIntegerArrayHelper.BinaryClampMaximum(const aMax: Integer; const oAscending: Boolean = True): Integer; overload;
var
  i, l, p, c: Integer;
begin
  Result := 0;
  l := Self.Length;
  if (l = 0) then
    Exit;
  case oAscending of
    True:
    begin
      p := Self.BinaryUpperBound(aMax);
      if (p < 0) then
        c := (-p - 1)
      else
        c := p;
    end;
    False:
    begin
      p := Self.BinaryLowerBound(aMax, False);
      if (p < 0) then
        p := (-p - 1);
      c := (l - p);
      for i := 0 to (c - 1) do
        Self[i] := Self[p + i];
    end;
  end;
  Result := (l - c);
  if (Result > 0) then
    SetLength(Self, c);
end;

{==============================================================================]
  <BinaryClampMinimum>
  @action: Removes all elements less than aMin from a sorted array using
           binary boundary detection. The array is modified in place and
           truncated to contain only values >= aMin.
  @note:
    • The array must already be sorted according to oAscending.
    • Ascending order:
        Uses BinaryLowerBound to locate the first element >= aMin.
        The valid tail segment is shifted to the beginning of the
        array before truncation.
    • Descending order:
        Uses BinaryUpperBound (descending mode) to locate the first
        element < aMin. Elements on the right side are truncated.
    • Time complexity: O(log n + k), where k is the number of
      retained elements that must be shifted (ascending case).
    • Returns the number of elements removed.
    • If no elements are less than aMin, the array remains unchanged
      and the function returns 0.
[==============================================================================}
function TIntegerArrayHelper.BinaryClampMinimum(const aMin: Integer; const oAscending: Boolean = True): Integer; overload;
var
  i, l, p, c: Integer;
begin
  Result := 0;
  l := Self.Length;
  if (l = 0) then
    Exit;
  case oAscending of
    True:
    begin
      p := Self.BinaryLowerBound(aMin);
      if (p < 0) then
        p := (-p - 1);
      c := (l - p);
      for i := 0 to (c - 1) do
        Self[i] := Self[p + i];
    end;
    False:
    begin
      p := Self.BinaryUpperBound(aMin, False);
      if (p < 0) then
        c := (-p - 1)
      else
        c := p;
    end;
  end;
  Result := (l - c);
  if (Result > 0) then
    SetLength(Self, c);
end;
{$ENDIF}
