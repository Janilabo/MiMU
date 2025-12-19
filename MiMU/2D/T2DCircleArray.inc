{$DEFINE TVar := TCircle}
{$DEFINE TArr := TCircleArray}
{$DEFINE T2DArr := T2DCircleArray}
{$DEFINE THelper := T2DCircleArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
{$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}