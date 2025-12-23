{$DEFINE string}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
{$I ../Type.inc}
{$ENDIF}

{$IFDEF HELPERS}
TStringHelper = type helper for string
  {$I ../Type.inc}
  {$I String.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS)}
{$I ../Type.inc}
{$I String.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF string}
