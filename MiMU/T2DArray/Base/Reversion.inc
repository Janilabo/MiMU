{$IFDEF HELPERS}
function Reverse: Boolean; overload; cdecl;
function Reversed: M2DArray; overload; cdecl;
function Reversify: Boolean; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Reverse>
  @action: Reverses the 2D array in place.
  @note: Returns True only if the array contained 2 or more elements.
         Returns False if Length < 2 (no operation performed).
[==============================================================================}
function M2DArrayHelper.Reverse: Boolean; overload; cdecl;
var
  r: TRange;
begin
  Result := (Self.Length > 1);
  if not Result then
    Exit;
  r.create(0, High(Self));
  while (r.start < r.stop) do
    Self[r.start.Increase].Swapped(Self[r.stop.Decrease]);
end;

{==============================================================================]
  <Reversify>
  @action: Reverses the order of elements in a 2D array.
           Works by creating a temporary array and copying elements in reverse order.
  @note: - The operation modifies Self in place.
         - Returns True if the array had 2 or more elements (reversal performed).
         - Returns False if the array had 0 or 1 element (nothing changed).
[==============================================================================}
function M2DArrayHelper.Reversed: M2DArray; overload; cdecl;
var
  i, l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  for i := 0 to (l - 1) do
    Result[i] := Self[(l - 1) - i];
end;

{==============================================================================]
  <Reversify>
  @action: Reverses the order of elements in a 2D array.
           Works by creating a temporary array and copying elements in reverse order.
  @note: - The operation modifies Self in place.
         - Returns True if the array had 2 or more elements (reversal performed).
         - Returns False if the array had 0 or 1 element (nothing changed).
[==============================================================================}
function M2DArrayHelper.Reversify: Boolean; overload; cdecl;
var
  s: M2DArray;
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
{$ENDIF}