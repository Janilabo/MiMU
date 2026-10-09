{$IFDEF HELPERS}
function RankSorted(const oAscending: Boolean = True): MArray; overload;
function ToOrder(const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <RankSorted>
  @action: Returns a sorted copy of the array constructed by calculating the positional rank of each element.
  @note: Uses O(N^2) pairwise comparison with index-tiebreaking to place every element directly at its rank index.
         Non-destructive function.
[==============================================================================}
function MArrayHelper.RankSorted(const oAscending: Boolean = True): MArray; overload;
var
  i, j, l, r: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Copy);
  for i := 0 to Result.Alloc(l) do
  begin
    r := 0;
    for j := 0 to (l - 1) do
      if ((oAscending and (Self[j] < Self[i])) or ((not oAscending) and (Self[j] > Self[i])) or ((j < i) and (Self[j] = Self[i]))) then
        Inc(r);
    Result[r] := Self[i];
  end;
end;

{==============================================================================]
  <ToOrder>
  @action: Sorts an array by decomposing it into monotonic sub-arrays and 
          recombining them via a k-way merge (Patience / Cascade Sort).
  @note: 
  - Pipeline approach: Executes Self.AsPiles to partition elements into sorted 
    piles, then calls MergeK to merge them back into a single sorted 1D array.
  - Achieves full sorting without a traditional QuickSort pass, leveraging 
    existing structural monotonicity in the source array.
  - Returns a sorted copy of Self according to the oAscending flag.
[==============================================================================}
function MArrayHelper.ToOrder(const oAscending: Boolean = True): MArray; overload;
begin
  Result := Self.AsPiles(oAscending).MergeK(oAscending);
end;
{$ENDIF}
