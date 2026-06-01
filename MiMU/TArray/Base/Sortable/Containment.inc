{$IFDEF HELPERS}
function Aboard(const sItem: MType): Boolean; overload;
function Ascont(const sItem: MType): Boolean; overload;
function Descont(const sItem: MType): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Aboard>
  @action: Automatically detects array sorting direction (ascending vs.
           descending) and queries membership using an optimized dual-path
           binary search.
  @param: item The integer value to locate within the array.
  @return: True if the item exists in the array; otherwise False.
  @note: Safely handles empty structures (Length = 0) and includes an
         instant evaluation shortcut for single-element arrays (Length = 1)
         before launching the O(log n) search loops.
[==============================================================================}
function MArrayHelper.Aboard(const sItem: MType): Boolean; overload;
var
  l, h, m: Integer;
begin
  if (h.Assign(High(Self)) > -1) then
  case (h = 0) of
    False:
    begin
      l := 0;
      case (Self[0] > Self[h]) of
        True:
        while (l <= h) do
        begin
          m := ((l + h) div 2);
          if (Self[m] = sItem) then
            Exit(True);
          if (Self[m] < sItem) then
            h := (m - 1)
          else
            l := (m + 1);
        end;
        False:
        while (l <= h) do
        begin
          m := ((l + h) div 2);
          if (Self[m] = sItem) then
            Exit(True);
          if (Self[m] < sItem) then
            l := (m + 1)
          else
            h := (m - 1);
        end;
      end;
    end;
    True: Exit(Self[0] = sItem);
  end;
  Result := False;
end;

{==============================================================================]
  <Ascont>
  @action: Checks if a item exists using a fast binary search algorithm.
  @note: REQUIRES THE ARRAY TO BE SORTED IN ASCENDING ORDER.
[==============================================================================}
function MArrayHelper.Ascont(const sItem: MType): Boolean; overload;
var
  l, h, m: Integer;
begin
  l := 0;
  h := High(Self);
  while (l <= h) do
  begin
    m := ((l + h) div 2);
    if (Self[m] = sItem) then
      Exit(True)
    else if (Self[m] < sItem) then
      l := (m + 1)
    else
      h := (m - 1);
  end;
  Result := False;
end;

{==============================================================================]
  <Descont>
  @action: Checks if a item exists in a descending-sorted array using binary search.
  @note: REQUIRES THE ARRAY TO BE SORTED IN DESCENDING ORDER.
[==============================================================================}
function MArrayHelper.Descont(const sItem: MType): Boolean; overload;
var
  l, h, m: Integer;
begin
  l := 0;
  h := High(Self);
  while (l <= h) do
  begin
    m := (l + h) div 2;
    if (Self[m] = sItem) then
      Exit(True)
    else if (Self[m] < sItem) then
      h := (m - 1)
    else
      l := (m + 1);
  end;
  Result := False;
end;
{$ENDIF}