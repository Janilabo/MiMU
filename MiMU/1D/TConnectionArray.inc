{$DEFINE TVar := TConnection}
{$DEFINE TArr := TConnectionArray}
{$DEFINE T2DArr := T2DConnectionArray}
{$DEFINE THelper := TConnectionArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
{$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}