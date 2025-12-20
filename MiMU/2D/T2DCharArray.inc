{$DEFINE MType := Char}
{$DEFINE MArray := TCharArray}
{$DEFINE M2DArray := T2DCharArray}
{$DEFINE MHelper := T2DCharArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
T2DCharArrayHelper = type helper for T2DCharArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}