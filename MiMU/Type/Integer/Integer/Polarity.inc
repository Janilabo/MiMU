{$IFDEF HELPERS}
function IsZero: Boolean; overload;
function Negative: Boolean; overload;
function Neutral: Boolean; overload;
function Nonzero: Boolean; overload;
function NotZero: Boolean; overload;
function Positive: Boolean; overload;
function Zero: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IsZero>
  @action: Determines whether the current integer is exactly zero.
  @note: Uses explicit less-than and greater-than guard clauses to eliminate non-zero values before returning True.
[==============================================================================}
function TIntegerHelper.IsZero: Boolean; overload;
begin
  if (Self < 0) then
    Exit(False)
  else if (Self > 0) then
    Exit(False);
  Result := True;
end;

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
  @action: Determines whether the current integer is mathematically neutral (neither positive nor negative).
  @note: Uses boolean negation (`not`) on the combined boundaries of positive and negative states to isolate zero.
[==============================================================================}
function TIntegerHelper.Neutral: Boolean; overload;
begin
  Result := not ((Self < 0) or (Self > 0));
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
  <NotZero>
  @action: Determines whether the current integer is any value other than zero.
  @note: Uses explicit greater-than and less-than guard clauses to immediately evaluate non-zero integers before returning False.
[==============================================================================}
function TIntegerHelper.NotZero: Boolean; overload;
begin
  if (Self > 0) then
    Exit(True)
  else if (Self < 0) then
    Exit(True);
  Result := False;
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