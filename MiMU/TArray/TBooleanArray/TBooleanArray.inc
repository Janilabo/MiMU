{$DEFINE Boolean}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CBooleanArray = class
public
  {$DEFINE METHODS}{$I TBooleanArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
TBooleanArrayHelper = type helper for TBooleanArray
  {$I TBooleanArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I TBooleanArray.pph}
{$ENDIF}

{$UNDEF Boolean}
