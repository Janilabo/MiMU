{$DEFINE Integer}{$I ./Configuration/Defines.inc}

{$IFDEF TYPES}
{$I ./Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TIntegerHelper = type helper for Integer
  {$I ./Core.inc}
  {$I ./Integer/Integer.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ./Core.inc}
{$I ./Integer/Integer.inc}
{$ENDIF}

{$UNDEF Integer}