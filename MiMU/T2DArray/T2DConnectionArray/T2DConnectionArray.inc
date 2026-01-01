{$DEFINE TConnection}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DConnectionArray = class
public 
  {$DEFINE METHODS}{$I T2DConnectionArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DConnectionArrayHelper = type helper for T2DConnectionArray
  {$I ../Base/Base.inc}
  {$I T2DConnectionArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I T2DConnectionArray.pph}
{$ENDIF}

{$UNDEF TConnection}
