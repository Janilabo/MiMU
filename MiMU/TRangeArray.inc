{==============================================================================]
  <TRangeArray_TIntegerArray>
  @action: Returns TRanges from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArray_TIntegerArray(const arr: TRangeArray): TIntegerArray; cdecl;
var
  i, j, l: Integer;
  r: TIntegerArray;
begin
  l := 0;
  for i := 0 to High(arr) do
    l := (l + TRange_Size(arr[i]));
  SetLength(Result, l);
  for i := High(arr) downto 0 do
  begin
    r := TRange_TIntegerArray(arr[i]);
    for j := High(r) downto 0 do
      Result[l.Decrement] := r[j];
  end;
end;

{==============================================================================]
  <TRangeArray_T2DIntegerArray>
  @action: Returns TRanges from arr as T2DIntegerArray.
  @note: None.
[==============================================================================}
function TRangeArray_T2DIntegerArray(const arr: TRangeArray): T2DIntegerArray; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
   for i := 0 to High(arr) do
    Result[i] := TRange_TIntegerArray(arr[i]);
end;
