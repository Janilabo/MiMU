{$IFDEF HELPERS}
function Ascension(const target: Integer = 0): TIntegerArray; overload;
function Ascment(const N: Integer = 2): TIntegerArray; overload;
function Descension(const target: Integer = 0): TIntegerArray; overload;
function Descment(const N: Integer = 2): TIntegerArray; overload;
function Downstairs(const target: Integer = 0): TIntegerArray; overload;
function Onto(const target: Integer = 0): TIntegerArray; overload;
function Path(const target: Integer = 0): TIntegerArray; overload;
function Rebound(const target: Integer = 0): TIntegerArray; overload;
function Route(const target: Integer = 0): TIntegerArray; overload;
function Stairs(const target: Integer = 0): TIntegerArray; overload;
function Steppify(const sCount: Integer = 0): TIntegerArray; overload;
function Thru(const target: Integer): TIntegerArray; overload;
function Upstairs(const target: Integer = 0): TIntegerArray; overload;
function Via(const target: Integer = 0): TIntegerArray; overload;
function Way(const target: Integer = 0): TIntegerArray; overload;
function WayTo(const target: Integer = 0): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascension>
  @action: Generates an ascending sequence array of integers starting from Self 
           up to and including the target value.
  @note: If Self is greater than target, it exits early returning only [Self]. 
         Uses direct pointer arithmetic to populate the array sequentially in 
         memory for optimized performance.
[==============================================================================}
function TIntegerHelper.Ascension(const target: Integer = 0): TIntegerArray; overload;
var
  i: Integer;
  P: PInteger;
begin
  if (Self > target) then
    Exit([Self]);
  SetLength(Result, ((target - Self) + 1));
  P := @Result[0];
  for i := 0 to High(Result) do
  begin
    P^ := (Self + i);
    Inc(P);
  end;
end;

{==============================================================================]
  <Ascment>
  @action: Generates an ascending sequence of N consecutive integers starting 
           from the current value of Self.
  @param: N The total number of elements to generate in the resulting array 
           (defaults to 1).
  @return: A dynamic TIntegerArray populated with the ascending range 
           [Self, Self + 1, ..., Self + N - 1].
  @note: A custom blend of "Ascend" and "Increment" serving as an inline 
         arithmetic sequence factory. Safely handles N <= 0 by returning 
         an empty array.
[==============================================================================}
function TIntegerHelper.Ascment(const N: Integer = 2): TIntegerArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Max(0, N)) do
    Result[i] := (Self + i);
end;

{==============================================================================]
  <Descension>
  @action: Generates a descending sequence array of integers starting from Self 
           down to and including the target value.
  @note: If Self is less than target, it exits early returning only [Self]. 
         Uses direct pointer arithmetic to populate the array sequentially in 
         memory for optimized performance.
[==============================================================================}
function TIntegerHelper.Descension(const target: Integer = 0): TIntegerArray; overload;
var
  i: Integer;
  P: PInteger;
begin
  if (Self < target) then
    Exit([Self]);
  SetLength(Result, ((Self - target) + 1));
  P := @Result[0];
  for i := 0 to High(Result) do
  begin
    P^ := (Self - i);
    Inc(P);
  end;
end;

{==============================================================================]
  <Descment>
  @action: Generates a descending sequence of N consecutive integers starting 
           from the current value of Self.
  @param: N The total number of elements to generate in the resulting array 
           (defaults to 1).
  @return: A dynamic TIntegerArray populated with the descending range 
           [Self, Self - 1, ..., Self - N + 1].
  @note: A custom blend of "Descend" and "Decrement" serving as an inline 
         reverse arithmetic sequence factory. Safely handles N <= 0 by returning 
         an empty array.
[==============================================================================}
function TIntegerHelper.Descment(const N: Integer = 2): TIntegerArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Max(0, N)) do
    Result[i] := (Self - i);
end;

{==============================================================================]
  <Downstairs>
  @action: Generates a descending sequence array of integers starting from Self
           down to and including the target value.
  @note: If Self is less than target, the loop bounds collapse and it returns
         an array containing only [Self].
[==============================================================================}
function TIntegerHelper.Downstairs(const target: Integer = 0): TIntegerArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Max(0, (Self - target)) + 1) do
    Result[i] := (Self - i);
end;

{==============================================================================]
  <Onto>
  @action: Generates an inclusive sequence array of integers starting from Self 
           and continuing directly onto the target value.
  @note: Automatically handles direction mapping. Uses the Compare method to 
         explicitly split execution paths: counting up for a lower origin, 
         counting down for a higher origin, or instantly returning [Self] if 
         Self equals target.
[==============================================================================}
function TIntegerHelper.Onto(const target: Integer = 0): TIntegerArray; overload;
var
  i: Integer;
begin
  case Self.Compare(target) of
    0: Result := [Self];
    -1:
    for i := 0 to Result.Alloc(Abs(target - Self) + 1) do
      Result[i] := (Self + i);
    1:  for i := 0 to Result.Alloc(Abs(target - Self) + 1) do
      Result[i] := (Self - i);
  end;
end;

{==============================================================================]
  <Path>
  @action: Generates a continuous, bi-directional sequence array of integers by 
           dynamically stepping from Self toward the target value.
  @note: Uses a localized tracking state variable (s) to drive the while loop 
         independently of the array's bounds. If Self equals target, the loop 
         is safely bypassed, instantly returning [Self]. Because the array grows 
         dynamically via concatenation (+), it prioritizes progressive path 
         exploration over static pre-allocation.
[==============================================================================}
function TIntegerHelper.Path(const target: Integer = 0): TIntegerArray; overload;
var
  d, s: Integer;
begin
  s := Self;
  d := target.Compare(Self);
  SetLength(Result, 0);
  while (s <> target) do
    Result := (Result + [s.Increase(d)]);
  Result := (Result + [s]);
end;

{==============================================================================]
  <Rebound>
  @action: Returns an ascending then descending (or vice versa) sequence
           between Self and target, returning back to Self.
  @note: 5.Rebound(8) -> [5,6,7,8,7,6,5]
         8.Rebound(5) -> [8,7,6,5,6,7,8]
[==============================================================================}
function TIntegerHelper.Rebound(const target: Integer = 0): TIntegerArray; overload;
var
  s, t: TIntegerArray;
  d, i: Integer;
begin
  d := Abs(target - Self);
  t := Self.Stairs(target);
  s := target.Stairs(Self);
  SetLength(Result, ((d * 2) + 1));
  for i := 0 to d do
    Result[i] := t[i];
  for i := 1 to d do
    Result[d + i] := s[i];
end;

{==============================================================================]
  <Route>
  @action: Generates a continuous, bi-directional sequence array of integers by 
           dynamically plotting a path from Self directly to the target destination.
  @note: Automatically determines direction using Compare. Because this method 
         dynamically appends to and reallocates the array step-by-step inside 
         a while loop, it is designed for maximum structural readability and 
         expressive pathfinding. Default target is 0.
[==============================================================================}
function TIntegerHelper.Route(const target: Integer = 0): TIntegerArray; overload;
var
  s: Integer;
begin
  s := target.Compare(Self);
  Result := [Self];
  while (Result[High(Result)] <> target) do
    Result := (Result + [Result[High(Result)] + s]);
end;

{==============================================================================]
  <Stairs>
  @action: Generates a continuous sequence array of integers starting from Self
           moving toward and including the target value.
  @note: Dynamically routes the direction. If Self is greater than target, it
         routes via Downstairs; otherwise, it routes via Upstairs. Unlike the
         directional methods, this will never collapse to a single-element
         array unless Self = target.
[==============================================================================}
function TIntegerHelper.Stairs(const target: Integer = 0): TIntegerArray; overload;
begin
  if (Self > target) then
    Result := Self.Downstairs(target)
  else
    Result := Self.Upstairs(target);
end;

{==============================================================================]
  <Steppify>
  @action: Generates a contiguous arithmetic sequence array of integers starting
           from Self, moving by a length of sCount.
  @note: Automatically handles directional scaling. A positive sCount increments 
         forward, a negative sCount decrements backward, and 0 returns an array 
         containing only Self. Resulting array length is always Abs(sCount) + 1.
[==============================================================================}
function TIntegerHelper.Steppify(const sCount: Integer = 0): TIntegerArray; overload;
var
  i: Integer;
begin
  case sCount.Compare(0) of
    0: Exit([Self]);
    -1:
    for i := 0 to Result.Alloc(-sCount + 1) do
      Result[i] := (Self - i);
    1:
    for i := 0 to Result.Alloc(sCount + 1) do
      Result[i] := (Self + i);
  end;
end;

{==============================================================================]
  <Thru>
  @action: Generates an array of integers spanning from Self to the target value.
  @note: Dynamically calculates range size and direction; supports both 
         ascending and descending sequences seamlessly.
[==============================================================================}
function TIntegerHelper.Thru(const target: Integer): TIntegerArray; overload;
var
  i, s: Integer;
begin
  s := IfThen((Self <= target), 1, -1);
  for i := 0 to Result.Alloc(Abs(target - Self) + 1) do
    Result[i] := (Self + (i * s));
end;

{==============================================================================]
  <Upstairs>
  @action: Generates an ascending sequence array of integers starting from Self
           up to and including the target value.
  @note: If Self is greater than target, the loop bounds collapse and it returns
         an array containing only [Self].
[==============================================================================}
function TIntegerHelper.Upstairs(const target: Integer = 0): TIntegerArray; overload;
var
  i: Integer;
begin
  for i := 0 to Result.Alloc(Max(0, (target - Self)) + 1) do
    Result[i] := (Self + i);
end;

{==============================================================================]
  <Via>
  @action: Generates a continuous, bi-directional sequence array of integers 
           starting from Self and traveling via steady steps to the target value.
  @note: Automatically detects direction. If target is greater than Self, it 
         increments forward (+1); if less, it decrements backward (-1). This 
         method calculates step vectors inline, ensuring a continuous sequence 
         is always returned without risking empty or single-element collapses.
[==============================================================================}
function TIntegerHelper.Via(const target: Integer = 0): TIntegerArray; overload;
var
  i, s: Integer;
begin
  if (Self = target) then
    Exit([Self]);
  s := IfThen((target > Self), 1, -1);
  for i := 0 to Result.Alloc(Abs(target - Self) + 1) do
    Result[i] := (Self + (i * s));
end;

{==============================================================================]
  <Way>
  @action: Generates a continuous, bi-directional sequence array of integers 
           starting from Self and traveling to the target value.
  @note: Automatically detects direction and uses optimized, manual pointer 
         byte-offset arithmetic to write values directly into memory. This 
         bypasses standard Pascal array-indexing bounds checking for maximum 
         performance.
[==============================================================================}
function TIntegerHelper.Way(const target: Integer = 0): TIntegerArray; overload;
var
  i, s, z: Integer;
  P: PInteger;
begin
  if (Self = target) then
    Exit([Self]);
  s := IfThen((target > Self), 1, -1);
  z := SizeOf(Integer);
  for i := 0 to Result.Alloc(Abs(target - Self) + 1) do
    PInteger(@Result[0] + (i * z))^ := (Self + (i * s));
end;

{==============================================================================]
  <WayTo>
  @action: Generates a continuous, bi-directional sequence array of integers 
           starting from Self and traveling sequentially to the target value.
  @note: Uses a highly optimized stream approach. By utilizing an escalating 
         pointer cursor (Inc(P)) combined with iterative state mutations 
         (Increase/Decrease) within a while loop, it entirely eliminates 
         multiplication overhead from the loop body for maximum throughput.
[==============================================================================}
function TIntegerHelper.WayTo(const target: Integer = 0): TIntegerArray; overload;
var
  s, r, l: Integer;
  P: PInteger;
begin
  if (Self = target) then
    Exit([Self]);
  l := (Abs(target - Self) + 1);
  SetLength(Result, l);
  P := @Result[0];
  s := IfThen((target > Self), 1, -1);
  r := Self;
  while (l.Decrease > 0) do
  begin
    P^ := r.Increase(s);
    Inc(P);
  end;
end;
{$ENDIF}
