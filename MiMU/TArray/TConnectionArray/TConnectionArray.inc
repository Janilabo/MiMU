{$DEFINE TConnection}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CConnectionArray = class
public
  {$UNDEF TYPES}{$DEFINE METHODS}{$I TConnectionArray.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
{$ENDIF}

{$IFDEF HELPERS}
TConnectionArrayHelper = type helper for TConnectionArray
  {$I TConnectionArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I TConnectionArray.pph}
{$ENDIF}

{$UNDEF TConnection}
