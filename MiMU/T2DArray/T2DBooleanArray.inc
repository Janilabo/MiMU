{$DEFINE Boolean}{$I ..\Type\Configuration\Defines.inc}

{$IFDEF HELPERS}
T2DBooleanArrayHelper = type helper for T2DBooleanArray
  {$I Core.inc}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}

{$UNDEF Boolean}