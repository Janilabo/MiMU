{$DEFINE Boolean}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
{$I ../Type.inc}
{$ENDIF}

{$IFDEF HELPERS}
TBooleanHelper = type helper for Boolean
  {$I ../Type.inc}
  {$I Boolean.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS)}
{$I ../Type.inc}
{$I Boolean.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Boolean}