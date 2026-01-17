{$IFDEF METHODS}
function Bottom: Integer;
function Dimensions(var bHorizontal, bVertical: TRange): Integer; overload;
function Dimensions(var bWidth, bHeight: Integer): Integer; overload;
function Frame(var fWidth, fHeight: Integer): TBox; overload;
function Frame: TBox; overload;
function GetHeight: Integer;
function GetWidth: Integer;
function Height: Integer; overload;
function Height(const h: Integer): Integer; overload;
function Horizontal: TRange;
function Left: Integer;
function Right: Integer;
function Top: Integer;
function Vertical: TRange;
function Width: Integer; overload;
function Width(const w: Integer): Integer; overload;
function XLength: Integer;
function XSize: Integer;
function YLength: Integer;
function YSize: Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Bottom>
  @action: Maximum Y-value
  @note: Always returns correct Bottom-value from TBox
[==============================================================================}
function TBox.Bottom: Integer;
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
  <Frame>
  @action: Returns the frame of TBox
  @note: Dimensional box of the TBox. Based on Width and Height.
[==============================================================================}
function TBox.Frame(var fWidth, fHeight: Integer): TBox; overload;
begin
  fWidth := Self.Width;
  fHeight := Self.Height;
  Result := Box(0, 0, (fWidth - 1), (fHeight - 1));
end;

{==============================================================================]
  <Frame>
  @action: Returns the frame of TBox
  @note: Dimensional box of the TBox. Based on Width and Height.
[==============================================================================}
function TBox.Frame: TBox; overload;
begin
  Result := Box(0, 0, (Self.Width - 1), (Self.Height - 1));
end;

{==============================================================================]
  <GetHeight>
  @action: Returns bx height.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.GetHeight: Integer;
begin
  Result := Succ(Self.Y2 - Self.Y1);
end;

{==============================================================================]
  <GetWidth>
  @action: Returns bx height.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.GetWidth: Integer;
begin
  Result := Succ(Self.X2 - Self.X1);
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
  <Horizontal>
  @action: Returns bx.X1 and bx.X2 as TRange.
  @note: Horitonzal-axis.
[==============================================================================}
function TBox.Horizontal: TRange;
begin
  Result.start := Self.X1;
  Result.stop := Self.X2;
end;

{==============================================================================]
  <Left>
  @action: Minimum X-value
  @note: Always returns correct Left-value from TBox
[==============================================================================}
function TBox.Left: Integer;
begin
  Result := Min(Self.X1, Self.X2);
end;

{==============================================================================]
  <Right>
  @action: Maximum X-value
  @note: Always returns correct Right-value from TBox
[==============================================================================}
function TBox.Right: Integer;
begin
  Result := Max(Self.X1, Self.X2);
end;

{==============================================================================]
  <Top>
  @action: Minimum Y-value
  @note: Always returns correct Top-value from TBox
[==============================================================================}
function TBox.Top: Integer;
begin
  Result := Min(Self.Y1, Self.Y2);
end;

{==============================================================================]
  <Vertical>
  @action: Returns bx.Y1 and bx.Y2 as TRange.
  @note: Vertical-axis.
[==============================================================================}
function TBox.Vertical: TRange;
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
  <XLength>
  @action: Returns bx width.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.XLength: Integer;
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
function TBox.XSize: Integer;
begin
  Result := TRange.Construct(Self.X1, Self.X2).Size;
end;

{==============================================================================]
  <YLength>
  @action: Returns bx height.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBox.YLength: Integer;
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
function TBox.YSize: Integer;
begin
  Result := TRange.Construct(Self.Y1, Self.Y2).Size;
end;
{$ENDIF}