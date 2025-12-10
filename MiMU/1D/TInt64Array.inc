{$DEFINE TVar := Int64}
{$DEFINE TArr := TInt64Array}
{$DEFINE T2DArr := T2DInt64Array}
{$DEFINE THelper := TInt64ArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
TInt64ArrayHelper = type helper for TInt64Array
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(T1D)}
{$I Core.inc}
{$ENDIF}