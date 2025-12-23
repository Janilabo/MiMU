{$IFNDEF BASE}
  {$I Integer/Integer.inc}
  {$I Double/Double.inc}
  {$I String/String.inc}
  {$I Char/Char.inc}
  {$I Boolean/Boolean.inc}
  {$I TPoint/TPoint.inc}
  {$I TRange/TRange.inc}
  {$I TBox/TBox.inc}
  {$I Int64/Int64.inc}
  {$I TConnection/TConnection.inc}
  {$I TCircle/TCircle.inc}
  {$I TTriangle/TTriangle.inc}
  {$I TSegment/TSegment.inc}
{$ELSE}
  {$I Base/Base.inc}
{$ENDIF}