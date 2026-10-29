{$IFDEF HELPERS}
function SlidingCount(const item: MType; const wWidth: Integer = 2): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <SlidingCount>
  @action: Returns how many times item occurs in every window of the given width.
  @note: The result has (Self.Length - wWidth + 1) elements. Returns an empty
         array if wWidth < 1 or wWidth > Self.Length. O(n): the count is updated
         by the entering and leaving element only.
[==============================================================================}
function MArrayHelper.SlidingCount(const item: MType; const wWidth: Integer = 2): TIntegerArray; overload;
var
  i, s, r: Integer;
begin
  s := Self.Length;
  if ((wWidth < 1) or (wWidth > s)) then
    Exit([]);
  SetLength(Result, (s - wWidth + 1));
  r := 0;
  for i := 0 to (wWidth - 1) do
    if (Self[i] = item) then
      Inc(r);
  Result[0] := r;
  for i := wWidth to (s - 1) do
  begin
    if (Self[i] = item) then
      Inc(r);
    if (Self[i - wWidth] = item) then
      Dec(r);
    Result[i - wWidth + 1] := r;
  end;
end;
{$ENDIF}