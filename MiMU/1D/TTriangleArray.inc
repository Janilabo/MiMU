{$DEFINE TVar := TTriangle}
{$DEFINE TArr := TTriangleArray}
{$DEFINE T2DArr := T2DTriangleArray}
{$DEFINE THelper := TTriangleArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
{$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}