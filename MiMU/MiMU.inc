{$IF DEFINED(TYPES) OR DEFINED(HELPERS) OR DEFINED(CLASSES)}
type
{$ENDIF}

{$IF (NOT DEFINED(TBS)) AND (NOT DEFINED(T1D)) AND (NOT DEFINED(T2D))}
  {$I 0D\Integer.inc}
  {$I 0D\Double.inc}
  {$I 0D\String.inc}
  {$I 0D\Char.inc}
  {$I 0D\Boolean.inc}
  {$I 0D\TPoint.inc}
  {$I 0D\TRange.inc}
  {$I 0D\TBox.inc}
  {$I 0D\Int64.inc}
  {$I 0D\TConnection.inc}
  {$I 0D\TCircle.inc}
  {$I 0D\TTriangle.inc}
  {$I 0D\TSegment.inc}
  {$I Randomness.inc}
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
  {$I 1D\TIntegerArray.inc}
  {$I 1D\TDoubleArray.inc}
  {$I 1D\TStringArray.inc}
  {$I 1D\TCharArray.inc}
  {$I 1D\TBooleanArray.inc}
  {$I 1D\TPointArray.inc}
  {$I 1D\TBoxArray.inc}
  {$I 1D\TRangeArray.inc}
  {$I 1D\TInt64Array.inc}
  {$I 1D\TConnectionArray.inc}
  {$I 1D\TCircleArray.inc}
  {$I 1D\TTriangleArray.inc}
  {$I 1D\TSegmentArray.inc}
{$ENDIF}

{$IFNDEF T1D}
  {$IFDEF T2D}
  T2D = class
  public
  {$ENDIF}
  {$I 2D\T2DIntegerArray.inc}
  {$I 2D\T2DDoubleArray.inc}
  {$I 2D\T2DStringArray.inc}
  {$I 2D\T2DCharArray.inc}
  {$I 2D\T2DBooleanArray.inc}
  {$I 2D\T2DPointArray.inc}
  {$I 2D\T2DBoxArray.inc}
  {$I 2D\T2DRangeArray.inc}
  {$I 2D\T2DInt64Array.inc}
  {$I 2D\T2DConnectionArray.inc}
  {$I 2D\T2DCircleArray.inc}
  {$I 2D\T2DTriangleArray.inc}
  {$I 2D\T2DSegmentArray.inc}
{$ENDIF}

{$IFDEF CLASSES}
end;
{$ENDIF} 