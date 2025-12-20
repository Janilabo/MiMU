{$DEFINE MType := Boolean}
{$DEFINE MArray := TBooleanArray}
{$DEFINE M2DArray := T2DBooleanArray}
{$DEFINE MHelper := T2DBooleanArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
T2DBooleanArrayHelper = type helper for T2DBooleanArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}