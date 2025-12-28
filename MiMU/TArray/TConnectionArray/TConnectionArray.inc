{$DEFINE TConnection}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
TConnectionArrayHelper = type helper for TConnectionArray
  {$I ../TArray.inc}
  {$I TConnectionArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../TArray.inc}
{$I TConnectionArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TConnection}
