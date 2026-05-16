{$IFDEF METHODS}
function Fix: Boolean; overload;
function Invalid: Boolean; overload;
function Valid: Boolean; overload;
function Unusable: Boolean; overload;
function Usable: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Fix>
  Explanation: Fixes the bx. Swaps incorrectly set values (XS/YS > XE/YE).
               Returns true if bx was fixed.
  Example: (200*, 100, 100*, 200) => (100, 100, 200, 200)
[==============================================================================}
function TBox.Fix: Boolean; overload;
var
  x, y: Boolean;
begin
  x := (Self.X1 > Self.X2);
  y := (Self.Y1 > Self.Y2);
  Result := (x or y);
  if not Result then
    Exit;
  if x then
    Swap(Self.X1, Self.X2);
  if y then
    Swap(Self.Y1, Self.Y2);
end;

{==============================================================================]
  <Invalid>
  Explanation: Returns true if TBox is invalid (X1 > X2 or Y1 > Y2)
  Example: None.
[==============================================================================}
function TBox.Invalid: Boolean; overload;
begin
  Result := ((Self.X1 > Self.X2) or (Self.Y1 > Self.Y2));
end;

{==============================================================================]
  <Valid>
  Explanation: Returns true if TBox is valid (X1 <= X2 and Y1 <= Y2)
  Example: None.
[==============================================================================}
function TBox.Valid: Boolean; overload;
begin
  Result := ((Self.X1 <= Self.X2) and (Self.Y1 <= Self.Y2));
end;

{==============================================================================]
  <Usable>
  Explanation: Determines whether the bounding box is invalid or inverted. 
               It checks if either the width or height calculations result 
               in a negative value, meaning the ending coordinates (X2, Y2) 
               mistakenly come before the starting coordinates (X1, Y1).
  Example: 
    * Invalid Box: b.X1=50, b.X2=10 -> (10 - 50) = -40 (< 0) -> True
    * Valid Box:   b.X1=10, b.X2=50 -> (50 - 10) =  40 (not < 0) -> False
    * Pixel Box:   b.X1=10, b.X2=10 -> (10 - 10) =   0 (not < 0) -> False
[==============================================================================}
function TBox.Unusable: Boolean; overload;
begin
  Result := (((b.X2 - b.X1) < 0) or ((b.Y2 - b.Y1) < 0));
end;

{==============================================================================]
  <Usable>
  Explanation: Determines whether the bounding box is valid and has a 
               non-negative area. It ensures that the ending coordinates 
               (X2, Y2) are greater than or equal to the starting 
               coordinates (X1, Y1).
  Example: 
    * Valid Box:   b.X1=10, b.X2=50 -> (50 - 10) = 40 (> -1) -> True
    * Pixel Box:   b.X1=10, b.X2=10 -> (10 - 10) =  0 (> -1) -> True
    * Invalid Box: b.X1=50, b.X2=10 -> (10 - 50) = -40 (not > -1) -> False
[==============================================================================}
function TBox.Usable: Boolean; overload;
begin
  Result := (((b.X2 - b.X1) > -1) and ((b.Y2 - b.Y1) > -1));
end;
{$ENDIF}