{$IFDEF OPERATORS}
operator +(const a, b: TRange): TRange;
operator -(const a, b: TRange): TRange;
operator =(const a, b: TRange): Boolean;
operator <>(const a, b: TRange): Boolean;

operator in(const I: Integer; const R: TRange): Boolean;
operator shl(const R: TRange; const N: Integer): TRange;
operator shr(const R: TRange; const N: Integer): TRange;

operator := (const I: Integer): TRange;
operator := (const S: TByteSet): TRange;
operator := (const A: TIntegerArray): TRange;
operator := (const R: TRange): TIntegerArray;
operator := (const R: TRange): string;

operator Explicit(const R: TRange): TIntegerArray;
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

{==============================================================================]
  <shl>
  @action: Shrinks the range by dividing both bounds by 2^N.
  @note: Scale Down
[==============================================================================}
operator shl(const R: TRange; const N: Integer): TRange;
begin
  Result.start := (R.start shr N);
  Result.stop := (R.stop shr N);
end;

{==============================================================================]
  <shr> 
  @action: Expands the range by multiplying both bounds by 2^N.
  @note: Scale Up
[==============================================================================}
operator shr(const R: TRange; const N: Integer): TRange;
begin
  Result.start := (R.start shl N);
  Result.stop := (R.stop shl N);
end;

operator := (const I: Integer): TRange;
begin
  Result.start := I;
  Result.stop := I;
end;

operator := (const S: TByteSet): TRange;
var
  i: Byte;
begin
  Result.start := 255;
  Result.stop := 0;
  for i := 0 to 255 do
    if i in S then
      if (i < Result.start) then
	    Result.start := i
      else if (i > Result.stop) then
	    Result.stop := i;
end;

operator := (const A: TIntegerArray): TRange;
var
  i: Integer;
begin
  if (Length(A) > 0) then
  begin
    Result.start := A[0];
    Result.stop := A[0];
    for i := 1 to High(A) do
      if (A[i] < Result.start) then
	    Result.start := A[i]
      else if (A[i] > Result.stop) then
	    Result.stop := A[i];
  end;
end;

operator := (const R: TRange): TIntegerArray;
var
  i, h: Integer;
begin
  SetLength(Result, (Abs(R.stop - R.start) + 1));
  h := 0;
  case (R.start <= R.stop) of
    True:
    for i := R.start to R.stop do
      Result[h.Increase] := i;
    False:
    for i := R.start downto R.stop do
      Result[h.Increase] := i;
  end;
end;

operator := (const R: TRange): string;
begin
  Result := Format('%d..%d', [R.start, R.stop]);
end;

operator Explicit(const R: TRange): TIntegerArray;
var
  i, l, s: Integer;
begin
  SetLength(Result, R.Size);
  s := IfThen(R.Descending, -1, 1);
  for i := 0 to High(Result) do
    Result[i] := (R.start + (i * s));
end;
{$ENDIF}
