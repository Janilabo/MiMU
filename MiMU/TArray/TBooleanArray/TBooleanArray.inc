{$DEFINE Boolean}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
CBooleanArray = class
public
  {$DEFINE METHODS}{$I TBooleanArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
TBooleanArrayHelper = type helper for TBooleanArray
  {$I ../TArray.inc}
  {$I TBooleanArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../TArray.inc}
{$I TBooleanArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Boolean}
