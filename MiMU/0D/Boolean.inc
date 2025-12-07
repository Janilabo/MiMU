{$DEFINE TVar := Boolean}
{$DEFINE TArr := TBooleanArray}
{$DEFINE T2DArr := T2DBooleanArray}
{$DEFINE THelper := TBooleanHelper}
{$UNDEF Sortable}

{$IFDEF TYPES}
TBooleanArray = array of Boolean;
T2DBooleanArray = array of TBooleanArray;
{$ENDIF}

{$IFDEF HELPERS}
TBooleanHelper = type helper for Boolean
  {$I Core.inc}
  function ToString: string;
  function Binary: Char;
  function BinaryDigit: Integer;
  function Bit: Integer; inline;
  function Bitify: Integer;
  function ToInteger: Integer;
  function AsInteger: Integer;
  function Toggle: Boolean;
  function Opposite: Boolean;
  function Switch: Boolean;
  function Flip: Boolean;
  function Shuffle: Boolean;
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
  function Enable: Boolean;
  function Disable: Boolean;
  function SetFalse: Integer;
  function SetTrue: Integer;
  function SwitchOn(const state: Boolean): Boolean;
  function SwitchOff(const state: Boolean): Boolean;
end;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{$I Core.inc}

{==============================================================================]
  <ToString>
  @action: Returns string of Self.
  @note: True => 'True', False => 'False'.
[==============================================================================}
function TBooleanHelper.ToString: string; 
begin
  if Self then
    Result := 'True'
  else
    Result := 'False';
end;

{==============================================================================]
  <Binary>
  @action: Returns binary char based on boolean state.
  @note: True => '1', False => '0'.
[==============================================================================}
function TBooleanHelper.Binary: Char; 
begin
  Result := IfThen(Self, '1', '0');
end;

{==============================================================================]
  <BinaryDigit>
  @action: Returns binary char from Boolean
  @note: True => 1 & False => 0
[==============================================================================}
function TBooleanHelper.BinaryDigit: Integer; 
begin
  Result := IfThen(Self, 1, 0);  
end;

{==============================================================================]
  <Bit>
  @action: Bit for helper booleans.
  @note: True => 1 | False => 0
[==============================================================================}
function TBooleanHelper.Bit: Integer; inline;
begin
  Result := (Integer(Self) and 1);
end;

{==============================================================================]
  <Bitify>
  @action: Bitify for helper booleans.
  @note: True => 1 | False => 0
[==============================================================================}
function TBooleanHelper.Bitify: Integer; 
begin
  Result := IfThen(Self, 1, 0);
end;

{==============================================================================]
  <ToInteger>
  @action: Returns integer based on state of Self.
  @note: True => 1 | False => 0
[==============================================================================}
function TBooleanHelper.ToInteger: Integer; 
begin
  case Self of
    True: Result := 1;
    False: Result := 0;
  end;
end;

{==============================================================================]
  <AsInteger>
  @action: Returns Self as Integer.
  @note: False => 0 | True => 1
[==============================================================================}
function TBooleanHelper.AsInteger: Integer; 
begin
  Result := Integer(Self);
end;

{==============================================================================]
  <Toggle>
  @action: Returns opposite of Self.
  @note: None
[==============================================================================}
function TBooleanHelper.Toggle: Boolean; 
begin
  Result := not Self;
end;

{==============================================================================]
  <Opposite>
  @action: Returns opposite of Self.
  @note: None
[==============================================================================}
function TBooleanHelper.Opposite: Boolean; 
begin
  if Self then
    Result := False
  else
    Result := True;
end;

{==============================================================================]
  <Switch>
  @action: Reverses Self.
  @note: Also returns the reversed Self.
[==============================================================================}
function TBooleanHelper.Switch: Boolean; 
begin
  if Self then
    Self := False
  else
    Self := True;
  Result := Self;
end;

{==============================================================================]
  <Flip>
  @action: Reverses Self.
  @note: Also returns the reversed Self.
[==============================================================================}
function TBooleanHelper.Flip: Boolean; 
begin
  Self := not Self;
  Result := Self;
end;

{==============================================================================]
  <Shuffle>
  @action: Randomizes Self and then returns it.
  @note: None
[==============================================================================}
function TBooleanHelper.Shuffle: Boolean; 
begin
  Self := (Random(2) = 0);
  Result := Self;
end;

{==============================================================================]
  <Select>
  @action: If (Self = True) then Result := T else Result := F; 
  @note: Returns T or F based on the Self-condition.
[==============================================================================}

function TBooleanHelper.Select(const bTrue, bFalse: Integer): Integer; overload; {$DEFINE Skeleton_Select}{$I Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: Int64): Int64; overload; {$DEFINE Skeleton_Select}{$I Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: Double): Double; overload; {$DEFINE Skeleton_Select}{$I Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: string): string; overload; {$DEFINE Skeleton_Select}{$I Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: Char): Char; overload; {$DEFINE Skeleton_Select}{$I Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: Boolean): Boolean; overload; {$DEFINE Skeleton_Select}{$I Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: TPoint): TPoint; overload; {$DEFINE Skeleton_Select}{$I Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: TBox): TBox; overload; {$DEFINE Skeleton_Select}{$I Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: TRange): TRange; overload; {$DEFINE Skeleton_Select}{$I Skeletons.inc}{$UNDEF Skeleton_Select}

{==============================================================================]
  <Evaluate>
  @action: If (Self = True) then Result := bTrue else Result := bFalse;
  @note: Returns bTrue or bFalse based on the Self-condition.
[==============================================================================}

function TBooleanHelper.Evaluate(const bTrue, bFalse: Integer): Integer; overload; {$DEFINE Skeleton_Evaluate}{$I Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Int64): Int64; overload; {$DEFINE Skeleton_Evaluate}{$I Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Double): Double; overload; {$DEFINE Skeleton_Evaluate}{$I Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: string): string; overload; {$DEFINE Skeleton_Evaluate}{$I Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Char): Char; overload; {$DEFINE Skeleton_Evaluate}{$I Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Boolean): Boolean; overload; {$DEFINE Skeleton_Evaluate}{$I Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TPoint): TPoint; overload; {$DEFINE Skeleton_Evaluate}{$I Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TBox): TBox; overload; {$DEFINE Skeleton_Evaluate}{$I Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TRange): TRange; overload; {$DEFINE Skeleton_Evaluate}{$I Skeletons.inc}{$UNDEF Skeleton_Evaluate}

{==============================================================================]
  <Enable>
  @action: Sets Self to True (enabled).
  @note: Returns True if Self was previously False.
[==============================================================================}
function TBooleanHelper.Enable: Boolean; 
begin
  Result := (Self <> True);
  Self := True;
end;

{==============================================================================]
  <Disable>
  @action: Sets Self to False (disabled).
  @note: Returns True if Self was previously True.
[==============================================================================}
function TBooleanHelper.Disable: Boolean; 
begin
  Result := (Self = True);
  Self := False;
end;

{==============================================================================]
  <SetFalse>
  @action: Sets Self as False and returns 0.
  @note: None.
[==============================================================================}
function TBooleanHelper.SetFalse: Integer; 
begin
  Self := False;
  Result := 0;
end;

{==============================================================================]
  <SetTrue>
  @action: Sets Self as True and returns 1.
  @note: None.
[==============================================================================}
function TBooleanHelper.SetTrue: Integer; 
begin
  Self := True;
  Result := 1;
end;

{==============================================================================]
  <SwitchOn>
  @action: Sets Self to the given state if different.
  @note: Returns True if Self was changed.
[==============================================================================}
function TBooleanHelper.SwitchOn(const state: Boolean): Boolean; 
begin
  Result := (Self <> state);
  if Result then
    Self := state;
end;

{==============================================================================]
  <SwitchOff>
  @action: Inverts Self only if it equals the given state.
  @note: Returns True if Self was changed.
[==============================================================================}
function TBooleanHelper.SwitchOff(const state: Boolean): Boolean; 
begin
  Result := (Self = state);
  if Result then
    Self := not state;
end;
{$ENDIF}