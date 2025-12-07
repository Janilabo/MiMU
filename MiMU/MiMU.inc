{$IF NOT (DEFINED(T1D) OR DEFINED(T2D))}
  {$I Type\Integer.inc}
  {$I Type\Double.inc}
  {$I Type\String.inc}
  {$I Type\Char.inc}
  {$I Type\TPoint.inc}
  {$I Type\Boolean.inc}
  {$I Type\TRange.inc}
  {$I Type\TBox.inc}
  {$I Type\Int64.inc}
  {$I Type\TConnection.inc}
  {$I Type\TCircle.inc}
  {$I Type\TTriangle.inc}
  {$I Type\TSegment.inc}
{$ENDIF}

{$IFNDEF T2D}
  {$IFDEF T1D}
  type
    T1D = class
    public
  {$ENDIF}
  {$I Array\TIntegerArray.inc}
  {$I Array\TDoubleArray.inc}
  {$I Array\TStringArray.inc}
  {$I Array\TCharArray.inc}
  {$I Array\TBooleanArray.inc}
  {$I Array\TPointArray.inc}
  {$I Array\TBoxArray.inc}
  {$I Array\TRangeArray.inc}
  {$IFDEF T1D}
  end;
  {$ENDIF}
{$ENDIF}

{$IFNDEF T1D}
  {$IFDEF T2D}
  type
    T2D = class
    public
  {$ENDIF}
  {$I Array\2D\T2DIntegerArray.inc}
  {$I Array\2D\T2DDoubleArray.inc}
  {$I Array\2D\T2DStringArray.inc}
  {$I Array\2D\T2DCharArray.inc}
  {$I Array\2D\T2DBooleanArray.inc}
  {$I Array\2D\T2DPointArray.inc}
  {$I Array\2D\T2DBoxArray.inc}
  {$I Array\2D\T2DRangeArray.inc}
  {$IFDEF T2D}
  end;
  {$ENDIF}
{$ENDIF}