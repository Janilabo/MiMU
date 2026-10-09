{$IFDEF HELPERS}
function Ternum(var iMin, iMid, iMax: MType): Boolean; overload;
function Trifecta(var iMin, iMid, iMax: MType): Boolean; overload;
function Trine(var iMin, iMid, iMax: MType): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ternum>
  @action: Reads the lowest, middle-ranked and highest values of Self in a
           single call. Returns False (leaving all three out parameters
           untouched) when Self is empty, True otherwise. Works on unsorted
           input.
  @note: Non-mutating: min and max come from one linear scan of Self, and the
         middle value from QuickSelect on a clone, so Self keeps its order.
         iMid is the element of ascending rank High(Self) div 2 (0-based),
         not an arithmetic median: for even lengths it is the lower of the
         two middle elements, since averaging is not defined for every MType
         (e.g. strings). Ordered-only: needs just < and >. O(n) average,
         O(n^2) worst case (inherited from QuickSelect), plus the O(n) clone.
         Float arrays containing NaN are undefined.
[==============================================================================}
function MArrayHelper.Ternum(var iMin, iMid, iMax: MType): Boolean; overload;
var
  s: MArray;
  i: Integer;
begin
  Result := (Self.Length > 0);
  if not Result then
    Exit;
  iMin := Self[0];
  iMax := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] < iMin) then
	  iMin := Self[i]
    else if (Self[i] > iMax) then
	  iMax := Self[i];
  s := Self.Cloned;
  iMid := s.QuickSelect(High(s) div 2);
end;

{==============================================================================]
  <Trifecta>
  @action: Reads the lowest, middle-ranked and highest values of Self in a
           single call. Returns False (leaving all three out parameters
           untouched) when Self is empty, True otherwise. Works on unsorted
           input.
  @note: Non-mutating: the middle value is selected from a copy, so Self keeps
         its order. iMid is the element of rank High(Self) div 2 (0-based), not
         an arithmetic median: for even lengths it is the lower of the two
         middle elements, since averaging is not defined for every MType (e.g.
         strings). Ordered-only: needs just < and >. Float arrays containing
         NaN are undefined.
[==============================================================================}
function MArrayHelper.Trifecta(var iMin, iMid, iMax: MType): Boolean; overload;
var
  i: Integer;
begin
  Result := (Self.Length > 0);
  if not Result then
    Exit;
  iMin := Self[0];
  iMid := Self[0];
  iMax := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] < iMin) then
      iMin := Self[i]
    else if (Self[i] > iMax) then
      iMax := Self[i]
    else
      iMid := Self[i];
end;

{==============================================================================]
  <Trine>
  @action: Reads the lowest, middle-ranked and highest values of Self in a
           single call. Returns False (leaving all three out parameters
           untouched) when Self is empty, True otherwise. Works on unsorted
           input.
  @note: Non-mutating: Self is sorted as a copy (QuickSorted), so it keeps its
         order, and all three values are read off the sorted copy by rank.
         iMid is the element of ascending rank High(Self) div 2 (0-based), not
         an arithmetic median: for even lengths it is the lower of the two
         middle elements, since averaging is not defined for every MType
         (e.g. strings). Ordered-only: needs just < and >. O(n log n) average
         (worst case inherited from QuickSorted), plus the O(n) copy. Does a
         full sort where only three ranks are needed; see Ternum for the
         selection-based O(n) average variant.
[==============================================================================}
function MArrayHelper.Trine(var iMin, iMid, iMax: MType): Boolean; overload;
var
  h: Integer;
  s: MArray;
begin
  h := High(Self);
  Result := (h > -1);
  if not Result then
    Exit;
  s := Self.QuickSorted;
  iMin := s[0];
  iMax := s[h];
  iMid := s[h div 2];
end;
{$ENDIF}
