{$IFDEF HELPERS}
function Backwards: MArray; overload;
function Flip: Boolean; overload;
function Oppose: Boolean; overload;
function Opposite: MArray; overload;
function Reversal: MArray; overload;
function Reverse: Boolean; overload;
function Reversed: MArray; overload;
function Reversement: Boolean; overload;
function Reversify: Boolean; overload;
function Reversion: MArray; overload;
function Revert: MArray; overload;
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
{$ENDIF}