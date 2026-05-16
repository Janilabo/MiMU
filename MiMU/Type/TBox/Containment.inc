{$IFDEF METHODS}
function Accepts(const pt: TPoint): Boolean; overload;
function Binds(const pt: TPoint): Boolean; overload;
function Contains(const pt: TPoint): Boolean; overload;
function Contains(const b: TBox): Boolean; overload;
function Disjoint(const target: TBox): Boolean; overload;
function Encase(const pt: TPoint): Boolean; overload;
function Encloses(const pt: TPoint): Boolean; overload;
function Got(const pt: TPoint): Boolean; overload;
function Has(const pt: TPoint): Boolean; overload;
function Holding(const pt: TPoint): Boolean; overload;
function Holds(const pt: TPoint): Boolean; overload;
function Houses(const pt: TPoint): Boolean; overload;
function Housing(const pt: TPoint): Boolean; overload;
function Inside(const target: TBox): Boolean; overload;
function Lacks(const pt: TPoint): Boolean; overload;
function Owns(const pt: TPoint): Boolean; overload;
function Seals(const pt: TPoint): Boolean; overload;
{$ENDIF}

{$IFDEF HELPERS}
function Inside(const targets: TBoxArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Accepts>
  @action: Determines if a point is within the box by checking if enclosing it changes the box's area.
  @note: Relies on Area calculations.
         Fails or yields unpredictable results if coordinate bounds are inverted (e.g., X1 > X2).
[==============================================================================}

function TBox.Accepts(const pt: TPoint): Boolean; overload;
begin
  Result := (Self.Area = Box(Min(pt.X, Self.X1), Min(pt.Y, Self.Y1), Max(pt.X, Self.X2), Max(pt.Y, Self.Y2)).Area);
end;

{==============================================================================]
  <Binds>
  @action: Determines if a point is within the box by measuring its distance from the box's center.
  @note: Requires normalized coordinates (X1 <= X2 and Y1 <= Y2);
         otherwise, the extents calculation yields a negative value, causing a false negative.
[==============================================================================}
function TBox.Binds(const pt: TPoint): Boolean; overload;
begin
  Result := ((Abs(pt.X - ((Self.X1 + Self.X2) div 2)) <= ((Self.X2 - Self.X1) div 2)) and (Abs(pt.Y - ((Self.Y1 + Self.Y2) div 2)) <= ((Self.Y2 - Self.Y1) div 2)));
end;

{==============================================================================]
  <Contains>
  @action: Returns true if pt is inside the given box (bx).
  @note: None.
[==============================================================================}
function TBox.Contains(const pt: TPoint): Boolean; overload;
begin
  Result := not ((pt.X < Self.X1) or (pt.Y < Self.Y1) or (pt.X > Self.X2) or (pt.Y > Self.Y2));
end;

{==============================================================================]
  <Contains>
  @action: Returns true if x is in/within bx boundaries.
  @note: None
[==============================================================================}
function TBox.Contains(const b: TBox): Boolean; overload;
begin
  Result := ((b.X1 >= Self.X1) and (b.X1 <= Self.X2) and (b.X2 >= Self.X1) and (b.X2 <= Self.X2) and (b.Y1 >= Self.Y1) and (b.Y1 <= Self.Y2) and (b.Y2 >= Self.Y1) and (b.Y2 <= Self.Y2));
end;

{==============================================================================]
  <Disjoint>
  @action: Returns true if target TBox is outside the target boundaries.
  @note: None.
[==============================================================================}
function TBox.Disjoint(const target: TBox): Boolean; overload;
begin
  Result := ((Self.X2 < target.X1) or (Self.Y2 < target.Y1) or (Self.X1 > target.X2) or (Self.Y1 > target.Y2));
end;

{==============================================================================]
  <Encase>
  @action: Determines containment by checking if clamping the point forces it to move.
  @note: Relies on Math.EnsureRange. Highly intuitive constraint-based approach.
[==============================================================================}
function TBox.Encase(const pt: TPoint): Boolean; overload;
begin
  Result := (EnsureRange(pt.X, Min(Self.X1, Self.X2), Max(Self.X1, Self.X2)) = pt.X) and (EnsureRange(pt.Y, Min(Self.Y1, Self.Y2), Max(Self.Y1, Self.Y2)) = pt.Y);
end;

{==============================================================================]
  <Encloses>
  @action: Determines if a specific 2D point lies within or on the boundaries of the box.
  @note: None.
[==============================================================================}
function TBox.Encloses(const pt: TPoint): Boolean; overload;
begin
  if ((Self.X1 = Self.X2) or (Self.Y1 = Self.Y2)) then
    Exit(InRange(pt.X, Self.X1, Self.X2) and InRange(pt.Y, Self.Y1, Self.Y2));
  Result := (InRange(((pt.X - Self.X1) / (Self.X2 - Self.X1)), 0, 1) and InRange(((pt.Y - Self.Y1) / (Self.Y2 - Self.Y1)), 0, 1));
end;

{==============================================================================]
  <Got>
  @action: Evaluates bounding box containment by casting positional violations into a temporary array and ensuring the final score is zero.
  @note: Leverages Free Pascal's managed types for automatic clean-up. Best suited for high-level, expressive layout contexts.
[==============================================================================}
function TBox.Got(const pt: TPoint): Boolean; overload;
begin
  Result := (TBooleanArray([(pt.X < Self.X1), (pt.Y < Self.Y1), (pt.X > Self.X2), (pt.Y > Self.Y2)]).Score = 0);
end;

{==============================================================================]
  <Has>
  @action: Determines if a specific 2D point lies within or on the boundaries of the box.
  @note: None.
[==============================================================================}
function TBox.Has(const pt: TPoint): Boolean; overload;
begin
  Result := (((pt.X - Self.X1) * (pt.X - Self.X2) <= 0) and ((pt.Y - Self.Y1) * (pt.Y - Self.Y2) <= 0));
end;

{==============================================================================]
  <Holding>
  @action: Hyper-optimized containment check that evaluates upper and lower bounds simultaneously via unsigned integer casting.
  @note: Requires normalized coordinates (X1 <= X2 and Y1 <= Y2). Highly efficient branchless optimization technique.
[==============================================================================}
function TBox.Holding(const pt: TPoint): Boolean; overload;
begin
  Result := ((Cardinal(pt.X - Self.X1) <= Cardinal(Self.X2 - Self.X1)) and (Cardinal(pt.Y - Self.Y1) <= Cardinal(Self.Y2 - Self.Y1)));
end;

{==============================================================================]
  <Holds>
  @action: Fast, branchless containment check using bitwise right-shifts to inspect integer sign bits.
  @note: Requires normalized box coordinates (X1 <= X2 and Y1 <= Y2). Highly performant as it avoids CPU branching.
[==============================================================================}
function TBox.Holds(const pt: TPoint): Boolean; overload;
var
  s: Integer;
begin
  s := ((SizeOf(Integer) * 8) - 1);
  Result := ((((pt.X - Self.X1) shr s) = 0) and (((Self.X2 - pt.X) shr s) = 0) and (((pt.Y - Self.Y1) shr s) = 0) and (((Self.Y2 - pt.Y) shr s) = 0));
end;

{==============================================================================]
  <Houses>
  @action: Determines if a point is within the box by validating that the sub-boxes formed with the corners do not exceed the original dimensions.
  @note: Requires normalized box coordinates (X1 <= X2 and Y1 <= Y2).
         It will fail with false negatives if the coordinates are inverted.
[==============================================================================}
function TBox.Houses(const pt: TPoint): Boolean; overload;
var
  w, h: Integer;
  b: TBox;
begin
  w := Self.Width;
  h := Self.Height;
  b := Box(pt.X, pt.Y, Self.X2, Self.Y2);
  if ((b.Width > w) or (b.Height > h)) then
    Exit(False);
  b := Box(Self.X1, Self.Y1, pt.X, pt.Y);
  Result := ((b.Width <= w) and (b.Height <= h));
end;

{==============================================================================]
  <Housing>
  @action: Determines containment by accumulating boundary violations as integers and verifying the total is zero.
  @note: Requires normalized box coordinates (X1 <= X2 and Y1 <= Y2). 
         Completely branchless, making it highly optimal for CPU pipelines.
[==============================================================================}
function TBox.Housing(const pt: TPoint): Boolean; overload;
begin
  Result := ((Integer(pt.X < Self.X1) + Integer(pt.Y < Self.Y1) + Integer(pt.X > Self.X2) + Integer(pt.Y > Self.Y2)) = 0);
end;

{==============================================================================]
  <Inside>
  @action: Returns true if bx is INSIDE target boundaries.
  @note: None.
[==============================================================================}
function TBox.Inside(const target: TBox): Boolean; overload;
begin
  Result := not ((Self.X2 < target.X1) or (Self.Y2 < target.Y1) or (Self.X1 > target.X2) or (Self.Y1 > target.Y2));
end;

{==============================================================================]
  <Inside>
  @action: Returns true if bx is in/within any area boundaries by target areas.
  @note: None.
[==============================================================================}
function TBoxHelper.Inside(const targets: TBoxArray): Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(targets) do
    if not ((Self.X2 < targets[i].X1) or (Self.X1 > targets[i].X2) or (Self.Y2 < targets[i].Y1) or (Self.Y1 > targets[i].Y2)) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Lacks>
  @action: Returns true if pt TPoint is OUTSIDE the TBox boundaries.
  @note: None.
[==============================================================================}
function TBox.Lacks(const pt: TPoint): Boolean; overload;
begin
  Result := ((pt.X > Self.X2) or (pt.Y > Self.Y2) or (pt.X < Self.X1) or (pt.Y < Self.Y1));
end;

{==============================================================================]
  <Owns>
  @action: Determines containment by checking the sign alignment of directed distances to all four walls.
  @note: Requires normalized coordinates (X1 <= X2 and Y1 <= Y2). Fails with false positives if coordinates are inverted.
[==============================================================================}
function TBox.Owns(const pt: TPoint): Boolean; overload;
var
  x, y: TRange;
begin
  x := TRange.Construct((pt.X - Self.X1), (Self.X2 - pt.X));
  y := TRange.Construct((pt.Y - Self.Y1), (Self.Y2 - pt.Y));
  Result := (((x.start * y.start) >= 0) and ((x.stop * y.start) >= 0) and ((x.stop * y.stop) >= 0) and ((x.start * y.stop) >= 0));
end;

{==============================================================================]
  <Seals>
  @action: Evaluates inclusion by checking if the origin falls inside the Minkowski Difference box.
  @note: Requires normalized box coordinates.
[==============================================================================}
function TBox.Seals(const pt: TPoint): Boolean; overload;
begin
  Result := (((Self.X1 - pt.X) <= 0) and ((Self.X2 - pt.X) >= 0) and ((Self.Y1 - pt.Y) <= 0) and ((Self.Y2 - pt.Y) >= 0));
end;
{$ENDIF}
