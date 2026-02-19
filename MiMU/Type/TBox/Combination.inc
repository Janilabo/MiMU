{$IFDEF METHODS}
function Envelope(const b: TBox): TBox;
function Union(const pt: TPoint): TBox; overload;
function Union(const b: TBox): TBox; overload;
function UnionX(const xCoord: Integer): TBox;
function Uniony(const yCoord: Integer): TBox;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Envelope>
  @action: Bounds 2 boxes (a and b) to 1 box.
  @note: Based on lowest / highest coordinate values.
[==============================================================================}
function TBox.Envelope(const b: TBox): TBox;
begin
  Result.X1 := Min(Min(Self.X1, Self.X2), Min(b.X1, b.X2));
  Result.Y1 := Min(Min(Self.Y1, Self.Y2), Min(b.Y1, b.Y2));
  Result.X2 := Max(Max(Self.X1, Self.X2), Max(b.X1, b.X2));
  Result.Y2 := Max(Max(Self.Y1, Self.Y2), Max(b.Y1, b.Y2));
end;

{==============================================================================]
  <Union>
  Explanation: Returns the Self unioned with pt.
  @note: None.
[==============================================================================}
function TBox.Union(const pt: TPoint): TBox; overload;
begin
  Result := Self.UnionX(pt.X).UnionY(pt.Y);
end;

{==============================================================================]
  <Union>
  @action: Returns union of a and b TBoxes
  @note: None
[==============================================================================}
function TBox.Union(const b: TBox): TBox; overload;
begin
  Result.X1 := Min(Self.X1, b.X1);
  Result.Y1 := Min(Self.Y1, b.Y1);
  Result.X2 := Max(Self.X2, b.X2);
  Result.Y2 := Max(Self.Y2, b.Y2);
end;

{==============================================================================]
  <UnionX>
  Explanation: Returns the TBox Self with X-value extended (if xCoord falls outside bounds)
  @note: None.
[==============================================================================}
function TBox.UnionX(const xCoord: Integer): TBox;
begin
  if (xCoord < Self.X1) then
    Result := Box(xCoord, Self.Y1, Self.X2, Self.Y2)
  else if (xCoord > Self.X2) then
    Result := Box(Self.X1, Self.Y1, xCoord, Self.Y2)
  else
    Result := Self;
end;

{==============================================================================]
  <UnionY>
  Explanation: Returns the TBox Self with Y-value extended (if yCoord falls outside bounds)
  @note: None.
[==============================================================================}
function TBox.UnionY(const yCoord: Integer): TBox;
begin
  if (yCoord < Self.Y1) then
    Result := Box(Self.X1, yCoord, Self.X2, Self.Y2)
  else if (yCoord > Self.Y2) then
    Result := Box(Self.X1, Self.Y1, Self.X2, yCoord)
  else
    Result := Self;
end;
{$ENDIF}