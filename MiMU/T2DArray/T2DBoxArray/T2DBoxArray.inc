{$DEFINE TBox}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DBoxArray = class
public 
  {$UNDEF TYPES}{$DEFINE METHODS}{$I T2DBoxArray.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DBoxArrayHelper = type helper for T2DBoxArray
  {$I T2DBoxArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I T2DBoxArray.pph}
{$ENDIF}

{$UNDEF TBox}
