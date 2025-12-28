{$DEFINE TBox}{$I ../../Type/Defines.inc}{$DEFINE BASE}


{$IFDEF HELPERS}
TBoxArrayHelper = type helper for TBoxArray
  {$I ../TArray.inc}
  {$I TBoxArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../TArray.inc}
{$I TBoxArray.pph}
{$IFNDEF CLASSES}
{$DEFINE FField := X1}{$I ../F.inc}
{$DEFINE FField := Y1}{$I ../F.inc}
{$DEFINE FField := X2}{$I ../F.inc}
{$DEFINE FField := Y2}{$I ../F.inc}
{$ENDIF}
{$ENDIF}

{$UNDEF BASE}{$UNDEF TBox}
