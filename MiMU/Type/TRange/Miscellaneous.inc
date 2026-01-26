{$IFDEF METHODS}
function Centered(const rCenter: Integer): TRange; overload;
function Frame(var rSize: Integer): TRange; overload;
function Frame: TRange; overload;
function Reserve: TIntegerArray; overload;
function Reserve(var aRange: TIntegerArray): Integer; overload;
function Split(var rLeft, rRight: TRange): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Centered>
  @action: Returns a new TRange that has the same length as Self but is
           repositioned so that its midpoint equals the specified Center value.
           Self remains unchanged.
  @note:   Direction-aware; preserves ascending or descending order.
           Useful for geometric or data range realignment.
[==============================================================================}
function TRange.Centered(const rCenter: Integer): TRange; overload;
var
  h: Integer;
begin
  h := Self.Half;
  if Self.Ascending then
    Result.Create((rCenter - h), (rCenter + h))
  else
    Result.Create((rCenter + h), (rCenter - h));
end;

{==============================================================================]
  <Frame>
  @action Returns a TRange covering the full extent of this instance,
          starting at 0 and ending at Size - 1.
  @note   None.
[==============================================================================}
function TRange.Frame(var rSize: Integer): TRange; overload;
begin
  rSize := Self.Size;
  Result := Range(0, (rSize - 1));
end;

{==============================================================================]
  <Frame>
  @action Returns a TRange covering the full extent of this instance,
          starting at 0 and ending at Size - 1.
  @note   None.
[==============================================================================}
function TRange.Frame: TRange; overload;
begin
  Result := Range(0, (Self.Size - 1));
end;

{==============================================================================]
  <Reserve>
  @action: Allocate an integer array sized to fit the full range.
  @note: The array is preallocated with the correct length but is not filled
         with values from start..stop. Elements are default-initialized to 0.
[==============================================================================}
function TRange.Reserve: TIntegerArray; overload;
begin
  SetLength(Result, Self.Size);
end;

{==============================================================================]
  <Reserve>
  @action: Allocate an integer array sized to fit the full range.
  @note: The array is preallocated with the correct length but is not filled
         with values from start..stop. Elements are default-initialized to 0.
[==============================================================================}
function TRange.Reserve(var aRange: TIntegerArray): Integer; overload;
begin
  Result := Self.Size;
  SetLength(aRange, Result);
end;

{==============================================================================]
  <Split>
  @action: Normalizes the range and splits it into two contiguous subranges of
           approximately equal size.
           If the range is singular (Start = Stop), both output ranges are set to
           the normalized range and no split is performed.
           Otherwise, the range is split at the midpoint:
           - mLeft covers Start .. Midpoint
           - mRight covers (Midpoint + 1) .. Stop
  @note:
    - The method always normalizes Self before splitting.
    - Both rLeft and rRight are assigned in all cases.
    - The function result is the split point (midpoint). For a singular range,
      the Start value is returned.
    - Integer division is used when calculating the midpoint.
[==============================================================================}
function TRange.Split(var rLeft, rRight: TRange): Integer;
var
  n: TRange;
begin
  n := Self.Normalize;
  rLeft := n;
  rRight := n;
  if n.Singular then
    Exit(n.start);
  Result := ((n.start + n.stop) div 2);
  rLeft.stop := Result;
  rRight.start := (Result + 1);
end;
{$ENDIF}