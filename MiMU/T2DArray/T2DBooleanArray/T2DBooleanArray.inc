{$DEFINE Boolean}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DBooleanArray = class
public 
  {$DEFINE METHODS}{$I T2DBooleanArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DBooleanArrayHelper = type helper for T2DBooleanArray
  {$I ../Base/Base.inc}
  {$I T2DBooleanArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I T2DBooleanArray.pph}
{$ENDIF}

{$UNDEF Boolean}
