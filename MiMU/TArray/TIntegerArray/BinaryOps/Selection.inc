{$IFDEF HELPERS}
function BinaryValues(const value: Integer; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryValues(const values: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryExtract(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryExtract(const values: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryFilter(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
function BinaryFilter(const values: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryValues>
  @action: Returns all items in the array that match a given value using binary search.
  @note: The array must be sorted (ascending or descending) depending on
         the value of aAscending. If the value does not occur in the array,
         an empty array is returned.
[==============================================================================}
function TIntegerArrayHelper.BinaryValues(const value: Integer; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryValues1}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryValues1}

{==============================================================================]
  <BinaryValues>
  @action: Returns all items in the array whose values fall within a given
           numeric range, determined via binary search.
  @note: The array must be sorted (ascending or descending) according to
         aAscending. The order of the returned values matches the direction
         of the input TRange: ascending input returns ascending results,
         and descending input returns results in descending order. If no
         items fall within the specified range, an empty array is returned.
[==============================================================================}
function TIntegerArrayHelper.BinaryValues(const values: TRange; const aAscending: Boolean = True): TIntegerArray; overload; {$DEFINE Skeleton_BinaryValues2}{$I ../../Skeletons.inc}{$UNDEF Skeleton_BinaryValues2}

{==============================================================================]
  <BinaryExtract>
  @action: Returns all integers from Self that lie within the specified range.
           Uses binary search to minimize scanning. Supports ascending or descending arrays.
  @note:   area.start ≤ area.stop → ascending range
           area.start >  area.stop → descending range
           aAscending specifies whether Self is sorted ascending (True) or descending (False).
[==============================================================================}
function TIntegerArrayHelper.BinaryExtract(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
  R: TRange;
begin
  if Self.Empty then
    Exit([]);
  R := Self.BinaryRange(area.Normalize, aAscending);
  if R.Employs(-1) then
    Exit([]);
  SetLength(Result, R.Size);
  for i := R.start to R.stop do
    Result[i - R.start] := Self[i];
end;

function TIntegerArrayHelper.BinaryExtract(const values: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
var
  v: TIntegerArray;
  h, i, r: Integer;
begin
  if (Self.Empty or values.Empty) then
    Exit([]);
  v := values.QuickSorted;
  h := High(v);
  SetLength(Result, Self.Size);
  r := 0;
  case aAscending of
    True:
    for i := 0 to High(Self) do
      if (Self[i] > v[h]) then
        Break
      else if ((Self[i] >= v[0]) and v.BinaryContains(Self[i])) then
        Result[r.Increase] := Self[i];
    False:
    for i := 0 to High(Self) do
      if (Self[i] < v[0]) then
        Break
      else if ((Self[i] <= v[h]) and v.BinaryContains(Self[i])) then
        Result[r.Increase] := Self[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <BinaryFilter>
  @action: Returns all integers from Self that lie outside the specified range.
           Uses binary search to minimize scanning. Supports ascending or descending arrays.
  @note:   area.start ≤ area.stop → ascending range
           area.start >  area.stop → descending range
           aAscending specifies whether Self is sorted ascending (True) or descending (False).
[==============================================================================}
function TIntegerArrayHelper.BinaryFilter(const area: TRange; const aAscending: Boolean = True): TIntegerArray; overload;
var
  i, L, h: Integer;
  R: TRange;
begin
  L := Self.Length;
  if (L = 0) then
    Exit([]);
  R := Self.BinaryRange(area.Normalize, aAscending);
  if R.Employs(-1) then
    Exit([]);
  SetLength(Result, (L - R.Size));
  h := 0;
  for i := 0 to (L - 1) do
    if ((i < R.start) or (i > R.stop)) then
      Result[h.Increase] := Self[i];
end;

function TIntegerArrayHelper.BinaryFilter(const values: TIntegerArray; const aAscending: Boolean = True): TIntegerArray; overload;
var
  h, i, r: Integer;
begin
  if Self.Empty then
    Exit([]);
  if values.Empty then
    Exit(Self.Copy);
  SetLength(Result, Self.Size);
  r := 0;
  for i := 0 to High(Self) do
    if not values.BinaryContains(Self[i], aAscending) then
      Result[r.Increase] := Self[i];
  SetLength(Result, r);
end;
{$ENDIF}
