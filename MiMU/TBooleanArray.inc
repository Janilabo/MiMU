{==============================================================================]
  <TBooleanArrayHelper.Falsed>
  @action: Returns true if ALL values in arr are False.
  @note: [False, False, False] => True.
[==============================================================================}
function TBooleanArrayHelper.Falsed: Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if Self[i] then
      Exit(False);
  Result := Self.Exists;
end;

{==============================================================================]
  <TBooleanArrayHelper.Falseless>
  @action: Returns true if arr is full of True values or is empty.
  @note: [True, True, True] / [] => True.
[==============================================================================}
function TBooleanArrayHelper.Falseless: Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i] then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <TBooleanArrayHelper.Falseless(maxFalse: Integer): Boolean>
  @action: Support for requirement amount of Falses.
  @note: [True, False, True, True] (1) => True / (0) => False.
[==============================================================================}
function TBooleanArrayHelper.Falseless(const maxFalse: Integer): Boolean; overload; cdecl;
var
  i, c: Integer;
begin
  c := 0;
  if (maxFalse < Length(Self)) then
  for i := 0 to High(Self) do
    if ((not Self[i]) and (c.Increment > maxFalse)) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <TBooleanArrayHelper.Falses>
  @action: Returns Indexes of arr where state is False.
  @note: [True, False, True, False] => [1,3]
[==============================================================================}
function TBooleanArrayHelper.Falses: TIntegerArray; overload; cdecl;
var
  i, r: Integer;
begin
  SetLength(Result, Length(Self));
  r := 0;
  for i := 0 to High(Self) do
    if not Self[i] then
      Result[r.Increase] := i;
  SetLength(Result, r);
end;

{==============================================================================]
  <TBooleanArrayHelper.Falsesome>
  @action: Returns true if arr contains any False value(s).
  @note: [False, False, True] => True.
[==============================================================================}
function TBooleanArrayHelper.Falsesome: Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i] then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <TBooleanArrayHelper.Falsesome(minFalse: Integer): Boolean>
  @action: Support for minFalse.
  @note: None.
[==============================================================================}
function TBooleanArrayHelper.Falsesome(const minFalse: Integer): Boolean; overload; cdecl;
var
  i, c: Integer;
begin
  c := 0;
  if (minFalse < Length(Self)) then
  for i := 0 to High(Self) do
  begin
    if not Self[i] then
      Inc(c);
    if (c >= minFalse) then
      Exit(True);
  end;
  Result := False;
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
  <TBooleanArrayHelper.Trued>
  @action: Returns true if ALL values in arr are True.
  @note: [True, True, True] => True.
[==============================================================================}
function TBooleanArrayHelper.Trued: Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i] then
      Exit(False);
  Result := Self.Exists;
end;

{==============================================================================]
  <TBooleanArrayHelper.Trueless>
  @action: Returns true if arr is full of False values or is empty.
  @note: [False, False, False] / [] => True.
[==============================================================================}
function TBooleanArrayHelper.Trueless: Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if Self[i] then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <TBooleanArrayHelper.Trueless(maxTrue: Integer): Boolean>
  @action: Support for requirement amount of Trues.
  @note: [False, True, False, False] (1) => True / (0) => False.
[==============================================================================}
function TBooleanArrayHelper.Trueless(const maxTrue: Integer): Boolean; overload; cdecl;
var
  i, c: Integer;
begin
  c := 0;
  if (maxTrue < Length(Self)) then
  for i := 0 to High(Self) do
    if (Self[i] and (c.Increment > maxTrue)) then
      Exit(False);
  Result := True;
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
  <TBooleanArrayHelper.Truesome>
  @action: Returns true if arr contains any True value(s).
  @note: [False, False, True] => True.
[==============================================================================}
function TBooleanArrayHelper.Truesome: Boolean; overload; cdecl;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if Self[i] then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <TBooleanArrayHelper.Truesome(minTrue: Integer): Boolean>
  @action: Support for minTrue.
  @note: None.
[==============================================================================}
function TBooleanArrayHelper.Truesome(const minTrue: Integer): Boolean; overload; cdecl;
var
  i, c: Integer;
begin
  c := 0;
  if (minTrue < Length(Self)) then
  for i := 0 to High(Self) do
  begin
    if Self[i] then
      Inc(c);
    if (c >= minTrue) then
      Exit(True);
  end;
  Result := False;
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
