{$DEFINE Double}{$I ../../Type/Defines.inc}

{$IFDEF TYPES}
CDoubleArray = class
public
  {$DEFINE METHODS}{$I TDoubleArray.pph}{$UNDEF METHODS}
end;
{$ENDIF}

{$IFDEF HELPERS}
TDoubleArrayHelper = type helper for TDoubleArray
  {$I ../Base/Base.inc}
  {$I TDoubleArray.pph}
  function Reinit: Integer; overload;
  function Attach(const items: TDoubleArray): Integer; overload;
  function Embed(const items: TDoubleArray; const index: Integer = 2147483647): Integer; overload;
end;
{$ENDIF}

{$IF DEFINED(FUNCTIONS) OR DEFINED(CLASSES) OR DEFINED(IMPLEMENTATION)}
{$I ../Base/Base.inc}
{$I TDoubleArray.pph}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           while keeping the current length unchanged.
  @note: None.
[==============================================================================}
function TDoubleArrayHelper.Reinit: Integer; overload;
begin
  Result := Self.Size;
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(Double)), 0);
end;

{==============================================================================]
  <Attach>
  @action: Appends all points from the given array to the end of Self.
           Returns the new total length of the array after appending.
  @note:   Uses Move() for efficiency since Integer is an unmanaged type.
           If the input array is empty, the function returns the current length
           of Self without modification.
[==============================================================================}
function TDoubleArrayHelper.Attach(const items: TDoubleArray): Integer; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  i := items.Size;
  if (i = 0) then
    Exit(l);
  Result := (l + i);
  SetLength(Self, Result);
  Move(items[0], Self[l], (i * SizeOf(Double)));
end;

{==============================================================================]
  <Embed>
  @action: Inserts the contents of another double array into the current array
           at the specified index. Existing elements from that position onward
           are shifted to make room for the new items.
  @note: If the index exceeds the current length, the items are appended.
         Passing an empty array leaves the original array unchanged.
         The function returns the new total element count.
[==============================================================================}
function TDoubleArrayHelper.Embed(const items: TDoubleArray; const index: Integer = 2147483647): Integer; overload;
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
    Move(Self[p], Self[p + l], (t * SizeOf(Double)));
  Move(items[0], Self[p], (l * SizeOf(Double)));
  Result := Self.Size;
end;
{$ENDIF}

{$UNDEF Double}
