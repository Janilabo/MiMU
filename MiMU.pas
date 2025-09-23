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
  TPoint = record
    X, Y: Integer;
    constructor Create(const pX, pY: Integer); overload;
    constructor Create(const value: Integer); overload;
    class function Construct(const pX, pY: Integer): TPoint; overload; cdecl; static;
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
  PPoint = ^TPoint;
  TRange = record
    start, stop: Integer;
    constructor Create(const rStart, rStop: Integer); overload;
    constructor Create(const value: Integer); overload;
    class function Construct(const rStart, rStop: Integer): TRange; overload; cdecl; static;
    function Singular: Boolean; cdecl;
    function Atomic: Boolean; cdecl;
    function Plural: Boolean; cdecl;
    function Composite: Boolean; cdecl;
    function Ascend: TRange; cdecl;
    function Ascending: Boolean; cdecl;
    function Descend: TRange; cdecl;
    function Descending: Boolean; cdecl;
    function Increasing: Boolean; cdecl;
    function Decreasing: Boolean; cdecl;
    function Build(const rStart: Integer = 0; const rStop: Integer = 0): Integer; cdecl;
    function Grab: TRange; cdecl;
    function Count: Integer; cdecl;
    function Area: Integer; cdecl;
    function Span: Integer; cdecl;
    function Size: Integer; cdecl;
    function Capacity: Integer; cdecl;
    function Delta: Integer; cdecl;
    function Lowest: Integer; cdecl;
    function Minimum: Integer; cdecl;
    function Highest: Integer; cdecl;
    function Maximum: Integer; cdecl;
    function Exceeds(const maxElements: Integer): Boolean; cdecl;
    function Insufficient(const minElements: Integer): Boolean; cdecl;
    function Digits: TIntegerArray; overload; cdecl;
    function Digits(const dIndex: Integer): Integer; overload; cdecl;
    function Digits(const dIDs: TIntegerArray): TIntegerArray; overload; cdecl;
    function Ints: TIntegerArray; cdecl;
    function Values: TIntegerArray; cdecl;
    function TIA: TIntegerArray; cdecl;
    function Enumerate: TIntegerArray; cdecl;
    function Enumerated: TIntegerArray; cdecl;
    function Elements: TIntegerArray; cdecl;
    function Numbers: TIntegerArray; cdecl;
    function Items: TIntegerArray; cdecl;
    function IDs: TIntegerArray; overload; cdecl;
    function IDs(const dValue: Integer): Integer; overload; cdecl;
    function IDs(const dVals: TIntegerArray): TIntegerArray; overload; cdecl;
    function ToArray: TIntegerArray; cdecl;
    function Materialize: TIntegerArray; cdecl;
    function Mixed(const mixings: Integer = 1): TIntegerArray; cdecl;
    function Shake(const shakes: Integer = 1): TIntegerArray; cdecl;
    function Shuffle(const shuffles: Integer = 1): TIntegerArray; cdecl;
    function Any: Integer; cdecl;
    function Some: TIntegerArray; overload; cdecl;
    function Some(const amount: Integer): TIntegerArray; overload; cdecl;
    function Normalize: TRange; cdecl;
    function Overlapping(const b: TRange): Boolean; cdecl;
    function Overlap(const b: TRange): Boolean; cdecl;
    function Intersect(const b: TRange): TRange; overload; cdecl;
    function Intersect(const b: TRange; var iZone: TRange): Boolean; overload; cdecl;
    function Union(const b: TRange): TRange; overload; cdecl;
    function Union(const val: Integer): TRange; overload; cdecl;
    function Extend(const val: Integer): Boolean; cdecl;
    function Shift(const sDelta: Integer): TRange; cdecl;
    function Contains(const x: Integer): Boolean; overload; cdecl;
    function Contains(const x: TRange): Boolean; overload; cdecl;
    function Above(const target: Integer): Boolean; overload; cdecl;
    function Above(const target: TRange): Boolean; overload; cdecl;
    function Below(const target: Integer): Boolean; overload; cdecl;
    function Below(const target: TRange): Boolean; overload; cdecl;
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
    function Neighbor(const b: TRange): Boolean; cdecl;
    function Neighbour(const b: TRange): Boolean; cdecl;
    function Touch(const b: TRange): Boolean; cdecl;
    function Touches(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; cdecl;
    function Touching(const b: TRange; const maxTouch: Integer = 1; const minTouch: Integer = 1): Boolean; cdecl;
    function Distance(const b: TRange): Integer; cdecl;
    function DistHausdorff(const b: TRange): Integer; cdecl;
    function Digit(const x: Integer): Boolean; cdecl; inline;
    function Value(const x: Integer): Boolean; cdecl; inline;
    function Item(const x: Integer): Boolean; cdecl; inline;
    function Middle: Double; cdecl;
    function MidValue: Double; cdecl;
    function MidVal: Double; cdecl;
    function Average: Double; cdecl;
    function Center: Integer; cdecl;
    function Str(const openRange: string = '['; const closeRange: string = ']'; const glueRange: string = '..'): string; cdecl;
    function ToStr(const glueRange: string = '..'; const openRange: string = '['; const closeRange: string = ']'): string; cdecl;
    function Stringify(const openRange: string = '['; const glueRange: string = '..'; const closeRange: string = ']'): string; cdecl;
    function Sum: Int64; cdecl;
    function Summation: Int64; cdecl;
    function Total: Int64; cdecl;
    function Extract: TIntegerArray; overload; cdecl;
    function Lacks(const x: Integer): Boolean; cdecl; inline;
    function Outside(const x: Integer): Boolean; cdecl; inline;
  end;
  TBox = record
    X1, Y1, X2, Y2: Integer;
    constructor Create(const minX, minY, maxX, maxY: Integer); overload;
    constructor Create(const top, bottom: TPoint); overload;
    constructor Create(const valueX, valueY: Integer); overload;
    constructor Create(const target: TPoint); overload;
    constructor Create(const value: Integer); overload;
    class function Construct(const XS, YS, XE, YE: Integer): TBox; overload; cdecl; static;
    function Build(const minX, minY, maxX, maxY: Integer): Integer; overload; cdecl;
    function Build(const top, bottom: TPoint): Integer; overload; cdecl;
    function Build(const valueX, valueY: Integer): Integer; overload; cdecl;
    function Build(const target: TPoint): Integer; overload; cdecl;
    function Build(const value: Integer = 0): Integer; overload; cdecl;
    function Form(const pt: TPoint; const size: Integer = 1): TBox; overload; cdecl;
    function Form(const pt: TPoint; const width, height: Integer): TBox; overload; cdecl;
    function Make(const pt: TPoint; const radius: Integer = 0): TBox; overload; cdecl;
    function Make(const pt: TPoint; const wRadius, hRadius: Integer): TBox; overload; cdecl;
    function Frame(var width, height: Integer): TBox; overload; cdecl;
    function Frame: TBox; overload; cdecl;
    function Singular: Boolean; cdecl;
    function IsPoint: Boolean; cdecl;
    function IsHorizontalLine: Boolean; cdecl;
    function IsVerticalLine: Boolean; cdecl;
    function IsLine: Boolean; cdecl;
    function Linear: Boolean; cdecl;
    function Is2D: Boolean; cdecl;
    function Collapsed: Boolean; cdecl;
    function Boxy: Boolean; cdecl;
    function Plural: Boolean; cdecl;
    function Rectangular: Boolean; cdecl;
    function Equilateral: Boolean; cdecl;
    function Square: Boolean; cdecl;
    function Size(var width, height: Integer): Integer; overload; cdecl; inline;
    function Size: TPoint; overload; cdecl;
    function Area: Integer; cdecl; inline;
    function Perimeter: Integer; cdecl;
    function Perim: Integer; cdecl;
    function Circumference: Integer; cdecl;
    function Diagonal: Double; cdecl;
    function Width: Integer; overload; cdecl;
    function Width(const w: Integer): Integer; overload; cdecl;
    function Height: Integer; overload; cdecl;
    function Height(const h: Integer): Integer; overload; cdecl;
    function Ratio: Double; cdecl;
    function Horizontal: TRange; cdecl;
    function Vertical: TRange; cdecl;
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
    function Valid: Boolean; cdecl; inline;
    function Invalid: Boolean; cdecl;
    function Similar(const b: TBox; const maxWDiff, maxHDiff: Integer): Boolean; overload; cdecl;
    function Similar(const b: TBox; const diff: Integer): Boolean; overload; cdecl;
    function Fix: Boolean; cdecl;
    function Constraint(const toArea: TBox): Boolean; cdecl;
    function Clip(const toArea: TBox): TBox; cdecl;
    function Restrict(const toArea: TBox): Boolean; cdecl;
    function Clamp(const toArea: TBox): TBox; cdecl;
    function Points: TPointArray; overload; cdecl;
    function Points(const pIndex: Integer): TPoint; overload; cdecl;
    function Points(const pIDs: TIntegerArray): TPointArray; overload; cdecl;
    function Points(var xArray, yArray: TIntegerArray): Integer; overload; cdecl;
    function Pixels: TPointArray; cdecl;
    function Pts: TPointArray; overload; cdecl;
    function IDs: TIntegerArray; overload; cdecl;
    function IDs(const p: TPoint): Integer; overload; cdecl;
    function IDs(const p: TPointArray): TIntegerArray; overload; cdecl;
    function TPA: TPointArray; cdecl;
    function Contents: TPointArray; cdecl;
    function Extract: TPointArray; cdecl;
    function Enumerate: TPointArray; cdecl;
    function Elements: TPointArray; cdecl;
    function Border: TPointArray; overload; cdecl;
    function Border(const X, Y: Integer): Boolean; overload; cdecl;
    function Border(const pt: TPoint): Boolean; overload; cdecl;
    function Edge: TPointArray; overload; cdecl;
    function Edge(const X, Y: Integer): Boolean; overload; cdecl;
    function Edge(const pt: TPoint): Boolean; overload; cdecl;
    function Outline: TPointArray; overload; cdecl;
    function Outline(const X, Y: Integer): Boolean; overload; cdecl;
    function Outline(const pt: TPoint): Boolean; overload; cdecl;
    function Contour: TPointArray; cdecl;
    function Spiral: TPointArray; cdecl;
    function Traverse: TPointArray; cdecl;
    function CornerPoints: TPointArray; cdecl;
    function CornerPts: TPointArray; cdecl;
    function Corners: TPointArray; cdecl;
    function Rows: T2DPointArray; cdecl;
    function Columns: T2DPointArray; cdecl;
    function Rowwise: TPointArray; cdecl;
    function Columnwise: TPointArray; cdecl;
    function SimilarSize(const b: TBox; const widthDifferency, heightDifferency: Integer): Boolean; overload; cdecl;
    function SimilarSize(const b: TBox; const differency: Integer): Boolean; overload; cdecl;
    function Centered(const toArea: TBox): TBox; cdecl;
    function CenterVertically(const toArea: TBox): TBox; cdecl;
    function CenterHorizontally(const toArea: TBox): TBox; cdecl;
    function Inside(const target: TBox): Boolean; overload; cdecl;
    function ExtendX(const xCoord: Integer): Boolean; cdecl;
    function ExtendY(const yCoord: Integer): Boolean; cdecl;
    function Extend(const pt: TPoint): Boolean; cdecl;
    function UnionX(const xCoord: Integer): TBox; cdecl;
    function Uniony(const yCoord: Integer): TBox; cdecl;
    function Union(const pt: TPoint): TBox; overload; cdecl;
    function Union(const b: TBox): TBox; overload; cdecl;
    function Disjoint(const target: TBox): Boolean; overload; cdecl;
    function Lacks(const pt: TPoint): Boolean; overload; cdecl;
    function Mixed(const mixings: Integer = 1): TPointArray; cdecl;
    function Shake(const shakes: Integer = 1): TPointArray; cdecl;
    function Shuffle(const shuffles: Integer = 1): TPointArray; cdecl;
    function Any: TPoint; cdecl;
    function Some: TPointArray; overload; cdecl;
    function Some(const amount: Integer): TPointArray; overload; cdecl;
  end;
  TBoxArray = array of TBox;
  T2DBoxArray = array of TBoxArray;
  TSegment = record
    A, B: TPoint;
    constructor Create(const sA, sB: TPoint); overload;
    constructor Create(const aX, aY, bX, bY: Integer); overload;
    class function Construct(const sA, sB: TPoint): TSegment; overload; cdecl; static;
    class function Construct(const aX, aY, bX, bY: Integer): TSegment; overload; cdecl; static;
    function Bounds: TBox; cdecl;
    function Boundaries: TBox; cdecl;
    function Envelope: TBox; cdecl;
    function Points: TPointArray; cdecl;
    function Pixels(const steps: Integer = 2147483647): TPointArray; cdecl;
  end;
  TSegmentArray = array of TSegment;
  T2DSegmentArray = array of TSegmentArray;
  TCircle = record
    Center: TPoint;
    Radius: Double;
    constructor Create(const cCenter: TPoint; const cRadius: Double); overload;
    constructor Create(const centerX, centerY: Integer; const cRadius: Double); overload;
    class function Construct(const cCenter: TPoint; const cRadius: Double): TCircle; overload; cdecl; static;
    class function Construct(const centerX, centerY: Integer; const cRadius: Double): TCircle; overload; cdecl; static;
    function Contains(const pt: TPoint): Boolean; cdecl;
    function Item(const pt: TPoint): Boolean; cdecl;
    function Pixel(const pt: TPoint): Boolean; cdecl;
    function Bounds: TBox; cdecl;
    function Boundaries: TBox; cdecl;
    function BoundingBox: TBox; cdecl;
    function Envelope: TBox; cdecl;
    function Points: TPointArray; cdecl;
    function TPA: TPointArray; cdecl;
    function BorderPoints(const count: Integer): TPointArray; cdecl;
    function Border: TPointArray; cdecl;
  end;
  TCircleArray = array of TCircle;
  T2DCircleArray = array of TCircleArray;
  TTriangle = record
    A, B, C: TPoint;
  end;
  TTriangleArray = array of TTriangle;
  T2DTriangleArray = array of TTriangleArray;

function MiMU_Version: Double; cdecl;

generic function Contains<T>(const arr: array of T; const item: T): Boolean;
generic function Includes<T>(const arr: array of T; const item: T): Boolean;
generic function Position<T>(const arr: array of T; const item: T): Integer;
generic function Location<T>(const arr: array of T; const item: T): Integer;
generic function Indexes<T>(const arr: array of T): TIntegerArray;

generic function IfThenElse<T>(const aBool, bBool: Boolean; const aResult, bResult, cResult: T): T;

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

function IfThen(const state: Boolean; const sTrue, sFalse: Integer): Integer; overload; cdecl;
function IfThen(const state: Boolean; const sTrue, sFalse: Int64): Int64; overload; cdecl;
function IfThen(const state: Boolean; const sTrue, sFalse: Double): Double; overload; cdecl;
function IfThen(const state: Boolean; const sTrue, sFalse: string): string; overload; cdecl;
function IfThen(const state: Boolean; const sTrue, sFalse: Char): Char; overload; cdecl;
function IfThen(const state: Boolean; const sTrue, sFalse: Boolean): Boolean; overload; cdecl;
function IfThen(const state: Boolean; const sTrue, sFalse: TPoint): TPoint; overload; cdecl;
function IfThen(const state: Boolean; const sTrue, sFalse: TBox): TBox; overload; cdecl;
function IfThen(const state: Boolean; const sTrue, sFalse: TRange): TRange; overload; cdecl;
function IfThen(const state: Boolean; const sTrue, sFalse: TSegment): TSegment; overload; cdecl;
function IfThen(const state: Boolean; const sTrue, sFalse: TCircle): TCircle; overload; cdecl;
function IfThen(const state: Boolean; const sTrue, sFalse: TTriangle): TTriangle; overload; cdecl;

function Bitify(const a: Boolean): Integer; overload; inline;
function Bitify(const a, b: Boolean): Integer; overload;
function Bitify(const a, b, c: Boolean): Integer; overload;
function Bitify(const a, b, c, d: Boolean): Integer; overload;
  
type
  TRangeArray = array of TRange;
  T2DRangeArray = array of TRangeArray;
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
    function Prime: Boolean; cdecl;
    function IsPrime: Boolean; cdecl;
    function Parity: Byte; cdecl; inline;
    function Even: Boolean; cdecl; inline;
    function Odd: Boolean; cdecl; inline;
    function Increase(const N: Int64 = 1): Int64; cdecl;
    function Decrease(const N: Int64 = 1): Int64; cdecl;
    function Increment(const N: Int64 = 1): Int64; cdecl;
    function Decrement(const N: Int64 = 1): Int64; cdecl;
    function DigitCount: Integer; cdecl;
    function Digitz: TIntegerArray; cdecl;
    function Digits: TIntegerArray; cdecl;
    function Compare(const target: Int64): Integer; cdecl; inline;
    function Distance(const T: Int64): Int64; cdecl; inline;
    function Difference(const T: Int64): Int64; cdecl; inline;
    function Opposite: Int64; cdecl; inline;
    function Sign: Integer; cdecl; inline;
    function Shuffle: Int64; cdecl;
    function Over(const target: Int64): Boolean; cdecl; inline;
    function Under(const target: Int64): Boolean; cdecl; inline;
    function Oversize(const limit: Int64): Boolean; cdecl; inline;
    function Undersize(const limit: Int64): Boolean; cdecl; inline;
  end;
  TIA = class
  public
    class function Init(var arr: TIntegerArray): Integer; overload; cdecl;
    class function Reverse(var arr: TIntegerArray): Boolean; overload; cdecl;
    class function Reversed(const arr: TIntegerArray): TIntegerArray; overload; cdecl;
    class function Unique(var arr: TIntegerArray): Integer; overload; cdecl;
	class function Combine(const A, B: TIntegerArray): TIntegerArray; overload; cdecl;
  end;
  TPA = class
    class function Init(var arr: TPointArray): Integer; overload; cdecl;
    class function Unique(var arr: TPointArray): Integer; overload; cdecl;
  end;
  TBA = class
    class function Init(var arr: TBooleanArray): Integer; overload; cdecl;
  end;
  ATIA = class
  public
    class function Merge(const arr: T2DIntegerArray): TIntegerArray; overload; cdecl;
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

{$DEFINE IMPLEMENT}{$INCLUDE MiMU\config\Templates\D.inc}{$UNDEF IMPLEMENT} 
 
implementation

function MiMU_Version: Double; cdecl;
begin
  Result := MiMU_VERSION_NUMBER;
end;

generic function Contains<T>(const arr: array of T; const item: T): Boolean;
var
  i: Integer;
begin
  for i := 0 to High(arr) do
    if (arr[i] = item) then
      Exit(True);
  Result := False;
end;

generic function Includes<T>(const arr: array of T; const item: T): Boolean;
var
  i: Integer;
begin
  for i := High(arr) downto 0 do
    if (arr[i] = item) then
      Exit(True);
  Result := False;
end;

generic function Position<T>(const arr: array of T; const item: T): Integer;
var
  i: Integer;
begin
  for i := 0 to High(arr) do
    if (arr[i] = item) then
      Exit(i);
  Result := -1;
end;

generic function Location<T>(const arr: array of T; const item: T): Integer;
var
  i: Integer;
begin
  for i := High(arr) downto 0 do
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

function IfThen(const state: Boolean; const sTrue, sFalse: Integer): Integer; overload; cdecl; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: Int64): Int64; overload; cdecl; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: Double): Double; overload; cdecl; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: string): string; overload; cdecl; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: Char): Char; overload; cdecl; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: Boolean): Boolean; overload; cdecl; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: TPoint): TPoint; overload; cdecl; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: TBox): TBox; overload; cdecl; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: TRange): TRange; overload; cdecl; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: TSegment): TSegment; overload; cdecl; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: TCircle): TCircle; overload; cdecl; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}
function IfThen(const state: Boolean; const sTrue, sFalse: TTriangle): TTriangle; overload; cdecl; {$DEFINE Skeleton_IfThen}{$I MiMU\config\Skeletons.inc}{$UNDEF Skeleton_IfThen}

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

class function TBA.Init(var arr: TBooleanArray): Integer; overload; cdecl;
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], Result, 0);
end;

class function TIA.Init(var arr: TIntegerArray): Integer; overload; cdecl;
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], (Result * SizeOf(Integer)), 0);
end;

class function TIA.Unique(var arr: TIntegerArray): Integer; overload; cdecl;
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

class function TIA.Reverse(var arr: TIntegerArray): Boolean; overload; cdecl;
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

class function TIA.Reversed(const arr: TIntegerArray): TIntegerArray; overload; cdecl;
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

class function TIA.Combine(const A, B: TIntegerArray): TIntegerArray; overload; cdecl;
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

class function ATIA.Merge(const arr: T2DIntegerArray): TIntegerArray; overload; cdecl;
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

class function TPA.Init(var arr: TPointArray): Integer; overload; cdecl;
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], (Result * SizeOf(TPoint)), 0);
end;

class function TPA.Unique(var arr: TPointArray): Integer; overload; cdecl;
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

{$mode objfpc}{$H+}

{$I MiMU.inc}

initialization

finalization

end.
