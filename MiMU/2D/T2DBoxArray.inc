{$DEFINE TVar := TBox}
{$DEFINE TArr := TBoxArray}
{$DEFINE T2DArr := T2DBoxArray}
{$DEFINE THelper := T2DBoxArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
T2DBoxArrayHelper = type helper for T2DBoxArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}