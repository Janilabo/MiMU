{$IFDEF TYPES}
function Neighbour(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
function Neighbor(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
function Adjacent(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF HELPERS}
function Surrounding(const adjacency8: Boolean = True): TPointArray; overload;
function Adjacent(const adjacency8: Boolean = True): TPointArray; overload;
procedure Adjacent(var adj: TPointArray; const adjacency8: Boolean = True); overload;
function Adjacency(const adjacency8: Boolean = True): TPointArray; overload;	  
function Neighbours(const adjacency8: Boolean = True): TPointArray; overload;
procedure Neighbours(var adj: TPointArray); overload;
function Neighbors(const adjacency8: Boolean = True): TPointArray; overload;
procedure Neighbors(var adj: TPointArray); overload;
{$ENDIF}

{$IFDEF METHODS}

{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Surrounding>
  @action: Returns an array of points surrounding the current point (Self)
           within a 3×3 neighborhood.
           Includes diagonal neighbors when adjacency8 = True.
  @note: Each point in the result represents an absolute position relative
         to the current point. The center point (Self) is excluded.
         Useful for grid traversal, flood fill, pathfinding, or image
         processing algorithms where nearby cells must be evaluated.
[==============================================================================}
function TPointHelper.Surrounding(const adjacency8: Boolean = True): TPointArray; overload;
var
  r, c, i: Integer;
begin
  SetLength(Result, IfThen(adjacency8, 8, 4));
  i := 0;
  for r := -1 to 1 do
    for c := -1 to 1 do
      if not ((r = 0) and (c = 0)) then
        if (adjacency8 or (Abs(r) + Abs(c) = 1)) then
          Result[i.Increase] := Point((Self.X + c), (Self.Y + r));
end;

{==============================================================================]
  <Neighbour>
  @action: Determines whether the given point `p` is a neighbor of `Self`.
           Considers either 8-way (including diagonals) or 4-way (orthogonal) adjacency.
  @note:  Uses explicit comparisons of absolute differences.
          Excludes `Self` from being a neighbor in 8-way mode.
[==============================================================================}
function TPoint.Neighbour(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
var
  d: TPoint;
begin
  d := Point(Abs(Self.X - p.X), Abs(Self.Y - p.Y));
  if adjacency8 then
    Result := (((d.X <= 1) and (d.Y <= 1)) and (not ((d.X = 0) and (d.Y = 0))))
  else
    Result := (((d.X = 1) and (d.Y = 0)) or ((d.X = 0) and (d.Y = 1)));
end;

{==============================================================================]
  <Neighbor>
  @action: Determines whether the given point `p` is a neighbor of `Self`.
           Considers either 8-way (including diagonals) or 4-way (orthogonal) adjacency.
  @note: Uses a more concise method with Chebyshev distance (Max(dx, dy)) for 8-way
         and Manhattan distance (dx + dy) for 4-way. Excludes `Self` automatically
         because distance 0 is not considered adjacency.
[==============================================================================}
function TPoint.Neighbor(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
var
  d: TPoint;
begin
  d := Point(Abs(Self.X - p.X), Abs(Self.Y - p.Y));
  if adjacency8 then
    Result := (Max(d.X, d.Y) = 1)
  else
    Result := ((d.X + d.Y) = 1);
end;

{==============================================================================]
  <Adjacent>
  @action: Checks whether the given point p is directly adjacent to `Self`.
           Uses a precomputed offset array for 4- or 8-way adjacency.
  @note: Efficient exact comparison. Self is not considered adjacent.
[==============================================================================}
function TPoint.Adjacent(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
const
  o: array[0..7] of TPoint = ((X: 1; Y: 0), (X: 0; Y: 1), (X: -1; Y: 0), (X: 0; Y: -1), (X: 1; Y: 1), (X: 1; Y: -1), (X: -1; Y: 1), (X: -1; Y: -1));
var
  i: Integer;
  c: TPoint;
begin
  c := Point((p.X - Self.X), (p.Y - Self.Y)); 
  for i := 0 to IfThen(adjacency8, 7, 3) do
    if ((c.X = o[i].X) and (c.Y = o[i].Y)) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Adjacent>
  @action: Returns all points adjacent to Self as a TPointArray.
           Can return either 4-way (orthogonal) or 8-way (including diagonals).
  @note: Creates a new dynamic array on each call.
[==============================================================================}
function TPointHelper.Adjacent(const adjacency8: Boolean = True): TPointArray; overload;
begin
  if adjacency8 then
    Exit([Point((Self.X + 1), Self.Y), Point(Self.X, (Self.Y + 1)), Point((Self.X - 1), Self.Y), Point(Self.X, (Self.Y - 1)), Point((Self.X + 1), (Self.Y + 1)), Point((Self.X + 1), (Self.Y - 1)), Point((Self.X - 1), (Self.Y + 1)), Point((Self.X - 1), (Self.Y - 1))]);
  Result := [Point((Self.X + 1), Self.Y), Point(Self.X, (Self.Y + 1)), Point((Self.X - 1), Self.Y), Point(Self.X, (Self.Y - 1))];
end;

{==============================================================================]
  <Adjacent>
  @action: Fills the given point array with the 4 or 8 adjacent points around Self.
  @note: If adjacency8 is True, diagonal neighbors are also included.
[==============================================================================}
procedure TPointHelper.Adjacent(var adj: TPointArray; const adjacency8: Boolean = True); overload;
begin
  adj[0].Create(Self.x, (Self.y - 1));
  adj[3].Create(Self.x, (Self.y + 1));
  adj[1].Create((Self.x + 1), Self.y);
  adj[2].Create((Self.x - 1), Self.y);
  if adjacency8 then
  begin
    adj[4].Create((Self.x - 1), (Self.y - 1));
    adj[5].Create((Self.x + 1), (Self.y - 1));
    adj[6].Create((Self.x - 1), (Self.y + 1));
    adj[7].Create((Self.x + 1), (Self.y + 1));
  end;
end;

{==============================================================================]
  <Adjacency>
  @action: Returns an array of points adjacent to the current point (Self).
           When adjacency8 is True, diagonal neighbors are included.
  @note: The resulting points are absolute coordinates on the same grid.
         Useful for operations like pathfinding, image processing, and
         grid traversal where nearby cells must be inspected.
[==============================================================================}
function TPointHelper.Adjacency(const adjacency8: Boolean = True): TPointArray; overload;
begin
  if adjacency8 then
    Result := [Point((Self.X - 1), (Self.Y - 1)), Point((Self.X - 1), Self.Y), Point((Self.X - 1), (Self.X + 1)), Point(Self.X, (Self.X + 1)), Point((Self.X + 1), (Self.Y + 1)), Point((Self.X + 1), Self.Y), Point((Self.X + 1), (Self.Y - 1)), Point(Self.X, (Self.Y - 1))]
  else
    Result := [Point((Self.X - 1), Self.Y), Point(Self.X, (Self.Y - 1)), Point((Self.X + 1), Self.Y), Point(Self.X, (Self.Y + 1))];
end;

{==============================================================================]
  <Neighbours>
  @action: Returns all neighboring points of Self as a TPointArray.
           Uses a precomputed offset array for 4- or 8-way adjacency.
  @note: Dynamic array is allocated for each call. Offset array ensures correct order.
[==============================================================================}
function TPointHelper.Neighbours(const adjacency8: Boolean = True): TPointArray; overload;
const
  o: array[0..7] of TPoint = ((X: 1; Y: 0), (X: 0; Y: 1), (X: -1; Y: 0), (X: 0; Y: -1), (X: 1; Y: 1), (X: 1; Y: -1), (X: -1; Y: 1), (X: -1; Y: -1));
var
  i: Integer;
begin
  SetLength(Result, IfThen(adjacency8, 8, 4));
  for i := 0 to High(Result) do
    Result[i] := Point((Self.X + o[i].X), (Self.Y + o[i].Y));
end;

{==============================================================================]
  <Neighbours>
  @action:  Populates the provided array with adjacent points in 4 or 8 directions.
  @note:    Uses 8-way adjacency if the array length is greater than 4; 
            otherwise only the 4 cardinal directions are filled.
[==============================================================================}
procedure TPointHelper.Neighbours(var adj: TPointArray); overload;
begin
  adj[0] := Point(Self.x, (Self.y - 1));
  adj[3] := Point(Self.x, (Self.y + 1));
  adj[1] := Point((Self.x + 1), Self.y);
  adj[2] := Point((Self.x - 1), Self.y);
  if (Length(adj) > 4) then
  begin
    adj[4] := Point((Self.x - 1), (Self.y - 1));
    adj[5] := Point((Self.x + 1), (Self.y - 1));
    adj[6] := Point((Self.x - 1), (Self.y + 1));
    adj[7] := Point((Self.x + 1), (Self.y + 1));
  end;
end;

{==============================================================================]
  <Neighbors>
  @action: Returns all neighboring points of Self as a TPointArray (alternative spelling).
           Supports 4-way or 8-way adjacency.
  @note: The first 4 points are orthogonal neighbors; the next 4 (if adjacency8) are diagonals.
[==============================================================================}
function TPointHelper.Neighbors(const adjacency8: Boolean = True): TPointArray; overload;
begin
  with Self do
    Result := [Point((X + 1), Y), Point(X, (Y + 1)), Point((X - 1), Y), Point(X, (Y - 1)),
               Point((X + 1), (Y + 1)), Point((X + 1), (Y - 1)), Point((X - 1), (Y + 1)), Point((X - 1), (Y - 1))];
  if not adjacency8 then
    SetLength(Result, 4);
end;

{==============================================================================]
  <Neighbors>
  @action:  Populates the provided array with adjacent points in 4 or 8 directions.
  @note:    Uses 8-way adjacency if the array length is greater than 4; 
            otherwise only the 4 cardinal directions are filled.
[==============================================================================}
procedure TPointHelper.Neighbors(var adj: TPointArray); overload;
begin
  adj[0].Create(Self.x, (Self.y - 1));
  adj[3].Create(Self.x, (Self.y + 1));
  adj[1].Create((Self.x + 1), Self.y);
  adj[2].Create((Self.x - 1), Self.y);
  if (Length(adj) > 4) then
  begin
    adj[4].Create((Self.x - 1), (Self.y - 1));
    adj[5].Create((Self.x + 1), (Self.y - 1));
    adj[6].Create((Self.x - 1), (Self.y + 1));
    adj[7].Create((Self.x + 1), (Self.y + 1));
  end;
end;
{$ENDIF}