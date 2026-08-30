{$IFDEF FUNCTIONS}
generic function BinaryContains<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Boolean; overload;
generic function BinaryFind<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
generic function BinarySearch<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
generic function BinaryLowerBound<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
generic function BinaryUpperBound<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
generic function BinaryFirst<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
generic function BinaryLast<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
generic function BinaryCount<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryContains>
  @action: Reports whether target exists anywhere in a sorted array of generic type T.
  @note: Thin wrapper over BinarySearch; discards the index and returns only membership.
         Inherits the same ascending/descending and relational-operator requirements.
[==============================================================================}
generic function BinaryContains<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Boolean; overload;
begin
  Result := (specialize BinarySearch<T>(arr, target, ascending) > -1);
end;

{==============================================================================]
  <BinaryFind>
  @action: Performs binary search using a direction multiplier for branch efficiency.
  @note: Evaluates sort direction outside the loop body for better performance.
[==============================================================================}
generic function BinaryFind<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
var
  L, H, D: Integer;
begin
  L := Low(arr);
  H := High(arr);
  if ascending then
    D := 1
  else
    D := -1;
  while (L <= H) do
  begin
    Result := (L + (H - L) div 2);
    if (arr[Result] = target) then
      Exit;
    if (D * (2 * Ord(Boolean(arr[Result] < target)) - 1) = 1) then
      L := (Result + 1)
    else
      H := (Result - 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinarySearch>
  @action: Performs a binary search on a sorted array of generic type T.
  @note: Supports both ascending and descending sorted order via the 
         'ascending' parameter. Returns the zero-based index of the target 
         if found; otherwise returns -1. Array elements must support standard 
         relational comparison operators (=, <, >).
[==============================================================================}
generic function BinarySearch<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
var
  L, H: Integer;
begin
  L := Low(Arr);
  H := High(Arr);
  while (L <= H) do
  begin
    Result := (L + (H - L) div 2);
    if (arr[Result] = target) then
      Exit
    else if ((ascending and (arr[Result] < target)) or ((not ascending) and (arr[Result] > target))) then
      L := (Result + 1)
    else
      H := (Result - 1);
  end;
  Result := -1;
end;

{==============================================================================]
  <BinaryLowerBound>
  @action: Finds the leftmost index at which target could be inserted into a
           sorted array of generic type T without violating sort order.
  @note: Returns the index of the first element not "before" target — i.e.
         the first element >= target (ascending) or <= target (descending).
         If every element is "before" target, returns High(arr) + 1 (one
         past the end). Does not require target to be present. Ordered-only
         tier; array elements must support < and >.
[==============================================================================}
generic function BinaryLowerBound<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
var
  H, M: Integer;
begin
  Result := Low(arr);
  H := (High(arr) + 1);
  while (Result < H) do
  begin
    M := (Result + (H - Result) div 2);
    if ((ascending and (arr[M] < target)) or ((not ascending) and (arr[M] > target))) then
      Result := (M + 1)
    else
      H := M;
  end;
end;

{==============================================================================]
  <BinaryUpperBound>
  @action: Finds the leftmost index past the last element of a sorted array
           of generic type T that is not "after" target.
  @note: Returns the index of the first element strictly "after" target —
         i.e. the first element > target (ascending) or < target
         (descending). If every element is <= target (ascending) or >=
         target (descending), returns High(arr) + 1. Does not require target
         to be present. Ordered-only tier; array elements must support < and >.
[==============================================================================}
generic function BinaryUpperBound<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
var
  H, M: Integer;
begin
  Result := Low(arr);
  H := High(arr) + 1;
  while (Result < H) do
  begin
    M := (Result + (H - Result) div 2);
    if ((ascending and (arr[M] <= target)) or ((not ascending) and (arr[M] >= target))) then
      Result := (M + 1)
    else
      H := M;
  end;
end;

{==============================================================================]
  <BinaryFirst>
  @action: Finds the leftmost occurrence of target in a sorted array of
           generic type T, correctly handling duplicates.
  @note: Thin wrapper over BinaryLowerBound; confirms the located slot
         actually holds target before returning it, since BinaryLowerBound
         also reports a valid insertion point when target is absent.
         Returns -1 if target is not present.
[==============================================================================}
generic function BinaryFirst<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
begin
  Result := specialize BinaryLowerBound<T>(arr, target, ascending);
  if not ((Result <= High(arr)) and (arr[Result] = target)) then
    Result := -1;
end;

{==============================================================================]
  <BinaryLast>
  @action: Finds the rightmost occurrence of target in a sorted array of
           generic type T, correctly handling duplicates.
  @note: Thin wrapper over BinaryUpperBound; steps one index back from the
         upper bound and confirms it holds target before returning it.
         Returns -1 if target is not present.
[==============================================================================}
generic function BinaryLast<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
begin
  Result := (specialize BinaryUpperBound<T>(arr, target, ascending) - 1);
  if not ((Result >= Low(arr)) and (arr[Result] = target)) then
    Result := -1;
end;

{==============================================================================]
  <BinaryCount>
  @action: Counts how many times target occurs in a sorted array of generic
           type T.
  @note: Composed from BinaryLast/BinaryFirst rather than its own loop;
         returns 0 if target is not present, otherwise Last - First + 1.
         Ordered-only tier, same requirements as BinaryFirst/BinaryLast.
         Requires arr to be 0-based (Low(arr) = 0); behavior with
         custom-bounded arrays is undefined.
[==============================================================================}
generic function BinaryCount<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
begin
  Result := specialize BinaryLast<T>(arr, target, ascending);
  if (Result > -1) then
    Result := ((Result - specialize BinaryFirst<T>(arr, target, ascending)) + 1)
  else
    Result := 0;
end;
{$ENDIF}