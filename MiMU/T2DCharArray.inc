{$DEFINE Char}{$I config\Defines.inc}

{$IFDEF HELPERS}
T2DCharArrayHelper = type helper for T2DCharArray
  {$I config\2D.inc}
end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I config\2D.inc}
{$ENDIF}

{$UNDEF Char}