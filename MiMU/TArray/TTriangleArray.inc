{$DEFINE TTriangle}{$I ../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
TTriangleArrayHelper = type helper for TTriangleArray
  {$I TArray.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I TArray.inc}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TTriangle}
