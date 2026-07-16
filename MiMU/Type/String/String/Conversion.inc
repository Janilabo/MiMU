{$IFDEF HELPERS}
function ToFloat(const fallback: Double = 0.0): Double; overload;
function ToInt(const fallback: Integer = 0): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <ToFloat>
  @action: Converts the string to a double-precision floating-point number, 
           returning a fallback value if the string is invalid.
  @note: Uses TryStrToFloat under the hood to safely handle parsing without 
         raising exceptions. Defaults to 0.0 if fallback is omitted.
[==============================================================================}
function TStringHelper.ToFloat(const fallback: Double = 0.0): Double; overload;
begin
  if not SysUtils.TryStrToFloat(Self, Result) then
    Result := fallback;
end;

{==============================================================================]
  <ToInt>
  @action: Converts the string to an integer, returning a fallback value if 
           the string is not a valid number.
  @note: Uses TryStrToInt under the hood to ensure it never throws an exception. 
         Defaults to 0 if fallback is omitted.
[==============================================================================}
function TStringHelper.ToInt(const fallback: Integer = 0): Integer; overload;
begin
  if not SysUtils.TryStrToInt(Self, Result) then
    Result := fallback;
end;
{$ENDIF}
