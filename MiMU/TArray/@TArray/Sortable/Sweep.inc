{$IFDEF HELPERS}
function SlidingMax(const wWidth: Integer = 2): MArray; overload;
function SlidingMin(const wWidth: Integer = 2): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <SlidingMax>
  @action: Returns the maximum of every window of the given width as an MArray.
  @note: Result[i] is the maximum of Self[i..i + width - 1], so the result has
         (Self.Length - width + 1) elements. Returns an empty array if width < 1
         or width > Self.Length. O(n): every index enters and leaves the deque
         at most once.
[==============================================================================}
function MArrayHelper.SlidingMax(const wWidth: Integer = 2): MArray; overload;
var
  i, s, h, t: Integer;
  q: TIntegerArray;
begin
  s := Self.Length;
  if ((wWidth < 1) or (wWidth > s)) then
    Exit([]);
  Result.SetSize(s - wWidth + 1);
  h := 0;
  t := -1;
  for i := 0 to q.Alloc(s) do
  begin
    while ((t >= h) and (not (Self[q[t]] > Self[i]))) do
      Dec(t);
    q[t.Increment] := i;
    if (q[h] <= (i - wWidth)) then
      Inc(h);
    if (i >= (wWidth - 1)) then
      Result[i - wWidth + 1] := Self[q[h]];
  end;
end;

{==============================================================================]
  <SlidingMin>
  @action: Returns the minimum of every window of the given width as an MArray.
  @note: Result[i] is the minimum of Self[i..i + width - 1], so the result has
         (Self.Length - width + 1) elements. Returns an empty array if width < 1
         or width > Self.Length. O(n): every index enters and leaves the deque
         at most once.
[==============================================================================}
function MArrayHelper.SlidingMin(const wWidth: Integer = 2): MArray; overload;
var
  i, s, h, t: Integer;
  q: TIntegerArray;
begin
  s := Self.Length;
  if ((wWidth < 1) or (wWidth > s)) then
    Exit([]);
  Result.SetSize(s - wWidth + 1);
  h := 0;
  t := -1;
  for i := 0 to q.Alloc(s) do
  begin
    while ((t >= h) and (not (Self[q[t]] < Self[i]))) do
      Dec(t);
    q[t.Increment] := i;
    if (q[h] <= (i - wWidth)) then
      Inc(h);
    if (i >= (wWidth - 1)) then
      Result[i - wWidth + 1] := Self[q[h]];
  end;
end;
{$ENDIF}