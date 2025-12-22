{$DEFINE TRange}{$I ../Defines.inc}

{$IFDEF TYPES}
TRangeEnumerator = record
private
  FCurrent, FStop, FStep: Integer;
  FFirst: Boolean;
public
  constructor Init(const AStart, AStop: Integer);
  function MoveNext: Boolean;
  property Current: Integer read FCurrent;
end;
TRange = record
  start, stop: Integer;
  function GetEnumerator: TRangeEnumerator;
  {$I ./TRange.pph}
  function Grab: TRange; 
  
  function Reserve: TIntegerArray; overload; 
  function Reserve(var aRange: TIntegerArray): Integer; overload; 
  
  function Frame(var rSize: Integer): TRange; overload; 
  function Frame: TRange; overload; 
  	
  
  
   
  
  function IDs: TIntegerArray; overload; 
  function IDs(const dValue: Integer): Integer; overload; 
  function IDs(const dVals: TIntegerArray): TIntegerArray; overload;  
   
  function Extend(const val: Integer): Boolean; 
  function Offset(const sDelta: Integer): TRange; 
   
  function Reversed: TRange; 
  function Reverse: Boolean; 
   
  
  function Absorb(const val: Integer): Boolean; overload; 
  function Include(const val: Integer): TRange; overload; 
  
  
  function Direction: Integer; 
  function Orientation: Integer;
  function Signum: Integer;
  function Slope: Integer;	
  function Radius: Integer; overload; 
  function Rad: Integer; overload; 
  function Radiar: Integer; overload; 
   
  function Sum: Int64; 
  function Summation: Int64; 
  function Total: Int64; 
  
  function Centered(const rCenter: Integer): TRange; overload; 
  function Shift(const N: Integer = 1): TRange; overload; 
  function Shifted(const N: Integer = 1): TRange; overload; 
  function Back(const N: Integer = 1): TRange; overload; 
  function Backed(const N: Integer = 1): TRange; overload; 
  function Increase(const N: Integer = 1): TRange; overload; 
  function Decrease(const N: Integer = 1): TRange; overload; 
  function Increment(const N: Integer = 1): TRange; overload; 
  function Decrement(const N: Integer = 1): TRange; overload; 
  function Modify(const mStart, mStop: Integer): TRange; overload; 
  function Modified(const mStart, mStop: Integer): TRange; overload; 
  function Contract(const N: Integer = 1): TRange; overload; 
  function Contracted(const N: Integer = 1): TRange; overload; 
  function Expand(const N: Integer = 1): TRange; overload; 
  function Expanded(const N: Integer = 1): TRange; overload;
  
  function CompareSize(const target: TRange): Integer;
  class function CompareSizeAscending(const A, B: TRange): Integer; static;
  class function CompareSizeDescending(const A, B: TRange): Integer; static;
end;
{$I ../Core.inc}
_TRange = class
public
  class function Create(const rStart, rStop: Integer): TRange; overload; 
  class function Create(const value: Integer = 0): TRange; overload; 
end;
{$ENDIF}

{$IFDEF OPERATORS}
operator +(const a, b: TRange): TRange;
operator -(const a, b: TRange): TRange;
operator =(const a, b: TRange): Boolean;
operator <>(const a, b: TRange): Boolean;

operator in(const I: Integer; const R: TRange): Boolean;
{$ENDIF}

{$IFDEF HELPERS}
TRangeHelper = type helper for TRange
  {$I ../Core.inc}
  {$I ./TRange.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ../Core.inc}
{$I ./TRange.pph}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <+>
  @action: Computes the union of two integer ranges. The result spans from the
           smallest start value of either input range to the largest stop value.
  @note:   Both ranges are internally normalized to ascending order before the
           union is calculated. Descending ranges are fully supported.
[==============================================================================}
operator +(const a, b: TRange): TRange;
var
  x, y: TRange;
begin
  x := a.Normalize;
  y := b.Normalize;
  Result.Create(Min(x.start, y.start), Max(x.stop,  y.stop));
end;

{==============================================================================]
  <->
  @action: Computes the intersection of two integer ranges. If the ranges
           overlap, the result contains the overlapping interval. If they do
           not overlap, the function returns an empty range marker.
  @note:   Both ranges are normalized internally to ascending order before the
           intersection is computed. A non-overlapping result is represented
           by start = stop = Low(Integer).
[==============================================================================}
operator -(const a, b: TRange): TRange;
var
  x, y: TRange;
begin
  x := a.Normalize;
  y := b.Normalize;
  if ((x.stop < y.start) or (y.stop < x.start)) then
    Exit(TRange.Null);
  Result.start := Max(x.start, y.start);
  Result.stop := Min(x.stop, y.stop);
end;

{==============================================================================]
  <=>
  @action: Compares two ranges for exact equality. Returns True when both start and stop
           values are identical in both ranges.
  @note: The comparison is structural; ordering is not normalized. A range (3, 7) is not
         considered equal to a reversed range (7, 3).
[==============================================================================}
operator =(const a, b: TRange): Boolean;
begin
  Result := ((a.start = b.start) and (a.stop = b.stop));
end;

{==============================================================================]
  <<>>
  @action: Compares two ranges for inequality. Returns True when either start or stop
           differs between the two ranges.
  @note: This is the logical negation of the equality operator. Like '=', the test is
         sensitive to value order and does not perform normalization.
[==============================================================================}
operator <>(const a, b: TRange): Boolean;
begin
  Result := not ((a.start = b.start) and (a.stop = b.stop));
end;

{==============================================================================]
  <in>
  @action: Evaluates whether the given integer I lies within the bounds of the
           specified range R. Returns True when I is contained inside R according
           to the range's containment rules.
  @note: The containment test follows TRange.Contains, including its handling of
         ascending or descending ranges. No normalization is performed unless
         Contains does so internally.
[==============================================================================}
operator in(const I: Integer; const R: TRange): Boolean;
begin
  Result := R.Contains(I);
end;

constructor TRangeEnumerator.Init(const AStart, AStop: Integer);
begin
  FStop := AStop;
  if (AStart <= AStop) then
    FStep := 1
  else
    FStep := -1;
  FCurrent := (AStart - FStep);
  FFirst := True;
end;

function TRangeEnumerator.MoveNext: Boolean;
begin
  Inc(FCurrent, FStep);
  Result := ((FStep > 0) and (FCurrent <= FStop) or (FStep < 0) and (FCurrent >= FStop));
end;

{==============================================================================]
  <GetEnumerator>
  @action: Creates and returns an enumerator that iterates through all integer
           values contained in the range, following the iteration rules defined
           by TRangeEnumerator.
  @note: The iteration order and behavior (ascending, descending, inclusive, or
         normalized) are determined entirely by TRangeEnumerator.Init. This
         function performs no normalization and passes the range endpoints
         exactly as stored.
[==============================================================================}
function TRange.GetEnumerator: TRangeEnumerator;
begin
  Result.Init(start, stop);
end;

{==============================================================================]
  <Grab>
  @action: Returns TRange with range, swaps range.stop and range.start if they are in reversed order.
  @note: None.
[==============================================================================}
function TRange.Grab: TRange;
begin
  Result := IfThen(Self.Descending, Result.Create(Self.stop, Self.start), Self);
end;

{==============================================================================]
  <Frame>
  @action Returns a TRange covering the full extent of this instance,
          starting at 0 and ending at Size - 1.
  @note   None.
[==============================================================================}
function TRange.Frame(var rSize: Integer): TRange; overload;
begin
  rSize := Self.Size;
  Result := Range(0, (rSize - 1));
end;

{==============================================================================]
  <Frame>
  @action Returns a TRange covering the full extent of this instance,
          starting at 0 and ending at Size - 1.
  @note   None.
[==============================================================================}
function TRange.Frame: TRange; overload;
begin
  Result := Range(0, (Self.Size - 1));
end;

{==============================================================================]
  <IDs>
  @action: Returns TRange indexes.
  @note: None.
[==============================================================================}
function TRange.IDs: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Area);
  for i := 0 to High(Result) do
    Result[i] := i;
end;

{==============================================================================]
  <IDs>
  @action: Returns TRange index by TRange value.
  @note: Returns -2147483648 if dValue does not exist in TRange.
[==============================================================================}
function TRange.IDs(const dValue: Integer): Integer; overload;
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
  <IDs>
  @action: Returns TRange index by TRange value.
  @note: Returns -2147483648 if dValue does not exist in TRange.
[==============================================================================}
function TRange.IDs(const dVals: TIntegerArray): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, (High(dVals) + 1));
  for i := 0 to High(dVals) do
    Result[i] := Self.IDs(dVals[i]);
end;

{==============================================================================]
  <Extend>
  @action: Returns true TRange is extended with val (val is not yet in range)
  @note: None.
[==============================================================================}
function TRange.Extend(const val: Integer): Boolean;
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
  <Offset>
  @action: Returns shift of range r by delta.
  @note: None.
[==============================================================================}
function TRange.Offset(const sDelta: Integer): TRange;
begin
  Result.Create((Self.start + sDelta), (Self.stop + sDelta));
end;

{==============================================================================]
  <Reversed>
  @action: Returns reversed range.
  @note: None.
[==============================================================================}
function TRange.Reversed: TRange;
begin
  Result.start := Self.stop;
  Result.stop := Self.start;
end;

{==============================================================================]
  <Reverse>
  @action: Reverses range, returns True if range was reversed.
  @note: None.
[==============================================================================}
function TRange.Reverse: Boolean;
begin
  Result := Self.Plural;
  if Result then
    Swap(Self.start, Self.stop);
end;

{==============================================================================]
  <Include>
  @action: Expands the range to include the given value while preserving ascending/descending order.
  @note: If the value is already inside the range, the range remains unchanged.
[==============================================================================}
function TRange.Include(const val: Integer): TRange; overload;
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
  <Absorb>
  @action: Expands the range to include the given value while preserving ascending/descending order.
  @note: If the value is already inside the range, the range remains unchanged.
         Returns true if value was added in.
[==============================================================================}
function TRange.Absorb(const val: Integer): Boolean; overload;
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
  <Create>
  @action: TRange 0..0.
  @note: None.
[==============================================================================}
function TRangeHelper.Create: TRange;
begin
  Self.start := 0;
  Self.stop := 0;
  Result := Self;
end;

{==============================================================================]
  <Direction>
  @action: Returns the orientation of the range.
  @note: 1  => descending (stop > start)
        -1  => ascending  (start > stop)
         0  => degenerate (start = stop)
[==============================================================================}
function TRange.Direction: Integer;
begin
  Result := Sign(Self.Delta);
end;

{==============================================================================]
  <Signum>
  @action: Returns the directional sign of the range. 
           +1 if the range is ascending (stop > start), 
           -1 if descending (stop < start), 
           0 if start = stop.
  @note: Useful for determining the trend or direction of the range without
         caring about the magnitude. Does not include endpoints count.
[==============================================================================}
function TRange.Signum: Integer;
begin
  if (Self.start = Self.stop) then
    Result := 0
  else
    Result := ((Self.stop - Self.start) div Abs(Self.start - Self.stop));
end;

{==============================================================================]
  <Orientation>
  @action: Returns +1 if the range is ascending or degenerate (Stop >= Start),
           and -1 if the range is descending (Stop < Start).
  @note: Useful for determining iteration direction or orientation of the range.
[==============================================================================}
function TRange.Orientation: Integer;
begin
  Result := IfThen((Self.Stop < Self.Start), -1, 1);
end;

{==============================================================================]
  <Slope>
  @action: Returns the slope (direction) of the range.
           +1 if the range is ascending (stop > start),
           -1 if descending (stop < start),
           0 if start = stop.
  @note: Useful for determining the trend of the range without considering magnitude.
         Equivalent to Signum in behavior; purely indicates direction.
[==============================================================================}
function TRange.Slope: Integer;
begin
  if (Self.start = Self.stop) then
    Result := 0
  else
    if (Self.stop > Self.start) then
      Result := 1
    else
      Result := -1;
end;

{==============================================================================]
  <Radius>
  @action: Returns half the total span (distance) between Start and Stop.
  @note: Equivalent to (RangeLength / 2); independent of which value is greater.
[==============================================================================}
function TRange.Radius: Integer; overload;
begin
  Result := ((Self.Maximum - Self.Minimum) div 2);
end;

{==============================================================================]
  <Rad>
  @action: Returns the half-length (radius) of the range as an integer value.
  @note: Computed as Abs(Stop - Start) shr 1; equivalent to (|Stop - Start| div 2).
[==============================================================================}
function TRange.Rad: Integer; overload;
begin
  Result := (Abs(Self.stop - Self.start) shr 1);
end;

{==============================================================================]
  <Radiar>
  @action: Returns half the absolute distance between Start and Stop, rounded to the nearest integer.
  @note: Computed as Round(Abs(Stop - Start) * 0.5). Useful when a midpoint-to-edge distance is needed
         and rounding is preferred over truncation. Order of Start and Stop does not matter.
[==============================================================================}
function TRange.Radiar: Integer; overload;
begin
  Result := Round(Abs(Self.stop - Self.start) * 0.5);
end;

{==============================================================================]
  <Sum>
  @action: Returns the sum of all TRange values (start..stop)
  @note: None
[==============================================================================}
function TRange.Sum: Int64;
var
  a, b: Int64;
begin
  a := Min(Self.start, Self.stop);
  b := Max(Self.start, Self.stop);
  Result := ((((b - a) + 1) * (a + b)) div 2);
end;

{==============================================================================]
  <Summation>
  @action: Returns the sum of all TRange values (start..stop)
  @note: None
[==============================================================================}
function TRange.Summation: Int64;
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
  <Total>
  @action: Returns the sum of all TRange values (start..stop)
  @note: None
[==============================================================================}
function TRange.Total: Int64;
begin
  if Self.Descending then
    Result := (((Int64(Self.start) * (Self.start + 1)) div 2) - ((Int64(Self.stop - 1) * Self.stop) div 2))
  else
    Result := (((Int64(Self.stop) * (Self.stop + 1)) div 2) - ((Int64(Self.start - 1) * Self.start) div 2));
end;

{==============================================================================]
  <Reserve>
  @action: Allocate an integer array sized to fit the full range.
  @note: The array is preallocated with the correct length but is not filled 
         with values from start..stop. Elements are default-initialized to 0.
[==============================================================================}
function TRange.Reserve: TIntegerArray; overload;
begin
  SetLength(Result, Self.Size);
end;

{==============================================================================]
  <Reserve>
  @action: Allocate an integer array sized to fit the full range.
  @note: The array is preallocated with the correct length but is not filled 
         with values from start..stop. Elements are default-initialized to 0.
[==============================================================================}
function TRange.Reserve(var aRange: TIntegerArray): Integer; overload;
begin
  Result := Self.Size;
  SetLength(aRange, Result);
end;

{==============================================================================]
  <Centered>
  @action: Returns a new TRange that has the same length as Self but is
           repositioned so that its midpoint equals the specified Center value.
           Self remains unchanged.
  @note:   Direction-aware; preserves ascending or descending order.
           Useful for geometric or data range realignment.
[==============================================================================}
function TRange.Centered(const rCenter: Integer): TRange; overload;
var
  h: Integer;
begin
  h := Self.Half;
  if Self.Ascending then
    Result.Create((rCenter - h), (rCenter + h))
  else
    Result.Create((rCenter + h), (rCenter - h));
end;

{==============================================================================]
  <Shift>
  @action: Adds the given offset N to both Start and Stop of the range, 
           modifying Self in place. Returns a copy of the original range 
           before the shift.
  @note:   Useful when you need the previous state while mutating the range.
[==============================================================================}
function TRange.Shift(const N: Integer = 1): TRange; overload;
begin
  Result := Self;
  Inc(Self.start, N);
  Inc(Self.stop, N);
end;

{==============================================================================]
  <Shifted>
  @action: Returns a new TRange offset N by the given value, without modifying Self.
  @note:   Functional style; Self remains unchanged. Can be used for expression-style 
           or fluent programming.
[==============================================================================}
function TRange.Shifted(const N: Integer = 1): TRange; overload;
begin
  Result.start := (Self.start + N);
  Result.stop := (Self.stop + N);
end;

{==============================================================================]
  <Back>
  @action: Subtracts the given offset N from both Start and Stop of the range,
           modifying Self in place. Returns a copy of the original range 
           before the backward shift.
  @note:   Default offset = 1. Useful when you need the previous state while 
           moving the range backward.
[==============================================================================}
function TRange.Back(const N: Integer = 1): TRange; overload;
begin
  Result := Self;
  Dec(Self.start, N);
  Dec(Self.stop, N);
end;

{==============================================================================]
  <Backed>
  @action: Returns a new TRange shifted backward by the given offset N, without 
           modifying Self.
  @note:   Default offset = 1. Functional style; Self remains unchanged. Can 
           be used for expression-style or fluent programming.
[==============================================================================}
function TRange.Backed(const N: Integer = 1): TRange; overload;
begin
  Result.start := (Self.start - N);
  Result.stop := (Self.stop - N);
end;

{==============================================================================]
  <Increase>
  @action: Adds the given amount (default = 1) to both Start and Stop of the range,
           modifying Self in place. Returns a copy of the original range 
           before the increase.
  @note:   Useful when you want to capture the previous state while mutating the range forward.
[==============================================================================}
function TRange.Increase(const N: Integer = 1): TRange; overload;
begin
  Result := Self;
  Self.start := (Self.start + N);
  Self.stop := (Self.stop + N);
end;

{==============================================================================]
  <Decrease>
  @action: Subtracts the given amount (default = 1) from both Start and Stop of the range,
           modifying Self in place. Returns a copy of the original range 
           before the decrease.
  @note:   Useful when you want to capture the previous state while mutating the range backward.
[==============================================================================}
function TRange.Decrease(const N: Integer = 1): TRange; overload;
begin
  Result := Self;
  Self.start := (Self.start - N);
  Self.stop := (Self.stop - N);
end;

{==============================================================================]
  <Increment>
  @action: Adds the given amount (default = 1) to both Start and Stop of the range,
           modifying Self in place. Returns the updated range after the increase.
  @note:   Functional-style usage: Self is modified, and the returned range reflects the new values.
[==============================================================================}
function TRange.Increment(const N: Integer = 1): TRange; overload;
begin
  Self.start := (Self.start + N);
  Self.stop := (Self.stop + N);
  Result := Self;
end;

{==============================================================================]
  <Decrement>
  @action: Subtracts the given amount (default = 1) from both Start and Stop of the range,
           modifying Self in place. Returns the updated range after the decrease.
  @note:   Functional-style usage: Self is modified, and the returned range reflects the new values.
[==============================================================================}
function TRange.Decrement(const N: Integer = 1): TRange; overload;
begin
  Self.start := (Self.start - N);
  Self.stop := (Self.stop - N);
  Result := Self;
end;

{==============================================================================]
  <Modify>
  @action: Adds the given mStart and mStop offsets to the current range bounds,
           modifying Self in place. Returns the original range before modification.
  @note:   Used internally by operations like Contract or Expand for direct bound
           adjustment while preserving the previous state.
[==============================================================================}
function TRange.Modify(const mStart, mStop: Integer): TRange; overload;
begin
  Result := Self;
  Self.start := (Self.start + mStart);
  Self.stop := (Self.stop + mStop);
end;

{==============================================================================]
  <Modified>
  @action: Returns a new TRange with Start and Stop adjusted by the specified
           mStart and mStop offsets, without modifying Self.
  @note:   Functional version of Modify. Useful for expression-style or
           fluent programming where immutability is preferred.
[==============================================================================}
function TRange.Modified(const mStart, mStop: Integer): TRange; overload;
begin
  Result.start := (Self.start + mStart);
  Result.stop := (Self.stop + mStop);
end;

{==============================================================================]
  <Contract>
  @action: Moves both range bounds toward each other by the given amount N,
           effectively reducing the range span. Modifies Self in place and
           returns the original (pre-contracted) range.
  @note:   Direction-aware; contracts correctly for both ascending and
           descending ranges.
[==============================================================================}
function TRange.Contract(const N: Integer = 1): TRange; overload;
begin
  Result := Self;
  if Self.Ascending then
    Self.Modify(N, -N)
  else
    Self.Modify(-N, N);
end;

{==============================================================================]
  <Contracted>
  @action: Returns a new TRange contracted by the given amount N without
           modifying Self.
  @note:   Functional style version of Contract; preserves Self and is safe
           for use in expressions or chainable operations.
[==============================================================================}
function TRange.Contracted(const N: Integer = 1): TRange; overload;
begin
  if Self.Ascending then
    Result.Create((Self.start + N), (Self.stop - N))
  else
    Result.Create((Self.start - N), (Self.stop + N));
end;

{==============================================================================]
  <Expand>
  @action: Moves both bounds of the range away from each other by the given
           amount N, effectively increasing the span of the range. Modifies Self
           in place and returns the original (pre-expanded) range.
  @note:   Direction-aware; expands correctly for both ascending and descending
           ranges. Used when the current range should grow outward.
[==============================================================================}
function TRange.Expand(const N: Integer = 1): TRange; overload;
begin
  Result := Self;
  if Self.Ascending then
    Self.Modify(-N, N)
  else
    Self.Modify(N, -N);
end;

{==============================================================================]
  <Expanded>
  @action: Returns a new TRange expanded by the given amount N without modifying
           Self.
  @note:   Functional version of Expand. Preserves the original range and can
           be used in expression-style or chainable operations. Handles both
           ascending and descending ranges.
[==============================================================================}
function TRange.Expanded(const N: Integer = 1): TRange; overload;
begin
  if Self.Ascending then
    Result.Create((Self.start - N), (Self.stop + N))
  else
    Result.Create((Self.start + N), (Self.stop - N));
end;

{==============================================================================]
  <CompareSize>
  @action: Compares the size of this TRange instance with another TRange.
           Returns a positive value if Self is larger, negative if smaller,
           and zero if they are equal in size.
  @note: This is an instance method; it requires a TRange object to call.
[==============================================================================}
function TRange.CompareSize(const target: TRange): Integer;
begin
  Result := (Self.Size - target.Size);
end;

{==============================================================================]
  <CompareSizeAscending>
  @action: Compares two TRanges for ascending size order.
           Returns a negative value if A is smaller, positive if A is larger,
           zero if sizes are equal. Suitable for sorting in ascending order.
  @note: Declared as a static class function so it can be passed directly
         to a procedural type such as TCompare<TRange>.
[==============================================================================}
class function TRange.CompareSizeAscending(const A, B: TRange): Integer;
begin
  Result := A.CompareSize(B);
end;

{==============================================================================]
  <CompareSizeDescending>
  @action: Compares two TRanges for descending size order.
           Returns a negative value if A is larger, positive if A is smaller,
           zero if sizes are equal. Suitable for sorting in descending order.
  @note: Declared as a static class function so it can be passed directly
         to a procedural type such as TCompare<TRange>.
[==============================================================================}
class function TRange.CompareSizeDescending(const A, B: TRange): Integer;
begin
  Result := B.CompareSize(A);
end;

{==============================================================================]
  <Create>
  @action: Creates TPoint using pX, pY 
  @note: function version
[==============================================================================}
class function _TRange.Create(const rStart, rStop: Integer): TRange; overload;
begin
  Result.start := rStart;
  Result.stop := rStop;
end;

{==============================================================================]
  <Create>
  @action: Creates TPoint using value 
  @note: function version
[==============================================================================}
class function _TRange.Create(const value: Integer = 0): TRange; overload;
begin
  Result := _TRange.Create(value, value);
end;
{$ENDIF}

{$UNDEF TRange}
