{$IFDEF HELPERS}
function IsMonotonic: Boolean; overload;
function Monotonicity: Boolean; overload;
function Monotony: Boolean; overload;
function Pure(const allowed: TDoubleArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IsMonotonic>
  @action: Returns True if the array elements are monotonic (entirely non-decreasing or non-increasing).
  @note: Works for empty and single-element arrays (they are trivially monotonic).
[==============================================================================}
function TDoubleArrayHelper.IsMonotonic: Boolean; overload;
var
  c: Double;
  i: Integer;
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
function TDoubleArrayHelper.Monotonicity: Boolean; overload;
var
  s, d: Double;
  i: Integer;
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
  @action:
    Determines whether the array of doubles is monotone — that is, whether all 
    its elements are entirely non-decreasing or entirely non-increasing.

    The function iterates through adjacent elements, computing the difference
    between each pair. If the difference is smaller than a small tolerance (EPS),
    the elements are considered equal. Otherwise, the sign of the difference 
    establishes the direction (increasing or decreasing). Once a direction is 
    locked, any reversal causes the function to return False immediately.

  @note:
    • Empty or single-element arrays are considered monotone (trivially True).  
    • Equal adjacent elements (within EPS tolerance) do not affect monotonicity.  
    • EPS is a small threshold to account for floating-point rounding errors.  
    • The function short-circuits for efficiency — exits as soon as a direction
      reversal is detected.  
    • Uses Sign(c) from Math unit to determine the direction of change.
[==============================================================================}
function TDoubleArrayHelper.Monotony: Boolean; overload;
const
  EPS = 1E-12;
var
  i, s, d: Integer;
  c: Double;
begin
  d := 0;
  for i := 1 to High(Self) do
  begin
    c := (Self[i] - Self[i - 1]);
    if (Abs(c) < EPS) then
      s := 0
    else
      s := Sign(c);
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
  <Pure>
  @action: Returns true if arr is made with only allowed items.
  @note: None.
[==============================================================================}
function TDoubleArrayHelper.Pure(const allowed: TDoubleArray): Boolean; var a: TDoubleArray; {$DEFINE Skeleton_Pure}{$I ../Skeletons.inc}{$UNDEF Skeleton_Pure}
{$ENDIF}
