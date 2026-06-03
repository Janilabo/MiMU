{$IFDEF Integer}
  {$DEFINE MType := Integer}
  {$DEFINE MArray := TIntegerArray}
  {$DEFINE M2DArray := T2DIntegerArray}
  {$DEFINE MCompare := TIntegerCompare}
  {$DEFINE MTypeHelper := TIntegerHelper}
  {$DEFINE MArrayHelper := TIntegerArrayHelper}
  {$DEFINE M2DArrayHelper := T2DIntegerArrayHelper}
  {$DEFINE MPointer := PInteger}
  {$DEFINE Sortable}
{$ENDIF}

{$IFDEF Double}
  {$DEFINE MType := Double}
  {$DEFINE MArray := TDoubleArray}
  {$DEFINE M2DArray := T2DDoubleArray}
  {$DEFINE MCompare := TDoubleCompare}
  {$DEFINE MTypeHelper := TDoubleHelper}
  {$DEFINE MArrayHelper := TDoubleArrayHelper}
  {$DEFINE M2DArrayHelper := T2DDoubleArrayHelper}
  {$DEFINE MPointer := PDouble}
  {$DEFINE Sortable}
{$ENDIF}

{$IFDEF string}
  {$DEFINE MType := string}
  {$DEFINE MArray := TStringArray}
  {$DEFINE M2DArray := T2DStringArray}
  {$DEFINE MCompare := TStringCompare}
  {$DEFINE MTypeHelper := TStringHelper}
  {$DEFINE MArrayHelper := TStringArrayHelper}
  {$DEFINE M2DArrayHelper := T2DStringArrayHelper}
  {$DEFINE MPointer := PString}
  {$DEFINE Sortable}
{$ENDIF}

{$IFDEF Char}
  {$DEFINE MType := Char}
  {$DEFINE MArray := TCharArray}
  {$DEFINE M2DArray := T2DCharArray}
  {$DEFINE MCompare := TCharCompare}
  {$DEFINE MTypeHelper := TCharHelper}
  {$DEFINE MArrayHelper := TCharArrayHelper}
  {$DEFINE M2DArrayHelper := T2DCharArrayHelper}
  {$DEFINE MPointer := PChar}
  {$DEFINE Sortable}
{$ENDIF}

{$IFDEF Boolean}
  {$DEFINE MType := Boolean}
  {$DEFINE MArray := TBooleanArray}
  {$DEFINE M2DArray := T2DBooleanArray}
  {$DEFINE MCompare := TBooleanCompare}
  {$DEFINE MTypeHelper := TBooleanHelper}
  {$DEFINE MArrayHelper := TBooleanArrayHelper}
  {$DEFINE M2DArrayHelper := T2DBooleanArrayHelper}
  {$DEFINE MPointer := PBoolean}
  {$UNDEF Sortable}
{$ENDIF}

{$IFDEF TPoint}
  {$DEFINE MType := TPoint}
  {$DEFINE MArray := TPointArray}
  {$DEFINE M2DArray := T2DPointArray}
  {$DEFINE MCompare := TPointCompare}
  {$DEFINE MTypeHelper := TPointHelper}
  {$DEFINE MArrayHelper := TPointArrayHelper}
  {$DEFINE M2DArrayHelper := T2DPointArrayHelper}
  {$DEFINE MPointer := PPoint}
  {$DEFINE FType := Integer}
  {$DEFINE FArray := TIntegerArray}
  {$DEFINE Sortable}
{$ENDIF}

{$IFDEF TBox}
  {$DEFINE MType := TBox}
  {$DEFINE MArray := TBoxArray}
  {$DEFINE M2DArray := T2DBoxArray}
  {$DEFINE MCompare := TBoxCompare}
  {$DEFINE MTypeHelper := TBoxHelper}
  {$DEFINE MArrayHelper := TBoxArrayHelper}
  {$DEFINE M2DArrayHelper := T2DBoxArrayHelper}
  {$DEFINE MPointer := PBox}
  {$DEFINE FType := Integer}
  {$DEFINE FArray := TIntegerArray}
  {$UNDEF Sortable}
{$ENDIF}

{$IFDEF TRange}
  {$DEFINE MType := TRange}
  {$DEFINE MArray := TRangeArray}
  {$DEFINE M2DArray := T2DRangeArray}
  {$DEFINE MCompare := TRangeCompare}
  {$DEFINE MTypeHelper := TRangeHelper}
  {$DEFINE MArrayHelper := TRangeArrayHelper}
  {$DEFINE M2DArrayHelper := T2DRangeArrayHelper}
  {$DEFINE MPointer := PRange}
  {$DEFINE FType := Integer}
  {$DEFINE FArray := TIntegerArray}
  {$UNDEF Sortable}
{$ENDIF}

{$IFDEF TConnection}
  {$DEFINE MType := TConnection}
  {$DEFINE MArray := TConnectionArray}
  {$DEFINE M2DArray := T2DConnectionArray}
  {$DEFINE MCompare := TConnectionCompare}
  {$DEFINE MTypeHelper := TConnectionHelper}
  {$DEFINE MArrayHelper := TConnectionArrayHelper}
  {$DEFINE M2DArrayHelper := T2DConnectionArrayHelper}
  {$DEFINE MPointer := PConnection}
  {$UNDEF Sortable}
{$ENDIF}

{$IFDEF TCircle}
  {$DEFINE MType := TCircle}
  {$DEFINE MArray := TCircleArray}
  {$DEFINE M2DArray := T2DCircleArray}
  {$DEFINE MCompare := TCircleCompare}
  {$DEFINE MTypeHelper := TCircleHelper}
  {$DEFINE MArrayHelper := TCircleArrayHelper}
  {$DEFINE M2DArrayHelper := T2DCircleArrayHelper}
  {$DEFINE MPointer := PCircle}
  {$UNDEF Sortable}
{$ENDIF}

{$IFDEF TTriangle}
  {$DEFINE MType := TTriangle}
  {$DEFINE MArray := TTriangleArray}
  {$DEFINE M2DArray := T2DTriangleArray}
  {$DEFINE MCompare := TTriangleCompare}
  {$DEFINE MTypeHelper := TTriangleHelper}
  {$DEFINE MArrayHelper := TTriangleArrayHelper}
  {$DEFINE M2DArrayHelper := T2DTriangleArrayHelper}
  {$DEFINE MPointer := PTriangle}
  {$UNDEF Sortable}
{$ENDIF}

{$IFDEF TSegment}
  {$DEFINE MType := TSegment}
  {$DEFINE MArray := TSegmentArray}
  {$DEFINE M2DArray := T2DSegmentArray}
  {$DEFINE MCompare := TSegmentCompare}
  {$DEFINE MTypeHelper := TSegmentHelper}
  {$DEFINE MArrayHelper := TSegmentArrayHelper}
  {$DEFINE M2DArrayHelper := T2DSegmentArrayHelper}
  {$DEFINE MPointer := PSegment}
  {$UNDEF Sortable}
{$ENDIF}

{$IFDEF Int64}
  {$DEFINE MType := Int64}
  {$DEFINE MArray := TInt64Array}
  {$DEFINE M2DArray := T2DInt64Array}
  {$DEFINE MCompare := TInt64Compare}
  {$DEFINE MTypeHelper := TInt64Helper}
  {$DEFINE MArrayHelper := TInt64ArrayHelper}
  {$DEFINE M2DArrayHelper := T2DInt64ArrayHelper}
  {$DEFINE MPointer := PInt64}
  {$DEFINE Sortable}
{$ENDIF}