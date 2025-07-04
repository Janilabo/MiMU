{$IFDEF Integer}
  {$DEFINE XVar := Integer}
  {$DEFINE XVarHelp := TIntegerHelper}
  {$DEFINE XArr := TIntegerArray}
  {$DEFINE XArrHelp := TIntegerArrayHelper}
  {$DEFINE X2DArr := T2DIntegerArray}
  {$DEFINE X2DArrHelp := T2DIntegerArrayHelper}
{$ENDIF}

{$IFDEF Double}
  {$DEFINE XVar := Double}
  {$DEFINE XVarHelp := TDoubleHelper}
  {$DEFINE XArr := TDoubleArray}
  {$DEFINE XArrHelp := TDoubleArrayHelper}
  {$DEFINE X2DArr := T2DDoubleArray}
  {$DEFINE X2DArrHelp := T2DDoubleArrayHelper}
{$ENDIF}

{$IFDEF string}
  {$DEFINE XVar := string}
  {$DEFINE XVarHelp := TStringHelper}
  {$DEFINE XArr := TStringArray}
  {$DEFINE XArrHelp := TStringArrayHelper}
  {$DEFINE X2DArr := T2DStringArray}
  {$DEFINE X2DArrHelp := T2DStringArrayHelper}
{$ENDIF}

{$IFDEF Char}
  {$DEFINE XVar := Char}
  {$DEFINE XVarHelp := TCharHelper}
  {$DEFINE XArr := TCharArray}
  {$DEFINE XArrHelp := TCharArrayHelper}
  {$DEFINE X2DArr := T2DCharArray}
  {$DEFINE X2DArrHelp := T2DCharArrayHelper}
{$ENDIF}

{$IFDEF Boolean}
  {$DEFINE XVar := Boolean}
  {$DEFINE XVarHelp := TBooleanHelper}
  {$DEFINE XArr := TBooleanArray}
  {$DEFINE XArrHelp := TBooleanArrayHelper}
  {$DEFINE X2DArr := T2DBooleanArray}
  {$DEFINE X2DArrHelp := T2DBooleanArrayHelper}
{$ENDIF}

{$IFDEF TPoint}
  {$DEFINE XVar := TPoint}
  {$DEFINE XVarHelp := TPointHelper}
  {$DEFINE XArr := TPointArray}
  {$DEFINE XArrHelp := TPointArrayHelper}
  {$DEFINE X2DArr := T2DPointArray}
  {$DEFINE X2DArrHelp := T2DPointArrayHelper}
{$ENDIF}

{$IFDEF TBox}
  {$DEFINE XVar := TBox}
  {$DEFINE XVarHelp := TBoxHelper}
  {$DEFINE XArr := TBoxArray}
  {$DEFINE XArrHelp := TBoxArrayHelper}
  {$DEFINE X2DArr := T2DBoxArray}
  {$DEFINE X2DArrHelp := T2DBoxArrayHelper}
{$ENDIF}

{$IFDEF TRange}
  {$DEFINE XVar := TRange}
  {$DEFINE XVarHelp := TRangeHelper}
  {$DEFINE XArr := TRangeArray}
  {$DEFINE XArrHelp := TRangeArrayHelper}
  {$DEFINE X2DArr := T2DRangeArray}
  {$DEFINE X2DArrHelp := T2DRangeArrayHelper}
{$ENDIF}