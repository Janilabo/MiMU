{$DEFINE Integer}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
C2DIntegerArray = class
public 
  {$DEFINE METHODS}{$I T2DIntegerArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DIntegerArrayHelper = type helper for T2DIntegerArray
  {$I ../T2DArray.inc}
  {$I T2DIntegerArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../T2DArray.inc}
{$I T2DIntegerArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Integer}
