                                    { MiMU is Massive Unit for Free Pascal )
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
 (v0.3}
 
 unit MiMU;

{$mode objfpc}{$H+}
{$macro on}
{$inline on}
{$modeswitch advancedrecords}
{$modeswitch arrayoperators}

interface

uses
  classes, sysutils, math;

type
  TIntegerArray = array of Integer;
  T2DIntegerArray = array of TIntegerArray;
  TDoubleArray = array of Double;
  T2DDoubleArray = array of TDoubleArray;
  TBooleanArray = array of Boolean;
  T2DBooleanArray = array of TBooleanArray;
  TCharArray = array of Char;
  T2DCharArray = array of TCharArray;
  TStringArray = array of string;
  T2DStringArray = array of TStringArray;
  TPoint = record
    X, Y: Integer;
  end;
  TPointArray = array of TPoint;
  T2DPointArray = array of TPointArray;
  TBox = record
    X1, Y1, X2, Y2: Integer;
  end;
  TBoxArray = array of TBox;
  T2DBoxArray = array of TBoxArray;
  TRange = record
    start, stop: Integer;
  end;
  TRangeArray = array of TRange;
  T2DRangeArray = array of TRangeArray;

operator+(const a, b: TPoint): TPoint;
operator+(const a, b: TBox): TBox;
operator+(const a, b: TRange): TRange;

operator-(const a, b: TPoint): TPoint;
operator-(const a, b: TBox): TBox;
operator-(const a, b: TRange): TRange;

operator=(const a, b: TPoint): Boolean;
operator=(const a, b: TBox): Boolean;
operator=(const a, b: TRange): Boolean;

operator<>(const a, b: TPoint): Boolean;
operator<>(const a, b: TBox): Boolean;
operator<>(const a, b: TRange): Boolean;

procedure Swap(var A, B: Integer); overload; inline;
procedure Swap(var A, B: Int64); overload; inline;
procedure Swap(var A, B: Double); overload; inline;
procedure Swap(var A, B: string); overload; inline;
procedure Swap(var A, B: Char); overload; inline;
procedure Swap(var A, B: Boolean); overload; inline;
procedure Swap(var A, B: TPoint); overload; inline;
procedure Swap(var A, B: TBox); overload; inline;
procedure Swap(var A, B: TRange); overload; inline;

function Integer_Even(const x: Integer): Boolean; cdecl; inline;
function Integer_Odd(const x: Integer): Boolean; cdecl; inline;
function Integer_Inc(var x: Integer; const N: Integer = 1): Integer; cdecl;
function Integer_Dec(var x: Integer; const N: Integer = 1): Integer; cdecl;
function Integer_Increase(var x: Integer; const N: Integer = 1): Integer; cdecl;
function Integer_Decrease(var x: Integer; const N: Integer = 1): Integer; cdecl;
function Integer_Increment(var x: Integer; const N: Integer = 1): Integer; cdecl;
function Integer_Decrement(var x: Integer; const N: Integer = 1): Integer; cdecl;
function Integer_Incr(var x: Integer; const N: Integer = 1): Integer; cdecl;
function Integer_Decr(var x: Integer; const N: Integer = 1): Integer; cdecl;
function Integer_DigitCount(const x: Integer): Integer; cdecl;
function Integer_Digitz(const x: Integer): TIntegerArray; cdecl;
function Integer_Digits(const x: Integer): TIntegerArray; cdecl;
function Integer_NegA(const x: Integer): Integer; cdecl; inline;
function Integer_Neg(const x: Integer): Integer; cdecl; inline;
function Integer_Negative(const x: Integer): Boolean; cdecl; inline;
function Integer_Positive(const x: Integer): Boolean; cdecl; inline;
function Integer_Neutral(const x: Integer): Boolean; cdecl; inline;
function Integer_Compare(const x, T: Integer): Integer; cdecl; inline;
function Integer_Distance(const x, T: Integer): Integer; cdecl; inline;
function Integer_Difference(const x, T: Integer): Integer; cdecl; inline;
function Integer_Opposite(const x: Integer): Integer; cdecl; inline;
function Integer_Sign(const x: Integer): Integer; cdecl; inline;
function Integer_Random(const range: Integer): Integer; cdecl;
function Integer_Oversize(const x, limit: Integer): Boolean; cdecl; inline;
function Integer_Undersize(const x, limit: Integer): Boolean; cdecl; inline;

function Int64_Even(const x: Int64): Boolean; cdecl; inline;
function Int64_Odd(const x: Int64): Boolean; cdecl; inline;
function Int64_Inc(var x: Int64; const N: Int64 = 1): Int64; cdecl;
function Int64_Dec(var x: Int64; const N: Int64 = 1): Int64; cdecl;
function Int64_Increase(var x: Int64; const N: Int64 = 1): Int64; cdecl;
function Int64_Decrease(var x: Int64; const N: Int64 = 1): Int64; cdecl;
function Int64_Increment(var x: Int64; const N: Int64 = 1): Int64; cdecl;
function Int64_Decrement(var x: Int64; const N: Int64 = 1): Int64; cdecl;
function Int64_Incr(var x: Int64; const N: Int64 = 1): Int64; cdecl;
function Int64_Decr(var x: Int64; const N: Int64 = 1): Int64; cdecl;
function Int64_DigitCount(const x: Int64): Integer; cdecl;
function Int64_Digitz(const x: Int64): TIntegerArray; cdecl;
function Int64_Digits(const x: Int64): TIntegerArray; cdecl;
function Int64_Compare(const x, T: Int64): Integer; cdecl; inline;
function Int64_Distance(const x, T: Int64): Int64; cdecl; inline;
function Int64_Difference(const x, T: Int64): Int64; cdecl; inline;
function Int64_Opposite(const x: Int64): Int64; cdecl; inline;
function Int64_Sign(const x: Int64): Integer; cdecl; inline;
function Int64_Random(const range: Int64): Int64; cdecl;
function Int64_Oversize(const x, limit: Int64): Boolean; cdecl; inline;
function Int64_Undersize(const x, limit: Int64): Boolean; cdecl; inline;

function Double_Inc(var x: Double; const N: Double = 1): Double; cdecl;
function Double_Dec(var x: Double; const N: Double = 1): Double; cdecl;
function Double_Increase(var x: Double; const N: Double = 1): Double; cdecl;
function Double_Decrease(var x: Double; const N: Double = 1): Double; cdecl;
function Double_Increment(var x: Double; const N: Double = 1): Double; cdecl;
function Double_Decrement(var x: Double; const N: Double = 1): Double; cdecl;
function Double_Incr(var x: Double; const N: Double = 1): Double; cdecl;
function Double_Decr(var x: Double; const N: Double = 1): Double; cdecl;
function Double_Digits(const x: Double): TIntegerArray; cdecl;
function Double_NegA(const x: Double): Double; cdecl; inline;
function Double_Neg(const x: Double): Double; cdecl; inline;
function Double_Negative(const x: Double): Boolean; cdecl; inline;
function Double_Positive(const x: Double): Boolean; cdecl; inline;
function Double_Neutral(const x: Double): Boolean; cdecl; inline;
function Double_MinDecimal(const x: Double): Double; cdecl;
function Double_MaxDecimal(const x: Double): Double; cdecl;
function Double_Copy(const x: Double; const a: Integer): Double; cdecl;
function Double_Compare(const x, T: Double): Integer; cdecl; inline;
function Double_Distance(const x, T: Double): Double; cdecl; inline;
function Double_Difference(const x, T: Double): Double; cdecl; inline;
function Double_Opposite(const x: Double): Double; cdecl; inline;
function Double_Sign(const x: Double): Integer; cdecl; inline;
function Double_FixDegrees(const dgrs: Double): Double; cdecl;
function Double_Degrees(const rdns: Double): Double; cdecl;
function Double_FixRadians(const rdns: Double): Double; cdecl;
function Double_Radians(const dgrs: Double; const compass: Boolean = False): Double; cdecl;
function Double_Percent(const source, position: Double): Double; cdecl; inline;
function Double_Percentage(const source, percent: Double): Double; cdecl; inline;
function Double_Oversize(const x, limit: Double): Boolean; cdecl;
function Double_Undersize(const x, limit: Double): Boolean; cdecl;

function String_Chars(const str: string): TCharArray; cdecl;
function String_At(const str, s: string; const index: Integer = 1): Boolean; cdecl; inline;
function String_Get(const str: string; const index, count: Integer): string; cdecl; inline;
function String_Pick(const str: string; const index: Integer; const count: Integer = 2147483647): string; cdecl;
function String_PosL(const str, s: string; const index: Integer = 1): Integer; cdecl;
function String_PosR(const str, s: string; const index: Integer = 2147483647): Integer; cdecl;
function String_Pos(const str, s: string; const index: Integer = 1): Integer; cdecl;
function String_PosLast(const str, s: string; const index: Integer = 2147483647): Integer; cdecl;
function String_Position(const str, s: string; const index: Integer = 1): Integer; cdecl;
function String_Contains(const str, s: string; const index: Integer = 1): Boolean; cdecl;
function String_Includes(const str, s: string; const index: Integer = 2147483647): Boolean; cdecl;
function String_Between(const str, s1, s2: string; const index: Integer = 1): string; cdecl;
function String_Count(const str, s: string; const overlap: Boolean = True; const index: Integer = 1): Integer; cdecl;
function String_Amount(const str, s: string; const overlap: Boolean = True; const index: Integer = 2147483647): Integer; cdecl;
function String_FromLeft(const str: string; const count: Integer; const index: Integer = 1): string; cdecl;
function String_FromRight(const str: string; const count: Integer; const index: Integer = 2147483647): string; cdecl;
function String_Explode(const str, d: string; const limit: Integer = -1): TStringArray; overload; cdecl;
function String_Explode(const str: string; const d: TStringArray; const limit: Integer = -1): TStringArray; overload; cdecl;
function String_Slice(const str: string; const a, b: Integer): string; cdecl;
function String_Chunk(const str: string; const a, b: Integer): string; cdecl;
function String_Reverse(var str: string): Boolean; cdecl;
function String_Flip(const str: string): string; cdecl;
function String_Reversed(const str: string): string; cdecl;
function String_StartsWith(const str, s: string): Boolean; cdecl;
function String_EndsWith(const str, s: string): Boolean; cdecl;
function String_Begin(var str: string; const s: string; const index: Integer = 1): Boolean; cdecl;
function String_End(var str: string; const s: string; const index: Integer = 2147483647): Boolean; cdecl;
function String_Behind(const str: string; const index, count: Integer): string; cdecl;
function String_Ahead(const str: string; const index, count: Integer): string; cdecl;
function String_After(const str, s: string; const index: Integer = 1): string; cdecl;
function String_Before(const str, s: string; const index: Integer = 1): string; cdecl;
function String_AfterLast(const str, s: string; const index: Integer = 2147483647): string; cdecl;
function String_BeforeLast(const str, s: string; const index: Integer = 2147483647): string; cdecl;
function String_Center(const str: string; const size: Integer; const fill: Char = #32): string; cdecl;
function String_Stuff(const str, s: string; const iFrom, iCount: Integer): string; cdecl;
function String_Duplicate(const str: string; const x: Integer = 2): string; cdecl;
function String_Duplicated(const str: string; const x: Integer; const glue: string): string; cdecl;
function String_Compare(const str, T: string): Integer; cdecl; inline;
function String_Quotatation(const str: string): string; cdecl;
function String_PregQuote(const str: string; const regex: string = '.\+*?[^]$(){}=!<>|:-'): string; cdecl;
function String_TrimLeft(const str: string; const t: Char = #32): string; cdecl;
function String_TrimRight(const str: string; const t: Char = #32): string; cdecl;
function String_Trim(const str: string; const t: Char = #32): string; cdecl;
function String_TRange(const str: string): TRange; cdecl;
function String_IDs(const str: string): TIntegerArray; overload; cdecl;
function String_IDs(const str: string; const IDs: TIntegerArray): TCharArray; overload; cdecl;
function String_IDs(const str: string; const IDs: TIntegerArray; const item: Char): TCharArray; overload; cdecl;
function String_IDs(const str: string; const IDs: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl;

function Boolean_Random: Boolean; cdecl; inline;
function Boolean_X(const X: Boolean; const trueX, falseX: Boolean): Boolean; overload; cdecl;
function Boolean_X(const X: Boolean; const trueX, falseX: Integer): Integer; overload; cdecl;
function Boolean_X(const X: Boolean; const trueX, falseX: Int64): Int64; overload; cdecl;
function Boolean_X(const X: Boolean; const trueX, falseX: Double): Double; overload; cdecl;
function Boolean_X(const X: Boolean; const trueX, falseX: string): string; overload; cdecl;
function Boolean_X(const X: Boolean; const trueX, falseX: Char): Char; overload; cdecl;
function Boolean_X(const X: Boolean; const trueX, falseX: TPoint): TPoint; overload; cdecl;
function Boolean_X(const X: Boolean; const trueX, falseX: TBox): TBox; overload; cdecl;
function Boolean_X(const X: Boolean; const trueX, falseX: TRange): TRange; overload; cdecl;

function TPoint_To(const X, Y: Integer): TPoint; cdecl; inline;
function TPoint_At(const X, Y: Integer): TPoint; cdecl; inline;
function TPoint_InBox(const pt: TPoint; const bx: TBox): Boolean; cdecl; inline;
function TPoint_InCircle(const pt, center: TPoint; const radius: Double): Boolean; cdecl; inline;
function TPoint_InEllipse(const pt, center: TPoint; const XRadius, YRadius: Double): Boolean; cdecl; inline;
function TPoint_AngleDegrees(const source, target: TPoint; const compass: Boolean = False): Double; cdecl;
function TPoint_AngleRadians(const source, target: TPoint): Double; cdecl;
function TPoint_DistEuclidean(const source, target: TPoint): Double; cdecl;
function TPoint_DistEuclidean2(const source, target: TPoint): Double; cdecl;
function TPoint_DistSquaredEuclidean(const source, target: TPoint): Double; cdecl;
function TPoint_DistManhattan(const source, target: TPoint): Double; cdecl;
function TPoint_DistChebyshev(const source, target: TPoint): Double; cdecl;
function TPoint_Grid(const pt: TPoint; const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TPointArray; cdecl;
function TPoint_Row(const pt: TPoint; const cells: Integer; const space: Integer = 0): TPointArray; cdecl;
function TPoint_Column(const pt: TPoint; const cells: Integer; const space: Integer = 0): TPointArray; cdecl;

function TBox_Build(const X1, Y1, X2, Y2: Integer): TBox; overload; cdecl;
function TBox_Build(const a, b: TPoint): TBox; overload; cdecl;
function TBox_Create(const X1, Y1, X2, Y2: Integer): TBox; overload; cdecl;
function TBox_Create(const a, b: TPoint): TBox; overload; cdecl;
function TBox_Form(const XY: Integer = 0): TBox; overload; cdecl;
function TBox_Form(const XY: TPoint): TBox; overload; cdecl;
function TBox_At(const pt: TPoint; const radius: Integer = 0): TBox; overload; cdecl;
function TBox_At(const pt: TPoint; const wRadius, hRadius: Integer): TBox; overload; cdecl;
function TBox_To(const pt: TPoint; const size: Integer = 1): TBox; overload; cdecl;
function TBox_To(const pt: TPoint; const width, height: Integer): TBox; overload; cdecl;
function TBox_Size(const bx: TBox; var width, height: Integer): Integer; cdecl; inline;
function TBox_Area(const bx: TBox): Integer; cdecl; inline;
function TBox_Diagonal(const bx: TBox): Double; cdecl;
function TBox_W(const bx: TBox): Integer; overload; cdecl;
function TBox_W(var bx: TBox; const width: Integer): Integer; overload; cdecl;
function TBox_Width(const bx: TBox): Integer; overload; cdecl;
function TBox_Width(var bx: TBox; const width: Integer): Integer; overload; cdecl;
function TBox_H(const bx: TBox): Integer; overload; cdecl;
function TBox_H(var bx: TBox; const height: Integer): Integer; overload; cdecl;
function TBox_Height(const bx: TBox): Integer; overload; cdecl;
function TBox_Height(var bx: TBox; const height: Integer): Integer; overload; cdecl;
function TBox_Expand(const bx: TBox; const change: Integer = 1): TBox; cdecl;
function TBox_Shrink(const bx: TBox; const change: Integer = 1): TBox; cdecl;
function TBox_Resize(const bx: TBox; const change: Integer): TBox; cdecl;
function TBox_ResizeVertically(const bx: TBox; const change: Integer): TBox; cdecl;
function TBox_ResizeHorizontally(const bx: TBox; const change: Integer): TBox; cdecl;
function TBox_ResizeTop(const bx: TBox; const change: Integer): TBox; cdecl;
function TBox_ResizeBottom(const bx: TBox; const change: Integer): TBox; cdecl;
function TBox_ResizeLeft(const bx: TBox; const change: Integer): TBox; cdecl;
function TBox_ResizeRight(const bx: TBox; const change: Integer): TBox; cdecl;
function TBox_ResizeTopLeft(const bx: TBox; const change: Integer): TBox; cdecl;
function TBox_ResizeTopRight(const bx: TBox; const change: Integer): TBox; cdecl;
function TBox_ResizeBottomRight(const bx: TBox; const change: Integer): TBox; cdecl;
function TBox_ResizeBottomLeft(const bx: TBox; const change: Integer): TBox; cdecl;
function TBox_Equal(const a, b: TBox): Boolean; cdecl; inline;
function TBox_Contains(const bx: TBox; const pt: TPoint): Boolean; overload; cdecl;
function TBox_Contains(const bx, x: TBox): Boolean; overload; cdecl;
function TBox_In(const bx, area: TBox): Boolean; overload; cdecl;
function TBox_In(const bx: TBox; const areas: TBoxArray): Boolean; overload; cdecl;
function TBox_Inside(const bx, area: TBox): Boolean; overload; cdecl;
function TBox_Inside(const bx: TBox; const areas: TBoxArray): Boolean; overload; cdecl;
function TBox_Center(const bx: TBox): TPoint; cdecl;
function TBox_Envelope(const a, b: TBox): TBox; cdecl;
function TBox_Overlap(const a, b: TBox): Boolean; cdecl; inline;
function TBox_Intersection(const a, b: TBox): TBox; cdecl;
function TBox_Intersect(const a, b: TBox; var intersection: TBox): Boolean; cdecl;
function TBox_Union(const a, b: TBox): TBox; cdecl;
function TBox_Valid(const bx: TBox): Boolean; cdecl; inline;
function TBox_Invalid(const bx: TBox): Boolean; cdecl;
function TBox_Similar(const a, b: TBox; const maxWDiff, maxHDiff: Integer): Boolean; overload; cdecl;
function TBox_Similar(const a, b: TBox; const diff: Integer): Boolean; overload; cdecl;
function TBox_Fix(var bx: TBox): Boolean; cdecl;
function TBox_Constraint(var bx: TBox; const area: TBox): Boolean; cdecl;
function TBox_Clip(const bx: TBox; const area: TBox): TBox; cdecl;
function TBox_Restrict(var bx: TBox; const area: TBox): Boolean; cdecl;
function TBox_Clamp(const bx, area: TBox): TBox; cdecl;
function TBox_Points(const bx: TBox): TPointArray; cdecl;
function TBox_TPointArray(const bx: TBox): TPointArray; cdecl;
function TBox_Grid(const bx: TBox; const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TBoxArray; cdecl;
function TBox_Row(const bx: TBox; const cells: Integer; const space: Integer = 0): TBoxArray; cdecl;
function TBox_Column(const bx: TBox; const cells: Integer; const space: Integer = 0): TBoxArray; cdecl;
function TBox_CornerPoints(const bx: TBox): TPointArray; cdecl;
function TBox_Corners(const bx: TBox): TPointArray; cdecl;
function TBox_SimilarSize(const a, b: TBox; const widthDifferency, heightDifferency: Integer): Boolean; overload; cdecl;
function TBox_SimilarSize(const a, b: TBox; const differency: Integer): Boolean; overload; cdecl;
function TBox_Centered(const bx, area: TBox): TBox; cdecl;
function TBox_CenterVertically(const bx, area: TBox): TBox; cdecl;
function TBox_CenterHorizontally(const bx, area: TBox): TBox; cdecl;

function TRange_Neutral(const range: TRange): Boolean; cdecl;
function TRange_Ascending(const range: TRange): Boolean; cdecl;
function TRange_Descending(const range: TRange): Boolean; cdecl;
function TRange_Create(const start: Integer = 0; const stop: Integer = 0): TRange; cdecl;
function TRange_Build(const start: Integer = 0; const stop: Integer = 0): TRange; cdecl;
function TRange_Grab(const range: TRange): TRange; cdecl;
function TRange_Size(const range: TRange): Integer; cdecl;
function TRange_Length(const range: TRange): Integer; cdecl;
function TRange_Min(const range: TRange): Integer; cdecl;
function TRange_Minimum(const range: TRange): Integer; cdecl;
function TRange_Max(const range: TRange): Integer; cdecl;
function TRange_Maximum(const range: TRange): Integer; cdecl;
function TRange_Digits(const range: TRange): TIntegerArray; cdecl;
function TRange_Ints(const range: TRange): TIntegerArray; cdecl;
function TRange_Values(const range: TRange): TIntegerArray; cdecl;
function TRange_TIntegerArray(const range: TRange): TIntegerArray; cdecl;
function TRange_Normalize(const range: TRange): TRange; cdecl;
function TRange_Overlapping(const a, b: TRange): Boolean; cdecl;
function TRange_Overlap(const a, b: TRange): Boolean; cdecl;
function TRange_Intersection(const a, b: TRange; const null: TRange): TRange; cdecl;
function TRange_Intersect(const a, b: TRange; var intersection: TRange): Boolean; cdecl;
function TRange_Union(const a, b: TRange): TRange; cdecl;
function TRange_Shift(const range: TRange; const delta: Integer): TRange; cdecl;
function TRange_Contains(const range: TRange; const x: Integer): Boolean; overload; cdecl;
function TRange_Contains(const range, x: TRange): Boolean; overload; cdecl;
function TRange_Reversed(const range: TRange): TRange; cdecl;
function TRange_Reverse(var range: TRange): Boolean; cdecl;
function TRange_Equals(const a, b: TRange): Boolean; cdecl;
function TRange_Differs(const a, b: TRange): Boolean; cdecl;
function TRange_Equal(const a, b: TRange): Boolean; cdecl;
function TRange_Differ(const a, b: TRange): Boolean; cdecl;
function TRange_Clamp(const range, zone: TRange): TRange; cdecl;
function TRange_ClampMax(const range: TRange; const maximum: Integer): TRange; cdecl;
function TRange_ClampMin(const range: TRange; const minimum: Integer): TRange; cdecl;
function TRange_Restrict(var range: TRange; const zone: TRange): Boolean; cdecl;
function TRange_RestrictMin(var range: TRange; const minimum: Integer): Boolean; cdecl;
function TRange_RestrictMax(var range: TRange; const maximum: Integer): Boolean; cdecl;
function TRange_Clip(const range, zone: TRange): TRange;
function TRange_ClipMin(const range: TRange; minimum: Integer): TRange;
function TRange_ClipMax(const range: TRange; maximum: Integer): TRange;
function TRange_Distribute(const range: TRange; const parts: Integer): TRangeArray; cdecl;
function TRange_Partition(const range: TRange; const size: Integer): TRangeArray; cdecl;
function TRange_Divide(const range: TRange; const size: Integer): TRangeArray; cdecl;
function TRange_Touch(const a, b: TRange): Boolean; cdecl;
function TRange_Touches(const a, b: TRange): Boolean; cdecl;
function TRange_Distance(const a, b: TRange): Integer; cdecl;
function TRange_DistHausdorff(const a, b: TRange): Integer; cdecl;
function TRange_Digit(const range: TRange; const x: Integer): Boolean; cdecl; inline;
function TRange_Value(const range: TRange; const x: Integer): Boolean; cdecl; inline;
function TRange_Middle(const range: TRange): Double; cdecl;
function TRange_Center(const range: TRange): Integer; cdecl;

function TIntegerArray_Descending(const arr: TIntegerArray): Boolean; cdecl;
function TIntegerArray_Ascending(const arr: TIntegerArray): Boolean; cdecl;
function TIntegerArray_Bounds(const arr: TIntegerArray): TRange; cdecl;
function TIntegerArray_TRange(const arr: TIntegerArray): TRange; cdecl;
function TIntegerArray_Unique(var arr: TIntegerArray): Integer; cdecl;
function TIntegerArray_Uniqued(const arr: TIntegerArray): TIntegerArray; cdecl;
function TIntegerArray_Numberline(const arr: TIntegerArray): TIntegerArray; cdecl;
function TIntegerArray_Min(const arr: TIntegerArray): Integer; cdecl;
function TIntegerArray_Max(const arr: TIntegerArray): Integer; cdecl;
function TIntegerArray_Mini(const arr: TIntegerArray; const ascending: Boolean = True; const start: Integer = -1): Integer; overload; cdecl;
function TIntegerArray_Mini(const arr: TIntegerArray; const start: Integer; const ascending: Boolean = True): Integer; overload; cdecl;
function TIntegerArray_Maxi(const arr: TIntegerArray; const ascending: Boolean = True; const start: Integer = -1): Integer; overload; cdecl;
function TIntegerArray_Maxi(const arr: TIntegerArray; const start: Integer; const ascending: Boolean = True): Integer; overload; cdecl;
function TIntegerArray_Sum(const arr: TIntegerArray): Int64; cdecl;
function TIntegerArray_Density(const arr: TIntegerArray): Double; cdecl;
function TIntegerArray_Mean(const arr: TIntegerArray): Double; cdecl;
function TIntegerArray_Mode(const arr: TIntegerArray): Integer; cdecl;
function TIntegerArray_Median(const arr: TIntegerArray): Double; cdecl;
function TIntegerArray_Middle(const arr: TIntegerArray): Double; cdecl;
function TIntegerArray_Center(const arr: TIntegerArray): Integer; cdecl;
function TIntegerArray_MostFrequent(const arr: TIntegerArray; const null: Integer = -2147483648): Integer; cdecl;
function TIntegerArray_LeastFrequent(const arr: TIntegerArray; const null: Integer = -2147483648): Integer; cdecl;
function TIntegerArray_BubbleSort(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_BubbleSort2(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_BubbleSortOptimized(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_QuickSort(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_QuickSort3W(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_QSort(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_CoctailSort(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_CoctailSort2(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_CombSort(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_GnomeSort(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_GnomeSortOptimized(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_HeapSort(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_InsertionSort(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_SelectionSort(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_SelectionSortBidirectional(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_SelectionSortBidirectional2(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_PancakeSort(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_MergeSort(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_MergeSortBU(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_ShellSort(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_BSort(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_BinarySort(var arr: TIntegerArray; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_BinarySorted(const arr: TIntegerArray; const ascending: Boolean = True): TIntegerArray; cdecl;
function TIntegerArray_BinaryBoundL(const arr: TIntegerArray; const x: Integer; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_BinaryBoundR(const arr: TIntegerArray; const x: Integer; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_BinaryPosL(const arr: TIntegerArray; const x: Integer; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_BinaryPosR(const arr: TIntegerArray; const x: Integer; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_BinaryLocate(const arr: TIntegerArray; const x: Integer; const ascending: Boolean = True): TRange; cdecl;
function TIntegerArray_BinarySearch(const arr: TIntegerArray; const x: Integer; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_BinaryContains(const arr: TIntegerArray; const x: Integer; const ascending: Boolean = True): Boolean; cdecl;
function TIntegerArray_BinaryLocation(const arr: TIntegerArray; const x: Integer; const ascending: Boolean = True): TRange; cdecl;
function TIntegerArray_BinaryAppend(var arr: TIntegerArray; const x: Integer; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_BinaryAdd(const arr: TIntegerArray; const x: Integer; const ascending: Boolean = True): TIntegerArray; cdecl;
function TIntegerArray_BinarySearchF(const arr: TIntegerArray; const x: TRange; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_BinarySearchL(const arr: TIntegerArray; const x: TRange; const ascending: Boolean = True): Integer; cdecl;
function TIntegerArray_Split(const arr: TIntegerArray; const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
function TIntegerArray_Split(const arr: TIntegerArray; const diff: Integer): T2DIntegerArray; overload; cdecl;
function TIntegerArray_Sblit(const arr: TIntegerArray; const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
function TIntegerArray_Sblit(const arr: TIntegerArray; const diff: Integer): T2DIntegerArray; overload; cdecl;
function TIntegerArray_Group(const arr: TIntegerArray; const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
function TIntegerArray_Group(const arr: TIntegerArray; const diff: Integer): T2DIntegerArray; overload; cdecl;
function TIntegerArray_Groub(const arr: TIntegerArray; const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
function TIntegerArray_Groub(const arr: TIntegerArray; const diff: Integer): T2DIntegerArray; overload; cdecl;
function TIntegerArray_Invert(const arr: TIntegerArray): TIntegerArray; cdecl;

function TPointArray_Bounds(const arr: TPointArray): TBox; cdecl;
function TPointArray_Unique(var arr: TPointArray): Integer; cdecl;
function TPointArray_Uniqued(const arr: TPointArray): TPointArray; cdecl;
function TPointArray_Invert(const arr: TPointArray): TPointArray; cdecl;
function TPointArray_Edge(const arr: TPointArray; const scan8W: Boolean = False): TPointArray; cdecl;
function TPointArray_FloodFill(const arr: TPointArray; const start: TPoint; const area: TBox; const scan8W: Boolean = False): TPointArray; overload; cdecl;
function TPointArray_FloodFill(const arr: TPointArray; const start: TPoint; const scan8W: Boolean = False): TPointArray; overload; cdecl;

function TRangeArray_TIntegerArray(const arr: TRangeArray): TIntegerArray; cdecl;
function TRangeArray_T2DIntegerArray(const arr: TRangeArray): T2DIntegerArray; cdecl;

function TArray_Add(const arr: TIntegerArray; const item: Integer): TIntegerArray; overload; cdecl;
function TArray_Add(const arr: TDoubleArray; const item: Double): TDoubleArray; overload; cdecl;
function TArray_Add(const arr: TStringArray; const item: string): TStringArray; overload; cdecl;
function TArray_Add(const arr: TCharArray; const item: Char): TCharArray; overload; cdecl;
function TArray_Add(const arr: TBooleanArray; const item: Boolean): TBooleanArray; overload; cdecl;
function TArray_Add(const arr: TPointArray; const item: TPoint): TPointArray; overload; cdecl;
function TArray_Add(const arr: TBoxArray; const item: TBox): TBoxArray; overload; cdecl;
function TArray_Add(const arr: TRangeArray; const item: TRange): TRangeArray; overload; cdecl;
function TArray_Add(const arr: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Add(const arr: TDoubleArray; const items: TDoubleArray): TDoubleArray; overload; cdecl;
function TArray_Add(const arr: TStringArray; const items: TStringArray): TStringArray; overload; cdecl;
function TArray_Add(const arr: TCharArray; const items: TCharArray): TCharArray; overload; cdecl;
function TArray_Add(const arr: TBooleanArray; const items: TBooleanArray): TBooleanArray; overload; cdecl;
function TArray_Add(const arr: TPointArray; const items: TPointArray): TPointArray; overload; cdecl;
function TArray_Add(const arr: TBoxArray; const items: TBoxArray): TBoxArray; overload; cdecl;
function TArray_Add(const arr: TRangeArray; const items: TRangeArray): TRangeArray; overload; cdecl;

function TArray_AllEqual(const arr: TIntegerArray): Boolean; overload; cdecl;
function TArray_AllEqual(const arr: TDoubleArray): Boolean; overload; cdecl;
function TArray_AllEqual(const arr: TStringArray): Boolean; overload; cdecl;
function TArray_AllEqual(const arr: TCharArray): Boolean; overload; cdecl;
function TArray_AllEqual(const arr: TBooleanArray): Boolean; overload; cdecl;
function TArray_AllEqual(const arr: TPointArray): Boolean; overload; cdecl;
function TArray_AllEqual(const arr: TBoxArray): Boolean; overload; cdecl;
function TArray_AllEqual(const arr: TRangeArray): Boolean; overload; cdecl;

function TArray_AllSame(const arr: TIntegerArray): Boolean; overload; cdecl;
function TArray_AllSame(const arr: TDoubleArray): Boolean; overload; cdecl;
function TArray_AllSame(const arr: TStringArray): Boolean; overload; cdecl;
function TArray_AllSame(const arr: TCharArray): Boolean; overload; cdecl;
function TArray_AllSame(const arr: TBooleanArray): Boolean; overload; cdecl;
function TArray_AllSame(const arr: TPointArray): Boolean; overload; cdecl;
function TArray_AllSame(const arr: TBoxArray): Boolean; overload; cdecl;
function TArray_AllSame(const arr: TRangeArray): Boolean; overload; cdecl;

function TArray_AllUnique(const arr: TIntegerArray): Boolean; overload; cdecl;
function TArray_AllUnique(const arr: TDoubleArray): Boolean; overload; cdecl;
function TArray_AllUnique(const arr: TStringArray): Boolean; overload; cdecl;
function TArray_AllUnique(const arr: TCharArray): Boolean; overload; cdecl;
function TArray_AllUnique(const arr: TBooleanArray): Boolean; overload; cdecl;
function TArray_AllUnique(const arr: TPointArray): Boolean; overload; cdecl;
function TArray_AllUnique(const arr: TBoxArray): Boolean; overload; cdecl;
function TArray_AllUnique(const arr: TRangeArray): Boolean; overload; cdecl;

function TArray_Append(var arr: TIntegerArray; const item: Integer): Integer; overload; cdecl;
function TArray_Append(var arr: TDoubleArray; const item: Double): Integer; overload; cdecl;
function TArray_Append(var arr: TStringArray; const item: string): Integer; overload; cdecl;
function TArray_Append(var arr: TCharArray; const item: Char): Integer; overload; cdecl;
function TArray_Append(var arr: TBooleanArray; const item: Boolean): Integer; overload; cdecl;
function TArray_Append(var arr: TPointArray; const item: TPoint): Integer; overload; cdecl;
function TArray_Append(var arr: TBoxArray; const item: TBox): Integer; overload; cdecl;
function TArray_Append(var arr: TRangeArray; const item: TRange): Integer; overload; cdecl;
function TArray_Append(var arr: TIntegerArray; const items: TIntegerArray): Integer; overload; cdecl;
function TArray_Append(var arr: TDoubleArray; const items: TDoubleArray): Integer; overload; cdecl;
function TArray_Append(var arr: TStringArray; const items: TStringArray): Integer; overload; cdecl;
function TArray_Append(var arr: TCharArray; const items: TCharArray): Integer; overload; cdecl;
function TArray_Append(var arr: TBooleanArray; const items: TBooleanArray): Integer; overload; cdecl;
function TArray_Append(var arr: TPointArray; const items: TPointArray): Integer; overload; cdecl;
function TArray_Append(var arr: TBoxArray; const items: TBoxArray): Integer; overload; cdecl;
function TArray_Append(var arr: TRangeArray; const items: TRangeArray): Integer; overload; cdecl;

function TArray_Build(const item: Integer; const size: Integer = 1): TIntegerArray; overload; cdecl;
function TArray_Build(const item: Double; const size: Integer = 1): TDoubleArray; overload; cdecl;
function TArray_Build(const item: string; const size: Integer = 1): TStringArray; overload; cdecl;
function TArray_Build(const item: Char; const size: Integer = 1): TCharArray; overload; cdecl;
function TArray_Build(const item: Boolean; const size: Integer = 1): TBooleanArray; overload; cdecl;
function TArray_Build(const item: TPoint; const size: Integer = 1): TPointArray; overload; cdecl;
function TArray_Build(const item: TBox; const size: Integer = 1): TBoxArray; overload; cdecl;
function TArray_Build(const item: TRange; const size: Integer = 1): TRangeArray; overload; cdecl;

function TArray_BuiltWith(const arr, allowed: TIntegerArray): Boolean; overload; cdecl;
function TArray_BuiltWith(const arr, allowed: TDoubleArray): Boolean; overload; cdecl;
function TArray_BuiltWith(const arr, allowed: TStringArray): Boolean; overload; cdecl;
function TArray_BuiltWith(const arr, allowed: TCharArray): Boolean; overload; cdecl;
function TArray_BuiltWith(const arr, allowed: TBooleanArray): Boolean; overload; cdecl;
function TArray_BuiltWith(const arr, allowed: TPointArray): Boolean; overload; cdecl;
function TArray_BuiltWith(const arr, allowed: TBoxArray): Boolean; overload; cdecl;
function TArray_BuiltWith(const arr, allowed: TRangeArray): Boolean; overload; cdecl;

function TArray_BuiltWithout(const arr, forbidden: TIntegerArray): Boolean; overload; cdecl;
function TArray_BuiltWithout(const arr, forbidden: TDoubleArray): Boolean; overload; cdecl;
function TArray_BuiltWithout(const arr, forbidden: TStringArray): Boolean; overload; cdecl;
function TArray_BuiltWithout(const arr, forbidden: TCharArray): Boolean; overload; cdecl;
function TArray_BuiltWithout(const arr, forbidden: TBooleanArray): Boolean; overload; cdecl;
function TArray_BuiltWithout(const arr, forbidden: TPointArray): Boolean; overload; cdecl;
function TArray_BuiltWithout(const arr, forbidden: TBoxArray): Boolean; overload; cdecl;
function TArray_BuiltWithout(const arr, forbidden: TRangeArray): Boolean; overload; cdecl;

function TArray_Clone(const arr: TIntegerArray; const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Clone(const arr: TDoubleArray; const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl;
function TArray_Clone(const arr: TStringArray; const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl;
function TArray_Clone(const arr: TCharArray; const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl;
function TArray_Clone(const arr: TBooleanArray; const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl;
function TArray_Clone(const arr: TPointArray; const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl;
function TArray_Clone(const arr: TBoxArray; const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl;
function TArray_Clone(const arr: TRangeArray; const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl;

function TArray_Combine(const a, b: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Combine(const a, b: TDoubleArray): TDoubleArray; overload; cdecl;
function TArray_Combine(const a, b: TStringArray): TStringArray; overload; cdecl;
function TArray_Combine(const a, b: TCharArray): TCharArray; overload; cdecl;
function TArray_Combine(const a, b: TBooleanArray): TBooleanArray; overload; cdecl;
function TArray_Combine(const a, b: TPointArray): TPointArray; overload; cdecl;
function TArray_Combine(const a, b: TBoxArray): TBoxArray; overload; cdecl;
function TArray_Combine(const a, b: TRangeArray): TRangeArray; overload; cdecl;

function TArray_Contains(const arr: TIntegerArray; const item: Integer; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Contains(const arr: TDoubleArray; const item: Double; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Contains(const arr: TStringArray; const item: string; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Contains(const arr: TCharArray; const item: Char; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Contains(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Contains(const arr: TPointArray; const item: TPoint; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Contains(const arr: TBoxArray; const item: TBox; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Contains(const arr: TRangeArray; const item: TRange; const index: Integer = 0): Boolean; overload; cdecl;

function TArray_Copy(const arr: TIntegerArray; const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Copy(const arr: TDoubleArray; const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl;
function TArray_Copy(const arr: TStringArray; const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl;
function TArray_Copy(const arr: TCharArray; const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl;
function TArray_Copy(const arr: TBooleanArray; const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl;
function TArray_Copy(const arr: TPointArray; const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl;
function TArray_Copy(const arr: TBoxArray; const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl;
function TArray_Copy(const arr: TRangeArray; const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl;
function TArray_Copy(const arr: TIntegerArray; const IDs: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Copy(const arr: TDoubleArray; const IDs: TIntegerArray): TDoubleArray; overload; cdecl;
function TArray_Copy(const arr: TStringArray; const IDs: TIntegerArray): TStringArray; overload; cdecl;
function TArray_Copy(const arr: TCharArray; const IDs: TIntegerArray): TCharArray; overload; cdecl;
function TArray_Copy(const arr: TBooleanArray; const IDs: TIntegerArray): TBooleanArray; overload; cdecl;
function TArray_Copy(const arr: TPointArray; const IDs: TIntegerArray): TPointArray; overload; cdecl;
function TArray_Copy(const arr: TBoxArray; const IDs: TIntegerArray): TBoxArray; overload; cdecl;
function TArray_Copy(const arr: TRangeArray; const IDs: TIntegerArray): TRangeArray; overload; cdecl;

function TArray_Create(const item: Integer): TIntegerArray; overload; cdecl;
function TArray_Create(const item: Double): TDoubleArray; overload; cdecl;
function TArray_Create(const item: string): TStringArray; overload; cdecl;
function TArray_Create(const item: Char): TCharArray; overload; cdecl;
function TArray_Create(const item: Boolean): TBooleanArray; overload; cdecl;
function TArray_Create(const item: TPoint): TPointArray; overload; cdecl;
function TArray_Create(const item: TBox): TBoxArray; overload; cdecl;
function TArray_Create(const item: TRange): TRangeArray; overload; cdecl;
function TArray_Create(const size: Integer; const item: Integer): TIntegerArray; overload; cdecl;
function TArray_Create(const size: Integer; const item: Double): TDoubleArray; overload; cdecl;
function TArray_Create(const size: Integer; const item: string): TStringArray; overload; cdecl;
function TArray_Create(const size: Integer; const item: Char): TCharArray; overload; cdecl;
function TArray_Create(const size: Integer; const item: Boolean): TBooleanArray; overload; cdecl;
function TArray_Create(const size: Integer; const item: TPoint): TPointArray; overload; cdecl;
function TArray_Create(const size: Integer; const item: TBox): TBoxArray; overload; cdecl;
function TArray_Create(const size: Integer; const item: TRange): TRangeArray; overload; cdecl;

function TArray_Delete(var arr: TIntegerArray; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TDoubleArray; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TStringArray; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TCharArray; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TBooleanArray; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TPointArray; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TBoxArray; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TRangeArray; const index: Integer = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TIntegerArray; const IDs: TIntegerArray): Integer; overload; cdecl;
function TArray_Delete(var arr: TDoubleArray; const IDs: TIntegerArray): Integer; overload; cdecl;
function TArray_Delete(var arr: TStringArray; const IDs: TIntegerArray): Integer; overload; cdecl;
function TArray_Delete(var arr: TCharArray; const IDs: TIntegerArray): Integer; overload; cdecl;
function TArray_Delete(var arr: TBooleanArray; const IDs: TIntegerArray): Integer; overload; cdecl;
function TArray_Delete(var arr: TPointArray; const IDs: TIntegerArray): Integer; overload; cdecl;
function TArray_Delete(var arr: TBoxArray; const IDs: TIntegerArray): Integer; overload; cdecl;
function TArray_Delete(var arr: TRangeArray; const IDs: TIntegerArray): Integer; overload; cdecl;

function TArray_Differ(const arr, target: TIntegerArray): Boolean; overload; cdecl;
function TArray_Differ(const arr, target: TDoubleArray): Boolean; overload; cdecl;
function TArray_Differ(const arr, target: TStringArray): Boolean; overload; cdecl;
function TArray_Differ(const arr, target: TCharArray): Boolean; overload; cdecl;
function TArray_Differ(const arr, target: TBooleanArray): Boolean; overload; cdecl;
function TArray_Differ(const arr, target: TPointArray): Boolean; overload; cdecl;
function TArray_Differ(const arr, target: TBoxArray): Boolean; overload; cdecl;
function TArray_Differ(const arr, target: TRangeArray): Boolean; overload; cdecl;

function TArray_Distribute(const arr: TIntegerArray; const parts: Integer): T2DIntegerArray; overload; cdecl;
function TArray_Distribute(const arr: TDoubleArray; const parts: Integer): T2DDoubleArray; overload; cdecl;
function TArray_Distribute(const arr: TStringArray; const parts: Integer): T2DStringArray; overload; cdecl;
function TArray_Distribute(const arr: TCharArray; const parts: Integer): T2DCharArray; overload; cdecl;
function TArray_Distribute(const arr: TBooleanArray; const parts: Integer): T2DBooleanArray; overload; cdecl;
function TArray_Distribute(const arr: TPointArray; const parts: Integer): T2DPointArray; overload; cdecl;
function TArray_Distribute(const arr: TBoxArray; const parts: Integer): T2DBoxArray; overload; cdecl;
function TArray_Distribute(const arr: TRangeArray; const parts: Integer): T2DRangeArray; overload; cdecl;

function TArray_Dump(var arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Dump(var arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Dump(var arr: TStringArray; const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Dump(var arr: TCharArray; const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Dump(var arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Dump(var arr: TPointArray; const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Dump(var arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Dump(var arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl;

function TArray_Dupe(const arr: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Dupe(const arr: TDoubleArray): TDoubleArray; overload; cdecl;
function TArray_Dupe(const arr: TStringArray): TStringArray; overload; cdecl;
function TArray_Dupe(const arr: TCharArray): TCharArray; overload; cdecl;
function TArray_Dupe(const arr: TBooleanArray): TBooleanArray; overload; cdecl;
function TArray_Dupe(const arr: TPointArray): TPointArray; overload; cdecl;
function TArray_Dupe(const arr: TBoxArray): TBoxArray; overload; cdecl;
function TArray_Dupe(const arr: TRangeArray): TRangeArray; overload; cdecl;

function TArray_Empty(const arr: TIntegerArray): Boolean; overload; cdecl;
function TArray_Empty(const arr: TDoubleArray): Boolean; overload; cdecl;
function TArray_Empty(const arr: TStringArray): Boolean; overload; cdecl;
function TArray_Empty(const arr: TCharArray): Boolean; overload; cdecl;
function TArray_Empty(const arr: TBooleanArray): Boolean; overload; cdecl;
function TArray_Empty(const arr: TPointArray): Boolean; overload; cdecl;
function TArray_Empty(const arr: TBoxArray): Boolean; overload; cdecl;
function TArray_Empty(const arr: TRangeArray): Boolean; overload; cdecl;

function TArray_Equal(const arr, target: TIntegerArray): Boolean; overload; cdecl;
function TArray_Equal(const arr, target: TDoubleArray): Boolean; overload; cdecl;
function TArray_Equal(const arr, target: TStringArray): Boolean; overload; cdecl;
function TArray_Equal(const arr, target: TCharArray): Boolean; overload; cdecl;
function TArray_Equal(const arr, target: TBooleanArray): Boolean; overload; cdecl;
function TArray_Equal(const arr, target: TPointArray): Boolean; overload; cdecl;
function TArray_Equal(const arr, target: TBoxArray): Boolean; overload; cdecl;
function TArray_Equal(const arr, target: TRangeArray): Boolean; overload; cdecl;

function TArray_Extend(const arr: TIntegerArray; const item: Integer): TIntegerArray; overload; cdecl;
function TArray_Extend(const arr: TDoubleArray; const item: Double): TDoubleArray; overload; cdecl;
function TArray_Extend(const arr: TStringArray; const item: string): TStringArray; overload; cdecl;
function TArray_Extend(const arr: TCharArray; const item: Char): TCharArray; overload; cdecl;
function TArray_Extend(const arr: TBooleanArray; const item: Boolean): TBooleanArray; overload; cdecl;
function TArray_Extend(const arr: TPointArray; const item: TPoint): TPointArray; overload; cdecl;
function TArray_Extend(const arr: TBoxArray; const item: TBox): TBoxArray; overload; cdecl;
function TArray_Extend(const arr: TRangeArray; const item: TRange): TRangeArray; overload; cdecl;
function TArray_Extend(const arr: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Extend(const arr: TDoubleArray; const items: TDoubleArray): TDoubleArray; overload; cdecl;
function TArray_Extend(const arr: TStringArray; const items: TStringArray): TStringArray; overload; cdecl;
function TArray_Extend(const arr: TCharArray; const items: TCharArray): TCharArray; overload; cdecl;
function TArray_Extend(const arr: TBooleanArray; const items: TBooleanArray): TBooleanArray; overload; cdecl;
function TArray_Extend(const arr: TPointArray; const items: TPointArray): TPointArray; overload; cdecl;
function TArray_Extend(const arr: TBoxArray; const items: TBoxArray): TBoxArray; overload; cdecl;
function TArray_Extend(const arr: TRangeArray; const items: TRangeArray): TRangeArray; overload; cdecl;

function TArray_Extract(const arr: TIntegerArray; const item: Integer; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Extract(const arr: TDoubleArray; const item: Double; const index: Integer = 0): TDoubleArray; overload; cdecl;
function TArray_Extract(const arr: TStringArray; const item: string; const index: Integer = 0): TStringArray; overload; cdecl;
function TArray_Extract(const arr: TCharArray; const item: Char; const index: Integer = 0): TCharArray; overload; cdecl;
function TArray_Extract(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0): TBooleanArray; overload; cdecl;
function TArray_Extract(const arr: TPointArray; const item: TPoint; const index: Integer = 0): TPointArray; overload; cdecl;
function TArray_Extract(const arr: TBoxArray; const item: TBox; const index: Integer = 0): TBoxArray; overload; cdecl;
function TArray_Extract(const arr: TRangeArray; const item: TRange; const index: Integer = 0): TRangeArray; overload; cdecl;
function TArray_Extract(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Extract(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): TDoubleArray; overload; cdecl;
function TArray_Extract(const arr: TStringArray; const items: TStringArray; const index: Integer = 0): TStringArray; overload; cdecl;
function TArray_Extract(const arr: TCharArray; const items: TCharArray; const index: Integer = 0): TCharArray; overload; cdecl;
function TArray_Extract(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): TBooleanArray; overload; cdecl;
function TArray_Extract(const arr: TPointArray; const items: TPointArray; const index: Integer = 0): TPointArray; overload; cdecl;
function TArray_Extract(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): TBoxArray; overload; cdecl;
function TArray_Extract(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): TRangeArray; overload; cdecl;

function TArray_ExtractEvery(const arr: TIntegerArray; const X: Integer = 1; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_ExtractEvery(const arr: TDoubleArray; const X: Integer = 1; const index: Integer = 0): TDoubleArray; overload; cdecl;
function TArray_ExtractEvery(const arr: TStringArray; const X: Integer = 1; const index: Integer = 0): TStringArray; overload; cdecl;
function TArray_ExtractEvery(const arr: TCharArray; const X: Integer = 1; const index: Integer = 0): TCharArray; overload; cdecl;
function TArray_ExtractEvery(const arr: TBooleanArray; const X: Integer = 1; const index: Integer = 0): TBooleanArray; overload; cdecl;
function TArray_ExtractEvery(const arr: TPointArray; const X: Integer = 1; const index: Integer = 0): TPointArray; overload; cdecl;
function TArray_ExtractEvery(const arr: TBoxArray; const X: Integer = 1; const index: Integer = 0): TBoxArray; overload; cdecl;
function TArray_ExtractEvery(const arr: TRangeArray; const X: Integer = 1; const index: Integer = 0): TRangeArray; overload; cdecl;

function TArray_Fill(const arr: TIntegerArray; const item: Integer; const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Fill(const arr: TDoubleArray; const item: Double; const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl;
function TArray_Fill(const arr: TStringArray; const item: string; const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl;
function TArray_Fill(const arr: TCharArray; const item: Char; const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl;
function TArray_Fill(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl;
function TArray_Fill(const arr: TPointArray; const item: TPoint; const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl;
function TArray_Fill(const arr: TBoxArray; const item: TBox; const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl;
function TArray_Fill(const arr: TRangeArray; const item: TRange; const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl;
function TArray_Fill(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Fill(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl;
function TArray_Fill(const arr: TStringArray; const items: TStringArray; const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl;
function TArray_Fill(const arr: TCharArray; const items: TCharArray; const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl;
function TArray_Fill(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl;
function TArray_Fill(const arr: TPointArray; const items: TPointArray; const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl;
function TArray_Fill(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl;
function TArray_Fill(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl;

function TArray_Filter(const arr: TIntegerArray; const item: Integer; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Filter(const arr: TDoubleArray; const item: Double; const index: Integer = 0): TDoubleArray; overload; cdecl;
function TArray_Filter(const arr: TStringArray; const item: string; const index: Integer = 0): TStringArray; overload; cdecl;
function TArray_Filter(const arr: TCharArray; const item: Char; const index: Integer = 0): TCharArray; overload; cdecl;
function TArray_Filter(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0): TBooleanArray; overload; cdecl;
function TArray_Filter(const arr: TPointArray; const item: TPoint; const index: Integer = 0): TPointArray; overload; cdecl;
function TArray_Filter(const arr: TBoxArray; const item: TBox; const index: Integer = 0): TBoxArray; overload; cdecl;
function TArray_Filter(const arr: TRangeArray; const item: TRange; const index: Integer = 0): TRangeArray; overload; cdecl;
function TArray_Filter(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Filter(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): TDoubleArray; overload; cdecl;
function TArray_Filter(const arr: TStringArray; const items: TStringArray; const index: Integer = 0): TStringArray; overload; cdecl;
function TArray_Filter(const arr: TCharArray; const items: TCharArray; const index: Integer = 0): TCharArray; overload; cdecl;
function TArray_Filter(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): TBooleanArray; overload; cdecl;
function TArray_Filter(const arr: TPointArray; const items: TPointArray; const index: Integer = 0): TPointArray; overload; cdecl;
function TArray_Filter(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): TBoxArray; overload; cdecl;
function TArray_Filter(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): TRangeArray; overload; cdecl;

function TArray_FilterEvery(const arr: TIntegerArray; const X: Integer = 1; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_FilterEvery(const arr: TDoubleArray; const X: Integer = 1; const index: Integer = 0): TDoubleArray; overload; cdecl;
function TArray_FilterEvery(const arr: TStringArray; const X: Integer = 1; const index: Integer = 0): TStringArray; overload; cdecl;
function TArray_FilterEvery(const arr: TCharArray; const X: Integer = 1; const index: Integer = 0): TCharArray; overload; cdecl;
function TArray_FilterEvery(const arr: TBooleanArray; const X: Integer = 1; const index: Integer = 0): TBooleanArray; overload; cdecl;
function TArray_FilterEvery(const arr: TPointArray; const X: Integer = 1; const index: Integer = 0): TPointArray; overload; cdecl;
function TArray_FilterEvery(const arr: TBoxArray; const X: Integer = 1; const index: Integer = 0): TBoxArray; overload; cdecl;
function TArray_FilterEvery(const arr: TRangeArray; const X: Integer = 1; const index: Integer = 0): TRangeArray; overload; cdecl;

function TArray_Flip(var arr: TIntegerArray): Boolean; overload; cdecl;
function TArray_Flip(var arr: TDoubleArray): Boolean; overload; cdecl;
function TArray_Flip(var arr: TStringArray): Boolean; overload; cdecl;
function TArray_Flip(var arr: TCharArray): Boolean; overload; cdecl;
function TArray_Flip(var arr: TBooleanArray): Boolean; overload; cdecl;
function TArray_Flip(var arr: TPointArray): Boolean; overload; cdecl;
function TArray_Flip(var arr: TBoxArray): Boolean; overload; cdecl;
function TArray_Flip(var arr: TRangeArray): Boolean; overload; cdecl;

function TArray_Get(const arr: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Get(const arr: TDoubleArray): TDoubleArray; overload; cdecl;
function TArray_Get(const arr: TStringArray): TStringArray; overload; cdecl;
function TArray_Get(const arr: TCharArray): TCharArray; overload; cdecl;
function TArray_Get(const arr: TBooleanArray): TBooleanArray; overload; cdecl;
function TArray_Get(const arr: TPointArray): TPointArray; overload; cdecl;
function TArray_Get(const arr: TBoxArray): TBoxArray; overload; cdecl;
function TArray_Get(const arr: TRangeArray): TRangeArray; overload; cdecl;
function TArray_Get(const arr: TIntegerArray; const IDs: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Get(const arr: TDoubleArray; const IDs: TIntegerArray): TDoubleArray; overload; cdecl;
function TArray_Get(const arr: TStringArray; const IDs: TIntegerArray): TStringArray; overload; cdecl;
function TArray_Get(const arr: TCharArray; const IDs: TIntegerArray): TCharArray; overload; cdecl;
function TArray_Get(const arr: TBooleanArray; const IDs: TIntegerArray): TBooleanArray; overload; cdecl;
function TArray_Get(const arr: TPointArray; const IDs: TIntegerArray): TPointArray; overload; cdecl;
function TArray_Get(const arr: TBoxArray; const IDs: TIntegerArray): TBoxArray; overload; cdecl;
function TArray_Get(const arr: TRangeArray; const IDs: TIntegerArray): TRangeArray; overload; cdecl;

function TArray_Group(const arr: TIntegerArray): T2DIntegerArray; overload; cdecl;
function TArray_Group(const arr: TDoubleArray): T2DDoubleArray; overload; cdecl;
function TArray_Group(const arr: TStringArray): T2DStringArray; overload; cdecl;
function TArray_Group(const arr: TCharArray): T2DCharArray; overload; cdecl;
function TArray_Group(const arr: TBooleanArray): T2DBooleanArray; overload; cdecl;
function TArray_Group(const arr: TPointArray): T2DPointArray; overload; cdecl;
function TArray_Group(const arr: TBoxArray): T2DBoxArray; overload; cdecl;
function TArray_Group(const arr: TRangeArray): T2DRangeArray; overload; cdecl;

function TArray_Holds(const arr, chain: TIntegerArray): Boolean; overload; cdecl;
function TArray_Holds(const arr, chain: TDoubleArray): Boolean; overload; cdecl;
function TArray_Holds(const arr, chain: TStringArray): Boolean; overload; cdecl;
function TArray_Holds(const arr, chain: TCharArray): Boolean; overload; cdecl;
function TArray_Holds(const arr, chain: TBooleanArray): Boolean; overload; cdecl;
function TArray_Holds(const arr, chain: TPointArray): Boolean; overload; cdecl;
function TArray_Holds(const arr, chain: TBoxArray): Boolean; overload; cdecl;
function TArray_Holds(const arr, chain: TRangeArray): Boolean; overload; cdecl;

function TArray_IDs(const arr: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_IDs(const arr: TDoubleArray): TIntegerArray; overload; cdecl;
function TArray_IDs(const arr: TStringArray): TIntegerArray; overload; cdecl;
function TArray_IDs(const arr: TCharArray): TIntegerArray; overload; cdecl;
function TArray_IDs(const arr: TBooleanArray): TIntegerArray; overload; cdecl;
function TArray_IDs(const arr: TPointArray): TIntegerArray; overload; cdecl;
function TArray_IDs(const arr: TBoxArray): TIntegerArray; overload; cdecl;
function TArray_IDs(const arr: TRangeArray): TIntegerArray; overload; cdecl;
function TArray_IDs(const arr: TIntegerArray; const IDs: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_IDs(const arr: TDoubleArray; const IDs: TIntegerArray): TDoubleArray; overload; cdecl;
function TArray_IDs(const arr: TStringArray; const IDs: TIntegerArray): TStringArray; overload; cdecl;
function TArray_IDs(const arr: TCharArray; const IDs: TIntegerArray): TCharArray; overload; cdecl;
function TArray_IDs(const arr: TBooleanArray; const IDs: TIntegerArray): TBooleanArray; overload; cdecl;
function TArray_IDs(const arr: TPointArray; const IDs: TIntegerArray): TPointArray; overload; cdecl;
function TArray_IDs(const arr: TBoxArray; const IDs: TIntegerArray): TBoxArray; overload; cdecl;
function TArray_IDs(const arr: TRangeArray; const IDs: TIntegerArray): TRangeArray; overload; cdecl;
function TArray_IDs(const arr: TIntegerArray; const IDs: TIntegerArray; const item: Integer): TIntegerArray; overload; cdecl;
function TArray_IDs(const arr: TDoubleArray; const IDs: TIntegerArray; const item: Double): TDoubleArray; overload; cdecl;
function TArray_IDs(const arr: TStringArray; const IDs: TIntegerArray; const item: string): TStringArray; overload; cdecl;
function TArray_IDs(const arr: TCharArray; const IDs: TIntegerArray; const item: Char): TCharArray; overload; cdecl;
function TArray_IDs(const arr: TBooleanArray; const IDs: TIntegerArray; const item: Boolean): TBooleanArray; overload; cdecl;
function TArray_IDs(const arr: TPointArray; const IDs: TIntegerArray; const item: TPoint): TPointArray; overload; cdecl;
function TArray_IDs(const arr: TBoxArray; const IDs: TIntegerArray; const item: TBox): TBoxArray; overload; cdecl;
function TArray_IDs(const arr: TRangeArray; const IDs: TIntegerArray; const item: TRange): TRangeArray; overload; cdecl;
function TArray_IDs(const arr: TIntegerArray; const IDs: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_IDs(const arr: TDoubleArray; const IDs: TIntegerArray; const items: TDoubleArray): TDoubleArray; overload; cdecl;
function TArray_IDs(const arr: TStringArray; const IDs: TIntegerArray; const items: TStringArray): TStringArray; overload; cdecl;
function TArray_IDs(const arr: TCharArray; const IDs: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl;
function TArray_IDs(const arr: TBooleanArray; const IDs: TIntegerArray; const items: TBooleanArray): TBooleanArray; overload; cdecl;
function TArray_IDs(const arr: TPointArray; const IDs: TIntegerArray; const items: TPointArray): TPointArray; overload; cdecl;
function TArray_IDs(const arr: TBoxArray; const IDs: TIntegerArray; const items: TBoxArray): TBoxArray; overload; cdecl;
function TArray_IDs(const arr: TRangeArray; const IDs: TIntegerArray; const items: TRangeArray): TRangeArray; overload; cdecl;

function TArray_Includes(const arr: TIntegerArray; const item: Integer; const index: Integer = 2147483647): Boolean; overload; cdecl;
function TArray_Includes(const arr: TDoubleArray; const item: Double; const index: Integer = 2147483647): Boolean; overload; cdecl;
function TArray_Includes(const arr: TStringArray; const item: string; const index: Integer = 2147483647): Boolean; overload; cdecl;
function TArray_Includes(const arr: TCharArray; const item: Char; const index: Integer = 2147483647): Boolean; overload; cdecl;
function TArray_Includes(const arr: TBooleanArray; const item: Boolean; const index: Integer = 2147483647): Boolean; overload; cdecl;
function TArray_Includes(const arr: TPointArray; const item: TPoint; const index: Integer = 2147483647): Boolean; overload; cdecl;
function TArray_Includes(const arr: TBoxArray; const item: TBox; const index: Integer = 2147483647): Boolean; overload; cdecl;
function TArray_Includes(const arr: TRangeArray; const item: TRange; const index: Integer = 2147483647): Boolean; overload; cdecl;

function TArray_Keep(var arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Keep(var arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Keep(var arr: TStringArray; const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Keep(var arr: TCharArray; const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Keep(var arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Keep(var arr: TPointArray; const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Keep(var arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Keep(var arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl;

function TArray_LeastFrequent(const arr: TIntegerArray): Integer; cdecl; overload;
function TArray_LeastFrequent(const arr: TDoubleArray): Double; cdecl; overload;
function TArray_LeastFrequent(const arr: TStringArray): string; cdecl; overload;
function TArray_LeastFrequent(const arr: TCharArray): Char; cdecl; overload;
function TArray_LeastFrequent(const arr: TBooleanArray): Boolean; cdecl; overload;
function TArray_LeastFrequent(const arr: TPointArray): TPoint; cdecl; overload;
function TArray_LeastFrequent(const arr: TBoxArray): TBox; cdecl; overload;
function TArray_LeastFrequent(const arr: TRangeArray): TRange; cdecl; overload;

function TArray_MostFrequent(const arr: TIntegerArray): Integer; cdecl; overload;
function TArray_MostFrequent(const arr: TDoubleArray): Double; cdecl; overload;
function TArray_MostFrequent(const arr: TStringArray): string; cdecl; overload;
function TArray_MostFrequent(const arr: TCharArray): Char; cdecl; overload;
function TArray_MostFrequent(const arr: TBooleanArray): Boolean; cdecl; overload;
function TArray_MostFrequent(const arr: TPointArray): TPoint; cdecl; overload;
function TArray_MostFrequent(const arr: TBoxArray): TBox; cdecl; overload;
function TArray_MostFrequent(const arr: TRangeArray): TRange; cdecl; overload;

function TArray_Move(var arr: TIntegerArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl;
function TArray_Move(var arr: TDoubleArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl;
function TArray_Move(var arr: TStringArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl;
function TArray_Move(var arr: TCharArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl;
function TArray_Move(var arr: TBooleanArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl;
function TArray_Move(var arr: TPointArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl;
function TArray_Move(var arr: TBoxArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl;
function TArray_Move(var arr: TRangeArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl;

function TArray_Oversize(const arr: TIntegerArray; const limit: Integer): Boolean; overload; cdecl;
function TArray_Oversize(const arr: TDoubleArray; const limit: Integer): Boolean; overload; cdecl;
function TArray_Oversize(const arr: TStringArray; const limit: Integer): Boolean; overload; cdecl;
function TArray_Oversize(const arr: TCharArray; const limit: Integer): Boolean; overload; cdecl;
function TArray_Oversize(const arr: TBooleanArray; const limit: Integer): Boolean; overload; cdecl;
function TArray_Oversize(const arr: TPointArray; const limit: Integer): Boolean; overload; cdecl;
function TArray_Oversize(const arr: TBoxArray; const limit: Integer): Boolean; overload; cdecl;
function TArray_Oversize(const arr: TRangeArray; const limit: Integer): Boolean; overload; cdecl;

function TArray_Partition(const arr: TIntegerArray; const size: Integer): T2DIntegerArray; overload; cdecl;
function TArray_Partition(const arr: TDoubleArray; const size: Integer): T2DDoubleArray; overload; cdecl;
function TArray_Partition(const arr: TStringArray; const size: Integer): T2DStringArray; overload; cdecl;
function TArray_Partition(const arr: TCharArray; const size: Integer): T2DCharArray; overload; cdecl;
function TArray_Partition(const arr: TBooleanArray; const size: Integer): T2DBooleanArray; overload; cdecl;
function TArray_Partition(const arr: TPointArray; const size: Integer): T2DPointArray; overload; cdecl;
function TArray_Partition(const arr: TBoxArray; const size: Integer): T2DBoxArray; overload; cdecl;
function TArray_Partition(const arr: TRangeArray; const size: Integer): T2DRangeArray; overload; cdecl;

function TArray_Pick(var arr: TIntegerArray; const IDs: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Pick(var arr: TDoubleArray; const IDs: TIntegerArray): TDoubleArray; overload; cdecl;
function TArray_Pick(var arr: TStringArray; const IDs: TIntegerArray): TStringArray; overload; cdecl;
function TArray_Pick(var arr: TCharArray; const IDs: TIntegerArray): TCharArray; overload; cdecl;
function TArray_Pick(var arr: TBooleanArray; const IDs: TIntegerArray): TBooleanArray; overload; cdecl;
function TArray_Pick(var arr: TPointArray; const IDs: TIntegerArray): TPointArray; overload; cdecl;
function TArray_Pick(var arr: TBoxArray; const IDs: TIntegerArray): TBoxArray; overload; cdecl;
function TArray_Pick(var arr: TRangeArray; const IDs: TIntegerArray): TRangeArray; overload; cdecl;

function TArray_Pop(var arr: TIntegerArray): Integer; overload; cdecl;
function TArray_Pop(var arr: TDoubleArray): Double; overload; cdecl;
function TArray_Pop(var arr: TStringArray): string; overload; cdecl;
function TArray_Pop(var arr: TCharArray): Char; overload; cdecl;
function TArray_Pop(var arr: TBooleanArray): Boolean; overload; cdecl;
function TArray_Pop(var arr: TPointArray): TPoint; overload; cdecl;
function TArray_Pop(var arr: TBoxArray): TBox; overload; cdecl;
function TArray_Pop(var arr: TRangeArray): TRange; overload; cdecl;
function TArray_Pop(var arr: TIntegerArray; const null: Integer): Integer; overload; cdecl;
function TArray_Pop(var arr: TDoubleArray; const null: Double): Double; overload; cdecl;
function TArray_Pop(var arr: TStringArray; const null: string): string; overload; cdecl;
function TArray_Pop(var arr: TCharArray; const null: Char): Char; overload; cdecl;
function TArray_Pop(var arr: TBooleanArray; const null: Boolean): Boolean; overload; cdecl;
function TArray_Pop(var arr: TPointArray; const null: TPoint): TPoint; overload; cdecl;
function TArray_Pop(var arr: TBoxArray; const null: TBox): TBox; overload; cdecl;
function TArray_Pop(var arr: TRangeArray; const null: TRange): TRange; overload; cdecl;

function TArray_Pos(const arr: TIntegerArray; const item: Integer; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TDoubleArray; const item: Double; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TStringArray; const item: string; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TCharArray; const item: Char; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TPointArray; const item: TPoint; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TBoxArray; const item: TBox; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TRangeArray; const item: TRange; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TStringArray; const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TCharArray; const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TPointArray; const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Pos(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl;

function TArray_Position(const arr: TIntegerArray; const item: Integer; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TDoubleArray; const item: Double; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TStringArray; const item: string; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TCharArray; const item: Char; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TPointArray; const item: TPoint; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TBoxArray; const item: TBox; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TRangeArray; const item: TRange; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TStringArray; const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TCharArray; const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TPointArray; const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Position(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl;

function TArray_Positions(const arr: TIntegerArray; const item: Integer; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TDoubleArray; const item: Double; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TStringArray; const item: string; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TCharArray; const item: Char; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TPointArray; const item: TPoint; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TBoxArray; const item: TBox; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TRangeArray; const item: TRange; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TStringArray; const items: TStringArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TCharArray; const items: TCharArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TPointArray; const items: TPointArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): TIntegerArray; overload; cdecl;

function TArray_PosLast(const arr: TIntegerArray; const item: Integer; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TDoubleArray; const item: Double; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TStringArray; const item: string; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TCharArray; const item: Char; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TBooleanArray; const item: Boolean; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TPointArray; const item: TPoint; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TBoxArray; const item: TBox; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TRangeArray; const item: TRange; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TStringArray; const items: TStringArray; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TCharArray; const items: TCharArray; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TPointArray; const items: TPointArray; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 2147483647): Integer; overload; cdecl;
function TArray_PosLast(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 2147483647): Integer; overload; cdecl;

function TArray_PosLasts(const arr: TIntegerArray; const item: Integer; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TDoubleArray; const item: Double; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TStringArray; const item: string; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TCharArray; const item: Char; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TBooleanArray; const item: Boolean; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TPointArray; const item: TPoint; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TBoxArray; const item: TBox; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TRangeArray; const item: TRange; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TStringArray; const items: TStringArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TCharArray; const items: TCharArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TPointArray; const items: TPointArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;

function TArray_Push(var arr: TIntegerArray; const item: Integer): Integer; overload; cdecl;
function TArray_Push(var arr: TDoubleArray; const item: Double): Integer; overload; cdecl;
function TArray_Push(var arr: TStringArray; const item: string): Integer; overload; cdecl;
function TArray_Push(var arr: TCharArray; const item: Char): Integer; overload; cdecl;
function TArray_Push(var arr: TBooleanArray; const item: Boolean): Integer; overload; cdecl;
function TArray_Push(var arr: TPointArray; const item: TPoint): Integer; overload; cdecl;
function TArray_Push(var arr: TBoxArray; const item: TBox): Integer; overload; cdecl;
function TArray_Push(var arr: TRangeArray; const item: TRange): Integer; overload; cdecl;
function TArray_Push(var arr: TIntegerArray; const items: TIntegerArray): Integer; overload; cdecl;
function TArray_Push(var arr: TDoubleArray; const items: TDoubleArray): Integer; overload; cdecl;
function TArray_Push(var arr: TStringArray; const items: TStringArray): Integer; overload; cdecl;
function TArray_Push(var arr: TCharArray; const items: TCharArray): Integer; overload; cdecl;
function TArray_Push(var arr: TBooleanArray; const items: TBooleanArray): Integer; overload; cdecl;
function TArray_Push(var arr: TPointArray; const items: TPointArray): Integer; overload; cdecl;
function TArray_Push(var arr: TBoxArray; const items: TBoxArray): Integer; overload; cdecl;
function TArray_Push(var arr: TRangeArray; const items: TRangeArray): Integer; overload; cdecl;

function TArray_Randomize(var arr: TIntegerArray; const shuffles: Integer = 1): Boolean; overload; cdecl;
function TArray_Randomize(var arr: TDoubleArray; const shuffles: Integer = 1): Boolean; overload; cdecl;
function TArray_Randomize(var arr: TStringArray; const shuffles: Integer = 1): Boolean; overload; cdecl;
function TArray_Randomize(var arr: TCharArray; const shuffles: Integer = 1): Boolean; overload; cdecl;
function TArray_Randomize(var arr: TBooleanArray; const shuffles: Integer = 1): Boolean; overload; cdecl;
function TArray_Randomize(var arr: TPointArray; const shuffles: Integer = 1): Boolean; overload; cdecl;
function TArray_Randomize(var arr: TBoxArray; const shuffles: Integer = 1): Boolean; overload; cdecl;
function TArray_Randomize(var arr: TRangeArray; const shuffles: Integer = 1): Boolean; overload; cdecl;

function TArray_Remove(var arr: TIntegerArray; const item: Integer; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TDoubleArray; const item: Double; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TStringArray; const item: string; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TCharArray; const item: Char; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TBooleanArray; const item: Boolean; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TPointArray; const item: TPoint; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TBoxArray; const item: TBox; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TRangeArray; const item: TRange; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TIntegerArray; const item: Integer; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TDoubleArray; const item: Double; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TStringArray; const item: string; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TCharArray; const item: Char; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TBooleanArray; const item: Boolean; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TPointArray; const item: TPoint; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TBoxArray; const item: TBox; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TRangeArray; const item: TRange; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TStringArray; const items: TStringArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TCharArray; const items: TCharArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TPointArray; const items: TPointArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TBoxArray; const items: TBoxArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TRangeArray; const items: TRangeArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
function TArray_Remove(var arr: TIntegerArray; const items: TIntegerArray; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TDoubleArray; const items: TDoubleArray; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TStringArray; const items: TStringArray; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TCharArray; const items: TCharArray; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TBooleanArray; const items: TBooleanArray; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TPointArray; const items: TPointArray; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TBoxArray; const items: TBoxArray; const all: Boolean): Integer; overload; cdecl;
function TArray_Remove(var arr: TRangeArray; const items: TRangeArray; const all: Boolean): Integer; overload; cdecl;

function TArray_Reverse(var arr: TIntegerArray): Boolean; overload; cdecl;
function TArray_Reverse(var arr: TDoubleArray): Boolean; overload; cdecl;
function TArray_Reverse(var arr: TStringArray): Boolean; overload; cdecl;
function TArray_Reverse(var arr: TCharArray): Boolean; overload; cdecl;
function TArray_Reverse(var arr: TBooleanArray): Boolean; overload; cdecl;
function TArray_Reverse(var arr: TPointArray): Boolean; overload; cdecl;
function TArray_Reverse(var arr: TBoxArray): Boolean; overload; cdecl;
function TArray_Reverse(var arr: TRangeArray): Boolean; overload; cdecl;

function TArray_Reversed(const arr: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Reversed(const arr: TDoubleArray): TDoubleArray; overload; cdecl;
function TArray_Reversed(const arr: TStringArray): TStringArray; overload; cdecl;
function TArray_Reversed(const arr: TCharArray): TCharArray; overload; cdecl;
function TArray_Reversed(const arr: TBooleanArray): TBooleanArray; overload; cdecl;
function TArray_Reversed(const arr: TPointArray): TPointArray; overload; cdecl;
function TArray_Reversed(const arr: TBoxArray): TBoxArray; overload; cdecl;
function TArray_Reversed(const arr: TRangeArray): TRangeArray; overload; cdecl;

function TArray_Set(const arr: TIntegerArray; const IDs: TIntegerArray; const item: Integer): TIntegerArray; overload; cdecl;
function TArray_Set(const arr: TDoubleArray; const IDs: TIntegerArray; const item: Double): TDoubleArray; overload; cdecl;
function TArray_Set(const arr: TStringArray; const IDs: TIntegerArray; const item: string): TStringArray; overload; cdecl;
function TArray_Set(const arr: TCharArray; const IDs: TIntegerArray; const item: Char): TCharArray; overload; cdecl;
function TArray_Set(const arr: TBooleanArray; const IDs: TIntegerArray; const item: Boolean): TBooleanArray; overload; cdecl;
function TArray_Set(const arr: TPointArray; const IDs: TIntegerArray; const item: TPoint): TPointArray; overload; cdecl;
function TArray_Set(const arr: TBoxArray; const IDs: TIntegerArray; const item: TBox): TBoxArray; overload; cdecl;
function TArray_Set(const arr: TRangeArray; const IDs: TIntegerArray; const item: TRange): TRangeArray; overload; cdecl;
function TArray_Set(const arr: TIntegerArray; const IDs: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Set(const arr: TDoubleArray; const IDs: TIntegerArray; const items: TDoubleArray): TDoubleArray; overload; cdecl;
function TArray_Set(const arr: TStringArray; const IDs: TIntegerArray; const items: TStringArray): TStringArray; overload; cdecl;
function TArray_Set(const arr: TCharArray; const IDs: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl;
function TArray_Set(const arr: TBooleanArray; const IDs: TIntegerArray; const items: TBooleanArray): TBooleanArray; overload; cdecl;
function TArray_Set(const arr: TPointArray; const IDs: TIntegerArray; const items: TPointArray): TPointArray; overload; cdecl;
function TArray_Set(const arr: TBoxArray; const IDs: TIntegerArray; const items: TBoxArray): TBoxArray; overload; cdecl;
function TArray_Set(const arr: TRangeArray; const IDs: TIntegerArray; const items: TRangeArray): TRangeArray; overload; cdecl;
function TArray_Set(const arr: TIntegerArray; const index: Integer; const items: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Set(const arr: TDoubleArray; const index: Integer; const items: TDoubleArray): TDoubleArray; overload; cdecl;
function TArray_Set(const arr: TStringArray; const index: Integer; const items: TStringArray): TStringArray; overload; cdecl;
function TArray_Set(const arr: TCharArray; const index: Integer; const items: TCharArray): TCharArray; overload; cdecl;
function TArray_Set(const arr: TBooleanArray; const index: Integer; const items: TBooleanArray): TBooleanArray; overload; cdecl;
function TArray_Set(const arr: TPointArray; const index: Integer; const items: TPointArray): TPointArray; overload; cdecl;
function TArray_Set(const arr: TBoxArray; const index: Integer; const items: TBoxArray): TBoxArray; overload; cdecl;
function TArray_Set(const arr: TRangeArray; const index: Integer; const items: TRangeArray): TRangeArray; overload; cdecl;

function TArray_Shift(var arr: TIntegerArray): Integer; overload; cdecl;
function TArray_Shift(var arr: TDoubleArray): Double; overload; cdecl;
function TArray_Shift(var arr: TStringArray): string; overload; cdecl;
function TArray_Shift(var arr: TCharArray): Char; overload; cdecl;
function TArray_Shift(var arr: TBooleanArray): Boolean; overload; cdecl;
function TArray_Shift(var arr: TPointArray): TPoint; overload; cdecl;
function TArray_Shift(var arr: TBoxArray): TBox; overload; cdecl;
function TArray_Shift(var arr: TRangeArray): TRange; overload; cdecl;
function TArray_Shift(var arr: TIntegerArray; const shift: Integer): TIntegerArray; overload; cdecl;
function TArray_Shift(var arr: TDoubleArray; const shift: Integer): TDoubleArray; overload; cdecl;
function TArray_Shift(var arr: TStringArray; const shift: Integer): TStringArray; overload; cdecl;
function TArray_Shift(var arr: TCharArray; const shift: Integer): TCharArray; overload; cdecl;
function TArray_Shift(var arr: TBooleanArray; const shift: Integer): TBooleanArray; overload; cdecl;
function TArray_Shift(var arr: TPointArray; const shift: Integer): TPointArray; overload; cdecl;
function TArray_Shift(var arr: TBoxArray; const shift: Integer): TBoxArray; overload; cdecl;
function TArray_Shift(var arr: TRangeArray; const shift: Integer): TRangeArray; overload; cdecl;

function TArray_Size(var arr: TIntegerArray; const size: Integer): Integer; overload; cdecl;
function TArray_Size(var arr: TDoubleArray; const size: Integer): Integer; overload; cdecl;
function TArray_Size(var arr: TStringArray; const size: Integer): Integer; overload; cdecl;
function TArray_Size(var arr: TCharArray; const size: Integer): Integer; overload; cdecl;
function TArray_Size(var arr: TBooleanArray; const size: Integer): Integer; overload; cdecl;
function TArray_Size(var arr: TPointArray; const size: Integer): Integer; overload; cdecl;
function TArray_Size(var arr: TBoxArray; const size: Integer): Integer; overload; cdecl;
function TArray_Size(var arr: TRangeArray; const size: Integer): Integer; overload; cdecl;
function TArray_Size(var arr: TIntegerArray; const size: Integer; const null: Integer): Integer; overload; cdecl;
function TArray_Size(var arr: TDoubleArray; const size: Integer; const null: Double): Integer; overload; cdecl;
function TArray_Size(var arr: TStringArray; const size: Integer; const null: string): Integer; overload; cdecl;
function TArray_Size(var arr: TCharArray; const size: Integer; const null: Char): Integer; overload; cdecl;
function TArray_Size(var arr: TBooleanArray; const size: Integer; const null: Boolean): Integer; overload; cdecl;
function TArray_Size(var arr: TPointArray; const size: Integer; const null: TPoint): Integer; overload; cdecl;
function TArray_Size(var arr: TBoxArray; const size: Integer; const null: TBox): Integer; overload; cdecl;
function TArray_Size(var arr: TRangeArray; const size: Integer; const null: TRange): Integer; overload; cdecl;
function TArray_Size(const arr: TIntegerArray): Integer; overload; cdecl;
function TArray_Size(const arr: TDoubleArray): Integer; overload; cdecl;
function TArray_Size(const arr: TStringArray): Integer; overload; cdecl;
function TArray_Size(const arr: TCharArray): Integer; overload; cdecl;
function TArray_Size(const arr: TBooleanArray): Integer; overload; cdecl;
function TArray_Size(const arr: TPointArray): Integer; overload; cdecl;
function TArray_Size(const arr: TBoxArray): Integer; overload; cdecl;
function TArray_Size(const arr: TRangeArray): Integer; overload; cdecl;

function TArray_SizeBetween(const arr: TIntegerArray; const x, y: Integer): Boolean; overload; cdecl;
function TArray_SizeBetween(const arr: TDoubleArray; const x, y: Integer): Boolean; overload; cdecl;
function TArray_SizeBetween(const arr: TStringArray; const x, y: Integer): Boolean; overload; cdecl;
function TArray_SizeBetween(const arr: TCharArray; const x, y: Integer): Boolean; overload; cdecl;
function TArray_SizeBetween(const arr: TBooleanArray; const x, y: Integer): Boolean; overload; cdecl;
function TArray_SizeBetween(const arr: TPointArray; const x, y: Integer): Boolean; overload; cdecl;
function TArray_SizeBetween(const arr: TBoxArray; const x, y: Integer): Boolean; overload; cdecl;
function TArray_SizeBetween(const arr: TRangeArray; const x, y: Integer): Boolean; overload; cdecl;

function TArray_SizeMax(const arr: TIntegerArray; const y: Integer): Boolean; overload; cdecl;
function TArray_SizeMax(const arr: TDoubleArray; const y: Integer): Boolean; overload; cdecl;
function TArray_SizeMax(const arr: TStringArray; const y: Integer): Boolean; overload; cdecl;
function TArray_SizeMax(const arr: TCharArray; const y: Integer): Boolean; overload; cdecl;
function TArray_SizeMax(const arr: TBooleanArray; const y: Integer): Boolean; overload; cdecl;
function TArray_SizeMax(const arr: TPointArray; const y: Integer): Boolean; overload; cdecl;
function TArray_SizeMax(const arr: TBoxArray; const y: Integer): Boolean; overload; cdecl;
function TArray_SizeMax(const arr: TRangeArray; const y: Integer): Boolean; overload; cdecl;

function TArray_SizeMin(const arr: TIntegerArray; const x: Integer): Boolean; overload; cdecl;
function TArray_SizeMin(const arr: TDoubleArray; const x: Integer): Boolean; overload; cdecl;
function TArray_SizeMin(const arr: TStringArray; const x: Integer): Boolean; overload; cdecl;
function TArray_SizeMin(const arr: TCharArray; const x: Integer): Boolean; overload; cdecl;
function TArray_SizeMin(const arr: TBooleanArray; const x: Integer): Boolean; overload; cdecl;
function TArray_SizeMin(const arr: TPointArray; const x: Integer): Boolean; overload; cdecl;
function TArray_SizeMin(const arr: TBoxArray; const x: Integer): Boolean; overload; cdecl;
function TArray_SizeMin(const arr: TRangeArray; const x: Integer): Boolean; overload; cdecl;

function TArray_Swap(var a, b: TIntegerArray): Integer; overload; cdecl;
function TArray_Swap(var a, b: TDoubleArray): Integer; overload; cdecl;
function TArray_Swap(var a, b: TStringArray): Integer; overload; cdecl;
function TArray_Swap(var a, b: TCharArray): Integer; overload; cdecl;
function TArray_Swap(var a, b: TBooleanArray): Integer; overload; cdecl;
function TArray_Swap(var a, b: TPointArray): Integer; overload; cdecl;
function TArray_Swap(var a, b: TBoxArray): Integer; overload; cdecl;
function TArray_Swap(var a, b: TRangeArray): Integer; overload; cdecl;

function TArray_Trade(var a, b: TIntegerArray): Integer; overload; cdecl;
function TArray_Trade(var a, b: TDoubleArray): Integer; overload; cdecl;
function TArray_Trade(var a, b: TStringArray): Integer; overload; cdecl;
function TArray_Trade(var a, b: TCharArray): Integer; overload; cdecl;
function TArray_Trade(var a, b: TBooleanArray): Integer; overload; cdecl;
function TArray_Trade(var a, b: TPointArray): Integer; overload; cdecl;
function TArray_Trade(var a, b: TBoxArray): Integer; overload; cdecl;
function TArray_Trade(var a, b: TRangeArray): Integer; overload; cdecl;

function TArray_Undersize(const arr: TIntegerArray; const limit: Integer): Boolean; overload; cdecl;
function TArray_Undersize(const arr: TDoubleArray; const limit: Integer): Boolean; overload; cdecl;
function TArray_Undersize(const arr: TStringArray; const limit: Integer): Boolean; overload; cdecl;
function TArray_Undersize(const arr: TCharArray; const limit: Integer): Boolean; overload; cdecl;
function TArray_Undersize(const arr: TBooleanArray; const limit: Integer): Boolean; overload; cdecl;
function TArray_Undersize(const arr: TPointArray; const limit: Integer): Boolean; overload; cdecl;
function TArray_Undersize(const arr: TBoxArray; const limit: Integer): Boolean; overload; cdecl;
function TArray_Undersize(const arr: TRangeArray; const limit: Integer): Boolean; overload; cdecl;

function TArray_Unique(var arr: TIntegerArray): Integer; overload; cdecl;
function TArray_Unique(var arr: TDoubleArray): Integer; overload; cdecl;
function TArray_Unique(var arr: TStringArray): Integer; overload; cdecl;
function TArray_Unique(var arr: TCharArray): Integer; overload; cdecl;
function TArray_Unique(var arr: TBooleanArray): Integer; overload; cdecl;
function TArray_Unique(var arr: TPointArray): Integer; overload; cdecl;
function TArray_Unique(var arr: TBoxArray): Integer; overload; cdecl;
function TArray_Unique(var arr: TRangeArray): Integer; overload; cdecl;

function TArray_Uniqued(const arr: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Uniqued(const arr: TDoubleArray): TDoubleArray; overload; cdecl;
function TArray_Uniqued(const arr: TStringArray): TStringArray; overload; cdecl;
function TArray_Uniqued(const arr: TCharArray): TCharArray; overload; cdecl;
function TArray_Uniqued(const arr: TBooleanArray): TBooleanArray; overload; cdecl;
function TArray_Uniqued(const arr: TPointArray): TPointArray; overload; cdecl;
function TArray_Uniqued(const arr: TBoxArray): TBoxArray; overload; cdecl;
function TArray_Uniqued(const arr: TRangeArray): TRangeArray; overload; cdecl;

function TArray_Uniques(const arr: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Uniques(const arr: TDoubleArray): TIntegerArray; overload; cdecl;
function TArray_Uniques(const arr: TStringArray): TIntegerArray; overload; cdecl;
function TArray_Uniques(const arr: TCharArray): TIntegerArray; overload; cdecl;
function TArray_Uniques(const arr: TBooleanArray): TIntegerArray; overload; cdecl;
function TArray_Uniques(const arr: TPointArray): TIntegerArray; overload; cdecl;
function TArray_Uniques(const arr: TBoxArray): TIntegerArray; overload; cdecl;
function TArray_Uniques(const arr: TRangeArray): TIntegerArray; overload; cdecl;

function TArray_Unshift(var arr: TIntegerArray; const item: Integer): Integer; overload; cdecl;
function TArray_Unshift(var arr: TDoubleArray; const item: Double): Integer; overload; cdecl;
function TArray_Unshift(var arr: TStringArray; const item: string): Integer; overload; cdecl;
function TArray_Unshift(var arr: TCharArray; const item: Char): Integer; overload; cdecl;
function TArray_Unshift(var arr: TBooleanArray; const item: Boolean): Integer; overload; cdecl;
function TArray_Unshift(var arr: TPointArray; const item: TPoint): Integer; overload; cdecl;
function TArray_Unshift(var arr: TBoxArray; const item: TBox): Integer; overload; cdecl;
function TArray_Unshift(var arr: TRangeArray; const item: TRange): Integer; overload; cdecl;
function TArray_Unshift(var arr: TIntegerArray; const items: TIntegerArray): Integer; overload; cdecl;
function TArray_Unshift(var arr: TDoubleArray; const items: TDoubleArray): Integer; overload; cdecl;
function TArray_Unshift(var arr: TStringArray; const items: TStringArray): Integer; overload; cdecl;
function TArray_Unshift(var arr: TCharArray; const items: TCharArray): Integer; overload; cdecl;
function TArray_Unshift(var arr: TBooleanArray; const items: TBooleanArray): Integer; overload; cdecl;
function TArray_Unshift(var arr: TPointArray; const items: TPointArray): Integer; overload; cdecl;
function TArray_Unshift(var arr: TBoxArray; const items: TBoxArray): Integer; overload; cdecl;
function TArray_Unshift(var arr: TRangeArray; const items: TRangeArray): Integer; overload; cdecl;

function T2DArray_Blank(const arr: T2DIntegerArray): Boolean; overload; cdecl;
function T2DArray_Blank(const arr: T2DDoubleArray): Boolean; overload; cdecl;
function T2DArray_Blank(const arr: T2DStringArray): Boolean; overload; cdecl;
function T2DArray_Blank(const arr: T2DCharArray): Boolean; overload; cdecl;
function T2DArray_Blank(const arr: T2DBooleanArray): Boolean; overload; cdecl;
function T2DArray_Blank(const arr: T2DPointArray): Boolean; overload; cdecl;
function T2DArray_Blank(const arr: T2DBoxArray): Boolean; overload; cdecl;
function T2DArray_Blank(const arr: T2DRangeArray): Boolean; overload; cdecl;

function T2DArray_Create(const size1D, size2D: Integer; const item: Integer): T2DIntegerArray; overload; cdecl;
function T2DArray_Create(const size1D, size2D: Integer; const item: Double): T2DDoubleArray; overload; cdecl;
function T2DArray_Create(const size1D, size2D: Integer; const item: string): T2DStringArray; overload; cdecl;
function T2DArray_Create(const size1D, size2D: Integer; const item: Char): T2DCharArray; overload; cdecl;
function T2DArray_Create(const size1D, size2D: Integer; const item: Boolean): T2DBooleanArray; overload; cdecl;
function T2DArray_Create(const size1D, size2D: Integer; const item: TPoint): T2DPointArray; overload; cdecl;
function T2DArray_Create(const size1D, size2D: Integer; const item: TBox): T2DBoxArray; overload; cdecl;
function T2DArray_Create(const size1D, size2D: Integer; const item: TRange): T2DRangeArray; overload; cdecl;

function T2DArray_Empty(const arr: T2DIntegerArray): Boolean; overload; cdecl;
function T2DArray_Empty(const arr: T2DDoubleArray): Boolean; overload; cdecl;
function T2DArray_Empty(const arr: T2DStringArray): Boolean; overload; cdecl;
function T2DArray_Empty(const arr: T2DCharArray): Boolean; overload; cdecl;
function T2DArray_Empty(const arr: T2DBooleanArray): Boolean; overload; cdecl;
function T2DArray_Empty(const arr: T2DPointArray): Boolean; overload; cdecl;
function T2DArray_Empty(const arr: T2DBoxArray): Boolean; overload; cdecl;
function T2DArray_Empty(const arr: T2DRangeArray): Boolean; overload; cdecl;

function T2DArray_Length(const arr: T2DIntegerArray; var lengths: TIntegerArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DDoubleArray; var lengths: TIntegerArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DStringArray; var lengths: TIntegerArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DCharArray; var lengths: TIntegerArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DBooleanArray; var lengths: TIntegerArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DPointArray; var lengths: TIntegerArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DBoxArray; var lengths: TIntegerArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DRangeArray; var lengths: TIntegerArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DIntegerArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DDoubleArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DStringArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DCharArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DBooleanArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DPointArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DBoxArray): Int64; overload; cdecl;
function T2DArray_Length(const arr: T2DRangeArray): Int64; overload; cdecl;

function T2DArray_Merge(const arr: T2DIntegerArray): TIntegerArray; overload; cdecl;
function T2DArray_Merge(const arr: T2DDoubleArray): TDoubleArray; overload; cdecl;
function T2DArray_Merge(const arr: T2DStringArray): TStringArray; overload; cdecl;
function T2DArray_Merge(const arr: T2DCharArray): TCharArray; overload; cdecl;
function T2DArray_Merge(const arr: T2DBooleanArray): TBooleanArray; overload; cdecl;
function T2DArray_Merge(const arr: T2DPointArray): TPointArray; overload; cdecl;
function T2DArray_Merge(const arr: T2DBoxArray): TBoxArray; overload; cdecl;
function T2DArray_Merge(const arr: T2DRangeArray): TRangeArray; overload; cdecl;
  
implementation

operator+(const a, b: TPoint): TPoint;
begin
  Result.X := (a.X + b.X);
  Result.X := (a.Y + b.Y);
end;

operator+(const a, b: TBox): TBox;
begin
  Result.X1 := (a.X1 + b.X1);
  Result.Y1 := (a.Y1 + b.Y1);
  Result.X2 := (a.X2 + b.X2);
  Result.Y2 := (a.Y2 + b.Y2);
end;

operator+(const a, b: TRange): TRange;
begin
  Result.start := (a.start + b.start);
  Result.stop := (a.stop + b.stop);
end;

operator-(const a, b: TPoint): TPoint;
begin
  Result.X := (a.X - b.X);
  Result.Y := (a.Y - b.Y);
end;

operator-(const a, b: TBox): TBox;
begin
  Result.X1 := (a.X1 - b.X1);
  Result.Y1 := (a.Y1 - b.Y1);
  Result.X2 := (a.X2 - b.X2);
  Result.Y2 := (a.Y2 - b.Y2);
end;

operator-(const a, b: TRange): TRange;
begin
  Result.start := (a.start - b.start);
  Result.stop := (a.stop - b.stop);
end;

operator=(const a, b: TPoint): Boolean;
begin
  Result := ((a.X = b.X) and (a.Y = b.Y));
end;

operator=(const a, b: TBox): Boolean;
begin
  Result := ((a.X1 = b.X1) and (a.Y1 = b.Y1) and (a.X2 = b.X2) and (a.Y2 = b.Y2));
end;

operator=(const a, b: TRange): Boolean;
begin
  Result := ((a.start = b.start) and (a.stop = b.stop));
end;

operator<>(const a, b: TPoint): Boolean;
begin
  Result := not ((a.X = b.X) and (a.Y = b.Y));
end;

operator<>(const a, b: TBox): Boolean;
begin
  Result := not ((a.X1 = b.X1) and (a.Y1 = b.Y1) and (a.X2 = b.X2) and (a.Y2 = b.Y2));
end;

operator<>(const a, b: TRange): Boolean;
begin
  Result := not ((a.start = b.start) and (a.stop = b.stop));
end;  

procedure Swap(var A, B: Integer); overload; inline;
var
  T: Integer;
begin
  T := A;
  A := B;
  B := T;
end;

procedure Swap(var A, B: Int64); overload; inline;
var
  T: Int64;
begin
  T := A;
  A := B;
  B := T;
end;

procedure Swap(var A, B: Double); overload; inline;
var
  T: Double;
begin
  T := A;
  A := B;
  B := T;
end;

procedure Swap(var A, B: string); overload; inline;
var
  T: string;
begin
  T := A;
  A := B;
  B := T;
end;

procedure Swap(var A, B: Char); overload; inline;
var
  T: Char;
begin
  T := A;
  A := B;
  B := T;
end;

procedure Swap(var A, B: Boolean); overload; inline;
var
  T: Boolean;
begin
  T := A;
  A := B;
  B := T;
end;

procedure Swap(var A, B: TPoint); overload; inline;
var
  T: TPoint;
begin
  T := A;
  A := B;
  B := T;
end;

procedure Swap(var A, B: TBox); overload; inline;
var
  T: TBox;
begin
  T := A;
  A := B;
  B := T;
end;

procedure Swap(var A, B: TRange); overload; inline;
var
  T: TRange;
begin
  T := A;
  A := B;
  B := T;
end;

{$I MiMU\Double.inc}
{$I MiMU\Integer.inc}
{$I MiMU\Int64.inc}
{$I MiMU\String.inc}
{$I MiMU\Boolean.inc}
{$I MiMU\TPoint.inc}
{$I MiMU\TBox.inc}
{$I MiMU\TRange.inc}
{$I MiMU\TIntegerArray.inc}
{$I MiMU\TPointArray.inc}
{$I MiMU\TRangeArray.inc}

{$DEFINE TArray_Add1}
function TArray_Add(const arr: TIntegerArray; const item: Integer): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Add(const arr: TDoubleArray; const item: Double): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Add(const arr: TStringArray; const item: string): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Add(const arr: TCharArray; const item: Char): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Add(const arr: TBooleanArray; const item: Boolean): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Add(const arr: TPointArray; const item: TPoint): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Add(const arr: TBoxArray; const item: TBox): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Add(const arr: TRangeArray; const item: TRange): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Add1}

{$DEFINE TArray_Add2}
function TArray_Add(const arr: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Add(const arr: TDoubleArray; const items: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Add(const arr: TStringArray; const items: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Add(const arr: TCharArray; const items: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Add(const arr: TBooleanArray; const items: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Add(const arr: TPointArray; const items: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Add(const arr: TBoxArray; const items: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Add(const arr: TRangeArray; const items: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Add2}

{$DEFINE TArray_AllEqual}
function TArray_AllEqual(const arr: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllEqual(const arr: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllEqual(const arr: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllEqual(const arr: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllEqual(const arr: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllEqual(const arr: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllEqual(const arr: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllEqual(const arr: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_AllEqual}

{$DEFINE TArray_AllSame}
function TArray_AllSame(const arr: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllSame(const arr: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllSame(const arr: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllSame(const arr: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllSame(const arr: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllSame(const arr: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllSame(const arr: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllSame(const arr: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_AllSame}

{$DEFINE TArray_AllUnique}
function TArray_AllUnique(const arr: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllUnique(const arr: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllUnique(const arr: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllUnique(const arr: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllUnique(const arr: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllUnique(const arr: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllUnique(const arr: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_AllUnique(const arr: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_AllUnique}

{$DEFINE TArray_Append1}
function TArray_Append(var arr: TIntegerArray; const item: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Append(var arr: TDoubleArray; const item: Double): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Append(var arr: TStringArray; const item: string): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Append(var arr: TCharArray; const item: Char): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Append(var arr: TBooleanArray; const item: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Append(var arr: TPointArray; const item: TPoint): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Append(var arr: TBoxArray; const item: TBox): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Append(var arr: TRangeArray; const item: TRange): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Append1}

{$DEFINE TArray_Append2}
function TArray_Append(var arr: TIntegerArray; const items: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Append(var arr: TDoubleArray; const items: TDoubleArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Append(var arr: TStringArray; const items: TStringArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Append(var arr: TCharArray; const items: TCharArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Append(var arr: TBooleanArray; const items: TBooleanArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Append(var arr: TPointArray; const items: TPointArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Append(var arr: TBoxArray; const items: TBoxArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Append(var arr: TRangeArray; const items: TRangeArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Append2}

{$DEFINE TArray_Build}
function TArray_Build(const item: Integer; const size: Integer = 1): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Build(const item: Double; const size: Integer = 1): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Build(const item: string; const size: Integer = 1): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Build(const item: Char; const size: Integer = 1): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Build(const item: Boolean; const size: Integer = 1): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Build(const item: TPoint; const size: Integer = 1): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Build(const item: TBox; const size: Integer = 1): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Build(const item: TRange; const size: Integer = 1): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Build}

{$DEFINE TArray_BuiltWith}
function TArray_BuiltWith(const arr, allowed: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_BuiltWith(const arr, allowed: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_BuiltWith(const arr, allowed: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_BuiltWith(const arr, allowed: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_BuiltWith(const arr, allowed: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_BuiltWith(const arr, allowed: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_BuiltWith(const arr, allowed: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_BuiltWith(const arr, allowed: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_BuiltWith}

{$DEFINE TArray_BuiltWithout}
function TArray_BuiltWithout(const arr, forbidden: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_BuiltWithout(const arr, forbidden: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_BuiltWithout(const arr, forbidden: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_BuiltWithout(const arr, forbidden: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_BuiltWithout(const arr, forbidden: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_BuiltWithout(const arr, forbidden: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_BuiltWithout(const arr, forbidden: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_BuiltWithout(const arr, forbidden: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_BuiltWithout}

{$DEFINE TArray_Clone}
function TArray_Clone(const arr: TIntegerArray; const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Clone(const arr: TDoubleArray; const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Clone(const arr: TStringArray; const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Clone(const arr: TCharArray; const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Clone(const arr: TBooleanArray; const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Clone(const arr: TPointArray; const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Clone(const arr: TBoxArray; const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Clone(const arr: TRangeArray; const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Clone}

{$DEFINE TArray_Combine}
function TArray_Combine(const a, b: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Combine(const a, b: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Combine(const a, b: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Combine(const a, b: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Combine(const a, b: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Combine(const a, b: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Combine(const a, b: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Combine(const a, b: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Combine}

{$DEFINE TArray_Contains}
function TArray_Contains(const arr: TIntegerArray; const item: Integer; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Contains(const arr: TDoubleArray; const item: Double; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Contains(const arr: TStringArray; const item: string; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Contains(const arr: TCharArray; const item: Char; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Contains(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Contains(const arr: TPointArray; const item: TPoint; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Contains(const arr: TBoxArray; const item: TBox; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Contains(const arr: TRangeArray; const item: TRange; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Contains}

{$DEFINE TArray_Copy1}
function TArray_Copy(const arr: TIntegerArray; const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Copy(const arr: TDoubleArray; const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Copy(const arr: TStringArray; const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Copy(const arr: TCharArray; const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Copy(const arr: TBooleanArray; const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Copy(const arr: TPointArray; const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Copy(const arr: TBoxArray; const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Copy(const arr: TRangeArray; const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Copy1}

{$DEFINE TArray_Copy2}
function TArray_Copy(const arr: TIntegerArray; const IDs: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Copy(const arr: TDoubleArray; const IDs: TIntegerArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Copy(const arr: TStringArray; const IDs: TIntegerArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Copy(const arr: TCharArray; const IDs: TIntegerArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Copy(const arr: TBooleanArray; const IDs: TIntegerArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Copy(const arr: TPointArray; const IDs: TIntegerArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Copy(const arr: TBoxArray; const IDs: TIntegerArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Copy(const arr: TRangeArray; const IDs: TIntegerArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Copy2}

{$DEFINE TArray_Create1}
function TArray_Create(const item: Integer): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Create(const item: Double): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Create(const item: string): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Create(const item: Char): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Create(const item: Boolean): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Create(const item: TPoint): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Create(const item: TBox): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Create(const item: TRange): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Create1}

{$DEFINE TArray_Create2}
function TArray_Create(const size: Integer; const item: Integer): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Create(const size: Integer; const item: Double): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Create(const size: Integer; const item: string): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Create(const size: Integer; const item: Char): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Create(const size: Integer; const item: Boolean): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Create(const size: Integer; const item: TPoint): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Create(const size: Integer; const item: TBox): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Create(const size: Integer; const item: TRange): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Create2}

{$DEFINE TArray_Delete1}
function TArray_Delete(var arr: TIntegerArray; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Delete(var arr: TDoubleArray; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Delete(var arr: TStringArray; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Delete(var arr: TCharArray; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Delete(var arr: TBooleanArray; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Delete(var arr: TPointArray; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Delete(var arr: TBoxArray; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Delete(var arr: TRangeArray; const index: Integer = 0): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Delete1}

{$DEFINE TArray_Delete2}
function TArray_Delete(var arr: TIntegerArray; const IDs: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Delete(var arr: TDoubleArray; const IDs: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Delete(var arr: TStringArray; const IDs: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Delete(var arr: TCharArray; const IDs: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Delete(var arr: TBooleanArray; const IDs: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Delete(var arr: TPointArray; const IDs: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Delete(var arr: TBoxArray; const IDs: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Delete(var arr: TRangeArray; const IDs: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Delete2}

{$DEFINE TArray_Differ}
function TArray_Differ(const arr, target: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Differ(const arr, target: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Differ(const arr, target: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Differ(const arr, target: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Differ(const arr, target: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Differ(const arr, target: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Differ(const arr, target: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Differ(const arr, target: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Differ}

{$DEFINE TArray_Distribute}
function TArray_Distribute(const arr: TIntegerArray; const parts: Integer): T2DIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Distribute(const arr: TDoubleArray; const parts: Integer): T2DDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Distribute(const arr: TStringArray; const parts: Integer): T2DStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Distribute(const arr: TCharArray; const parts: Integer): T2DCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Distribute(const arr: TBooleanArray; const parts: Integer): T2DBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Distribute(const arr: TPointArray; const parts: Integer): T2DPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Distribute(const arr: TBoxArray; const parts: Integer): T2DBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Distribute(const arr: TRangeArray; const parts: Integer): T2DRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Distribute}

{$DEFINE TArray_Dump}
function TArray_Dump(var arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Dump(var arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Dump(var arr: TStringArray; const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Dump(var arr: TCharArray; const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Dump(var arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Dump(var arr: TPointArray; const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Dump(var arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Dump(var arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Dump}

{$DEFINE TArray_Dupe}
function TArray_Dupe(const arr: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Dupe(const arr: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Dupe(const arr: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Dupe(const arr: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Dupe(const arr: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Dupe(const arr: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Dupe(const arr: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Dupe(const arr: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Dupe}

{$DEFINE TArray_Empty}
function TArray_Empty(const arr: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Empty(const arr: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Empty(const arr: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Empty(const arr: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Empty(const arr: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Empty(const arr: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Empty(const arr: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Empty(const arr: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Empty}

{$DEFINE TArray_Equal}
function TArray_Equal(const arr, target: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Equal(const arr, target: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Equal(const arr, target: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Equal(const arr, target: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Equal(const arr, target: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Equal(const arr, target: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Equal(const arr, target: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Equal(const arr, target: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Equal}

{$DEFINE TArray_Extend1}
function TArray_Extend(const arr: TIntegerArray; const item: Integer): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extend(const arr: TDoubleArray; const item: Double): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extend(const arr: TStringArray; const item: string): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extend(const arr: TCharArray; const item: Char): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extend(const arr: TBooleanArray; const item: Boolean): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extend(const arr: TPointArray; const item: TPoint): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extend(const arr: TBoxArray; const item: TBox): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extend(const arr: TRangeArray; const item: TRange): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Extend1}

{$DEFINE TArray_Extend2}
function TArray_Extend(const arr: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extend(const arr: TDoubleArray; const items: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extend(const arr: TStringArray; const items: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extend(const arr: TCharArray; const items: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extend(const arr: TBooleanArray; const items: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extend(const arr: TPointArray; const items: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extend(const arr: TBoxArray; const items: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extend(const arr: TRangeArray; const items: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Extend2}

{$DEFINE TArray_Extract1}
function TArray_Extract(const arr: TIntegerArray; const item: Integer; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extract(const arr: TDoubleArray; const item: Double; const index: Integer = 0): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extract(const arr: TStringArray; const item: string; const index: Integer = 0): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extract(const arr: TCharArray; const item: Char; const index: Integer = 0): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extract(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extract(const arr: TPointArray; const item: TPoint; const index: Integer = 0): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extract(const arr: TBoxArray; const item: TBox; const index: Integer = 0): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extract(const arr: TRangeArray; const item: TRange; const index: Integer = 0): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Extract1}

{$DEFINE TArray_Extract2}
function TArray_Extract(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extract(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extract(const arr: TStringArray; const items: TStringArray; const index: Integer = 0): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extract(const arr: TCharArray; const items: TCharArray; const index: Integer = 0): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extract(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extract(const arr: TPointArray; const items: TPointArray; const index: Integer = 0): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extract(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Extract(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Extract2}

{$DEFINE TArray_ExtractEvery}
function TArray_ExtractEvery(const arr: TIntegerArray; const X: Integer = 1; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_ExtractEvery(const arr: TDoubleArray; const X: Integer = 1; const index: Integer = 0): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_ExtractEvery(const arr: TStringArray; const X: Integer = 1; const index: Integer = 0): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_ExtractEvery(const arr: TCharArray; const X: Integer = 1; const index: Integer = 0): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_ExtractEvery(const arr: TBooleanArray; const X: Integer = 1; const index: Integer = 0): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_ExtractEvery(const arr: TPointArray; const X: Integer = 1; const index: Integer = 0): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_ExtractEvery(const arr: TBoxArray; const X: Integer = 1; const index: Integer = 0): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_ExtractEvery(const arr: TRangeArray; const X: Integer = 1; const index: Integer = 0): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_ExtractEvery}

{$DEFINE TArray_Fill1}
function TArray_Fill(const arr: TIntegerArray; const item: Integer; const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Fill(const arr: TDoubleArray; const item: Double; const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Fill(const arr: TStringArray; const item: string; const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Fill(const arr: TCharArray; const item: Char; const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Fill(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Fill(const arr: TPointArray; const item: TPoint; const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Fill(const arr: TBoxArray; const item: TBox; const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Fill(const arr: TRangeArray; const item: TRange; const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Fill1}

{$DEFINE TArray_Fill2}
function TArray_Fill(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Fill(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Fill(const arr: TStringArray; const items: TStringArray; const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Fill(const arr: TCharArray; const items: TCharArray; const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Fill(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Fill(const arr: TPointArray; const items: TPointArray; const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Fill(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Fill(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Fill2}

{$DEFINE TArray_Filter1}
function TArray_Filter(const arr: TIntegerArray; const item: Integer; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Filter(const arr: TDoubleArray; const item: Double; const index: Integer = 0): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Filter(const arr: TStringArray; const item: string; const index: Integer = 0): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Filter(const arr: TCharArray; const item: Char; const index: Integer = 0): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Filter(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Filter(const arr: TPointArray; const item: TPoint; const index: Integer = 0): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Filter(const arr: TBoxArray; const item: TBox; const index: Integer = 0): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Filter(const arr: TRangeArray; const item: TRange; const index: Integer = 0): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Filter1}

{$DEFINE TArray_Filter2}
function TArray_Filter(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Filter(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Filter(const arr: TStringArray; const items: TStringArray; const index: Integer = 0): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Filter(const arr: TCharArray; const items: TCharArray; const index: Integer = 0): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Filter(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Filter(const arr: TPointArray; const items: TPointArray; const index: Integer = 0): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Filter(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Filter(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Filter2}

{$DEFINE TArray_FilterEvery}
function TArray_FilterEvery(const arr: TIntegerArray; const X: Integer = 1; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_FilterEvery(const arr: TDoubleArray; const X: Integer = 1; const index: Integer = 0): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_FilterEvery(const arr: TStringArray; const X: Integer = 1; const index: Integer = 0): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_FilterEvery(const arr: TCharArray; const X: Integer = 1; const index: Integer = 0): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_FilterEvery(const arr: TBooleanArray; const X: Integer = 1; const index: Integer = 0): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_FilterEvery(const arr: TPointArray; const X: Integer = 1; const index: Integer = 0): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_FilterEvery(const arr: TBoxArray; const X: Integer = 1; const index: Integer = 0): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_FilterEvery(const arr: TRangeArray; const X: Integer = 1; const index: Integer = 0): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_FilterEvery}

{$DEFINE TArray_Flip}
function TArray_Flip(var arr: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Flip(var arr: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Flip(var arr: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Flip(var arr: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Flip(var arr: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Flip(var arr: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Flip(var arr: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Flip(var arr: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Flip}

{$DEFINE TArray_Get1}
function TArray_Get(const arr: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Get(const arr: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Get(const arr: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Get(const arr: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Get(const arr: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Get(const arr: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Get(const arr: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Get(const arr: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Get1}

{$DEFINE TArray_Get2}
function TArray_Get(const arr: TIntegerArray; const IDs: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Get(const arr: TDoubleArray; const IDs: TIntegerArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Get(const arr: TStringArray; const IDs: TIntegerArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Get(const arr: TCharArray; const IDs: TIntegerArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Get(const arr: TBooleanArray; const IDs: TIntegerArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Get(const arr: TPointArray; const IDs: TIntegerArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Get(const arr: TBoxArray; const IDs: TIntegerArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Get(const arr: TRangeArray; const IDs: TIntegerArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Get2}

{$DEFINE TArray_Group}
function TArray_Group(const arr: TIntegerArray): T2DIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Group(const arr: TDoubleArray): T2DDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Group(const arr: TStringArray): T2DStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Group(const arr: TCharArray): T2DCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Group(const arr: TBooleanArray): T2DBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Group(const arr: TPointArray): T2DPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Group(const arr: TBoxArray): T2DBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Group(const arr: TRangeArray): T2DRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Group}

{$DEFINE TArray_Holds}
function TArray_Holds(const arr, chain: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Holds(const arr, chain: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Holds(const arr, chain: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Holds(const arr, chain: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Holds(const arr, chain: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Holds(const arr, chain: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Holds(const arr, chain: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Holds(const arr, chain: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Holds}

{$DEFINE TArray_IDs1}
function TArray_IDs(const arr: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TDoubleArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TStringArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TCharArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TBooleanArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TPointArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TBoxArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TRangeArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_IDs1}

{$DEFINE TArray_IDs2}
function TArray_IDs(const arr: TIntegerArray; const IDs: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TDoubleArray; const IDs: TIntegerArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TStringArray; const IDs: TIntegerArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TCharArray; const IDs: TIntegerArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TBooleanArray; const IDs: TIntegerArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TPointArray; const IDs: TIntegerArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TBoxArray; const IDs: TIntegerArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TRangeArray; const IDs: TIntegerArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_IDs2}

{$DEFINE TArray_IDs3}
function TArray_IDs(const arr: TIntegerArray; const IDs: TIntegerArray; const item: Integer): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TDoubleArray; const IDs: TIntegerArray; const item: Double): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TStringArray; const IDs: TIntegerArray; const item: string): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TCharArray; const IDs: TIntegerArray; const item: Char): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TBooleanArray; const IDs: TIntegerArray; const item: Boolean): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TPointArray; const IDs: TIntegerArray; const item: TPoint): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TBoxArray; const IDs: TIntegerArray; const item: TBox): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TRangeArray; const IDs: TIntegerArray; const item: TRange): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_IDs3}

{$DEFINE TArray_IDs4}
function TArray_IDs(const arr: TIntegerArray; const IDs: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TDoubleArray; const IDs: TIntegerArray; const items: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TStringArray; const IDs: TIntegerArray; const items: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TCharArray; const IDs: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TBooleanArray; const IDs: TIntegerArray; const items: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TPointArray; const IDs: TIntegerArray; const items: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TBoxArray; const IDs: TIntegerArray; const items: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_IDs(const arr: TRangeArray; const IDs: TIntegerArray; const items: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_IDs4}

{$DEFINE TArray_Includes}
function TArray_Includes(const arr: TIntegerArray; const item: Integer; const index: Integer = 2147483647): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Includes(const arr: TDoubleArray; const item: Double; const index: Integer = 2147483647): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Includes(const arr: TStringArray; const item: string; const index: Integer = 2147483647): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Includes(const arr: TCharArray; const item: Char; const index: Integer = 2147483647): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Includes(const arr: TBooleanArray; const item: Boolean; const index: Integer = 2147483647): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Includes(const arr: TPointArray; const item: TPoint; const index: Integer = 2147483647): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Includes(const arr: TBoxArray; const item: TBox; const index: Integer = 2147483647): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Includes(const arr: TRangeArray; const item: TRange; const index: Integer = 2147483647): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Includes}

{$DEFINE TArray_Keep}
function TArray_Keep(var arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Keep(var arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Keep(var arr: TStringArray; const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Keep(var arr: TCharArray; const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Keep(var arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Keep(var arr: TPointArray; const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Keep(var arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Keep(var arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Keep}

{$DEFINE TArray_LeastFrequent}
function TArray_LeastFrequent(const arr: TIntegerArray): Integer; cdecl; overload; {$I MIMU\TArray.inc}
function TArray_LeastFrequent(const arr: TDoubleArray): Double; cdecl; overload; {$I MIMU\TArray.inc}
function TArray_LeastFrequent(const arr: TStringArray): string; cdecl; overload; {$I MIMU\TArray.inc}
function TArray_LeastFrequent(const arr: TCharArray): Char; cdecl; overload; {$I MIMU\TArray.inc}
function TArray_LeastFrequent(const arr: TBooleanArray): Boolean; cdecl; overload; {$I MIMU\TArray.inc}
function TArray_LeastFrequent(const arr: TPointArray): TPoint; cdecl; overload; {$I MIMU\TArray.inc}
function TArray_LeastFrequent(const arr: TBoxArray): TBox; cdecl; overload; {$I MIMU\TArray.inc}
function TArray_LeastFrequent(const arr: TRangeArray): TRange; cdecl; overload; {$I MIMU\TArray.inc}
{$UNDEF TArray_LeastFrequent}

{$DEFINE TArray_MostFrequent}
function TArray_MostFrequent(const arr: TIntegerArray): Integer; cdecl; overload; {$I MIMU\TArray.inc}
function TArray_MostFrequent(const arr: TDoubleArray): Double; cdecl; overload; {$I MIMU\TArray.inc}
function TArray_MostFrequent(const arr: TStringArray): string; cdecl; overload; {$I MIMU\TArray.inc}
function TArray_MostFrequent(const arr: TCharArray): Char; cdecl; overload; {$I MIMU\TArray.inc}
function TArray_MostFrequent(const arr: TBooleanArray): Boolean; cdecl; overload; {$I MIMU\TArray.inc}
function TArray_MostFrequent(const arr: TPointArray): TPoint; cdecl; overload; {$I MIMU\TArray.inc}
function TArray_MostFrequent(const arr: TBoxArray): TBox; cdecl; overload; {$I MIMU\TArray.inc}
function TArray_MostFrequent(const arr: TRangeArray): TRange; cdecl; overload; {$I MIMU\TArray.inc}
{$UNDEF TArray_MostFrequent}

{$DEFINE TArray_Move}
function TArray_Move(var arr: TIntegerArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: Integer; {$I MIMU\TArray.inc}
function TArray_Move(var arr: TDoubleArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: Double; {$I MIMU\TArray.inc}
function TArray_Move(var arr: TStringArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: string; {$I MIMU\TArray.inc}
function TArray_Move(var arr: TCharArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: Char; {$I MIMU\TArray.inc}
function TArray_Move(var arr: TBooleanArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: Boolean; {$I MIMU\TArray.inc}
function TArray_Move(var arr: TPointArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: TPoint; {$I MIMU\TArray.inc}
function TArray_Move(var arr: TBoxArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: TBox; {$I MIMU\TArray.inc}
function TArray_Move(var arr: TRangeArray; oldIndex, newIndex: Integer): Boolean; overload; cdecl; var t: TRange; {$I MIMU\TArray.inc}
{$UNDEF TArray_Move}

{$DEFINE TArray_Oversize}
function TArray_Oversize(const arr: TIntegerArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Oversize(const arr: TDoubleArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Oversize(const arr: TStringArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Oversize(const arr: TCharArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Oversize(const arr: TBooleanArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Oversize(const arr: TPointArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Oversize(const arr: TBoxArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Oversize(const arr: TRangeArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Oversize}

{$DEFINE TArray_Partition}
function TArray_Partition(const arr: TIntegerArray; const size: Integer): T2DIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Partition(const arr: TDoubleArray; const size: Integer): T2DDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Partition(const arr: TStringArray; const size: Integer): T2DStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Partition(const arr: TCharArray; const size: Integer): T2DCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Partition(const arr: TBooleanArray; const size: Integer): T2DBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Partition(const arr: TPointArray; const size: Integer): T2DPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Partition(const arr: TBoxArray; const size: Integer): T2DBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Partition(const arr: TRangeArray; const size: Integer): T2DRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Partition}

{$DEFINE TArray_Pick}
function TArray_Pick(var arr: TIntegerArray; const IDs: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pick(var arr: TDoubleArray; const IDs: TIntegerArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pick(var arr: TStringArray; const IDs: TIntegerArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pick(var arr: TCharArray; const IDs: TIntegerArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pick(var arr: TBooleanArray; const IDs: TIntegerArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pick(var arr: TPointArray; const IDs: TIntegerArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pick(var arr: TBoxArray; const IDs: TIntegerArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pick(var arr: TRangeArray; const IDs: TIntegerArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Pick}

{$DEFINE TArray_Pop1}
function TArray_Pop(var arr: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pop(var arr: TDoubleArray): Double; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pop(var arr: TStringArray): string; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pop(var arr: TCharArray): Char; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pop(var arr: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pop(var arr: TPointArray): TPoint; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pop(var arr: TBoxArray): TBox; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pop(var arr: TRangeArray): TRange; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Pop1}

{$DEFINE TArray_Pop2}
function TArray_Pop(var arr: TIntegerArray; const null: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pop(var arr: TDoubleArray; const null: Double): Double; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pop(var arr: TStringArray; const null: string): string; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pop(var arr: TCharArray; const null: Char): Char; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pop(var arr: TBooleanArray; const null: Boolean): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pop(var arr: TPointArray; const null: TPoint): TPoint; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pop(var arr: TBoxArray; const null: TBox): TBox; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pop(var arr: TRangeArray; const null: TRange): TRange; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Pop2}

{$DEFINE TArray_Pos1}
function TArray_Pos(const arr: TIntegerArray; const item: Integer; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TDoubleArray; const item: Double; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TStringArray; const item: string; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TCharArray; const item: Char; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TPointArray; const item: TPoint; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TBoxArray; const item: TBox; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TRangeArray; const item: TRange; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Pos1}

{$DEFINE TArray_Pos2}
function TArray_Pos(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TStringArray; const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TCharArray; const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TPointArray; const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Pos(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Pos2}

{$DEFINE TArray_Position1}
function TArray_Position(const arr: TIntegerArray; const item: Integer; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Position(const arr: TDoubleArray; const item: Double; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Position(const arr: TStringArray; const item: string; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Position(const arr: TCharArray; const item: Char; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Position(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Position(const arr: TPointArray; const item: TPoint; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Position(const arr: TBoxArray; const item: TBox; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Position(const arr: TRangeArray; const item: TRange; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Position1}

{$DEFINE TArray_Position2}
function TArray_Position(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Position(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Position(const arr: TStringArray; const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Position(const arr: TCharArray; const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Position(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Position(const arr: TPointArray; const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Position(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Position(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Position2}

{$DEFINE TArray_Positions1}
function TArray_Positions(const arr: TIntegerArray; const item: Integer; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Positions(const arr: TDoubleArray; const item: Double; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Positions(const arr: TStringArray; const item: string; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Positions(const arr: TCharArray; const item: Char; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Positions(const arr: TBooleanArray; const item: Boolean; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Positions(const arr: TPointArray; const item: TPoint; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Positions(const arr: TBoxArray; const item: TBox; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Positions(const arr: TRangeArray; const item: TRange; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Positions1}

{$DEFINE TArray_Positions2}
function TArray_Positions(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Positions(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Positions(const arr: TStringArray; const items: TStringArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Positions(const arr: TCharArray; const items: TCharArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Positions(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Positions(const arr: TPointArray; const items: TPointArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Positions(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Positions(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Positions2}

{$DEFINE TArray_PosLast1}
function TArray_PosLast(const arr: TIntegerArray; const item: Integer; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLast(const arr: TDoubleArray; const item: Double; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLast(const arr: TStringArray; const item: string; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLast(const arr: TCharArray; const item: Char; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLast(const arr: TBooleanArray; const item: Boolean; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLast(const arr: TPointArray; const item: TPoint; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLast(const arr: TBoxArray; const item: TBox; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLast(const arr: TRangeArray; const item: TRange; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_PosLast1}

{$DEFINE TArray_PosLast2}
function TArray_PosLast(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLast(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLast(const arr: TStringArray; const items: TStringArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLast(const arr: TCharArray; const items: TCharArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLast(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLast(const arr: TPointArray; const items: TPointArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLast(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLast(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 2147483647): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_PosLast2}

{$DEFINE TArray_PosLasts1}
function TArray_PosLasts(const arr: TIntegerArray; const item: Integer; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLasts(const arr: TDoubleArray; const item: Double; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLasts(const arr: TStringArray; const item: string; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLasts(const arr: TCharArray; const item: Char; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLasts(const arr: TBooleanArray; const item: Boolean; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLasts(const arr: TPointArray; const item: TPoint; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLasts(const arr: TBoxArray; const item: TBox; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLasts(const arr: TRangeArray; const item: TRange; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_PosLasts1}

{$DEFINE TArray_PosLasts2}
function TArray_PosLasts(const arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLasts(const arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLasts(const arr: TStringArray; const items: TStringArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLasts(const arr: TCharArray; const items: TCharArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLasts(const arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLasts(const arr: TPointArray; const items: TPointArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLasts(const arr: TBoxArray; const items: TBoxArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_PosLasts(const arr: TRangeArray; const items: TRangeArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_PosLasts2}

{$DEFINE TArray_Push1}
function TArray_Push(var arr: TIntegerArray; const item: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Push(var arr: TDoubleArray; const item: Double): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Push(var arr: TStringArray; const item: string): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Push(var arr: TCharArray; const item: Char): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Push(var arr: TBooleanArray; const item: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Push(var arr: TPointArray; const item: TPoint): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Push(var arr: TBoxArray; const item: TBox): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Push(var arr: TRangeArray; const item: TRange): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Push1}

{$DEFINE TArray_Push2}
function TArray_Push(var arr: TIntegerArray; const items: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Push(var arr: TDoubleArray; const items: TDoubleArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Push(var arr: TStringArray; const items: TStringArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Push(var arr: TCharArray; const items: TCharArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Push(var arr: TBooleanArray; const items: TBooleanArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Push(var arr: TPointArray; const items: TPointArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Push(var arr: TBoxArray; const items: TBoxArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Push(var arr: TRangeArray; const items: TRangeArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Push2}

{$DEFINE TArray_Randomize}
function TArray_Randomize(var arr: TIntegerArray; const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Randomize(var arr: TDoubleArray; const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Randomize(var arr: TStringArray; const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Randomize(var arr: TCharArray; const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Randomize(var arr: TBooleanArray; const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Randomize(var arr: TPointArray; const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Randomize(var arr: TBoxArray; const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Randomize(var arr: TRangeArray; const shuffles: Integer = 1): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Randomize}

{$DEFINE TArray_Remove1}
function TArray_Remove(var arr: TIntegerArray; const item: Integer; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TDoubleArray; const item: Double; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TStringArray; const item: string; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TCharArray; const item: Char; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TBooleanArray; const item: Boolean; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TPointArray; const item: TPoint; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TBoxArray; const item: TBox; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TRangeArray; const item: TRange; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Remove1}

{$DEFINE TArray_Remove2}
function TArray_Remove(var arr: TIntegerArray; const item: Integer; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TDoubleArray; const item: Double; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TStringArray; const item: string; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TCharArray; const item: Char; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TBooleanArray; const item: Boolean; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TPointArray; const item: TPoint; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TBoxArray; const item: TBox; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TRangeArray; const item: TRange; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Remove2}

{$DEFINE TArray_Remove3}
function TArray_Remove(var arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TStringArray; const items: TStringArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TCharArray; const items: TCharArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TPointArray; const items: TPointArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TBoxArray; const items: TBoxArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TRangeArray; const items: TRangeArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Remove3}

{$DEFINE TArray_Remove4}
function TArray_Remove(var arr: TIntegerArray; const items: TIntegerArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TDoubleArray; const items: TDoubleArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TStringArray; const items: TStringArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TCharArray; const items: TCharArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TBooleanArray; const items: TBooleanArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TPointArray; const items: TPointArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TBoxArray; const items: TBoxArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Remove(var arr: TRangeArray; const items: TRangeArray; const all: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Remove4}

{$DEFINE TArray_Reverse}
function TArray_Reverse(var arr: TIntegerArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Reverse(var arr: TDoubleArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Reverse(var arr: TStringArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Reverse(var arr: TCharArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Reverse(var arr: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Reverse(var arr: TPointArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Reverse(var arr: TBoxArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Reverse(var arr: TRangeArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Reverse}

{$DEFINE TArray_Reversed}
function TArray_Reversed(const arr: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Reversed(const arr: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Reversed(const arr: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Reversed(const arr: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Reversed(const arr: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Reversed(const arr: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Reversed(const arr: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Reversed(const arr: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Reversed}

{$DEFINE TArray_Set1}
function TArray_Set(const arr: TIntegerArray; const IDs: TIntegerArray; const item: Integer): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TDoubleArray; const IDs: TIntegerArray; const item: Double): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TStringArray; const IDs: TIntegerArray; const item: string): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TCharArray; const IDs: TIntegerArray; const item: Char): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TBooleanArray; const IDs: TIntegerArray; const item: Boolean): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TPointArray; const IDs: TIntegerArray; const item: TPoint): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TBoxArray; const IDs: TIntegerArray; const item: TBox): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TRangeArray; const IDs: TIntegerArray; const item: TRange): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Set1}

{$DEFINE TArray_Set2}
function TArray_Set(const arr: TIntegerArray; const IDs: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TDoubleArray; const IDs: TIntegerArray; const items: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TStringArray; const IDs: TIntegerArray; const items: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TCharArray; const IDs: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TBooleanArray; const IDs: TIntegerArray; const items: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TPointArray; const IDs: TIntegerArray; const items: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TBoxArray; const IDs: TIntegerArray; const items: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TRangeArray; const IDs: TIntegerArray; const items: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Set2}

{$DEFINE TArray_Set3}
function TArray_Set(const arr: TIntegerArray; const index: Integer; const items: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TDoubleArray; const index: Integer; const items: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TStringArray; const index: Integer; const items: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TCharArray; const index: Integer; const items: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TBooleanArray; const index: Integer; const items: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TPointArray; const index: Integer; const items: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TBoxArray; const index: Integer; const items: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Set(const arr: TRangeArray; const index: Integer; const items: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Set3}

{$DEFINE TArray_Shift1}
function TArray_Shift(var arr: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Shift(var arr: TDoubleArray): Double; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Shift(var arr: TStringArray): string; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Shift(var arr: TCharArray): Char; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Shift(var arr: TBooleanArray): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Shift(var arr: TPointArray): TPoint; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Shift(var arr: TBoxArray): TBox; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Shift(var arr: TRangeArray): TRange; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Shift1}

{$DEFINE TArray_Shift2}
function TArray_Shift(var arr: TIntegerArray; const shift: Integer): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Shift(var arr: TDoubleArray; const shift: Integer): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Shift(var arr: TStringArray; const shift: Integer): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Shift(var arr: TCharArray; const shift: Integer): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Shift(var arr: TBooleanArray; const shift: Integer): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Shift(var arr: TPointArray; const shift: Integer): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Shift(var arr: TBoxArray; const shift: Integer): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Shift(var arr: TRangeArray; const shift: Integer): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Shift2}

{$DEFINE TArray_Size1}
function TArray_Size(var arr: TIntegerArray; const size: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(var arr: TDoubleArray; const size: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(var arr: TStringArray; const size: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(var arr: TCharArray; const size: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(var arr: TBooleanArray; const size: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(var arr: TPointArray; const size: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(var arr: TBoxArray; const size: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(var arr: TRangeArray; const size: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Size1}

{$DEFINE TArray_Size2}
function TArray_Size(var arr: TIntegerArray; const size: Integer; const null: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(var arr: TDoubleArray; const size: Integer; const null: Double): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(var arr: TStringArray; const size: Integer; const null: string): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(var arr: TCharArray; const size: Integer; const null: Char): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(var arr: TBooleanArray; const size: Integer; const null: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(var arr: TPointArray; const size: Integer; const null: TPoint): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(var arr: TBoxArray; const size: Integer; const null: TBox): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(var arr: TRangeArray; const size: Integer; const null: TRange): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Size2}

{$DEFINE TArray_Size3}
function TArray_Size(const arr: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(const arr: TDoubleArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(const arr: TStringArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(const arr: TCharArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(const arr: TBooleanArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(const arr: TPointArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(const arr: TBoxArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Size(const arr: TRangeArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Size3}

{$DEFINE TArray_SizeBetween}
function TArray_SizeBetween(const arr: TIntegerArray; const x, y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeBetween(const arr: TDoubleArray; const x, y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeBetween(const arr: TStringArray; const x, y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeBetween(const arr: TCharArray; const x, y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeBetween(const arr: TBooleanArray; const x, y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeBetween(const arr: TPointArray; const x, y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeBetween(const arr: TBoxArray; const x, y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeBetween(const arr: TRangeArray; const x, y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_SizeBetween}

{$DEFINE TArray_SizeMax}
function TArray_SizeMax(const arr: TIntegerArray; const y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeMax(const arr: TDoubleArray; const y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeMax(const arr: TStringArray; const y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeMax(const arr: TCharArray; const y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeMax(const arr: TBooleanArray; const y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeMax(const arr: TPointArray; const y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeMax(const arr: TBoxArray; const y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeMax(const arr: TRangeArray; const y: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_SizeMax}

{$DEFINE TArray_SizeMin}
function TArray_SizeMin(const arr: TIntegerArray; const x: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeMin(const arr: TDoubleArray; const x: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeMin(const arr: TStringArray; const x: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeMin(const arr: TCharArray; const x: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeMin(const arr: TBooleanArray; const x: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeMin(const arr: TPointArray; const x: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeMin(const arr: TBoxArray; const x: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_SizeMin(const arr: TRangeArray; const x: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_SizeMin}

{$DEFINE TArray_Swap}
function TArray_Swap(var a, b: TIntegerArray): Integer; overload; cdecl; var c: TIntegerArray; {$I MIMU\TArray.inc}
function TArray_Swap(var a, b: TDoubleArray): Integer; overload; cdecl; var c: TDoubleArray; {$I MIMU\TArray.inc}
function TArray_Swap(var a, b: TStringArray): Integer; overload; cdecl; var c: TStringArray; {$I MIMU\TArray.inc}
function TArray_Swap(var a, b: TCharArray): Integer; overload; cdecl; var c: TCharArray; {$I MIMU\TArray.inc}
function TArray_Swap(var a, b: TBooleanArray): Integer; overload; cdecl; var c: TBooleanArray; {$I MIMU\TArray.inc}
function TArray_Swap(var a, b: TPointArray): Integer; overload; cdecl; var c: TPointArray; {$I MIMU\TArray.inc}
function TArray_Swap(var a, b: TBoxArray): Integer; overload; cdecl; var c: TBoxArray; {$I MIMU\TArray.inc}
function TArray_Swap(var a, b: TRangeArray): Integer; overload; cdecl; var c: TRangeArray; {$I MIMU\TArray.inc}
{$UNDEF TArray_Swap}

{$DEFINE TArray_Trade}
function TArray_Trade(var a, b: TIntegerArray): Integer; overload; cdecl; var c: TIntegerArray; {$I MIMU\TArray.inc}
function TArray_Trade(var a, b: TDoubleArray): Integer; overload; cdecl; var c: TDoubleArray; {$I MIMU\TArray.inc}
function TArray_Trade(var a, b: TStringArray): Integer; overload; cdecl; var c: TStringArray; {$I MIMU\TArray.inc}
function TArray_Trade(var a, b: TCharArray): Integer; overload; cdecl; var c: TCharArray; {$I MIMU\TArray.inc}
function TArray_Trade(var a, b: TBooleanArray): Integer; overload; cdecl; var c: TBooleanArray; {$I MIMU\TArray.inc}
function TArray_Trade(var a, b: TPointArray): Integer; overload; cdecl; var c: TPointArray; {$I MIMU\TArray.inc}
function TArray_Trade(var a, b: TBoxArray): Integer; overload; cdecl; var c: TBoxArray; {$I MIMU\TArray.inc}
function TArray_Trade(var a, b: TRangeArray): Integer; overload; cdecl; var c: TRangeArray; {$I MIMU\TArray.inc}
{$UNDEF TArray_Trade}

{$DEFINE TArray_Undersize}
function TArray_Undersize(const arr: TIntegerArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Undersize(const arr: TDoubleArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Undersize(const arr: TStringArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Undersize(const arr: TCharArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Undersize(const arr: TBooleanArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Undersize(const arr: TPointArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Undersize(const arr: TBoxArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Undersize(const arr: TRangeArray; const limit: Integer): Boolean; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Undersize}

{$DEFINE TArray_Unique}
function TArray_Unique(var arr: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unique(var arr: TDoubleArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unique(var arr: TStringArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unique(var arr: TCharArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unique(var arr: TBooleanArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unique(var arr: TPointArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unique(var arr: TBoxArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unique(var arr: TRangeArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Unique}

{$DEFINE TArray_Uniqued}
function TArray_Uniqued(const arr: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Uniqued(const arr: TDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Uniqued(const arr: TStringArray): TStringArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Uniqued(const arr: TCharArray): TCharArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Uniqued(const arr: TBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Uniqued(const arr: TPointArray): TPointArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Uniqued(const arr: TBoxArray): TBoxArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Uniqued(const arr: TRangeArray): TRangeArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Uniqued}

{$DEFINE TArray_Uniques}
function TArray_Uniques(const arr: TIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Uniques(const arr: TDoubleArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Uniques(const arr: TStringArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Uniques(const arr: TCharArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Uniques(const arr: TBooleanArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Uniques(const arr: TPointArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Uniques(const arr: TBoxArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Uniques(const arr: TRangeArray): TIntegerArray; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Uniques}

{$DEFINE TArray_Unshift1}
function TArray_Unshift(var arr: TIntegerArray; const item: Integer): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unshift(var arr: TDoubleArray; const item: Double): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unshift(var arr: TStringArray; const item: string): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unshift(var arr: TCharArray; const item: Char): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unshift(var arr: TBooleanArray; const item: Boolean): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unshift(var arr: TPointArray; const item: TPoint): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unshift(var arr: TBoxArray; const item: TBox): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unshift(var arr: TRangeArray; const item: TRange): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Unshift1}

{$DEFINE TArray_Unshift2}
function TArray_Unshift(var arr: TIntegerArray; const items: TIntegerArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unshift(var arr: TDoubleArray; const items: TDoubleArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unshift(var arr: TStringArray; const items: TStringArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unshift(var arr: TCharArray; const items: TCharArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unshift(var arr: TBooleanArray; const items: TBooleanArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unshift(var arr: TPointArray; const items: TPointArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unshift(var arr: TBoxArray; const items: TBoxArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
function TArray_Unshift(var arr: TRangeArray; const items: TRangeArray): Integer; overload; cdecl; {$I MIMU\TArray.inc}
{$UNDEF TArray_Unshift2}

{$DEFINE T2DArray_Blank}
function T2DArray_Blank(const arr: T2DIntegerArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Blank(const arr: T2DDoubleArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Blank(const arr: T2DStringArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Blank(const arr: T2DCharArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Blank(const arr: T2DBooleanArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Blank(const arr: T2DPointArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Blank(const arr: T2DBoxArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Blank(const arr: T2DRangeArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
{$UNDEF T2DArray_Blank}

{$DEFINE T2DArray_Create}
function T2DArray_Create(const size1D, size2D: Integer; const item: Integer): T2DIntegerArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Create(const size1D, size2D: Integer; const item: Double): T2DDoubleArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Create(const size1D, size2D: Integer; const item: string): T2DStringArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Create(const size1D, size2D: Integer; const item: Char): T2DCharArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Create(const size1D, size2D: Integer; const item: Boolean): T2DBooleanArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Create(const size1D, size2D: Integer; const item: TPoint): T2DPointArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Create(const size1D, size2D: Integer; const item: TBox): T2DBoxArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Create(const size1D, size2D: Integer; const item: TRange): T2DRangeArray; overload; cdecl; {$I MIMU\T2DArray.inc}
{$UNDEF T2DArray_Create}

{$DEFINE T2DArray_Empty}
function T2DArray_Empty(const arr: T2DIntegerArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Empty(const arr: T2DDoubleArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Empty(const arr: T2DStringArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Empty(const arr: T2DCharArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Empty(const arr: T2DBooleanArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Empty(const arr: T2DPointArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Empty(const arr: T2DBoxArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Empty(const arr: T2DRangeArray): Boolean; overload; cdecl; {$I MIMU\T2DArray.inc}
{$UNDEF T2DArray_Empty}

{$DEFINE T2DArray_Length1}
function T2DArray_Length(const arr: T2DIntegerArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DDoubleArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DStringArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DCharArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DBooleanArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DPointArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DBoxArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DRangeArray; var lengths: TIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
{$UNDEF T2DArray_Length1}

{$DEFINE T2DArray_Length2}
function T2DArray_Length(const arr: T2DIntegerArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DDoubleArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DStringArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DCharArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DBooleanArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DPointArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DBoxArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Length(const arr: T2DRangeArray): Int64; overload; cdecl; {$I MIMU\T2DArray.inc}
{$UNDEF T2DArray_Length2}

{$DEFINE T2DArray_Merge}
function T2DArray_Merge(const arr: T2DIntegerArray): TIntegerArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Merge(const arr: T2DDoubleArray): TDoubleArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Merge(const arr: T2DStringArray): TStringArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Merge(const arr: T2DCharArray): TCharArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Merge(const arr: T2DBooleanArray): TBooleanArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Merge(const arr: T2DPointArray): TPointArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Merge(const arr: T2DBoxArray): TBoxArray; overload; cdecl; {$I MIMU\T2DArray.inc}
function T2DArray_Merge(const arr: T2DRangeArray): TRangeArray; overload; cdecl; {$I MIMU\T2DArray.inc}
{$UNDEF T2DArray_Merge}

initialization

finalization

end.
