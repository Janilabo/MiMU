{$IFDEF METHODS}
function CompareSize(const target: TRange): Integer;
class function CompareSizeAscending(const A, B: TRange): Integer; static;
class function CompareSizeDescending(const A, B: TRange): Integer; static;
function Rank(const target: TRange): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}