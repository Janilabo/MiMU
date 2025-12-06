{$DEFINE TBox}{$DEFINE THelper := T2DBoxArrayHelper}{$I config\Defines.inc}

{$IFDEF HELPERS}
T2DBoxArrayHelper = type helper for T2DBoxArray
  {$I config\2D.inc}
end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I config\2D.inc}
{$ENDIF}

{$UNDEF TBox}