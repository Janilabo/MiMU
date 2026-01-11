{$IFDEF METHODS}
function Extend(const pt: TPoint): Boolean;
function ExtendX(const xCoord: Integer): Boolean; 
function ExtendY(const yCoord: Integer): Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Extend>
  Explanation: Returns true if TBox is changed with pt (X1, X2, Y1 or Y2)
  @note: Modifies the Self!
[==============================================================================}
function TBox.Extend(const pt: TPoint): Boolean;
var
  w, h: Boolean;
begin
  w := Self.ExtendX(pt.X);
  h := Self.ExtendY(pt.Y);
  Result := (w or h);
end;

{==============================================================================]
  <ExtendX>
  Explanation: Returns true if TBox is changed with xCoord (X1 or X2)
  @note: Modifies the Self!
[==============================================================================}
function TBox.ExtendX(const xCoord: Integer): Boolean;
begin
  if (xCoord < Self.X1) then
    Self.X1 := xCoord
  else
    if (xCoord > Self.X2) then
      Self.X2 := xCoord
    else
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <ExtendY>
  Explanation: Returns true if TBox is changed with yCoord (Y1 or Y2)
  @note: Modifies the Self!
[==============================================================================}
function TBox.ExtendY(const yCoord: Integer): Boolean;
begin
  if (yCoord < Self.Y1) then
    Self.Y1 := yCoord
  else
    if (yCoord > Self.Y2) then
      Self.Y2 := yCoord
    else
      Exit(False);
  Result := True;
end;
{$ENDIF}