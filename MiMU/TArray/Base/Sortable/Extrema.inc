{$IFDEF HELPERS}
function Lowest: MType; overload;
function Highest: MType; overload;
function Mini(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload;
function Mini(const start: Integer; const aAscending: Boolean = True): Integer; overload;
function Maxi(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload;
function Maxi(const start: Integer; const aAscending: Boolean = True): Integer; overload;
function MinItem: MType; overload;
function MinItem(const null: MType): MType; overload;
function MaxItem: MType; overload;
function MaxItem(const null: MType): MType; overload;
function Minimum(var index: Integer): MType; overload;
function Minimum: MType; overload;
function Maximum(var index: Integer): MType; overload;
function Maximum: MType; overload;
function Minim(var index: Integer): MType; overload;
function Minim: MType; overload;
function Maxim(var index: Integer): MType; overload;
function Maxim: MType; overload;
function Peaks: TIntegerArray; overload;
function Valleys: TIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Lowest>
  @action: Returns array minimum value.
  @note: None.
[==============================================================================}
function MArrayHelper.Lowest: MType; overload;
var
  i: Integer;
begin
  if (High(Self) > -1) then
    Result := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] < Result) then
      Result := Self[i];
end;

{==============================================================================]
  <Highest>
  @action: Returns array maximum value.
  @note: None.
[==============================================================================}
function MArrayHelper.Highest: MType; overload;
var
  i: Integer;
begin
  if (High(Self) > -1) then
    Result := Self[0];
  for i := 1 to High(Self) do
    if (Self[i] < Result) then
      Result := Self[i];
end;

{==============================================================================]
  <Mini>
  @action: Returns array INDEX with minimum value.
  @note: Supports reversed order (last min index) with aAscending as False.
[==============================================================================}
function MArrayHelper.Mini(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload;
var
  h, i: Integer;
begin
  h := High(Self);
  if ((h = -1) or (aAscending and (start > h)) or ((not aAscending) and (start < 0))) then
    Exit(-1);
  case aAscending of
    True:
    begin
      Result := Max(0, start);
      for i := (Result + 1) to h do
        if (Self[i] < Self[Result]) then
          Result := i;
    end;
    False:
    begin
      Result := Min(h, start);
      for i := (Result - 1) downto 0 do
        if (Self[i] < Self[Result]) then
          Result := i;
    end;
  end;
end;

function MArrayHelper.Mini(const start: Integer; const aAscending: Boolean = True): Integer; overload;
begin
  Result := Self.Mini(aAscending, start);
end;

{==============================================================================]
  <Maxi>
  @action: Returns array INDEX with maximum value.
  @note: Supports reversed order (last max index) with aAscending as False.
[==============================================================================}
function MArrayHelper.Maxi(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload;
var
  h, i: Integer;
begin
  h := High(Self);
  if ((h = -1) or (aAscending and (start > h)) or ((not aAscending) and (start < 0))) then
    Exit(-1);
  case aAscending of
    True:
    begin
      Result := Max(0, start);
      for i := (Result + 1) to h do
        if (Self[i] > Self[Result]) then
          Result := i;
    end;
    False:
    begin
      Result := Min(h, start);
      for i := (Result - 1) downto 0 do
        if (Self[i] > Self[Result]) then
          Result := i;
    end;
  end;
end;

function MArrayHelper.Maxi(const start: Integer; const aAscending: Boolean = True): Integer; overload;
begin
  Result := Self.Maxi(aAscending, start);
end;

{==============================================================================]
  <MinItem>
  @action: Returns minimum item from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.MinItem: MType; overload;
var
  i: Integer;
begin
  if not Self.Empty then
    Result := Self[0];
  for i := 1 to High(Self) do
    Result := Min(Self[i], Result);
end;

{==============================================================================]
  <MinItem>
  @action: Returns minimum item from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.MinItem(const null: MType): MType; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(null);
  Result := Self[0];
  for i := 1 to High(Self) do
    Result := Min(Self[i], Result);
end;

{==============================================================================]
  <MaxItem>
  @action: Returns maximum item from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.MaxItem: MType; overload;
var
  i: Integer;
begin
  if not Self.Empty then
    Result := Self[0];
  for i := 1 to High(Self) do
    Result := Max(Self[i], Result);
end;

{==============================================================================]
  <MaxItem>
  @action: Returns maximum item from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.MaxItem(const null: MType): MType; overload;
var
  i: Integer;
begin
  if Self.Empty then
    Exit(null);
  Result := Self[0];
  for i := 1 to High(Self) do
    Result := Max(Self[i], Result);
end;

{==============================================================================]
  <Minimum>
  @action: Returns minimum value from arr and stores index to Integer variable.
  @note: None.
[==============================================================================}
function MArrayHelper.Minimum(var index: Integer): MType; overload;
var
  i: Integer;
begin
  if not Self.Empty then
  begin
    index := 0;
    for i := 1 to High(Self) do
      if (Self[i] < Self[index]) then
        index := i;
    Result := Self[index];
  end else
    index := -1;
end;

{==============================================================================]
  <Minimum>
  @action: Returns minimum value from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Minimum: MType; overload;
var
  i: Integer;
begin
  Result := Self.Minimum(i);
end;

{==============================================================================]
  <Maximum>
  @action: Returns maximum value from arr and stores index to Integer variable.
  @note: None.
[==============================================================================}
function MArrayHelper.Maximum(var index: Integer): MType; overload;
var
  i: Integer;
begin
  if not Self.Empty then
  begin
    index := 0;
    for i := 1 to High(Self) do
      if (Self[i] > Self[index]) then
        index := i;
    Result := Self[index];
  end else
    index := -1;
end;

{==============================================================================]
  <Maximum>
  @action: Returns maximum value from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Maximum: MType; overload;
var
  i: Integer;
begin
  Result := Self.Maximum(i);
end;

{==============================================================================]
  <Minim>
  @action: Returns minimum value from arr and stores index to Integer variable.
  @note: None.
[==============================================================================}
function MArrayHelper.Minim(var index: Integer): MType; overload;
var
  i: Integer;
begin
  index := IfThen(Self.Empty, -1, 0);
  for i := 1 to High(Self) do
    if (Self[i] < Self[index]) then
      index := i;
  if (index > -1) then
    Result := Self[index];
end;

{==============================================================================]
  <Minim>
  @action: Returns minimum value from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Minim: MType; overload;
var
  i: Integer;
begin
  Result := Self.Minim(i);
end;

{==============================================================================]
  <Maxim>
  @action: Returns maximum value from arr and stores index to Integer variable.
  @note: None.
[==============================================================================}
function MArrayHelper.Maxim(var index: Integer): MType; overload;
var
  i: Integer;
begin
  index := IfThen(Self.Empty, -1, 0);
  for i := 1 to High(Self) do
    if (Self[i] > Self[index]) then
      index := i;
  if (index > -1) then
    Result := Self[index];
end;

{==============================================================================]
  <Maxim>
  @action: Returns maximum value from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.Maxim: MType; overload;
var
  i: Integer;
begin
  Result := Self.Maxim(i);
end;

{==============================================================================]
  <Peaks>
  @action: Returns the indices of all local maxima in the array.
  @note: A local maximum is any element strictly greater than its immediate
         neighbors. Edge elements (index 0 or index High) are included when
         they satisfy the one-sided comparison. The result array is sized
         exactly to the number of detected peaks.
[==============================================================================}
function MArrayHelper.Peaks: TIntegerArray; overload;
var
  h, l, i: Integer;
begin
  h := High(Self);
  SetLength(Result, (h + 1));
  if Self.Empty then
    Exit;
  l := 0;
  if ((h = 0) or (Self[0] > Self[1])) then
    Result[l.Increase] := 0;
  for i := 1 to (h - 1) do
    if ((Self[i] > Self[i - 1]) and (Self[i] > Self[i + 1])) then
      Result[l.Increase] := i;
  if ((h > 0) and (Self[h] > Self[h - 1])) then
    Result[l.Increase] := h;
  SetLength(Result, l);
end;

{==============================================================================]
  <Valleys>
  @action: Returns the indices of all local minima in the array.
  @note: A local minimum is any element strictly lower than its immediate
         neighbors. Edge elements (index 0 or index High) are included when
         they satisfy the one-sided comparison. The result array is sized
         exactly to the number of detected valleys.
[==============================================================================}
function MArrayHelper.Valleys: TIntegerArray; overload;
var
  h, l, i: Integer;
begin
  h := High(Self);
  SetLength(Result, (h + 1));
  if Self.Empty then
    Exit;
  l := 0;
  if ((h = 0) or (Self[0] < Self[1])) then
    Result[l.Increase] := 0;
  for i := 1 to (h - 1) do
    if ((Self[i] < Self[i - 1]) and (Self[i] < Self[i + 1])) then
      Result[l.Increase] := i;
  if (h > 0) and (Self[h] < Self[h - 1]) then
    Result[l.Increase] := h;
  SetLength(Result, l);
end;
{$ENDIF}