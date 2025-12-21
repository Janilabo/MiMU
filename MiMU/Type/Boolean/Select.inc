{$IFDEF HELPERS}
function Select(const bTrue, bFalse: Integer): Integer; overload;
function Select(const bTrue, bFalse: Int64): Int64; overload;
function Select(const bTrue, bFalse: Double): Double; overload;
function Select(const bTrue, bFalse: string): string; overload;
function Select(const bTrue, bFalse: Char): Char; overload;
function Select(const bTrue, bFalse: Boolean): Boolean; overload;
function Select(const bTrue, bFalse: TPoint): TPoint; overload;
function Select(const bTrue, bFalse: TBox): TBox; overload;
function Select(const bTrue, bFalse: TRange): TRange; overload;
function Evaluate(const bTrue, bFalse: Integer): Integer; overload;
function Evaluate(const bTrue, bFalse: Int64): Int64; overload;
function Evaluate(const bTrue, bFalse: Double): Double; overload;
function Evaluate(const bTrue, bFalse: string): string; overload;
function Evaluate(const bTrue, bFalse: Char): Char; overload;
function Evaluate(const bTrue, bFalse: Boolean): Boolean; overload;
function Evaluate(const bTrue, bFalse: TPoint): TPoint; overload;
function Evaluate(const bTrue, bFalse: TBox): TBox; overload;
function Evaluate(const bTrue, bFalse: TRange): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Select>
  @action: If (Self = True) then Result := bTrue else Result := bFalse; 
  @note: Returns T or F based on the Self-condition.
[==============================================================================}

function TBooleanHelper.Select(const bTrue, bFalse: Integer): Integer; overload; {$DEFINE Skeleton_Select}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: Int64): Int64; overload; {$DEFINE Skeleton_Select}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: Double): Double; overload; {$DEFINE Skeleton_Select}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: string): string; overload; {$DEFINE Skeleton_Select}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: Char): Char; overload; {$DEFINE Skeleton_Select}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: Boolean): Boolean; overload; {$DEFINE Skeleton_Select}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: TPoint): TPoint; overload; {$DEFINE Skeleton_Select}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: TBox): TBox; overload; {$DEFINE Skeleton_Select}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: TRange): TRange; overload; {$DEFINE Skeleton_Select}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Select}

{==============================================================================]
  <Evaluate>
  @action: If (Self = True) then Result := bTrue else Result := bFalse;
  @note: Returns bTrue or bFalse based on the Self-condition.
[==============================================================================}

function TBooleanHelper.Evaluate(const bTrue, bFalse: Integer): Integer; overload; {$DEFINE Skeleton_Evaluate}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Int64): Int64; overload; {$DEFINE Skeleton_Evaluate}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Double): Double; overload; {$DEFINE Skeleton_Evaluate}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: string): string; overload; {$DEFINE Skeleton_Evaluate}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Char): Char; overload; {$DEFINE Skeleton_Evaluate}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Boolean): Boolean; overload; {$DEFINE Skeleton_Evaluate}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TPoint): TPoint; overload; {$DEFINE Skeleton_Evaluate}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TBox): TBox; overload; {$DEFINE Skeleton_Evaluate}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TRange): TRange; overload; {$DEFINE Skeleton_Evaluate}{$I ../Configuration/Skeletons.inc}{$UNDEF Skeleton_Evaluate}
{$ENDIF}