{$IFDEF HELPERS}
function Attach(const items: MArray): Integer; overload;
function Embed(const items: MArray; const index: Integer = 2147483647): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Attach>
  @action: ppends all elements from the given array to the end of Self.
           Returns the new total length of the array after appending.
  @note: Uses Move() for efficiency.
         If the input array is empty, the function returns the current length
         of Self without modification.
[==============================================================================}
function MArrayHelper.Attach(const items: MArray): Integer; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  i := items.Size;
  if (i = 0) then
    Exit(l);
  Result := Self.SetSize(l + i);
  Move(items[0], Self[l], (i * SizeOf(MType)));
end;

{==============================================================================]
  <Embed>
  @action: Inserts the contents of another array into the current array
           at the specified index. Existing elements from that position onward
           are shifted to make room for the new items.
  @note: If the index exceeds the current length, the items are appended.
         Passing an empty array leaves the original array unchanged.
         The function returns the new total element count.
[==============================================================================}
function MArrayHelper.Embed(const items: MArray; const index: Integer = 2147483647): Integer; overload;
var
  s, l, p, t: Integer;
begin
  s := Self.Size;
  l := items.Length;
  if (l = 0) then
    Exit(s);
  p := EnsureRange(index, 0, s);
  t := (s - p);
  SetLength(Self, (s + l));
  if (t > 0) then
    Move(Self[p], Self[p + l], (t * SizeOf(MType)));
  Move(items[0], Self[p], (l * SizeOf(MType)));
  Result := Self.Size;
end;
{$ENDIF}
