{$DEFINE MType := TSegment}
{$DEFINE MArray := TSegmentArray}
{$DEFINE M2DArray := T2DSegmentArray}
{$DEFINE MHelper := T2DSegmentArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
T2DSegmentArrayHelper = type helper for T2DSegmentArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}