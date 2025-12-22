{$DEFINE string}{$I ../Defines.inc}

{$IFDEF TYPES}
{$I ../Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TStringHelper = type helper for string
  {$I ../Core.inc}
  {$I ./String.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ../Core.inc}
{$I ./String.pph}
{$ENDIF}

{$UNDEF string}
