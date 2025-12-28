{$DEFINE Boolean}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DBooleanArrayHelper = type helper for T2DBooleanArray
  {$I ../T2DArray.inc}
  {$I T2DBooleanArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../T2DArray.inc}
{$I T2DBooleanArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Boolean}
