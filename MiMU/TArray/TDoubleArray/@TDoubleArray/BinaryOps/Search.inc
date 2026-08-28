{$IFDEF HELPERS}
function BinaryLeeway(const item: Double; const epsilon: Double = 1e-9; const oAscending: Boolean = True): Integer; overload;
function BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryLeeway>
  @action: Performs a binary search for the index of an element approximately
           equal to `item`, using absolute tolerance `epsilon` in place of
           exact (`=`) comparison — for locating a Double value that may not
           compare bit-exact due to floating-point representation error.
           Returns the index of the first element encountered during
           bisection whose distance from `item` is within `epsilon`, or -1
           if no element in the array falls within that tolerance.
  @note: The array must already be sorted according to `oAscending`. Unlike
         every other search in this family, this is not an exact-key search
         — it's a fuzzy-equality contract. The bisection itself still
         converges toward a single value (the lower/upper edge of the
         tolerance window, `item -/+ epsilon`), so ordinary binary-search
         convergence guarantees still apply; only the match test at each
         pivot (`Abs(Self[M] - item) <= epsilon`) differs from the rest of
         the family. If multiple elements fall within `epsilon` of `item`,
         the one returned depends on bisection order — not guaranteed to be
         the closest or the first occurrence.
         Default `epsilon = 1E-9` is a reasonable general-purpose Double
         tolerance; callers comparing values accumulated through many
         floating-point operations may need a looser epsilon.
[==============================================================================}
function TDoubleArrayHelper.BinaryLeeway(const item: Double; const epsilon: Double = 1e-9; const oAscending: Boolean = True): Integer; overload;
var
  L, R, M: Integer;
  i: Double;
begin
  L := 0;
  R := High(Self);
  if (R > -1) then
  case oAscending of
    True:
    begin
      i := (item - epsilon);
      while (L <= R) do
      begin
        M := (L + ((R - L) shr 1));
        if (Abs(Self[M] - item) <= epsilon) then
          Exit(M);
        if (Self[M] < i) then
          L := (M + 1)
        else
          R := (M - 1);
      end;
    end;
    False:
    begin
      i := (item + epsilon);
      while (L <= R) do
      begin
        M := (L + ((R - L) shr 1));
        if (Abs(Self[M] - item) <= epsilon) then
          Exit(M);
        if (Self[M] > i) then
          L := (M + 1)
        else
          R := (M - 1);
      end;
    end;
  end;
  Result := -1;
end;

{==============================================================================]
  <BinarySearchSpan>
  @action: Performs a recursive binary search within a specified sub-range [L, R] of a
           sorted array to locate any element whose value falls inside a given TRange,
           supporting ascending or descending order.
  @note: The array must be pre-sorted according to `aAscending` across the given
         [L, R] span. `range` is normalized internally, so its start/stop order does
         not matter. Returns the index of an element whose value lies within `range`
         (not guaranteed to be the first such element in the array), or -1 if none is
         found, or if L < 0 or R exceeds the array's upper bound.
[==============================================================================}
function TDoubleArrayHelper.BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
  function BSS(const range: TRange; const L, R: Integer; const aAscending: Boolean): Integer;
  var
    M: Integer;
  begin
    if (L > R) then
      Exit(-1);
    M := (L + ((R - L) div 2));
    if InRange(Self[M], range.start, range.stop) then
      Exit(M);
    if ((aAscending and (range.stop < Self[M])) or ((not aAscending) and (range.start > Self[M]))) then
      Result := BSS(range, L, (M - 1), aAscending)
    else if ((aAscending and (range.start > Self[M])) or ((not aAscending) and (range.stop < Self[M]))) then
      Result := BSS(range, (M + 1), R, aAscending);
  end;
begin
  if (L < 0) or (R > High(Self)) then
    Exit(-1);
  Result := BSS(range.Normalize, L, R, aAscending);
end;
{$ENDIF}
