{$IFDEF HELPERS}
function IsMonotonic: Boolean; overload;
function Monotonicity: Boolean; overload;
function Monotony: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IsMonotonic>
  @action: Returns True if the array elements are monotonic (entirely non-decreasing or non-increasing).
  @note: Works for empty and single-element arrays (they are trivially monotonic).
[==============================================================================}
function TIntegerArrayHelper.IsMonotonic: Boolean; overload;
var
  c, i: Integer;
  A, D: Boolean;
begin
  A := True;
  D := True;
  for i := 1 to High(Self) do
  begin
    c := (Self[i] - Self[i - 1]);
    if (c > 0) then
      D := False
    else
      if (c < 0) then
        A := False;
    if not (A or D) then
      Exit(False);
  end;
  Result := (A or D);
end;

{==============================================================================]
  <Monotonicity>
  @action:
    Determines whether the array is monotonic — that is, whether all its
    elements are entirely non-decreasing or entirely non-increasing.

    The function compares each element with the previous one, establishing
    a direction based on the first non-equal pair. If any subsequent element
    violates this direction, the function immediately returns False.
  @note:
    • Empty or single-element arrays are considered monotonic (trivially True).
    • Equal adjacent elements do not affect monotonicity.
    • Uses Sign(A - B) to determine the direction between consecutive elements.
    • Short-circuits for efficiency — exits as soon as a violation is detected.
[==============================================================================}
function TIntegerArrayHelper.Monotonicity: Boolean; overload;
var
  s, d, i: Integer;
begin
  d := 0;
  for i := 1 to High(Self) do
  begin
    s := Sign(Self[i] - Self[i - 1]);
    if (s = 0) then
      Continue;
    if (d = 0) then
      d := s
    else if (s <> d) then
      Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <Monotony>
    Determines whether the array is monotone (entirely non-decreasing or
    entirely non-increasing).
  @note:
    • Empty or single-element arrays are considered monotone (trivially True).
    • Equal adjacent elements do not affect monotonicity.
    • Uses Sign(A - B) from Math to compute relative order.
    • Short-circuits for efficiency — exits as soon as a reversal is detected.
    • This version differs from the “direction-lock” version by using an
      accumulated trend variable instead of separate Booleans for ascending
      and descending.
[==============================================================================}
function TIntegerArrayHelper.Monotony: Boolean; overload;
var
  i, t, s: Integer;
begin
  t := 0;
  for i := 1 to High(Self) do
  begin
    s := Sign(Self[i] - Self[i - 1]);
    t := (t or s);
    if (((t = 1) and (s = -1)) or ((t = -1) and (s = 1))) then
      Exit(False);
  end;
  Result := True;
end;
{$ENDIF}
