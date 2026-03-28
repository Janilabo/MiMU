{$IFDEF METHODS}
function Shared(const other: TRange): TIntegerArray; overload;
function Sharing(const other: TRange): TIntegerArray; overload;
function Unsharing(const other: TRange): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Shared>
  @action: Returns an array of every integer that exists in both ranges.
  @note: The order of the resulting array matches the direction of 'Self'.
         If there is no overlap, returns an empty array.
[==============================================================================}
function TRange.Shared(const other: TRange): TIntegerArray; overload;
var
  r: TRange;
  i, s: Integer;
begin
  if not Self.Meet(other, r) then
    Exit([]);
  s := r.Size;
  if (s = 1) then
    Exit([Self.start]);
  SetLength(Result, s);
  case Self.Ascending of
    True:
    for i := 0 to (s - 1) do
      Result[i] := r.start.Increase;
    False:
    for i := 0 to (s - 1) do
      Result[i] := r.stop.Decrease;
  end;
end;

{==============================================================================]
  <Sharing>
  @action: Returns an array of values from this range that exist in the other.
  @note: Maintains the direction of 'Self'.
[==============================================================================}
function TRange.Sharing(const other: TRange): TIntegerArray; overload;
var
  i, r, v, s, d: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  r := 0;
  d := IfThen(Self.Ascending, 1, -1);
  for i := 0 to (s - 1) do
  begin
    v := (Self.start + (i * d));
    if other.Contains(v) then
      Result[r.Increase] := v;
  end;
  if (r < s) then
    SetLength(Result, r);
end;

{==============================================================================]
  <Unsharing>
  @action: Returns an array of values from this range that are NOT in the other.
  @note: Useful for finding the "Difference" between two sets of numbers.
[==============================================================================}
function TRange.Unsharing(const other: TRange): TIntegerArray; overload;
var
  i, r, v, s, d: Integer;
begin
  s := Self.Size;
  SetLength(Result, s);
  r := 0;
  d := IfThen(Self.Ascending, 1, -1);
  for i := 0 to (s - 1) do
  begin
    v := (Self.start + (i * d));
    if not other.Contains(v) then
      Result[r.Increase] := v;
  end;
  if (r < s) then
    SetLength(Result, r);
end;
{$ENDIF}