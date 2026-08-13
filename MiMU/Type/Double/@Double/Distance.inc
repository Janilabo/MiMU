{$IFDEF HELPERS}
function Distance2(const target: Double): Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Distance2>
  @action: Calculates the absolute distance between two values using a geometric approach (square root of the squared difference).
  @note: Uses floating-point math routines (Sqr, Sqrt).
         Unlike the Integer function, no overflow concern here — Double's
         range comfortably covers the squared difference for any realistic
         magnitude, though extreme values near Double's upper range could
         still theoretically overflow during squaring.
[==============================================================================}
function TDoubleHelper.Distance2(const target: Double): Double; overload;
begin
  Result := Sqrt(Sqr(Self - target));
end;
{$ENDIF}