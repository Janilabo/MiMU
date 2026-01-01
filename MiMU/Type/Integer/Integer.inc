{$DEFINE Integer}{$I ../Defines.inc}

{$IFDEF TYPES}
TIntegerCompare = specialize TCompare<Integer>;
TIntegerArray = array of Integer;
T2DIntegerArray = array of TIntegerArray;
{$ENDIF}

{$IFDEF HELPERS}
TIntegerHelper = type helper for Integer
  {$I ../Base/Base.inc}
  {$I Integer.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I Integer.pph}
{$ENDIF}

{$UNDEF Integer}