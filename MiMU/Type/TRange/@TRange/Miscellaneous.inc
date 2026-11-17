{$IFDEF METHODS}
function Deconstruct(var rStart, rStop: Integer): Integer; overload;
function Progress(const pPercent: Double): Integer; overload;
function Reserve: TIntegerArray; overload;
function Reserve(var aRange: TIntegerArray): Integer; overload;
function Stippled: TIntegerArray; overload;
function YoYo: TIntegerArray; overload;
{$ENDIF}

{$IFDEF HELPERS}
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
function TRange.Progress(const pPercent: Double): Integer; overload;
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
  Result := aRange.SetSize(Self.Size);
end;

function TRangeHelper.Select(const arr: TIntegerArray): TIntegerArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Asceal, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

function TRangeHelper.Select(const arr: TDoubleArray): TDoubleArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Asceal, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

function TRangeHelper.Select(const arr: TStringArray): TStringArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Asceal, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

function TRangeHelper.Select(const arr: TCharArray): TCharArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Asceal, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

function TRangeHelper.Select(const arr: TBooleanArray): TBooleanArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Asceal, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

function TRangeHelper.Select(const arr: TPointArray): TPointArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Asceal, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

function TRangeHelper.Select(const arr: TBoxArray): TBoxArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Asceal, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

function TRangeHelper.Select(const arr: TRangeArray): TRangeArray; overload;
var
  i, s, l: Integer;
begin
  l := Self.Size;
  SetLength(Result, l);
  s := IFThen(Self.Asceal, 1, -1);
  for i := 0 to (l - 1) do
    Result[i] := arr[Self.start + (i * s)];
end;

{==============================================================================]
  <Stippled>
  @action: Materializes the range into a standard sequential array.
  @note: 
    - Logic: Employs a non-linear "dot-filling" strategy. It utilizes a 
      congruential mapping (((i * 7) + 1) mod s) to determine the write 
      destination.
    - Semantic: Like a pointillist painting, the range is "stippled" into 
      memory. The indices are visited in a pseudo-random order, yet the 
      final array is perfectly ordered.
    - Purpose: Demonstrates index-value independence and tests cache 
      performance under non-sequential write patterns.
[==============================================================================}
function TRange.Stippled: TIntegerArray; overload;
var
  i, r, s, d: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  d := Self.Direction;
  for i := 0 to (s - 1) do
  begin
    r := (((i * 7) + 1) mod s);
    Result[r] := (Self.start + (r * d));
  end;
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
