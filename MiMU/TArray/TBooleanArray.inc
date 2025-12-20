{$DEFINE Boolean}{$I ..\Configuration\Defines.inc}

{$IFDEF TYPES}
TBA = class
  class function Init(var arr: TBooleanArray): Integer; overload; 
end;
{$ENDIF}

{$IFDEF HELPERS}
TBooleanArrayHelper = type helper for TBooleanArray
  {$I Core.inc}
  function Select(const sTrue, sFalse: Integer): TIntegerArray; overload;
  function Select(const sTrue, sFalse: Double): TDoubleArray; overload;
  function Select(const sTrue, sFalse: string): TStringArray; overload;
  function Select(const sTrue, sFalse: Char): TCharArray; overload;
  function Select(const sTrue, sFalse: Boolean): TBooleanArray; overload;
  function Select(const sTrue, sFalse: TPoint): TPointArray; overload;
  function Select(const sTrue, sFalse: TBox): TBoxArray; overload;
  function Select(const sTrue, sFalse: TRange): TRangeArray; overload;
  function Bits: Integer;
  function Bitify: Integer;
  function ToBits: Integer;
  function Digits: TIntegerArray; overload;
  function Falsed: Boolean; overload;
  function Falseless: Boolean; overload;
  function Falseless(const maxFalse: Integer): Boolean; overload;
  function Falseness: Integer; overload;
  function Falses: TIntegerArray; overload;
  function Falsesome: Boolean; overload;
  function Falsesome(const minFalse: Integer): Boolean; overload;
  function Str(const separator: string; const strTrue: string = 'True'; strFalse: string = 'False'): string; overload;
  function Str: string; overload;
  function Text(const strTrue, strFalse, separator: string): string; overload;
  function Text(const strTrue: string = 'True'; strFalse: string = 'False'): string; overload;
  function TIA(const valTrue: Integer = 1; const valFalse: Integer = 0): TIntegerArray; overload;
  function Toggle: TBooleanArray; overload;
  function Trued: Boolean; overload;
  function Trueless: Boolean; overload;
  function Trueless(const maxTrue: Integer): Boolean; overload;
  function Trueness: Integer; overload;
  function Trues: TIntegerArray; overload;
  function Truesome: Boolean; overload;
  function Truesome(const minTrue: Integer): Boolean; overload;
  function Opposite: TBooleanArray; overload;
  function BinaryStr: string;
  function BinaryDigits: TIntegerArray;
  function Binary: string;
  function Reinit: Integer; overload;
  function Occupancy(const val: Boolean = True): Double; overload;
  function Attach(const items: TBooleanArray): Integer; overload;
  function Embed(const items: TBooleanArray; const index: Integer = 2147483647): Integer; overload;
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS) OR DEFINED(CLASSES)}
{$I Core.inc}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Select>
  @action: IfThen method for TBooleanArray.
  @note: [True, False, True] => 5.
[==============================================================================}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Integer): TIntegerArray; overload; {$DEFINE Skeleton_Select2}{$I Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Double): TDoubleArray; overload; {$DEFINE Skeleton_Select2}{$I Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: string): TStringArray; overload; {$DEFINE Skeleton_Select2}{$I Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Char): TCharArray; overload; {$DEFINE Skeleton_Select2}{$I Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: Boolean): TBooleanArray; overload; {$DEFINE Skeleton_Select2}{$I Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TPoint): TPointArray; overload; {$DEFINE Skeleton_Select2}{$I Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TBox): TBoxArray; overload; {$DEFINE Skeleton_Select2}{$I Skeletons.inc}{$UNDEF Skeleton_Select2}
function TBooleanArrayHelper.Select(const sTrue, sFalse: TRange): TRangeArray; overload; {$DEFINE Skeleton_Select2}{$I Skeletons.inc}{$UNDEF Skeleton_Select2}

{==============================================================================]
  <Bitify>
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
  <Bits>
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
  <ToBits>
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
  <Digits>
  @action: Returns TBooleanArray as Integers.
  @note: [True, False] => [1, 0].
[==============================================================================}
function TBooleanArrayHelper.Digits: TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Ord(Self[i]);
end;

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
  <Falseness>
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
  <Falses>
  @action: Returns Indexes of arr where state is False.
  @note: [True, False, True, False] => [1,3]
[==============================================================================}
function TBooleanArrayHelper.Falses: TIntegerArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, Self.Size);
  r := 0;
  for i := 0 to High(Self) do
    if not Self[i] then
      Result[r.Increase] := i;
  SetLength(Result, r);
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
  <Str>
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
    SetLength(Result, (System.Length(Result) - System.Length(separator)));
  Result := (Result + ']');
end;

function TBooleanArrayHelper.Str: string; overload;
begin
  Result := Self.Str(', ');
end;

{==============================================================================]
  <Text>
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
    SetLength(Result, (System.Length(Result) - System.Length(separator)));
  Result := (Result + ']');
end;

function TBooleanArrayHelper.Text(const strTrue: string = 'True'; strFalse: string = 'False'): string; overload;
begin
  Result := Self.Text(strTrue, strFalse, ', ');
end;

{==============================================================================]
  <TIA>
  @action: Returns TBooleanArray as Integers.
  @note: [True, False] => [1, 0].
[==============================================================================}
function TBooleanArrayHelper.TIA(const valTrue: Integer = 1; const valFalse: Integer = 0): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    if Self[i] then
      Result[i] := valTrue
    else
      Result[i] := valFalse;
end;

{==============================================================================]
  <Toggle>
  @action: Returns opposite version of arr.
  @note: [True, False] => [False, True].
[==============================================================================}
function TBooleanArrayHelper.Toggle: TBooleanArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := (not Self[i]);
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
  <Trueness>
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
  <Trues>
  @action: Returns Indexes of arr where state is True.
  @note: [True, False, True, False] => [0,2]
[==============================================================================}
function TBooleanArrayHelper.Trues: TIntegerArray; overload;
var
  i, r: Integer;
begin
  SetLength(Result, Self.Size);
  r := 0;
  for i := 0 to High(Self) do
    if (Self[i] = True) then
      Result[r.Increase] := i;
  SetLength(Result, r);
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

{==============================================================================]
  <Opposite>
  @action: Returns opposite version of arr.
  @note: [True, False] => [False, True].
[==============================================================================}
function TBooleanArrayHelper.Opposite: TBooleanArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    if Self[i] then
      Result[i] := False
	else
	  Result[i] := True;
end;

{==============================================================================]
  <BinaryStr>
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
  <BinaryDigits>
  @action: Returns binary digits from Boolean Array
  @note: [True, False] => [1, 0] & [False, True] => [0, 1]
[==============================================================================}
function TBooleanArrayHelper.BinaryDigits: TIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := IfThen(Self[i], 1, 0);  
end;

{==============================================================================]
  <Binary>
  @action: Returns binary string from Boolean Array
  @note: [True, False] => '10' & [False, True] => '01'
[==============================================================================}
function TBooleanArrayHelper.Binary: string;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Binary;  
end;

{==============================================================================]
  <Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           setting all booleans to False, while keeping the current length unchanged.
  @note: Works safely because Boolean is an unmanaged type (1 byte per element).
[==============================================================================}
function TBooleanArrayHelper.Reinit: Integer; overload;
begin
  Result := Self.Size;
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(Boolean)), 0);
end;

{==============================================================================]
  <Occupancy>
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
  Result := (c / Self.Size);
end;

{==============================================================================]
  <Attach>
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
  l := Self.Length;
  i := items.Size;
  if (i = 0) then
    Exit(l);
  Result := (l + i);
  SetLength(Self, Result);
  Move(items[0], Self[l], (i * SizeOf(Boolean)));
end;

{==============================================================================]
  <Embed>
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
  s := Self.Size;
  l := items.Length;
  if (l = 0) then
    Exit(s);
  p := EnsureRange(index, 0, s);
  t := (s - p);
  SetLength(Self, (s + l));
  if (t > 0) then
    Move(Self[p], Self[p + l], (t * SizeOf(Boolean)));
  Move(items[0], Self[p], (l * SizeOf(Boolean)));
  Result := Self.Size;
end;

class function TBA.Init(var arr: TBooleanArray): Integer; overload; 
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], Result, 0);
end;
{$ENDIF}

{$UNDEF Boolean}