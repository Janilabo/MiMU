{$IFDEF HELPERS}
function Negative: Boolean; overload;
function Neutral: Boolean; overload;
function Nonzero: Boolean; overload;
function Positive: Boolean; overload;
function Zero: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Negative>
  @action: Returns True if Integer value x is lower than 0 (negative), otherwise False.
  @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Negative: Boolean; overload;
begin
  Result := (Self < 0);
end;

{==============================================================================]
  <Neutral>
  @action: Returns True if Integer value x is 0 (neutral), otherwise False.
  @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Neutral: Boolean; overload;
begin
  Result := (Self = 0);
end;

{==============================================================================]
  <Nonzero>
  @action: Checks if the integer value is any value other than zero.
  @note: Returns True if Self does not equal 0 (covers both positive and negative integers).
[==============================================================================}
function TIntegerHelper.Nonzero: Boolean; overload;
begin
  Result := (Self <> 0);
end;

{==============================================================================]
  <Positive>
  @action: Returns True if Integer value x is higher than 0 (positive), otherwise False.
  @note: 0 is not negative or positive!
[==============================================================================}
function TIntegerHelper.Positive: Boolean; overload;
begin
  Result := (Self > 0);
end;

{==============================================================================]
  <Zero>
  @action: Checks if the integer value is exactly zero.
  @note: Returns True if Self equals 0; otherwise returns False.
[==============================================================================}
function TIntegerHelper.Zero: Boolean; overload;
begin
  Result := (Self = 0);
end;
{$ENDIF}