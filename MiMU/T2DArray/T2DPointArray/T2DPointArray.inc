{$DEFINE TPoint}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DPointArray = class
public
  {$UNDEF TYPES}{$DEFINE METHODS}{$I T2DPointArray.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DPointArrayHelper = type helper for T2DPointArray
  {$I T2DPointArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I T2DPointArray.pph}
{$ENDIF}

{$UNDEF TPoint}
