{$DEFINE TConnection}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CConnectionArray = class
public
  {$DEFINE METHODS}{$I TConnectionArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
TConnectionArrayHelper = type helper for TConnectionArray
  {$I ../Base/Base.inc}
  {$I TConnectionArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I TConnectionArray.pph}
{$ENDIF}

{$UNDEF TConnection}
