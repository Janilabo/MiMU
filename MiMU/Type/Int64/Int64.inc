{$DEFINE Int64}{$I ../Defines.inc}

{$IFDEF TYPES}
TInt64Compare = specialize TCompare<Int64>;
TInt64Array = array of Int64;
T2DInt64Array = array of TInt64Array;
{$ENDIF}

{$IFDEF HELPERS}
TInt64Helper = type helper for Int64
  {$I Int64.pph}
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(IMPLEMENTATION)}
{$I Int64.pph}
{$ENDIF}

{$UNDEF Int64}