{$DEFINE TRange}{$DEFINE THelper := T2DRangeArrayHelper}{$I config\Defines.inc}

{$IFDEF HELPERS}
T2DRangeArrayHelper = type helper for T2DRangeArray
  {$I config\2D.inc}
end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I config\2D.inc}
{$ENDIF}

{$UNDEF TRange}