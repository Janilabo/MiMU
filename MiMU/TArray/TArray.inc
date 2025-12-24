{$IFNDEF BASE}
  {$I TIntegerArray.inc}
  {$I TDoubleArray.inc}
  {$I TStringArray.inc}
  {$I TCharArray.inc}
  {$I TBooleanArray/TBooleanArray.inc}
  {$I TPointArray.inc}
  {$I TRangeArray.inc}
  {$I TBoxArray.inc}
  {$I TInt64Array.inc}
  {$I TConnectionArray.inc}
  {$I TCircleArray.inc}
  {$I TTriangleArray.inc}
  {$I TSegmentArray.inc}
{$ELSE}
  {$I Base/Base.inc}
{$ENDIF}