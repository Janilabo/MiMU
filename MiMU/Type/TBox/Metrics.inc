{$IFDEF METHODS}
function Size(var width, height: Integer): Integer; overload; inline;
function Size: TPoint; overload; 
function Area: Integer; inline;
function Capacity: Integer; 
function Footprint: Double; 
function Perimeter: Integer; 
function Perim: Integer; 
function Circumference: Integer; 
function Diagonal: Double; 
function Width: Integer; overload; 
function Width(const w: Integer): Integer; overload; 
function Height: Integer; overload; 
function Height(const h: Integer): Integer; overload; 
function Ratio: Double; 
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Size>
  @action: Stores dimensions from TBox (bx) to width and height variables
  @note: Returns bx area.
[==============================================================================}
function TBox.Size(var width, height: Integer): Integer; overload; inline;
begin
  width := Self.Width;
  height := Self.Height;
  Result := (width * height);
end;

{==============================================================================]
  <Size>
  @action: Returns TBox dimensions (Width and Height) as TPoint.
  @note: X = Width, Y = Height.
[==============================================================================}
function TBox.Size: TPoint; overload;
begin
  Result := Point(Self.Width, Self.Height);
end;

{==============================================================================]
  <Area>
  @action: Calculates the amount of pixels in TBox (bx).
  @note: None
[==============================================================================}
function TBox.Area: Integer; inline;
begin
  Result := (Self.Width * Self.Height);
end;

{==============================================================================]
  <Capacity>
  @action: Calculates the amount of pixels in TBox (bx).
  @note: None
[==============================================================================}
function TBox.Capacity: Integer; inline;
begin
  with Self do
    Result := (((Max(X1, X2) - Min(X1, X2)) + 1) * ((Max(Y1, Y2) - Min(Y1, Y2)) + 1));
end;

{==============================================================================]
  <Footprint>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TBox.Footprint: Double;
begin
  Result := ((Abs(Self.X2 - Self.X1) + 1) * (Abs(Self.Y2 - Self.Y1) + 1));
end;

{==============================================================================]
  <Perimeter>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Perimeter: Integer;
begin
  Result := ((2 * (Self.Width + Self.Height)) - 4);
end;

{==============================================================================]
  <Perim>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Perim: Integer;
begin
  Result := (2 * (Pred(Self.Width) + Pred(Self.Height)));
end;

{==============================================================================]
  <Circumference>
  @action: Returns the length of TBox edge/border.
  @note: None
[==============================================================================}
function TBox.Circumference: Integer;
begin
  Result := ((Self.Width - 1) shl 1) + ((Self.Height - 1) shl 1);
end;

{==============================================================================]
  <Diagonal>
  @action: Returns diagonal size of bx.
  @note: None.
[==============================================================================}
function TBox.Diagonal: Double;
begin
  Result := Sqrt(Sqr(Self.Width) + Sqr(Self.Height));
end;

{==============================================================================]
  <Width>
  @action: Returns bx width.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.Width: Integer; overload;
begin
  Result := ((Self.X2 - Self.X1) + 1);
end;

{==============================================================================]
  <Width>
  @action: Sets bx width.
  @note: Returns old width.
[==============================================================================}
function TBox.Width(const w: Integer): Integer; overload;
begin
  Result := ((Self.X2 - Self.X1) + 1);
  Self.X2 := (Self.X1 + (w - 1));
end;

{==============================================================================]
  <Height>
  @action: Returns bx height.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.Height: Integer; overload;
begin
  Result := ((Self.Y2 - Self.Y1) + 1);
end;

{==============================================================================]
  <Height>
  @action: Sets bx height.
  @note: Returns old height.
[==============================================================================}
function TBox.Height(const h: Integer): Integer; overload;
begin
  Result := ((Self.Y2 - Self.Y1) + 1);
  Self.Y2 := (Self.Y1 + (h - 1));
end;

{==============================================================================]
  <Ratio>
  @action: Returns ratio of Width to Height.
  @note: None.
[==============================================================================}
function TBox.Ratio: Double;
begin
  Result := (Self.Width / Self.Height);
end;
{$ENDIF}