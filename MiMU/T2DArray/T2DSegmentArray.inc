{$DEFINE TSegment}{$I ..\Type\Configuration\Defines.inc}

{$IFDEF HELPERS}
T2DSegmentArrayHelper = type helper for T2DSegmentArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}

{$UNDEF TSegment}