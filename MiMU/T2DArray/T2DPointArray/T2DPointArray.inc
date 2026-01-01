{$DEFINE TPoint}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DPointArray = class
public 
  {$DEFINE METHODS}{$I T2DPointArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DPointArrayHelper = type helper for T2DPointArray
  {$I ../Base/Base.inc}
  {$I T2DPointArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I T2DPointArray.pph}
{$ENDIF}

{$UNDEF TPoint}
