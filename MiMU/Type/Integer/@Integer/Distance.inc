{$IFDEF HELPERS}
function Dist64(const T: Integer): Int64; overload;
function Distance2(const target: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <Distance2>
  @action: Calculates the absolute distance between two integers using a geometric approach (square root of the squared difference).
  @note: Uses floating-point math routines (Sqr, Sqrt, Round).
         Be aware that values with a difference greater than 46,340 will cause an integer overflow during the squaring phase.
[==============================================================================}
function TIntegerHelper.Distance2(const target: Integer): Integer; overload;
begin
  Result := Round(Sqrt(Sqr(Self - target)));
end;
{$ENDIF}