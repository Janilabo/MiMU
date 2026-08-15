{$IFDEF HELPERS}
function AllDifferent: Boolean; overload;
function Echo: Boolean; overload;
function Injective(const isSorted: Boolean = False): Boolean; overload;
function IsInjective(const isSorted: Boolean = False): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AllDifferent>
  @action: Returns True if all elements in the array are pairwise distinct.
           Uses a temporary sorted array and BinarySupply to efficiently detect
           duplicates while preserving order.
  @note:
    • Arrays with zero or one element are considered "all different".  
    • Each element is inserted into a temporary sorted array using BinarySupply.  
      - BinarySupply returns False if the element is already present, immediately
        causing AllDifferent to return False.  
    • Time complexity: O(n log n) due to binary insertion.  
[==============================================================================}
function MArrayHelper.AllDifferent: Boolean; overload;
var
  h, i: Integer;
  s: MArray;
begin
  h := High(Self);
  if (h < 1) then
    Exit(h = 0);
  s := [Self[0]];
  for i := 1 to h do
    if not s.BinarySupply(Self[i]) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Echo>
  @action: Determines if the array is symmetrical (a palindrome) by comparing 
           elements from both ends simultaneously.
  @note: 
    - Strategy: Employs a dual-pointer "converging" approach. The 'S' (Start) 
      pointer moves forward while the 'E' (End) pointer moves backward.
    - Efficiency: O(N) time complexity with a 0.5x iteration factor. 
      Exits immediately (False) at the first point of divergence.
    - Performance: Highly optimized; avoids the overhead of array index 
      calculations and bounds checking by using raw pointer dereferencing.
    - Safety: Returns True for empty arrays or single-element arrays, as 
      they are inherently symmetrical.
[==============================================================================}
function MArrayHelper.Echo: Boolean; overload;
var
  S, E: MPointer;
begin
  if (Self.Length < 2) then
    Exit(True);
  S := @Self[0];
  E := @Self[High(Self)];
  while (S < E) do
  begin
    if (S^ <> E^) then
	  Exit(False);
    Inc(S);
    Dec(E);
  end;
  Result := True;
end;

{==============================================================================]
  <Injective>
  @action: Returns True if the array contains no duplicate elements
           (i.e. the mapping index → value is injective).
  @note:
    • Arrays with zero or one element are injective by definition.
    • If isSorted = True, the array is assumed to already be sorted and
      only adjacent elements are compared (O(n)).
    • If isSorted = False, a sorted copy of the array is created using
      QuickSorted and duplicates are detected via adjacent comparison.
    • Sorting branch complexity: O(n log n) time, O(n) additional space.
    • Equality is evaluated using the = operator of MType.
    • When isSorted = True, correctness depends on the array being
      sorted according to the same ordering used by QuickSorted.
[==============================================================================}
function MArrayHelper.Injective(const isSorted: Boolean = False): Boolean; overload;
var
  i: Integer;
  s: MArray;
begin
  if (Self.Length > 1) then
  case isSorted of
    True:
    for i := 1 to High(Self) do
      if (Self[i] = Self[i - 1]) then
        Exit(False);
    False:
    begin
      s := Self.QuickSorted;
      for i := 1 to High(s) do
        if (s[i] = s[i - 1]) then
          Exit(False);
    end;
  end;
  Result := True;
end;

{==============================================================================]
  <IsInjective>
  @action: Returns True if the array contains no duplicate elements
           (i.e. the index → value mapping is injective).
  @note:
    • Arrays with zero or one element are injective by definition.
    • If isSorted = False (default), the array is first sorted using
      QuickSorted, and injectivity is then verified on the sorted copy.
    • If isSorted = True, the array is assumed to already be sorted and
      only adjacent elements are compared.
    • Sorted branch complexity: O(n).
    • Unsorted branch complexity: O(n log n) due to sorting.
    • Equality is determined using the = operator of MType.
    • Correctness of the isSorted = True branch depends on the array
      being sorted according to the same ordering used by QuickSorted.
[==============================================================================}
function MArrayHelper.IsInjective(const isSorted: Boolean = False): Boolean; overload;
var
  i: Integer;
begin
  if not isSorted then
    Exit(Self.QuickSorted.IsInjective(True));
  for i := 1 to High(Self) do
    if (Self[i] = Self[i - 1]) then
      Exit(False);
  Result := True;
end;
{$ENDIF}
