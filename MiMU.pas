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

 unit MiMU;

{$mode objfpc}
{$macro on}
{$inline on}
{$modeswitch advancedrecords}
{$modeswitch arrayoperators}
{$modeswitch typehelpers}
{$H+}

interface

uses
  Classes, SysUtils, Math, Generics.Collections, Generics.Defaults, FGL;

const
  MiMU_VERSION_NUMBER = 0.5;

function MiMU_Version: Double;

type
  TDistanceMetric = (dmHypotEuclidean, dmEuclidean, dmEuclidean2, dmSquaredEuclidean, dmManhattan, dmChebyshev, dmMinkowski, dmMaxMinChebyshev, dmOctile);

{$I MiMU.inc}

function DistanceFunction(const distFunc: TDistanceFunction): TDistanceFunction; overload;
function DistanceFunction(const method: Integer = 0): TDistanceFunction; overload;
function DistanceFunction(const metric: TDistanceMetric): TDistanceFunction; overload;
function HypotEuclidean(const A, B: TPoint): Double;
function Euclidean(const A, B: TPoint): Double;
function Euclidean2(const A, B: TPoint): Double;
function SquaredEuclidean(const A, B: TPoint): Double;
function Manhattan(const A, B: TPoint): Double;
function Chebyshev(const A, B: TPoint): Double;
function Minkowski(const A, B: TPoint): Double; overload;
function Minkowski(const A, B: TPoint; const P: Double): Double; overload;
function MaxMinChebyshev(const A, B: TPoint): Double;
function Octile(const A, B: TPoint): Double;
function Distance(const A, B: TPoint; const distFunc: TDistanceFunction): Double; overload;
function Distance(const A, B: TPoint; const metric: TDistanceMetric = dmEuclidean): Double; overload;

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

function RandomB: Boolean; overload; 
function RandomBit: Byte; overload; 
function RandomSample(const x: Integer; const size: Integer): TIntegerArray; overload; 
function RandomMean(const x: Integer; const sample: Integer = 10): Integer; overload; 
function Random2(const x: Integer; const r: Integer = 2): Integer; overload; 
function RandomMax(const x: Integer; const r: Integer = 2): Integer; overload; 
function RandomMin(const x: Integer; const r: Integer = 2): Integer; overload; 

function XORSort(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload;
function XORSort(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload;

function iSort(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload;
function iSort(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload;

function Max(a, b: string): string; overload; inline;
function Max(a, b: Char): Char; overload; inline;
function Min(a, b: string): string; overload; inline;
function Min(a, b: Char): Char; overload; inline;

function Swap(var A, B: Integer): Boolean; overload; inline;
function Swap(var A, B: Int64): Boolean; overload; inline;
function Swap(var A, B: Double): Boolean; overload; inline;
function Swap(var A, B: string): Boolean; overload; inline;
function Swap(var A, B: Char): Boolean; overload; inline;
function Swap(var A, B: Boolean): Boolean; overload; inline;
function Swap(var A, B: TPoint): Boolean; overload; inline;
function Swap(var A, B: TBox): Boolean; overload; inline;
function Swap(var A, B: TRange): Boolean; overload; inline;
function Swap(var A, B: TSegment): Boolean; overload; inline;
function Swap(var A, B: TCircle): Boolean; overload; inline;
function Swap(var A, B: TTriangle): Boolean; overload; inline;

function Swop(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B: Int64; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B: Double; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B: string; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B: Char; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B: TPoint; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B, C: Int64; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B, C: Double; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B, C: string; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B, C: Char; const oAscending: Boolean = True): Boolean; overload;
function Swop(var A, B, C: TPoint; const oAscending: Boolean = True): Boolean; overload;

function Sort(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B: Int64; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B: Double; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B: string; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B: Char; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B: TPoint; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B, C: Int64; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B, C: Double; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B, C: string; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B, C: Char; const oAscending: Boolean = True): Boolean; overload;
function Sort(var A, B, C: TPoint; const oAscending: Boolean = True): Boolean; overload;

function IfThen(const state: Boolean; const sTrue, sFalse: Integer): Integer; overload; inline;
function IfThen(const state: Boolean; const sTrue, sFalse: Int64): Int64; overload; inline;
function IfThen(const state: Boolean; const sTrue, sFalse: Double): Double; overload; inline;
function IfThen(const state: Boolean; const sTrue, sFalse: string): string; overload; inline;
function IfThen(const state: Boolean; const sTrue, sFalse: Char): Char; overload; inline;
function IfThen(const state: Boolean; const sTrue, sFalse: Boolean): Boolean; overload; inline;
function IfThen(const state: Boolean; const sTrue, sFalse: TPoint): TPoint; overload; inline;
function IfThen(const state: Boolean; const sTrue, sFalse: TBox): TBox; overload; inline;
function IfThen(const state: Boolean; const sTrue, sFalse: TRange): TRange; overload; inline;
function IfThen(const state: Boolean; const sTrue, sFalse: TSegment): TSegment; overload; inline;
function IfThen(const state: Boolean; const sTrue, sFalse: TCircle): TCircle; overload; inline;
function IfThen(const state: Boolean; const sTrue, sFalse: TTriangle): TTriangle; overload; inline;

function Bitify(const a: Boolean): Integer; overload; inline;
function Bitify(const a, b: Boolean): Integer; overload;
function Bitify(const a, b, c: Boolean): Integer; overload;
function Bitify(const a, b, c, d: Boolean): Integer; overload;

type
{$DEFINE T1D}
  T1D = class
  public
  {$DEFINE Integer}{$I MiMU\config\Classes.inc}{$UNDEF Integer}
  {$DEFINE Double}{$I MiMU\config\Classes.inc}{$UNDEF Double}
  {$DEFINE string}{$I MiMU\config\Classes.inc}{$UNDEF string}
  {$DEFINE Char}{$I MiMU\config\Classes.inc}{$UNDEF Char}
  {$DEFINE TPoint}{$I MiMU\config\Classes.inc}{$UNDEF TPoint}
  {$DEFINE Boolean}{$I MiMU\config\Classes.inc}{$UNDEF Boolean}
  {$DEFINE TBox}{$I MiMU\config\Classes.inc}{$UNDEF TBox}
  {$DEFINE TRange}{$I MiMU\config\Classes.inc}{$UNDEF TRange}
  end;
{$UNDEF T1D}
{$DEFINE T2D}
  T2D = class
  public
  {$DEFINE Integer}{$I MiMU\config\Classes.inc}{$UNDEF Integer}
  {$DEFINE Double}{$I MiMU\config\Classes.inc}{$UNDEF Double}
  {$DEFINE string}{$I MiMU\config\Classes.inc}{$UNDEF string}
  {$DEFINE Char}{$I MiMU\config\Classes.inc}{$UNDEF Char}
  {$DEFINE TPoint}{$I MiMU\config\Classes.inc}{$UNDEF TPoint}
  {$DEFINE Boolean}{$I MiMU\config\Classes.inc}{$UNDEF Boolean}
  {$DEFINE TBox}{$I MiMU\config\Classes.inc}{$UNDEF TBox}
  {$DEFINE TRange}{$I MiMU\config\Classes.inc}{$UNDEF TRange}
  end;
{$UNDEF T2D}
 
implementation

{$DEFINE IMPLEMENT} 

function MiMU_Version: Double; 
begin
  Result := MiMU_VERSION_NUMBER;
end;

generic function Swap<T>(var A, B: T): Boolean; overload;
var
  C: T;
begin
  Result := (A <> B);
  C := A;
  A := B;
  B := C;
end;

generic function Swop<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
var
  C: T;
begin
  Result := ((oAscending and (A > B)) or ((not oAscending) and (B > A)));
  if not Result then
    Exit;
  C := A;
  A := B;
  B := C;
end;

generic function Swop<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((Integer(Swop(A, B, oAscending)) + Integer(Swop(A, C, oAscending)) + Integer(Swop(B, C, oAscending))) > 0);
end;

generic function Sort<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((oAscending and (A > B)) or ((not oAscending) and (A < B)));
  if Result then
    specialize Swap<T>(A, B);
end;

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

generic function Contains<T>(const arr: array of T; const item: T): Boolean;
var
  i: Integer;
begin
  for i := Low(arr) to High(arr) do
    if (arr[i] = item) then
      Exit(True);
  Result := False;
end;

generic function Includes<T>(const arr: array of T; const item: T): Boolean;
var
  i: Integer;
begin
  for i := High(arr) downto Low(arr) do
    if (arr[i] = item) then
      Exit(True);
  Result := False;
end;

generic function Position<T>(const arr: array of T; const item: T): Integer;
var
  i: Integer;
begin
  for i := Low(arr) to High(arr) do
    if (arr[i] = item) then
      Exit(i);
  Result := -1;
end;

generic function Location<T>(const arr: array of T; const item: T): Integer;
var
  i: Integer;
begin
  for i := High(arr) downto Low(arr) do
    if (arr[i] = item) then
      Exit(i);
  Result := -1;
end;

generic function Indexes<T>(const arr: array of T): TIntegerArray;
var
  i, l: Integer;
begin
  SetLength(Result, Length(arr));
  l := Low(arr);
  for i := l to High(arr) do
    Result[i - l] := i;
end;

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

generic function SetSize<T>(var A, B: specialize TArray<T>; const size: Integer = 1): Integer; overload;
begin
  Result := Max(0, size);
  SetLength(A, Result);
  SetLength(B, Result);
end;

generic function SetSize<T>(var A, B, C: specialize TArray<T>; const size: Integer = 1): Integer; overload;
begin
  Result := Max(0, size);
  SetLength(A, Result);
  SetLength(B, Result);
  SetLength(C, Result);
end;

generic function SetSize<T>(var A, B, C, D: specialize TArray<T>; const size: Integer = 1): Integer; overload;
begin
  Result := Max(0, size);
  SetLength(A, Result);
  SetLength(B, Result);
  SetLength(C, Result);
  SetLength(D, Result);
end;

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

function RandomB: Boolean; overload; 
begin
  Result := (Random(2) = 1);
end;

function RandomBit: Byte; overload; 
begin
  Result := Random(2);
end;

function RandomSample(const x: Integer; const size: Integer): TIntegerArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, size);
  for i := 0 to High(Result) do
    Result[i] := Random(x);
end;

function RandomMean(const x: Integer; const sample: Integer = 10): Integer; overload; 
begin
  Result := Round(RandomSample(x, sample).Mean);
end;

function Random2(const x: Integer; const r: Integer = 2): Integer; overload; 
var
  i: Integer;
begin
  for i := 1 to Random(r + 1) do
    Random(x);
  Result := Random(x);
end;

function RandomMax(const x: Integer; const r: Integer = 2): Integer; overload; 
var
  i: Integer;
begin
  Result := -2147483648;
  for i := 1 to r do
    Result := Max(Result, Random(x));
end;

function RandomMin(const x: Integer; const r: Integer = 2): Integer; overload; 
var
  i: Integer;
begin
  Result := 2147483647;
  for i := 1 to r do
    Result := Min(Result, Random(x));
end; 

function Swap(var A, B: Integer): Boolean; overload; inline; var C: Integer; {$DEFINE Skeleton_Swap}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Swap}
function Swap(var A, B: Int64): Boolean; overload; inline; var C: Int64; {$DEFINE Skeleton_Swap}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Swap}
function Swap(var A, B: Double): Boolean; overload; inline; var C: Double; {$DEFINE Skeleton_Swap}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Swap}
function Swap(var A, B: string): Boolean; overload; inline; var C: string; {$DEFINE Skeleton_Swap}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Swap}
function Swap(var A, B: Char): Boolean; overload; inline; var C: Char; {$DEFINE Skeleton_Swap}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Swap}
function Swap(var A, B: Boolean): Boolean; overload; inline; var C: Boolean; {$DEFINE Skeleton_Swap}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Swap}
function Swap(var A, B: TPoint): Boolean; overload; inline; var C: TPoint; {$DEFINE Skeleton_Swap}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Swap}
function Swap(var A, B: TBox): Boolean; overload; inline; var C: TBox; {$DEFINE Skeleton_Swap}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Swap}
function Swap(var A, B: TRange): Boolean; overload; inline; var C: TRange; {$DEFINE Skeleton_Swap}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Swap}
function Swap(var A, B: TSegment): Boolean; overload; inline; var C: TSegment; {$DEFINE Skeleton_Swap}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Swap}
function Swap(var A, B: TCircle): Boolean; overload; inline; var C: TCircle; {$DEFINE Skeleton_Swap}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Swap}
function Swap(var A, B: TTriangle): Boolean; overload; inline; var C: TTriangle; {$DEFINE Skeleton_Swap}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Swap}

function Swop(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<Integer>(A, B, oAscending); end;
function Swop(var A, B: Int64; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<Int64>(A, B, oAscending); end;
function Swop(var A, B: Double; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<Double>(A, B, oAscending); end;
function Swop(var A, B: string; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<string>(A, B, oAscending); end;
function Swop(var A, B: Char; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<Char>(A, B, oAscending); end;
function Swop(var A, B: TPoint; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<TPoint>(A, B, oAscending); end;
function Swop(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<Integer>(A, B, C, oAscending); end;
function Swop(var A, B, C: Int64; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<Int64>(A, B, C, oAscending); end;
function Swop(var A, B, C: Double; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<Double>(A, B, C, oAscending); end;
function Swop(var A, B, C: string; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<string>(A, B, C, oAscending); end;
function Swop(var A, B, C: Char; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<Char>(A, B, C, oAscending); end;
function Swop(var A, B, C: TPoint; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Swop<TPoint>(A, B, C, oAscending); end;

function Sort(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<Integer>(A, B, oAscending); end;
function Sort(var A, B: Int64; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<Int64>(A, B, oAscending); end;
function Sort(var A, B: Double; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<Double>(A, B, oAscending); end;
function Sort(var A, B: string; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<string>(A, B, oAscending); end;
function Sort(var A, B: Char; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<Char>(A, B, oAscending); end;
function Sort(var A, B: TPoint; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<TPoint>(A, B, oAscending); end;
function Sort(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<Integer>(A, B, C, oAscending); end;
function Sort(var A, B, C: Int64; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<Int64>(A, B, C, oAscending); end;
function Sort(var A, B, C: Double; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<Double>(A, B, C, oAscending); end;
function Sort(var A, B, C: string; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<string>(A, B, C, oAscending); end;
function Sort(var A, B, C: Char; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<Char>(A, B, C, oAscending); end;
function Sort(var A, B, C: TPoint; const oAscending: Boolean = True): Boolean; overload; begin Result := specialize Sort<TPoint>(A, B, C, oAscending); end;

function IfThen(const state: Boolean; const sTrue, sFalse: Integer): Integer; overload; inline; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: Int64): Int64; overload; inline; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: Double): Double; overload; inline; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: string): string; overload; inline; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: Char): Char; overload; inline; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: Boolean): Boolean; overload; inline; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: TPoint): TPoint; overload; inline; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: TBox): TBox; overload; inline; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: TRange): TRange; overload; inline; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: TSegment): TSegment; overload; inline; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: TCircle): TCircle; overload; inline; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: TTriangle): TTriangle; overload; inline; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}

function Bitify(const a: Boolean): Integer; overload; inline;
begin
  if a then
    Result := 1
  else
    Result := 0;
end;

function Bitify(const a, b: Boolean): Integer; overload;
begin
  Result := ((Bitify(a) shl 1) or Bitify(b));
end;

function Bitify(const a, b, c: Boolean): Integer; overload;
begin
  Result := ((Bitify(a) shl 2) or (Bitify(b) shl 1) or Bitify(c));
end;

function Bitify(const a, b, c, d: Boolean): Integer; overload;
begin
  Result := ((Bitify(a) shl 3) or (Bitify(b) shl 2) or (Bitify(c) shl 1) or Bitify(d));
end;

function XORSort(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := (oAscending and (A > B)) or ((not oAscending) and (A < B));
  if Result then
  begin
    A := (A xor B);
    B := (A xor B);
    A := (A xor B);
  end;
end;

function XORSort(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((Integer(XORSort(A, B)) + Integer(XORSort(A, C)) + Integer(XORSort(B, C))) > 0);
end;

function iSort(var A, B: Integer; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((oAscending and (A > B)) or ((not oAscending) and (A < B)));
  if Result then
  begin
    A := (A + B);
    B := (A - B);
    A := (A - B);
  end;
end;

function iSort(var A, B, C: Integer; const oAscending: Boolean = True): Boolean; overload;
begin
  Result := ((Integer(iSort(A, B, oAscending)) + Integer(iSort(A, C, oAscending)) + Integer(iSort(B, C, oAscending))) > 0);
end;

function Max(A, B: string): string; overload; inline; {$DEFINE Skeleton_Max}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Max}
function Max(A, B: Char): Char; overload; inline; {$DEFINE Skeleton_Max}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Max}

function Min(A, B: string): string; overload; inline; {$DEFINE Skeleton_Min}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Min}
function Min(A, B: Char): Char; overload; inline; {$DEFINE Skeleton_Min}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_Min}

function HypotEuclidean(const A, B: TPoint): Double;
begin
  Result := Hypot(A.X - B.X, A.Y - B.Y);
end;

function Euclidean(const A, B: TPoint): Double;
begin
  Result := (Sqrt(Sqr(A.X - B.X) + Sqr(A.Y - B.Y)));
end;

function Euclidean2(const A, B: TPoint): Double;
begin
  Result := Sqrt(Power((A.X - B.X), 2) + Power((A.Y - B.Y), 2));
end;

function SquaredEuclidean(const A, B: TPoint): Double;
begin
  Result := (Sqr(A.X - B.X) + Sqr(A.Y - B.Y));
end;

function Manhattan(const A, B: TPoint): Double;
begin
  Result := (Abs(A.X - B.X) + Abs(A.Y - B.Y));
end;

function Chebyshev(const A, B: TPoint): Double;
begin
  Result := Max(Abs(A.X - B.X), Abs(A.Y - B.Y));
end;

function Minkowski(const A, B: TPoint): Double; overload;
begin
  Result := Power(Power(Abs(A.X - B.X), 2.0) + Power(Abs(A.Y - B.Y), 2.0), (1 / 2.0));
end;

function Minkowski(const A, B: TPoint; const P: Double): Double; overload;
begin
  Result := Power(Power(Abs(A.X - B.X), P) + Power(Abs(A.Y - B.Y), P), (1 / P));
end;

function MaxMinChebyshev(const A, B: TPoint): Double;
begin
  Result := Max(Max(A.X, B.X) - Min(A.X, B.X), Max(A.Y, B.Y) - Min(A.Y, B.Y));
end;

function Octile(const A, B: TPoint): Double;
var
  h, v: Integer;
begin
  h := Abs(A.X - B.X);
  v := Abs(A.Y - B.Y);
  Result := (Max(h, v) + (Sqrt(2) - 1) * Min(h, v));
end;

function DistanceFunction(const distFunc: TDistanceFunction): TDistanceFunction; overload;
begin
  Result := distFunc;
  if not Assigned(Result) then
    Result := @Euclidean;
end;

function DistanceFunction(const method: Integer = 0): TDistanceFunction; overload;
begin
  if not InRange(method, 0, 8) then
    Exit(@Euclidean);
  case method of
    0: Result := @HypotEuclidean;
    1: Result := @Euclidean;
    2: Result := @Euclidean2;
    3: Result := @SquaredEuclidean;
    4: Result := @Manhattan;
    5: Result := @Chebyshev;
    6: Result := @Minkowski;
    7: Result := @MaxMinChebyshev;
    8: Result := @Octile;
  end;
end;

function DistanceFunction(const metric: TDistanceMetric): TDistanceFunction; overload;
begin
  case metric of
    dmHypotEuclidean: Result := @HypotEuclidean;
    dmEuclidean: Result := @Euclidean;
    dmEuclidean2: Result := @Euclidean2;
    dmSquaredEuclidean: Result := @SquaredEuclidean;
    dmManhattan: Result := @Manhattan;
    dmChebyshev: Result := @Chebyshev;
    dmMinkowski: Result := @Minkowski;
    dmMaxMinChebyshev: Result := @MaxMinChebyshev;
    dmOctile: Result := @Octile;
  else
    Result := @Euclidean;
  end;
end;

function Distance(const A, B: TPoint; const distFunc: TDistanceFunction): Double; overload;
begin
  Result := distFunc(A, B);
end;

function Distance(const A, B: TPoint; const metric: TDistanceMetric = dmEuclidean): Double; overload;
begin
  Result := Distance(A, B, DistanceFunction(metric));
end;

{$mode objfpc}{$H+}

{$I MiMU.inc}

initialization

finalization

end.
