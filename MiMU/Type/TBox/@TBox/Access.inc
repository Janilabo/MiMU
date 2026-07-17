{$IFDEF METHODS}
function Access(const rowID, columnID: Integer): TPoint; overload;
function Access(const pID: Integer): TPoint; overload;
function At(const rowID, columnID: Integer): TPoint; overload;
function At(const pID: Integer): TPoint; overload;
function Get(const rowID, columnID: Integer): TPoint; overload;
function Get(const pID: Integer): TPoint; overload;
function Map(const rowID, columnID: Integer): TPoint; overload;
function Map(const pID: Integer): TPoint; overload;
function Read(const rowID, columnID: Integer): TPoint; overload;
function Read(const pID: Integer): TPoint; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <At>
  @action: Directly locates a 2D spatial TPoint coordinate using 0-indexed row 
           and column offsets relative to the box's top-left origin.
  @note: 
    - Designed for raw speed: bypasses boundary validation checks to maximize 
      performance in tight rendering loops.
    - Expects 'rowID' and 'columnID' to start at 0, matching the exact mathematical 
      offsets of your linear array suites.
[==============================================================================}
function TBox.At(const rowID, columnID: Integer): TPoint; overload;
begin
  Result := Point((Self.X1 + columnID), (Self.Y1 + rowID));
end;

{==============================================================================]
  <At>
  @action: Directly locates a 2D spatial TPoint coordinate using a flat, 
           0-indexed sequential index.
  @note: 
    - Optimized for performance: completely bypasses boundary validation checks 
      for maximum execution speed in intensive processing pipelines.
    - Uses your core row-major formulas ('mod' and 'div') to project a single 
      linear position back into spatial coordinates on the fly.
[==============================================================================}
function TBox.At(const pID: Integer): TPoint; overload;
begin
  Result := Point((Self.X1 + (pID mod Self.Width)), (Self.Y1 + (pID div Self.Width)));
end;

{==============================================================================]
  <Access>
  @action: Safely extracts a 2D spatial TPoint coordinate using 0-indexed row 
           and column offsets relative to the box's top-left origin.
  @note: 
    - The defensive, boundary-checked companion to 'At(rowID, columnID)'.
    - Validates inputs against 'Self.Width' and 'Self.Height'; if any coordinate 
      falls out of bounds, it handles the safety fallback by returning Point(0, 0).
[==============================================================================}
function TBox.Access(const rowID, columnID: Integer): TPoint; overload;
begin
  if ((rowID < 0) or (columnID < 0) or (rowID >= Self.Height) or (columnID >= Self.Width)) then
    Exit(Point(0, 0));
  Result.X := (Self.X1 + columnID);
  Result.Y := (Self.Y1 + rowID);
end;

{==============================================================================]
  <Access>
  @action: Translates a single 1D flat index into its corresponding 2D spatial
           TPoint coordinate inside the box boundaries.
  @note:
    - Complements 'Filled' and 'Filling' by calculating coordinates on-the-fly
      without allocating an entire array.
    - If the pID is out of range (less than 0 or greater than or equal to Area),
      it handles the safety fallback cleanly.
[==============================================================================}
function TBox.Access(const pID: Integer): TPoint; overload;
begin
  if ((pID < 0) or (pID >= Self.Area)) then
    Exit(Point(0, 0));
  Result.X := (Self.X1 + (pID mod Self.Width));
  Result.Y := (Self.Y1 + (pID div Self.Width));
end;

{==============================================================================]
  <Get>
  @action: Converts a 2D grid offset (rowID, columnID) into an absolute screen/canvas coordinate (TPoint).
  @note: Automatically clamps values using EnsureRange so out-of-bounds inputs stick to the inside edges of the box.
[==============================================================================}
function TBox.Get(const rowID, columnID: Integer): TPoint; overload;
begin
  Result := Point((Self.X1 + EnsureRange(columnID, 0, (Self.Width  - 1))), (Self.Y1 + EnsureRange(rowID, 0, (Self.Height - 1))));
end;

{==============================================================================]
  <Get>
  @action: Converts a 1D index (pID) into a 2D coordinate (TPoint) within the box bounds, safely wrapping out-of-bounds indices.
  @note: Uses a double modulo operation to correctly handle negative pID values.
[==============================================================================}
function TBox.Get(const pID: Integer): TPoint; overload;
var
  a, w, h: Integer;
begin
  a := Self.Size(w, h);
  h := (((pID mod a) + a) mod a);
  Result.X := (Self.X1 + (h mod w));
  Result.Y := (Self.Y1 + (h div w));
end;

{==============================================================================]
  <Map>
  @action: Converts a 2D grid offset (rowID, columnID) into an absolute coordinate (TPoint), clamping values to the box bounds.
  @note: Streamlines the logic by combining Max(0, ...) for the lower bound and an IfThen call for the upper bound.
[==============================================================================}
function TBox.Map(const rowID, columnID: Integer): TPoint; overload;
begin
  Result.X := (Self.X1 + Max(0, IfThen((columnID < Self.Width),  columnID, (Self.Width  - 1))));
  Result.Y := (Self.Y1 + Max(0, IfThen((rowID < Self.Height), rowID, (Self.Height - 1))));
end;

{==============================================================================]
  <Map>
  @action: Converts a 1D flat index (pID) into an absolute 2D coordinate (TPoint) within the box area bounds.
  @note: Clamps the pID to the valid area index range (0 to Area - 1) before performing the 2D grid mapping calculations.
[==============================================================================}
function TBox.Map(const pID: Integer): TPoint; overload;
var
  p: Integer;
begin
  p := Max(0, IfThen((pID < Self.Area), pID, (Self.Area - 1)));
  Result.X := (Self.X1 + (p mod Self.Width));
  Result.Y := (Self.Y1 + (p div Self.Width));
end;

{==============================================================================]
  <Read>
  @action: Converts a 2D grid offset (rowID, columnID) into an absolute coordinate (TPoint),
           clamping values to the box boundaries.
  @note: Uses nested Max(0, Min(...)) calls as a manual boundary clamp instead of EnsureRange.
[==============================================================================}
function TBox.Read(const rowID, columnID: Integer): TPoint; overload;
begin
  Result.X := (Self.X1 + Max(0, Min(columnID, (Self.Width - 1))));
  Result.Y := (Self.Y1 + Max(0, Min(rowID, (Self.Height - 1))));
end;

{==============================================================================]
  <Read>
  @action: Converts a 1D flat index (pID) into a 2D coordinate (TPoint) within the box bounds.
  @note: Breaks down the 1D index using standard div/mod by Width, passing the results directly to the 2D Read overload.
[==============================================================================}
function TBox.Read(const pID: Integer): TPoint; overload;
begin
  Result := Self.Read((pID div Self.Width), (pID mod Self.Width));
end;
{$ENDIF}
