{$IFDEF TYPES}
class function Null(const value: Integer = -2147483648): TBox; overload; static;
function Frame(var fWidth, fHeight: Integer): TBox; overload;
function Frame: TBox; overload;  
function Horizontal: TRange; 
function Vertical: TRange; 
function Center: TPoint;  
function Reserve: TPointArray; overload; 
function Reserve(var aBox: TPointArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Null>
  @action: Returns a "null" or empty box, represented by all coordinates set to 
           the specified sentinel value.
  @param: value - Optional integer to use as the sentinel for an empty box. 
                  Defaults to Low(Integer) (-2147483648 for 32-bit integers).
  @note:   This function is typically used to mark non-overlapping boxes resulting 
           from intersection operations. It provides a consistent marker for 
           "empty" boxes.
[==============================================================================}
class function TBox.Null(const value: Integer = -2147483648): TBox; overload;
begin
  Result := Box(value, value, value, value);
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
  <Center>
  @action: Returns Center point from bx.
  @note: None.
[==============================================================================}
function TBox.Center: TPoint;
begin
  Result.X := Round(Self.X1 + ((Self.Width - 1) div 2));
  Result.Y := Round(Self.Y1 + ((Self.Height - 1) div 2));
end;

{==============================================================================]
  <Reserve>
  Explanation: Reselve function for TBox.
  Example: None.
[==============================================================================}
function TBox.Reserve: TPointArray; overload;
begin
  SetLength(Result, Self.Area);
end;

{==============================================================================]
  <Reserve>
  @action: Allocate an TPoint array sized to fit the full box.
  @note: The array is preallocated with the correct length but is not filled 
         with values from X1,Y1..X2,Y2. Elements are default-initialized to 0,0.
[==============================================================================}
function TBox.Reserve(var aBox: TPointArray): Integer; overload;
begin
  Result := Self.Area;
  SetLength(aBox, Result);
end;
{$ENDIF}