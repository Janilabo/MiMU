{$DEFINE Integer}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
TIntegerCompare = specialize TCompare<Integer>;
TIntegerArray = array of Integer;
T2DIntegerArray = array of TIntegerArray;
{$I ../Type.inc}
{$ENDIF}

{$IFDEF HELPERS}
TIntegerHelper = type helper for Integer
  {$I ../Type.inc}
  {$I Integer.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Type.inc}
{$I Integer.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Integer}