{$IFDEF METHODS}
function Deconstruct(var rStart, rStop: Integer): Integer; overload;
function Progress(const pPercent: Double): Integer;
function Reserve: TIntegerArray; overload;
function Reserve(var aRange: TIntegerArray): Integer; overload;
function YoYo: TIntegerArray; overload;
{$ENDIF}

{$IFDEF HELPERS}
function Complement(const target: TRange): TRangeArray; overload;
function Cutout(const target: TRange): TRangeArray; overload;
function Select(const arr: TIntegerArray): TIntegerArray; overload;
function Select(const arr: TDoubleArray): TDoubleArray; overload;
function Select(const arr: TStringArray): TStringArray; overload;
function Select(const arr: TCharArray): TCharArray; overload;
function Select(const arr: TBooleanArray): TBooleanArray; overload;
function Select(const arr: TPointArray): TPointArray; overload;
function Select(const arr: TBoxArray): TBoxArray; overload;
function Select(const arr: TRangeArray): TRangeArray; overload;
{$ENDIf}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Complement>
  @action: Performs a relative set difference (Self \ target). Returns an 
           array of ranges representing the portions of 'Self' that are 
           not covered by 'target'.
  @param: target - The range to be "subtracted" from the current instance.
  @return: A TRangeArray containing 0, 1, or 2 ranges depending on the 
           overlap topology.
  @note: - Discrete Logic: Uses +/- 1 offsets, assuming integer-like step 
           boundaries.
         - Normalization: Automatically handles ranges where start > stop.
         - Total Overlap: Returns an empty array if 'target' encompasses 'Self'.
[==============================================================================}
function TRangeHelper.Complement(const target: TRange): TRangeArray; overload;
var
  s, t: TRange;
begin
  SetLength(Result, 0);
  s := Self.Normalized;
  t := target.Normalized;
  if ((t.stop < s.start) or (t.start > s.stop)) then
    Exit([Self]);
  if (t.start > s.start) then
    Result.Supply(TRange.Construct(s.start, (t.start - 1)));
  if (t.stop < s.stop) then
    Result.Supply(TRange.Construct((t.stop + 1), s.stop));
end;

{==============================================================================]
  <Cutout>
  @action: Subtracts the target range from Self, returning the remaining pieces.
  @return: A TRangeArray containing:
           - 0 elements: If Self was completely consumed by target.
           - 1 element:  If Self was clipped at one end or not hit at all.
           - 2 elements: If the target punched a hole through the middle of Self.
[==============================================================================}
function TRangeHelper.Cutout(const target: TRange): TRangeArray; overload;
var
  s, t: TRange;
  procedure C(const A, B: Integer);
  begin
    SetLength(Result, (Result.Length + 1));
    if Self.Ascending then
      Result[High(Result)] := TRange.Construct(A, B)
    else
      Result[High(Result)] := TRange.Construct(B, A);
  end;
begin
  if not Self.Intersects(target) then
    Exit([Self]);
  s := Self.Normalized;
  t := target.Normalized;
  SetLength(Result, 0);
  if (s.start < t.start) then
    C(s.start, (t.start - 1));
  if (s.stop > t.stop) then
    C((t.stop + 1), s.stop);
  if Self.Descending then
    Result.Reverse;
end;

{==============================================================================]
  <Deconstruct>
  @action: Outputs the Start and Stop bounds of the range via reference parameters and returns its Size.
  @note: This is a non-mutating structural deconstruction of the range.
         The bounds are returned exactly as stored (not normalized),
		 and the function result represents the range cardinality.
[==============================================================================}
function TRange.Deconstruct(var rStart, rStop: Integer): Integer; overload;
begin
  rStart := Self.start;
  rStop := Self.stop;
  Result := Self.Size;
end;

{==============================================================================]
  <Progress>
  @action: Returns a position within the range corresponding to the given progress
          ratio.
          The position is calculated by linearly interpolating between Start and Stop
		  using pPercent, then rounding to the nearest integer.
  @note:
    - pPercent is expected to be in the range 0.0 .. 1.0, where:
        0.0 returns Start
        1.0 returns Stop
    - Values outside this range will extrapolate beyond the bounds.
    - No normalization is performed; Start and Stop are used as-is.
    - Rounding is applied after interpolation and may bias the result.
    - For a singular range (Start = Stop), the result equals Start regardless
      of pPercent.
[==============================================================================}
function TRange.Progress(const pPercent: Double): Integer;
begin
  Result := (Self.start + Round(Self.Delta * pPercent));
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

function TRangeHelper.Select(const arr: TIntegerArray): TIntegerArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Ascending, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

function TRangeHelper.Select(const arr: TDoubleArray): TDoubleArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Ascending, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

function TRangeHelper.Select(const arr: TStringArray): TStringArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Ascending, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

function TRangeHelper.Select(const arr: TCharArray): TCharArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Ascending, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

function TRangeHelper.Select(const arr: TBooleanArray): TBooleanArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Ascending, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

function TRangeHelper.Select(const arr: TPointArray): TPointArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Ascending, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

function TRangeHelper.Select(const arr: TBoxArray): TBoxArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Ascending, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

function TRangeHelper.Select(const arr: TRangeArray): TRangeArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Ascending, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

{==============================================================================]
  <YoYo>
  @action: Generates a symmetric “back-and-forth” sequence over the range.
  @note: Produces a palindromic expansion of the range values, starting from
         Self.start and progressing by Self.Direction to Self.stop, then
         mirroring back in reverse order (excluding the endpoint duplication).
         The resulting array has length (2 * Size - 1). If Size = 1, returns
         a single-element array [Self.start]. This is commonly used for
         oscillation-style traversal patterns.
[==============================================================================}
function TRange.YoYo: TIntegerArray; overload;
var
  i, s, d, l: Integer;
begin
  s := Self.Size;
  if (s = 1) then
    Exit([Self.start]);
  l := ((s * 2) - 1);
  SetLength(Result, l);
  d := Self.Direction;
  for i := 0 to (s - 1) do
  begin
    Result[i] := (Self.start + (i * d));
    if (i < (s - 1)) then
      Result[(l - 1) - i] := Result[i];
  end;
end;
{$ENDIF}
