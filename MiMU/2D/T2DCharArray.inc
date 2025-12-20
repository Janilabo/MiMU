{$DEFINE MType := Char}
{$DEFINE MArray := TCharArray}
{$DEFINE M2DArray := T2DCharArray}
{$DEFINE MHelper := T2DCharArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
{$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}