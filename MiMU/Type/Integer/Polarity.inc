{$IFDEF HELPERS}
function Negative: Boolean;
function Neutral: Boolean;
function Positive: Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Negative>
  @action: Returns True if Integer value x is lower than 0 (negative), otherwise False.
  @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Negative: Boolean;
begin
  Result := (Self < 0);
end;

{==============================================================================]
  <Neutral>
  @action: Returns True if Integer value x is 0 (neutral), otherwise False.
  @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Neutral: Boolean;
begin
  Result := (Self = 0);
end;

{==============================================================================]
  <Positive>
  @action: Returns True if Integer value x is higher than 0 (positive), otherwise False.
  @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Positive: Boolean;
begin
  Result := (Self > 0);
end;
{$ENDIF}