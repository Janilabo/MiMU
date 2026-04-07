{$IFDEF HELPERS}
function Amounts: TInt64Array; overload;
function Counts: TIntegerArray; overload;
function Lengths: TIntegerArray; overload;
function Sized: Int64; overload;
function Sizes: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Amounts>
  @action: Returns an array containing the amount of each range in the array.
  @note: Output array length matches source; each element maps to corresponding range.Amount.
[==============================================================================}
function TRangeArrayHelper.Amounts: TInt64Array; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Result) do
    Result[i] := Self[i].Amount;
end;

{==============================================================================]
  <Counts>
  @action: Returns an array containing the count of each range in the array.
  @note: Output array length matches source; each element maps to corresponding range.Count.
[==============================================================================}
function TRangeArrayHelper.Counts: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Result) do
    Result[i] := Self[i].Count;
end;

{==============================================================================]
  <Lengths>
  @action: Returns an array containing the length of each range in the array.
  @note: Output array length matches source; each element maps to corresponding range.Length.
[==============================================================================}
function TRangeArrayHelper.Lengths: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Result) do
    Result[i] := Self[i].Length;
end;

{==============================================================================]
  <Sized>
  @action: Computes the total size across all ranges in the array.
  @note: Accumulates range.Size into Int64 result.
[==============================================================================}
function TRangeArrayHelper.Sized: Int64; overload;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Inc(Result, Self[i].Size);
end;

{==============================================================================]
  <Sizes>
  @action: Returns an array containing the size of each range in the array.
  @note: Output array length matches source; each element maps to corresponding range.Size. 
[==============================================================================}
function TRangeArrayHelper.Sizes: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Result) do
    Result[i] := Self[i].Size;
end;
{$ENDIF}
