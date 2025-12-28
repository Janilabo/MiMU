{$DEFINE TConnection}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DConnectionArrayHelper = type helper for T2DConnectionArray
  {$I ../T2DArray.inc}
  {$I T2DConnectionArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../T2DArray.inc}
{$I T2DConnectionArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TConnection}
