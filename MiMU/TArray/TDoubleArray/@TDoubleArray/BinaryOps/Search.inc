{$IFDEF HELPERS}
function BinarySearchSpan(const range: TRange; const L, R: Integer; const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
