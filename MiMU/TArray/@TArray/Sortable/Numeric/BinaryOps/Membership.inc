{$IFDEF HELPERS}
function BinaryExistent(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryExistent>
  @action: Performs a binary search on the array to determine if a
           specified item exists. Returns True if found and provides the
           item's index via the out parameter.
  @note: Assumes the array is pre-sorted in ascending or descending order,
         depending on the oAscending flag. Uses a directional multiplier
         for handling sort order efficiently. Returns -1 in the index
         parameter when the item is not found.
[==============================================================================}
function MArrayHelper.BinaryExistent(const item: MType; out index: Integer; const oAscending: Boolean = True): Boolean; overload;
var
  C: MType;
  D: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  D := ((Ord(oAscending) * 2) - 1);
  while (R.start <= R.stop) do
  begin
    index := R.Pivot;
    C := ((Self[index] - item) * D);
    if (C = 0) then
      Exit(True);
    if (C < 0) then
      R.start := (index + 1)
    else
      R.stop := (index - 1);
  end;
  index := -1;
  Result := False;
end;
{$ENDIF}
