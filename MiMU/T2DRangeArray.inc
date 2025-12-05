{$DEFINE TRange}{$I config\Defines.inc}

{$IFDEF INTERFACE}
{$ENDIF}

{$IFDEF HELPERS}
type
  T2DRangeArrayHelper = type helper for T2DRangeArray
    {$I config\2D.inc}
  end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I config\2D.inc}
{$ENDIF}

{$UNDEF TRange}