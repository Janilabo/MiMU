{$DEFINE Boolean}{$I config\Defines.inc}

{$IFNDEF IMPLEMENT}
  {$I config\Helpers.inc}
{$ENDIF}

{$IFDEF IMPLEMENT}

{$I Generic.inc}

{==============================================================================]
  <TBooleanArrayHelper.Select>
  @action: IfThen method for TBooleanArray.
  @note: [True, False, True] => 5.
[==============================================================================}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Integer): TIntegerArray; overload; {$DEFINE Skeleton_Select2}{$I config\Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Double): TDoubleArray; overload; {$DEFINE Skeleton_Select2}{$I config\Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: string): TStringArray; overload; {$DEFINE Skeleton_Select2}{$I config\Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Char): TCharArray; overload; {$DEFINE Skeleton_Select2}{$I config\Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Boolean): TBooleanArray; overload; {$DEFINE Skeleton_Select2}{$I config\Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TPoint): TPointArray; overload; {$DEFINE Skeleton_Select2}{$I config\Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TBox): TBoxArray; overload; {$DEFINE Skeleton_Select2}{$I config\Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TRange): TRangeArray; overload; {$DEFINE Skeleton_Select2}{$I config\Skeletons.inc}{$UNDEF Skeleton_Select2}

{==============================================================================]
  <TBooleanArrayHelper.Bitify>
  @action: Returns TBooleanArray as bits.
  @note: [True, False, True] => 5.
[==============================================================================}
function TBooleanArrayHelper.Bitify: Integer;
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
function TBooleanArrayHelper.Bits: Integer;
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
function TBooleanArrayHelper.ToBits: Integer;
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
function TBooleanArrayHelper.Digits: TIntegerArray; overload;
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
  <TBooleanArrayHelper.Falseless>
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
  <TBooleanArrayHelper.Falseless(maxFalse: Integer): Boolean>
  @action: Support for requirement amount of Falses.
  @note: [True, False, True, True] (1) => True / (0) => False.
[==============================================================================}
function TBooleanArrayHelper.Falseless(const maxFalse: Integer): Boolean; overload;
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
function TBooleanArrayHelper.Falseness: Integer; overload;
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
function TBooleanArrayHelper.Falses: TIntegerArray; overload;
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
  <TBooleanArrayHelper.Falsesome(minFalse: Integer): Boolean>
  @action: Support for minFalse.
  @note: None.
[==============================================================================}
function TBooleanArrayHelper.Falsesome(const minFalse: Integer): Boolean; overload;
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
function TBooleanArrayHelper.Str(const separator: string; const strTrue: string = 'True'; strFalse: string = 'False'): string; overload;
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

function TBooleanArrayHelper.Str: string; overload;
begin
  Result := Self.Str(', ');
end;

{==============================================================================]
  <TBooleanArrayHelper.Text(strTrue, strFalse, separator: string): string>
  @action: Returns TBooleanArray as string.
  @note: Supports custom separator & True / False strings.
[==============================================================================}
function TBooleanArrayHelper.Text(const strTrue, strFalse, separator: string): string; overload;
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

function TBooleanArrayHelper.Text(const strTrue: string = 'True'; strFalse: string = 'False'): string; overload;
begin
  Result := Self.Text(strTrue, strFalse, ', ');
end;

{==============================================================================]
  <TBooleanArrayHelper.TIA>
  @action: Returns TBooleanArray as Integers.
  @note: [True, False] => [1, 0].
[==============================================================================}
function TBooleanArrayHelper.TIA(const valTrue: Integer = 1; const valFalse: Integer = 0): TIntegerArray; overload;
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
function TBooleanArrayHelper.Toggle: TBooleanArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := (not Self[i]);
end;

{==============================================================================]
  <TBooleanArrayHelper.Trued>
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
  <TBooleanArrayHelper.Trueless>
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
  <TBooleanArrayHelper.Trueless(maxTrue: Integer): Boolean>
  @action: Support for requirement amount of Trues.
  @note: [False, True, False, False] (1) => True / (0) => False.
[==============================================================================}
function TBooleanArrayHelper.Trueless(const maxTrue: Integer): Boolean; overload;
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
function TBooleanArrayHelper.Trueness: Integer; overload;
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
function TBooleanArrayHelper.Trues: TIntegerArray; overload;
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
  <TBooleanArrayHelper.Truesome(minTrue: Integer): Boolean>
  @action: Support for minTrue.
  @note: None.
[==============================================================================}
function TBooleanArrayHelper.Truesome(const minTrue: Integer): Boolean; overload;
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
function TBooleanArrayHelper.Opposite: TBooleanArray; overload;
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
function TBooleanArrayHelper.BinaryStr: string;
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
function TBooleanArrayHelper.BinaryDigits: TIntegerArray;
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
function TBooleanArrayHelper.Binary: string;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := Self[i].Binary;  
end;

{==============================================================================]
  <TBooleanArrayHelper.Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           setting all booleans to False, while keeping the current length unchanged.
  @note: Works safely because Boolean is an unmanaged type (1 byte per element).
[==============================================================================}
function TBooleanArrayHelper.Reinit: Integer; overload;
begin
  Result := Length(Self);
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(Boolean)), 0);
end;

{==============================================================================]
  <TBooleanArrayHelper.Occupancy>
  @action: Returns the occupancy of the array: fraction of elements that are True.
           1.0 = all val, 0.0 = no vals
[==============================================================================}
function TBooleanArrayHelper.Occupancy(const val: Boolean = True): Double; overload;
var
  i, c: Integer;
begin
  if Self.Empty then
    Exit(0.0);
  c := 0;
  for i := 0 to High(Self) do
    if (Self[i] = val) then
      Inc(c);
  Result := (c / Length(Self));
end;

{==============================================================================]
  <TBooleanArrayHelper.Attach>
  @action: Appends all points from the given array to the end of Self.
           Returns the new total length of the array after appending.
  @note:   Uses Move() for efficiency since Boolean is an unmanaged type.
           If the input array is empty, the function returns the current length
           of Self without modification.
[==============================================================================}
function TBooleanArrayHelper.Attach(const items: TBooleanArray): Integer; overload;
var
  l, i: Integer;
begin
  l := Length(Self);
  i := Length(items);
  if (i = 0) then
    Exit(l);
  Result := (l + i);
  SetLength(Self, Result);
  Move(items[0], Self[l], (i * SizeOf(Boolean)));
end;

{==============================================================================]
  <TBooleanArrayHelper.Embed>
  @action: Inserts the contents of another boolean array into the current array
           at the specified index. Existing elements from that position onward
           are shifted to make room for the new items.
  @note: If the index exceeds the current length, the items are appended.
         Passing an empty array leaves the original array unchanged.
         The function returns the new total element count.
[==============================================================================}
function TBooleanArrayHelper.Embed(const items: TBooleanArray; const index: Integer = 2147483647): Integer; overload;
var
  s, l, p, t: Integer;
begin
  s := Length(Self);
  l := Length(items);
  if (l = 0) then
    Exit(s);
  p := EnsureRange(index, 0, s);
  t := (s - p);
  SetLength(Self, (s + l));
  if (t > 0) then
    Move(Self[p], Self[p + l], (t * SizeOf(Boolean)));
  Move(items[0], Self[p], (l * SizeOf(Boolean)));
  Result := Length(Self);
end;

class function TBA.Init(var arr: TBooleanArray): Integer; overload; 
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], Result, 0);
end;

{$ENDIF}

{$UNDEF Boolean}