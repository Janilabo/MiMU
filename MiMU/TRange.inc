{$DEFINE TRange}{$I config\Defines.inc}

{==============================================================================]
  <TRange.Create>
  @action: Create a TRange with start and stop
  @note: None.
[==============================================================================}
constructor TRange.Create(const rStart, rStop: Integer); overload;
begin
  Self.start := rStart;
  Self.stop := rStop;
end;

{==============================================================================]
  <TRange.Create>
  @action: Create a TRange with value
  @note: None.
[==============================================================================}
constructor TRange.Create(const value: Integer); overload;
begin
  Self.Create(value, value);
end;

{==============================================================================]
  <TRange.Construct>
  @action: Constructs TRange with rStart and rStop.
  @note: None.
[==============================================================================}
class function TRange.Construct(const rStart, rStop: Integer): TRange; overload; cdecl;
begin
  Result.start := rStart;
  Result.stop := rStop;
end;

{==============================================================================]
  <TRange.Build>
  @action: Create a TRange with rStart and rStop, using Min and Max for safety.
  @note: None.
[==============================================================================}
function TRange.Build(const rStart: Integer = 0; const rStop: Integer = 0): Integer; cdecl;
begin
  Self.start := Min(rStart, rStop);
  Self.stop := Max(rStop, rStart);
  Result := (Abs(rStop - rStart) + 1);
end;

{==============================================================================]
  <TRange.Init>
  @action: Initializes the current TRange with the specified start and stop values.
           Also returns the initialized record so it can be assigned in-line.
  @note: Useful for initializing a TRange instance and simultaneously returning it
         for assignment. Example: a := b.Init(1, 10);
[==============================================================================}
function TRange.Init(const rStart, rStop: Integer): TRange; overload; cdecl;
begin
  Self.start := rStart;
  Self.stop := rStop;
  Result.start := rStart;
  Result.stop := rStop;
end;

{==============================================================================]
  <TRange.Init>
  @action: Initializes the current TRange as a copy of another TRange.
           Also returns the copied record.
  @note: Useful for copying values from an existing TRange while allowing in-line assignment.
         Example: a := b.Init(c);
[==============================================================================}
function TRange.Init(const r: TRange): TRange; overload; cdecl;
begin
  Self := r;
  Result := r;
end;

{==============================================================================]
  <TRange.Init>
  @action: Initializes the current TRange with both start and stop set to the same value.
           Also returns the initialized record.
  @note: The parameter has a default of 0, allowing zero-initialization.
         Example: a := b.Init; or a := b.Init(5);
[==============================================================================}
function TRange.Init(const val: Integer = 0): TRange; overload; cdecl;
begin
  Self.start := val;
  Self.stop := val;
  Result.start := val;
  Result.stop := val;
end;

{==============================================================================]
  <TRange.Singular>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRange.Singular: Boolean; cdecl;
begin
  Result := (Self.start = Self.stop);
end;

{==============================================================================]
  <TRange.Atomic>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRange.Atomic: Boolean; cdecl;
begin
  Result := ((Self.start - Self.stop) = 0);
end;

{==============================================================================]
  <TRange.Plural>
  @action: Returns true if range start does NOT equal to stop
  @note: None.
[==============================================================================}
function TRange.Plural: Boolean; cdecl;
begin
  Result := (Self.start <> Self.stop);
end;

{==============================================================================]
  <TRange.Composite>
  @action: Returns true if range start does NOT equal to stop
  @note: None.
[==============================================================================}
function TRange.Composite: Boolean; cdecl;
begin
  Result := not (Self.start = Self.stop);
end;

{==============================================================================]
  <TRange.Ascend>
  @action: Returns ascending TRange of Self.
  @note: None.
[==============================================================================}
function TRange.Ascend: TRange; cdecl;
begin
  Result.start := Min(Self.start, Self.stop);
  Result.stop := Max(Self.stop, Self.start);
end;

{==============================================================================]
  <TRange.Descend>
  @action: Returns descending TRange of Self.
  @note: None.
[==============================================================================}
function TRange.Descend: TRange; cdecl;
begin
  Result.start := Max(Self.stop, Self.start);
  Result.stop := Min(Self.start, Self.stop);
end;

{==============================================================================]
  <TRange.Ascending>
  @action: Returns true if range start is lower or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Ascending: Boolean; cdecl;
begin
  Result := (Self.start <= Self.stop);
end;

{==============================================================================]
  <TRange.Ascends>
  @action: Returns true if range start is lower or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Ascends: Boolean; cdecl;
begin
  Result := not (Self.start > Self.stop);
end;

{==============================================================================]
  <TRange.Descending>
  @action: Returns true if range start is higher or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Descending: Boolean; cdecl;
begin
  Result := (Self.start >= Self.stop);
end;

{==============================================================================]
  <TRange.Descends>
  @action: Returns true if range start is higher or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Descends: Boolean; cdecl;
begin
  Result := not (Self.start < Self.stop);
end;

{==============================================================================]
  <TRange.Increasing>
  @action: Returns true if range start is lower or equal with stop
  @note: Non-strict.
[==============================================================================}
function TRange.Increasing: Boolean; cdecl;
begin
  Result := not (Self.start > Self.stop);
end;

{==============================================================================]
  <TRange.Decreasing>
  @action: Returns true if range start is higher or equal with stop
  @note: Different logic compared to TRange.Descending!
[==============================================================================}
function TRange.Decreasing: Boolean; cdecl;
begin
  Result := not (Self.start < Self.stop);
end;

{==============================================================================]
  <TRange.Growing>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Growing: Boolean; cdecl;
begin
  Result := (Self.start < Self.stop);
end;

{==============================================================================]
  <TRange.Grows>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Grows: Boolean; cdecl;
begin
  Result := not (Self.start >= Self.stop);
end;

{==============================================================================]
  <TRange.Shrinking>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Shrinking: Boolean; cdecl;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <TRange.Shrinks>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Shrinks: Boolean; cdecl;
begin
  Result := not (Self.start <= Self.stop);
end;

{==============================================================================]
  <TRange.Rising>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Rising: Boolean; cdecl;
begin
  Result := (Self.start < Self.stop);
end;

{==============================================================================]
  <TRange.Rises>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Rises: Boolean; cdecl;
begin
  Result := not (Self.start >= Self.stop);
end;

{==============================================================================]
  <TRange.Dropping>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Dropping: Boolean; cdecl;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <TRange.Drops>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Drops: Boolean; cdecl;
begin
  Result := not (Self.start <= Self.stop);
end;

{==============================================================================]
  <TRange.Grab>
  @action: Returns TRange with range, swaps range.stop and range.start if they are in reversed order.
  @note: None.
[==============================================================================}
function TRange.Grab: TRange; cdecl;
begin
  Result := IfThen(Self.Descending, Result.Create(Self.stop, Self.start), Self);
end;

{==============================================================================]
  <TRange.Count>
  @action: Returns count values in the given range.
  @note: None.
[==============================================================================}
function TRange.Count: Integer; cdecl;
begin
  Result := ((Max(Self.start, Self.stop) - Min(Self.start, Self.stop)) + 1);
end;

{==============================================================================]
  <TRange.Area>
  @action: Returns area of the given range.
  @note: None.
[==============================================================================}
function TRange.Area: Integer; cdecl;
begin
  Result := ((Self.stop - Self.start) + 1);
  if (Self.stop < Self.start) then
    Result := (-Result + 2);
end;

{==============================================================================]
  <TRange.Span>
  @action: Returns span of the given range.
  @note: None.
[==============================================================================}
function TRange.Span: Integer; cdecl;
begin
  Result := Abs(Self.stop - Self.start);
end;

{==============================================================================]
  <TRange.Size>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRange.Size: Integer; cdecl;
begin
  Result := (Abs(Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <TRange.Capacity>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.Capacity: Integer; cdecl;
begin
  Result := (IfThen(Self.Descending, (Self.start - Self.stop), (Self.stop - Self.start)) + 1);
end;

{==============================================================================]
  <TRange.Frame>
  @action Returns a TRange covering the full extent of this instance,
          starting at 0 and ending at Size - 1.
  @note   None.
[==============================================================================}
function TRange.Frame(var rSize: Integer): TRange; overload; cdecl;
begin
  rSize := Self.Size;
  Result := Range(0, (rSize - 1));
end;

{==============================================================================]
  <TRange.Frame>
  @action Returns a TRange covering the full extent of this instance,
          starting at 0 and ending at Size - 1.
  @note   None.
[==============================================================================}
function TRange.Frame: TRange; overload; cdecl;
begin
  Result := Range(0, (Self.Size - 1));
end;

{==============================================================================]
  <TRange.Highest>
  @action: Returns maximum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Highest: Integer; cdecl;
begin
  Result := Max(Self.stop, Self.start);
end;

{==============================================================================]
  <TRange.Lowest>
  @action: Returns minimum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Lowest: Integer; cdecl;
begin
  Result := Min(Self.start, Self.stop);
end;

{==============================================================================]
  <TRange.Maximum>
  @action: Returns maximum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Maximum: Integer; cdecl;
begin
  if (Self.start < Self.stop) then
    Result := Self.stop
  else
    Result := Self.start;
end;

{==============================================================================]
  <TRange.Minimum>
  @action: Returns minimum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Minimum: Integer; cdecl;
begin
  if (Self.stop > Self.start) then
    Result := Self.start
  else
    Result := Self.stop;
end;

{==============================================================================]
  <TRange.Exceeds>
  @action: Returns true if TRange contains more than maxElements.
  @note: TRange Exceeds maximum elements.
[==============================================================================}
function TRange.Exceeds(const maxElements: Integer): Boolean; cdecl;
begin
  Result := (Self.Size > maxElements);
end;

{==============================================================================]
  <TRange.Insufficient>
  @action: Returns true if TRange contains less than minElements.
  @note: TRange is behind minimum elements.
[==============================================================================}
function TRange.Insufficient(const minElements: Integer): Boolean; cdecl;
begin
  Result := (Self.Size < minElements);
end;

{==============================================================================]
  <TRange.Digits>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Digits: TIntegerArray; overload; cdecl;
var
  i, s: Integer;
begin
  s := Sign(Self.stop - Self.start);
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := (Self.start + (i * s));
end;

{==============================================================================]
  <TRange.Digits>
  @action: Returns digit from TRange by index.
  @note: None.
[==============================================================================}
function TRange.Digits(const dIndex: Integer): Integer; overload; cdecl;
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
  <TRange.Digits>
  @action: Returns digits from TRange by indexes.
  @note: None.
[==============================================================================}
function TRange.Digits(const dIDs: TIntegerArray): TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, (High(dIDs) + 1));
  for i := 0 to High(dIDs) do
    Result[i] := Self.Digits(dIDs[i]);
end;

{==============================================================================]
  <TRange.IDs>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.IDs: TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Self.Area);
  for i := 0 to High(Result) do
    Result[i] := i;
end;

{==============================================================================]
  <TRange.IDs>
  @action: Returns TRange index by TRange value.
  @note: Returns -2147483648 if dValue does not exist in TRange.
[==============================================================================}
function TRange.IDs(const dValue: Integer): Integer; overload; cdecl;
begin
  case Self.Ascending of
    True:
    if ((dValue < Self.start) or (dValue > Self.stop)) then
      Result := -2147483648
    else
      Result := (dValue - Self.start);
    False:
    if ((dValue > Self.start) or (dValue < Self.stop)) then
      Result := -2147483648
    else
      Result := (Self.start - dValue);
  end;
end;

{==============================================================================]
  <TRange.IDs>
  @action: Returns TRange index by TRange value.
  @note: Returns -2147483648 if dValue does not exist in TRange.
[==============================================================================}
function TRange.IDs(const dVals: TIntegerArray): TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, (High(dVals) + 1));
  for i := 0 to High(dVals) do
    Result[i] := Self.IDs(dVals[i]);
end;

{==============================================================================]
  <TRange.Ints>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Ints: TIntegerArray; cdecl;
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
  <TRange.Values>
  @action: Returns values of the given range.
  @note: None.
[==============================================================================}
function TRange.Values: TIntegerArray; cdecl;
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
  <TRange.TIA>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.TIA: TIntegerArray; cdecl;
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
  <TRange.Enumerate>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Enumerate: TIntegerArray; cdecl;
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
  <TRange.Enumerated>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Enumerated: TIntegerArray; cdecl;
var
  n, i: Integer;
begin
  Result := Self.Reserve;
  i := 0;
  for n in Self do
    Result[i.Increase] := n;
end;

{==============================================================================]
  <TBox.Elements>
  Explanation: Returns TBox points as TPointArray.
  Example: Alternative method.
[==============================================================================}
function TRange.Elements: TIntegerArray; cdecl;
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
  <TRange.Elements>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Numbers: TIntegerArray; cdecl;
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
  <TRange.Items>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Items: TIntegerArray; cdecl;
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
  <TRange.ToArray>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.ToArray: TIntegerArray; cdecl;
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
  <TRange.AsArray>
  @action: Two-way alternative for extracting items from TRange.
  @note: None.
[==============================================================================}
function TRange.AsArray: TIntegerArray; overload; cdecl;
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
  <TRange.Materialize>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Materialize: TIntegerArray; cdecl;
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
  <TRange.Mixed>
  @action: Returns TRange randomly mixed as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Mixed(const mixings: Integer = 1): TIntegerArray; cdecl;
var
  i, s, r: Integer;
begin
  s := IfThen(Self.Ascending, 1, -1);
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := ((Self.Start + i) * s);
  if (Result.Size > 1) then
  for r := 1 to mixings do
    for i := High(Result) downto 0 do
      Swap(Result[Random(Result.Size)], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <TRange.Shake>
  @action: Returns TRange randomly shaked as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Shake(const shakes: Integer = 1): TIntegerArray; cdecl;
var
  i, s, r: Integer;
begin
  s := IfThen(Self.Ascending, 1, -1);
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := ((Self.Start + i) * s);
  if (Result.Size > 1) then
  for r := 1 to shakes do
    for i := Random(Result.Size) downto 0 do
      Swap(Result[i], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <TRange.Shuffle>
  @action: Returns TRange randomly shuffled as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Shuffle(const shuffles: Integer = 1): TIntegerArray; cdecl;
var
  i, s, r: Integer;
begin
  s := IfThen(Self.Ascending, 1, -1);
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := ((Self.Start + i) * s);
  if (Result.Size > 1) then
  for r := 1 to shuffles do
    for i := High(Result) downto 0 do
      Swap(Result[i], Result[Random(Result.Size)]);
end;

{==============================================================================]
  <TRange.Any>
  @action: Returns random TRange item.
  @note: None.
[==============================================================================}
function TRange.Any: Integer; cdecl;
begin
  Result := ((Self.Start + Random(Self.Size)) * IfThen(Self.Ascending, 1, -1));
end;

{==============================================================================]
  <TRange.Some>
  @action: Returns random amount of random TRange items.
  @note: Does not return empty arrays.
[==============================================================================}
function TRange.Some: TIntegerArray; overload; cdecl;
begin
  Result := Copy(Self.Shuffle, 0, Max(Random(Self.Size + 1), 1))
end;

{==============================================================================]
  <TRange.Some>
  @action: Returns random amount of random TRange items.
  @note: Does not return empty arrays.
[==============================================================================}
function TRange.Some(const amount: Integer): TIntegerArray; overload; cdecl;
begin
  Result := Copy(Self.Shuffle, 0, Max(1, Min(amount, Self.Size)));
end;

{==============================================================================]
  <TRange.All>
  @action: Returns ALL TRange items as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.All: TIntegerArray; overload; cdecl;
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
  <TRange.Normalize>
  @action: Using Min-Maxing this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Normalize: TRange; cdecl;
begin
  Result.start := Min(Self.start, Self.stop);
  Result.stop := Max(Self.start, Self.stop);
end;

{==============================================================================]
  <TRange.Overlapping>
  @action: Checks if a and b overlap eachother.
  @note: Returns true if overlap is found.
[==============================================================================}
function TRange.Overlapping(const b: TRange): Boolean; cdecl;
begin
  Result := ((Min(Self.start, Self.stop) <= Max(b.start, b.stop)) and (Min(b.start, b.stop) <= Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <TRange.Overlap>
  @action: Checks if a and b overlap eachother.
  @note: Returns true if overlap is found.
[==============================================================================}
function TRange.Overlap(const b: TRange): Boolean; cdecl;
begin
  Result := not ((Min(Self.start, Self.stop) > Max(b.start, b.stop)) or (Min(b.start, b.stop) > Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <TRange.Intersect>
  @action: Returns intersection of a and b.
  @note: Returns null if there is no intersection for a and b.
[==============================================================================}
function TRange.Intersect(const b: TRange): TRange; overload; cdecl;
var
  s, t: TRange;
begin
  s := Self.Normalize;
  t := b.Normalize;
  Result.start := Max(s.start, t.start);
  Result.stop := Min(s.stop, t.stop);
end;

{==============================================================================]
  <TRange.Intersect>
  @action: Returns true if of a and b contains intersection.
  @note: Stores intersection to variable, if Result is True.
[==============================================================================}
function TRange.Intersect(const b: TRange; var iZone: TRange): Boolean; overload; cdecl;
var
  s, t: TRange;
  x, y: Integer;
begin
  s := Self.Normalize;
  t := b.Normalize;
  x := Max(s.start, t.start);
  y := Min(s.stop, t.stop);
  Result := (x <= y);
  if Result then
    iZone.Create(x, y);
end;

{==============================================================================]
  <TRange.Extend>
  @action: Returns true TRange is extended with val (val is not yet in range)
  @note: None.
[==============================================================================}
function TRange.Extend(const val: Integer): Boolean; cdecl;
begin
  case Self.Descending of
    True:
    if (val > Self.start) then
      Self.start := val
    else
      if (val < Self.stop) then
        Self.stop := val
      else
        Exit(False);
    False:
    if (val < Self.start) then
      Self.start := val
    else
      if (val > Self.stop) then
        Self.stop := val
      else
        Exit(False);
  end;
  Result := True;
end;

{==============================================================================]
  <TRange.Union>
  @action: Returns union of ranges a and b.
  @note: None.
[==============================================================================}
function TRange.Union(const b: TRange): TRange; overload; cdecl;
begin
  Result.start := Min(Min(Self.start, Self.stop), Min(b.start, b.stop));
  Result.stop := Max(Max(Self.start, Self.stop), Max(b.start, b.stop));
end;

{==============================================================================]
  <TRange.Union>
  @action: Returns union of range and val.
  @note: None.
[==============================================================================}
function TRange.Union(const val: Integer): TRange; overload; cdecl;
begin
  Result := Self;
  case Self.Descending of
    True:
	if (val > Self.start) then
	  Result.start := val
	else
	  if (val < Self.stop) then
	    Result.stop := val;
    False:
	if (val < Self.start) then
	  Result.start := val
	else
	  if (val > Self.stop) then
	    Result.stop := val;
  end;
end;

{==============================================================================]
  <TRange.Shift>
  @action: Returns shift of range r by delta.
  @note: None.
[==============================================================================}
function TRange.Shift(const sDelta: Integer): TRange; cdecl;
begin
  Result.Create((Self.start + delta), (Self.stop + delta));
end;

{==============================================================================]
  <TRange.Contains>
  @action: Returns True if range contains x-value.
  @note: None.
[==============================================================================}
function TRange.Contains(const x: Integer): Boolean; overload; cdecl;
begin
  Result := ((x >= Min(Self.start, Self.stop)) and (x <= Max(Self.stop, Self.start)));
end;

{==============================================================================]
  <TRange.Contains>
  @action: Returns True if range contains x.
  @note: Meaning x is completely part of range.
[==============================================================================}
function TRange.Contains(const x: TRange): Boolean; overload; cdecl;
begin
  Result := ((Min(x.start, x.stop) >= Min(Self.start, Self.stop)) and (Max(x.start, x.stop) <= Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <TRange.Above>
  @action: Returns True if range is above target.
  @note: None.
[==============================================================================}
function TRange.Above(const target: Integer): Boolean; overload; cdecl;
begin
  Result := (Self.Minimum > target);
end;

function TRange.Above(const target: TRange): Boolean; overload; cdecl;
begin
  Result := Self.Above(target.Maximum);
end;

{==============================================================================]
  <TRange.Below>
  @action: Returns True if range is below target.
  @note: None.
[==============================================================================}
function TRange.Below(const target: Integer): Boolean; overload; cdecl;
begin
  Result := (Self.Maximum < target);
end;

function TRange.Below(const target: TRange): Boolean; overload; cdecl;
begin
  Result := Self.Below(target.Minimum);
end;

{==============================================================================]
  <TRange.Reversed>
  @action: Returns reversed range.
  @note: None.
[==============================================================================}
function TRange.Reversed: TRange; cdecl;
begin
  Result.start := Self.stop;
  Result.stop := Self.start;
end;

{==============================================================================]
  <TRange.Reverse>
  @action: Reverses range, returns True if range was reversed.
  @note: None.
[==============================================================================}
function TRange.Reverse: Boolean; cdecl;
begin
  Result := Self.Plural;
  if Result then
    Swap(Self.start, Self.stop);
end;

{==============================================================================]
  <TRange.Equals>
  @action: Checks if a matches b.
  @note: 0..3 and 3..0 will be treated as match.
[==============================================================================}
function TRange.Equals(const b: TRange): Boolean; cdecl;
begin
  Result := ((Min(Self.start, Self.stop) = Min(b.start, b.stop)) and (Max(Self.start, Self.stop) = Max(b.start, b.stop)));
end;

{==============================================================================]
  <TRange.Differs>
  @action: Checks if a unmatches b.
  @note: 0..3 and 3..0 will be treated as match.
[==============================================================================}
function TRange.Differs(const b: TRange): Boolean; cdecl;
begin
  Result := ((Min(Self.start, Self.stop) <> Min(b.start, b.stop)) or (Max(Self.start, Self.stop) <> Max(b.start, b.stop)));
end;

{==============================================================================]
  <TRange.Equal>
  @action: Checks if a matches b exactly.
  @note: 0..3 and 3..0 will NOT be treated as match.
[==============================================================================}
function TRange.Equal(const b: TRange): Boolean; cdecl;
begin
  Result := ((Self.start = b.start) and (Self.stop = b.stop));
end;

{==============================================================================]
  <TRange.Differ>
  @action: Checks if a unmatches b exactly.
  @note: 0..3 and 3..0 will NOT be treated as match.
[==============================================================================}
function TRange.Differ(const b: TRange): Boolean; cdecl;
begin
  Result := ((Self.start <> b.start) or (Self.stop <> b.stop));
end;

{==============================================================================]
  <TRange.Clamp>
  @action: Returns range clamped inside zone range.
  @note: Makes sure Result is range fitted in zone bounds.
[==============================================================================}
function TRange.Clamp(const zone: TRange): TRange; cdecl;
var
  z: TRange;
begin
  Result := Self.Normalize;
  z := zone.Normalize;
  if (Result.start < z.start) then
    Result.start := z.start
  else
    if (Result.start > z.stop) then
      Result.start := z.stop;
  if (Result.stop > z.stop) then
    Result.stop := z.stop
  else
    if (Result.stop < z.start) then
      Result.stop := z.start;
  if (Self.start > Self.stop) then
    Result.Reverse;
end;

{==============================================================================]
  <TRange.ClampMax>
  @action: Returns range with start and stop with maximum value.
  @note: Makes sure neither start or stop is higher than maximum.
[==============================================================================}
function TRange.ClampMax(const maxValue: Integer): TRange; cdecl;
begin
  if (Self.start > maxValue) then
    Result.start := maxValue
  else
    Result.start := Self.start;
  if (Self.stop > maxValue) then
    Result.stop := maxValue
  else
    Result.stop := Self.stop;
end;

{==============================================================================]
  <TRange.ClampMin>
  @action: Returns range with start and stop with minimum value.
  @note: Makes sure neither start or stop is lower than minimum.
[==============================================================================}
function TRange.ClampMin(const minValue: Integer): TRange; cdecl;
begin
  if (Self.start < minValue) then
    Result.start := minValue
  else
    Result.start := Self.start;
  if (Self.stop < minValue) then
    Result.stop := minValue
  else
    Result.stop := Self.stop;
end;

{==============================================================================]
  <TRange.Restrict>
  @action: Ensures range start and stop stays within zone.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange.Restrict(const zone: TRange): Boolean; cdecl;
var
  e: TRange;
begin
  e := Self.Clamp(zone);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <TRange.RestrictMin>
  @action: Ensures range start and stop stays within minimum.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange.RestrictMin(const minValue: Integer): Boolean; cdecl;
var
  e: TRange;
begin
  e := Self.ClampMin(minValue);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <TRange.RestrictMax>
  @action: Ensures range start and stop stays within maximum.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange.RestrictMax(const maxValue: Integer): Boolean; cdecl;
var
  e: TRange;
begin
  e := Self.ClampMax(maxValue);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <TRange.Clip>
  @action: Ensures range start and stop stays within zone.
  @note: Alternative for TRange_Clamp.
[==============================================================================}
function TRange.Clip(const zone: TRange): TRange; cdecl;
begin
  Result.start := Max(zone.start, Min(Self.start, zone.stop));
  Result.stop := Min(zone.stop, Max(Self.stop, zone.start));
end;

{==============================================================================]
  <TRange.ClipMin>
  @action: Ensures range start and stop stays within minimum.
  @note: Alternative for TRange_ClampMin.
[==============================================================================}
function TRange.ClipMin(const minValue: Integer): TRange; cdecl;
begin
  Result.start := Max(Self.start, minValue);
  Result.stop := Max(Self.stop, minValue);
end;

{==============================================================================]
  <TRange.ClipMax>
  @action: Ensures range start and stop stays within maximum.
  @note: Alternative for TRange_ClampMax.
[==============================================================================}
function TRange.ClipMax(const maxValue: Integer): TRange; cdecl;
begin
  Result.start := Min(Self.start, maxValue);
  Result.stop := Min(Self.stop, maxValue);
end;

{==============================================================================]
  <TRange.Include>
  @action: Expands the range to include the given value while preserving ascending/descending order.
  @note: If the value is already inside the range, the range remains unchanged.
[==============================================================================}
function TRange.Include(const val: Integer): TRange; overload; cdecl;
begin
  Result := Self;
  case Result.Ascending of
    True:
    if (val < Result.start) then
      Result.start := val
    else
      if (val > Result.stop) then
        Result.stop := val;
    False:
    if (val < Result.stop) then
      Result.stop := val
    else
      if (val > Result.start) then
        Result.start := val;
  end;
end;

{==============================================================================]
  <TRange.Absorb>
  @action: Expands the range to include the given value while preserving ascending/descending order.
  @note: If the value is already inside the range, the range remains unchanged.
         Returns true if value was added in.
[==============================================================================}
function TRange.Absorb(const val: Integer): Boolean; overload; cdecl;
var
  s: TRange;
begin
  s := Self;
  case Self.Ascending of
    True:
    if (val < Self.start) then
      Self.start := val
    else
      if (val > Self.stop) then
        Self.stop := val;
    False:
    if (val > Self.start) then
      Self.start := val
    else
      if (val < Self.stop) then
        Self.stop := val;
  end;
  Result := (Self <> s); 
end;

{==============================================================================]
  <TRangeHelper.Create>
  @action: TRange 0..0.
  @note: None.
[==============================================================================}
function TRangeHelper.Create: TRange; cdecl;
begin
  Self.start := 0;
  Self.stop := 0;
  Result := Self;
end;

{==============================================================================]
  <TRangeHelper.Distribute>
  @action: Distributes range to TRangeArray by amount of parts
  @note: None.
[==============================================================================}
function TRangeHelper.Distribute(const parts: Integer): TRangeArray; cdecl;
var
  i, s, e, a, b, p: Integer;
  r: TRange;
begin
  if (parts > 0) then
  begin
    r := Self.Normalize;
    s := r.Size;
    p := Min(s, parts);
    e := (s mod p);
    a := r.start;
    SetLength(Result, p);
    for i := 0 to (p - 1) do
    begin
      b := (a + ((s div p) - 1));
      if (i < e) then
        Inc(b);
      if (Self.start > Self.stop) then
        Result[i].Create(b, a)
      else
        Result[i].Create(a, b);
      a := (b + 1);
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <TRangeHelper.Partition>
  @action: Partitions range to TRangeArray by size of parts
  @note: None.
[==============================================================================}
function TRangeHelper.Partition(const size: Integer): TRangeArray; cdecl;
var
  a, b, l: Integer;
  r: TRange;
begin
  l := 0;
  if (size > 0) then
  begin
    r := Self.Normalize;
    SetLength(Result, r.Size);
    a := r.start;
    while (a <= r.stop) do
    begin
      b := Min(((a + size) - 1), r.stop);
      if (Self.start > Self.stop) then
        Result[l.Increase].Create(b, a)
      else
        Result[l.Increase].Create(a, b);
      a := (b + 1);
    end;
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <TRangeHelper.Divide>
  @action: Partitions range to TRangeArray by size of parts
  @note: Alternative for TRange_Partition.
[==============================================================================}
function TRangeHelper.Divide(const size: Integer): TRangeArray; cdecl;
var
  a, b, i: Integer;
  r: TRange;
begin
  if (size > 0) then
  begin
    r := Self.Normalize;
    SetLength(Result, (((r.Size + size) - 1) div size));
    a := r.start;
    for i := 0 to High(Result) do
    begin
      b := Min(((a + size) - 1), r.stop);
      if (Self.start > Self.stop) then
        Result[i].Create(b, a)
      else
        Result[i].Create(a, b);
      a := (b + 1);
    end;
  end else
    SetLength(Result, 0);
end;

{==============================================================================]
  <TRange.Neighbor>
  @action: Returns true if 2 TRanges are right next to eachother.
  @note: (Distance is exactly 1 between em).
[==============================================================================}
function TRange.Neighbor(const b: TRange): Boolean; cdecl;
var
  i, j: TRange;
begin
  i := Self.Normalize;
  j := b.Normalize;
  Result := ((i.stop + 1) = j.start) or ((j.stop + 1) = i.start);
end;

{==============================================================================]
  <TRange.Neighbour>
  @action: Returns true if 2 TRanges are right next to eachother.
  @note: (Distance is exactly 1 between em).
[==============================================================================}
function TRange.Neighbour(const b: TRange): Boolean; cdecl;
begin
  Result := (((Max(Self.start, Self.stop) + 1) = Min(b.start, b.stop)) or ((Max(b.start, b.stop) + 1) = Min(Self.start, Self.stop)));
end;

{==============================================================================]
  <TRange.Touch>
  @action: Returns true if range touches b.
  @note: Touch = only single value is shared between the ranges.
[==============================================================================}
function TRange.Touch(const b: TRange): Boolean; cdecl;
var
  l, h, r: TRange;
begin
  l := Self.Normalize;
  h := b.Normalize;
  r.Create(Max(l.start, h.start), Min(l.stop, h.stop));
  Result := r.Singular;
end;

{==============================================================================]
  <TRange.Touches>
  @action: Returns true if range touches b with minimum and maximum contact.
  @note: Touch = minimum/maximum shared values.
[==============================================================================}
function TRange.Touches(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; cdecl;
var
  x, y: TRange;
  i, s: Integer;
begin
  x := Self.Normalize;
  y := b.Normalize;
  s := 0;
  for i := x.start to x.stop do
    if ((i >= y.start) and (i <= y.stop)) then
      if (s.Increment > maxTouch) then
        Exit(False);
  Result := (s >= minTouch);
end;

{==============================================================================]
  <TRange.Touching>
  @action: Returns true if range touches b with minimum and maximum contact.
  @note: Touch = minimum/maximum shared values.
[==============================================================================}
function TRange.Touching(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; cdecl;
var
  x, y: TRange;
  s, i: Integer;
begin
  x := Self.Normalize;
  y := b.Normalize;
  s := 0;
  for i := x.start to x.stop do
    if ((i >= y.start) and (i <= y.stop)) then
      if (s.Increment > maxTouch) then
        Exit(False);
  Result := (s >= minTouch);
end;

{==============================================================================]
  <TRange.Distance>
  @action: Returns minimum distance between ranges a and b.
  @note: If ranges overlap, distance is 0.
[==============================================================================}
function TRange.Distance(const b: TRange): Integer; cdecl;
var
  r1, r2: TRange;
begin
  r1 := Self.Normalize;
  r2 := b.Normalize;
  if (r1.stop < r2.start) then
    Result := (r2.start - r1.stop)
  else
    if (r2.stop < r1.start) then
      Result := (r1.start - r2.stop)
    else
      Result := 0;
end;

{==============================================================================]
  <TRange.DistHausdorff>
  @action: Returns Hausdorff-based distance between ranges a and b.
  @note: None.
[==============================================================================}
function TRange.DistHausdorff(const b: TRange): Integer; cdecl;
var
  i, j: TRange;
begin
  i := Self.Normalize;
  j := b.Normalize;
  Result := Max(Abs(i.start - j.stop), Abs(i.stop - j.start));
end;

{==============================================================================]
  <TRange.Delta>
  @action: Delta returns the signed difference from start to stop; the sign indicates the range’s orientation.
  @note: None.
[==============================================================================}
function TRange.Delta: Integer; cdecl; inline;
begin
  Result := (Self.stop - Self.start);
end;

{==============================================================================]
  <TRange.Direction>
  @action: Returns the orientation of the range.
  @note: 1  => descending (stop > start)
        -1  => ascending  (start > stop)
         0  => degenerate (start = stop)
[==============================================================================}
function TRange.Direction: Integer; cdecl;
begin
  Result := Sign(Self.Delta);
end;

{==============================================================================]
  <TRange.Magnitude>
  @action: Returns the magnitude (non-negative size) of the range, ignoring orientation.
  @note: Computed as the absolute value of Delta (Abs(Stop - Start)).
         Always ≥ 0, regardless of whether the range is ascending or descending.
[==============================================================================}
function TRange.Magnitude: Integer; cdecl;
begin
  Result := Abs(Self.Delta);
end;

{==============================================================================]
  <TRange.Orientation>
  @action: Returns +1 if the range is ascending or degenerate (Stop >= Start),
           and -1 if the range is descending (Stop < Start).
  @note: Useful for determining iteration direction or orientation of the range.
[==============================================================================}
function TRange.Orientation: Integer; cdecl;
begin
  Result := IfThen((Self.Stop < Self.Start), -1, 1);
end;

{==============================================================================]
  <TRange.Deficit>
  @action: Returns the negative absolute distance between Start and Stop.
  @note: Computed as Min(Start, Stop) - Max(Start, Stop).
         Always ≤ 0. Ignores orientation; useful when a negative “shortfall” value is needed.
[==============================================================================}
function TRange.Deficit: Integer; cdecl;
begin
  Result := (Min(Self.start, Self.stop) - Max(Self.start, Self.stop));
end;

{==============================================================================]
 <TRange.Digit>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRange.Digit(const x: Integer): Boolean; cdecl; inline;
begin
  Result := (((x >= Self.start) and (x <= Self.stop)) or ((x >= Self.stop) and (x <= Self.start)));
end;

{==============================================================================]
 <TRange.Value>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRange.Value(const x: Integer): Boolean; cdecl; inline;
begin
  Result := not (((x < Self.start) and (x < Self.stop)) or ((x > Self.stop) and (x > Self.start)));
end;

{==============================================================================]
 <TRange.Lacks>
 @action: Returns true if x-value is out of range.
 @note: None.
[==============================================================================}
function TRange.Lacks(const x: Integer): Boolean; cdecl; inline;
begin
  Result := (((x < Self.start) and (x < Self.stop)) or ((x > Self.stop) and (x > Self.start)));
end;

{==============================================================================]
 <TRange.Outside>
 @action: Returns true if x-value is outside the range.
 @note: None.
[==============================================================================}
function TRange.Outside(const x: Integer): Boolean; cdecl; inline;
begin
  Result := not (((x >= Self.start) and (x <= Self.stop)) or ((x >= Self.stop) and (x <= Self.start)));
end;

{==============================================================================]
 <TRange.Item>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRange.Item(const x: Integer): Boolean; cdecl; inline;
begin
  if (Self.start <= Self.stop) then
    Result := ((x >= Self.start) and (x <= Self.stop))
  else
    Result := ((x >= Self.stop) and (x <= Self.start));
end;

{==============================================================================]
 <TRange.Pivot>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Pivot: Integer; cdecl;
begin
  if Self.Ascending then
    Result := (Self.start + ((Self.stop - Self.start) div 2))
  else
    Result := (Self.stop + ((Self.start - Self.stop) div 2));
end;

{==============================================================================]
 <TRange.Middle>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Middle: Integer; cdecl;
begin
  Result := ((Self.start + Self.stop) div 2);
end;

{==============================================================================]
 <TRange.Mid>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Mid: Double; cdecl;
begin
  Result := ((Self.start + Self.stop) / 2.0);
end;

{==============================================================================]
 <TRange.MidVal>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.MidVal: Double; cdecl;
var
  s: Integer;
begin
  s := (Self.Highest + Self.Lowest);
  Result := (s div 2);
  if ((s mod 2) = 1) then
    Result := (((Result + 1) + Result) / 2.0);
end;

{==============================================================================]
 <TRange.MidValue>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.MidValue: Double; cdecl;
var
  s: Integer;
begin
  s := (Self.start + Self.stop);
  Result := (s div 2);
  if ((s mod 2) <> 0) then
    Result := (Result + 0.5);
end;

{==============================================================================]
 <TRange.Average>
 @action: Average value from TRange.
 @note: None
[==============================================================================}
function TRange.Average: Double; cdecl;
var
  c: Int64;
begin
  c := Self.Size;
  Result := ((c * (Self.start + Self.stop) div 2) / c);
end;

{==============================================================================]
 <TRange.Center>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Center: Integer; cdecl;
begin
  Result := ((Self.Highest + Self.Lowest) div 2);
end;

{==============================================================================]
 <TRange.Central>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Central: Integer; cdecl; inline;
begin
  Result := ((Self.start + self.stop) shr 1);
end;

{==============================================================================]
 <TRange.Str>
 @action: Converts TRange range to string.
 @note: None
[==============================================================================}
function TRange.Str(const openRange: string = '['; const closeRange: string = ']'; const glueRange: string = '..'): string; cdecl;
begin
  Result := ('[' + IntToStr(Self.start) + glueRange + IntToStr(Self.stop) + ']');
end;

{==============================================================================]
 <TRange.ToStr>
 @action: Converts TRange range to string.
 @note: None
[==============================================================================}
function TRange.ToStr(const glueRange: string = '..'; const openRange: string = '['; const closeRange: string = ']'): string; cdecl;
begin
  Result := '';
  if (openRange <> '') then
    Result := (Result + openRange);
  Result := (Result + IntToStr(Self.start));
  if (glueRange <> '') then
    Result := (Result + glueRange);
  Result := (Result + IntToStr(Self.stop));
  if (closeRange <> '') then
    Result := (Result + closeRange);
end;

{==============================================================================]
 <TRange.Stringify>
 @action: Converts TRange range to string.
 @note: None
[==============================================================================}
function TRange.Stringify(const openRange: string = '['; const glueRange: string = '..'; const closeRange: string = ']'): string; cdecl;
begin
  Result := Format(openRange + '%d' + glueRange + '%d' + closeRange, [Self.start, Self.stop]);
end;

{==============================================================================]
 <TRange.Sum>
 @action: Returns the sum of all TRange values (start..stop)
 @note: None
[==============================================================================}
function TRange.Sum: Int64; cdecl;
var
  a, b: Int64;
begin
  a := Min(Self.start, Self.stop);
  b := Max(Self.start, Self.stop);
  Result := ((((b - a) + 1) * (a + b)) div 2);
end;

{==============================================================================]
 <TRange.Summation>
 @action: Returns the sum of all TRange values (start..stop)
 @note: None
[==============================================================================}
function TRange.Summation: Int64; cdecl;
var
  a, b, c, s, n: Int64;
begin
  a := Min(Self.start, Self.stop);
  b := Max(Self.start, Self.stop);
  n := ((b - a) + 1);
  s := (a + b);
  c := (s div 2);
  Result := (n * c);
  if ((s and 1) = 1) then
    Result := (Result + (n div 2));
end;

{==============================================================================]
 <TRange.Total>
 @action: Returns the sum of all TRange values (start..stop)
 @note: None
[==============================================================================}
function TRange.Total: Int64; cdecl;
begin
  if Self.Descending then
    Result := (((Int64(Self.start) * (Self.start + 1)) div 2) - ((Int64(Self.stop - 1) * Self.stop) div 2))
  else
    Result := (((Int64(Self.stop) * (Self.stop + 1)) div 2) - ((Int64(Self.start - 1) * Self.start) div 2));
end;

{==============================================================================]
  <TRange.Reserve>
  @action: Allocate an integer array sized to fit the full range.
  @note: The array is preallocated with the correct length but is not filled 
         with values from start..stop. Elements are default-initialized to 0.
[==============================================================================}
function TRange.Reserve: TIntegerArray; overload; cdecl;
begin
  SetLength(Result, Self.Size);
end;

{==============================================================================]
  <TRange.Reserve>
  @action: Allocate an integer array sized to fit the full range.
  @note: The array is preallocated with the correct length but is not filled 
         with values from start..stop. Elements are default-initialized to 0.
[==============================================================================}
function TRange.Reserve(var aRange: TIntegerArray): Integer; overload; cdecl;
begin
  Result := Self.Size;
  SetLength(aRange, Result);
end;

{==============================================================================]
  <TRange.Extract>
  @action: Extracts TRange as TIntegerArray. 
  @note: None.
[==============================================================================}
function TRange.Extract: TIntegerArray; overload; cdecl;
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
  <TRange.Extracted>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Extracted: TIntegerArray; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Result) do
    Result[i] := (Self.Start + i);
  if Self.Descending then
    Result.Reverse;
end;

{==============================================================================]
  <TRange.Steps>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Steps: TIntegerArray; overload; cdecl;
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
  <TRange.Recursed>
  @action: Returns digits of the given range.
  @note: Recursion-based.
[==============================================================================}
function TRange.Recursed: TIntegerArray; overload; cdecl;
  function BR(const rStart, rStop: Integer): TIntegerArray;
  begin
    if (rStart = rStop) then
      Exit([rStart]);
    Result := BR(rStart, (rStop - Sign(rStop - rStart)));
    SetLength(Result, (Length(Result) + 1));
    Result[High(Result)] := rStop;
  end;
begin
  Result := BR(Self.start, Self.stop);
end;

{==============================================================================]
  <TRange.Limit>
  @action: Restricts a value to lie within the range defined by Start and Stop.
  @note: Equivalent to clamping value to the inclusive range [Min(start, stop), Max(start, stop)].
         Returns Min(start, stop) if val is below the range.
         Returns Max(start, stop) if val is above the range.
         Otherwise returns value itself.
[==============================================================================}
function TRange.Limit(const val: Integer): Integer; cdecl;
var
  r: TRange;
begin
  r.Create(Min(Self.Start, Self.Stop), Max(Self.start, Self.stop));
  if (val < r.start) then
    Result := r.start
  else
    if (val > r.stop) then
      Result := r.stop
    else
      Result := val;
end;

{==============================================================================]
  <TRange.MinLimit>
  @action: Ensures a value is not less than the range minimum.
  @note: Returns Max(val, Min(start, stop)).
         Values above the range maximum are allowed.
         Useful when you only want to enforce a lower bound.
[==============================================================================}
function TRange.MinLimit(const val: Integer): Integer; cdecl;
begin
  Result := Max(val, Min(Self.start, Self.stop));
end;

{==============================================================================]
  <TRange.MaxLimit>
  @action: Ensures a value is not greater than the range maximum.
  @note: Returns Min(val, Max(start, stop)).
         Values below the range minimum are allowed.
         Useful when you only want to enforce an upper bound.
[==============================================================================}
function TRange.MaxLimit(const val: Integer): Integer; cdecl;
begin
  Result := Min(val, Max(Self.start, Self.stop));
end;

{==============================================================================]
  <TRange.Sample>
  @action: Return evenly spaced integer samples across the range.
  @note: Always includes both start and stop values of the range (if sSize > 1).
         Uses rounding to map floating step positions to integers.
         If sSize = 1, returns only the start value.
[==============================================================================}
function TRange.Sample(const sSize: Integer): TIntegerArray; overload; cdecl;
var
  i: Integer;
  s: Double;
begin
  if (sSize < 1) then
    Exit([]);
  SetLength(Result, sSize);
  s := (Self.Delta / (sSize - 1));
  for i := 0 to (sSize - 1) do
    Result[i] := Round(Self.start + (i * s));
end;

{==============================================================================]
  <TRange.Windows>
  @action: Generate all possible subranges (sliding windows) of Self inside
           the target range. These windows may overlap.
  @note:   The number of results is (TargetSize - SelfSize + 1).
[==============================================================================}
function TRangeHelper.Windows(const target: TRange): TRangeArray; overload; cdecl;
var
  r, s: Integer;
  f, t: TRange;
begin
  s := Self.Size;
  if (target.Size < s) then
    Exit([]);
  t.Create(Min(target.start, target.stop), ((Max(target.start, target.stop) - s) + 1));
  SetLength(Result, t.Size);
  r := 0;
  f := Self.Frame;
  for s := t.start to t.stop do
    Result[r.Increase].Create((f.start + s), (f.stop + s));
end;

{==============================================================================]
  <TRange.Sectioned>                                                             
  @action: Divide the target range into sequential, non-overlapping subranges
           of the same size as Self.
  @note:   Any remainder at the end of the target range is discarded.
[==============================================================================}
function TRangeHelper.Sectioned(const target: TRange): TRangeArray; overload; cdecl;
var
  p, r, s, m: Integer;
  f, t: TRange;
begin
  s := Self.Size;
  t := target.Normalize;
  if (s > t.Size) then
    Exit([]);
  f := Self.Frame;
  m := ((t.stop - s) + 1);
  SetLength(Result, (t.Size div s));
  r := 0;
  p := (t.start - s);
  while (p.Increment(s) <= m) do
    Result[r.Increase].Create((f.start + p), (f.stop + p));
end;

{==============================================================================]
  <TRange.Binned>
  @action: Generate grid-aligned subranges (bins) of the same size as Self
           inside the target range.
  @note:   Subranges are aligned in steps of SelfSize from the start of target.
           Any remainder that does not fit evenly is ignored.
[==============================================================================}
function TRangeHelper.Binned(const target: TRange): TRangeArray; overload; cdecl;
var
  i, s: Integer;
  f, t: TRange;
begin
  t := target.Normalize;
  s := Self.Size;
  if (s > t.Size) then
    Exit([]);
  f := Self.Frame;
  SetLength(Result, (t.Size div s));
  for i := 0 to High(Result) do
  begin
    Result[i].start := (t.start + (s * i));
    Result[i].stop := (Result[i].start + (s - 1));
  end;
end; 

{==============================================================================]
  <_TRange.Create>
  @action: Creates TPoint using pX, pY 
  @note: function version
[==============================================================================}
class function _TRange.Create(const rStart, rStop: Integer): TRange; overload; cdecl;
begin
  Result.start := rStart;
  Result.stop := rStop;
end;

{==============================================================================]
  <_TRange.Create>
  @action: Creates TPoint using value 
  @note: function version
[==============================================================================}
class function _TRange.Create(const value: Integer = 0): TRange; overload; cdecl;
begin
  Result := _TRange.Create(value, value);
end;

{$UNDEF TRange}
