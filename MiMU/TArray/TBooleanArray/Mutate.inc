{$IFDEF HELPERS}
function Attach(const items: TBooleanArray): Integer; overload;
function Embed(const items: TBooleanArray; const index: Integer = 2147483647): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Attach>
  @action: Appends all booleans from the given array to the end of Self.
           Returns the new total length of the array after appending.
  @note:   Uses Move() for efficiency since Boolean is an unmanaged type.
           If the input array is empty, the function returns the current length
           of Self without modification.
[==============================================================================}
function TBooleanArrayHelper.Attach(const items: TBooleanArray): Integer; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  i := items.Size;
  if (i = 0) then
    Exit(l);
  Result := (l + i);
  SetLength(Self, Result);
  Move(items[0], Self[l], (i * SizeOf(Boolean)));
end;

{==============================================================================]
  <Embed>
  @action: Inserts the contents of another boolean array into the current array
           at the specified index. Existing elements from that position onward
           are shifted to make room for the new items.
  @note: If the index exceeds the current length, the items are appended.
         Passing an empty array leaves the original array unchanged.
         The function returns the new total element count.
[==============================================================================}
function TBooleanArrayHelper.Embed(const items: TBooleanArray; const index: Integer = 2147483647): Integer; overload;
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
    Move(Self[p], Self[p + l], (t * SizeOf(Boolean)));
  Move(items[0], Self[p], (l * SizeOf(Boolean)));
  Result := Self.Size;
end;
{$ENDIF}
