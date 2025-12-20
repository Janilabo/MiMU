{$DEFINE MType := TRange}
{$DEFINE MArray := TRangeArray}
{$DEFINE M2DArray := T2DRangeArray}
{$DEFINE MHelper := T2DRangeArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
{$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}