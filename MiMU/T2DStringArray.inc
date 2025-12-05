{$DEFINE string}{$I config\Defines.inc}

{$IFDEF HELPERS}
T2DStringArrayHelper = type helper for T2DStringArray
  {$I config\2D.inc}
end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I config\2D.inc}
{$ENDIF}

{$UNDEF string}