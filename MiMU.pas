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
  MiMU_VERSION_NUMBER = 0.41;

type
  TPoint = record
    X, Y: Integer;
  end;
  TBox = record
    X1, Y1, X2, Y2: Integer;
  end;
  TRange = record
    start, stop: Integer;
  end;
  TIntegerArray = array of Integer;
  TDoubleArray = array of Double;
  TStringArray = array of string;
  TCharArray = array of Char;
  TBooleanArray = array of Boolean;
  TPointArray = array of TPoint;
  TBoxArray = array of TBox;
  TRangeArray = array of TRange;
  T2DIntegerArray = array of TIntegerArray;
  T2DDoubleArray = array of TDoubleArray;
  T2DStringArray = array of TStringArray;
  T2DCharArray = array of TCharArray;
  T2DBooleanArray = array of TBooleanArray;
  T2DPointArray = array of TPointArray;
  T2DBoxArray = array of TBoxArray;
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
  end;
  TStringHelper = type helper for string
    function Chars: TCharArray; cdecl;
    function At(const s: string; const index: Integer = 1): Boolean; cdecl; inline;
    function Get(const index: Integer; const count: Integer): string; cdecl; inline;
    function Pick(const index: Integer; const count: Integer = 2147483647): string; cdecl;
    function PosL(const s: string; const index: Integer = 1): Integer; cdecl;
    function PosR(const s: string; const index: Integer = 2147483647): Integer; cdecl;
    function Find(const s: string; const index: Integer = 1): Integer; cdecl;
    function PosLast(const s: string; const index: Integer = 2147483647): Integer; cdecl;
    function Position(const s: string; const index: Integer = 1): Integer; cdecl;
    function Contains(const s: string; const index: Integer = 1): Boolean; cdecl;
    function Includes(const s: string; const index: Integer = 2147483647): Boolean; cdecl;
    function Between(const s1, s2: string; const index: Integer = 1): string; cdecl;
    function Count(const s: string; const overlap: Boolean = True; const index: Integer = 1): Integer; cdecl;
    function Amount(const s: string; const overlap: Boolean = True; const index: Integer = 2147483647): Integer; cdecl;
    function FromLeft(const count: Integer; const index: Integer = 1): string; cdecl;
    function FromRight(const count: Integer; const index: Integer = 2147483647): string; cdecl;
    function Explode(const d: string; const limit: Integer = -1): TStringArray; overload; cdecl;
    function Explode(const d: TStringArray; const limit: Integer = -1): TStringArray; overload; cdecl;
    function Slice(const a, b: Integer): string; cdecl;
    function Chunk(const a, b: Integer): string; cdecl;
    function Reverse: Boolean; cdecl;
    function Flip: string; cdecl;
    function Reversed: string; cdecl;
    function StartsWith(const s: string): Boolean; cdecl;
    function EndsWith(const s: string): Boolean; cdecl;
    function StartWith(const s: string; const index: Integer = 1): Boolean; cdecl;
    function EndWith(const s: string; const index: Integer = 2147483647): Boolean; cdecl;
    function Behind(const index, count: Integer): string; cdecl;
    function Ahead(const index, count: Integer): string; cdecl;
    function After(const s: string; const index: Integer = 1): string; cdecl;
    function Before(const s: string; const index: Integer = 1): string; cdecl;
    function AfterLast(const s: string; const index: Integer = 2147483647): string; cdecl;
    function BeforeLast(const s: string; const index: Integer = 2147483647): string; cdecl; 
    function Center(const size: Integer; const fill: Char = #32): string; cdecl;
    function Stuff(const s: string; const iFrom, iCount: Integer): string; cdecl;
    function Duplicate(const x: Integer = 2): string; cdecl;
    function Duplicated(const x: Integer; const glue: string): string; cdecl;
    function Compare(const s: string): Integer; cdecl; inline;
    function Quotatation: string; cdecl;
    function PregQuote(const regex: string = '.\+*?[^]$(){}=!<>|:-'): string; cdecl;
    function TrimLeft(const t: Char = #32): string; cdecl;
    function TrimRight(const t: Char = #32): string; cdecl;
    function Trim(const t: Char = #32): string; cdecl;
    function ToTRange: TRange; cdecl;
    function IDs: TIntegerArray; overload; cdecl;
    function IDs(const ID: TIntegerArray): TCharArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const item: Char): TCharArray; overload; cdecl;
    function IDs(const ID: TIntegerArray; const items: TCharArray): TCharArray; overload; cdecl;  
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
  end;
  TPointHelper = type helper for TPoint
    function Create(const X, Y: Integer): TPoint; cdecl; inline;
    function Build(const X, Y: Integer): TPoint; cdecl; inline;
    function InBox(const bx: TBox): Boolean; cdecl; inline;
    function InCircle(const center: TPoint; const radius: Double): Boolean; cdecl; inline;
    function InEllipse(const center: TPoint; const XRadius, YRadius: Double): Boolean; cdecl; inline;
    function AngleDegrees(const target: TPoint; const compass: Boolean = False): Double; cdecl;
    function AngleRadians(const target: TPoint): Double; cdecl;
    function DistEuclidean(const target: TPoint): Double; cdecl;
    function DistEuclidean2(const target: TPoint): Double; cdecl;
    function DistSquaredEuclidean(const target: TPoint): Double; cdecl;
    function DistManhattan(const target: TPoint): Double; cdecl;
    function DistChebyshev(const target: TPoint): Double; cdecl;
    function Grid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TPointArray; cdecl;
    function Row(const cells: Integer; const space: Integer = 0): TPointArray; cdecl;
    function Column(const cells: Integer; const space: Integer = 0): TPointArray; cdecl;  
  end;
  TBoxHelper = type helper for TBox
    function Build(const X1, Y1, X2, Y2: Integer): TBox; overload; cdecl;
    function Build(const a, b: TPoint): TBox; overload; cdecl;
    function Create(const X1, Y1, X2, Y2: Integer): TBox; overload; cdecl;
    function Create(const a, b: TPoint): TBox; overload; cdecl;
    function Form(const XY: Integer = 0): TBox; overload; cdecl;
    function Form(const XY: TPoint): TBox; overload; cdecl;
    function Make(const pt: TPoint; const radius: Integer = 0): TBox; overload; cdecl;
    function Make(const pt: TPoint; const wRadius, hRadius: Integer): TBox; overload; cdecl;
    function Yield(const pt: TPoint; const size: Integer = 1): TBox; overload; cdecl;
    function Yield(const pt: TPoint; const width, height: Integer): TBox; overload; cdecl;
    function Size(var width, height: Integer): Integer; cdecl; inline;
    function Area: Integer; cdecl; inline;
    function Diagonal: Double; cdecl;
    function W: Integer; overload; cdecl;
    function W(const width: Integer): Integer; overload; cdecl;
    function Width: Integer; overload; cdecl;
    function Width(const w: Integer): Integer; overload; cdecl;
    function H: Integer; overload; cdecl;
    function H(const height: Integer): Integer; overload; cdecl;
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
    function InArea(const area: TBox): Boolean; overload; cdecl;
    function InArea(const areas: TBoxArray): Boolean; overload; cdecl;
    function Inside(const area: TBox): Boolean; overload; cdecl;
    function Inside(const areas: TBoxArray): Boolean; overload; cdecl;
    function Center: TPoint; cdecl;
    function Envelope(const b: TBox): TBox; cdecl;
    function Overlap(const b: TBox): Boolean; cdecl; inline;
    function Intersection(const b: TBox): TBox; cdecl;
    function Intersect(const b: TBox; var intersection: TBox): Boolean; cdecl;
    function Union(const b: TBox): TBox; cdecl;
    function Valid: Boolean; cdecl; inline;
    function Invalid: Boolean; cdecl;
    function Similar(const b: TBox; const maxWDiff, maxHDiff: Integer): Boolean; overload; cdecl;
    function Similar(const b: TBox; const diff: Integer): Boolean; overload; cdecl;
    function Fix: Boolean; cdecl;
    function Constraint(const area: TBox): Boolean; cdecl;
    function Clip(const area: TBox): TBox; cdecl;
    function Restrict(const area: TBox): Boolean; cdecl;
    function Clamp(const area: TBox): TBox; cdecl;
    function Points: TPointArray; cdecl;
    function TPA: TPointArray; cdecl;
    function Grid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TBoxArray; cdecl;
    function Row(const cells: Integer; const space: Integer = 0): TBoxArray; cdecl;
    function Column(const cells: Integer; const space: Integer = 0): TBoxArray; cdecl;
    function CornerPoints: TPointArray; cdecl;
    function Corners: TPointArray; cdecl;
    function SimilarSize(const b: TBox; const widthDifferency, heightDifferency: Integer): Boolean; overload; cdecl;
    function SimilarSize(const b: TBox; const differency: Integer): Boolean; overload; cdecl;
    function Centered(const area: TBox): TBox; cdecl;
    function CenterVertically(const area: TBox): TBox; cdecl;
    function CenterHorizontally(const area: TBox): TBox; cdecl;
  end;
  TRangeHelper = type helper for TRange
    function Neutral: Boolean; cdecl;
    function Ascending: Boolean; cdecl;
    function Descending: Boolean; cdecl;
    function Create(const start: Integer = 0; const stop: Integer = 0): TRange; cdecl;
    function Build(const start: Integer = 0; const stop: Integer = 0): TRange; cdecl;
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
    function Intersection(const b: TRange; const null: TRange): TRange; cdecl;
    function Intersect(const b: TRange; var intersection: TRange): Boolean; cdecl;
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
    function ClampMax(const maximum: Integer): TRange; cdecl;
    function ClampMin(const minimum: Integer): TRange; cdecl;
    function Restrict(const zone: TRange): Boolean; cdecl;
    function RestrictMin(const minimum: Integer): Boolean; cdecl;
    function RestrictMax(const maximum: Integer): Boolean; cdecl;
    function Clip(const zone: TRange): TRange; cdecl;
    function ClipMin(const minimum: Integer): TRange; cdecl;
    function ClipMax(const maximum: Integer): TRange; cdecl;
    function Distribute(const parts: Integer): TRangeArray; cdecl;
    function Partition(const size: Integer): TRangeArray; cdecl;
    function Divide(const size: Integer): TRangeArray; cdecl;
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
  TIntegerArrayHelper = type helper for TIntegerArray
    function Add(const item: Integer; const duplicates: Boolean = True): TIntegerArray; overload; cdecl;
    function Add(const items: TIntegerArray; const duplicates: Boolean = True): TIntegerArray; overload; cdecl;
    function AllEqual: Boolean; overload; cdecl;
	function AllSame: Boolean; overload cdecl;
	function AllUnique: Boolean; overload; cdecl;
    function Append(const item: Integer; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Append(const items: TIntegerArray; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Build(const item: Integer; const size: Integer = 1): TIntegerArray; overload; cdecl;
    function Create(const item: Integer): TIntegerArray; overload; cdecl;
    function Create(const size: Integer; const item: Integer): TIntegerArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; cdecl;
    function Clone(const ID: TIntegerArray): TIntegerArray; overload; cdecl;
    function Combine(const b: TIntegerArray): TIntegerArray; overload; cdecl;
    function Contains(const item: Integer; const index: Integer = 0): Boolean; cdecl;
    function Includes(const item: Integer; const index: Integer = 2147483647): Boolean; cdecl;

    function Descending: Boolean; cdecl;
    function Ascending: Boolean; cdecl;
    function Bounds: TRange; overload; cdecl;
    function Bounds(var size: Integer): TRange; overload; cdecl;
    function Range: TRange; cdecl;
    function Unique: Integer; cdecl;
    function Uniqued: TIntegerArray; cdecl;
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
    function MostFrequent(const null: Integer = -2147483648): Integer; cdecl;
    function LeastFrequent(const null: Integer = -2147483648): Integer; cdecl;
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
    function Build(const item: Double; const size: Integer = 1): TDoubleArray; overload; cdecl;
    function Create(const item: Double): TDoubleArray; overload; cdecl;
    function Create(const size: Integer; const item: Double): TDoubleArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; cdecl;
    function Clone(const ID: TIntegerArray): TDoubleArray; overload; cdecl;
    function Combine(const b: TDoubleArray): TDoubleArray; overload; cdecl;
    function Contains(const item: Double; const index: Integer = 0): Boolean; cdecl;
    function Includes(const item: Double; const index: Integer = 2147483647): Boolean; cdecl;	
  end;
  TStringArrayHelper = type helper for TStringArray
    function Add(const item: string; const duplicates: Boolean = True): TStringArray; overload; cdecl;
    function Add(const items: TStringArray; const duplicates: Boolean = True): TStringArray; overload; cdecl;
    function AllEqual: Boolean; overload; cdecl;
	function AllSame: Boolean; overload cdecl;
	function AllUnique: Boolean; overload; cdecl;
    function Append(const item: string; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Append(const items: TStringArray; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Build(const item: string; const size: Integer = 1): TStringArray; overload; cdecl;
    function Create(const item: string): TStringArray; overload; cdecl;
    function Create(const size: Integer; const item: string): TStringArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TStringArray; cdecl;
    function Clone(const ID: TIntegerArray): TStringArray; overload; cdecl;
    function Combine(const b: TStringArray): TStringArray; overload; cdecl;
    function Contains(const item: string; const index: Integer = 0): Boolean; cdecl;
    function Includes(const item: string; const index: Integer = 2147483647): Boolean; cdecl;	
  end;
  TCharArrayHelper = type helper for TCharArray
    function Add(const item: Char; const duplicates: Boolean = True): TCharArray; overload; cdecl;
    function Add(const items: TCharArray; const duplicates: Boolean = True): TCharArray; overload; cdecl;
    function AllEqual: Boolean; overload; cdecl;
	function AllSame: Boolean; overload cdecl;
	function AllUnique: Boolean; overload; cdecl;
    function Append(const item: Char; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Append(const items: TCharArray; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Build(const item: Char; const size: Integer = 1): TCharArray; overload; cdecl;
    function Create(const item: Char): TCharArray; overload; cdecl;
    function Create(const size: Integer; const item: Char): TCharArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TCharArray; cdecl;
    function Clone(const ID: TIntegerArray): TCharArray; overload; cdecl;
    function Combine(const b: TCharArray): TCharArray; overload; cdecl;
    function Contains(const item: Char; const index: Integer = 0): Boolean; cdecl;
    function Includes(const item: Char; const index: Integer = 2147483647): Boolean; cdecl;
  end;
  TBooleanArrayHelper = type helper for TBooleanArray
    function Add(const item: Boolean; const duplicates: Boolean = True): TBooleanArray; overload; cdecl;
    function Add(const items: TBooleanArray; const duplicates: Boolean = True): TBooleanArray; overload; cdecl;
    function AllEqual: Boolean; overload; cdecl;
	function AllSame: Boolean; overload cdecl;
	function AllUnique: Boolean; overload; cdecl;
    function Append(const item: Boolean; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Append(const items: TBooleanArray; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Build(const item: Boolean; const size: Integer = 1): TBooleanArray; overload; cdecl;
    function Create(const item: Boolean): TBooleanArray; overload; cdecl;
    function Create(const size: Integer; const item: Boolean): TBooleanArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; cdecl;
    function Clone(const ID: TIntegerArray): TBooleanArray; overload; cdecl;
    function Combine(const b: TBooleanArray): TBooleanArray; overload; cdecl;
    function Contains(const item: Boolean; const index: Integer = 0): Boolean; cdecl;
    function Includes(const item: Boolean; const index: Integer = 2147483647): Boolean; cdecl;	
  end;
  TPointArrayHelper = type helper for TPointArray
    function Add(const item: TPoint; const duplicates: Boolean = True): TPointArray; overload; cdecl;
    function Add(const items: TPointArray; const duplicates: Boolean = True): TPointArray; overload; cdecl;
    function AllEqual: Boolean; overload; cdecl;
	function AllSame: Boolean; overload cdecl;
	function AllUnique: Boolean; overload; cdecl;
    function Append(const item: TPoint; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Append(const items: TPointArray; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Build(const item: TPoint; const size: Integer = 1): TPointArray; overload; cdecl;
    function Create(const item: TPoint): TPointArray; overload; cdecl;
    function Create(const size: Integer; const item: TPoint): TPointArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TPointArray; cdecl;
    function Clone(const ID: TIntegerArray): TPointArray; overload; cdecl;
    function Combine(const b: TPointArray): TPointArray; overload; cdecl;
    function Contains(const item: TPoint; const index: Integer = 0): Boolean; cdecl;
    function Includes(const item: TPoint; const index: Integer = 2147483647): Boolean; cdecl;

    function Bounds: TBox; overload; cdecl;
    function Bounds(var width, height: Integer): TBox; overload; cdecl;
    function Unique: Integer; cdecl;
    function Uniqued: TPointArray; cdecl;
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
    function Build(const item: TBox; const size: Integer = 1): TBoxArray; overload; cdecl;
    function Create(const item: TBox): TBoxArray; overload; cdecl;
    function Create(const size: Integer; const item: TBox): TBoxArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; cdecl;
    function Clone(const ID: TIntegerArray): TBoxArray; overload; cdecl;
    function Combine(const b: TBoxArray): TBoxArray; overload; cdecl;
    function Contains(const item: TBox; const index: Integer = 0): Boolean; cdecl;
    function Includes(const item: TBox; const index: Integer = 2147483647): Boolean; cdecl;	
  end;
  TRangeArrayHelper = type helper for TRangeArray
    function Add(const item: TRange; const duplicates: Boolean = True): TRangeArray; overload; cdecl;
    function Add(const items: TRangeArray; const duplicates: Boolean = True): TRangeArray; overload; cdecl;
    function AllEqual: Boolean; overload; cdecl;
	function AllSame: Boolean; overload cdecl;
	function AllUnique: Boolean; overload; cdecl;
    function Append(const item: TRange; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Append(const items: TRangeArray; const duplicates: Boolean = True): Integer; overload; cdecl;
    function Build(const item: TRange; const size: Integer = 1): TRangeArray; overload; cdecl;
    function Create(const item: TRange): TRangeArray; overload; cdecl;
    function Create(const size: Integer; const item: TRange): TRangeArray; overload; cdecl;
    function Clear: Boolean; cdecl;
    function Clone(const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; cdecl;
    function Clone(const ID: TIntegerArray): TRangeArray; overload; cdecl;
    function Combine(const b: TRangeArray): TRangeArray; overload; cdecl;
    function Contains(const item: TRange; const index: Integer = 0): Boolean; cdecl;
    function Includes(const item: TRange; const index: Integer = 2147483647): Boolean; cdecl;

    function TIA: TIntegerArray; cdecl;
    function T2DIA: T2DIntegerArray; cdecl;  
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

procedure Swap(var A, B: Integer); overload; inline;
procedure Swap(var A, B: Int64); overload; inline;
procedure Swap(var A, B: Double); overload; inline;
procedure Swap(var A, B: string); overload; inline;
procedure Swap(var A, B: Char); overload; inline;
procedure Swap(var A, B: Boolean); overload; inline;
procedure Swap(var A, B: TPoint); overload; inline;
procedure Swap(var A, B: TBox); overload; inline;
procedure Swap(var A, B: TRange); overload; inline;

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

function TArray_Copy(const arr: TIntegerArray; const index: Integer = 0; const count: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Copy(const arr: TDoubleArray; const index: Integer = 0; const count: Integer = 2147483647): TDoubleArray; overload; cdecl;
function TArray_Copy(const arr: TStringArray; const index: Integer = 0; const count: Integer = 2147483647): TStringArray; overload; cdecl;
function TArray_Copy(const arr: TCharArray; const index: Integer = 0; const count: Integer = 2147483647): TCharArray; overload; cdecl;
function TArray_Copy(const arr: TBooleanArray; const index: Integer = 0; const count: Integer = 2147483647): TBooleanArray; overload; cdecl;
function TArray_Copy(const arr: TPointArray; const index: Integer = 0; const count: Integer = 2147483647): TPointArray; overload; cdecl;
function TArray_Copy(const arr: TBoxArray; const index: Integer = 0; const count: Integer = 2147483647): TBoxArray; overload; cdecl;
function TArray_Copy(const arr: TRangeArray; const index: Integer = 0; const count: Integer = 2147483647): TRangeArray; overload; cdecl;

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
function TArray_Empty(const arr: Integer): TIntegerArray; overload; cdecl;
function TArray_Empty(const arr: Double): TDoubleArray; overload; cdecl;
function TArray_Empty(const arr: string): TStringArray; overload; cdecl;
function TArray_Empty(const arr: Char): TCharArray; overload; cdecl;
function TArray_Empty(const arr: Boolean): TBooleanArray; overload; cdecl;
function TArray_Empty(const arr: TPoint): TPointArray; overload; cdecl;
function TArray_Empty(const arr: TBox): TBoxArray; overload; cdecl;
function TArray_Empty(const arr: TRange): TRangeArray; overload; cdecl;

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

function TArray_Find(const arr: TIntegerArray; const IDs: TRange; const item: Integer): Integer; overload; cdecl;
function TArray_Find(const arr: TDoubleArray; const IDs: TRange; const item: Double): Integer; overload; cdecl;
function TArray_Find(const arr: TStringArray; const IDs: TRange; const item: string): Integer; overload; cdecl;
function TArray_Find(const arr: TCharArray; const IDs: TRange; const item: Char): Integer; overload; cdecl;
function TArray_Find(const arr: TBooleanArray; const IDs: TRange; const item: Boolean): Integer; overload; cdecl;
function TArray_Find(const arr: TPointArray; const IDs: TRange; const item: TPoint): Integer; overload; cdecl;
function TArray_Find(const arr: TBoxArray; const IDs: TRange; const item: TBox): Integer; overload; cdecl;
function TArray_Find(const arr: TRangeArray; const IDs: TRange; const item: TRange): Integer; overload; cdecl;
function TArray_Find(const arr: TIntegerArray; const IDs: TIntegerArray; const item: Integer): Integer; overload; cdecl;
function TArray_Find(const arr: TDoubleArray; const IDs: TIntegerArray; const item: Double): Integer; overload; cdecl;
function TArray_Find(const arr: TStringArray; const IDs: TIntegerArray; const item: string): Integer; overload; cdecl;
function TArray_Find(const arr: TCharArray; const IDs: TIntegerArray; const item: Char): Integer; overload; cdecl;
function TArray_Find(const arr: TBooleanArray; const IDs: TIntegerArray; const item: Boolean): Integer; overload; cdecl;
function TArray_Find(const arr: TPointArray; const IDs: TIntegerArray; const item: TPoint): Integer; overload; cdecl;
function TArray_Find(const arr: TBoxArray; const IDs: TIntegerArray; const item: TBox): Integer; overload; cdecl;
function TArray_Find(const arr: TRangeArray; const IDs: TIntegerArray; const item: TRange): Integer; overload; cdecl;
function TArray_Find(const arr: TIntegerArray; const IDs: TRange; const items: TIntegerArray): Integer; overload; cdecl;
function TArray_Find(const arr: TDoubleArray; const IDs: TRange; const items: TDoubleArray): Integer; overload; cdecl;
function TArray_Find(const arr: TStringArray; const IDs: TRange; const items: TStringArray): Integer; overload; cdecl;
function TArray_Find(const arr: TCharArray; const IDs: TRange; const items: TCharArray): Integer; overload; cdecl;
function TArray_Find(const arr: TBooleanArray; const IDs: TRange; const items: TBooleanArray): Integer; overload; cdecl;
function TArray_Find(const arr: TPointArray; const IDs: TRange; const items: TPointArray): Integer; overload; cdecl;
function TArray_Find(const arr: TBoxArray; const IDs: TRange; const items: TBoxArray): Integer; overload; cdecl;
function TArray_Find(const arr: TRangeArray; const IDs: TRange; const items: TRangeArray): Integer; overload; cdecl;
function TArray_Find(const arr: TIntegerArray; const IDs: TIntegerArray; const items: TIntegerArray): Integer; overload; cdecl;
function TArray_Find(const arr: TDoubleArray; const IDs: TIntegerArray; const items: TDoubleArray): Integer; overload; cdecl;
function TArray_Find(const arr: TStringArray; const IDs: TIntegerArray; const items: TStringArray): Integer; overload; cdecl;
function TArray_Find(const arr: TCharArray; const IDs: TIntegerArray; const items: TCharArray): Integer; overload; cdecl;
function TArray_Find(const arr: TBooleanArray; const IDs: TIntegerArray; const items: TBooleanArray): Integer; overload; cdecl;
function TArray_Find(const arr: TPointArray; const IDs: TIntegerArray; const items: TPointArray): Integer; overload; cdecl;
function TArray_Find(const arr: TBoxArray; const IDs: TIntegerArray; const items: TBoxArray): Integer; overload; cdecl;
function TArray_Find(const arr: TRangeArray; const IDs: TIntegerArray; const items: TRangeArray): Integer; overload; cdecl;

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

function TArray_Keep(var arr: TIntegerArray; const items: TIntegerArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Keep(var arr: TDoubleArray; const items: TDoubleArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Keep(var arr: TStringArray; const items: TStringArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Keep(var arr: TCharArray; const items: TCharArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Keep(var arr: TBooleanArray; const items: TBooleanArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Keep(var arr: TPointArray; const items: TPointArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Keep(var arr: TBoxArray; const items: TBoxArray; const index: Integer = 0): Integer; overload; cdecl;
function TArray_Keep(var arr: TRangeArray; const items: TRangeArray; const index: Integer = 0): Integer; overload; cdecl;

function TArray_LeastFrequent(const arr: TIntegerArray): Integer; overload; cdecl;
function TArray_LeastFrequent(const arr: TDoubleArray): Double; overload; cdecl;
function TArray_LeastFrequent(const arr: TStringArray): string; overload; cdecl;
function TArray_LeastFrequent(const arr: TCharArray): Char; overload; cdecl;
function TArray_LeastFrequent(const arr: TBooleanArray): Boolean; overload; cdecl;
function TArray_LeastFrequent(const arr: TPointArray): TPoint; overload; cdecl;
function TArray_LeastFrequent(const arr: TBoxArray): TBox; overload; cdecl;
function TArray_LeastFrequent(const arr: TRangeArray): TRange; overload; cdecl;

function TArray_Length(var arr: TIntegerArray; const size: Integer): Integer; overload; cdecl;
function TArray_Length(var arr: TDoubleArray; const size: Integer): Integer; overload; cdecl;
function TArray_Length(var arr: TStringArray; const size: Integer): Integer; overload; cdecl;
function TArray_Length(var arr: TCharArray; const size: Integer): Integer; overload; cdecl;
function TArray_Length(var arr: TBooleanArray; const size: Integer): Integer; overload; cdecl;
function TArray_Length(var arr: TPointArray; const size: Integer): Integer; overload; cdecl;
function TArray_Length(var arr: TBoxArray; const size: Integer): Integer; overload; cdecl;
function TArray_Length(var arr: TRangeArray; const size: Integer): Integer; overload; cdecl;
function TArray_Length(const arr: TIntegerArray): Integer; overload; cdecl;
function TArray_Length(const arr: TDoubleArray): Integer; overload; cdecl;
function TArray_Length(const arr: TStringArray): Integer; overload; cdecl;
function TArray_Length(const arr: TCharArray): Integer; overload; cdecl;
function TArray_Length(const arr: TBooleanArray): Integer; overload; cdecl;
function TArray_Length(const arr: TPointArray): Integer; overload; cdecl;
function TArray_Length(const arr: TBoxArray): Integer; overload; cdecl;
function TArray_Length(const arr: TRangeArray): Integer; overload; cdecl;

function TArray_MostFrequent(const arr: TIntegerArray): Integer; overload; cdecl;
function TArray_MostFrequent(const arr: TDoubleArray): Double; overload; cdecl;
function TArray_MostFrequent(const arr: TStringArray): string; overload; cdecl;
function TArray_MostFrequent(const arr: TCharArray): Char; overload; cdecl;
function TArray_MostFrequent(const arr: TBooleanArray): Boolean; overload; cdecl;
function TArray_MostFrequent(const arr: TPointArray): TPoint; overload; cdecl;
function TArray_MostFrequent(const arr: TBoxArray): TBox; overload; cdecl;
function TArray_MostFrequent(const arr: TRangeArray): TRange; overload; cdecl;

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

function TArray_Scan(const arr: TIntegerArray; const IDs: TRange; const item: Integer; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TDoubleArray; const IDs: TRange; const item: Double; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TStringArray; const IDs: TRange; const item: string; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TCharArray; const IDs: TRange; const item: Char; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TBooleanArray; const IDs: TRange; const item: Boolean; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TPointArray; const IDs: TRange; const item: TPoint; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TBoxArray; const IDs: TRange; const item: TBox; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TRangeArray; const IDs: TRange; const item: TRange; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TIntegerArray; const IDs: TIntegerArray; const item: Integer; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TDoubleArray; const IDs: TIntegerArray; const item: Double; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TStringArray; const IDs: TIntegerArray; const item: string; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TCharArray; const IDs: TIntegerArray; const item: Char; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TBooleanArray; const IDs: TIntegerArray; const item: Boolean; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TPointArray; const IDs: TIntegerArray; const item: TPoint; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TBoxArray; const IDs: TIntegerArray; const item: TBox; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TRangeArray; const IDs: TIntegerArray; const item: TRange; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TIntegerArray; const IDs: TRange; const items: TIntegerArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TDoubleArray; const IDs: TRange; const items: TDoubleArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TStringArray; const IDs: TRange; const items: TStringArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TCharArray; const IDs: TRange; const items: TCharArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TBooleanArray; const IDs: TRange; const items: TBooleanArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TPointArray; const IDs: TRange; const items: TPointArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TBoxArray; const IDs: TRange; const items: TBoxArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TRangeArray; const IDs: TRange; const items: TRangeArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TIntegerArray; const IDs: TIntegerArray; const items: TIntegerArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TDoubleArray; const IDs: TIntegerArray; const items: TDoubleArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TStringArray; const IDs: TIntegerArray; const items: TStringArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TCharArray; const IDs: TIntegerArray; const items: TCharArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TBooleanArray; const IDs: TIntegerArray; const items: TBooleanArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TPointArray; const IDs: TIntegerArray; const items: TPointArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TBoxArray; const IDs: TIntegerArray; const items: TBoxArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
function TArray_Scan(const arr: TRangeArray; const IDs: TIntegerArray; const items: TRangeArray; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;

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

{$mode objfpc}{$H+}

{$I MiMU.inc}

initialization

finalization

end.
