{$DEFINE TBox}{$I ../Type/Defines.inc}

{$IFDEF HELPERS}
T2DBoxArrayHelper = type helper for T2DBoxArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF TBox}
