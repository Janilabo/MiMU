{$DEFINE TBox}{$I ../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DBoxArrayHelper = type helper for T2DBoxArray
  {$I T2DArray.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I T2DArray.inc}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TBox}
