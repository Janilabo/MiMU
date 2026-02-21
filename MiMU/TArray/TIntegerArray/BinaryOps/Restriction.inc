{$IFDEF HELPERS}
function BinaryClamp(const allowed: TRange; const oAscending: Boolean = True): Integer; overload;
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
{$ENDIF}