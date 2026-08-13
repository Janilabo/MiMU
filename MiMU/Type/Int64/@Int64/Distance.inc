{$IFDEF HELPERS}
function Distance2(const target: Int64): Int64; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Distance2>
  @action: Calculates the absolute distance between two Int64's using a geometric approach (square root of the squared difference).
  @note: Uses floating-point math routines (Sqr, Sqrt, Round).
[==============================================================================}
function TInt64Helper.Distance2(const target: Int64): Int64; overload;
begin
  Result := Round(Sqrt(Sqr(Self - target)));
end;
{$ENDIF}