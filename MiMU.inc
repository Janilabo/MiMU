{$IFDEF Integer}
  {$DEFINE XVar := Integer}
  {$DEFINE XVarHelp := TIntegerHelper}
  {$DEFINE XArr := TIntegerArray}
  {$DEFINE XArrHelp := TIntegerArrayHelper}
  {$DEFINE X2DArr := T2DIntegerArray}
  {$DEFINE X2DArrHelp := T2DIntegerArrayHelper}
{$ENDIF}
{$IFDEF Double}
  {$DEFINE XVar := Double}
  {$DEFINE XVarHelp := TDoubleHelper}
  {$DEFINE XArr := TDoubleArray}
  {$DEFINE XArrHelp := TDoubleArrayHelper}
  {$DEFINE X2DArr := T2DDoubleArray}
  {$DEFINE X2DArrHelp := T2DDoubleArrayHelper}
{$ENDIF}
{$IFDEF string}
  {$DEFINE XVar := string}
  {$DEFINE XVarHelp := TStringHelper}
  {$DEFINE XArr := TStringArray}
  {$DEFINE XArrHelp := TStringArrayHelper}
  {$DEFINE X2DArr := T2DStringArray}
  {$DEFINE X2DArrHelp := T2DStringArrayHelper}
{$ENDIF}
{$IFDEF Char}
  {$DEFINE XVar := Char}
  {$DEFINE XVarHelp := TCharHelper}
  {$DEFINE XArr := TCharArray}
  {$DEFINE XArrHelp := TCharArrayHelper}
  {$DEFINE X2DArr := T2DCharArray}
  {$DEFINE X2DArrHelp := T2DCharArrayHelper}
{$ENDIF}
{$IFDEF Boolean}
  {$DEFINE XVar := Boolean}
  {$DEFINE XVarHelp := TBooleanHelper}
  {$DEFINE XArr := TBooleanArray}
  {$DEFINE XArrHelp := TBooleanArrayHelper}
  {$DEFINE X2DArr := T2DBooleanArray}
  {$DEFINE X2DArrHelp := T2DBooleanArrayHelper}
{$ENDIF}
{$IFDEF TPoint}
  {$DEFINE XVar := TPoint}
  {$DEFINE XVarHelp := TPointHelper}
  {$DEFINE XArr := TPointArray}
  {$DEFINE XArrHelp := TPointArrayHelper}
  {$DEFINE X2DArr := T2DPointArray}
  {$DEFINE X2DArrHelp := T2DPointArrayHelper}
{$ENDIF}
{$IFDEF TBox}
  {$DEFINE XVar := TBox}
  {$DEFINE XVarHelp := TBoxHelper}
  {$DEFINE XArr := TBoxArray}
  {$DEFINE XArrHelp := TBoxArrayHelper}
  {$DEFINE X2DArr := T2DBoxArray}
  {$DEFINE X2DArrHelp := T2DBoxArrayHelper}
{$ENDIF}
{$IFDEF TRange}
  {$DEFINE XVar := TRange}
  {$DEFINE XVarHelp := TRangeHelper}
  {$DEFINE XArr := TRangeArray}
  {$DEFINE XArrHelp := TRangeArrayHelper}
  {$DEFINE X2DArr := T2DRangeArray}
  {$DEFINE X2DArrHelp := T2DRangeArrayHelper}
{$ENDIF}
{$IFDEF Int64}
  {$DEFINE XVar := Int64}
  {$DEFINE XVarHelp := TInt64Helper}
{$ENDIF}

{$IFDEF Helpers}  
  type
    XVarHelp = type helper for XVar
    {$IFDEF Int64}
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
   {$ELSE}
      function TArray(const aSize: Integer = 1): XArr; overload cdecl;
      function T2DArray(const size1D: Integer = 1; const size2D: Integer = 1): X2DArr; overload cdecl;
   {$ENDIF}
   {$IFDEF Integer}
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
    {$ENDIF}
    {$IFDEF Double}
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
    {$ENDIF}
    {$IFDEF string}
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
    {$ENDIF}
    {$IFDEF Char}
      // Nothing special yet :(
    {$ENDIF}
    {$IFDEF Boolean}
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
    {$ENDIF}
    {$IFDEF TPoint}
      function Inside(const bx: TBox): Boolean; cdecl; inline;
      function Create: TPoint; overload; cdecl;
      function Grid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TPointArray; cdecl;
      function Row(const cells: Integer; const space: Integer = 0): TPointArray; cdecl;
      function Column(const cells: Integer; const space: Integer = 0): TPointArray; cdecl;
    {$ENDIF}
    {$IFDEF TBox}
      function Create: TBox; overload; cdecl;
      function Inside(const targets: TBoxArray): Boolean; overload; cdecl;
      function Grid(const rows, columns: Integer; const spaceVertical: Integer = 0; const spaceHorizontal: Integer = 0): TBoxArray; cdecl;
      function Row(const cells: Integer; const space: Integer = 0): TBoxArray; cdecl;
      function Column(const cells: Integer; const space: Integer = 0): TBoxArray; cdecl;
    {$ENDIF}
    {$IFDEF TRange}
      function Create: TRange; overload; cdecl;
      function Distribute(const parts: Integer): TRangeArray; cdecl;
      function Partition(const size: Integer): TRangeArray; cdecl;
      function Divide(const size: Integer): TRangeArray; cdecl;
    {$ENDIF}
  end;
  {$IFNDEF Int64}
    XArrHelp = type helper for XArr
      function Add(const item: XVar; const duplicates: Boolean = True): XArr; overload; cdecl;
      function Add(const items: XArr; const duplicates: Boolean = True): XArr; overload; cdecl;
      function AllEqual: Boolean; overload; cdecl;
      function AllSame: Boolean; overload; cdecl;
      function AllUnique: Boolean; overload; cdecl;
      function Append(const item: XVar; const duplicates: Boolean = True): Integer; overload; cdecl;
      function Append(const items: XArr; const duplicates: Boolean = True): Integer; overload; cdecl;
      function Build(const item: XVar; const aSize: Integer = 1): XArr; overload; cdecl;
      function BuiltWith(const allowed: XArr): Boolean; overload; cdecl;
      function BuiltWithout(const forbidden: XArr): Boolean; overload; cdecl;
      function Clear: Boolean; cdecl;
      function Clone(const index: Integer = 0; const count: Integer = 2147483647): XArr; cdecl;
      function Clone(const ID: TIntegerArray): XArr; overload; cdecl;
      function Combine(const b: XArr): XArr; overload; cdecl;
      function Contains(const item: XVar; const index: Integer = 0): Boolean; cdecl;
      function Copy(const index: Integer = 0; const count: Integer = 2147483647): XArr; overload; cdecl;
      function Create(const item: XVar): XArr; overload; cdecl;
      function Create(const aSize: Integer; const item: XVar): XArr; overload; cdecl;
	  function Deduplicate: Integer; overload; cdecl;
      function Delete(const index: Integer = 0): Boolean; overload; cdecl;
      function Delete(const ID: TIntegerArray): Integer; overload; cdecl;
      function Differ(const target: XArr): Boolean; overload; cdecl;
      function Distribute(const parts: Integer): X2DArr; overload; cdecl;
      function Dump(const items: XArr; const index: Integer = 0): Integer; overload; cdecl;
      function Dupe: XArr; overload; cdecl;
      function Duplicate(const xTimes: Integer = 1): XArr; overload; cdecl;
      function Empty: Boolean; overload; cdecl;
      function Equal(const target: XArr): Boolean; overload; cdecl;
      function Erase(const item: XVar; const index: Integer = 2147483647; const all: Boolean = True): Integer; overload; cdecl;
      function Erase(const item: XVar; const all: Boolean): Integer; overload; cdecl;
      function Erase(const items: XArr; const index: Integer = 2147483647; const all: Boolean = True): Integer; overload; cdecl;
      function Erase(const items: XArr; const all: Boolean): Integer; overload; cdecl;
      function Excessive: Boolean; overload; cdecl; 
      function Exch(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
      function Exchange(const aIndex, bIndex: Integer): Boolean; overload; cdecl;
      function Extend(const item: XVar): XArr; overload; cdecl;
      function Extend(const items: XArr): XArr; overload; cdecl;
      function Extract(const item: XVar; const index: Integer = 0): XArr; overload; cdecl;
      function Extract(const items: XArr; const index: Integer = 0): XArr; overload; cdecl;
      function ExtractEvery(const X: Integer = 1; const index: Integer = 0): XArr; overload; cdecl;
      function Fill(const item: XVar; const index: Integer = 0; const count: Integer = 2147483647): XArr; overload; cdecl;
      function Fill(const items: XArr; const index: Integer = 0; const count: Integer = 2147483647): XArr; overload; cdecl;
      function Filter(const item: XVar; const index: Integer = 0): XArr; overload; cdecl;
      function Filter(const items: XArr; const index: Integer = 0): XArr; overload; cdecl;
      function FilterEvery(const X: Integer = 1; const index: Integer = 0): XArr; overload; cdecl;
      function Find(const ID: TRange; const item: XVar): Integer; overload; cdecl;
      function Find(const ID: TIntegerArray; const item: XVar): Integer; overload; cdecl;
      function Find(const ID: TRange; const items: XArr): Integer; overload; cdecl;
      function Find(const ID: TIntegerArray; const items: XArr): Integer; overload; cdecl;
      function Flip: Boolean; overload; cdecl;
      function FromLeft(const count: Integer; const index: Integer = 2147483647): XArr; overload; cdecl;
      function FromRight(const count: Integer; const index: Integer = 0): XArr; overload; cdecl;
      function Get: XArr; overload; cdecl;
      function Get(const ID: TIntegerArray): XArr; overload; cdecl;
      function Get(const ID: TRange): XArr; overload; cdecl;
      function Group: X2DArr; overload; cdecl;
      function Holds(const chain: XArr): Boolean; overload; cdecl;
      function IDs(const aAscending: Boolean = True): TIntegerArray; overload; cdecl;
      function IDs(const ID: TIntegerArray): XArr; overload; cdecl;
      function IDs(const ID: TIntegerArray; const item: XVar): XArr; overload; cdecl;
      function IDs(const ID: TIntegerArray; const items: XArr): XArr; overload; cdecl;
      function Includes(const item: XVar; const index: Integer = 2147483647): Boolean; cdecl;
      function Keep(const items: XArr; const index: Integer = 0): Integer; overload; cdecl;
      function LeastFrequent: XVar; overload; cdecl;
      function Len: Integer; overload; cdecl;
      function Len(const aSize: Integer): Integer; overload; cdecl;
      function Len(const aSize: Integer; const null: XVar): Integer; overload; cdecl;
      function Loc(const item: XVar; const index: Integer = 2147483647): Integer; overload; cdecl;
      function Loc(const items: XArr; const index: Integer = 2147483647): Integer; overload; cdecl;
      function Location(const item: XVar; const index: Integer = 2147483647): Integer; overload; cdecl;
      function Location(const items: XArr; const index: Integer = 2147483647): Integer; overload; cdecl;
      function Locations(const item: XVar; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
      function Locations(const items: XArr; const index: Integer = 2147483647): TIntegerArray; overload; cdecl;
      function Mix(const shuffles: Integer = 1): Boolean; overload; cdecl;
      function MostFrequent: XVar; overload; cdecl;
      function Move(const oldIndex, newIndex: Integer): Boolean; overload; cdecl;
      function Next(const index: Integer; const count: Integer = 2147483647): XArr; overload; cdecl;
      function Oversize(const limit: Integer): Boolean; overload; cdecl;
      function Partition(const pSize: Integer): X2DArr; overload; cdecl;
      function Pick(const ID: TIntegerArray): XArr; overload; cdecl;
      function Pop: XVar; overload; cdecl;
      function Pop(const null: XVar): XVar; overload; cdecl;
      function Populate(const items: XArr; const times: Integer = 1): Boolean; overload; cdecl;
      function Populate(const item: XVar; const times: Integer = 1): Boolean; overload; cdecl;
      function Pos(const item: XVar; const index: Integer = 0): Integer; overload; cdecl;
      function Pos(const items: XArr; const index: Integer = 0): Integer; overload; cdecl;
      function Position(const item: XVar; const index: Integer = 0): Integer; overload; cdecl;
      function Position(const items: XArr; const index: Integer = 0): Integer; overload; cdecl;
      function Positions(const item: XVar; const index: Integer = 0): TIntegerArray; overload; cdecl;
      function Positions(const items: XArr; const index: Integer = 0): TIntegerArray; overload; cdecl;
      function Previous(const index: Integer; const count: Integer = 2147483647): XArr; overload; cdecl;
      function Push(const item: XVar): Integer; overload; cdecl;
      function Push(const items: XArr): Integer; overload; cdecl;
      function Put(const ID: TIntegerArray; const item: XVar): XArr; overload; cdecl;
      function Put(const ID: TIntegerArray; const items: XArr): XArr; overload; cdecl;
      function Put(const index: Integer; const items: XArr): XArr; overload; cdecl;
      function Remove(const item: XVar; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
      function Remove(const item: XVar; const all: Boolean): Integer; overload; cdecl;
      function Remove(const items: XArr; const index: Integer = 0; const all: Boolean = True): Integer; overload; cdecl;
      function Remove(const items: XArr; const all: Boolean): Integer; overload; cdecl;
      function Resize(const aChange: Integer): Integer; overload; cdecl;
      function Resize(const aChange: Integer; const null: XVar): Integer; overload; cdecl;
      function Reverse: Boolean; overload; cdecl;
      function Reversed: XArr; overload; cdecl;
      function Scan(const ID: TRange; const item: XVar; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
      function Scan(const ID: TIntegerArray; const item: XVar; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
      function Scan(const ID: TRange; const items: XArr; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
      function Scan(const ID: TIntegerArray; const items: XArr; const limit: Integer = 2147483647): TIntegerArray; overload; cdecl;
      function Shift: XVar; overload; cdecl;
      function Shift(const sCount: Integer): XArr; overload; cdecl;
      function Size(const aSize: Integer): Integer; overload; cdecl;
      function Size: Integer; overload; cdecl;
      function SizeBetween(const sMin, sMax: Integer): Boolean; overload; cdecl;
      function SizeMax(const target: Integer): Boolean; overload; cdecl;
      function SizeMin(const target: Integer): Boolean; overload; cdecl;
      function SubarrayLocation(const pattern: XArr): Integer; overload; cdecl;
      function SubarrayLocations(const pattern: XArr): TIntegerArray; overload; cdecl;
      function SubarrayPosition(const pattern: XArr): Integer; overload; cdecl;
      function SubarrayPositions(const pattern: XArr): TIntegerArray; overload; cdecl;
      function Swap(var b: XArr): Integer; overload; cdecl;
      function Trade(var b: XArr): Integer; overload; cdecl;
      function Undersize(const limit: Integer): Boolean; overload; cdecl;
      function Unique: Integer; overload; cdecl;
      function Uniqued: XArr; overload; cdecl;
      function Uniques: TIntegerArray; overload; cdecl;
      function Unshift(const item: XVar): Integer; overload; cdecl;
      function Unshift(const items: XArr): Integer; overload; cdecl;
    {$IFDEF Integer}
      function Descending: Boolean; cdecl;
      function Ascending: Boolean; cdecl;
      function Bounds: TRange; overload; cdecl;
      function Bounds(var aSize: Integer): TRange; overload; cdecl;
      function Range: TRange; cdecl;
      function Undupe: Integer; cdecl;
      function Unduped: TIntegerArray; cdecl;
      function Numberline: TIntegerArray; cdecl;
      function Lowest: Integer; cdecl;
      function Highest: Integer; cdecl;
      function Mini(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload; cdecl;
      function Mini(const start: Integer; const aAscending: Boolean = True): Integer; overload; cdecl;
      function Maxi(const aAscending: Boolean = True; const start: Integer = -1): Integer; overload; cdecl;
      function Maxi(const start: Integer; const aAscending: Boolean = True): Integer; overload; cdecl;
      function Sum: Int64; cdecl;
      function Density: Double; cdecl;
      function Mean: Double; cdecl;
      function Mode: Integer; cdecl;
      function Median: Double; cdecl;
      function Middle: Double; cdecl;
      function Center: Integer; cdecl;
      function MostFreq(const null: Integer = -2147483648): Integer; cdecl;
      function LeastFreq(const null: Integer = -2147483648): Integer; cdecl;
      function BubbleSort(const aAscending: Boolean = True): Integer; cdecl;
      function BubbleSort2(const aAscending: Boolean = True): Integer; cdecl;
      function BubbleSortOptimized(const aAscending: Boolean = True): Integer; cdecl;
      function QuickSort(const aAscending: Boolean = True): Integer; cdecl;
      function QuickSort3W(const aAscending: Boolean = True): Integer; cdecl;
      function QSort(const aAscending: Boolean = True): Integer; cdecl;
      function CoctailSort(const aAscending: Boolean = True): Integer; cdecl;
      function CoctailSort2(const aAscending: Boolean = True): Integer; cdecl;
      function CombSort(const aAscending: Boolean = True): Integer; cdecl;
      function GnomeSort(const aAscending: Boolean = True): Integer; cdecl;
      function GnomeSortOptimized(const aAscending: Boolean = True): Integer; cdecl;
      function HeapSort(const aAscending: Boolean = True): Integer; cdecl;
      function InsertionSort(const aAscending: Boolean = True): Integer; cdecl;
      function SelectionSort(const aAscending: Boolean = True): Integer; cdecl;
      function SelectionSortBidirectional(const aAscending: Boolean = True): Integer; cdecl;
      function SelectionSortBidirectional2(const aAscending: Boolean = True): Integer; cdecl;
      function PancakeSort(const aAscending: Boolean = True): Integer; cdecl;
      function MergeSort(const aAscending: Boolean = True): Integer; cdecl;
      function MergeSortBU(const aAscending: Boolean = True): Integer; cdecl;
      function ShellSort(const aAscending: Boolean = True): Integer; cdecl;
      function BSort(const aAscending: Boolean = True): Integer; cdecl;
      function BinarySort(const aAscending: Boolean = True): Integer; cdecl;
      function BinarySorted(const aAscending: Boolean = True): TIntegerArray; cdecl;
      function BinaryBoundL(const x: Integer; const aAscending: Boolean = True): Integer; cdecl;
      function BinaryBoundR(const x: Integer; const aAscending: Boolean = True): Integer; cdecl;
      function BinaryPosL(const x: Integer; const aAscending: Boolean = True): Integer; cdecl;
      function BinaryPosR(const x: Integer; const aAscending: Boolean = True): Integer; cdecl;
      function BinarySearch(const x: Integer; const aAscending: Boolean = True): Integer; cdecl;
      function BinaryContains(const x: Integer; const aAscending: Boolean = True): Boolean; cdecl;
      function BinaryLocate(const x: Integer; const aAscending: Boolean = True): TRange; cdecl;
      function BinaryLocation(const x: Integer; const aAscending: Boolean = True): TRange; cdecl;
      function BinaryAppend(const x: Integer; const aAscending: Boolean = True): Integer; cdecl;
      function BinaryAdd(const x: Integer; const aAscending: Boolean = True): TIntegerArray; cdecl;
      function BinarySearchF(const x: TRange; const aAscending: Boolean = True): Integer; cdecl;
      function BinarySearchL(const x: TRange; const aAscending: Boolean = True): Integer; cdecl;
      function BinaryUnique(const aAscending: Boolean = True): Integer; cdecl;
      function BinaryUniqued(const aAscending: Boolean = True): TIntegerArray; cdecl;
      function Split(const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
      function Split(const diff: Integer): T2DIntegerArray; overload; cdecl;
      function Sblit(const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
      function Sblit(const diff: Integer): T2DIntegerArray; overload; cdecl;
      function Group(const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
      function Group(const diff: Integer): T2DIntegerArray; overload; cdecl;
      function Groub(const minDiff, maxDiff: Integer): T2DIntegerArray; overload; cdecl;
      function Groub(const diff: Integer): T2DIntegerArray; overload; cdecl;
      function Invert: TIntegerArray; cdecl;
    {$ENDIF}
    {$IFDEF TPoint}
      function Bounds: TBox; overload; cdecl;
      function Bounds(var width, height: Integer): TBox; overload; cdecl;
      function Undupe: Integer; cdecl;
      function Unduped: TPointArray; cdecl;
      function Invert: TPointArray; cdecl;
      function Edge(const scan8W: Boolean = False): TPointArray; cdecl;
      function FloodFill(const start: TPoint; const area: TBox; const scan8W: Boolean = False): TPointArray; overload; cdecl;
      function FloodFill(const start: TPoint; const scan8W: Boolean = False): TPointArray; overload; cdecl;
    {$ENDIF}	
    {$IFDEF TRange}
      function TIA: TIntegerArray; cdecl;
      function T2DIA: T2DIntegerArray; cdecl;
    {$ENDIF}	
    end;
    X2DArrHelp = type helper for X2DArr
      function Blank: Boolean; overload; cdecl;
      function Empty: Boolean; overload; cdecl;
      function Size(var lengths: TIntegerArray): Int64; overload; cdecl;
      function Size: Int64; overload; cdecl;
      function Size(const aSize: Integer): Int64; overload; cdecl;
      function Size(const size1D, size2D: Integer): Int64; overload; cdecl;
      function Merge: XArr; overload; cdecl;  
    end;
  {$ENDIF}
{$ENDIF}

{$IFDEF implementation}
  {$I MiMU\Integer.inc}
  {$I MiMU\Int64.inc}
  {$I MiMU\Double.inc}
  {$I MiMU\String.inc}
  {$I MiMU\Boolean.inc}
  {$I MiMU\TPoint.inc}
  {$I MiMU\TBox.inc}
  {$I MiMU\TRange.inc}
  {$I MiMU\TIntegerArray.inc}
  {$I MiMU\TDoubleArray.inc}
  {$I MiMU\TStringArray.inc}
  {$I MiMU\TCharArray.inc}
  {$I MiMU\TBooleanArray.inc}
  {$I MiMU\TPointArray.inc}
  {$I MiMU\TBoxArray.inc}
  {$I MiMU\TRangeArray.inc}
{$ENDIF}

{$IFDEF Generic}
  {$I MiMU\Generic.inc}
{$ENDIF}
