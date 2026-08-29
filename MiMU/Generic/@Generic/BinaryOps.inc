{$IFDEF FUNCTIONS}
generic function BinarySearch<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
generic function BinaryFind<T>(const arr: array of T; const target: T; const ascending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
{$ENDIF}