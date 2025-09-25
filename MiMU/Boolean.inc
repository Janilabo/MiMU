{==============================================================================]
 <TBooleanHelper.ToString>
 @action: Returns string of Self.
 @note: True => 'True', False => 'False'.
[==============================================================================}
function TBooleanHelper.ToString: string; cdecl;
begin
  if Self then
    Result := 'True'
  else
    Result := 'False';
end;

{==============================================================================]
 <TBooleanHelper.Binary>
 @action: Returns binary char based on boolean state.
 @note: True => '1', False => '0'.
[==============================================================================}
function TBooleanHelper.Binary: Char; cdecl;
begin
  Result := IfThen(Self, '1', '0');
end;

{==============================================================================]
  <TBooleanHelper.BinaryDigit>
  @action: Returns binary char from Boolean
  @note: True => 1 & False => 0
[==============================================================================}
function TBooleanHelper.BinaryDigit: Integer; cdecl;
begin
  Result := IfThen(Self, 1, 0);  
end;

{==============================================================================]
 <TBooleanHelper.Bit>
 @action: Bit for helper booleans.
 @note: True => 1 | False => 0
[==============================================================================}
function TBooleanHelper.Bit: Integer; cdecl; inline;
begin
  Result := (Integer(Self) and 1);
end;

{==============================================================================]
 <TBooleanHelper.Bitify>
 @action: Bitify for helper booleans.
 @note: True => 1 | False => 0
[==============================================================================}
function TBooleanHelper.Bitify: Integer; cdecl;
begin
  Result := IfThen(Self, 1, 0);
end;

{==============================================================================]
 <TBooleanHelper.ToInteger>
 @action: Returns integer based on state of Self.
 @note: True => 1 | False => 0
[==============================================================================}
function TBooleanHelper.ToInteger: Integer; cdecl;
begin
  case Self of
    True: Result := 1;
    False: Result := 0;
  end;
end;

{==============================================================================]
 TBooleanHelper.AsInteger>
 @action: Returns Self as Integer.
 @note: False => 0 | True => 1
[==============================================================================}
function TBooleanHelper.AsInteger: Integer; cdecl;
begin
  Result := Integer(Self);
end;

{==============================================================================]
 <TBooleanHelper.Toggle>
 @action: Returns opposite of Self.
 @note: None
[==============================================================================}
function TBooleanHelper.Toggle: Boolean; cdecl;
begin
  Result := not Self;
end;

{==============================================================================]
 <TBooleanHelper.Opposite>
 @action: Returns opposite of Self.
 @note: None
[==============================================================================}
function TBooleanHelper.Opposite: Boolean; cdecl;
begin
  if Self then
    Result := False
  else
    Result := True;
end;

{==============================================================================]
 <TBooleanHelper.Switch>
 @action: Reverses Self.
 @note: Also returns the reversed Self.
[==============================================================================}
function TBooleanHelper.Switch: Boolean; cdecl;
begin
  if Self then
    Self := False
  else
    Self := True;
  Result := Self;
end;

{==============================================================================]
 <TBooleanHelper.Flip>
 @action: Reverses Self.
 @note: Also returns the reversed Self.
[==============================================================================}
function TBooleanHelper.Flip: Boolean; cdecl;
begin
  Self := not Self;
  Result := Self;
end;

{==============================================================================]
 <TBooleanHelper.Shuffle>
 @action: Randomizes Self and then returns it.
 @note: None
[==============================================================================}
function TBooleanHelper.Shuffle: Boolean; cdecl;
begin
  Self := (Random(2) = 0);
  Result := Self;
end;

{==============================================================================]
 <TBooleanHelper.Select>
 @action: If (Self = True) then Result := T else Result := F; 
 @note: Returns T or F based on the Self-condition.
[==============================================================================}

function TBooleanHelper.Select(const bTrue, bFalse: Integer): Integer; overload; cdecl; {$DEFINE Skeleton_Select}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: Int64): Int64; overload; cdecl; {$DEFINE Skeleton_Select}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: Double): Double; overload; cdecl; {$DEFINE Skeleton_Select}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: string): string; overload; cdecl; {$DEFINE Skeleton_Select}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: Char): Char; overload; cdecl; {$DEFINE Skeleton_Select}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: Boolean): Boolean; overload; cdecl; {$DEFINE Skeleton_Select}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: TPoint): TPoint; overload; cdecl; {$DEFINE Skeleton_Select}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: TBox): TBox; overload; cdecl; {$DEFINE Skeleton_Select}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select}
function TBooleanHelper.Select(const bTrue, bFalse: TRange): TRange; overload; cdecl; {$DEFINE Skeleton_Select}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select}

{==============================================================================]
 <TBooleanHelper.Evaluate>
 @action: If (Self = True) then Result := bTrue else Result := bFalse;
 @note: Returns bTrue or bFalse based on the Self-condition.
[==============================================================================}

function TBooleanHelper.Evaluate(const bTrue, bFalse: Integer): Integer; overload; cdecl; {$DEFINE Skeleton_Evaluate}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Int64): Int64; overload; cdecl; {$DEFINE Skeleton_Evaluate}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Double): Double; overload; cdecl; {$DEFINE Skeleton_Evaluate}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: string): string; overload; cdecl; {$DEFINE Skeleton_Evaluate}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Char): Char; overload; cdecl; {$DEFINE Skeleton_Evaluate}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: Boolean): Boolean; overload; cdecl; {$DEFINE Skeleton_Evaluate}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TPoint): TPoint; overload; cdecl; {$DEFINE Skeleton_Evaluate}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TBox): TBox; overload; cdecl; {$DEFINE Skeleton_Evaluate}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Evaluate}
function TBooleanHelper.Evaluate(const bTrue, bFalse: TRange): TRange; overload; cdecl; {$DEFINE Skeleton_Evaluate}{$I libraries\MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Evaluate}

{==============================================================================]
  <TBooleanHelper.Enable>
  @action: Sets Self to True (enabled).
  @note: Returns True if Self was previously False.
[==============================================================================}
function TBooleanHelper.Enable: Boolean; cdecl;
begin
  Result := (Self <> True);
  Self := True;
end;

{==============================================================================]
  <TBooleanHelper.Disable>
  @action: Sets Self to False (disabled).
  @note: Returns True if Self was previously True.
[==============================================================================}
function TBooleanHelper.Disable: Boolean; cdecl;
begin
  Result := (Self = True);
  Self := False;
end;

{==============================================================================]
  <TBooleanHelper.SetFalse>
  @action: Sets Self as False and returns 0.
  @note: None.
[==============================================================================}
function TBooleanHelper.SetFalse: Integer; cdecl;
begin
  Self := False;
  Result := 0;
end;

{==============================================================================]
  <TBooleanHelper.SetTrue>
  @action: Sets Self as True and returns 1.
  @note: None.
[==============================================================================}
function TBooleanHelper.SetTrue: Integer; cdecl;
begin
  Self := True;
  Result := 1;
end;

{==============================================================================]
  <TBooleanHelper.SwitchOn>
  @action: Sets Self to the given state if different.
  @note: Returns True if Self was changed.
[==============================================================================}
function TBooleanHelper.SwitchOn(const state: Boolean): Boolean; cdecl;
begin
  Result := (Self <> state);
  if Result then
    Self := state;
end;

{==============================================================================]
  <TBooleanHelper.SwitchOff>
  @action: Inverts Self only if it equals the given state.
  @note: Returns True if Self was changed.
[==============================================================================}
function TBooleanHelper.SwitchOff(const state: Boolean): Boolean; cdecl;
begin
  Result := (Self = state);
  if Result then
    Self := not state;
end;
