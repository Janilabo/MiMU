{$DEFINE TBox}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CBoxArray = class
public
  {$DEFINE METHODS}{$I TBoxArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
TBoxArrayHelper = type helper for TBoxArray
  {$I TBoxArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I TBoxArray.pph}
{$IFNDEF CLASSES}
{$DEFINE FField := X1}{$I ../F.inc}
{$DEFINE FField := Y1}{$I ../F.inc}
{$DEFINE FField := X2}{$I ../F.inc}
{$DEFINE FField := Y2}{$I ../F.inc}
{$ENDIF}
{$ENDIF}

{$UNDEF TBox}
