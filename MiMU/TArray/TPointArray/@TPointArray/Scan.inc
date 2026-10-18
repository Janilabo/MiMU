{$IFDEF HELPERS}
function Xvalued(const value: Integer): TIntegerArray; overload;
function Xvalued(const values: TIntegerArray): TIntegerArray; overload;
function Yvalued(const value: Integer): TIntegerArray; overload;
function Yvalued(const values: TIntegerArray): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Xvalued>
  @action: Returns the indices of all points whose X coordinate equals the given value.
  @note: Single linear pass that preallocates Self.Length and trims to the match count.
         Indices come out in ascending order (original array order). Returns an empty
         array if Self is empty or no point matches. Does not modify Self.
[==============================================================================}
function TPointArrayHelper.Xvalued(const value: Integer): TIntegerArray; overload;
var
  i, r: Integer;
begin
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  r := 0;
  for i := 0 to High(Self) do
    if (Self[i].X = value) then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;

{==============================================================================]
  <Xvalued>
  @action: Returns the indices of all points whose X coordinate equals any of the
           given values.
  @note: Sorts a copy of values once (QuickSorted), then tests each point's X with a
         binary search, so the cost is O(k log k + n log k) for k values and n points.
         Indices come out in ascending order (original array order). Duplicate
         entries in values are harmless. Returns an empty array if Self or values is
         empty, or nothing matches. Does not modify Self or values.
[==============================================================================}
function TPointArrayHelper.Xvalued(const values: TIntegerArray): TIntegerArray; overload;
var
  i, r: Integer;
  v: TIntegerArray;
begin
  if (values.Length = 0) then
    Exit([]);
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  v := values.QuickSorted;
  r := 0;
  for i := 0 to High(Self) do
    if v.BinaryContains(Self[i].X) then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;

{==============================================================================]
  <Yvalued>
  @action: Returns the indices of all points whose Y coordinate equals the given value.
  @note: Single linear pass that preallocates Self.Length and trims to the match count.
         Indices come out in ascending order (original array order). Returns an empty
         array if Self is empty or no point matches. Does not modify Self.
[==============================================================================}
function TPointArrayHelper.Yvalued(const value: Integer): TIntegerArray; overload;
var
  i, r: Integer;
begin
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  r := 0;
  for i := 0 to High(Self) do
    if (Self[i].Y = value) then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;

{==============================================================================]
  <Yvalued>
  @action: Returns the indices of all points whose Y coordinate equals any of the
           given values.
  @note: Sorts a copy of values once (QuickSorted), then tests each point's Y with a
         binary search, so the cost is O(k log k + n log k) for k values and n points.
         Indices come out in ascending order (original array order). Duplicate
         entries in values are harmless. Returns an empty array if Self or values is
         empty, or nothing matches. Does not modify Self or values.
[==============================================================================}
function TPointArrayHelper.Yvalued(const values: TIntegerArray): TIntegerArray; overload;
var
  i, r: Integer;
  v: TIntegerArray;
begin
  if (values.Length = 0) then
    Exit([]);
  if (Result.SetSize(Self.Length) = 0) then
    Exit;
  v := values.QuickSorted;
  r := 0;
  for i := 0 to High(Self) do
    if v.BinaryContains(Self[i].Y) then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;
{$ENDIF}
