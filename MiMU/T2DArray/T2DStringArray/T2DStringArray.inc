{$DEFINE string}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DStringArray = class
public
  {$UNDEF TYPES}{$DEFINE METHODS}{$I T2DStringArray.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DStringArrayHelper = type helper for T2DStringArray
  {$I T2DStringArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I T2DStringArray.pph}
{$ENDIF}

{$UNDEF string}
