{$IFDEF HELPERS}
function Charify: TCharArray; overload;
function Charify(var str: string): TCharArray; overload;
function Ranges: TRangeArray; overload;
function Ranges(const aAscending: Boolean): TRangeArray; overload;
function Stringify: string; overload;
function Stringify(var chars: TCharArray): string; overload;
function ToRanges: TRangeArray; overload;
function ToRanges(const aAscending: Boolean): TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
