{$DEFINE TConnection}{$I ../Type/Defines.inc}

{$IFDEF HELPERS}
TConnectionArrayHelper = type helper for TConnectionArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF TConnection}
