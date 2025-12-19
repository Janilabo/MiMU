{$DEFINE TVar := TRange}
{$DEFINE TArr := TRangeArray}
{$DEFINE T2DArr := T2DRangeArray}
{$DEFINE THelper := T2DRangeArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
{$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}