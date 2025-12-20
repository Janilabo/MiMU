{$DEFINE MType := TCircle}
{$DEFINE MArray := TCircleArray}
{$DEFINE M2DArray := T2DCircleArray}
{$DEFINE MHelper := T2DCircleArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
T2DCircleArrayHelper = type helper for T2DCircleArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}