{==============================================================================]
  <X1(arr: TBoxArray): TIntegerArray>
  @action: Returns X1 values from TBoxArray arr.
  @note: None.
[==============================================================================}
function X1(const arr: TBoxArray): TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(Result) do
    Result[i] := arr[i].X1;
end;

{==============================================================================]
  <X2(arr: TBoxArray): TIntegerArray>
  @action: Returns X2 values from TBoxArray arr.
  @note: None.
[==============================================================================}
function X2(const arr: TBoxArray): TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(Result) do
    Result[i] := arr[i].X2;
end;

{==============================================================================]
  <Y1(arr: TBoxArray): TIntegerArray>
  @action: Returns Y1 values from TBoxArray arr.
  @note: None.
[==============================================================================}
function Y1(const arr: TBoxArray): TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(Result) do
    Result[i] := arr[i].Y1;
end;

{==============================================================================]
  <Y2(arr: TBoxArray): TIntegerArray>
  @action: Returns Y2 values from TBoxArray arr.
  @note: None.
[==============================================================================}
function Y2(const arr: TBoxArray): TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(Result) do
    Result[i] := arr[i].Y2;
end;