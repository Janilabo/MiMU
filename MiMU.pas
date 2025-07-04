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
  Classes, SysUtils, Math, Generics.Collections;

const
  MiMU_VERSION_NUMBER = 0.42;

type
  TIntegerArray = array of Integer;
  T2DIntegerArray = array of TIntegerArray;
  TDoubleArray = array of Double;
  T2DDoubleArray = array of TDoubleArray;
  TStringArray = array of string;
  T2DStringArray = array of TStringArray;
  TCharArray = array of Char;
  T2DCharArray = array of TCharArray;
  TBooleanArray = array of Boolean;
  T2DBooleanArray = array of TBooleanArray;
  TPoint = record
    X, Y: Integer;
    constructor Create(const pX, pY: Integer); overload;
    constructor Create(const value: Integer); overload;
    function Build(const pX, pY: Integer): TPoint; cdecl; inline;
    function InCircle(const center: TPoint; const radius: Double): Boolean; cdecl; inline;
    function InEllipse(const center: TPoint; const XRadius, YRadius: Double): Boolean; cdecl; inline;
    function AngleDegrees(const target: TPoint; const compass: Boolean = False): Double; cdecl;
    function AngleRadians(const target: TPoint): Double; cdecl;
    function DistEuclidean(const target: TPoint): Double; cdecl;
    function DistEuclidean2(const target: TPoint): Double; cdecl;
    function DistSquaredEuclidean(const target: TPoint): Double; cdecl;
    function DistManhattan(const target: TPoint): Double; cdecl;
    function DistChebyshev(const target: TPoint): Double; cdecl;
  end;
  TPointArray = array of TPoint;
  T2DPointArray = array of TPointArray;
  TBox = record
    X1, Y1, X2, Y2: Integer;
    constructor Create(const minX, minY, maxX, maxY: Integer); overload;
    constructor Create(const top, bottom: TPoint); overload;
    constructor Create(const valueX, valueY: Integer); overload;
    constructor Create(const target: TPoint); overload;
    constructor Create(const value: Integer); overload;
    function Build(const minX, minY, maxX, maxY: Integer): Integer; overload; cdecl;
    function Build(const top, bottom: TPoint): Integer; overload; cdecl;
    function Build(const valueX, valueY: Integer): Integer; overload; cdecl;
    function Build(const target: TPoint): Integer; overload; cdecl;
    function Build(const value: Integer = 0): Integer; overload; cdecl;
    function Form(const pt: TPoint; const size: Integer = 1): TBox; overload; cdecl;
    function Form(const pt: TPoint; const width, height: Integer): TBox; overload; cdecl;
    function Make(const pt: TPoint; const radius: Integer = 0): TBox; overload; cdecl;
    function Make(const pt: TPoint; const wRadius, hRadius: Integer): TBox; overload; cdecl;
    function Size(var width, height: Integer): Integer; cdecl; inline;
    function Area: Integer; cdecl; inline;
    function Diagonal: Double; cdecl;
    function Width: Integer; overload; cdecl;
    function Width(const w: Integer): Integer; overload; cdecl;
    function Height: Integer; overload; cdecl;
    function Height(const h: Integer): Integer; overload; cdecl;
    function Expand(const change: Integer = 1): TBox; cdecl;
    function Shrink(const change: Integer = 1): TBox; cdecl;
    function Resize(const change: Integer): TBox; cdecl;
    function ResizeVertically(const change: Integer): TBox; cdecl;
    function ResizeHorizontally(const change: Integer): TBox; cdecl;
    function ResizeTop(const change: Integer): TBox; cdecl;
    function ResizeBottom(const change: Integer): TBox; cdecl;
    function ResizeLeft(const change: Integer): TBox; cdecl;
    function ResizeRight(const change: Integer): TBox; cdecl;
    function ResizeTopLeft(const change: Integer): TBox; cdecl;
    function ResizeTopRight(const change: Integer): TBox; cdecl;
    function ResizeBottomRight(const change: Integer): TBox; cdecl;
    function ResizeBottomLeft(const change: Integer): TBox; cdecl;
    function Equal(const b: TBox): Boolean; cdecl; inline;
    function Contains(const pt: TPoint): Boolean; overload; cdecl;
    function Contains(const b: TBox): Boolean; overload; cdecl;
    function Center: TPoint; cdecl;
    function Envelope(const b: TBox): TBox; cdecl;
    function Overlap(const b: TBox): Boolean; cdecl; inline;
    function Intersect(const b: TBox): TBox; overload; cdecl;
    function Intersect(const b: TBox; var iArea: TBox): Boolean; overload; cdecl;
    function Union(const b: TBox): TBox; cdecl;
    function Valid: Boolean; cdecl; inline;
    function Invalid: Boolean; cdecl;
    function Similar(const b: TBox; const maxWDiff, maxHDiff: Integer): Boolean; overload; cdecl;
    function Similar(const b: TBox; const diff: Integer): Boolean; overload; cdecl;
    function Fix: Boolean; cdecl;
    function Constraint(const toArea: TBox): Boolean; cdecl;
    function Clip(const toArea: TBox): TBox; cdecl;
    function Restrict(const toArea: TBox): Boolean; cdecl;
    function Clamp(const toArea: TBox): TBox; cdecl;
    function Points: TPointArray; cdecl;
    function TPA: TPointArray; cdecl;
    function CornerPoints: TPointArray; cdecl;
    function Corners: TPointArray; cdecl;
    function SimilarSize(const b: TBox; const widthDifferency, heightDifferency: Integer): Boolean; overload; cdecl;
    function SimilarSize(const b: TBox; const differency: Integer): Boolean; overload; cdecl;
    function Centered(const toArea: TBox): TBox; cdecl;
    function CenterVertically(const toArea: TBox): TBox; cdecl;
    function CenterHorizontally(const toArea: TBox): TBox; cdecl;
	function Inside(const target: TBox): Boolean; overload; cdecl;
  end;
  TBoxArray = array of TBox;
  T2DBoxArray = array of TBoxArray;
  TRange = record
    start, stop: Integer;
    constructor Create(const rStart, rStop: Integer); overload;
	constructor Create(const value: Integer); overload;
    function Neutral: Boolean; cdecl;
    function Ascending: Boolean; cdecl;
    function Descending: Boolean; cdecl;
    function Build(const rStart: Integer = 0; const rStop: Integer = 0): Integer; cdecl;
    function Grab: TRange; cdecl;
    function Size: Integer; cdecl;
    function Length: Integer; cdecl;
    function Lowest: Integer; cdecl;
    function Minimum: Integer; cdecl;
    function Highest: Integer; cdecl;
    function Maximum: Integer; cdecl;
    function Digits: TIntegerArray; cdecl;
    function Ints: TIntegerArray; cdecl;
    function Values: TIntegerArray; cdecl;
    function TIA: TIntegerArray; cdecl;
    function Normalize: TRange; cdecl;
    function Overlapping(const b: TRange): Boolean; cdecl;
    function Overlap(const b: TRange): Boolean; cdecl;
    function Intersect(const b: TRange): TRange; overload; cdecl;
    function Intersect(const b: TRange; var iZone: TRange): Boolean; overload; cdecl;
    function Union(const b: TRange): TRange; cdecl;
    function Shift(const delta: Integer): TRange; cdecl;
    function Contains(const x: Integer): Boolean; overload; cdecl;
    function Contains(const x: TRange): Boolean; overload; cdecl;
    function Reversed: TRange; cdecl;
    function Reverse: Boolean; cdecl;
    function Equals(const b: TRange): Boolean; cdecl;
    function Differs(const b: TRange): Boolean; cdecl;
    function Equal(const b: TRange): Boolean; cdecl;
    function Differ(const b: TRange): Boolean; cdecl;
    function Clamp(const zone: TRange): TRange; cdecl;
    function ClampMax(const maxValue: Integer): TRange; cdecl;
    function ClampMin(const minValue: Integer): TRange; cdecl;
    function Restrict(const zone: TRange): Boolean; cdecl;
    function RestrictMin(const minValue: Integer): Boolean; cdecl;
    function RestrictMax(const maxValue: Integer): Boolean; cdecl;
    function Clip(const zone: TRange): TRange; cdecl;
    function ClipMin(const minValue: Integer): TRange; cdecl;
    function ClipMax(const maxValue: Integer): TRange; cdecl;
    function Touch(const b: TRange): Boolean; cdecl;
    function Touches(const b: TRange): Boolean; cdecl;
    function Distance(const b: TRange): Integer; cdecl;
    function DistHausdorff(const b: TRange): Integer; cdecl;
    function Digit(const x: Integer): Boolean; cdecl; inline;
    function Value(const x: Integer): Boolean; cdecl; inline;
    function Middle: Double; cdecl;
    function Center: Integer; cdecl;
    function Str: string; cdecl;
  end;
  TRangeArray = array of TRange;
  T2DRangeArray = array of TRangeArray;
  TIntegerHelper = type helper for Integer
    function Even: Boolean; cdecl; inline;
    function Odd: Boolean; cdecl; inline;
    function Increase(const N: Integer = 1): Integer; cdecl;
    function Decrease(const N: Integer = 1): Integer; cdecl;
    function Increment(const N: Integer = 1): Integer; cdecl;
    function Decrement(const N: Integer = 1): Integer; cdecl;
    function DigitCount: Integer; cdecl;
    function Digitz: TIntegerArray; cdecl;
    function Digits: TIntegerArray; cdecl;
    function NegA: Integer; cdecl; inline;
    function Neg: Integer; cdecl; inline;
    function Negative: Boolean; cdecl; inline;
    function Positive: Boolean; cdecl; inline;
    function Neutral: Boolean; cdecl; inline;
    function Compare(const T: Integer): Integer; cdecl; inline;
    function Distance(const T: Integer): Integer; cdecl; inline;
    function Difference(const T: Integer): Integer; cdecl; inline;
    function Opposite: Integer; cdecl; inline;
    function Sign: Integer; cdecl; inline;
    function Shuffle: Integer; cdecl;
    function Oversize(const limit: Integer): Boolean; cdecl; inline;
    function Undersize(const limit: Integer): Boolean; cdecl; inline;
	
    function TArray(const aSize: Integer = 1): TIntegerArray; overload cdecl;
    function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DIntegerArray; overload cdecl;
  end;
  TInt64Helper = type helper for Int64
    function Even: Boolean; cdecl; inline;
    function Odd: Boolean; cdecl; inline;
    function Increase(const N: Int64 = 1): Int64; cdecl;
    function Decrease(const N: Int64 = 1): Int64; cdecl;
    function Increment(const N: Int64 = 1): Int64; cdecl;
    function Decrement(const N: Int64 = 1): Int64; cdecl;
    function DigitCount: Integer; cdecl;
    function Digitz: TIntegerArray; cdecl;
    function Digits: TIntegerArray; cdecl;
    function Compare(const T: Int64): Integer; cdecl; inline;
    function Distance(const T: Int64): Int64; cdecl; inline;
    function Difference(const T: Int64): Int64; cdecl; inline;
    function Opposite: Int64; cdecl; inline;
    function Sign: Integer; cdecl; inline;
    function Shuffle: Int64; cdecl;
    function Oversize(const limit: Int64): Boolean; cdecl; inline;
    function Undersize(const limit: Int64): Boolean; cdecl; inline;
  end;
  TDoubleHelper = type helper for Double
    function Increase(const N: Double = 1): Double; cdecl;
    function Decrease(const N: Double = 1): Double; cdecl;
    function Increment(const N: Double = 1): Double; cdecl;
    function Decrement(const N: Double = 1): Double; cdecl;
    function Digits: TIntegerArray; cdecl;
    function NegA: Double; cdecl; inline;
    function Neg: Double; cdecl; inline;
    function Negative: Boolean; cdecl; inline;
    function Positive: Boolean; cdecl; inline;
    function Neutral: Boolean; cdecl; inline;
    function MinDecimal: Double; cdecl;
    function MaxDecimal: Double; cdecl;
    function Accuracy(const a: Int32): Double; cdecl;
    function Compare(const T: Double): Int32; cdecl; inline;
    function Distance(const T: Double): Double; cdecl; inline;
    function Difference(const T: Double): Double; cdecl; inline;
    function Opposite: Double; cdecl; inline;
    function Sign: Int32; cdecl; inline;
    function FixDegrees: Double; cdecl;
    function Degrees: Double; cdecl;
    function FixRadians: Double; cdecl;
    function Radians(const compass: Boolean = False): Double; cdecl;
    function Percent(const position: Double): Double; cdecl; inline;
    function Percentage(const percent: Double): Double; cdecl; inline;
    function Oversize(const limit: Double): Boolean; cdecl;
    function Undersize(const limit: Double): Boolean; cdecl;
	
    function TArray(const aSize: Integer = 1): TDoubleArray; overload cdecl;
    function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DDoubleArray; overload cdecl;
  end;
  TStringHelper = type helper for string
    function After(const s: string; const index: Integer = 1): string; overload;
    function After(const index: Integer; const count: Integer = 2147483647): string; overload;
    function Ahead(const s: string; const index: Integer = 2147483647): string; overload;
    function Ahead(const index: Integer; const count: Integer = 2147483647): string; overload;
    function Before(const s: string; const index: Integer = 1): string; overload;
    function Before(const index: Integer; const count: Integer = 2147483647): string; overload;
    function Behind(const s: string; const index: Integer = 2147483647): string; overload;
    function Behind(const index: Integer; const count: Integer = 2147483647): string; overload;
    function Amount(const s: string; const overlap: Boolean = True; const index: Integer = 2147483647): Integer; cdecl;
    function At(const s: string; const index: Integer = 1): Boolean; cdecl; inline;
    function Between(const s1, s2: string; const index: Integer = 1): string; cdecl;
    function Chars: TCharArray; cdecl;
    function Chunk(const a, b: Integer): string; cdecl;
    function Center(const size: Integer; const fill: Char = #32): string; cdecl;
    function Compare(const s: string): Integer; cdecl; inline;
    function Contains(const s: string; const index: Integer = 1): Boolean; cdecl;
    function Count(const s: string; const overlap: Boolean = True; const index: Integer = 1): Integer; cdecl;
    function Duplicate(const x: Integer = 2): string; cdecl;
    function Duplicated(const x: Integer; const glue: string): string; cdecl;
    function EndsWith(const s: string): Boolean; cdecl;
    function EndWith(const s: string; const index: Integer = 2147483647): Boolean; cdecl;
    function Exch(const aIndex, bIndex: Integer): Boolean; cdecl;
    function Exchange(const aIndex, bIndex: Integer): Boolean; cdecl;
    function Explode(const d: string; const limit: Integer = -1): TStringArray; overload; cdecl;
    function Explode(const d: TStringArray; const limit: Integer = -1): TStringArray; overload; cdecl;
    function Find(const s: string; const index: Integer = 1): Integer; cdecl;
    function Flip: string; cdecl;
    function FromLeft(const count: Integer; const index: Integer = 1): string; cdecl;
    function FromRight(const count: Integer; const index: Integer = 2147483647): string; cdecl;
    function Get(const index: Integer; const count: Integer): string; cdecl; inline;
    function IDs: TIntegerArray; overload; cdecl;
    function IDs(const ID: TIntegerArray): TCharArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const item: Char): TCharArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl;
    function Includes(const s: string; const index: Integer = 2147483647): Boolean; cdecl;
    function Loc(const s: string; const index: Integer = 2147483647): Integer; cdecl;
    function Location(const s: string; const index: Integer = 2147483647): Integer; cdecl;
    function Pick(const index: Integer; const count: Integer = 2147483647): string; cdecl;
    function Pos(const s: string; const index: Integer = 1): Integer; cdecl;
    function Position(const s: string; const index: Integer = 1): Integer; cdecl;
    function PregQuote(const regex: string = '.\+*?[^]$(){}=!<>|:-'): string; cdecl;
    function Reverse: Boolean; cdecl;  
    function Reversed: string; cdecl;
    function Slice(const a, b: Integer): string; cdecl;
    function StartsWith(const s: string): Boolean; cdecl;
    function StartWith(const s: string; const index: Integer = 1): Boolean; cdecl;
    function Stuff(const s: string; const iFrom, iCount: Integer): string; cdecl;
    function TrimLeft(const t: Char = #32): string; cdecl;
    function TrimRight(const t: Char = #32): string; cdecl;
    function Trim(const t: Char = #32): string; cdecl;
    function ToTRange: TRange; cdecl;
    function Quotatation: string; cdecl;

    function TArray(const aSize: Integer = 1): TStringArray; overload cdecl;
    function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DStringArray; overload cdecl;	
  end;
  TCharHelper = type helper for Char
    function TArray(const aSize: Integer = 1): TCharArray; overload cdecl;
    function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DCharArray; overload cdecl;
  end;
  TBooleanHelper = type helper for Boolean
    function ToString: string; cdecl;
    function ToInteger: Integer; cdecl;
    function AsInteger: Integer; cdecl;
    function Toggle: Boolean; cdecl;
    function Opposite: Boolean; cdecl;
    function Switch: Boolean; cdecl;
    function Flip: Boolean; cdecl;
    function Shuffle: Boolean; cdecl;
    function Select(const bTrue, bFalse: Integer): Integer; overload; cdecl;
    function Select(const bTrue, bFalse: Int64): Int64; overload; cdecl;
    function Select(const bTrue, bFalse: Double): Double; overload; cdecl;
    function Select(const bTrue, bFalse: string): string; overload; cdecl;
    function Select(const bTrue, bFalse: Char): Char; overload; cdecl;
    function Select(const bTrue, bFalse: Boolean): Boolean; overload; cdecl;
    function Select(const bTrue, bFalse: TPoint): TPoint; overload; cdecl;
    function Select(const bTrue, bFalse: TBox): TBox; overload; cdecl;
    function Select(const bTrue, bFalse: TRange): TRange; overload; cdecl;
    function Evaluate(const bTrue, bFalse: Integer): Integer; overload; cdecl;
    function Evaluate(const bTrue, bFalse: Int64): Int64; overload; cdecl;
    function Evaluate(const bTrue, bFalse: Double): Double; overload; cdecl;
    function Evaluate(const bTrue, bFalse: string): string; overload; cdecl;
    function Evaluate(const bTrue, bFalse: Char): Char; overload; cdecl;
    function Evaluate(const bTrue, bFalse: Boolean): Boolean; overload; cdecl;
    function Evaluate(const bTrue, bFalse: TPoint): TPoint; overload; cdecl;
    function Evaluate(const bTrue, bFalse: TBox): TBox; overload; cdecl;
    function Evaluate(const bTrue, bFalse: TRange): TRange; overload; cdecl;
    function Enable: Boolean; cdecl;
    function Disable: Boolean; cdecl;
    function SetFalse: Integer; cdecl;
    function SetTrue: Integer; cdecl;
    function SwitchOn(const state: Boolean): Boolean; cdecl;
    function SwitchOff(const state: Boolean): Boolean; cdecl;
	
    function TArray(const aSize: Integer = 1): TBooleanArray; overload cdecl;
    function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DBooleanArray; overload cdecl;	
  end;
  TPointHelper = type helper for TPoint
    function Inside(const bx: TBox): Boolean; cdecl; inline;
    function Create: TPoint; overload; cdecl;
    function Grid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TPointArray; cdecl;
    function Row(const cells: Integer; const space: Integer = 0): TPointArray; cdecl;
    function Column(const cells: Integer; const space: Integer = 0): TPointArray; cdecl;
	
    function TArray(const aSize: Integer = 1): TPointArray; overload cdecl;
    function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DPointArray; overload cdecl;	
  end;
  TBoxHelper = type helper for TBox
    function Create: TBox; overload; cdecl;
    function Inside(const targets: TBoxArray): Boolean; overload; cdecl;
    function Grid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TBoxArray; cdecl;
    function Row(const cells: Integer; const space: Integer = 0): TBoxArray; cdecl;
    function Column(const cells: Integer; const space: Integer = 0): TBoxArray; cdecl;

    function TArray(const aSize: Integer = 1): TBoxArray; overload cdecl;
    function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DBoxArray; overload cdecl;
  end;
  TRangeHelper = type helper for TRange
    function Create: TRange; overload; cdecl;
    function Distribute(const parts: Integer): TRangeArray; cdecl;
    function Partition(const size: Integer): TRangeArray; cdecl;
    function Divide(const size: Integer): TRangeArray; cdecl;
	
    function TArray(const aSize: Integer = 1): TRangeArray; overload cdecl;
    function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): T2DRangeArray; overload cdecl;	
  end;
 
{$DEFINE Integer}{$I Config.inc}{$I Types.inc}{$UNDEF Integer}
{$DEFINE Double}{$I Config.inc}{$I Types.inc}{$UNDEF Double}
{$DEFINE string}{$I Config.inc}{$I Types.inc}{$UNDEF string}
{$DEFINE Char}{$I Config.inc}{$I Types.inc}{$UNDEF Char}
{$DEFINE Boolean}{$I Config.inc}{$I Types.inc}{$UNDEF Boolean}
{$DEFINE TPoint}{$I Config.inc}{$I Types.inc}{$UNDEF TPoint}
{$DEFINE TBox}{$I Config.inc}{$I Types.inc}{$UNDEF TBox}
{$DEFINE TRange}{$I Config.inc}{$I Types.inc}{$UNDEF TRange}
  
type
  T1D = class
  public
    class function Init(var arr: TIntegerArray): Integer; overload; cdecl;
    class function Init(var arr: TPointArray): Integer; overload; cdecl;
    class function Init(var arr: TBooleanArray): Integer; overload; cdecl;
    class function Unique(var arr: TIntegerArray): Integer; overload; cdecl;
    class function Unique(var arr: TPointArray): Integer; overload; cdecl;
  end;
  T2D = class
  public
    class function Create(const size1D, size2D: Integer; const item: Integer): T2DIntegerArray; overload; cdecl;
    class function Create(const size1D, size2D: Integer; const item: Double): T2DDoubleArray; overload; cdecl;
    class function Create(const size1D, size2D: Integer; const item: string): T2DStringArray; overload; cdecl;
    class function Create(const size1D, size2D: Integer; const item: Char): T2DCharArray; overload; cdecl;
    class function Create(const size1D, size2D: Integer; const item: Boolean): T2DBooleanArray; overload; cdecl;
    class function Create(const size1D, size2D: Integer; const item: TPoint): T2DPointArray; overload; cdecl;
    class function Create(const size1D, size2D: Integer; const item: TBox): T2DBoxArray; overload; cdecl;
    class function Create(const size1D, size2D: Integer; const item: TRange): T2DRangeArray; overload; cdecl;
  end;
  _TPoint = class
  public
    class function Create(const pX, pY: Integer): TPoint; overload; cdecl;
    class function Create(const value: Integer = 0): TPoint; overload; cdecl;
  end;
  _TBox = class
  public
    class function Create(const minX, minY, maxX, maxY: Integer): TBox; overload; cdecl;
    class function Create(const top, bottom: TPoint): TBox; overload; cdecl;
    class function Create(const valueX, valueY: Integer): TBox; overload; cdecl;
    class function Create(const target: TPoint): TBox; overload; cdecl;
    class function Create(const value: Integer = 0): TBox; overload; cdecl;
  end;
  _TRange = class
  public
    class function Create(const rStart, rStop: Integer): TRange; overload; cdecl;
    class function Create(const value: Integer = 0): TRange; overload; cdecl;
  end;

function MiMU_Version: Double; cdecl;

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

function Point(const pX, pY: Integer): TPoint; overload; inline;
function Point(const val: Integer = 0): TPoint; overload; inline;
function Range(const rStart, rStop: Integer): TRange; overload; inline;
function Range(const val: Integer = 0): TRange; overload; inline;
function Box(const bX1, bY1, bX2, bY2: Integer): TBox; overload; inline;
function Box(const val: Integer = 0): TBox; overload; inline;

function Swap(var A, B: Integer): Boolean; overload; inline;
function Swap(var A, B: Int64): Boolean; overload; inline;
function Swap(var A, B: Double): Boolean; overload; inline;
function Swap(var A, B: string): Boolean; overload; inline;
function Swap(var A, B: Char): Boolean; overload; inline;
function Swap(var A, B: Boolean): Boolean; overload; inline;
function Swap(var A, B: TPoint): Boolean; overload; inline;
function Swap(var A, B: TBox): Boolean; overload; inline;
function Swap(var A, B: TRange): Boolean; overload; inline;
  
implementation

function MiMU_Version: Double; cdecl;
begin
  Result := MiMU_VERSION_NUMBER;
end;

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

function Point(const pX, pY: Integer): TPoint; overload; inline;
begin
  Result.X := pX;
  Result.Y := pY;
end;

function Point(const val: Integer = 0): TPoint; overload; inline;
begin
  Result.X := val;
  Result.Y := val;
end;

function Range(const rStart, rStop: Integer): TRange; overload; inline;
begin
  Result.start := rStart;
  Result.stop := rStop;
end;

function Range(const val: Integer = 0): TRange; overload; inline;
begin
  Result.start := val;
  Result.stop := val;
end;

function Box(const bX1, bY1, bX2, bY2: Integer): TBox; overload; inline;
begin
  Result.X1 := bX1;
  Result.Y1 := bY1;
  Result.X2 := bX2;
  Result.Y2 := bY2;
end;

function Box(const val: Integer = 0): TBox; overload; inline;
begin
  Result.X1 := val;
  Result.Y1 := val;
  Result.X2 := val;
  Result.Y2 := val;
end;  

function Swap(var A, B: Integer): Boolean; overload; inline;
var
  T: Integer;
begin
  Result := (A <> B);
  T := A;
  A := B;
  B := T;
end;

function Swap(var A, B: Int64): Boolean; overload; inline;
var
  T: Int64;
begin
  Result := (A <> B);
  T := A;
  A := B;
  B := T;
end;

function Swap(var A, B: Double): Boolean; overload; inline;
var
  T: Double;
begin
  Result := (A <> B);
  T := A;
  A := B;
  B := T;
end;

function Swap(var A, B: string): Boolean; overload; inline;
var
  T: string;
begin
  Result := (A <> B);
  T := A;
  A := B;
  B := T;
end;

function Swap(var A, B: Char): Boolean; overload; inline;
var
  T: Char;
begin
  Result := (A <> B);
  T := A;
  A := B;
  B := T;
end;

function Swap(var A, B: Boolean): Boolean; overload; inline;
var
  T: Boolean;
begin
  Result := (A <> B);
  T := A;
  A := B;
  B := T;
end;

function Swap(var A, B: TPoint): Boolean; overload; inline;
var
  T: TPoint;
begin
  Result := (A <> B);
  T := A;
  A := B;
  B := T;
end;

function Swap(var A, B: TBox): Boolean; overload; inline;
var
  T: TBox;
begin
  Result := (A <> B);
  T := A;
  A := B;
  B := T;
end;

function Swap(var A, B: TRange): Boolean; overload; inline;
var
  T: TRange;
begin
  Result := (A <> B);
  T := A;
  A := B;
  B := T;
end;

class function T1D.Init(var arr: TIntegerArray): Integer; overload; cdecl;
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], (Result * SizeOf(Integer)), 0);
end;

class function T1D.Init(var arr: TPointArray): Integer; overload; cdecl;
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], (Result * SizeOf(TPoint)), 0);
end;

class function T1D.Init(var arr: TBooleanArray): Integer; overload; cdecl;
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], Result, 0);
end;

class function T1D.Unique(var arr: TIntegerArray): Integer; overload; cdecl;
var
  x, y, z: Integer;
  r: TRange;
  b: TBooleanArray;
begin
  y := High(arr);
  if (y > 0) then
  begin
    z := 0;
    r := arr.Bounds;
    b.Create(r.Size, False);
    for x := 0 to y do
      if b[arr[x] - r.start].Enable then
        arr[z.Increase] := arr[x];
    SetLength(b, 0);
    SetLength(arr, z);
    Result := ((y + 1) - z);
  end else
    Result := 0;
end;

class function T1D.Unique(var arr: TPointArray): Integer; overload; cdecl;
var
  i, r, l, w, h: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  l := Length(arr);
  if (l > 1) then
  begin
    r := 0;
    b := arr.Bounds(w, h);
    m := T2D.Create(w, h, False);
    for i := 0 to (l - 1) do
      if m[arr[i].X - b.X1][arr[i].Y - b.Y1].Enable then
        arr[r.Increase] := arr[i];
    SetLength(arr, r);
    SetLength(m, 0);
  end;
  Result := (l - Length(arr));
end;

{$mode objfpc}{$H+}

{$I MiMU.inc}

initialization

finalization

end.
