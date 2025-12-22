{$DEFINE TConnection}{$I ../Type/Defines.inc}

{$IFDEF HELPERS}
T2DConnectionArrayHelper = type helper for T2DConnectionArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF TConnection}
