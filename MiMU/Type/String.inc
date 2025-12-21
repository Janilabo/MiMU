{$DEFINE string}{$I ./Configuration/Defines.inc}

{$IFDEF TYPES}
{$I ./Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TStringHelper = type helper for string
  {$I ./Core.inc}
  {$I ./String/String.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ./Core.inc}
{$I ./String/String.inc}
{$ENDIF}

{$UNDEF string}
