{$DEFINE Int64}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
{$I ../Type.inc}
{$ENDIF}

{$IFDEF HELPERS}
TInt64Helper = type helper for Int64
  {$I ../Type.inc} 
  {$I Int64.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ../Type.inc}
{$I Int64.pph}
{$ENDIF}

{$UNDEF BASE}{$UNDEF Int64}