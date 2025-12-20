{$DEFINE MType := TSegment}
{$DEFINE MArray := TSegmentArray}
{$DEFINE M2DArray := T2DSegmentArray}
{$DEFINE MHelper := T2DSegmentArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
{$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}