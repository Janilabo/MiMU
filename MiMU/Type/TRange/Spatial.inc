{$IFDEF METHODS}
function Commonality(const other: TRange): Integer; overload;
function Confluency(const target: TRange): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Commonality>
  @action: Returns the number of discrete values shared by this range and another
          range.
  @note: If the ranges overlap, the result is the inclusive size of their
         intersection, calculated as
         Min(Self.Maximum, other.Maximum) - Max(Self.Minimum, other.Minimum) + 1.
         If the ranges do not overlap, the result is 0.
         This method assumes both ranges are valid (Minimum <= Maximum).
[==============================================================================}
function TRange.Commonality(const other: TRange): Integer; overload;
begin
  if Self.Overlaps(other) then
    Result := ((Min(Self.Maximum, other.Maximum) - Max(Self.Minimum, other.Minimum)) + 1)
  else
    Result := 0;
end;

{==============================================================================]
  <Confluency>
  @action: Returns the count of integers shared between Self and target.
  @note: - Self [1..5]  Overlap [3..8]  -> 3  (3, 4, 5)
         - Self [1..5]  Overlap [5..10] -> 1  (5)
         - Self [1..5]  Overlap [6..10] -> 0
         - Self [1..10] Overlap [3..7]  -> 5  (3, 4, 5, 6, 7)
[==============================================================================}
function TRange.Confluency(const target: TRange): Integer; overload;
begin
  Result := Max(0, ((Min(Self.Maximum, target.Maximum) - Max(Self.Minimum, target.Minimum)) + 1));
end;
{$ENDIF}