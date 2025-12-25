{$IFNDEF BASE}
  {$I TIntegerArray.inc}
  {$I TDoubleArray/TDoubleArray.inc}
  {$I TStringArray/TStringArray.inc}
  {$I TCharArray/TCharArray.inc}
  {$I TBooleanArray/TBooleanArray.inc}
  {$I TPointArray.inc}
  {$I TRangeArray.inc}
  {$I TBoxArray/TBoxArray.inc}
  {$I TInt64Array/TInt64Array.inc}
  {$I TConnectionArray/TConnectionArray.inc}
  {$I TCircleArray/TCircleArray.inc}
  {$I TTriangleArray/TTriangleArray.inc}
  {$I TSegmentArray/TSegmentArray.inc}
{$ELSE}
  {$I Base/Base.inc}
{$ENDIF}
