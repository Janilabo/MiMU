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
 (v0.1}
 
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
  TIntegerArray = array of Int32;
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
    X, Y: Int32;
  end;
  TPointArray = array of TPoint;
  T2DPointArray = array of TPointArray;
  TBox = record
    X1, Y1, X2, Y2: Int32;
  end;
  TBoxArray = array of TBox;
  T2DBoxArray = array of TBoxArray;
  TRange = record
    start, stop: Int32;
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

procedure Swap(var A, B: Int32); overload; inline;
procedure Swap(var A, B: Int64); overload; inline;
procedure Swap(var A, B: Double); overload; inline;
procedure Swap(var A, B: string); overload; inline;
procedure Swap(var A, B: Char); overload; inline;
procedure Swap(var A, B: Boolean); overload; inline;
procedure Swap(var A, B: TPoint); overload; inline;
procedure Swap(var A, B: TBox); overload; inline;
procedure Swap(var A, B: TRange); overload; inline;

function Int32_Even(const x: Int32): Boolean; cdecl; inline;
function Int32_Odd(const x: Int32): Boolean; cdecl; inline;
function Int32_Inc(var x: Int32; const N: Int32 = 1): Int32; cdecl; inline;
function Int32_Dec(var x: Int32; const N: Int32 = 1): Int32; cdecl;
function Int32_Increase(var x: Int32; const N: Int32 = 1): Int32; cdecl; inline;
function Int32_Decrease(var x: Int32; const N: Int32 = 1): Int32; cdecl;
function Int32_DigitCount(const x: Int32): Int32; cdecl;
function Int32_Digitz(const x: Int32): TIntegerArray; cdecl;
function Int32_Digits(const x: Int32): TIntegerArray; cdecl;
function Int32_NegA(const x: Int32): Int32; cdecl; inline;
function Int32_Neg(const x: Int32): Int32; cdecl; inline;
function Int32_Negative(const x: Int32): Boolean; cdecl; inline;
function Int32_Positive(const x: Int32): Boolean; cdecl; inline;
function Int32_Neutral(const x: Int32): Boolean; cdecl; inline;
function Int32_Compare(const x, T: Int32): Int32; cdecl; inline;
function Int32_Distance(const x, T: Int32): Int32; cdecl; inline;
function Int32_Difference(const x, T: Int32): Int32; cdecl; inline;
function Int32_Opposite(const x: Int32): Int32; cdecl; inline;
function Int32_Sign(const x: Int32): Int32; cdecl; inline;
function Int32_Random(const range: Int32): Int32; cdecl;
function Int32_Oversize(const x, limit: Int32): Boolean; cdecl; inline;
function Int32_Undersize(const x, limit: Int32): Boolean; cdecl; inline;

function Int64_Even(const x: Int64): Boolean; cdecl; inline;
function Int64_Odd(const x: Int64): Boolean; cdecl; inline;
function Int64_Inc(var x: Int64; const N: Int64 = 1): Int64; cdecl; inline;
function Int64_Dec(var x: Int64; const N: Int64 = 1): Int64; cdecl;
function Int64_Increase(var x: Int64; const N: Int64 = 1): Int64; cdecl; inline;
function Int64_Decrease(var x: Int64; const N: Int64 = 1): Int64; cdecl;
function Int64_DigitCount(const x: Int64): Int32; cdecl;
function Int64_Digitz(const x: Int64): TIntegerArray; cdecl;
function Int64_Digits(const x: Int64): TIntegerArray; cdecl;
function Int64_Compare(const x, T: Int64): Int32; cdecl; inline;
function Int64_Distance(const x, T: Int64): Int64; cdecl; inline;
function Int64_Difference(const x, T: Int64): Int64; cdecl; inline;
function Int64_Opposite(const x: Int64): Int64; cdecl; inline;
function Int64_Sign(const x: Int64): Int32; cdecl; inline;
function Int64_Random(const range: Int64): Int64; cdecl;
function Int64_Oversize(const x, limit: Int64): Boolean; cdecl; inline;
function Int64_Undersize(const x, limit: Int64): Boolean; cdecl; inline;

function Double_Inc(var x: Double; const N: Double = 1): Double; cdecl; inline;
function Double_Dec(var x: Double; const N: Double = 1): Double; cdecl;
function Double_Increase(var x: Double; const N: Double = 1): Double; cdecl; inline;
function Double_Decrease(var x: Double; const N: Double = 1): Double; cdecl;
function Double_Digits(const x: Double): TIntegerArray; cdecl;
function Double_NegA(const x: Double): Double; cdecl; inline;
function Double_Neg(const x: Double): Double; cdecl; inline;
function Double_Negative(const x: Double): Boolean; cdecl; inline;
function Double_Positive(const x: Double): Boolean; cdecl; inline;
function Double_Neutral(const x: Double): Boolean; cdecl; inline;
function Double_MinDecimal(const x: Double): Double; cdecl;
function Double_MaxDecimal(const x: Double): Double; cdecl;
function Double_Copy(const x: Double; const a: Int32): Double; cdecl;
function Double_Compare(const x, T: Double): Int32; cdecl; inline;
function Double_Distance(const x, T: Double): Double; cdecl; inline;
function Double_Difference(const x, T: Double): Double; cdecl; inline;
function Double_Opposite(const x: Double): Double; cdecl; inline;
function Double_Sign(const x: Double): Int32; cdecl; inline;
function Double_FixDegrees(const dgrs: Double): Double; cdecl;
function Double_Degrees(const rdns: Double): Double; cdecl;
function Double_FixRadians(const rdns: Double): Double; cdecl;
function Double_Radians(const dgrs: Double; const compass: Boolean = False): Double; cdecl;
function Double_Percent(const source, position: Double): Double; cdecl; inline;
function Double_Percentage(const source, percent: Double): Double; cdecl; inline;
function Double_Oversize(const x, limit: Double): Boolean; cdecl;
function Double_Undersize(const x, limit: Double): Boolean; cdecl;

function String_At(const str, s: string; const index: Int32 = 1): Boolean; cdecl; inline;
function String_Get(const str: string; const index, size: Int32): string; cdecl; inline;
function String_Pos(const str, s: string; const offset: Int32 = 0): Int32; cdecl;
function String_PosLast(const str, s: string; const offset: Int32 = -1): Int32; cdecl;
function String_Position(const str, s: string; const offset: Int32 = 0): Int32; cdecl;
function String_Between(const str, s1, s2: string; const offset: Int32 = 0): string; cdecl;
function String_Count(const str, s: string; const overlap: Boolean = True): Int32; cdecl;
function String_FromLeft(const str: string; const x: Int32): string; cdecl;
function String_FromRight(const str: string; const x: Int32): string; cdecl;
function String_Explode(const str, d: string; const limit: Int32 = -1): TStringArray; cdecl;
function String_Exploded(const str: string; const d: TStringArray; const limit: Int32 = -1): TStringArray; cdecl;
function String_Slice(const str: string; const a, b: Int32): string; cdecl;
function String_Chunk(const str: string; const a, b: Int32): string; cdecl;
function String_Reverse(var str: string): Boolean; cdecl;
function String_Flip(const str: string): string; cdecl;
function String_Reversed(const str: string): string; cdecl;
function String_StartsWith(const str, s: string): Boolean; cdecl;
function String_EndsWith(const str, s: string): Boolean; cdecl;
function String_Begin(var str: string; const s: string; const offset: Int32 = 0): Boolean; cdecl;
function String_End(var str: string; const s: string; const offset: Int32 = -1): Boolean; cdecl;
function String_Behind(const str: string; const position, size: Int32): string; cdecl;
function String_Ahead(const str: string; const position, size: Int32): string; cdecl;
function String_After(const str, s: string; offset: Int32 = -1): string; cdecl;
function String_Before(const str, s: string; offset: Int32 = -1): string; cdecl;
function String_AfterLast(const str, s: string; const offset: Int32 = -1): string; cdecl;
function String_BeforeLast(const str, s: string; const offset: Int32 = -1): string; cdecl;
function String_Center(const str: string; const size: Int32; const fill: Char = #32): string; cdecl;
function String_Stuff(const str, s: string; const iFrom, iCount: Integer): string; cdecl;
function String_Duplicate(const str: string; const count: Int32 = 2): string; cdecl;
function String_Duplicated(const str: string; const count: Int32; const glue: string): string; cdecl;
function String_Compare(const str, T: string): Int32; cdecl; inline;
function String_Quotatation(const str: string): string; cdecl;
function String_PregQuote(const str: string; const regex: string = '.\+*?[^]$(){}=!<>|:-'): string; cdecl;
function String_TrimLeft(const str: string; const t: Char = #32): string; cdecl;
function String_TrimRight(const str: string; const t: Char = #32): string; cdecl;
function String_Trim(const str: string; const t: Char = #32): string; cdecl;

function Boolean_Random: Boolean; cdecl; inline;

function TPoint_To(const X, Y: Int32): TPoint; cdecl; inline;
function TPoint_At(const X, Y: Int32): TPoint; cdecl; inline;
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
function TPoint_Grid(const pt: TPoint; const rows, columns: Int32; const spaceVertical: Int32 = 0; const spaceHorizontal: Int32 = 0): TPointArray; cdecl;
function TPoint_Row(const pt: TPoint; const cells: Int32; const space: Int32 = 0): TPointArray; cdecl;
function TPoint_Column(const pt: TPoint; const cells: Int32; const space: Int32 = 0): TPointArray; cdecl;

function TBox_Build(const X1, Y1, X2, Y2: Int32): TBox; overload; cdecl;
function TBox_Build(const a, b: TPoint): TBox; overload; cdecl;
function TBox_Create(const X1, Y1, X2, Y2: Int32): TBox; overload; cdecl;
function TBox_Create(const a, b: TPoint): TBox; overload; cdecl;
function TBox_Form(const XY: Int32 = 0): TBox; overload; cdecl;
function TBox_Form(const XY: TPoint): TBox; overload; cdecl;
function TBox_At(const pt: TPoint; const radius: Int32 = 0): TBox; overload; cdecl;
function TBox_At(const pt: TPoint; const wRadius, hRadius: Int32): TBox; overload; cdecl;
function TBox_To(const pt: TPoint; const size: Int32 = 1): TBox; overload; cdecl;
function TBox_To(const pt: TPoint; const width, height: Int32): TBox; overload; cdecl;
function TBox_Size(const bx: TBox; var width, height: Int32): Int32; cdecl; inline;
function TBox_Area(const bx: TBox): Int32; cdecl; inline;
function TBox_Diagonal(const bx: TBox): Double; cdecl;
function TBox_W(const bx: TBox): Int32; overload; cdecl;
function TBox_W(var bx: TBox; const width: Int32): Int32; overload; cdecl;
function TBox_Width(const bx: TBox): Int32; overload; cdecl;
function TBox_Width(var bx: TBox; const width: Int32): Int32; overload; cdecl;
function TBox_H(const bx: TBox): Int32; overload; cdecl;
function TBox_H(var bx: TBox; const height: Int32): Int32; overload; cdecl;
function TBox_Height(const bx: TBox): Int32; overload; cdecl;
function TBox_Height(var bx: TBox; const height: Int32): Int32; overload; cdecl;
function TBox_Expand(const bx: TBox; const change: Int32 = 1): TBox; cdecl;
function TBox_Shrink(const bx: TBox; const change: Int32 = 1): TBox; cdecl;
function TBox_Resize(const bx: TBox; const change: Int32): TBox; cdecl;
function TBox_ResizeVertically(const bx: TBox; const change: Int32): TBox; cdecl;
function TBox_ResizeHorizontally(const bx: TBox; const change: Int32): TBox; cdecl;
function TBox_ResizeTop(const bx: TBox; const change: Int32): TBox; cdecl;
function TBox_ResizeBottom(const bx: TBox; const change: Int32): TBox; cdecl;
function TBox_ResizeLeft(const bx: TBox; const change: Int32): TBox; cdecl;
function TBox_ResizeRight(const bx: TBox; const change: Int32): TBox; cdecl;
function TBox_ResizeTopLeft(const bx: TBox; const change: Int32): TBox; cdecl;
function TBox_ResizeTopRight(const bx: TBox; const change: Int32): TBox; cdecl;
function TBox_ResizeBottomRight(const bx: TBox; const change: Int32): TBox; cdecl;
function TBox_ResizeBottomLeft(const bx: TBox; const change: Int32): TBox; cdecl;
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
function TBox_Similar(const a, b: TBox; const maxWDiff, maxHDiff: Int32): Boolean; overload; cdecl;
function TBox_Similar(const a, b: TBox; const diff: Int32): Boolean; overload; cdecl;
function TBox_Fix(var bx: TBox): Boolean; cdecl;
function TBox_Constraint(var bx: TBox; const area: TBox): Boolean; cdecl;
function TBox_Clip(const bx: TBox; const area: TBox): TBox; cdecl;
function TBox_Restrict(var bx: TBox; const area: TBox): Boolean; cdecl;
function TBox_Clamp(const bx, area: TBox): TBox; cdecl;
function TBox_Points(const bx: TBox): TPointArray; cdecl;
function TBox_TPointArray(const bx: TBox): TPointArray; cdecl;
function TBox_Grid(const bx: TBox; const rows, columns: Int32; const spaceVertical: Int32 = 0; const spaceHorizontal: Int32 = 0): TBoxArray; cdecl;
function TBox_Row(const bx: TBox; const cells: Int32; const space: Int32 = 0): TBoxArray; cdecl;
function TBox_Column(const bx: TBox; const cells: Int32; const space: Int32 = 0): TBoxArray; cdecl;
function TBox_CornerPoints(const bx: TBox): TPointArray; cdecl;
function TBox_Corners(const bx: TBox): TPointArray; cdecl;
function TBox_SimilarSize(const a, b: TBox; const widthDifferency, heightDifferency: Int32): Boolean; overload; cdecl;
function TBox_SimilarSize(const a, b: TBox; const differency: Integer): Boolean; overload; cdecl;
function TBox_Centered(const bx, area: TBox): TBox; cdecl;
function TBox_CenterVertically(const bx, area: TBox): TBox; cdecl;
function TBox_CenterHorizontally(const bx, area: TBox): TBox; cdecl;

function TRange_Neutral(const range: TRange): Boolean; cdecl;
function TRange_Ascending(const range: TRange): Boolean; cdecl;
function TRange_Descending(const range: TRange): Boolean; cdecl;
function TRange_Create(const start: Int32 = 0; const stop: Int32 = 0): TRange; cdecl;
function TRange_Build(const start: Int32 = 0; const stop: Int32 = 0): TRange; cdecl;
function TRange_Grab(const range: TRange): TRange; cdecl;
function TRange_Size(const range: TRange): Int32; cdecl;
function TRange_Length(const range: TRange): Int32; cdecl;
function TRange_Min(const range: TRange): Int32; cdecl;
function TRange_Minimum(const range: TRange): Int32; cdecl;
function TRange_Max(const range: TRange): Int32; cdecl;
function TRange_Maximum(const range: TRange): Int32; cdecl;
function TRange_Digits(const range: TRange): TIntegerArray; cdecl;
function TRange_Ints(const range: TRange): TIntegerArray; cdecl;
function TRange_TIntegerArray(const range: TRange): TIntegerArray; cdecl;
function TRange_Normalize(const range: TRange): TRange; cdecl;
function TRange_Overlapping(const a, b: TRange): Boolean; cdecl;
function TRange_Overlap(const a, b: TRange): Boolean; cdecl;
function TRange_Intersection(const a, b: TRange; const null: TRange): TRange; cdecl;
function TRange_Intersect(const a, b: TRange; var intersection: TRange): Boolean; cdecl;
function TRange_Union(const a, b: TRange): TRange; cdecl;
function TRange_Shift(const range: TRange; const delta: Int32): TRange; cdecl;
function TRange_Contains(const range: TRange; const x: Int32): Boolean; overload; cdecl;
function TRange_Contains(const range, x: TRange): Boolean; overload; cdecl;
function TRange_Reversed(const range: TRange): TRange; cdecl;
function TRange_Reverse(var range: TRange): Boolean; cdecl;
function TRange_Equals(const a, b: TRange): Boolean; cdecl;
function TRange_Differs(const a, b: TRange): Boolean; cdecl;
function TRange_Equal(const a, b: TRange): Boolean; cdecl;
function TRange_Differ(const a, b: TRange): Boolean; cdecl;
function TRange_Clamp(const range, zone: TRange): TRange; cdecl;
function TRange_ClampMax(const range: TRange; const maximum: Int32): TRange; cdecl;
function TRange_ClampMin(const range: TRange; const minimum: Int32): TRange; cdecl;
function TRange_Restrict(var range: TRange; const zone: TRange): Boolean; cdecl;
function TRange_RestrictMin(var range: TRange; const minimum: Int32): Boolean; cdecl;
function TRange_RestrictMax(var range: TRange; const maximum: Int32): Boolean; cdecl;
function TRange_Clip(const range, zone: TRange): TRange;
function TRange_ClipMin(const range: TRange; minimum: Int32): TRange;
function TRange_ClipMax(const range: TRange; maximum: Int32): TRange;
function TRange_Distribute(const range: TRange; const parts: Int32): TRangeArray; cdecl;
function TRange_Partition(const range: TRange; const size: Int32): TRangeArray; cdecl;
function TRange_Divide(const range: TRange; const size: Int32): TRangeArray; cdecl;
function TRange_Touch(const a, b: TRange): Boolean; cdecl;
function TRange_Touches(const a, b: TRange): Boolean; cdecl;
function TRange_Distance(const a, b: TRange): Int32; cdecl;
function TRange_DistHausdorff(const a, b: TRange): Int32; cdecl;
function TRange_Digit(const range: TRange; const x: Int32): Boolean; cdecl; inline;
function TRange_Value(const range: TRange; const x: Int32): Boolean; cdecl; inline;

function TPointArray_Bounds(const arr: TPointArray): TBox; cdecl;
function TPointArray_Unique(var arr: TPointArray): Int32; cdecl;
function TPointArray_Uniqued(const arr: TPointArray): TPointArray; cdecl;
function TPointArray_Invert(const arr: TPointArray): TPointArray; cdecl;
function TPointArray_Edge(const arr: TPointArray; const scan8W: Boolean = False): TPointArray; cdecl;
function TPointArray_FloodFill(const arr: TPointArray; const start: TPoint; const area: TBox; const scan8W: Boolean = False): TPointArray; overload; cdecl;
function TPointArray_FloodFill(const arr: TPointArray; const start: TPoint; const scan8W: Boolean = False): TPointArray; overload; cdecl;

function TArray_Add(const arr: TIntegerArray; const item: Int32): TIntegerArray; overload; cdecl;
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

function TArray_Append(var arr: TIntegerArray; const item: Int32): Int32; overload; cdecl;
function TArray_Append(var arr: TDoubleArray; const item: Double): Int32; overload; cdecl;
function TArray_Append(var arr: TStringArray; const item: string): Int32; overload; cdecl;
function TArray_Append(var arr: TCharArray; const item: Char): Int32; overload; cdecl;
function TArray_Append(var arr: TBooleanArray; const item: Boolean): Int32; overload; cdecl;
function TArray_Append(var arr: TPointArray; const item: TPoint): Int32; overload; cdecl;
function TArray_Append(var arr: TBoxArray; const item: TBox): Int32; overload; cdecl;
function TArray_Append(var arr: TRangeArray; const item: TRange): Int32; overload; cdecl;
function TArray_Append(var arr: TIntegerArray; const items: TIntegerArray): Int32; overload; cdecl;
function TArray_Append(var arr: TDoubleArray; const items: TDoubleArray): Int32; overload; cdecl;
function TArray_Append(var arr: TStringArray; const items: TStringArray): Int32; overload; cdecl;
function TArray_Append(var arr: TCharArray; const items: TCharArray): Int32; overload; cdecl;
function TArray_Append(var arr: TBooleanArray; const items: TBooleanArray): Int32; overload; cdecl;
function TArray_Append(var arr: TPointArray; const items: TPointArray): Int32; overload; cdecl;
function TArray_Append(var arr: TBoxArray; const items: TBoxArray): Int32; overload; cdecl;
function TArray_Append(var arr: TRangeArray; const items: TRangeArray): Int32; overload; cdecl;

function TArray_Build(const item: Int32; const size: Int32 = 1): TIntegerArray; overload; cdecl;
function TArray_Build(const item: Double; const size: Int32 = 1): TDoubleArray; overload; cdecl;
function TArray_Build(const item: string; const size: Int32 = 1): TStringArray; overload; cdecl;
function TArray_Build(const item: Char; const size: Int32 = 1): TCharArray; overload; cdecl;
function TArray_Build(const item: Boolean; const size: Int32 = 1): TBooleanArray; overload; cdecl;
function TArray_Build(const item: TPoint; const size: Int32 = 1): TPointArray; overload; cdecl;
function TArray_Build(const item: TBox; const size: Int32 = 1): TBoxArray; overload; cdecl;
function TArray_Build(const item: TRange; const size: Int32 = 1): TRangeArray; overload; cdecl;

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

function TArray_Clone(const arr: TIntegerArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Clone(const arr: TDoubleArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TDoubleArray; overload; cdecl;
function TArray_Clone(const arr: TStringArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TStringArray; overload; cdecl;
function TArray_Clone(const arr: TCharArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TCharArray; overload; cdecl;
function TArray_Clone(const arr: TBooleanArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TBooleanArray; overload; cdecl;
function TArray_Clone(const arr: TPointArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TPointArray; overload; cdecl;
function TArray_Clone(const arr: TBoxArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TBoxArray; overload; cdecl;
function TArray_Clone(const arr: TRangeArray; const startIndex: Int32 = 0; const count: Int32 = 2147483647): TRangeArray; overload; cdecl;

function TArray_Combine(const a, b: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Combine(const a, b: TDoubleArray): TDoubleArray; overload; cdecl;
function TArray_Combine(const a, b: TStringArray): TStringArray; overload; cdecl;
function TArray_Combine(const a, b: TCharArray): TCharArray; overload; cdecl;
function TArray_Combine(const a, b: TBooleanArray): TBooleanArray; overload; cdecl;
function TArray_Combine(const a, b: TPointArray): TPointArray; overload; cdecl;
function TArray_Combine(const a, b: TBoxArray): TBoxArray; overload; cdecl;
function TArray_Combine(const a, b: TRangeArray): TRangeArray; overload; cdecl;

function TArray_Contains(const arr: TIntegerArray; const item: Int32; const start: Int32 = 0): Boolean; overload; cdecl;
function TArray_Contains(const arr: TDoubleArray; const item: Double; const start: Int32 = 0): Boolean; overload; cdecl;
function TArray_Contains(const arr: TStringArray; const item: string; const start: Int32 = 0): Boolean; overload; cdecl;
function TArray_Contains(const arr: TCharArray; const item: Char; const start: Int32 = 0): Boolean; overload; cdecl;
function TArray_Contains(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 0): Boolean; overload; cdecl;
function TArray_Contains(const arr: TPointArray; const item: TPoint; const start: Int32 = 0): Boolean; overload; cdecl;
function TArray_Contains(const arr: TBoxArray; const item: TBox; const start: Int32 = 0): Boolean; overload; cdecl;
function TArray_Contains(const arr: TRangeArray; const item: TRange; const start: Int32 = 0): Boolean; overload; cdecl;

function TArray_Copy(const arr: TIntegerArray; const index: Int32 = 0; const count: Int32 = -1): TIntegerArray; overload; cdecl;
function TArray_Copy(const arr: TDoubleArray; const index: Int32 = 0; const count: Int32 = -1): TDoubleArray; overload; cdecl;
function TArray_Copy(const arr: TStringArray; const index: Int32 = 0; const count: Int32 = -1): TStringArray; overload; cdecl;
function TArray_Copy(const arr: TCharArray; const index: Int32 = 0; const count: Int32 = -1): TCharArray; overload; cdecl;
function TArray_Copy(const arr: TBooleanArray; const index: Int32 = 0; const count: Int32 = -1): TBooleanArray; overload; cdecl;
function TArray_Copy(const arr: TPointArray; const index: Int32 = 0; const count: Int32 = -1): TPointArray; overload; cdecl;
function TArray_Copy(const arr: TBoxArray; const index: Int32 = 0; const count: Int32 = -1): TBoxArray; overload; cdecl;
function TArray_Copy(const arr: TRangeArray; const index: Int32 = 0; const count: Int32 = -1): TRangeArray; overload; cdecl;
function TArray_Copy(const arr: TIntegerArray; const IDs: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Copy(const arr: TDoubleArray; const IDs: TIntegerArray): TDoubleArray; overload; cdecl;
function TArray_Copy(const arr: TStringArray; const IDs: TIntegerArray): TStringArray; overload; cdecl;
function TArray_Copy(const arr: TCharArray; const IDs: TIntegerArray): TCharArray; overload; cdecl;
function TArray_Copy(const arr: TBooleanArray; const IDs: TIntegerArray): TBooleanArray; overload; cdecl;
function TArray_Copy(const arr: TPointArray; const IDs: TIntegerArray): TPointArray; overload; cdecl;
function TArray_Copy(const arr: TBoxArray; const IDs: TIntegerArray): TBoxArray; overload; cdecl;
function TArray_Copy(const arr: TRangeArray; const IDs: TIntegerArray): TRangeArray; overload; cdecl;

function TArray_Create(const size: Int32; const item: Int32): TIntegerArray; overload; cdecl;
function TArray_Create(const size: Int32; const item: Double): TDoubleArray; overload; cdecl;
function TArray_Create(const size: Int32; const item: string): TStringArray; overload; cdecl;
function TArray_Create(const size: Int32; const item: Char): TCharArray; overload; cdecl;
function TArray_Create(const size: Int32; const item: Boolean): TBooleanArray; overload; cdecl;
function TArray_Create(const size: Int32; const item: TPoint): TPointArray; overload; cdecl;
function TArray_Create(const size: Int32; const item: TBox): TBoxArray; overload; cdecl;
function TArray_Create(const size: Int32; const item: TRange): TRangeArray; overload; cdecl;

function TArray_Delete(var arr: TIntegerArray; const index: Int32 = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TDoubleArray; const index: Int32 = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TStringArray; const index: Int32 = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TCharArray; const index: Int32 = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TBooleanArray; const index: Int32 = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TPointArray; const index: Int32 = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TBoxArray; const index: Int32 = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TRangeArray; const index: Int32 = 0): Boolean; overload; cdecl;
function TArray_Delete(var arr: TIntegerArray; const IDs: TIntegerArray): Int32; overload; cdecl;
function TArray_Delete(var arr: TDoubleArray; const IDs: TIntegerArray): Int32; overload; cdecl;
function TArray_Delete(var arr: TStringArray; const IDs: TIntegerArray): Int32; overload; cdecl;
function TArray_Delete(var arr: TCharArray; const IDs: TIntegerArray): Int32; overload; cdecl;
function TArray_Delete(var arr: TBooleanArray; const IDs: TIntegerArray): Int32; overload; cdecl;
function TArray_Delete(var arr: TPointArray; const IDs: TIntegerArray): Int32; overload; cdecl;
function TArray_Delete(var arr: TBoxArray; const IDs: TIntegerArray): Int32; overload; cdecl;
function TArray_Delete(var arr: TRangeArray; const IDs: TIntegerArray): Int32; overload; cdecl;

function TArray_Differ(const arr, target: TIntegerArray): Boolean; overload; cdecl;
function TArray_Differ(const arr, target: TDoubleArray): Boolean; overload; cdecl;
function TArray_Differ(const arr, target: TStringArray): Boolean; overload; cdecl;
function TArray_Differ(const arr, target: TCharArray): Boolean; overload; cdecl;
function TArray_Differ(const arr, target: TBooleanArray): Boolean; overload; cdecl;
function TArray_Differ(const arr, target: TPointArray): Boolean; overload; cdecl;
function TArray_Differ(const arr, target: TBoxArray): Boolean; overload; cdecl;
function TArray_Differ(const arr, target: TRangeArray): Boolean; overload; cdecl;

function TArray_Distribute(const arr: TIntegerArray; const parts: Int32): T2DIntegerArray; overload; cdecl;
function TArray_Distribute(const arr: TDoubleArray; const parts: Int32): T2DDoubleArray; overload; cdecl;
function TArray_Distribute(const arr: TStringArray; const parts: Int32): T2DStringArray; overload; cdecl;
function TArray_Distribute(const arr: TCharArray; const parts: Int32): T2DCharArray; overload; cdecl;
function TArray_Distribute(const arr: TBooleanArray; const parts: Int32): T2DBooleanArray; overload; cdecl;
function TArray_Distribute(const arr: TPointArray; const parts: Int32): T2DPointArray; overload; cdecl;
function TArray_Distribute(const arr: TBoxArray; const parts: Int32): T2DBoxArray; overload; cdecl;
function TArray_Distribute(const arr: TRangeArray; const parts: Int32): T2DRangeArray; overload; cdecl;

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

function TArray_Extend(const arr: TIntegerArray; const item: Int32): TIntegerArray; overload; cdecl;
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

function TArray_Extract(const arr: TIntegerArray; const item: Int32; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Extract(const arr: TDoubleArray; const item: Double; const start: Int32 = 0): TDoubleArray; overload; cdecl;
function TArray_Extract(const arr: TStringArray; const item: string; const start: Int32 = 0): TStringArray; overload; cdecl;
function TArray_Extract(const arr: TCharArray; const item: Char; const start: Int32 = 0): TCharArray; overload; cdecl;
function TArray_Extract(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 0): TBooleanArray; overload; cdecl;
function TArray_Extract(const arr: TPointArray; const item: TPoint; const start: Int32 = 0): TPointArray; overload; cdecl;
function TArray_Extract(const arr: TBoxArray; const item: TBox; const start: Int32 = 0): TBoxArray; overload; cdecl;
function TArray_Extract(const arr: TRangeArray; const item: TRange; const start: Int32 = 0): TRangeArray; overload; cdecl;
function TArray_Extract(const arr: TIntegerArray; const items: TIntegerArray; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Extract(const arr: TDoubleArray; const items: TDoubleArray; const start: Int32 = 0): TDoubleArray; overload; cdecl;
function TArray_Extract(const arr: TStringArray; const items: TStringArray; const start: Int32 = 0): TStringArray; overload; cdecl;
function TArray_Extract(const arr: TCharArray; const items: TCharArray; const start: Int32 = 0): TCharArray; overload; cdecl;
function TArray_Extract(const arr: TBooleanArray; const items: TBooleanArray; const start: Int32 = 0): TBooleanArray; overload; cdecl;
function TArray_Extract(const arr: TPointArray; const items: TPointArray; const start: Int32 = 0): TPointArray; overload; cdecl;
function TArray_Extract(const arr: TBoxArray; const items: TBoxArray; const start: Int32 = 0): TBoxArray; overload; cdecl;
function TArray_Extract(const arr: TRangeArray; const items: TRangeArray; const start: Int32 = 0): TRangeArray; overload; cdecl;

function TArray_ExtractEvery(const arr: TIntegerArray; const X: Int32 = 1; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_ExtractEvery(const arr: TDoubleArray; const X: Int32 = 1; const start: Int32 = 0): TDoubleArray; overload; cdecl;
function TArray_ExtractEvery(const arr: TStringArray; const X: Int32 = 1; const start: Int32 = 0): TStringArray; overload; cdecl;
function TArray_ExtractEvery(const arr: TCharArray; const X: Int32 = 1; const start: Int32 = 0): TCharArray; overload; cdecl;
function TArray_ExtractEvery(const arr: TBooleanArray; const X: Int32 = 1; const start: Int32 = 0): TBooleanArray; overload; cdecl;
function TArray_ExtractEvery(const arr: TPointArray; const X: Int32 = 1; const start: Int32 = 0): TPointArray; overload; cdecl;
function TArray_ExtractEvery(const arr: TBoxArray; const X: Int32 = 1; const start: Int32 = 0): TBoxArray; overload; cdecl;
function TArray_ExtractEvery(const arr: TRangeArray; const X: Int32 = 1; const start: Int32 = 0): TRangeArray; overload; cdecl;

function TArray_Fill(const arr: TIntegerArray; const item: Int32; const start: Int32 = 0; const count: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Fill(const arr: TDoubleArray; const item: Double; const start: Int32 = 0; const count: Int32 = 2147483647): TDoubleArray; overload; cdecl;
function TArray_Fill(const arr: TStringArray; const item: string; const start: Int32 = 0; const count: Int32 = 2147483647): TStringArray; overload; cdecl;
function TArray_Fill(const arr: TCharArray; const item: Char; const start: Int32 = 0; const count: Int32 = 2147483647): TCharArray; overload; cdecl;
function TArray_Fill(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 0; const count: Int32 = 2147483647): TBooleanArray; overload; cdecl;
function TArray_Fill(const arr: TPointArray; const item: TPoint; const start: Int32 = 0; const count: Int32 = 2147483647): TPointArray; overload; cdecl;
function TArray_Fill(const arr: TBoxArray; const item: TBox; const start: Int32 = 0; const count: Int32 = 2147483647): TBoxArray; overload; cdecl;
function TArray_Fill(const arr: TRangeArray; const item: TRange; const start: Int32 = 0; const count: Int32 = 2147483647): TRangeArray; overload; cdecl;
function TArray_Fill(const arr: TIntegerArray; const items: TIntegerArray; const start: Int32 = 0; const count: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Fill(const arr: TDoubleArray; const items: TDoubleArray; const start: Int32 = 0; const count: Int32 = 2147483647): TDoubleArray; overload; cdecl;
function TArray_Fill(const arr: TStringArray; const items: TStringArray; const start: Int32 = 0; const count: Int32 = 2147483647): TStringArray; overload; cdecl;
function TArray_Fill(const arr: TCharArray; const items: TCharArray; const start: Int32 = 0; const count: Int32 = 2147483647): TCharArray; overload; cdecl;
function TArray_Fill(const arr: TBooleanArray; const items: TBooleanArray; const start: Int32 = 0; const count: Int32 = 2147483647): TBooleanArray; overload; cdecl;
function TArray_Fill(const arr: TPointArray; const items: TPointArray; const start: Int32 = 0; const count: Int32 = 2147483647): TPointArray; overload; cdecl;
function TArray_Fill(const arr: TBoxArray; const items: TBoxArray; const start: Int32 = 0; const count: Int32 = 2147483647): TBoxArray; overload; cdecl;
function TArray_Fill(const arr: TRangeArray; const items: TRangeArray; const start: Int32 = 0; const count: Int32 = 2147483647): TRangeArray; overload; cdecl;

function TArray_Filter(const arr: TIntegerArray; const item: Int32; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Filter(const arr: TDoubleArray; const item: Double; const start: Int32 = 0): TDoubleArray; overload; cdecl;
function TArray_Filter(const arr: TStringArray; const item: string; const start: Int32 = 0): TStringArray; overload; cdecl;
function TArray_Filter(const arr: TCharArray; const item: Char; const start: Int32 = 0): TCharArray; overload; cdecl;
function TArray_Filter(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 0): TBooleanArray; overload; cdecl;
function TArray_Filter(const arr: TPointArray; const item: TPoint; const start: Int32 = 0): TPointArray; overload; cdecl;
function TArray_Filter(const arr: TBoxArray; const item: TBox; const start: Int32 = 0): TBoxArray; overload; cdecl;
function TArray_Filter(const arr: TRangeArray; const item: TRange; const start: Int32 = 0): TRangeArray; overload; cdecl;
function TArray_Filter(const arr: TIntegerArray; const items: TIntegerArray; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Filter(const arr: TDoubleArray; const items: TDoubleArray; const start: Int32 = 0): TDoubleArray; overload; cdecl;
function TArray_Filter(const arr: TStringArray; const items: TStringArray; const start: Int32 = 0): TStringArray; overload; cdecl;
function TArray_Filter(const arr: TCharArray; const items: TCharArray; const start: Int32 = 0): TCharArray; overload; cdecl;
function TArray_Filter(const arr: TBooleanArray; const items: TBooleanArray; const start: Int32 = 0): TBooleanArray; overload; cdecl;
function TArray_Filter(const arr: TPointArray; const items: TPointArray; const start: Int32 = 0): TPointArray; overload; cdecl;
function TArray_Filter(const arr: TBoxArray; const items: TBoxArray; const start: Int32 = 0): TBoxArray; overload; cdecl;
function TArray_Filter(const arr: TRangeArray; const items: TRangeArray; const start: Int32 = 0): TRangeArray; overload; cdecl;

function TArray_FilterEvery(const arr: TIntegerArray; const X: Int32 = 1; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_FilterEvery(const arr: TDoubleArray; const X: Int32 = 1; const start: Int32 = 0): TDoubleArray; overload; cdecl;
function TArray_FilterEvery(const arr: TStringArray; const X: Int32 = 1; const start: Int32 = 0): TStringArray; overload; cdecl;
function TArray_FilterEvery(const arr: TCharArray; const X: Int32 = 1; const start: Int32 = 0): TCharArray; overload; cdecl;
function TArray_FilterEvery(const arr: TBooleanArray; const X: Int32 = 1; const start: Int32 = 0): TBooleanArray; overload; cdecl;
function TArray_FilterEvery(const arr: TPointArray; const X: Int32 = 1; const start: Int32 = 0): TPointArray; overload; cdecl;
function TArray_FilterEvery(const arr: TBoxArray; const X: Int32 = 1; const start: Int32 = 0): TBoxArray; overload; cdecl;
function TArray_FilterEvery(const arr: TRangeArray; const X: Int32 = 1; const start: Int32 = 0): TRangeArray; overload; cdecl;

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

function TArray_Includes(const arr: TIntegerArray; const item: Int32; const start: Int32 = 2147483647): Boolean; overload; cdecl;
function TArray_Includes(const arr: TDoubleArray; const item: Double; const start: Int32 = 2147483647): Boolean; overload; cdecl;
function TArray_Includes(const arr: TStringArray; const item: string; const start: Int32 = 2147483647): Boolean; overload; cdecl;
function TArray_Includes(const arr: TCharArray; const item: Char; const start: Int32 = 2147483647): Boolean; overload; cdecl;
function TArray_Includes(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 2147483647): Boolean; overload; cdecl;
function TArray_Includes(const arr: TPointArray; const item: TPoint; const start: Int32 = 2147483647): Boolean; overload; cdecl;
function TArray_Includes(const arr: TBoxArray; const item: TBox; const start: Int32 = 2147483647): Boolean; overload; cdecl;
function TArray_Includes(const arr: TRangeArray; const item: TRange; const start: Int32 = 2147483647): Boolean; overload; cdecl;

function TArray_Move(var arr: TIntegerArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
function TArray_Move(var arr: TDoubleArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
function TArray_Move(var arr: TStringArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
function TArray_Move(var arr: TCharArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
function TArray_Move(var arr: TBooleanArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
function TArray_Move(var arr: TPointArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
function TArray_Move(var arr: TBoxArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;
function TArray_Move(var arr: TRangeArray; oldIndex, newIndex: Int32): Boolean; overload; cdecl;

function TArray_Oversize(const arr: TIntegerArray; const limit: Int32): Boolean; overload; cdecl;
function TArray_Oversize(const arr: TDoubleArray; const limit: Int32): Boolean; overload; cdecl;
function TArray_Oversize(const arr: TStringArray; const limit: Int32): Boolean; overload; cdecl;
function TArray_Oversize(const arr: TCharArray; const limit: Int32): Boolean; overload; cdecl;
function TArray_Oversize(const arr: TBooleanArray; const limit: Int32): Boolean; overload; cdecl;
function TArray_Oversize(const arr: TPointArray; const limit: Int32): Boolean; overload; cdecl;
function TArray_Oversize(const arr: TBoxArray; const limit: Int32): Boolean; overload; cdecl;
function TArray_Oversize(const arr: TRangeArray; const limit: Int32): Boolean; overload; cdecl;

function TArray_Partition(const arr: TIntegerArray; const size: Int32): T2DIntegerArray; overload; cdecl;
function TArray_Partition(const arr: TDoubleArray; const size: Int32): T2DDoubleArray; overload; cdecl;
function TArray_Partition(const arr: TStringArray; const size: Int32): T2DStringArray; overload; cdecl;
function TArray_Partition(const arr: TCharArray; const size: Int32): T2DCharArray; overload; cdecl;
function TArray_Partition(const arr: TBooleanArray; const size: Int32): T2DBooleanArray; overload; cdecl;
function TArray_Partition(const arr: TPointArray; const size: Int32): T2DPointArray; overload; cdecl;
function TArray_Partition(const arr: TBoxArray; const size: Int32): T2DBoxArray; overload; cdecl;
function TArray_Partition(const arr: TRangeArray; const size: Int32): T2DRangeArray; overload; cdecl;

function TArray_Pick(var arr: TIntegerArray; const IDs: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Pick(var arr: TDoubleArray; const IDs: TIntegerArray): TDoubleArray; overload; cdecl;
function TArray_Pick(var arr: TStringArray; const IDs: TIntegerArray): TStringArray; overload; cdecl;
function TArray_Pick(var arr: TCharArray; const IDs: TIntegerArray): TCharArray; overload; cdecl;
function TArray_Pick(var arr: TBooleanArray; const IDs: TIntegerArray): TBooleanArray; overload; cdecl;
function TArray_Pick(var arr: TPointArray; const IDs: TIntegerArray): TPointArray; overload; cdecl;
function TArray_Pick(var arr: TBoxArray; const IDs: TIntegerArray): TBoxArray; overload; cdecl;
function TArray_Pick(var arr: TRangeArray; const IDs: TIntegerArray): TRangeArray; overload; cdecl;

function TArray_Pop(var arr: TIntegerArray): Int32; overload; cdecl;
function TArray_Pop(var arr: TDoubleArray): Double; overload; cdecl;
function TArray_Pop(var arr: TStringArray): string; overload; cdecl;
function TArray_Pop(var arr: TCharArray): Char; overload; cdecl;
function TArray_Pop(var arr: TBooleanArray): Boolean; overload; cdecl;
function TArray_Pop(var arr: TPointArray): TPoint; overload; cdecl;
function TArray_Pop(var arr: TBoxArray): TBox; overload; cdecl;
function TArray_Pop(var arr: TRangeArray): TRange; overload; cdecl;
function TArray_Pop(var arr: TIntegerArray; const null: Int32): Int32; overload; cdecl;
function TArray_Pop(var arr: TDoubleArray; const null: Double): Double; overload; cdecl;
function TArray_Pop(var arr: TStringArray; const null: string): string; overload; cdecl;
function TArray_Pop(var arr: TCharArray; const null: Char): Char; overload; cdecl;
function TArray_Pop(var arr: TBooleanArray; const null: Boolean): Boolean; overload; cdecl;
function TArray_Pop(var arr: TPointArray; const null: TPoint): TPoint; overload; cdecl;
function TArray_Pop(var arr: TBoxArray; const null: TBox): TBox; overload; cdecl;
function TArray_Pop(var arr: TRangeArray; const null: TRange): TRange; overload; cdecl;

function TArray_Pos(const arr: TIntegerArray; const item: Int32; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TDoubleArray; const item: Double; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TStringArray; const item: string; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TCharArray; const item: Char; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TPointArray; const item: TPoint; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TBoxArray; const item: TBox; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TRangeArray; const item: TRange; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TIntegerArray; const items: TIntegerArray; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TDoubleArray; const items: TDoubleArray; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TStringArray; const items: TStringArray; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TCharArray; const items: TCharArray; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TBooleanArray; const items: TBooleanArray; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TPointArray; const items: TPointArray; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TBoxArray; const items: TBoxArray; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Pos(const arr: TRangeArray; const items: TRangeArray; const start: Int32 = 0): Int32; overload; cdecl;

function TArray_Position(const arr: TIntegerArray; const item: Int32; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TDoubleArray; const item: Double; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TStringArray; const item: string; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TCharArray; const item: Char; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TPointArray; const item: TPoint; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TBoxArray; const item: TBox; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TRangeArray; const item: TRange; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TIntegerArray; const items: TIntegerArray; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TDoubleArray; const items: TDoubleArray; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TStringArray; const items: TStringArray; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TCharArray; const items: TCharArray; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TBooleanArray; const items: TBooleanArray; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TPointArray; const items: TPointArray; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TBoxArray; const items: TBoxArray; const start: Int32 = 0): Int32; overload; cdecl;
function TArray_Position(const arr: TRangeArray; const items: TRangeArray; const start: Int32 = 0): Int32; overload; cdecl;

function TArray_Positions(const arr: TIntegerArray; const item: Int32; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TDoubleArray; const item: Double; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TStringArray; const item: string; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TCharArray; const item: Char; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TPointArray; const item: TPoint; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TBoxArray; const item: TBox; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TRangeArray; const item: TRange; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TIntegerArray; const items: TIntegerArray; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TDoubleArray; const items: TDoubleArray; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TStringArray; const items: TStringArray; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TCharArray; const items: TCharArray; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TBooleanArray; const items: TBooleanArray; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TPointArray; const items: TPointArray; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TBoxArray; const items: TBoxArray; const start: Int32 = 0): TIntegerArray; overload; cdecl;
function TArray_Positions(const arr: TRangeArray; const items: TRangeArray; const start: Int32 = 0): TIntegerArray; overload; cdecl;

function TArray_PosLast(const arr: TIntegerArray; const item: Int32; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TDoubleArray; const item: Double; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TStringArray; const item: string; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TCharArray; const item: Char; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TPointArray; const item: TPoint; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TBoxArray; const item: TBox; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TRangeArray; const item: TRange; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TIntegerArray; const items: TIntegerArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TDoubleArray; const items: TDoubleArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TStringArray; const items: TStringArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TCharArray; const items: TCharArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TBooleanArray; const items: TBooleanArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TPointArray; const items: TPointArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TBoxArray; const items: TBoxArray; const start: Int32 = 2147483647): Int32; overload; cdecl;
function TArray_PosLast(const arr: TRangeArray; const items: TRangeArray; const start: Int32 = 2147483647): Int32; overload; cdecl;

function TArray_PosLasts(const arr: TIntegerArray; const item: Int32; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TDoubleArray; const item: Double; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TStringArray; const item: string; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TCharArray; const item: Char; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TBooleanArray; const item: Boolean; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TPointArray; const item: TPoint; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TBoxArray; const item: TBox; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TRangeArray; const item: TRange; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TIntegerArray; const items: TIntegerArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TDoubleArray; const items: TDoubleArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TStringArray; const items: TStringArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TCharArray; const items: TCharArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TBooleanArray; const items: TBooleanArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TPointArray; const items: TPointArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TBoxArray; const items: TBoxArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;
function TArray_PosLasts(const arr: TRangeArray; const items: TRangeArray; const start: Int32 = 2147483647): TIntegerArray; overload; cdecl;

function TArray_Push(var arr: TIntegerArray; const item: Int32): Int32; overload; cdecl;
function TArray_Push(var arr: TDoubleArray; const item: Double): Int32; overload; cdecl;
function TArray_Push(var arr: TStringArray; const item: string): Int32; overload; cdecl;
function TArray_Push(var arr: TCharArray; const item: Char): Int32; overload; cdecl;
function TArray_Push(var arr: TBooleanArray; const item: Boolean): Int32; overload; cdecl;
function TArray_Push(var arr: TPointArray; const item: TPoint): Int32; overload; cdecl;
function TArray_Push(var arr: TBoxArray; const item: TBox): Int32; overload; cdecl;
function TArray_Push(var arr: TRangeArray; const item: TRange): Int32; overload; cdecl;
function TArray_Push(var arr: TIntegerArray; const items: TIntegerArray): Int32; overload; cdecl;
function TArray_Push(var arr: TDoubleArray; const items: TDoubleArray): Int32; overload; cdecl;
function TArray_Push(var arr: TStringArray; const items: TStringArray): Int32; overload; cdecl;
function TArray_Push(var arr: TCharArray; const items: TCharArray): Int32; overload; cdecl;
function TArray_Push(var arr: TBooleanArray; const items: TBooleanArray): Int32; overload; cdecl;
function TArray_Push(var arr: TPointArray; const items: TPointArray): Int32; overload; cdecl;
function TArray_Push(var arr: TBoxArray; const items: TBoxArray): Int32; overload; cdecl;
function TArray_Push(var arr: TRangeArray; const items: TRangeArray): Int32; overload; cdecl;

function TArray_Randomize(var arr: TIntegerArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
function TArray_Randomize(var arr: TDoubleArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
function TArray_Randomize(var arr: TStringArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
function TArray_Randomize(var arr: TCharArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
function TArray_Randomize(var arr: TBooleanArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
function TArray_Randomize(var arr: TPointArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
function TArray_Randomize(var arr: TBoxArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;
function TArray_Randomize(var arr: TRangeArray; const shuffles: Int32 = 1): Boolean; overload; cdecl;

function TArray_Remove(var arr: TIntegerArray; const item: Int32; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TIntegerArray; const item: Int32; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TDoubleArray; const item: Double; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TDoubleArray; const item: Double; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TStringArray; const item: string; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TStringArray; const item: string; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TCharArray; const item: Char; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TCharArray; const item: Char; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TBooleanArray; const item: Boolean; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TBooleanArray; const item: Boolean; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TPointArray; const item: TPoint; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TPointArray; const item: TPoint; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TBoxArray; const item: TBox; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TBoxArray; const item: TBox; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TRangeArray; const item: TRange; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TRangeArray; const item: TRange; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TIntegerArray; const items: TIntegerArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TIntegerArray; const items: TIntegerArray; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TDoubleArray; const items: TDoubleArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TDoubleArray; const items: TDoubleArray; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TStringArray; const items: TStringArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TStringArray; const items: TStringArray; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TCharArray; const items: TCharArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TCharArray; const items: TCharArray; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TBooleanArray; const items: TBooleanArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TBooleanArray; const items: TBooleanArray; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TPointArray; const items: TPointArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TPointArray; const items: TPointArray; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TBoxArray; const items: TBoxArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TBoxArray; const items: TBoxArray; const all: Boolean): Int32; overload; cdecl;
function TArray_Remove(var arr: TRangeArray; const items: TRangeArray; const start: Int32 = 0; const all: Boolean = True): Int32; overload; cdecl;
function TArray_Remove(var arr: TRangeArray; const items: TRangeArray; const all: Boolean): Int32; overload; cdecl;

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

function TArray_Set(const arr: TIntegerArray; const IDs: TIntegerArray; const item: Int32): TIntegerArray; overload; cdecl;
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
function TArray_Set(const arr: TIntegerArray; const start: Int32; const items: TIntegerArray): TIntegerArray; overload; cdecl;
function TArray_Set(const arr: TDoubleArray; const start: Int32; const items: TDoubleArray): TDoubleArray; overload; cdecl;
function TArray_Set(const arr: TStringArray; const start: Int32; const items: TStringArray): TStringArray; overload; cdecl;
function TArray_Set(const arr: TCharArray; const start: Int32; const items: TCharArray): TCharArray; overload; cdecl;
function TArray_Set(const arr: TBooleanArray; const start: Int32; const items: TBooleanArray): TBooleanArray; overload; cdecl;
function TArray_Set(const arr: TPointArray; const start: Int32; const items: TPointArray): TPointArray; overload; cdecl;
function TArray_Set(const arr: TBoxArray; const start: Int32; const items: TBoxArray): TBoxArray; overload; cdecl;
function TArray_Set(const arr: TRangeArray; const start: Int32; const items: TRangeArray): TRangeArray; overload; cdecl;

function TArray_Size(var arr: TIntegerArray; const size: Int32): Int32; overload; cdecl;
function TArray_Size(var arr: TDoubleArray; const size: Int32): Int32; overload; cdecl;
function TArray_Size(var arr: TStringArray; const size: Int32): Int32; overload; cdecl;
function TArray_Size(var arr: TCharArray; const size: Int32): Int32; overload; cdecl;
function TArray_Size(var arr: TBooleanArray; const size: Int32): Int32; overload; cdecl;
function TArray_Size(var arr: TPointArray; const size: Int32): Int32; overload; cdecl;
function TArray_Size(var arr: TBoxArray; const size: Int32): Int32; overload; cdecl;
function TArray_Size(var arr: TRangeArray; const size: Int32): Int32; overload; cdecl;
function TArray_Size(var arr: TIntegerArray; const size: Int32; const null: Int32): Int32; overload; cdecl;
function TArray_Size(var arr: TDoubleArray; const size: Int32; const null: Double): Int32; overload; cdecl;
function TArray_Size(var arr: TStringArray; const size: Int32; const null: string): Int32; overload; cdecl;
function TArray_Size(var arr: TCharArray; const size: Int32; const null: Char): Int32; overload; cdecl;
function TArray_Size(var arr: TBooleanArray; const size: Int32; const null: Boolean): Int32; overload; cdecl;
function TArray_Size(var arr: TPointArray; const size: Int32; const null: TPoint): Int32; overload; cdecl;
function TArray_Size(var arr: TBoxArray; const size: Int32; const null: TBox): Int32; overload; cdecl;
function TArray_Size(var arr: TRangeArray; const size: Int32; const null: TRange): Int32; overload; cdecl;
function TArray_Size(const arr: TIntegerArray): Int32; overload; cdecl;
function TArray_Size(const arr: TDoubleArray): Int32; overload; cdecl;
function TArray_Size(const arr: TStringArray): Int32; overload; cdecl;
function TArray_Size(const arr: TCharArray): Int32; overload; cdecl;
function TArray_Size(const arr: TBooleanArray): Int32; overload; cdecl;
function TArray_Size(const arr: TPointArray): Int32; overload; cdecl;
function TArray_Size(const arr: TBoxArray): Int32; overload; cdecl;
function TArray_Size(const arr: TRangeArray): Int32; overload; cdecl;

function TArray_SizeBetween(const arr: TIntegerArray; const x, y: Int32): Boolean; overload; cdecl;
function TArray_SizeBetween(const arr: TDoubleArray; const x, y: Int32): Boolean; overload; cdecl;
function TArray_SizeBetween(const arr: TStringArray; const x, y: Int32): Boolean; overload; cdecl;
function TArray_SizeBetween(const arr: TCharArray; const x, y: Int32): Boolean; overload; cdecl;
function TArray_SizeBetween(const arr: TBooleanArray; const x, y: Int32): Boolean; overload; cdecl;
function TArray_SizeBetween(const arr: TPointArray; const x, y: Int32): Boolean; overload; cdecl;
function TArray_SizeBetween(const arr: TBoxArray; const x, y: Int32): Boolean; overload; cdecl;
function TArray_SizeBetween(const arr: TRangeArray; const x, y: Int32): Boolean; overload; cdecl;

function TArray_SizeMax(const arr: TIntegerArray; const y: Int32): Boolean; overload; cdecl;
function TArray_SizeMax(const arr: TDoubleArray; const y: Int32): Boolean; overload; cdecl;
function TArray_SizeMax(const arr: TStringArray; const y: Int32): Boolean; overload; cdecl;
function TArray_SizeMax(const arr: TCharArray; const y: Int32): Boolean; overload; cdecl;
function TArray_SizeMax(const arr: TBooleanArray; const y: Int32): Boolean; overload; cdecl;
function TArray_SizeMax(const arr: TPointArray; const y: Int32): Boolean; overload; cdecl;
function TArray_SizeMax(const arr: TBoxArray; const y: Int32): Boolean; overload; cdecl;
function TArray_SizeMax(const arr: TRangeArray; const y: Int32): Boolean; overload; cdecl;

function TArray_SizeMin(const arr: TIntegerArray; const x: Int32): Boolean; overload; cdecl;
function TArray_SizeMin(const arr: TDoubleArray; const x: Int32): Boolean; overload; cdecl;
function TArray_SizeMin(const arr: TStringArray; const x: Int32): Boolean; overload; cdecl;
function TArray_SizeMin(const arr: TCharArray; const x: Int32): Boolean; overload; cdecl;
function TArray_SizeMin(const arr: TBooleanArray; const x: Int32): Boolean; overload; cdecl;
function TArray_SizeMin(const arr: TPointArray; const x: Int32): Boolean; overload; cdecl;
function TArray_SizeMin(const arr: TBoxArray; const x: Int32): Boolean; overload; cdecl;
function TArray_SizeMin(const arr: TRangeArray; const x: Int32): Boolean; overload; cdecl;

function TArray_Swap(var a, b: TIntegerArray): Int32; overload; cdecl;
function TArray_Swap(var a, b: TDoubleArray): Int32; overload; cdecl;
function TArray_Swap(var a, b: TStringArray): Int32; overload; cdecl;
function TArray_Swap(var a, b: TCharArray): Int32; overload; cdecl;
function TArray_Swap(var a, b: TBooleanArray): Int32; overload; cdecl;
function TArray_Swap(var a, b: TPointArray): Int32; overload; cdecl;
function TArray_Swap(var a, b: TBoxArray): Int32; overload; cdecl;
function TArray_Swap(var a, b: TRangeArray): Int32; overload; cdecl;

function TArray_Trade(var a, b: TIntegerArray): Int32; overload; cdecl;
function TArray_Trade(var a, b: TDoubleArray): Int32; overload; cdecl;
function TArray_Trade(var a, b: TStringArray): Int32; overload; cdecl;
function TArray_Trade(var a, b: TCharArray): Int32; overload; cdecl;
function TArray_Trade(var a, b: TBooleanArray): Int32; overload; cdecl;
function TArray_Trade(var a, b: TPointArray): Int32; overload; cdecl;
function TArray_Trade(var a, b: TBoxArray): Int32; overload; cdecl;
function TArray_Trade(var a, b: TRangeArray): Int32; overload; cdecl;

function TArray_Undersize(const arr: TIntegerArray; const limit: Int32): Boolean; overload; cdecl;
function TArray_Undersize(const arr: TDoubleArray; const limit: Int32): Boolean; overload; cdecl;
function TArray_Undersize(const arr: TStringArray; const limit: Int32): Boolean; overload; cdecl;
function TArray_Undersize(const arr: TCharArray; const limit: Int32): Boolean; overload; cdecl;
function TArray_Undersize(const arr: TBooleanArray; const limit: Int32): Boolean; overload; cdecl;
function TArray_Undersize(const arr: TPointArray; const limit: Int32): Boolean; overload; cdecl;
function TArray_Undersize(const arr: TBoxArray; const limit: Int32): Boolean; overload; cdecl;
function TArray_Undersize(const arr: TRangeArray; const limit: Int32): Boolean; overload; cdecl;

function TArray_Unique(var arr: TIntegerArray): Int32; overload; cdecl;
function TArray_Unique(var arr: TDoubleArray): Int32; overload; cdecl;
function TArray_Unique(var arr: TStringArray): Int32; overload; cdecl;
function TArray_Unique(var arr: TCharArray): Int32; overload; cdecl;
function TArray_Unique(var arr: TBooleanArray): Int32; overload; cdecl;
function TArray_Unique(var arr: TPointArray): Int32; overload; cdecl;
function TArray_Unique(var arr: TBoxArray): Int32; overload; cdecl;
function TArray_Unique(var arr: TRangeArray): Int32; overload; cdecl;

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

function TArray_Unshift(var arr: TIntegerArray; const item: Int32): Int32; overload; cdecl;
function TArray_Unshift(var arr: TDoubleArray; const item: Double): Int32; overload; cdecl;
function TArray_Unshift(var arr: TStringArray; const item: string): Int32; overload; cdecl;
function TArray_Unshift(var arr: TCharArray; const item: Char): Int32; overload; cdecl;
function TArray_Unshift(var arr: TBooleanArray; const item: Boolean): Int32; overload; cdecl;
function TArray_Unshift(var arr: TPointArray; const item: TPoint): Int32; overload; cdecl;
function TArray_Unshift(var arr: TBoxArray; const item: TBox): Int32; overload; cdecl;
function TArray_Unshift(var arr: TRangeArray; const item: TRange): Int32; overload; cdecl;
function TArray_Unshift(var arr: TIntegerArray; const items: TIntegerArray): Int32; overload; cdecl;
function TArray_Unshift(var arr: TDoubleArray; const items: TDoubleArray): Int32; overload; cdecl;
function TArray_Unshift(var arr: TStringArray; const items: TStringArray): Int32; overload; cdecl;
function TArray_Unshift(var arr: TCharArray; const items: TCharArray): Int32; overload; cdecl;
function TArray_Unshift(var arr: TBooleanArray; const items: TBooleanArray): Int32; overload; cdecl;
function TArray_Unshift(var arr: TPointArray; const items: TPointArray): Int32; overload; cdecl;
function TArray_Unshift(var arr: TBoxArray; const items: TBoxArray): Int32; overload; cdecl;
function TArray_Unshift(var arr: TRangeArray; const items: TRangeArray): Int32; overload; cdecl;

function T2DArray_Blank(const arr: T2DIntegerArray): Boolean; overload; cdecl;
function T2DArray_Blank(const arr: T2DDoubleArray): Boolean; overload; cdecl;
function T2DArray_Blank(const arr: T2DStringArray): Boolean; overload; cdecl;
function T2DArray_Blank(const arr: T2DCharArray): Boolean; overload; cdecl;
function T2DArray_Blank(const arr: T2DBooleanArray): Boolean; overload; cdecl;
function T2DArray_Blank(const arr: T2DPointArray): Boolean; overload; cdecl;
function T2DArray_Blank(const arr: T2DBoxArray): Boolean; overload; cdecl;
function T2DArray_Blank(const arr: T2DRangeArray): Boolean; overload; cdecl;

function T2DArray_Create(const size1D, size2D: Int32; const item: Int32): T2DIntegerArray; overload; cdecl;
function T2DArray_Create(const size1D, size2D: Int32; const item: Double): T2DDoubleArray; overload; cdecl;
function T2DArray_Create(const size1D, size2D: Int32; const item: string): T2DStringArray; overload; cdecl;
function T2DArray_Create(const size1D, size2D: Int32; const item: Char): T2DCharArray; overload; cdecl;
function T2DArray_Create(const size1D, size2D: Int32; const item: Boolean): T2DBooleanArray; overload; cdecl;
function T2DArray_Create(const size1D, size2D: Int32; const item: TPoint): T2DPointArray; overload; cdecl;
function T2DArray_Create(const size1D, size2D: Int32; const item: TBox): T2DBoxArray; overload; cdecl;
function T2DArray_Create(const size1D, size2D: Int32; const item: TRange): T2DRangeArray; overload; cdecl;

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

procedure Swap(var A, B: Int32); overload; inline;
var
  T: Int32;
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

{$I MiMU/types/Double.pas}
{$I MiMU/types/Int32.pas}
{$I MiMU/types/Int64.pas}
{$I MiMU/types/String.pas}
{$I MiMU/types/Boolean.pas}
{$I MiMU/types/TPoint.pas}
{$I MiMU/types/TBox.pas}
{$I MiMU/types/TRange.pas}

{$I MiMU/generic/TArray_Copy.pas}
{$I MiMU/generic/TArray_Get.pas}
{$I MiMU/generic/TArray_Set.pas}
{$I MiMU/generic/TArray_Size.pas}
{$I MiMU/generic/TArray_SizeBetween.pas}
{$I MiMU/generic/TArray_SizeMax.pas}
{$I MiMU/generic/TArray_SizeMin.pas}
{$I MiMU/generic/TArray_Clone.pas}
{$I MiMU/generic/TArray_Differ.pas}
{$I MiMU/generic/TArray_Empty.pas}
{$I MiMU/generic/TArray_Equal.pas}
{$I MiMU/generic/TArray_Extend.pas}
{$I MiMU/generic/TArray_AllEqual.pas}
{$I MiMU/generic/TArray_AllSame.pas}
{$I MiMU/generic/TArray_AllUnique.pas}
{$I MiMU/generic/TArray_Append.pas}
{$I MiMU/generic/TArray_Add.pas}
{$I MiMU/generic/TArray_Create.pas}
{$I MiMU/generic/TArray_Build.pas}
{$I MiMU/generic/TArray_BuiltWith.pas}
{$I MiMU/generic/TArray_BuiltWithout.pas}
{$I MiMU/generic/TArray_Combine.pas}
{$I MiMU/generic/TArray_Contains.pas}
{$I MiMU/generic/TArray_Includes.pas}
{$I MiMU/generic/TArray_Oversize.pas}
{$I MiMU/generic/TArray_Position.pas}
{$I MiMU/generic/TArray_Positions.pas}
{$I MiMU/generic/TArray_Pos.pas}
{$I MiMU/generic/TArray_Pop.pas}
{$I MiMU/generic/TArray_PosLast.pas}
{$I MiMU/generic/TArray_PosLasts.pas}
{$I MiMU/generic/TArray_Push.pas}
{$I MiMU/generic/TArray_Delete.pas}
{$I MiMU/generic/TArray_Remove.pas}
{$I MiMU/generic/TArray_Filter.pas}
{$I MiMU/generic/TArray_Extract.pas}
{$I MiMU/generic/TArray_FilterEvery.pas}
{$I MiMU/generic/TArray_ExtractEvery.pas}
{$I MiMU/generic/TArray_Reverse.pas}
{$I MiMU/generic/TArray_Reversed.pas}
{$I MiMU/generic/TArray_Flip.pas}
{$I MiMU/generic/TArray_Fill.pas}
{$I MiMU/generic/TArray_Holds.pas}
{$I MiMU/generic/TArray_Dupe.pas}
{$I MiMU/generic/TArray_Swap.pas}
{$I MiMU/generic/TArray_Trade.pas}
{$I MiMU/generic/TArray_Undersize.pas}
{$I MiMU/generic/TArray_Unique.pas}
{$I MiMU/generic/TArray_Uniqued.pas}
{$I MiMU/generic/TArray_Uniques.pas}
{$I MiMU/generic/TArray_Unshift.pas}
{$I MiMU/generic/TArray_Pick.pas}
{$I MiMU/generic/TArray_Move.pas}
{$I MiMU/generic/TArray_Group.pas}
{$I MiMU/generic/TArray_Partition.pas}
{$I MiMU/generic/TArray_Distribute.pas}
{$I MiMU/generic/TArray_Randomize.pas}

{$I MiMU/generic/T2DArray_Blank.pas}
{$I MiMU/generic/T2DArray_Create.pas}
{$I MiMU/generic/T2DArray_Empty.pas}
{$I MiMU/generic/T2DArray_Length.pas}
{$I MiMU/generic/T2DArray_Merge.pas}

{$I MiMU/types/TPointArray.pas}

initialization

finalization

end.
