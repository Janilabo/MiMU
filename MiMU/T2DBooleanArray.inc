{$DEFINE Boolean}{$I config\Defines.inc}

{$IFDEF INTERFACE}
{$ENDIF}

{$IFDEF HELPERS}
type
  T2DBooleanArrayHelper = type helper for T2DBooleanArray
    {$I config\2D.inc}
  end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I config\2D.inc}
{$ENDIF}

{$UNDEF Boolean}