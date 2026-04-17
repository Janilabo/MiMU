{$IFDEF METHODS}
function Align(const oAscending: Boolean = True): Boolean; overload;
function Arrange(const oAscending: Boolean = True): TRange; overload;
function Asc: TIntegerArray; overload;
function Ascend: TRange; overload;
function Ascended: TRange; overload;
function Desc: TIntegerArray; overload;
function Descend: TRange; overload;
function Descended: TRange; overload;
function Fix(const oAscending: Boolean = True): TRange; overload;
function Fixed(const oAscending: Boolean = True): TRange; overload;
function Order(const oAscending: Boolean = True): Boolean; overload;
function Ordered(const oAscending: Boolean = True): TRange; overload;
function OrderTo(const oAscending: Boolean = True): TRange; overload;
function Orient(const oAscending: Boolean = True): TRange; overload;
function Oriented(const oAscending: Boolean = True): TRange; overload;
function Sort(const oAscending: Boolean = True): Boolean; overload;
function Sorted(const oAscending: Boolean = True): TRange; overload;
function SortedTo(const oAscending: Boolean = True): TRange; overload;
function ToOrder(const oAscending: Boolean = True): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Align>
  @action: Ensures the range ordering matches the requested direction in-place.
  @note: Checks whether Self.start and Self.stop violate the desired ordering
         (ascending or descending). If so, swaps the bounds using System.Move.
         Returns True if a swap was performed, otherwise False.
[==============================================================================}
function TRange.Align(const oAscending: Boolean = True): Boolean; overload;
var
  x, s: Integer;
begin
  Result := ((oAscending and (Self.start > Self.stop)) or ((not oAscending) and (Self.start < Self.stop)));
  if Result then
  begin
    x := SizeOf(Integer);
    System.Move(Self.start, s, x);
    System.Move(Self.stop, Self.start, x);
    System.Move(s, Self.stop, x);
  end;
end;

{==============================================================================]
  <Arrange>
  @action: Returns a new range arranged in the specified order.
  @note:
    - If `oAscending = True`, the returned range will be ascending (`start <= stop`).
    - If `oAscending = False`, the returned range will be descending (`start >= stop`).
    - If the range is singular (start = stop), it is returned unchanged.
    - Uses `EnsureRange` to clamp endpoints safely within valid integer limits.
    - Useful for preparing a range for iteration, chunking, or other operations
      that require a specific ordering.
[==============================================================================}
function TRange.Arrange(const oAscending: Boolean = True): TRange; overload;
begin
  if Self.Singular then
    Result := Self
  else if oAscending then
    Result := TRange.Construct(EnsureRange(Self.start, Low(Integer), Self.stop), EnsureRange(Self.stop, Self.start, High(Integer)))
  else
    Result := TRange.Construct(EnsureRange(Self.stop, Self.start, High(Integer)), EnsureRange(Self.start, Low(Integer), Self.stop));
end;

{==============================================================================]
  <Asc>
  @action: Returns an ascending sequence of integers from Start to Stop.
  @note: If Start > Stop, the order is still ascending (from the smaller to the larger value).
[==============================================================================}
function TRange.Asc: TIntegerArray; overload;
var
  l, h, i: Integer;
begin
  SetLength(Result, Self.Size(l, h));
  for i := 0 to (h - l) do
    Result[i] := (l + i);
end;

{==============================================================================]
  <Ascend>
  @action: Returns ascending TRange of Self.
  @note: None.
[==============================================================================}
function TRange.Ascend: TRange; overload;
begin
  Result.start := Self.Minimum;
  Result.stop := Self.Maximum;
end;

{==============================================================================]
  <Ascended>
  @action: Returns TRange in ascending order.
  @note: None.
[==============================================================================}
function TRange.Ascended: TRange; overload;
begin
  if (Self.stop >= Self.start) then
    Result.Create(Self.start, Self.stop)
  else
    Result.Create(Self.stop, Self.start);
end;

{==============================================================================]
  <Desc>
  @action: Returns a descending sequence of integers from Stop down to Start.
  @note: If Start < Stop, the order is still descending (from the larger to the smaller value).
[==============================================================================}
function TRange.Desc: TIntegerArray; overload;
var
  l, h, i: Integer;
begin
  SetLength(Result, Self.Size(l, h));
  for i := 0 to (h - l) do
    Result[i] := (h - i);
end;

{==============================================================================]
  <Descend>
  @action: Returns descending TRange of Self.
  @note: None.
[==============================================================================}
function TRange.Descend: TRange; overload;
begin
  Result.start := Self.Maximum;
  Result.stop := Self.Minimum;
end;

{==============================================================================]
  <Descended>
  @action: Returns TRange in descending order.
  @note: None.
[==============================================================================}
function TRange.Descended: TRange; overload;
begin
  if (Self.start > Self.stop) then
    Result.Create(Self.start, Self.stop)
  else
    Result.Create(Self.stop, Self.start);
end;

{==============================================================================]
  <Fix>
  @action: Returns a new range with endpoints arranged according to the
           specified order, preserving the original range's size.
  @note:
    - If `oAscending = True`, the returned range will be ascending (`start <= stop`).
    - If `oAscending = False`, the returned range will be descending (`start >= stop`).
    - Singular ranges (start = stop) are returned unchanged.
    - Uses the range midpoint and half-width to reconstruct the range.
    - Useful when you want a guaranteed ordered range without changing its
      span or size.
[==============================================================================}
function TRange.Fix(const oAscending: Boolean = True): TRange; overload;
var
  c, h: Double;
begin
  if Self.Singular then
    Exit(Self);
  c := ((Self.start + Self.stop) / 2);
  h := (Abs(Self.start - Self.stop) / 2);
  if oAscending then
    Result.Create(Round(c - h), Round(c + h))
  else
    Result.Create(Round(c + h), Round(c - h));
end;

{==============================================================================]
  <Fixed>
  @action: Returns a normalized range with controlled ordering.
  @note: Reorders Self.start and Self.stop so the resulting range matches
         the requested direction. If oAscending is True, ensures
         start <= stop; otherwise ensures start >= stop. Uses index-based
         selection to swap bounds without branching.
[==============================================================================} 
function TRange.Fixed(const oAscending: Boolean = True): TRange; overload;
type
  I2 = array[0..1] of Integer;
begin
  Result.start := I2(Self)[Ord((Self.start > Self.stop) = oAscending)];
  Result.stop := I2(Self)[Ord((Self.start < Self.stop) = oAscending)];
end;

{==============================================================================]
  <Order>
  @action: Sorts the current TRange in-place according to oAscending.
           Returns True if a swap of Start and Stop was performed.
           Uses arithmetic trick with Ord() to determine order.
  @note: In-place version of Ordered; efficient, works for both ascending and descending.
[==============================================================================}
function TRange.Order(const oAscending: Boolean = True): Boolean; overload;
begin
  Result := (((Ord(oAscending) * 2 - 1) * (Self.Stop - Self.Start)) < 0);
  if Result then
    Swap(Self.start, Self.stop);
end;

{==============================================================================]
  <Ordered>
  @action: Returns a new TRange with Start and Stop ordered according to oAscending.
           Uses arithmetic trick with Ord() to determine order.
  @note: Functional version; does NOT modify the current record. Works for both ascending and descending.
[==============================================================================}
function TRange.Ordered(const oAscending: Boolean = True): TRange; overload;
begin
  if (((Ord(oAscending) * 2 - 1) * (Self.Stop - Self.Start)) >= 0) then
    Result.Create(Self.Start, Self.Stop)
  else
    Result.Create(Self.Stop, Self.Start);
end;

{==============================================================================]
  <OrderTo>
  @action: Normalizes the range to a specific direction (Ascending or Descending).
  @note: Acts as a toggleable normalizer; uses the boolean parameter to choose 
         between a Min-Max or Max-Min result.
[==============================================================================}
function TRange.OrderTo(const oAscending: Boolean = True): TRange; overload;
begin
  if oAscending then
    Result := TRange.Construct(Self.Minimum, Self.Maximum)
  else
    Result := TRange.Construct(Self.Maximum, Self.Minimum);
end;

{==============================================================================]
  <Orient>
  @action: Returns a range reordered to match the requested direction.
  @note: Produces an ascending or descending range depending on oAscending
         without mutating the original instance. Uses branchless bitwise
         operations (XOR and masking) to conditionally swap Self.start and
         Self.stop. Functionally equivalent to Fixed, but optimized to avoid
         conditional branching.
[==============================================================================}
function TRange.Orient(const oAscending: Boolean = True): TRange; overload;
var
  s: Integer;
begin
  s := -Ord(oAscending xor (Self.start < Self.stop));
  Result.start := (Self.start xor ((Self.start xor Self.stop) and s));
  Result.stop := (Self.stop xor ((Self.start xor Self.stop) and s));
end;

{==============================================================================]
  <Oriented>
  @action: Constructs a new range ordered according to the specified direction.
  @note: Returns a normalized range where bounds are explicitly selected
         using MinIntValue and MaxIntValue. If oAscending is True, the result
         satisfies start <= stop; otherwise start >= stop. This implementation
         is explicit and branch-based, contrasting with Orient’s branchless
         bitwise approach and Fixed’s index-based selection.
[==============================================================================}
function TRange.Oriented(const oAscending: Boolean = True): TRange; overload;
begin
  if oAscending then
    Result := TRange.Construct(MinIntValue([Self.start, Self.stop]), MaxIntValue([Self.start, Self.stop]))
  else
    Result := TRange.Construct(MaxIntValue([Self.start, Self.stop]), MinIntValue([Self.start, Self.stop]));
end;

{==============================================================================]
  <Sort>
  @action: Sorts the current TRange in-place according to oAscending.
           Returns True if a swap of Start and Stop was performed.
  @note: If oAscending=True, Start <= Stop after call; if False, Start >= Stop.
[==============================================================================}
function TRange.Sort(const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((oAscending and (Self.start > Self.stop)) or ((not oAscending) and (Self.stop > Self.start)));
  if Result then
    Swap(Self.stop, Self.start);
end;

{==============================================================================]
  <Sorted>
  @action: Returns a new TRange with Start and Stop ordered according to aAscending.
           Does NOT modify the current record.
  @note: If aAscending=True, ensures Start <= Stop; if False, Start >= Stop.
[==============================================================================}
function TRange.Sorted(const oAscending: Boolean = True): TRange; overload;
begin
  if ((oAscending and (Self.start > Self.stop)) or ((not oAscending) and (Self.start < Self.stop))) then
    Result.Create(Self.stop, Self.start)
  else
    Result.Create(Self.start, Self.stop);
end;

{==============================================================================]
  <Sorted>
  @action: Sort bounds in ascending/descending order and return new range
  @note: Uses QuickSorted helper; order controlled by oAscending parameter
[==============================================================================}
function TRange.SortedTo(const oAscending: Boolean = True): TRange; overload;
var
  t: TIntegerArray;
begin
  t := [Self.start, Self.stop];
  t.InsertionSort(oAscending);
  Result := TRange.Construct(t[0], t[1]);
end;

{==============================================================================]
  <ToOrder>
  @action: Returns a new range with endpoints reordered according to the
           specified order.
  @note:
    - If `oAscending = True`, the returned range will have `start <= stop`.
    - If `oAscending = False`, the returned range will have `start >= stop`.
    - If the range is already in the requested order, it is returned unchanged.
    - Uses branchless bitwise operations to conditionally swap endpoints.
    - Useful for calculations or iterations that require a specific range order.
[==============================================================================}
function TRange.ToOrder(const oAscending: Boolean = True): TRange; overload;
var
  m: Integer;
begin
  if oAscending then
    m := -Ord(Self.start > Self.stop)
  else
    m := -Ord(Self.start <= Self.stop);
  Result.start := (Self.start xor ((Self.start xor Self.stop) and m));
  Result.stop := (Self.stop  xor ((Self.start xor Self.stop) and m)); 
end;
{$ENDIF}
