{$DEFINE MType := TSegment}
{$DEFINE MArray := TSegmentArray}
{$DEFINE M2DArray := T2DSegmentArray}
{$DEFINE MHelper := TSegmentArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
TSegmentArrayHelper = type helper for TSegmentArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}