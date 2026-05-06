{$IFDEF METHODS}
function Contract(const N: Integer = 1): TRange; overload;
function Contracted(const N: Integer = 1): TRange; overload;
function Expand(const N: Integer = 1): TRange; overload;
function Expanded(const N: Integer = 1): TRange; overload;
function ExpandStart: TRange; overload;
function ExpandStop: TRange; overload;
function ShrinkStart: TRange; overload;
function ShrinkStop: TRange; overload;
function SnipStart: Boolean; overload;
function SnipStop: Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Contract>
  @action: Moves both range bounds toward each other by the given amount N,
           effectively reducing the range span. Modifies Self in place and
           returns the original (pre-contracted) range.
  @note:   Direction-aware; contracts correctly for both ascending and
           descending ranges.
[==============================================================================}
function TRange.Contract(const N: Integer = 1): TRange; overload;
begin
  Result := Self;
  if Self.Ascending then
    Self.Modify(N, -N)
  else
    Self.Modify(-N, N);
end;

{==============================================================================]
  <Contracted>
  @action: Returns a new TRange contracted by the given amount N without
           modifying Self.
  @note:   Functional style version of Contract; preserves Self and is safe
           for use in expressions or chainable operations.
[==============================================================================}
function TRange.Contracted(const N: Integer = 1): TRange; overload;
begin
  if Self.Ascending then
    Result.Create((Self.start + N), (Self.stop - N))
  else
    Result.Create((Self.start - N), (Self.stop + N));
end;

{==============================================================================]
  <Expand>
  @action: Moves both bounds of the range away from each other by the given
           amount N, effectively increasing the span of the range. Modifies Self
           in place and returns the original (pre-expanded) range.
  @note:   Direction-aware; expands correctly for both ascending and descending
           ranges. Used when the current range should grow outward.
[==============================================================================}
function TRange.Expand(const N: Integer = 1): TRange; overload;
begin
  Result := Self;
  if Self.Ascending then
    Self.Modify(-N, N)
  else
    Self.Modify(N, -N);
end;

{==============================================================================]
  <Expanded>
  @action: Returns a new TRange expanded by the given amount N without modifying
           Self.
  @note:   Functional version of Expand. Preserves the original range and can
           be used in expression-style or chainable operations. Handles both
           ascending and descending ranges.
[==============================================================================}
function TRange.Expanded(const N: Integer = 1): TRange; overload;
begin
  if Self.Ascending then
    Result.Create((Self.start - N), (Self.stop + N))
  else
    Result.Create((Self.start + N), (Self.stop - N));
end;

{==============================================================================]
  <ExpandStart>
  @action: Increments the range's magnitude by moving the start point outward.
  @note: Increases the distance between boundaries; moves toward negative 
         infinity in a forward range or positive infinity in a reverse range.
[==============================================================================}
function TRange.ExpandStart: TRange; overload;
begin
  if (Self.start > Self.stop) then
    Result := TRange.Construct((Self.start + 1), Self.stop)
  else
    Result := TRange.Construct((Self.start - 1), Self.stop);
end;

{==============================================================================]
  <ExpandStop>
  @action: Increments the range's magnitude by moving the stop point outward.
  @note: Increases the distance between boundaries; moves toward positive 
         infinity in a forward range or negative infinity in a reverse range.
[==============================================================================}
function TRange.ExpandStop: TRange; overload;
begin
  if (Self.stop > Self.start) then
    Result := TRange.Construct(Self.start, (Self.stop + 1))
  else
    Result := TRange.Construct(Self.start, (Self.stop - 1));
end;

{==============================================================================]
  <ShrinkStart>
  @action: Decreases the range's magnitude by moving the start point inward.
  @note: Returns Self if Singular; otherwise moves start closer to stop 
         without crossing it.
[==============================================================================}
function TRange.ShrinkStart: TRange; overload;
begin
  if Self.Singular then
    Result := Self
  else if (Self.start > Self.stop) then
    Result := TRange.Construct((Self.start - 1), Self.stop)
  else
    Result := TRange.Construct((Self.start + 1), Self.stop);
end;

{==============================================================================]
  <ShrinkStop>
  @action: Decreases the range's magnitude by moving the stop point inward.
  @note: Returns Self if Singular; otherwise moves stop closer to start 
         without crossing it.
[==============================================================================}
function TRange.ShrinkStop: TRange; overload;
begin
  if Self.Singular then
    Result := Self
  else if (Self.stop > Self.start) then
    Result := TRange.Construct(Self.start, (Self.stop - 1))
  else
    Result := TRange.Construct(Self.start, (Self.stop + 1));
end;

{==============================================================================]
  <SnipStart>
  @action: Shifts the start boundary one unit toward the stop position.
  @note: Returns True if the move was successful; False if start already equals stop.
[==============================================================================}
function TRange.SnipStart: Boolean; overload;
begin
  Result := (Self.start <> Self.stop);
  if not Result then
    Exit;
  if (Self.start > Self.stop) then
    Dec(Self.start)
  else
    Inc(Self.start);
end;

{==============================================================================]
  <SnipStop>
  @action: Shifts the stop boundary one unit toward the start position.
  @note: Returns True if the move was successful; False if stop already equals start.
[==============================================================================}
function TRange.SnipStop: Boolean; overload;
begin
  Result := (Self.stop <> Self.start);
  if not Result then
    Exit;
  if (Self.stop > Self.start) then
    Dec(Self.stop)
  else
    Inc(Self.stop);
end;
{$ENDIF}