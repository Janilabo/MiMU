{$DEFINE Boolean}{$I ../Defines.inc}

{$IFDEF TYPES}
TBooleanCompare = specialize TCompare<Boolean>;
TBooleanArray = array of Boolean;
T2DBooleanArray = array of TBooleanArray;
{$I ../Base/Base.inc}
{$ENDIF}

{$IFDEF HELPERS}
TBooleanHelper = type helper for Boolean
  {$I ../Base/Base.inc}
  {$I Boolean.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I Boolean.pph}
{$ENDIF}

{$UNDEF Boolean}