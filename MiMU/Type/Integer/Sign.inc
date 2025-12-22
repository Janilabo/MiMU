{$IFDEF HELPERS}
function NegA: Integer; inline;
function Neg: Integer; inline;
function Negative: Boolean; inline;
function Positive: Boolean; inline;
function Neutral: Boolean; inline;
function Opposite: Integer; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <NegA>
  @action: Returns the negative number of x.
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TIntegerHelper.NegA: Integer; inline;
begin
  Result := (Abs(Self) * -1);
end;

{==============================================================================]
  <Neg>
  @action: Returns the negative number of x.
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TIntegerHelper.Neg: Integer; inline;
begin
  if (Self > -1) then
    Result := (Self * -1)
  else
    Result := Self;
end;

{==============================================================================]
  <Negative>
  @action: Returns True if Integer value x is lower than 0 (negative), otherwise False.
  @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Negative: Boolean; inline;
begin
  Result := (Self < 0);
end;

{==============================================================================]
  <Positive>
  @action: Returns True if Integer value x is higher than 0 (positive), otherwise False.
  @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Positive: Boolean; inline;
begin
  Result := (Self > 0);
end;

{==============================================================================]
  <Neutral>
  @action: Returns True if Integer value x is 0 (neutral), otherwise False.
  @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Neutral: Boolean; inline;
begin
  Result := (Self = 0);
end;

{==============================================================================]
  <Opposite>
  @action: Returns the opposite number of x.
           -9999 to 9999 OR 9999 to -9999 (- <=> +)
  @note: None
[==============================================================================}
function TIntegerHelper.Opposite: Integer; inline;
begin
  Result := (Self * -1);
end;
{$ENDIF}