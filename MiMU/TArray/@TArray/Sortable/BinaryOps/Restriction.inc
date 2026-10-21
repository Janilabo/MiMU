{$IFDEF HELPERS}
function BinaryClamp(const aMin, aMax: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryClampMaximum(const aMax: MType; const oAscending: Boolean = True): Integer; overload;
function BinaryClampMinimum(const aMin: MType; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryClamp>
  @action: Removes all elements outside [aMin, aMax] from a sorted array using
           binary boundary detection. The array is modified in place and
           truncated to contain only values >= aMin and <= aMax.
  @note:
    • The array must already be sorted according to oAscending.
    • Ascending order:
        p = BinaryLowerBound(aMin)  (first element >= aMin)
        q = BinaryUpperBound(aMax)  (first element >  aMax)
    • Descending order:
        p = BinaryLowerBound(aMax, False)  (first element <= aMax)
        q = BinaryUpperBound(aMin, False)  (first element <  aMin)
    • The retained window is [p, q). It is shifted to the beginning of the
      array only when p > 0, then the array is truncated once.
    • Time complexity: O(log n + k), where k is the number of retained
      elements that must be shifted.
    • If aMin > aMax, no element can qualify and the array is emptied.
    • Returns the number of elements removed.
    • If nothing is outside the range, the array remains unchanged
      and the function returns 0.
[==============================================================================}
function MArrayHelper.BinaryClamp(const aMin, aMax: MType; const oAscending: Boolean = True): Integer; overload;
var
  i, l, p, q, c: Integer;
begin
  Result := 0;
  l := Self.Length;
  if (l = 0) then
    Exit;
  if oAscending then
  begin
    p := Self.BinaryLowerBound(aMin);
    q := Self.BinaryUpperBound(aMax);
  end else
  begin
    p := Self.BinaryLowerBound(aMax, False);
    q := Self.BinaryUpperBound(aMin, False);
  end;
  c := (q - p);
  if (c < 0) then
    c := 0;
  Result := (l - c);
  if (Result = 0) then
    Exit;
  if ((c > 0) and (p > 0)) then
    for i := 0 to (c - 1) do
      Self[i] := Self[p + i];
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
function MArrayHelper.BinaryClampMaximum(const aMax: MType; const oAscending: Boolean = True): Integer; overload;
var
  i, l, p, c: Integer;
begin
  Result := 0;
  l := Self.Length;
  if (l = 0) then
    Exit;
  if not oAscending then
  begin
    p := Self.BinaryLowerBound(aMax, False);
    c := (l - p);
    for i := 0 to (c - 1) do
      Self[i] := Self[p + i];
  end else
    c := Self.BinaryUpperBound(aMax);
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
function MArrayHelper.BinaryClampMinimum(const aMin: MType; const oAscending: Boolean = True): Integer; overload;
var
  i, l, p, c: Integer;
begin
  Result := 0;
  l := Self.Length;
  if (l = 0) then
    Exit;
  if oAscending then
  begin
    p := Self.BinaryLowerBound(aMin);
    c := (l - p);
    for i := 0 to (c - 1) do
      Self[i] := Self[p + i];
  end else
    c := Self.BinaryUpperBound(aMin, False);
  Result := (l - c);
  if (Result > 0) then
    SetLength(Self, c);
end;
{$ENDIF}
