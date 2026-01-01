{$DEFINE TSegment}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
C2DSegmentArray = class
public 
  {$DEFINE METHODS}{$I T2DSegmentArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
T2DSegmentArrayHelper = type helper for T2DSegmentArray
  {$I ../Base/Base.inc}
  {$I T2DSegmentArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I T2DSegmentArray.pph}
{$ENDIF}

{$UNDEF TSegment}
