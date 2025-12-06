{$IFDEF Integer}
  {$DEFINE TVar := Integer}
  {$DEFINE TArr := TIntegerArray}
  {$DEFINE T2DArr := T2DIntegerArray}
  {$DEFINE Sortable}
{$ENDIF}
{$IFDEF Double}
  {$DEFINE TVar := Double}
  {$DEFINE TArr := TDoubleArray}
  {$DEFINE T2DArr := T2DDoubleArray}
  {$DEFINE Sortable}
{$ENDIF}
{$IFDEF string}
  {$DEFINE TVar := string}
  {$DEFINE TArr := TStringArray}
  {$DEFINE T2DArr := T2DStringArray}
  {$DEFINE Sortable}
{$ENDIF}
{$IFDEF Char}
  {$DEFINE TVar := Char}
  {$DEFINE TArr := TCharArray}
  {$DEFINE T2DArr := T2DCharArray}
  {$DEFINE Sortable}
{$ENDIF}
{$IFDEF Boolean}
  {$DEFINE TVar := Boolean}
  {$DEFINE TArr := TBooleanArray}
  {$DEFINE T2DArr := T2DBooleanArray}
  {$UNDEF Sortable}
{$ENDIF}
{$IFDEF TPoint}
  {$DEFINE TVar := TPoint}
  {$DEFINE TArr := TPointArray}
  {$DEFINE T2DArr := T2DPointArray}
  {$DEFINE Sortable}
  {$DEFINE FVar := Integer}
  {$DEFINE FArr := TIntegerArray}
{$ENDIF}
{$IFDEF TBox}
  {$DEFINE TVar := TBox}
  {$DEFINE TArr := TBoxArray}
  {$DEFINE T2DArr := T2DBoxArray}
  {$UNDEF Sortable}
  {$DEFINE FVar := Integer}
  {$DEFINE FArr := TIntegerArray}
{$ENDIF}
{$IFDEF TRange}
  {$DEFINE TVar := TRange}
  {$DEFINE TArr := TRangeArray}
  {$DEFINE T2DArr := T2DRangeArray}
  {$UNDEF Sortable}
  {$DEFINE FVar := Integer}
  {$DEFINE FArr := TIntegerArray}
{$ENDIF}
{$IFDEF Int64}
  {$DEFINE TVar := Int64}
{$ENDIF}