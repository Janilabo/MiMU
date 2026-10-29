{$IFDEF HELPERS}
function SlidingBounds(const wWidth: Integer = 2): TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <SlidingBounds>
  @action: Returns the minimum and maximum of every window of the given width as a TRangeArray.
  @note: Result[i].start is the minimum and Result[i].stop is the maximum of
         Self[i..i + width - 1], so every range is ascending (start = stop when
         the window is constant). The result has (Self.Length - width + 1)
         elements. Returns an empty array if width < 1 or width > Self.Length.
         O(n): two monotonic deques, each index enters and leaves each once.
[==============================================================================}
function TIntegerArrayHelper.SlidingBounds(const wWidth: Integer = 2): TRangeArray; overload;
var
  i, n: Integer;
  a, b: TIntegerArray;
  x, y: TRange;
begin
  n := Self.Length;
  if ((wWidth < 1) or (wWidth > n)) then
    Exit([]);
  SetLength(Result, (n - wWidth + 1));
  SetLength(a, n);
  SetLength(b, n);
  x.Create(0, -1);
  y.Create(0, -1);
  for i := 0 to (n - 1) do
  begin
    while ((x.stop >= x.start) and (Self[a[x.stop]] <= Self[i])) do
      Dec(x.stop);
    Inc(x.stop);
    a[x.stop] := i;
    while ((y.stop >= y.start) and (Self[b[y.stop]] >= Self[i])) do
      Dec(y.stop);
    Inc(y.stop);
    b[y.stop] := i;
    if (a[x.start] <= (i - wWidth)) then
      Inc(x.start);
    if (b[y.start] <= (i - wWidth)) then
      Inc(y.start);
    if (i >= (wWidth - 1)) then
    begin
      Result[i - wWidth + 1].start := Self[b[y.start]];
      Result[i - wWidth + 1].stop := Self[a[x.start]];
    end;
  end;
end; 
{$ENDIF}