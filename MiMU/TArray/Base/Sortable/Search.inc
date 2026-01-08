{$IFDEF HELPERS}
function Spanning(const item: MType; const oAscending: Boolean = True): TRange; overload; cdecl;
function FibonacciSearch(const item: MType; const oAscending: Boolean = True): Integer; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Spanning>
  @action: Searches the array for the specified `item` and returns a TRange
           representing the inclusive index span where `item` occurs.
           Works for both ascending and descending arrays, as specified by `oAscending`.
           If the array is empty or the item is not found, returns a sentinel TRange
           with both `start` and `stop` set to Low(Integer).
  @note:
    - `oAscending` indicates whether the array is sorted in ascending order (True)
      or descending order (False).
    - Scans from both ends of the array:
        - `Result.start` increments until the first occurrence of `item` is found.
        - `Result.stop` decrements until the last occurrence of `item` is found.
    - Works correctly with negative numbers.
    - Returned TRange:
        - `Result.start <= Result.stop` → item found; range of indices inclusive.
        - `Result.start > Result.stop` → item not found; sentinel range returned.
    - Time complexity: O(n) (linear search).
[==============================================================================}
function MArrayHelper.Spanning(const item: MType; const oAscending: Boolean = True): TRange; overload; cdecl;
begin
  if Self.Empty then
    Exit(TRange.Construct(Low(Integer), Low(Integer)));
  Result.Create(0, High(Self));
  while ((Result.start < Result.stop) and ((oAscending and (Self[Result.start] < item)) or ((not oAscending) and (Self[Result.start] > item)))) do
    Inc(Result.start);
  while ((Result.stop >= Result.start) and ((oAscending and (Self[Result.stop] > item)) or ((not oAscending) and (Self[Result.stop] < item)))) do
    Dec(Result.stop);
  if (Result.start > Result.stop) then
    Result.Create(Low(Integer));
end;

{==============================================================================]
  <FibonacciSearch>
  @action: Executes a Fibonacci Search over the array.
           The routine locates the index of a target value using progressively
           shrinking search intervals determined by the Fibonacci sequence.
           The array may be sorted in ascending or descending order as
           specified by the oAscending parameter. Returns the index of the 
           matching element if found; otherwise returns -1.
  @note: Fibonacci Search is an alternative to binary search that partitions
         the search interval using Fibonacci ratios rather than powers of two.
         It preserves ordered-search correctness while enabling searches that
         favor sequential access patterns. Performance is comparable to 
         binary search for random-access arrays and may offer advantages for 
         memory-hierarchy–sensitive workloads. The input array must be
         pre-sorted in the order defined by oAscending.
[==============================================================================}
function MArrayHelper.FibonacciSearch(const item: MType; const oAscending: Boolean = True): Integer; overload; cdecl;
var
  M: Integer;
  H, o, i: Integer;
  F: TRange;
begin
  H := High(Self);
  F.Create(0, 1);
  M := (F.stop + F.start);
  while (M < (H + 1)) do
  begin
    F.start := F.stop;
    F.stop := M;
    M := (F.stop + F.start);
  end;
  o := -1;
  while (M > 1) do
  begin
    i := Integer(o + F.start).ClampMax(H);
    case ((oAscending and (Self[i] < item)) or ((not oAscending) and (Self[i] > item))) of
      True:
      begin
        M := F.stop;
        F.stop := F.start;
        F.start := (M - F.stop);
        o := i;
      end;
      False:
      case ((oAscending and (Self[i] > item)) or ((not oAscending) and (Self[i] < item))) of
        True:
        begin
          M := F.start;
          F.stop := (F.stop - F.start);
          F.start := (M - F.stop);
        end;
        False: Exit(i);
      end;
    end;
  end;
  if ((F.stop = 1) and ((o + 1) <= H) and (Self[o + 1] = item)) then
    Exit(o + 1);
  Result := -1;
end;
{$ENDIF}