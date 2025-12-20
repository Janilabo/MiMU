{$DEFINE MType := Int64}
{$DEFINE MArray := TInt64Array}
{$DEFINE M2DArray := T2DInt64Array}
{$DEFINE MHelper := T2DInt64ArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
T2DInt64ArrayHelper = type helper for T2DInt64Array
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}