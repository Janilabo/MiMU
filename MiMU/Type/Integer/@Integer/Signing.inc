{$IFDEF HELPERS}
function Signage(const origin: Integer = 0): Integer; overload;
function Signature(const origin: Integer = 0): string; overload;
function Signed(const origin: Integer = 0): Integer; overload;
function Signify(const origin: Integer = 0): Integer; overload;
function Signing(const origin: Integer = 0): Integer; overload;
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
  <Signature>
  @action: Returns '+', '-', or '' based on the sign of the integer relative 
           to a baseline origin value.
  @note: Useful for trend tracking, layout prefixing, or relative log formatting. 
         Compares the integer against the origin parameter (defaulting to 0); 
         returns an empty string ('') if the integer exactly matches the origin.
[==============================================================================}
function TIntegerHelper.Signature(const origin: Integer = 0): string; overload;
begin
  if (Self > origin) then
    Result := '+'
  else if (Self < origin) then
    Result := '-'
  else
    Result := '';
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
  @action: Non-mutating, three-way comparator relative to an origin.
  @note: Returns -1 if Self < origin, 1 if Self > origin, or 0 if Self = origin.
[==============================================================================}
function TIntegerHelper.Signing(const origin: Integer = 0): Integer; overload;
begin
  if (Self < origin) then
    Result := -1
  else if (Self > origin) then
    Result := 1
  else
    Result := 0;
end;

{==============================================================================]
  <SignOf>
  @action: Determines the sign of the current instance relative to an origin reference point.
  @note: Returns 1 if Self > origin, -1 if Self < origin, or 0 if Self equals origin.
[==============================================================================}
function TIntegerHelper.SignOf(const origin: Integer = 0): Integer; overload;
begin
  Result := (Ord(Self > origin) - Ord(Self < origin));
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