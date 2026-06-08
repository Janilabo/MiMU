{$IFDEF HELPERS}
function Ascending: Boolean; overload;
function Descending: Boolean; overload;
function Decreasing: Boolean; overload;
function Direction: Integer; overload;
function Downward: Boolean; overload;
function Falling: Boolean; overload;
function Increasing: Boolean; overload;
function IsAsc(const strictly: Boolean = False): Boolean; overload;
function IsDesc(const strictly: Boolean = False): Boolean; overload;
function IsStrictAscending: Boolean; overload;
function IsStrictDescending: Boolean; overload;
function Orientation: Integer; overload;
function Rising: Boolean; overload;
function StrictlyAscending: Boolean; overload;
function StrictlyAscends: Boolean; overload;
function StrictlyDecreasing: Boolean; overload;
function StrictlyDescending: Boolean; overload;
function StrictlyDescends: Boolean; overload;
function StrictlyIncreasing: Boolean; overload;
function Unidirectional: Boolean; overload;
function Upward: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascending>
  @action: Returns true if array arr is in asscending order.
  @note: [0,1] = True | [0,0] = False | [1,0] = False |
[==============================================================================}
function MArrayHelper.Ascending: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i - 1] > Self[i]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <Decreasing>
  @action: Returns true if array arr is in descending order.
  @note: [0,1] = False | [0,0] = True | [1,0] = True |
[==============================================================================}
function MArrayHelper.Decreasing: Boolean; overload;
var
  i: Integer;
begin
  for i := High(Self) downto 1 do
    if (Self[i] > Self[i - 1]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <Descending>
  @action: Returns true if array arr is in descending order.
  @note: [0,1] = False | [0,0] = False | [1,0] = True |
[==============================================================================}
function MArrayHelper.Descending: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i - 1] < Self[i]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <Direction>
  @action: Returns numeric trend across the entire array:
           1 = Rising (monotonically non-decreasing),
          -1 = Falling (monotonically non-increasing),
           0 = Notrending (mixed sequence or empty/single element).
  @note: Checks all elements. Inclusive comparisons (≤ / ≥).
[==============================================================================}
function MArrayHelper.Direction: Integer; overload;
begin
  if Self.Notrending then
    Result := 0
  else if Rising then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
  <Downward>
  @action: Returns true if array arr is in descending order.
  @note: Returns true with empty []array! Unlike Descending, Decreasing.
[==============================================================================}
function MArrayHelper.Downward: Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  while (h.Decrement > -1) do
    if (Self[h] < Self[h + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Falling>
  @action: Returns True if the array is monotonically non-increasing,
           i.e., each element is greater than or equal to the next.
  @note: Arrays with 0 or 1 element are considered Falling by default.
         Checks all elements, not just the first and last.
[==============================================================================}
function MArrayHelper.Falling: Boolean; overload;
var
  i: Integer;
begin
  for i := Low(Self) to (High(Self) - 1) do
    if (Self[i] < Self[i + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Increasing>
  @action: Returns true if array arr is in asscending order.
  @note: [0,1] = True | [0,0] = True | [1,0] = False |
[==============================================================================}
function MArrayHelper.Increasing: Boolean; overload;
var
  i: Integer;
begin
  for i := High(Self) downto 1 do
    if (Self[i] < Self[i - 1]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <IsAsc>
  @action: Checks if the array's endpoints indicate an ascending trend.
  @param: strictly - If true, requires the first element to be strictly less
           than the last element. Defaults to False.
  @note: Uses short-circuit evaluation (h > -1) to safely handle empty arrays
         without throwing an index exception.
[==============================================================================}
function MArrayHelper.IsAsc(const strictly: Boolean = False): Boolean; overload;
var
  h: Integer;
begin
  Result := ((h.Assign(High(Self)) > -1) and ((Self[0] < Self[h]) or ((not strictly) and (Self[0] = Self[h]))));
end;

{==============================================================================]
  <IsDesc>
  @action: Checks if the array's endpoints indicate a descending trend.
  @param: strictly If true, requires the first element to be strictly greater
          than the last element. Defaults to False.
  @return: True if a descending trend is detected; otherwise False.
  @note: Uses short-circuit evaluation (h > -1) to safely handle empty arrays
         without throwing an index exception.
[==============================================================================}
function MArrayHelper.IsDesc(const strictly: Boolean = False): Boolean; overload;
var
  h: Integer;
begin
  Result := ((h.Assign(High(Self)) > -1) and ((Self[0] > Self[h]) or ((not strictly) and (Self[0] = Self[h]))));
end;

{==============================================================================]
  <IsStrictAscending>
  @action: Sequential check for strict ascending order with early exit.
  @note: Highly optimized for CPU branch prediction and immediate failure exit.
[==============================================================================}
function MArrayHelper.IsStrictAscending: Boolean; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l <= 1) then
    Exit(l = 1);
  if (Self[0] >= Self[1]) then
    Exit(False);
  for i := 1 to (l - 2) do
    if (Self[i] >= Self[i + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <IsStrictDescending>
  @action: Sequential check for strict descending order with early exit.
  @note: Highly optimized for CPU branch prediction and immediate failure exit.
[==============================================================================}
function MArrayHelper.IsStrictDescending: Boolean; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l <= 1) then
    Exit(l = 1);
  if (Self[0] <= Self[1]) then
    Exit(False);
  for i := 1 to (l - 2) do
    if (Self[i] <= Self[i + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Orientation>
  @action: Returns the direction which way array goes
  @note: -1 = DESCENDING, 0=NO ORDER OR MIXED ARRAY, 1=ASCENDING
         [1,2,3] => 1 [1,1,1] => 0 [1,0,1] => 0 [3,2,1] => -1
[==============================================================================}
function MArrayHelper.Orientation: Integer; overload;
var
  i: Integer;
  a, d: Boolean;
begin
  if not Self.Multi then
    Exit(0);
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
  <Rising>
  @action: Returns True if the array is monotonically non-decreasing,
           i.e., each element is less than or equal to the next.
  @note: Arrays with 0 or 1 element are considered Rising by default.
         Checks all elements, not just the first and last.
[==============================================================================}
function MArrayHelper.Rising: Boolean; overload;
var
  i: Integer;
begin
  for i := Low(Self) to (High(Self) - 1) do
    if (Self[i] > Self[i + 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <StrictlyAscending>
  @action: Checks if the array elements are strictly increasing.
  @note: Returns False if any element is less than or equal to the preceding one,
         or if the array is empty (no duplicates allowed).
[==============================================================================}
function MArrayHelper.StrictlyAscending: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i - 1] >= Self[i]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <StrictlyAscends>
  @action: Checks if the array is strictly sorted in ascending order.
  @note: Uses a two-pointer approach checking from both ends simultaneously.
         Returns False if any adjacent elements are equal.
[==============================================================================}
function MArrayHelper.StrictlyAscends: Boolean; overload;
var
  r, l: Integer;
begin
  r := Self.Length;
  l := -1;
  Result := (r > 0);
  while (Result and (l.Increment < r.Decrement)) do
    Result := ((Self[l] < Self[l + 1]) and (Self[r - 1] < Self[r]));
end;

{==============================================================================]
  <StrictlyDecreasing>
  @action: Checks if the elements of the integer array are in a strictly decreasing order.
  @note: Uses a while loop with an increment helper. Returns False if any element is
         less than or equal to the next one, or if the array is empty.
[==============================================================================}
function MArrayHelper.StrictlyDecreasing: Boolean; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  i := 0;
  Result := (l > 0);
  while (Result and (i.Increment < l)) do
    Result := (Self[i - 1] > Self[i]);
end;

{==============================================================================]
  <StrictlyDescending>
  @action: Checks if the array elements are strictly decreasing.
  @note: Returns False if any element is greater than or equal to the preceding one,
         or if the array is empty (no duplicates allowed).
[==============================================================================}
function MArrayHelper.StrictlyDescending: Boolean; overload;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i - 1] <= Self[i]) then
      Exit(False);
  Result := (High(Self) > -1);
end;

{==============================================================================]
  <StrictlyDescends>
  @action: Checks if the array is strictly sorted in descending order.
  @note: Uses a two-pointer approach checking from both ends simultaneously.
         Returns False if any adjacent elements are equal.
[==============================================================================}
function MArrayHelper.StrictlyDescends: Boolean; overload;
var
  r, l: Integer;
begin
  r := Self.Length;
  l := -1;
  Result := (r > 0);
  while (Result and (l.Increment < r.Decrement)) do
    Result := ((Self[l] > Self[l + 1]) and (Self[r - 1] > Self[r]));
end;

{==============================================================================]
  <StrictlyIncreasing>
  @action: Checks if the elements of the integer array are in a strictly increasing order.
  @note: Uses a while loop with an increment helper. Returns False if any element is
         greater than or equal to the next one, or if the array is empty.
[==============================================================================}
function MArrayHelper.StrictlyIncreasing: Boolean; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  i := 0;
  Result := (l > 0);
  while (Result and (i.Increment < l)) do
    Result := (Self[i - 1] < Self[i]);
end;

{==============================================================================]
  <Unidirectional>
  @action: Checks if the array is monotonic (either non-decreasing or non-increasing).
  @note: Returns True if all elements move in one direction, False otherwise.
[==============================================================================}
function MArrayHelper.Unidirectional: Boolean; overload;
label
  D;
var
  i: Integer;
begin
  for i := 1 to High(Self) do
    if (Self[i] < Self[i - 1]) then
      goto D;
  Exit(True);
  D:
  for i := 1 to High(Self) do
    if (Self[i] > Self[i - 1]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Upward>
  @action: Returns true if array arr is in ascending order.
  @note: Returns true with empty [] array! Unlike Ascending, Increasing.
[==============================================================================}
function MArrayHelper.Upward: Boolean; overload;
var
  h: Integer;
begin
  h := High(Self);
  while (h.Decrement > -1) do
    if (Self[h] > Self[h + 1]) then
      Exit(False);
  Result := True;
end;
{$ENDIF}