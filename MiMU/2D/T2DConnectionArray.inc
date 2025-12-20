{$DEFINE MType := TConnection}
{$DEFINE MArray := TConnectionArray}
{$DEFINE M2DArray := T2DConnectionArray}
{$DEFINE MHelper := T2DConnectionArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
T2DConnectionArrayHelper = type helper for T2DConnectionArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}