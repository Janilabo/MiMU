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

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Type.inc}
{$I String.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF string}
