{$IFDEF METHODS}
function Compare(const target: TRange): Integer; overload;
function Compared(const target: TRange): Integer; overload;
function CompareTo(const target: TRange): Integer; overload;
function CompareSize(const target: TRange): Integer;
class function CompareSizeAscending(const A, B: TRange): Integer; static;
class function CompareSizeDescending(const A, B: TRange): Integer; static;
function Comparison(const target: TRange): Integer; overload;
function Rank(const target: TRange): Integer; overload;
function SideOf(const target: TRange): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Compare>
  @action: Returns an integer indicating the relative position of this range 
           to the target range.
  @returns: 
    -1 : This range is entirely BELOW (less than) the target.
     0 : This range OVERLAPS with the target.
     1 : This range is entirely ABOVE (greater than) the target.
  @note: This follows standard comparison logic where a lower value 
         returns a negative result.
[==============================================================================}
function TRange.Compare(const target: TRange): Integer; overload;
begin
  if (Self.Maximum < target.Minimum) then
    Result := -1
  else if (Self.Minimum > target.Maximum) then
    Result := 1
  else
    Result := 0;
end;

{==============================================================================]
  <Compared>
  @action: Returns the relative spatial relationship between this range and 
           the target as a normalized integer (-1, 0, or 1).
  @returns: 
     -1 : This range is strictly below the target.
      0 : This range overlaps with or touches the target.
      1 : This range is strictly above the target.
  @note: Uses a branchless Ordinal calculation on normalized ranges to ensure 
         consistent results regardless of start/stop order.
[==============================================================================}
function TRange.Compared(const target: TRange): Integer; overload;
var
  s, t: TRange;
begin
  s := Self.Normalized;
  t := target.Normalized;
  Result := (Ord(s.start > t.stop) - Ord(s.stop < t.start));
end;

{==============================================================================]
  <CompareTo>
  @action: Evaluates the relative spatial position of this range against a target.
  @returns: 
     -1 : This range is strictly less than (below/left of) the target.
      1 : This range is strictly greater than (above/right of) the target.
      0 : The ranges overlap or touch.
  @note: Both ranges are normalized internally before comparison to ensure 
         consistent results regardless of coordinate order.
[==============================================================================}
function TRange.CompareTo(const target: TRange): Integer; overload;
var
  s, t: TRange;
begin
  s := Self.Normalized;
  t := target.Normalized;
  if (s.stop < t.start) then
    Result := -1
  else if (s.start > t.stop) then
    Result := 1
  else
    Result := 0;
end;

{==============================================================================]
  <CompareSize>
  @action: Compares the size of this TRange instance with another TRange.
           Returns a positive value if Self is larger, negative if smaller,
           and zero if they are equal in size.
  @note: This is an instance method; it requires a TRange object to call.
[==============================================================================}
function TRange.CompareSize(const target: TRange): Integer;
begin
  Result := (Self.Size - target.Size);
end;

{==============================================================================]
  <CompareSizeAscending>
  @action: Compares two TRanges for ascending size order.
           Returns a negative value if A is smaller, positive if A is larger,
           zero if sizes are equal. Suitable for sorting in ascending order.
  @note: Declared as a static class function so it can be passed directly
         to a procedural type such as TCompare<TRange>.
[==============================================================================}
class function TRange.CompareSizeAscending(const A, B: TRange): Integer;
begin
  Result := A.CompareSize(B);
end;

{==============================================================================]
  <CompareSizeDescending>
  @action: Compares two TRanges for descending size order.
           Returns a negative value if A is larger, positive if A is smaller,
           zero if sizes are equal. Suitable for sorting in descending order.
  @note: Declared as a static class function so it can be passed directly
         to a procedural type such as TCompare<TRange>.
[==============================================================================}
class function TRange.CompareSizeDescending(const A, B: TRange): Integer;
begin
  Result := B.CompareSize(A);
end;

{==============================================================================]
  <Comparison>
  @action: Compares two ranges by start then stop values.
  @note: Returns -1 if less, 1 if greater, 0 if equal.
[==============================================================================}
function TRange.Comparison(const target: TRange): Integer; overload;
begin
  if (Self.start < target.start) then
    Exit(-1);
  if (Self.start > target.start) then
    Exit(1);
  if (Self.stop < target.stop) then
    Exit(-1);
  if (Self.stop > target.stop) then
    Exit(1);
  Result := 0;
end;

{==============================================================================]
  <Rank>
  @action: Compares this range with the target range to determine their relative
           ordering. Returns:
             -1 if Self comes before target,
             0 if Self and target are identical,
             1 if Self comes after target.
           Comparison is performed first on the normalized start values, and if
           equal, then on the normalized stop (end) values.
  @note:
    • Uses normalized ranges (via Self.Normalize and target.Normalize),
      so ranges with reversed min/max are correctly handled.
    • Ordering is total: every two ranges will yield -1, 0, or 1.
    • Normalization ensures Minimum ≤ Maximum before comparison.
    • This is suitable for sorting ranges or defining a canonical order.
[==============================================================================}
function TRange.Rank(const target: TRange): Integer; overload;
var
  s, t: TRange;
begin
  s := Self.Normalize;
  t := target.Normalize;
  if (s.start < t.start) then
    Exit(-1)
  else if (s.start > t.start) then
    Exit(1)
  else if (s.stop < t.stop) then
    Exit(-1)
  else if (s.stop > t.stop) then
    Exit(1);
  Result := 0;
end;

{==============================================================================]
  <SideOf>
  @action: Returns the relative spatial orientation of this range compared 
           to a target range.
  @returns: 
     -1 : This range is entirely below (Minimum > target.Maximum) the target.
      0 : This range overlaps with the target.
      1 : This range is entirely above (Maximum < target.Minimum) the target.
  @note: This is a branchless implementation using ordinal subtraction. It 
         assumes Minimum and Maximum are the normalized boundaries.
[==============================================================================}
function TRange.SideOf(const target: TRange): Integer; overload;
begin
  Result := (Ord(Self.Minimum > target.Maximum) - Ord(Self.Maximum < target.Minimum));
end;
{$ENDIF}