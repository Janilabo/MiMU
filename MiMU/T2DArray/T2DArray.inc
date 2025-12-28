{$IFNDEF BASE}
  {$I T2DIntegerArray.inc}
  {$I T2DDoubleArray.inc}
  {$I T2DStringArray.inc}
  {$I T2DCharArray.inc}
  {$I T2DBooleanArray.inc}
  {$I T2DPointArray.inc}
  {$I T2DBoxArray.inc}
  {$I T2DRangeArray.inc}
  {$I T2DInt64Array.inc}
  {$I T2DConnectionArray.inc}
  {$I T2DCircleArray.inc}
  {$I T2DTriangleArray.inc}
  {$I T2DSegmentArray.inc}
{$ELSE}
  {$I Base/Base.inc}
{$ENDIF}
