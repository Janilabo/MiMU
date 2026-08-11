{$IFDEF HELPERS}
function AsSign: Integer; overload;
function GetSign: Integer; overload;
function Sign: Integer; overload;
function Signed: Integer; overload;
function Signing: Integer; overload;
function ToSign: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsSign>
  @action: Converts Self to a signed unit value.
  @note: Returns 1 if Self is True, -1 if Self is False. There is no zero case.
[==============================================================================}
function TBooleanHelper.AsSign: Integer; overload;
begin
  if not Self then
    Exit(-1);
  Result := 1;
end;

{==============================================================================]
  <GetSign>
  @action: Converts Self to a signed unit value.
  @note: Returns 1 if Self is True, -1 if Self is False. There is no zero case.
[==============================================================================}
function TBooleanHelper.GetSign: Integer; overload;
begin
  Result := (1 - (2 * Ord(not Self)));
end;

{==============================================================================]
  <Sign>
  @action: Converts Self to a signed unit value.
  @note: Returns 1 if Self is True, -1 if Self is False. There is no zero case.
[==============================================================================}
function TBooleanHelper.Sign: Integer; overload;
begin
  if Self then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
  <Signed>
  @action: Returns a signed integer representation of the Boolean value (1 for True, -1 for False).
  @note: Uses conditional evaluation (IfThen) to map True to 1 and False to -1.
[==============================================================================}
function TBooleanHelper.Signed: Integer; overload;
begin
  Result := Self.IfThen(1, -1);
end;

{==============================================================================]
  <Signing>
  @action: Maps a Boolean value to a signed integer (-1 for False, 1 for True).
  @note: Uses a constant lookup array indexed by the Boolean value to avoid conditional branching and arithmetic calculations at runtime.
[==============================================================================}
function TBooleanHelper.Signing: Integer; overload;
const
  SIGNS: array[Boolean] of Integer = (-1, 1);
begin
  Result := SIGNS[Self];
end;

{==============================================================================]
  <ToSign>
  @action: Converts a Boolean value into a numeric sign (-1 for False, 1 for True).
  @note: Uses boolean ordinal values (Ord(False) = 0, Ord(True) = 1) to map False to -1 and True to 1 without conditional branching.
[==============================================================================}
function TBooleanHelper.ToSign: Integer; overload;
begin
  Result := ((Ord(Self) * 2) - 1);
end;
{$ENDIF}
