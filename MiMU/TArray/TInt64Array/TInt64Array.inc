{$DEFINE Int64}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CInt64Array = class
public
  {$DEFINE METHODS}{$I TInt64Array.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
TInt64ArrayHelper = type helper for TInt64Array
  {$I ../Base/Base.inc}
  {$I TInt64Array.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I TInt64Array.pph}
{$ENDIF}

{$UNDEF Int64}
