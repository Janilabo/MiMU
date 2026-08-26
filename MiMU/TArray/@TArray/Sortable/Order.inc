{$IFDEF HELPERS}
function Order: Integer; overload;
function Orderly: Boolean; overload;
function Ordered(const aAscending: Boolean = True; const index: Integer = 0): Boolean; overload;
function Ordering(const oAscending: Boolean = True): Boolean; overload;
function Orderion: Boolean; overload;
function Orderious(const oAscending: Boolean = True): Boolean; overload;
function InOrder(const aAscending: Boolean = True): Boolean; overload;
function IsOrder(const oAscending: Boolean = True): Boolean; overload;
function OnOrder: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Order>
  @action: Returns the direction which way array goes
  @note: -1 = DESCENDING, 0=NO ORDER OR MIXED ARRAY, 1=ASCENDING
         [1,2,3] => 1 [1,1,1] => 1 [1,0,1] => 0 [3,2,1] => -1
[==============================================================================}
function MArrayHelper.Order: Integer; overload;
var
  i, l: Integer;
  a, d: Boolean;
begin
  case Self.Length of
    0: Exit(0);
    1: Exit(1);
  end;
  a := True;
  d := True;
  for i := 1 to High(Self) do
  begin
    if (Self[i] < Self[i - 1]) then
      a := False
    else if (Self[i] > Self[i - 1]) then
      d := False;
    if not (a or d) then
      Exit(0);
  end;
  if a then
    Result := 1
  else if d then
    Result := -1
  else
    Result := 0;
end;

{==============================================================================]
  <Orderly>
  @action: Returns true if array arr is in ascending AND/OR descending order.
  @note: None.
[==============================================================================}
function MArrayHelper.Orderly: Boolean; overload;
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
function MArrayHelper.Ordered(const aAscending: Boolean = True; const index: Integer = 0): Boolean; overload;
begin
  if (index >= High(Self)) then
    Exit(True);
  if ((aAscending and (Self[index] > Self[index + 1])) or ((not aAscending) and (Self[index] < Self[index + 1]))) then
    Exit(False);
  Result := Self.Ordered(aAscending, (index + 1));
end;

{==============================================================================]
  <Ordering>
  @action: Verifies whether the entire array is sorted according to the
           specified order (ascending or descending). Returns True if the
           array respects that order, False otherwise.
  @note: - Arrays of length 0 or 1 are considered trivially sorted.
         - Equality is allowed (non‑strict monotonicity). Thus, adjacent
           equal elements do not break the order.
         - Complexity: O(n) – linear scan.
         - Useful as a precondition check before calling any binary‑search
           method (since they all assume a sorted array). Can be used in
           debug assertions or input validation.
         - The name "Ordering" suggests the function is checking the
           array's order property; alternative common names for this
           routine are `IsSorted`, `IsOrdered`, or `Sorted`.
[==============================================================================}
function MArrayHelper.Ordering(const oAscending: Boolean = True): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to (Self.Length - 2) do
    if ((oAscending and (Self[i] > Self[i + 1])) or ((not oAscending) and (Self[i] < Self[i + 1]))) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Orderion>
  @action: Returns True if the array is monotonic — either entirely
           non-decreasing or entirely non-increasing throughout. Returns
           False as soon as both an ascending pair and a descending pair
           have been observed, meaning the sequence changes direction.
  @note: Ordered-only tier (relies on `<`/`>`). Equal adjacent elements
         are neutral — they don't count toward either direction, so a
         sequence with repeated values can still register as monotonic.
         Single-pass, early-exits the moment direction reverses rather
         than scanning to completion.
[==============================================================================}
function MArrayHelper.Orderion: Boolean; overload;
var
  i, a, d: Integer;
begin
  a := 0;
  d := 0;
  for i := 1 to High(Self) do
  begin
    if (Self[i] < Self[i - 1]) then
      Inc(a)
    else if (Self[i] > Self[i - 1]) then
      Inc(d);
    if ((a * d) > 0) then
      Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <Orderious>
  @action: Checks whether the array is sorted in ascending (True) or descending (False) order using a recursive divide-and-conquer approach.
  @note: Returns True if sorted, False otherwise.
[==============================================================================}
function MArrayHelper.Orderious(const oAscending: Boolean = True): Boolean; overload;
  function A(const aLow, aHigh: Integer): Boolean;
  var
    m: Integer;
  begin
    if (aLow >= aHigh) then
      Exit(True);
    m := (aLow + (aHigh - aLow) div 2);
    Result := ((Self[m] <= Self[m + 1]) and A(aLow, m) and A((m + 1), aHigh));
  end;
  function D(const aLow, aHigh: Integer): Boolean;
  var
    m: Integer;
  begin
    if (aLow >= aHigh) then
      Exit(True);
    m := (aLow + (aHigh - aLow) div 2);
    Result := ((Self[m] >= Self[m + 1]) and D(aLow, m) and D((m + 1), aHigh));
  end;
begin
  if oAscending then
    Result := A(0, High(Self))
  else
    Result := D(0, High(Self));
end;

{==============================================================================]
  <InOrder>
  @action: Returns true if array arr is in ascending/descending order by aAscending.
  @note: By default checking for ascending order.
[==============================================================================}
function MArrayHelper.InOrder(const aAscending: Boolean = True): Boolean; overload;
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
  <IsOrder>
  @action: Checks whether the array is sorted in ascending or descending order based on the oAscending parameter.
           Returns True if sorted, False otherwise.
  @note: The loop uses a strided index pattern (i * 2) + j that checks adjacent elements in two separate passes (even and odd starting pairs).
[==============================================================================}
function MArrayHelper.IsOrder(const oAscending: Boolean = True): Boolean; overload;
var
  h, i, j: Integer;
begin
  h := High(Self);
  if (h > 0) then
  case oAscending of
    True:
    for j := 0 to 1 do
      for i := 0 to (((h + (1 - j)) div 2) - 1) do
        if (Self[(i * 2) + j] > Self[(i * 2) + (1 + j)]) then
          Exit(False);
    False:
    for j := 0 to 1 do
      for i := 0 to (((h + (1 - j)) div 2) - 1) do
        if (Self[(i * 2) + j] < Self[(i * 2) + (1 + j)]) then
          Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <OnOrder>
  @action: Determines whether the array elements remain consistently ordered,
           either non-decreasing, non-increasing, or constant.
  @note: Returns True if the sequence does not reverse direction (monotonic in
         either direction). Returns False if the order changes (both rises and falls occur).
[==============================================================================}
function MArrayHelper.OnOrder: Boolean; overload;
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