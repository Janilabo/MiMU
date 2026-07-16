{$IFDEF HELPERS}
function Difference(const T: Integer): Integer; overload;
function Dist2(const T: Integer): Integer; overload;
function Dist64(const T: Integer): Int64; overload;
function Distance(const T: Integer): Integer; overload;
function Distance2(const T: Integer): Integer; overload;
function DistanceTo(const T: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Difference>
  @action: Returns the difference from x to T.
  @note: None
[==============================================================================}
function TIntegerHelper.Difference(const T: Integer): Integer; overload;
begin
  Result := (T - Self);
end;

{==============================================================================]
  <Dist2>
  @action: Calculates the absolute distance between the current integer and another integer by subtracting the smaller value from the larger value.
  @note: Uses a branch-based comparison method (Max/Min) to guarantee a non-negative result without relying on the Abs() function.
[==============================================================================}
function TIntegerHelper.Dist2(const T: Integer): Integer; overload;
begin
  Result := (Max(Self, T) - Min(Self, T));
end;

{==============================================================================]
  <Dist64>
  @action: Calculates the absolute distance between the current integer and another integer.
  @note: Casts operands to Int64 before subtraction to safely prevent 32-bit integer overflow.
[==============================================================================}
function TIntegerHelper.Dist64(const T: Integer): Int64; overload;
begin
  Result := Abs(Int64(Self) - Int64(T));
end;

{==============================================================================]
  <Distance>
  @action: Returns the distance between x and T.
  @note: None
[==============================================================================}
function TIntegerHelper.Distance(const T: Integer): Integer; overload;
begin
  Result := Abs(T - Self);
end;

{==============================================================================]
  <Distance2>
  @action: Calculates the absolute distance between two integers using a geometric approach (square root of the squared difference).
  @note: Uses floating-point math routines (Sqr, Sqrt, Round).
         Be aware that values with a difference greater than 46,340 will cause an integer overflow during the squaring phase.
[==============================================================================}
function TIntegerHelper.Distance2(const T: Integer): Integer; overload;
begin
  Result := Round(Sqrt(Sqr(Self - T)));
end;

{==============================================================================]
  <DistanceTo>
  @action: Calculates the absolute distance between the current integer and another integer using conditional branching.
  @note: Uses a manual greater-than check to subtract the smaller value from the larger value, avoiding external function calls.
[==============================================================================}
function TIntegerHelper.DistanceTo(const T: Integer): Integer; overload;
begin
  if (Self > T) then
    Result := (Self - T)
  else
    Result := (T - Self);
end;
{$ENDIF}