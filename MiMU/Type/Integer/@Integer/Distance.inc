{$IFDEF HELPERS}
function Distance2(const target: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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