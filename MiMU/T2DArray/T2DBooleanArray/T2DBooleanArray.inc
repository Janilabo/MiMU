{$DEFINE Boolean}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DBooleanArray = class
public 
  {$UNDEF TYPES}{$DEFINE METHODS}{$I T2DBooleanArray.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DBooleanArrayHelper = type helper for T2DBooleanArray
  {$I T2DBooleanArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I T2DBooleanArray.pph}
{$ENDIF}

{$UNDEF Boolean}
