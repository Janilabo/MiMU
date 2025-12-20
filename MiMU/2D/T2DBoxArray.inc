{$DEFINE MType := TBox}
{$DEFINE MArray := TBoxArray}
{$DEFINE M2DArray := T2DBoxArray}
{$DEFINE MHelper := T2DBoxArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
{$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}