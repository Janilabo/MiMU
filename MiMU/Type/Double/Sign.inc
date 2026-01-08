{$IFDEF HELPERS}
function Neg: Double; cdecl; inline;
function Negative: Boolean; cdecl; inline;
function NegA: Double; cdecl; inline;
function Neutral: Boolean; cdecl; inline;
function Opposite: Double; cdecl; inline;
function Positive: Boolean; cdecl; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Neg>
  @action: Returns the negative number of i. 
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TDoubleHelper.Neg: Double; cdecl; inline;
begin
  if (Self > 0) then
    Result := (Self * -1)
  else
    Result := Self;
end; 

{==============================================================================]
  <Negative>
  @action: Returns True if Double value x is lower than 0 (negative), otherwise False. 
  @note: 0 is not negative or positive!
[==============================================================================}
function TDoubleHelper.Negative: Boolean; cdecl; inline;
begin
  Result := (Self < 0);
end;

{==============================================================================]
  <NegA>
  @action: Returns the negative number of x. 
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TDoubleHelper.NegA: Double; cdecl; inline;
begin
  Result := (Abs(Self) * -1);
end;

{==============================================================================]
  <Neutral>
  @action: Returns True if Double value x is 0 (neutral), otherwise False. 
  @note: 0 is not negative or positive!
[==============================================================================}
function TDoubleHelper.Neutral: Boolean; cdecl; inline;
begin
  Result := (Self = 0);
end;

{==============================================================================]
  <Opposite>
  @action: Returns the opposite number of x. 
           -9999 to 9999 OR 9999 to -9999 (- <=> +) 
  @note: None
[==============================================================================}
function TDoubleHelper.Opposite: Double; cdecl; inline;
begin
  Result := (Self * -1);
end;

{==============================================================================]
  <Positive>
  @action: Returns True if Double value x is higher than 0 (positive), otherwise False. 
  @note: 0 is not negative or positive!
[==============================================================================}
function TDoubleHelper.Positive: Boolean; cdecl; inline;
begin
  Result := (Self > 0);
end;
{$ENDIF}