{$I MiMU\Integer.inc}
{$I MiMU\Int64.inc}
{$I MiMU\Double.inc}
{$I MiMU\String.inc}
{$I MiMU\Boolean.inc}
{$I MiMU\TPoint.inc}
{$I MiMU\TBox.inc}
{$I MiMU\TRange.inc}
{$I MiMU\TIntegerArray.inc}
{$I MiMU\TDoubleArray.inc}
{$I MiMU\TStringArray.inc}
{$I MiMU\TCharArray.inc}
{$I MiMU\TBooleanArray.inc}
{$I MiMU\TPointArray.inc}
{$I MiMU\TBoxArray.inc}
{$I MiMU\TRangeArray.inc}

{$DEFINE var_TArray}
function TIntegerHelper.TArray(const aSize: Integer = 1): TIntegerArray; overload cdecl; {$I MIMU\TArray.inc}
function TDoubleHelper.TArray(const aSize: Integer = 1): TDoubleArray; overload cdecl; {$I MIMU\TArray.inc}
function TStringHelper.TArray(const aSize: Integer = 1): TStringArray; overload cdecl; {$I MIMU\TArray.inc}
function TCharHelper.TArray(const aSize: Integer = 1): TCharArray; overload cdecl; {$I MIMU\TArray.inc}
function TBooleanHelper.TArray(const aSize: Integer = 1): TBooleanArray; overload cdecl; {$I MIMU\TArray.inc}
function TPointHelper.TArray(const aSize: Integer = 1): TPointArray; overload cdecl; {$I MIMU\TArray.inc}
function TBoxHelper.TArray(const aSize: Integer = 1): TBoxArray; overload cdecl; {$I MIMU\TArray.inc}
function TRangeHelper.TArray(const aSize: Integer = 1): TRangeArray; overload cdecl; {$I MIMU\TArray.inc}
{$UNDEF var_TArray}

{$DEFINE var_T2DArray}
function TIntegerHelper.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DIntegerArray; overload cdecl; {$I MIMU\T2DArray.inc}
function TDoubleHelper.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DDoubleArray; overload cdecl; {$I MIMU\T2DArray.inc}
function TStringHelper.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DStringArray; overload cdecl; {$I MIMU\T2DArray.inc}
function TCharHelper.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DCharArray; overload cdecl; {$I MIMU\T2DArray.inc}
function TBooleanHelper.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DBooleanArray; overload cdecl; {$I MIMU\T2DArray.inc}
function TPointHelper.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DPointArray; overload cdecl; {$I MIMU\T2DArray.inc}
function TBoxHelper.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DBoxArray; overload cdecl; {$I MIMU\T2DArray.inc}
function TRangeHelper.T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DRangeArray; overload cdecl; {$I MIMU\T2DArray.inc}
{$UNDEF var_T2DArray}

{$DEFINE TArray_Add1}
function TIntegerArrayHelper.Add(const item: Integer; const duplicates: Boolean = True): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Add(const item: Double; const duplicates: Boolean = True): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Add(const item: string; const duplicates: Boolean = True): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Add(const item: Char; const duplicates: Boolean = True): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Add(const item: Boolean; const duplicates: Boolean = True): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Add(const item: TPoint; const duplicates: Boolean = True): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Add(const item: TBox; const duplicates: Boolean = True): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Add(const item: TRange; const duplicates: Boolean = True): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Add1}

{$DEFINE TArray_Add2}
function TIntegerArrayHelper.Add(const items: TIntegerArray; const duplicates: Boolean = True): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Add(const items: TDoubleArray; const duplicates: Boolean = True): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Add(const items: TStringArray; const duplicates: Boolean = True): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Add(const items: TCharArray; const duplicates: Boolean = True): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Add(const items: TBooleanArray; const duplicates: Boolean = True): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Add(const items: TPointArray; const duplicates: Boolean = True): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Add(const items: TBoxArray; const duplicates: Boolean = True): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Add(const items: TRangeArray; const duplicates: Boolean = True): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Add2}

{$DEFINE TArray_AllEqual}
function TIntegerArrayHelper.AllEqual: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.AllEqual: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.AllEqual: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.AllEqual: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.AllEqual: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.AllEqual: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.AllEqual: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.AllEqual: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_AllEqual}

{$DEFINE TArray_AllSame}
function TIntegerArrayHelper.AllSame: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.AllSame: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.AllSame: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.AllSame: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.AllSame: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.AllSame: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.AllSame: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.AllSame: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_AllSame}

{$DEFINE TArray_AllUnique}
function TIntegerArrayHelper.AllUnique: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.AllUnique: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.AllUnique: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.AllUnique: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.AllUnique: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.AllUnique: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.AllUnique: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.AllUnique: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_AllUnique}

{$DEFINE TArray_Append1}
function TIntegerArrayHelper.Append(const item: Integer; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Append(const item: Double; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Append(const item: string; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Append(const item: Char; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Append(const item: Boolean; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Append(const item: TPoint; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Append(const item: TBox; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Append(const item: TRange; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Append1}

{$DEFINE TArray_Append2}
function TIntegerArrayHelper.Append(const items: TIntegerArray; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Append(const items: TDoubleArray; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Append(const items: TStringArray; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Append(const items: TCharArray; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Append(const items: TBooleanArray; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Append(const items: TPointArray; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Append(const items: TBoxArray; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Append(const items: TRangeArray; const duplicates: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Append2}

{$DEFINE TArray_Build}
function TIntegerArrayHelper.Build(const item: Integer; const aSize: Integer = 1): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Build(const item: Double; const aSize: Integer = 1): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Build(const item: string; const aSize: Integer = 1): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Build(const item: Char; const aSize: Integer = 1): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Build(const item: Boolean; const aSize: Integer = 1): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Build(const item: TPoint; const aSize: Integer = 1): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Build(const item: TBox; const aSize: Integer = 1): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Build(const item: TRange; const aSize: Integer = 1): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Build}

{$DEFINE TArray_BuiltWith}
function TIntegerArrayHelper.BuiltWith(const allowed: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.BuiltWith(const allowed: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.BuiltWith(const allowed: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.BuiltWith(const allowed: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.BuiltWith(const allowed: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.BuiltWith(const allowed: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.BuiltWith(const allowed: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.BuiltWith(const allowed: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_BuiltWith}

{$DEFINE TArray_BuiltWithout}
function TIntegerArrayHelper.BuiltWithout(const forbidden: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.BuiltWithout(const forbidden: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.BuiltWithout(const forbidden: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.BuiltWithout(const forbidden: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.BuiltWithout(const forbidden: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.BuiltWithout(const forbidden: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.BuiltWithout(const forbidden: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.BuiltWithout(const forbidden: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_BuiltWithout}

{$DEFINE TArray_Clear}
function TIntegerArrayHelper.Clear: Boolean; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Clear: Boolean; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Clear: Boolean; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Clear: Boolean; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Clear: Boolean; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Clear: Boolean; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Clear: Boolean; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Clear: Boolean; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Clear}

{$DEFINE TArray_Clone1}
function TIntegerArrayHelper.Clone(const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Clone(const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Clone(const index: Integer = 0; const count: Integer = 2147483647): TStringArray; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Clone(const index: Integer = 0; const count: Integer = 2147483647): TCharArray; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Clone(const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Clone(const index: Integer = 0; const count: Integer = 2147483647): TPointArray; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Clone(const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Clone(const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Clone1}

{$DEFINE TArray_Clone2}
function TIntegerArrayHelper.Clone(const ID: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Clone(const ID: TIntegerArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Clone(const ID: TIntegerArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Clone(const ID: TIntegerArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Clone(const ID: TIntegerArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Clone(const ID: TIntegerArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Clone(const ID: TIntegerArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Clone(const ID: TIntegerArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Clone2}

{$DEFINE TArray_Combine}
function TIntegerArrayHelper.Combine(const b: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Combine(const b: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Combine(const b: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Combine(const b: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Combine(const b: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Combine(const b: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Combine(const b: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Combine(const b: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Combine}

{$DEFINE TArray_Contains}
function TIntegerArrayHelper.Contains(const item: Integer; const index: Integer = 0): Boolean; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Contains(const item: Double; const index: Integer = 0): Boolean; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Contains(const item: string; const index: Integer = 0): Boolean; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Contains(const item: Char; const index: Integer = 0): Boolean; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Contains(const item: Boolean; const index: Integer = 0): Boolean; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Contains(const item: TPoint; const index: Integer = 0): Boolean; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Contains(const item: TBox; const index: Integer = 0): Boolean; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Contains(const item: TRange; const index: Integer = 0): Boolean; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Contains}

{$DEFINE TArray_Copy}
function TIntegerArrayHelper.Copy(const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Copy(const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Copy(const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Copy(const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Copy(const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Copy(const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Copy(const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Copy(const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Copy}

{$DEFINE TArray_Create1}
function TIntegerArrayHelper.Create(const item: Integer): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Create(const item: Double): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Create(const item: string): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Create(const item: Char): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Create(const item: Boolean): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Create(const item: TPoint): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Create(const item: TBox): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Create(const item: TRange): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Create1}

{$DEFINE TArray_Create2}
function TIntegerArrayHelper.Create(const aSize: Integer; const item: Integer): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Create(const aSize: Integer; const item: Double): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Create(const aSize: Integer; const item: string): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Create(const aSize: Integer; const item: Char): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Create(const aSize: Integer; const item: Boolean): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Create(const aSize: Integer; const item: TPoint): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Create(const aSize: Integer; const item: TBox): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Create(const aSize: Integer; const item: TRange): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Create2}

{$DEFINE TArray_Delete1}
function TIntegerArrayHelper.Delete(const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Delete(const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Delete(const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Delete(const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Delete(const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Delete(const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Delete(const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Delete(const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Delete1}

{$DEFINE TArray_Delete2}
function TIntegerArrayHelper.Delete(const ID: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Delete(const ID: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Delete(const ID: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Delete(const ID: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Delete(const ID: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Delete(const ID: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Delete(const ID: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Delete(const ID: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Delete2}

{$DEFINE TArray_Differ}
function TIntegerArrayHelper.Differ(const target: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Differ(const target: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Differ(const target: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Differ(const target: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Differ(const target: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Differ(const target: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Differ(const target: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Differ(const target: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Differ}

{$DEFINE TArray_Distribute}
function TIntegerArrayHelper.Distribute(const parts: Integer): T2DIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Distribute(const parts: Integer): T2DDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Distribute(const parts: Integer): T2DStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Distribute(const parts: Integer): T2DCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Distribute(const parts: Integer): T2DBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Distribute(const parts: Integer): T2DPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Distribute(const parts: Integer): T2DBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Distribute(const parts: Integer): T2DRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Distribute}

{$DEFINE TArray_Dump}
function TIntegerArrayHelper.Dump(const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Dump(const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Dump(const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Dump(const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Dump(const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Dump(const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Dump(const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Dump(const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Dump}

{$DEFINE TArray_Dupe}
function TIntegerArrayHelper.Dupe: TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Dupe: TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Dupe: TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Dupe: TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Dupe: TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Dupe: TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Dupe: TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Dupe: TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Dupe}

{$DEFINE TArray_Empty1}
function TIntegerArrayHelper.Empty: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Empty: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Empty: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Empty: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Empty: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Empty: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Empty: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Empty: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Empty1}

{$DEFINE TArray_Equal}
function TIntegerArrayHelper.Equal(const target: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Equal(const target: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Equal(const target: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Equal(const target: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Equal(const target: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Equal(const target: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Equal(const target: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Equal(const target: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Equal}

{$DEFINE TArray_Extend1}
function TIntegerArrayHelper.Extend(const item: Integer): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Extend(const item: Double): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Extend(const item: string): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Extend(const item: Char): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Extend(const item: Boolean): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Extend(const item: TPoint): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Extend(const item: TBox): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Extend(const item: TRange): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Extend1}

{$DEFINE TArray_Extend2}
function TIntegerArrayHelper.Extend(const items: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Extend(const items: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Extend(const items: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Extend(const items: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Extend(const items: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Extend(const items: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Extend(const items: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Extend(const items: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Extend2}

{$DEFINE TArray_Extract1}
function TIntegerArrayHelper.Extract(const item: Integer; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Extract(const item: Double; const index: Integer = 0): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Extract(const item: string; const index: Integer = 0): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Extract(const item: Char; const index: Integer = 0): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Extract(const item: Boolean; const index: Integer = 0): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Extract(const item: TPoint; const index: Integer = 0): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Extract(const item: TBox; const index: Integer = 0): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Extract(const item: TRange; const index: Integer = 0): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Extract1}

{$DEFINE TArray_Extract2}
function TIntegerArrayHelper.Extract(const items: TIntegerArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Extract(const items: TDoubleArray; const index: Integer = 0): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Extract(const items: TStringArray; const index: Integer = 0): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Extract(const items: TCharArray; const index: Integer = 0): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Extract(const items: TBooleanArray; const index: Integer = 0): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Extract(const items: TPointArray; const index: Integer = 0): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Extract(const items: TBoxArray; const index: Integer = 0): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Extract(const items: TRangeArray; const index: Integer = 0): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Extract2}

{$DEFINE TArray_ExtractEvery}
function TIntegerArrayHelper.ExtractEvery(const X: Integer = 1; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.ExtractEvery(const X: Integer = 1; const index: Integer = 0): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.ExtractEvery(const X: Integer = 1; const index: Integer = 0): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.ExtractEvery(const X: Integer = 1; const index: Integer = 0): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.ExtractEvery(const X: Integer = 1; const index: Integer = 0): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.ExtractEvery(const X: Integer = 1; const index: Integer = 0): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.ExtractEvery(const X: Integer = 1; const index: Integer = 0): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.ExtractEvery(const X: Integer = 1; const index: Integer = 0): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_ExtractEvery}

{$DEFINE TArray_Fill1}
function TIntegerArrayHelper.Fill(const item: Integer; const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Fill(const item: Double; const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Fill(const item: string; const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Fill(const item: Char; const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Fill(const item: Boolean; const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Fill(const item: TPoint; const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Fill(const item: TBox; const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Fill(const item: TRange; const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Fill1}

{$DEFINE TArray_Fill2}
function TIntegerArrayHelper.Fill(const items: TIntegerArray; const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Fill(const items: TDoubleArray; const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Fill(const items: TStringArray; const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Fill(const items: TCharArray; const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Fill(const items: TBooleanArray; const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Fill(const items: TPointArray; const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Fill(const items: TBoxArray; const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Fill(const items: TRangeArray; const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Fill2}

{$DEFINE TArray_Filter1}
function TIntegerArrayHelper.Filter(const item: Integer; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Filter(const item: Double; const index: Integer = 0): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Filter(const item: string; const index: Integer = 0): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Filter(const item: Char; const index: Integer = 0): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Filter(const item: Boolean; const index: Integer = 0): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Filter(const item: TPoint; const index: Integer = 0): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Filter(const item: TBox; const index: Integer = 0): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Filter(const item: TRange; const index: Integer = 0): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Filter1}

{$DEFINE TArray_Filter2}
function TIntegerArrayHelper.Filter(const items: TIntegerArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Filter(const items: TDoubleArray; const index: Integer = 0): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Filter(const items: TStringArray; const index: Integer = 0): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Filter(const items: TCharArray; const index: Integer = 0): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Filter(const items: TBooleanArray; const index: Integer = 0): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Filter(const items: TPointArray; const index: Integer = 0): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Filter(const items: TBoxArray; const index: Integer = 0): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Filter(const items: TRangeArray; const index: Integer = 0): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Filter2}

{$DEFINE TArray_FilterEvery}
function TIntegerArrayHelper.FilterEvery(const X: Integer = 1; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.FilterEvery(const X: Integer = 1; const index: Integer = 0): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.FilterEvery(const X: Integer = 1; const index: Integer = 0): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.FilterEvery(const X: Integer = 1; const index: Integer = 0): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.FilterEvery(const X: Integer = 1; const index: Integer = 0): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.FilterEvery(const X: Integer = 1; const index: Integer = 0): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.FilterEvery(const X: Integer = 1; const index: Integer = 0): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.FilterEvery(const X: Integer = 1; const index: Integer = 0): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_FilterEvery}

{$DEFINE TArray_Find1}
function TIntegerArrayHelper.Find(const ID: TRange; const item: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Find(const ID: TRange; const item: Double): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Find(const ID: TRange; const item: string): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Find(const ID: TRange; const item: Char): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Find(const ID: TRange; const item: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Find(const ID: TRange; const item: TPoint): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Find(const ID: TRange; const item: TBox): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Find(const ID: TRange; const item: TRange): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Find1}

{$DEFINE TArray_Find2}
function TIntegerArrayHelper.Find(const ID: TIntegerArray; const item: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Find(const ID: TIntegerArray; const item: Double): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Find(const ID: TIntegerArray; const item: string): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Find(const ID: TIntegerArray; const item: Char): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Find(const ID: TIntegerArray; const item: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Find(const ID: TIntegerArray; const item: TPoint): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Find(const ID: TIntegerArray; const item: TBox): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Find(const ID: TIntegerArray; const item: TRange): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Find2}

{$DEFINE TArray_Find3}
function TIntegerArrayHelper.Find(const ID: TRange; const items: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Find(const ID: TRange; const items: TDoubleArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Find(const ID: TRange; const items: TStringArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Find(const ID: TRange; const items: TCharArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Find(const ID: TRange; const items: TBooleanArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Find(const ID: TRange; const items: TPointArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Find(const ID: TRange; const items: TBoxArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Find(const ID: TRange; const items: TRangeArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Find3}

{$DEFINE TArray_Find4}
function TIntegerArrayHelper.Find(const ID: TIntegerArray; const items: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Find(const ID: TIntegerArray; const items: TDoubleArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Find(const ID: TIntegerArray; const items: TStringArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Find(const ID: TIntegerArray; const items: TCharArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Find(const ID: TIntegerArray; const items: TBooleanArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Find(const ID: TIntegerArray; const items: TPointArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Find(const ID: TIntegerArray; const items: TBoxArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Find(const ID: TIntegerArray; const items: TRangeArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Find4}

{$DEFINE TArray_Flip}
function TIntegerArrayHelper.Flip: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Flip: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Flip: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Flip: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Flip: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Flip: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Flip: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Flip: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Flip}

{$DEFINE TArray_Get1}
function TIntegerArrayHelper.Get: TIntegerArray; overload; cdecl; var a: Integer; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Get: TDoubleArray; overload; cdecl; var a: Double; {$I MIMU\TArray.inc}
function TStringArrayHelper.Get: TStringArray; overload; cdecl; var a: string; {$I MIMU\TArray.inc}
function TCharArrayHelper.Get: TCharArray; overload; cdecl; var a: Char; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Get: TBooleanArray; overload; cdecl; var a: Boolean; {$I MIMU\TArray.inc}
function TPointArrayHelper.Get: TPointArray; overload; cdecl; var a: TPoint; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Get: TBoxArray; overload; cdecl; var a: TBox; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Get: TRangeArray; overload; cdecl; var a: TRange; {$I MIMU\TArray.inc}
{$UNDEF TArray_Get1}

{$DEFINE TArray_Get2}
function TIntegerArrayHelper.Get(const ID: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Get(const ID: TIntegerArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Get(const ID: TIntegerArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Get(const ID: TIntegerArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Get(const ID: TIntegerArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Get(const ID: TIntegerArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Get(const ID: TIntegerArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Get(const ID: TIntegerArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Get2}

{$DEFINE TArray_Get3}
function TIntegerArrayHelper.Get(const ID: TRange): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Get(const ID: TRange): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Get(const ID: TRange): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Get(const ID: TRange): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Get(const ID: TRange): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Get(const ID: TRange): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Get(const ID: TRange): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Get(const ID: TRange): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Get3}

{$DEFINE TArray_Group}
function TIntegerArrayHelper.Group: T2DIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Group: T2DDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Group: T2DStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Group: T2DCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Group: T2DBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Group: T2DPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Group: T2DBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Group: T2DRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Group}

{$DEFINE TArray_Holds}
function TIntegerArrayHelper.Holds(const chain: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Holds(const chain: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Holds(const chain: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Holds(const chain: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Holds(const chain: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Holds(const chain: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Holds(const chain: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Holds(const chain: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Holds}

{$DEFINE TArray_IDs1}
function TIntegerArrayHelper.IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_IDs1}

{$DEFINE TArray_IDs2}
function TIntegerArrayHelper.IDs(const ID: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.IDs(const ID: TIntegerArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.IDs(const ID: TIntegerArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.IDs(const ID: TIntegerArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.IDs(const ID: TIntegerArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.IDs(const ID: TIntegerArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.IDs(const ID: TIntegerArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.IDs(const ID: TIntegerArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_IDs2}

{$DEFINE TArray_IDs3}
function TIntegerArrayHelper.IDs(const ID: TIntegerArray; const item: Integer): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.IDs(const ID: TIntegerArray; const item: Double): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.IDs(const ID: TIntegerArray; const item: string): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.IDs(const ID: TIntegerArray; const item: Char): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.IDs(const ID: TIntegerArray; const item: Boolean): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.IDs(const ID: TIntegerArray; const item: TPoint): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.IDs(const ID: TIntegerArray; const item: TBox): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.IDs(const ID: TIntegerArray; const item: TRange): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_IDs3}

{$DEFINE TArray_IDs4}
function TIntegerArrayHelper.IDs(const ID: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.IDs(const ID: TIntegerArray; const items: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.IDs(const ID: TIntegerArray; const items: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.IDs(const ID: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.IDs(const ID: TIntegerArray; const items: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.IDs(const ID: TIntegerArray; const items: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.IDs(const ID: TIntegerArray; const items: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.IDs(const ID: TIntegerArray; const items: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_IDs4}

{$DEFINE TArray_Includes}
function TIntegerArrayHelper.Includes(const item: Integer; const index: Integer = 2147483647): Boolean; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Includes(const item: Double; const index: Integer = 2147483647): Boolean; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Includes(const item: string; const index: Integer = 2147483647): Boolean; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Includes(const item: Char; const index: Integer = 2147483647): Boolean; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Includes(const item: Boolean; const index: Integer = 2147483647): Boolean; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Includes(const item: TPoint; const index: Integer = 2147483647): Boolean; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Includes(const item: TBox; const index: Integer = 2147483647): Boolean; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Includes(const item: TRange; const index: Integer = 2147483647): Boolean; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Includes}

{$DEFINE TArray_Keep}
function TIntegerArrayHelper.Keep(const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Keep(const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Keep(const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Keep(const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Keep(const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Keep(const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Keep(const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Keep(const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Keep}

{$DEFINE TArray_LeastFrequent}
function TIntegerArrayHelper.LeastFrequent: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.LeastFrequent: Double; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.LeastFrequent: string; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.LeastFrequent: Char; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.LeastFrequent: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.LeastFrequent: TPoint; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.LeastFrequent: TBox; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.LeastFrequent: TRange; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_LeastFrequent}

{$DEFINE TArray_Len1}
function TIntegerArrayHelper.Len: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Len: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Len: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Len: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Len: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Len: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Len: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Len: Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Len1}

{$DEFINE TArray_Len2}
function TIntegerArrayHelper.Len(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Len(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Len(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Len(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Len(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Len(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Len(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Len(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Len2}

{$DEFINE TArray_Len3}
function TIntegerArrayHelper.Len(const aSize: Integer; const null: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Len(const aSize: Integer; const null: Double): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Len(const aSize: Integer; const null: string): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Len(const aSize: Integer; const null: Char): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Len(const aSize: Integer; const null: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Len(const aSize: Integer; const null: TPoint): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Len(const aSize: Integer; const null: TBox): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Len(const aSize: Integer; const null: TRange): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Len3}

{$DEFINE TArray_Location1}
function TIntegerArrayHelper.Location(const item: Integer; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Location(const item: Double; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Location(const item: string; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Location(const item: Char; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Location(const item: Boolean; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Location(const item: TPoint; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Location(const item: TBox; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Location(const item: TRange; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Location1}

{$DEFINE TArray_Location2}
function TIntegerArrayHelper.Location(const items: TIntegerArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Location(const items: TDoubleArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Location(const items: TStringArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Location(const items: TCharArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Location(const items: TBooleanArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Location(const items: TPointArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Location(const items: TBoxArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Location(const items: TRangeArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Location2}

{$DEFINE TArray_Locations1}
function TIntegerArrayHelper.Locations(const item: Integer; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Locations(const item: Double; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Locations(const item: string; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Locations(const item: Char; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Locations(const item: Boolean; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Locations(const item: TPoint; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Locations(const item: TBox; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Locations(const item: TRange; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Locations1}

{$DEFINE TArray_Locations2}
function TIntegerArrayHelper.Locations(const items: TIntegerArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Locations(const items: TDoubleArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Locations(const items: TStringArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Locations(const items: TCharArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Locations(const items: TBooleanArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Locations(const items: TPointArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Locations(const items: TBoxArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Locations(const items: TRangeArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Locations2}

{$DEFINE TArray_Mix}
function TIntegerArrayHelper.Mix(const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Mix(const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Mix(const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Mix(const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Mix(const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Mix(const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Mix(const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Mix(const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Mix}

{$DEFINE TArray_MostFrequent}
function TIntegerArrayHelper.MostFrequent: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.MostFrequent: Double; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.MostFrequent: string; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.MostFrequent: Char; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.MostFrequent: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.MostFrequent: TPoint; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.MostFrequent: TBox; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.MostFrequent: TRange; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_MostFrequent}

{$DEFINE TArray_Move}
function TIntegerArrayHelper.Move(const oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: Integer; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Move(const oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: Double; {$I MIMU\TArray.inc}
function TStringArrayHelper.Move(const oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: string; {$I MIMU\TArray.inc}
function TCharArrayHelper.Move(const oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: Char; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Move(const oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: Boolean; {$I MIMU\TArray.inc}
function TPointArrayHelper.Move(const oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: TPoint; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Move(const oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: TBox; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Move(const oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: TRange; {$I MIMU\TArray.inc}
{$UNDEF TArray_Move}

{$DEFINE TArray_Oversize}
function TIntegerArrayHelper.Oversize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Oversize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Oversize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Oversize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Oversize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Oversize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Oversize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Oversize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Oversize}

{$DEFINE TArray_Partition}
function TIntegerArrayHelper.Partition(const pSize: Integer): T2DIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Partition(const pSize: Integer): T2DDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Partition(const pSize: Integer): T2DStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Partition(const pSize: Integer): T2DCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Partition(const pSize: Integer): T2DBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Partition(const pSize: Integer): T2DPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Partition(const pSize: Integer): T2DBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Partition(const pSize: Integer): T2DRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Partition}

{$DEFINE TArray_Pick}
function TIntegerArrayHelper.Pick(const ID: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Pick(const ID: TIntegerArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Pick(const ID: TIntegerArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Pick(const ID: TIntegerArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Pick(const ID: TIntegerArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Pick(const ID: TIntegerArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Pick(const ID: TIntegerArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Pick(const ID: TIntegerArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Pick}

{$DEFINE TArray_Pop1}
function TIntegerArrayHelper.Pop: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Pop: Double; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Pop: string; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Pop: Char; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Pop: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Pop: TPoint; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Pop: TBox; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Pop: TRange; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Pop1}

{$DEFINE TArray_Pop2}
function TIntegerArrayHelper.Pop(const null: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Pop(const null: Double): Double; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Pop(const null: string): string; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Pop(const null: Char): Char; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Pop(const null: Boolean): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Pop(const null: TPoint): TPoint; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Pop(const null: TBox): TBox; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Pop(const null: TRange): TRange; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Pop2}

{$DEFINE TArray_Pos1}
function TArray_Pos(const arr: TIntegerArray; const item: Integer; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TDoubleArray; const item: Double; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TStringArray; const item: string; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TCharArray; const item: Char; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TPointArray; const item: TPoint; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TBoxArray; const item: TBox; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TRangeArray; const item: TRange; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Pos1}

{$DEFINE TArray_Pos2}
function TArray_Pos(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TStringArray; const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TCharArray; const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TPointArray; const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Pos2}

{$DEFINE TArray_Position1}
function TIntegerArrayHelper.Position(const item: Integer; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Position(const item: Double; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Position(const item: string; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Position(const item: Char; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Position(const item: Boolean; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Position(const item: TPoint; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Position(const item: TBox; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Position(const item: TRange; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Position1}

{$DEFINE TArray_Position2}
function TIntegerArrayHelper.Position(const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Position(const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Position(const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Position(const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Position(const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Position(const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Position(const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Position(const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Position2}

{$DEFINE TArray_Positions1}
function TIntegerArrayHelper.Positions(const item: Integer; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Positions(const item: Double; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Positions(const item: string; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Positions(const item: Char; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Positions(const item: Boolean; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Positions(const item: TPoint; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Positions(const item: TBox; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Positions(const item: TRange; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Positions1}

{$DEFINE TArray_Positions2}
function TIntegerArrayHelper.Positions(const items: TIntegerArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Positions(const items: TDoubleArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Positions(const items: TStringArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Positions(const items: TCharArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Positions(const items: TBooleanArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Positions(const items: TPointArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Positions(const items: TBoxArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Positions(const items: TRangeArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Positions2}

{$DEFINE TArray_Push1}
function TIntegerArrayHelper.Push(const item: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Push(const item: Double): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Push(const item: string): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Push(const item: Char): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Push(const item: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Push(const item: TPoint): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Push(const item: TBox): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Push(const item: TRange): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Push1}

{$DEFINE TArray_Push2}
function TIntegerArrayHelper.Push(const items: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Push(const items: TDoubleArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Push(const items: TStringArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Push(const items: TCharArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Push(const items: TBooleanArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Push(const items: TPointArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Push(const items: TBoxArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Push(const items: TRangeArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Push2}

{$DEFINE TArray_Put1}
function TIntegerArrayHelper.Put(const ID: TIntegerArray; const item: Integer): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Put(const ID: TIntegerArray; const item: Double): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Put(const ID: TIntegerArray; const item: string): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Put(const ID: TIntegerArray; const item: Char): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Put(const ID: TIntegerArray; const item: Boolean): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Put(const ID: TIntegerArray; const item: TPoint): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Put(const ID: TIntegerArray; const item: TBox): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Put(const ID: TIntegerArray; const item: TRange): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Put1}

{$DEFINE TArray_Put2}
function TIntegerArrayHelper.Put(const ID: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Put(const ID: TIntegerArray; const items: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Put(const ID: TIntegerArray; const items: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Put(const ID: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Put(const ID: TIntegerArray; const items: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Put(const ID: TIntegerArray; const items: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Put(const ID: TIntegerArray; const items: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Put(const ID: TIntegerArray; const items: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Put2}

{$DEFINE TArray_Put3}
function TIntegerArrayHelper.Put(const index: Integer; const items: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Put(const index: Integer; const items: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Put(const index: Integer; const items: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Put(const index: Integer; const items: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Put(const index: Integer; const items: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Put(const index: Integer; const items: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Put(const index: Integer; const items: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Put(const index: Integer; const items: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Put3}

{$DEFINE TArray_Remove1}
function TIntegerArrayHelper.Remove(const item: Integer; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Remove(const item: Double; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Remove(const item: string; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Remove(const item: Char; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Remove(const item: Boolean; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Remove(const item: TPoint; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Remove(const item: TBox; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Remove(const item: TRange; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Remove1}

{$DEFINE TArray_Remove2}
function TIntegerArrayHelper.Remove(const item: Integer; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Remove(const item: Double; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Remove(const item: string; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Remove(const item: Char; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Remove(const item: Boolean; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Remove(const item: TPoint; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Remove(const item: TBox; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Remove(const item: TRange; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Remove2}

{$DEFINE TArray_Remove3}
function TIntegerArrayHelper.Remove(const items: TIntegerArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Remove(const items: TDoubleArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Remove(const items: TStringArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Remove(const items: TCharArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Remove(const items: TBooleanArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Remove(const items: TPointArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Remove(const items: TBoxArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Remove(const items: TRangeArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Remove3}

{$DEFINE TArray_Remove4}
function TIntegerArrayHelper.Remove(const items: TIntegerArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Remove(const items: TDoubleArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Remove(const items: TStringArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Remove(const items: TCharArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Remove(const items: TBooleanArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Remove(const items: TPointArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Remove(const items: TBoxArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Remove(const items: TRangeArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Remove4}

{$DEFINE TArray_Resize1}
function TIntegerArrayHelper.Resize(const aChange: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Resize(const aChange: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Resize(const aChange: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Resize(const aChange: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Resize(const aChange: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Resize(const aChange: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Resize(const aChange: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Resize(const aChange: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Resize1}

{$DEFINE TArray_Resize2}
function TIntegerArrayHelper.Resize(const aChange: Integer; const null: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Resize(const aChange: Integer; const null: Double): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Resize(const aChange: Integer; const null: string): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Resize(const aChange: Integer; const null: Char): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Resize(const aChange: Integer; const null: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Resize(const aChange: Integer; const null: TPoint): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Resize(const aChange: Integer; const null: TBox): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Resize(const aChange: Integer; const null: TRange): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Resize2}

{$DEFINE TArray_Reverse}
function TIntegerArrayHelper.Reverse: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Reverse: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Reverse: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Reverse: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Reverse: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Reverse: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Reverse: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Reverse: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Reverse}

{$DEFINE TArray_Reversed}
function TIntegerArrayHelper.Reversed: TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Reversed: TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Reversed: TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Reversed: TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Reversed: TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Reversed: TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Reversed: TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Reversed: TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Reversed}

{$DEFINE TArray_Scan1}
function TIntegerArrayHelper.Scan(const ID: TRange; const item: Integer; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Scan(const ID: TRange; const item: Double; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Scan(const ID: TRange; const item: string; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Scan(const ID: TRange; const item: Char; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Scan(const ID: TRange; const item: Boolean; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Scan(const ID: TRange; const item: TPoint; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Scan(const ID: TRange; const item: TBox; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Scan(const ID: TRange; const item: TRange; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Scan1}

{$DEFINE TArray_Scan2}
function TIntegerArrayHelper.Scan(const ID: TIntegerArray; const item: Integer; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Scan(const ID: TIntegerArray; const item: Double; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Scan(const ID: TIntegerArray; const item: string; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Scan(const ID: TIntegerArray; const item: Char; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Scan(const ID: TIntegerArray; const item: Boolean; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Scan(const ID: TIntegerArray; const item: TPoint; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Scan(const ID: TIntegerArray; const item: TBox; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Scan(const ID: TIntegerArray; const item: TRange; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Scan2}

{$DEFINE TArray_Scan3}
function TIntegerArrayHelper.Scan(const ID: TRange; const items: TIntegerArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Scan(const ID: TRange; const items: TDoubleArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Scan(const ID: TRange; const items: TStringArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Scan(const ID: TRange; const items: TCharArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Scan(const ID: TRange; const items: TBooleanArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Scan(const ID: TRange; const items: TPointArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Scan(const ID: TRange; const items: TBoxArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Scan(const ID: TRange; const items: TRangeArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Scan3}

{$DEFINE TArray_Scan4}
function TIntegerArrayHelper.Scan(const ID: TIntegerArray; const items: TIntegerArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Scan(const ID: TIntegerArray; const items: TDoubleArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Scan(const ID: TIntegerArray; const items: TStringArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Scan(const ID: TIntegerArray; const items: TCharArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Scan(const ID: TIntegerArray; const items: TBooleanArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Scan(const ID: TIntegerArray; const items: TPointArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Scan(const ID: TIntegerArray; const items: TBoxArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Scan(const ID: TIntegerArray; const items: TRangeArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Scan4}

{$DEFINE TArray_Shift1}
function TIntegerArrayHelper.Shift: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Shift: Double; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Shift: string; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Shift: Char; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Shift: Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Shift: TPoint; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Shift: TBox; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Shift: TRange; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Shift1}

{$DEFINE TArray_Shift2}
function TIntegerArrayHelper.Shift(const sCount: Integer): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Shift(const sCount: Integer): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Shift(const sCount: Integer): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Shift(const sCount: Integer): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Shift(const sCount: Integer): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Shift( const sCount: Integer): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Shift(const sCount: Integer): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Shift(const sCount: Integer): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Shift2}

{$DEFINE TArray_Size1}
function TIntegerArrayHelper.Size(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Size(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Size(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Size(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Size(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Size(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Size(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Size(const aSize: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Size1}

{$DEFINE TArray_Size2}
function TIntegerArrayHelper.Size: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Size: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Size: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Size: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Size: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Size: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Size: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Size: Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Size2}

{$DEFINE TArray_SizeBetween}
function TIntegerArrayHelper.SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_SizeBetween}

{$DEFINE TArray_SizeMax}
function TIntegerArrayHelper.SizeMax(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.SizeMax(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.SizeMax(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.SizeMax(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.SizeMax(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.SizeMax(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.SizeMax(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.SizeMax(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_SizeMax}

{$DEFINE TArray_SizeMin}
function TIntegerArrayHelper.SizeMin(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.SizeMin(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.SizeMin(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.SizeMin(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.SizeMin(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.SizeMin(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.SizeMin(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.SizeMin(const target: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_SizeMin}

{$DEFINE TArray_Swap1}
function TIntegerArrayHelper.Swap(const aIndex, bIndex: Integer): Boolean; overload; cdecl; var c: Integer; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Swap(const aIndex, bIndex: Integer): Boolean; overload; cdecl; var c: Double; {$I MIMU\TArray.inc}
function TStringArrayHelper.Swap(const aIndex, bIndex: Integer): Boolean; overload; cdecl; var c: string; {$I MIMU\TArray.inc}
function TCharArrayHelper.Swap(const aIndex, bIndex: Integer): Boolean; overload; cdecl; var c: Char; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Swap(const aIndex, bIndex: Integer): Boolean; overload; cdecl; var c: Boolean; {$I MIMU\TArray.inc}
function TPointArrayHelper.Swap(const aIndex, bIndex: Integer): Boolean; overload; cdecl; var c: TPoint; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Swap(const aIndex, bIndex: Integer): Boolean; overload; cdecl; var c: TBox; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Swap(const aIndex, bIndex: Integer): Boolean; overload; cdecl; var c: TRange; {$I MIMU\TArray.inc}
{$UNDEF TArray_Swap1}

{$DEFINE TArray_Swap2}
function TIntegerArrayHelper.Swap(var b: TIntegerArray): Integer; overload; cdecl; var a: TIntegerArray; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Swap(var b: TDoubleArray): Integer; overload; cdecl; var a: TDoubleArray; {$I MIMU\TArray.inc}
function TStringArrayHelper.Swap(var b: TStringArray): Integer; overload; cdecl; var a: TStringArray; {$I MIMU\TArray.inc}
function TCharArrayHelper.Swap(var b: TCharArray): Integer; overload; cdecl; var a: TCharArray; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Swap(var b: TBooleanArray): Integer; overload; cdecl; var a: TBooleanArray; {$I MIMU\TArray.inc}
function TPointArrayHelper.Swap(var b: TPointArray): Integer; overload; cdecl; var a: TPointArray; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Swap(var b: TBoxArray): Integer; overload; cdecl; var a: TBoxArray; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Swap(var b: TRangeArray): Integer; overload; cdecl; var a: TRangeArray; {$I MIMU\TArray.inc}
{$UNDEF TArray_Swap2}

{$DEFINE TArray_Trade}
function TIntegerArrayHelper.Trade(var b: TIntegerArray): Integer; overload; cdecl; var a: TIntegerArray; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Trade(var b: TDoubleArray): Integer; overload; cdecl; var a: TDoubleArray; {$I MIMU\TArray.inc}
function TStringArrayHelper.Trade(var b: TStringArray): Integer; overload; cdecl; var a: TStringArray; {$I MIMU\TArray.inc}
function TCharArrayHelper.Trade(var b: TCharArray): Integer; overload; cdecl; var a: TCharArray; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Trade(var b: TBooleanArray): Integer; overload; cdecl; var a: TBooleanArray; {$I MIMU\TArray.inc}
function TPointArrayHelper.Trade(var b: TPointArray): Integer; overload; cdecl; var a: TPointArray; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Trade(var b: TBoxArray): Integer; overload; cdecl; var a: TBoxArray; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Trade(var b: TRangeArray): Integer; overload; cdecl; var a: TRangeArray; {$I MIMU\TArray.inc}
{$UNDEF TArray_Trade}

{$DEFINE TArray_Undersize}
function TIntegerArrayHelper.Undersize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Undersize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Undersize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Undersize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Undersize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Undersize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Undersize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Undersize(const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Undersize}

{$DEFINE TArray_Unique}
function TIntegerArrayHelper.Unique: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Unique: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Unique: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Unique: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Unique: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Unique: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Unique: Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Unique: Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Unique}

{$DEFINE TArray_Uniqued}
function TIntegerArrayHelper.Uniqued: TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Uniqued: TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Uniqued: TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Uniqued: TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Uniqued: TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Uniqued: TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Uniqued: TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Uniqued: TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Uniqued}

{$DEFINE TArray_Uniques}
function TIntegerArrayHelper.Uniques: TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Uniques: TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Uniques: TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Uniques: TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Uniques: TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Uniques: TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Uniques: TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Uniques: TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Uniques}

{$DEFINE TArray_Unshift1}
function TIntegerArrayHelper.Unshift(const item: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Unshift(const item: Double): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Unshift(const item: string): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Unshift(const item: Char): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Unshift(const item: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Unshift(const item: TPoint): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Unshift(const item: TBox): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Unshift(const item: TRange): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Unshift1}

{$DEFINE TArray_Unshift2}
function TIntegerArrayHelper.Unshift(const items: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TDoubleArrayHelper.Unshift(const items: TDoubleArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TStringArrayHelper.Unshift(const items: TStringArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TCharArrayHelper.Unshift(const items: TCharArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBooleanArrayHelper.Unshift(const items: TBooleanArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TPointArrayHelper.Unshift(const items: TPointArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TBoxArrayHelper.Unshift(const items: TBoxArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TRangeArrayHelper.Unshift(const items: TRangeArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Unshift2}

{$DEFINE T2DArray_Blank}
function T2DArray_Blank(const arr: T2DIntegerArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Blank(const arr: T2DDoubleArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Blank(const arr: T2DStringArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Blank(const arr: T2DCharArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Blank(const arr: T2DBooleanArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Blank(const arr: T2DPointArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Blank(const arr: T2DBoxArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Blank(const arr: T2DRangeArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
{$UNDEF T2DArray_Blank}

{$DEFINE T2DArray_Create}
function T2DArray_Create(const size1D, size2D: Integer; const item: Integer): T2DIntegerArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Create(const size1D, size2D: Integer; const item: Double): T2DDoubleArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Create(const size1D, size2D: Integer; const item: string): T2DStringArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Create(const size1D, size2D: Integer; const item: Char): T2DCharArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Create(const size1D, size2D: Integer; const item: Boolean): T2DBooleanArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Create(const size1D, size2D: Integer; const item: TPoint): T2DPointArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Create(const size1D, size2D: Integer; const item: TBox): T2DBoxArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Create(const size1D, size2D: Integer; const item: TRange): T2DRangeArray; overload; cdecl; {$I MIMU\T2DArray.inc}
{$UNDEF T2DArray_Create}

{$DEFINE T2DArray_Empty}
function T2DArray_Empty(const arr: T2DIntegerArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Empty(const arr: T2DDoubleArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Empty(const arr: T2DStringArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Empty(const arr: T2DCharArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Empty(const arr: T2DBooleanArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Empty(const arr: T2DPointArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Empty(const arr: T2DBoxArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Empty(const arr: T2DRangeArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
{$UNDEF T2DArray_Empty}

{$DEFINE T2DArray_Length1}
function T2DArray_Length(const arr: T2DIntegerArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DDoubleArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DStringArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DCharArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DBooleanArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DPointArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DBoxArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DRangeArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
{$UNDEF T2DArray_Length1}

{$DEFINE T2DArray_Length2}
function T2DArray_Length(const arr: T2DIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DDoubleArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DStringArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DCharArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DBooleanArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DPointArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DBoxArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DRangeArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
{$UNDEF T2DArray_Length2}

{$DEFINE T2DArray_Merge}
function T2DArray_Merge(const arr: T2DIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Merge(const arr: T2DDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Merge(const arr: T2DStringArray): TStringArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Merge(const arr: T2DCharArray): TCharArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Merge(const arr: T2DBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Merge(const arr: T2DPointArray): TPointArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Merge(const arr: T2DBoxArray): TBoxArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Merge(const arr: T2DRangeArray): TRangeArray; overload; cdecl; {$I MIMU\T2DArray.inc}
{$UNDEF T2DArray_Merge}
