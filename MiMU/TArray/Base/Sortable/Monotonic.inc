{$IFDEF HELPERS}
function Monotonic: Boolean; overload;
function Monotone: Boolean; overload;
function IsMonotone: Boolean; overload;
function Monotonious: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Monotonic>
  @action: Checks whether the array is globally monotonic by simultaneously comparing
           elements from both ends toward the center, while also validating adjacent pairs.
           Detects ascending or descending trends dynamically based on endpoints.
  @note: Returns True for arrays of length 0 or 1.
         This approach may detect global disorder slightly earlier than adjacent-only checks.
         Performs both global and local comparisons in a single loop.
         Uses Integer_Increment and Integer_Decrement for safe index movement.
[==============================================================================}
function MArrayHelper.Monotonic: Boolean; overload;
var
  L, R: Integer;
begin
  L := -1;
  R := Self.Size;
  if (R > 1) then
  case (Self[L + 1] <= Self[R - 1]) of
    True:
    while (L.Increment < R.Decrement) do
      if ((Self[R] < Self[L]) or (Self[L] > Self[L + 1]) or (Self[R - 1] > Self[R])) then
        Exit(False);
    False:
    while (L.Increment < R.Decrement) do
      if ((Self[R] > Self[L]) or (Self[L] < Self[L + 1]) or (Self[R - 1] < Self[R])) then
        Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <Monotone>
  @action: Checks whether the array is monotonic (ascending or descending) by performing
           a symmetric two-way scan from both ends toward the middle.
           Repeatedly evaluates adjacent pairs and global trend to determine monotonicity.
  @note: Returns True for arrays of length 0 or 1.
         Uses a repeat-until loop with early exit if a violation is detected.
         This function is a slightly simpler alternative to Sortedness, but checks both
         global and local conditions for each iteration.
[==============================================================================}
function MArrayHelper.Monotone: Boolean; overload;
var
  L, R: Integer;
begin
  L := 0;
  R := High(Self);
  if (R <= L) then
    Exit(True);
  case (Self[L] <= Self[R]) of
    True:
    repeat
      Result := not ((Self[L] > Self[L + 1]) or (Self[R - 1] > Self[R]));
    until ((not Result) or ((L.Increment > R.Decrement)));
    False:
    repeat
      Result := not ((Self[L] < Self[L + 1]) or (Self[R - 1] < Self[R]));
    until ((not Result) or ((L.Increment > R.Decrement)));
  end;
end;

{==============================================================================]
  <IsMonotone>
  @action: Determines whether the array is monotone — that is, entirely non-decreasing
           or non-increasing throughout its elements.
           Returns True if the array’s values either never decrease (monotone ascending)
           or never increase (monotone descending). Equal adjacent values are allowed.
           Returns False if the array changes direction (both rises and falls occur).
  @note:
    • Works correctly for arrays of any length.
      (Empty or single-element arrays are considered monotone.)
    • The function short-circuits for efficiency — exits early once a
      non-monotone pattern is detected.
[==============================================================================}
function MArrayHelper.IsMonotone: Boolean; overload;
var
  i: Integer;
  A, D: Boolean;
begin
  A := True;
  D := True;
  for i := 1 to High(Self) do
  begin
    case Self[i].Sign(Self[i - 1]) of
      0: Continue;
      1: D := False;
      -1: A := False;
    end;
    if not (A or D) then
      Exit(False);
  end;
  Result := (A or D);
end;

{==============================================================================]
  <Monotonious>
  @action:
    Determines whether the integer array is monotone — that is, entirely
    non-decreasing or entirely non-increasing.

    The function iterates through the array, comparing each element with its
    predecessor. Two variables track whether any increases (`h`) or decreases
    (`l`) have been observed. If both an increase and a decrease occur, the
    array is not monotone, and the function immediately returns False. Otherwise,
    it returns True.
  @note:
    • Empty or single-element arrays are considered monotone (trivially True).
    • Equal adjacent elements do not affect monotonicity.
    • Uses two integer flags (`h` for increases, `l` for decreases) instead of
      a single accumulator or Boolean pair.
    • Short-circuits for efficiency — exits as soon as both directions are seen.
    • This is functionally equivalent to other “direction-lock” or “accumulator”
      implementations but tracks high/low separately.
[==============================================================================}
function MArrayHelper.Monotonious: Boolean; overload;
var
  i, h, l: Integer;
begin
  l := 0;
  h := 0;
  for i := 1 to High(Self) do
  begin
    if (Self[i] = Self[i - 1]) then
      Continue;
    if (Self[i] > Self[i - 1]) then
      h := 1
    else if (Self[i] < Self[i - 1]) then
      l := -1;
    if ((h = 1) and (l = -1)) then
      Exit(False);
  end;
  Result := True;
end;
{$ENDIF}