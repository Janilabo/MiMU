{$DEFINE TVar := Char}
{$DEFINE TArr := TCharArray}
{$DEFINE T2DArr := T2DCharArray}
{$DEFINE THelper := T2DCharArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
{$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}