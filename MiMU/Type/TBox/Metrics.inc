{$IFDEF METHODS}
function Area: Integer; cdecl; inline;
function Capacity: Integer; cdecl;
function Circumference: Integer; cdecl;
function Diagonal: Double; cdecl;
function Footprint: Double; cdecl;
function Height: Integer; overload; cdecl;
function Height(const h: Integer): Integer; overload; cdecl;
function Perim: Integer; cdecl;
function Perimeter: Integer; cdecl;
function Ratio: Double; cdecl;
function Size(var bWidth, bHeight: Integer): Integer; overload; cdecl; inline;
function Size: TPoint; overload; cdecl;
function Width: Integer; overload; cdecl;
function Width(const w: Integer): Integer; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Area>
  @action: Calculates the amount of pixels in TBox (bx).
  @note: None
[==============================================================================}
function TBox.Area: Integer; cdecl; inline;
begin
  Result := (Self.Width * Self.Height);
end;

{==============================================================================]
  <Capacity>
  @action: Calculates the amount of pixels in TBox (bx).
  @note: None
[==============================================================================}
function TBox.Capacity: Integer; cdecl; inline;
begin
  with Self do
    Result := (((Max(X1, X2) - Min(X1, X2)) + 1) * ((Max(Y1, Y2) - Min(Y1, Y2)) + 1));
end;

{==============================================================================]
  <Circumference>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Circumference: Integer; cdecl;
begin
  Result := ((Self.Width - 1) shl 1) + ((Self.Height - 1) shl 1);
end;

{==============================================================================]
  <Diagonal>
  @action: Returns diagonal size of bx.
  @note: None.
[==============================================================================}
function TBox.Diagonal: Double; cdecl;
begin
  Result := Sqrt(Sqr(Self.Width) + Sqr(Self.Height));
end;

{==============================================================================]
  <Footprint>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TBox.Footprint: Double; cdecl;
begin
  Result := ((Abs(Self.X2 - Self.X1) + 1) * (Abs(Self.Y2 - Self.Y1) + 1));
end;

{==============================================================================]
  <Height>
  @action: Returns bx height.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.Height: Integer; overload; cdecl;
begin
  Result := ((Self.Y2 - Self.Y1) + 1);
end;

{==============================================================================]
  <Height>
  @action: Sets bx height.
  @note: Returns old height.
[==============================================================================}
function TBox.Height(const h: Integer): Integer; overload; cdecl;
begin
  Result := ((Self.Y2 - Self.Y1) + 1);
  Self.Y2 := (Self.Y1 + (h - 1));
end;

{==============================================================================]
  <Perim>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Perim: Integer; cdecl;
begin
  Result := (2 * (Pred(Self.Width) + Pred(Self.Height)));
end;

{==============================================================================]
  <Perimeter>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Perimeter: Integer; cdecl;
begin
  Result := ((2 * (Self.Width + Self.Height)) - 4);
end;

{==============================================================================]
  <Ratio>
  @action: Returns ratio of Width to Height.
  @note: None.
[==============================================================================}
function TBox.Ratio: Double; cdecl;
begin
  Result := (Self.Width / Self.Height);
end;

{==============================================================================]
  <Size>
  @action: Stores dimensions from TBox (bx) to width and height variables
  @note: Returns bx area.
[==============================================================================}
function TBox.Size(var bWidth, bHeight: Integer): Integer; overload; cdecl; inline;
begin
  bWidth := Self.Width;
  bHeight := Self.Height;
  Result := (bWidth * bHeight);
end;

{==============================================================================]
  <Size>
  @action: Returns TBox dimensions (Width and Height) as TPoint.
  @note: X = Width, Y = Height.
[==============================================================================}
function TBox.Size: TPoint; overload; cdecl;
begin
  Result := Point(Self.Width, Self.Height);
end;

{==============================================================================]
  <Width>
  @action: Returns bx width.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.Width: Integer; overload; cdecl;
begin
  Result := ((Self.X2 - Self.X1) + 1);
end;

{==============================================================================]
  <Width>
  @action: Sets bx width.
  @note: Returns old width.
[==============================================================================}
function TBox.Width(const w: Integer): Integer; overload; cdecl;
begin
  Result := ((Self.X2 - Self.X1) + 1);
  Self.X2 := (Self.X1 + (w - 1));
end;
{$ENDIF}
