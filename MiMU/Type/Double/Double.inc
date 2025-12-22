{$DEFINE Double}{$I ../Defines.inc}

{$IFDEF TYPES}
{$I ../Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TDoubleHelper = type helper for Double
  {$I ../Core.inc}
  {$I ./Double.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ../Core.inc}
{$I ./Double.pph}
{$ENDIF}

{$UNDEF Double}