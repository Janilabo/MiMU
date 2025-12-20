{$DEFINE MType := string}
{$DEFINE MArray := TStringArray}
{$DEFINE M2DArray := T2DStringArray}
{$DEFINE MHelper := T2DStringArrayHelper}
{$DEFINE Sortable}

{$IFDEF HELPERS}
T2DStringArrayHelper = type helper for T2DStringArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}