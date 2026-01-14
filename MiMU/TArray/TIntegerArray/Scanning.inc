{$IFDEF HELPERS}
function Hits(const items: TIntegerArray; const oAscending: Boolean = True): TIntegerArray; overload;
function Hits(const items: TRange; const oAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Hits>
  @action: Returns the indices of elements in Self whose values occur in a given set
  @note: - Self must be sorted according to oAscending
         - items are internally sorted before evaluation
         - The result contains indices into Self, not the matching values
         - Multiple equal values in Self produce multiple hits
         - Returns an empty array if Self or items is empty
         - Time complexity: O(N + M), where N = Length(Self) and M = Length(items)
[==============================================================================}
function TIntegerArrayHelper.Hits(const items: TIntegerArray; const oAscending: Boolean = True): TIntegerArray; overload;
var
  s: TIntegerArray;
  h, i, j, k, l: Integer;
begin
  h := High(items);
  l := Self.Length;
  if ((l = 0) or (h = -1)) then
    Exit([]);
  SetLength(Result, l);
  s := items.QuickSorted(oAscending);
  i := 0;
  j := 0;
  k := 0;
  while ((i < l) and (j <= h)) do
  case (Self[i] = s[j]) of
    True:
    begin
      Result[k.Increase] := i;
      Inc(i);
      Inc(j);
    end;
	False:
    if ((Self[i] < s[j]) = oAscending) then
      Inc(i)
    else
      Inc(j);
  end;
  SetLength(Result, k);
end;

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