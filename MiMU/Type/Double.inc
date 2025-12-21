{$DEFINE Double}{$I ./Configuration/Defines.inc}

{$IFDEF TYPES}
{$I ./Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TDoubleHelper = type helper for Double
  {$I ./Core.inc}
  {$I ./Double/Double.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ./Core.inc}
{$I ./Double/Double.inc}
{$ENDIF}

{$UNDEF Double}