{$IFDEF METHODS}
function Fill(var target: TIntegerArray): Integer; overload;
function FillBackward(var arr: TIntegerArray): Integer; overload;
function FillBackwarded(var arr: TIntegerArray): Integer; overload;
function FillBackwards(var arr: TIntegerArray): Integer; overload;
function FillForward(var arr: TIntegerArray): Integer; overload;
function FillForwarded(var arr: TIntegerArray): Integer; overload;
function FillForwards(var arr: TIntegerArray): Integer; overload;
function FillRandom(var arr: TIntegerArray): Integer; overload;
function Populate(var arr: TIntegerArray): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Fill>
  @action: Fills the provided array with values from the range, respecting direction.
  @note: Returns the number of elements filled; does nothing if the target array is empty.
[==============================================================================}
function TRange.Fill(var target: TIntegerArray): Integer; overload;
var
  i, v, d: Integer;
begin
  Result := target.Length;
  if (Result = 0) then
    Exit;
  v := Self.start;
  d := Self.Direction;
  for i := 0 to (Result - 1) do
    target[i] := v.Increase(d);
end;

{==============================================================================]
  <FillBackward>
  @action: Populates the array with range values starting from Stop back toward
           Start, using the smaller of the array length or range size.
  @note: Safe execution using Min(Array.Length, Range.Size) to prevent overflows.
[==============================================================================}
function TRange.FillBackward(var arr: TIntegerArray): Integer; overload;
var
  i, n, d: Integer;
begin
  Result := Min(arr.Length, Self.Size);
  d := Self.Direction;
  for i := 0 to (Result - 1) do
    arr[i] := (Self.stop + (i * -d));
end;

{==============================================================================]
  <FillBackwarded>
  @action: Populates the entire array with the range sequence starting from
           Stop and moving backward, wrapping back to Stop if the array
           is larger than the range.
  @note: Uses a cyclic (modulo) approach. Effectively "tiles" the array
         with the reverse direction of the range.
[==============================================================================}
function TRange.FillBackwarded(var arr: TIntegerArray): Integer; overload;
var
  i, s, d: Integer;
begin
  Result := arr.Length;
  if (Result = 0) then
    Exit;
  s := Self.Size;
  d := Self.Direction;
  for i := 0 to (Result - 1) do
    arr[i] := (Self.stop + ((i mod s) * -d));
end;

{==============================================================================]
  <FillBackwards>
  @action: Populates the array with range values starting from Stop, using the
           larger of the array length or range size.
  @note: Uses Max(Array.Length, Range.Size). [Warning] Ensure the target array
         is pre-allocated to the Range Size to avoid Access Violations.
[==============================================================================}
function TRange.FillBackwards(var arr: TIntegerArray): Integer; overload;
var
  i, n, d: Integer;
begin
  Result := Max(arr.Length, Self.Size);
  d := Self.Direction;
  for i := 0 to (Result - 1) do
    arr[i] := (Self.stop + (i * -d));
end;

{==============================================================================]
  <FillForward>
  @action: Populates the array with range values starting from Start toward
           Stop, using the smaller of the array length or range size.
  @note: Safe execution using Min(Array.Length, Range.Size) to prevent overflows.
[==============================================================================}
function TRange.FillForward(var arr: TIntegerArray): Integer; overload;
var
  i, n, d: Integer;
begin
  Result := Min(arr.Length, Self.Size);
  d := Self.Direction;
  for i := 0 to (Result - 1) do
    arr[i] := (Self.start + (i * d));
end;

{==============================================================================]
  <FillForwarded>
  @action: Populates the entire array with the range sequence starting from
           Start, wrapping back to the beginning if the array is larger
           than the range.
  @note: Uses a cyclic (modulo) approach to ensure the array is fully
         tiled with range values.
[==============================================================================}
function TRange.FillForwarded(var arr: TIntegerArray): Integer; overload;
var
  i, s, d: Integer;
begin
  Result := arr.Length;
  if (Result = 0) then
    Exit;
  s := Self.Size;
  d := Self.Direction;
  for i := 0 to (Result - 1) do
    arr[i] := (Self.start + ((i mod s) * d));
end;

{==============================================================================]
  <FillForwards>
  @action: Populates the array with range values starting from Start, using the
           larger of the array length or range size.
  @note: Uses Max(Array.Length, Range.Size). [Warning] Ensure the target array
         is pre-allocated to the Range Size to avoid Access Violations.
[==============================================================================}
function TRange.FillForwards(var arr: TIntegerArray): Integer; overload;
var
  i, n, d: Integer;
begin
  Result := Max(arr.Length, Self.Size);
  d := Self.Direction;
  for i := 0 to (Result - 1) do
    arr[i] := (Self.start + (i * d));
end;

{==============================================================================]
  <FillRandom>
  @action: Populates every element of the provided array with random integers
           plotted within the inclusive bounds of the range.
  @note: Disregards range direction and sequence; relies on the system's
         Random generator. Ensure Randomize is called once at app start.
[==============================================================================}
function TRange.FillRandom(var arr: TIntegerArray): Integer; overload;
var
  i, r, s: Integer;
begin
  Result := arr.Length;
  s := Self.Minimum;
  r := ((Self.Maximum - s) + 1);
  for i := 0 to (Result - 1) do
    arr[i] := (s + Random(r));
end;

{==============================================================================]
  <Populate>
  @action: Fills the provided integer array `arr` with the sequence of values 
           represented by this TRange, respecting the ascending or descending order.
           The array must already be allocated; its length determines how many values 
           are filled. The method also returns a TRange reflecting the filled portion.
  @note:
    - If the array is empty, the method exits immediately without modification.
    - The step between elements is automatically set to +1 (ascending) or -1 (descending).
    - The `Result.start` is set to Self.start, and `Result.stop` is set to the last 
      value written to the array.
    - Unlike `Generated` or `Material`, this method **populates an existing array** 
      rather than allocating a new one.
    - Useful when you want to reuse preallocated memory for performance.
[==============================================================================}
function TRange.Populate(var arr: TIntegerArray): TRange; overload;
var
  i, s: Integer;
begin
  if arr.Empty then
    Exit;
  s := IfThen(Self.Descending, -1, 1);
  Result.start := Self.start;
  for i := 0 to High(arr) do
    arr[i] := (Self.start + (i * s));
  Result.stop := arr[High(arr)];
end;
{$ENDIF}
