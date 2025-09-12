{==============================================================================]
  <TBooleanArrayHelper.Select>
  @action: IfThen method for TBooleanArray.
  @note: [True, False, True] => 5.
[==============================================================================}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Integer): TIntegerArray; overload; cdecl; {$DEFINE Skeleton_Select2}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Double): TDoubleArray; overload; cdecl; {$DEFINE Skeleton_Select2}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: string): TStringArray; overload; cdecl; {$DEFINE Skeleton_Select2}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Char): TCharArray; overload; cdecl; {$DEFINE Skeleton_Select2}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Boolean): TBooleanArray; overload; cdecl; {$DEFINE Skeleton_Select2}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TPoint): TPointArray; overload; cdecl; {$DEFINE Skeleton_Select2}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TBox): TBoxArray; overload; cdecl; {$DEFINE Skeleton_Select2}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TRange): TRangeArray; overload; cdecl; {$DEFINE Skeleton_Select2}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Select2}

{==============================================================================]
  <TBooleanArrayHelper.Bitify>
  @action: Returns TBooleanArray as bits.
  @note: [True, False, True] => 5.
[==============================================================================}
function TBooleanArrayHelper.Bitify: Integer; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
  begin
    Result := (Result shl 1);
    if Self[i] then
      Inc(Result);
  end;
end;

{==============================================================================]
  <TBooleanArrayHelper.Bits>
  @action: Returns TBooleanArray as bits.
  @note: [True, False, True] => 5.
[==============================================================================}
function TBooleanArrayHelper.Bits: Integer; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := ((Result shl 1) or Self[i].Bit);
end;

{==============================================================================]
  <TBooleanArrayHelper.ToBits>
  @action: Returns TBooleanArray as bits.
  @note: [True, False, True] => 5.
[==============================================================================}
function TBooleanArrayHelper.ToBits: Integer; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    Result := ((Result shl 1) or Byte(Self[i]));
end;

{==============================================================================]
  <TBooleanArrayHelper.Digits>
  @action: Returns TBooleanArray as Integers.
  @note: [True, False] => [1, 0].
[==============================================================================}
function TBooleanArrayHelper.Digits: TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Ord(Self[i]);
end;

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
  <TBooleanArrayHelper.Falseness: Integer>
  @action: Returns count of False values arr has got.
  @note: [False, False, True, True, False] => 3
[==============================================================================}
function TBooleanArrayHelper.Falseness: Integer; overload; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    if not Self[i] then
      Inc(Result);
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
  <TBooleanArrayHelper.Str(separator, strTrue, strFalse: string): string>
  @action: Returns TBooleanArray as string.
  @note: Supports custom separator & True / False strings.
[==============================================================================}
function TBooleanArrayHelper.Str(const separator: string; const strTrue: string = 'True'; strFalse: string = 'False'): string; overload; cdecl;
var
  i: Integer;
begin
  Result := '[';
  for i := 0 to High(Self) do
    if Self[i] then
      Result := (Result + strTrue + separator)
    else
      Result := (Result + strFalse + separator);
  if not (separator = '') then
    SetLength(Result, (Length(Result) - Length(separator)));
  Result := (Result + ']');
end;

function TBooleanArrayHelper.Str: string; overload; cdecl;
begin
  Result := Self.Str(', ');
end;

{==============================================================================]
  <TBooleanArrayHelper.Text(strTrue, strFalse, separator: string): string>
  @action: Returns TBooleanArray as string.
  @note: Supports custom separator & True / False strings.
[==============================================================================}
function TBooleanArrayHelper.Text(const strTrue, strFalse, separator: string): string; overload; cdecl;
var
  i: Integer;
begin
  Result := '[';
  for i := 0 to High(Self) do
    if Self[i] then
      Result := (Result + strTrue + separator)
    else
      Result := (Result + strFalse + separator);
  if not (separator = '') then
    SetLength(Result, (Length(Result) - Length(separator)));
  Result := (Result + ']');
end;

function TBooleanArrayHelper.Text(const strTrue: string = 'True'; strFalse: string = 'False'): string; overload; cdecl;
begin
  Result := Self.Text(strTrue, strFalse, ', ');
end;

{==============================================================================]
  <TBooleanArrayHelper.TIA>
  @action: Returns TBooleanArray as Integers.
  @note: [True, False] => [1, 0].
[==============================================================================}
function TBooleanArrayHelper.TIA(const valTrue: Integer = 1; const valFalse: Integer = 0): TIntegerArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    if Self[i] then
      Result[i] := valTrue
    else
      Result[i] := valFalse;
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
  <TBooleanArrayHelper.Trueness: Integer>
  @action: Returns count of True values arr has got.
  @note: [False, False, True, True, False] => 2
[==============================================================================}
function TBooleanArrayHelper.Trueness: Integer; overload; cdecl;
var
  i: Integer;
begin
  Result := 0;
  for i := 0 to High(Self) do
    if Self[i] then
      Inc(Result);
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

{==============================================================================]
  <TBooleanArrayHelper.BinaryStr>
  @action: Returns binary string from Boolean Array
  @note: [True, False] => '10' & [False, True] => '01'
[==============================================================================}
function TBooleanArrayHelper.BinaryStr: string; cdecl;
var
  i: Integer;
begin
  Result := '';
  for i := 0 to High(Self) do
    Result := (Result + IfThen(Self[i], '1', '0'));  
end;

{==============================================================================]
  <TBooleanArrayHelper.BinaryDigits>
  @action: Returns binary digits from Boolean Array
  @note: [True, False] => [1, 0] & [False, True] => [0, 1]
[==============================================================================}
function TBooleanArrayHelper.BinaryDigits: TIntegerArray; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := IfThen(Self[i], 1, 0);  
end;

{==============================================================================]
  <TBooleanArrayHelper.Binary>
  @action: Returns binary string from Boolean Array
  @note: [True, False] => '10' & [False, True] => '01'
[==============================================================================}
function TBooleanArrayHelper.Binary: string; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i + 1] := Self[i].Binary;  
end;