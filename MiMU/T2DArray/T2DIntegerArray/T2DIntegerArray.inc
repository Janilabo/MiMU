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

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../T2DArray.inc}
{$I T2DIntegerArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Integer}
