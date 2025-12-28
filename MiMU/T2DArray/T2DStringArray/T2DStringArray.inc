{$DEFINE string}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF HELPERS}
T2DStringArrayHelper = type helper for T2DStringArray
  {$I ../T2DArray.inc}
  {$I T2DStringArray.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../T2DArray.inc}
{$I T2DStringArray.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF string}
