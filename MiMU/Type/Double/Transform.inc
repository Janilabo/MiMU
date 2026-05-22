{$IFDEF HELPERS}
function Neg: Double;
function NegA: Double;
function Opposite: Double;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Neg>
  @action: Returns the negative number of i.
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TDoubleHelper.Neg: Double;
begin
  if (Self > 0) then
    Result := (Self * -1)
  else
    Result := Self;
end;

{==============================================================================]
  <NegA>
  @action: Returns the negative number of x.
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TDoubleHelper.NegA: Double;
begin
  Result := (Abs(Self) * -1);
end;

{==============================================================================]
  <Opposite>
  @action: Returns the opposite number of x.
           -9999 to 9999 OR 9999 to -9999 (- <=> +)
  @note: None
[==============================================================================}
function TDoubleHelper.Opposite: Double;
begin
  Result := (Self * -1);
end;
{$ENDIF}