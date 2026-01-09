{$DEFINE Boolean}{$I ../Defines.inc}

{$IFDEF TYPES}
TBooleanCompare = function(const A, B: Boolean): Integer;
TBooleanArray = array of Boolean;
T2DBooleanArray = array of TBooleanArray;
{$ENDIF}

{$IFDEF HELPERS}
TBooleanHelper = type helper for Boolean
  {$I Boolean.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I Boolean.pph}
{$ENDIF}

{$UNDEF Boolean}