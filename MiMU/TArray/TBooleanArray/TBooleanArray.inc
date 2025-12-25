{$DEFINE Boolean}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
TBA = class
  {$DEFINE METHODS}{$I TBooleanArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
TBooleanArrayHelper = type helper for TBooleanArray
  {$I ../TArray.inc}
  {$I TBooleanArray.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../TArray.inc}
{$I TBooleanArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Boolean}
