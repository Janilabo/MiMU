{$DEFINE TVar := TRange}
{$DEFINE TArr := TRangeArray}
{$DEFINE T2DArr := T2DRangeArray}
{$DEFINE THelper := TRangeHelper}
{$UNDEF Sortable}

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
  constructor Create(const rStart, rStop: Integer); overload;
  constructor Create(const value: Integer); overload;
  class function Construct(const rStart, rStop: Integer): TRange; overload; static;
  class function Null(const value: Integer = -2147483648): TRange; overload; static;
  function Build(const rStart: Integer = 0; const rStop: Integer = 0): Integer; 
  function Init(const rStart, rStop: Integer): TRange; overload; 
  function Init(const r: TRange): TRange; overload; 
  function Init(const val: Integer = 0): TRange; overload; 
  function Singular: Boolean; 
  function Atomic: Boolean; 
  function Plural: Boolean; 
  function Composite: Boolean; 
  function Sorted(const oAscending: Boolean = True): TRange; overload; 
  function Sort(const oAscending: Boolean = True): Boolean; overload; 
  function Ordered(const oAscending: Boolean = True): TRange; overload; 
  function Order(const oAscending: Boolean = True): Boolean; overload; 
  function Asc: TIntegerArray; overload; 
  function Ascend: TRange; 
  function Ascended: TRange; 
  function Ascending: Boolean; 
  function Ascends: Boolean; 
  function Desc: TIntegerArray; overload; 
  function Descend: TRange; 
  function Descended: TRange; 
  function Descending: Boolean; 
  function Descends: Boolean; 
  function Increasing: Boolean; 
  function Decreasing: Boolean; 
  function Growing: Boolean; 
  function Grows: Boolean; 
  function Shrinking: Boolean; 
  function Shrinks: Boolean; 
  function Rising: Boolean; 
  function Rises: Boolean; 
  function Dropping: Boolean; 
  function Drops: Boolean; 
  function Grab: TRange; 
  function Count: Integer; 
  function Area: Integer; 
  function Span: Integer;
  function Sized: Integer; overload;	
  function Size: Integer; overload; 
  function Size(var minVal, maxVal: Integer): Integer; overload; 
  function Length: Integer; overload;
  function Capacity: Integer;
  function Extent: Integer; overload;
  function Reach: Integer; overload;
  function Coverage: Integer; overload;
  function Diameter: Integer; overload;
  function Population: Integer; overload;	
  function Delta: Integer; 
  function Frame(var rSize: Integer): TRange; overload; 
  function Frame: TRange; overload; 
  function Lowest: Integer;  
  function Highest: Integer;
  function Minimum: Integer;	
  function Maximum: Integer;
  function Minima: Integer;
  function Maxima: Integer;
  function Minimal: Integer;	
  function Maximal: Integer;
  function Left: Integer; overload;
  function Right: Integer; overload;
  function First: Integer; overload;
  function Last: Integer; overload;
  function Lower: Integer; overload;
  function Higher: Integer; overload;
  function Bottom: Integer; overload;
  function Top: Integer; overload;	
  function Exceeds(const maxElements: Integer): Boolean; 
  function Insufficient(const minElements: Integer): Boolean; 
  function Digits: TIntegerArray; overload; 
  function Digits(const dIndex: Integer): Integer; overload; 
  function Digits(const dIDs: TIntegerArray): TIntegerArray; overload; 
  function Ints: TIntegerArray; 
  function Values: TIntegerArray; 
  function TIA: TIntegerArray; 
  function Enumerate: TIntegerArray; 
  function Enumerated: TIntegerArray; 
  function Elements: TIntegerArray; 
  function Numbers: TIntegerArray; 
  function Items: TIntegerArray;
  function Sequence: TIntegerArray;
  function IDs: TIntegerArray; overload; 
  function IDs(const dValue: Integer): Integer; overload; 
  function IDs(const dVals: TIntegerArray): TIntegerArray; overload; 
  function ToArray: TIntegerArray; 
  function AsArray: TIntegerArray; overload; 
  function Materialize: TIntegerArray; 
  function Mixed(const mixings: Integer = 1): TIntegerArray; 
  function Shake(const shakes: Integer = 1): TIntegerArray; 
  function Shuffle(const shuffles: Integer = 1): TIntegerArray; 
  function Any: Integer; 
  function Some: TIntegerArray; overload; 
  function Some(const amount: Integer): TIntegerArray; overload; 
  function All: TIntegerArray; overload;
  function Unzip: TIntegerArray; overload; 
  function Unpack: TIntegerArray; overload; 
  function Unwrap: TIntegerArray; overload; 
  function Unfold: TIntegerArray; overload;
  function Zigzag(const zAscending: Boolean = True): TIntegerArray; overload;
  function Normed: TRange; 
  function Norm: TRange; 
  function Normal: TRange;
  function Normally: TRange; 
  function Normalize: TRange; 
  function Normalized: TRange; 
  function MinMax: TRange; overload;
  function MaxMin: TRange; overload;
  function Overlapping(const b: TRange): Boolean; 
  function Overlap(const b: TRange): Boolean; 
  function Intersect(const b: TRange): TRange; overload; 
  function Intersect(const b: TRange; var iZone: TRange): Boolean; overload; 
  function Union(const b: TRange): TRange; overload; 
  function Union(const val: Integer): TRange; overload; 
  function Extend(const val: Integer): Boolean; 
  function Offset(const sDelta: Integer): TRange; 
  function Contains(const x: Integer): Boolean; overload; 
  function Contains(const x: TRange): Boolean; overload;
  function Holds(const val: Integer): Boolean; overload;
  function Holds(const vals: TRange): Boolean; overload;
  function Missing(const val: Integer): Boolean; overload;
  function Missing(const vals: TRange): Boolean; overload;	
  function Above(const target: Integer): Boolean; overload; 
  function Above(const target: TRange): Boolean; overload; 
  function Below(const target: Integer): Boolean; overload; 
  function Below(const target: TRange): Boolean; overload; 
  function Reversed: TRange; 
  function Reverse: Boolean; 
  function Equals(const b: TRange): Boolean; 
  function Differs(const b: TRange): Boolean; 
  function Equal(const b: TRange): Boolean; 
  function Differ(const b: TRange): Boolean; 
  function Clamp(const zone: TRange): TRange; overload; 
  function ClampMax(const maxValue: Integer): TRange; 
  function ClampMin(const minValue: Integer): TRange; 
  function Restrict(const zone: TRange): Boolean; 
  function RestrictMin(const minValue: Integer): Boolean; 
  function RestrictMax(const maxValue: Integer): Boolean; 
  function Clip(const zone: TRange): TRange; 
  function ClipMin(const minValue: Integer): TRange; 
  function ClipMax(const maxValue: Integer): TRange; 
  function Ensured(const zone: TRange): TRange; overload; 
  function Ensure(const zone: TRange): Boolean; overload; 
  function Absorb(const val: Integer): Boolean; overload; 
  function Include(const val: Integer): TRange; overload; 
  function Neighbor(const b: TRange): Boolean; 
  function Neighbour(const b: TRange): Boolean; 
  function Touch(const b: TRange): Boolean; 
  function Touches(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; 
  function Touching(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; 
  function Distance(const b: TRange): Integer; overload;
  function Distance: Integer; overload;
  function Dist: Integer;
  function Difference: Integer;
  function Diff: Integer;
  function DistHausdorff(const b: TRange): Integer; 
  function Direction: Integer; 
  function Orientation: Integer;
  function Signum: Integer;
  function Slope: Integer;	
  function Magnitude: Integer; 
  function Deficit: Integer; 
  function Digit(const x: Integer): Boolean; inline;
  function Value(const x: Integer): Boolean; inline;
  function Item(const x: Integer): Boolean; inline;
  function Pivot: Integer; 
  function Mean: Double; overload;
  function Medium: Double; overload;
  function MiddleRight: Integer; overload;
  function MiddleLeft: Integer; overload;
  function Middle: Integer;
  function MiddleValue: Double;
  function MiddleVal: Integer; overload;
  function MiddleStep: Integer; overload;
  function MiddleBit: Integer; overload;
  function MidBit: Integer; overload;
  function Mid: Double; 
  function MidValue: Double; 
  function MidVal: Double; 
  function Midpoint(const wStart: Double = 1; const wStop: Double = 1): Double; overload;
  function Average: Double; 
  function Center: Integer; 
  function Central: Integer; inline;
  function Centre: Integer; overload;
  function Centroid: Integer; overload;
  function Core: Integer; overload;
  function Half: Integer; overload; 
  function Halfway: Integer; overload; 
  function Halved: Integer; overload; 
  function Radius: Integer; overload; 
  function Rad: Integer; overload; 
  function Radiar: Integer; overload; 
  function AsStr(const rReversed: Boolean = False): string; overload; 
  function Str(const openRange: string = '['; const closeRange: string = ']'; const glueRange: string = '..'): string;
  function ToStr(const glueRange: string = '..'; const openRange: string = '['; const closeRange: string = ']'): string; 
  function Stringify(const openRange: string = '['; const glueRange: string = '..'; const closeRange: string = ']'): string; 
  function Sum: Int64; 
  function Summation: Int64; 
  function Total: Int64; 
  function Reserve: TIntegerArray; overload; 
  function Reserve(var aRange: TIntegerArray): Integer; overload; 
  function Extract: TIntegerArray; overload; 
  function Extracted: TIntegerArray; overload; 
  function Steps: TIntegerArray; overload; 
  function Recursed: TIntegerArray; overload; 
  function Limit(const val: Integer): Integer; 
  function MinLimit(const val: Integer): Integer; 
  function MaxLimit(const val: Integer): Integer; 
  function Lacks(const x: Integer): Boolean; inline;
  function Outside(const x: Integer): Boolean; inline;
  function Sample(const sSize: Integer): TIntegerArray; overload; 
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
  function Uniform(const val: Integer): Boolean; overload;
  function Uniform: Boolean; overload;
  function Employs(const val: Integer): Boolean;
  function Omits(const val: Integer): Boolean;
  function Even: Boolean; overload;
  function Odd: Boolean; overload;
  function Evens: Integer; overload;
  function Odds: Integer; overload;
  function EvenCount: Integer; overload;
  function OddCount: Integer; overload;
  function Evened: TIntegerArray; overload;
  function Odded: TIntegerArray; overload;
  function Evenz: TIntegerArray; overload;
  function Oddz: TIntegerArray; overload;
  function CompareSize(const target: TRange): Integer;
  class function CompareSizeAscending(const A, B: TRange): Integer; static;
  class function CompareSizeDescending(const A, B: TRange): Integer; static;
end;
TRangeCompare = specialize TCompare<TRange>;
TRangeArray = array of TRange;
T2DRangeArray = array of TRangeArray;
_TRange = class
public
  class function Create(const rStart, rStop: Integer): TRange; overload; 
  class function Create(const value: Integer = 0): TRange; overload; 
end;
{$ENDIF}

{$IFDEF METHODS}
function Range(const rStart, rStop: Integer): TRange; overload; inline;
function Range(const val: Integer = 0): TRange; overload; inline;
{$ENDIF}

{$IFDEF OPERATORS}
operator +(const a, b: TRange): TRange;
operator -(const a, b: TRange): TRange;
operator =(const a, b: TRange): Boolean;
operator <>(const a, b: TRange): Boolean;

operator in(const I: Integer; const R: TRange): Boolean;
{$ENDIF}

{$IFDEF HELPERS}
type
  TRangeHelper = type helper for TRange
    {$I Core.inc}
    function Create: TRange; overload;
    function Distribute(const parts: Integer): TRangeArray;
    function Partition(const size: Integer): TRangeArray;
    function Divide(const size: Integer): TRangeArray;
    function Windows(const target: TRange): TRangeArray; overload;
    function Sectioned(const target: TRange): TRangeArray; overload;
    function Binned(const target: TRange): TRangeArray; overload;
  end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I Core.inc}
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
  <Range>
  @action: Constructs and returns a TRange whose start and stop values are set to
           rStart and rStop respectively. No normalization or validation is
           performed.
  @note: The resulting range preserves the specified ordering. If rStart > rStop,
         the function returns a descending range.
[==============================================================================}
function Range(const rStart, rStop: Integer): TRange; overload; inline;
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
function Range(const val: Integer = 0): TRange; overload; inline;
begin
  Result.start := val;
  Result.stop := val;
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
  <Build>
  @action: Create a TRange with rStart and rStop, using Min and Max for safety.
  @note: None.
[==============================================================================}
function TRange.Build(const rStart: Integer = 0; const rStop: Integer = 0): Integer;
begin
  Self.start := Min(rStart, rStop);
  Self.stop := Max(rStop, rStart);
  Result := (Abs(rStop - rStart) + 1);
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
  <Singular>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRange.Singular: Boolean;
begin
  Result := (Self.start = Self.stop);
end;

{==============================================================================]
  <Atomic>
  @action: Returns true if range start equals stop
  @note: None.
[==============================================================================}
function TRange.Atomic: Boolean;
begin
  Result := ((Self.start - Self.stop) = 0);
end;

{==============================================================================]
  <Plural>
  @action: Returns true if range start does NOT equal to stop
  @note: None.
[==============================================================================}
function TRange.Plural: Boolean;
begin
  Result := (Self.start <> Self.stop);
end;

{==============================================================================]
  <Composite>
  @action: Returns true if range start does NOT equal to stop
  @note: None.
[==============================================================================}
function TRange.Composite: Boolean;
begin
  Result := not (Self.start = Self.stop);
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
  <Ascend>
  @action: Returns ascending TRange of Self.
  @note: None.
[==============================================================================}
function TRange.Ascend: TRange;
begin
  Result.start := Min(Self.start, Self.stop);
  Result.stop := Max(Self.stop, Self.start);
end;

{==============================================================================]
  <Descend>
  @action: Returns descending TRange of Self.
  @note: None.
[==============================================================================}
function TRange.Descend: TRange;
begin
  Result.start := Max(Self.stop, Self.start);
  Result.stop := Min(Self.start, Self.stop);
end;

{==============================================================================]
  <Descended>
  @action: Returns TRange in descending order.
  @note: None.
[==============================================================================}
function TRange.Descended: TRange;
begin
  if (Self.start > Self.stop) then
    Result.Create(Self.start, Self.stop)
  else
    Result.Create(Self.stop, Self.start);
end;

{==============================================================================]
  <Ascended>
  @action: Returns TRange in ascending order.
  @note: None.
[==============================================================================}
function TRange.Ascended: TRange;
begin
  if (Self.stop > Self.start) then
    Result.Create(Self.start, Self.stop)
  else
    Result.Create(Self.stop, Self.start);
end;

{==============================================================================]
  <Ascending>
  @action: Returns true if range start is lower or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Ascending: Boolean;
begin
  Result := (Self.start <= Self.stop);
end;

{==============================================================================]
  <Ascends>
  @action: Returns true if range start is lower or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Ascends: Boolean;
begin
  Result := not (Self.start > Self.stop);
end;

{==============================================================================]
  <Descending>
  @action: Returns true if range start is higher or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Descending: Boolean;
begin
  Result := (Self.start >= Self.stop);
end;

{==============================================================================]
  <Descends>
  @action: Returns true if range start is higher or equal than stop
  @note: Non-strict.
[==============================================================================}
function TRange.Descends: Boolean;
begin
  Result := not (Self.start < Self.stop);
end;

{==============================================================================]
  <Increasing>
  @action: Returns true if range start is lower or equal with stop
  @note: Non-strict.
[==============================================================================}
function TRange.Increasing: Boolean;
begin
  Result := not (Self.start > Self.stop);
end;

{==============================================================================]
  <Decreasing>
  @action: Returns true if range start is higher or equal with stop
  @note: Different logic compared to TRange.Descending!
[==============================================================================}
function TRange.Decreasing: Boolean;
begin
  Result := not (Self.start < Self.stop);
end;

{==============================================================================]
  <Growing>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Growing: Boolean;
begin
  Result := (Self.start < Self.stop);
end;

{==============================================================================]
  <Grows>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Grows: Boolean;
begin
  Result := not (Self.start >= Self.stop);
end;

{==============================================================================]
  <Shrinking>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Shrinking: Boolean;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <Shrinks>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Shrinks: Boolean;
begin
  Result := not (Self.start <= Self.stop);
end;

{==============================================================================]
  <Rising>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Rising: Boolean;
begin
  Result := (Self.start < Self.stop);
end;

{==============================================================================]
  <Rises>
  @action: Returns true if range start is lower or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Rises: Boolean;
begin
  Result := not (Self.start >= Self.stop);
end;

{==============================================================================]
  <Dropping>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Dropping: Boolean;
begin
  Result := (Self.start > Self.stop);
end;

{==============================================================================]
  <Drops>
  @action: Returns true if range start is higher or equal with stop
  @note: Strict.
[==============================================================================}
function TRange.Drops: Boolean;
begin
  Result := not (Self.start <= Self.stop);
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
  <Count>
  @action: Returns count values in the given range.
  @note: None.
[==============================================================================}
function TRange.Count: Integer;
begin
  Result := ((Max(Self.start, Self.stop) - Min(Self.start, Self.stop)) + 1);
end;

{==============================================================================]
  <Diameter>
  @action: Returns area of the given range.
  @note: None.
[==============================================================================}
function TRange.Diameter: Integer; overload;
begin
  Result := ((Self.stop - Self.start) + 1);
  if (Self.stop < Self.start) then
    Result := (-Result + 2);
end;

{==============================================================================]
  <Area>
  @action: Returns area of the given range.
  @note: None.
[==============================================================================}
function TRange.Area: Integer;
begin
  if (Self.start > Self.stop) then
    Result := ((Self.start - Self.stop) + 1)
  else 
    Result := ((Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <Size>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRange.Size: Integer; overload;
begin
  Result := (Abs(Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <Size>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRange.Size(var minVal, maxVal: Integer): Integer; overload;
begin
  minVal := Min(Self.start, Self.stop);
  maxVal := Max(Self.start, Self.stop);
  Result := ((maxVal - minVal) + 1);
end;

{==============================================================================]
  <Sized>
  @action: Returns size of the given range.
  @note: None.
[==============================================================================}
function TRange.Sized: Integer; overload;
begin
  Result := ((Self.Maximum - Self.Minimum) + 1);
end;

{==============================================================================]
  <Length>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.Length: Integer; overload;
begin
  if (Self.start = Self.stop) then
    Result := 1
  else if (Self.stop < Self.start) then
    Result := ((Self.start - Self.stop) + 1)
  else
    Result := ((Self.stop - Self.start) + 1);
end;

{==============================================================================]
  <Capacity>
  @action: Returns length of the given range.
  @note: None.
[==============================================================================}
function TRange.Capacity: Integer;
begin
  Result := (IfThen(Self.Descending, (Self.start - Self.stop), (Self.stop - Self.start)) + 1);
end;

{==============================================================================]
  <Reach>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Reach: Integer; overload;
begin
  Result := (Self.stop - Self.start);
  if (Result < 0) then
    Result := -Result;
  Result := (Result + 1);
end;

{==============================================================================]
  <Extent>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Extent: Integer; overload;
begin
  Result := Succ(Max(Self.start, Self.stop) - Min(Self.start, Self.stop));
end;

{==============================================================================]
  <Reach>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Coverage: Integer; overload;
begin
  case Self.start.Compare(Self.stop) of
    0: Result := 1;
	-1: Result := ((Self.stop - Self.start) + 1);
	1: Result := ((Self.start - Self.stop) + 1);
  end;
end;

{==============================================================================]
  <Population>
  @action: Returns the size of TRange.
  @note: Alternative.
[==============================================================================}
function TRange.Population: Integer; overload;
begin
  Result := ((Self.MinMax.stop - Self.MinMax.start) + 1);
end;

{==============================================================================]
  <Span>
  @action: Returns span of the given range.
  @note: None.
[==============================================================================}
function TRange.Span: Integer;
begin
  Result := Abs(Self.stop - Self.start);
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
  <Highest>
  @action: Returns maximum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Highest: Integer;
begin
  Result := Max(Self.stop, Self.start);
end;

{==============================================================================]
  <Lowest>
  @action: Returns minimum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Lowest: Integer;
begin
  Result := Min(Self.start, Self.stop);
end;

{==============================================================================]
  <Maximum>
  @action: Returns maximum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Maximum: Integer;
begin
  if (Self.start < Self.stop) then
    Result := Self.stop
  else
    Result := Self.start;
end;

{==============================================================================]
  <Minimum>
  @action: Returns minimum value of the given range.
  @note: None.
[==============================================================================}
function TRange.Minimum: Integer;
begin
  if (Self.stop > Self.start) then
    Result := Self.start
  else
    Result := Self.stop;
end;

{==============================================================================]
  <Minima>
  @action: Returns the smaller of `start` and `stop`, regardless of ordering.
  @note: Implements a branchless minimum operation using bitwise arithmetic.
[==============================================================================}
function TRange.Minima: Integer;
begin
  Result := (Self.stop xor ((Self.start xor Self.stop) and ((Self.start - Self.stop) shr 31)));
end;

{==============================================================================]
  <Maxima>
  @action: Returns the larger of `start` and `stop`, regardless of ordering.
  @note: Implements a branchless maximum operation using bitwise arithmetic.
[==============================================================================}
function TRange.Maxima: Integer;
begin
  Result := (Self.start xor ((Self.start xor Self.stop) and ((Self.start - Self.stop) shr 31)));
end;

{==============================================================================]
  <Minimal>
  @action: Returns the smaller of the two endpoints (`start` and `stop`) of the range.
           Effectively, this is the left-side of the range on a number line.
  @note:
    - Uses a branchless array indexing trick.
    - Works for ranges where start <= stop (ascending) or start > stop (descending).
    - Equivalent to Min(Self.start, Self.stop) but written without a function call.
[==============================================================================}
function TRange.Minimal: Integer;
var
  v: TIntegerArray;
begin
  v := [Self.start, Self.stop];
  Result := v[Integer(Self.start > Self.stop)];
end;

{==============================================================================]
  <Maximal>
  @action: Returns the larger of the two endpoints (`start` and `stop`) of the range.
           Effectively, this is the right-side of the range on a number line.
  @note:
    - Uses a branchless array indexing trick.
    - Works for ranges where start <= stop (ascending) or start > stop (descending).
    - Equivalent to Max(Self.start, Self.stop) but written without a function call.
[==============================================================================}
function TRange.Maximal: Integer;
var
  v: TIntegerArray;
begin
  v := [Self.start, Self.stop];
  Result := v[Integer(Self.start < Self.stop)];
end;

{==============================================================================]
  <Left>
  @action: Returns the lower endpoint of the range, regardless of whether the
           original start/stop values form an ascending or descending range.
  @note: This is a derived, normalized boundary. It does not reflect the
         caller’s declared direction; it always represents the smaller value.
[==============================================================================}
function TRange.Left: Integer; overload;
begin
  Result := IfThen((Self.start <= Self.stop), Self.start, Self.stop);
end;

{==============================================================================]
  <Right>
  @action: Returns the upper endpoint of the range, independent of the direction
           in which the range was specified.
  @note: This value is always the larger of start/stop. It defines the
         normalized right-hand boundary used for length calculations
         and ordered interval operations.
[==============================================================================}
function TRange.Right: Integer; overload;
begin
  Result := IfThen((Self.start >= Self.stop), Self.start, Self.stop);
end;

{==============================================================================]
  <First>
  @action: Returns the smaller of start and stop, regardless of order.
  @note: Can be computed branchlessly using arithmetic: (start + stop - Abs(start - stop)) div 2.
         Equivalent to Low/Min. Watch for potential integer overflow.
[==============================================================================}
function TRange.First: Integer; overload;
begin
  Result := (((Self.start + Self.stop) - Abs(Self.start - Self.stop)) div 2);
end;

{==============================================================================]
  <Last>
  @action: Returns the larger of start and stop, regardless of order.
  @note: Can be computed branchlessly using arithmetic: (start + stop + Abs(start - stop)) div 2.
         Equivalent to High/Max. Watch for potential integer overflow.
[==============================================================================}
function TRange.Last: Integer; overload;
begin
  Result := (((Self.start + Self.stop) + Abs(Self.start - Self.stop)) div 2);
end;

{==============================================================================]
  <Lower>
  @action: Returns the smaller of `start` and `stop` (the lower bound of the range).
  @note: Implemented using a branchless bitwise arithmetic trick.
[==============================================================================}
function TRange.Lower: Integer; overload;
begin
  Result := ((Self.start * Ord(Self.start <= Self.stop)) + (Self.stop * Ord(Self.start > Self.stop)));
end;

{==============================================================================]
  <Higher>
  @action: Returns the larger of `start` and `stop` (the upper bound of the range).
  @note: Implemented using a branchless bitwise arithmetic trick.
[==============================================================================}
function TRange.Higher: Integer; overload;
begin
  Result := ((Self.start * Ord(Self.start >= Self.stop)) + (Self.stop * Ord(Self.start < Self.stop)));
end;

{==============================================================================]
  <Bottom>
  @action: Returns the smaller of `start` and `stop` (the lower bound of the range).
  @note:
    - Implemented using a `case` statement on the Boolean expression `(start < stop)`.
    - Handles ascending and descending ranges, including negative numbers.
    - Fully portable across Free Pascal, Delphi, and PascalScript.
    - Equivalent in behavior to `if start <= stop then Result := start else Result := stop;` 
      or `Result := Min(start, stop);`.
[==============================================================================}
function TRange.Bottom: Integer; overload;
begin
  case (Self.start < Self.stop) of
    True:  Result := Self.start;
    False: Result := Self.stop;
  end;
end;

{==============================================================================]
  <Top>
  @action: Returns the larger of `start` and `stop` (the upper bound of the range).
  @note:
    - Implemented using a `case` statement on the Boolean expression `(stop > start)`.
    - Handles ascending and descending ranges, including negative numbers.
    - Fully portable across Free Pascal, Delphi, and PascalScript.
    - Equivalent in behavior to `if start >= stop then Result := start else Result := stop;`
      or `Result := Max(start, stop);`.
[==============================================================================}
function TRange.Top: Integer; overload;
begin
  case (Self.stop > Self.start) of
    True: Result := Self.stop;
    False: Result := Self.start;
  end;
end; 

{==============================================================================]
  <Exceeds>
  @action: Returns true if TRange contains more than maxElements.
  @note: TRange Exceeds maximum elements.
[==============================================================================}
function TRange.Exceeds(const maxElements: Integer): Boolean;
begin
  Result := (Self.Size > maxElements);
end;

{==============================================================================]
  <Insufficient>
  @action: Returns true if TRange contains less than minElements.
  @note: TRange is behind minimum elements.
[==============================================================================}
function TRange.Insufficient(const minElements: Integer): Boolean;
begin
  Result := (Self.Size < minElements);
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
  <Sequence>
  @action: Returns digits from TRange.
  @note: None.
[==============================================================================}
function TRange.Sequence: TIntegerArray;
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
  <Ints>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Ints: TIntegerArray;
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
  <Values>
  @action: Returns values of the given range.
  @note: None.
[==============================================================================}
function TRange.Values: TIntegerArray;
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
  <TIA>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.TIA: TIntegerArray;
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
  <Enumerate>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Enumerate: TIntegerArray;
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
  <Enumerated>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Enumerated: TIntegerArray;
var
  n, i: Integer;
begin
  Result := Self.Reserve;
  i := 0;
  for n in Self do
    Result[i.Increase] := n;
end;

{==============================================================================]
  <Elements>
  Explanation: Returns TBox points as TPointArray.
  Example: Alternative method.
[==============================================================================}
function TRange.Elements: TIntegerArray;
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
  <Elements>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Numbers: TIntegerArray;
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
  <Items>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Items: TIntegerArray;
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
  <ToArray>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.ToArray: TIntegerArray;
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
  <Zigzag>
  @action: Returns the integer values of the range in an alternating “zig-zag” order,
           taking elements from the start and end of the range alternately.
           For example, for a range 1..5, the result is [1,5,2,4,3].
  @note:   Works for ascending and descending ranges. 
           If the range contains a single value, returns an array with that single value.
           Internally uses two arrays (ascending and reversed) to construct the pattern.
[==============================================================================}
function TRange.Zigzag(const zAscending: Boolean = True): TIntegerArray; overload;
var
  a, d: TIntegerArray;
  l, i, j, r, z: Integer;
begin
  if (Self.start = Self.stop) then
    Exit([Self.start]);
  a := Self.ToArray;
  d := a.Reversed;
  l := a.Length;
  SetLength(Result, l);
  i := 0;
  j := 0;
  r := -1;
  z := IfThen(zAscending, 0, 1);
  while ((i + j) < l) do
    if ((r.Increment mod 2) = z) then
      Result[r] := a[i.Increase]
    else
      Result[r] := d[j.Increase];
end;

{==============================================================================]
  <Materialize>
  @action: Returns digits of the given range.
  @note: None.
[==============================================================================}
function TRange.Materialize: TIntegerArray;
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
  <Mixed>
  @action: Returns TRange randomly mixed as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Mixed(const mixings: Integer = 1): TIntegerArray;
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
  <Shake>
  @action: Returns TRange randomly shaked as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Shake(const shakes: Integer = 1): TIntegerArray;
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
  <Shuffle>
  @action: Returns TRange randomly shuffled as TIntegerArray.
  @note: None.
[==============================================================================}
function TRange.Shuffle(const shuffles: Integer = 1): TIntegerArray;
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
  <Any>
  @action: Returns random TRange item.
  @note: None.
[==============================================================================}
function TRange.Any: Integer;
begin
  Result := ((Self.Start + Random(Self.Size)) * IfThen(Self.Ascending, 1, -1));
end;

{==============================================================================]
  <Some>
  @action: Returns random amount of random TRange items.
  @note: Does not return empty arrays.
[==============================================================================}
function TRange.Some: TIntegerArray; overload;
begin
  Result := Copy(Self.Shuffle, 0, Max(Random(Self.Size + 1), 1))
end;

{==============================================================================]
  <Some>
  @action: Returns random amount of random TRange items.
  @note: Does not return empty arrays.
[==============================================================================}
function TRange.Some(const amount: Integer): TIntegerArray; overload;
begin
  Result := Copy(Self.Shuffle, 0, Max(1, Min(amount, Self.Size)));
end;

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
  <Normed>
  @action: Using if-then comparison this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Normed: TRange;
begin
  Result.Create(IfThen((Self.start < Self.stop), Self.start, Self.stop), IfThen((Self.start < Self.stop), Self.stop, Self.start));
end;

{==============================================================================]
  <Norm>
  @action: Using if-then comparison this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Norm: TRange;
begin
  Result := IfThen((Self.start > Self.stop), Self.Reversed, Self);
end;

{==============================================================================]
  <Normal>
  @action: XOR-swap based.
  @note: None.
[==============================================================================}
 function TRange.Normal: TRange;
begin
  Result := Self;
  if (Result.start <= Result.stop) then
    Exit;
  Result.start := (Result.start xor Result.stop);
  Result.stop := (Result.start xor Result.stop);
  Result.start := (Result.start xor Result.stop);
end;

{==============================================================================]
  <Normally>
  @action: Ord-based.
  @note: None.
[==============================================================================}
function TRange.Normally: TRange;
var
  a: TIntegerArray;
begin
  a := [Self.start, Self.stop];
  Result.Create(a[Ord(Self.start > Self.stop)], a[Ord(Self.start <= Self.stop)]);
end;

{==============================================================================]
  <Normalize>
  @action: Using Min-Maxing this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Normalize: TRange;
begin
  Result.start := Min(Self.start, Self.stop);
  Result.stop := Max(Self.start, Self.stop);
end;

{==============================================================================]
  <Normalized>
  @action: Using if-then comparison this function returns "normal" range.
  @note: None.
[==============================================================================}
function TRange.Normalized: TRange;
begin
  Result.start := ((Self.start + Self.stop) shr 1);
  Result.stop := (Abs(Self.start - Self.stop) shr 1);
  Result.Create((Result.start - Result.stop), (Result.start + Result.stop));
end;

{==============================================================================]
  <MinMax>
  @action: Returns a normalized ascending version of the range, ensuring start <= stop.
  @note: If the current range is already ascending, the function returns Self unchanged.
[==============================================================================}
function TRange.MinMax: TRange; overload;
begin
  if (Self.start < Self.stop) then
    Exit(Self);
  Result.Create(Self.stop, Self.start);
end;

{==============================================================================]
  <MaxMin>
  @action: Returns a normalized descending version of the range, ensuring start >= stop.
  @note: If the current range is already descending, the function returns Self unchanged.
[==============================================================================}
function TRange.MaxMin: TRange; overload;
begin
  if (Self.start > Self.stop) then
    Exit(Self);
  Result.Create(Self.stop, Self.start);
end;

{==============================================================================]
  <Overlapping>
  @action: Checks if a and b overlap eachother.
  @note: Returns true if overlap is found.
[==============================================================================}
function TRange.Overlapping(const b: TRange): Boolean;
begin
  Result := ((Min(Self.start, Self.stop) <= Max(b.start, b.stop)) and (Min(b.start, b.stop) <= Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <Overlap>
  @action: Checks if a and b overlap eachother.
  @note: Returns true if overlap is found.
[==============================================================================}
function TRange.Overlap(const b: TRange): Boolean;
begin
  Result := not ((Min(Self.start, Self.stop) > Max(b.start, b.stop)) or (Min(b.start, b.stop) > Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <Intersect>
  @action: Returns intersection of a and b.
  @note: Returns null if there is no intersection for a and b.
[==============================================================================}
function TRange.Intersect(const b: TRange): TRange; overload;
var
  s, t: TRange;
begin
  s := Self.Normalize;
  t := b.Normalize;
  Result.start := Max(s.start, t.start);
  Result.stop := Min(s.stop, t.stop);
end;

{==============================================================================]
  <Intersect>
  @action: Returns true if of a and b contains intersection.
  @note: Stores intersection to variable, if Result is True.
[==============================================================================}
function TRange.Intersect(const b: TRange; var iZone: TRange): Boolean; overload;
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
  <Union>
  @action: Returns union of ranges a and b.
  @note: None.
[==============================================================================}
function TRange.Union(const b: TRange): TRange; overload;
begin
  Result.start := Min(Min(Self.start, Self.stop), Min(b.start, b.stop));
  Result.stop := Max(Max(Self.start, Self.stop), Max(b.start, b.stop));
end;

{==============================================================================]
  <Union>
  @action: Returns union of range and val.
  @note: None.
[==============================================================================}
function TRange.Union(const val: Integer): TRange; overload;
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
  <Offset>
  @action: Returns shift of range r by delta.
  @note: None.
[==============================================================================}
function TRange.Offset(const sDelta: Integer): TRange;
begin
  Result.Create((Self.start + sDelta), (Self.stop + sDelta));
end;

{==============================================================================]
  <Contains>
  @action: Returns True if range contains x-value.
  @note: None.
[==============================================================================}
function TRange.Contains(const x: Integer): Boolean; overload;
begin
  Result := ((x >= Min(Self.start, Self.stop)) and (x <= Max(Self.stop, Self.start)));
end;

{==============================================================================]
  <Contains>
  @action: Returns True if range contains x.
  @note: Meaning x is completely part of range.
[==============================================================================}
function TRange.Contains(const x: TRange): Boolean; overload;
begin
  Result := ((Min(x.start, x.stop) >= Min(Self.start, Self.stop)) and (Max(x.start, x.stop) <= Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <Holds>
  @action: Determines whether a given integer value lies within the range.
  @note: Returns True if the value is greater than or equal to the lower bound
         and less than or equal to the upper bound, regardless of whether
         start > stop. Complementary to Missing.
[==============================================================================}
function TRange.Holds(const val: Integer): Boolean; overload;
begin
  Result := ((val >= Min(Self.start, Self.stop)) and (val <= Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <Holds>
  @action: Determines whether a given integer value lies within the range.
  @note: Returns True if the value is greater than or equal to the lower bound
         and less than or equal to the upper bound, regardless of whether
         start > stop. Complementary to Missing.
[==============================================================================}
function TRange.Holds(const vals: TRange): Boolean; overload;
begin
  Result := (Min(vals.start, vals.stop) >= Min(Self.start, Self.stop)) and (Max(vals.start, vals.stop) <= Max(Self.start, Self.stop));
end;

{==============================================================================]
  <Missing>
  @action: Determines whether a given integer value lies outside the range.
  @note: Returns True if the value is less than the lower bound or greater than
         the upper bound, regardless of start/stop order. Complementary to Holds.
[==============================================================================}
function TRange.Missing(const val: Integer): Boolean; overload;
begin
  Result := ((val < Min(Self.start, Self.stop)) or (val > Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <Missing>
  @action: Determines whether another range lies entirely outside this range.
  @note: Returns True if the input range is completely disjoint from this range,
         i.e., there is no overlap between the ranges. Works correctly for both
         ascending and descending ranges by normalizing start and stop values.
[==============================================================================}
function TRange.Missing(const vals: TRange): Boolean; overload;
begin
  Result := ((Max(vals.start, vals.stop) < Min(Self.start, Self.stop)) or (Min(vals.start, vals.stop) > Max(Self.start, Self.stop)));
end;

{==============================================================================]
  <Above>
  @action: Returns True if range is above target.
  @note: None.
[==============================================================================}
function TRange.Above(const target: Integer): Boolean; overload;
begin
  Result := (Self.Minimum > target);
end;

function TRange.Above(const target: TRange): Boolean; overload;
begin
  Result := Self.Above(target.Maximum);
end;

{==============================================================================]
  <Below>
  @action: Returns True if range is below target.
  @note: None.
[==============================================================================}
function TRange.Below(const target: Integer): Boolean; overload;
begin
  Result := (Self.Maximum < target);
end;

function TRange.Below(const target: TRange): Boolean; overload;
begin
  Result := Self.Below(target.Minimum);
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
  <Equals>
  @action: Checks if a matches b.
  @note: 0..3 and 3..0 will be treated as match.
[==============================================================================}
function TRange.Equals(const b: TRange): Boolean;
begin
  Result := ((Min(Self.start, Self.stop) = Min(b.start, b.stop)) and (Max(Self.start, Self.stop) = Max(b.start, b.stop)));
end;

{==============================================================================]
  <Differs>
  @action: Checks if a unmatches b.
  @note: 0..3 and 3..0 will be treated as match.
[==============================================================================}
function TRange.Differs(const b: TRange): Boolean;
begin
  Result := ((Min(Self.start, Self.stop) <> Min(b.start, b.stop)) or (Max(Self.start, Self.stop) <> Max(b.start, b.stop)));
end;

{==============================================================================]
  <Equal>
  @action: Checks if a matches b exactly.
  @note: 0..3 and 3..0 will NOT be treated as match.
[==============================================================================}
function TRange.Equal(const b: TRange): Boolean;
begin
  Result := ((Self.start = b.start) and (Self.stop = b.stop));
end;

{==============================================================================]
  <Differ>
  @action: Checks if a unmatches b exactly.
  @note: 0..3 and 3..0 will NOT be treated as match.
[==============================================================================}
function TRange.Differ(const b: TRange): Boolean;
begin
  Result := ((Self.start <> b.start) or (Self.stop <> b.stop));
end;

{==============================================================================]
  <Clamp>
  @action: Returns range clamped inside zone range.
  @note: Makes sure Result is range fitted in zone bounds.
[==============================================================================}
function TRange.Clamp(const zone: TRange): TRange;
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
  <ClampMax>
  @action: Returns range with start and stop with maximum value.
  @note: Makes sure neither start or stop is higher than maximum.
[==============================================================================}
function TRange.ClampMax(const maxValue: Integer): TRange;
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
  <ClampMin>
  @action: Returns range with start and stop with minimum value.
  @note: Makes sure neither start or stop is lower than minimum.
[==============================================================================}
function TRange.ClampMin(const minValue: Integer): TRange;
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
  <Restrict>
  @action: Ensures range start and stop stays within zone.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange.Restrict(const zone: TRange): Boolean;
var
  e: TRange;
begin
  e := Self.Clamp(zone);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <RestrictMin>
  @action: Ensures range start and stop stays within minimum.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange.RestrictMin(const minValue: Integer): Boolean;
var
  e: TRange;
begin
  e := Self.ClampMin(minValue);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <RestrictMax>
  @action: Ensures range start and stop stays within maximum.
  @note: Returns true if restriction was performed for start or/and stop.
[==============================================================================}
function TRange.RestrictMax(const maxValue: Integer): Boolean;
var
  e: TRange;
begin
  e := Self.ClampMax(maxValue);
  Result := not e.Equals(Self);
  if Result then
    Self := e;
end;

{==============================================================================]
  <Clip>
  @action: Ensures range start and stop stays within zone.
  @note: Alternative for TRange_Clamp.
[==============================================================================}
function TRange.Clip(const zone: TRange): TRange;
begin
  Result.start := Max(zone.start, Min(Self.start, zone.stop));
  Result.stop := Min(zone.stop, Max(Self.stop, zone.start));
end;

{==============================================================================]
  <ClipMin>
  @action: Ensures range start and stop stays within minimum.
  @note: Alternative for TRange_ClampMin.
[==============================================================================}
function TRange.ClipMin(const minValue: Integer): TRange;
begin
  Result.start := Max(Self.start, minValue);
  Result.stop := Max(Self.stop, minValue);
end;

{==============================================================================]
  <ClipMax>
  @action: Ensures range start and stop stays within maximum.
  @note: Alternative for TRange_ClampMax.
[==============================================================================}
function TRange.ClipMax(const maxValue: Integer): TRange;
begin
  Result.start := Min(Self.start, maxValue);
  Result.stop := Min(Self.stop, maxValue);
end;

{==============================================================================]
  <Ensured>
  @action: Returns a new TRange with start and stop clamped to fit within zone.
  @note: Preserves the direction (start > stop) of the original range.
         Zone is normalized internally, so reversed zones are handled.
[==============================================================================}
function TRange.Ensured(const zone: TRange): TRange; overload;
begin
  Result := zone.Normalize;
  Result.Create(Max(Result.start, Min(Self.start, Result.stop)), Min(Result.stop,  Max(Self.stop,  Result.start)));
end;

{==============================================================================]
  <Ensure>
  @action: Clamps the current TRange (Self) to fit within zone.
  @note: Preserves the direction (start > stop) of Self.
         Returns True if Self was modified; False otherwise.
         Zone is normalized internally, so reversed zones are handled.
[==============================================================================}
function TRange.Ensure(const zone: TRange): Boolean; overload;
var
  s: TRange;
begin
  s := Self;
  Self := zone.Normalize;
  Self.Create(Max(Self.start, Min(s.start, Self.stop)), Min(Self.stop,  Max(s.stop,  Self.start)));
  Result := (Self <> s);
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
  <Distribute>
  @action: Distributes range to TRangeArray by amount of parts
  @note: None.
[==============================================================================}
function TRangeHelper.Distribute(const parts: Integer): TRangeArray;
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
  <Partition>
  @action: Partitions range to TRangeArray by size of parts
  @note: None.
[==============================================================================}
function TRangeHelper.Partition(const size: Integer): TRangeArray;
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
  <Divide>
  @action: Partitions range to TRangeArray by size of parts
  @note: Alternative for TRange_Partition.
[==============================================================================}
function TRangeHelper.Divide(const size: Integer): TRangeArray;
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
  <Neighbor>
  @action: Returns true if 2 TRanges are right next to eachother.
  @note: (Distance is exactly 1 between em).
[==============================================================================}
function TRange.Neighbor(const b: TRange): Boolean;
var
  i, j: TRange;
begin
  i := Self.Normalize;
  j := b.Normalize;
  Result := ((i.stop + 1) = j.start) or ((j.stop + 1) = i.start);
end;

{==============================================================================]
  <Neighbour>
  @action: Returns true if 2 TRanges are right next to eachother.
  @note: (Distance is exactly 1 between em).
[==============================================================================}
function TRange.Neighbour(const b: TRange): Boolean;
begin
  Result := (((Max(Self.start, Self.stop) + 1) = Min(b.start, b.stop)) or ((Max(b.start, b.stop) + 1) = Min(Self.start, Self.stop)));
end;

{==============================================================================]
  <Touch>
  @action: Returns true if range touches b.
  @note: Touch = only single value is shared between the ranges.
[==============================================================================}
function TRange.Touch(const b: TRange): Boolean;
var
  l, h, r: TRange;
begin
  l := Self.Normalize;
  h := b.Normalize;
  r.Create(Max(l.start, h.start), Min(l.stop, h.stop));
  Result := r.Singular;
end;

{==============================================================================]
  <Touches>
  @action: Returns true if range touches b with minimum and maximum contact.
  @note: Touch = minimum/maximum shared values.
[==============================================================================}
function TRange.Touches(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean;
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
  <Touching>
  @action: Returns true if range touches b with minimum and maximum contact.
  @note: Touch = minimum/maximum shared values.
[==============================================================================}
function TRange.Touching(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean;
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
  <Distance>
  @action: Returns minimum distance between ranges a and b.
  @note: If ranges overlap, distance is 0.
[==============================================================================}
function TRange.Distance(const b: TRange): Integer; overload;
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
  <Distance>
  @action: Returns the distance between the start and stop values of the range.
           Accounts for the direction of the range (descending or ascending).
  @note: Distance is exclusive of endpoints. Use this if you want the signed
         difference based on the range direction (negative if descending?).
[==============================================================================}
function TRange.Distance: Integer; overload;
begin
  if Self.Descending then
    Result := (Self.start - Self.stop)
  else
    Result := (Self.stop - Self.start);
end;

{==============================================================================]
  <Dist>
  @action: Returns the distance between the start and stop values of the range.
           Uses a compact conditional expression to handle descending ranges.
  @note: Same as Distance but written using IfThen for brevity. Still exclusive
         of endpoints and sensitive to the Descending flag.
[==============================================================================}
function TRange.Dist: Integer;
begin
  Result := IfThen(Self.Descending, (Self.start - Self.stop), (Self.stop - Self.start));
end;

{==============================================================================]
  <Difference>
  @action: Returns the absolute difference between the start and stop values,
           ignoring the direction of the range.
  @note: Diff is always non-negative and exclusive of endpoints. Use this if
         you only care about the magnitude of the gap, not whether the range
         is ascending or descending.
[==============================================================================}
function TRange.Difference: Integer;
begin
  Result := Abs(Self.stop - Self.start);
end;

{==============================================================================]
  <Diff>
  @action: Returns the absolute difference (magnitude) between start and stop,
           ignoring the direction of the range.
  @note: The result is always non-negative. Equivalent to Abs(stop - start).
         Does not include endpoints; useful when only the gap between values matters.
[==============================================================================}
function TRange.Diff: Integer;
begin
  Result := (Max(Self.start, Self.stop) - Min(Self.start, Self.stop));
end;

{==============================================================================]
  <DistHausdorff>
  @action: Returns Hausdorff-based distance between ranges a and b.
  @note: None.
[==============================================================================}
function TRange.DistHausdorff(const b: TRange): Integer;
var
  i, j: TRange;
begin
  i := Self.Normalize;
  j := b.Normalize;
  Result := Max(Abs(i.start - j.stop), Abs(i.stop - j.start));
end;

{==============================================================================]
  <Delta>
  @action: Delta returns the signed difference from start to stop; the sign indicates the range’s orientation.
  @note: None.
[==============================================================================}
function TRange.Delta: Integer; inline;
begin
  Result := (Self.stop - Self.start);
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
  <Magnitude>
  @action: Returns the magnitude (non-negative size) of the range, ignoring orientation.
  @note: Computed as the absolute value of Delta (Abs(Stop - Start)).
         Always ≥ 0, regardless of whether the range is ascending or descending.
[==============================================================================}
function TRange.Magnitude: Integer;
begin
  Result := Abs(Self.Delta);
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
  <Deficit>
  @action: Returns the negative absolute distance between Start and Stop.
  @note: Computed as Min(Start, Stop) - Max(Start, Stop).
         Always ≤ 0. Ignores orientation; useful when a negative “shortfall” value is needed.
[==============================================================================}
function TRange.Deficit: Integer;
begin
  Result := (Min(Self.start, Self.stop) - Max(Self.start, Self.stop));
end;

{==============================================================================]
 <Digit>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRange.Digit(const x: Integer): Boolean; inline;
begin
  Result := (((x >= Self.start) and (x <= Self.stop)) or ((x >= Self.stop) and (x <= Self.start)));
end;

{==============================================================================]
 <Value>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRange.Value(const x: Integer): Boolean; inline;
begin
  Result := not (((x < Self.start) and (x < Self.stop)) or ((x > Self.stop) and (x > Self.start)));
end;

{==============================================================================]
 <Lacks>
 @action: Returns true if x-value is out of range.
 @note: None.
[==============================================================================}
function TRange.Lacks(const x: Integer): Boolean; inline;
begin
  Result := (((x < Self.start) and (x < Self.stop)) or ((x > Self.stop) and (x > Self.start)));
end;

{==============================================================================]
 <Outside>
 @action: Returns true if x-value is outside the range.
 @note: None.
[==============================================================================}
function TRange.Outside(const x: Integer): Boolean; inline;
begin
  Result := not (((x >= Self.start) and (x <= Self.stop)) or ((x >= Self.stop) and (x <= Self.start)));
end;

{==============================================================================]
 <Item>
 @action: Returns true if range contains x-value.
 @note: None.
[==============================================================================}
function TRange.Item(const x: Integer): Boolean; inline;
begin
  if (Self.start <= Self.stop) then
    Result := ((x >= Self.start) and (x <= Self.stop))
  else
    Result := ((x >= Self.stop) and (x <= Self.start));
end;

{==============================================================================]
 <Pivot>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Pivot: Integer;
begin
  if Self.Ascending then
    Result := (Self.start + ((Self.stop - Self.start) div 2))
  else
    Result := (Self.stop + ((Self.start - Self.stop) div 2));
end;

{==============================================================================]
 <Mean>
 @action: Returns the arithmetic mean (midpoint) of the range's Start and Stop values as a Double.
 @note: Uses floating-point division to avoid integer truncation and to handle large integer values safely.
[==============================================================================}
function TRange.Mean: Double; overload;
begin
  Result := ((Self.start / 2.0) + (Self.stop / 2.0));
end;

{==============================================================================]
 <Medium>
 @action: Returns the arithmetic mean of the range bounds as a floating-point value.
 @note: This represents a mathematical midpoint only. The result may be fractional.
[==============================================================================}
function TRange.Medium: Double; overload;
begin
  Result := ((Self.start + Self.stop) * 0.5);
end;

{==============================================================================]
 <MiddleRight>
 @action: Returns the integer midpoint of the range, biased toward the higher index.
 @note: Uses ceiling division. Suitable for binary search variants that advance the
        lower bound and require guaranteed progress on even-length ranges. Supports
        both ascending and descending ranges.
[==============================================================================}
function TRange.MiddleRight: Integer; overload;
begin
  if (Self.start > Self.stop) then
    Exit(Self.stop + ((Self.start - Self.stop) + 1) div 2);
  Result := (Self.start + ((Self.stop - Self.start) + 1) div 2);
end;

{==============================================================================]
 <MiddleLeft>
 @action: Returns the integer midpoint of the range, biased toward the lower index.
 @note: Uses floor division. This is the classic binary search midpoint and is safe
        for single-element, ascending, and descending ranges.
[==============================================================================}
function TRange.MiddleLeft: Integer; overload;
begin
  if (Self.start > Self.stop) then
    Exit(Self.stop + (Self.start - Self.stop) div 2);
  Result := (Self.start + (Self.stop - Self.start) div 2);
end;

{==============================================================================]
 <Middle>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Middle: Integer;
begin
  Result := ((Self.start + Self.stop) div 2);
end;

{==============================================================================]
 <MiddleStep>
 @action: Returns the integer midpoint of the range, calculated by stepping halfway 
          from start to stop. Works for both ascending and descending ranges.
 @note: Neutral midpoint, unbiased toward lower or higher indices.
[==============================================================================}
function TRange.MiddleStep: Integer; overload;
begin
  if (Self.stop > Self.start) then
    Result := (Self.start + (Abs(Self.stop - Self.start) div 2))
  else
    Result := (Self.start - (Abs(Self.stop - Self.start) div 2));
end;

{==============================================================================]
 <MiddleBit>
 @action: Returns the integer midpoint of the range using a bitwise shift for division by 2.
 @note: Safe for ascending and descending ranges. Equivalent to a floor-biased midpoint
        but uses low-level arithmetic for efficiency.
[==============================================================================}
function TRange.MiddleBit: Integer; overload;
begin
  if (Self.start <= Self.stop) then
    Result := (Self.start + ((Self.stop - Self.start) shr 1))
  else
    Result := (Self.start - ((Self.start - Self.stop) shr 1));
end;

{==============================================================================]
 <MidBit>
 @action: Returns the integer midpoint of the range using a bitwise shift (shr 1) for division by 2.
 @note: Safe for both ascending and descending ranges. This is a floor-biased midpoint,
        equivalent to MiddleLeft, but implemented with a bit shift for efficiency.
[==============================================================================}
function TRange.MidBit: Integer; overload;
begin
  if (Self.start <= Self.stop) then
    Exit(Self.start + ((Self.stop - Self.start) shr 1));
  Result := TRange.Construct(Self.stop, Self.start).MidBit;
end;

{==============================================================================]
 <Mid>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Mid: Double;
begin
  Result := ((Self.start + Self.stop) / 2.0);
end;

{==============================================================================]
 <MidVal>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.MidVal: Double;
var
  s: Integer;
begin
  s := (Self.Highest + Self.Lowest);
  Result := (s div 2);
  if ((s mod 2) = 1) then
    Result := (((Result + 1) + Result) / 2.0);
end;

{==============================================================================]
 <MidValue>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.MidValue: Double;
var
  s: Integer;
begin
  s := (Self.start + Self.stop);
  Result := (s div 2);
  if ((s mod 2) <> 0) then
    Result := (Result + 0.5);
end;

{==============================================================================]
 <MiddleValue>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.MiddleValue: Double;
begin
  if (Self.start <= Self.stop) then
    Result := (Self.start + ((Self.stop - Self.start) / 2))
  else
    Result := (Self.stop + ((Self.start - Self.stop) / 2));
end;

{==============================================================================]
 <MiddleVal>
 @action: Middle value alternative
 @note: None
[==============================================================================}
function TRange.MiddleVal: Integer; overload;
begin
  Result := ((Int64(Self.start) + Int64(Self.stop)) div 2);
end;

{==============================================================================]
 <Midpoint>
  @action: Computes the weighted midpoint (center) of the range using given weights.
  @note: Returns a Double. Weighted midpoint formula: ((Start * wStart) + (Stop * wStop)) / (wStart + wStop).
         Useful when one bound of the range has more importance than the other.
[==============================================================================}
function TRange.Midpoint(const wStart: Double = 1; const wStop: Double = 1): Double; overload;
begin
  Result := (((Self.start * wStart) + (Self.stop * wStop)) / (wStart + wStop));
end;

{==============================================================================]
 <Average>
 @action: Average value from TRange.
 @note: None
[==============================================================================}
function TRange.Average: Double;
var
  c: Int64;
begin
  c := Self.Size;
  Result := ((c * (Self.start + Self.stop) div 2) / c);
end;

{==============================================================================]
 <Center>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Center: Integer;
begin
  Result := ((Self.start + Self.stop) div 2);
end;

{==============================================================================]
 <Central>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Central: Integer; inline;
begin
  Result := ((Self.start + self.stop) shr 1);
end;

{==============================================================================]
 <Centre>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Centre: Integer; overload;
begin
  Result := ((Min(Self.start, Self.stop)) + (Abs(Self.start - Self.stop) div 2));
end;

{==============================================================================]
 <Centroid>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Centroid: Integer; overload;
begin
  Result := (((Self.start div 2) + (Self.stop div 2)) + (((Self.start mod 2) + (Self.stop mod 2)) div 2));
end;

{==============================================================================]
 <Core>
 @action: The value(s) at the center position(s) of given range.
 @note: None
[==============================================================================}
function TRange.Core: Integer; overload;
begin
  Result := (Self.stop - Self.start);
  Result := (Result - (Result and 1));
  Result := (Self.start + (Result div 2));
end;

{==============================================================================]
  <Half>
  @action: Returns half the length of the range as an integer, calculated as the
           absolute difference between Stop and Start divided by two.
  @note:   Direction-agnostic; works for both ascending and descending ranges.
           Useful for offset calculations, contraction, or expansion operations.
[==============================================================================}
function TRange.Half: Integer; overload;
begin
  Result := (Abs(Self.stop - Self.start) div 2);
end;

{==============================================================================]
  <Halfway>
  @action: Returns half the distance between Start and Stop, explicitly handling
           ascending and descending ranges.
  @note:   Functionally identical to Half; uses conditional logic instead of Abs().
           Can be used interchangeably where explicit branch logic is preferred.
[==============================================================================}
function TRange.Halfway: Integer; overload;
begin
  if (Self.start > Self.stop) then
    Result := ((Self.start - Self.stop) div 2)
  else
    Result := ((Self.stop - Self.start) div 2);
end;

{==============================================================================]
  <Halved>
  @action: Returns half the distance between Start and Stop, explicitly handling
           ascending and descending ranges.
  @note:   EnsureRange-based.
[==============================================================================}
function TRange.Halved: Integer; overload;
begin
  Result := EnsureRange((Abs(Self.stop - Self.start) div 2), 0, High(Integer));
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
  <AsStr>
  @action: Converts TRange range to string.
  @note: From..To or To..From.
[==============================================================================}
function TRange.AsStr(const rReversed: Boolean = False): string; overload;
begin
  if not rReversed then
    Result := Format('%d..%d', [Self.start, Self.stop])
  else
    Result := Format('%d..%d', [Self.stop, Self.start]);
end;

{==============================================================================]
  <Str>
  @action: Converts TRange range to string.
  @note: None
[==============================================================================}
function TRange.Str(const openRange: string = '['; const closeRange: string = ']'; const glueRange: string = '..'): string;
begin
  Result := ('[' + IntToStr(Self.start) + glueRange + IntToStr(Self.stop) + ']');
end;

{==============================================================================]
  <ToStr>
  @action: Converts TRange range to string.
  @note: None
[==============================================================================}
function TRange.ToStr(const glueRange: string = '..'; const openRange: string = '['; const closeRange: string = ']'): string;
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
  <Stringify>
  @action: Converts TRange range to string.
  @note: None
[==============================================================================}
function TRange.Stringify(const openRange: string = '['; const glueRange: string = '..'; const closeRange: string = ']'): string;
begin
  Result := Format(openRange + '%d' + glueRange + '%d' + closeRange, [Self.start, Self.stop]);
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
function TRange.Extracted: TIntegerArray;
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
  <Limit>
  @action: Restricts a value to lie within the range defined by Start and Stop.
  @note: Equivalent to clamping value to the inclusive range [Min(start, stop), Max(start, stop)].
         Returns Min(start, stop) if val is below the range.
         Returns Max(start, stop) if val is above the range.
         Otherwise returns value itself.
[==============================================================================}
function TRange.Limit(const val: Integer): Integer;
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
  <MinLimit>
  @action: Ensures a value is not less than the range minimum.
  @note: Returns Max(val, Min(start, stop)).
         Values above the range maximum are allowed.
         Useful when you only want to enforce a lower bound.
[==============================================================================}
function TRange.MinLimit(const val: Integer): Integer;
begin
  Result := Max(val, Min(Self.start, Self.stop));
end;

{==============================================================================]
  <MaxLimit>
  @action: Ensures a value is not greater than the range maximum.
  @note: Returns Min(val, Max(start, stop)).
         Values below the range minimum are allowed.
         Useful when you only want to enforce an upper bound.
[==============================================================================}
function TRange.MaxLimit(const val: Integer): Integer;
begin
  Result := Min(val, Max(Self.start, Self.stop));
end;

{==============================================================================]
  <Sample>
  @action: Return evenly spaced integer samples across the range.
  @note: Always includes both start and stop values of the range (if sSize > 1).
         Uses rounding to map floating step positions to integers.
         If sSize = 1, returns only the start value.
[==============================================================================}
function TRange.Sample(const sSize: Integer): TIntegerArray; overload;
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
  <Windows>
  @action: Generate all possible subranges (sliding windows) of Self inside
           the target range. These windows may overlap.
  @note:   The number of results is (TargetSize - SelfSize + 1).
[==============================================================================}
function TRangeHelper.Windows(const target: TRange): TRangeArray; overload;
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
  <Sectioned>                                                             
  @action: Divide the target range into sequential, non-overlapping subranges
           of the same size as Self.
  @note:   Any remainder at the end of the target range is discarded.
[==============================================================================}
function TRangeHelper.Sectioned(const target: TRange): TRangeArray; overload;
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
  <Binned>
  @action: Generate grid-aligned subranges (bins) of the same size as Self
           inside the target range.
  @note:   Subranges are aligned in steps of SelfSize from the start of target.
           Any remainder that does not fit evenly is ignored.
[==============================================================================}
function TRangeHelper.Binned(const target: TRange): TRangeArray; overload;
var
  i, s: Integer;
  t: TRange;
begin
  t := target.Normalize;
  s := Self.Size;
  if (s > t.Size) then
    Exit([]);
  SetLength(Result, (t.Size div s));
  for i := 0 to High(Result) do
  begin
    Result[i].start := (t.start + (s * i));
    Result[i].stop := (Result[i].start + (s - 1));
  end;
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
  <Uniform>
  @action: Checks whether both endpoints of the range equal the specified value.
  @note: Returns True only if (Start = Stop = val).
[==============================================================================}
function TRange.Uniform(const val: Integer): Boolean; overload;
begin
  Result := ((Self.start = val) and (Self.stop = val));
end;

{==============================================================================]
  <Uniform>
  @action: Checks whether the range’s start and stop positions are equal.
  @note: Returns True if (Start = Stop).
[==============================================================================}
function TRange.Uniform: Boolean; overload;
begin
  Result := (Self.start = Self.stop);
end;

{==============================================================================]
  <Employs>
  @action: Checks if the given integer value matches either the start or stop of the range.
  @note: Useful for quickly verifying if a value is an endpoint of the range.
[==============================================================================}
function TRange.Employs(const val: Integer): Boolean;
begin
  Result := ((Self.start = val) or (Self.stop = val));
end;

{==============================================================================]
  <Omits>
  @action: Checks if the given integer value is NOT present as either the start or stop of the range.
  @note: Logical inverse of TRange.Employs; returns True if the value is absent from the range endpoints.
[==============================================================================}
function TRange.Omits(const val: Integer): Boolean;
begin
  Result := not ((Self.start = val) or (Self.stop = val));
end;

{==============================================================================]
  <Even>
  @action: Returns True when the size of the range is an even integer.
  @note: Delegates to Self.Size.Even; no side effects.
[==============================================================================}
function TRange.Even: Boolean; overload;
begin
  Result := Self.Size.Even;
end;

{==============================================================================]
  <Odd>
  @action: Returns True when the size of the range is an odd integer.
  @note: Delegates to Self.Size.Odd; no side effects.
[==============================================================================}
function TRange.Odd: Boolean; overload;
begin
  Result := Self.Size.Odd;
end;

{==============================================================================]
  <Evens>
  @action: Computes the total number of even integers contained within the range.
  @note: The computation is O(1) and works for both ascending and descending
         ranges. The result is inclusive of both endpoints.
[==============================================================================}
function TRange.Evens: Integer; overload;
var
  r: TRange;
begin
  r := Self.Normalize;
  if r.start.Odd then
    Inc(r.start);
  if r.stop.Odd then
    Dec(r.stop);
  if (r.start > r.stop) then
    Result := 0
  else
    Result := (((r.stop - r.start) div 2) + 1);
end;

{==============================================================================]
  <Odds>
  @action: Computes the total number of odd integers contained within the range.
  @note: Determined as (RangeSize - Evens), ensuring correctness regardless
         of range direction or endpoint parity.
[==============================================================================}
function TRange.Odds: Integer; overload;
begin
  Result := (Self.Size - Self.Evens);
end;

{==============================================================================]
  <EvenCount>
  @action: Returns the number of even integers within the range (including both start and stop).
  @note: Works for ascending, descending, and single-element ranges. Handles negative numbers correctly.
[==============================================================================}
function TRange.EvenCount: Integer; overload;
var
  f, l: Integer;
begin
  Result := Self.Direction;
  if (Result = 0) then
    Exit(IfThen(Self.start.Even, 1, 0));
  f := IfThen(Self.start.Even, Self.start, (Self.start + Result));
  l := IfThen(Self.stop.Even, Self.stop, (Self.stop - Result));
  if not (((Result > 0) and (f > l)) or ((Result < 0) and (f < l))) then
    Result := Abs((l - f) div 2) + 1;
end;

{==============================================================================]
  <OddCount>
  @action: Returns the number of odd integers within the range (including both start and stop).
  @note: Calculated as the total range size minus the number of even numbers. Works for ascending, descending, and negative ranges.
[==============================================================================}
function TRange.OddCount: Integer; overload;
begin
  Result := (Self.Size - Self.EvenCount);
end;

{==============================================================================]
  <Evened>
  @action: Produces an array containing all even integers within the range,
           ordered according to the range direction.
  @note: The first element is aligned to the nearest even boundary starting
         from `start`, then values progress by ±2 depending on whether the
         range is ascending or descending.
[==============================================================================}
function TRange.Evened: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Evens);
  if (Result.Length = 0) then
    Exit;
  Result[0] := Self.start;
  if Self.start.Odd then
    Result[0] := (Result[0] + Self.Direction);
  case Self.Ascending of
    True:
    for i := 1 to High(Result) do
      Result[i] := (Result[i - 1] + 2);
    False:
    for i := 1 to High(Result) do
      Result[i] := (Result[i - 1] - 2);
  end;
end;

{==============================================================================]
  <Odded>
  @action: Produces an array containing all odd integers within the range,
           ordered according to the range direction.
  @note: The first element is aligned to the nearest odd boundary starting
         from `start`, then values progress by ±2 depending on the direction
         of the range.
[==============================================================================}
function TRange.Odded: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Odds);
  if (Result.Length = 0) then
    Exit;
  Result[0] := Self.start;
  if Self.start.Even then
    Result[0] := (Result[0] + Self.Direction);
  case Self.Ascending of
    True:
    for i := 1 to High(Result) do
      Result[i] := (Result[i - 1] + 2);
    False:
    for i := 1 to High(Result) do
      Result[i] := (Result[i - 1] - 2);
  end;
end;

{==============================================================================]
  <TRange.Evenz>
  @action: Returns an array of all even integers within the range (from start to stop).
  @note:
    - Works for ascending, descending, and single-element ranges.
    - Handles negative numbers correctly.
    - Uses Direction to step properly through the range.
    - Skips the first element if it is odd.
[==============================================================================}
function TRange.Evenz: TIntegerArray; overload;
var
  i, s, d: Integer;
begin
  SetLength(Result, Self.EvenCount);
  if (Result.Size = 0) then
    Exit;
  d := Self.Direction;
  s := Self.start;
  if s.Odd then
    s := (s + d);
  for i := 0 to High(Result) do
    Result[i] := s.Increase(2 * d);
end;

{==============================================================================]
  <TRange.Oddz>
  @action: Returns an array of all odd integers within the range (from start to stop).
  @note:
    - Works for ascending, descending, and single-element ranges.
    - Handles negative numbers correctly.
    - Uses Direction to step properly through the range.
    - Skips the first element if it is even.
[==============================================================================}
function TRange.Oddz: TIntegerArray; overload;
var
  i, s, d: Integer;
begin
  SetLength(Result, Self.OddCount);
  if (Result.Size = 0) then
    Exit;
  d := Self.Direction;
  s := Self.start;
  if s.Even then
    s := (s + d);
  for i := 0 to High(Result) do
    Result[i] := s.Increase(2 * d);
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
