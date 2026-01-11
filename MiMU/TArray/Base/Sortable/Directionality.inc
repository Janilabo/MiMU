{$IFDEF HELPERS}
function Direction: Integer; overload;
function Rising: Boolean; overload;
function Falling: Boolean; overload;
function Descending: Boolean; overload;
function Ascending: Boolean; overload;
function Decreasing: Boolean; overload;
function Increasing: Boolean; overload;
function Downward: Boolean; overload;
function Upward: Boolean; overload;
function Orientation: Integer; overload;
function Unidirectional: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  else
    if Rising then
      Result := 1
    else
      Result := -1;
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
{$ENDIF}