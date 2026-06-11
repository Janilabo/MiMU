{$IFDEF HELPERS}
function Backwards: MArray; overload;
function Esrever: Boolean; overload;
function Flip: Boolean; overload;
function Oppose: Boolean; overload;
function Opposite: MArray; overload;
function Reflex(const rIndex: Integer): MType; overload;
function Reversal: MArray; overload;
function Reverse: Boolean; overload;
function Reversed: MArray; overload;
function Reversement: Boolean; overload;
function Reversified: MArray; overload;
function Reversify: Boolean; overload;
function Reversion: MArray; overload;
function Revert: MArray; overload;
function Reverted: MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Backwards>
  @action: Returns arr as reversed.
  @note: Alternative for Reversed methods
[==============================================================================}
function MArrayHelper.Backwards: MArray; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  i := 0;
  while (l > 0) do
    Result[i.Increase] := Self[l.Decrement];
end;

{==============================================================================]
  <Esrever>
  @action: Reverses the elements of the original array in-place and returns 
           True if any swaps were executed.
  @note: Modifies the source array directly (zero-allocation). Initializes a 
         range structure bounding the array, and uses a while-loop to swap 
         elements from the outside edges inward. Uses standalone functional 
         mutators (Increment and Decrement) to adjust bounds 
         until they meet or cross in the middle.
[==============================================================================}
function MArrayHelper.Esrever: Boolean; overload;
var
  R: TRange;
begin
  R.Create(-1, Self.Length);
  Result := (R.stop > 1);
  if Result then
  while (R.start.Increment < R.stop.Decrement) do
    Swap(Self[R.start], Self[R.stop]);
end;

{==============================================================================]
  <Flip>
  @action: Reverses array arr.
  @note: Alternative for TArray_Reverse
[==============================================================================}
function MArrayHelper.Flip: Boolean; overload;
var
  r: TRange;
begin
  r.Create(0, (Self.Size - 1));
  Result := (r.stop > 0);
  while (r.start < r.stop) do
    Exchange(r.start.Increase, r.stop.Decrease);
end;

{==============================================================================]
  <Oppose>
  @action: Reverses the elements of the array **in place**, swapping the first
           element with the last, the second with the second-to-last, and so on.
           The operation is performed on the original array.
  @note: The function returns True if the array has more than one element
         and the reversal was performed. Returns False if the array has
         zero or one element (nothing to reverse). The order of all other
         elements is preserved according to the reversal.
[==============================================================================}
function MArrayHelper.Oppose: Boolean; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Self.Exch(i, ((l - 1) - i));
end;

{==============================================================================]
  <Opposite>
  @action: eturns a new array containing the elements of the current array
           in reverse order. The original array is not modified.
  @note: The order of elements is inverted: the last element becomes
         the first, the second-to-last becomes the second, and so on.
         The resulting array has the same elements as the original,
         but in reversed order.
[==============================================================================}
function MArrayHelper.Opposite: MArray; overload;
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, 0);
  while (l.Decrease > 0) do
    Result := (Result + [Self[l]]);
end;

{==============================================================================]
  <Reflex>
  @action: Retrieves the element from the mirrored position of the given index.
  @note:
    - Virtual Mapping: Acts as a "Lazy Reversal," mapping index [i] to
      [High - i] to simulate a backward view of the array.
    - Performance: O(1) constant time. Since it only performs a single
      subtraction, it is infinitely faster than physically reversing the
      data for one-off lookups.
    - Non-Mutating: Does not modify the array or allocate new memory.
    - Symmetry: The logic is reflexive; calling Reflex on a mirrored
      index returns the original forward-facing element.
[==============================================================================}
function MArrayHelper.Reflex(const rIndex: Integer): MType; overload;
begin
  Result := Self[High(Self) - rIndex];
end;

{==============================================================================]
  <Reversal>
  @action: Returns array with items in reversed order.
  @note: None.
[==============================================================================}
function MArrayHelper.Reversal: MArray; overload;
var
  r: TRange;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, Self.Size);
  r.Create(-1, Result.Size);
  while (r.start.Increment <= r.stop.Decrement) do
  begin
    Result[r.start] := Self[r.stop];
    if (r.start <> r.stop) then
      Result[r.stop] := Self[r.start];
  end;
end;

{==============================================================================]
  <Reverse>
  @action: Reverses items in array.
  @note: Returns true with success (array contains 2 or more items)
[==============================================================================}
function MArrayHelper.Reverse: Boolean; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Exchange(i, ((l - i) - 1));
end;

{==============================================================================]
  <Reversed>
  @action: Returns reversed version of array arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Reversed: MArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := Self[(l - i) - 1];
end;

{==============================================================================]
  <Reversement>
  @action: Reverses the elements of the array in place.
  @note: Performs an in-place symmetric swap of elements from both ends toward 
         the center. Returns True if the array length is greater than 1 and a 
         reversal occurred; otherwise returns False.
[==============================================================================}
function MArrayHelper.Reversement: Boolean; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  Result := (l > 1);
  if not Result then
    Exit; 
  i := -1;
  while (i.Increment < l.Decrement) do
    Swap(Self[i], Self[l]);
end;

{==============================================================================]
  <Reversified>
  @action: Returns a new array containing the elements of the original array 
           in reverse order.
  @note: Initializes a range structure spanning from index 0 to the high index 
         of the array. If the target array allocation succeeds, it uses a 
         two-pointer repeat-until loop, swapping elements from the outer edges 
         inward. Relies on custom integer helpers (start.Increment and 
         stop.Decrement) to advance the bounds and terminate the loop.
[==============================================================================}
function MArrayHelper.Reversified: MArray; overload;
var
  R: TRange;
begin
  R.Create(0, High(Self));
  if (Result.SetSize(R.stop + 1) > 0) then
  repeat
    Result[R.start] := Self[R.stop];
    Result[R.stop] := Self[R.start];
  until (R.start.Increment > R.stop.Decrement);
end;

{==============================================================================]
  <Reversify>
  @action: Reverses the order of elements in a 1D array.
           Works by creating a temporary array and copying elements in reverse order.
  @note: - The operation modifies Self in place.
         - Returns True if the array had 2 or more elements (reversal performed).
         - Returns False if the array had 0 or 1 element (nothing changed).
[==============================================================================}
function MArrayHelper.Reversify: Boolean; overload;
var
  s: MArray;
  i, l: Integer;
begin
  l := Self.Length;
  Result := (l > 1);
  if not Result then
    Exit;
  SetLength(s, l);
  for i := 0 to (l - 1) do
    s[i] := Self[(l - 1) - i];
  Self := s;
end;

{==============================================================================]
  <Reversion>
  @action: Returns array with items in reversed order.
  @note: None.
[==============================================================================}
function MArrayHelper.Reversion: MArray; overload;
var
  h, i, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, l);
  h := (l div 2);
  for i := 0 to (h - 1) do
  begin
    Result[i] := Self[(l - i) - 1];
    Result[(l - i) - 1] := Self[i];
  end;
  if l.Odd then
    Result[h] := Self[h];
end;

{==============================================================================]
  <Revert>
  @action: Returns a new array with the elements in reverse order.
  @note:
    - The original array remains unchanged.
    - Time complexity: O(n).
    - Space complexity: O(n) due to result allocation.
    - Equivalent to a non-destructive array reversal.
[==============================================================================}
function MArrayHelper.Revert: MArray; overload;
var
  h, i: Integer;
begin
  h := High(Self);
  SetLength(Result, (h + 1));
  for i := 0 to h do
    Result[i] := Self[h - i];
end;

{==============================================================================]
  <Reverted>
  @action: Returns a new array with the elements of the original array in 
           reverse order.
  @note: Uses a two-pointer approach meeting in the middle. Relies on custom 
         integer helpers (L.Increment and R.Decrement) acting as pre-operation 
         mutators to safely handle 0-based indexing and loop termination.
[==============================================================================}
function MArrayHelper.Reverted: MArray; overload;
var
  L, R: Integer;
begin
  R := Self.Length;
  SetLength(Result, R);
  if (R = 0) then
    Exit;
  L := -1;
  while (L.Increment <= R.Decrement) do
  begin
    Result[L] := Self[R];
    Result[R] := Self[L];
  end;
end;
{$ENDIF}