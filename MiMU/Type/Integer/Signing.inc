{$IFDEF HELPERS}
function Signage(const origin: Integer = 0): Integer; overload;
function Signed(const origin: Integer = 0): Integer; overload;
function Signify(const origin: Integer = 0): Integer; overload;
function Signing(const origin: Integer): Integer; overload;
function SignOf(const origin: Integer = 0): Integer; overload;
function Signum(const origin: Integer = 0): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Signage>
  @action: Returns the mathematical sign (-1, 0, or 1) of the difference between the integer and a given origin.
  @note: Overloaded function. Uses Math.IfThen for conditional assignment and defaults to a baseline of 0.
[==============================================================================}
function TIntegerHelper.Signage(const origin: Integer = 0): Integer; overload;
begin
  Result := (Self - origin);
  if (Result <> 0) then
    Result := IfThen((Result < 0), -1, 1);
end;

{==============================================================================]
  <Signed>
  @action: Returns the sign (-1, 0, or 1) of the integer relative to a given origin using early exit statements.
  @note: Overloaded function. Defaults to comparing against 0. Uses immediate Exit calls for positive and negative checks.
[==============================================================================}
function TIntegerHelper.Signed(const origin: Integer = 0): Integer; overload;
begin
  if (Self > origin) then
    Exit(1)
  else if (Self < origin) then
    Exit(-1);
  Result := 0;
end;

{==============================================================================]
  <Signify>
  @action: Returns the sign of the integer (-1, 0, or 1) relative to a given origin.
  @note: Overloaded function. Defaults to comparing against 0 if no origin is provided.
[==============================================================================}
function TIntegerHelper.Signify(const origin: Integer = 0): Integer; overload;
begin
  Result := (Integer(Self > origin) - Integer(Self < origin));
end;

{==============================================================================]
  <Signing>
  @action: Determines the mathematical sign of a given integer, returning 
           -1 for negative numbers, 1 for positive numbers, and 0 for zero.
  @note: Implemented using standard conditional branching (if-then-else). 
         While highly readable, it introduces CPU branch evaluation points.
[==============================================================================}
function TIntegerHelper.Signing(const origin: Integer): Integer; overload;
begin
  if (origin < 0) then
    Result := -1
  else if (origin > 0) then
    Result := 1
  else
    Result := 0;
end;

{==============================================================================]
  <SignOf>
  @action: Returns the mathematical sign of an integer (-1 for negative, 
           0 for zero, and 1 for positive).
  @note: Implemented using a branchless bitwise/logical trick via Ord() 
         to optimize performance by avoiding CPU branch mispredictions.
[==============================================================================}
function TIntegerHelper.SignOf(const origin: Integer = 0): Integer; overload;
begin
  Result := (Ord(origin > 0) - Ord(origin < 0));
end;

{==============================================================================]
  <Signum>
  @action: Returns the sign of the integer (-1, 0, or 1) relative to a given origin.
  @note: Overloaded function. Defaults to comparing against 0 if no origin is provided.
[==============================================================================}
function TIntegerHelper.Signum(const origin: Integer = 0): Integer; overload;
begin
  if (Self = origin) then
    Result := 0
  else if (Self < origin) then
    Result := -1
  else
    Result := 1;
end;
{$ENDIF}