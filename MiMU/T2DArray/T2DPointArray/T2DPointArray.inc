{$DEFINE TPoint}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DPointArrayHelper = type helper for T2DPointArray
  {$I ../T2DArray.inc}
  {$I T2DPointArray.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../T2DArray.inc}
{$I T2DPointArray.pph}
{$ENDIF}

{$DEFINE BASE}{$UNDEF TPoint}
