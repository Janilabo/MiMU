{$IFDEF METHODS}
function Beginning(const N: Integer = 1): TIntegerArray; overload;
function Closing(const N: Integer = 1): TIntegerArray; overload;
function Ending(const N: Integer = 1): TIntegerArray; overload;
function Head(const N: Integer = 1): TIntegerArray; overload;
function Intro(const N: Integer = 1): TIntegerArray; overload;
function Lead(const N: Integer = 1): TIntegerArray; overload;
function Leading(const N: Integer = 1): TIntegerArray; overload;
function Opening(const N: Integer = 1): TIntegerArray; overload;
function Origin(const sSteps: Integer = 0): TIntegerArray; overload;
function Outro(const N: Integer = 1): TIntegerArray; overload;
function Tail(const N: Integer = 1): TIntegerArray; overload;
function Terminus(const sSteps: Integer = 0): TIntegerArray; overload;
function Trail(const N: Integer = 1): TIntegerArray; overload;
function Trailing(const N: Integer = 1): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Beginning>
  @action: Returns the first N elements using a sub-range delegation.
  @note: Clamps to Self.Size.
[==============================================================================}
function TRange.Beginning(const N: Integer = 1): TIntegerArray; overload;
begin
  Result := Range(Self.start, (Self.start + (Min(N, Self.Size) - 1) * Self.Direction)).Items;
end;

{==============================================================================]
  <Closing>
  @action: Returns the last N elements in natural order using pointer arithmetic.
  @note: Clamps to Self.Size.
[==============================================================================}
function TRange.Closing(const N: Integer = 1): TIntegerArray; overload;
var
  i, d, c: Integer;
  p: PInteger;
begin
  if (N < 1) then
    Exit([]);
  SetLength(Result, N);
  p := @Result[0];
  d := Self.Direction;
  for i := 0 to (N - 1) do
  begin
    p^ := (Self.stop - ((N - 1 - i) * d));
    Inc(p);
  end;
end;

{==============================================================================]
  <Ending>
  @action: Returns the last N elements via sub-range delegation.
  @note: Clamps to Self.Size. Natural order preserved.
[==============================================================================}
function TRange.Ending(const N: Integer = 1): TIntegerArray; overload;
begin
  Result := Range((Self.stop - ((Min(Max(N, 0), Self.Size) - 1) * Self.Direction)), Self.stop).Items;
end;

{==============================================================================]
  <Head>
  @action: Returns the first N elements from the range, starting at `start` and progressing in `Direction`.
  @note: Does not clamp to range bounds; if N exceeds the logical range length, values may extend beyond `stop`.
[==============================================================================}
function TRange.Head(const N: Integer = 1): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Max(0, N));
  for i := 0 to (N - 1) do
    Result[i] := (Self.start + (i * Self.Direction));
end;

{==============================================================================]
  <Intro>
  @action: Returns the first N values of the range.
  @note: If N >= Size the full range is returned. N <= 0 returns empty array.
[==============================================================================}
function TRange.Intro(const N: Integer = 1): TIntegerArray; overload;
var
  i, d: Integer;
begin
  if (N < 1) then
    Exit([]);
  SetLength(Result, Min(N, Self.Size));
  d := IfThen(Self.Ascending, 1, -1);
  for i := 0 to High(Result) do
    Result[i] := (Self.start + (i * d));
end;

{==============================================================================]
  <Lead>
  @action: Returns the first N elements from the range.
  @note: N is clamped to [0, Size]. Elements are copied in original order.
[==============================================================================}
function TRange.Lead(const N: Integer = 1): TIntegerArray; overload;
begin
  if (N > 0) then
    Result := Self.Items;
  SetLength(Result, Min(Max(0, N), Self.Size));
end;

{==============================================================================]
  <Leading>
  @action: Returns the first N elements from the range.
  @note: N is clamped to [0, Size]. Elements are copied in original order.
[==============================================================================}
function TRange.Leading(const N: Integer = 1): TIntegerArray; overload;
var
  i, c, v, d: Integer;
begin
  c := Min(Max(0, N), Self.Size);
  SetLength(Result, c);
  d := Self.Direction;
  v := Self.start;
  for i := 0 to (c - 1) do
    Result[i] := v.Increase(d);
end;

{==============================================================================]
  <Opening>
  @action: Returns the first N elements using pointer arithmetic.
  @note: Does not clamp to range bounds.
[==============================================================================}
function TRange.Opening(const N: Integer = 1): TIntegerArray; overload;
var
  i, d: Integer;
  p: PInteger;
begin
  if (N < 1) then
    Exit([]);
  SetLength(Result, N);
  p := @Result[0];
  d := Self.Direction;
  for i := 0 to (N - 1) do
  begin
    p^ := (Self.start + (i * d));
    Inc(p);
  end;
end;

{==============================================================================]
  <Origin>
  @action: Returns a contiguous segment anchored at `start`,
           extending `sSteps` steps along the range direction (inclusive of the origin element).
  @note: Result length is `sSteps + 1`. Does not clamp to range bounds; may extend beyond `stop`.
[==============================================================================}
function TRange.Origin(const sSteps: Integer = 0): TIntegerArray; overload;
begin
  Result := TRange.Construct(Self.start, IfThen(Self.Ascending, (Self.start + sSteps), (Self.start - sSteps))).Items;
end;

{==============================================================================]
  <Outro>
  @action: Returns the last N values of the range.
  @note: If N >= Size the full range is returned. N <= 0 returns empty array.
[==============================================================================}
function TRange.Outro(const N: Integer = 1): TIntegerArray; overload;
var
  i, d, c: Integer;
begin
  if (N < 1) then
    Exit([]);
  c := Min(N, Self.Size);
  SetLength(Result, c);
  d := IfThen(Self.Ascending, 1, -1);
  for i := 0 to High(Result) do
    Result[i] := (Self.stop - ((c - 1 - i) * d));
end;

{==============================================================================]
  <Tail>
  @action: Returns the last N elements from the range, starting at `stop` and progressing backward using `Direction`.
@note: Order is reversed relative to the range direction; does not clamp to range bounds, so results may extend past `start`.
[==============================================================================}
function TRange.Tail(const N: Integer = 1): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Max(0, N));
  for i := 0 to High(Result) do
    Result[i] := (Self.stop - (i * Self.Direction));
end;

{==============================================================================]
  <Terminus>
  @action: Returns a contiguous segment anchored at `stop`,
           extending `sSteps` steps opposite to the range direction (inclusive of the terminal element).
  @note: Result length is `sSteps + 1`. Does not clamp to range bounds; may extend beyond `start`.
[==============================================================================}
function TRange.Terminus(const sSteps: Integer = 0): TIntegerArray; overload;
begin
  Result := TRange.Construct(Self.stop, IfThen(Self.Ascending, (Self.stop - sSteps), (Self.stop + sSteps))).Items;
end;

{==============================================================================]
  <Trail>
  @action: Returns the last N elements from the range.
  @note: N is clamped to [0, Size]. Elements are returned in reverse order.
[==============================================================================}
function TRange.Trail(const N: Integer = 1): TIntegerArray; overload;
begin  
  if (N > 0) then
    Result := Self.Reversed.Items;
  SetLength(Result, Min(Max(0, N), Self.Size));
end;

{==============================================================================]
  <Trailing>
  @action: Returns the last N elements from the range.
  @note: N is clamped to [0, Size]. Elements are returned in reverse order.
[==============================================================================}
function TRange.Trailing(const N: Integer = 1): TIntegerArray; overload;
var
  i, c, v, d: Integer;
begin
  c := Min(Max(0, N), Self.Size);
  SetLength(Result, c);
  d := Self.Direction;
  v := (Self.start + (Self.Size - c) * d);
  for i := 0 to (c - 1) do
    Result[(c - i) - 1] := v.Increase(d);
end;
{$ENDIF}
