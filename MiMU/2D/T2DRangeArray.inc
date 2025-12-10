{$DEFINE TVar := TRange}
{$DEFINE TArr := TRangeArray}
{$DEFINE T2DArr := T2DRangeArray}
{$DEFINE THelper := T2DRangeArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
T2DRangeArrayHelper = type helper for T2DRangeArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(T2D)}
{$I Core.inc}
{$ENDIF}