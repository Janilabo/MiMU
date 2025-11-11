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
  TConnection = record
    id1, id2: Integer;
    constructor Create(const index1, index2: Integer); overload;
    class function Construct(const index1, index2: Integer): TConnection; overload; static;
    function Build(const index1, index2: Integer): TConnection; overload;
  end;
  TConnectionArray = array of TConnection;
  TPoint = record
    X, Y: Integer;
    constructor Create(const pX, pY: Integer); overload;
    constructor Create(const value: Integer); overload;
    class function Construct(const pX, pY: Integer): TPoint; overload; static;
    function Build(const pX, pY: Integer): TPoint;  inline;
    function Comparison(const target: TPoint): Integer; overload;
    function Compare(const target: TPoint): Integer; overload;
    function Compared(const target: TPoint): Integer; overload;
    function Comp(const target: TPoint): Integer; overload;
    function Cmp(const target: TPoint): Integer; overload;
    function XComp(const target: TPoint): Integer; inline;
    function YComp(const target: TPoint): Integer; inline;
    function XCompare(const target: TPoint): Integer;
    function YCompare(const target: TPoint): Integer;
    function CompareX(const target: TPoint): Integer;
    function CompareY(const target: TPoint): Integer;
    function CompX(const target: TPoint): Integer;
    function CompY(const target: TPoint): Integer;
    function InCircle(const center: TPoint; const radius: Double): Boolean; inline;
    function InEllipse(const center: TPoint; const XRadius, YRadius: Double): Boolean; inline;
    function AngleDegrees(const target: TPoint; const compass: Boolean = False): Double; 
    function AngleRadians(const target: TPoint): Double;
    function DistHypotEuclidean(const target: TPoint): Double; 	
    function DistEuclidean(const target: TPoint): Double; 
    function DistEuclidean2(const target: TPoint): Double; 
    function DistSquaredEuclidean(const target: TPoint): Double; 
    function DistManhattan(const target: TPoint): Double; 
    function DistChebyshev(const target: TPoint): Double;
    function DistMinkowski(const target: TPoint): Double; overload;
    function DistMinkowski(const target: TPoint; const P: Double): Double; overload;
    function DistMaxMinChebyshev(const target: TPoint): Double;
    function DistOctile(const target: TPoint): Double;
    function Within(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
    function Near(const target: TPoint; const radius: Double = 1.0): Boolean; overload;
    function Near(const target: TPoint; const xRadius, yRadius: Integer): Boolean; overload;
    function Neighbour(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
    function Neighbor(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
    function Adjacent(const p: TPoint; const adjacency8: Boolean = True): Boolean; overload;
    function DistX(const target: TPoint): Integer;
    function DistY(const target: TPoint): Integer;
    function DistanceX(const target: TPoint): Integer;
    function DistanceY(const target: TPoint): Integer;
    function DistMaxMinX(const Target: TPoint): Integer;
    function DistMaxMinY(const Target: TPoint): Integer;
    function Reflected: TPoint; inline;
    function Flipped: TPoint; inline;
    function DeltaX(const target: TPoint): Integer;
    function DeltaY(const target: TPoint): Integer;
    function Delta(const target: TPoint): TPoint;
    function HorizontalDist(const target: TPoint): Integer;
    function VerticalDist(const target: TPoint): Integer;
    function Uniform(const val: Integer): Boolean; overload;
    function Uniform: Boolean; overload;
    function Employs(const val: Integer): Boolean;
    function Omits(const val: Integer): Boolean; 	
  end;
  TPointArray = array of TPoint;
  T2DPointArray = array of TPointArray;
  PPoint = ^TPoint;
  TDistanceFunction = function(const A, B: TPoint): Double;
  TDistanceMetric = (dmHypotEuclidean, dmEuclidean, dmEuclidean2, dmSquaredEuclidean, dmManhattan, dmChebyshev, dmMinkowski, dmMaxMinChebyshev, dmOctile);
  TRangeEnumerator = record
  private
    FCurrent, FStop, FStep: Integer;
    FFirst: Boolean;
  public
    constructor Init(const AStart, AStop: Integer);
    function MoveNext: Boolean;
    property Current: Integer read FCurrent;
  end;
  TRange = record
    start, stop: Integer;
    function GetEnumerator: TRangeEnumerator;
    constructor Create(const rStart, rStop: Integer); overload;
    constructor Create(const value: Integer); overload;
    class function Construct(const rStart, rStop: Integer): TRange; overload;  static;
    function Build(const rStart: Integer = 0; const rStop: Integer = 0): Integer; 
    function Init(const rStart, rStop: Integer): TRange; overload; 
    function Init(const r: TRange): TRange; overload; 
    function Init(const val: Integer = 0): TRange; overload; 
    function Singular: Boolean; 
    function Atomic: Boolean; 
    function Plural: Boolean; 
    function Composite: Boolean; 
    function Sorted(const oAscending: Boolean = True): TRange; overload; 
    function Sort(const oAscending: Boolean = True): Boolean; overload; 
    function Ordered(const oAscending: Boolean = True): TRange; overload; 
    function Order(const oAscending: Boolean = True): Boolean; overload; 
    function Asc: TIntegerArray; overload; 
    function Ascend: TRange; 
    function Ascended: TRange; 
    function Ascending: Boolean; 
    function Ascends: Boolean; 
    function Desc: TIntegerArray; overload; 
    function Descend: TRange; 
    function Descended: TRange; 
    function Descending: Boolean; 
    function Descends: Boolean; 
    function Increasing: Boolean; 
    function Decreasing: Boolean; 
    function Growing: Boolean; 
    function Grows: Boolean; 
    function Shrinking: Boolean; 
    function Shrinks: Boolean; 
    function Rising: Boolean; 
    function Rises: Boolean; 
    function Dropping: Boolean; 
    function Drops: Boolean; 
    function Grab: TRange; 
    function Count: Integer; 
    function Area: Integer; 
    function Span: Integer; 
    function Size: Integer; overload; 
    function Size(var minVal, maxVal: Integer): Integer; overload; 
    function Capacity: Integer; 
    function Delta: Integer; 
    function Frame(var rSize: Integer): TRange; overload; 
    function Frame: TRange; overload; 
    function Lowest: Integer; 
    function Minimum: Integer; 
    function Highest: Integer; 
    function Maximum: Integer; 
    function Exceeds(const maxElements: Integer): Boolean; 
    function Insufficient(const minElements: Integer): Boolean; 
    function Digits: TIntegerArray; overload; 
    function Digits(const dIndex: Integer): Integer; overload; 
    function Digits(const dIDs: TIntegerArray): TIntegerArray; overload; 
    function Ints: TIntegerArray; 
    function Values: TIntegerArray; 
    function TIA: TIntegerArray; 
    function Enumerate: TIntegerArray; 
    function Enumerated: TIntegerArray; 
    function Elements: TIntegerArray; 
    function Numbers: TIntegerArray; 
    function Items: TIntegerArray; 
    function IDs: TIntegerArray; overload; 
    function IDs(const dValue: Integer): Integer; overload; 
    function IDs(const dVals: TIntegerArray): TIntegerArray; overload; 
    function ToArray: TIntegerArray; 
    function AsArray: TIntegerArray; overload; 
    function Materialize: TIntegerArray; 
    function Mixed(const mixings: Integer = 1): TIntegerArray; 
    function Shake(const shakes: Integer = 1): TIntegerArray; 
    function Shuffle(const shuffles: Integer = 1): TIntegerArray; 
    function Any: Integer; 
    function Some: TIntegerArray; overload; 
    function Some(const amount: Integer): TIntegerArray; overload; 
    function All: TIntegerArray; overload;
    function Unzip: TIntegerArray; overload; 
    function Unpack: TIntegerArray; overload; 
    function Unwrap: TIntegerArray; overload; 
    function Unfold: TIntegerArray; overload;
    function Zigzag(const zAscending: Boolean = True): TIntegerArray; overload;
    function Normed: TRange; 
    function Norm: TRange; 
    function Normal: TRange;
    function Normally: TRange; 
    function Normalize: TRange; 
    function Normalized: TRange; 
    function Overlapping(const b: TRange): Boolean; 
    function Overlap(const b: TRange): Boolean; 
    function Intersect(const b: TRange): TRange; overload; 
    function Intersect(const b: TRange; var iZone: TRange): Boolean; overload; 
    function Union(const b: TRange): TRange; overload; 
    function Union(const val: Integer): TRange; overload; 
    function Extend(const val: Integer): Boolean; 
    function Offset(const sDelta: Integer): TRange; 
    function Contains(const x: Integer): Boolean; overload; 
    function Contains(const x: TRange): Boolean; overload;
    function Holds(const val: Integer): Boolean; overload;
    function Holds(const vals: TRange): Boolean; overload;
    function Missing(const val: Integer): Boolean; overload;
    function Missing(const vals: TRange): Boolean; overload;	
    function Above(const target: Integer): Boolean; overload; 
    function Above(const target: TRange): Boolean; overload; 
    function Below(const target: Integer): Boolean; overload; 
    function Below(const target: TRange): Boolean; overload; 
    function Reversed: TRange; 
    function Reverse: Boolean; 
    function Equals(const b: TRange): Boolean; 
    function Differs(const b: TRange): Boolean; 
    function Equal(const b: TRange): Boolean; 
    function Differ(const b: TRange): Boolean; 
    function Clamp(const zone: TRange): TRange; overload; 
    function ClampMax(const maxValue: Integer): TRange; 
    function ClampMin(const minValue: Integer): TRange; 
    function Restrict(const zone: TRange): Boolean; 
    function RestrictMin(const minValue: Integer): Boolean; 
    function RestrictMax(const maxValue: Integer): Boolean; 
    function Clip(const zone: TRange): TRange; 
    function ClipMin(const minValue: Integer): TRange; 
    function ClipMax(const maxValue: Integer): TRange; 
    function Ensured(const zone: TRange): TRange; overload; 
    function Ensure(const zone: TRange): Boolean; overload; 
    function Absorb(const val: Integer): Boolean; overload; 
    function Include(const val: Integer): TRange; overload; 
    function Neighbor(const b: TRange): Boolean; 
    function Neighbour(const b: TRange): Boolean; 
    function Touch(const b: TRange): Boolean; 
    function Touches(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; 
    function Touching(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; 
    function Distance(const b: TRange): Integer; overload;
    function Distance: Integer; overload;
    function Dist: Integer;
    function Difference: Integer;
    function Diff: Integer;
    function DistHausdorff(const b: TRange): Integer; 
    function Direction: Integer; 
    function Orientation: Integer;
    function Signum: Integer;
    function Slope: Integer;	
    function Magnitude: Integer; 
    function Deficit: Integer; 
    function Digit(const x: Integer): Boolean;  inline;
    function Value(const x: Integer): Boolean;  inline;
    function Item(const x: Integer): Boolean;  inline;
    function Pivot: Integer; 
    function Mean: Double; overload; 
    function Middle: Integer; 
    function Mid: Double; 
    function MidValue: Double; 
    function MidVal: Double; 
    function Midpoint(const wStart: Double = 1; const wStop: Double = 1): Double; overload;
    function Average: Double; 
    function Center: Integer; 
    function Central: Integer;  inline;
    function Half: Integer; overload; 
    function Halfway: Integer; overload; 
    function Halved: Integer; overload; 
    function Radius: Integer; overload; 
    function Rad: Integer; overload; 
    function Radiar: Integer; overload; 
    function AsStr(const rReversed: Boolean = False): string; overload; 
    function Str(const openRange: string = '['; const closeRange: string = ']'; const glueRange: string = '..'): string;
    function ToStr(const glueRange: string = '..'; const openRange: string = '['; const closeRange: string = ']'): string; 
    function Stringify(const openRange: string = '['; const glueRange: string = '..'; const closeRange: string = ']'): string; 
    function Sum: Int64; 
    function Summation: Int64; 
    function Total: Int64; 
    function Reserve: TIntegerArray; overload; 
    function Reserve(var aRange: TIntegerArray): Integer; overload; 
    function Extract: TIntegerArray; overload; 
    function Extracted: TIntegerArray; overload; 
    function Steps: TIntegerArray; overload; 
    function Recursed: TIntegerArray; overload; 
    function Limit(const val: Integer): Integer; 
    function MinLimit(const val: Integer): Integer; 
    function MaxLimit(const val: Integer): Integer; 
    function Lacks(const x: Integer): Boolean;  inline;
    function Outside(const x: Integer): Boolean;  inline;
    function Sample(const sSize: Integer): TIntegerArray; overload; 
    function Centered(const rCenter: Integer): TRange; overload; 
    function Shift(const N: Integer = 1): TRange; overload; 
    function Shifted(const N: Integer = 1): TRange; overload; 
    function Back(const N: Integer = 1): TRange; overload; 
    function Backed(const N: Integer = 1): TRange; overload; 
    function Increase(const N: Integer = 1): TRange; overload; 
    function Decrease(const N: Integer = 1): TRange; overload; 
    function Increment(const N: Integer = 1): TRange; overload; 
    function Decrement(const N: Integer = 1): TRange; overload; 
    function Modify(const mStart, mStop: Integer): TRange; overload; 
    function Modified(const mStart, mStop: Integer): TRange; overload; 
    function Contract(const N: Integer = 1): TRange; overload; 
    function Contracted(const N: Integer = 1): TRange; overload; 
    function Expand(const N: Integer = 1): TRange; overload; 
    function Expanded(const N: Integer = 1): TRange; overload;
    function Uniform(const val: Integer): Boolean; overload;
    function Uniform: Boolean; overload;
    function Employs(const val: Integer): Boolean;
    function Omits(const val: Integer): Boolean; 	
  end;
  TRangeArray = array of TRange;
  T2DRangeArray = array of TRangeArray;
  TBoxEnumerator = record
  private
    FX, FY, XStart, YStart, XStop, YStop: Integer;
    FFirst: Boolean;
  public
    constructor Init(const AX1, AY1, AX2, AY2: Integer);
    function MoveNext: Boolean;
    function GetCurrent: TPoint;
    property Current: TPoint read GetCurrent;
  end;
  TBox = record
    X1, Y1, X2, Y2: Integer;
    function GetEnumerator: TBoxEnumerator;
    constructor Create(const minX, minY, maxX, maxY: Integer); overload;
    constructor Create(const top, bottom: TPoint); overload;
    constructor Create(const valueX, valueY: Integer); overload;
    constructor Create(const target: TPoint); overload;
    constructor Create(const value: Integer); overload;
    class function Construct(const XS, YS, XE, YE: Integer): TBox; overload;  static;
    function Build(const minX, minY, maxX, maxY: Integer): Integer; overload; 
    function Build(const top, bottom: TPoint): Integer; overload; 
    function Build(const valueX, valueY: Integer): Integer; overload; 
    function Build(const target: TPoint): Integer; overload; 
    function Build(const value: Integer = 0): Integer; overload; 
    function Init(const bX1, bY1, bX2, bY2: Integer): TBox; overload; 
    function Init(const b: TBox): TBox; overload; 
    function Init(const val: Integer = 0): TBox; overload; 
    function Init(const p: TPoint): TBox; overload; 
    function Init(const TL, BR: TPoint): TBox; overload; 
    function Form(const pt: TPoint; const size: Integer = 1): TBox; overload; 
    function Form(const pt: TPoint; const width, height: Integer): TBox; overload; 
    function Make(const pt: TPoint; const radius: Integer = 0): TBox; overload; 
    function Make(const pt: TPoint; const wRadius, hRadius: Integer): TBox; overload; 
    function Frame(var width, height: Integer): TBox; overload; 
    function Frame: TBox; overload;  
    function Singular: Boolean; 
    function IsPoint: Boolean; 
    function IsHorizontalLine: Boolean; 
    function IsVerticalLine: Boolean; 
    function IsLine: Boolean; 
    function Linear: Boolean; 
    function Is2D: Boolean; 
    function Collapsed: Boolean; 
    function Boxy: Boolean; 
    function Plural: Boolean; 
    function Rectangular: Boolean; 
    function Equilateral: Boolean; 
    function Square: Boolean; 
    function Size(var width, height: Integer): Integer; overload;  inline;
    function Size: TPoint; overload; 
    function Area: Integer;  inline;
    function Capacity: Integer; 
    function Footprint: Double; 
    function Perimeter: Integer; 
    function Perim: Integer; 
    function Circumference: Integer; 
    function Diagonal: Double; 
    function Width: Integer; overload; 
    function Width(const w: Integer): Integer; overload; 
    function Height: Integer; overload; 
    function Height(const h: Integer): Integer; overload; 
    function Ratio: Double; 
    function Horizontal: TRange; 
    function Vertical: TRange; 
    function Expand(const change: Integer = 1): TBox; overload; 
    function Expand(const target: TBox): TBox; overload; 
    function Shrink(const change: Integer = 1): TBox; overload; 
    function Shrink(const target: TBox): TBox; overload; 
    function Resize(const change: Integer): TBox; 
    function ResizeVertically(const change: Integer): TBox; 
    function ResizeHorizontally(const change: Integer): TBox; 
    function ResizeTop(const change: Integer): TBox; 
    function ResizeBottom(const change: Integer): TBox; 
    function ResizeLeft(const change: Integer): TBox; 
    function ResizeRight(const change: Integer): TBox; 
    function ResizeTopLeft(const change: Integer): TBox; 
    function ResizeTopRight(const change: Integer): TBox; 
    function ResizeBottomRight(const change: Integer): TBox; 
    function ResizeBottomLeft(const change: Integer): TBox; 
    function Equal(const b: TBox): Boolean;  inline;
    function Contains(const pt: TPoint): Boolean; overload; 
    function Contains(const b: TBox): Boolean; overload; 
    function Center: TPoint; 
    function Envelope(const b: TBox): TBox; 
    function Overlap(const b: TBox): Boolean;  inline;
    function Intersect(const b: TBox): TBox; overload; 
    function Intersect(const b: TBox; var iArea: TBox): Boolean; overload; 
    function Valid: Boolean;  inline;
    function Invalid: Boolean; 
    function Similar(const b: TBox; const maxWDiff, maxHDiff: Integer): Boolean; overload; 
    function Similar(const b: TBox; const diff: Integer): Boolean; overload; 
    function Fix: Boolean; 
    function Constraint(const toArea: TBox): Boolean; 
    function Clip(const toArea: TBox): TBox; 
    function Restrict(const toArea: TBox): Boolean; 
    function Clamp(const toArea: TBox): TBox;
    function Unzip(var bX1, bY1, bX2, bY2: Integer): Integer; overload;	
    function Unzip: TPointArray; overload;
    function Unpack: TPointArray; overload;
    function Points: TPointArray; overload; 
    function Points(const pIndex: Integer): TPoint; overload; 
    function Points(const pIDs: TIntegerArray): TPointArray; overload; 
    function Points(var xArray, yArray: TIntegerArray): Integer; overload; 
    function Pixels: TPointArray; overload; 
    function Pixels(const index: Integer): TPoint; overload; 
    function Pixeled: TPointArray; overload; 
    function Pts: TPointArray; overload;
    function Explode: TPointArray; overload; 
    function Flat: TPointArray; overload; 	
    function IDs: TIntegerArray; overload; 
    function IDs(const p: TPoint): Integer; overload; 
    function IDs(const p: TPointArray): TIntegerArray; overload; 
    function TPA: TPointArray; overload; 
    function TPA(const index: Integer): TPoint; overload; 
    function Contents: TPointArray;
    function Content: TPointArray;	
    function Extract: TPointArray; 
    function Enumerate: TPointArray; 
    function Enumerated: TPointArray; 
    function Elements: TPointArray;	
    function Border: TPointArray; overload; 
    function Border(const X, Y: Integer): Boolean; overload; 
    function Border(const pt: TPoint): Boolean; overload; 
    function Edge: TPointArray; overload; 
    function Edge(const X, Y: Integer): Boolean; overload; 
    function Edge(const pt: TPoint): Boolean; overload; 
    function Outline: TPointArray; overload; 
    function Outline(const X, Y: Integer): Boolean; overload; 
    function Outline(const pt: TPoint): Boolean; overload; 
    function Contour: TPointArray; 
    function Spiral: TPointArray; 
    function Traverse: TPointArray; 
    function CornerPoints: TPointArray; 
    function CornerPts: TPointArray; 
    function Corners: TPointArray; 
    function Rows: T2DPointArray; 
    function Columns: T2DPointArray; 
    function Rowwise: TPointArray; 
    function Columnwise: TPointArray; 
    function SimilarSize(const b: TBox; const widthDifferency, heightDifferency: Integer): Boolean; overload; 
    function SimilarSize(const b: TBox; const differency: Integer): Boolean; overload; 
    function Centered(const toArea: TBox): TBox; 
    function CenterVertically(const toArea: TBox): TBox; 
    function CenterHorizontally(const toArea: TBox): TBox; 
    function Inside(const target: TBox): Boolean; overload; 
    function ExtendX(const xCoord: Integer): Boolean; 
    function ExtendY(const yCoord: Integer): Boolean; 
    function Extend(const pt: TPoint): Boolean; 
    function UnionX(const xCoord: Integer): TBox; 
    function Uniony(const yCoord: Integer): TBox; 
    function Union(const pt: TPoint): TBox; overload; 
    function Union(const b: TBox): TBox; overload; 
    function Disjoint(const target: TBox): Boolean; overload; 
    function Lacks(const pt: TPoint): Boolean; overload; 
    function Mixed(const mixings: Integer = 1): TPointArray; 
    function Shake(const shakes: Integer = 1): TPointArray; 
    function Shuffle(const shuffles: Integer = 1): TPointArray; 
    function Any: TPoint; 
    function Some: TPointArray; overload; 
    function Some(const amount: Integer): TPointArray; overload; 
    function All: TPointArray; overload;
    function Places(const target: TBox; const o: TPoint): TPointArray; overload;
    function Places(const target: TBox): TPointArray; overload;
    function Reserve: TPointArray; overload; 
    function Reserve(var aBox: TPointArray): Integer; overload;
    function Uniform(const val: Integer): Boolean; overload;
    function Uniform: Boolean; overload;
    function Employs(const val: Integer): Boolean;
    function Omits(const val: Integer): Boolean; 
  end;
  TBoxArray = array of TBox;
  T2DBoxArray = array of TBoxArray;
  TSegment = record
    A, B: TPoint;
    constructor Create(const sA, sB: TPoint); overload;
    constructor Create(const aX, aY, bX, bY: Integer); overload;
    class function Construct(const sA, sB: TPoint): TSegment; overload;  static;
    class function Construct(const aX, aY, bX, bY: Integer): TSegment; overload;  static;
    function Bounds: TBox; 
    function Boundaries: TBox; 
    function Envelope: TBox; 
    function Points: TPointArray; 
    function Pixels(const steps: Integer = 2147483647): TPointArray; 
  end;
  TSegmentArray = array of TSegment;
  T2DSegmentArray = array of TSegmentArray;
  TCircle = record
    Center: TPoint;
    Radius: Double;
    constructor Create(const cCenter: TPoint; const cRadius: Double); overload;
    constructor Create(const centerX, centerY: Integer; const cRadius: Double); overload;
    class function Construct(const cCenter: TPoint; const cRadius: Double): TCircle; overload;  static;
    class function Construct(const centerX, centerY: Integer; const cRadius: Double): TCircle; overload;  static;
    function Contains(const pt: TPoint): Boolean; 
    function Item(const pt: TPoint): Boolean; 
    function Pixel(const pt: TPoint): Boolean; 
    function Bounds: TBox; 
    function Boundaries: TBox; 
    function BoundingBox: TBox; 
    function Envelope: TBox; 
    function Points: TPointArray; 
    function TPA: TPointArray; 
    function BorderPoints(const count: Integer): TPointArray; 
    function Border: TPointArray; 
  end;
  TCircleArray = array of TCircle;
  T2DCircleArray = array of TCircleArray;
  TTriangle = record
    A, B, C: TPoint;
  end;
  TTriangleArray = array of TTriangle;
  T2DTriangleArray = array of TTriangleArray;

function MiMU_Version: Double; 

generic function Sort<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
generic function Sort<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
generic function Swap<T>(var A, B: T): Boolean; overload;
generic function Swop<T>(var A, B: T; const oAscending: Boolean = True): Boolean; overload;
generic function Swop<T>(var A, B, C: T; const oAscending: Boolean = True): Boolean; overload;
generic function Contains<T>(const arr: array of T; const item: T): Boolean;
generic function Includes<T>(const arr: array of T; const item: T): Boolean;
generic function Position<T>(const arr: array of T; const item: T): Integer;
generic function Location<T>(const arr: array of T; const item: T): Integer;
generic function Indexes<T>(const arr: array of T): TIntegerArray;
generic function IfThenElse<T>(const aBool, bBool: Boolean; const aResult, bResult, cResult: T): T;
generic function SetSize<T>(var A, B: specialize TArray<T>; const size: Integer = 1): Integer; overload;
generic function SetSize<T>(var A, B, C: specialize TArray<T>; const size: Integer = 1): Integer; overload;
generic function SetSize<T>(var A, B, C, D: specialize TArray<T>; const size: Integer = 1): Integer; overload;

operator+(const a, b: TPoint): TPoint;
operator+(const a, b: TBox): TBox;
operator+(const a, b: TRange): TRange;

operator-(const a, b: TPoint): TPoint;
operator-(const a, b: TBox): TBox;
operator-(const a, b: TRange): TRange;

operator=(const a, b: TPoint): Boolean;
operator=(const a, b: TBox): Boolean;
operator=(const a, b: TRange): Boolean;
operator=(const a, b: TSegment): Boolean;
operator=(const a, b: TCircle): Boolean;
operator=(const a, b: TTriangle): Boolean;

operator<>(const a, b: TPoint): Boolean;
operator<>(const a, b: TBox): Boolean;
operator<>(const a, b: TRange): Boolean;
operator<>(const a, b: TSegment): Boolean;
operator<>(const a, b: TCircle): Boolean;
operator<>(const a, b: TTriangle): Boolean;

operator>(const a, b: TPoint): Boolean;
operator<(const a, b: TPoint): Boolean;
operator>=(const a, b: TPoint): Boolean;
operator<=(const a, b: TPoint): Boolean;

function RandomB: Boolean; overload; 
function RandomBit: Byte; overload; 
function RandomSample(const x: Integer; const size: Integer): TIntegerArray; overload; 
function RandomMean(const x: Integer; const sample: Integer = 10): Integer; overload; 
function Random2(const x: Integer; const r: Integer = 2): Integer; overload; 
function RandomMax(const x: Integer; const r: Integer = 2): Integer; overload; 
function RandomMin(const x: Integer; const r: Integer = 2): Integer; overload; 

function Max(a, b: string): string; overload; inline;
function Max(a, b: Char): Char; overload; inline;
function Min(a, b: string): string; overload; inline;
function Min(a, b: Char): Char; overload; inline;

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
  
{$DEFINE Sortable}
  {$DEFINE Integer}{$I MiMU\config\Helpers.inc}{$UNDEF Integer}
  {$DEFINE Double}{$I MiMU\config\Helpers.inc}{$UNDEF Double}
  {$DEFINE string}{$I MiMU\config\Helpers.inc}{$UNDEF string}
  {$DEFINE Char}{$I MiMU\config\Helpers.inc}{$UNDEF Char}
{$UNDEF Sortable}
{$DEFINE Boolean}{$I MiMU\config\Helpers.inc}{$UNDEF Boolean}
{$DEFINE TPoint}{$I MiMU\config\Helpers.inc}{$UNDEF TPoint}
{$DEFINE TBox}{$I MiMU\config\Helpers.inc}{$UNDEF TBox}
{$DEFINE TRange}{$I MiMU\config\Helpers.inc}{$UNDEF TRange}
type
  TInt64Helper = type helper for Int64
    function Prime: Boolean; 
    function IsPrime: Boolean; 
    function Parity: Byte; inline;
    function Even: Boolean; inline;
    function Odd: Boolean; inline;
    function Increase(const N: Int64 = 1): Int64; 
    function Decrease(const N: Int64 = 1): Int64; 
    function Increment(const N: Int64 = 1): Int64; 
    function Decrement(const N: Int64 = 1): Int64; 
    function DigitCount: Integer; 
    function Digitz: TIntegerArray; 
    function Digits: TIntegerArray; 
    function Compare(const target: Int64): Integer; inline;
    function Precede(const target: Int64; const aAscending: Boolean): Boolean; overload; 
    function Distance(const T: Int64): Int64; inline;
    function Difference(const T: Int64): Int64; inline;
    function Opposite: Int64; inline;
    function Sign(const target: Int64 = 0): Integer; inline;
    function Shuffle: Int64; 
    function Over(const target: Int64): Boolean; inline;
    function Under(const target: Int64): Boolean; inline;
    function Oversize(const limit: Int64): Boolean; inline;
    function Undersize(const limit: Int64): Boolean; inline;
  end;
  TIA = class
  public
    class function Init(var arr: TIntegerArray): Integer; overload; 
    class function Reverse(var arr: TIntegerArray): Boolean; overload; 
    class function Reversed(const arr: TIntegerArray): TIntegerArray; overload; 
    class function Unique(var arr: TIntegerArray): Integer; overload; 
    class function Combine(const A, B: TIntegerArray): TIntegerArray; overload;
  end;
  TPA = class
    class function Init(var arr: TPointArray): Integer; overload; 
    class function Unique(var arr: TPointArray): Integer; overload; 
    class function Create(const xRange, yRange: TRange): TPointArray; overload; 
    class function Create(const xRange, yRange: TRange; const offset: TPoint): TPointArray; overload; 
    class function Create(const xValues, yValues: TIntegerArray): TPointArray; overload; 
    class function Create(const xValues, yValues: TIntegerArray; const offset: TPoint): TPointArray; overload; 
  end;
  TBA = class
    class function Init(var arr: TBooleanArray): Integer; overload; 
  end;
  ATIA = class
  public
    class function Merge(const arr: T2DIntegerArray): TIntegerArray; overload; 
    class function Create(const width, height: Integer; const value: Integer = 0): T2DIntegerArray; overload; 
    class function Build(const rows, columns: Integer; const value: Integer = 0): T2DIntegerArray; overload; 
  end;
{$DEFINE T1D}
  T1D = class
  public
  {$DEFINE Sortable}
    {$DEFINE Integer}{$I MiMU\config\Classes.inc}{$UNDEF Integer}
    {$DEFINE Double}{$I MiMU\config\Classes.inc}{$UNDEF Double}
    {$DEFINE string}{$I MiMU\config\Classes.inc}{$UNDEF string}
    {$DEFINE Char}{$I MiMU\config\Classes.inc}{$UNDEF Char}
  {$UNDEF Sortable}
  {$DEFINE Boolean}{$I MiMU\config\Classes.inc}{$UNDEF Boolean}
  {$DEFINE TPoint}{$I MiMU\config\Classes.inc}{$UNDEF TPoint}
  {$DEFINE TBox}{$I MiMU\config\Classes.inc}{$UNDEF TBox}
  {$DEFINE TRange}{$I MiMU\config\Classes.inc}{$UNDEF TRange}
  end;
{$UNDEF T1D}
{$DEFINE T2D}
  T2D = class
  public
   {$DEFINE Sortable}
    {$DEFINE Integer}{$I MiMU\config\Classes.inc}{$UNDEF Integer}
    {$DEFINE Double}{$I MiMU\config\Classes.inc}{$UNDEF Double}
    {$DEFINE string}{$I MiMU\config\Classes.inc}{$UNDEF string}
    {$DEFINE Char}{$I MiMU\config\Classes.inc}{$UNDEF Char}
  {$UNDEF Sortable}
  {$DEFINE Boolean}{$I MiMU\config\Classes.inc}{$UNDEF Boolean}
  {$DEFINE TPoint}{$I MiMU\config\Classes.inc}{$UNDEF TPoint}
  {$DEFINE TBox}{$I MiMU\config\Classes.inc}{$UNDEF TBox}
  {$DEFINE TRange}{$I MiMU\config\Classes.inc}{$UNDEF TRange}
  end;
{$UNDEF T2D}
  _TPoint = class
  public
    class function Create(const pX, pY: Integer): TPoint; overload; 
    class function Create(const value: Integer = 0): TPoint; overload; 
  end;
  _TBox = class
  public
    class function Create(const minX, minY, maxX, maxY: Integer): TBox; overload; 
    class function Create(const top, bottom: TPoint): TBox; overload; 
    class function Create(const valueX, valueY: Integer): TBox; overload; 
    class function Create(const target: TPoint): TBox; overload; 
    class function Create(const value: Integer = 0): TBox; overload; 
  end;
  _TRange = class
  public
    class function Create(const rStart, rStop: Integer): TRange; overload; 
    class function Create(const value: Integer = 0): TRange; overload; 
  end;

{$DEFINE IMPLEMENT}{$INCLUDE MiMU\config\Templates\D.inc}{$UNDEF IMPLEMENT} 
 
implementation

{==============================================================================]
  <TConnection.Create>
  @action: Creates TConnection with index1 and index2.
  @note: None.
[==============================================================================}
constructor TConnection.Create(const index1, index2: Integer); overload;
begin
  Self.id1 := index1;
  Self.id2 := index2;
end;

class function TConnection.Construct(const index1, index2: Integer): TConnection; overload;
begin
  Result.id1 := index1;
  Result.id2 := index2;
end;

function TConnection.Build(const index1, index2: Integer): TConnection; overload;
begin
  Self.id1 := index1;
  Self.id2 := index2;
  Result := Self;
end;

constructor TRangeEnumerator.Init(const AStart, AStop: Integer);
begin
  FStop := AStop;
  if (AStart <= AStop) then
    FStep := 1
  else
    FStep := -1;
  FCurrent := (AStart - FStep);
  FFirst := True;
end;

function TRangeEnumerator.MoveNext: Boolean;
begin
  Inc(FCurrent, FStep);
  Result := ((FStep > 0) and (FCurrent <= FStop) or (FStep < 0) and (FCurrent >= FStop));
end;

function TRange.GetEnumerator: TRangeEnumerator;
begin
  Result.Init(start, stop);
end;

constructor TBoxEnumerator.Init(const AX1, AY1, AX2, AY2: Integer);
begin
  XStart := AX1;
  XStop := AX2;
  YStart := AY1;
  YStop := AY2;
  FX := (XStart - 1);
  FY := YStart;
  FFirst := True;
end;

function TBoxEnumerator.MoveNext: Boolean;
begin
  if FFirst then
  begin
    FFirst := False;
    FX := XStart;
    Result := True;
    Exit;
  end;
  Inc(FX);
  if (FX > XStop) then
  begin
    FX := XStart;
    Inc(FY);
  end;
  Result := (FY <= YStop);
end;

function TBoxEnumerator.GetCurrent: TPoint;
begin
  Result := Point(FX, FY);
end;


function TBox.GetEnumerator: TBoxEnumerator;
begin
  Result.Init(X1, Y1, X2, Y2);
end;

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

operator=(const a, b: TSegment): Boolean;
begin
  Result := ((a.A.X = b.A.X) and (a.A.Y = b.A.Y) and (a.B.X = b.B.X) and (a.B.Y = b.B.Y));
end;

operator=(const a, b: TCircle): Boolean;
begin
  Result := ((a.Center = b.Center) and (a.Radius = b.Radius));
end;

operator=(const a, b: TTriangle): Boolean;
begin
  Result := ((a.A = b.A) and (a.B = b.B) and (a.C = b.C));
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

operator<>(const a, b: TSegment): Boolean;
begin
  Result := not (a = b);
end;

operator<>(const a, b: TCircle): Boolean;
begin
  Result := not (a = b);
end;

operator<>(const a, b: TTriangle): Boolean;
begin
  Result := not (a = b);
end;

operator>(const a, b: TPoint): Boolean;
begin
  Result := ((a.Y > b.Y) or ((a.Y = b.Y) and (a.X > b.X)));
end;

operator<(const a, b: TPoint): Boolean;
begin
  Result := ((a.Y < b.Y) or ((a.Y = b.Y) and (a.X < b.X)));
end;

operator >=(const a, b: TPoint): Boolean;
begin
  Result := ((a > b) or (a = b));
end;

operator <=(const a, b: TPoint): Boolean;
begin
  Result := ((a < b) or (a = b));
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

class function TBA.Init(var arr: TBooleanArray): Integer; overload; 
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], Result, 0);
end;

class function TIA.Init(var arr: TIntegerArray): Integer; overload; 
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], (Result * SizeOf(Integer)), 0);
end;

class function TIA.Unique(var arr: TIntegerArray): Integer; overload; 
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

class function TIA.Reverse(var arr: TIntegerArray): Boolean; overload; 
var
  a: TIntegerArray;
  i: Integer;
begin
  Result := (Length(arr) > 1);
  if not Result then
    Exit;
  SetLength(a, Length(arr));
  for i := 0 to High(arr) do
    a[i] := arr[High(arr) - i];
  Move(a[0], arr[0], (Length(arr) * SizeOf(Integer)));
end;

class function TIA.Reversed(const arr: TIntegerArray): TIntegerArray; overload; 
var
  i, r: Integer;
begin
  SetLength(Result, Length(arr));
  if (Length(arr) = 0) then
    Exit;
  Move(arr[0], Result[0], (Length(arr) * SizeOf(Integer)));
  for i := 0 to (High(Result) div 2) do
  begin
    r := Result[i];
    Move(Result[High(Result) - i], Result[i], SizeOf(Integer));
    Move(r, Result[High(Result) - i], SizeOf(Integer));
  end;
end;

class function TIA.Combine(const A, B: TIntegerArray): TIntegerArray; overload; 
var
  x, y: Integer;
begin
  x := Length(A);
  y := Length(B);
  SetLength(Result, (x + y));
  if (x > 0) then
    Move(A[0], Result[0], (x * SizeOf(Integer)));
  if (y > 0) then
    Move(B[0], Result[x], (y * SizeOf(Integer)));
end;

class function ATIA.Merge(const arr: T2DIntegerArray): TIntegerArray; overload; 
var
  i, r: Integer;
begin
  SetLength(Result, arr.Size);
  if Result.Empty then
    Exit;
  r := 0;
  for i := 0 to High(arr) do
    if (arr[i].Size > 0) then
	  Move(arr[i][0], Result[r.Increase(arr[i].Size)], (arr[i].Size * SizeOf(Integer))); 
end;

class function ATIA.Create(const width, height: Integer; const value: Integer = 0): T2DIntegerArray; overload; 
var
  x, y: Integer;
begin
  SetLength(Result, height, width);
  for y := 0 to High(Result) do
    for x := 0 to High(Result[y]) do
      Result[y][x] := value;
end;

class function ATIA.Build(const rows, columns: Integer; const value: Integer = 0): T2DIntegerArray; overload; 
var
  r, c: Integer;
begin
  SetLength(Result, rows, columns);
  for r := 0 to High(Result) do
    for c := 0 to High(Result[r]) do
      Result[r][c] := value;
end;


class function TPA.Init(var arr: TPointArray): Integer; overload; 
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], (Result * SizeOf(TPoint)), 0);
end;

class function TPA.Unique(var arr: TPointArray): Integer; overload; 
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
    m := T2D.Create(False, w, h);
    for i := 0 to (l - 1) do
      if m[arr[i].X - b.X1][arr[i].Y - b.Y1].Enable then
        arr[r.Increase] := arr[i];
    SetLength(arr, r);
    SetLength(m, 0);
  end;
  Result := (l - Length(arr));
end;

class function TPA.Create(const xRange, yRange: TRange): TPointArray; overload; 
var
  x, y, i: Integer;
begin
  SetLength(Result, (xRange.Size * yRange.Size));
  i := 0;
  for y in yRange do
    for x in xRange do
      Result[i.Increase] := Point(x, y);
end;

class function TPA.Create(const xRange, yRange: TRange; const offset: TPoint): TPointArray; overload; 
var
  x, y, i: Integer;
begin
  SetLength(Result, (xRange.Size * yRange.Size));
  i := 0;
  for y in yRange do
    for x in xRange do
      Result[i.Increase] := Point((x + offset.X), (y + offset.Y));
end;

class function TPA.Create(const xValues, yValues: TIntegerArray): TPointArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, Min(Length(xValues), Length(yValues)));
  for i := 0 to High(Result) do
    Result[i] := Point(xValues[i], yValues[i]);	
end;

class function TPA.Create(const xValues, yValues: TIntegerArray; const offset: TPoint): TPointArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, Min(Length(xValues), Length(yValues)));
  for i := 0 to High(Result) do
    Result[i] := Point((xValues[i] + offset.X), (yValues[i] + offset.Y));	
end;

{$mode objfpc}{$H+}

{$I MiMU.inc}

initialization

finalization

end.
