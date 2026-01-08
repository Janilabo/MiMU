{$IFDEF HELPERS}
function Backwards: MArray; overload; cdecl;
function Flip: Boolean; overload; cdecl;
function Reversal: MArray; overload; cdecl;
function Reverse: Boolean; overload; cdecl;
function Reversed: MArray; overload; cdecl;
function Reversify: Boolean; overload; cdecl;
function Reversion: MArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Backwards>
  @action: Returns arr as reversed.
  @note: Alternative for Reversed methods
[==============================================================================}
function MArrayHelper.Backwards: MArray; overload; cdecl;
var
  l, i: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  i := 0;
  while (l > 0) do
    Result[i.Increase] := Self[l.Decrement];
end;

{==============================================================================]
  <Flip>
  @action: Reverses array arr.
  @note: Alternative for TArray_Reverse
[==============================================================================}
function MArrayHelper.Flip: Boolean; overload; cdecl;
var
  r: TRange;
begin
  r.Create(0, (Self.Size - 1));
  Result := (r.stop > 0);
  while (r.start < r.stop) do
    Exchange(r.start.Increase, r.stop.Decrease);
end;

{==============================================================================]
  <Reversal>
  @action: Returns array with items in reversed order.
  @note: None.
[==============================================================================}
function MArrayHelper.Reversal: MArray; overload; cdecl;
var
  r: TRange;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, Self.Size);
  r.Create(-1, Result.Size);
  while (r.start.Increment <= r.stop.Decrement) do
  begin
    Result[r.start] := Self[r.stop];
    if (r.start <> r.stop) then
      Result[r.stop] := Self[r.start];
  end;
end;

{==============================================================================]
  <Reverse>
  @action: Reverses items in array.
  @note: Returns true with success (array contains 2 or more items)
[==============================================================================}
function MArrayHelper.Reverse: Boolean; overload; cdecl;
var
  i, l: Integer;
begin
  l := Self.Length;
  Result := (l > 1);
  if Result then
  for i := 0 to ((l div 2) - 1) do
    Exchange(i, ((l - i) - 1));
end;

{==============================================================================]
  <Reversed>
  @action: Returns reversed version of array arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Reversed: MArray; overload; cdecl;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := Self[(l - i) - 1];
end;

{==============================================================================]
  <Reversify>
  @action: Reverses the order of elements in a 1D array.
           Works by creating a temporary array and copying elements in reverse order.
  @note: - The operation modifies Self in place.
         - Returns True if the array had 2 or more elements (reversal performed).
         - Returns False if the array had 0 or 1 element (nothing changed).
[==============================================================================}
function MArrayHelper.Reversify: Boolean; overload; cdecl;
var
  s: MArray;
  i, l: Integer;
begin
  l := Self.Length;
  Result := (l > 1);
  if not Result then
    Exit;
  SetLength(s, l);
  for i := 0 to (l - 1) do
    s[i] := Self[(l - 1) - i];
  Self := s;
end;

{==============================================================================]
  <Reversion>
  @action: Returns array with items in reversed order.
  @note: None.
[==============================================================================}
function MArrayHelper.Reversion: MArray; overload; cdecl;
var
  h, i, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self[0]]);
  end;
  SetLength(Result, l);
  h := (l div 2);
  for i := 0 to (h - 1) do
  begin
    Result[i] := Self[(l - i) - 1];
    Result[(l - i) - 1] := Self[i];
  end;
  if l.Odd then
    Result[h] := Self[h];
end;
{$ENDIF}