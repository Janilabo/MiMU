{$IFDEF HELPERS}
function Ascont(const sItem: MType): Boolean; overload;
function Descont(const sItem: MType): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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