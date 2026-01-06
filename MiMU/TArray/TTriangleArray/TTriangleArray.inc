{$DEFINE TTriangle}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CTriangleArray = class
public
  {$UNDEF TYPES}{$DEFINE METHODS}{$I TTriangleArray.pph}{$UNDEF METHODS}{$DEFINE TYPES}
end;
{$ENDIF}

{$IFDEF HELPERS}
TTriangleArrayHelper = type helper for TTriangleArray
  {$I TTriangleArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I TTriangleArray.pph}
{$ENDIF}

{$UNDEF TTriangle}
