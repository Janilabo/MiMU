{$DEFINE string}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
TStringArrayHelper = type helper for TStringArray
  {$I ../TArray.inc}
  {$I TStringArray.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../TArray.inc}
{$I TStringArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF string}
