{==============================================================================]
  <TBooleanArrayHelper.Falses>
  @action: Returns Indexes of arr where state is True.
  @note: [True, False, True, False] => [1,3]
[==============================================================================}
function TBooleanArrayHelper.Falses: TIntegerArray; overload; cdecl;
var
  i, r: Integer;
begin
  SetLength(Result, Length(Self));
  r := 0;
  for i := 0 to High(Self) do
    if (Self[i] = False) then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;

{==============================================================================]
  <TBooleanArrayHelper.Toggle>
  @action: Returns opposite version of arr.
  @note: [True, False] => [False, True].
[==============================================================================}
function TBooleanArrayHelper.Toggle: TBooleanArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := not Self[i];
end;

{==============================================================================]
  <TBooleanArrayHelper.Trues>
  @action: Returns Indexes of arr where state is True.
  @note: [True, False, True, False] => [0,2]
[==============================================================================}
function TBooleanArrayHelper.Trues: TIntegerArray; overload; cdecl;
var
  i, r: Integer;
begin
  SetLength(Result, Length(Self));
  r := 0;
  for i := 0 to High(Self) do
    if (Self[i] = True) then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;

{==============================================================================]
  <TBooleanArrayHelper.Opposite>
  @action: Returns opposite version of arr.
  @note: [True, False] => [False, True].
[==============================================================================}
function TBooleanArrayHelper.Opposite: TBooleanArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    if Self[i] then
      Result[i] := False
	else
	  Result[i] := True;
end;