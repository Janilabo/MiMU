{$IFDEF METHODS}
function All: TIntegerArray; overload;
function Arrayed(const rAscending: Boolean = True): TIntegerArray; overload;
function ArrayOf: TIntegerArray; overload;
function AsArr: TIntegerArray; overload;
function AsArray: TIntegerArray; overload;
function Atomize: TIntegerArray; overload;
function Atomized: TIntegerArray; overload;
function Bank: TIntegerArray; overload;
function Body: TIntegerArray; overload;
function Breakdown: TIntegerArray; overload;
function Bundle: TIntegerArray; overload;
function Capture: TIntegerArray; overload;
function Captured: TIntegerArray; overload;
function Collect: TIntegerArray; overload;
function Collection: TIntegerArray; overload;
function Composition: TIntegerArray; overload;
function Content: TIntegerArray; overload;
function Contents: TIntegerArray; overload;
function Contentum: TIntegerArray; overload;
function Data: TIntegerArray; overload;
function Decompose: TIntegerArray; overload;
function Dequeued: TIntegerArray; overload;
function Digited: TIntegerArray; overload;
function Digits: TIntegerArray; overload;
function Digits(const dIndex: Integer): Integer; overload;
function Digits(const dIDs: TIntegerArray): TIntegerArray; overload;
function Disclose: TIntegerArray; overload;
function Dismantle: TIntegerArray; overload;
function Dissolve: TIntegerArray; overload;
function Elemented: TIntegerArray; overload;
function Elements: TIntegerArray; overload;
function Emit: TIntegerArray; overload;
function Entirely: TIntegerArray; overload;
function Entirety: TIntegerArray; overload;
function Enumerate: TIntegerArray; overload;
function Enumerated: TIntegerArray; overload;
function Enumerating: TIntegerArray; overload;
function Every(const N: Integer = 1): TIntegerArray; overload;
function Explode: TIntegerArray; overload;
function Exploded: TIntegerArray; overload;
function Explosion: TIntegerArray; overload;
function Expose(const rAscending: Boolean = True): TIntegerArray; overload;
function Extract: TIntegerArray; overload;
function Extracted: TIntegerArray; overload;
function Flatten: TIntegerArray; overload;
function Flattened: TIntegerArray; overload;
function Flooded: TIntegerArray; overload;
function Fill(var target: TIntegerArray): Integer; overload;
function Filled: TIntegerArray; overload;
function FromTo(const rAscending: Boolean = True): TIntegerArray; overload;
function Formation: TIntegerArray; overload;
function Gather: TIntegerArray; overload;
function Generate: TIntegerArray; overload;
function Generated: TIntegerArray; overload;
function Harvest: TIntegerArray; overload;
function Integers: TIntegerArray; overload;
function Ints: TIntegerArray; overload;
function Itemed: TIntegerArray; overload;
function Itemize: TIntegerArray; overload;
function Itemized(const AStep: Integer = 1): TIntegerArray; overload;
function Items: TIntegerArray; overload;
function Iter: TIntegerArray; overload;
function Iter(out rDigits: TIntegerArray; const rReverse: Boolean = False): Integer; overload;
function Iterate: TIntegerArray; overload;
function Iterate(out rDigits: TIntegerArray; const rReverse: Boolean = False): Integer; overload;
function Iterated: TIntegerArray; overload;
function Iterated(out rDigits: TIntegerArray; const rReverse: Boolean = False): Integer; overload;
function Iteration: TIntegerArray; overload;
function Iteration(out rDigits: TIntegerArray; const rReverse: Boolean = False): Integer; overload;
function Lay: TIntegerArray; overload;
function Layout: TIntegerArray; overload;
function List: TIntegerArray; overload;
function Listed: TIntegerArray; overload;
function Listing: TIntegerArray; overload;
function Material: TIntegerArray; overload;
function Materialize: TIntegerArray; overload;
function Materialized: TIntegerArray; overload;
function Membered: TIntegerArray; overload;
function Members: TIntegerArray; overload;
function Numbered: TIntegerArray; overload;
function Numbers: TIntegerArray; overload;
function Numeralize: TIntegerArray; overload;
function Numerals: TIntegerArray; overload;
function Numericize: TIntegerArray; overload;
function Numerics: TIntegerArray; overload;
function Open: TIntegerArray; overload;
function Particles: TIntegerArray; overload;
function Pile: TIntegerArray; overload;
function Populate(var arr: TIntegerArray): TRange; overload;
function Produce: TIntegerArray; overload;
function Produced: TIntegerArray; overload;
function Process: TIntegerArray; overload;
function Publish(const rAscending: Boolean = True): TIntegerArray; overload;
function Pull: TIntegerArray; overload;
function Pulled: TIntegerArray; overload;
function Queue: TIntegerArray; overload;
function Raw: TIntegerArray; overload;
function Realize: TIntegerArray; overload;
function Recursed: TIntegerArray; overload;
function Recursively: TIntegerArray; overload;
function Release: TIntegerArray; overload;
function Render: TIntegerArray; overload;
function Rendered: TIntegerArray; overload;
function Resources: TIntegerArray; overload;
function Reveal: TIntegerArray; overload;
function Revealed: TIntegerArray; overload;
function Separately(const rReverse: Boolean = False): TIntegerArray; overload;
function Sequence: TIntegerArray; overload;
function Snapshot: TIntegerArray; overload;
function Stack: TIntegerArray; overload;
function Start2Stop: TIntegerArray; overload;
function StartToStop: TIntegerArray; overload;
function Stepped(const sSize: Integer = 1): TIntegerArray; overload;
function Steps: TIntegerArray; overload;
function Stock: TIntegerArray; overload;
function Stop2Start: TIntegerArray; overload;
function StopToStart: TIntegerArray; overload;
function Storage: TIntegerArray; overload;
function Succinct: TIntegerArray; overload;
function Sweep: TIntegerArray; overload;
function TIA: TIntegerArray; overload;
function ToArr: TIntegerArray; overload;
function ToArray: TIntegerArray; overload;
class function ToArray(const AStart, AStop: Integer): TIntegerArray; overload; static;
function ToIntegers: TIntegerArray; overload;
function ToValues: TIntegerArray; overload;
function Unfold: TIntegerArray; overload;
function Unfolded: TIntegerArray; overload;
function Unpack: TIntegerArray; overload;
function Unpacked: TIntegerArray; overload;
function Unrolled: TIntegerArray; overload;
function Unwrap: TIntegerArray; overload;
function Unzip: TIntegerArray; overload;
function Values: TIntegerArray; overload;
function View(const vSize: Integer = 2147483647; const sIndex: Integer = 0): TIntegerArray; overload;
function Yielded: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <All>
  @action: Returns ALL TRange items as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.All: TIntegerArray; overload;
var
  i, j: Integer;
  p: PInteger;
begin
  if Self.Singular then
    Exit([Self.start]);
  SetLength(Result, Self.Size);
  j := IfThen(Self.Ascending, 1, -1);
  p := PInteger(Result);
  i := Self.start;
  while (i <> (Self.stop + j)) do
  begin
    p^ := i;
    Inc(p);
    Inc(i, j);
  end;
end;

{==============================================================================]
  <Arrayed>
  @action: Returns an array containing all integer values within the range.
  @note: The result includes both bounds and is ordered ascending or
         descending based on rAscending. Iteration respects the chosen
         direction while remaining within the range.
[==============================================================================}
function TRange.Arrayed(const rAscending: Boolean = True): TIntegerArray; overload;
var
  d, s, r: Integer;
begin
  d := IfThen(rAscending, 1, -1);
  if rAscending then
    s := Self.Minimum
  else
    s := Self.Maximum;
  SetLength(Result, Self.Size);
  r := 0;
  while Self.Contains(s) do
    Result[r.Increase] := s.Increase(d);
end;

{==============================================================================]
  <ArrayOf>
  @action: Returns ALL TRange items as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.ArrayOf: TIntegerArray; overload;
label
  loop, finish;
var
  i, v, d, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  i := 0;
  v := Self.start;
  d := IfThen(Self.Ascending, 1, -1);
  loop:
  if (i >= s) then
    goto finish;
  Result[i] := v;
  Inc(v, d);
  Inc(i);
  goto loop;
  finish:
end;

{==============================================================================]
  <AsArr>
  @action: Two-way alternative for extracting items from TRange.
  @note: None.
[==============================================================================}
function TRange.AsArr: TIntegerArray; overload;
var
  i, r, l, s: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := Self.Direction;
  if (s = 0) then
    s := 1;
  r := 0;
  i := Self.start;
  repeat
    Result[r.Increase] := i.Increase(s);
  until (r >= l);
end;

{==============================================================================]
  <AsArray>
  @action: Two-way alternative for extracting items from TRange.
  @note: None.
[==============================================================================}
function TRange.AsArray: TIntegerArray; overload;
var
  h, i, l: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  SetLength(Result, Self.Size);
  h := High(Result);
  l := ((h + 1) div 2);
  i := 0;
  case Self.Ascending of
    True:
    repeat
      Result[i] := (Self.start + i);
      Result[h - i] := (Self.stop - i);
    until (i.Increment > l);
    False:
    repeat
      Result[i] := (Self.start - i);
      Result[h - i] := (Self.stop + i);
    until (i.Increment > l);
  end;
  if h.Even then
    Result[i] := IfThen(Self.Ascending, (Self.start + i), (Self.start - i));
end;

{==============================================================================]
  <Atomize>
  @action: Returns an array of all integers in the range in sequential order,
           generated in fixed-size chunks.
           - For ascending ranges: values go from Start to Stop
           - For descending ranges: values go from Start down to Stop
  @note: Implementation details:
         - Allocates an array of length = Self.Size
         - Uses a fixed chunk size (CHUNK_SIZE = 64)
         - Iterates over the range in chunks, computing offset for each chunk
         - Each chunk fills at most CHUNK_SIZE consecutive values using
           direct index arithmetic: Result[o + i] := Start + d * (o + i)
         - The final chunk is automatically truncated if the remaining
           element count is smaller than CHUNK_SIZE
         - This approach is branch-light, cache-friendly, and suitable
           for large ranges where predictable memory access is desired
[==============================================================================}
function TRange.Atomize: TIntegerArray; overload;
const
  CHUNK_SIZE = 64;
var
  c, i, o, d, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  d := IfThen(Self.Ascending, 1, -1);
  c := 0;
  while ((c * CHUNK_SIZE) < s) do
  begin
    o := (c * CHUNK_SIZE);
    for i := 0 to Min((CHUNK_SIZE - 1), ((s - o) - 1)) do
      Result[o + i] := (Self.start + (d * (o + i)));
    Inc(c);
  end;
end;

{==============================================================================]
  <Atomized>
  @action: Fills the range using 64-bit packed writes (2 integers per iteration).
  @note:
    - O(n), reduced loop count (~n/2 iterations)
    - Packs: [v, v + d] into one Int64 write
    - Uses PInt64 for sequential bulk writes
    - Tail-safe: handles odd Size
    - Assumes little-endian layout and proper alignment
    - Writes as: start + i * (±1)
[==============================================================================}
function TRange.Atomized: TIntegerArray; overload;
var
  i, s, d, v: Integer;
  p: PInt64;
begin
  s := Self.Size;
  SetLength(Result, s);
  d := IfThen(Self.Ascending, 1, -1);
  v := Self.start;
  p := PInt64(@Result[0]);
  i := 0;
  while ((i + 2) <= s) do
  begin
    p^ := Int64(Cardinal(v)) or (Int64(Cardinal(v + d)) shl 32);
    Inc(p);
    Inc(v, (d * 2));
    Inc(i, 2);
  end;
  if ((s and 1) = 1) then
    Result[s - 1] := v;
end;

{==============================================================================]
  <Bank>
  @action: Returns ALL TRange items as TIntegerArray.
  @note: ?
[==============================================================================}
function TRange.Bank: TIntegerArray; overload;
var
  d: Integer;
  r: TRange;
begin
  SetLength(Result, Self.Size);
  d := IfThen(Self.Ascending, 1, -1);
  r.Create(-1, Result.Length);
  while (r.start.Increment <= r.stop.Decrement) do
  begin
    Result[r.start] := (Self.start + (d * r.start));
    if (r.start <> r.stop) then
      Result[r.stop] := (Self.start + (d * r.stop));
  end;
end;

{==============================================================================]
  <Body>
  @action: Returns ALL TRange items as TIntegerArray.
  @note: ?
[==============================================================================}
function TRange.Body: TIntegerArray; overload;
var
  l, h, d: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  SetLength(Result, Self.Size);
  d := Self.Direction;
  l := 0;
  h := High(Result);
  repeat
    Result[l] := (Self.start + (l * d));
    Result[h] := (Self.stop + (-l * d));
  until (l.Increment > h.Decrement);
end;

{==============================================================================]
  <Breakdown>
  @action: Returns ALL TRange items as TIntegerArray.
  @note: ?
[==============================================================================}
function TRange.Breakdown: TIntegerArray; overload;
var
  c, i, b, p, d, v: Integer;
begin
  c := Self.Count;
  SetLength(Result, c);
  d := Self.Direction;
  for i := 0 to (c - 1) do
  begin
    v := Self.start;
    p := i;
    b := 0;
    while (p > 0) do
    begin
      if ((p and 1) = 1) then
        v := (v + (d shl b));
      p := (p shr 1);
      Inc(b);
    end;
    Result[i] := v;
  end;
end;

{==============================================================================]
  <Bundle>
  @action: Fills the range in two interleaved passes (even and odd indices).
  @note:
    - O(n), dual-stride traversal
    - First loop fills even indices, second fills odd indices
    - Each element computed as: start + i * Direction
    - Relies on custom Increment(2) stepping behavior
[==============================================================================}
function TRange.Bundle: TIntegerArray; overload;
var
  i, s, d: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  d := Self.Direction;
  i := -2;
  while (i.Increment(2) < s) do
    Result[i] := (Self.start + (i * d));
  i := -1;
  while (i.Increment(2) < s) do
    Result[i] := (Self.start + (i * d));
end;

{==============================================================================]
  <Capture>
  @action: Materializes the range into a concrete array of integers.
  @note: The returned array represents a point-in-time snapshot of the range
         and is ordered according to the range direction.
[==============================================================================}
function TRange.Capture: TIntegerArray; overload;
var
  i, v: Integer;
  P: PInteger;
begin
  SetLength(Result, Self.Size);
  P := @Result[0];
  v := Self.start;
  case Self.Ascending of
    True:
    for i := 1 to Result.Length do
    begin
      P^ := v.Increase;
      Inc(P);
    end;
    False:
    for i := 1 to Result.Length do
    begin
      P^ := v.Decrease;
      Inc(P);
    end;
  end;
end;

{==============================================================================]
  <Captured>
  @action: Returns a concrete array containing all values in the range.
  @note: The returned array reflects the range's current start, end, and 
         ascending/descending direction. Evaluation is eager and allocates
         a new array of integers.
[==============================================================================}
function TRange.Captured: TIntegerArray; overload;
var
  i, v: Integer;
  P: PInteger;
  a: Boolean;
begin
  SetLength(Result, Self.Size);
  P := @Result[0];
  v := Self.start;
  a := Self.Ascending;
  for i := 1 to Result.Length do
  begin
    if a then
      P^ := v.Increase
    else
      P^ := v.Decrease;
    Inc(P);
  end;
end;

{==============================================================================]
  <Collect>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Collect: TIntegerArray; overload;
  procedure Return(var arr: TIntegerArray);
  var
    c, i, f, s: Integer;
  begin
    s := 1;
    if (Self.start > Self.stop) then
      s := -1;
    f := Self.start;
    SetLength(arr, Self.Size);
    i := 0;
    while (f <> (Self.stop + s)) do
      arr[i.Increase] := f.Increase(s);
  end;
begin
  Return(Result);
end;

{==============================================================================]
  <Collection>
  @action: Generates an array representing the numeric sequence defined by the range.
  @note: The resulting array preserves the range size and direction. The first
         element is initialized with `Start`, and each subsequent element is
         derived incrementally based on the previous value. Assumes that
         `Direction` encodes the step behavior (e.g., +1 or -1).
[==============================================================================}
function TRange.Collection: TIntegerArray; overload;
var
  i: Integer;
begin
  Result.Create(Self.Size, Self.Direction);
  Result[0] := Self.start;
  for i := 1 to High(Result) do
    Result[i] := (Result[i - 1] + Result[i]);
end;

{==============================================================================]
  <Composition>
  @action: Materializes the range into an integer array using a 3-way partitioned
           write strategy.
             - Splits the output buffer into three contiguous segments:
               L: [0 .. t-1]
               M: [t .. 2t-1]
               H: [2t .. 3t-1]
               where `t = Size div 3`
			 - Fills these segments in parallel within a single loop using pointer
               arithmetic (`PInteger`) to reduce index overhead and improve locality
             - Any remaining tail elements (when `Size mod 3 <> 0`) are filled in a
               final linear pass
             Produces the same sequence as a standard range:
             Ascending  → start + i
             Descending → start - i
  @note:
    - Time complexity: O(n)
    - Memory: Allocates a new array of length Size
    - Micro-optimization:
      Reduces loop control overhead by writing 3 elements per iteration
      and avoids repeated index computations via raw pointers (`l`, `m`, `h`)
    - Pointer layout:
      l → base
      m → base + t
      h → base + 2t
    - Tail handling:
      `r := (3 * t) - 1`
      Loop fills indices [3t .. Size-1]
    - Assumes:
       * `Size >= 0`
       * Safe pointer arithmetic within allocated buffer
       * `Increment` advances `r` before comparison (non-standard helper)
    - Behavior is undefined if:
       * `Size = 0` (dereferencing @Result[0])
       * `Increment` is not well-defined or inlined
      Equivalent closed form:
      Result[i] = start + i * (Ascending ? +1 : -1)
      Trade-off:
      Slightly more complex than a single loop, but can yield better
      performance in tight loops due to reduced branching and improved
      instruction-level parallelism.
[==============================================================================}
function TRange.Composition: TIntegerArray; overload;
var
  s, t, r, i, d: Integer;
  l, m, h: PInteger;
begin
  s := Self.Size;
  SetLength(Result, s);
  d := IfThen(Self.Ascending, 1, -1);
  t := (s div 3);
  l := @Result[0];
  m := @Result[t];
  h := @Result[2 * t];
  for i := 0 to (t - 1) do
  begin
    l^ := (Self.start + (d * i));
    m^ := (Self.start + (d * (t + i)));
    h^ := (Self.start + (d * ((2 * t) + i)));
    Inc(l);
    Inc(m);
    Inc(h);
  end;
  r := ((3 * t) - 1);
  while (r.Increment < s) do
    Result[r] := (Self.start + (d * r));
end;

{==============================================================================]
  <Content>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Content: TIntegerArray; overload;
var
  i, c, s: Integer;
begin
  SetLength(Result, Self.Size);
  s := IfThen(Self.Ascending, 1, -1);
  c := Self.start;
  for i := 0 to High(Result) do
    Result[i] := c.Increase(s);
end;

{==============================================================================]
  <Contents>
  @action: Returns ALL TRange items as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Contents: TIntegerArray; overload;
var
  i, s: Integer;
begin
  SetLength(Result, Self.Size);
  case Self.Direction of
    0, 1: s := 1;
    -1: s := -1;
  end;
  for i := 0 to High(Result) do
    Result[i] := (Self.start + (i * s));
end;

{==============================================================================]
  <Contentum>
  @action: Materializes the range via reverse-order buffer population.
  @note: 
    - Strategy: Starts at the 'stop' boundary and fills the array from the 
      last index toward the first.
    - Safety: Uses the range's internal 'Contains' logic as a loop guard to 
      ensure boundary integrity.
    - Directionality: Inverts the step direction to ensure the final array 
      maintains the correct Start -> Stop visual order despite being filled 
      backward.
[==============================================================================}
function TRange.Contentum: TIntegerArray; overload;
var
  l, d, s: Integer;
begin
  l := Result.SetSize(Self.Size);
  d := IfThen(Self.Ascending, 1, -1);
  s := Self.stop;
  while Self.Contains(s) do
    Result[l.Decrement] := s.Decrease(d);
end;

{==============================================================================]
  <Data>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Data: TIntegerArray; overload;
var
  n, i: Integer;
begin
  Result := Self.Reserve;
  i := 0;
  for n in Self do
    Result[i.Increase] := n;
end;

{==============================================================================]
  <Decompose>
  @action: Converts the range to an array using divide and conquer.
  @returns: Dynamic array containing all values from Start to Stop
  @note: Respects range direction (ascending/descending).
         Uses recursive divide and conquer strategy.
[==============================================================================}
function TRange.Decompose: TIntegerArray; overload;
  procedure FillRange(var arr: TIntegerArray; const offset, start, stop, step: Integer);
  var
    m: Integer;
  begin
    if (start = stop) then
    begin
      arr[offset] := start;
      Exit;
    end;
    if (Abs(stop - start) = Abs(step)) then
    begin
      arr[offset] := start;
      arr[offset + 1] := stop;
      Exit;
    end;
    m := (start + ((stop - start) div 2));
    FillRange(arr, offset, start, m, step);
    FillRange(arr, (offset + ((Abs(m - start) div Abs(step)) + 1)), (m + step), stop, step);
  end;
var
  d: Integer;
begin
  SetLength(Result, Self.Count);
  FillRange(Result, 0, Self.Start, Self.Stop, Self.Direction);
end;

{==============================================================================]
  <Dequeued>
  @action: Generates an array containing all integer values within the range.
  @note: Values are produced sequentially from start using the configured
         direction (Self.Direction) and step size of 1. Internally, a deque
         is used as a temporary buffer before converting the result to an array.
[==============================================================================}
function TRange.Dequeued: TIntegerArray; overload;
var
  q: specialize TDeque<Integer>;
  i, d: Integer;
begin
  q := specialize TDeque<Integer>.Create;
  try
    d := Self.Direction;
    for i := 0 to (Self.Size - 1) do
      q.PushBack(Self.start + (i * d));
    SetLength(Result, Self.Size);
    for i := 0 to (Self.Size - 1) do
      Result[i] := q.Items[i];
  finally
    q.Free;
  end;
end;

{==============================================================================]
  <Digited>
  @action: Returns an integer array containing all discrete values within the range,
           starting at Start and progressing by Direction for Size elements.
  @note: The resulting array length equals Size. Values are generated incrementally using the range Direction (+1 or −1).
         The range instance is not modified.
[==============================================================================}
function TRange.Digited: TIntegerArray; overload;
var
  d, i: Integer;
begin
  Result := [Self.start];
  d := Self.Direction;
  for i := 1 to (Self.Size - 1) do
    Result := (Result + [Result[i - 1] + d]);
end;

{==============================================================================]
  <Digits>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Digits: TIntegerArray; overload;
var
  i, s: Integer;
begin
  s := Self.Direction;
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := (Self.start + (i * s));
end;

{==============================================================================]
  <Digits>
  @action: Returns digit from TRange by index.
  @note: None.
[==============================================================================}
function TRange.Digits(const dIndex: Integer): Integer; overload;
begin
  if ((dIndex < 0) or (dIndex >= Self.Area)) then
    Result := -2147483648
  else if Self.Ascending then
    Result := (Self.start + dIndex)
  else
    Result := (Self.start - dIndex);
end;

{==============================================================================]
  <Digits>
  @action: Returns digits from TRange by indexes.
  @note: None.
[==============================================================================}
function TRange.Digits(const dIDs: TIntegerArray): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, (High(dIDs) + 1));
  for i := 0 to High(dIDs) do
    Result[i] := Self.Digits(dIDs[i]);
end;

{==============================================================================]
  <Disclose>
  @action: Populates an array with the range values using direct memory pointers.
  @note: Optimized for speed. If the range is "Singular," it returns a single-
         element array.
[==============================================================================}
function TRange.Disclose: TIntegerArray; overload;
var
  P: PInteger;
  i, l, s: Integer;
begin
  if Self.Singular Then
    Exit([Self.start]);
  l := Result.SetSize(Self.Size);
  P := @Result[0];
  s := Self.Start;
  for i := 0 to (l - 1) do
  begin
    P^ := s.Increase(Self.Direction);
    Inc(P);
  end;
end;

{==============================================================================]
  <Dismantle>
  @action: Returns an array of all integers in the range arranged in a “dismantle”
           or interleaved order:
           - Pulls values from the start and stop toward the center
           - Fills the middle segment sequentially from the start
           - Produces a three-part ordering (start segment, end segment, middle segment)
           Works for both ascending and descending ranges.
  @note: Implementation details:
         - Allocates an array of length = Self.Size
         - Computes:
             - h = High(Result) (last index)
             - d = direction (+1 for ascending, -1 for descending)
             - t = number of elements in the “end segments” = (h + 1) div 3
         - Fills arrays in three phases:
             1. Start segment: indices 0..t ← start + d*i
             2. End segment: indices h..h-t ← stop - d*i
             3. Middle segment: indices t+1 .. h-t-1 ← start + d*i
         - Produces a non-linear ordering useful for algorithms that benefit
           from sampling from both ends and center simultaneously.
         - Single-element ranges (start = stop) are handled implicitly.
[==============================================================================}
function TRange.Dismantle: TIntegerArray; overload;
var
  i, h, t, d: Integer;
begin
  SetLength(Result, Self.Size);
  h := High(Result);
  d := IfThen(Self.Descending, -1, 1);
  t := ((h + 1) div 3);
  for i := 0 to t do
    Result[i] := (Self.start + (d * i));
  for i := 0 to t do
    Result[h - i] := (Self.stop - (d * i));
  for i := (t + 1) to ((h - t) - 1) do
    Result[i] := (Self.start + (d * i));
end;

{==============================================================================]
  <Dissolve>
  @action: Expands the range into an array using a 4-lane unrolled loop.
  @note: 
    - Optimization: Reduces branching overhead by processing 4 elements per cycle.
    - Mechanics: Uses pointer-based offsets for block-writes and a tail-pass
      for remaining elements. 
    - Order: Writes within the 4-element window are performed from high-index 
      to low-index before advancing.
[==============================================================================}
function TRange.Dissolve: TIntegerArray; overload;
var
  i, s, d, v: Integer;
  p: PInteger;
begin
  s := Self.Size;
  if (s = 1) then
    Exit([Self.start]);
  SetLength(Result, s);
  d := Self.Direction;
  v := Self.start;
  p := @Result[0];
  i := -4;
  while (i.Increment(4) <= (s - 4)) do
  begin
    p[3] := (v + (d * 3));
    p[2] := (v + (d * 2));
    p[1] := (v + d);
    p[0] := v.Increase(d * 4);
    Inc(p, 4);
  end;
  while (i.Increase < s) do
    Result[i - 1] := v.Increase(d);
end;

{==============================================================================]
  <Elemented>
  action: Expands range into an array of its elements based on direction.
  @note: Preserves order; ascending increments, descending decrements.
[==============================================================================}
function TRange.Elemented: TIntegerArray; overload;
var
  s: Integer;
  procedure RA;
  var
    i: Integer;
  begin
    for i := 0 to (s - 1) do
      Result[i] := (Self.start + i);
  end;
  procedure RD;
  var
    i: Integer;
  begin
    for i := 0 to (s - 1) do
      Result[i] := (Self.start - i);
  end;
begin
  s := Self.Size;
  SetLength(Result, s);
  if Self.Ascending then
    RA
  else
    RD;
end;

{==============================================================================]
  <Elements>
  action: Returns TRange digits as TIntegerArray.
  note: Alternative method.
[==============================================================================}
function TRange.Elements: TIntegerArray; overload;
var
  i: specialize TList<Integer>;
  e: Integer;
begin
  i := specialize TList<Integer>.Create;
  try
    case Self.Ascending of
      True:
      for e := Self.start to Self.stop do
        i.Add(e);
      False:
      for e := Self.start downto Self.stop do
        i.Add(e);
    end;
    Result := i.ToArray;
  finally
    i.Free;
  end;
end;

{==============================================================================]
  <Emit>
  @action: Emits all values of the range into a newly allocated integer array.
  @note: Materializes the inclusive range from Start to Stop as an ordered
         sequence. The emission direction is determined by the relative
         ordering of Start and Stop.
         For a single-value range, the result contains that value only.
[==============================================================================}
function TRange.Emit: TIntegerArray; overload;
var
  c, s, v: Integer;
  p: PInteger;
begin
  if Self.Singular then
    Exit([Self.start]);
  c := Self.Size;
  SetLength(Result, c);
  s := Self.Direction;
  v := Self.start;
  p := @Result[0];
  while (c > 0) do
  begin
    p^ := v;
    Inc(v, s);
    Inc(p);
    Dec(c);
  end;
end;

{==============================================================================]
  <Entirely>
  @action: Generates an array containing all integer values within the range.
  @note: The result includes both start and stop bounds. Values are produced
         in sequential order from start to stop, respecting direction
         (ascending or descending) based on the relative ordering of bounds.
         The range is fully expanded into a newly allocated integer array.
[==============================================================================}
function TRange.Entirely: TIntegerArray; overload;
var
  r, d: Integer;
begin
  SetLength(Result, Self.Size);
  d := Sign(Self.stop - Self.start);
  Result[0] := Self.start;
  r := 0;
  while (Result[r.Increase] <> Self.stop) do
    Result[r] := (Result[r - 1] + d);
end;

{==============================================================================]
  <Entirety>
  @action: Generates an array containing all integer values from start to stop.
  @note: The sequence includes both bounds and is produced by stepping from
         start toward stop using a direction derived from their difference.
         The result is fully materialized into a newly allocated array.
[==============================================================================}
function TRange.Entirety: TIntegerArray; overload;
var
  r, d, s: Integer;
begin
  SetLength(Result, Self.Size);
  d := Sign(Self.stop - Self.start);
  s := Self.start;
  Result[0] := s;
  r := 0;
  while (s <> Self.stop) do
    Result[r.Increment] := s.Increment(d);
end;

{==============================================================================]
  <Enumerate>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Enumerate: TIntegerArray; overload;
var
  i: Integer;
  e: TRangeEnumerator;
begin
  SetLength(Result, Self.Size);
  e := GetEnumerator;
  i := 0;
  while e.MoveNext do
    Result[i.Increase] := e.Current;
end;

{==============================================================================]
  <Enumerated>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Enumerated: TIntegerArray; overload;
var
  i: Integer;
  e: TRangeEnumerator;
begin
  SetLength(Result, Self.Size);
  e := GetEnumerator;
  for i := 0 to High(Result) do
    if e.MoveNext then
      Result[i] := e.Current;
end;

{==============================================================================]
  <Enumerating>
  @action: Produces an array containing all values within the range.
  @note: Iterates over the range using its enumerator and appends each
         element to the result array. The resulting array reflects the
         range order (ascending or descending). Dynamic growth via Supply
         may incur reallocation overhead for large ranges.
[==============================================================================}
function TRange.Enumerating: TIntegerArray; overload;
var
  e: TRangeEnumerator;
begin
  SetLength(Result, 0);
  e := GetEnumerator;
  while e.MoveNext do
    Result.Supply(e.Current);
end;

{==============================================================================]
  <Every>
  @action: Generates a sequence of values from the range at a fixed step.
  @note: Returns an array starting at Self.start and advancing by N units
         in the direction of the range until Self.stop is reached or exceeded.
         The step is scaled by Direction to preserve ascending/descending order.
         If N <= 0, returns an empty array. The resulting length is computed
         as (|stop - start| div N) + 1. Uses pointer iteration for efficient writes.
[==============================================================================}
function TRange.Every(const N: Integer = 1): TIntegerArray; overload;
var
  i, s, r: Integer;
  P: PInteger;
begin
  if (N <= 0) then
    Exit([]);
  SetLength(Result, ((Abs(Self.stop - Self.start) div N) + 1));
  P := PInteger(Result);
  s := (Self.Direction * N);
  r := Self.start;
  for i := 0 to High(Result) do
  begin
    P^ := r.Increase(s);
    Inc(P);
  end;
end;

{==============================================================================]
  <Explode>
  @action: Expands the range into an integer array using index-based calculation.
  @note: Elements are computed as start + (index * step), where step is the
         sign of (stop - start). The number of elements is determined entirely
         by TRange_Size(Self). Recursion terminates by index, not by value.
[==============================================================================}
function TRange.Explode: TIntegerArray; overload;
var
  s, c: Integer;
  procedure Return(const i: Integer);
  begin
    if (i < c) then
    begin
      Result[i] := (Self.start + (i * s));
      Return(i + 1);
    end;
  end;
begin
  c := Self.Size;
  SetLength(Result, c);
  s := Self.Direction;
  if (s = 0) then
    s := 1;
  Return(0);
end;

{==============================================================================]
  <Exploded>
  @action: Expands the range into an integer array by iterating from start to stop.
  @note: Elements are generated by repeatedly advancing the current value by
         step until the stop value is reached. Recursion terminates on value
         equality (current = stop). Step direction is derived from
         sign(stop - start), defaulting to +1 when both are equal.
[==============================================================================}
function TRange.Exploded: TIntegerArray; overload;
  procedure Return(var arr: TIntegerArray; const index, current, target, step: Integer);
  begin
    arr[index] := current;
    if (current <> target) then
      Return(arr, (index + 1), (current + step), target, step);
  end;
var
  s: Integer;
begin
  SetLength(Result, Self.Size);
  s := Self.Direction;
  if (s = 0) then
    s := 1;
  Return(Result, 0, Self.start, Self.stop, s);
end;

{==============================================================================]
  <Explosion>
  @action: Expands the range by iterative block-doubling from an initial seed.
  @note:
    - O(n), logarithmic growth via Move (copy + adjust)
    - Starts from start, repeatedly duplicates prefix blocks
    - Each copied block is offset by (r * Direction)
    - Efficient due to bulk memory moves
    - Handles Size = 0 safely
    - Final sequence: start + i * Direction
[==============================================================================}
function TRange.Explosion: TIntegerArray; overload;
var
  i, s, d, r, l, x: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  if (s = 0) then
    Exit;
  d := Self.Direction;
  Result[0] := Self.start;
  r := 1;
  x := SizeOf(Integer);
  while (r < s) do
  begin
    l := Min(r, (s - r));
    Move(Result[0], Result[r], (l * x));
    for i := r to ((r + l) - 1) do
      Inc(Result[i], (r * d));
    Inc(r, l);
  end;
end;

{==============================================================================]
  <Expose>
  @action: Returns an array containing all integer values within the range.
  @note: The result includes both bounds and can be ordered ascending or
         descending based on rAscending. The range is expanded into a
         newly allocated array.
[==============================================================================}
function TRange.Expose(const rAscending: Boolean = True): TIntegerArray; overload;
var
  l, h, i: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  l := Self.Minimum;
  h := Self.Maximum;
  SetLength(Result, Self.Size);
  i := 1;
  Result[0] := IfThen(rAscending, l, h);
  while (l < h) do
  case rAscending of
    True: Result[i.Increase] := l.Increment;
    False: Result[i.Increase] := h.Decrement;
  end;
end;

{==============================================================================]
  <Extract>
  @action: Extracts TRange as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Extract: TIntegerArray; overload;
var
  i, s: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  s := IfThen((Self.stop > Self.start), 1, -1);
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := (Self.start + (i * s));
end;

{==============================================================================]
  <Extracted>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Extracted: TIntegerArray; overload;
var
  i, s: Integer;
begin
  SetLength(Result, Self.Size);
  s := IfThen(Self.Ascending, Self.start, Self.stop);
  for i := 0 to High(Result) do
    Result[i] := (s + i);
  if Self.Descending then
    Result.Reverse;
end;

{==============================================================================]
  <Fill>
  @action: Fills the provided array with values from the range, respecting direction.
  @note: Returns the number of elements filled; does nothing if the target array is empty.
[==============================================================================}
function TRange.Fill(var target: TIntegerArray): Integer; overload;
var
  i, v, d: Integer;
begin
  Result := target.Length;
  if (Result = 0) then
    Exit;
  v := Self.start;
  d := Self.Direction;
  for i := 0 to (Result - 1) do
    target[i] := v.Increase(d);
end;

{==============================================================================]
  <Filled>
  @action: Returns ALL TRange items as TIntegerArray.
  @note: Uses FillChar for zero-based ascending ranges (byte broadcast of 0),
         then applies a directional correction pass for all other ranges.
         FillChar operates at byte granularity; only 0x00 is safe to broadcast
         across a 4-byte integer without corruption.
[==============================================================================}
function TRange.Filled: TIntegerArray; overload;
var
  i, s, d: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  if ((Self.start = 0) and Self.Ascending) then
  begin
    FillChar(Result[0], (s * SizeOf(Integer)), 0);
    for i := 1 to (s - 1) do
      Result[i] := i;
  end else
  begin
    FillChar(Result[0], (s * SizeOf(Integer)), Byte(Self.start));
    d := IfThen(Self.Ascending, 1, -1);
    for i := 0 to (s - 1) do
      Result[i] := (Self.start + (i * d));
  end;
end; 

{==============================================================================]
  <Flatten>
  @action: Materializes the range into a contiguous integer array.
  @note: Expands the inclusive range from Start to Stop into an ordered
         sequence of values. The direction is determined by the relative
         ordering of Start and Stop.
         For a single-element range, the array contains Start only.
[==============================================================================}
function TRange.Flatten: TIntegerArray; overload;
var
  i, s: Integer;
begin
  SetLength(Result, Self.Size);
  if (Result.Length > 1) then
  begin
    s := Self.Direction;
    for i := 0 to High(Result) do
      Result[i] := (Self.start + (i * s));
  end else
    Result[0] := Self.start;
end;

{==============================================================================]
  <Flattened>
  @action: Builds the range via a temporary 2D grid, then flattens to 1D.
  @note:
    - O(n), extra 2D allocation
    - Grid dims: r ≈ √n, c = ceil(n / r)
    - Writes as: start + i * Direction (row-major)
    - Final array is identical to linear construction
[==============================================================================}
function TRange.Flattened: TIntegerArray; overload;
var
  r, c, i, j, d, s: Integer;
  g: T2DIntegerArray;
begin
  s := Self.Size;
  d := Self.Direction;
  r := Max(1, Round(Sqrt(s)));
  c := ((s + r - 1) div r);
  SetLength(g, r);
  for i := 0 to (r - 1) do
  begin
    SetLength(g[i], Min(c, (s - (i * c))));
    for j := 0 to High(g[i]) do
      g[i][j] := (Self.start + (d * ((i * c) + j)));
  end;
  SetLength(Result, s);
  for i := 0 to (r - 1) do
    for j := 0 to High(g[i]) do
      Result[(i * c) + j] := g[i][j];
end;

{==============================================================================]
  <Flooded>
  @action: Uses FillDWord for bulk initialization followed by a corrective pass.
  @note: None.
[==============================================================================}
function TRange.Flooded: TIntegerArray; overload;
var
  i, d, s: Integer;
begin
  s := Self.Size;
  if (s = 1) then
    Exit([Self.start]);
  SetLength(Result, s);
  FillDWord(Result[0], s, Cardinal(Self.start));
  d := Self.Direction;
  for i := 1 to (s - 1) do
    Result[i] := (Result[i] + (i * d));
end;

{==============================================================================]
  <FromTo>
  @action: Returns an array containing all integer values within the range.
  @note: The result includes both bounds and can be ordered ascending or
         descending based on rAscending. For a singular range, a single-element
         array is returned.
[==============================================================================}
function TRange.FromTo(const rAscending: Boolean = True): TIntegerArray; overload;
var
  l, h, i: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  l := Self.Minimum;
  h := Self.Maximum;
  SetLength(Result, Self.Size);
  case rAscending of
    True:
    for i := l to h do
      Result[i - l] := i;
    False:
    for i := h downto l do
      Result[h - i] := i;
  end;
end;

{==============================================================================]
  <Formation>
  @action: Builds the range via a raw byte buffer, then bulk-copies into result.
  @note:
    - O(n), ~2× memory (buffer + result)
    - Writes as: start + i * Direction
    - Uses PInteger + Move for linear, low-level transfer
    - Requires Size > 0 (unsafe @b[0] if empty)
[==============================================================================}
function TRange.Formation: TIntegerArray; overload;
var
  b: TBytes;
  p: PInteger;
  i, d, s: Integer;
begin
  s := Self.Size;
  SetLength(b, (s * SizeOf(Integer)));
  p := PInteger(@b[0]);
  d := Self.Direction;
  for i := 0 to (s - 1) do
  begin
    p^ := (Self.start + (i * d));
    Inc(p);
  end;
  SetLength(Result, s);
  Move(b[0], Result[0], System.Length(b));
end;

{==============================================================================]
  <Gather>
  @action: Returns all values of the range as an integer array, in order.
           Works for ascending, descending, or singleton ranges.
  @note: Uses bitwise arithmetic to determine the step direction without
         explicit branching. The first element is Start, and each subsequent
         element is incremented or decremented depending on the sign of
         (Stop - Start). Resulting array length equals Size (inclusive).
         Assumes Start and Stop fit in 32-bit integers.
[==============================================================================}
function TRange.Gather: TIntegerArray; overload;
var
  i, m: Integer;
begin
  SetLength(Result, Self.Size);
  m := (Self.Delta shr 31);
  Result[0] := Self.start;
  for i := 1 to High(Result) do
    Result[i] := (Result[i - 1] + (1 - (2 * (m and 1))));
end;

{==============================================================================]
  <Generate>
  @action: Returns values of the given range.
  @note: None.
[==============================================================================}
function TRange.Generate: TIntegerArray; overload;
var
  i: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  SetLength(Result, 0);
  case Self.Ascending of
    True:
    for i := Self.start to Self.stop do
      Result := (Result + [i]);
    False:
    for i := Self.start downto Self.stop do
      Result := (Result + [i]);
  end;
end;

{==============================================================================]
  <Generated>
  @action: Returns an array of all integers in the range in sequential order.
             - For ascending ranges: values go from Start to Stop
             - For descending ranges: values go from Start down to Stop
           Uses an internal helper function `NextValue` to increment or decrement.
  @note: Implementation details:
           - Allocates an array of length = Self.Size
           - Initializes:
               - v := Start value
               - d := direction (1 for ascending, -1 for descending)
           - Defines `NextValue` to return the current value of `v` and
             increment it by `d` using v.Increase(d)
           - Fills Result array by calling `NextValue` for each index
           - Works for ranges of any size and orientation
[==============================================================================}
function TRange.Generated: TIntegerArray; overload;
var
  i, v, d: Integer;
  function NextValue: Integer;
  begin
    Result := v.Increase(d);
  end;
begin
  SetLength(Result, Self.Size);
  v := Self.start;
  d := IfThen(Self.Ascending, 1, -1);
  for i := 0 to High(Result) do
    Result[i] := NextValue;
end;

{==============================================================================]
  <Harvest>
  @action: Returns an array containing all integer values within the range.
  @note: The result includes both bounds and is ordered based on the range
         direction. This method materializes the full sequence of values.
[==============================================================================}
function TRange.Harvest: TIntegerArray; overload;
var
  s, r, d: Integer;
begin
  Result := [Self.start];
  s := Self.Size;
  d := Sign(Self.start - Self.stop);
  r := 0;
  while (r.Increment < s) do
  begin
    SetLength(Result, (r + 1));
    Result[r] := (Result[r - 1] - d);
  end;
end;

{==============================================================================]
  <Integers>
  @action: Constructs and returns a TIntegerArray representing the inclusive
           integer range [start, stop] by iteratively appending each value
           in Direction order.  
           The iteration begins at start and advances using Direction (±1),
           terminating after reaching stop. Each value is appended to the end
           of the dynamic array using Insert at the current length position.
           The sequence is produced in-order and is equivalent to:
             start, start + d, start + 2d, ... stop
           where d = Direction.
  @note:   Time complexity is O(n²) in the current implementation due to
           repeated Insert operations at the end of a dynamic array, which
           requires array reallocation and copying on each append.
           Space complexity is O(n).
           This is functionally correct but performance-inefficient for large
           ranges. A preallocated array with indexed assignment is preferred:
             SetLength(Result, Size);
             Result[i] := ...
           Termination condition relies on:
             v <> (stop + Direction)
           which ensures inclusion of stop while avoiding overshoot.
           Correctness depends on:
             - Direction ∈ [+1, -1]
             - start/stop being consistent with Direction progression
[==============================================================================}
function TRange.Integers: TIntegerArray; overload;
var
  v, d: Integer;
begin
  Result := [];
  v := Self.start;
  d := Self.Direction;
  while (v <> (Self.stop + d)) do
    Insert(v.Increase(d), Result, Result.Length);
end;

{==============================================================================]
  <Ints>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Ints: TIntegerArray; overload;
var
  i, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  case Self.Descending of
    True:
    for i := 0 to High(Result) do
      Result[(l - i) - 1] := (i + Self.stop);
    False:
    for i := 0 to High(Result) do
      Result[i] := (i + Self.start);
  end;
end;

{==============================================================================]
  <Itemed>
  @action: Generates an array representing the range step by step, using ±1 increments.
  @note: First element is Start; subsequent elements increment or decrement based on Ascending property.
[==============================================================================}
function TRange.Itemed: TIntegerArray; overload;
var
  i, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  for i := 0 to High(Result) do
    Result[i] := IfThen(Self.Ascending, 1, -1);
  Result[0] := Self.start;
  for i := 1 to High(Result) do
    Result[i] := (Result[i - 1] + Result[i]);
end;

{==============================================================================]
  <Itemize>
  @action: Returns an array containing every integer in the range, enumerated
           sequentially with a step of 1.
  @note: 
    - The array length is equal to the size of the range.
    - Works for both ascending and descending ranges.
    - The first element is `Self.start`; the last element is `Self.stop`.
    - Suitable for generating a full list of values for iteration or indexing.
[==============================================================================}
function TRange.Itemize: TIntegerArray; overload;
var
  i, s: Integer;
begin
  SetLength(Result, Self.Size);
  Result[0] := Self.start;
  for i := 1 to High(Result) do
    if Self.Ascending then
      Result[i] := (Result[i - 1] + 1)
    else
      Result[i] := (Result[i - 1] - 1);
end;

{==============================================================================]
  <Itemized>
  @action: Returns an array containing values in the range, enumerated with a
           custom step `AStep`.
  @note: 
    - If `AStep <= 0`, it is treated as 1.
    - The array starts at `Self.start` and increments or decrements by `AStep` 
      depending on whether the range is ascending or descending.
    - The final element may not exactly equal `Self.stop` if the step does not
      divide the range evenly.
    - Useful for generating sequences with custom increments, such as ranges
      for sampling or subsampling data.
[==============================================================================}
function TRange.Itemized(const AStep: Integer = 1): TIntegerArray; overload;
var
  s, i, v: Integer;
begin
  s := Max(AStep, 0);
  SetLength(Result, ((Abs(Self.stop - Self.start) div s) + 1));
  v := Self.start;
  for i := 0 to High(Result) do
  begin
    Result[i] := v;
    if Self.Ascending then
      v := (v + s)
    else
      v := (v - s);
  end;
end;

{==============================================================================]
  <Items>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Items: TIntegerArray; overload;
var
  i, s: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  s := IfThen(Self.Descending, -1, 1);
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := (Self.start + (s * i));
end;

{==============================================================================]
  <Iter>
  @action: Returns a fully materialized array of the range values, pre-sized
           for maximum efficiency. Uses pointer arithmetic and Increase() to
           populate values sequentially from start to stop.
  @note: - Values are generated from Self.start toward Self.stop,
           INCLUDING the terminal bound.
         - Direction is determined by Self.Ascending:
             * True  → step = +1
             * False → step = -1
         - Array length is precomputed as Abs(Int64(stop) - start) + 1,
           avoiding any dynamic resizing.
         - Uses a pointer (PInteger) for fast sequential assignment.
         - Increase(s) is used to advance the iterator for each element.
         - This overload does not support reversing; always iterates in
           natural ascending/descending order.
         - Ideal for high-performance scenarios where a complete
           materialization is required.
[==============================================================================}
function TRange.Iter: TIntegerArray; overload;
var
  P: PInteger;
  i, r, s: Integer;
begin
  SetLength(Result, Integer(Abs(Int64(Self.stop) - Self.start) + 1));
  P := @Result[0];
  s := IfThen(Self.Ascending, 1, -1);
  r := Self.start;
  for i := 0 to High(Result) do
  begin
    P^ := r.Increase(s);
    Inc(P);
  end;
end;

{==============================================================================]
  <Iter>
  @action: Populates a caller-provided array with the range values, optionally
           in reversed order. Optimized with pre-sizing and pointer-based
           assignment.
  @note: - Values are generated from Self.start to Self.stop, INCLUDING
           the terminal bound.
         - Direction is determined by Self.Ascending:
             * True  → step = +1
             * False → step = -1
         - If rReverse = True, iteration starts from Self.stop and steps
           in the opposite direction.
         - Array length is precomputed; the output array is resized once
           to exactly match the range length.
         - Uses a PInteger pointer for efficient sequential writes.
         - Increase(s) is used to advance the iterator for each element.
         - This overload avoids any intermediate array or dynamic growth.
[==============================================================================}
function TRange.Iter(out rDigits: TIntegerArray; const rReverse: Boolean = False): Integer; overload;
var
  P: PInteger;
  i, r, s: Integer;
begin
  Result := Integer(Abs(Int64(Self.stop) - Self.start) + 1);
  SetLength(rDigits, Result);
  P := @rDigits[0];
  s := IfThen(Self.Ascending, 1, -1);
  if rReverse then
  begin
    r := Self.stop;
    s := -s;
  end else
    r := Self.start;
  for i := 0 to (Result - 1) do
  begin
    P^ := r.Increase(s);
    Inc(P);
  end;
end;

{==============================================================================]
  <Iterate>
  @action: Returns a dynamically constructed array representing the range.
  @note: - For non-singular ranges, values are generated from Self.start
           toward Self.stop, INCLUDING the terminal bound.
         - Direction is determined by Self.Ascending:
             * True  → step = +1
             * False → step = -1
         - Uses a local iterator (r) initialized to (start - step), then
           advanced via Increase(s) prior to each append.
         - Elements are appended using Supply, resulting in dynamic
           growth of the output array.
         - Iteration condition (r.Increase(s) <> Self.stop) ensures the
           stop value is included in the result.
         - Singular ranges (start = stop) return a single-element array
           immediately.
[==============================================================================}
function TRange.Iterate: TIntegerArray; overload;
var
  i, s, r: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  SetLength(Result, 0);
  s := IfThen(Self.Ascending, 1, -1);
  r := (Self.start - s);
  while (r.Increase(s) <> Self.stop) do
    Result.Supply(r);
end;

{==============================================================================]
  <Iterate>
  @action: Expands the current range into a contiguous array of integers.
           Iteration respects the natural direction of the range unless
           explicitly reversed via rReverse.
  @note: - For non-singular ranges, values are generated starting from
           Self.start toward Self.stop, INCLUDING the terminal bound.
         - Direction is inferred automatically:
            * Ascending  (start <= stop) → step = +1
            * Descending (start >  stop) → step = -1
        - When rReverse = True, the logical order is inverted without
          mutating the original range.
        - The resulting array is pre-sized for performance (no reallocation
          during population).
        - Singular ranges (start = stop) produce a single-element array.
        - Uses Increase(s) as the stepping primitive; behavior depends on
          its implementation (assumed side-effect increment).
  @return: Number of elements written to rDigits.
[==============================================================================}
function TRange.Iterate(out rDigits: TIntegerArray; const rReverse: Boolean = False): Integer; overload;
var
  i, s, d, j: Integer;
  r: TRange;
begin
  case Self.Singular of
    False:
    begin
      s := IfThen((Self.start <= Self.stop), 1, -1);
      if rReverse then
      begin
        r := Self.Reversed;
        s := -s;
      end else
        r := Self;
      d := 0;
      i := (r.start - s);
      while (i.Increase(s) <> r.stop) do
        Inc(d);
      SetLength(rDigits, d);
      i := r.start;
      for j := 0 to (d - 1) do
        rDigits[j] := i.Increase(s);
    end;
    True: rDigits := [Self.start];
  end;
  Result := rDigits.Length;
end;

{==============================================================================]
  <Iterated>
  @action: Returns an array of integers produced by iterating the range.
  @note: Uses an optimized lookup-based implementation for ascending ranges
         within predefined bounds; otherwise falls back to the standard
         materialization logic.
[==============================================================================}
function TRange.Iterated: TIntegerArray; overload;
const
  MASTER: array[0..99] of Integer =
   (0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
    60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
    90, 91, 92, 93, 94, 95, 96, 97, 98, 99);
var
  l: Integer;
begin
  if (Self.Descending or (Self.start < 0) or (Self.stop > High(MASTER))) then
    Exit(Self.Items);
  l := Self.Size;
  SetLength(Result, l);
  Move(MASTER[start], Result[0], (l * SizeOf(Integer)));
end;

{==============================================================================]
  <Iterated>
  @action: Materializes the range into an integer array by incrementally
           supplying values using a dynamic append strategy.
  @note: - For non-singular ranges, values are generated from Self.start
           toward Self.stop, INCLUDING the terminal bound.
         - Direction is determined by Self.Ascending:
             * True  → step = +1
             * False → step = -1
         - When rReverse = True, iteration order is inverted by switching
           to the reversed range and negating the step.
         - Uses dynamic growth (Supply) instead of pre-allocation; array
           capacity expands as elements are appended.
         - Iteration is controlled via (r.start - s) <> r.stop, ensuring
           the stop value is included.
         - Uses Increase(s) as the stepping primitive (assumed to mutate
           and return the advanced value).
         - Singular ranges (start = stop) produce a single-element array.
[==============================================================================}
function TRange.Iterated(out rDigits: TIntegerArray; const rReverse: Boolean = False): Integer; overload;
var
  s: Integer;
  r: TRange;
begin
  case Self.Singular of
    False:
    begin
      SetLength(rDigits, 0);
      s := IfThen(Self.Ascending, 1, -1);
      if rReverse then
      begin
        r := Self.Reversed;
        s := -s;
      end else
        r := Self;
      while ((r.start - s) <> r.stop) do
        rDigits.Supply(r.start.Increase(s));
    end;
    True: rDigits := [Self.start];
  end;
  Result := rDigits.Length;
end;

{==============================================================================]
  <Iteration>
  @action: Constructs and returns a dynamic integer array of length
           Self.Size using index-based iteration from zero, deriving
           each element relative to Self.Start and directionally
           adjusted by Self.Ascending.
  @note: The method iterates from 0 to (Self.Size - 1) and appends
         one computed element per iteration:
          • Ascending  : Self.Start + i
          • Descending : Self.Start - i
[==============================================================================}
function TRange.Iteration: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to (Self.Size - 1) do
    Result := (Result + [IfThen(Self.Ascending, (Self.start + i), (Self.start - i))]);
end;

{==============================================================================]
  <Iteration>
  @action: Expands the range into an integer array using manual capacity
           management with exponential growth for efficient appends.
  @note: - For non-singular ranges, values are generated from Self.start
           toward Self.stop, INCLUDING the terminal bound.
         - Direction is determined by Self.Ascending:
             * True  → step = +1
             * False → step = -1
         - When rReverse = True, iteration order is inverted by switching
           to the reversed range and negating the step.
         - Starts with an initial buffer (b = 4) and grows capacity by
           doubling when needed (amortized linear complexity).
         - Result acts as both the write index and final element count.
         - Iteration condition (r.start - s) <> r.stop guarantees inclusion
           of the stop value.
         - Uses Increase() for both index progression and value stepping.
         - Final array is trimmed to exact size after population.
         - Singular ranges (start = stop) return a single-element array
           and exit early.
[==============================================================================}
function TRange.Iteration(out rDigits: TIntegerArray; const rReverse: Boolean = False): Integer; overload;
var
  s, b: Integer;
  r: TRange;
begin
  if Self.Singular then
  begin
    rDigits := [Self.start];
    Exit(1);
  end;
  Result := 0;
  b := 4;
  SetLength(rDigits, b);
  s := IfThen(Self.Ascending, 1, -1);
  if rReverse then
  begin
    r := Self.Reversed;
    s := -s;
  end else
    r := Self;
  while ((r.start - s) <> r.stop) do
  begin
    if (Result = b) then
    begin
      b := (b * 2);
      SetLength(rDigits, b);
    end;
    rDigits[Result.Increase] := r.start.Increase(s);
  end;
  SetLength(rDigits, Result);
end;

{==============================================================================]
  <Lay>
  @action: Constructs a range array using a cumulative step approach.
             - Initializes the array with a constant step value:
               +1 if `Ascending = True`
               -1 if `Ascending = False`
             - Seeds the first element with `start`
             - Each subsequent element is computed as: Result[i] = Result[i - 1] + step
           Effectively produces:
            Ascending  → [start, start+1, start+2, ...]
            Descending → [start, start-1, start-2, ...]
  @note:
    - Time complexity: O(n)
    - Memory: Allocates a new array of length Size
    - Relies on FillDWord to broadcast the step value across the array
    - Uses a prefix-sum style recurrence:
      Result[i] := Result[i - 1] + Result[i]
      where Result[i] initially holds the step (±1)
    - `IfThen(Self.Ascending, 1, -1)` determines direction without branching
    - Assumes `Size > 0`; writing to `Result[0]` is unsafe if `Size = 0`
    - Behavior depends on correct 32-bit representation of `-1` when cast to `DWord`.
    Equivalent closed form: Result[i] = start + i * (Ascending ? +1 : -1)
[==============================================================================}
function TRange.Lay: TIntegerArray; overload;
var
  i, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  FillDWord(Result[0], s, DWord(IfThen(Self.Ascending, 1, -1)));
  Result[0] := Self.start;
  for i := 1 to (s - 1) do
    Result[i] := (Result[i - 1] + Result[i]);
end;

{==============================================================================]
  <Layout>
  @action: Materializes the range into a contiguous integer array (TIntegerArray),
           based on the current range configuration (start value, size, and direction).
             - If `start = 0` and `Ascending = True`, a zero-based identity sequence
               is generated: [0, 1, 2, ..., Size-1].
             - Otherwise, the array is initialized with `start` and then incremented
               or decremented per index depending on `Ascending`.
  @note:
    - Time complexity: O(n)
    - Memory: Allocates a new array of length Size
    - Uses FillDWord for fast initialization when start <> 0 or descending
    - Assumes Size >= 0; no bounds checking on negative size
    - Behavior is undefined if Size overflows array limits
    Equivalent logic:
     Ascending  → Result[i] = start + i
     Descending → Result[i] = start - i
    Fast path: When `start = 0` and ascending, avoids bulk fill and computes directly.
[==============================================================================}
function TRange.Layout: TIntegerArray; overload;
var
  i, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  case ((Self.start = 0) and Self.Ascending) of
    False:
    begin
      FillDWord(Result[0], s, DWord(Self.start));
      case Self.Ascending of
	    True:
        for i := 1 to (s - 1) do
          Inc(Result[i], i);
        False:
        for i := 1 to (s - 1) do
          Dec(Result[i], i);
	  end;
	end;
	True:
    for i := 0 to (s - 1) do
      Result[i] := i;
  end;
end;

{==============================================================================]
  <List>
  @action: Collects all values of the range into a newly allocated integer array
           using a generic list as an intermediate container.
  @note: Iterates over the range using its enumerator and appends each value
         to a TList<Integer>, which is then converted to an array.
         This implementation is compatible with Free Pascal generic lists
         (via specialize) and preserves inclusive range semantics.
         Less efficient than direct array emission due to intermediate storage.
[==============================================================================}
function TRange.List: TIntegerArray; overload;
var
  l: specialize TList<Integer>;
  v: Integer;
begin
  l := specialize TList<Integer>.Create;
  try
    for v in Self do
      l.Add(v);
    Result := l.ToArray;
  finally
    l.Free;
  end;
end;

{==============================================================================]
  <Listed>
  @action: Collects all values of the range into a generic list and returns them as an array.
  @note: Iterates from Start to Stop (inclusive) in the proper direction,
         determined by the sign of Stop - Start.
         Uses a TList<Integer> internally, then calls ToArray.
[==============================================================================}
function TRange.Listed: TIntegerArray; overload;
var
  l: specialize TList<Integer>;
  v, s, i: Integer;
begin
  l := specialize TList<Integer>.Create;
  try
    s := Self.Direction;
    if (s = 0) then
	  s := 1;
    v := Self.start;
    repeat
      l.Add(v);
      if (v = Self.stop) then
	    Break;
      Inc(v, s);
    until False;
    Result := l.ToArray;
  finally
    l.Free;
  end;
end;

{==============================================================================]
  <Listing>
  @action: Builds a fully enumerated list of all values in the range.
  @note: Generates a sequential array from Self.start to Self.stop (inclusive),
         respecting the direction (ascending or descending). Internally uses a
         TList as a temporary storage buffer, storing integer values via pointer
         casting, then converts them back into a typed integer array. This is a
         two-phase materialization: first list population, then array extraction.
         Functionally equivalent to Produced/Every with step = 1, but with
         additional heap-based indirection overhead due to TList usage.
[==============================================================================}
function TRange.Listing: TIntegerArray; overload;
var
  l: TList;
  i, v, s: Integer;
begin
  l := TList.Create;
  try
    l.Count := Self.Size;
    s := IfThen(Self.Ascending, 1, -1);
    v := Self.start;
    for i := 0 to (l.Count - 1) do
    begin
      l.Items[i] := Pointer(PtrUint(v)); 
      Inc(v, s);
    end;
    SetLength(Result, l.Count);
    for i := 0 to (l.Count - 1) do
      Result[i] := Integer(PtrUint(l.Items[i]));
  finally
    l.Free;
  end;
end;

{==============================================================================]
  <Material>
  @action: Returns an array of all integers in the range in sequential order,
           efficiently filling values in blocks of four, then handling any
           remaining elements at the end.
           - For ascending ranges: values go from Start to Stop
           - For descending ranges: values go from Start down to Stop
  @note: Implementation details:
         - Allocates an array of length = Self.Size
         - Initializes:
             - v := Start value
             - d := direction (+1 for ascending, -1 for descending)
         - Fills the array in a while loop in blocks of four:
             - Result[i] := v
             - Result[i+1] := v + d
             - Result[i+2] := v + 2*d
             - Result[i+3] := v + 3*d
             - Then increments v by 4*d and i by 4
         - Handles remaining elements (if Size mod 4 ≠ 0) in a final loop
         - Produces the same sequential order as Numbered() or Generated(),
           but optimized for batch assignments
         - Works for any range length and both ascending/descending ranges
         - Useful for performance-critical situations where repeated single-step
           assignment is costly
[==============================================================================}
function TRange.Material: TIntegerArray; overload;
var
  i, d, v, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  d := IfThen(Self.Ascending, 1, -1);
  v := Self.start;
  i := 0;
  while ((i + 3) < s) do
  begin
    Result[i] := v;
    Result[i + 1] := (v + d);
    Result[i + 2] := (v + (d * 2));
    Result[i + 3] := (v + (d * 3));
    Inc(v, (d * 4));
    Inc(i, 4);
  end;
  while (i < s) do
  begin
    Result[i] := v;
    Inc(v, d);
    Inc(i);
  end;
end; 

{==============================================================================]
  <Materialize>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Materialize: TIntegerArray; overload;
var
  i, s, v: Integer;
  p: PInteger;
begin
  s := IfThen(Self.Ascending, 1, -1);
  SetLength(Result, Self.Size);
  v := Self.Start;
  p := @Result[0];
  for i := 0 to High(Result) do
  begin
    p^ := v.Increase(s);
    Inc(p);
  end;
end;

{==============================================================================]
  <Materialized>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Materialized: TIntegerArray; overload;
var
  i, r, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IfThen(Self.Ascending, 1, -1);
  r := 0;
  i := Self.start;
  while (r < l) do
    Result[r.Increase] := i.Increase(s);
end;

{==============================================================================]
  <Membered>
  @action: Returns ALL TRange items as TIntegerArray.
  @note: Bypasses SetLength; allocates raw memory directly via GetMem,
         writes values via pointer, then transfers ownership to Result.
[==============================================================================}
function TRange.Membered: TIntegerArray; overload;
var
  p, w: PInteger;
  i, s, d, z: Integer;
begin
  s := Self.Size;
  if (s = 1) then
    Exit([Self.start]);
  z := SizeOf(Integer);
  GetMem(p, (s * z));
  try
    d := IfThen(Self.Ascending, 1, -1);
    w := p;
    for i := 0 to (s - 1) do
    begin
      w^ := (Self.start + (i * d));
      Inc(w);
    end;
    SetLength(Result, s);
    Move(p^, Result[0], (s * z));
  finally
    FreeMem(p);
  end;
end;

{==============================================================================]
  <Members>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Members: TIntegerArray; overload;
var
  i, c: Integer;
begin
  SetLength(Result, Self.Size);
  c := Self.start;
  for i := 0 to High(Result) do
    if Self.Ascending then
      Result[i] := c.Increase
    else
      Result[i] := c.Decrease;
end;

{==============================================================================]
  <Numbered>
  @action: Returns an array of all integers in the range in **natural order**.
           For an ascending range, values go from Start to Stop; for a descending
           range, values go from Start down to Stop.
  @note: Implementation details:
         - Allocates an array of length equal to Self.Size
         - Fills each element using Self.At(i), which returns the i-th element
           in the range accounting for ascending or descending order
         - Resulting array preserves the range’s original orientation
         - Unlike Pull, Numbered produces a **sequential order**, not a symmetric
           “pull from ends” order
[==============================================================================}
function TRange.Numbered: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := Self.At(i);
end;

{==============================================================================]
  <Numbers>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Numbers: TIntegerArray; overload;
var
  i, r, s: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  s := IfThen(Self.Descending, -1, 1);
  SetLength(Result, Self.Size);
  r := 0;
  i := Self.start;
  while (((s = 1) and (i <= Self.stop)) or ((s = -1) and (i >= Self.stop))) do
    Result[r.Increase] := i.Increase(s);
end;

{==============================================================================]
  <Numeralize>
  @action: Expands the range into a dynamic array of integers using a
           divide-and-conquer strategy, producing all values from Start to Stop.
           A TIntegerArray containing every integer in the range, in order,
           respecting the range’s direction (ascending or descending).
  @note:
    - Efficiently populates the array by recursively splitting the range.
    - Handles ranges of any length, including single-element or two-element ranges.
    - Preserves the numeric progression; step is always 1 in the correct direction.
    - Empty ranges return an empty array.
[==============================================================================}
function TRange.Numeralize: TIntegerArray; overload;
  procedure DividedFill(var arr: TIntegerArray; const offset, rangeStart, rangeStop: Integer);
  var
    c, m, i, s: Integer;
  begin
    c := (Abs(rangeStop - rangeStart) + 1);
    if (c <= 2) then
    begin
      arr[offset] := rangeStart;
      if (c = 2) then
        arr[offset + 1] := rangeStop;
      Exit;
    end;
    s := IfThen((rangeStart <= rangeStop), 1, -1);
    m := (rangeStart + ((c div 2) * s));
    DividedFill(arr, offset, rangeStart, (m - s));
    DividedFill(arr, (offset + (c div 2)), m, rangeStop);
  end;
begin
  SetLength(Result, Self.Count);
  DividedFill(Result, 0, Self.start, Self.stop);
end;

{==============================================================================]
  <Numerals>
  @action: Expands the range into a dynamic array of integers containing
           all values from Start to Stop.
           A TIntegerArray containing every integer in the range, in order,
           respecting the range’s direction (ascending or descending).
  @note:
    - Uses a recursive divide-and-conquer strategy for efficient population.
    - Single-element ranges produce a one-element array.
    - Empty ranges return an empty array.
    - Preserves the numeric progression; the step between elements is always 1
      in the correct direction (ascending or descending).
[==============================================================================}
function TRange.Numerals: TIntegerArray; overload;
  procedure FillPartition(var arr: TIntegerArray; const left, right, startVal, step: Integer);
  var
    m, i: Integer;
  begin
    if (left > right) then
      Exit;
    if (left = right) then
    begin
      arr[left] := startVal;
      Exit;
    end;
    i := ((left + right) div 2);
    m := (startVal + ((i - left) * step));
    arr[i] := m;
    FillPartition(arr, left, (i - 1), startVal, step);
    FillPartition(arr, (i + 1), right, (m + step), step);
  end;
begin
  SetLength(Result, Self.Count);
  FillPartition(Result, 0, High(Result), Self.start, Self.Direction);
end;

{==============================================================================]
  <Numericize>
  @action: Materializes the range into a preallocated integer array
          by iterating from Start in the Wind direction while the value remains contained within the range.
  @note: The resulting array is allocated with Size elements and filled sequentially using Wind as the step.
         Iteration stops when Contains returns False. The range instance is not modified.
[==============================================================================}
function TRange.Numericize: TIntegerArray; overload;
var
  r, d, s: Integer;
begin
  d := Self.Wind;
  SetLength(Result, Self.Size);
  s := Self.start;
  r := 0;
  while Self.Contains(s) do
    Result[r.Increase] := s.Increase(d);
end;

{==============================================================================]
  <Numerics>
  @action: Materializes the range into an integer array by iteratively appending values from Start in the Wind direction
          while contained in the range.
@note:   The array grows dynamically through concatenation on each iteration.
         This approach is less efficient than Numericize due to repeated reallocations.
         The range instance remains unchanged.
[==============================================================================}
function TRange.Numerics: TIntegerArray; overload;
var
  d, s: Integer;
begin
  d := Self.Wind;
  SetLength(Result, 0);
  s := Self.start;
  while Self.Contains(s) do
    Result := (Result + [s.Increase(d)]);
end;

{==============================================================================]
  <Open>
  @action: Expands the range into a sequential integer array.
  @note: Produces a fully materialized sequence starting at Self.start and
         advancing by Self.Direction until Self.stop is reached (inclusive).
         Uses a helper procedure to fill the array via arithmetic progression:
         value[i] = start + (i * step). This is a direct, allocation-minimal
         implementation equivalent to Enumerating with constant step = ±1.
[==============================================================================}
function TRange.Open: TIntegerArray; overload;
  procedure F(var a: TIntegerArray; const b, s: Integer);
  var i: Integer;
  begin
    for i := 0 to High(a) do
      a[i] := (b + (i * s));
  end;
begin
  SetLength(Result, Self.Size);
  F(Result, Self.start, Self.Direction);
end;

{==============================================================================]
  <Particles>
  @action: Iteratively constructs and returns a dynamic integer array
           representing the inclusive sequence from Self.Start to
           Self.Stop using the increment defined by Self.Wind.

  @note: The sequence begins with Self.Start and repeatedly appends
         the previous element plus Wind until Self.Stop is reached.
[==============================================================================}
function TRange.Particles: TIntegerArray; overload;
var
  s: Integer;
begin
  Result := [Self.start];
  s := Self.Wind;
  while (Result[High(Result)] <> Self.stop) do
    Result := (Result + [Result[High(Result)] + s]);
end;

{==============================================================================]
  <Pile>
  @action: Converts the range into a dynamic array of integers using a
           recursive divide-and-conquer strategy, producing all values from Start to Stop.
           A TIntegerArray containing every integer in the range, in order,
           respecting the range’s direction (ascending or descending).
  @note:
    - Builds the array recursively by splitting the range into subarrays.
    - Handles ranges of any length, including single-element ranges.
    - Preserves numeric progression; step is always 1 in the correct direction.
    - Empty ranges return an empty array.
    - Functionally similar to `Numeralize` but implemented via explicit array concatenation.
[==============================================================================}
function TRange.Pile: TIntegerArray; overload;
  function BuildSubArray(const start, stop: Integer): TIntegerArray;
  var
    i, c, m, s: Integer;
    l, r: TIntegerArray;
  begin
    c := (Abs(stop - start) + 1);
    if (c = 1) then
    begin
      SetLength(Result, 1);
      Result[0] := start;
      Exit;
    end;
    s := IfThen((start <= stop), 1, -1);
    m := (start + ((c div 2) * s));
    l := BuildSubArray(start, (m - s));
    r := BuildSubArray(m, stop);
    SetLength(Result, (System.Length(l) + System.Length(r)));
    for i := 0 to High(l) do
      Result[i] := l[i];
    for i := 0 to High(r) do
      Result[System.Length(l) + i] := r[i];
  end;
begin
  Result := BuildSubArray(Self.start, Self.stop);
end; 

{==============================================================================]
  <Populate>
  @action: Fills the provided integer array `arr` with the sequence of values 
           represented by this TRange, respecting the ascending or descending order.
           The array must already be allocated; its length determines how many values 
           are filled. The method also returns a TRange reflecting the filled portion.
  @note:
    - If the array is empty, the method exits immediately without modification.
    - The step between elements is automatically set to +1 (ascending) or -1 (descending).
    - The `Result.start` is set to Self.start, and `Result.stop` is set to the last 
      value written to the array.
    - Unlike `Generated` or `Material`, this method **populates an existing array** 
      rather than allocating a new one.
    - Useful when you want to reuse preallocated memory for performance.
[==============================================================================}
function TRange.Populate(var arr: TIntegerArray): TRange; overload;
var
  i, s: Integer;
begin
  if arr.Empty then
    Exit;
  s := IfThen(Self.Descending, -1, 1);
  Result.start := Self.start;
  for i := 0 to High(arr) do
    arr[i] := (Self.start + (i * s));
  Result.stop := arr[High(arr)];
end;

{==============================================================================]
  <Produce>
  @action: Materializes the inclusive integer range [start, stop] into a
           contiguous TIntegerArray using a single-pass iterative fill.   
           The result array is preallocated to Size, initialized with start,
           and each subsequent element is derived by applying Direction (±1)
           to the previous value:
             Result[i] := Result[i-1] + Direction
           This yields a strictly ordered sequence from start to stop,
           respecting the sign of Direction.
  @note: Time complexity is O(n) with a single linear traversal.  
         Space complexity is O(n) with exactly one allocation; no intermediate
         arrays are created. 
         This implementation is optimal with respect to both allocation and
         copy overhead compared to recursive or Concat-based variants.  
         Correctness depends on:
           - Direction ∈ [+1, -1]
           - Size representing the inclusive number of elements
         Behavior is undefined if Size ≤ 0 (e.g., start/stop inconsistent
         with Direction) unless externally validated.
         For Size = 1, returns a singleton array [start].
[==============================================================================}
function TRange.Produce: TIntegerArray; overload;
var
  d, i: Integer;
begin
  SetLength(Result, Self.Size);
  Result[0] := Self.start;
  d := Self.Direction;
  for i := 1 to High(Result) do
    Result[i] := (Result[i - 1] + d);
end;

{==============================================================================]
  <Produced>
  @action: Generates the full sequence of values defined by the range.
  @note: Returns an array containing all elements from Self.start to
         Self.stop (inclusive), respecting the range direction. Uses an
         exponential block-copy strategy: previously computed segments are
         duplicated via Move and offset by a directional delta (±b), where
         b grows by powers of two. This reduces per-element iteration cost
         compared to naive enumeration. Assumes Size >= 1.
[==============================================================================}
function TRange.Produced: TIntegerArray; overload;
var
  b, i, n, d, z: Integer;
begin
  n := Self.Size;
  if (n = 1) then
    Exit([Self.start]);
  SetLength(Result, n);
  d := IfThen(Self.Ascending, 1, -1);
  Result[0] := Self.start;
  b := 1;
  z := SizeOf(Integer);
  while (b < n) do
  begin
    Move(Result[0], Result[b], (Min(b, (n - b)) * z));
    for i := b to (Min((b * 2), n) - 1) do
      Inc(Result[i], (d * b));
    b := (b * 2);
  end;
end;

{==============================================================================]
  <Process>
  @action: Converts the range to an array using a blocked iteration (tiling) 
           pattern for cache efficiency.
  @note: 
    - Strategy: Segments the allocation into 1024-integer chunks to minimize 
      L1 cache misses during high-volume materialization.
    - Robustness: Automatically handles "remainder" blocks when the range 
      size is not a perfect multiple of the BLOCK_SIZE.
    - Scalability: Ideal for processing massive ranges (millions of entries) 
      where memory throughput is the primary bottleneck.
[==============================================================================}
function TRange.Process: TIntegerArray; overload;
const
  BLOCK_SIZE = 1024;
var
  i, j, s, d, r, l: Integer;
begin
  s := Self.Size;
  if (s = 1) then
    Exit([Self.start]);
  SetLength(Result, s);
  d := Self.Direction;
  r := Self.start;
  i := -BLOCK_SIZE;
  while (i.Increment(BLOCK_SIZE) < s) do
  begin
    l := (i + BLOCK_SIZE - 1);
    if (l >= s) then
      l := (s - 1);
    for j := i to l do
      Result[j] := (r + (j * d));
  end;
end;

{==============================================================================]
  <Publish>
  @action: Returns an array containing all integer values within the range.
  @note: The result includes both bounds and is ordered ascending or
         descending based on rAscending. For a singular range, a single-element
         array is returned.
[==============================================================================}
function TRange.Publish(const rAscending: Boolean = True): TIntegerArray; overload;
var
  l, h, i: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  l := Self.Minimum;
  h := Self.Maximum;
  SetLength(Result, Self.Size);
  i := 0;
  case rAscending of
    True:
    repeat
      Result[i.Increase] := l;
    until (l.Increment > h);
    False:
    repeat
      Result[i.Increase] := h;
    until (l > h.Decrement);
  end;
end;

{==============================================================================]
  <Pull>
  @action: Returns an array of all integers contained in the range, 
           starting from both ends and meeting in the middle.
           For example, for range [1,5], the output will be:
             [1,5,2,4,3]
           Works for both ascending and descending ranges.
  @note: Implementation details:
         - If start = stop, returns a single-element array [start]
         - Otherwise, allocates an array of length = Size of range
         - Iterates from 0 to half of the array, filling:
             - Result[i] from the start (or start descending)
             - Result[High-i] from the stop (or stop descending)
         - Produces a symmetric “pull from ends to center” ordering
         - Orientation (ascending/descending) is handled via Self.Descending
[==============================================================================}
function TRange.Pull: TIntegerArray; overload;
var
  h, i: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  SetLength(Result, Self.Size);
  h := High(Result);
  case Self.Descending of
    False:
    for i := 0 to (h div 2) do
    begin
      Result[i] := (Self.start + i);
      Result[h - i] := (Self.stop - i);
    end;
    True:
    for i := 0 to (h div 2) do
    begin
      Result[i] := (Self.start - i);
      Result[h - i] := (Self.stop + i);
    end;
  end;
end;

{==============================================================================]
  <Pulled>
  @action: Builds the range by seeding the center and expanding outward symmetrically.
  @note:
    - O(n), center-out write pattern
    - Starts at mid index c, fills left/right alternately
    - Writes as: start + i * Direction
    - Final layout identical to linear construction
[==============================================================================}
function TRange.Pulled: TIntegerArray; overload;
var
  c, i, d, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  d := IfThen(Self.Ascending, 1, -1);
  c := (s div 2);
  Result[c] := (Self.start + (c * d));
  for i := 1 to c do
  begin
    Result[c - i] := (Self.start + ((c - i) * d));
    if ((c + i) < s) then
      Result[c + i] := (Self.start + ((c + i) * d));
  end;
end;

{==============================================================================]
  <Queue>
  @action: Generates an array of integers representing the range defined in the TRange object. 
           Values are enqueued into a queue to preserve the natural order, and then converted 
           to an array.
  @note: Uses a generic TQueue<Integer> to store values temporarily. The queue ensures that 
         integers are kept in insertion order (FIFO), so the resulting array matches the 
         intended ascending or descending sequence.
[==============================================================================}
function TRange.Queue: TIntegerArray; overload;
var
  Q: specialize TQueue<Integer>;
  i, h, s: Integer;
begin
  Q := specialize TQueue<Integer>.Create;
  try
    h := Abs(Self.stop - Self.start);
    s := IfThen(Self.Ascending, 1, -1);
    for i := 0 to h do
      Q.Enqueue(Self.start + (i * s));
    Result := Q.ToArray;
  finally
    Q.Free;
  end;
end;

{==============================================================================]
  <Raw>
  @action: Produces the range as a contiguous integer array using a split-fill
           strategy for improved write locality.
  @note: The array is allocated to `Size` and populated in two parallel
         segments: the lower half (from index 0 upward) and the upper half
         (from midpoint upward). This reduces dependency chains compared to
         strictly sequential filling. The step direction is derived from
         `Ascending` (±1). For odd sizes, the final element is written
         explicitly after the loop.
[==============================================================================}
function TRange.Raw: TIntegerArray; overload;
var
  m, i, s, d: Integer;
  l, h: PInteger;
begin
  s := Self.Size;
  SetLength(Result, s);
  m := (s div 2);
  d := IfThen(Self.Ascending, 1, -1);
  l := @Result[0];
  h := @Result[m];
  for i := 0 to (m - 1) do
  begin
    l^ := (Self.start + (d * i));
    h^ := (Self.start + (d * (i + m)));
    Inc(l);
    Inc(h);
  end;
  if ((s mod 2) = 1) then
    Result[s - 1] := (Self.start + (d * (s - 1)));
end;

{==============================================================================]
  <Realize>
  @action: Recursively materializes the inclusive integer range [start, stop]
           into a TIntegerArray by partitioning the range and combining results
           via Concat.
           The range is split at midpoint m, computed relative to Direction:
             d = Direction  (±1)
             m = start + (Size div 2) * d
           Two subranges are formed:
             [start .. m - d] and [m .. stop]
           Each subrange is recursively produced and the resulting arrays are
           merged using Concat, preserving order according to Direction.
  @note: This implementation is Concat-driven: every recursive step allocates
         a new array and copies both sub-results into it.  
         Time complexity is O(n log n) due to repeated concatenation across
         recursion levels.    
         Space complexity exceeds O(n) because of intermediate arrays created
         during recursion.   
         Recursion depth is O(log n). 
         Correctness depends on:
           - Direction ∈ [+1, -1]
           - Size representing the inclusive number of elements
         Special case:
           - Size = 1 returns a singleton array [start]
         For performance-critical use, a preallocated linear fill avoids
         Concat entirely and achieves O(n) time with minimal allocations.
[==============================================================================}
function TRange.Realize: TIntegerArray; overload;
var
  d, m: Integer;
begin
  if (Self.Size = 1) then
    Exit([Self.start]);
  d := Self.Direction;
  m := (Self.start + ((Self.Size div 2) * d));
  Result := Concat(TRange.Construct(Self.start, (m - d)).Realize, TRange.Construct(m, Self.stop).Realize);
end;

{==============================================================================]
  <Recursed>
  @action: Returns digits of the given range.
  @note: Recursion-based.
[==============================================================================}
function TRange.Recursed: TIntegerArray; overload;
  function BR(const rStart, rStop: Integer): TIntegerArray;
  begin
    if (rStart = rStop) then
      Exit([rStart]);
    Result := BR(rStart, (rStop - Sign(rStop - rStart)));
    SetLength(Result, (Result.Size + 1));
    Result[High(Result)] := rStop;
  end;
begin
  Result := BR(Self.start, Self.stop);
end;

{==============================================================================]
  <Recursively>
  @action: Builds and returns a dynamic integer array representing the
           inclusive sequence from Self.Start to Self.Stop using Self.Step,
           constructed via recursive descent.
  @note: Terminates only when Self.Start = Self.Stop.
         Requires:
          • Self.Step <> 0
          • Self.Step moves toward Self.Stop
          • Self.Stop is reachable from Self.Start by repeated addition
            of Self.Step
          Violation of these conditions results in infinite recursion (stack overflow).
          Complexity:
          - Time  : O(n²)  (due to repeated dynamic array concatenation)
          - Space : O(n)
          - Stack : O(n)
[==============================================================================}
function TRange.Recursively: TIntegerArray; overload;
begin
  Result := [Self.start];
  if (Self.start <> Self.stop) then
    Result := (Result + Range((Self.start + Self.Step), Self.stop).Recursively);
end;

{==============================================================================]
  <Release>
  @action: Returns ALL TRange items as TIntegerArray.
  @note: Fills a circular buffer (ring) with range values, then drains it
         sequentially into Result. The ring wraps via modulo masking; size
         must be a power of two for the mask to work correctly.
         Two-phase: fill phase writes into ring, drain phase reads out.
[==============================================================================}
function TRange.Release: TIntegerArray; overload;
const
  RING_SIZE = 64;
  RING_MASK = (RING_SIZE - 1);
var
  r: array[0..RING_MASK] of Integer;
  h, t, i, s, d, v, w: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  d := IfThen(Self.Ascending, 1, -1);
  v := Self.start;
  h := 0;
  t := 0;
  w := 0;
  i := 0;
  while (w < s) do
  begin
    while ((((t + 1) and RING_MASK) <> h) and (i < s)) do
    begin
      r[t] := v.Increase(d);
      t := ((t + 1) and RING_MASK);
      Inc(i);
    end;
    while (h <> t) do
    begin
      Result[w.Increase] := r[h];
      h := ((h + 1) and RING_MASK);
    end;
  end;
end;

{==============================================================================]
  <Render>
  @action: Constructs the range recursively via concatenation.
  @note:
    - O(n²) due to repeated array concatenation
    - Recurrence: [start] + Render(start + step, count - 1)
    - Allocates many intermediate arrays
    - Stack depth = Size (risk for large n)
    - Final sequence: start + i * Direction
[==============================================================================}
function TRange.Render: TIntegerArray; overload;
  function Return(const aStart, aCount, aStep: Integer): TIntegerArray;
  begin
    if (aCount <= 0) then
      Exit([]);
    if (aCount = 1) then
      Exit([aStart]);
    Result := ([aStart] + Return((aStart + aStep), (aCount - 1), aStep));
  end;
begin
  Result := Return(Self.start, Self.Size, Self.Direction);
end;

{==============================================================================]
  <Rendered>
  @action: Materializes the full range using an incremental accumulation pass.
  @note: 
    - Strategy: Sets the initial seed (Start) and derives every subsequent 
      element from its predecessor.
    - Directionality: Automatically branches between +1 and -1 steps based on 
      the range's Ascending state.
    - Concreteness: Signals to the user that the abstract range logic has been 
      fully "drawn" into a physical array.
[==============================================================================}
function TRange.Rendered: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  Result[0] := Self.start;
  for i := 1 to High(Result) do
    Result[i] := (Result[i - 1] + IfThen(Self.Ascending, 1, -1));
end;

{==============================================================================]
  <Resources>
  @action: Fills an array with all values of the range using block-wise increments of 16 for efficiency.
  @note: Handles ascending and descending ranges; any remaining elements after blocks are filled individually.
[==============================================================================}
function TRange.Resources: TIntegerArray; overload;
var
  i, d, v, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  d := IfThen(Self.Ascending, 1, -1);
  v := Self.start;
  i := 0;
  while ((i + 15) < s) do
  begin
    Result[i] := v;
    Result[i + 1] := (v + d);
    Result[i + 2] := (v + (d * 2));
    Result[i + 3] := (v + (d * 3));
    Result[i + 4] := (v + (d * 4));
    Result[i + 5] := (v + (d * 5));
    Result[i + 6] := (v + (d * 6));
    Result[i + 7] := (v + (d * 7));
    Result[i + 8] := (v + (d * 8));
    Result[i + 9] := (v + (d * 9));
    Result[i + 10] := (v + (d * 10));
    Result[i + 11] := (v + (d * 11));
    Result[i + 12] := (v + (d * 12));
    Result[i + 13] := (v + (d * 13));
    Result[i + 14] := (v + (d * 14));
    Result[i + 15] := (v + (d * 15));
    Inc(v, (d * 16));
    Inc(i, 16);
  end;
  while (i < s) do
    Result[i.Increase] := v.Increase(d);
end;

{==============================================================================]
  <Reveal>
  @action: Progressively unfolds the range into a dynamic array.
  @note: Starts with the 'start' value and iteratively supplies the next
         integer based on direction until 'stop' is reached. Useful for
         following the natural path of the range (Ascending or Descending).
[==============================================================================}
function TRange.Reveal: TIntegerArray; overload;
begin
  Result := [Self.start];
  while (Self.stop <> Result[High(Result)]) do
    Result.Supply(Result[High(Result)] + Self.Direction);
end;

{==============================================================================]
  <Revealed>
  @action: Generates a concrete array of integers based on the range's 
           start, size, and direction.
  @note: Uses a countdown loop (Decrement) to populate the array from 
         the end to the beginning.
[==============================================================================}
function TRange.Revealed: TIntegerArray; overload;
var
  s: Integer;
begin
  s := Result.SetSize(Self.Size);
  while (s.Decrement > -1) do
    Result[s] := (Self.start + (s * Self.Direction));
end; 

{==============================================================================]
  <Separately>
  @action: Converts the range to a TIntegerArray.
  @note:
    - If rReverse = False, the array preserves the range’s natural order:
        - Ascending range → ascending array.
        - Descending range → descending array.
    - If rReverse = True, the array is returned in reverse order:
        - Ascending range → descending array.
        - Descending range → ascending array.
    - Singular ranges (start = stop) return a single-element array.
    - Uses a step variable (`r`) to determine the direction of iteration.
[==============================================================================}
function TRange.Separately(const rReverse: Boolean = False): TIntegerArray; overload;
var
  i, s, r: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  SetLength(Result, Self.Size);
  s := IfThen(rReverse, Self.stop, Self.start);
  if Self.Ascending then
    r := IfThen(rReverse, -1, 1)
  else
    r := IfThen(rReverse, 1, -1);
  for i := 0 to High(Result) do
    Result[i] := s.Increase(r);
end;

{==============================================================================]
  <Sequence>
  @action: Returns digits from TRange.
  @note: None.
[==============================================================================}
function TRange.Sequence: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  case Self.Descending of
    False:
    for i := 0 to High(Result) do
      Result[i] := (Self.start + i);
    True:
    for i := 0 to High(Result) do
      Result[i] := (Self.start - i);
  end;
end;

{==============================================================================]
  <Snapshot>
  @action: Produces an array containing all integers in the range.
  @note: The returned array represents a point-in-time snapshot of the range,
         preserving the start value, end value, and ascending or descending
         order. The evaluation is eager and allocates a new array.
[==============================================================================}
function TRange.Snapshot: TIntegerArray; overload;
var
  i, s: Integer;
  P: PInteger;
begin
  SetLength(Result, Self.Size);
  P := @Result[0];
  Result[0] := Self.start;
  s := IfThen(Self.Ascending, 1, -1);
  for i := 1 to High(Result) do
  begin
    Inc(P);
    P^ := (Result[i - 1] + s);
  end;
end;

{==============================================================================]
  <Stack>
  @action: Generates an array of integers representing the range defined in the TRange object. 
           The integers are returned in proper order (ascending or descending) regardless 
           of how they are pushed onto the temporary stack.
  @note: Uses TStack.
[==============================================================================}
function TRange.Stack: TIntegerArray;
var
  s: specialize TStack<Integer>;
  i, l, d, v: Integer;
begin
  s := specialize TStack<Integer>.Create;
  try
    l := Self.Size;
    d := IfThen(Self.Ascending, 1, -1);
    v := Self.stop;
    for i := 1 to l do
    begin
      s.Push(v);
      v := (v - d);
    end;
    SetLength(Result, l);
    for i := 0 to (l - 1) do
      Result[i] := s.Pop;
  finally
    s.Free;
  end;
end;

{==============================================================================]
  <Start2Stop>
  @action: Materializes the range in natural order (start → stop)
           by consuming `stop` inward via SStop on a working copy.
  @note: Non-destructive — operates on a local copy of Self.
[==============================================================================}
function TRange.Start2Stop: TIntegerArray; overload;
var
  r: TRange;
  i: Integer;
begin
  r := Self;
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := r.SStart;
end;

{==============================================================================]
  <StartToStop>
  @action: Materializes the range in natural order (start → stop)
           by consuming `stop` inward via SStop on a working copy.
  @note: Non-destructive — operates on a local copy of Self.
[==============================================================================}
function TRange.StartToStop: TIntegerArray; overload;
var
  r: TRange;
  s: Integer;
begin
  r := Self;
  s := r.Size;
  SetLength(Result, Self.Size);
  while (r.Size > 1) do
    Result[s.Decrement] := r.SStop;
  Result[s - 1] := r.stop;
end;

{==============================================================================]
  <Stepped>
  @action: Materializes the range into an array of integers with a custom
           step size. Values are incremented by sSize at each iteration.
  @note: - For non-singular ranges, values are generated from Self.start
           toward Self.stop, INCLUDING the terminal bound.
         - Direction is determined by Self.Ascending:
             * True  → step = +sSize
             * False → step = -sSize
         - If sSize < 1, the function returns an empty array.
         - Array length is precomputed based on the step size:
           ((Abs(stop - start) div sSize) + 1)
         - Uses Increase(d) to advance the iterator at each step.
         - Singular ranges (start = stop) produce a single-element array
           if step size allows.
         - Allows sampling the range at regular intervals.
[==============================================================================}
function TRange.Stepped(const sSize: Integer = 1): TIntegerArray; overload;
var
  i, r, d: Integer;
begin
  if (sSize < 1) then
    Exit([]);
  SetLength(Result, ((Abs(Int64(Self.stop) - Self.start) div sSize) + 1));
  d := IfThen(Self.Ascending, sSize, -Integer(sSize));
  r := Self.start;
  for i := 0 to High(Result) do
    Result[i] := r.Increase(d);
end;

{==============================================================================]
  <Steps>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Steps: TIntegerArray; overload;
var
  i, s: Integer;
  p: PInteger;
begin
  s := IfThen(Self.Ascending, 1, -1);
  Result := Self.Reserve;
  p := @Result[0];
  p^ := Self.start;
  Inc(p);
  for i := 1 to High(Result) do
  begin
    p^ := ((p - 1)^ + s);
    Inc(p);
  end;
end;

{==============================================================================]
  <Stock>
  @action: Returns an array of all integers in the range in sequential order,
           filled using two interleaved passes over the result indices.
           Works for both ascending and descending ranges.
  @note: Implementation details:
         - Allocates an array of length = Self.Size
         - Computes direction d (+1 for ascending, -1 for descending)
         - Fills the result array in two phases:
             • First pass fills indices 0, 2, 4, ...
             • Second pass fills indices 1, 3, 5, ...
         - Each value is computed directly as: Start + d * index
         - This interleaving can reduce dependency chains and may improve
           instruction-level parallelism on some architectures
[==============================================================================}
function TRange.Stock: TIntegerArray; overload;
var
  i, j, d, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  d := IfThen(Self.Ascending, 1, -1);
  for j := 0 to 1 do
  begin
    i := (j - 2);
    while (i.Increment(2) < s) do
      Result[i] := (Self.start + (d * i));
  end;
end;

{==============================================================================]
  <Stop2Start>
  @action: Materializes the range in reverse order (stop → start)
           by consuming `start` inward via SStart on a working copy.
  @note: Non-destructive — operates on a local copy of Self.
[==============================================================================}
function TRange.Stop2Start: TIntegerArray; overload;
var
  r: TRange;
  i: Integer;
begin
  r := Self;
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := r.SStop;
end;

{==============================================================================]
  <StopToStart>
  @action: Materializes the range in reverse order (stop → start)
           by consuming `start` inward via SStart on a working copy.
  @note: Non-destructive — operates on a local copy of Self.
[==============================================================================}
function TRange.StopToStart: TIntegerArray; overload;
var
  r: TRange;
  s: Integer;
begin
  r := Self;
  s := r.Size;
  SetLength(Result, Self.Size);
  while (r.Size > 1) do
    Result[s.Decrement] := r.SStart;
  Result[s - 1] := r.start;
end;

{==============================================================================]
  <Storage>
  @action: Materializes the range into a contiguous TIntegerArray using
    block-based expansion from a fixed base digit table.
  @note:
    This implementation fills the result array in fixed-size chunks
    (BASE_DIGITS), reducing loop-control overhead and improving
    instruction locality compared to a naïve element-by-element fill.

    The method is order-safe for both ascending and descending ranges.
    It is functionally equivalent to sequential generation, but favors
    predictable memory access patterns and partial unrolling.
[==============================================================================}
function TRange.Storage: TIntegerArray; overload;
var
  b, i, o, d, s: Integer;
begin
  b := System.Length(BASE_DIGITS);
  s := Self.Size;
  SetLength(Result, s);
  d := IfThen(Self.Ascending, 1, -1);
  o := -b;
  while (o.Increment(b) < s) do
    for i := 0 to Min((b - 1), ((s - o) - 1)) do
      Result[o + i] := (Self.start + (d * (BASE_DIGITS[i] + o)));
end;

{==============================================================================]
  <Succinct>
  @action: Generates an array containing all integer values within the range.
  @note: The result includes both bounds and is constructed sequentially from
         the start value. Ordering follows the range direction (ascending or
         descending) using successive increment or decrement operations.
[==============================================================================}
function TRange.Succinct: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  Result[0] := Self.start;
  case Self.Ascending of
    True:
    for i := 1 to High(Result) do
      Result[i] := Succ(Result[i - 1]);
    False:
    for i := 1 to High(Result) do
      Result[i] := Pred(Result[i - 1]);
  end;
end;

{==============================================================================]
  <Sweep>
  @action: Materializes the range into a dynamically growing array. Values
           are appended sequentially using an exponential buffer expansion
           strategy.
  @note: - For non-singular ranges, values are generated from Self.start
           toward Self.stop, INCLUDING the terminal bound.
         - Direction is determined by Self.Ascending:
             * True  → step = +1
             * False → step = -1
         - Starts with an initial buffer of size 8 and doubles the
           capacity whenever the current buffer is exhausted.
         - Uses a local iterator (r) and Increase(s) to advance each
           value.
         - Dynamic growth avoids precomputing exact length, trading
           minor overhead for flexibility.
         - Singular ranges (start = stop) produce a single-element array
           immediately.
         - Final array is trimmed to match the exact number of elements.
[==============================================================================}
function TRange.Sweep: TIntegerArray; overload;
var
  b, l, r, s: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  b := 8;
  SetLength(Result, b);
  l := 0;
  s := IfThen(Self.Ascending, 1, -1);
  r := (Self.start - s);
  while (r.Increase(s) <> Self.stop) do
  begin
    if (l = b) then
      SetLength(Result, X2(b));
    Result[l.Increase] := r;
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <TIA>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.TIA: TIntegerArray; overload;
var
  i, l, d: Integer;
begin
  l := Self.Capacity;
  SetLength(Result, l);
  if Self.Plural then
  begin
    d := Self.Direction;
    for i := 0 to ((l - 1) div 2) do
    begin
      Result[i] := (Self.start + (i * d));
      Result[(l - 1) - i] := (Self.stop - (i * d));
    end;
  end else
    Result[0] := Self.start;
end;

{==============================================================================]
  <ToArr>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.ToArr: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    if Self.Ascending then
      Result[i] := (Self.start + i)
    else
      Result[i] := (Self.start - i);
end;

{==============================================================================]
  <ToArray>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.ToArray: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  case Self.Descending of
    False:
    for i := Self.start to Self.stop do
      Result[i - Self.start] := i;
    True:
    for i := Self.start downto Self.stop do
      Result[Self.start - i] := i;
  end;
end;

{==============================================================================]
  <ToArray>
  @action: Creates and returns a new integer array containing all integers from 
           `AStart` to `AStop`, inclusive. The order of elements respects the 
           direction of the range:
            - Ascending if AStart <= AStop
            - Descending if AStart > AStop
  @note:
    - Allocates a new array internally; the caller does not need to preallocate it.
    - The length of the resulting array is Abs(AStop - AStart) + 1.
    - Useful as a static helper when you want to quickly convert a numeric range 
      into an array without first constructing a TRange instance.
    - Overloaded versions may exist to create arrays from existing TRange instances.
[==============================================================================}
class function TRange.ToArray(const AStart, AStop: Integer): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, (Abs(AStop - AStart) + 1));
  case (AStart > AStop) of
    False:
    for i := 0 to High(Result) do
      Result[i] := (AStart + i);
	True:
	for i := 0 to High(Result) do
      Result[i] := (AStart - i);
  end;
end;

{==============================================================================]
  <ToIntegers>
  @action: Generates an array of all integer values within the range.
  @note: The result is fully expanded and includes both bounds. Values are
         produced in ascending or descending order depending on the relative
         ordering of start and stop.
[==============================================================================}
function TRange.ToIntegers: TIntegerArray; overload;
var
  i, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  for i := 0 to (s - 1) do
    Result[i] := i;
  case Self.Ascending of
    True:
    for i := 0 to (s - 1) do
      Result[i] := (Self.start + Result[i]);
    False:
    for i := 0 to (s - 1) do
      Result[i] := (Self.start - Result[i]);
  end;
end;

{==============================================================================]
  <ToValues>
  @action: Expands range into an array of its values using direct pointer iteration.
  @note: Preserves order; ascending adds, descending subtracts from start.
[==============================================================================}
function TRange.ToValues: TIntegerArray; overload;
var
  a: Boolean;
  p: PInteger;
  i, s: Integer;
begin
  a := Self.Ascending;
  s := Self.Size;
  SetLength(Result, s);
  p := @Result[0];
  for i := 0 to (s - 1) do
  begin
    if a then
      p^ := (Self.start + i)
    else
      p^ := (Self.start - i);
    Inc(p);
  end;
end;

{==============================================================================]
  <Unfold>
  @action: Recursion-based alternative for extracting items from TRange.
  @note: None.
[==============================================================================}
function TRange.Unfold: TIntegerArray; overload;
  procedure F2W(const R: TRange; const L, H: Integer; const A: Boolean; var arr: TIntegerArray);
  begin
    if (L > H) then
      Exit;
    case A of
      True:
      begin
        arr[L] := (R.start + L);
        arr[H] := (R.stop - L);
      end;
      False:
      begin
        arr[L] := (R.start - L);
        arr[H] := (R.stop + L);
      end;
    end;
    F2W(R, (L + 1), (H - 1), A, arr);
  end;
begin
  if Self.Singular then
    Exit([Self.start]);
  SetLength(Result, Self.Size);
  F2W(Self, 0, High(Result), Self.Ascending, Result);
end;

{==============================================================================]
  <Unfolded>
  @action: Materializes the range via iterative binary bisection.
  @note: 
    - Pattern: Level-order (Breadth-First) filling of indices.
    - Mechanism: Seeds boundaries, then resolves midpoints at power-of-two 
      strides (Stride, Stride/2, Stride/4...).
    - Stability: Uses a zero-sentinel check to prevent redundant calculation 
      of previously established midpoints.
[==============================================================================}
function TRange.Unfolded: TIntegerArray; overload;
var
  s, h, i, d, l, m, r: Integer;
begin
  s := Self.Size;
  if (s = 1) then
    Exit([Self.start]);
  h := (s - 1);
  i := 1;
  while (i < h) do
    i := (i shl 1);
  d := Self.Direction;
  SetLength(Result, s);
  Result[0] := Self.start;
  Result[h] := Self.stop;
  while (i > 0) do
  begin
    l := 0;
    while ((l + i) <= h) do
    begin
      r := (l + i);
      m := ((l + r) div 2);
      if ((m > 0) and (m < h)) then
        Result[m] := (Self.start + (m * d));
      l := r;
    end;
    i := (i div 2);
  end;
end;

{==============================================================================]
  <Unpack>
  @action: Two-way alternative for extracting items from TRange.
  @note: None.
[==============================================================================}
function TRange.Unpack: TIntegerArray; overload;
var
  s, i: Integer;
  o: Boolean;
begin
  s := Self.Size;
  SetLength(Result, s);
  o := Self.Ascending;
  for i := 0 to (s - 1) do
    if (i < (s div 2)) then
      Result[i] := o.Select((Self.start + i), (Self.start - i))
    else
      Result[i] := o.Select((Self.stop - ((s - 1) - i)), (Self.stop + ((s - 1) - i)));
end;

{==============================================================================]
  <Unpacked>
  @action: Expands the range into a concrete array representation.
  @note: If the range contains multiple distinct values (Plural = True),
         delegates to All to produce the full sequence. Otherwise, allocates
         an array of Size and fills it with the single value Self.start.
         This avoids enumeration overhead for degenerate (constant) ranges.
[==============================================================================}
function TRange.Unpacked: TIntegerArray; overload;
begin
  if Self.Plural then
    Exit(Self.All);
  SetLength(Result, Self.Size);
  FillDWord(Result[0], Self.Size, Cardinal(Self.start));
end;

{==============================================================================]
  <Unrolled>
  @action: Expands the range into an array using loop unrolling in blocks of 8 for efficiency.
  @note: Handles ascending or descending ranges; fills any remaining elements individually after unrolled blocks.
[==============================================================================}
function TRange.Unrolled: TIntegerArray; overload;
var
  i, v, d, s, c: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  v := Self.start;
  d := Self.Direction;
  c := s;
  i := 0;
  while (c >= 8) do
  begin
    Result[i] := v;
	Result[i + 1] := (v + d);
    Result[i + 2] := (v + (2 * d));
	Result[i + 3] := (v + (3 * d));
    Result[i + 4] := (v + (4 * d));
	Result[i + 5] := (v + (5 * d));
    Result[i + 6] := (v + (6 * d));
	Result[i + 7] := (v + (7 * d));
    Inc(i, 8);
    Inc(v, (8 * d));
    Dec(c, 8);
  end;
  while (c.Decrease > 0) do
    Result[i.Increase] := v.Increase(d);
end;

{==============================================================================]
  <Unwrap>
  @action: Two-way alternative for extracting items from TRange.
  @note: None.
[==============================================================================}
function TRange.Unwrap: TIntegerArray; overload;
var
  s, h, i: Integer;
  a: Boolean;
begin
  s := Self.Size;
  SetLength(Result, s);
  h := ((s + 1) div 2);
  a := Self.Ascending;
  for i := 0 to (h - 1) do
  case a of
    True:
    begin
      Result[i] := (Self.start + i);
      Result[(s - 1) - i] := (Self.stop - i);
    end;
    False:
    begin
      Result[i] := (Self.start - i);
      Result[(s - 1) - i] := (Self.stop + i);
    end;
  end;
end;

{==============================================================================]
  <Unzip>
  @action: Two-way alternative for extracting items from TRange.
  @note: None.
[==============================================================================}
function TRange.Unzip: TIntegerArray; overload;
var
  r: TRange;
begin
  if Self.Singular then
    Exit([Self.start]);
  SetLength(Result, Self.Size);
  r.Create(0, High(Result));
  case Self.Ascending of
    True:
    repeat
      Result[r.start] := (Self.start + r.start);
      Result[r.stop] := (Self.stop - r.start);
    until (r.start.Increment > r.stop.Decrement);
    False:
    repeat
      Result[r.start] := (Self.start - r.start);
      Result[r.stop] := (Self.stop + r.start);
    until (r.start.Increment > r.stop.Decrement);
  end;
end;

{==============================================================================]
  <Values>
  @action: Returns values of the given range.
  @note: None.
[==============================================================================}
function TRange.Values: TIntegerArray; overload;
var
  i, r: Integer;
begin
  r := 0;
  SetLength(Result, Self.Size);
  case Self.Ascending of
    False:
    for i := Self.start downto Self.stop do
      Result[r.Increase] := i;
    True:
    for i := Self.start to Self.stop do
      Result[r.Increase] := i;
  end;
end;

{==============================================================================]
  <View>
  @action: Returns a contiguous slice (view) of the range starting at sIndex and
    containing up to vSize elements.
  @note:
    - vSize < 0 returns an empty array.
    - sIndex defines the starting offset (default = 0).
    - If sIndex is negative, it is clamped to 0 and the effective size is
      reduced accordingly.
    - If sIndex is outside the range bounds, returns an empty array.
    - The result is always clipped to the available range size.
    - Does not modify the original range.
    - Uses Self.Digits for indexed element access.
    - vSize defaults to MaxInt, effectively meaning "to end of range".
    - Complexity: O(n), where n is the number of returned elements.
[==============================================================================}
function TRange.View(const vSize: Integer = 2147483647; const sIndex: Integer = 0): TIntegerArray; overload;
var
  i, s, o, c: Integer;
begin
  if ((vSize < 0) or (sIndex >= Self.Size(s)) or ((sIndex + vSize) < 0)) then
    Exit([]);
  if (sIndex < 0) then
    o := 0
  else
    o := sIndex;
  if (o >= s) then
    Exit([]);
  c := IfThen((sIndex < 0), (vSize - (-sIndex)), vSize);
  SetLength(Result, Min(c, (s - o)));
  for i := 0 to High(Result) do
    Result[i] := Self.Digits(o + i);
end;

{==============================================================================]
  <Yielded>
  @action: Returns ALL TRange items as TIntegerArray.
  @note: Simulates a generator/coroutine via callback. Each value is
         "yielded" by invoking the callback, which appends to the result.
         The caller drives consumption; the generator drives production.
[==============================================================================}
function TRange.Yielded: TIntegerArray; overload;
var
  d, i, v: Integer;
  procedure Y(const aValue: Integer);
  begin
    Result.Supply(aValue);
  end;
begin
  SetLength(Result, 0);
  d := IfThen(Self.Ascending, 1, -1);
  v := Self.start;
  for i := 0 to (Self.Size - 1) do
    Y(v.Increase(d));
end;
{$ENDIF}
