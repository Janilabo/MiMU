{$IF DEFINED(TYPES) OR DEFINED(HELPERS) OR DEFINED(CLASSES)}
type
{$ENDIF}

{$IF (NOT DEFINED(TBS)) AND (NOT DEFINED(T1D)) AND (NOT DEFINED(T2D))}
  {$I Type/Type.inc}
  {$I Miscellaneous/Randomness.inc}
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
  {$I TArray/TArray.inc}
{$ENDIF}

{$IFNDEF T1D}
  {$IFDEF T2D}
  T2D = class
  public
  {$ENDIF}
  {$I T2DArray/T2DIntegerArray.inc}
  {$I T2DArray/T2DDoubleArray.inc}
  {$I T2DArray/T2DStringArray.inc}
  {$I T2DArray/T2DCharArray.inc}
  {$I T2DArray/T2DBooleanArray.inc}
  {$I T2DArray/T2DPointArray.inc}
  {$I T2DArray/T2DBoxArray.inc}
  {$I T2DArray/T2DRangeArray.inc}
  {$I T2DArray/T2DInt64Array.inc}
  {$I T2DArray/T2DConnectionArray.inc}
  {$I T2DArray/T2DCircleArray.inc}
  {$I T2DArray/T2DTriangleArray.inc}
  {$I T2DArray/T2DSegmentArray.inc}
{$ENDIF}

{$IFDEF CLASSES}
end;
{$ENDIF} 