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

{$mode objfpc}{$H+}
{$MODESWITCH ADVANCEDRECORDS}
{$MODESWITCH ARRAYOPERATORS}
{$MODESWITCH TYPEHELPERS}
{$MACRO ON}
{$INLINE ON}

unit MiMU;

interface

uses
  Classes, SysUtils, StrUtils, Math, Generics.Collections, Generics.Defaults, FGL, gdeque;

const
  {Radix sets}
  BINARY_CHARS: set of Char = ['0', '1'];
  BINARY_BITS: set of Byte = [0, 1];
  BINARY_BOOLS: set of Boolean = [False, True];
  BINARY_CODES: set of Byte = [48, 49];
  DIGIT_CHARS: set of Char = ['0'..'9'];
  SIGN_CHARS: set of Char = ['+', '-'];
  
  BOOL_CHR: array[Boolean] of Char = ('0', '1');
  BOOL_BIT: array[Boolean] of Byte = (0, 1);
  BOOL_STR: array[Boolean] of string = ('False', 'True');
  
  {Digit value tables}
  DECIMAL_VALUES: array['0'..'9'] of Byte = (0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  BASE_DIGITS: array[0..9] of Byte = (0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  DIGIT_MINIMA: array[0..18] of Int64 = (
    0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000,
    10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000
  );
  DIGIT_MAXIMA: array[0..18] of Int64 = (
    0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999, 99999999999, 999999999999, 9999999999999,
    99999999999999, 999999999999999, 9999999999999999, 99999999999999999, 999999999999999999
  );
  
  {Power tables}
  POWERS_OF_TEN: array[0..18] of Int64 = (
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000,
	10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000
  );
  POWERS_OF_TWO: array[0..62] of Int64 = (
    1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576,
    2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648,
    4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776,
    2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664, 140737488355328, 281474976710656, 562949953421312,
    1125899906842624, 2251799813685248, 4503599627370496, 9007199254740992, 18014398509481984, 36028797018963968,
    72057594037927936, 144115188075855872, 288230376151711744, 576460752303423488, 1152921504606846976, 2305843009213693952, 4611686018427387904
  );
  
  WHITESPACE_CHARS: set of Char = [#9, #10, #13, #32];
  ALPHA_CHARS: set of Char = ['A'..'Z', 'a'..'z'];
  UPPER_CHARS: set of Char = ['A'..'Z'];
  LOWER_CHARS: set of Char = ['a'..'z'];
  
  NULL = #0;
  TAB = #9;
  LF = #10;
  CR = #13;
  SPACE = #32;
  CRLF = #13#10;

  MIN_INTEGER: Integer = -2147483648;
  MAX_INTEGER: Integer = 2147483647;
  MIN_INT64: Int64 = -9223372036854775808;
  MAX_INT64: Int64 = 9223372036854775807;
  
  MiMU_VERSION_NUMBER = 0.5;

function MiMU_Version: Double;

type
  generic TCompare<T> = function(const A, B: T): Integer;
  generic TInterval<T> = record
    lower, upper: T;
    class operator =(const a, b: TInterval): Boolean; overload;
    class operator <>(const a, b: TInterval): Boolean; overload;
    constructor Create(const a, b: T);
    function Adjoins(const other: TInterval): Boolean; overload;
    function Clamp(const item: T): T; overload;
    function Contains(const item: T): Boolean; overload;
    function Contains(const other: TInterval): Boolean; overload;
    function Extend(const other: TInterval): TInterval; overload;
    function Extend(const item: T): TInterval; overload;
    function Intersect(const other: TInterval): TInterval; overload;
    function Overlaps(const other: TInterval): Boolean; overload;
    function Plural: Boolean; overload;
    function Precedes(const other: TInterval): Boolean; overload;
    function Singular: Boolean; overload;
    function Succeeds(const other: TInterval): Boolean; overload;
  end;

{$I MiMU/MiMU.inc}

generic function Interval<T>(const a, b: T): specialize TInterval<T>; overload;

generic function IncEx<T>(var values: array of T; const N: T = 1): Integer; overload;
generic function DecEx<T>(var values: array of T; const N: T = 1): Integer; overload;
generic function Sort<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
generic function Sort<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
generic function Swappify<T>(var current: T; var target: T): T; overload;
generic function Swap<T>(var A, B: T): Boolean; overload;
generic function Swop<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
generic function Swop<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
generic function Arrange<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
generic function Arrange<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
generic function Contains<T>(const arr: array of T; const item: T): Boolean; overload;
generic function Includes<T>(const arr: array of T; const item: T): Boolean; overload;
generic function Position<T>(const arr: array of T; const item: T): Integer; overload;
generic function Location<T>(const arr: array of T; const item: T): Integer; overload;
generic function Indexes<T>(const arr: array of T): TIntegerArray; overload;
generic function Indices<T>(const arr: array of T): TIntegerArray; overload;
generic function IDs<T>(const arr: array of T): TIntegerArray; overload;
generic function GetArrayBounds<T>(const arr: array of T; out L, H: Integer): Integer; overload;
generic function IfThenElse<T>(const aBool, bBool: Boolean; const aResult, bResult, cResult: T): T; overload;
generic function Iff<T>(bState: Boolean; const bTrue, bFalse: T): T; overload;
generic function SetSize<T>(var A, B: specialize TArray<T>; const size: Integer = 1): Integer; overload;
generic function SetSize<T>(var A, B, C: specialize TArray<T>; const size: Integer = 1): Integer; overload;
generic function SetSize<T>(var A, B, C, D: specialize TArray<T>; const size: Integer = 1): Integer; overload;
generic function Trade<T>(var A, B: T): Boolean; overload;
generic function QuickSort<T>(var arr: array of T; const comp: specialize TCompare<T>): Integer; overload;
generic function QSort<T>(var arr: array of T; const comp: specialize TCompare<T>): Integer; overload;

implementation

{$DEFINE IMPLEMENTATION}

function MiMU_Version: Double;
begin
  Result := MiMU_VERSION_NUMBER;
end;

class operator TInterval.=(const a, b: TInterval): Boolean; overload;
begin
  Result := ((a.lower = b.lower) and (a.upper = b.upper));
end;

class operator TInterval.<>(const a, b: TInterval): Boolean; overload;
begin
  Result := not (a = b);
end;

{==============================================================================]
  <Create>
  @action: Constructs a TInterval from two values in either order, normalizing them so `lower` always holds the smaller and `upper` always holds the larger.
  @note: Enforces the interval invariant (lower <= upper) unconditionally — there is no way to construct an out-of-order TInterval, so no caller-side validation is needed downstream.
[==============================================================================}
constructor TInterval.Create(const a, b: T);
begin
  if (a <= b) then
  begin
    Self.lower := a;
    Self.upper := b;
  end else
  begin
    Self.lower := b;
    Self.upper := a;
  end;
end;

{==============================================================================]
  <Adjoins>
  @action: Checks whether this interval touches another at exactly one boundary point, with no interior overlap.
  @note: True when Self.upper = other.lower or Self.lower = other.upper. Distinct from Overlaps, which already counts boundary-touching as True — Adjoins isolates that specific edge case from genuine interior overlap.
[==============================================================================}
function TInterval.Adjoins(const other: TInterval): Boolean; overload;
begin
  Result := ((Self.upper = other.lower) or (Self.lower = other.upper));
end;

{==============================================================================]
  <Clamp>
  @action: Constrains a item to fall within [lower, upper], leaving it unchanged if already inside.
  @note: Ordered-only tier — uses comparison alone, no arithmetic, so it works for any T including Char.
[==============================================================================}
function TInterval.Clamp(const item: T): T; overload;
begin
  if (item < Self.lower) then
    Result := Self.lower
  else if (item > Self.upper) then
    Result := Self.upper
  else
    Result := item;
end;

{==============================================================================]
  <Contains>
  @action: Checks whether a value lies within the interval, inclusive of both endpoints.
  @note: Bounds are inclusive on both ends (`>= lower` and `<= upper`); since `TInterval`'s invariant guarantees `lower <= upper`.
[==============================================================================}
function TInterval.Contains(const item: T): Boolean; overload;
begin
  Result := ((item >= Self.lower) and (item <= Self.upper));
end;

{==============================================================================]
  <Contains>
  @action: Checks if the current interval completely encompasses the specified 'other' interval.
  @note: Returns True only if 'other' starts on or after Self.lower AND ends on or before Self.upper.
[==============================================================================}
function TInterval.Contains(const other: TInterval): Boolean; overload;
begin
  Result := ((Self.lower <= other.lower) and (Self.upper >= other.upper));
end;

{==============================================================================]
  <Extend>
  @action: Returns the smallest TInterval that fully encloses both this interval and another.
  @note: This is a bounding operation, not a set union — if the two intervals don't overlap,
         the result still spans the gap between them (e.g. [1,3] and [8,10] consolidate to [1,10],
		 not two separate pieces). Relies on TInterval's invariant holding for both operands.
[==============================================================================}
function TInterval.Extend(const other: TInterval): TInterval; overload;
var
  l, u: T;
begin
  if (Self.lower <= other.lower) then
    l := Self.lower
  else
    l := other.lower;
  if (Self.upper >= other.upper) then
    u := Self.upper
  else
    u := other.upper;
  Result := TInterval.Create(l, u);
end;

{==============================================================================]
  <Extend>
  @action: Returns a new TInterval, grown just enough to include a item or another interval that may fall outside the current bounds.
  @note: If the argument is already fully within [lower, upper], the result is identical to the original.
         Only ever widens, never shrinks — ordered-only tier, works for any T.
[==============================================================================}
function TInterval.Extend(const item: T): TInterval; overload;
var
  l, u: T;
begin
  if (Self.lower <= item) then
    l := Self.lower
  else
    l := item;
  if (Self.upper >= item) then
    u := Self.upper
  else
    u := item;
  Result := TInterval.Create(l, u);
end;

{==============================================================================]
  <Intersect>
  @action: Returns the interval representing the overlapping region between this interval and another.
  @note: Only meaningful when Overlaps(other) is True — callers should check Overlaps first. If the intervals do not overlap, the result violates TInterval's invariant (lower > upper) and should not be used.
[==============================================================================}
function TInterval.Intersect(const other: TInterval): TInterval; overload;
var
  l, u: T;
begin
  if (Self.lower >= other.lower) then
    l := Self.lower
  else
    l := other.lower;
  if (Self.upper <= other.upper) then
    u := Self.upper
  else
    u := other.upper;
  Result := TInterval.Create(l, u);
end;

{==============================================================================]
  <Overlaps>
  @action: Checks whether this interval shares any values with another interval.
  @note: Standard closed-interval overlap test: two intervals overlap iff each one's lower bound is not past the other's upper bound.
         Relies on TInterval's invariant (lower <= upper) holding for both operands.
[==============================================================================}
function TInterval.Overlaps(const other: TInterval): Boolean; overload;
begin
  Result := ((Self.lower <= other.upper) and (other.lower <= Self.upper));
end;

{==============================================================================]
  <Plural>
  @action: Checks whether the interval spans more than a single point (lower differs from upper).
  @note: The logical complement of Singular — every valid TInterval is either Singular (a single point) or Plural (a proper span), never both.
[==============================================================================}
function TInterval.Plural: Boolean; overload;
begin
  Result := (Self.lower < Self.upper);
end;

{==============================================================================]
  <Precedes>
  @action: Checks whether this interval lies entirely before another, with no overlap.
  @note: Strict — if the intervals merely touch at a boundary (Self.upper = other.lower), this returns False, since that boundary point is shared. Complements Overlaps: for any two intervals, exactly one of Overlaps, Precedes, or other.Precedes(Self) holds.
[==============================================================================}
function TInterval.Precedes(const other: TInterval): Boolean; overload;
begin
  Result := (Self.upper < other.lower);
end;

{==============================================================================]
  <Singular>
  @action: Checks whether the interval collapses to a single point (lower equals upper).
  @note: A valid, non-empty edge case under the invariant — Create(5, 5) is legal and produces a degenerate interval.
[==============================================================================}
function TInterval.Singular: Boolean; overload;
begin
  Result := (Self.lower = Self.upper);
end;

{==============================================================================]
  <Succeeds>
  @action: Checks whether this interval lies entirely after another, with no overlap.
  @note: Strict — if the intervals merely touch at a boundary (Self.lower = other.upper), this returns False, since that boundary point is shared. Mirror of Precedes: Self.Succeeds(other) is equivalent to other.Precedes(Self).
[==============================================================================}
function TInterval.Succeeds(const other: TInterval): Boolean; overload;
begin
  Result := (Self.lower > other.upper);
end;

{==============================================================================]
  <Interval>
  @action: Constructs a TInterval<T> from two values in either order, without requiring the caller to write out the full `specialize TInterval<T>.Create(...)` syntax.
  @note: A thin convenience wrapper — normalization (lower <= upper) is entirely handled by TInterval.Create itself.
         T is inferred from the argument types at the call site in most cases, so callers can typically write Interval(1, 10) rather than specialize Interval<Integer>(1, 10).
		 Requires T to support <=, same ordered-only constraint as TInterval itself.
[==============================================================================}
generic function Interval<T>(const a, b: T): specialize TInterval<T>; overload;
begin
  Result := specialize TInterval<T>.Create(a, b);
end;

{==============================================================================]
  <IncEx>
  @action: Increments every element in an open array by a specified value.
  @note: Operates directly on the passed array (var). Defaults to adding 1.
         Returns the total number of elements that were increased.
[==============================================================================}
generic function IncEx<T>(var values: array of T; const N: T = 1): Integer; overload;
var
  i: Integer;
begin
  Result := Length(values);
  for i := Low(values) to High(values) do
    values[i] := (values[i] + N);
end;

{==============================================================================]
  <DecEx>
  @action: Decrements every element in an open array by a specified value.
  @note: Operates directly on the passed array (var). Defaults to subtracting 1.
         Returns the total number of elements that were decreased.
[==============================================================================}
generic function DecEx<T>(var values: array of T; const N: T = 1): Integer; overload;
var
  i: Integer;
begin
  Result := Length(values);
  for i := Low(values) to High(values) do
    values[i] := (values[i] - N);
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
  <Swappify>
  @action: Mutually exchanges the values of Current and Target, then returns 
           the original historical value of Current.
  @note: Universal type-safe state-exchange pipeline utilizing generics. 
         Because it captures the pre-swap state of Current as the function result, 
         it enables fluent "fetch-and-replace" assignment chains for any data type.
[==============================================================================}
generic function Swappify<T>(var current: T; var target: T): T; overload;
begin
  Result := current;
  current := target;
  target := Result;
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
generic function Contains<T>(const arr: array of T; const item: T): Boolean; overload;
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
generic function Includes<T>(const arr: array of T; const item: T): Boolean; overload;
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
generic function Position<T>(const arr: array of T; const item: T): Integer; overload;
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
generic function Location<T>(const arr: array of T; const item: T): Integer; overload;
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
generic function Indexes<T>(const arr: array of T): TIntegerArray; overload;
var
  i, l: Integer;
begin
  SetLength(Result, Length(arr));
  l := Low(arr);
  for i := l to High(arr) do
    Result[i - l] := i;
end;

{==============================================================================]
  <Indices>
  @action: Returns an array containing all valid zero-based index values
           for the specified dynamic array.
  @note: Supports dynamic arrays only (passed via open array parameter).
         Allocates a new array with Length(arr) elements.
         Result range: 0 .. Length(arr) - 1.
         Time complexity: O(n). Space complexity: O(n).
[==============================================================================}
generic function Indices<T>(const arr: array of T): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Length(arr));
  for i := 0 to High(arr) do
    Result[i] := i;
end;

{==============================================================================]
  <IDs>
  @action: Returns an array containing sequential index values corresponding  
           to the valid element positions of the specified dynamic array.      
  @note: Supports dynamic arrays passed via open array parameter.           
         Result contains values: Low(arr) .. High(arr).                     
         Allocates a new dynamic array of size Length(arr). 
[==============================================================================}
generic function IDs<T>(const arr: array of T): TIntegerArray; overload;
var
  i, L, H: Integer;
begin
  L := Low(arr);
  H := High(arr);
  if (H < L) then
    Exit([]);
  SetLength(Result, ((H - L) + 1));
  for i := L to H do
    Result[i - L] := i;
end;

{==============================================================================]
  <GetArrayBounds>
  @action: Returns the bounds and element count of the specified dynamic array.
  @note: Supports dynamic arrays passed via open array parameter.
         Returns 0 if the array is empty.
         L = Low(arr), H = High(arr).
         Complexity: O(1). No element traversal performed.
[==============================================================================}
generic function GetArrayBounds<T>(const arr: array of T; out L, H: Integer): Integer; overload;
begin
  L := Low(arr);
  H := High(arr);
  if (H < L) then
    Exit(0);
  Result := ((H - L) + 1);
end;

{==============================================================================]
  <IfThenElse>
  @action: Returns one of three possible results depending on two Boolean conditions.
  @note: Evaluates aBool first, then bBool, returning aResult, bResult, or cResult accordingly.
[==============================================================================}
generic function IfThenElse<T>(const aBool, bBool: Boolean; const aResult, bResult, cResult: T): T; overload;
begin
  if aBool then
    Result := aResult
  else if bBool then
    Result := bResult
  else
    Result := cResult;
end;

generic function Iff<T>(bState: Boolean; const bTrue, bFalse: T): T; overload;
begin
  if bState then
    Result := bTrue
  else
    Result := bFalse;
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

{==============================================================================]
  <QSort>
  @action: Sorts a dynamic array in place using QuickSort with Hoare partitioning, ordered by a caller-supplied three-way comparer.
  @note: Recurses into the smaller partition and loops into the larger one, bounding worst-case stack depth to O(log n) regardless of input order.
         Pivot is the middle element (overflow-safe index calculation), so adversarial/already-sorted input doesn't force worst-case behavior the way first/last-element pivoting would.
		 Works for any T, including types with no native ordering, since ordering comes entirely from comp. Returns Length(arr) for convenience.
[==============================================================================}
generic function QSort<T>(var arr: array of T; const comp: specialize TCompare<T>): Integer; overload;
  procedure Sorting(L, R: Integer);
  var
    I, J: Integer;
    P: T;
  begin
    while (L < R) do
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
      if ((J - L) < (R - I)) then
      begin
        if (L < J) then
		  Sorting(L, J);
        L := I;
      end else
      begin
        if (I < R) then
		  Sorting(I, R);
        R := J;
      end;
    end;
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
