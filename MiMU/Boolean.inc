{==============================================================================]
 <Boolean_Random>
 @action: Returns random boolean.
 @note: None
[==============================================================================}

function Boolean_Random: Boolean; cdecl; inline;
begin
  Result := (Random(2) = 0);
end;

{==============================================================================]
 <Boolean_X>
 @action: If (X = True) then Result := trueX else Result := falseX; 
 @note: Returns trueX or falseX based on the X-condition.
[==============================================================================}

function Boolean_X(const X: Boolean; const trueX, falseX: Boolean): Boolean; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: Int32): Int32; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: Int64): Int64; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: Double): Double; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: string): string; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: Char): Char; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: TPoint): TPoint; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: TBox): TBox; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

function Boolean_X(const X: Boolean; const trueX, falseX: TRange): TRange; overload; cdecl;
begin
  if X then
    Result := trueX
  else
    Result := falseX;
end;

{==============================================================================]
  <Boolean_Opposite>
  @action: Returns the opposite value of X.
  @note: True => False / False => True.
[==============================================================================}
function Boolean_Opposite(const x: Boolean): Boolean; cdecl;
begin
  Result := not x;
end;

{==============================================================================]
  <Boolean_Toggle>
  @action: Toggles the Boolean value of X.
  @note: Returns the original value before toggling.
[==============================================================================}
function Boolean_Toggle(var x: Boolean): Boolean; cdecl;
begin
  Result := x;
  x := not x;
end;

{==============================================================================]
  <Boolean_Set>
  @action: Sets X to the given state if different.
  @note: Returns True if X was changed.
[==============================================================================}
function Boolean_Set(var x: Boolean; const state: Boolean): Boolean; cdecl;
begin
  Result := not (x = state);
  if Result then
    x := state;
end;

{==============================================================================]
  <Boolean_Unset>
  @action: Inverts X only if it equals the given state.
  @note: Returns True if X was changed.
[==============================================================================}
function Boolean_Unset(var x: Boolean; const state: Boolean): Boolean; cdecl;
begin
  Result := (x = state);
  if Result then
    x := not x;
end;

{==============================================================================]
  <Boolean_Check>
  @action: Sets X to True (checked).
  @note: Returns True if X was previously False.
[==============================================================================}
function Boolean_Check(var x: Boolean): Boolean; cdecl;
begin
  Result := (x = False);
  x := True;
end;

{==============================================================================]
  <Boolean_Uncheck>
  @action: Sets X to False (unchecked).
  @note: Returns True if X was previously True.
[==============================================================================}
function Boolean_Uncheck(var x: Boolean): Boolean; cdecl;
begin
  Result := (x = True);
  x := False;
end;

{==============================================================================]
  <Boolean_Enable>
  @action: Sets X to True (enabled).
  @note: Returns True if X was previously False.
[==============================================================================}
function Boolean_Enable(var x: Boolean): Boolean; cdecl;
begin
  Result := not x;
  x := True;
end;

{==============================================================================]
  <Boolean_Disable>
  @action: Sets X to False (disabled).
  @note: Returns True if X was previously True.
[==============================================================================}
function Boolean_Disable(var x: Boolean): Boolean; cdecl;
begin
  Result := x;
  x := False;
end;