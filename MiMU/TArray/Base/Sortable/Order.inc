{$IFDEF HELPERS}
function Orderly: Boolean; overload; cdecl;
function Ordered(const aAscending: Boolean = True; const index: Integer = 0): Boolean; overload; cdecl;
function Order: Integer; overload; cdecl;
function InOrder(const aAscending: Boolean = True): Boolean; overload; cdecl;
function OnOrder: Boolean; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Orderly>
  @action: Returns true if array arr is in ascending AND/OR descending order.
  @note: None.
[==============================================================================}
function MArrayHelper.Orderly: Boolean; overload; cdecl;
var
  i: Integer;
  a, d: Boolean;
begin
  a := True;
  d := True;
  for i := 0 to (High(Self) - 1) do
  begin
    if (Self[i] > Self[i + 1]) then
      a := False;
    if (Self[i] < Self[i + 1]) then
      d := False;
    if not (a or d) then
      Break;
  end;
  Result := (a or d);
end;

{==============================================================================]
  <Ordered>
  @action: Returns true if array arr is in ascending AND/OR descending order by aAscending.
  @note: Recursive alternative.
[==============================================================================}
function MArrayHelper.Ordered(const aAscending: Boolean = True; const index: Integer = 0): Boolean; overload; cdecl;
begin
  if (index >= High(Self)) then
    Exit(True);
  if ((aAscending and (Self[index] > Self[index + 1])) or ((not aAscending) and (Self[index] < Self[index + 1]))) then
    Exit(False);
  Result := Self.Ordered(aAscending, (index + 1));
end;

{==============================================================================]
  <Order>
  @action: Returns the direction which way array goes
  @note: -1 = DESCENDING, 0=NO ORDER OR MIXED ARRAY, 1=ASCENDING
         [1,2,3] => 1 [1,1,1] => 1 [1,0,1] => 0 [3,2,1] => -1
[==============================================================================}
function MArrayHelper.Order: Integer; overload; cdecl;
var
  i, l: Integer;
  a, d: Boolean;
begin
  l := Self.Length;
  case l of
    0: Exit(0);
    1: Exit(1);
  end;
  a := True;
  d := True;
  for i := 1 to (l - 1) do
  begin
    if (Self[i] < Self[i - 1]) then
      a := False
    else
      if (Self[i] > Self[i - 1]) then
        d := False;
    if not (a or d) then
      Exit(0);
  end;
  if a then
    Result := 1
  else
    if d then
      Result := -1
    else
      Result := 0;
end;

{==============================================================================]
  <InOrder>
  @action: Returns true if array arr is in ascending/descending order by aAscending.
  @note: By default checking for ascending order.
[==============================================================================}
function MArrayHelper.InOrder(const aAscending: Boolean = True): Boolean; overload; cdecl;
var
  i, l: Integer;
begin
  i := -1;
  l := Self.Length;
  Result := (l > 0);
  if (l > 1) then
  case aAscending of
    True:
    while (i.Increment < l.Decrement) do
      if ((Self[i] > Self[i + 1]) or (Self[l - 1] > Self[l])) then
        Exit(False);
    False:
    while (i.Increment < l.Decrement) do
      if ((Self[i] < Self[i + 1]) or (Self[l - 1] < Self[l])) then
        Exit(False);
  end;
end;

{==============================================================================]
  <OnOrder>
  @action: Determines whether the array elements remain consistently ordered,
           either non-decreasing, non-increasing, or constant.
  @note: Returns True if the sequence does not reverse direction (monotonic in
         either direction). Returns False if the order changes (both rises and falls occur).
[==============================================================================}
function MArrayHelper.OnOrder: Boolean; overload; cdecl;
var
  i, h, l: Integer;
begin
  h := 0;
  l := 0;
  for i := 1 to High(Self) do
    if ((h.Increment(Self[i] > Self[i - 1]) * l.Increment(Self[i] < Self[i - 1])) > 0) then
      Exit(False);
  Result := True;
end;
{$ENDIF}