{$IFDEF METHODS}
function Deconstruct(var rStart, rStop: Integer): Integer; overload;
function Progress(const pPercent: Double): Integer;
function Reserve: TIntegerArray; overload;
function Reserve(var aRange: TIntegerArray): Integer; overload;
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
{$ENDIF}
