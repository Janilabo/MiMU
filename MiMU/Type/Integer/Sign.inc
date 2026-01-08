{$IFDEF HELPERS}
function Neg: Integer; cdecl; inline;
function Negative: Boolean; cdecl; inline;
function NegA: Integer; cdecl; inline;
function Neutral: Boolean; cdecl; inline;
function Opposite: Integer; cdecl; inline;
function Positive: Boolean; cdecl; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Neg>
  @action: Returns the negative number of x.
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TIntegerHelper.Neg: Integer; cdecl; inline;
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
function TIntegerHelper.Negative: Boolean; cdecl; inline;
begin
  Result := (Self < 0);
end;

{==============================================================================]
  <NegA>
  @action: Returns the negative number of x.
           -9999 to -9999 OR 9999 to -9999 (+/- => -)
  @note: None
[==============================================================================}
function TIntegerHelper.NegA: Integer; cdecl; inline;
begin
  Result := (Abs(Self) * -1);
end;

{==============================================================================]
  <Neutral>
  @action: Returns True if Integer value x is 0 (neutral), otherwise False.
  @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Neutral: Boolean; cdecl; inline;
begin
  Result := (Self = 0);
end;

{==============================================================================]
  <Opposite>
  @action: Returns the opposite number of x.
           -9999 to 9999 OR 9999 to -9999 (- <=> +)
  @note: None
[==============================================================================}
function TIntegerHelper.Opposite: Integer; cdecl; inline;
begin
  Result := (Self * -1);
end;

{==============================================================================]
  <Positive>
  @action: Returns True if Integer value x is higher than 0 (positive), otherwise False.
  @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Positive: Boolean; cdecl; inline;
begin
  Result := (Self > 0);
end;
{$ENDIF}