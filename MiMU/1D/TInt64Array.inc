{$DEFINE MType := Int64}
{$DEFINE MArray := TInt64Array}
{$DEFINE M2DArray := T2DInt64Array}
{$DEFINE MHelper := TInt64ArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
TInt64ArrayHelper = type helper for TInt64Array
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}