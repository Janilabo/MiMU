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

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(T2D)}
{$I Core.inc}
{$ENDIF}