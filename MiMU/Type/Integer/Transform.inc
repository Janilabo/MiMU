{$IFDEF HELPERS}
function Neg: Integer;
function NegA: Integer;
function Opposite: Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Neg>
  @action: Returns the negative number of x.
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TIntegerHelper.Neg: Integer;
begin
  if (Self > -1) then
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
function TIntegerHelper.NegA: Integer;
begin
  Result := (Abs(Self) * -1);
end;

{==============================================================================]
  <Opposite>
  @action: Returns the opposite number of x.
           -9999 to 9999 OR 9999 to -9999 (- <=> +)
  @note: None
[==============================================================================}
function TIntegerHelper.Opposite: Integer;
begin
  Result := (Self * -1);
end;
{$ENDIF}