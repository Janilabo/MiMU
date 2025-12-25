{$IFDEF HELPERS}
function Falsed: Boolean; overload;
function Falseless: Boolean; overload;
function Falseless(const maxFalse: Integer): Boolean; overload;
function Falsesome: Boolean; overload;
function Falsesome(const minFalse: Integer): Boolean; overload;
function Trued: Boolean; overload;
function Trueless: Boolean; overload;
function Trueless(const maxTrue: Integer): Boolean; overload;
function Truesome: Boolean; overload;
function Truesome(const minTrue: Integer): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Falsed>
  @action: Returns true if ALL values in arr are False.
  @note: [False, False, False] => True.
[==============================================================================}
function TBooleanArrayHelper.Falsed: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if Self[i] then
      Exit(False);
  Result := Self.Exists;
end;

{==============================================================================]
  <Falseless>
  @action: Returns true if arr is full of True values or is empty.
  @note: [True, True, True] / [] => True.
[==============================================================================}
function TBooleanArrayHelper.Falseless: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i] then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Falseless>
  @action: Support for requirement amount of Falses.
  @note: [True, False, True, True] (1) => True / (0) => False.
[==============================================================================}
function TBooleanArrayHelper.Falseless(const maxFalse: Integer): Boolean; overload;
var
  i, c: Integer;
begin
  c := 0;
  if (maxFalse < Self.Size) then
  for i := 0 to High(Self) do
    if ((not Self[i]) and (c.Increment > maxFalse)) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Falsesome>
  @action: Returns true if arr contains any False value(s).
  @note: [False, False, True] => True.
[==============================================================================}
function TBooleanArrayHelper.Falsesome: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i] then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Falsesome>
  @action: Support for minFalse.
  @note: None.
[==============================================================================}
function TBooleanArrayHelper.Falsesome(const minFalse: Integer): Boolean; overload;
var
  i, c: Integer;
begin
  c := 0;
  if (minFalse < Self.Size) then
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
  <Trued>
  @action: Returns true if ALL values in arr are True.
  @note: [True, True, True] => True.
[==============================================================================}
function TBooleanArrayHelper.Trued: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if not Self[i] then
      Exit(False);
  Result := Self.Exists;
end;

{==============================================================================]
  <Trueless>
  @action: Returns true if arr is full of False values or is empty.
  @note: [False, False, False] / [] => True.
[==============================================================================}
function TBooleanArrayHelper.Trueless: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if Self[i] then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Trueless>
  @action: Support for requirement amount of Trues.
  @note: [False, True, False, False] (1) => True / (0) => False.
[==============================================================================}
function TBooleanArrayHelper.Trueless(const maxTrue: Integer): Boolean; overload;
var
  i, c: Integer;
begin
  c := 0;
  if (maxTrue < Self.Size) then
  for i := 0 to High(Self) do
    if (Self[i] and (c.Increment > maxTrue)) then
      Exit(False);
  Result := True;
end;

{==============================================================================]
  <Truesome>
  @action: Returns true if arr contains any True value(s).
  @note: [False, False, True] => True.
[==============================================================================}
function TBooleanArrayHelper.Truesome: Boolean; overload;
var
  i: Integer;
begin
  for i := 0 to High(Self) do
    if Self[i] then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Truesome>
  @action: Support for minTrue.
  @note: None.
[==============================================================================}
function TBooleanArrayHelper.Truesome(const minTrue: Integer): Boolean; overload;
var
  i, c: Integer;
begin
  c := 0;
  if (minTrue < Self.Size) then
  for i := 0 to High(Self) do
  begin
    if Self[i] then
      Inc(c);
    if (c >= minTrue) then
      Exit(True);
  end;
  Result := False;
end;
{$ENDIF}
