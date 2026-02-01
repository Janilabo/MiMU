{$IFDEF METHODS}
function All: TIntegerArray; overload;
function ArrayOf: TIntegerArray; overload;
function AsArr: TIntegerArray; overload;
function AsArray: TIntegerArray; overload;
function Atomize: TIntegerArray; overload;
function Bank: TIntegerArray; overload;
function Capture: TIntegerArray; overload;
function Captured: TIntegerArray; overload;
function Collect: TIntegerArray; overload;
function Content: TIntegerArray; overload;
function Contents: TIntegerArray; overload;
function Data: TIntegerArray; overload;
function Digits: TIntegerArray; overload;
function Digits(const dIndex: Integer): Integer; overload;
function Digits(const dIDs: TIntegerArray): TIntegerArray; overload;
function Disjoint: TIntegerArray; overload;
function Elements: TIntegerArray; overload;
function Emit: TIntegerArray; overload;
function Enumerate: TIntegerArray; overload;
function Enumerated: TIntegerArray; overload;
function Explode: TIntegerArray; overload;
function Exploded: TIntegerArray; overload;
function Extract: TIntegerArray; overload;
function Extracted: TIntegerArray; overload;
function Flatten: TIntegerArray; overload;
function Gather: TIntegerArray; overload;
function Generate: TIntegerArray; overload;
function Generated: TIntegerArray; overload;
function Ints: TIntegerArray; overload;
function Items: TIntegerArray; overload;
function Iterated: TIntegerArray; overload;
function List: TIntegerArray; overload;
function Listed: TIntegerArray; overload;
function Material: TIntegerArray; overload;
function Materialize: TIntegerArray; overload;
function Materialized: TIntegerArray; overload;
function Members: TIntegerArray; overload;
function Numbered: TIntegerArray; overload;
function Numbers: TIntegerArray; overload;
function Populate(var arr: TIntegerArray): TRange; overload;
function Pull: TIntegerArray; overload;
function Recursed: TIntegerArray; overload;
function Sequence: TIntegerArray; overload;
function Snapshot: TIntegerArray; overload;
function Steps: TIntegerArray; overload;
function Stock: TIntegerArray; overload;
function Storage: TIntegerArray; overload;
function TIA: TIntegerArray; overload;
function ToArr: TIntegerArray; overload;
function ToArray: TIntegerArray; overload;
class function ToArray(const AStart, AStop: Integer): TIntegerArray; overload; static;
function Unfold: TIntegerArray; overload;
function Unpack: TIntegerArray; overload;
function Unwrap: TIntegerArray; overload;
function Unzip: TIntegerArray; overload;
function Values: TIntegerArray; overload;
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
  if (Self.start = Self.stop) then
    Exit([Self.start]);
  SetLength(Result, Self.Size);
  j := IfThen((Self.start <= Self.stop), 1, -1);
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
  <ArrayOf>
  @action: Returns ALL TRange items as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.ArrayOf: TIntegerArray; overload;
label
  sLoop, eLoop;
var
  i, v, d, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  i := 0;
  v := Self.start;
  d := IfThen(Self.Ascending, 1, -1);
  sLoop:
  if (i >= s) then
    goto eLoop;
  Result[i] := v;
  Inc(v, d);
  Inc(i);
  goto sLoop;
  eLoop:
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
  s := Sign(Self.stop - Self.start);
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
  if (Self.start = Self.stop) then
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
  <Bank>
  @action: ?
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
  <Content>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Content: TIntegerArray; overload;
var
  i, c, s: Integer;
begin
  SetLength(Result, Self.Size);
  s := IfThen((Self.start <= Self.stop), 1, -1);
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
  case Sign(Self.stop - Self.start) of
    0, 1:  s := 1;
    -1: s := -1;
  end;
  for i := 0 to High(Result) do
    Result[i] := (Self.start + (i * s));
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
  <Digits>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Digits: TIntegerArray; overload;
var
  i, s: Integer;
begin
  s := Sign(Self.stop - Self.start);
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
  else
    if Self.Ascending then
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
  <Disjoint>
  @action: Returns an array of all integers in the range arranged in a “disjoint”
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
function TRange.Disjoint: TIntegerArray; overload;
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
  <Elements>
  action: Returns TBox points as TPointArray.
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
  if (Self.start = Self.stop) then
    Exit([Self.start]);
  c := Self.Size;
  SetLength(Result, c);
  s := Sign(Self.stop - Self.start);
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
  s := Sign(Self.stop - Self.start);
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
  s := Sign(Self.stop - Self.start);
  if (s = 0) then
    s := 1;
  Return(Result, 0, Self.start, Self.stop, s);
end;

{==============================================================================]
  <Extract>
  @action: Extracts TRange as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Extract: TIntegerArray; overload;
var
  i, c, s: Integer;
begin
  if Self.Singular then
    Exit([Self.start]);
  s := IfThen((Self.stop > Self.start), 1, -1);
  c := (Abs(Self.stop - Self.start) + 1);
  SetLength(Result, c);
  for i := 0 to (c - 1) do
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
    s := Sign(Self.stop - Self.start);
    for i := 0 to High(Result) do
      Result[i] := (Self.start + (i * s));
  end else
    Result[0] := Self.start;
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
  i, d, m: Integer;
begin
  SetLength(Result, Self.Size);
  d := (Self.stop - Self.start);
  m := (d shr 31);
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
  @note:   Implementation details:
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
    s := Sign(Self.stop - Self.start);
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
  s := IfThen((Self.start <= Self.stop), 1, -1);
  r := 0;
  i := Self.start;
  while (r < l) do
    Result[r.Increase] := i.Increase(s);
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
    if (Self.start <= Self.stop) then
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
  if (Self.start = Self.stop) then
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
  <Steps>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Steps: TIntegerArray; overload;
var
  i, s: Integer;
  p: PInteger;
begin
  s := IfThen((Self.start < Self.stop), 1, -1);
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
    d := Sign(Self.stop - Self.start);
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
    if (Self.start <= Self.stop) then
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
  if (Self.start = Self.stop) then
    Exit([Self.start]);
  SetLength(Result, Self.Size);
  F2W(Self, 0, High(Result), Self.Ascending, Result);
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
  if (Self.start = Self.stop) then
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
{$ENDIF}
