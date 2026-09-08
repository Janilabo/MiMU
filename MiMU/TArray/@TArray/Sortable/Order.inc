{$IFDEF HELPERS}
function AnOrder(const oAscending: Boolean = True): Boolean; overload;
function AtOrder(const oAscending: Boolean = True): Boolean; overload;
function Orda(const oAscending: Boolean = True): Boolean; overload;
function Order: Integer; overload;
function Orderal(const oAscending: Boolean = True): Boolean; overload;
function Orderly: Boolean; overload;
function Ordered(const aAscending: Boolean = True; const index: Integer = 0): Boolean; overload;
function Ordering(const oAscending: Boolean = True): Boolean; overload;
function Orderion: Boolean; overload;
function Orderion(out sDirection: Integer): Boolean; overload;
function Orderious(const oAscending: Boolean = True): Boolean; overload;
function Ordo(const oAscending: Boolean = True): Boolean; overload;
function InOrder(const aAscending: Boolean = True): Boolean; overload;
function IsOrder(const oAscending: Boolean = True): Boolean; overload;
function OnOrder: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AnOrder>
  @action: Determines whether the array elements maintain a monotonic order 
           according to the specified direction (ascending or descending).
  @note: Uses a dual-pointer inward convergence loop with local adjacent 
         and cross-boundary invariant checks for early termination.
[==============================================================================}
function MArrayHelper.AnOrder(const oAscending: Boolean = True): Boolean; overload;
var
  L, R: Integer;
begin
  L := -1;
  R := Self.Length;
  if (R > 1) then
  case oAscending of
    True:
    while (L.Increment < R.Decrement) do
      if ((Self[L] > Self[L + 1]) or (Self[R - 1] > Self[R]) or (Self[L] > Self[R])) then
        Exit(False);
    False:
    while (L.Increment < R.Decrement) do
      if ((Self[L] < Self[L + 1]) or (Self[R - 1] < Self[R]) or (Self[L] < Self[R])) then
        Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <AtOrder>
  @action: Verifies whether Self is already sorted in the given direction —
           non-decreasing if `oAscending`, non-increasing otherwise — using
           the three-way `Compare` comparator on each adjacent pair, with
           early exit on the first violation.
  @note: Non-strict: equal adjacent elements never trigger a violation in
         either direction, so this checks "sorted" in the monotonic sense,
         not strictly increasing/decreasing. Trivially returns True for
         length 0 or 1 (loop body never runs).
[==============================================================================}
function MArrayHelper.AtOrder(const oAscending: Boolean = True): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to (High(Self) - 1) do
    if ((oAscending and (Self[i].Compare(Self[i + 1]) > 0)) or (not oAscending and (Self[i].Compare(Self[i + 1]) < 0))) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Orda>
  @action: Validates whether the array elements are sorted in the specified 
           directional order using a diminishing ShellSort gap sequence.
  @note: Performs multi-pass gap checks (Knuth sequence: h = 3h + 1) down to 
         h = 1 to detect distant non-monotonicity early. Exits immediately on 
         the first detected inversion across any gap stride.
[==============================================================================}
function MArrayHelper.Orda(const oAscending: Boolean = True): Boolean; overload;
var
  l, i, h: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(True);
  h := 1;
  while (h < (l div 3)) do
    h := ((3 * h) + 1);
  case oAscending of
    True:
    while (h >= 1) do
    begin
      for i := 0 to (l - 1 - h) do
        if (Self[i] > Self[i + h]) then
          Exit(False);
      h := (h div 3);
    end;
    False:
    while (h >= 1) do
    begin
      for i := 0 to (l - 1 - h) do
        if (Self[i] < Self[i + h]) then
          Exit(False);
      h := (h div 3);
    end;
  end;
  Result := True;
end;

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
  <Orderal>
  @action: Verifies whether the array elements are strictly sorted in the 
           specified directional order (ascending or descending).
  @note: Uses a dual-ended inward scan with rolling min/max bounds tracking 
         to perform an efficient single-pass order validation.
[==============================================================================}
function MArrayHelper.Orderal(const oAscending: Boolean = True): Boolean; overload;
var
  l, h: MType;
  s: TRange;
begin
  s.Create(-1, Self.Length);
  if (s.stop > 1) then
  begin
    l := Self[s.start + 1];
    h := Self[s.stop - 1];
    case oAscending of
      True:
      while (s.start.Increment <= s.stop.Decrement) do
        if (l.MinWith(Self[s.start]) or h.MaxWith(Self[s.stop]) or (Self[s.start] > Self[s.stop])) then
          Exit(False);
      False:
      while (s.start.Increment <= s.stop.Decrement) do
        if (l.MaxWith(Self[s.start]) or h.MinWith(Self[s.stop]) or (Self[s.start] < Self[s.stop])) then
          Exit(False);
    end;
  end;
  Result := True;
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
  <Orderion>
  @action: Determines whether Self is monotonic (non-decreasing or
           non-increasing) in a single effective pass, and reports the
           direction found via the `sDirection` out parameter (+1 ascending,
           -1 descending, 0 if no strict direction exists — length < 2 or all
           elements equal). Returns False on the first reversal encountered
           after a direction has been established.
  @note: Relies on the FPC-specific (non-portable-Pascal) guarantee that a
         `for` loop's counter retains its value after `Break` — the second
         loop resumes scanning from where the first loop broke off rather
         than re-checking the pair that established the direction.
[==============================================================================}
function MArrayHelper.Orderion(out sDirection: Integer): Boolean; overload;
var
  i, s: Integer;
begin
  sDirection := 0;
  if (Self.Length < 2) then
    Exit(True);
  for i := 0 to (High(Self) - 1) do
  begin
    if (Self[i] < Self[i + 1]) then
      sDirection := 1
    else if (Self[i] > Self[i + 1]) then
      sDirection := -1;
    if (sDirection <> 0) then
      Break;
  end;
  if (sDirection = 0) then
    Exit(True);
  for i := (i + 1) to (High(Self) - 1) do
    if ((sDirection = 1) and (Self[i] > Self[i + 1])) then
      Exit(False)
    else if ((sDirection = -1) and (Self[i] < Self[i + 1])) then
      Exit(False);
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
  <Ordo>
  @action: Validates array order using a divide-and-conquer QuickSort partitioning
           strategy to detect global and regional inversions early.
  @note:   Selects a median pivot per sub-range and verifies partition boundary
           invariants before recursively validating left and right partitions.
[==============================================================================}
function MArrayHelper.Ordo(const oAscending: Boolean = True): Boolean; overload;
  function A(aLow, aHigh: Integer): Boolean;
  var
    p: MType;
    m, i: Integer;
  begin
    if ((aHigh - aLow) < 1) then
      Exit(True);
    m := (aLow + (aHigh - aLow) div 2);
    p := Self[m];
    for i := aLow to (m - 1) do
      if (Self[i] > p) then
        Exit(False);
    for i := (m + 1) to aHigh do
      if (Self[i] < p) then
        Exit(False);
    Result := (A(aLow, (m - 1)) and A((m + 1), aHigh));
  end;
  function D(aLow, aHigh: Integer): Boolean;
  var
    p: MType;
    m, i: Integer;
  begin
    if ((aHigh - aLow) < 1) then
      Exit(True);
    m := (aLow + (aHigh - aLow) div 2);
    p := Self[m];
    for i := aLow to (m - 1) do
      if (Self[i] < p) then
        Exit(False);
    for i := (m + 1) to aHigh do
      if (Self[i] > p) then
        Exit(False);
    Result := (D(aLow, (m - 1)) and D((m + 1), aHigh));
  end;
begin
  if (Self.Length < 2) then
    Exit(True);
  if oAscending then
    Result := A(0, (Self.Length - 1))
  else
    Result := D(0, (Self.Length - 1));
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
