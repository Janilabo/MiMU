{$IFDEF HELPERS}
function Select(const sTrue, sFalse: Integer): TIntegerArray; overload;
function Select(const sTrue, sFalse: Double): TDoubleArray; overload;
function Select(const sTrue, sFalse: string): TStringArray; overload;
function Select(const sTrue, sFalse: Char): TCharArray; overload;
function Select(const sTrue, sFalse: Boolean): TBooleanArray; overload;
function Select(const sTrue, sFalse: TPoint): TPointArray; overload;
function Select(const sTrue, sFalse: TBox): TBoxArray; overload;
function Select(const sTrue, sFalse: TRange): TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Select>
  @action: IfThen method for TBooleanArray.
  @note: [True, False, True] => 5.
[==============================================================================}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Integer): TIntegerArray; overload; {$DEFINE Skeleton_Select2}{$I ../Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Double): TDoubleArray; overload; {$DEFINE Skeleton_Select2}{$I ../Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: string): TStringArray; overload; {$DEFINE Skeleton_Select2}{$I ../Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Char): TCharArray; overload; {$DEFINE Skeleton_Select2}{$I ../Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Boolean): TBooleanArray; overload; {$DEFINE Skeleton_Select2}{$I ../Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TPoint): TPointArray; overload; {$DEFINE Skeleton_Select2}{$I ../Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TBox): TBoxArray; overload; {$DEFINE Skeleton_Select2}{$I ../Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TRange): TRangeArray; overload; {$DEFINE Skeleton_Select2}{$I ../Skeletons.inc}{$UNDEF Skeleton_Select2}
{$ENDIF}
