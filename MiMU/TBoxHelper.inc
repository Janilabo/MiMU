{==============================================================================]
  <TBoxHelper.Build>
  @action: Builds TBox using X1, Y1, X2, Y2.
  @note: Unsafe, fast.
[==============================================================================}
function TBoxHelper.Build(const X1, Y1, X2, Y2: Integer): TBox; overload; cdecl;
begin
  Self.X1 := X1;
  Self.Y1 := Y1;
  Self.X2 := X2;
  Self.Y2 := Y2;
  Result := Self;
end;

{==============================================================================]
  <TBoxHelper.Build>
  @action: Builds TBox using 2 points (a = start point, b = end point)..
  @note: Make sure start and end points are correct!
[==============================================================================}
function TBoxHelper.Build(const a, b: TPoint): TBox; overload; cdecl;
begin
  Self.X1 := a.X;
  Self.Y1 := a.Y;
  Self.X2 := b.X;
  Self.Y2 := b.Y;
  Result := Self;
end;

{==============================================================================]
  <TBoxHelper.Create>
  @action: Creates TBox using X1, Y1, X2, Y2.
  @note: Min-Maxed. Creates only valid TBoxes.
[==============================================================================}
function TBoxHelper.Create(const X1, Y1, X2, Y2: Integer): TBox; overload; cdecl;
begin
  Self.X1 := Min(X1, X2);
  Self.Y1 := Min(Y1, Y2);
  Self.X2 := Max(X2, X1);
  Self.Y2 := Max(Y2, Y1);
  Result := Self;
end;

{==============================================================================]
  <TBoxHelper.Create>
  @action: Creates a TBox with 2 points (a, b)..
  @note: Automatically corrects/fixes the incorrect values.
[==============================================================================}
function TBoxHelper.Create(const a, b: TPoint): TBox; overload; cdecl;
begin
  Self.X1 := Min(a.X, b.X);
  Self.Y1 := Min(a.Y, b.Y);
  Self.X2 := Max(a.X, b.X);
  Self.Y2 := Max(a.Y, b.Y);
  Result := Self;
end;

{==============================================================================]
  <TBoxHelper.Form>
  @action: Forms TBox using XY for all X1, Y1, X2, Y2.
  @note: Unsafe, fast.
[==============================================================================}
function TBoxHelper.Form(const XY: Integer = 0): TBox; overload; cdecl;
begin
  Self.X1 := XY;
  Self.Y1 := XY;
  Self.X2 := XY;
  Self.Y2 := XY;
  Result := Self;
end;

{==============================================================================]
  <TBoxHelper.Form>
  @action: Forms TBox using XY for all X1, Y1, X2, Y2.
  @note: Unsafe, fast.
[==============================================================================}
function TBoxHelper.Form(const XY: TPoint): TBox; overload; cdecl;
begin
  Self.X1 := XY.X;
  Self.Y1 := XY.Y;
  Self.X2 := XY.X;
  Self.Y2 := XY.Y;
  Result := Self;
end;

{==============================================================================]
  <TBoxHelper.Make>
  @action: Creates TBox from pt by radius used for width and height.
  @note: None.
[==============================================================================}
function TBoxHelper.Make(const pt: TPoint; const radius: Integer = 0): TBox; overload; cdecl;
begin
  Self.X1 := (pt.X - radius);
  Self.Y1 := (pt.Y - radius);
  Self.X2 := (pt.X + radius);
  Self.Y2 := (pt.Y + radius);
  Result := Self;
end;

{==============================================================================]
  <TBoxHelper.Make>
  @action: Creates TBox from pt by radius used for width and height.
  @note: None.
[==============================================================================}
function TBoxHelper.Make(const pt: TPoint; const wRadius, hRadius: Integer): TBox; overload; cdecl;
begin
  Self.X1 := (pt.X - wRadius);
  Self.Y1 := (pt.Y - hRadius);
  Self.X2 := (pt.X + wRadius);
  Self.Y2 := (pt.Y + hRadius);
  Result := Self;
end;

{==============================================================================]
  <TBoxHelper.Yield>
  @action: Creates box to point, with size for width and height.
  @note: None.
[==============================================================================}
function TBoxHelper.Yield(const pt: TPoint; const size: Integer = 1): TBox; overload; cdecl;
begin
  Self.X1 := pt.X;
  Self.Y1 := pt.Y;
  Self.X2 := (pt.X + (size - 1));
  Self.Y2 := (pt.Y + (size - 1));
  Result := Self;
end;

{==============================================================================]
  <TBoxHelper.Yield>
  @action: Creates box to point, with width and height.
  @note: None.
[==============================================================================}
function TBoxHelper.Yield(const pt: TPoint; const width, height: Integer): TBox; overload; cdecl;
begin
  Self.X1 := pt.X;
  Self.Y1 := pt.Y;
  Self.X2 := (pt.X + (width - 1));
  Self.Y2 := (pt.Y + (height - 1));
  Result := Self;
end;

{==============================================================================]
  <TBoxHelper.Size>
  @action: Stores dimensions from TBox (bx) to width and height variables
  @note: Returns bx area.
[==============================================================================}
function TBoxHelper.Size(var width, height: Integer): Integer; cdecl; inline;
begin
  width := ((Self.X2 - Self.X1) + 1);
  height := ((Self.Y2 - Self.Y1) + 1);
  Result := (width * height);
end;

{==============================================================================]
  <TBoxHelper.Area>
  @action: Calculates the amount of pixels in TBox (bx).
           Returns -1 with invalid TBox.
  @note: None
[==============================================================================}
function TBoxHelper.Area: Integer; cdecl; inline;
begin
  Result := (((Self.X2 - Self.X1) + 1) * ((Self.Y2 - Self.Y1) + 1));
end;

{==============================================================================]
  <TBoxHelper.Diagonal>
  @action: Returns diagonal size of bx.
  @note: None.
[==============================================================================}
function TBoxHelper.Diagonal: Double; cdecl;
begin
  Result := Sqrt(Sqr((Self.X2 - Self.X1) + 1) + Sqr((Self.Y2 - Self.Y1) + 1));
end;

{==============================================================================]
  <TBoxHelper.W>
  @action: Returns bx width.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBoxHelper.W: Integer; overload; cdecl;
begin
  Result := ((Self.X2 - Self.X1) + 1);
end;

{==============================================================================]
  <TBoxHelper.W>
  @action: Sets bx width.
  @note: Returns old width.
[==============================================================================}
function TBoxHelper.W(const width: Integer): Integer; overload; cdecl;
begin
  Result := ((Self.X2 - Self.X1) + 1);
  Self.X2 := (Self.X1 + (width - 1));
end;

{==============================================================================]
  <TBoxHelper.Width>
  @action: Returns bx width.
  @note: Safe, based on Abs() call.
[==============================================================================}
function TBoxHelper.Width: Integer; overload; cdecl;
begin
  Result := (Abs(Self.X2 - Self.X1) + 1);
end;

{==============================================================================]
  <TBoxHelper.Width>
  @action: Sets bx width.
  @note: Returns old width.
[==============================================================================}
function TBoxHelper.Width(const width: Integer): Integer; overload; cdecl;
begin
  Result := (Abs(Self.X2 - Self.X1) + 1);
  Self.X2 := (Self.X1 + (width - 1));
end;

{==============================================================================]
  <TBoxHelper.H>
  @action: Returns bx height.
  @note: Fast, works with only valid TBoxes.
[==============================================================================}
function TBoxHelper.H: Integer; overload; cdecl;
begin
  Result := ((Self.Y2 - Self.Y1) + 1);
end;

{==============================================================================]
  <TBoxHelper.H>
  @action: Sets bx height.
  @note: Returns old height.
[==============================================================================}
function TBoxHelper.H(const height: Integer): Integer; overload; cdecl;
begin
  Result := ((Self.Y2 - Self.Y1) + 1);
  Self.Y2 := (Self.Y1 + (height - 1));
end;

{==============================================================================]
  <TBoxHelper.Height>
  @action: Returns bx height.
  @note: Safe, based on Abs() call.
[==============================================================================}
function TBoxHelper.Height: Integer; overload; cdecl;
begin
  Result := (Abs(Self.Y2 - Self.Y1) + 1);
end;

{==============================================================================]
  <TBoxHelper.Height>
  @action: Sets bx height.
  @note: Returns old height.
[==============================================================================}
function TBoxHelper.Height(const height: Integer): Integer; overload; cdecl;
begin
  Result := (Abs(Self.Y2 - Self.Y1) + 1);
  Self.Y2 := (Self.Y1 + (height - 1));
end;

{==============================================================================]
  <TBoxHelper.Expand>
  @action: Returns bx that has been expanded fully by change.
  @note: Works with positive values only.
[==============================================================================}
function TBoxHelper.Expand(const change: Integer = 1): TBox; cdecl;
begin
  if (change < 1) then
    Exit(Self);
  Result.X1 := (Self.X1 - change);
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := (Self.X2 + change);
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <TBoxHelper.Shrink>
  @action: Returns bx that has been shrinked fully by change.
  @note: Works with positive values only. UNSAFE method, no checks!
[==============================================================================}
function TBoxHelper.Shrink(const change: Integer = 1): TBox; cdecl;
begin
  if (change < 1) then
    Exit(Self);
  Result.X1 := (Self.X1 + change);
  Result.Y1 := (Self.Y1 + change);
  Result.X2 := (Self.X2 - change);
  Result.Y2 := (Self.Y2 - change);
end;

{==============================================================================]
  <TBoxHelper.Resize>
  @action: Returns bx that has been resized fully by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBoxHelper.Resize(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := (Self.X2 + change);
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <TBoxHelper.ResizeVertically>
  @action: Returns bx that has been resized vertically by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBoxHelper.ResizeVertically(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := Self.X2;
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <TBox_ResizeHorizontally>
  @action: Returns bx that has been resized horizontally by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBoxHelper.ResizeHorizontally(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := Self.Y1;
  Result.X2 := (Self.X2 + change);
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBoxHelper.ResizeTop>
  @action: Returns bx that has been resized horizontally by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBoxHelper.ResizeTop(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := Self.X2;
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBoxHelper.ResizeBottom>
  @action: Returns bx that has been resized from bottom by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBoxHelper.ResizeBottom(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := Self.Y1;
  Result.X2 := Self.X2;
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <TBoxHelper.ResizeLeft>
  @action: Returns bx that has been resized from left-side by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBoxHelper.ResizeLeft(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := Self.Y1;
  Result.X2 := Self.X2;
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBoxHelper.ResizeRight>
  @action: Returns bx that has been resized from right-side by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBoxHelper.ResizeRight(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := Self.Y1;
  Result.X2 := (Self.X2 + change);
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBoxHelper.ResizeTopLeft>
  @action: Returns bx that has been resized from top-left by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBoxHelper.ResizeTopLeft(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (Self.X1 - change);
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := Self.X2;
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBoxHelper.ResizeTopRight>
  @action: Returns bx that has been resized from top-right by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBoxHelper.ResizeTopRight(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := (Self.Y1 - change);
  Result.X2 := (Self.X2 + change);
  Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBoxHelper.ResizeBottomRight>
  @action: Returns bx that has been resized from bottom-right by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBoxHelper.ResizeBottomRight(const change: Integer): TBox; cdecl;
begin
  Result.X1 := Self.X1;
  Result.Y1 := Self.Y1;
  Result.X2 := (Self.X2 + change);
  Result.Y2 := (Self.Y2 + change);
end;

{==============================================================================]
  <TBoxHelper.ResizeBottomLeft>
  @action: Returns bx that has been resized from bottom-left by change.
  @note: Change value can be also negative - so be careful with it! :)
[==============================================================================}
function TBoxHelper.ResizeBottomLeft(const change: Integer): TBox; cdecl;
begin
  Result.X1 := (bx.X1 - change);
  Result.Y1 := bx.Y1;
  Result.X2 := bx.X2;
  Result.Y2 := (bx.Y2 + change);
end;

{==============================================================================]
  <TBoxHelper.Equal>
  @action: Returns true if bx1 and bx2 are identical.
  @note: None
[==============================================================================}
function TBoxHelper.Equal(const b: TBox): Boolean; cdecl; inline;
begin
  Result := ((Self.X1 = b.X1) and (Self.Y1 = b.Y1) and (Self.X2 = b.X2) and (Self.Y2 = b.Y2));
end;  

{==============================================================================]
  <TBoxHelper.Contains>
  @action: Returns true if pt is inside the given box (bx).
  @note: None.
[==============================================================================}
function TBoxHelper.Contains(const pt: TPoint): Boolean; overload; cdecl;
begin
  Result := not ((pt.X < Self.X1) or (pt.Y < Self.Y1) or (pt.X > Self.X2) or (pt.Y > Self.Y2));
end;

{==============================================================================]
  <TBoxHelper.Contains>
  @action: Returns true if x is in/within bx boundaries.
  @note: None
[==============================================================================}
function TBoxHelper.Contains(const b: TBox): Boolean; overload; cdecl;
begin
  Result := ((b.X1 >= Self.X1) and (b.X1 <= Self.X2) and (b.X2 >= Self.X1) and (b.X2 <= Self.X2) and (b.Y1 >= Self.Y1) and (b.Y1 <= Self.Y2) and (b.Y2 >= Self.Y1) and (b.Y2 <= Self.Y2));
end;

{==============================================================================]
  <TBoxHelper.InArea>
  @action: Returns true if bx is in/within area boundaries.
  @note: None
[==============================================================================}
function TBoxHelper.InArea(const area: TBox): Boolean; overload; cdecl;
begin
  Result := not ((Self.X2 < area.X1) or (Self.Y2 < area.Y1) or (Self.X1 > area.X2) or (Self.Y1 > area.Y2)); 
end;

{==============================================================================]
  <TBoxHelper.InArea>
  @action: Returns true if bx is in/within any area boundaries by areas.
  @note: None
[==============================================================================}
function TBoxHelper.InArea(const areas: TBoxArray): Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 0 to High(areas) do
    if not ((Self.X2 < areas[i].X1) or (Self.X1 > areas[i].X2) or (Self.Y2 < areas[i].Y1) or (Self.Y1 > areas[i].Y2)) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <TBoxHelper.Inside>
  @action: Returns true if bx is INSIDE area boundaries.
  @note: Performs different action than TBox_In!
[==============================================================================}
function TBoxHelper.Inside(const area: TBox): Boolean; overload; cdecl;
begin
  Result := ((Self.X1 > area.X1) and (Self.X1 < area.X2) and (Self.X2 > area.X1) and (Self.X2 < area.X2) and (Self.Y1 > area.Y1) and (Self.Y1 < area.Y2) and (Self.Y2 > area.Y1) and (Self.Y2 < area.Y2));
end;

{==============================================================================]
  <TBoxHelper.Inside>
  @action: Returns true if bx is INSIDE area boundaries by areas.
  @note: Performs different action than TBox_In!
[==============================================================================}
function TBoxHelper.Inside(const areas: TBoxArray): Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 0 to High(areas) do
    if ((Self.X1 > areas[i].X1) and (Self.X1 < areas[i].X2) and (Self.X2 > areas[i].X1) and (Self.X2 < areas[i].X2) and (Self.Y1 > areas[i].Y1) and (Self.Y1 < areas[i].Y2) and (Self.Y2 > areas[i].Y1) and (Self.Y2 < areas[i].Y2)) then
      Exit(True);
  Result := False;
end; 

{==============================================================================]
  <TBox_Center>
  @action: Returns Center point from bx.
  @note: None.
[==============================================================================}
function TBoxHelper.Center: TPoint; cdecl;
begin
  Result.X := Round(Self.X1 + ((Self.X2 - Self.X1) div 2));
  Result.Y := Round(Self.Y1 + ((Self.Y2 - Self.Y1) div 2));
end;

{==============================================================================]
  <TBoxHelper.Envelope>
  @action: Bounds 2 boxes (a and b) to 1 box.
  @note: Based on lowest / highest coordinate values.
[==============================================================================}
function TBoxHelper.Envelope(const b: TBox): TBox; cdecl;
begin
  Result.X1 := Min(Min(Self.X1, Self.X2), Min(b.X1, b.X2));
  Result.Y1 := Min(Min(Self.Y1, Self.Y2), Min(b.Y1, b.Y2));
  Result.X2 := Max(Max(Self.X1, Self.X2), Max(b.X1, b.X2));
  Result.Y2 := Max(Max(Self.Y1, Self.Y2), Max(b.Y1, b.Y2));
end;

{==============================================================================]
  <TBoxHelper.Overlap>
  @action: Returns true if a and b are in anykind of contact with each other.
  @note: None
[==============================================================================}
function TBoxHelper.Overlap(const b: TBox): Boolean; cdecl; inline;
begin
  Result := not ((Self.X1 > b.X2) or (Self.X2 < b.X1) or (Self.Y1 > b.Y2) or (Self.Y2 < b.Y1));
end;

{==============================================================================]
  <TBoxHelper.Intersection>
  @action: Returns true if a and b are in anykind of contact with each other.
  @note: None
[==============================================================================}
function TBoxHelper.Intersection(const b: TBox): TBox; cdecl;
begin
  Result.X1 := Max(Self.X1, b.X1);
  Result.Y1 := Max(Self.Y1, b.Y1);
  Result.X2 := Min(Self.X2, b.X2);
  Result.Y2 := Min(Self.Y2, b.Y2);
end;

{==============================================================================]
  <TBoxHelper.Intersect>
  @action: Returns true if a and b are in anykind of contact with each other.
  @note: None
[==============================================================================}
function TBoxHelper.Intersect(const b: TBox; var intersection: TBox): Boolean; cdecl;
begin
  intersection := Self.Intersection(b);
  Result := not ((intersection.X1 > intersection.X2) or (intersection.Y1 > intersection.Y2));
end;

{==============================================================================]
  <TBoxHelper.Union>
  @action: Returns true if a and b are in anykind of contact with each other.
  @note: None
[==============================================================================}
function TBoxHelper.Union(const b: TBox): TBox; cdecl;
begin
  Result.X1 := Min(Self.X1, b.X1);
  Result.Y1 := Min(Self.Y1, b.Y1);
  Result.X2 := Max(Self.X2, b.X2);
  Result.Y2 := Max(Self.Y2, b.Y2);
end;

{==============================================================================]
  <TBox_Valid>
  Explanation: Returns true if TBox is valid (X1 <= X2 and Y1 <= Y2)
  Example: None.
[==============================================================================}
function TBoxHelper.Valid: Boolean; cdecl; inline;
begin
  Result := ((Self.X1 <= Self.X2) and (Self.Y1 <= Self.Y2));
end;

{==============================================================================]
  <TBoxHelper.Invalid>
  Explanation: Returns true if TBox is invalid (X1 > X2 or Y1 > Y2)
  Example: None.
[==============================================================================}
function TBoxHelper.Invalid: Boolean; cdecl;
begin
  Result := ((Self.X1 > Self.X2) or (Self.Y1 > Self.Y2));
end;

{==============================================================================]
  <TBox_Similar>
  @action: Returns true if the dimensions from boxes bx1 and bx2
           are within maxWDiff (max width differency) and maxHDiff (max height differency).
  @note: None
[==============================================================================}
function TBoxHelper.Similar(const b: TBox; const maxWDiff, maxHDiff: Integer): Boolean; overload; cdecl;
begin
  Result := ((Abs(((b.X2 - b.X1) + 1) - ((Self.X2 - Self.X1) + 1)) <= maxWDiff) and (Abs(((b.Y2 - b.Y1) + 1) - ((Self.Y2 - Self.Y1) + 1)) <= maxHDiff));
end;

{==============================================================================]
  <TBoxHelper.Similar>
  @action: Returns true if the dimensions from boxes bx1 and bx2
           are within diff (max width and height differency).
  @note: None
[==============================================================================}
function TBoxHelper.Similar(const b: TBox; const diff: Integer): Boolean; overload; cdecl;
begin
  Result := ((Abs(((b.X2 - b.X1) + 1) - ((Self.X2 - Self.X1) + 1)) <= diff) and (Abs(((b.Y2 - b.Y1) + 1) - ((Self.Y2 - Self.Y1) + 1)) <= diff));
end;

{==============================================================================]
  <TBoxHelper.Fix>
  Explanation: Fixes the bx. Swaps incorrectly set values (XS/YS > XE/YE).
               Returns true if bx was fixed.
  Example: (200*, 100, 100*, 200) => (100, 100, 200, 200)
[==============================================================================}
function TBoxHelper.Fix: Boolean; cdecl;
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
  <TBoxHelper.Constraint>
  Explanation: Constraints bx to area.
  Example: None.
[==============================================================================}
function TBoxHelper.Constraint(const area: TBox): Boolean; cdecl;
var
  b: TBox;
begin
  b := bx;
  Self.X1 := Max(area.X1, Min(area.X2, Self.X1));
  Self.Y1 := Max(area.Y1, Min(area.Y2, Self.Y1));
  Self.X2 := Max(area.X1, Min(area.X2, Self.X2));
  Self.Y2 := Max(area.Y1, Min(area.Y2, Self.Y2));
  Result := (Self <> b);
end;

{==============================================================================]
  <TBoxHelper.Clip>
  Explanation: Returns bx that has been constrained to area.
  Example: None.
[==============================================================================}
function TBoxHelper.Clip(const area: TBox): TBox; cdecl;
begin
  Result.X1 := Max(area.X1, Min(area.X2, Self.X1));
  Result.Y1 := Max(area.Y1, Min(area.Y2, Self.Y1));
  Result.X2 := Max(area.X1, Min(area.X2, Self.X2));
  Result.Y2 := Max(area.Y1, Min(area.Y2, Self.Y2));
end;

{==============================================================================]
  <TBox_Restrict>
  Explanation: Restricts bx to area.
  Example: None.
[==============================================================================}
function TBoxHelper.Restrict(const area: TBox): Boolean; cdecl;
var
  b: TBox;
begin
  b := Self;
  if (Self.X1 < area.X1) then
    Self.X1 := area.X1
  else
    if (Self.X1 > area.X2) then
      Self.X1 := area.X2;
  if (Self.Y1 < area.Y1) then
    Self.Y1 := area.Y1
  else
    if (Self.Y1 > area.Y2) then
      Self.Y1 := area.Y2;
  if (Self.X2 > area.X2) then
    Self.X2 := area.X2
  else
    if (Self.X2 < area.X1) then
      Self.X2 := area.X1;
  if (Self.Y2 > area.Y2) then
    Self.Y2 := area.Y2
  else
    if (Self.Y2 < area.Y1) then
      Self.Y2 := area.Y1;
  Result := (Self <> b);
end;

{==============================================================================]
  <TBox_Clamp>
  Explanation: Returns bx that has been restricted to area.
  Example: None.
[==============================================================================}
function TBoxHelper.Clamp(const area: TBox): TBox; cdecl;
begin
  if (Self.X1 < area.X1) then
    Result.X1 := area.X1
  else
    if (Self.X1 > area.X2) then
      Result.X1 := area.X2
    else
      Result.X1 := Self.X1;
  if (Self.Y1 < area.Y1) then
    Result.Y1 := area.Y1
  else
    if (Self.Y1 > area.Y2) then
      Result.Y1 := area.Y2
    else
      Result.Y1 := Self.Y1;
  if (Self.X2 > area.X2) then
    Result.X2 := area.X2
  else
    if (Self.X2 < area.X1) then
      Result.X2 := area.X1
    else
      Result.X2 := Self.X2;
  if (Self.Y2 > area.Y2) then
    Result.Y2 := area.Y2
  else
    if (Self.Y2 < area.Y1) then
      Result.Y2 := area.Y1
    else
      Result.Y2 := Self.Y2;
end;

{==============================================================================]
  <TBox_Points>
  Explanation: Returns TBox points as TPointArray.
  Example: None.
[==============================================================================}
function TBoxHelper.Points: TPointArray; cdecl;
var
  x, y, r: Integer;
begin
  SetLength(Result, (((Self.X2 - Self.X1) + 1) * ((Self.Y2 - Self.Y1) + 1)));
  r := 0;
  for y := Self.Y1 to Self.Y2 do
    for x := Self.X1 to Self.X2 do
	  Result[r.Increase].Create(x, y);
end;

{==============================================================================]
  <TBoxHelper.TPointArray>
  Explanation: Returns TBox points as TPointArray.
  Example: None.
[==============================================================================}
function TBoxHelper.TPointArray: TPointArray; cdecl;
var
  i, w, h, x, y: Integer;
begin
  w := ((Self.X2 - Self.X1) + 1);
  h := ((Self.Y2 - Self.Y1) + 1);
  SetLength(Result, (w * h));
  for i := 0 to ((w * h) - 1) do
    Result[i].Create((Self.X1 + (i mod w)), (Self.Y1 + (i div w)));
end;

{==============================================================================]
 <TBoxHelper.Grid>
 @action: Outputs/builds grid of boxes with parameters;
          bx = starting box, used for starting coordinates and also for dimensions (width & height) of the boxes.
          rows, columns = count of rows and columns
          spaceHorizontal = space between columns
          spaceVertical = space between rows
 @note: None.
[==============================================================================}
function TBoxHelper.Grid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TBoxArray; cdecl;
var
  w, h, r, c, i, x, y: Integer;
begin
  if (((rows > -1) and (columns > -1)) and ((rows * columns) > 0)) then
  begin
    TBox_Size(Self, w, h);
    SetLength(Result, (rows * columns));
    for r := 0 to (rows - 1) do
    begin
      y := (Self.Y1 + (r * (h + spaceVertical)));
      for c := 0 to (columns - 1) do
      begin
        i := ((r * columns) + c);
        x := (Self.X1 + (c * (w + spaceHorizontal)));
		Result[i] := TBox_Build(x, y, (x + (w - 1)), (y + (h - 1)));
      end;
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <TBoxHelper.Row>
 @action: Outputs row of boxes. Starting from bx,
          where space is the amount of space between each cell.
 @note: None
[==============================================================================}
function TBoxHelper.Row(const cells: Integer; const space: Integer = 0): TBoxArray; cdecl;
var
  w, h, i, z: Integer;
begin
  if (cells > 0) then
  begin
    TBox_Size(Self, w, h);
    SetLength(Result, cells);
    for i := 0 to (cells - 1) do
    begin
      z := (Self.X1 + (i * (w + space)));
	  Result[i] := TBox_Build(z, Self.Y1, (z + (w - 1)), Self.Y2);
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <TBox_Column>
 @action: Outputs column of boxes. Starting from bx,
          where space is the amount of space between each cell.
 @note: None
[==============================================================================}
function TBoxHelper.Column(const cells: Integer; const space: Integer = 0): TBoxArray; cdecl;
var
  w, h, i, z: Integer;
begin
  if (cells > 0) then
  begin
    TBox_Size(Self, w, h);
    SetLength(Result, cells);
    for i := 0 to (cells - 1) do
    begin
      z := (Self.Y1 + (i * (h + space)));
	  Result[i] := TBox_Build(Self.X1, z, Self.X2, (z + (h - 1)));
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
 <TBoxHelper.CornerPoints>
 @action: Returns all 4 corner points of bx.
 @note: None
[==============================================================================}
function TBoxHelper.CornerPoints: TPointArray; cdecl;
begin
  SetLength(Result, 4);
  Result[0].X := Self.X1;
  Result[0].Y := Self.Y1;
  Result[1].X := Self.X2;
  Result[1].Y := Self.Y1;
  Result[2].X := Self.X2;
  Result[2].Y := Self.Y2;
  Result[3].X := Self.X1;
  Result[3].Y := Self.Y2;
end;

{==============================================================================]
 <TBoxHelper.Corners>
 @action: Returns corner points of bx.
 @note: Outputs only unique TPoints.
[==============================================================================}
function TBoxHelper.Corners: TPointArray; cdecl;
var
  p: TPoint;
begin
  SetLength(Result, 0);
  case ((Ord(Boolean(Self.X1 = Self.X2)) shl 1) or Ord(Boolean(Self.Y1 = Self.Y2))) of
    0: Result := [p.Create(Self.X1, Self.Y1), p.Create(Self.X2, Self.Y1), p.Create(Self.X2, Self.Y2), p.Create(Self.X1, Self.Y2)];
    1: Result := [p.Create(Self.X1, Self.Y1), p.Create(Self.X2, Self.Y1)];
    2: Result := [p.Create(Self.X1, Self.Y1), p.Create(Self.X1, Self.Y2)];
    3: Result := [p.Create(Self.X1, Self.Y1)];
  end;
end;

{==============================================================================]
  <TBoxHelper.SimilarSize>
  @action: Returns true if the size from boxes a and b
           are within widthDifferency and heightDifferency.
  @note: None.
[==============================================================================}
function TBoxHelper.SimilarSize(const b: TBox; const widthDifferency, heightDifferency: Integer): Boolean; overload; cdecl;
begin
  Result := ((Abs(((b.X2 - b.X1) + 1) - ((Self.X2 - Self.X1) + 1)) <= widthDifferency) and (Abs(((b.Y2 - b.Y1) + 1) - ((Self.Y2 - Self.Y1) + 1)) <= heightDifferency));
end;

{==============================================================================]
  <TBox_SimilarSize>
  Explanation: Returns true if the size from boxes a and b
               are within differency.
  @note: None.
[==============================================================================}
function TBoxHelper.SimilarSize(const b: TBox; const differency: Integer): Boolean; overload; cdecl;
begin
  Result := ((Abs(((b.X2 - b.X1) + 1) - ((Self - Self.X1) + 1)) <= differency) and (Abs(((b.Y2 - b.Y1) + 1) - ((Self.Y2 - Self.Y1) + 1)) <= differency));
end;

{==============================================================================]
  <TBox_Centered>
  Explanation: Returns bx (by the dimensions) centered to area.
  @note: None.
[==============================================================================}
function TBoxHelper.Centered(const area: TBox): TBox; cdecl;
var
  w, h: Integer;
begin
  TBox_Size(Self, w, h);
  Result.X1 := (area.X1 + ((TBox_Width(area) - w) div 2));
  Result.Y1 := (area.Y1 + ((TBox_Height(area) - h) div 2));
  Result.X2 := (Result.X1 + (w - 1));
  Result.Y2 := (Result.Y1 + (h - 1));
end;

{==============================================================================]
  <TBoxHelper.CenterVertically>
  Explanation: Returns bx centered vertically to area.
  @note: None.
[==============================================================================}
function TBoxHelper.CenterVertically(const area: TBox): TBox; cdecl;
var
  h: Integer;
begin
  h := TBox_H(Self);
  Result.X1 := Self.X1;
  Result.Y1 := (area.Y1 + ((TBox_H(area) - h) div 2));
  Result.X2 := Self.X2;
  Result.Y2 := (Result.Y1 + (h - 1));
end;

{==============================================================================]
  <TBoxHelper.CenterHorizontally>
  Explanation: Returns bx centered horizontally to area.
  @note: None.
[==============================================================================}
function TBoxHelper.CenterHorizontally(const area: TBox): TBox; cdecl;
var
  w: Integer;
begin
  w := TBox_W(Self);
  Result.X1 := (area.X1 + ((TBox_W(area) - w) div 2));
  Result.X2 := (Result.X1 + (w - 1));
  Result.Y1 := Self.Y1;
  Result.Y2 := Self.Y2;
end;
