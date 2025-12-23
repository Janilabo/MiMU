{$DEFINE Integer}{$I ../Defines.inc}

{$IFDEF TYPES}
{$I ../Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TIntegerHelper = type helper for Integer
  {$I ../Core.inc}
  {$I Integer.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ../Core.inc}
{$I Integer.pph}
{$ENDIF}

{$UNDEF Integer}