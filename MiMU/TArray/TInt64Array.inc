{$DEFINE Int64}{$I ..\Type\Configuration\Defines.inc}

{$IFDEF HELPERS}
TInt64ArrayHelper = type helper for TInt64Array
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}

{$UNDEF Int64}