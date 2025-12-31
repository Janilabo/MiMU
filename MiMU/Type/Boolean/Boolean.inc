{$DEFINE Boolean}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
TBooleanCompare = specialize TCompare<Boolean>;
TBooleanArray = array of Boolean;
T2DBooleanArray = array of TBooleanArray;
{$I ../Type.inc}
{$ENDIF}

{$IFDEF HELPERS}
TBooleanHelper = type helper for Boolean
  {$I ../Type.inc}
  {$I Boolean.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Type.inc}
{$I Boolean.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Boolean}