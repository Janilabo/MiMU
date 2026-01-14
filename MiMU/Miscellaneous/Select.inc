{$IFDEF FUNCTIONS}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Integer): Integer; overload; cdecl;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Double): Double; overload; cdecl;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: string): string; overload; cdecl;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Char): Char; overload; cdecl;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Boolean): Boolean; overload; cdecl;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TPoint): TPoint; overload; cdecl;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TBox): TBox; overload; cdecl;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TRange): TRange; overload; cdecl;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TConnection): TConnection; overload; cdecl;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TSegment): TSegment; overload; cdecl;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TTriangle): TTriangle; overload; cdecl;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TCircle): TCircle; overload; cdecl;
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Int64): Int64; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <IfThenElse>
  @action: Returns one of three possible results depending on two Boolean conditions.
  @note: Evaluates aBool first, then bBool, returning aResult, bResult, or cResult accordingly.
[==============================================================================}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Integer): Integer; overload; cdecl; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Double): Double; overload; cdecl; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: string): string; overload; cdecl; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Char): Char; overload; cdecl; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Boolean): Boolean; overload; cdecl; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TPoint): TPoint; overload; cdecl; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TBox): TBox; overload; cdecl; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TRange): TRange; overload; cdecl; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TConnection): TConnection; overload; cdecl; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TSegment): TSegment; overload; cdecl; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TTriangle): TTriangle; overload; cdecl; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: TCircle): TCircle; overload; cdecl; {$I Skeletons/IfThenElse.inc}
function IfThenElse(const aBool, bBool: Boolean; const aResult, bResult, cResult: Int64): Int64; overload; cdecl;
begin
  if aBool then
    Result := aResult
  else if bBool then
    Result := bResult
  else
    Result := cResult;
end;
{$ENDIF}
