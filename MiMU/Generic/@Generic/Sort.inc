{$IFDEF FUNCTIONS}
generic function Sort<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
generic function Sort<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;

generic function QuickSort<T>(var arr: array of T; const comp: specialize TCompare<T>): Integer; overload;
generic function QSort<T>(var arr: array of T; const comp: specialize TCompare<T>): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Sort>
  @action: Ensures that two values are ordered according to the ascending flag, performing a swap if necessary.
  @note: Returns True if a swap occurred, False otherwise. Calls generic Swap<T> internally.
[==============================================================================}
generic function Sort<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((oAscending and (A > B)) or ((not oAscending) and (A < B)));
  if Result then
    specialize Swap<T>(A, B);
end;

{==============================================================================]
  <Sort>
  @action: Ensures that three values A, B, C are ordered according to the ascending flag, performing swaps if necessary.
  @note: Returns True if any swaps occurred, False otherwise. Does not fully sort arrays, only these three values.
[==============================================================================}
generic function Sort<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
  function DoSwap(var X, Y: T): Boolean;
  var
    Z: T;
  begin
    Z := X;
    X := Y;
    Y := Z;
    Result := True;
  end;
begin
  Result := False;
  if ((oAscending and (A > B)) or ((not oAscending) and (A < B))) then
    Result := DoSwap(A, B);
  if ((oAscending and (A > C)) or ((not oAscending) and (A < C))) then
    Result := DoSwap(A, C);
  if ((oAscending and (B > C)) or ((not oAscending) and (B < C))) then
    Result := DoSwap(B, C);
end;

{==============================================================================]
  <QuickSort>
  @action: Performs an in-place QuickSort on a dynamic array of any type T.
           Uses a provided comparer function to determine ordering.
  @note: Returns the length of the array (optional). The array is modified directly.
         Pivot selection is safe against integer overflow. Uses generic Swap<T> internally.
[==============================================================================}
generic function QuickSort<T>(var arr: array of T; const comp: specialize TCompare<T>): Integer; overload;
  procedure Sorting(L, R: Integer);
  var
    P: T;
    I, J: Integer;
  begin
    I := L;
    J := R;
    P := arr[L + ((R - L) div 2)];
    repeat
      while (comp(arr[I], P) < 0) do
        Inc(I);
      while (comp(arr[J], P) > 0) do
        Dec(J);
      if (I <= J) then
      begin
        specialize Swap<T>(arr[I], arr[J]);
        Inc(I);
        Dec(J);
      end;
    until (I > J);
    if (L < J) then
	  Sorting(L, J);
    if (I < R) then
      Sorting(I, R);
  end;
begin
  Result := Length(arr);
  if (Result > 1) then
    Sorting(0, High(arr));
end;

{==============================================================================]
  <QSort>
  @action: Sorts a dynamic array in place using QuickSort with Hoare partitioning, ordered by a caller-supplied three-way comparer.
  @note: Recurses into the smaller partition and loops into the larger one, bounding worst-case stack depth to O(log n) regardless of input order.
         Pivot is the middle element (overflow-safe index calculation), so adversarial/already-sorted input doesn't force worst-case behavior the way first/last-element pivoting would.
		 Works for any T, including types with no native ordering, since ordering comes entirely from comp. Returns Length(arr) for convenience.
[==============================================================================}
generic function QSort<T>(var arr: array of T; const comp: specialize TCompare<T>): Integer; overload;
  procedure Sorting(L, R: Integer);
  var
    I, J: Integer;
    P: T;
  begin
    while (L < R) do
    begin
      I := L;
      J := R;
      P := arr[L + ((R - L) div 2)];
      repeat
        while (comp(arr[I], P) < 0) do
          Inc(I);
        while (comp(arr[J], P) > 0) do
          Dec(J);
        if (I <= J) then
        begin
          specialize Swap<T>(arr[I], arr[J]);
          Inc(I);
          Dec(J);
        end;
      until (I > J);
      if ((J - L) < (R - I)) then
      begin
        if (L < J) then
		  Sorting(L, J);
        L := I;
      end else
      begin
        if (I < R) then
		  Sorting(I, R);
        R := J;
      end;
    end;
  end;
begin
  Result := Length(arr);
  if (Result > 1) then
    Sorting(0, High(arr));
end;
{$ENDIF}