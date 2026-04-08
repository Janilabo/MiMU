{$IFDEF HELPERS}
function AsRanges(const oAscending: Boolean = True): TRangeArray; overload;
function Charify: TCharArray; overload;
function Charify(var str: string): TCharArray; overload;
function Intervals: TRangeArray; overload;
function Ranges: TRangeArray; overload;
function Ranges(const aAscending: Boolean): TRangeArray; overload;
function Stringify: string; overload;
function Stringify(var chars: TCharArray): string; overload;
function ToRanges: TRangeArray; overload;
function ToRanges(const aAscending: Boolean): TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsRanges>
  @action: Transforms an integer array into a minimal set of contiguous ranges
           (TRangeArray), grouping consecutive values into interval segments.
           The result is a run-length style compression where each range represents
           a maximal sequence of adjacent integers.
  @note:
    - Preprocessing:
        * Input is sorted using QuickSorted(oAscending).
        * Duplicate values are removed via Compress.
    - Adjacency rule:
        * Ascending:
            consecutive if s[i] = previous.stop + 1
        * Descending:
            consecutive if s[i] = previous.stop - 1
        Controlled by:
            d := +1 (ascending) or -1 (descending)
    - Algorithm:
        1. Initialize first range with s[0].
        2. Iterate through sorted unique values:
            * If current value continues the active range → extend stop
            * Otherwise → start a new range
        3. Trim result to the number of constructed ranges
    - Output:
        * Each range is maximal (no two adjacent ranges can be merged further).
        * Ranges preserve ordering based on oAscending.
    - Complexity:
        * Sorting:     O(n log n)
        * Compression: O(n)
        * Scan:        O(n)
        * Overall:     O(n log n)
    - Edge cases:
        * Empty input → returns empty array
        * Single element → single-point range [x, x]
    - Characteristics:
        * Non-destructive (operates on a sorted copy).
        * Eliminates duplicates before range construction.
        * Produces canonical segmentation of discrete values.
[==============================================================================}
function TIntegerArrayHelper.AsRanges(const oAscending: Boolean = True): TRangeArray; overload;
var
  s: TIntegerArray;
  i, l, d: Integer;
begin
  if (Self.Length = 0) then
    Exit([]);
  s := Self.QuickSorted(oAscending);
  s.Compress;
  SetLength(Result, s.Length);
  l := 0;
  Result[0].Create(s[0], s[0]);
  d := IfThen(oAscending, 1, -1);
  for i := 1 to High(s) do
    if (s[i] = (Result[l].stop + d)) then
      Result[l].stop := s[i]
    else
      Result[l.Increment].Create(s[i], s[i]);
  SetLength(Result, (l + 1));
end;

{==============================================================================]
  <Charify>
  @action: Converts TIntegerArray to Chars.
  @note: Make sure the values in array are correct!
[==============================================================================}
function TIntegerArrayHelper.Charify: TCharArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Chr(Self[i]);
end;

{==============================================================================]
  <Charify>
  @action: Converts TIntegerArray to Chars.
  @note: Make sure the values in array are correct!
         Stores str version to variable.
[==============================================================================}
function TIntegerArrayHelper.Charify(var str: string): TCharArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  SetLength(str, Self.Size);
  for i := 0 to High(Self) do
  begin
    Result[i] := Chr(Self[i]);
    str[i + 1] := Result[i];
  end;
end;

{==============================================================================]
  <Intervals>
  @action: Returns an array of ranges representing consecutive elements in
           the current integer array. Each range spans from one element to
           the next (i.e., [Self[i]..Self[i+1]]).
  @note: - If the array is empty, the result is empty.  
         - If the array has one element, the result contains a single
           range from that element to itself.  
         - The order of elements is preserved, and the resulting array
           length is `Length(Self)-1` for arrays with two or more elements.
         - Useful for constructing intervals between consecutive numbers.
[==============================================================================}
function TIntegerArrayHelper.Intervals: TRangeArray; overload;
var
  i, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([TRange.Construct(Self[0], Self[0])]);
  end;
  SetLength(Result, (l - 1));
  for i := 0 to High(Result) do
    Result[i].Create(Self[i], Self[i + 1]);
end;

{==============================================================================]
  <Ranges>
  @action: Converts the integer array into an array of consecutive ranges (TRangeArray)
           using overlapping ranges. Each range represents a sequence of consecutive
           integers (ascending or descending) in the array. A new range starts from
           the previous range’s stop whenever the sequence trend breaks.
  @note: - Returns an empty array if the source array is empty.
         - If the array has one element, the range has Start = Stop.
         - If the array has two elements, the range covers both values.
         - The direction (ascending/descending) is determined automatically.
         - Overlapping ensures that each new range starts from the last stop.
         - Useful for compressing sequences or detecting consecutive runs.
[==============================================================================}
function TIntegerArrayHelper.Ranges: TRangeArray; overload;
var
  h, l, d, s, i: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([TRange.Construct(Self[0], Self[0])]);
    2: Exit([TRange.Construct(Self[0], Self[1])]);
  end;
  SetLength(Result, l);
  h := 0;
  Result[0].Create(Self[0], Self[1]);
  d := Result[0].Direction;
  i := 2;
  repeat
    s := Result[h].stop.Sign(Self[i]);
    case ((d = 0) or ((s = 0) or (s = d))) of
      True:
      begin
        if (d = 0) then
          d := s;
        Result[h].stop := Self[i];
      end;
      False:
      begin
        d := 0;
        Result[h.Increment].Create(Self[i.Decrement]);
      end;
    end;
  until (i.Increment >= l);
  SetLength(Result, (h + 1));
end;

{==============================================================================]
  <Ranges>
  @action: Converts the integer array into an array of ranges (TRangeArray) following
           a specific direction (ascending or descending) using overlapping ranges.
           Each range starts from the previous range’s stop and continues in the
           specified direction until the trend breaks.
  @note: - If aAscending = True, ranges only include ascending steps.
         - If aAscending = False, ranges only include descending steps.
         - Repeated values (0 sign) are included in the same range.
         - Returns empty array for empty input; single-element arrays produce
           a single-element range.
         - Useful for generating directional ranges with overlaps.
[==============================================================================}
function TIntegerArrayHelper.Ranges(const aAscending: Boolean): TRangeArray; overload;
var
  h, l, d, s, i: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([TRange.Construct(Self[0], Self[0])]);
  end;
  SetLength(Result, l);
  h := 0;
  Result[0].Create(Self[0]);
  d := IfThen(aAscending, 1, -1);
  i := 1;
  repeat
    s := Result[h].stop.Sign(Self[i]);
    if ((s = 0) or (s = d)) then
      Result[h].stop := Self[i]
    else
      Result[h.Increment].Create(Self[i]);
  until (i.Increment >= l);
  SetLength(Result, (h + 1));
end;

{==============================================================================]
  <Stringify>
  @action: Converts TIntegerArray to string.
  @note: Make sure the values in array are correct!
[==============================================================================}
function TIntegerArrayHelper.Stringify: string; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i + 1] := Chr(Self[i]);
end;

{==============================================================================]
  <Stringify>
  @action: Converts TIntegerArray to Chars.
  @note: Make sure the values in array are correct!
         Stores charset version to variable.
[==============================================================================}
function TIntegerArrayHelper.Stringify(var chars: TCharArray): string; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  SetLength(chars, Self.Size);
  for i := 0 to High(Self) do
  begin
    Result[i + 1] := Chr(Self[i]);
    chars[i] := Result[i];
  end;
end;

{==============================================================================]
  <ToRanges>
  @action: Converts the integer array into an array of consecutive ranges (TRangeArray).
           Each range represents a sequence of consecutive numbers (ascending or descending)
           found in the array. A new range starts whenever the consecutive trend breaks.
  @note: - Returns an empty array if the source array is empty.
         - Single-element arrays produce a single range with identical Start and Stop.
         - Two-element arrays produce a single range covering the two values.
         - Direction of each range (ascending or descending) is determined automatically.
         - Useful for compressing sequences or detecting consecutive runs in arrays.
[==============================================================================}
function TIntegerArrayHelper.ToRanges: TRangeArray; overload;
var
  h, l, d, s, i: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([TRange.Construct(Self[0], Self[0])]);
    2: Exit([TRange.Construct(Self[0], Self[1])]);
  end;
  SetLength(Result, l);
  h := 0;
  Result[0].Create(Self[0], Self[1]);
  d := Result[0].Direction;
  for i := 2 to (l - 1) do
  begin
    s := Result[h].stop.Sign(Self[i]);
    case ((d = 0) or ((s = 0) or (s = d))) of
      True:
      begin
        if (d = 0) then
          d := s;
        Result[h].stop := Self[i];
      end;
      False:
      begin
        d := 0;
        Result[h.Increment].Create(Self[i]);
      end;
    end;
  end;
  SetLength(Result, (h + 1));
end;

{==============================================================================]
  <ToRanges>
  @action: Converts the integer array into an array of ranges (TRangeArray) following
           a specific direction as indicated by aAscending.
           Each range extends in the requested direction until a break occurs.
  @note: - If aAscending = True, only ascending sequences (+1) are allowed in a range.
         - If aAscending = False, only descending sequences (-1) are allowed in a range.
         - Sequences that match the specified direction or repeat the same value
           are merged into the same range.
         - Returns empty array for empty input and single-element array produces
           a single-element range.
         - Useful when you want ranges restricted to a specific direction.
[==============================================================================}
function TIntegerArrayHelper.ToRanges(const aAscending: Boolean): TRangeArray; overload;
var
  h, l, d, s, i: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([TRange.Construct(Self[0], Self[0])]);
  end;
  SetLength(Result, l);
  h := 0;
  Result[0].Create(Self[0]);
  d := IfThen(aAscending, 1, -1);
  for i := 1 to (l - 1) do
  begin
    s := Result[h].stop.Sign(Self[i]);
    if ((s = 0) or (s = d)) then
      Result[h].stop := Self[i]
    else
      Result[h.Increment].Create(Self[i]);
  end;
  SetLength(Result, (h + 1));
end;
{$ENDIF}
