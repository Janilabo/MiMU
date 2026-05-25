{$IFDEF FUNCTIONS}
function Selectionsorted(const A, B, C: MType; const oAscending: Boolean = True): MArray; overload;
function Sort3(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
function Sorted3(const A, B, C: MType; const oAscending: Boolean = True): MArray; overload;
function Triosorted(const A, B, C: MType; const oAscending: Boolean = True): MArray; overload;
function Trisort(var A, B, C: MType; const oAscending: Boolean = True): MType; overload;
function Trisorted(const A, B, C: MType; const oAscending: Boolean = True): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Selectionsorted>
  @action: Accepts three values and applies a 3-element Selection Sort algorithm, 
           and returns the sorted elements within an array structure.
  @note: This function operates non-destructively on the original parameters (`const`) by copying 
         them into a local array instance (`Result`). It then runs an iterative selection sort loop:
         * In each pass, it identifies the index `m` of the extreme element (minimum for ascending, 
           maximum for descending) in the remaining unsorted portion.
         * If the extreme element is not already at index `i`, it invokes a `Swap` routine to put it in place.
         * Due to fixed boundaries (loops constrained exactly to 3 elements), the overhead is minimal, 
           making it a predictable sorting structure.
[==============================================================================}
function Selectionsorted(const A, B, C: MType; const oAscending: Boolean = True): MArray; overload;
var
  i, j, m: Integer;
begin
  Result := [A, B, C];
  for i := 0 to 1 do
  begin
    m := i;
    for j := (i + 1) to 2 do
      if ((oAscending and (Result[j] < Result[m])) or (not oAscending and (Result[j] > Result[m]))) then
        m := j;
    if (m <> i) then
      Swap(Result[i], Result[m]);
  end;
end;

{==============================================================================]
  <Sort3>
  @action: Sorts three values in place
  @note: Uses bubble-sort logic optimized for 3 elements
[==============================================================================}
function Sort3(var A, B, C: MType; const oAscending: Boolean = True): Boolean; overload;
  function F(var X, Y: MType): Byte;
  begin
    Result := Byte((oAscending and (X > Y)) or ((not oAscending) and (X < Y)));
    if (Result = 1) then
      Swap(X, Y);
  end;
begin
  Result := ((F(A, B) + F(B, C) + F(A, B)) > 0);
end;

{==============================================================================]
  <Sorted3>
  @action: Accepts three values of type `MType`, sorts them in either ascending or 
           descending order, and returns them packed inside an array structure (`MArray`).
  @note: This function preserves the original inputs (`const`) by initializing a new local 
         array instance with them. It then delegates the actual reordering logic to a secondary, 
         in-place routine named `Sort3`. The direction of the sort is governed by the 
         `oAscending` parameter (defaulting to `True`).
[==============================================================================}
function Sorted3(const A, B, C: MType; const oAscending: Boolean = True): MArray; overload;
begin
  Result := [A, B, C];
  Sort3(Result[0], Result[1], Result[2], oAscending);
end;

{==============================================================================]
  <Triosorted>
  @action: Accepts three values, identifies their minimum, median, and 
           maximum values, and returns them ordered inside an array.
  @note: This function abstracts the sorting process by delegating the isolation of the extreme 
         and middle values to distinct utility functions (`Min3`, `Med3`, and `Max3`). 
         * When `oAscending` is `True`, it populates the array from lowest to highest.
         * When `oAscending` is `False`, it mirrors the index positions to order from highest to lowest.
         * This approach creates highly readable code, though it assumes that `Min3`, `Med3`, and 
           `Max3` are internally optimized to avoid redundant comparison overhead.
[==============================================================================}
function Triosorted(const A, B, C: MType; const oAscending: Boolean = True): MArray; overload;
begin
  if oAscending then
    Result := [Min3(A, B, C), Med3(A, B, C), Max3(A, B, C)]
  else
    Result := [Max3(A, B, C), Med3(A, B, C), Min3(A, B, C)];
end;

{==============================================================================]
  <Trisort>
  @action: Reorders three mutable variables in-place using a 3-element sorting network.
  @note: Since A, B, and C are passed as reference parameters (`var`), their original values 
         are permanently updated. `oAscending` switches the order direction.
  @result: The first element of the newly sorted sequence (the minimum value if 
           `oAscending` is True, or the maximum value if `oAscending` is False).
[==============================================================================}
function Trisort(var A, B, C: MType; const oAscending: Boolean = True): MType; overload;
var
  D: MType;
begin
  if ((oAscending and (A > B)) or ((not oAscending) and (A < B))) then
    Swap(A, B);
  if ((oAscending and (B > C)) or ((not oAscending) and (B < C))) then
    Swap(B, C);
  if ((oAscending and (A > B)) or ((not oAscending) and (A < B))) then
    Swap(A, B);
  Result := A;
end;

{==============================================================================]
  <Trisorted>
  @action: Returns a new sorted array using Trisort algorithm.
  @note: Copies values, sorts them in place, returns as array.
  @param oAscending: True for ascending order, False for descending.
  @example: Trisorted(3,1,2) returns [1,2,3]
[==============================================================================}
function Trisorted(const A, B, C: MType; const oAscending: Boolean = True): MArray; overload;
begin
  Result := [A, B, C];
  Trisort(Result[0], Result[1], Result[2], oAscending);
end;
{$ENDIF}