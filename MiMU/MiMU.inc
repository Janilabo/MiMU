{$IF DEFINED(TYPES) OR DEFINED(HELPERS) OR DEFINED(CLASSES)}
type
{$ENDIF}

{$IF (NOT DEFINED(TBS)) AND (NOT DEFINED(T1D)) AND (NOT DEFINED(T2D))}
  {$I ./Type/Integer.inc}
  {$I ./Type/Double.inc}
  {$I ./Type/String.inc}
  {$I ./Type/Char.inc}
  {$I ./Type/Boolean.inc}
  {$I ./Type/TPoint.inc}
  {$I ./Type/TRange.inc}
  {$I ./Type/TBox.inc}
  {$I ./Type/Int64.inc}
  {$I ./Type/TConnection.inc}
  {$I ./Type/TCircle.inc}
  {$I ./Type/TTriangle.inc}
  {$I ./Type/TSegment.inc}
  
  {$I .\Miscellaneous\Randomness.inc}
{$ENDIF}

{$IFNDEF T2D}
  {$IFDEF T1D}
  T1D = class
  public
  {$ENDIF}
  {$IFDEF TBS}
  TBinarySearch = class
  public
  {$ENDIF}
  {$I ./TArray/TIntegerArray.inc}
  {$I ./TArray/TDoubleArray.inc}
  {$I ./TArray/TStringArray.inc}
  {$I ./TArray/TCharArray.inc}
  {$I ./TArray/TBooleanArray.inc}
  {$I ./TArray/TPointArray.inc}
  {$I ./TArray/TBoxArray.inc}
  {$I ./TArray/TRangeArray.inc}
  {$I ./TArray/TInt64Array.inc}
  {$I ./TArray/TConnectionArray.inc}
  {$I ./TArray/TCircleArray.inc}
  {$I ./TArray/TTriangleArray.inc}
  {$I ./TArray/TSegmentArray.inc}
{$ENDIF}

{$IFNDEF T1D}
  {$IFDEF T2D}
  T2D = class
  public
  {$ENDIF}
  {$I ./T2DArray/T2DIntegerArray.inc}
  {$I ./T2DArray/T2DDoubleArray.inc}
  {$I ./T2DArray/T2DStringArray.inc}
  {$I ./T2DArray/T2DCharArray.inc}
  {$I ./T2DArray/T2DBooleanArray.inc}
  {$I ./T2DArray/T2DPointArray.inc}
  {$I ./T2DArray/T2DBoxArray.inc}
  {$I ./T2DArray/T2DRangeArray.inc}
  {$I ./T2DArray/T2DInt64Array.inc}
  {$I ./T2DArray/T2DConnectionArray.inc}
  {$I ./T2DArray/T2DCircleArray.inc}
  {$I ./T2DArray/T2DTriangleArray.inc}
  {$I ./T2DArray/T2DSegmentArray.inc}
{$ENDIF}

{$IFDEF CLASSES}
end;
{$ENDIF} 