{$DEFINE TBox}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DBoxArrayHelper = type helper for T2DBoxArray
  {$I ../T2DArray.inc}
  {$I T2DBoxArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../T2DArray.inc}
{$I T2DBoxArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TBox}
