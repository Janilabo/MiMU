{$DEFINE Int64}{$I ./Configuration/Defines.inc}

{$IFDEF TYPES}
{$I ./Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TInt64Helper = type helper for Int64
  {$I ./Core.inc} 
  {$I ./Int64/Int64.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ./Core.inc}
{$I ./Int64/Int64.inc}
{$ENDIF}

{$UNDEF Int64}