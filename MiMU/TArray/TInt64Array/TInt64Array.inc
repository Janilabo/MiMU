{$DEFINE Int64}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CInt64Array = class
public
  {$UNDEF TYPES}{$DEFINE METHODS}{$I TInt64Array.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
{$ENDIF}

{$IFDEF HELPERS}
TInt64ArrayHelper = type helper for TInt64Array
  {$I TInt64Array.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I TInt64Array.pph}
{$ENDIF}

{$UNDEF Int64}
