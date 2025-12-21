{$DEFINE string}{$I ../Type/Configuration/Defines.inc}

{$IFDEF HELPERS}
T2DStringArrayHelper = type helper for T2DStringArray
  {$I ./Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I ./Core.inc}
{$ENDIF}

{$UNDEF string}