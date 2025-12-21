{$DEFINE Boolean}{$I ./Configuration/Defines.inc}

{$IFDEF TYPES}
{$I ./Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TBooleanHelper = type helper for Boolean
  {$I ./Core.inc}
  {$I ./Boolean/Boolean.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ./Core.inc}
{$I ./Boolean/Boolean.inc}
{$ENDIF}

{$UNDEF Boolean}