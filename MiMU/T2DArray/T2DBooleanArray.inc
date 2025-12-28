{$DEFINE Boolean}{$I ../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DBooleanArrayHelper = type helper for T2DBooleanArray
  {$I T2DArray.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I T2DArray.inc}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Boolean}
