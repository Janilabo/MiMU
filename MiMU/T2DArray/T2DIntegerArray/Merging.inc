{$IFDEF METHODS}
class function Merge(const arr: T2DIntegerArray): TIntegerArray; overload;
{$ENDIF}

{$IFDEF HELPERS}
function Fusage(const rAscending: Boolean = True): TIntegerArray; overload;
function Fusaged(const rAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
class function C2DIntegerArray.Merge(const arr: T2DIntegerArray): TIntegerArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, Length(arr));
  if Result.Empty then
    Exit;
  r := 0;
  for i := 0 to High(arr) do
    if (arr[i].Size > 0) then
      Move(arr[i][0], Result[r.Increase(arr[i].Size)], (arr[i].Size * SizeOf(Integer)));
end;

{==============================================================================]
  <Fusage>
  @action: Flattens a 2D array by concatenating rows and sorting the result.
  @note: Higher memory overhead than a merge, but simpler logic.
[==============================================================================}
function T2DIntegerArrayHelper.Fusage(const rAscending: Boolean = True): TIntegerArray; overload;
var
  i, s, o, l: Integer;
begin
  s := 0;
  for i := 0 to High(Self) do
    Inc(s, Self[i].Length);
  if (s = 0) then
    Exit([]);
  SetLength(Result, s);
  o := 0;
  for i := 0 to High(Self) do
  begin
    l := Self[i].Length;
    if (l = 0) then
      Continue;
    Move(Self[i][0], Result[o.Increase(l)], (l * SizeOf(Integer)));
  end;
  Result.QuickSort(rAscending);
end;

{==============================================================================]
  <Fusaged>
  @action: Flattens a 2D array by concatenating rows and sorting the result.
  @note: Higher memory overhead than a merge, but simpler logic.
[==============================================================================}
function T2DIntegerArrayHelper.Fusaged(const rAscending: Boolean = True): TIntegerArray; overload;
var
  i, s, o: Integer;
  l: TIntegerArray;
begin
  s := 0;
  SetLength(l, Self.Length);
  for i := 0 to High(Self) do
  begin
    l[i] := Self[i].Length;
    Inc(s, l[i]);
  end;
  if (s = 0) then
    Exit([]);
  SetLength(Result, s);
  o := 0;
  for i := 0 to High(Self) do
    if (l[i] > 0) then
      Move(Self[i][0], Result[o.Increase(l[i])], (l[i] * SizeOf(Integer)));
  Result.QuickSort(rAscending);
end;
{$ENDIF}
