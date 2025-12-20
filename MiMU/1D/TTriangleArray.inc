{$DEFINE MType := TTriangle}
{$DEFINE MArray := TTriangleArray}
{$DEFINE M2DArray := T2DTriangleArray}
{$DEFINE MHelper := TTriangleArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
{$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}