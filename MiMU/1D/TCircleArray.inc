{$DEFINE MType := TCircle}
{$DEFINE MArray := TCircleArray}
{$DEFINE M2DArray := T2DCircleArray}
{$DEFINE MHelper := TCircleArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
TCircleArrayHelper = type helper for TCircleArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}