{$IFDEF HELPERS}
function Amounts: TInt64Array; overload;
function Counts: TIntegerArray; overload;
function Lengths: TIntegerArray; overload;
function Sizeck: Int64; overload;
function Sizem: Int64; overload;
function Sizery: Int64; overload;
function Sizid: Int64; overload;
function Sizing: Int64; overload;
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
  for i := 0 to Result.Alloc(Self.Length) do
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
  for i := 0 to Result.Alloc(Self.Length) do
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
  for i := 0 to Result.Alloc(Self.Length) do
    Result[i] := Self[i].Length;
end;

{==============================================================================]
  <Sizeck>
  @action: Computes total unique coverage by checking off visited slots 
           in a Boolean lookup array.
  @note: Ideal for dense, bounded integer ranges.
[==============================================================================}
function TRangeArrayHelper.Sizeck: Int64; overload;
var
  m: TBooleanArray;
  b: TRange;
  i, r: Integer;
begin
  Result := 0;
  case Self.Length of
    0: Exit;
    1: Exit(Self[0].Size);
  end;
  b := Self.Bounds;
  m.Create(((b.stop - b.start) + 1), False);
  for i := 0 to High(Self) do
    for r := Self[i].Minimum to Self[i].Maximum do
      m[r - b.start] := True;
  for i := 0 to High(m) do
    if m[i] then
      Inc(Result);
end;

{==============================================================================]
  <Sizem>
  @action: Calculates the total count of unique integers covered by the ranges,
           merging any overlapping or adjacent intervals.
  @note: Sorts ranges by start value and normalizes/merges touching intervals 
         in-place in O(N log N) time, avoiding individual value iteration.
[==============================================================================}
function TRangeArrayHelper.Sizem: Int64; overload;
var
  s: TRangeArray;
  i, l: Integer;
begin
  Result := 0;
  case Self.Length of
    0: Exit;
    1: Exit(Self[0].Size);
  end;
  s := Self.SortedByMinimum.Normalized;
  l := 0;
  for i := 1 to High(s) do
    if (s[i].start > (s[l].stop + 1)) then
      s[l.Increment] := s[i]
    else if (s[i].stop > s[l].stop) then
      s[l].stop := s[i].stop;
  for i := 0 to l do
    Inc(Result, ((Int64(s[i].stop) - s[i].start) + 1));
end;

{==============================================================================]
  <Sizery>
  @action: Calculates the total count of unique integer values covered across 
           all ranges in the array.
  @note: Collects discrete values from each range into a sorted integer array 
         via BinaryGrow to eliminate duplicates, returning the resulting 
         array length.
[==============================================================================}
function TRangeArrayHelper.Sizery: Int64; overload;
var
  j, i: Integer;
  r: TIntegerArray;
begin
  case Self.Length of
    0: Exit(0);
	1: Exit(Self[0].Size);
  end;
  SetLength(r, 0);
  for i := 0 to High(Self) do
    for j := Self[i].Minimum to Self[i].Maximum do
      r.BinaryGrow(j);
  Result := r.Length;
end;

{==============================================================================]
  <Sizid>
  @action: Calculates the total count of unique integer values covered across 
           all ranges using a hash dictionary for deduplication.
  @note: Iterates through each discrete integer from Minimum to Maximum for 
         every range, inserting values into an ObjFPC specialized TDictionary 
         to eliminate duplicates.
[==============================================================================}
function TRangeArrayHelper.Sizid: Int64; overload;
var
  d: specialize TDictionary<Integer, Byte>;
  i, j: Integer;
begin
  d := specialize TDictionary<Integer, Byte>.Create;
  try
    for i := 0 to High(Self) do
      for j := Self[i].Minimum to Self[i].Maximum do
        d.AddOrSetValue(j, 0);
    Result := d.Count;
  finally
    d.Free;
  end;
end;

{==============================================================================]
  <Sizing>
  @action: Computes the total size across all ranges in the array.
  @note: Accumulates range.Size into Int64 result.
[==============================================================================}
function TRangeArrayHelper.Sizing: Int64; overload;
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
  for i := 0 to Result.Alloc(Self.Length) do
    Result[i] := Self[i].Size;
end;
{$ENDIF}
