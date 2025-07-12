{$IFDEF Integer}
  {$DEFINE XVar := Integer}
  {$DEFINE XVarHelp := TIntegerHelper}
  {$DEFINE XArr := TIntegerArray}
  {$DEFINE XArrHelp := TIntegerArrayHelper}
  {$DEFINE X2DArr := T2DIntegerArray}
  {$DEFINE X2DArrHelp := T2DIntegerArrayHelper}
  {$DEFINE Sortable}
{$ENDIF}
{$IFDEF Double}
  {$DEFINE XVar := Double}
  {$DEFINE XVarHelp := TDoubleHelper}
  {$DEFINE XArr := TDoubleArray}
  {$DEFINE XArrHelp := TDoubleArrayHelper}
  {$DEFINE X2DArr := T2DDoubleArray}
  {$DEFINE X2DArrHelp := T2DDoubleArrayHelper}
  {$DEFINE Sortable}
{$ENDIF}
{$IFDEF string}
  {$DEFINE XVar := string}
  {$DEFINE XVarHelp := TStringHelper}
  {$DEFINE XArr := TStringArray}
  {$DEFINE XArrHelp := TStringArrayHelper}
  {$DEFINE X2DArr := T2DStringArray}
  {$DEFINE X2DArrHelp := T2DStringArrayHelper}
  {$DEFINE Sortable}
{$ENDIF}
{$IFDEF Char}
  {$DEFINE XVar := Char}
  {$DEFINE XVarHelp := TCharHelper}
  {$DEFINE XArr := TCharArray}
  {$DEFINE XArrHelp := TCharArrayHelper}
  {$DEFINE X2DArr := T2DCharArray}
  {$DEFINE X2DArrHelp := T2DCharArrayHelper}
  {$DEFINE Sortable}
{$ENDIF}
{$IFDEF Boolean}
  {$DEFINE XVar := Boolean}
  {$DEFINE XVarHelp := TBooleanHelper}
  {$DEFINE XArr := TBooleanArray}
  {$DEFINE XArrHelp := TBooleanArrayHelper}
  {$DEFINE X2DArr := T2DBooleanArray}
  {$DEFINE X2DArrHelp := T2DBooleanArrayHelper}
  {$UNDEF Sortable}
{$ENDIF}
{$IFDEF TPoint}
  {$DEFINE XVar := TPoint}
  {$DEFINE XVarHelp := TPointHelper}
  {$DEFINE XArr := TPointArray}
  {$DEFINE XArrHelp := TPointArrayHelper}
  {$DEFINE X2DArr := T2DPointArray}
  {$DEFINE X2DArrHelp := T2DPointArrayHelper}
  {$UNDEF Sortable}
{$ENDIF}
{$IFDEF TBox}
  {$DEFINE XVar := TBox}
  {$DEFINE XVarHelp := TBoxHelper}
  {$DEFINE XArr := TBoxArray}
  {$DEFINE XArrHelp := TBoxArrayHelper}
  {$DEFINE X2DArr := T2DBoxArray}
  {$DEFINE X2DArrHelp := T2DBoxArrayHelper}
  {$UNDEF Sortable}
{$ENDIF}
{$IFDEF TRange}
  {$DEFINE XVar := TRange}
  {$DEFINE XVarHelp := TRangeHelper}
  {$DEFINE XArr := TRangeArray}
  {$DEFINE XArrHelp := TRangeArrayHelper}
  {$DEFINE X2DArr := T2DRangeArray}
  {$DEFINE X2DArrHelp := T2DRangeArrayHelper}
  {$UNDEF Sortable}
{$ENDIF}
{$IFDEF Int64}
  {$DEFINE XVar := Int64}
  {$DEFINE XVarHelp := TInt64Helper}
{$ENDIF}