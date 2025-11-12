{$IFDEF Integer}
  {$DEFINE TVar := Integer}
  {$DEFINE HVar := TIntegerHelper}
  {$DEFINE TArr := TIntegerArray}
  {$DEFINE HArr := TIntegerArrayHelper}
  {$DEFINE T2DArr := T2DIntegerArray}
  {$DEFINE H2DArr := T2DIntegerArrayHelper}
  {$DEFINE Sortable}
{$ENDIF}
{$IFDEF Double}
  {$DEFINE TVar := Double}
  {$DEFINE HVar := TDoubleHelper}
  {$DEFINE TArr := TDoubleArray}
  {$DEFINE HArr := TDoubleArrayHelper}
  {$DEFINE T2DArr := T2DDoubleArray}
  {$DEFINE H2DArr := T2DDoubleArrayHelper}
  {$DEFINE Sortable}
{$ENDIF}
{$IFDEF string}
  {$DEFINE TVar := string}
  {$DEFINE HVar := TStringHelper}
  {$DEFINE TArr := TStringArray}
  {$DEFINE HArr := TStringArrayHelper}
  {$DEFINE T2DArr := T2DStringArray}
  {$DEFINE H2DArr := T2DStringArrayHelper}
  {$DEFINE Sortable}
{$ENDIF}
{$IFDEF Char}
  {$DEFINE TVar := Char}
  {$DEFINE HVar := TCharHelper}
  {$DEFINE TArr := TCharArray}
  {$DEFINE HArr := TCharArrayHelper}
  {$DEFINE T2DArr := T2DCharArray}
  {$DEFINE H2DArr := T2DCharArrayHelper}
  {$DEFINE Sortable}
{$ENDIF}
{$IFDEF Boolean}
  {$DEFINE TVar := Boolean}
  {$DEFINE HVar := TBooleanHelper}
  {$DEFINE TArr := TBooleanArray}
  {$DEFINE HArr := TBooleanArrayHelper}
  {$DEFINE T2DArr := T2DBooleanArray}
  {$DEFINE H2DArr := T2DBooleanArrayHelper}
  {$UNDEF Sortable}
{$ENDIF}
{$IFDEF TPoint}
  {$DEFINE TVar := TPoint}
  {$DEFINE HVar := TPointHelper}
  {$DEFINE TArr := TPointArray}
  {$DEFINE HArr := TPointArrayHelper}
  {$DEFINE T2DArr := T2DPointArray}
  {$DEFINE H2DArr := T2DPointArrayHelper}
  {$DEFINE Sortable}
{$ENDIF}
{$IFDEF TBox}
  {$DEFINE TVar := TBox}
  {$DEFINE HVar := TBoxHelper}
  {$DEFINE TArr := TBoxArray}
  {$DEFINE HArr := TBoxArrayHelper}
  {$DEFINE T2DArr := T2DBoxArray}
  {$DEFINE H2DArr := T2DBoxArrayHelper}
  {$UNDEF Sortable}
{$ENDIF}
{$IFDEF TRange}
  {$DEFINE TVar := TRange}
  {$DEFINE HVar := TRangeHelper}
  {$DEFINE TArr := TRangeArray}
  {$DEFINE HArr := TRangeArrayHelper}
  {$DEFINE T2DArr := T2DRangeArray}
  {$DEFINE H2DArr := T2DRangeArrayHelper}
  {$UNDEF Sortable}
{$ENDIF}
{$IFDEF Int64}
  {$DEFINE TVar := Int64}
  {$DEFINE HVar := TInt64Helper}
{$ENDIF}