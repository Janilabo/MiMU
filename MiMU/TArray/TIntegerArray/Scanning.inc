{$IFDEF HELPERS}
function Hits(const items: TRange; const oAscending: Boolean = True): TIntegerArray; overload;
function WhereIn(const items: TIntegerArray): TIntegerArray; overload;
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

{==============================================================================]
  <WhereIn>
  @action: Returns the indices of elements in the current array that exist within
           the 'items' collection using a high-speed bitset mapping.
  @note: 
    - Complexity: O(n + m) where n is Self.Length and m is items.Length.
    - Extremely efficient for dense integer ranges.
    - Memory usage scales with the range (Max - Min) of 'items'.
    - If 'items' has a massive range (e.g., [0, 2^31-1]), this may raise 
      an out-of-memory exception.
[==============================================================================}
function TIntegerArrayHelper.WhereIn(const items: TIntegerArray): TIntegerArray; overload;
var
  b: TBits;
  i, c, l, h, v: Integer;
  r: Int64;
begin
  if ((Self.Length = 0) or (not items.GetMinMax(l, h))) then
    Exit([]);
  r := (Int64(h) - Int64(l) + 1);
  b := TBits.Create;
  try
    b.Size := r;
    for i := 0 to High(items) do
      b[items[i] - l] := True;
    SetLength(Result, Self.Length);
    c := 0;
    for i := 0 to High(Self) do
    begin
      v := Self[i];
      if (((v >= l) and (v <= h)) and b[v - l]) then
        Result[c.Increase] := i;
    end;
    SetLength(Result, c);
  finally
    b.Free;
  end;
end;
{$ENDIF}
