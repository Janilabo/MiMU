{$DEFINE MType := Double}
{$DEFINE MArray := TDoubleArray}
{$DEFINE M2DArray := T2DDoubleArray}
{$DEFINE MHelper := T2DDoubleArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
{$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}