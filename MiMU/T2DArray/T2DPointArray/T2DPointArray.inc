{$DEFINE TPoint}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
C2DPointArray = class
public 
  {$DEFINE METHODS}{$I T2DPointArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DPointArrayHelper = type helper for T2DPointArray
  {$I ../T2DArray.inc}
  {$I T2DPointArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../T2DArray.inc}
{$I T2DPointArray.pph}
{$ENDIF}

{$DEFINE BASE}{$UNDEF TPoint}
