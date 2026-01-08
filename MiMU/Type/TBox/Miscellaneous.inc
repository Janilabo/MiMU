{$IFDEF METHODS}
function Center: TPoint; cdecl;
function Frame(var fWidth, fHeight: Integer): TBox; overload; cdecl;
function Frame: TBox; overload; cdecl; 
function Horizontal: TRange; cdecl;
class function Null(const value: Integer = -2147483648): TBox; overload; cdecl; static;
function Reserve: TPointArray; overload; cdecl;
function Reserve(var aBox: TPointArray): Integer; overload; cdecl;
function Vertical: TRange; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Center>
  @action: Returns Center point from bx.
  @note: None.
[==============================================================================}
function TBox.Center: TPoint; cdecl;
begin
  Result.X := Round(Self.X1 + ((Self.Width - 1) div 2));
  Result.Y := Round(Self.Y1 + ((Self.Height - 1) div 2));
end;

{==============================================================================]
  <Frame>
  @action: Returns the frame of TBox 
  @note: Dimensional box of the TBox. Based on Width and Height.
[==============================================================================}
function TBox.Frame(var fWidth, fHeight: Integer): TBox; overload; cdecl;
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
function TBox.Frame: TBox; overload; cdecl;
begin
  Result := Box(0, 0, (Self.Width - 1), (Self.Height - 1));
end;

{==============================================================================]
  <Horizontal>
  @action: Returns bx.X1 and bx.X2 as TRange.
  @note: Horitonzal-axis.
[==============================================================================}
function TBox.Horizontal: TRange; cdecl;
begin
  Result.start := Self.X1;
  Result.stop := Self.X2;
end;

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
class function TBox.Null(const value: Integer = -2147483648): TBox; overload; cdecl;
begin
  Result := Box(value, value, value, value);
end;

{==============================================================================]
  <Reserve>
  Explanation: Reselve function for TBox.
  Example: None.
[==============================================================================}
function TBox.Reserve: TPointArray; overload; cdecl;
begin
  SetLength(Result, Self.Area);
end;

{==============================================================================]
  <Reserve>
  @action: Allocate an TPoint array sized to fit the full box.
  @note: The array is preallocated with the correct length but is not filled 
         with values from X1,Y1..X2,Y2. Elements are default-initialized to 0,0.
[==============================================================================}
function TBox.Reserve(var aBox: TPointArray): Integer; overload; cdecl;
begin
  Result := Self.Area;
  SetLength(aBox, Result);
end;

{==============================================================================]
  <Vertical>
  @action: Returns bx.Y1 and bx.Y2 as TRange.
  @note: Vertical-axis.
[==============================================================================}
function TBox.Vertical: TRange; cdecl;
begin
  Result.start := Self.Y1;
  Result.stop := Self.Y2;
end;
{$ENDIF}