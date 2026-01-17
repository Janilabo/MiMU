{$IFDEF METHODS}
function Center: TPoint;
class function Null(const value: Integer = -2147483648): TBox; overload; static;
function Reserve: TPointArray; overload;
function Reserve(var aBox: TPointArray): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <Reserve>
  Explanation: Reserve function for TBox.
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