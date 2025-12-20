{$DEFINE MType := TConnection}
{$DEFINE MArray := TConnectionArray}
{$DEFINE M2DArray := T2DConnectionArray}
{$DEFINE MHelper := TConnectionArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
TConnectionArrayHelper = type helper for TConnectionArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}