{$IFDEF HELPERS}
function Hits(const items: TRange; const oAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Hits>
  @action: Returns the indices of elements in Self whose values fall within a given range
  @note: - Self must be sorted according to oAscending
         - Range is normalized before evaluation
         - The result contains indices into Self, not the matching values
         - Evaluation stops early once values fall outside the range
         - Time complexity: O(N) in the worst case, O(K) with early termination
[==============================================================================}
function TIntegerArrayHelper.Hits(const items: TRange; const oAscending: Boolean = True): TIntegerArray; overload;
var
  r: TRange;
  i, k, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  if (l = 0) then
    Exit;
  r := items.Normalize;
  k := 0;
  for i := 0 to (l - 1) do
    if InRange(Self[i], r.start, r.stop) then
      Result[k.Increase] := i
    else if ((oAscending and (Self[i] > r.stop)) or ((not oAscending) and (Self[i] < r.start))) then
      Break;
  SetLength(Result, k);
end;
{$ENDIF}