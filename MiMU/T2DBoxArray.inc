{$DEFINE TBox}{$I config\Defines.inc}

{$IFDEF INTERFACE}
{$ENDIF}

{$IFDEF HELPERS}
type
  T2DBoxArrayHelper = type helper for T2DBoxArray
    {$I config\2D.inc}
  end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I config\2D.inc}
{$ENDIF}

{$UNDEF TBox}