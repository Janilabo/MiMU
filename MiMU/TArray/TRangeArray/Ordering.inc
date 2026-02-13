{$IFDEF HELPERS}
function Ascend: TRangeArray; overload;
function Ascended: TRangeArray; overload;
function Descend: TRangeArray; overload;
function Descended: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Ascend>
  @action: Returns a new range array where each element is transformed using its Ascend method.
  @note: The original array is not modified. The resulting array has the same length as the source array.
[==============================================================================}
function TRangeArrayHelper.Ascend: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Ascend;  
end;

{==============================================================================]
  <Ascended>
  @action: Returns a new range array where each element is replaced with its Ascended result.
  @note: This is a non-mutating operation. The resulting array preserves the original array length.
[==============================================================================}
function TRangeArrayHelper.Ascended: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Ascended;  
end;

{==============================================================================]
  <Descend>
  @action: Returns a new range array where each element is transformed using its Descend method.
  @note: The source array remains unchanged. The result has the same length as the original.
[==============================================================================}
function TRangeArrayHelper.Descend: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Descend;  
end;

{==============================================================================]
  <Descended>
  @action: Returns a new range array where each element is replaced with its Descended result.
  @note: This operation does not modify the original array. The returned array matches the source length.
[==============================================================================}
function TRangeArrayHelper.Descended: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Length);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Descended;  
end;
{$ENDIF}
