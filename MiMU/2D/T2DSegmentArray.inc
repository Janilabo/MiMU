{$DEFINE TVar := TSegment}
{$DEFINE TArr := TSegmentArray}
{$DEFINE T2DArr := T2DSegmentArray}
{$DEFINE THelper := T2DSegmentArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
{$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}