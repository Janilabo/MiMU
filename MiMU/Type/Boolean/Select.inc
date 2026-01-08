{$IFDEF HELPERS}
function Evaluate(const bTrue, bFalse: Integer): Integer; overload; cdecl;
function Evaluate(const bTrue, bFalse: Int64): Int64; overload; cdecl;
function Evaluate(const bTrue, bFalse: Double): Double; overload; cdecl;
function Evaluate(const bTrue, bFalse: string): string; overload; cdecl;
function Evaluate(const bTrue, bFalse: Char): Char; overload; cdecl;
function Evaluate(const bTrue, bFalse: Boolean): Boolean; overload; cdecl;
function Evaluate(const bTrue, bFalse: TPoint): TPoint; overload; cdecl;
function Evaluate(const bTrue, bFalse: TBox): TBox; overload; cdecl;
function Evaluate(const bTrue, bFalse: TRange): TRange; overload; cdecl;
function Select(const bTrue, bFalse: Integer): Integer; overload; cdecl;
function Select(const bTrue, bFalse: Int64): Int64; overload; cdecl;
function Select(const bTrue, bFalse: Double): Double; overload; cdecl;
function Select(const bTrue, bFalse: string): string; overload; cdecl;
function Select(const bTrue, bFalse: Char): Char; overload; cdecl;
function Select(const bTrue, bFalse: Boolean): Boolean; overload; cdecl;
function Select(const bTrue, bFalse: TPoint): TPoint; overload; cdecl;
function Select(const bTrue, bFalse: TBox): TBox; overload; cdecl;
function Select(const bTrue, bFalse: TRange): TRange; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Evaluate>
  @action: If (Self = True) then Result := bTrue else Result := bFalse;
  @note: Returns bTrue or bFalse based on the Self-condition.
[==============================================================================}

function TBooleanHelper.Evaluate(const bTrue, bFalse: Integer): Integer; overload; cdecl; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Int64): Int64; overload; cdecl; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Double): Double; overload; cdecl; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: string): string; overload; cdecl; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Char): Char; overload; cdecl; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Boolean): Boolean; overload; cdecl; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TPoint): TPoint; overload; cdecl; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TBox): TBox; overload; cdecl; {$I Skeletons/Evaluate.inc}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TRange): TRange; overload; cdecl;
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

function TBooleanHelper.Select(const bTrue, bFalse: Integer): Integer; overload; cdecl; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: Int64): Int64; overload; cdecl; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: Double): Double; overload; cdecl; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: string): string; overload; cdecl; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: Char): Char; overload; cdecl; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: Boolean): Boolean; overload; cdecl; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TPoint): TPoint; overload; cdecl; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TBox): TBox; overload; cdecl; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TRange): TRange; overload; cdecl;
begin
  if Self then
    Result := bTrue
  else
    Result := bFalse;
end;
{$ENDIF}