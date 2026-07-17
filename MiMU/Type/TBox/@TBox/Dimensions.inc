{$IFDEF METHODS}
function Dimensign: Integer; overload;
function Dimensio: Integer; overload;
function Dimension: Integer; overload;
function Dimensionality: Integer; overload;
function Dimensionally: Integer; overload;
function Dimensions: Integer; overload;

function Dimensions(var bHorizontal, bVertical: TRange): Integer; overload;
function Dimensions(var bWidth, bHeight: Integer): Integer; overload;
function GetH: Integer; overload;
function GetHeight: Integer; overload;
function GetW: Integer; overload;
function GetWidth: Integer; overload;
function Height: Integer; overload;
function Height(const h: Integer): Integer; overload;
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
  <Dimensign>
  @action: Returns the exact geometric dimension of the box (-1, 0, 1, or 2).
  @note: Delegates axis comparison to 'Sign' on each delta; a negative sign on
         either axis is immediately invalid, otherwise the result is just a
         count of how many axes are strictly extended.
[==============================================================================}
function TBox.Dimensign: Integer; overload;
var
  h, v: Integer;
begin
  h := Sign(Self.X2 - Self.X1);
  v := Sign(Self.Y2 - Self.Y1);
  if ((h < 0) or (v < 0)) then
    Exit(-1);
  Result := (Ord(h > 0) + Ord(v > 0));
end;

{==============================================================================]
  <Dimensio>
  @action: Returns the exact geometric dimension of the box (-1, 0, 1, or 2).
  @note: The stripped-down baseline of the family: a single inversion check
         upfront, then the result is just a count of strictly extended axes.
         No intermediate variables, no Sign/CompareValue delegation — just
         direct comparisons.
[==============================================================================}
function TBox.Dimensio: Integer; overload;
begin
  if ((Self.X1 > Self.X2) or (Self.Y1 > Self.Y2)) then
    Exit(-1);
  Result := (Ord(Self.X2 > Self.X1) + Ord(Self.Y2 > Self.Y1));
end;

{==============================================================================]
  <Dimension>
  @action: Returns the exact geometric dimension of the box (-1, 0, 1, or 2).
  @note: A highly optimized, linear layout that uses consecutive early exits 
         and falls through to a default -1 for any inverted coordinates.
[==============================================================================}
function TBox.Dimension: Integer; overload;
begin
  if (Self.X2 > Self.X1) then
    if (Self.Y2 > Self.Y1) then
      Exit(2)
    else if (Self.Y2 = Self.Y1) then
      Exit(1);
  if (Self.X2 = Self.X1) then
    if (Self.Y2 = Self.Y1) then
      Exit(0)
    else if (Self.Y2 > Self.Y1) then
      Exit(1);
  Result := -1;
end;

{==============================================================================]
  <Dimensionality>
  @action: Returns the geometric dimension of the box (-1 for invalid/empty,
           0 for a point, 1 for a line, 2 for an area).
  @note:
    - Optimized for performance by checking the most common state (2D) first,
      then falling back to 0D, 1D, or invalid.
    - The 1D branch relies on 'not((X inverted) or (Y inverted))': since the
      2D and 0D cases are already peeled off above it, this leaves only the
      two genuine line orientations (one axis flat, the other extended) to
      resolve to 1, with every remaining inverted-axis combination correctly
      falling through to -1.
[==============================================================================}
function TBox.Dimensionality: Integer; overload;
begin
  if ((Self.X2 > Self.X1) and (Self.Y2 > Self.Y1)) then
    Result := 2
  else if ((Self.X2 = Self.X1) and (Self.Y2 = Self.Y1)) then
    Result := 0
  else if not ((Self.X1 > Self.X2) or (Self.Y1 > Self.Y2)) then
    Result := 1
  else
    Result := -1;
end;

{==============================================================================]
  <Dimensionally>
  @action: Returns the exact geometric dimension of the box (-1, 0, 1, or 2).
  @note: Uses a nested boolean case-tree to explicitly evaluate and isolate all 
         9 possible boundary layout permutations without any overlap.
[==============================================================================}
function TBox.Dimensionally: Integer; overload;
begin
  case (Self.X2 > Self.X1) of
    True:
    if (Self.Y2 > Self.Y1) then
      Result := 2
    else if (Self.Y2 = Self.Y1) then
      Result := 1
    else
      Result := -1;
    False:
    case (Self.X2 = Self.X1) of
      True:
      if (Self.Y2 = Self.Y1) then
        Result := 0
      else if (Self.Y2 > Self.Y1) then
        Result := 1
      else
        Result := -1;
      False: Result := -1;
    end;
  end;
end;

{==============================================================================]
  <Dimensions>
  @action: Returns the exact geometric dimension of the box (-1, 0, 1, or 2).
  @note: Uses early exits inside an optimized case branch, letting all invalid 
         or inverted permutations gracefully fall through to a default -1.
[==============================================================================}
function TBox.Dimensions: Integer; overload;
begin
  case (Self.X2 > Self.X1) of
    True:
    if (Self.Y2 > Self.Y1) then
      Exit(2)
    else if (Self.Y2 = Self.Y1) then
      Exit(1);
    False:
    if (Self.X2 = Self.X1) then
      if (Self.Y2 = Self.Y1) then
        Exit(0)
      else if (Self.Y2 > Self.Y1) then
        Exit(1);
  end;
  Result := -1;
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
  <GetH>
  @action: Calculates the absolute height of the box along the Y-axis.
  @note: 
    - Uses an inclusive coordinate calculation ((Y2 - Y1) + 1).
    - If Y1 equals Y2, the function evaluates to a height of 1 pixel/unit, 
      representing a non-degenerate single-line span.
[==============================================================================}
function TBox.GetH: Integer; overload;
begin
  Result := ((Self.Y2 - Self.Y1) + 1);
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
  <GetW>
  @action: Calculates the absolute width of the box along the X-axis.
  @note: 
    - Uses an inclusive coordinate calculation ((X2 - X1) + 1).
    - If X1 equals X2, the function evaluates to a width of 1 pixel/unit, 
      representing a non-degenerate single-column span.
[==============================================================================}
function TBox.GetW: Integer; overload;
begin
  Result := ((Self.X2 - Self.X1) + 1);
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
