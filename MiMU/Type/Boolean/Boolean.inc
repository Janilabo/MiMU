{$DEFINE Boolean}{$I ../Defines.inc}

{$IFDEF TYPES}
{$I ../Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TBooleanHelper = type helper for Boolean
  {$I ../Core.inc}
  {$I ./Boolean.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ../Core.inc}
{$I ./Boolean.pph}
{$ENDIF}

{$UNDEF Boolean}