{$IFDEF HELPERS}
function SafeDiv(const aDenominator: Double; const fallback: Double = 0.0): Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <SafeDiv>
  @action: Divides the current value by a denominator, returning a fallback
           value if the denominator is zero.
  @note: Prevents division-by-zero runtime errors. Defaults to 0.0 as the
         fallback if not specified.
[==============================================================================}
function TDoubleHelper.SafeDiv(const aDenominator: Double; const fallback: Double = 0.0): Double; overload;
begin
  if (aDenominator = 0.0) then
    Exit(fallback);
  Result := (Self / aDenominator);
end; 
{$ENDIF}