{$DEFINE TVar := Double}
{$DEFINE TArr := TDoubleArray}
{$DEFINE T2DArr := T2DDoubleArray}
{$DEFINE THelper := T2DDoubleArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
T2DDoubleArrayHelper = type helper for T2DDoubleArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) or DEFINED(T2D)}
{$I Core.inc}
{$ENDIF}