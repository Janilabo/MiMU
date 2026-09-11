{$IFDEF HELPERS}
function Disquared: Int64; overload;
function IsPowerOf2: Boolean; overload;
function IsPowOf2: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <?>
  @action: Returns floor(sqrt(Self)) using binary search over [0, Self],
           testing candidates via `M <= Self div M` rather than `M * M <= Self`
           to avoid overflow for the full Int64 range.
  @note: Self <= 0 returns 0 (loop body never runs since Result(0) < S is
         false). M is guaranteed >= 1 whenever the loop body executes, so the
         `Self div M` division is always safe.
[==============================================================================}
function TInt64Helper.Disquared: Int64; overload;
var
  S, M: Int64;
begin
  Result := 0;
  S := Self;
  while (Result < S) do
  begin
    M := (Result + ((S - Result) + 1) div 2);
    if (M <= (Self div M)) then
      Result := M
    else
      S := (M - 1);
  end;
end;

{==============================================================================]
  <IsPowerOf2>
  @action: Returns True if the integer is a positive power of 2 (e.g., 1, 2, 4, 8, 16...), and False otherwise.
  @note: Uses an efficient bitwise trick `(Self and (Self - 1)) = 0` which executes in O(1) time without loops or floating-point math.
[==============================================================================}
function TInt64Helper.IsPowerOf2: Boolean; overload;
begin
  Result := ((Self > 0) and ((Self and (Self - 1)) = 0));
end;

{==============================================================================]
  <IsPowOf2>
  @action: Returns True if the 64-bit integer matches a precomputed value in the POWERS_OF_TWO array (covering 2^0 to 2^62).
  @note: Uses a linear search across 63 elements. It is 100% safe from the 64-bit floating-point precision drops that plague Log2, but it scales linearly in execution time.
[==============================================================================}
function TInt64Helper.IsPowOf2: Boolean; overload;
var
  i: Integer;
begin
  if (Self > 0) then
  for i := 0 to 62 do
    if (Self = POWERS_OF_TWO[i]) then
      Exit(True);
  Result := False;
end;
{$ENDIF}
