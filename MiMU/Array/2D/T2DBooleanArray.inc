{$DEFINE TVar := Boolean}
{$DEFINE TArr := TBooleanArray}
{$DEFINE T2DArr := T2DBooleanArray}
{$DEFINE THelper := T2DBooleanArrayHelper}
{$UNDEF Sortable}

{$IFDEF HELPERS}
T2DBooleanArrayHelper = type helper for T2DBooleanArray
  {$I Core.inc}
end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I Core.inc}
{$ENDIF}