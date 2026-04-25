{$IFDEF METHODS}
class function Ascending(const A, B: Integer): TRange; overload; static;
function Assign(const AStart, AStop: Integer): Integer; overload;
function Assign(const ARange: TRange): Integer; overload;
class function Construct(const rStart, rStop: Integer): TRange; overload; static;
class function Construct(const rVal: Integer): TRange; overload; static;
class function Construct: TRange; overload; static;
class function Construct(const arr: TIntegerArray; const oAscending: Boolean = True): TRange; overload; static;
function Build(const rStart: Integer = 0; const rStop: Integer = 0): Integer; overload;
constructor Create(const rStart, rStop: Integer); overload;
constructor Create(const value: Integer); overload;
constructor Create(const data: string); overload;
constructor Create(const other: TRange); overload;
constructor Create(const arr: TIntegerArray; const rAscending: Boolean = True); overload;
class function Descending(const A, B: Integer): TRange; overload; static;
class function From(const startingVal: Integer; const stepCount: Integer = 0): TRange; overload; static;
class function From(const arr: TIntegerArray; const rAscending: Boolean = True): TRange; overload; static;
class function Form(const val: Integer; const radius: Integer = 0; const rAscending: Boolean = True): TRange; overload; static;
class function Form(const arr: TIntegerArray; const rAscending: Boolean = True): TRange; overload; static;
function Init(const rStart, rStop: Integer): TRange; overload;
function Init(const r: TRange): TRange; overload;
function Init(const val: Integer = 0): TRange; overload;
function Make(const A: Integer = 0; const B: Integer = 0): Integer; overload;
class function Null(const value: Integer = -2147483648): TRange; overload; static;
class function Unbounded(const oAscending: Boolean = True): TRange; overload; static;
{$ENDIF}

{$IFDEF HELPERS}
function Create: TRange; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Range(const rStart, rStop: Integer): TRange; overload;
function Range(const val: Integer = 0): TRange; overload;
function Range(const arr: TIntegerArray; const rAscending: Boolean = True): TRange; overload;
function R(const startVal, stopVal: Integer): TRange; overload;
function R(const val: Integer = 0): TRange; overload;
function R(const arr: TIntegerArray; const rAscending: Boolean = True): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascending>
  @action: Creates a range whose start value is less than or equal to its stop
           value, regardless of the order of the input parameters.
  @note: The smaller of A and B is assigned to start, and the larger to stop.
         This guarantees an ascending (non-decreasing) range.
[==============================================================================}
class function TRange.Ascending(const A, B: Integer): TRange; overload;
begin
  Result.start := Min(A, B);
  Result.stop := Max(A, B);
end;

{==============================================================================]
  <Assign>
  @action: Sets the boundary points of the range and returns its total span.
  @note: This method allows for "unordered" input; the returned size is 
         always the absolute distance (delta) between start and stop.
[==============================================================================}
function TRange.Assign(const AStart, AStop: Integer): Integer; overload;
begin
  Self.start := AStart;
  Self.stop := AStop;
  Result := Self.Size;
end;

{==============================================================================]
  <Assign>
  @action: Copies the boundaries from a target range and returns the new size.
  @note: None.
[==============================================================================}
function TRange.Assign(const ARange: TRange): Integer; overload;
begin
  Result := Self.Assign(ARange.start, ARange.stop);
end;

{==============================================================================]
  <Build>
  @action: Create a TRange with rStart and rStop, using Min and Max for safety.
  @note: None.
[==============================================================================}
function TRange.Build(const rStart: Integer = 0; const rStop: Integer = 0): Integer; overload;
begin
  Self.start := Min(rStart, rStop);
  Self.stop := Max(rStop, rStart);
  Result := ((Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <Construct>
  @action: Constructs TRange with rStart and rStop.
  @note: None.
[==============================================================================}
class function TRange.Construct(const rStart, rStop: Integer): TRange; overload;
begin
  Result.start := rStart;
  Result.stop := rStop;
end;

{==============================================================================]
  <Construct>
  @action: Constructs TRange with rVal.
  @note: rVal will be used for both start and stop.
[==============================================================================}
class function TRange.Construct(const rVal: Integer): TRange; overload;
begin
  Result.start := rVal;
  Result.stop := rVal;
end;

{==============================================================================]
  <Construct>
  @action: Constructs TRange with 0's.
  @note: 0 will be used for both start and stop.
[==============================================================================}
class function TRange.Construct: TRange; overload;
begin
  Result.start := 0;
  Result.stop := 0;
end;

{==============================================================================]
  <Construct>
  @action: Constructs a TRange whose bounds span all values in the given integer array.
  @note: The oAscending flag only controls comparison direction; the resulting range
         always represents the minimum and maximum values in the array.
[==============================================================================}
class function TRange.Construct(const arr: TIntegerArray; const oAscending: Boolean = True): TRange; overload;
var
  i: Integer;
begin
  if (System.Length(arr) = 0) then
    Exit(TRange.Null);
  Result.start := arr[0];
  Result.stop := arr[0];
  case oAscending of
    True:
    for i := 1 to High(arr) do
      if (arr[i] < Result.start) then
        Result.start := arr[i]
      else if (arr[i] > Result.stop) then
        Result.stop := arr[i];
    False:
    for i := 1 to High(arr) do
      if (arr[i] < Result.stop) then
        Result.stop := arr[i]
      else if (arr[i] > Result.start) then
        Result.start := arr[i];
  end;
end; 

{==============================================================================]
  <Create>
  @action: Create a TRange with start and stop
  @note: None.
[==============================================================================}
constructor TRange.Create(const rStart, rStop: Integer); overload;
begin
  Self.start := rStart;
  Self.stop := rStop;
end;

{==============================================================================]
  <Create>
  @action: Create a TRange with value
  @note: None.
[==============================================================================}
constructor TRange.Create(const value: Integer); overload;
begin
  Self.Create(value, value);
end;

{==============================================================================]
  <Create>
  @action: Parses a textual range specification and initializes the range
           boundaries from it.
  @note: The input string must contain exactly two integer values separated
         by one of the supported delimiters: "..", "-", ":", or ",".
         Whitespace around the values is ignored.
         An exception is raised if the format is invalid or if either value
         cannot be converted to an integer.
[==============================================================================}
constructor TRange.Create(const data: string); overload;
var
  p: TStringArray;
  s: string;
begin
  if (Pos('..', data) > 0) then
    s := '..'
  else if (Pos('-', data) > 0) then
    s := '-'
  else if (Pos(':', data) > 0) then
    s := ':'
  else if (Pos(',', data) > 0) then
    s := ','
  else
    raise Exception.Create('Invalid range format');
  p := SplitString(data, s);
  if (System.Length(p) <> 2) then
    raise Exception.Create('Invalid range format');
  start := StrToInt(Trim(p[0]));
  stop  := StrToInt(Trim(p[1]));
end;

{==============================================================================]
  <Create>
  @action: Create a TRange with other TRange
  @note: None.
[==============================================================================}
constructor TRange.Create(const other: TRange); overload;
begin
  Self.start := other.start;
  Self.stop := other.stop;
end;

{==============================================================================]
  <Create>
  @action: TRange 0..0.
  @note: None.
[==============================================================================}
function TRangeHelper.Create: TRange; overload;
begin
  Self.start := 0;
  Self.stop := 0;
  Result := Self;
end;

{==============================================================================]
  <Create>
  @action: Initializes the range to span the minimum and maximum values of the
           given integer array.
  @note: If the array is empty, the constructor exits without modifying Self.
         The range is computed by scanning elements in pairs for efficiency,
         ensuring all values contribute to the final bounds.
         If the array contains a single element, the range is [value, value].
         After construction, if rAscending is True, the range is normalized to
         [min(arr), max(arr)]; otherwise it remains in reverse order
         [max(arr), min(arr)].
[==============================================================================}
constructor TRange.Create(const arr: TIntegerArray; const rAscending: Boolean = True); overload;
var
  i, h: Integer;
begin
  h := High(arr);
  if (h = -1) then
    Exit;
  Self := TRange.Construct(arr[0], arr[0]);
  i := -1;
  while (i.Increment(2) < h) do
  case (arr[i] < arr[i + 1]) of
    True:
    begin
      if (arr[i] < Self.start) then
        Self.start := arr[i];
      if (arr[i + 1] > Self.stop) then
        Self.stop := arr[i + 1];
    end;
    False:
    begin
      if (arr[i + 1] < Self.start) then
        Self.start := arr[i + 1];
      if (arr[i] > Self.stop) then
        Self.stop := arr[i];
    end;
  end;
  if (i = h) then
    if (arr[i] < Self.start) then
      Self.start := arr[i]
    else if (arr[i] > Self.stop) then
      Self.stop := arr[i];
  if not rAscending then
    Self.Reverse;
end;

{==============================================================================]
  <Descending>
  @action: Creates a range whose start value is greater than or equal to its stop
           value, regardless of the order of the input parameters.
  @note: The larger of A and B is assigned to start, and the smaller to stop.
         This guarantees a descending (non-increasing) range.
[==============================================================================}
class function TRange.Descending(const A, B: Integer): TRange; overload;
begin
  Result.start := Max(A, B);
  Result.stop := Min(A, B);
end;

{==============================================================================]
  <From>
  @action: Creates a new TRange starting at the given value and extending by the
           specified step count.
  @note: The stop value is computed as startingVal + stepCount. A stepCount of zero
         produces a single-point range where start = stop.
[==============================================================================}
class function TRange.From(const startingVal: Integer; const stepCount: Integer = 0): TRange; overload;
begin
  Result.start := startingVal;
  Result.stop := (startingVal + stepCount);
end;

{==============================================================================]
  <From>
  @action: Creates a range that spans the minimum and maximum values in the
           given integer array.
  @note: If the array is empty, an uninitialized range is returned.
         If the array contains a single element, the range is [value, value].
         If rAscending is True, the resulting range is ordered as
         [min(arr), max(arr)]; otherwise the bounds are reversed to
         [max(arr), min(arr)].
[==============================================================================}
class function TRange.From(const arr: TIntegerArray; const rAscending: Boolean = True): TRange; overload;
var
  h, i: Integer;
begin
  h := High(arr);
  case h of
    -1: Exit;
    0: Exit(TRange.Construct(arr[0], arr[0]));
  end;
  Result.Create(arr[0], arr[0]);
  case rAscending of
    True:
    for i := 1 to h do
      if (arr[i] < Result.start) then
        Result.start := arr[i]
      else if (arr[i] > Result.stop) then
        Result.stop := arr[i];
    False:
    for i := 1 to h do
      if (arr[i] < Result.stop) then
        Result.stop := arr[i]
      else if (arr[i] > Result.start) then
        Result.start := arr[i];
  end;
end;

{==============================================================================]
  <Form>
  @action: Creates a range centered at a given value using the specified radius.
  @note: If radius < 1, the resulting range is a single-point range [val, val].
         If rAscending is True, the range is [val - radius, val + radius];
         otherwise the bounds are reversed to [val + radius, val - radius].
[==============================================================================}
class function TRange.Form(const val: Integer; const radius: Integer = 0; const rAscending: Boolean = True): TRange; overload;
begin
  if (radius < 1) then
    Result.Create(val, val)
  else if rAscending then
    Result.Create((val - radius), (val + radius))
  else
    Result.Create((val + radius), (val - radius));
end;

{==============================================================================]
  <Form>
  @action: Creates a range spanning the minimum and maximum values of the
           given integer array.
  @note: If the array is empty, the function exits without modifying Result.
         If the array contains a single element, the range is [value, value].
         If rAscending is True, the range is [Minimum(arr), Maximum(arr)];
         otherwise the bounds are reversed to [Maximum(arr), Minimum(arr)].
[==============================================================================}
class function TRange.Form(const arr: TIntegerArray; const rAscending: Boolean = True): TRange; overload;
begin
  case arr.Length of
    0: Exit;
    1: Exit(TRange.Construct(arr[0], arr[0]));
  end;
  if rAscending then
    Result.Create(arr.Minimum, arr.Maximum)
  else
    Result.Create(arr.Maximum, arr.Minimum);
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TRange with the specified start and stop values.
           Also returns the initialized record so it can be assigned in-line.
  @note: Useful for initializing a TRange instance and simultaneously returning it
         for assignment. Example: a := b.Init(1, 10);
[==============================================================================}
function TRange.Init(const rStart, rStop: Integer): TRange; overload;
begin
  Self.start := rStart;
  Self.stop := rStop;
  Result.start := rStart;
  Result.stop := rStop;
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TRange as a copy of another TRange.
           Also returns the copied record.
  @note: Useful for copying values from an existing TRange while allowing in-line assignment.
         Example: a := b.Init(c);
[==============================================================================}
function TRange.Init(const r: TRange): TRange; overload;
begin
  Self := r;
  Result := r;
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TRange with both start and stop set to the same value.
           Also returns the initialized record.
  @note: The parameter has a default of 0, allowing zero-initialization.
         Example: a := b.Init; or a := b.Init(5);
[==============================================================================}
function TRange.Init(const val: Integer = 0): TRange; overload;
begin
  Self.start := val;
  Self.stop := val;
  Result.start := val;
  Result.stop := val;
end;

{==============================================================================]
  <Make>
  @action: Initializes the current TRange instance using the given bounds and
           returns the resulting range size.
  @note: This method assigns the range as Starting(A).Stopping(B), overwriting
         the current instance. The return value is the Size of the resulting
         range.
[==============================================================================}
function TRange.Make(const A: Integer = 0; const B: Integer = 0): Integer; overload;
begin
  Self := TRange.From(A).Stopping(B);
  Result := Self.Size;
end;

{==============================================================================]
  <Null>
  @action: Returns a special "null" or empty range, represented by both start and stop
           being set to the specified sentinel value.
  @param: value - Optional integer to use as the sentinel for an empty range. Defaults
                  to Low(Integer) (-2147483648 for 32-bit integers).
  @note:   This function is typically used to represent non-overlapping ranges or
           invalid ranges in operations like intersection. It provides a consistent
           marker for "empty" ranges.
[==============================================================================}
class function TRange.Null(const value: Integer = -2147483648): TRange; overload;
begin
  Result := Range(value, value);
end;

{==============================================================================]
  <Unbounded>
  @action: Constructs a TRange representing the full span of Integer values.
  @note: The oAscending flag determines the ordering of start and stop:
         ascending yields (Low(Integer), High(Integer));
         descending yields (High(Integer), Low(Integer)).
[==============================================================================}
class function TRange.Unbounded(const oAscending: Boolean = True): TRange; overload;
begin
  if oAscending then
    Result.Create(Low(Integer), High(Integer))
  else
    Result.Create(High(Integer), Low(Integer));
end;

{==============================================================================]
  <Range>
  @action: Constructs and returns a TRange whose start and stop values are set to
           rStart and rStop respectively. No normalization or validation is
           performed.
  @note: The resulting range preserves the specified ordering. If rStart > rStop,
         the function returns a descending range.
[==============================================================================}
function Range(const rStart, rStop: Integer): TRange; overload;
begin
  Result.start := rStart;
  Result.stop := rStop;
end;

{==============================================================================]
  <Range>
  @action: Constructs and returns a TRange representing a single-value range,
           with both start and stop initialized to val.
  @note: This overload is intended for convenience when creating point ranges.
         The default value (0) is used when no argument is provided.
[==============================================================================}
function Range(const val: Integer = 0): TRange; overload;
begin
  Result.start := val;
  Result.stop := val;
end;

{==============================================================================]
  <Range>
  @action: Returns a range spanning the minimum and maximum values of the
           given integer array.
  @note: If the array is empty, the function exits without assigning Result.
         If the array contains a single element, the range is [value, value].
         The bounds are determined via a linear scan of the array.
         If rAscending is True, the range is [min(arr), max(arr)];
         otherwise the bounds are reversed to [max(arr), min(arr)].
[==============================================================================}
function Range(const arr: TIntegerArray; const rAscending: Boolean = True): TRange; overload;
var
  p: PInteger;
  i, l, h: Integer;
begin
  case arr.Length of
    0: Exit;
    1: Exit(TRange.Construct(arr[0], arr[0]));
  end;
  p := @arr[0];
  l := p^;
  h := p^;
  for i := 1 to High(arr) do
  begin
    Inc(p);
    if (p^ < l) then
      l := p^
    else if (p^ > h) then
      h := p^;
  end;
  if rAscending then
    Result .Create(l, h)
  else
    Result.Create(h, l);
end;

{==============================================================================]
  <R>
  @action: Constructs and returns a TRange whose start and stop values are set to
           startVal and stopVal respectively. No normalization or validation is
           performed.
  @note: The resulting range preserves the specified ordering. If startVal > stopVal,
         the function returns a descending range.
[==============================================================================}
function R(const startVal, stopVal: Integer): TRange; overload;
begin
  Result.start := startVal;
  Result.stop := stopVal;
end;

{==============================================================================]
  <R>
  @action: Constructs and returns a TRange representing a single-value range,
           with both start and stop initialized to val.
  @note: This overload is intended for convenience when creating point ranges.
         The default value (0) is used when no argument is provided.
[==============================================================================}
function R(const val: Integer = 0): TRange; overload;
begin
  Result.start := val;
  Result.stop := val;
end;

{==============================================================================]
  <R>
  @action: Returns a range spanning the minimum and maximum values of the
           given integer array.
  @note: If the array is empty, the function exits without assigning Result.
         The bounds are initialized to extreme integer limits and refined
         through a linear scan.
         If rAscending is True, the range is [min(arr), max(arr)];
         otherwise the bounds are reversed to [max(arr), min(arr)].
[==============================================================================}
function R(const arr: TIntegerArray; const rAscending: Boolean = True): TRange; overload;
var
  i: Integer;
begin
  if arr.Empty then
    Exit;
  Result.start := IfThen(rAscending, High(Integer), Low(Integer));
  Result.stop := IfThen(rAscending, Low(Integer), High(Integer));
  case rAscending of
    True:
    for i := 0 to High(arr) do
    begin
      Result.start := Min(arr[i], Result.start);
	  Result.stop := Max(arr[i], Result.stop);
	end;
	False:
    for i := 0 to High(arr) do
    begin
      Result.stop := Min(arr[i], Result.stop);
	  Result.start := Max(arr[i], Result.start);
	end;
  end;
end;
{$ENDIF}
