{$DEFINE TVar := Double}
{$DEFINE TArr := TDoubleArray}
{$DEFINE T2DArr := T2DDoubleArray}
{$DEFINE THelper := T2DDoubleArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
{$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}