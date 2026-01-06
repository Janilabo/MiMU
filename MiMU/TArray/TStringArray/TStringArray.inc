{$DEFINE string}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CStringArray = class
public
  {$UNDEF TYPES}{$DEFINE METHODS}{$I TStringArray.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
{$ENDIF}

{$IFDEF HELPERS}
TStringArrayHelper = type helper for TStringArray
  {$I TStringArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I TStringArray.pph}
{$ENDIF}

{$UNDEF string}
