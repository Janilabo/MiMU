{$DEFINE TVar := string}
{$DEFINE TArr := TStringArray}
{$DEFINE T2DArr := T2DStringArray}
{$DEFINE THelper := T2DStringArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
T2DStringArrayHelper = type helper for T2DStringArray
  {$I Core.inc}
end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I Core.inc}
{$ENDIF}