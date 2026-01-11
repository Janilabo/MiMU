{$IFDEF FUNCTIONS}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Integer): Integer; overload;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Double): Double; overload;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: string): string; overload;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Char): Char; overload;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Boolean): Boolean; overload;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TPoint): TPoint; overload;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TBox): TBox; overload;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TRange): TRange; overload;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TConnection): TConnection; overload;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TSegment): TSegment; overload;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TTriangle): TTriangle; overload;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TCircle): TCircle; overload;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Int64): Int64; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IfThenElse>
  @action: Returns one of three possible results depending on two Boolean conditions.
  @note: Evaluates aBool first, then bBool, returning aResult, bResult, or cResult accordingly.
[==============================================================================}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Integer): Integer; overload; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Double): Double; overload; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: string): string; overload; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Char): Char; overload; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Boolean): Boolean; overload; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TPoint): TPoint; overload; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TBox): TBox; overload; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TRange): TRange; overload; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TConnection): TConnection; overload; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TSegment): TSegment; overload; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TTriangle): TTriangle; overload; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TCircle): TCircle; overload; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Int64): Int64; overload;
begin
  if aBool then
    Result := aResult
  else if bBool then
    Result := bResult
  else
    Result := cResult;
end;
{$ENDIF}
