                                            { MiMU is Massive Unit )
 ╔╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╗
 ╠╬╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╬╣
 ╠╣                                                                                                           ╠╣
 ╠╣                                                                                                           ╠╣
 ╠╣              _____                    _____                    _____                   _____              ╠╣
 ╠╣             /\    \                  /\    \                  /\    \                 /\    \             ╠╣
 ╠╣            /##\____\                /##\    \                /##\____\               /##\____\            ╠╣
 ╠╣           /####|   |                \###\    \              /####|   |              /###/    /            ╠╣
 ╠╣          /#####|   |                 \###\    \            /#####|   |             /###/    /             ╠╣
 ╠╣         /######|   |                  \###\    \          /######|   |            /###/    /              ╠╣
 ╠╣        /###/|##|   |                   \###\    \        /###/|##|   |           /###/    /               ╠╣
 ╠╣       /###/ |##|   |                   /####\    \      /###/ |##|   |          /###/    /                ╠╣
 ╠╣      /###/  |##|___|______    ____    /######\    \    /###/  |##|___|______   /###/    /      _____      ╠╣
 ╠╣     /###/   |########\    \  /\   \  /###/\###\    \  /###/   |########\    \ /###/____/      /\    \     ╠╣
 ╠╣    /###/    |#########\____\/##\   \/###/  \###\____\/###/    |#########\____\###|    /      /##\____\    ╠╣
 ╠╣    \##/    / -----/###/    /\###\  /###/    \##/    /\##/    / -----/###/    /###|____\     /###/    /    ╠╣
 ╠╣     \/____/      /###/    /  \###\/###/    / \/____/  \/____/      /###/    / \###\    \   /###/    /     ╠╣
 ╠╣                 /###/    /    \######/    /                       /###/    /   \###\    \ /###/    /      ╠╣
 ╠╣                /###/    /      \####/____/                       /###/    /     \###\    /###/    /       ╠╣
 ╠╣               /###/    /        \###\    \                      /###/    /       \###\__/###/    /        ╠╣
 ╠╣              /###/    /          \###\    \                    /###/    /         \########/    /         ╠╣
 ╠╣             /###/    /            \###\    \                  /###/    /           \######/    /          ╠╣
 ╠╣            /###/    /              \###\____\                /###/    /             \####/    /           ╠╣
 ╠╣            \##/    /                \##/    /                \##/    /               \##/    /            ╠╣
 ╠╣             \/____/                  \/____/                  \/____/                 \/____/             ╠╣
 ╠╣                                                                                                           ╠╣
 ╠╣                                                                                                           ╠╣
 ╠╬╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╬╣
 ╚╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╝
                                             ( ..for Free Pascal }

{$mode objfpc}
{$macro on}
{$inline on}
{$modeswitch advancedrecords}
{$modeswitch arrayoperators}
{$modeswitch typehelpers}
{$H+}

unit MiMU;

interface

uses
  Classes, SysUtils, StrUtils, Math, Generics.Collections, Generics.Defaults, FGL;

const
  MiMU_VERSION_NUMBER = 0.5;

function MiMU_Version: Double;

type
  generic TCompare<T> = function(const A, B: T): Integer;
  TByteSet = set of Byte;

{$I MiMU/MiMU.inc}

generic function Sort<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
generic function Sort<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
generic function Swap<T>(var A, B: T): Boolean; overload;
generic function Swop<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
generic function Swop<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
generic function Arrange<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
generic function Arrange<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
generic function Contains<T>(const arr: array of T; const item: T): Boolean;
generic function Includes<T>(const arr: array of T; const item: T): Boolean;
generic function Position<T>(const arr: array of T; const item: T): Integer;
generic function Location<T>(const arr: array of T; const item: T): Integer;
generic function Indexes<T>(const arr: array of T): TIntegerArray;
generic function IfThenElse<T>(const aBool, bBool: Boolean; const aResult, bResult, cResult: T): T;
generic function SetSize<T>(var A, B: specialize TArray<T>; const size: Integer = 1): Integer; overload;
generic function SetSize<T>(var A, B, C: specialize TArray<T>; const size: Integer = 1): Integer; overload;
generic function SetSize<T>(var A, B, C, D: specialize TArray<T>; const size: Integer = 1): Integer; overload;
generic function Trade<T>(var A, B: T): Boolean; overload;
generic function QuickSort<T>(var arr: array of T; const comp: specialize TCompare<T>): Integer; overload;

implementation

{$DEFINE IMPLEMENTATION}

function MiMU_Version: Double;
begin
  Result := MiMU_VERSION_NUMBER;
end;

{==============================================================================]
  <Swap>
  @action: Swaps the values of two variables of any type T.
  @note: Returns True if the values were different before the swap, False otherwise.
         Requires that type T supports the <> operator.
[==============================================================================}
generic function Swap<T>(var A, B: T): Boolean; overload;
var
  C: T;
begin
  Result := (A <> B);
  C := A;
  A := B;
  B := C;
end;

{==============================================================================]
  <Swop>
  @action: Swaps two variables A and B if they are out of order according to the specified ascending flag.
  @note: Returns True if a swap occurred, False otherwise.
[==============================================================================}
generic function Swop<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
var
 S: T;
begin
  Result := ((oAscending and (A > B)) or ((not oAscending) and (B > A)));
  if not Result then
    Exit;
  S := A;
  A := B;
  B := S;
end;

{==============================================================================]
  <Swop>
  @action: Arranges three variables A, B, C in order according to the ascending flag by performing minimal swaps.
  @note: Returns True if any swap occurred, False otherwise.
[==============================================================================}
generic function Swop<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
var
  S: T;
procedure SwapIf(var X, Y: T);
begin
  if ((oAscending and (X > Y)) or ((not oAscending) and (X < Y))) then
  begin
    S := X;
    X := Y;
    Y := S;
    Result := True;
  end;
end;
begin
  Result := False;
  SwapIf(A, B);
  SwapIf(A, C);
  SwapIf(B, C);
end;

{==============================================================================]
  <Sort>
  @action: Ensures that two values are ordered according to the ascending flag, performing a swap if necessary.
  @note: Returns True if a swap occurred, False otherwise. Calls generic Swap<T> internally.
[==============================================================================}
generic function Sort<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((oAscending and (A > B)) or ((not oAscending) and (A < B)));
  if Result then
    specialize Swap<T>(A, B);
end;

{==============================================================================]
  <Sort>
  @action: Ensures that three values A, B, C are ordered according to the ascending flag, performing swaps if necessary.
  @note: Returns True if any swaps occurred, False otherwise. Does not fully sort arrays, only these three values.
[==============================================================================}
generic function Sort<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
  function DoSwap(var X, Y: T): Boolean;
  var
    Z: T;
  begin
    Z := X;
    X := Y;
    Y := Z;
    Result := True;
  end;
begin
  Result := False;
  if ((oAscending and (A > B)) or ((not oAscending) and (A < B))) then
    Result := DoSwap(A, B);
  if ((oAscending and (A > C)) or ((not oAscending) and (A < C))) then
    Result := DoSwap(A, C);
  if ((oAscending and (B > C)) or ((not oAscending) and (B < C))) then
    Result := DoSwap(B, C);
end;

{==============================================================================]
  <Arrange>
  @action: Ensures that the two items A and B are in the specified order (ascending or descending).
           Performs a swap if necessary.
  @note: Returns True if a swap occurred, False otherwise.
         This function only arranges the two values; it does not sort arrays or larger collections.
[==============================================================================}
generic function Arrange<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((oAscending and (A > B)) or ((not oAscending) and (A < B)));
  if Result then
    specialize Swap<T>(A, B);
end;

{==============================================================================]
  <Arrange>
  @action: Ensures that the three items A, B, and C are arranged relative to each other according
           to the specified order (ascending or descending).
           Performs minimal swaps to enforce ordering between the three items.
  @note: Returns True if any swaps occurred, False otherwise.
         This function does not perform a full sort; it only arranges the three values
         relative to each other.
[==============================================================================}
generic function Arrange<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := (specialize Arrange<T>(A, B) or specialize Arrange<T>(A, C) or specialize Arrange<T>(B, C));
end;

{==============================================================================]
  <Contains>
  @action: Checks if a given item exists in an array.
  @note: Returns True if the item is found, False otherwise. Searches from Low(arr) to High(arr).
[==============================================================================}
generic function Contains<T>(const arr: array of T; const item: T): Boolean;
var
  i: Integer;
begin
  for i := Low(arr) to High(arr) do
    if (arr[i] = item) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Includes>
  @action: Checks if a given item exists in an array.
  @note: Returns True if the item is found, False otherwise. Searches from High(arr) down to Low(arr).
[==============================================================================}
generic function Includes<T>(const arr: array of T; const item: T): Boolean;
var
  i: Integer;
begin
  for i := High(arr) downto Low(arr) do
    if (arr[i] = item) then
      Exit(True);
  Result := False;
end;

{==============================================================================]
  <Position>
  @action: Finds the first index of an item in an array.
  @note: Returns the index if found, -1 if the item does not exist. Searches Low to High.
[==============================================================================}
generic function Position<T>(const arr: array of T; const item: T): Integer;
var
  i: Integer;
begin
  for i := Low(arr) to High(arr) do
    if (arr[i] = item) then
      Exit(i);
  Result := -1;
end;

{==============================================================================]
  <Location>
  @action: Finds the last index of an item in an array.
  @note: Returns the index if found, -1 if the item does not exist. Searches High to Low.
[==============================================================================}
generic function Location<T>(const arr: array of T; const item: T): Integer;
var
  i: Integer;
begin
  for i := High(arr) downto Low(arr) do
    if (arr[i] = item) then
      Exit(i);
  Result := -1;
end;

{==============================================================================]
  <Indexes>
  @action: Generates an array of integer indexes corresponding to the input array.
  @note: The returned array has the same length as the input array, with values Low(arr) to High(arr).
[==============================================================================}
generic function Indexes<T>(const arr: array of T): TIntegerArray;
var
  i, l: Integer;
begin
  SetLength(Result, Length(arr));
  l := Low(arr);
  for i := l to High(arr) do
    Result[i - l] := i;
end;

{==============================================================================]
  <IfThenElse>
  @action: Returns one of three possible results depending on two Boolean conditions.
  @note: Evaluates aBool first, then bBool, returning aResult, bResult, or cResult accordingly.
[==============================================================================}
generic function IfThenElse<T>(const aBool, bBool: Boolean; const aResult, bResult, cResult: T): T;
begin
  if aBool then
    Result := aResult
  else
    if bBool then
      Result := bResult
    else
      Result := cResult;
end;

{==============================================================================]
  <SetSize>
  @action: Resizes two dynamic arrays to the specified size.
  @note: Returns the size used. Size is clamped to 0 minimum. Overloaded for multiple arrays.
[==============================================================================}
generic function SetSize<T>(var A, B: specialize TArray<T>; const size: Integer = 1): Integer; overload;
begin
  Result := Max(0, size);
  SetLength(A, Result);
  SetLength(B, Result);
end;

{==============================================================================]
  <SetSize>
  @action: Resizes three dynamic arrays to the specified size.
  @note: Returns the size used. Size is clamped to 0 minimum. Overloaded for multiple arrays.
[==============================================================================}
generic function SetSize<T>(var A, B, C: specialize TArray<T>; const size: Integer = 1): Integer; overload;
begin
  Result := Max(0, size);
  SetLength(A, Result);
  SetLength(B, Result);
  SetLength(C, Result);
end;

{==============================================================================]
  <SetSize>
  @action: Resizes four dynamic arrays to the specified size.
  @note: Returns the size used. Size is clamped to 0 minimum. Overloaded for multiple arrays.
[==============================================================================}
generic function SetSize<T>(var A, B, C, D: specialize TArray<T>; const size: Integer = 1): Integer; overload;
begin
  Result := Max(0, size);
  SetLength(A, Result);
  SetLength(B, Result);
  SetLength(C, Result);
  SetLength(D, Result);
end;

{==============================================================================]
  <Trade>
  @action: Swaps two variables if their memory addresses are different.
  @note: Returns True if a swap occurred, False otherwise.
[==============================================================================}
generic function Trade<T>(var A, B: T): Boolean; overload;
var
  C: T;
begin
  Result := (@A <> @B);
  if Result then
  begin
    C := A;
    A := B;
    B := C;
  end;
end;

{==============================================================================]
  <QuickSort>
  @action: Performs an in-place QuickSort on a dynamic array of any type T.
           Uses a provided comparer function to determine ordering.
  @note: Returns the length of the array (optional). The array is modified directly.
         Pivot selection is safe against integer overflow. Uses generic Swap<T> internally.
[==============================================================================}
generic function QuickSort<T>(var arr: array of T; const comp: specialize TCompare<T>): Integer; overload;
  procedure Sorting(L, R: Integer);
  var
    P: T;
    I, J: Integer;
  begin
    I := L;
    J := R;
    P := arr[L + ((R - L) div 2)];
    repeat
      while (comp(arr[I], P) < 0) do
        Inc(I);
      while (comp(arr[J], P) > 0) do
        Dec(J);
      if (I <= J) then
      begin
        specialize Swap<T>(arr[I], arr[J]);
        Inc(I);
        Dec(J);
      end;
    until (I > J);
    if (L < J) then
	  Sorting(L, J);
    if (I < R) then
      Sorting(I, R);
  end;
begin
  Result := Length(arr);
  if (Result > 1) then
    Sorting(0, High(arr));
end;

{$I MiMU/MiMU.inc}

{$UNDEF IMPLEMENTATION}

initialization

finalization

end.
