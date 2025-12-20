{$DEFINE MType := TTriangle}
{$DEFINE MArray := TTriangleArray}
{$DEFINE M2DArray := T2DTriangleArray}
{$DEFINE MHelper := T2DTriangleArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
T2DTriangleArrayHelper = type helper for T2DTriangleArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}