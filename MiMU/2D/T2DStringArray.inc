{$DEFINE TVar := string}
{$DEFINE TArr := TStringArray}
{$DEFINE T2DArr := T2DStringArray}
{$DEFINE THelper := T2DStringArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
{$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}