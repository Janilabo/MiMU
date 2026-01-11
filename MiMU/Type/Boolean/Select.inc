{$IFDEF HELPERS}
function Evaluate(const bTrue, bFalse: Integer): Integer; overload;
function Evaluate(const bTrue, bFalse: Double): Double; overload;
function Evaluate(const bTrue, bFalse: string): string; overload;
function Evaluate(const bTrue, bFalse: Char): Char; overload;
function Evaluate(const bTrue, bFalse: Boolean): Boolean; overload;
function Evaluate(const bTrue, bFalse: TPoint): TPoint; overload;
function Evaluate(const bTrue, bFalse: TBox): TBox; overload;
function Evaluate(const bTrue, bFalse: TRange): TRange; overload;
function Evaluate(const bTrue, bFalse: TConnection): TConnection; overload;
function Evaluate(const bTrue, bFalse: TSegment): TSegment; overload;
function Evaluate(const bTrue, bFalse: TTriangle): TTriangle; overload;
function Evaluate(const bTrue, bFalse: TCircle): TCircle; overload;
function Evaluate(const bTrue, bFalse: Int64): Int64; overload;

function Select(const bTrue, bFalse: Integer): Integer; overload;
function Select(const bTrue, bFalse: Double): Double; overload;
function Select(const bTrue, bFalse: string): string; overload;
function Select(const bTrue, bFalse: Char): Char; overload;
function Select(const bTrue, bFalse: Boolean): Boolean; overload;
function Select(const bTrue, bFalse: TPoint): TPoint; overload;
function Select(const bTrue, bFalse: TBox): TBox; overload;
function Select(const bTrue, bFalse: TRange): TRange; overload;
function Select(const bTrue, bFalse: TConnection): TConnection; overload;
function Select(const bTrue, bFalse: TSegment): TSegment; overload;
function Select(const bTrue, bFalse: TTriangle): TTriangle; overload;
function Select(const bTrue, bFalse: TCircle): TCircle; overload;
function Select(const bTrue, bFalse: Int64): Int64; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Evaluate>
  @action: If (Self = True) then Result := bTrue else Result := bFalse;
  @note: Returns bTrue or bFalse based on the Self-condition.
[==============================================================================}

function TBooleanHelper.Evaluate(const bTrue, bFalse: Integer): Integer; overload; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Double): Double; overload; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: string): string; overload; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Char): Char; overload; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Boolean): Boolean; overload; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TPoint): TPoint; overload; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TBox): TBox; overload; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TRange): TRange; overload; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TConnection): TConnection; overload; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TSegment): TSegment; overload; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TTriangle): TTriangle; overload; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TCircle): TCircle; overload; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Int64): Int64; overload;
begin
  case Self of
    True: Result := bTrue;
    False: Result := bFalse;
  end;
end;

{==============================================================================]
  <Select>
  @action: If (Self = True) then Result := bTrue else Result := bFalse; 
  @note: Returns T or F based on the Self-condition.
[==============================================================================}

function TBooleanHelper.Select(const bTrue, bFalse: Integer): Integer; overload; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: Double): Double; overload; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: string): string; overload; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: Char): Char; overload; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: Boolean): Boolean; overload; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TPoint): TPoint; overload; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TBox): TBox; overload; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TRange): TRange; overload; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TConnection): TConnection; overload; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TSegment): TSegment; overload; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TTriangle): TTriangle; overload; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TCircle): TCircle; overload; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: Int64): Int64; overload;
begin
  if Self then
    Result := bTrue
  else
    Result := bFalse;
end;
{$ENDIF}
