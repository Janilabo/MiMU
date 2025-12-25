{$IFDEF HELPERS}
function Unzip(var x1Arr, y1Arr, x2Arr, y2Arr: TIntegerArray): Integer;
function Zip(const x1Arr, y1Arr, x2Arr, y2Arr: TIntegerArray): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Unzip>
  @action: Stores arr X1/X2 and Y1/Y2 values to x1/x2Arr and y1/y2Arr.
  @note: Returns Length(arr).
[==============================================================================}
function TBoxArrayHelper.Unzip(var x1Arr, y1Arr, x2Arr, y2Arr: TIntegerArray): Integer;
var
  i: Integer;
begin
  Result := Self.Length;
  specialize SetSize<Integer>(x1Arr, y1Arr, x2Arr, y2Arr, Result);
  for i := 0 to (Result - 1) do
    Self[i].Unzip(x1Arr[i], y1Arr[i], x2Arr[i], y2Arr[i]);
end;

{==============================================================================]
  <Zip>
  @action: Zips TBoxArray with x1/x2Arr and y1/y2Arr.
  @note: Uses minimum length(!), if xArr differs from yArr size.
[==============================================================================}
function TBoxArrayHelper.Zip(const x1Arr, y1Arr, x2Arr, y2Arr: TIntegerArray): Integer;
var
  i: Integer;
begin
  Result := Min(Min(x1Arr.Size, x2Arr.Size), Min(y1Arr.Size, y2Arr.Size));
  SetLength(Self, Result);
  for i := 0 to (Result - 1) do
    Self[i] := Box(x1Arr[i], y1Arr[i], x2Arr[i], y2Arr[i]);
end;
{$ENDIF}
