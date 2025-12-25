{$DEFINE string}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
TStringArrayHelper = type helper for TStringArray
  {$I ../TArray.inc}
  {$I TStringArray.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../TArray.inc}
{$I TStringArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF string}
