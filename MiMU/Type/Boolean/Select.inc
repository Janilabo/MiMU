{$IFDEF HELPERS}
function Choice(const bTrue, bFalse: Integer): Integer; overload;
function Choice(const bTrue, bFalse: Double): Double; overload;
function Choice(const bTrue, bFalse: string): string; overload;
function Choice(const bTrue, bFalse: Char): Char; overload;
function Choice(const bTrue, bFalse: Boolean): Boolean; overload;
function Choice(const bTrue, bFalse: TPoint): TPoint; overload;
function Choice(const bTrue, bFalse: TBox): TBox; overload;
function Choice(const bTrue, bFalse: TRange): TRange; overload;
function Choice(const bTrue, bFalse: TConnection): TConnection; overload;
function Choice(const bTrue, bFalse: TSegment): TSegment; overload;
function Choice(const bTrue, bFalse: TTriangle): TTriangle; overload;
function Choice(const bTrue, bFalse: TCircle): TCircle; overload;
function Choice(const bTrue, bFalse: Int64): Int64; overload;

function Choose(const bTrue, bFalse: Integer): Integer; overload;
function Choose(const bTrue, bFalse: Double): Double; overload;
function Choose(const bTrue, bFalse: string): string; overload;
function Choose(const bTrue, bFalse: Char): Char; overload;
function Choose(const bTrue, bFalse: Boolean): Boolean; overload;
function Choose(const bTrue, bFalse: TPoint): TPoint; overload;
function Choose(const bTrue, bFalse: TBox): TBox; overload;
function Choose(const bTrue, bFalse: TRange): TRange; overload;
function Choose(const bTrue, bFalse: TConnection): TConnection; overload;
function Choose(const bTrue, bFalse: TSegment): TSegment; overload;
function Choose(const bTrue, bFalse: TTriangle): TTriangle; overload;
function Choose(const bTrue, bFalse: TCircle): TCircle; overload;
function Choose(const bTrue, bFalse: Int64): Int64; overload;

function Decide(const bTrue, bFalse: Integer): Integer; overload;
function Decide(const bTrue, bFalse: Double): Double; overload;
function Decide(const bTrue, bFalse: string): string; overload;
function Decide(const bTrue, bFalse: Char): Char; overload;
function Decide(const bTrue, bFalse: Boolean): Boolean; overload;
function Decide(const bTrue, bFalse: TPoint): TPoint; overload;
function Decide(const bTrue, bFalse: TBox): TBox; overload;
function Decide(const bTrue, bFalse: TRange): TRange; overload;
function Decide(const bTrue, bFalse: TConnection): TConnection; overload;
function Decide(const bTrue, bFalse: TSegment): TSegment; overload;
function Decide(const bTrue, bFalse: TTriangle): TTriangle; overload;
function Decide(const bTrue, bFalse: TCircle): TCircle; overload;
function Decide(const bTrue, bFalse: Int64): Int64; overload;

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

function IfThen(const bTrue, bFalse: Integer): Integer; overload;
function IfThen(const bTrue, bFalse: Double): Double; overload;
function IfThen(const bTrue, bFalse: string): string; overload;
function IfThen(const bTrue, bFalse: Char): Char; overload;
function IfThen(const bTrue, bFalse: Boolean): Boolean; overload;
function IfThen(const bTrue, bFalse: TPoint): TPoint; overload;
function IfThen(const bTrue, bFalse: TBox): TBox; overload;
function IfThen(const bTrue, bFalse: TRange): TRange; overload;
function IfThen(const bTrue, bFalse: TConnection): TConnection; overload;
function IfThen(const bTrue, bFalse: TSegment): TSegment; overload;
function IfThen(const bTrue, bFalse: TTriangle): TTriangle; overload;
function IfThen(const bTrue, bFalse: TCircle): TCircle; overload;
function IfThen(const bTrue, bFalse: Int64): Int64; overload;

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
  <Choice>
  @action: Selects and returns one of two values based on a Boolean state 
           without using conditional branching (if-then-else).
  @note: Uses an array of pointers for maximizing speed.
[==============================================================================}
function TBooleanHelper.Choice(const bTrue, bFalse: Integer): Integer; overload; var P: array[Boolean] of PInteger; {$I Skeletons/Choice.inc}
function TBooleanHelper.Choice(const bTrue, bFalse: Double): Double; overload; var P: array[Boolean] of PDouble; {$I Skeletons/Choice.inc}
function TBooleanHelper.Choice(const bTrue, bFalse: string): string; overload; var P: array[Boolean] of PString; {$I Skeletons/Choice.inc}
function TBooleanHelper.Choice(const bTrue, bFalse: Char): Char; overload; var P: array[Boolean] of PChar; {$I Skeletons/Choice.inc}
function TBooleanHelper.Choice(const bTrue, bFalse: Boolean): Boolean; overload; var P: array[Boolean] of PBoolean; {$I Skeletons/Choice.inc}
function TBooleanHelper.Choice(const bTrue, bFalse: TPoint): TPoint; overload; var P: array[Boolean] of PPoint; {$I Skeletons/Choice.inc}
function TBooleanHelper.Choice(const bTrue, bFalse: TBox): TBox; overload; var P: array[Boolean] of PBox; {$I Skeletons/Choice.inc}
function TBooleanHelper.Choice(const bTrue, bFalse: TRange): TRange; overload; var P: array[Boolean] of PRange; {$I Skeletons/Choice.inc}
function TBooleanHelper.Choice(const bTrue, bFalse: TConnection): TConnection; overload; var P: array[Boolean] of PConnection; {$I Skeletons/Choice.inc}
function TBooleanHelper.Choice(const bTrue, bFalse: TSegment): TSegment; overload; var P: array[Boolean] of PSegment; {$I Skeletons/Choice.inc}
function TBooleanHelper.Choice(const bTrue, bFalse: TTriangle): TTriangle; overload; var P: array[Boolean] of PTriangle; {$I Skeletons/Choice.inc}
function TBooleanHelper.Choice(const bTrue, bFalse: TCircle): TCircle; overload; var P: array[Boolean] of PCircle; {$I Skeletons/Choice.inc}
function TBooleanHelper.Choice(const bTrue, bFalse: Int64): Int64; overload;
var
  P: array[Boolean] of PInt64;
begin
  P[False] := @bFalse;
  P[True] := @bTrue;
  Result := P[Self]^;
end;

{==============================================================================]
  <Choice>
  @action: Selects and returns one of two values based on a Boolean state
           without using conditional branching (if-then-else).
  @note: Uses an array of pointers for maximizing speed.
[==============================================================================}
function TBooleanHelper.Choose(const bTrue, bFalse: Integer): Integer; overload; var A: array[0..1] of Integer; {$I Skeletons/Choose.inc}
function TBooleanHelper.Choose(const bTrue, bFalse: Double): Double; overload; var A: array[0..1] of Double; {$I Skeletons/Choose.inc}
function TBooleanHelper.Choose(const bTrue, bFalse: string): string; overload; var A: array[0..1] of string; {$I Skeletons/Choose.inc}
function TBooleanHelper.Choose(const bTrue, bFalse: Char): Char; overload; var A: array[0..1] of Char; {$I Skeletons/Choose.inc}
function TBooleanHelper.Choose(const bTrue, bFalse: Boolean): Boolean; overload; var A: array[0..1] of Boolean; {$I Skeletons/Choose.inc}
function TBooleanHelper.Choose(const bTrue, bFalse: TPoint): TPoint; overload; var A: array[0..1] of TPoint; {$I Skeletons/Choose.inc}
function TBooleanHelper.Choose(const bTrue, bFalse: TBox): TBox; overload; var A: array[0..1] of TBox; {$I Skeletons/Choose.inc}
function TBooleanHelper.Choose(const bTrue, bFalse: TRange): TRange; overload; var A: array[0..1] of TRange; {$I Skeletons/Choose.inc}
function TBooleanHelper.Choose(const bTrue, bFalse: TConnection): TConnection; overload; var A: array[0..1] of TConnection; {$I Skeletons/Choose.inc}
function TBooleanHelper.Choose(const bTrue, bFalse: TSegment): TSegment; overload; var A: array[0..1] of TSegment; {$I Skeletons/Choose.inc}
function TBooleanHelper.Choose(const bTrue, bFalse: TTriangle): TTriangle; overload; var A: array[0..1] of TTriangle; {$I Skeletons/Choose.inc}
function TBooleanHelper.Choose(const bTrue, bFalse: TCircle): TCircle; overload; var A: array[0..1] of TCircle; {$I Skeletons/Choose.inc}
function TBooleanHelper.Choose(const bTrue, bFalse: Int64): Int64; overload;
var
  A: array[0..1] of Int64;
begin
  A[0] := bFalse;
  A[1] := bTrue;
  Result := A[Ord(Self)];
end;

{==============================================================================]
  <Decide>
  @action: Selects and returns one of two values based on a Boolean state.
  @note: Uses a generic TArray constructor invocation to create an anonymous 
         array on the fly, performing a branchless lookup via Ord(Self).
[==============================================================================}
function TBooleanHelper.Decide(const bTrue, bFalse: Integer): Integer; overload; type RT = Integer; {$I Skeletons/Decide.inc}
function TBooleanHelper.Decide(const bTrue, bFalse: Double): Double; overload; type RT = Double; {$I Skeletons/Decide.inc}
function TBooleanHelper.Decide(const bTrue, bFalse: string): string; overload; type RT = string; {$I Skeletons/Decide.inc}
function TBooleanHelper.Decide(const bTrue, bFalse: Char): Char; overload; type RT = Char; {$I Skeletons/Decide.inc}
function TBooleanHelper.Decide(const bTrue, bFalse: Boolean): Boolean; overload; type RT = Boolean; {$I Skeletons/Decide.inc}
function TBooleanHelper.Decide(const bTrue, bFalse: TPoint): TPoint; overload; type RT = TPoint; {$I Skeletons/Decide.inc}
function TBooleanHelper.Decide(const bTrue, bFalse: TBox): TBox; overload; type RT = TBox; {$I Skeletons/Decide.inc}
function TBooleanHelper.Decide(const bTrue, bFalse: TRange): TRange; overload; type RT = TRange; {$I Skeletons/Decide.inc}
function TBooleanHelper.Decide(const bTrue, bFalse: TConnection): TConnection; overload; type RT = TConnection; {$I Skeletons/Decide.inc}
function TBooleanHelper.Decide(const bTrue, bFalse: TSegment): TSegment; overload; type RT = TSegment; {$I Skeletons/Decide.inc}
function TBooleanHelper.Decide(const bTrue, bFalse: TTriangle): TTriangle; overload; type RT = TTriangle; {$I Skeletons/Decide.inc}
function TBooleanHelper.Decide(const bTrue, bFalse: TCircle): TCircle; overload; type RT = TCircle; {$I Skeletons/Decide.inc}
function TBooleanHelper.Decide(const bTrue, bFalse: Int64): Int64; overload;
type
  RT = Int64;
begin
  Result := specialize TArray<RT>.Create(bFalse, bTrue)[Ord(Self)];
end; 

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
  <IfThen>
  @action: If (Self = True) then Result := bTrue else Result := bFalse; 
  @note: Returns T or F based on the Self-condition.
[==============================================================================}
function TBooleanHelper.IfThen(const bTrue, bFalse: Integer): Integer; overload; {$I Skeletons/IfThen.inc}
function TBooleanHelper.IfThen(const bTrue, bFalse: Double): Double; overload; {$I Skeletons/IfThen.inc}
function TBooleanHelper.IfThen(const bTrue, bFalse: string): string; overload; {$I Skeletons/IfThen.inc}
function TBooleanHelper.IfThen(const bTrue, bFalse: Char): Char; overload; {$I Skeletons/IfThen.inc}
function TBooleanHelper.IfThen(const bTrue, bFalse: Boolean): Boolean; overload; {$I Skeletons/IfThen.inc}
function TBooleanHelper.IfThen(const bTrue, bFalse: TPoint): TPoint; overload; {$I Skeletons/IfThen.inc}
function TBooleanHelper.IfThen(const bTrue, bFalse: TBox): TBox; overload; {$I Skeletons/IfThen.inc}
function TBooleanHelper.IfThen(const bTrue, bFalse: TRange): TRange; overload; {$I Skeletons/IfThen.inc}
function TBooleanHelper.IfThen(const bTrue, bFalse: TConnection): TConnection; overload; {$I Skeletons/IfThen.inc}
function TBooleanHelper.IfThen(const bTrue, bFalse: TSegment): TSegment; overload; {$I Skeletons/IfThen.inc}
function TBooleanHelper.IfThen(const bTrue, bFalse: TTriangle): TTriangle; overload; {$I Skeletons/IfThen.inc}
function TBooleanHelper.IfThen(const bTrue, bFalse: TCircle): TCircle; overload; {$I Skeletons/IfThen.inc}
function TBooleanHelper.IfThen(const bTrue, bFalse: Int64): Int64; overload;
begin
  if Self then
    Result := bTrue
  else
    Result := bFalse;
end;

{==============================================================================]
  <Select>
  @action: Returns a specified string using an inline literal array lookup based
           on the Boolean state.
  @note: Uses Ord() conversion to switch between index 0 (bFalse) and index 1 (bTrue),
         completely eliminating high-level conditional branch lines.
[==============================================================================}
function TBooleanHelper.Select(const bTrue, bFalse: Integer): Integer; overload; type TA = array of Integer; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: Double): Double; overload; type TA = array of Double; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: string): string; overload; type TA = array of string; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: Char): Char; overload; type TA = array of Char; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: Boolean): Boolean; overload; type TA = array of Boolean; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TPoint): TPoint; overload; type TA = array of TPoint; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TBox): TBox; overload; type TA = array of TBox; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TRange): TRange; overload; type TA = array of TRange; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TConnection): TConnection; overload; type TA = array of TConnection; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TSegment): TSegment; overload; type TA = array of TSegment; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TTriangle): TTriangle; overload; type TA = array of TTriangle; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: TCircle): TCircle; overload; type TA = array of TCircle; {$I Skeletons/Select.inc}
function TBooleanHelper.Select(const bTrue, bFalse: Int64): Int64; overload;
type
  TA = array of Int64; 
begin
  Result := TA.Create(bFalse, bTrue)[Ord(Self)];
end;
{$ENDIF}
