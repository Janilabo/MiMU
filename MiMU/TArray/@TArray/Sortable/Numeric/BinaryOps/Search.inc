{$IFDEF HELPERS}
function BinaryQuest(const item: MType; const aAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryQuest>
  @action: Binary search for item in the array, returning its index.
  @note:
    - Self must already be sorted according to aAscending.
    - Returns -1 if item is not found.
    - If item appears multiple times, the returned index is whichever
      match the binary search happens to land on first — not guaranteed
      to be the first or last occurrence. Use BinaryLeftpos/BinaryRightpos
      if a specific boundary is required.
[==============================================================================}
function MArrayHelper.BinaryQuest(const item: MType; const aAscending: Boolean = True): Integer; overload;
var
  s: MType;
  m, o: Integer;
  r: TRange;
begin
  Result := -1;
  o := aAscending.Select(1, -1);
  s := (o * item);
  r.Create(0, High(Self));
  while (r.Asceal and (Result = -1)) do
  begin
    m := r.Pivot;
    if ((o * Self[m]) = s) then
      Result := m
    else if ((o * Self[m]) < s) then
      r.start := (m + 1)
    else
      r.stop := (m - 1);
  end;
end;
{$ENDIF}
