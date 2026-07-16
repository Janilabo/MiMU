{$IFDEF METHODS}
function A2B: TIntegerArray; overload;
function Arrayed(const rAscending: Boolean = True): TIntegerArray; overload;
function Arrayment(const rAscending: Boolean = True): TIntegerArray; overload;
function B2A: TIntegerArray; overload;
function Expose(const rAscending: Boolean = True): TIntegerArray; overload;
function FromTo(const rAscending: Boolean = True): TIntegerArray; overload;
function MaximumToMinimum: TIntegerArray; overload;
function MaxMinArr: TIntegerArray; overload;
function MaxMinArray: TIntegerArray; overload;
function MaxMinned: TIntegerArray; overload;
function MaxToMin: TIntegerArray; overload;
function MaxTillMin: TIntegerArray; overload;
function MinimumToMaximum: TIntegerArray; overload;
function MinMaxArr: TIntegerArray; overload;
function MinMaxArray: TIntegerArray; overload;
function MinMaxxed: TIntegerArray; overload;
function MinTillMax: TIntegerArray; overload;
function MinToMax: TIntegerArray; overload;
function Publish(const rAscending: Boolean = True): TIntegerArray; overload;
function Separately(const rReverse: Boolean = False): TIntegerArray; overload;
function Start2Stop: TIntegerArray; overload;
function Startage: TIntegerArray; overload;
function Startcast: TIntegerArray; overload;
function Started: TIntegerArray; overload;
function Startify: TIntegerArray; overload;
function StartRoute: TIntegerArray; overload;
function Startset: TIntegerArray; overload;
function StartToStop: TIntegerArray; overload;
function Startvalued: TIntegerArray; overload;
function Stop2Start: TIntegerArray; overload;
function Stopcast: TIntegerArray; overload;
function Stopify: TIntegerArray; overload;
function Stoppage: TIntegerArray; overload;
function Stopped: TIntegerArray; overload;
function StopRoute: TIntegerArray; overload;
function Stopset: TIntegerArray; overload;
function StopToStart: TIntegerArray; overload;
function Stopvalued: TIntegerArray; overload;
function ToStart: TIntegerArray; overload;
function ToStarting: TIntegerArray; overload;
function ToStop: TIntegerArray; overload;
function ToStopping: TIntegerArray; overload;
function Unrange(const rAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <A2B>
  @action: Returns an array containing all values from Start (A) to Stop (B).
  @note: Follows the range's natural direction.
         A = Start, B = Stop.
         Uses dynamic array supply pattern with integer stepping.
  @example:
    TRange(1, 5).A2B   -> [1, 2, 3, 4, 5]
    TRange(5, 1).A2B   -> [5, 4, 3, 2, 1]
    TRange(3, 3).A2B   -> [3]
[==============================================================================}
function TRange.A2B: TIntegerArray; overload;
var
  r, d: Integer;
begin
  Result := [Self.start];
  d := Self.Direction;
  r := (Self.start + d);
  while (r <> (Self.stop + d)) do
    Result.Supply(r.Increase(d));
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
  <Arrayment>
  @action: Converts the TRange into a TIntegerArray, populating it with an 
           ordered sequence of numbers spanning the range. 
  @note: By default, the array is generated in ascending order (from Minimum 
         upwards). Set rAscending to False to generate it in descending order 
         (from Maximum downwards). Uses efficient pointer operations.
[==============================================================================}
function TRange.Arrayment(const rAscending: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
  P: PInteger;
  s: TPoint;
begin
  SetLength(Result, Self.Size);
  P := @Result[0];
  s := IfThen(rAscending, Point(Self.Minimum, 1), Point(Self.Maximum, -1));
  for i := 0 to High(Result) do
  begin
    P^ := s.X.Increase(s.Y);
    Inc(P);
  end;
end;

{==============================================================================]
  <B2A>
  @action: Returns an array containing all values from Stop (B) to Start (A).
  @note: Opposite of the range's natural direction.
         A = Start, B = Stop.
         Traverses backward from B to A.
  @example:
    TRange(1, 5).B2A   -> [5, 4, 3, 2, 1]
    TRange(5, 1).B2A   -> [1, 2, 3, 4, 5]
    TRange(3, 3).B2A   -> [3]
[==============================================================================}
function TRange.B2A: TIntegerArray; overload;
var
  r, d: Integer;
begin
  Result := [Self.stop];
  d := Self.Direction;
  r := (Self.stop - d);
  while (r <> (Self.start - d)) do
    Result.Supply(r.Decrease(d));
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
  <MaximumToMinimum>
  @action: Generates an array of integers sequentially ordered from the Maximum value down to the Minimum value.
  @note: Calculates values safely relative to the maximum boundary using the loop index.
[==============================================================================}
function TRange.MaximumToMinimum: TIntegerArray; overload;
var
  i, m: Integer;
begin
  SetLength(Result, Self.Size);
  m := Self.Maximum;
  for i := 0 to High(Result) do
    Result[i] := (m - i);
end;

{==============================================================================]
  <MaxMinArr>
  @action: Generates a descending sequence of integers from Maximum down to Minimum using dynamic array concatenation.
  @note: Initializes as an empty array and dynamically grows during execution; utilizes a 'downto' loop to step backward.
[==============================================================================}
function TRange.MaxMinArr: TIntegerArray; overload;
var
  i: Integer;
begin
  Result := [];
  for i := Self.Maximum downto Self.Minimum do
    Result := (Result + [i]);
end;

{==============================================================================]
  <MaxMinArray>
  @action: Generates a sequentially descending array of integers from the Maximum value down to the Minimum value.
  @note: Highly optimized; combines the predictable boundary safety of a standard loop with low-level pointer assignment speed.
[==============================================================================}
function TRange.MaxMinArray: TIntegerArray; overload;
var
  i, m: Integer;
  p: PInteger;
begin
  SetLength(Result, Self.Size);
  p := @Result[0];
  m := Self.Maximum;
  for i := 0 to High(Result) do
  begin
    p^ := (m - i);
    Inc(p);
  end;
end;

{==============================================================================]
  <MaxMinned>
  @action: Generates a sequentially descending array of integers starting from the Maximum value down toward the Minimum.
  @note: Leverages fast pointer assignment combined with fluent type helper mutations (`.Decrement` and `.Decrease`).
[==============================================================================}
function TRange.MaxMinned: TIntegerArray; overload;
var
  P: PInteger;
  m, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  P := @Result[0];
  m := Self.Maximum;
  while (s.Decrement > -1) do
  begin
    P^ := m.Decrease;
    Inc(P);
  end;
end;

{==============================================================================]
  <MaxToMin>
  @action: Generates an array of integers sequentially ordered in reverse from the Maximum value down to the Minimum value.
  @note: Self.Size matches the total count of numbers in the range, and Result[0] initializes at Self.Maximum.
[==============================================================================}
function TRange.MaxToMin: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  Result[0] := Self.Maximum;
  for i := 1 to High(Result) do
    Result[i] := (Result[i - 1] - 1);
end;

{==============================================================================]
  <MaxTillMin>
  @action: Generates an array of integers starting from the range's maximum value, 
           decrementing each subsequent element by 1, down to the size of the range.
  @note: Acts as a descending sequence generator starting from the top of the range.
[==============================================================================}
function TRange.MaxTillMin: TIntegerArray; overload;
var
  i, m, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  i := 0;
  m := Self.Maximum;
  repeat
    Result[i] := m.Decrease;
  until (i.Increment = s);
end; 

{==============================================================================]
  <MinimumToMaximum>
  @action: Generates an array of integers sequentially ordered from the Minimum value up to the Maximum value.
  @note: Calculates values safely relative to the minimum boundary using the loop index.
[==============================================================================}
function TRange.MinimumToMaximum: TIntegerArray; overload;
var
  i, m: Integer;
begin
  SetLength(Result, Self.Size);
  m := Self.Minimum;
  for i := 0 to High(Result) do
    Result[i] := (m + i);
end;

{==============================================================================]
  <MinMaxArr>
  @action: Generates an ascending sequence of integers from Minimum to Maximum using dynamic array concatenation.
  @note: Initializes as an empty array and dynamically grows during execution; avoids requiring an explicit 'Size' property calculation.
[==============================================================================}
function TRange.MinMaxArr: TIntegerArray; overload;
var
  i: Integer;
begin
  Result := [];
  for i := Self.Minimum to Self.Maximum do
    Result := (Result + [i]);
end;

{==============================================================================]
  <MinMaxArray>
  @action: Generates a sequentially ascending array of integers from the Minimum value up to the Maximum value.
  @note: Highly optimized; combines the predictable boundary safety of a standard loop with low-level pointer assignment speed.
[==============================================================================}
function TRange.MinMaxArray: TIntegerArray; overload;
var
  i, m: Integer;
  p: PInteger;
begin
  SetLength(Result, Self.Size);
  p := @Result[0];
  m := Self.Minimum;
  for i := 0 to High(Result) do
  begin
    p^ := (m + i);
    Inc(p);
  end;
end;

{==============================================================================]
  <MinMaxxed>
  @action: Generates a sequentially ascending array of integers starting from the Minimum value up toward the Maximum.
  @note: Leverages fast pointer assignment combined with fluent type helper mutations (`.Decrement` and `.Increase`).
[==============================================================================}
function TRange.MinMaxxed: TIntegerArray; overload;
var
  P: PInteger;
  m, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  P := @Result[0];
  m := Self.Minimum;
  while (s.Decrement > -1) do
  begin
    P^ := m.Increase;
    Inc(P);
  end;
end;

{==============================================================================]
  <MinTillMax>
  @action: Generates an array of integers starting from the range's minimum value, 
           incrementing each subsequent element by 1, up to the size of the range.
  @note: Acts as an ascending sequence generator.
[==============================================================================}
function TRange.MinTillMax: TIntegerArray; overload;
var
  i, m, s: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  i := 0;
  m := Self.Minimum;
  repeat
    Result[i] := m.Increase;
  until (i.Increment = s);
end;

{==============================================================================]
  <MinToMax>
  @action: Generates an array of integers sequentially ordered from the Minimum value to the Maximum value.
  @note: Self.Size matches the total count of numbers in the range, and Result[0] initializes at Self.Minimum.
[==============================================================================}
function TRange.MinToMax: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  Result[0] := Self.Minimum;
  for i := 1 to High(Result) do
    Result[i] := (Result[i - 1] + 1);
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
  if Self.Asceal then
    r := IfThen(rReverse, -1, 1)
  else
    r := IfThen(rReverse, 1, -1);
  for i := 0 to High(Result) do
    Result[i] := s.Increase(r);
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
  <Startage>
  @action: Returns array of range values starting from Start value
  @return: TIntegerArray with values progressing from Start toward Stop
  @note: Optimized with special cases for sizes 1, 2, and 3
         Direction-aware (handles ascending and descending)
  @example:
    Range(1,5).Startage → [1,2,3,4,5]
    Range(5,1).Startage → [5,4,3,2,1]
[==============================================================================}
function TRange.Startage: TIntegerArray; overload;
var
  d, s, i: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  Result[0] := Self.start;
  if (s = 1) then
    Exit;
  d := Self.Direction;
  Result[1] := (Self.start + d);
  for i := 2 to (s - 1) do
    Result[i] := (Self.start + (i * d));
end;

{==============================================================================]
  <Startcast>
  @action: Projects the entire range into an array, originating from the Start point.
  @note: Effectively "unrolls" the range into a linear sequence of integers.
[==============================================================================}
function TRange.Startcast: TIntegerArray; overload;
var
  s, i: Integer;
  r: TRange;
begin
  s := Self.Size;
  SetLength(Result, s);
  r := Self.ExpandStop;
  while r.SnipStop do
    Result[s.Decrement] := r.stop;
end;

{==============================================================================]
  <Started>
  @action: Returns an array of values traversing from the Start value through the range
  @return: TIntegerArray containing the range values in natural direction
  @note: Direction-aware behavior:
         - Direction = 1 (ascending): [Start, Start+1, Start+2, ..., Stop]
         - Direction = -1 (descending): [Start, Start-1, Start-2, ..., Stop]
         - Direction = 0 (single value): [Start]
         Example: Range(1, 5) → [1, 2, 3, 4, 5]
         Example: Range(5, 1) → [5, 4, 3, 2, 1]
         Example: Range(3, 3) → [3]
[==============================================================================}
function TRange.Started: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  case Self.Direction of
    0: Result[0] := Self.start;
    1:
    for i := 0 to High(Result) do
      Result[i] := (Self.start + i);
    -1:
    for i := 0 to High(Result) do
      Result[i] := (Self.start - i);
  end;
end;

{==============================================================================]
  <Startify>
  @action: Generates a sequence array where the 'stop' value is placed at the 
           final index and the preceding values are backfilled toward 'start'.
  @note: Uses a reverse-fill approach. The sequence is calculated by 
         applying the negative Direction to the stop value.
[==============================================================================}
function TRange.Startify: TIntegerArray; overload;
var
  s, d: Integer;
begin
  SetLength(Result, Self.Size);
  s := High(Result);
  d := -Self.Direction;
  Result[s] := Self.stop;
  while (s.Decrement > -1) do
    Result[s] := (Result[s + 1] + d);
end;

{==============================================================================]
  <StartRoute>
  @action: Generates a sequential TIntegerArray starting from the Start point.
  @note: High-performance implementation using pointer math and directional steps.
[==============================================================================}
function TRange.StartRoute: TIntegerArray; overload;
var
  p: PInteger;
  i, d, s: Integer;
begin
  s := Self.Size;
  if (s = 1) then
    Exit([Self.start]);
  SetLength(Result, s);
  p := @Result[0];
  p^ := Self.start;
  d := Self.Direction;
  for i := 1 to (s - 1) do
    p[i] := (p[i - 1] + d);
end;

{==============================================================================]
  <Startset>
  @action: Recursively unrolls the range into an array starting from the 
           start boundary.
  @note: Produces an ordered sequence from Start to Stop; order follows the 
         range direction (ascending for forward, descending for reverse).
[==============================================================================}
function TRange.Startset: TIntegerArray; overload;
begin
  if (Self.Size = 1) then
    Result := [Self.start]
  else
    Result := ([Self.start] + Self.ShrinkStart.Startset);
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
  <Startvalued>
  @action: Generates an array of all integers in the range, beginning at Start.
  @note: Uses iterative shrinking to collect values into a TIntegerArray.
[==============================================================================}
function TRange.Startvalued: TIntegerArray; overload;
label
  loop;
var
  S: TRange;
begin
  SetLength(Result, 0);
  S := Self;
  loop:
  Result := (Result + [S.start]);
  if (S.start = S.stop) then
    Exit;
  S := S.ShrinkStart;
  goto loop;
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
  <Stopcast>
  @action: Projects the entire range into an array, originating from the Stop point.
  @note: Generates the sequence in reverse, starting the array with the Stop value.
[==============================================================================}
function TRange.Stopcast: TIntegerArray; overload;
var
  s, i: Integer;
  r: TRange;
begin
  s := Self.Size;
  SetLength(Result, s);
  r := Self.ExpandStart;
  while r.SnipStart do
    Result[s.Decrement] := r.start;
end;

{==============================================================================]
  <Stopify>
  @action: Generates a sequence array where the 'start' value is placed at the 
           final index and the preceding values are backfilled toward 'stop'.
  @note: Effectively creates a mirrored or inverted progression compared to 
         Startify by subtracting the directional delta during backfill.
[==============================================================================}
function TRange.Stopify: TIntegerArray; overload;
var
  s, d: Integer;
begin
  SetLength(Result, Self.Size);
  s := High(Result);
  d := -Self.Direction;
  Result[s] := Self.start;
  while (s.Decrement > -1) do
    Result[s] := (Result[s + 1] - d);
end;

{==============================================================================]
  <Stoppage>
  @action: Returns array of range values starting from Stop value
  @return: TIntegerArray with values progressing from Stop toward Start
  @note: Optimized with special cases for sizes 1, 2, and 3
  @example: Range(1,5).Stoppage → [5,4,3,2,1]
[==============================================================================}
function TRange.Stoppage: TIntegerArray; overload;
var
  d, s, i: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  Result[0] := Self.stop;
  if (s = 1) then
    Exit;
  d := Self.Direction;
  Result[1] := (Self.stop - d);
  for i := 2 to (s - 1) do
    Result[i] := (Self.stop - (i * d));
end;

{==============================================================================]
  <Stopped>
  @action: Returns an array of values traversing from the Stop value backward through the range
  @return: TIntegerArray containing the range values in reverse direction
  @note: Direction-aware behavior:
         - Direction = 1 (ascending): [Stop, Stop-1, Stop-2, ..., Start]
         - Direction = -1 (descending): [Stop, Stop+1, Stop+2, ..., Start]
         - Direction = 0 (single value): [Stop]
         Example: Range(1, 5) → [5, 4, 3, 2, 1]
         Example: Range(5, 1) → [1, 2, 3, 4, 5]
         Example: Range(3, 3) → [3]
[==============================================================================}
function TRange.Stopped: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  case Self.Direction of
    0: Result[0] := Self.stop;
    1:
    for i := 0 to High(Result) do
      Result[i] := (Self.stop - i);
    -1:
    for i := 0 to High(Result) do
      Result[i] := (Self.stop + i);
  end;
end;

{==============================================================================]
  <StopRoute>
  @action: Generates a sequential TIntegerArray starting from the Stop point.
  @note: Traverses the range in reverse by subtracting the direction from Stop.
[==============================================================================}
function TRange.StopRoute: TIntegerArray; overload;
var
  p: PInteger;
  i, d, s: Integer;
begin
  s := Self.Size;
  if (s = 1) then
    Exit([Self.stop]);
  SetLength(Result, s);
  p := @Result[0];
  p^ := Self.stop;
  d := Self.Direction;
  for i := 1 to (Self.Size - 1) do
    p[i] := (p[i - 1] - d);
end;

{==============================================================================]
  <Stopset>
  @action: Recursively unrolls the range into an array starting from the 
           stop boundary.
  @note: Produces an ordered sequence from Stop to Start; effectively the 
         reverse order of the range's natural direction.
[==============================================================================}
function TRange.Stopset: TIntegerArray; overload;
begin
  if (Self.Size = 1) then
    Result := [Self.stop]
  else
    Result := ([Self.stop] + Self.ShrinkStop.Stopset);
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
  <Stopvalued>
  @action: Generates an array of all integers in the range, beginning at Stop.
  @note: Useful for retrieving the range sequence in reverse order.
[==============================================================================}
function TRange.Stopvalued: TIntegerArray; overload;
label
  loop;
var
  S: TRange;
begin
  SetLength(Result, 0);
  S := Self;
  loop:
  Result := (Result + [S.stop]);
  if (S.start = S.stop) then
    Exit;
  S := S.ShrinkStop;
  goto loop;
end;

{==============================================================================]
  <ToStart>
  @action: Returns an array containing all values from Stop to Start.
  @note: Opposite of the range's natural direction.
  @example:
    TRange(1, 5).ToStart  -> [5, 4, 3, 2, 1]
    TRange(5, 1).ToStart  -> [1, 2, 3, 4, 5]
[==============================================================================}
function TRange.ToStart: TIntegerArray; overload;
var
  p: PInteger;
  i, r, d: Integer;
begin
  SetLength(Result, Self.Size);
  p := @Result[0];
  r := Self.stop;
  d := Self.Direction;
  for i := 0 to High(Result) do
  begin
    p^ := r.Decrease(d);
    Inc(p);
  end;
end;

{==============================================================================]
  <ToStarting>
  @action: Returns an array containing all values from Stop to Start.
  @note: Opposite of the range's natural direction.
  @example:
    TRange(1, 5).ToStarting  -> [5, 4, 3, 2, 1]
    TRange(5, 1).ToStarting  -> [1, 2, 3, 4, 5]
[==============================================================================}
function TRange.ToStarting: TIntegerArray; overload;
var
  r, d: Integer;
begin
  Result := [];
  d := Self.Direction;
  r := Self.stop;
  repeat
    Result.Supply(r.Decrease(d));
  until (((d > 0) and (r < Self.start)) or ((d < 0) and (r > Self.start)));
end;

{==============================================================================]
  <ToStop>
  @action: Returns an array containing all values from Start to Stop.
  @note: Follows the range's natural direction (ascending or descending).
  @example: 
    TRange(1, 5).ToStop   -> [1, 2, 3, 4, 5]
    TRange(5, 1).ToStop   -> [5, 4, 3, 2, 1]
[==============================================================================}
function TRange.ToStop: TIntegerArray; overload;
var
  p: PInteger;
  i, r, d: Integer;
begin
  SetLength(Result, Self.Size);
  p := @Result[0];
  r := Self.start;
  d := Self.Direction;
  for i := 0 to High(Result) do
  begin
    p^ := r.Increase(d);
    Inc(p);
  end;
end;

{==============================================================================]
  <ToStopping>
  @action: Returns an array containing all values from Start to Stop.
  @note: Follows the range's natural direction (ascending or descending).
  @example: 
    TRange(1, 5).ToStopping   -> [1, 2, 3, 4, 5]
    TRange(5, 1).ToStopping   -> [5, 4, 3, 2, 1]
[==============================================================================}
function TRange.ToStopping: TIntegerArray; overload;
var
  r, d: Integer;
begin
  Result := [];
  d := Self.Direction;
  r := Self.start;
  repeat
    Result.Supply(r.Increase(d));
  until (((d > 0) and (r > Self.stop)) or ((d < 0) and (r < Self.stop)));
end;

{==============================================================================]
  <Unrange>
  @action: Unrolls a compact TRange object into a flat, sequential array of 
           integers spanning from one boundary to the other.
  @note: Uses a safe math-based progression strategy rather than pointers. 
         Set rAscending to True (default) to start from the Minimum and count up, 
         or False to start from the Maximum and count down.
[==============================================================================}
function TRange.Unrange(const rAscending: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
  s: TPoint;
begin
  SetLength(Result, Self.Size);
  s := IfThen(rAscending, Point(Self.Minimum, 1), Point(Self.Maximum, -1));
  for i := 0 to High(Result) do
    Result[i] := (s.X + (i * s.Y));
end;
{$ENDIF}
