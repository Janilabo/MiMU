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
  Classes, SysUtils, Math;

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
  TIntegerArrayHelper = type helper for TIntegerArray
    function Add(const item: Integer; const duplicates: Boolean = True): TIntegerArray; overload; cdecl;
    function Add(const items: TIntegerArray; const duplicates: Boolean = True): TIntegerArray; overload; cdecl;
    function AllEqual: Boolean; overload; cdecl;
    function AllSame: Boolean; overload cdecl;
    function AllUnique: Boolean; overload; cdecl;
    function Append(const item: Integer; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Append(const items: TIntegerArray; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Build(const item: Integer; const aSize: Integer = 1): TIntegerArray; overload; cdecl;
    function BuiltWith(const allowed: TIntegerArray): Boolean; overload; cdecl;
    function BuiltWithout(const forbidden: TIntegerArray): Boolean; overload; cdecl;
    function Create(const item: Integer): TIntegerArray; overload; cdecl;
    function Create(const aSize: Integer; const item: Integer): TIntegerArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; cdecl;
    function Clone(const ID: TIntegerArray): TIntegerArray; overload; cdecl;
    function Combine(const b: TIntegerArray): TIntegerArray; overload; cdecl;
    function Contains(const item: Integer; const index: Integer = 0): Boolean; cdecl;
    function Copy(const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Delete(const index: Integer = 0): Boolean; overload; cdecl;
    function Delete(const ID: TIntegerArray): Integer; overload; cdecl;
    function Differ(const target: TIntegerArray): Boolean; overload; cdecl;
    function Distribute(const parts: Integer): T2DIntegerArray; overload; cdecl;
    function Dump(const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl;
    function Dupe: TIntegerArray; overload; cdecl;
    function Duplicate(const xTimes: Integer = 1): TIntegerArray; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Equal(const target: TIntegerArray): Boolean; overload; cdecl;
    function Exch(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Exchange(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Extend(const item: Integer): TIntegerArray; overload; cdecl;
    function Extend(const items: TIntegerArray): TIntegerArray; overload; cdecl;
    function Extract(const item: Integer; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Extract(const items: TIntegerArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function ExtractEvery(const X: Integer = 1; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Fill(const item: Integer; const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Fill(const items: TIntegerArray; const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Filter(const item: Integer; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Filter(const items: TIntegerArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function FilterEvery(const X: Integer = 1; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Find(const ID: TRange; const item: Integer): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const item: Integer): Integer; overload; cdecl;
    function Find(const ID: TRange; const items: TIntegerArray): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const items: TIntegerArray): Integer; overload; cdecl;
    function Flip: Boolean; overload; cdecl;
    function FromLeft(const count: Integer; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function FromRight(const count: Integer; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Get: TIntegerArray; overload; cdecl;
    function Get(const ID: TIntegerArray): TIntegerArray; overload; cdecl;
    function Get(const ID: TRange): TIntegerArray; overload; cdecl;
    function Group: T2DIntegerArray; overload; cdecl;
    function Holds(const chain: TIntegerArray): Boolean; overload; cdecl;
    function IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl;
    function IDs(const ID: TIntegerArray): TIntegerArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const item: Integer): TIntegerArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl;
    function Includes(const item: Integer; const index: Integer = 2147483647): Boolean; cdecl;
    function Keep(const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl;
    function LeastFrequent: Integer; overload; cdecl;
    function Len: Integer; overload; cdecl;
    function Len(const aSize: Integer): Integer; overload; cdecl;
    function Len(const aSize: Integer; const null: Integer): Integer; overload; cdecl;
    function Loc(const item: Integer; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Loc(const items: TIntegerArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const item: Integer; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const items: TIntegerArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Locations(const item: Integer; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Locations(const items: TIntegerArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Mix(const shuffles: Integer = 1): Boolean; overload; cdecl;
    function MostFrequent: Integer; overload; cdecl;
    function Move(const oldIndex, newIndex: Integer): Boolean; overload cdecl;
	function Next(const index: Integer; const count: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Oversize(const limit: Integer): Boolean; overload; cdecl;
    function Partition(const pSize: Integer): T2DIntegerArray; overload; cdecl;
    function Pick(const ID: TIntegerArray): TIntegerArray; overload; cdecl;
    function Pop: Integer; overload; cdecl;
    function Pop(const null: Integer): Integer; overload; cdecl;
    function Pos(const item: Integer; const index: Integer = 0): Integer; overload; cdecl;
    function Pos(const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const item: Integer; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl;
    function Positions(const item: Integer; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Positions(const items: TIntegerArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Previous(const index: Integer; const count: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Push(const item: Integer): Integer; overload; cdecl;
    function Push(const items: TIntegerArray): Integer; overload; cdecl;
    function Put(const ID: TIntegerArray; const item: Integer): TIntegerArray; overload; cdecl;
    function Put(const ID: TIntegerArray; const items: TIntegerArray): TIntegerArray; overload; cdecl;
    function Put(const index: Integer; const items: TIntegerArray): TIntegerArray; overload; cdecl;
    function Remove(const item: Integer; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const item: Integer; const all: Boolean): Integer; overload; cdecl;
    function Remove(const items: TIntegerArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const items: TIntegerArray; const all: Boolean): Integer; overload; cdecl;
    function Resize(const aChange: Integer): Integer; overload; cdecl;
    function Resize(const aChange: Integer; const null: Integer): Integer; overload; cdecl;
    function Reverse: Boolean; overload; cdecl;
    function Reversed: TIntegerArray; overload; cdecl;
    function Scan(const ID: TRange; const item: Integer; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const item: Integer; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TRange; const items: TIntegerArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const items: TIntegerArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Shift: Integer; overload; cdecl;
    function Shift(const sCount: Integer): TIntegerArray; overload; cdecl;
    function Size(const aSize: Integer): Integer; overload; cdecl;
    function Size: Integer; overload; cdecl;
    function SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl;
    function SizeMax(const target: Integer): Boolean; overload; cdecl;
    function SizeMin(const target: Integer): Boolean; overload; cdecl;
    function SubarrayLocation(const pattern: TIntegerArray): Integer; overload; cdecl;
    function SubarrayLocations(const pattern: TIntegerArray): TIntegerArray; overload; cdecl;
    function SubarrayPosition(const pattern: TIntegerArray): Integer; overload; cdecl;
    function SubarrayPositions(const pattern: TIntegerArray): TIntegerArray; overload; cdecl;
    function Swap(var b: TIntegerArray): Integer; overload; cdecl;
    function Undersize(const limit: Integer): Boolean; overload; cdecl;
    function Trade(var b: TIntegerArray): Integer; overload; cdecl;
    function Unique: Integer; overload; cdecl;
    function Uniqued: TIntegerArray; overload; cdecl;
    function Uniques: TIntegerArray; overload; cdecl;
    function Unshift(const item: Integer): Integer; overload; cdecl;
    function Unshift(const items: TIntegerArray): Integer; overload; cdecl;

    function Descend: Boolean; cdecl;
    function Ascend: Boolean; cdecl;
    function Bounds: TRange; overload; cdecl;
    function Bounds(var aSize: Integer): TRange; overload; cdecl;
    function Range: TRange; cdecl;
    function Undupe: Integer; cdecl;
    function Unduped: TIntegerArray; cdecl;
    function Numberline: TIntegerArray; cdecl;
    function Lowest: Integer; cdecl;
    function Highest: Integer; cdecl;
    function Mini(const ascending: Boolean = True; const start: Integer = -1): Integer; overload; cdecl;
    function Mini(const start: Integer; const ascending: Boolean = True): Integer; overload; cdecl;
    function Maxi(const ascending: Boolean = True; const start: Integer = -1): Integer; overload; cdecl;
    function Maxi(const start: Integer; const ascending: Boolean = True): Integer; overload; cdecl;
    function Sum: Int64; cdecl;
    function Density: Double; cdecl;
    function Mean: Double; cdecl;
    function Mode: Integer; cdecl;
    function Median: Double; cdecl;
    function Middle: Double; cdecl;
    function Center: Integer; cdecl;
    function MostFreq(const null: Integer = -2147483648): Integer; cdecl;
    function LeastFreq(const null: Integer = -2147483648): Integer; cdecl;
    function BubbleSort(const ascending: Boolean = True): Integer; cdecl;
    function BubbleSort2(const ascending: Boolean = True): Integer; cdecl;
    function BubbleSortOptimized(const ascending: Boolean = True): Integer; cdecl;
    function QuickSort(const ascending: Boolean = True): Integer; cdecl;
    function QuickSort3W(const ascending: Boolean = True): Integer; cdecl;
    function QSort(const ascending: Boolean = True): Integer; cdecl;
    function CoctailSort(const ascending: Boolean = True): Integer; cdecl;
    function CoctailSort2(const ascending: Boolean = True): Integer; cdecl;
    function CombSort(const ascending: Boolean = True): Integer; cdecl;
    function GnomeSort(const ascending: Boolean = True): Integer; cdecl;
    function GnomeSortOptimized(const ascending: Boolean = True): Integer; cdecl;
    function HeapSort(const ascending: Boolean = True): Integer; cdecl;
    function InsertionSort(const ascending: Boolean = True): Integer; cdecl;
    function SelectionSort(const ascending: Boolean = True): Integer; cdecl;
    function SelectionSortBidirectional(const ascending: Boolean = True): Integer; cdecl;
    function SelectionSortBidirectional2(const ascending: Boolean = True): Integer; cdecl;
    function PancakeSort(const ascending: Boolean = True): Integer; cdecl;
    function MergeSort(const ascending: Boolean = True): Integer; cdecl;
    function MergeSortBU(const ascending: Boolean = True): Integer; cdecl;
    function ShellSort(const ascending: Boolean = True): Integer; cdecl;
    function BSort(const ascending: Boolean = True): Integer; cdecl;
    function BinarySort(const ascending: Boolean = True): Integer; cdecl;
    function BinarySorted(const ascending: Boolean = True): TIntegerArray; cdecl;
    function BinaryBoundL(const x: Integer; const ascending: Boolean = True): Integer; cdecl;
    function BinaryBoundR(const x: Integer; const ascending: Boolean = True): Integer; cdecl;
    function BinaryPosL(const x: Integer; const ascending: Boolean = True): Integer; cdecl;
    function BinaryPosR(const x: Integer; const ascending: Boolean = True): Integer; cdecl;
    function BinarySearch(const x: Integer; const ascending: Boolean = True): Integer; cdecl;
    function BinaryContains(const x: Integer; const ascending: Boolean = True): Boolean; cdecl;
    function BinaryLocate(const x: Integer; const ascending: Boolean = True): TRange; cdecl;
    function BinaryLocation(const x: Integer; const ascending: Boolean = True): TRange; cdecl;
    function BinaryAppend(const x: Integer; const ascending: Boolean = True): Integer; cdecl;
    function BinaryAdd(const x: Integer; const ascending: Boolean = True): TIntegerArray; cdecl;
    function BinarySearchF(const x: TRange; const ascending: Boolean = True): Integer; cdecl;
    function BinarySearchL(const x: TRange; const ascending: Boolean = True): Integer; cdecl;
    function BinaryUnique(const ascending: Boolean = True): Integer; cdecl;
    function BinaryUniqued(const ascending: Boolean = True): TIntegerArray; cdecl;
    function Split(const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
    function Split(const diff: Integer): T2DIntegerArray; overload; cdecl;
    function Sblit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
    function Sblit(const diff: Integer): T2DIntegerArray; overload; cdecl;
    function Group(const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
    function Group(const diff: Integer): T2DIntegerArray; overload; cdecl;
    function Groub(const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
    function Groub(const diff: Integer): T2DIntegerArray; overload; cdecl;
    function Invert: TIntegerArray; cdecl;
  end;
  TDoubleArrayHelper = type helper for TDoubleArray
    function Add(const item: Double; const duplicates: Boolean = True): TDoubleArray; overload; cdecl;
    function Add(const items: TDoubleArray; const duplicates: Boolean = True): TDoubleArray; overload; cdecl;
    function AllEqual: Boolean; overload; cdecl;
    function AllSame: Boolean; overload cdecl;
    function AllUnique: Boolean; overload; cdecl;
    function Append(const item: Double; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Append(const items: TDoubleArray; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Build(const item: Double; const aSize: Integer = 1): TDoubleArray; overload; cdecl;
    function BuiltWith(const allowed: TDoubleArray): Boolean; overload; cdecl;
    function BuiltWithout(const forbidden: TDoubleArray): Boolean; overload; cdecl;
    function Create(const item: Double): TDoubleArray; overload; cdecl;
    function Create(const aSize: Integer; const item: Double): TDoubleArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; cdecl;
    function Clone(const ID: TIntegerArray): TDoubleArray; overload; cdecl;
    function Combine(const b: TDoubleArray): TDoubleArray; overload; cdecl;
    function Contains(const item: Double; const index: Integer = 0): Boolean; cdecl;
    function Copy(const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl;
    function Delete(const index: Integer = 0): Boolean; overload; cdecl;
    function Delete(const ID: TIntegerArray): Integer; overload; cdecl;
    function Differ(const target: TDoubleArray): Boolean; overload; cdecl;
    function Distribute(const parts: Integer): T2DDoubleArray; overload; cdecl;
    function Dump(const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl;
    function Dupe: TDoubleArray; overload; cdecl;
    function Duplicate(const xTimes: Integer = 1): TDoubleArray; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Equal(const target: TDoubleArray): Boolean; overload; cdecl;
    function Exch(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Exchange(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Extend(const item: Double): TDoubleArray; overload; cdecl;
    function Extend(const items: TDoubleArray): TDoubleArray; overload; cdecl;
    function Extract(const item: Double; const index: Integer = 0): TDoubleArray; overload; cdecl;
    function Extract(const items: TDoubleArray; const index: Integer = 0): TDoubleArray; overload; cdecl;
    function ExtractEvery(const X: Integer = 1; const index: Integer = 0): TDoubleArray; overload; cdecl;
    function Fill(const item: Double; const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl;
    function Fill(const items: TDoubleArray; const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl;
    function Filter(const item: Double; const index: Integer = 0): TDoubleArray; overload; cdecl;
    function Filter(const items: TDoubleArray; const index: Integer = 0): TDoubleArray; overload; cdecl;
    function FilterEvery(const X: Integer = 1; const index: Integer = 0): TDoubleArray; overload; cdecl;
    function Find(const ID: TRange; const item: Double): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const item: Double): Integer; overload; cdecl;
    function Find(const ID: TRange; const items: TDoubleArray): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const items: TDoubleArray): Integer; overload; cdecl;
    function Flip: Boolean; overload; cdecl;
    function FromLeft(const count: Integer; const index: Integer = 2147483647): TDoubleArray; overload; cdecl;
    function FromRight(const count: Integer; const index: Integer = 0): TDoubleArray; overload; cdecl;
    function Get: TDoubleArray; overload; cdecl;
    function Get(const ID: TIntegerArray): TDoubleArray; overload; cdecl;
    function Get(const ID: TRange): TDoubleArray; overload; cdecl;
    function Group: T2DDoubleArray; overload; cdecl;
    function Holds(const chain: TDoubleArray): Boolean; overload; cdecl;
    function IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl;
    function IDs(const ID: TIntegerArray): TDoubleArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const item: Double): TDoubleArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const items: TDoubleArray): TDoubleArray; overload; cdecl;
    function Includes(const item: Double; const index: Integer = 2147483647): Boolean; cdecl;
    function Keep(const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl;
    function LeastFrequent: Double; overload; cdecl;
    function Len: Integer; overload; cdecl;
    function Len(const aSize: Integer): Integer; overload; cdecl;
    function Len(const aSize: Integer; const null: Double): Integer; overload; cdecl;
    function Loc(const item: Double; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Loc(const items: TDoubleArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const item: Double; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const items: TDoubleArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Locations(const item: Double; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Locations(const items: TDoubleArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Mix(const shuffles: Integer = 1): Boolean; overload; cdecl;
    function MostFrequent: Double; overload; cdecl;
    function Move(const oldIndex, newIndex: Integer): Boolean; overload; cdecl;
    function Next(const index: Integer; const count: Integer = 2147483647): TDoubleArray; overload; cdecl;
    function Oversize(const limit: Integer): Boolean; overload; cdecl;
    function Partition(const pSize: Integer): T2DDoubleArray; overload; cdecl;
    function Pick(const ID: TIntegerArray): TDoubleArray; overload; cdecl;
    function Pop: Double; overload; cdecl;
    function Pop(const null: Double): Double; overload; cdecl;
    function Pos(const item: Double; const index: Integer = 0): Integer; overload; cdecl;
    function Pos(const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const item: Double; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl;
    function Positions(const item: Double; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Positions(const items: TDoubleArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Previous(const index: Integer; const count: Integer = 2147483647): TDoubleArray; overload; cdecl;
    function Push(const item: Double): Integer; overload; cdecl;
    function Push(const items: TDoubleArray): Integer; overload; cdecl;
    function Put(const ID: TIntegerArray; const item: Double): TDoubleArray; overload; cdecl;
    function Put(const ID: TIntegerArray; const items: TDoubleArray): TDoubleArray; overload; cdecl;
    function Put(const index: Integer; const items: TDoubleArray): TDoubleArray; overload; cdecl;
    function Remove(const item: Double; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const item: Double; const all: Boolean): Integer; overload; cdecl;
    function Remove(const items: TDoubleArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const items: TDoubleArray; const all: Boolean): Integer; overload; cdecl;
    function Resize(const aChange: Integer): Integer; overload; cdecl;
    function Resize(const aChange: Integer; const null: Double): Integer; overload; cdecl;
    function Reverse: Boolean; overload; cdecl;
    function Reversed: TDoubleArray; overload; cdecl;
    function Scan(const ID: TRange; const item: Double; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const item: Double; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TRange; const items: TDoubleArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const items: TDoubleArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Shift: Double; overload; cdecl;
    function Shift(const sCount: Integer): TDoubleArray; overload; cdecl;
    function Size(const aSize: Integer): Integer; overload; cdecl;
    function Size: Integer; overload; cdecl;
    function SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl;
    function SizeMax(const target: Integer): Boolean; overload; cdecl;
    function SizeMin(const target: Integer): Boolean; overload; cdecl;
    function SubarrayLocation(const pattern: TDoubleArray): Integer; overload; cdecl;
    function SubarrayLocations(const pattern: TDoubleArray): TIntegerArray; overload; cdecl;
    function SubarrayPosition(const pattern: TDoubleArray): Integer; overload; cdecl;
    function SubarrayPositions(const pattern: TDoubleArray): TIntegerArray; overload; cdecl;
    function Swap(var b: TDoubleArray): Integer; overload; cdecl;
    function Undersize(const limit: Integer): Boolean; overload; cdecl;
    function Trade(var b: TDoubleArray): Integer; overload; cdecl;
    function Unique: Integer; overload; cdecl;
    function Uniqued: TDoubleArray; overload; cdecl;
    function Uniques: TIntegerArray; overload; cdecl;
    function Unshift(const item: Double): Integer; overload; cdecl;
    function Unshift(const items: TDoubleArray): Integer; overload; cdecl;
  end;
  TStringArrayHelper = type helper for TStringArray
    function Add(const item: string; const duplicates: Boolean = True): TStringArray; overload; cdecl;
    function Add(const items: TStringArray; const duplicates: Boolean = True): TStringArray; overload; cdecl;
    function AllEqual: Boolean; overload; cdecl;
    function AllSame: Boolean; overload cdecl;
    function AllUnique: Boolean; overload; cdecl;
    function Append(const item: string; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Append(const items: TStringArray; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Build(const item: string; const aSize: Integer = 1): TStringArray; overload; cdecl;
    function BuiltWith(const allowed: TStringArray): Boolean; overload; cdecl;
    function BuiltWithout(const forbidden: TStringArray): Boolean; overload; cdecl;
    function Create(const item: string): TStringArray; overload; cdecl;
    function Create(const aSize: Integer; const item: string): TStringArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TStringArray; cdecl;
    function Clone(const ID: TIntegerArray): TStringArray; overload; cdecl;
    function Combine(const b: TStringArray): TStringArray; overload; cdecl;
    function Contains(const item: string; const index: Integer = 0): Boolean; cdecl;
    function Copy(const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl;
    function Delete(const index: Integer = 0): Boolean; overload; cdecl;
    function Delete(const ID: TIntegerArray): Integer; overload; cdecl;
    function Differ(const target: TStringArray): Boolean; overload; cdecl;
    function Distribute(const parts: Integer): T2DStringArray; overload; cdecl;
    function Dump(const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl;
    function Dupe: TStringArray; overload; cdecl;
    function Duplicate(const xTimes: Integer = 1): TStringArray; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Equal(const target: TStringArray): Boolean; overload; cdecl;
    function Exch(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Exchange(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Extend(const item: string): TStringArray; overload; cdecl;
    function Extend(const items: TStringArray): TStringArray; overload; cdecl;
    function Extract(const item: string; const index: Integer = 0): TStringArray; overload; cdecl;
    function Extract(const items: TStringArray; const index: Integer = 0): TStringArray; overload; cdecl;
    function ExtractEvery(const X: Integer = 1; const index: Integer = 0): TStringArray; overload; cdecl;
    function Fill(const item: string; const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl;
    function Fill(const items: TStringArray; const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl;
    function Filter(const item: string; const index: Integer = 0): TStringArray; overload; cdecl;
    function Filter(const items: TStringArray; const index: Integer = 0): TStringArray; overload; cdecl;
    function FilterEvery(const X: Integer = 1; const index: Integer = 0): TStringArray; overload; cdecl;
    function Find(const ID: TRange; const item: string): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const item: string): Integer; overload; cdecl;
    function Find(const ID: TRange; const items: TStringArray): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const items: TStringArray): Integer; overload; cdecl;
    function Flip: Boolean; overload; cdecl;
    function FromLeft(const count: Integer; const index: Integer = 2147483647): TStringArray; overload; cdecl;
    function FromRight(const count: Integer; const index: Integer = 0): TStringArray; overload; cdecl;
    function Get: TStringArray; overload; cdecl;
    function Get(const ID: TIntegerArray): TStringArray; overload; cdecl;
    function Get(const ID: TRange): TStringArray; overload; cdecl;
    function Group: T2DStringArray; overload; cdecl;
    function Holds(const chain: TStringArray): Boolean; overload; cdecl;
    function IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl;
    function IDs(const ID: TIntegerArray): TStringArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const item: string): TStringArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const items: TStringArray): TStringArray; overload; cdecl;
    function Includes(const item: string; const index: Integer = 2147483647): Boolean; cdecl;
    function Keep(const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl;
    function LeastFrequent: string; overload; cdecl;
    function Len: Integer; overload; cdecl;
    function Len(const aSize: Integer): Integer; overload; cdecl;
    function Len(const aSize: Integer; const null: string): Integer; overload; cdecl;
    function Loc(const item: string; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Loc(const items: TStringArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const item: string; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const items: TStringArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Locations(const item: string; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Locations(const items: TStringArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Mix(const shuffles: Integer = 1): Boolean; overload; cdecl;
    function MostFrequent: string; overload; cdecl;
    function Move(const oldIndex, newIndex: Integer): Boolean; overload cdecl;
    function Next(const index: Integer; const count: Integer = 2147483647): TStringArray; overload; cdecl;
    function Oversize(const limit: Integer): Boolean; overload; cdecl;
    function Partition(const pSize: Integer): T2DStringArray; overload; cdecl;
    function Pick(const ID: TIntegerArray): TStringArray; overload; cdecl;
    function Pop: string; overload; cdecl;
    function Pop(const null: string): string; overload; cdecl;
    function Pos(const item: string; const index: Integer = 0): Integer; overload; cdecl;
    function Pos(const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const item: string; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl;
    function Positions(const item: string; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Positions(const items: TStringArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Previous(const index: Integer; const count: Integer = 2147483647): TStringArray; overload; cdecl;
    function Push(const item: string): Integer; overload; cdecl;
    function Push(const items: TStringArray): Integer; overload; cdecl;
    function Put(const ID: TIntegerArray; const item: string): TStringArray; overload; cdecl;
    function Put(const ID: TIntegerArray; const items: TStringArray): TStringArray; overload; cdecl;
    function Put(const index: Integer; const items: TStringArray): TStringArray; overload; cdecl;
    function Remove(const item: string; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const item: string; const all: Boolean): Integer; overload; cdecl;
    function Remove(const items: TStringArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const items: TStringArray; const all: Boolean): Integer; overload; cdecl;
    function Resize(const aChange: Integer): Integer; overload; cdecl;
    function Resize(const aChange: Integer; const null: string): Integer; overload; cdecl;
    function Reverse: Boolean; overload; cdecl;
    function Reversed: TStringArray; overload; cdecl;
    function Scan(const ID: TRange; const item: string; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const item: string; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TRange; const items: TStringArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const items: TStringArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Shift: string; overload; cdecl;
    function Shift(const sCount: Integer): TStringArray; overload; cdecl;
    function Size(const aSize: Integer): Integer; overload; cdecl;
    function Size: Integer; overload; cdecl;
    function SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl;
    function SizeMax(const target: Integer): Boolean; overload; cdecl;
    function SizeMin(const target: Integer): Boolean; overload; cdecl;
    function SubarrayLocation(const pattern: TStringArray): Integer; overload; cdecl;
    function SubarrayLocations(const pattern: TStringArray): TIntegerArray; overload; cdecl;
    function SubarrayPosition(const pattern: TStringArray): Integer; overload; cdecl;
    function SubarrayPositions(const pattern: TStringArray): TIntegerArray; overload; cdecl;
    function Swap(var b: TStringArray): Integer; overload; cdecl;
    function Undersize(const limit: Integer): Boolean; overload; cdecl;
    function Trade(var b: TStringArray): Integer; overload; cdecl;
    function Unique: Integer; overload; cdecl;
    function Uniqued: TStringArray; overload; cdecl;
    function Uniques: TIntegerArray; overload; cdecl;
    function Unshift(const item: string): Integer; overload; cdecl;
    function Unshift(const items: TStringArray): Integer; overload; cdecl;
  end;
  TCharArrayHelper = type helper for TCharArray
    function Add(const item: Char; const duplicates: Boolean = True): TCharArray; overload; cdecl;
    function Add(const items: TCharArray; const duplicates: Boolean = True): TCharArray; overload; cdecl;
    function AllEqual: Boolean; overload; cdecl;
    function AllSame: Boolean; overload cdecl;
    function AllUnique: Boolean; overload; cdecl;
    function Append(const item: Char; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Append(const items: TCharArray; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Build(const item: Char; const aSize: Integer = 1): TCharArray; overload; cdecl;
    function BuiltWith(const allowed: TCharArray): Boolean; overload; cdecl;
    function BuiltWithout(const forbidden: TCharArray): Boolean; overload; cdecl;
    function Create(const item: Char): TCharArray; overload; cdecl;
    function Create(const aSize: Integer; const item: Char): TCharArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TCharArray; cdecl;
    function Clone(const ID: TIntegerArray): TCharArray; overload; cdecl;
    function Combine(const b: TCharArray): TCharArray; overload; cdecl;
    function Contains(const item: Char; const index: Integer = 0): Boolean; cdecl;
    function Copy(const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl;
    function Delete(const index: Integer = 0): Boolean; overload; cdecl;
    function Delete(const ID: TIntegerArray): Integer; overload; cdecl;
    function Differ(const target: TCharArray): Boolean; overload; cdecl;
    function Distribute(const parts: Integer): T2DCharArray; overload; cdecl;
    function Dump(const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl;
    function Dupe: TCharArray; overload; cdecl;
    function Duplicate(const xTimes: Integer = 1): TCharArray; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Equal(const target: TCharArray): Boolean; overload; cdecl;
    function Exch(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
	function Exchange(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Extend(const item: Char): TCharArray; overload; cdecl;
    function Extend(const items: TCharArray): TCharArray; overload; cdecl;
    function Extract(const item: Char; const index: Integer = 0): TCharArray; overload; cdecl;
    function Extract(const items: TCharArray; const index: Integer = 0): TCharArray; overload; cdecl;
    function ExtractEvery(const X: Integer = 1; const index: Integer = 0): TCharArray; overload; cdecl;
    function Fill(const item: Char; const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl;
    function Fill(const items: TCharArray; const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl;
    function Filter(const item: Char; const index: Integer = 0): TCharArray; overload; cdecl;
    function Filter(const items: TCharArray; const index: Integer = 0): TCharArray; overload; cdecl;
    function FilterEvery(const X: Integer = 1; const index: Integer = 0): TCharArray; overload; cdecl;
    function Find(const ID: TRange; const item: Char): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const item: Char): Integer; overload; cdecl;
    function Find(const ID: TRange; const items: TCharArray): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const items: TCharArray): Integer; overload; cdecl;
    function Flip: Boolean; overload; cdecl;
    function FromLeft(const count: Integer; const index: Integer = 2147483647): TCharArray; overload; cdecl;
    function FromRight(const count: Integer; const index: Integer = 0): TCharArray; overload; cdecl;
    function Get: TCharArray; overload; cdecl;
    function Get(const ID: TIntegerArray): TCharArray; overload; cdecl;
    function Get(const ID: TRange): TCharArray; overload; cdecl;
    function Group: T2DCharArray; overload; cdecl;
    function Holds(const chain: TCharArray): Boolean; overload; cdecl;
    function IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl;
    function IDs(const ID: TIntegerArray): TCharArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const item: Char): TCharArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl;
    function Includes(const item: Char; const index: Integer = 2147483647): Boolean; cdecl;
    function Keep(const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl;
    function LeastFrequent: Char; overload; cdecl;
    function Len: Integer; overload; cdecl;
    function Len(const aSize: Integer): Integer; overload; cdecl;
    function Len(const aSize: Integer; const null: Char): Integer; overload; cdecl;
    function Loc(const item: Char; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Loc(const items: TCharArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const item: Char; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const items: TCharArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Locations(const item: Char; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Locations(const items: TCharArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Mix(const shuffles: Integer = 1): Boolean; overload; cdecl;
    function MostFrequent: Char; overload; cdecl;
    function Move(const oldIndex, newIndex: Integer): Boolean; overload cdecl;
    function Next(const index: Integer; const count: Integer = 2147483647): TCharArray; overload; cdecl;
    function Oversize(const limit: Integer): Boolean; overload; cdecl;
    function Partition(const pSize: Integer): T2DCharArray; overload; cdecl;
    function Pick(const ID: TIntegerArray): TCharArray; overload; cdecl;
    function Pop: Char; overload; cdecl;
    function Pop(const null: Char): Char; overload; cdecl;
    function Pos(const item: Char; const index: Integer = 0): Integer; overload; cdecl;
    function Pos(const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const item: Char; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl;
    function Positions(const item: Char; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Positions(const items: TCharArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Previous(const index: Integer; const count: Integer = 2147483647): TCharArray; overload; cdecl;
    function Push(const item: Char): Integer; overload; cdecl;
    function Push(const items: TCharArray): Integer; overload; cdecl;
    function Put(const ID: TIntegerArray; const item: Char): TCharArray; overload; cdecl;
    function Put(const ID: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl;
    function Put(const index: Integer; const items: TCharArray): TCharArray; overload; cdecl;	
    function Remove(const item: Char; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const item: Char; const all: Boolean): Integer; overload; cdecl;
    function Remove(const items: TCharArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const items: TCharArray; const all: Boolean): Integer; overload; cdecl;
    function Resize(const aChange: Integer): Integer; overload; cdecl;
    function Resize(const aChange: Integer; const null: Char): Integer; overload; cdecl;
    function Reverse: Boolean; overload; cdecl;
    function Reversed: TCharArray; overload; cdecl;
    function Scan(const ID: TRange; const item: Char; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const item: Char; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TRange; const items: TCharArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const items: TCharArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Shift: Char; overload; cdecl;
    function Shift(const sCount: Integer): TCharArray; overload; cdecl;
    function Size(const aSize: Integer): Integer; overload; cdecl;
    function Size: Integer; overload; cdecl;
    function SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl;
    function SizeMax(const target: Integer): Boolean; overload; cdecl;
    function SizeMin(const target: Integer): Boolean; overload; cdecl;
    function SubarrayLocation(const pattern: TCharArray): Integer; overload; cdecl;
    function SubarrayLocations(const pattern: TCharArray): TIntegerArray; overload; cdecl;
    function SubarrayPosition(const pattern: TCharArray): Integer; overload; cdecl;
    function SubarrayPositions(const pattern: TCharArray): TIntegerArray; overload; cdecl;
    function Swap(var b: TCharArray): Integer; overload; cdecl;
    function Undersize(const limit: Integer): Boolean; overload; cdecl;
    function Trade(var b: TCharArray): Integer; overload; cdecl;
    function Unique: Integer; overload; cdecl;
    function Uniqued: TCharArray; overload; cdecl;
    function Uniques: TIntegerArray; overload; cdecl;
    function Unshift(const item: Char): Integer; overload; cdecl;
    function Unshift(const items: TCharArray): Integer; overload; cdecl;
  end;
  TBooleanArrayHelper = type helper for TBooleanArray
    function Add(const item: Boolean; const duplicates: Boolean = True): TBooleanArray; overload; cdecl;
    function Add(const items: TBooleanArray; const duplicates: Boolean = True): TBooleanArray; overload; cdecl;
    function AllEqual: Boolean; overload; cdecl;
    function AllSame: Boolean; overload cdecl;
    function AllUnique: Boolean; overload; cdecl;
    function Append(const item: Boolean; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Append(const items: TBooleanArray; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Build(const item: Boolean; const aSize: Integer = 1): TBooleanArray; overload; cdecl;
    function BuiltWith(const allowed: TBooleanArray): Boolean; overload; cdecl;
    function BuiltWithout(const forbidden: TBooleanArray): Boolean; overload; cdecl;
    function Create(const item: Boolean): TBooleanArray; overload; cdecl;
    function Create(const aSize: Integer; const item: Boolean): TBooleanArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; cdecl;
    function Clone(const ID: TIntegerArray): TBooleanArray; overload; cdecl;
    function Combine(const b: TBooleanArray): TBooleanArray; overload; cdecl;
    function Contains(const item: Boolean; const index: Integer = 0): Boolean; cdecl;
    function Copy(const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl;
    function Delete(const index: Integer = 0): Boolean; overload; cdecl;
    function Delete(const ID: TIntegerArray): Integer; overload; cdecl;
    function Differ(const target: TBooleanArray): Boolean; overload; cdecl;
    function Distribute(const parts: Integer): T2DBooleanArray; overload; cdecl;
    function Dump(const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl;
    function Dupe: TBooleanArray; overload; cdecl;
    function Duplicate(const xTimes: Integer = 1): TBooleanArray; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Equal(const target: TBooleanArray): Boolean; overload; cdecl;
    function Exch(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Exchange(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Extend(const item: Boolean): TBooleanArray; overload; cdecl;
    function Extend(const items: TBooleanArray): TBooleanArray; overload; cdecl;
    function Extract(const item: Boolean; const index: Integer = 0): TBooleanArray; overload; cdecl;
    function Extract(const items: TBooleanArray; const index: Integer = 0): TBooleanArray; overload; cdecl;
    function ExtractEvery(const X: Integer = 1; const index: Integer = 0): TBooleanArray; overload; cdecl;
    function Fill(const item: Boolean; const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl;
    function Fill(const items: TBooleanArray; const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl;
    function Filter(const item: Boolean; const index: Integer = 0): TBooleanArray; overload; cdecl;
    function Filter(const items: TBooleanArray; const index: Integer = 0): TBooleanArray; overload; cdecl;
    function FilterEvery(const X: Integer = 1; const index: Integer = 0): TBooleanArray; overload; cdecl;
    function Find(const ID: TRange; const item: Boolean): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const item: Boolean): Integer; overload; cdecl;
    function Find(const ID: TRange; const items: TBooleanArray): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const items: TBooleanArray): Integer; overload; cdecl;
    function Flip: Boolean; overload; cdecl;
    function FromLeft(const count: Integer; const index: Integer = 2147483647): TBooleanArray; overload; cdecl;
    function FromRight(const count: Integer; const index: Integer = 0): TBooleanArray; overload; cdecl;
    function Get: TBooleanArray; overload; cdecl;
    function Get(const ID: TIntegerArray): TBooleanArray; overload; cdecl;
    function Get(const ID: TRange): TBooleanArray; overload; cdecl;
    function Group: T2DBooleanArray; overload; cdecl;
    function Holds(const chain: TBooleanArray): Boolean; overload; cdecl;
    function IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl;
    function IDs(const ID: TIntegerArray): TBooleanArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const item: Boolean): TBooleanArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const items: TBooleanArray): TBooleanArray; overload; cdecl; 
    function Includes(const item: Boolean; const index: Integer = 2147483647): Boolean; cdecl;
    function Keep(const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl;
    function LeastFrequent: Boolean; overload; cdecl;
    function Len: Integer; overload; cdecl;
    function Len(const aSize: Integer): Integer; overload; cdecl;
    function Len(const aSize: Integer; const null: Boolean): Integer; overload; cdecl;
    function Loc(const item: Boolean; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Loc(const items: TBooleanArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const item: Boolean; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const items: TBooleanArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Locations(const item: Boolean; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Locations(const items: TBooleanArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Mix(const shuffles: Integer = 1): Boolean; overload; cdecl;
    function MostFrequent: Boolean; overload; cdecl;
    function Move(const oldIndex, newIndex: Integer): Boolean; overload cdecl;
    function Next(const index: Integer; const count: Integer = 2147483647): TBooleanArray; overload; cdecl;
    function Oversize(const limit: Integer): Boolean; overload; cdecl;
    function Partition(const pSize: Integer): T2DBooleanArray; overload; cdecl;
    function Pick(const ID: TIntegerArray): TBooleanArray; overload; cdecl;
    function Pop: Boolean; overload; cdecl;
    function Pop(const null: Boolean): Boolean; overload; cdecl;
    function Pos(const item: Boolean; const index: Integer = 0): Integer; overload; cdecl;
    function Pos(const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const item: Boolean; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl;
    function Positions(const item: Boolean; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Positions(const items: TBooleanArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Previous(const index: Integer; const count: Integer = 2147483647): TBooleanArray; overload; cdecl;
    function Push(const item: Boolean): Integer; overload; cdecl;
    function Push(const items: TBooleanArray): Integer; overload; cdecl;
    function Put(const ID: TIntegerArray; const item: Boolean): TBooleanArray; overload; cdecl;
    function Put(const ID: TIntegerArray; const items: TBooleanArray): TBooleanArray; overload; cdecl;
    function Put(const index: Integer; const items: TBooleanArray): TBooleanArray; overload; cdecl;
    function Remove(const item: Boolean; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const item: Boolean; const all: Boolean): Integer; overload; cdecl;
    function Remove(const items: TBooleanArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const items: TBooleanArray; const all: Boolean): Integer; overload; cdecl;
    function Resize(const aChange: Integer): Integer; overload; cdecl;
    function Resize(const aChange: Integer; const null: Boolean): Integer; overload; cdecl;
    function Reverse: Boolean; overload; cdecl;
    function Reversed: TBooleanArray; overload; cdecl;
    function Scan(const ID: TRange; const item: Boolean; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const item: Boolean; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TRange; const items: TBooleanArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const items: TBooleanArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Shift: Boolean; overload; cdecl;
    function Shift(const sCount: Integer): TBooleanArray; overload; cdecl;
    function Size(const aSize: Integer): Integer; overload; cdecl;
    function Size: Integer; overload; cdecl;
    function SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl;
    function SizeMax(const target: Integer): Boolean; overload; cdecl;
    function SizeMin(const target: Integer): Boolean; overload; cdecl;
    function SubarrayLocation(const pattern: TBooleanArray): Integer; overload; cdecl;
    function SubarrayLocations(const pattern: TBooleanArray): TIntegerArray; overload; cdecl;
    function SubarrayPosition(const pattern: TBooleanArray): Integer; overload; cdecl;
    function SubarrayPositions(const pattern: TBooleanArray): TIntegerArray; overload; cdecl;
    function Swap(var b: TBooleanArray): Integer; overload; cdecl;
    function Undersize(const limit: Integer): Boolean; overload; cdecl;
    function Trade(var b: TBooleanArray): Integer; overload; cdecl;
    function Unique: Integer; overload; cdecl;
    function Uniqued: TBooleanArray; overload; cdecl;
    function Uniques: TIntegerArray; overload; cdecl;
    function Unshift(const item: Boolean): Integer; overload; cdecl;
    function Unshift(const items: TBooleanArray): Integer; overload; cdecl;
  end;
  TPointArrayHelper = type helper for TPointArray
    function Add(const item: TPoint; const duplicates: Boolean = True): TPointArray; overload; cdecl;
    function Add(const items: TPointArray; const duplicates: Boolean = True): TPointArray; overload; cdecl;
    function AllEqual: Boolean; overload; cdecl;
    function AllSame: Boolean; overload cdecl;
    function AllUnique: Boolean; overload; cdecl;
    function Append(const item: TPoint; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Append(const items: TPointArray; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Build(const item: TPoint; const aSize: Integer = 1): TPointArray; overload; cdecl;
    function BuiltWith(const allowed: TPointArray): Boolean; overload; cdecl;
    function BuiltWithout(const forbidden: TPointArray): Boolean; overload; cdecl;
    function Create(const item: TPoint): TPointArray; overload; cdecl;
    function Create(const aSize: Integer; const item: TPoint): TPointArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TPointArray; cdecl;
    function Clone(const ID: TIntegerArray): TPointArray; overload; cdecl;
    function Combine(const b: TPointArray): TPointArray; overload; cdecl;
    function Contains(const item: TPoint; const index: Integer = 0): Boolean; cdecl;
    function Copy(const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl;
    function Delete(const index: Integer = 0): Boolean; overload; cdecl;
    function Delete(const ID: TIntegerArray): Integer; overload; cdecl;
    function Differ(const target: TPointArray): Boolean; overload; cdecl;
    function Distribute(const parts: Integer): T2DPointArray; overload; cdecl;
    function Dump(const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl;
    function Dupe: TPointArray; overload; cdecl;
    function Duplicate(const xTimes: Integer = 1): TPointArray; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Equal(const target: TPointArray): Boolean; overload; cdecl;
    function Exch(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Exchange(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Extend(const item: TPoint): TPointArray; overload; cdecl;
    function Extend(const items: TPointArray): TPointArray; overload; cdecl;
    function Extract(const item: TPoint; const index: Integer = 0): TPointArray; overload; cdecl;
    function Extract(const items: TPointArray; const index: Integer = 0): TPointArray; overload; cdecl;
    function ExtractEvery(const X: Integer = 1; const index: Integer = 0): TPointArray; overload; cdecl;
    function Fill(const item: TPoint; const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl;
    function Fill(const items: TPointArray; const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl;
    function Filter(const item: TPoint; const index: Integer = 0): TPointArray; overload; cdecl;
    function Filter(const items: TPointArray; const index: Integer = 0): TPointArray; overload; cdecl;
    function FilterEvery(const X: Integer = 1; const index: Integer = 0): TPointArray; overload; cdecl;
    function Find(const ID: TRange; const item: TPoint): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const item: TPoint): Integer; overload; cdecl;
    function Find(const ID: TRange; const items: TPointArray): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const items: TPointArray): Integer; overload; cdecl;
    function Flip: Boolean; overload; cdecl;
    function FromLeft(const count: Integer; const index: Integer = 2147483647): TPointArray; overload; cdecl;
    function FromRight(const count: Integer; const index: Integer = 0): TPointArray; overload; cdecl;
    function Get: TPointArray; overload; cdecl;
    function Get(const ID: TIntegerArray): TPointArray; overload; cdecl;
    function Get(const ID: TRange): TPointArray; overload; cdecl;
    function Group: T2DPointArray; overload; cdecl;
    function Holds(const chain: TPointArray): Boolean; overload; cdecl;
    function IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl;
    function IDs(const ID: TIntegerArray): TPointArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const item: TPoint): TPointArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const items: TPointArray): TPointArray; overload; cdecl;
    function Includes(const item: TPoint; const index: Integer = 2147483647): Boolean; cdecl;
    function Keep(const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl;
    function LeastFrequent: TPoint; overload; cdecl;
    function Len: Integer; overload; cdecl;
    function Len(const aSize: Integer): Integer; overload; cdecl;
    function Len(const aSize: Integer; const null: TPoint): Integer; overload; cdecl;
    function Loc(const item: TPoint; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Loc(const items: TPointArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const item: TPoint; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const items: TPointArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Locations(const item: TPoint; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Locations(const items: TPointArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Mix(const shuffles: Integer = 1): Boolean; overload; cdecl;
    function MostFrequent: TPoint; overload; cdecl;
    function Move(const oldIndex, newIndex: Integer): Boolean; overload cdecl;
    function Next(const index: Integer; const count: Integer = 2147483647): TPointArray; overload; cdecl;
    function Oversize(const limit: Integer): Boolean; overload; cdecl;
    function Partition(const pSize: Integer): T2DPointArray; overload; cdecl;
    function Pick(const ID: TIntegerArray): TPointArray; overload; cdecl;
    function Pop: TPoint; overload; cdecl;
    function Pop(const null: TPoint): TPoint; overload; cdecl;
    function Pos(const item: TPoint; const index: Integer = 0): Integer; overload; cdecl;
    function Pos(const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const item: TPoint; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl;
    function Positions(const item: TPoint; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Positions(const items: TPointArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Previous(const index: Integer; const count: Integer = 2147483647): TPointArray; overload; cdecl;
    function Push(const item: TPoint): Integer; overload; cdecl;
    function Push(const items: TPointArray): Integer; overload; cdecl;
    function Put(const ID: TIntegerArray; const item: TPoint): TPointArray; overload; cdecl;
    function Put(const ID: TIntegerArray; const items: TPointArray): TPointArray; overload; cdecl;
    function Put(const index: Integer; const items: TPointArray): TPointArray; overload; cdecl;
    function Remove(const item: TPoint; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const item: TPoint; const all: Boolean): Integer; overload; cdecl;
    function Remove(const items: TPointArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const items: TPointArray; const all: Boolean): Integer; overload; cdecl;
    function Resize(const aChange: Integer): Integer; overload; cdecl;
    function Resize(const aChange: Integer; const null: TPoint): Integer; overload; cdecl;
    function Reverse: Boolean; overload; cdecl;
    function Reversed: TPointArray; overload; cdecl;
    function Scan(const ID: TRange; const item: TPoint; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const item: TPoint; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TRange; const items: TPointArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const items: TPointArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Shift: TPoint; overload; cdecl;
    function Shift(const sCount: Integer): TPointArray; overload; cdecl;
    function Size(const aSize: Integer): Integer; overload; cdecl;
    function Size: Integer; overload; cdecl;
    function SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl;
    function SizeMax(const target: Integer): Boolean; overload; cdecl;
    function SizeMin(const target: Integer): Boolean; overload; cdecl;
    function SubarrayLocation(const pattern: TPointArray): Integer; overload; cdecl;
    function SubarrayLocations(const pattern: TPointArray): TIntegerArray; overload; cdecl;
    function SubarrayPosition(const pattern: TPointArray): Integer; overload; cdecl;
    function SubarrayPositions(const pattern: TPointArray): TIntegerArray; overload; cdecl;
    function Swap(var b: TPointArray): Integer; overload; cdecl;
    function Undersize(const limit: Integer): Boolean; overload; cdecl;
    function Trade(var b: TPointArray): Integer; overload; cdecl;
    function Unique: Integer; overload; cdecl;
    function Uniqued: TPointArray; overload; cdecl;
    function Uniques: TIntegerArray; overload; cdecl;
    function Unshift(const item: TPoint): Integer; overload; cdecl;
    function Unshift(const items: TPointArray): Integer; overload; cdecl;
	
    function Bounds: TBox; overload; cdecl;
    function Bounds(var width, height: Integer): TBox; overload; cdecl;
    function Undupe: Integer; cdecl;
    function Unduped: TPointArray; cdecl;
    function Invert: TPointArray; cdecl;
    function Edge(const scan8W: Boolean = False): TPointArray; cdecl;
    function FloodFill(const start: TPoint; const area: TBox; const scan8W: Boolean = False): TPointArray; overload; cdecl;
    function FloodFill(const start: TPoint; const scan8W: Boolean = False): TPointArray; overload; cdecl;  
  end;
  TBoxArrayHelper = type helper for TBoxArray
    function Add(const item: TBox; const duplicates: Boolean = True): TBoxArray; overload; cdecl;
    function Add(const items: TBoxArray; const duplicates: Boolean = True): TBoxArray; overload; cdecl;
    function AllEqual: Boolean; overload; cdecl;
    function AllSame: Boolean; overload cdecl;
    function AllUnique: Boolean; overload; cdecl;
    function Append(const item: TBox; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Append(const items: TBoxArray; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Build(const item: TBox; const aSize: Integer = 1): TBoxArray; overload; cdecl;
    function BuiltWith(const allowed: TBoxArray): Boolean; overload; cdecl;
    function BuiltWithout(const forbidden: TBoxArray): Boolean; overload; cdecl;
    function Create(const item: TBox): TBoxArray; overload; cdecl;
    function Create(const aSize: Integer; const item: TBox): TBoxArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; cdecl;
    function Clone(const ID: TIntegerArray): TBoxArray; overload; cdecl;
    function Combine(const b: TBoxArray): TBoxArray; overload; cdecl;
    function Contains(const item: TBox; const index: Integer = 0): Boolean; cdecl;
    function Copy(const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl;
    function Delete(const index: Integer = 0): Boolean; overload; cdecl;
    function Delete(const ID: TIntegerArray): Integer; overload; cdecl;
    function Differ(const target: TBoxArray): Boolean; overload; cdecl;
    function Distribute(const parts: Integer): T2DBoxArray; overload; cdecl;
    function Dump(const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl;
    function Dupe: TBoxArray; overload; cdecl;
    function Duplicate(const xTimes: Integer = 1): TBoxArray; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Equal(const target: TBoxArray): Boolean; overload; cdecl;
    function Exch(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Exchange(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Extend(const item: TBox): TBoxArray; overload; cdecl;
    function Extend(const items: TBoxArray): TBoxArray; overload; cdecl;
    function Extract(const item: TBox; const index: Integer = 0): TBoxArray; overload; cdecl;
    function Extract(const items: TBoxArray; const index: Integer = 0): TBoxArray; overload; cdecl;
    function ExtractEvery(const X: Integer = 1; const index: Integer = 0): TBoxArray; overload; cdecl;
    function Fill(const item: TBox; const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl;
    function Fill(const items: TBoxArray; const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl;
    function Filter(const item: TBox; const index: Integer = 0): TBoxArray; overload; cdecl;
    function Filter(const items: TBoxArray; const index: Integer = 0): TBoxArray; overload; cdecl;
    function FilterEvery(const X: Integer = 1; const index: Integer = 0): TBoxArray; overload; cdecl;
    function Find(const ID: TRange; const item: TBox): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const item: TBox): Integer; overload; cdecl;
    function Find(const ID: TRange; const items: TBoxArray): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const items: TBoxArray): Integer; overload; cdecl;
    function Flip: Boolean; overload; cdecl;
    function FromLeft(const count: Integer; const index: Integer = 2147483647): TBoxArray; overload; cdecl;
    function FromRight(const count: Integer; const index: Integer = 0): TBoxArray; overload; cdecl;
    function Get: TBoxArray; overload; cdecl;
    function Get(const ID: TIntegerArray): TBoxArray; overload; cdecl;
    function Get(const ID: TRange): TBoxArray; overload; cdecl;
    function Group: T2DBoxArray; overload; cdecl;
    function Holds(const chain: TBoxArray): Boolean; overload; cdecl;
    function IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl;
    function IDs(const ID: TIntegerArray): TBoxArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const item: TBox): TBoxArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const items: TBoxArray): TBoxArray; overload; cdecl;
    function Includes(const item: TBox; const index: Integer = 2147483647): Boolean; cdecl;
    function Keep(const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl;
    function LeastFrequent: TBox; overload; cdecl;
    function Len: Integer; overload; cdecl;
    function Len(const aSize: Integer): Integer; overload; cdecl;
    function Len(const aSize: Integer; const null: TBox): Integer; overload; cdecl;
    function Loc(const item: TBox; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Loc(const items: TBoxArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const item: TBox; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const items: TBoxArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Locations(const item: TBox; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Locations(const items: TBoxArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Mix(const shuffles: Integer = 1): Boolean; overload; cdecl;
    function MostFrequent: TBox; overload; cdecl;
    function Move(const oldIndex, newIndex: Integer): Boolean; overload cdecl;
    function Next(const index: Integer; const count: Integer = 2147483647): TBoxArray; overload; cdecl;
    function Oversize(const limit: Integer): Boolean; overload; cdecl;
    function Partition(const pSize: Integer): T2DBoxArray; overload; cdecl;
    function Pick(const ID: TIntegerArray): TBoxArray; overload; cdecl;
    function Pop: TBox; overload; cdecl;
    function Pop(const null: TBox): TBox; overload; cdecl;
    function Pos(const item: TBox; const index: Integer = 0): Integer; overload; cdecl;
    function Pos(const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const item: TBox; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl;
    function Positions(const item: TBox; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Positions(const items: TBoxArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Previous(const index: Integer; const count: Integer = 2147483647): TBoxArray; overload; cdecl;
    function Push(const item: TBox): Integer; overload; cdecl;
    function Push(const items: TBoxArray): Integer; overload; cdecl;
    function Put(const ID: TIntegerArray; const item: TBox): TBoxArray; overload; cdecl;
    function Put(const ID: TIntegerArray; const items: TBoxArray): TBoxArray; overload; cdecl;
    function Put(const index: Integer; const items: TBoxArray): TBoxArray; overload; cdecl;
    function Remove(const item: TBox; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const item: TBox; const all: Boolean): Integer; overload; cdecl;
    function Remove(const items: TBoxArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const items: TBoxArray; const all: Boolean): Integer; overload; cdecl;
    function Resize(const aChange: Integer): Integer; overload; cdecl;
    function Resize(const aChange: Integer; const null: TBox): Integer; overload; cdecl;
    function Reverse: Boolean; overload; cdecl;
    function Reversed: TBoxArray; overload; cdecl;
    function Scan(const ID: TRange; const item: TBox; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const item: TBox; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TRange; const items: TBoxArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const items: TBoxArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Shift: TBox; overload; cdecl;
    function Shift(const sCount: Integer): TBoxArray; overload; cdecl;
    function Size(const aSize: Integer): Integer; overload; cdecl;
    function Size: Integer; overload; cdecl;
    function SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl;
    function SizeMax(const target: Integer): Boolean; overload; cdecl;
    function SizeMin(const target: Integer): Boolean; overload; cdecl;
    function SubarrayLocation(const pattern: TBoxArray): Integer; overload; cdecl;
    function SubarrayLocations(const pattern: TBoxArray): TIntegerArray; overload; cdecl;
    function SubarrayPosition(const pattern: TBoxArray): Integer; overload; cdecl;
    function SubarrayPositions(const pattern: TBoxArray): TIntegerArray; overload; cdecl;
    function Swap(var b: TBoxArray): Integer; overload; cdecl;
    function Undersize(const limit: Integer): Boolean; overload; cdecl;
    function Trade(var b: TBoxArray): Integer; overload; cdecl;
    function Unique: Integer; overload; cdecl;
    function Uniqued: TBoxArray; overload; cdecl;
    function Uniques: TIntegerArray; overload; cdecl;
    function Unshift(const item: TBox): Integer; overload; cdecl;
    function Unshift(const items: TBoxArray): Integer; overload; cdecl;
  end;
  TRangeArrayHelper = type helper for TRangeArray
    function Add(const item: TRange; const duplicates: Boolean = True): TRangeArray; overload; cdecl;
    function Add(const items: TRangeArray; const duplicates: Boolean = True): TRangeArray; overload; cdecl;
    function AllEqual: Boolean; overload; cdecl;
    function AllSame: Boolean; overload cdecl;
    function AllUnique: Boolean; overload; cdecl;
    function Append(const item: TRange; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Append(const items: TRangeArray; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Build(const item: TRange; const aSize: Integer = 1): TRangeArray; overload; cdecl;
    function BuiltWith(const allowed: TRangeArray): Boolean; overload; cdecl;
    function BuiltWithout(const forbidden: TRangeArray): Boolean; overload; cdecl;
    function Create(const item: TRange): TRangeArray; overload; cdecl;
    function Create(const aSize: Integer; const item: TRange): TRangeArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; cdecl;
    function Clone(const ID: TIntegerArray): TRangeArray; overload; cdecl;
    function Combine(const b: TRangeArray): TRangeArray; overload; cdecl;
    function Contains(const item: TRange; const index: Integer = 0): Boolean; cdecl;
    function Copy(const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl;
    function Delete(const index: Integer = 0): Boolean; overload; cdecl;
    function Delete(const ID: TIntegerArray): Integer; overload; cdecl;
    function Differ(const target: TRangeArray): Boolean; overload; cdecl;
    function Distribute(const parts: Integer): T2DRangeArray; overload; cdecl;
    function Dump(const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl;
    function Dupe: TRangeArray; overload; cdecl;
    function Duplicate(const xTimes: Integer = 1): TRangeArray; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Equal(const target: TRangeArray): Boolean; overload; cdecl;
    function Exch(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Exchange(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
    function Extend(const item: TRange): TRangeArray; overload; cdecl;
    function Extend(const items: TRangeArray): TRangeArray; overload; cdecl;
    function Extract(const item: TRange; const index: Integer = 0): TRangeArray; overload; cdecl;
    function Extract(const items: TRangeArray; const index: Integer = 0): TRangeArray; overload; cdecl;
    function ExtractEvery(const X: Integer = 1; const index: Integer = 0): TRangeArray; overload; cdecl;
    function Fill(const item: TRange; const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl;
    function Fill(const items: TRangeArray; const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl;
    function Filter(const item: TRange; const index: Integer = 0): TRangeArray; overload; cdecl;
    function Filter(const items: TRangeArray; const index: Integer = 0): TRangeArray; overload; cdecl;
    function FilterEvery(const X: Integer = 1; const index: Integer = 0): TRangeArray; overload; cdecl;
    function Find(const ID: TRange; const item: TRange): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const item: TRange): Integer; overload; cdecl;
    function Find(const ID: TRange; const items: TRangeArray): Integer; overload; cdecl;
    function Find(const ID: TIntegerArray; const items: TRangeArray): Integer; overload; cdecl;
    function Flip: Boolean; overload; cdecl;
    function FromLeft(const count: Integer; const index: Integer = 2147483647): TRangeArray; overload; cdecl;
    function FromRight(const count: Integer; const index: Integer = 0): TRangeArray; overload; cdecl;
    function Get: TRangeArray; overload; cdecl;
    function Get(const ID: TIntegerArray): TRangeArray; overload; cdecl;
    function Get(const ID: TRange): TRangeArray; overload; cdecl;
    function Group: T2DRangeArray; overload; cdecl;
    function Holds(const chain: TRangeArray): Boolean; overload; cdecl;
    function IDs(const ascending: Boolean = True): TIntegerArray; overload; cdecl;
    function IDs(const ID: TIntegerArray): TRangeArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const item: TRange): TRangeArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const items: TRangeArray): TRangeArray; overload; cdecl;
    function Includes(const item: TRange; const index: Integer = 2147483647): Boolean; cdecl;
    function Keep(const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl;
    function LeastFrequent: TRange; overload; cdecl;
    function Len: Integer; overload; cdecl;
    function Len(const aSize: Integer): Integer; overload; cdecl;
    function Len(const aSize: Integer; const null: TRange): Integer; overload; cdecl;
    function Loc(const item: TRange; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Loc(const items: TRangeArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const item: TRange; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Location(const items: TRangeArray; const index: Integer = 2147483647): Integer; overload; cdecl;
    function Locations(const item: TRange; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Locations(const items: TRangeArray; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Mix(const shuffles: Integer = 1): Boolean; overload; cdecl;
    function MostFrequent: TRange; overload; cdecl;
    function Move(const oldIndex, newIndex: Integer): Boolean; overload cdecl;
    function Next(const index: Integer; const count: Integer = 2147483647): TRangeArray; overload; cdecl;
    function Oversize(const limit: Integer): Boolean; overload; cdecl;
    function Partition(const pSize: Integer): T2DRangeArray; overload; cdecl;
    function Pick(const ID: TIntegerArray): TRangeArray; overload; cdecl;
    function Pop: TRange; overload; cdecl;
    function Pop(const null: TRange): TRange; overload; cdecl;
    function Pos(const item: TRange; const index: Integer = 0): Integer; overload; cdecl;
    function Pos(const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const item: TRange; const index: Integer = 0): Integer; overload; cdecl;
    function Position(const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl;
    function Positions(const item: TRange; const index: Integer = 0): TIntegerArray; overload; cdecl;
    function Positions(const items: TRangeArray; const index: Integer = 0): TIntegerArray; overload; cdecl;
	function Previous(const index: Integer; const count: Integer = 2147483647): TRangeArray; overload; cdecl;
    function Push(const item: TRange): Integer; overload; cdecl;
    function Push(const items: TRangeArray): Integer; overload; cdecl;
    function Put(const ID: TIntegerArray; const item: TRange): TRangeArray; overload; cdecl;
    function Put(const ID: TIntegerArray; const items: TRangeArray): TRangeArray; overload; cdecl;
    function Put(const index: Integer; const items: TRangeArray): TRangeArray; overload; cdecl;
    function Remove(const item: TRange; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const item: TRange; const all: Boolean): Integer; overload; cdecl;
    function Remove(const items: TRangeArray; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
    function Remove(const items: TRangeArray; const all: Boolean): Integer; overload; cdecl;
    function Resize(const aChange: Integer): Integer; overload; cdecl;
    function Resize(const aChange: Integer; const null: TRange): Integer; overload; cdecl;
    function Reverse: Boolean; overload; cdecl;
    function Reversed: TRangeArray; overload; cdecl;
    function Scan(const ID: TRange; const item: TRange; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const item: TRange; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TRange; const items: TRangeArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Scan(const ID: TIntegerArray; const items: TRangeArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
    function Shift: TRange; overload; cdecl;
    function Shift(const sCount: Integer): TRangeArray; overload; cdecl;
    function Size(const aSize: Integer): Integer; overload; cdecl;
    function Size: Integer; overload; cdecl;
    function SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl;
    function SizeMax(const target: Integer): Boolean; overload; cdecl;
    function SizeMin(const target: Integer): Boolean; overload; cdecl;
    function SubarrayLocation(const pattern: TRangeArray): Integer; overload; cdecl;
    function SubarrayLocations(const pattern: TRangeArray): TIntegerArray; overload; cdecl;
    function SubarrayPosition(const pattern: TRangeArray): Integer; overload; cdecl;
    function SubarrayPositions(const pattern: TRangeArray): TIntegerArray; overload; cdecl;
    function Swap(var b: TRangeArray): Integer; overload; cdecl;
    function Undersize(const limit: Integer): Boolean; overload; cdecl;
    function Trade(var b: TRangeArray): Integer; overload; cdecl;
    function Unique: Integer; overload; cdecl;
    function Uniqued: TRangeArray; overload; cdecl;
    function Uniques: TIntegerArray; overload; cdecl;
    function Unshift(const item: TRange): Integer; overload; cdecl;
    function Unshift(const items: TRangeArray): Integer; overload; cdecl;
	
    function TIA: TIntegerArray; cdecl;
    function T2DIA: T2DIntegerArray; cdecl;  
  end;
  T2DIntegerArrayHelper = type helper for T2DIntegerArray
    function Blank: Boolean; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Size(var lengths: TIntegerArray): Int64; overload; cdecl;
    function Size: Int64; overload; cdecl;
    function Size(const aSize: Integer): Int64; overload; cdecl;
    function Size(const size1D, size2D: Integer): Int64; overload; cdecl;
    function Merge: TIntegerArray; overload; cdecl;  
  end;
  T2DDoubleArrayHelper = type helper for T2DDoubleArray
    function Blank: Boolean; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Size(var lengths: TIntegerArray): Int64; overload; cdecl;
    function Size: Int64; overload; cdecl;
    function Size(const aSize: Integer): Int64; overload; cdecl;
    function Size(const size1D, size2D: Integer): Int64; overload; cdecl;
    function Merge: TDoubleArray; overload; cdecl;  
  end;
  T2DStringArrayHelper = type helper for T2DStringArray
    function Blank: Boolean; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Size(var lengths: TIntegerArray): Int64; overload; cdecl;
    function Size: Int64; overload; cdecl;
    function Size(const aSize: Integer): Int64; overload; cdecl;
    function Size(const size1D, size2D: Integer): Int64; overload; cdecl;
    function Merge: TStringArray; overload; cdecl;  
  end;
  T2DCharArrayHelper = type helper for T2DCharArray
    function Blank: Boolean; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Size(var lengths: TIntegerArray): Int64; overload; cdecl;
    function Size: Int64; overload; cdecl;
    function Size(const aSize: Integer): Int64; overload; cdecl;
    function Size(const size1D, size2D: Integer): Int64; overload; cdecl;
    function Merge: TCharArray; overload; cdecl;  
  end;
  T2DBooleanArrayHelper = type helper for T2DBooleanArray
    function Blank: Boolean; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Size(var lengths: TIntegerArray): Int64; overload; cdecl;
    function Size: Int64; overload; cdecl;
    function Size(const aSize: Integer): Int64; overload; cdecl;
    function Size(const size1D, size2D: Integer): Int64; overload; cdecl;
    function Merge: TBooleanArray; overload; cdecl;  
  end;
  T2DPointArrayHelper = type helper for T2DPointArray
    function Blank: Boolean; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Size(var lengths: TIntegerArray): Int64; overload; cdecl;
    function Size: Int64; overload; cdecl;
    function Size(const aSize: Integer): Int64; overload; cdecl;
    function Size(const size1D, size2D: Integer): Int64; overload; cdecl;
    function Merge: TPointArray; overload; cdecl;  
  end;
  T2DBoxArrayHelper = type helper for T2DBoxArray
    function Blank: Boolean; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Size(var lengths: TIntegerArray): Int64; overload; cdecl;
    function Size: Int64; overload; cdecl;
    function Size(const aSize: Integer): Int64; overload; cdecl;
    function Size(const size1D, size2D: Integer): Int64; overload; cdecl;
    function Merge: TBoxArray; overload; cdecl;  
  end;
  T2DRangeArrayHelper = type helper for T2DRangeArray
    function Blank: Boolean; overload; cdecl;
    function Empty: Boolean; overload; cdecl;
    function Size(var lengths: TIntegerArray): Int64; overload; cdecl;
    function Size: Int64; overload; cdecl;
    function Size(const aSize: Integer): Int64; overload; cdecl;
    function Size(const size1D, size2D: Integer): Int64; overload; cdecl;
    function Merge: TRangeArray; overload; cdecl;  
  end;
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
