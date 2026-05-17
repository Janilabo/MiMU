{$IFDEF METHODS}
function Bottom: Integer; overload;
function Dimensions(var bHorizontal, bVertical: TRange): Integer; overload;
function Dimensions(var bWidth, bHeight: Integer): Integer; overload;
function GetHeight: Integer; overload;
function GetWidth: Integer; overload;
function Height: Integer; overload;
function Height(const h: Integer): Integer; overload;
function Horizontal: TRange; overload;
function Left: Integer; overload;
function Right: Integer; overload;
function Top: Integer; overload;
function Vertical: TRange; overload;
function Width: Integer; overload;
function Width(const w: Integer): Integer; overload;
function XLength: Integer; overload;
function XSize: Integer; overload;
function XSpan: Integer; overload;
function YLength: Integer; overload;
function YSize: Integer; overload;
function YSpan: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Bottom>
  @action: Maximum Y-value
  @note: Always returns correct Bottom-value from TBox
[==============================================================================}
function TBox.Bottom: Integer; overload;
begin
  Result := Max(Self.Y1, Self.Y2);
end;

{==============================================================================]
  <Dimensions>
  @action: Returns area of the TBox
  @note: Stores horizontal & vertical axis to TRange variables.
[==============================================================================}
function TBox.Dimensions(var bHorizontal, bVertical: TRange): Integer; overload;
begin
  bHorizontal := Self.Horizontal;
  bVertical := Self.Vertical;
  Result := (bHorizontal.Size * bVertical.Size);
end;

{==============================================================================]
  <Dimensions>
  @action: Returns area of the TBox
  @note: Stores width & height variables.
[==============================================================================}
function TBox.Dimensions(var bWidth, bHeight: Integer): Integer; overload;
begin
  bWidth := Self.Horizontal.Size;
  bHeight := Self.Vertical.Size;
  Result := (bWidth * bHeight);
end;

{==============================================================================]
  <GetHeight>
  @action: Returns bx height.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.GetHeight: Integer; overload;
begin
  Result := Succ(Self.YSpan);
end;

{==============================================================================]
  <GetWidth>
  @action: Returns bx height.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.GetWidth: Integer; overload;
begin
  Result := Succ(Self.XSpan);
end;

{==============================================================================]
  <Height>
  @action: Returns bx height.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.Height: Integer; overload;
begin
  Result := (Self.YSpan + 1);
end;

{==============================================================================]
  <Height>
  @action: Sets bx height.
  @note: Returns old height.
[==============================================================================}
function TBox.Height(const h: Integer): Integer; overload;
begin
  Result := (Self.YSpan + 1);
  Self.Y2 := (Self.Y1 + (h - 1));
end;

{==============================================================================]
  <Horizontal>
  @action: Returns bx.X1 and bx.X2 as TRange.
  @note: Horitonzal-axis.
[==============================================================================}
function TBox.Horizontal: TRange; overload;
begin
  Result.start := Self.X1;
  Result.stop := Self.X2;
end;

{==============================================================================]
  <Left>
  @action: Minimum X-value
  @note: Always returns correct Left-value from TBox
[==============================================================================}
function TBox.Left: Integer; overload;
begin
  Result := Min(Self.X1, Self.X2);
end;

{==============================================================================]
  <Right>
  @action: Maximum X-value
  @note: Always returns correct Right-value from TBox
[==============================================================================}
function TBox.Right: Integer; overload;
begin
  Result := Max(Self.X1, Self.X2);
end;

{==============================================================================]
  <Top>
  @action: Minimum Y-value
  @note: Always returns correct Top-value from TBox
[==============================================================================}
function TBox.Top: Integer; overload;
begin
  Result := Min(Self.Y1, Self.Y2);
end;

{==============================================================================]
  <Vertical>
  @action: Returns bx.Y1 and bx.Y2 as TRange.
  @note: Vertical-axis.
[==============================================================================}
function TBox.Vertical: TRange; overload;
begin
  Result.start := Self.Y1;
  Result.stop := Self.Y2;
end;

{==============================================================================]
  <Width>
  @action: Returns bx width.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.Width: Integer; overload;
begin
  Result := (Self.XSpan + 1);
end;

{==============================================================================]
  <Width>
  @action: Sets bx width.
  @note: Returns old width.
[==============================================================================}
function TBox.Width(const w: Integer): Integer; overload;
begin
  Result := (Self.XSpan + 1);
  Self.X2 := (Self.X1 + (w - 1));
end;

{==============================================================================]
  <XLength>
  @action: Returns bx width.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.XLength: Integer; overload;
begin
  Result := Self.X2;
  Dec(Result, Self.X1);
  Inc(Result);
end;

{==============================================================================]
  <XSize>
  @action: Returns bx width.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.XSize: Integer; overload;
begin
  Result := TRange.Construct(Self.X1, Self.X2).Size;
end;

{==============================================================================]
  <XSpan>
  @action: Calculates and returns the horizontal width (span) of the box.
  @note: Represents the distance along the X-axis from the left edge (X1) to 
         the right edge (X2). Note that if X2 is less than X1, this will return 
         a negative value unless normalized.
[==============================================================================}
function TBox.XSpan: Integer; overload;
begin
  Result := (Self.X2 - Self.X1);
end;

{==============================================================================]
  <YLength>
  @action: Returns bx height.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.YLength: Integer; overload;
begin
  Result := Self.Y2;
  Dec(Result, Self.Y1);
  Inc(Result);
end;

{==============================================================================]
  <YSize>
  @action: Returns bx height.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.YSize: Integer; overload;
begin
  Result := TRange.Construct(Self.Y1, Self.Y2).Size;
end;

{==============================================================================]
  <YSpan>
  @action: Calculates and returns the vertical height (span) of the box.
  @note: Represents the distance along the Y-axis from the top edge (Y1) to 
         the bottom edge (Y2). In most computer graphics coordinate systems, 
         Y increases downwards, meaning a positive result indicates a downward 
         span from Y1.
[==============================================================================}
function TBox.YSpan: Integer; overload;
begin
  Result := (Self.Y2 - Self.Y1);
end;
{$ENDIF}