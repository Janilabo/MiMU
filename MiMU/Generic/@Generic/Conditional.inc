{$IFDEF FUNCTIONS}
generic function IfThenElse<T>(const aBool, bBool: Boolean; const aResult, bResult, cResult: T): T; overload;
generic function Iff<T>(bState: Boolean; const bTrue, bFalse: T): T; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IfThenElse>
  @action: Returns one of three possible results depending on two Boolean conditions.
  @note: Evaluates aBool first, then bBool, returning aResult, bResult, or cResult accordingly.
[==============================================================================}
generic function IfThenElse<T>(const aBool, bBool: Boolean; const aResult, bResult, cResult: T): T; overload;
begin
  if aBool then
    Result := aResult
  else if bBool then
    Result := bResult
  else
    Result := cResult;
end;

generic function Iff<T>(bState: Boolean; const bTrue, bFalse: T): T; overload;
begin
  if bState then
    Result := bTrue
  else
    Result := bFalse;
end;
{$ENDIF}