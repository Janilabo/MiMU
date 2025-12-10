{$DEFINE TVar := Int64}
{$DEFINE TArr := TInt64Array}
{$DEFINE T2DArr := T2DInt64Array}
{$DEFINE THelper := T2DInt64ArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
T2DInt64ArrayHelper = type helper for T2DInt64Array
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(T2D)}
{$I Core.inc}
{$ENDIF}