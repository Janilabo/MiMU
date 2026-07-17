{$IFDEF METHODS}
function Access(const rowID, columnID: Integer): TPoint; overload;
function Access(const pID: Integer): TPoint; overload;
function At(const rowID, columnID: Integer): TPoint; overload;
function At(const pID: Integer): TPoint; overload;
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
{$ENDIF}
