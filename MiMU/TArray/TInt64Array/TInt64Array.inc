{$DEFINE Int64}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
TInt64ArrayHelper = type helper for TInt64Array
  {$I ../TArray.inc}
  {$I TInt64Array.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../TArray.inc}
{$I TInt64Array.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Int64}
