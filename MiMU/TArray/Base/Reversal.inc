{$IFDEF HELPERS}
function Antipodean: MArray; overload;
function Backwards: MArray; overload;
function Desrever: MArray; overload;
function Esrever: Boolean; overload;
function Flip: Boolean; overload;
function Obverse: MArray; overload;
function Obversed: MArray; overload;
function Oppose: Boolean; overload;
function Opposite: MArray; overload;
function Reflex(const rIndex: Integer): MType; overload;
function Reversal: MArray; overload;
function Reverse: Boolean; overload;
function Reversed: MArray; overload;
function ReverseEx: MArray; overload;
function Reversement: Boolean; overload;
function Reversified: MArray; overload;
function Reversify: Boolean; overload;
function Reversion: MArray; overload;
function Revert: MArray; overload;
function Reverted: MArray; overload;
function RReverse: MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Antipodean>
  @action: Returns a new array containing the elements of the original array 
           in reverse order.
  @note: Scans the source array backward from its highest index down to 0 using 
         a downto for-loop. It populates the destination array sequentially 
         from the beginning by utilizing a custom integer helper (r.Increase) 
         to step forward.
[==============================================================================}
function MArrayHelper.Antipodean: MArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  SetLength(Result, Self.Length);
  for i := High(Self) downto 0 do
    Result[r.Increase] := Self[i];
end;

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
  <Desrever>
  @action: Returns a new array containing the elements of the original array 
           in reverse order.
  @note: Allocates the target array size and uses a single forward for-loop 
         to scan the source array from index 0 upward. It populates the 
         destination array in reverse by utilizing a custom integer helper 
         (r.Decrement) to step backward from the end of the destination array.
[==============================================================================}
function MArrayHelper.Desrever: MArray; overload;
var
  i, r: Integer;
begin
  r := Result.SetSize(Self.Length);
  for i := 0 to High(Self) do
    Result[r.Decrement] := Self[i];
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
  <Obverse>
  @action: Returns a new array containing the elements of the original array
           in reverse order using a symmetric midpoint subtraction technique.
  @note: Allocates the target array and determines its maximum index boundary (h).
         Iterates forward through the source elements, mapping each input item
         directly to its corresponding mirrored offset position (h - i) in the
         destination array.
[==============================================================================}
function MArrayHelper.Obverse: MArray; overload;
var
  i, h: Integer;
begin
  h := (Result.SetSize(Self.Length) - 1);
  for i := 0 to h do
    Result[h - i] := Self[i];
end;

{==============================================================================]
  <Obversed>
  @action: Returns a new array containing the elements of the original array
           in reverse order (the "obverse" or opposite side).
  @param: None - operates on the current array instance.
  @return: MArray - A new array with the same elements as Self, but in
           reversed order. The original array is not modified.
  @note: Non-destructive. The name derives from "obverse" - the opposite
         side of a coin or object, reflecting the reversed nature of the
         output. Time complexity: O(n). Space complexity: O(n) for the
         result array. Equivalent to Self.Reversed but with an alternative
         naming convention.
  @example:
    // Assuming arr = [1, 2, 3, 4]
    newArr := arr.Obversed;  // newArr = [4, 3, 2, 1]
    // arr remains [1, 2, 3, 4]
[==============================================================================}
function MArrayHelper.Obversed: MArray; overload;
var
  s, l: Integer;
begin
  l := Result.SetSize(s.Assign(Self.Length));
  while (l.Decrement > -1) do
    Result[(s - l) - 1] := Self[l];
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
  <ReverseEx>
  @action: Returns a new array containing the elements of the original array
           in reverse order, utilizing optimized hardcoded branches for small
           array sizes.
  @note: Allocates the target array and evaluates its length. For lengths 0 to
         4, it completely bypasses loop overhead by hardcoding the direct
         index-to-index reverse assignments. For larger arrays, it falls back
         to a forward for-loop that populates the destination array backward
         via a custom integer helper (l.Decrement).
[==============================================================================}
function MArrayHelper.ReverseEx: MArray; overload;
var
  l, i: Integer;
begin
  l := Result.SetSize(Self.Length);
  case l of
    0: Exit;
    1: Result[0] := Self[0];
    2:
    begin
      Result[0] := Self[1];
      Result[1] := Self[0];
    end;
    3:
    begin
      Result[0] := Self[2];
      Result[1] := Self[1];
      Result[2] := Self[0];
    end;
    4:
    begin
      Result[0] := Self[3];
      Result[1] := Self[2];
      Result[2] := Self[1];
      Result[3] := Self[0];
    end;
  else
    for i := 0 to High(Result) do
      Result[l.Decrement] := Self[i];
  end;
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
  h := (Result.SetSize(Result, Self.Length) - 1);
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

{==============================================================================]
  <RReverse>
  @action: Returns a new array containing the elements of the original array 
           in reverse order using a recursive strategy.
  @note: Creates a duplicate of the original array via Self.Clone, then passes 
         it into a nested recursive function (R). The recursion walks inward 
         from both bounds (A and B), swapping elements at each step, and terminates 
         when the boundaries meet or cross.
[==============================================================================}
function MArrayHelper.RReverse: MArray; overload;
  function R(const C: MArray; const A, B: Integer): MArray;
  begin
    if (A >= B) then
      Exit(C);
    Result := C;
    Swap(Result[A], Result[B]);
    Result := R(Result, (A + 1), (B - 1));
  end;
begin
  Result := R(Self.Clone, 0, High(Self));
end;
{$ENDIF}
