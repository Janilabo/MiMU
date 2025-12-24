{$DEFINE Int64}{$I ../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
TInt64ArrayHelper = type helper for TInt64Array
  {$I TArray.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I TArray.inc}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Int64}
