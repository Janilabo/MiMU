{$IFDEF HELPERS}
function CountOf(const items: MArray; const iAscending: Boolean = True): Integer; overload; cdecl;
function Counted(const items: MArray; const iSorted: Boolean = False): Integer; overload; cdecl;
function IntersectionCount(const items: MArray; const oAscending: Boolean = True): Integer; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <CountOf>
  @action: Counts how many elements in Self are present in the array items, assuming
           items is already sorted in either ascending or descending order.
  @note:
    - Membership testing is performed using binary search.
    - Items must be sorted prior to calling this function.
    - The iAscending flag specifies the sort direction of Items.
    - Each element in Self is counted independently; duplicates in Self are
      counted multiple times if present in Items.
    - Time complexity: O(N log M), where N = Length(Self),
      M = Length(Items).
[==============================================================================}
function MArrayHelper.CountOf(const items: MArray; const iAscending: Boolean = True): Integer; overload; cdecl;
var
  i: Integer;
begin
  Result := 0;
  if (items.Length > 0) then
  for i := 0 to High(Self) do
    if (items.WithinBounds(Self[i], iAscending) and (items.BinarySearchBy(Self[i], iAscending) > -1)) then
      Inc(Result);
end;

{==============================================================================]
  <Counted>
  @action: Counts how many elements in Self are present in the array items, optionally
           sorting items internally if it is not already sorted.
  @note:
    - If iSorted = False, Items is copied and sorted before searching.
    - If iSorted = True, Items is assumed to be pre-sorted.
    - Binary search is used for membership testing.
    - Sort order is automatically inferred when Items is sorted.
    - Each element in Self is counted independently; duplicates in Self are
      counted multiple times if present in Items.
    - Time complexity:
        * iSorted = False: O(M log M + N log M)
        * iSorted = True : O(N log M)
      where N = Length(Self), M = Length(Items).
[==============================================================================}
function MArrayHelper.Counted(const items: MArray; const iSorted: Boolean = False): Integer; overload; cdecl;
var
  s: MArray;
  i: Integer;
  a: Boolean;
begin
  Result := 0;
  if ((items.Length > 0) and (Self.Length > 0)) then
  case iSorted of
    False:
    begin
      s := items.QuickSorted;
      for i := 0 to High(Self) do
        if (s.WithinBounds(Self[i]) and (s.BinarySearchBy(Self[i]) > -1)) then
          Inc(Result);
    end;
    True:
    begin
      a := (items[0] <= items[High(items)]);
      for i := 0 to High(Self) do
        if (items.WithinBounds(Self[i], a) and (items.BinarySearchBy(Self[i], a) > -1)) then
          Inc(Result);
    end;
  end;
end;

{==============================================================================]
  <IntersectionCount>
  @action: Counts the number of elements that appear in both Self and Items, treating
           duplicates according to multiset semantics (each match consumes one element
           from each array).
  @note:
    - Both Self and Items must be sorted in the same order (ascending or
      descending) as indicated by oAscending.
    - Uses a linear merge algorithm; time complexity is O(N + M), where N =
      Length(Self), M = Length(Items).
    - Each element in Self can match at most one element in Items.
    - Duplicates in either array are handled pairwise:
        e.g., Self = [2,2,2], Items = [2,2] → Result = 2
    - Returns 0 if either array is empty.
[==============================================================================}
function MArrayHelper.IntersectionCount(const items: MArray; const oAscending: Boolean = True): Integer; overload; cdecl;
var
  h, s, i, j: Integer;
begin
  Result := 0;
  i := 0;
  j := 0;
  s := High(Self);
  h := High(Items);
  while ((i <= s) and (j <= h)) do
  case (Self[i] = items[j]) of
    True:
    begin
      Inc(Result);
      Inc(i);
      Inc(j);
    end;
    False:
    if ((Self[i] < items[j]) xor (not oAscending)) then
      Inc(i)
    else
      Inc(j);
  end;
end;
{$ENDIF}
