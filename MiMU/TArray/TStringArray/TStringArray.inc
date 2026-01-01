{$DEFINE string}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CStringArray = class
public
  {$DEFINE METHODS}{$I TStringArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
TStringArrayHelper = type helper for TStringArray
  {$I ../Base/Base.inc}
  {$I TStringArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I TStringArray.pph}
{$ENDIF}

{$UNDEF string}
