{$IFDEF HELPERS}
function Antipodean: MArray; overload;
function Backwardize: MArray; overload;
function Backwards: MArray; overload;
function Converse: MArray; overload;
function Conversed: MArray; overload;
function Convert: MArray; overload;
function Desrever: MArray; overload;
function Destack: MArray; overload;
function Esrever: Boolean; overload;
function Flip: Boolean; overload;
function Obverse: MArray; overload;
function Obversed: MArray; overload;
function Obversion: MArray; overload;
function Oppose: Boolean; overload;
function Opposed: MArray; overload;
function Opposite: MArray; overload;
function Overturn: Boolean; overload;
function Rebel: MArray; overload;
function Reflex(const rIndex: Integer): MType; overload;
function Regress: MArray; overload;
function Relist: MArray; overload;
function Reverc: Boolean; overload;
function Reversal: MArray; overload;
function Reversally: MArray; overload;
function Reverse: Boolean; overload;
function Reversed: MArray; overload;
function ReversedEx: MArray; overload;
function Reversedly: MArray; overload;
function ReverseEx: MArray; overload;
function Reversement: Boolean; overload;
function Reversied: MArray; overload;
function Reversified: MArray; overload;
function Reversify: Boolean; overload;
function Reversion: MArray; overload;
function Reversively: MArray; overload;
function Reversivly: MArray; overload;
function Reversy: MArray; overload;
function Revert: MArray; overload;
function Reverta: MArray; overload;
function Reverte: MArray; overload;
function Reverted: MArray; overload;
function Reverto: MArray; overload;
function RReverse: MArray; overload;
function Snapshot: MArray; overload;
function Upend: Integer; overload;
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
  <Backwardize>
  @action: Reverses the sequence of elements in the array.
  @note: Dual-behavior operation: mutates the original array (Self) in-place 
         while simultaneously populates and returns a new reversed array (Result).
[==============================================================================}
function MArrayHelper.Backwardize: MArray; overload;
var
  l, r: Integer;
begin
  l := -1;
  r := Result.SetSize(Self.Length);
  while (l.Increment < r.Decrement) do
  begin
    Result[l] := Self[r];
    Result[r] := Self[l];
    Self[l] := Result[r];
    Self[r] := Result[l];
  end;
  if (l = r) then
    Result[l] := Self[l];
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
  l := Result.SetSize(Self.Length);
  i := 0;
  while (l > 0) do
    Result[i.Increase] := Self[l.Decrement];
end;

{==============================================================================]
  <Converse>
  @action: Reverses the order of elements in an MArray instance using a 
           recursive divide-and-conquer approach.
  @note: While functional, this recursive implementation has a time complexity 
         of O(N²) and high memory overhead due to repeated array slicing 
         (System.Copy) and concatenation (+) at every recursion depth. For 
         large datasets, an in-place iterative swap is highly recommended.
[==============================================================================}
function MArrayHelper.Converse: MArray; overload;
begin
  if (Self.Length < 2) then
    Exit(Self);
  Result := ([Self[High(Self)]] + System.Copy(Self, 0, High(Self)).Converse);
end;

{==============================================================================]
  <Conversed>
  @action: reates and returns a new array with the elements of the original array in reverse order.
  @note: Operates on a custom `MArray` type. It uses a `downto` loop to iterate from the highest index to 0,
        appending each element to the result.
		Note that array concatenation (`Result + [...]`) in a loop can be performance-intensive for very large arrays due to repeated reallocations.
[==============================================================================}
function MArrayHelper.Conversed: MArray; overload;
var
  i: Integer;
begin
  Result := [];
  for i := High(Self) downto 0 do
    Result := (Result + [Self[i]]);
end;

{==============================================================================]
  <Convert>
  @action: Transforms Self into its reversed form while capturing a 
           forward-facing copy in Result using a unified single-pass loop.
  @note: Employs a state-aware nested function (M) that dynamically shifts its 
         data source from Self to Result once the iteration index crosses the 
         array's midpoint, safely avoiding data corruption without explicit 
         midpoint branching inside the loop body.
[==============================================================================}
function MArrayHelper.Convert: MArray; overload;
var
  i, l: Integer;
  function M(const src, snap: MArray): MType;
  begin
    if (i <= (l div 2)) then
      Result := src[l - i]
    else
      Result := snap[l - i];
  end;
begin
  l := (Result.SetSize(Self.Length) - 1);
  for i := 0 to l do
    Result[i] := Self[i].IO(M(Self, Result));
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
  <Destack>
  @action: Returns a new array containing the elements of the original array
           in reverse order using a stack-based strategy.
  @note: Pushes all elements onto a generic stack, then pops them sequentially
         into the result array. The LIFO nature of the stack naturally produces
         the reversed order without any index arithmetic.
[==============================================================================}
function MArrayHelper.Destack: MArray; overload;
var
  s: specialize TStack<MType>;
  i, l: Integer;
begin
  l := Result.SetSize(Self.Length);
  s := specialize TStack<MType>.Create;
  try
    for i := 0 to (l - 1) do
      s.Push(Self[i]);
    for i := 0 to (l - 1) do
      Result[i] := s.Pop;
  finally
    s.Free;
  end;
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
  <Obversion>
  @action: Reverses the order of the elements in the MArray and returns the result.
  @note: This is a recursive implementation. While elegant, it may cause a stack 
         overflow error on exceptionally large arrays due to the deep call stack 
         and repeated array copying.
[==============================================================================}
function MArrayHelper.Obversion: MArray; overload;
begin
  if (Self.Length < 2) then
    Exit(Self);
  Result := (System.Copy(Self, 1, (Self.Length - 1)).Obversion + [Self[0]]);
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
  Result := (l.Assign(Self.Length) > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Self.Exch(i, ((l - 1) - i));
end;

{==============================================================================]
  <Opposed>
  @action: Reverses the order of elements in the array in-place using a 
           two-pointer iterative approach.
  @note: Highly efficient O(N) time complexity with O(1) auxiliary space. 
         Note that this implementation relies on side-effect modifications 
         within the loop condition (.Increment and .Decrement helpers) to 
         advance the pointers before each swap.
[==============================================================================}
function MArrayHelper.Opposed: MArray; overload;
var
  L, R: Integer;
  S: MType;
begin
  Result := System.Copy(Self);
  L := -1;
  R := Result.Length;
  while (L.Increment < R.Decrement) do
  begin
    S := Result[L];
    Result[L] := Result[R];
    Result[R] := S;
  end;
end;

{==============================================================================]
  <Opposite>
  @action: Returns a new array containing the elements of the current array
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
  <Overturn>
  @action: Reverses the order of the elements within the MArray in place, 
           mutating the original structure. Returns True if the array was 
           long enough to be modified (Length > 1), otherwise False.
  @note: Highly optimized via loop unrolling. By swapping 4 element pairs 
         simultaneously from the outside edges inward, it significantly 
         reduces loop overhead and maximizes cache performance. Completely 
         safe from stack overflows.
[==============================================================================}
function MArrayHelper.Overturn: Boolean; overload;
var
  l, h: Integer;
  C: MType;
procedure S(const A, B: Integer);
begin
  C := Self[A];
  Self[A] := Self[B];
  Self[B] := C;
end;
begin
  h := High(Self);
  Result := (h > 0);
  if not Result then
    Exit;
  l := 0;
  while ((l + 3) < (h - 3)) do
  begin
    S((l + 3), (h - 3));
	S((l + 2), (h - 2));
    S((l + 1), (h - 1));
	S(l.Increase(4), h.Decrease(4));
  end;
  while (l < h) do
    S(l.Increase, h.Decrease);
end;

{==============================================================================]
  <Rebel>
  @action: Reverses the order of elements in the array using a backward-looping 
           mechanism controlled by an explicit goto label.
  @note: Achieves O(N) efficiency by pre-allocating the result array and copying 
         elements directly. However, the use of a 'goto' statement and sequential 
         labels deviates from modern structured programming paradigms (like for/while loops).
[==============================================================================}
function MArrayHelper.Rebel: MArray; overload;
label
  loop;
var
  i, s: Integer;
begin
  s := High(Self);
  if (s < 1) then
    Exit(Self.Copy);
  SetLength(Result, (s + 1));
  i := 0;
  loop:
  Result[i.Increase] := Self[s];
  if (s.Decrement > -1) then
    goto loop;
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
  <Regress>
  @action: Returns a new array with the elements of the original array in 
           completely reversed order.
  @note: Performs the reversal by interleaving elements in two forward passes. 
         The first pass fills even-indexed positions by reading backward from 
         the end of the source. The second pass fills odd-indexed positions 
         continuing the backward read, seamlessly weaving the full reversed array.
[==============================================================================}
function MArrayHelper.Regress: MArray; overload;
var
  i, l, j, s: Integer;
begin
  l := Result.SetSize(Self.Length);
  s := (l - 1);
  for j := -2 to -1 do
  begin
    i := j;
    while (i.Increment(2) < l) do
      Result[i] := Self[s - i];
  end;
end;

{==============================================================================]
  <Relist>
  @action: Returns a new array containing the elements of the original array
           in reverse order by leveraging TList<T>.Reverse from the
           Generics.Collections unit.
  @note: The name is a portmanteau of "reverse" and "list". The method creates
         a generic TList<MType>, appends all elements from Self, calls the
         built‑in Reverse method (which reverses the list in‑place), and then
         copies the elements back to a new MArray result. While not the most
         memory‑efficient (requires two passes and a separate list), it
         demonstrates reusing the standard collection library. The original
         array remains unchanged.
[==============================================================================}
function MArrayHelper.Relist: MArray; overload;
var
  l: specialize TList<MType>;
  i: Integer;
begin
  if (Self.Length < 2) then
    Exit(Self.Clone);
  l := specialize TList<MType>.Create;
  try
    for i := 0 to High(Self) do
      l.Add(Self[i]);
    l.Reverse;
    SetLength(Result, l.Count);
    for i := 0 to (l.Count - 1) do
      Result[i] := l[i];
  finally
    l.Free;
  end;
end;

{==============================================================================]
  <Reverc>
  @action: Reverses the array in‑place using a recursive two‑pointer swap.
  @note: Zero extra array allocations. Recursion depth = N/2, so it may
         cause stack overflow for huge arrays (N > 50 000). Included here
         to demonstrate a pure recursive mutation, distinct from your
         allocation‑heavy recursive versions.
[==============================================================================}
function MArrayHelper.Reverc: Boolean; overload;
  procedure R(L, H: Integer);
  begin
    if (L >= H) then
      Exit;
    Swap(Self[L], Self[H]);
    R((L + 1), (H - 1));
  end;
begin
  Result := (Self.Length > 1);
  if Result then
    R(0, High(Self));
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
  <Reversally>
  @action: Creates and returns a new array with the elements of the source array in reverse order.
  @note: Employs a center-pivot mirroring algorithm. It calculates the mathematical midpoint 
         of the array and uses coordinate reflection (distance from the pivot) to map elements 
         from their original positions to their mirrored, reversed indices.
[==============================================================================}
function MArrayHelper.Reversally: MArray; overload;
var
  i, d, l: Integer;
  m: Double;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(Self.Copy);
  SetLength(Result, l);
  d := (l div 2);
  case l.Even of
    True:
    begin
      m := (d - 0.5);
      for i := 0 to (l - 1) do
      case m.Compare(i) of
        0: Result[i] := Self[i];
        1: Result[i] := Self[Round(m + (m - i))];
        -1: Result[i] := Self[Round(m - (i - m))];
      end;
    end;
    False:
    for i := 0 to (l - 1) do
    case d.Compare(i) of
      0: Result[i] := Self[i];
      1: Result[i] := Self[d + (d - i)];
      -1: Result[i] := Self[d - (i - d)];
    end;
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
  Result := (l.Assign(Self.Length) > 1);
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
  l := Result.SetSize(Self.Length);
  for i := 0 to (l - 1) do
    Result[i] := Self[(l - i) - 1];
end;

{==============================================================================]
  <ReversedEx>
  @action: Reverses the order of the elements in the MArray and returns the result.
  @note: Uses an optimized hybrid approach. Small arrays (lengths 0 to 5) are 
         handled instantly via hardcoded lookup cases to eliminate loop overhead. 
         Larger arrays are safely reversed iteratively using a single loop, 
         making it highly performant and completely safe from stack overflows.
[==============================================================================}
function MArrayHelper.ReversedEx: MArray; overload;
var
  h, i: Integer;
begin
  h := High(Self); 
  case h of
    -1: Exit([]);
    0: Exit([Self[0]]);
    1: Exit([Self[1], Self[0]]);
    2: Exit([Self[2], Self[1], Self[0]]);
    3: Exit([Self[3], Self[2], Self[1], Self[0]]);
    4: Exit([Self[4], Self[3], Self[2], Self[1], Self[0]]);
  end;
  SetLength(Result, (h + 1));
  for i := 0 to h do
    Result[i] := Self[h - i];
end;

{==============================================================================]
  <Reversedly>
  @action: Allocates a new array and copies the elements of the source array in reverse order.
  @note: Returns a new inverted array without modifying the original source array (Self).
[==============================================================================}
function MArrayHelper.Reversedly: MArray; overload;
var
  l, r: Integer;
begin
  l := Result.SetSize(Self.Length);
  if (l = 0) then
    Exit;
  r := -1;
  while (l.Decrement > -1) do
    Result[r.Increment] := Self[l];
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
  <Reversied>
  @action: Allocates and fills a new array with the elements of the source array in reverse order.
  @note: Uses a single-variable backward iteration (`downto`). By looping from the end of the 
         source array to the beginning, it cleanly maps the current source index ('i') to its 
         inverted destination index calculated via `High(Self) - i`.
[==============================================================================}
function MArrayHelper.Reversied: MArray; overload;
var
  i: Integer;
begin
  for i := (Result.SetSize(Self.Length) - 1) downto 0 do
    Result[High(Self) - i] := Self[i];
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
  <Reversively>
  @action: Returns a new array with the elements of the source array in reverse order.
  @note: Efficiently allocates the required memory upfront and maps elements to their 
         inverted indices, achieving an optimized linear time complexity ($O(n)$).
[==============================================================================}
function MArrayHelper.Reversively: MArray; overload;
var
  i, l: Integer;
begin
  l := Result.SetSize(Self.Length);
  for i := 0 to (l - 1) do
    Result[(l - 1) - i] := Self[i];
end;

{==============================================================================]
  <Reversivly>
  @action: Returns a new array containing the elements of the source array in reverse order.
  @note: Uses a loop to continuously insert elements at index 0 of the result array.
         Note that this approach incurs a performance penalty ($O(n^2)$ complexity) due to repeated memory shifting during insertion.
[==============================================================================}
function MArrayHelper.Reversivly: MArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    Insert(Self[i], Result, 0);
end;

{==============================================================================]
  <Reversy>
  @action: Populates and returns a pre-allocated array with elements from the source array in reverse order.
  @note: Uses a synchronized dual-index traversal (converging/shifting pointers). The destination index ('l') 
         moves sequentially forward while the source index ('r') moves backward, transferring elements 
         in a single pass.
[==============================================================================}
function MArrayHelper.Reversy: MArray; overload;
var
  l, r, s: Integer;
begin
  s := Result.SetSize(Self.Length);
  l := 0;
  r := (s - 1);
  while (l < s) do
    Result[l.Increase] := Self[r.Decrease];
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
  h := (Result.SetSize(Self.Length) - 1);
  for i := 0 to h do
    Result[i] := Self[h - i];
end;

{==============================================================================]
  <Reverta>
  @action: Duplicates the array sequence into Result, then reverses Self.
  @note: Uses two separate sequential passes: the first loop clones Self into 
         Result forward; the second loop uses Result to overwrite Self backward.
[==============================================================================}
function MArrayHelper.Reverta: MArray; overload;
var
  i, l: Integer;
begin
  l := (Result.SetSize(Self.Length) - 1);
  for i := 0 to l do
    Result[i] := Self[i];
  for i := 0 to l do
    Self[i] := Result[l - i];
end;

{==============================================================================]
  <Reverte>
  @action: Performs a simultaneous forward-copy and backward-swap in a single 
           pass across the first half of the array.
  @note: Optimized single-pass variant. The loop explicitly terminates at the 
         midpoint (l div 2) to safely swap the outer bounds inward without 
         overwriting or corrupting the data sequence.
[==============================================================================}
function MArrayHelper.Reverte: MArray; overload;
var
  i, l: Integer;
begin
  l := (Result.SetSize(Self.Length) - 1);
  for i := 0 to (l div 2) do
  begin
    Result[i] := Self[i];
    Self[i] := Self[l - i];
    Result[l - i] := Self[i];
    Self[l - i] := Result[i];
  end;
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
  R := Result.SetSize(Self.Length);
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
  <Reverto>
  @action: Simultaneously clones the original elements into Result while 
           reversing Self from the outside in.
  @note: Highly optimized midpoint pass (0 to m). Copies mirrored elements into 
         Result first to safely use them as buffers for the inversion of Self. 
         Explicitly captures the absolute center element for odd-sized lengths.
[==============================================================================}
function MArrayHelper.Reverto: MArray; overload;
var
  i, l, m: Integer;
begin
  l := (Result.SetSize(Self.Length) - 1);
  m := (l div 2);
  for i := 0 to m do
  begin
    Result[i] := Self[i];
    Result[l - i] := Self[l - i];
    Self[i] := Result[l - i];
    Self[l - i] := Result[i];
  end;
  if l.Even then
    Result[m] := Self[m];
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

{==============================================================================]
  <Snapshot>
  @action: Captures a clean, forward-facing duplicate of the array sequence.
  @note: Dual-behavior side effect: The returned clone (Result) preserves the 
         original array layout, while the source array (Self) is completely 
         reversed in-place.
[==============================================================================}
function MArrayHelper.Snapshot: MArray; overload;
var
  l, r: Integer;
begin
  l := -1;
  r := Result.SetSize(Self.Length);
  while (l.Increment < r.Decrement) do
  begin
    Result[l] := Self[l];
    Result[r] := Self[r];
    Self[l] := Result[r];
    Self[r] := Result[l];
  end;
  if (l = r) then
    Result[l] := Self[l];
end;

{==============================================================================]
  <Upend>
  @action: Reverses the order of the elements in the array in-place.
  @note: Modifies the original array by swapping pairs from the outside inward. 
         Returns the number of swaps performed (the midpoint index).
[==============================================================================}
function MArrayHelper.Upend: Integer; overload;
var
  h, i: Integer;
begin
  Result := ((h.Assign(High(Self)) + 1) div 2);
  for i := 0 to (Result - 1) do
    Swap(Self[i], Self[h - i]);
end;
{$ENDIF}
