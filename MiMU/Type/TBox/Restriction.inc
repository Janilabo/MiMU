{$IFDEF METHODS}
function Constraint(const toArea: TBox): Boolean; 
function Clip(const toArea: TBox): TBox; 
function Restrict(const toArea: TBox): Boolean; 
function Clamp(const toArea: TBox): TBox;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Constraint>
  Explanation: Constraints bx to area.
  Example: None.
[==============================================================================}
function TBox.Constraint(const toArea: TBox): Boolean;
var
  b: TBox;
begin
  b := Self;
  Self.X1 := Max(toArea.X1, Min(toArea.X2, Self.X1));
  Self.Y1 := Max(toArea.Y1, Min(toArea.Y2, Self.Y1));
  Self.X2 := Max(toArea.X1, Min(toArea.X2, Self.X2));
  Self.Y2 := Max(toArea.Y1, Min(toArea.Y2, Self.Y2));
  Result := (Self <> b);
end;

{==============================================================================]
  <Clip>
  Explanation: Returns bx that has been constrained to area.
  Example: None.
[==============================================================================}
function TBox.Clip(const toArea: TBox): TBox;
begin
  Result.X1 := Max(toArea.X1, Min(toArea.X2, Self.X1));
  Result.Y1 := Max(toArea.Y1, Min(toArea.Y2, Self.Y1));
  Result.X2 := Max(toArea.X1, Min(toArea.X2, Self.X2));
  Result.Y2 := Max(toArea.Y1, Min(toArea.Y2, Self.Y2));
end;

{==============================================================================]
  <Restrict>
  Explanation: Restricts bx to area.
  Example: None.
[==============================================================================}
function TBox.Restrict(const toArea: TBox): Boolean;
var
  b: TBox;
begin
  b := Self;
  if (Self.X1 < toArea.X1) then
    Self.X1 := toArea.X1
  else
    if (Self.X1 > toArea.X2) then
      Self.X1 := toArea.X2;
  if (Self.Y1 < toArea.Y1) then
    Self.Y1 := toArea.Y1
  else
    if (Self.Y1 > toArea.Y2) then
      Self.Y1 := toArea.Y2;
  if (Self.X2 > toArea.X2) then
    Self.X2 := toArea.X2
  else
    if (Self.X2 < toArea.X1) then
      Self.X2 := toArea.X1;
  if (Self.Y2 > toArea.Y2) then
    Self.Y2 := toArea.Y2
  else
    if (Self.Y2 < toArea.Y1) then
      Self.Y2 := toArea.Y1;
  Result := (Self <> b);
end;

{==============================================================================]
  <Clamp>
  Explanation: Returns bx that has been restricted to area.
  Example: None.
[==============================================================================}
function TBox.Clamp(const toArea: TBox): TBox;
begin
  if (Self.X1 < toArea.X1) then
    Result.X1 := toArea.X1
  else
    if (Self.X1 > toArea.X2) then
      Result.X1 := toArea.X2
    else
      Result.X1 := Self.X1;
  if (Self.Y1 < toArea.Y1) then
    Result.Y1 := toArea.Y1
  else
    if (Self.Y1 > toArea.Y2) then
      Result.Y1 := toArea.Y2
    else
      Result.Y1 := Self.Y1;
  if (Self.X2 > toArea.X2) then
    Result.X2 := toArea.X2
  else
    if (Self.X2 < toArea.X1) then
      Result.X2 := toArea.X1
    else
      Result.X2 := Self.X2;
  if (Self.Y2 > toArea.Y2) then
    Result.Y2 := toArea.Y2
  else
    if (Self.Y2 < toArea.Y1) then
      Result.Y2 := toArea.Y1
    else
      Result.Y2 := Self.Y2;
end;
{$ENDIF}