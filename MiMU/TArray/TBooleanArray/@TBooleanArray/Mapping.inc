{$IFDEF HELPERS}
function Consignment(const oAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Consignment>
  @action: Returns the scatter map for a flank record: Result[i] is the index
           where element i lands when a bucket is deployed to its flanks.
           Flags equal to oAscending go to the right block, the rest to the
           left block. The left block is filled right to left in admission
           order, the right block left to right, so the two meet at the
           boundary (the count of left-flagged elements).
  @note: Non-mutating and value-free. Reads only the flags, never the elements
         themselves. Apply it with Scattered/Scatter (Result[map[i]] := A[i]),
         or carry satellite arrays through the same arrangement.
         The result is always a permutation of 0..Length-1, whatever the flags
         hold. It only orders correctly for flags from the admission process
         (each element a new minimum or maximum of its bucket). Self[0]'s flag
         does not change the outcome, since the element lands at the boundary
         either way.
         Two linear passes (count, then assign), O(n) extra memory for the map.
         An empty Self returns an empty map.
[==============================================================================}
function TBooleanArrayHelper.Consignment(const oAscending: Boolean = True): TIntegerArray; overload;
var
  c, l, r, i: Integer;
begin
  c := 0;
  for i := 0 to High(Self) do
    if (Self[i] <> oAscending) then
      Inc(c);
  l := (c - 1);
  r := c;
  for i := 0 to Result.Alloc(Self.Length) do
    if (Self[i] = oAscending) then
      Result[i] := r.Increase
    else
      Result[i] := l.Decrease;
end;
{$ENDIF}
