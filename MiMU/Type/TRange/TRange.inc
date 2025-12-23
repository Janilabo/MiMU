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
  {$I TRange.pph}
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
  {$I TRange.pph}
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I ../Core.inc}
{$I TRange.pph}
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
