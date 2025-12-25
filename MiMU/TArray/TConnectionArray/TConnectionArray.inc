{$DEFINE TConnection}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
TConnectionArrayHelper = type helper for TConnectionArray
  {$I ../TArray.inc}
  {$I TConnectionArray.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../TArray.inc}
{$I TConnectionArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TConnection}
