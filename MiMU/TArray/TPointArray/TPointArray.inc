{$DEFINE TPoint}{$I ../../Type/Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
CPointArray = class
  class function Init(var arr: TPointArray): Integer; overload; 
  class function Unique(var arr: TPointArray): Integer; overload; 
  class function Create(const xRange, yRange: TRange): TPointArray; overload; 
  class function Create(const xRange, yRange: TRange; const offset: TPoint): TPointArray; overload; 
  class function Create(const xValues, yValues: TIntegerArray): TPointArray; overload; 
  class function Create(const xValues, yValues: TIntegerArray; const offset: TPoint): TPointArray; overload; 
end;
{$ENDIF}

{$IFDEF HELPERS}
TPointArrayHelper = type helper for TPointArray
  {$I ../TArray.inc}
  {$I TPointArray.pph}
  function Binify(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function Binify(const radius: Double; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
  function Binified(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function Binified(const radius: Double; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
  function Bounds: TBox; overload;
  function Bounds(var width, height: Integer): TBox; overload;
  function BoundingBox: TBox;
  function Boundaries: TBox;
  function Box: TBox;
  function BBox: TBox; overload;
  function Boxed: TBox;
  function MinMax: TBox;
  function Region: TBox; overload;
  function Coverage: TBox; overload;
  function Undupe: TPointArray;
  function Unduped: TPointArray;
  function Invert: TPointArray;
  function Inverted(const arrBounds: TBox): TPointArray; overload;
  function Inverted: TPointArray; overload;
  function Inverse(const arrBounds: TBox): TPointArray; overload;
  function Inverse: TPointArray; overload;
  function Edge(const scan8W: Boolean = False): TPointArray;
  function FloodFill(const start: TPoint; const area: TBox; const scan8W: Boolean = False): TPointArray; overload;
  function FloodFill(const start: TPoint; const scan8W: Boolean = False): TPointArray; overload;
  function Xs: TIntegerArray; overload;
  function Ys: TIntegerArray; overload;
  function XValues: TIntegerArray; overload;
  function YValues: TIntegerArray; overload;
  function Unzip(var xArr, yArr: TIntegerArray): Integer;
  function Zip(const xArr, yArr: TIntegerArray): Integer;
  function Extent: TBox;
  function Vertical: TRange; overload;
  function Horizontal: TRange; overload;
  function Neighborify(const adjacency8: Boolean = True): T2DPointArray; overload;
  function Regionize(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function Regionize(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
  function Regionize(const radius: Double = 1.0): T2DPointArray; overload;
  function RSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
  function RSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
  function RSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
  function CSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
  function CSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
  function CSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;  
  function XSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
  function XSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
  function XSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
  function YSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
  function YSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
  function YSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
  function Split(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function Split(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
  function Split(const radius: Double = 1.0): T2DPointArray; overload;
  function SplitEx(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function SplitEx(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
  function SplitEx(const radius: Double = 1.0): T2DPointArray; overload;
  function Clusters(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
  function Clusters(const radius: Double = 1.0): T2DPointArray; overload;
  function Clusters(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function Cluster(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
  function Cluster(const radius: Double = 1.0): T2DPointArray; overload;
  function Cluster(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function Clustered(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
  function Clustered(const radius: Double = 1.0): T2DPointArray; overload;
  function Clustered(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function Clusterify(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
  function Clusterify(const radius: Double = 1.0): T2DPointArray; overload;
  function Clusterify(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function Clusterize(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
  function Clusterize(const radius: Double = 1.0): T2DPointArray; overload;
  function Clusterize(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function Segment(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
  function Segment(const radius: Double = 1.0): T2DPointArray; overload;
  function Segment(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function Fragment(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
  function Fragment(const radius: Double = 1.0): T2DPointArray; overload;
  function Fragment(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function Groups(const adjacency8: Boolean = True): T2DPointArray; overload;
  function Grouping(const adjacency8: Boolean = True): T2DPointArray; overload;
  function Grouped(const adjacency8: Boolean = True): T2DPointArray; overload;
  function Groupify(const adjacency8: Boolean = True): T2DPointArray; overload;
  function XClassify(const pSorted: Boolean = False): T2DPointArray; overload;
  function YClassify(const pSorted: Boolean = False): T2DPointArray; overload;
  function Axes(var X, Y: TIntegerArray): Integer; overload;
  function Axed: T2DIntegerArray; overload;
  function Axed(var X, Y: TIntegerArray): Integer; overload;
  function SortByRow(const aAscending: Boolean = True): Integer; overload;
  function SortByColumn(const aAscending: Boolean = True): Integer; overload;
  function SortedByIndex(const aAscending: Boolean = True): TPointArray; overload;
  function Attach(const items: TPointArray): Integer; overload;
  function Embed(const items: TPointArray; const index: Integer = 2147483647): Integer; overload;
  function FrameLinks(const dist: Integer; const area: TBox): TPointArray; overload;
  function FrameLinks(const dist: Integer = 1): TPointArray; overload;
  function Reinit: Integer; overload;
  function XVals(const aAscending: Boolean = True): TIntegerArray;
  function YVals(const aAscending: Boolean = True): TIntegerArray;
  function XArr(const aAscending: Boolean = True): TIntegerArray;
  function YArr(const aAscending: Boolean = True): TIntegerArray;
  function XAxis(const rUnique: Boolean = True): TIntegerArray; overload;
  function YAxis(const rUnique: Boolean = True): TIntegerArray; overload;
  function X2D(var yArr: TIntegerArray; const xOrder: Boolean = True; const xAscending: Boolean = True): T2DIntegerArray; overload;
  function Y2D(var xArr: TIntegerArray; const yOrder: Boolean = True; const yAscending: Boolean = True): T2DIntegerArray; overload;
  function Blobs(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function Blobs(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
  function Blobs(const radius: Double = 1.0): T2DPointArray; overload;
  function Blobify(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function Blobify(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
  function Blobify(const radius: Double = 1.0): T2DPointArray; overload;
  function YTo2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
  function YTo2D(var xArr: TIntegerArray): T2DIntegerArray; overload;
  function XTo2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
  function XTo2D(var yArr: TIntegerArray): T2DIntegerArray; overload;
  function YAs2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
  function YAs2D(var xArr: TIntegerArray): T2DIntegerArray; overload;
  function XAs2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
  function XAs2D(var yArr: TIntegerArray): T2DIntegerArray; overload;
  function DBSCAN(const radius: Double; const minPts: Integer; const distFunc: TDistance): T2DPointArray; overload;
  function DBSCAN(const radius: Double = 1.0; const minPts: Integer = 2; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
  function DBSCAN(const xRadius, yRadius: Integer; const minPts: Integer): T2DPointArray; overload;
  function Nearby(const target: TPoint; const radius: Double; const distFunc: TDistance): TPointArray; overload;
  function Nearby(const target: TPoint; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): TPointArray; overload;
  function Nearby(const target: TPoint; const xRadius, yRadius: Integer): TPointArray; overload;
  function Nearby(const targets: TPointArray; const radius: Double; const distFunc: TDistance): TPointArray; overload;
  function Nearby(const targets: TPointArray; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): TPointArray; overload;
  function Nearby(const targets: TPointArray; const xRadius, yRadius: Integer): TPointArray; overload;
  function CorePointsMax(const maximumNeighbours: Integer; const xRadius, yRadius: Integer): TPointArray; overload;
  function CorePointsMax(const maximumNeighbours: Integer; const radius: Double; const metric: TMetrics = dmEuclidean): TPointArray; overload;
  function CorePointsMin(const minimumNeighbours: Integer; const xRadius, yRadius: Integer): TPointArray; overload;
  function CorePointsMin(const minimumNeighbours: Integer; const radius: Double; const metric: TMetrics = dmEuclidean): TPointArray; overload;
  function CorePoints(const allowedNeighbours: TRange; const radius: Double; const metric: TMetrics = dmEuclidean): TPointArray; overload;
  function CorePoints(const allowedNeighbours: TRange; const xRadius, yRadius: Integer): TPointArray; overload;
  function Bins(const radius: Double; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
  function Bins(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function XBuckets(const bWidth: Integer = 1): T2DPointArray;
  function YBuckets(const bHeight: Integer = 1): T2DPointArray;
  function Buckets(const bWidth, bHeight: Integer): T2DPointArray; overload;
  function Buckets(const bSize: Integer = 1): T2DPointArray; overload;
  function Bucketed(const bWidth, bHeight: Integer): T2DPointArray; overload;
  function Bucketed(const bSize: Integer = 1): T2DPointArray; overload;
  function Boxify(const bWidth, bHeight: Integer): T2DPointArray; overload;
  function Boxify(const bSize: Integer = 1): T2DPointArray; overload;
  function Boxified(const bWidth, bHeight: Integer): T2DPointArray; overload;
  function Boxified(const bSize: Integer = 1): T2DPointArray; overload;
  function BinBox(const bWidth, bHeight: Integer): T2DPointArray; overload;
  function BinBox(const bSize: Integer = 1): T2DPointArray; overload;
  function BinaryFloodFill(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
  function BinaryFill(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
  function BinaryFilled(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
  function BFloodFill(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
  function AdjFill(const scan8W: Boolean = True): T2DPointArray;
  function NFill(const scan8W: Boolean = True): T2DPointArray;
  function AFill(const scan8W: Boolean = True): T2DPointArray;
  function CFill(const scan8W: Boolean = True): T2DPointArray;
  function BCluster(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
  function BCluster(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function QuickSortByX(const aAscending: Boolean = True): Integer;
  function QuickSortByY(const aAscending: Boolean = True): Integer;
  function QuickSortByXY(const aAscending: Boolean = True): Integer;
  function QuickSortByYX(const aAscending: Boolean = True): Integer;
  function SortByIndex(const aBounds: TBox; const aAscending: Boolean = True): Integer; overload;
  function SortByIndex(const aAscending: Boolean = True): Integer; overload;
  function SortByScanline(const aBounds: TBox; const aAscending: Boolean = True): Integer; overload;
  function SortByScanline(const aAscending: Boolean = True): Integer; overload;
  function ProximityCluster(const xRadius, yRadius: Integer; const method: Integer = 0): T2DPointArray; overload;
  function ProximityCluster(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const method: Integer = 0): T2DPointArray; overload;
  function Linked(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const check: Integer = 1): T2DPointArray; overload;
  function Linked(const xRadius, yRadius: Integer; const check: Integer = 1): T2DPointArray; overload;
  function Chain(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const check: Integer = 5): T2DPointArray; overload;
  function Chain(const xRadius, yRadius: Integer; const check: Integer = 5): T2DPointArray; overload;
  function Attach(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const check: Integer = 5): T2DPointArray; overload;
  function Attach(const xRadius, yRadius: Integer; const check: Integer = 5): T2DPointArray; overload;
  function RCluster(const xRadius, yRadius: Integer): T2DPointArray; overload;
  function RCluster(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
  function ToRows: T2DPointArray;
  function ToColumns: T2DPointArray;
  function AsRows: T2DPointArray;
  function AsColumns: T2DPointArray;
  function Rows: T2DPointArray;
  function Columns: T2DPointArray;
  function Pure(const allowed: TPointArray): Boolean; overload;
  function BSort(const aAscending: Boolean = True): Integer; overload;
  function BSorted(const aAscending: Boolean = True): TPointArray; overload;
  function BinarySearch(const item: TPoint): Integer; overload;
  function BinarySearch(const area: TBox): Integer; overload;
  function BinaryFind(const item: TPoint): Integer; overload;
  function BinaryFind(const area: TBox): Integer; overload;
  function BinaryIndexOf(const item: TPoint): Integer; overload;
  function BinaryExists(const item: TPoint): Boolean; overload;
  function BinaryPosL(const item: TPoint): Integer; overload;
  function BinaryPosR(const item: TPoint): Integer; overload;
  function BinaryRank(const item: TPoint): Integer; overload;
  function BinaryContains(const item: TPoint): Boolean; overload;
  function BinaryInsert(const item: TPoint; const allowDuplicates: Boolean = True): Integer; overload;
  function BinaryAppend(const item: TPoint; const allowDuplicates: Boolean = True): Integer; overload;
  function BinarySupply(const item: TPoint): Integer; overload;
  function BinaryCount(const item: TPoint): Integer; overload;
  function BinaryAmount(const item: TPoint): Integer; overload;
  function BinaryRange(const item: TPoint): TRange; overload;
  function BinaryRangeOf(const item: TPoint): TRange; overload;
  function BinaryScan(const area: TBox): TIntegerArray; overload;
  function BinaryScanned(const area: TBox): TIntegerArray; overload;
  function BinaryDelete(const item: TPoint): Boolean; overload;
  function BinaryRemove(const item: TPoint; const all: Boolean = True): Integer; overload;
  function BinarySinglify(const item: TPoint): Integer; overload;
  function BinarySinglified(const item: TPoint): TPointArray; overload;
  function BinaryMerge(const items: TPointArray): TPointArray; overload;
  function BinaryReplace(const oItem, nItem: TPoint): Boolean; overload;
  function BinaryReplaceAll(const oItem, nItem: TPoint): Integer; overload;
  function BinaryXs(const unique: Boolean = True): TIntegerArray; overload;
  function BinaryYs(const unique: Boolean = True): TIntegerArray; overload;
  function BinaryYPoints(const yValue: Integer): TPointArray; overload;
  function BinaryXPoints(const xValue: Integer): TPointArray; overload;
  function BinaryGrouped: T2DPointArray; overload;
  function BinaryExtract(const area: TBox): TPointArray; overload;
  function BinaryFilter(const area: TBox): TPointArray; overload;
  function BinaryX: TIntegerArray; overload;
  function BinaryY: TIntegerArray; overload;
  function BinaryInsertSorted(const oAscending: Boolean = True): TPointArray; overload;
  function BinaryInsertSort(const oAscending: Boolean = True): Integer; overload;
end;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS) OR DEFINED(CLASSES)}
{$I ../TArray.inc}
{$I TPointArray.pph}
{$IFNDEF CLASSES}
{$DEFINE FField := X}{$I ../F.inc}
{$DEFINE FField := Y}{$I ../F.inc}
{$ENDIF}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Bounds>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Bounds: TBox; overload; 
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  Result.Make(Self[0]);
  for i := 1 to High(Self) do
  begin
    if (Self[i].X < Result.X1) then
      Result.X1 := Self[i].X
    else
      if (Self[i].X > Result.X2) then
        Result.X2 := Self[i].X;
    if (Self[i].Y < Result.Y1) then
      Result.Y1 := Self[i].Y
    else
      if (Self[i].Y > Result.Y2) then
        Result.Y2 := Self[i].Y;
  end;
end;

{==============================================================================]
  <Bounds>
  @action: Returns bounding box around TPointArray arr.
  @note: Stores width and height of bounds to width and height variables.
[==============================================================================}
function TPointArrayHelper.Bounds(var width, height: Integer): TBox; overload; 
begin
  case Self.Empty of
    False:
    begin
      Result := Self.Bounds;
      Result.Size(width, height);
    end;
    True:
    begin
      Result.Create(-2147483648);
      width := 0;
      height := 0;
    end;
  end;
end;

{==============================================================================]
  <BoundingBox>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.BoundingBox: TBox; 
var
  i: Integer;
  a, b: TIntegerArray;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  SetLength(a, Self.Size);
  SetLength(b, Self.Size);
  for i := 0 to High(Self) do
  begin
    a[i] := Self[i].X;
    b[i] := Self[i].Y;
  end;
  Result.Create(MinValue(a), MinValue(b), MaxValue(a), MaxValue(b));
end;

{==============================================================================]
  <Boundaries>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Boundaries: TBox; 
  function BR(const arr: TPointArray; const L, R: Integer): TBox;
  var
    M: Integer;
  begin
    if (L = R) then
      Exit(Result.Create(arr[L].X, arr[L].Y, arr[L].X, arr[L].Y));
    M := ((L + R) div 2);
    Result := BR(arr, L, M).Union(BR(arr, (M + 1), R));
  end;
begin
  if Self.Empty then
    Exit(Default(TBox));
  Result := BR(Self, 0, High(Self));
end;

{==============================================================================]
  <Box>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Box: TBox; 
var
  P: TPoint;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  Result.Create(Self[0]);
  for P in Self do
    Result.Create(Min(Result.X1, p.X), Min(Result.Y1, p.Y), Max(Result.X2, p.X), Max(Result.Y2, p.Y));
end;

{==============================================================================]
  <BBox>
  @action: Computes the minimal bounding box (TBox) that encloses all points
           in the TPointArray. It calculates the minimum and maximum X and Y
           coordinates among the points to define the box.
  @note:   - If the array is empty, the resulting TBox will be uninitialized.
           - If the array has only one point, the bounding box will be a
             degenerate box where X1=X2 and Y1=Y2.
           - Uses pointer-based iteration for efficiency.
[==============================================================================}
function TPointArrayHelper.BBox: TBox; overload;
var
  P, M: PPoint;
  L: Integer;
begin
  L := Self.Length;
  if (L > 0) then
  with Result do
  begin
    P := @Self[0];
    X1 := P^.X;
    Y1 := P^.Y;
    X2 := P^.X;
    Y2 := P^.Y;
    if (L = 1) then
      Exit;
    M := @Self[0];
    Inc(M, L);
    repeat
      if (X1 > P^.X) then
        X1 := P^.X
      else if (X2 < P^.X) then
        X2 := P^.X;
      if (Y1 > P^.Y) then
        Y1 := P^.Y
      else if (Y2 < P^.Y) then
        Y2 := P^.Y;
      Inc(P);
    until (P = M);
  end;
end; 

{==============================================================================]
  <MinMax>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.MinMax: TBox; 
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  Result.Create(Self[0]);
  for i := 0 to High(Self) do
  begin
    Result.X1 := Min(Self[i].X, Result.X1);
    Result.Y1 := Min(Self[i].Y, Result.Y1);
    Result.X2 := Max(Self[i].X, Result.X2);
    Result.Y2 := Max(Self[i].Y, Result.Y2);
  end;
end;

{==============================================================================]
  <Boxed>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Boxed: TBox; 
var
  i: Integer;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  Result.Create(Self[0]);
  for i := 1 to High(Self) do
    if (Self[i].X < Result.X1) then
      Result.X1 := Self[i].X;
  for i := 1 to High(Self) do
    if (Self[i].X > Result.X2) then
      Result.X2 := Self[i].X;
  for i := 1 to High(Self) do
    if (Self[i].Y < Result.Y1) then
      Result.Y1 := Self[i].Y;
  for i := 1 to High(Self) do
    if (Self[i].Y > Result.Y2) then
      Result.Y2 := Self[i].Y;
end;

{==============================================================================]
  <Region>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Region: TBox; overload; 
var
  i, l: Integer;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(Result.Create(-2147483648));
  Result.Create(MaxInt, MaxInt, -MaxInt, -MaxInt);
  for i := 0 to (l - 1) do
  begin
    if (Self[i].X < Result.X1) then
      Result.X1 := Self[i].X;
    if (Self[i].Y < Result.Y1) then
      Result.Y1 := Self[i].Y;
    if (Self[i].X > Result.X2) then
      Result.X2 := Self[i].X;
    if (Self[i].Y > Result.Y2) then
      Result.Y2 := Self[i].Y;
  end;
end;

{==============================================================================]
  <Coverage>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Coverage: TBox; overload; 
var
  i: Integer;
  a, b: TPoint;
begin
  if Self.Empty then
    Exit(Result.Create(-2147483648));
  a := Point(High(Integer), High(Integer));
  b := Point(Low(Integer), Low(Integer));
  for i := 0 to High(Self) do
  begin
    if (Self[i].X < a.X) then
      a.X := Self[i].X
    else
      if (Self[i].X > b.X) then
        b.X := Self[i].X;
    if (Self[i].Y < a.Y) then
      a.Y := Self[i].Y
    else
      if (Self[i].Y > b.Y) then
        b.Y := Self[i].Y;
  end;
  Result.Create(a.X, a.Y, b.X, b.Y);
end;

{==============================================================================]
  <Undupe>
  @action: Removes duplicates from arr.
  @note: Returns number of duplicate items that were removed from arr.
[==============================================================================}
function TPointArrayHelper.Undupe: TPointArray; 
begin
  Result := Self.Copy;
  CPointArray.Unique(Result);
end;

{==============================================================================]
  <Unduped>
  @action: Returns arr without duplicates.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Unduped: TPointArray; 
var
  i, r, w, h: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  r := 0;
  if Self.Exists then
  begin
    b := Self.Bounds(w, h);
    m := T2D.Create(False, w, h);
    SetLength(Result, Self.Size);
    for i := 0 to High(Self) do
      if m[Self[i].X - b.X1][Self[i].Y - b.Y1].Enable then
        Result[r.Increase] := Self[i];
    SetLength(m, 0);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Invert>
  @action: Returns inverted version of arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Invert: TPointArray; 
var
  i, x, y, w, h, r: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  r := 0;
  if (High(Self) > 0) then
  begin
    b := Self.Bounds(w, h);
	m := T2D.Create(False, w, h);
    x := 0;
    for i := 0 to High(Self) do
      if m[Self[i].X - b.X1][Self[i].Y - b.Y1].Enable then
        Inc(x);
    SetLength(Result, ((w * h) - x));
    if (Result.Size > 0) then
    for y := 0 to (h - 1) do
      for x := 0 to (w - 1) do
        if not m[x][y] then
          Result[r.Increase].Create((x + b.X1), (y + b.Y1));
    SetLength(m, 0);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Inverted>
  @action: Returns inverted version of arr.
  @note: Supports custom bounds.
[==============================================================================}
function TPointArrayHelper.Inverted(const arrBounds: TBox): TPointArray; overload; 
var
  x, y, r: Integer;
begin
  SetLength(Result, arrBounds.Area);
  r := 0;
  for y := arrBounds.Y1 to arrBounds.Y2 do
    for x := arrBounds.X1 to arrBounds.X2 do
      if not Self.Contains(Point(x, y)) then
        Result[r.Increase] := Point(x, y);
  SetLength(Result, r);
end;

function TPointArrayHelper.Inverted: TPointArray; overload; 
begin
  Result := Self.Inverted(Self.Bounds);
end;

{==============================================================================]
  <Inverse>
  @action: Returns inverted version of arr.
  @note: Supports custom bounds.
[==============================================================================}
function TPointArrayHelper.Inverse(const arrBounds: TBox): TPointArray; overload; 
var
  w, h, l, i, x, y: Integer;
  b: T2DBooleanArray;
begin
  if (Self.Size < 2) then
    Exit([]);
  SetLength(Result, arrBounds.Size(w, h));
  b := T2D.Create(False, h, w);
  for i := 0 to High(Self) do
    if arrBounds.Contains(Self[i]) then
      b[Self[i].Y - arrBounds.Y1][Self[i].X - arrBounds.X1] := True;
  l := 0;
  for y := arrBounds.Y1 to arrBounds.Y2 do
    for x := arrBounds.X1 to arrBounds.X2 do
      if not b[y - arrBounds.Y1][x - arrBounds.X1] then
        Result[l.Increase] := Point(x, y);
  SetLength(Result, l);
end;

function TPointArrayHelper.Inverse: TPointArray; overload; 
begin
  Result := Self.Inverse(Self.Bounds);
end;

{==============================================================================]
  <Edge>
  @action: Returns with all the edge-points from arr.
           Supports both, 4-way and 8-way direction scanning styles.
  @note: Edge-points are points that are on the edge of the TPointArray, not completely surrounded by other points.
[==============================================================================}
function TPointArrayHelper.Edge(const scan8W: Boolean = False): TPointArray; 
var
  i, l, x, y, w, h, r: Integer;
  m: T2DBooleanArray;
  b: TBox;
begin
  l := Self.Length;
  if (l > 4) then
  begin
    b := Self.Bounds;
    b := b.Expand;
    b.Size(w, h);
    m := T2D.Create(False, w, h);
    for i := 0 to (l - 1) do
      m[Self[i].X - b.X1][Self[i].Y - b.Y1] := True;
    SetLength(Result, (w * h));
    w := (w - 2);
    h := (h - 2);
    r := 0;
    case scan8W of
      False:
      for y := 1 to h do
        for x := 1 to w do
          if (m[x][y] and not (m[x - 1][y] and m[x][y - 1] and m[x + 1][y] and m[x][y + 1])) then
            Result[r.Increase].Create((x + b.X1), (y + b.Y1));
      True:
      for y := 1 to h do
        for x := 1 to w do
          if (m[x][y] and not (m[x - 1][y] and m[x][y - 1] and m[x + 1][y] and m[x][y + 1] and m[x - 1][y - 1] and m[x - 1][y + 1] and m[x + 1][y - 1] and m[x + 1][y + 1])) then
            Result[r.Increase].Create((x + b.X1), (y + b.Y1));
    end;
    SetLength(Result, r);
    SetLength(m, 0);
  end else
    Result := Self.Copy;
end;

{==============================================================================]
  <FloodFill>
  @action:: Outputs Flood Filled points from TPointArray or non-TPointArray points inside an area,
            starting from start, based on FloodFill() action.
            Supports custom area by area as TBox.
  note: Make sure start is inside your area. Doesn't pay attention to ANYTHING outside area. :)
[==============================================================================}
function TPointArrayHelper.FloodFill(const start: TPoint; const area: TBox; const scan8W: Boolean = False): TPointArray; overload; 
var
  l, i, w, h, x, y, f, r: Integer;
  q, a: TPointArray;
  p: TPoint;
  c, z: T2DBooleanArray;
  o, s: Boolean;
begin
  r := 0;
  l := Self.Length;
  if ((l > 0) and area.Contains(start)) then
  begin
    o := False;
    area.Size(w, h);
    c := T2D.Create(False, w, h);
    for i := 0 to (l - 1) do
    begin
      if not o then
        o := (start = Self[i]);
      if (((Self[i].X - area.X1) > -1) and ((Self[i].Y - area.Y1) > -1) and ((Self[i].Y - area.Y1) < h) and ((Self[i].X - area.X1) < w)) then
        c[Self[i].X - area.X1][Self[i].Y - area.Y1] := True;
    end;
    s := not o;
    if scan8W then
      f := 7
    else
      f := 3;
    SetLength(a, (f + 1));
    SetLength(q, (w * h));
    z := T2D.Create(False, w, h);
    q[0] := start;
    l := 0;
    while (l > -1) do
    begin
      q[l].Adjacent(a, scan8W);
      for i := 0 to f do
      begin
        p := a[i];
        x := (p.X - area.X1);
        y := (p.Y - area.Y1);
        if ((x > -1) and (y > -1) and (x < w) and (y < h) and (c[x][y] = not s)) then
        begin
          c[x][y] := s;
          z[x][y] := True;
          q[l.Increase] := p;
        end;
      end;
      l := (l - 1);
    end;
    SetLength(c, 0);
    SetLength(q, 0);
    SetLength(a, 0);
    SetLength(Result, (w * h));
    for y := 0 to (h - 1) do
      for x := 0 to (w - 1) do
        if z[x][y] then
          Result[r.Increase].Create((x + area.X1), (y + area.Y1));
    SetLength(z, 0);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <FloodFill>
  @action: Outputs Flood Filled points from TPointArray or non-TPointArray points inside arr Bounds,
           starting from start, based on FloodFill() action.
  @note: Make sure start is inside TPA Bounds.
         Doesn't pay attention to ANYTHING outside those boundaries. :)
[==============================================================================}
function TPointArrayHelper.FloodFill(const start: TPoint; const scan8W: Boolean = False): TPointArray; overload; 
begin
  Result := Self.FloodFill(start, Self.Bounds, scan8W);
end;

{==============================================================================]
  <Xs>
  @action: Extracts the X-coordinates of all points in the array and returns
           them as a TIntegerArray. The order of values in the result matches
           the order of the points in the source array.
  @note: This is a direct projection operation; no filtering, sorting, or
         transformation is applied. The returned array always has the same
         length as the source.
[==============================================================================}
function TPointArrayHelper.Xs: TIntegerArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].X;
end;

{==============================================================================]
  <Ys>
  @action: Extracts the Y-coordinates of all points in the array and returns
           them as a TIntegerArray, preserving the original element order.
  @note: Performs a simple coordinate projection without any modification or
         reordering. The returned array has the same length as the input.
[==============================================================================}
function TPointArrayHelper.Ys: TIntegerArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i] := Self[i].Y;
end;

{==============================================================================]
  <XValues>
  @action: Returns X-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TPointArrayHelper.XValues: TIntegerArray; overload; 
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].X;
end;

{==============================================================================]
  <YValues>
  @action: Returns Y-values from arr as TIntegerArray.
  @note: None.
[==============================================================================}
function TPointArrayHelper.YValues: TIntegerArray; overload; 
var
  l: Integer;
begin
  l := Self.Length;
  SetLength(Result, l);
  while (l.Decrement > -1) do
    Result[l] := Self[l].Y;
end;

{==============================================================================]
  <Unzip>
  @action: Stores arr X and Y values to xArr and yArr.
  @note: Returns Length(arr).
[==============================================================================}
function TPointArrayHelper.Unzip(var xArr, yArr: TIntegerArray): Integer; 
var
  i: Integer;
begin
  Result := Self.Size;
  SetLength(xArr, Result);
  SetLength(yArr, Result);
  for i := 0 to (Result - 1) do
  begin
    xArr[i] := Self[i].X;
    yArr[i] := Self[i].Y;
  end;
end;

{==============================================================================]
  <Zip>
  @action: Zips TPointArray with xArr and yArr.
  @note: Uses minimum length(!), if xArr differs from yArr size.
[==============================================================================}
function TPointArrayHelper.Zip(const xArr, yArr: TIntegerArray): Integer; 
var
  i: Integer;
begin
  Result := Min(xArr.Size, yArr.Size);
  SetLength(Self, Result);
  for i := 0 to (Result - 1) do
    Self[i] := Point(xArr[i], yArr[i]);
end;

{==============================================================================]
  <Extent>
  @action: Returns bounding box around TPointArray arr.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Extent: TBox; 
var
  h, v: TIntegerArray;
  z: Integer;
begin
  z := (Self.Unzip(h, v) - 1);
  if (z > -1) then
  begin
    h.QuickSort;
    v.QuickSort;
    Result.Create(h[0], v[0], h[z], v[z]);
  end;
end;

{==============================================================================]
  <Horizontal>
  @action: Returns Horizontal-axis from TPointArray as TRange.
  @note: MinMax X-values.
[==============================================================================}
function TPointArrayHelper.Horizontal: TRange; overload; 
var
  i: Integer;
begin
  if Self.Exists then
  begin
    Result.Create(Self[0].X, Self[0].X);
    for i := 0 to High(Self) do
      if (Self[i].X < Result.start) then
        Result.start := Self[i].X
      else
        if (Self[i].X > Result.stop) then
          Result.stop := Self[i].X;
  end else
    Result := Default(TRange);
end;

{==============================================================================]
  <Vertical>
  @action: Returns Vertical-axis from TPointArray as TRange.
  @note: MinMax Y-values.
[==============================================================================}
function TPointArrayHelper.Vertical: TRange; overload; 
var
  i: Integer;
begin
  if Self.Exists then
  begin
    Result.Create(Self[0].Y, Self[0].Y);
    for i := 0 to High(Self) do
      if (Self[i].Y < Result.start) then
        Result.start := Self[i].Y
      else
        if (Self[i].Y > Result.stop) then
          Result.stop := Self[i].Y;
  end else
    Result := Default(TRange);
end;

{==============================================================================]
  <Neighborify>
  @action: Groups points into clusters of connected neighbors based on 4- or 8-directional adjacency.
  @note: Uses a flood-fill algorithm on a bounding-box grid. Returns a T2DPointArray where each sub-array is a connected component.
         Empty arrays return [] and single-point arrays return [Self].
[==============================================================================}
function TPointArrayHelper.Neighborify(const adjacency8: Boolean = True): T2DPointArray; overload;
var
  w, h, l: Integer;
  v, g: T2DBooleanArray;
  d, q: TPointArray;
  s: TRange;
  i, j, x, y, z, r: Integer;
  p: TPoint;
  b: TBox;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  b := Self.Bounds(w, h);
  SetLength(g, w, h);
  SetLength(v, w, h);
  for i := 0 to (l - 1) do
    g[Self[i].X - b.X1][Self[i].Y - b.Y1] := True;
  if adjacency8 then
    d := [Point(-1, -1), Point(-1, 0), Point(-1, 1), Point(0, 1), Point(1, 1), Point(1, 0), Point(1, -1), Point(0, -1)]
  else
    d := [Point(-1, 0), Point(0, -1), Point(1, 0), Point(0, 1)];
  r := 0;
  SetLength(Result, l);
  for i := 0 to (w - 1) do
    for j := 0 to (h - 1) do
      if (g[i][j] and (not v[i][j])) then
      begin
        SetLength(q, 1);
        q[0] := Point(i, j);
        s.Create(0, 1);
        while (s.start < s.stop) do
        begin
          p := q[s.start.Increase];
          if v[p.X][p.Y] then
            Continue;
          v[p.X][p.Y] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := Point((p.X + b.X1), (p.Y + b.Y1));
          for z := 0 to High(d) do
          begin
            x := (p.X + d[z].X);
            y := (p.Y + d[z].Y);
            if ((x >= 0) and (x < w) and (y >= 0) and (y < h) and g[x][y] and (not v[x][y])) then
            begin
              if (s.stop >= q.Size) then
                SetLength(q, (q.Size * 2));
              q[s.stop.Increase] := Point(x, y);
            end;
          end;
        end;
        if (Result[r].Size > 0) then
          Inc(r);
      end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Regionize>
  @action: Groups points in the array into clusters based on rectangular neighborhoods
           defined by X and Y radii.
  @note: Clusters are formed by examining a box of size XRadius x YRadius around each
         point. Points within the same box are grouped together. This version does not
         use a distance function; it is grid/box-based.
[==============================================================================}
function TPointArrayHelper.Regionize(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  x, y, i, l, r, c, t, f: Integer;
  g, d: TStringList;
  p, n: TPoint;
  q: TPointArray;
  k: string;
  a, b: TBox;
  function KeyStr(const p: TPoint): string; inline;
  begin
    Result := (IntToStr(p.X) + ',' + IntToStr(p.Y));
  end;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  b := Self.Bounds;
  g := TStringList.Create;
  g.Sorted := False;
  g.Duplicates := dupIgnore;
  d := TStringList.Create;
  d.Sorted := True;
  d.Duplicates := dupIgnore;
  r := 0;
  SetLength(Result, l);
  try
    for i := 0 to (l - 1) do
      g.Add(KeyStr(Self[i]));
    g.Sorted := True;
    g.Sort;
    for i := 0 to (l - 1) do
    begin
      if d.Find(KeyStr(Self[i]), f) then
        Continue;
      SetLength(Result[r], 0);
      SetLength(q, 1);
      q[0] := Self[i];
      t := 0;
      c := 1;
      while (t < c) do
      begin
        p := q[t.Increase];
        k := KeyStr(p);
        if d.Find(k, f) then
          Continue;
        d.Add(k);
        SetLength(Result[r], (Result[r].Size + 1));
        Result[r][High(Result[r])] := p;
        a := p.Boxed(xRadius, yRadius).Clamp(b);
        for y := a.Y1 to a.Y2 do
          for x := a.X1 to a.X2 do
          begin
            n := Point(x, y);
            k := KeyStr(n);
            if (g.Find(k, f) and (not d.Find(k, f))) then
            begin
              SetLength(q, (c + 1));
              q[c.Increase] := n;
            end;
          end;
      end;
      if (Result[r].Size > 0) then
        Inc(r);
    end;
  finally
    g.Free;
    d.Free;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Regionize>
  @action: Groups points in the array into clusters based on a distance threshold.
  @note: Clusters are formed by examining all points within the array using the
         provided distance function. Points within the specified radius (Double)
         of any cluster member are added to the same cluster. This version supports
         arbitrary distance metrics via the TDistance parameter.
[==============================================================================}
function TPointArrayHelper.Regionize(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  i, j, l, r, c, t, f: Integer;
  g, d: TStringList;
  p: TPoint;
  q: TPointArray;
  k: string;
  function KeyStr(const p: TPoint): string; inline;
  begin
    Result := (IntToStr(p.X) + ',' + IntToStr(p.Y));
  end;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  g := TStringList.Create;
  g.Sorted := False;
  g.Duplicates := dupIgnore;
  d := TStringList.Create;
  d.Sorted := True;
  d.Duplicates := dupIgnore;
  r := 0;
  SetLength(Result, l);
  try
    for i := 0 to (l - 1) do
      g.Add(KeyStr(Self[i]));
    g.Sorted := True;
    g.Sort;
    for i := 0 to (l - 1) do
    begin
      if d.Find(KeyStr(Self[i]), f) then
        Continue;
      SetLength(Result[r], 0);
      SetLength(q, 1);
      q[0] := Self[i];
      t := 0;
      c := 1;
      while (t < c) do
      begin
        p := q[t.Increase];
        k := KeyStr(p);
        if d.Find(k, f) then
          Continue;
        d.Add(k);
        SetLength(Result[r], (Result[r].Size + 1));
        Result[r][High(Result[r])] := p;
        for j := 0 to (l - 1) do
          if ((not d.Find(KeyStr(Self[j]), f)) and p.Within(Self[j], radius, distFunc)) then
          begin
            SetLength(q, (c + 1));
            q[c.Increase] := Self[j];
          end;
      end;
      if (Result[r].Size > 0) then
        Inc(r);
    end;
  finally
    g.Free;
    d.Free;
  end;
  SetLength(Result, r);
end;

function TPointArrayHelper.Regionize(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Regionize(radius, @Euclidean);
end;

{==============================================================================]
  <CSplit>
  @action: Groups points into clusters based on horizontal (X-axis) proximity.
  @note: Sorts by column (X) unless already sorted. Uses distance function or fixed x/y radii.
[==============================================================================}
function TPointArrayHelper.CSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByColumn;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      for k := 0 to High(a) do
      begin
        if u[k] then
          Continue;
        p := Result[r][j];
        m.Create(Trunc(p.X - radius), Trunc(p.X + radius));
        if (((a[k].X >= m.start) and (a[k].X <= m.stop)) and p.Within(a[k], radius, distFunc)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
      end;
      Inc(j);
    end;
  end;
end;

function TPointArrayHelper.CSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
begin
  Result := Self.CSplit(radius, @Euclidean, sSorted);
end;

{==============================================================================]
  <CSplit>
  @action: Splits the point set into disjoint clusters using a column-oriented
           expansion rule. A working copy of the array is optionally sorted by
           (X, then Y). Each cluster is formed by starting from an unassigned
           seed point and adding all points whose horizontal separation from
           the seed is within xRadius and whose vertical separation is within
           yRadius. Newly added points become additional expansion sources until
           no further points qualify.
  @note: This method is the column-ordered analogue to RSplit. When sSorted
         is False, the input is first sorted by column (X-major order), which
         determines the order in which seeds are encountered but does not
         affect cluster membership. The expansion process is a simple iterative
         scan: for every point already in the cluster, all remaining points are
         tested for axis-aligned proximity (rectangular window). Complexity is
         O(N²) in the worst case. No metric distance is evaluated—only direct
         coordinate comparisons.
[==============================================================================}
function TPointArrayHelper.CSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByColumn;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      for k := 0 to High(a) do
      begin
        if u[k] then
          Continue;
        p := Result[r][j];
        m.Create((p.X - xRadius), (p.X + xRadius));
        if (((a[k].X >= m.start) and (a[k].X <= m.stop)) and (Abs(a[k].Y - p.Y) <= yRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <RSplit>
  @action: Groups points into clusters based on vertical (Y-axis) proximity.
  @note: Sorts by row (Y) unless already sorted. Uses distance function or fixed x/y radii.
[==============================================================================}
function TPointArrayHelper.RSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByRow;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      for k := 0 to High(a) do
      begin
        if u[k] then
          Continue;
        m.Create(Trunc(p.Y - radius), Trunc(p.Y + radius));
        if (((a[k].Y >= m.start) and (a[k].Y <= m.stop)) and p.Within(a[k], radius, distFunc)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
      end;
      Inc(j);
    end;
  end;
end;

function TPointArrayHelper.RSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
begin
  Result := Self.RSplit(radius, @Euclidean, sSorted);
end;

{==============================================================================]
  <RSplit>
  @action: Partitions the point set into disjoint groups based on axis-aligned
           proximity criteria, optionally assuming the input is already sorted
           by (Y, then X). Each group is built by repeatedly expanding from a
           seed point and adding all unassigned points whose vertical separation
           from the seed is within yRadius and whose horizontal separation is
           within xRadius. Returns an array of these groups.
  @note: This procedure implements a row-oriented regional split. If sSorted
         is False, the method first creates a working copy of the input and
         sorts it by Y (and secondarily by X). The grouping uses a simple
         expansion pass (not a queue-based BFS) in which newly added points
         are appended to the cluster and subsequently used as additional
         expansion seeds. Ordering of the sorted working array influences
         cluster formation order but not final cluster membership. Worst-case
         complexity is O(N²). No distance metric is used—only coordinate-wise
         comparisons.
[==============================================================================}
function TPointArrayHelper.RSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByRow;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      for k := 0 to High(a) do
      begin
        if u[k] then
          Continue;
        m.Create((p.Y - yRadius), (p.Y + yRadius));
        if (((a[k].Y >= m.start) and (a[k].Y <= m.stop)) and (Abs(a[k].X - p.X) <= xRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <XSplit>
  @action: Splits the point array into clusters based on X/Y coordinate proximity.
  @note: Optimized for arrays sorted by X (ascending). 
         Each group contains points within |ΔX| ≤ xRadius and |ΔY| ≤ yRadius.
         If sSorted = True, sorting is skipped to save time.
[==============================================================================}
function TPointArrayHelper.XSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  a: TPointArray;
  m: TRange;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByColumn;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      m.Create((p.X - xRadius), (p.X + xRadius));
      k := i;
      while ((k < l) and (a[k].X <= m.stop)) do
      begin
        if ((not u[k]) and (Abs(a[k].Y - p.Y) <= yRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Inc(k);
      end;
      k := (i - 1);
      while ((k >= 0) and (a[k].X >= m.start)) do
      begin
        if ((not u[k]) and (Abs(a[k].Y - p.Y) <= yRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Dec(k);
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <XSplit>
  @action: Splits the point array into clusters using a custom distance function.
  @note: Efficient for data already sorted by X.
         Points are grouped if distFunc(p, q) ≤ radius.
         The X-range window limits comparisons for performance (O(n log n) typical).
[==============================================================================}
function TPointArrayHelper.XSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByColumn;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      m.Create(Trunc(p.X - radius), Trunc(p.X + radius));
      k := i;
      while ((k < l) and (a[k].X <= m.stop)) do
      begin
        if ((not u[k]) and p.Within(a[k], radius, distFunc)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Inc(k);
      end;
      k := (i - 1);
      while ((k >= 0) and (a[k].X >= m.start)) do
      begin
        if ((not u[k]) and p.Within(a[k], radius, distFunc)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Dec(k);
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <XSplit>
  @action: Splits the point array into clusters using Euclidean distance.
  @note: Shorthand for XSplit(radius, @Euclidean, sSorted).
         Groups points if their Euclidean distance ≤ radius.
[==============================================================================}
function TPointArrayHelper.XSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
begin
  Result := Self.XSplit(radius, @Euclidean, sSorted);
end;

{==============================================================================]
  <YSplit>
  @action: Splits the point array into clusters based on Y/X coordinate proximity.
  @note: Optimized for arrays sorted by Y (ascending).
         Each group contains points within |ΔY| ≤ yRadius and |ΔX| ≤ xRadius.
         If sSorted = True, sorting is skipped to save time.
[==============================================================================}
function TPointArrayHelper.YSplit(const xRadius, yRadius: Integer; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  a: TPointArray;
  m: TRange;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByRow;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      m.Create((p.Y - yRadius), (p.Y + yRadius));
      k := i;
      while ((k < l) and (a[k].Y <= m.stop)) do
      begin
        if ((not u[k]) and (Abs(a[k].X - p.X) <= xRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Inc(k);
      end;
      k := (i - 1);
      while ((k >= 0) and (a[k].Y >= m.start)) do
      begin
        if ((not u[k]) and (Abs(a[k].X - p.X) <= xRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Dec(k);
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <YSplit>
  @action: Splits the point array into clusters using a custom distance function.
  @note: Efficient for data already sorted by Y.
         Points are grouped if distFunc(p, q) ≤ radius.
         Y-sorted scanning limits comparisons for faster clustering.
[==============================================================================}
function TPointArrayHelper.YSplit(const radius: Double; const distFunc: TDistance; const sSorted: Boolean = False): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
  m: TRange;
  a: TPointArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  u := T1D.Create(False, l);
  SetLength(Result, 0);
  a := Self.Copy;
  if not sSorted then
    a.SortByRow;
  for i := 0 to High(a) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := a[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      m.Create(Trunc(p.Y - radius), Trunc(p.Y + radius));
      k := i;
      while ((k < l) and (a[k].Y <= m.stop)) do
      begin
        if ((not u[k]) and p.Within(a[k], radius, distFunc)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Inc(k);
      end;
      k := (i - 1);
      while ((k >= 0) and (a[k].Y >= m.start)) do
      begin
        if ((not u[k]) and p.Within(a[k], radius, distFunc)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := a[k];
        end;
        Dec(k);
      end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <YSplit>
  @action: Splits the point array into clusters using Euclidean distance.
  @note: Shorthand for YSplit(radius, @Euclidean, sSorted).
         Groups points if their Euclidean distance ≤ radius.
[==============================================================================}
function TPointArrayHelper.YSplit(const radius: Double = 1.0; const sSorted: Boolean = False): T2DPointArray; overload;
begin
  Result := Self.YSplit(radius, @Euclidean, sSorted);
end;

{==============================================================================]
  <Split>
  @action: Splits TPointArray to groups by xRadius and yRadius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Split(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  l, s, c, e, r, h: Integer;
  p: TPointArray;
begin
  h := High(Self);
  case h of
    -1: Exit([]);
    0: Exit([Self]);
  end;
  p := Self.Copy;
  SetLength(Result, (h + 1));
  c := 0;
  e := 0;
  while ((h - e) >= 0) do
  begin
    SetLength(Result[c], 1);
    Result[c][0] := p[0];
    p[0] := p[h - e];
    Inc(e);
    l := 1;
    r := 0;
    while (r < l) do
    begin
      s := 0;
      while (s <= (h - e)) do
      begin
        if Result[c][r].Within(p[s], xRadius, yRadius) then
        begin
          SetLength(Result[c], (l + 1));
          Result[c][l.Increase] := p[s];
          p[s.Decrease] := p[h - e.Increase];
        end;
        Inc(s);
      end;
      Inc(r);
    end;
    Inc(c);
  end;
  SetLength(Result, c);
end;

{==============================================================================]
  <Split>
  @action: Splits TPointArray to groups by radius.
  @note: Supports custom distance function.
[==============================================================================}
function TPointArrayHelper.Split(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  l, s, c, e, r, h: Integer;
  p: TPointArray;
begin
  h := High(Self);
  case h of
    -1: Exit([]);
    0: Exit([Self]);
  end;
  p := Self.Copy;
  SetLength(Result, (h + 1));
  c := 0;
  e := 0;
  while ((h - e) >= 0) do
  begin
    SetLength(Result[c], 1);
    Result[c][0] := p[0];
    p[0] := p[h - e];
    Inc(e);
    l := 1;
    r := 0;
    while (r < l) do
    begin
      s := 0;
      while (s <= (h - e)) do
      begin
        if Result[c][r].Within(p[s], radius, distFunc) then
        begin
          SetLength(Result[c], (l + 1));
          Result[c][l.Increase] := p[s];
          p[s.Decrease] := p[h - e.Increase];
        end;
        Inc(s);
      end;
      Inc(r);
    end;
    Inc(c);
  end;
  SetLength(Result, c);
end;

{==============================================================================]
  <Split>
  @action: Splits TPointArray to groups by radius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Split(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Split(radius, @Euclidean);
end;

{==============================================================================]
  <SplitEx>
  @action: Splits TPointArray to groups by xRadius and yRadius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.SplitEx(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
begin
  l := Self.Length;
  case l of
    -1: Exit([]);
    0: Exit([Self]);
  end;
  u.Create(l, False);
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      for k := 0 to (l - 1) do
        if ((not u[k]) and p.Within(Self[k], xRadius, yRadius)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := Self[k];
        end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <SplitEx>
  @action: Splits TPointArray to groups by radius.
  @note: Supports custom distance function.
[==============================================================================}
function TPointArrayHelper.SplitEx(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  i, j, k, r, l: Integer;
  u: TBooleanArray;
  p: TPoint;
begin
  l := Self.Length;
  case l of
    -1: Exit([]);
    0: Exit([Self]);
  end;
  u.Create(l, False);
  SetLength(Result, 0);
  for i := 0 to High(Self) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    r := High(Result);
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    u[i] := True;
    j := 0;
    while (j < Result[r].Size) do
    begin
      p := Result[r][j];
      for k := 0 to (l - 1) do
        if ((not u[k]) and p.Within(Self[k], radius, distFunc)) then
        begin
          u[k] := True;
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := Self[k];
        end;
      Inc(j);
    end;
  end;
end;

{==============================================================================]
  <SplitEx>
  @action: Splits TPointArray to groups by radius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.SplitEx(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.SplitEx(radius, @Euclidean);
end;

{==============================================================================]
  <Clusters>
  @action: Group points in the array into clusters based on a distance threshold.
  @note: Uses a breadth-first region-growing approach.
         Each cluster contains points whose pairwise distances are within radius.
         Uses the provided distance function.
[==============================================================================}
function TPointArrayHelper.Clusters(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  i, w, h, e, v, z, r, n, t, x, y: Integer;
  c: T2DIntegerArray;
  s: T2DBooleanArray;
  q: TPointArray;
  b, f: TBox;
  g, k, u: TPoint;
  a: Boolean;
  l: TRange;
  d, m, o: Double;
begin
  z := Self.Size;
  case z of
    0: Exit([]);
    1: ExiT([Self]);
  end;
  SetLength(Result, 0);
  b := Self.Bounds(w, h);
  c := T2D.Create(0, w, h);
  s := T2D.Create(False, w, h);
  for i := 0 to High(Self) do
    Inc(c[Self[i].X - b.X1][Self[i].Y - b.Y1]);
  SetLength(q, z);
  d := Max(radius, 0);
  o := (d * d);
  m := Min(d, Max(w, h));
  r := 0;
  e := 0;
  for i := 0 to (z - 1) do
  begin
    g:= Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    if (c[g.X][g.Y] <= 0) then
      Continue;
    n := c[g.X][g.Y];
    SetLength(Result, (r + 1));
    SetLength(Result[r], n);
    for v := 0 to (n - 1) do
      Result[r][v] := Self[i];
    if (e.Increment(n) > (z - 1)) then
      Exit;
    l.Create(0);
    q[l.stop.Increase] := Result[r][0];
    c[g.X][g.Y] := 0;
    while (l.start < l.stop) do
    begin
      k := q[l.start.Increase];
      f := k.Boxed(Ceil(m)).Clamp(b);
      for y := f.Y1 to f.Y2 do
      begin
        if s[f.X2 - b.X1][y - b.Y1] then
          Continue;
        a := True;
        for x := f.X1 to f.X2 do
        begin
          u := Point((x - b.X1), (y - b.Y1));
          if not (c[u.X][u.Y] > 0) then
            Continue;
          if k.Within(Point(x, y), o, distFunc) then
          begin
            t := Result[r].Size;
            SetLength(Result[r], (t + c[u.X][u.Y]));
            for v := 0 to (c[u.X][u.Y] - 1) do
              Result[r][t + v] := Point(x, y);
            q[l.stop.Increase] := Result[r][t];
            if (e.Increment(c[u.X][u.Y]) > (z - 1)) then
              Exit;
            c[u.X][u.Y] := 0;
          end else
            a := False;
        end;
        if a then
          s[f.X2 - b.X1][y - b.Y1] := True;
      end;
    end;
    Inc(r);
  end;
end;

function TPointArrayHelper.Clusters(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Clusters(radius, @Euclidean);
end;

{==============================================================================]
  <Clusters>
  @action: Group points in the array into rectangular clusters based on X and Y radii.
  @note: Clustering is anisotropic — points are grouped if their |ΔX| ≤ xRadius and |ΔY| ≤ yRadius.
         No distance function is used.
[==============================================================================}
function TPointArrayHelper.Clusters(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, w, h, e, v, z, r, n, t, x, y: Integer;
  c: T2DIntegerArray;
  s: T2DBooleanArray;
  q: TPointArray;
  b, f: TBox;
  g, k, u, m: TPoint;
  a: Boolean;
  l: TRange;
begin
  z := Self.Size;
  case z of
    0: Exit([]);
    1: ExiT([Self]);
  end;
  SetLength(Result, 0);
  b := Self.Bounds(w, h);
  c := T2D.Create(0, w, h);
  s := T2D.Create(False, w, h);
  for i := 0 to High(Self) do
    Inc(c[Self[i].X - b.X1][Self[i].Y - b.Y1]);
  SetLength(q, z);
  m := Point(Min(Max(0, xRadius), w), Min(Max(0, yRadius), h));
  r := 0;
  e := 0;
  for i := 0 to (z - 1) do
  begin
    g:= Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    if (c[g.X][g.Y] <= 0) then
      Continue;
    n := c[g.X][g.Y];
    SetLength(Result, (r + 1));
    SetLength(Result[r], n);
    for v := 0 to (n - 1) do
      Result[r][v] := Self[i];
    if (e.Increment(n) > (z - 1)) then
      Exit;
    l.Create(0);
    q[l.stop.Increase] := Result[r][0];
    c[g.X][g.Y] := 0;
    while (l.start < l.stop) do
    begin
      k := q[l.start.Increase];
      f := k.Boxed(Max(m.X, m.Y)).Clamp(b);
      for y := f.Y1 to f.Y2 do
      begin
        if s[f.X2 - b.X1][y - b.Y1] then
          Continue;
        a := True;
        for x := f.X1 to f.X2 do
        begin
          u := Point((x - b.X1), (y - b.Y1));
          if not (c[u.X][u.Y] > 0) then
            Continue;
          if k.Within(Point(x, y), m.X, m.Y) then
          begin
            t := Result[r].Size;
            SetLength(Result[r], (t + c[u.X][u.Y]));
            for v := 0 to (c[u.X][u.Y] - 1) do
              Result[r][t + v] := Point(x, y);
            q[l.stop.Increase] := Result[r][t];
            if (e.Increment(c[u.X][u.Y]) > (z - 1)) then
              Exit;
            c[u.X][u.Y] := 0;
          end else
            a := False;
        end;
        if a then
          s[f.X2 - b.X1][y - b.Y1] := True;
      end;
    end;
    Inc(r);
  end;
end;

{==============================================================================]
  <Cluster>
  @action: Groups the points in the array into clusters based on a given distance threshold.
  @note: Uses a grid-based breadth-first search (BFS) approach; points are added to a cluster 
         if their distance from any member is less than or equal to radius.
		 Supports custom distance functions via distFunc (default is Euclidean).
[==============================================================================}
function TPointArrayHelper.Cluster(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  w, h, i, j, c, r, x, y: Integer;
  d: Double;
  b, a: TBox;
  e: Boolean;
  v: T2DBooleanArray;
  g: array of T2DPointArray;
  q: TPointArray;
  z, p, n: TPoint;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(Result, 0);
  SetLength(Result, Self.Size);
  b := Self.Bounds(w, h);
  d := Max(0, radius);
  c := Ceil(d);
  SetLength(g, (w + 1), (h + 1));
  SetLength(v, (w + 1), (h + 1));
  for i := 0 to High(Self) do
  begin
    n := Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    SetLength(g[n.X][n.Y], (g[n.X][n.Y].Size + 1));
    g[n.X][n.Y][High(g[n.X][n.Y])] := Self[i];
  end;
  r := 0;
  for i := 0 to High(Self) do
  begin
    n := Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    if (v[n.X][n.Y] or g[n.X][n.Y].Empty) then
      Continue;
    SetLength(q, 1);
    q[0] := Self[i];
    while (q.Size > 0) do
    begin
      z := q[High(q)];
      SetLength(q, High(q));
      a.Create((z.X - c), (z.Y - c), (z.X + c), (z.Y + c)).Constraint(b);
      for y := a.Y1 to a.Y2 do
        for x := a.X1 to a.X2 do
        begin
          if v[x - b.X1][y - b.Y1] then
            Continue;
          for j := 0 to High(g[x - b.X1][y - b.Y1]) do
          begin
            p := g[x - b.X1][y - b.Y1][j];
            if (distFunc(z, p) <= d) then
            begin
              SetLength(Result[r], (Result[r].Size + 1));
              Result[r][High(Result[r])] := p;
              SetLength(q, (q.Size + 1));
              q[High(q)] := p;
              g[x - b.X1][y - b.Y1][j] := Point(-1, -1);
            end;
          end;
          e := True;
          for j := 0 to High(g[x - b.X1][y - b.Y1]) do
            if (g[x - b.X1][y - b.Y1][j].X <> -1) then
              e := False;
          if e then
            v[x - b.X1][y - b.Y1] := True;
        end;
    end;
    if (Result[r].Size > 0) then
      Inc(r);
  end;
  SetLength(Result, r);
end;

function TPointArrayHelper.Cluster(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Cluster(radius, @Euclidean);
end;

{==============================================================================]
  <Cluster>
  @action: Groups points into clusters using separate X and Y distance limits.
  @note: Clusters are formed within rectangular (axis-aligned) bounds where the 
         absolute difference in X and Y coordinates does not exceed xRadius and yRadius. 
         Faster than the distance-function version but not rotation invariant.
[==============================================================================}
function TPointArrayHelper.Cluster(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  w, h, i, j, r, x, y: Integer;
  b, a: TBox;
  e: Boolean;
  v: T2DBooleanArray;
  g: array of T2DPointArray;
  q: TPointArray;
  z, p, n, d: TPoint;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(Result, 0);
  SetLength(Result, Self.Size);
  b := Self.Bounds(w, h);
  d := Point(Max(0, xRadius), Max(0, yRadius));
  SetLength(g, (w + 1), (h + 1));
  SetLength(v, (w + 1), (h + 1));
  for i := 0 to High(Self) do
  begin
    n := Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    SetLength(g[n.X][n.Y], (g[n.X][n.Y].Size + 1));
    g[n.X][n.Y][High(g[n.X][n.Y])] := Self[i];
  end;
  r := 0;
  for i := 0 to High(Self) do
  begin
    n := Point((Self[i].X - b.X1), (Self[i].Y - b.Y1));
    if (v[n.X][n.Y] or g[n.X][n.Y].Empty) then
      Continue;
    SetLength(q, 1);
    q[0] := Self[i];
    while (q.Size > 0) do
    begin
      z := q[High(q)];
      SetLength(q, High(q));
      a.Create((z.X - d.X), (z.Y - d.Y), (z.X + d.X), (z.Y + d.Y)).Constraint(b);
      for y := a.Y1 to a.Y2 do
        for x := a.X1 to a.X2 do
        begin
          if v[x - b.X1][y - b.Y1] then
            Continue;
          for j := 0 to High(g[x - b.X1][y - b.Y1]) do
          begin
            p := g[x - b.X1][y - b.Y1][j];
            if z.Within(p, xRadius, yRadius) then
            begin
              SetLength(Result[r], (Result[r].Size + 1));
              Result[r][High(Result[r])] := p;
              SetLength(q, (q.Size + 1));
              q[High(q)] := p;
              g[x - b.X1][y - b.Y1][j] := Point(-1, -1);
            end;
          end;
          e := True;
          for j := 0 to High(g[x - b.X1][y - b.Y1]) do
            if (g[x - b.X1][y - b.Y1][j].X <> -1) then
              e := False;
          if e then
            v[x - b.X1][y - b.Y1] := True;
        end;
    end;
    if (Result[r].Size > 0) then
      Inc(r);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Clustered>
  @action: Groups points into clusters based on pairwise proximity using the
           supplied distance function and radius threshold. Each cluster is a
           connected component where every point is reachable from any other
           through successive neighbor relationships.
  @note: The algorithm performs a flood-fill/region-growing traversal. A point
         joins a cluster if it lies within `radius` of any member of that
         cluster according to `distFunc`. Complexity is O(N²) in the worst
         case. Returns an array of clusters, each cluster being a dynamic
         array of TPoint. Input array ordering is preserved in cluster
         discovery; no sorting is performed.
[==============================================================================}
function TPointArrayHelper.Clustered(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  i, j, r: Integer;
  v: TBooleanArray;
  q: TPointArray;
  p: TPoint;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, Self.Size);
  r := 0;
  SetLength(Result, 0);
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
  begin
    if v[i] then
      Continue;
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    v[i] := True;
    SetLength(q, 1);
    q[0] := Self[i];
    while (q.Size > 0) do
    begin
      p := q[High(q)];
      SetLength(q, High(q));
      for j := 0 to High(Self) do
        if ((not v[j]) and p.Within(Self[j], radius, distFunc)) then
        begin
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := Self[j];
          SetLength(q, (q.Size + 1));
          q[High(q)] := Self[j];
          v[j] := True;
        end;
    end;
    Inc(r);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Clustered>
  @action: Groups points into proximity-based clusters using Euclidean distance
           with a caller-specified radius.
  @note: This overload is equivalent to calling the primary variant with the
         built-in Euclidean distance function. See the primary documentation
         for clustering semantics and performance considerations.
[==============================================================================}
function TPointArrayHelper.Clustered(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Clustered(radius, @Euclidean);
end;

{==============================================================================]
  <Clustered>
  @action: Generates clusters by treating two points as neighbors when their
           coordinate-wise separations fall within the specified horizontal and
           vertical radii. Clusters are constructed as connected components under
           this axis-aligned proximity rule.
  @note: Uses a rectangular neighborhood test (Chebyshev-like, but not metric)
         rather than a general distance function. Points are aggregated via a
         flood-fill process identical in structure to the radius-based
         overload. Worst-case complexity is O(N²). Ordering of the input array
         determines cluster enumeration order.
[==============================================================================}
function TPointArrayHelper.Clustered(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, r: Integer;
  v: TBooleanArray;
  q: TPointArray;
  p: TPoint;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, Self.Size);
  r := 0;
  SetLength(Result, 0);
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
  begin
    if v[i] then
      Continue;
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    v[i] := True;
    SetLength(q, 1);
    q[0] := Self[i];
    while (q.Size > 0) do
    begin
      p := q[High(q)];
      SetLength(q, High(q));
      for j := 0 to High(Self) do
        if ((not v[j]) and p.Within(Self[j], xRadius, yRadius)) then
        begin
          SetLength(Result[r], (Result[r].Size + 1));
          Result[r][High(Result[r])] := Self[j];
          SetLength(q, (q.Size + 1));
          q[High(q)] := Self[j];
          v[j] := True;
        end;
    end;
    Inc(r);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Clusterify>
  @action: Performs index-based clustering of the point array using a breadth-
           first expansion. A point joins a cluster when its distance from any
           existing cluster member is within the specified radius according to
           the given distance function. Returns an array of clusters, each
           represented as a TPoint array.
  @note: The algorithm uses an integer queue referencing element indices,
         avoiding redundant point copies during traversal. This variant is
         functionally equivalent to `Clustered` but may offer clearer index
         management and slightly reduced per-iteration overhead. Input order
         determines the order in which clusters are discovered. Worst-case
         complexity is O(N²).
[==============================================================================}
function TPointArrayHelper.Clusterify(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  i, j, r: Integer;
  v: TBooleanArray;
  q: TIntegerArray;
  s, l, c: Integer;
  p: TPoint;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, Self.Size);
  SetLength(Result, Self.Size);
  r := 0;
  for i := 0 to High(Self) do
  begin
    if v[i] then
      Continue;
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    l := 1;
    v[i] := True;
    SetLength(q, 1);
    q[0] := i;
    s := 1;
    while (s > 0) do
    begin
      c := q[s - 1];
      Dec(s);
      SetLength(q, s);
      p := Self[c];
      for j := 0 to High(Self) do
        if ((not v[j]) and p.Within(Self[j], radius, distFunc)) then
        begin
          v[j] := True;
          SetLength(Result[r], (l + 1));
          Result[r][l.Increase] := Self[j];
          SetLength(q, (s + 1));
          q[s.Increase] := j;
        end;
    end;
    Inc(r);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Clusterify>
  @action: Creates proximity-based clusters using Euclidean distance and the
           specified radius. Equivalent to the primary variant but uses the
           built-in Euclidean metric by default.
  @note: See the main overload for details regarding traversal, performance
         profile, and cluster generation semantics.
[==============================================================================}
function TPointArrayHelper.Clusterify(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Clusterify(radius, @Euclidean);
end;

{==============================================================================]
  <Clusterify>
  @action: Produces clusters by treating two points as neighbors when their
           coordinate differences fall within the specified horizontal and
           vertical radii. Clusters are formed as connected components under
           this axis-aligned proximity constraint.
  @note: Uses an index queue and a rectangular neighborhood test, identical in
         structure to the radius/distance-function variant. No sorting of the
         input array is performed; clusters are emitted in the order in which
         unvisited points are encountered. Complexity is O(N²) in the worst
         case due to exhaustive neighbor checks.
[==============================================================================}
function TPointArrayHelper.Clusterify(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, r: Integer;
  v: TBooleanArray;
  q: TIntegerArray;
  s, l, c: Integer;
  p: TPoint;
begin
  case Self.Size of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, Self.Size);
  SetLength(Result, Self.Size);
  r := 0;
  for i := 0 to High(Self) do
  begin
    if v[i] then
      Continue;
    SetLength(Result[r], 1);
    Result[r][0] := Self[i];
    l := 1;
    v[i] := True;
    SetLength(q, 1);
    q[0] := i;
    s := 1;
    while (s > 0) do
    begin
      c := q[s - 1];
      Dec(s);
      SetLength(q, s);
      p := Self[c];
      for j := 0 to High(Self) do
        if ((not v[j]) and (p.Within(Self[j], xRadius, yRadius))) then
        begin
          v[j] := True;
          SetLength(Result[r], (l + 1));
          Result[r][l.Increase] := Self[j];
          SetLength(q, (s + 1));
          q[s.Increase] := j;
        end;
    end;
    Inc(r);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Clusterize>
  @action: Splits TPointArray to groups by radius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Clusterize(const radius: Double; const distFunc: TDistance): T2DPointArray; overload; 
var
  m, p: TIntegerArray;
  r, l, i, j: Integer;
  function PFind(x: Integer): Integer;
  var
    s: Integer;
  begin
    Result := x;
    while (p[Result] <> Result) do
      Result := p[Result];
    while (p[x] <> x) do
    begin
      s := p[x];
      p[x] := Result;
      x := s;
    end;
  end;
  procedure PUnioned(a, b: Integer);
  var
    f, t: Integer;
  begin
    f := PFind(a);
    t := PFind(b);
    if (f <> t) then
      p[t] := f;
  end;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(p, l);
  for i := 0 to (l - 1) do
    p[i] := i;
  for i := 0 to (l - 1) do
    for j := (i + 1) to (l - 1) do
	  if Self[i].Within(Self[j], radius, distFunc) then
        PUnioned(i, j);
  SetLength(m, l);
  for i := 0 to (l - 1) do
    m[i] := -1;
  SetLength(Result, 0);
  for i := 0 to (l - 1) do
  begin
    r := PFind(i);
    if (m[r] = -1) then
    begin
      m[r] := System.Length(Result);
      SetLength(Result, (System.Length(Result) + 1));
      Result[m[r]] := [];
    end;
    Result[m[r]] := (Result[m[r]] + [Self[i]]);
  end;
end;

function TPointArrayHelper.Clusterize(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Clusterize(radius, @HypotEuclidean);
end;

{==============================================================================]
  <Clusterize>
  @action: Splits TPointArray to groups by xRadius and yRadius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Clusterize(const xRadius, yRadius: Integer): T2DPointArray; overload; 
var
  m, p: TIntegerArray;
  i, j, r, c: Integer;
  function PFind(x: Integer): Integer;
  var
    s: Integer;
  begin
    Result := x;
    while (p[Result] <> Result) do
      Result := p[Result];
    while (p[x] <> x) do
    begin
      s := p[x];
      p[x] := Result;
      x := s;
    end;
  end;
  procedure PUnioned(a, b: Integer);
  var
    f, t: Integer;
  begin
    f := PFind(a);
    t := PFind(b);
    if (f <> t) then
      p[t] := f;
  end;
begin
  SetLength(Result, 0);
  if Self.Empty then
    Exit;
  SetLength(p, Self.Size);
  for i := 0 to High(Self) do
    p[i] := i;
  for i := 0 to (High(Self) - 1) do
    for j := (i + 1) to High(Self) do
      if Self[i].Within(Self[j], xRadius, yRadius) then
        PUnioned(i, j);
  SetLength(m, Self.Size);
  for i := 0 to High(m) do
    m[i] := -1;
  c := 0;
  for i := 0 to High(Self) do
  begin
    r := PFind(i);
    if (m[r] = -1) then
    begin
      m[r] := c;
      SetLength(Result, (c + 1));
      SetLength(Result[c.Increase], 0);
    end;
    Result[m[r]] := (Result[m[r]] + [Self[i]]);
  end;
end;

{==============================================================================]
  <Grouped>
  @action: Partitions the points in the array into groups of connected points
           based on adjacency (4- or 8-connectivity). Each group is returned
           as a separate T2DPointArray within the result array.
  @note: The adjacency method is determined by the 'adjacency8' parameter:
         - True  => 8-connectivity (including diagonals)
         - False => 4-connectivity (orthogonal neighbors only)
         Returns a T2DPointArray where each element is a group of connected points.
         Uses a BFS (breadth-first search) algorithm internally to find the groups.
[==============================================================================}
function TPointArrayHelper.Grouped(const adjacency8: Boolean = True): T2DPointArray; overload;
var
  v: TBooleanArray;
  q: TIntegerArray;
  d: TPointArray;
  r: TRange;
  i, j, p, g, k, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(v, l);
  d := Point(0,0).Surrounding(adjacency8);
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    g := System.Length(Result);
    SetLength(Result, (g + 1));
    SetLength(q, l);
    r.Create(0, 0);
    q[r.stop.Increase] := i;
    v[i] := True;
    while (r.start < r.stop) do
    begin
      p := q[r.start.Increase];
      SetLength(Result[g], (Result[g].Size + 1));
      Result[g][High(Result[g])] := Self[p];
      for j := 0 to High(d) do
        for k := 0 to (l - 1) do
          if ((not v[k]) and (Self[k] = (Self[p] + d[j]))) then
          begin
            v[k] := True;
            q[r.stop.Increase] := k;
          end;
    end;
  end;
end;

{==============================================================================]
  <Groupify>
  @action: Partitions the points in the array into connected groups (clusters)
           based on adjacency. Two points are considered connected if they
           are neighbors according to 4- or 8-connectivity.
  @note: The adjacency method is determined by the 'adjacency8' parameter:
         - True  => 8-connectivity (including diagonals)
         - False => 4-connectivity (orthogonal neighbors only)
         Returns a T2DPointArray where each element is a group of connected points.
         Uses a union-find (disjoint-set) algorithm internally for efficiency.
[==============================================================================}
function TPointArrayHelper.Groupify(const adjacency8: Boolean = True): T2DPointArray; overload;
var
  p: TIntegerArray;
  i, j, k, l: Integer;
  d: TPointArray;
  c, n: Integer;
  r, m: TIntegerArray;
  function FindRoot(const x: Integer): Integer;
  begin
    if (p[x] = x) then
      Exit(x);
    p[x] := FindRoot(p[x]);
    Exit(p[x]);
  end;
  procedure Unioned(const x, y: Integer);
  var
    h, v: Integer;
  begin
    h := FindRoot(x);
    v := FindRoot(y);
    if (h <> v) then
      p[v] := h;
  end;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  p := Self.IDs;
  d := Point(0, 0).Surrounding(adjacency8);
  for i := 0 to (l - 1) do
    for j := 0 to High(d) do
    begin
      k := Self.Pos(Point((Self[i].X + d[j].X), (Self[i].Y + d[j].Y)));
      if (k <> -1) then
        Unioned(i, k);
    end;
  c := 0;
  SetLength(r, l);
  for i := 0 to (l - 1) do
  begin
    r[i] := FindRoot(i);
    if (r[i] = i) then
      Inc(c);
  end;
  SetLength(m, l);
  n := 0;
  for i := 0 to (l - 1) do
    if (r[i] = i) then
      m[i] := n.Increase
    else
      m[i] := m[r[i]];
  SetLength(Result, c);
  for i := 0 to (l - 1) do
  begin
    c := m[r[i]];
    SetLength(Result[c], (Result[c].Size + 1));
    Result[c][High(Result[c])] := Self[i];
  end;
end;

{==============================================================================]
  <Groups>
  @action: Partitions the points in the array into connected groups using
           an iterative depth-first search (DFS). Each group is returned as
           a TPointArray within the resulting T2DPointArray.
  @note: adjacency8 = True uses 8-connectivity (diagonals included),
         False uses 4-connectivity (orthogonal neighbors only).
         The function uses a manual stack to avoid recursion.
         Returns a T2DPointArray where each element represents a group of
         connected points.
[==============================================================================}
function TPointArrayHelper.Groups(const adjacency8: Boolean = True): T2DPointArray; overload;
var
  v: TBooleanArray;
  d: TPointArray;
  s: TIntegerArray;
  c, n, g, l, i, j, t: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(Result, 0);
  SetLength(v, l);
  d := Point(0,0).Surrounding(adjacency8);
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    g := System.Length(Result);
    SetLength(Result, (g + 1));
    SetLength(s, l);
    t := 0;
    s[t.Increase] := i;
    v[i] := True;
    while (t) > 0 do
    begin
      c := s[t.Decrement];
      SetLength(Result[g], (Result[g].Size + 1));
      Result[g][High(Result[g])] := Self[c];
      for j := 0 to High(d) do
        for n := 0 to (l - 1) do
          if ((not v[n]) and (Self[n] = (Self[c] + d[j]))) then
          begin
            v[n] := True;
            s[t.Increase] := n;
          end;
      end;
    end;
end;

{==============================================================================]
  <Grouping>
  @action: Partitions the points in the array into connected groups using a
           recursive depth-first search (DFS). Each group is returned as a 
           separate TPointArray within the resulting T2DPointArray.
  @note: The adjacency method is determined by the 'adjacency8' parameter:
         - True  => 8-connectivity (includes diagonals)
         - False => 4-connectivity (orthogonal neighbors only)
         Returns a T2DPointArray where each element represents a group of 
         connected points.
         Internally uses DFS to traverse and collect all points belonging
         to the same connected component.
[==============================================================================}
function TPointArrayHelper.Grouping(const adjacency8: Boolean = True): T2DPointArray; overload;
  procedure DFS(const arr: TPointArray; const index: Integer; const directions: TPointArray; var visited: TBooleanArray; var group: TPointArray);
  var
    i, j: Integer;
  begin
    visited[index] := True;
    SetLength(group, (group.Size + 1));
    group[High(group)] := arr[index];
    for i := 0 to High(directions) do
      for j := 0 to High(arr) do
        if ((not visited[j]) and (arr[j] = (arr[index] + directions[i]))) then
          DFS(arr, j, directions, visited, group);
  end;
var
  v: TBooleanArray;
  d: TPointArray;
  i, l: Integer;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(Result, 0);
  SetLength(v, l);
  d := Point(0,0).Surrounding(adjacency8);
  for i := 0 to (l - 1) do
    if not v[i] then
    begin
      SetLength(Result, (System.Length(Result) + 1));
      DFS(Self, i, d, v, Result[High(Result)]);
    end;
end;

{==============================================================================]
  <Segment>
  @action: Splits TPointArray to groups by radius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Segment(const radius: Double; const distFunc: TDistance): T2DPointArray; overload; 
var
  b, f, l, i, j, k, p, r, c: Integer;
  v: TBooleanArray;
  q: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(v, l);
  for i := 0 to (l - 1) do
    v[i] := False;
  SetLength(Result, l);
  r := 0;
  p := 0;
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    SetLength(q, l);
    f := 0;
    b := 0;
    q[b.Increase] := i;
    v[i] := True;
    c := 0;
    SetLength(Result[r], (l - p));
    while (f < b) do
    begin
      j := q[f.Increase];
      Result[r][c.Increase] := Self[j];
      for k := 0 to (l - 1) do
        if ((not v[k]) and Self[j].Within(Self[k], radius, distFunc)) then
        begin
          v[k] := True;
          q[b.Increase] := k;
        end;
    end;
    Inc(p, c);
    SetLength(Result[r.Increase], c);
  end;
  SetLength(Result, r);
end;

function TPointArrayHelper.Segment(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Segment(radius, @HypotEuclidean);
end;

{==============================================================================]
  <Segment>
  @action: Splits TPointArray to groups by xRadius and yRadius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Segment(const xRadius, yRadius: Integer): T2DPointArray; overload; 
var
  b, f, l, i, j, k, p, r, c: Integer;
  v: TBooleanArray;
  q: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(v, l);
  for i := 0 to (l - 1) do
    v[i] := False;
  SetLength(Result, l);
  r := 0;
  p := 0;
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    SetLength(q, l);
    f := 0;
    b := 0;
    q[b.Increase] := i;
    v[i] := True;
    c := 0;
    SetLength(Result[r], (l - p));
    while (f < b) do
    begin
      j := q[f.Increase];
      Result[r][c.Increase] := Self[j];
      for k := 0 to (l - 1) do
        if ((not v[k]) and Self[j].Within(Self[k], xRadius, yRadius)) then
        begin
          v[k] := True;
          q[b.Increase] := k;
        end;
    end;
    Inc(p, c);
    SetLength(Result[r.Increase], c);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Fragment>
  @action: Splits TPointArray to groups by radius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Fragment(const radius: Double; const distFunc: TDistance): T2DPointArray; overload; 
var
  h, l, i, j, k, r, p, c: Integer;
  v: TBooleanArray;
  s: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(v, l);
  for i := 0 to (l - 1) do
    v[i] := False;
  SetLength(Result, l);
  r := 0;
  p := 0;
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    SetLength(s, l);
    h := 0;
    s[h.Increase] := i;
    v[i] := True;
    c := 0;
    SetLength(Result[r], (l - p));
    while (h > 0) do
    begin
      j := s[h.Decrement];
      Result[r][c.Increase] := Self[j];
      for k := 0 to (l - 1) do
        if ((not v[k]) and Self[j].Within(Self[k], radius, distFunc)) then
        begin
          v[k] := True;
          s[h.Increase] := k;
        end;
    end;
    Inc(p, c);
    SetLength(Result[r.Increase], c);
  end;
  SetLength(Result, r);
end;

function TPointArrayHelper.Fragment(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Fragment(radius, @HypotEuclidean);
end;

{==============================================================================]
  <Fragment>
  @action: Splits TPointArray to groups by xRadius and yRadius.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Fragment(const xRadius, yRadius: Integer): T2DPointArray; overload; 
var
  h, l, i, j, k, r, p, c: Integer;
  v: TBooleanArray;
  s: TIntegerArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(v, l);
  for i := 0 to (l - 1) do
    v[i] := False;
  SetLength(Result, l);
  r := 0;
  p := 0;
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    SetLength(s, l);
    h := 0;
    s[h.Increase] := i;
    v[i] := True;
    c := 0;
    SetLength(Result[r], (l - p));
    while (h > 0) do
    begin
      j := s[h.Decrement];
      Result[r][c.Increase] := Self[j];
      for k := 0 to (l - 1) do
        if ((not v[k]) and Self[j].Within(Self[k], xRadius, yRadius)) then
        begin
          v[k] := True;
          s[h.Increase] := k;
        end;
    end;
    Inc(p, c);
    SetLength(Result[r.Increase], c);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <XClassify>
  @action: Classifies TPointArray to groups by X-value
  @note: None.
[==============================================================================}
function TPointArrayHelper.XClassify(const pSorted: Boolean = False): T2DPointArray; overload; 
var
  p: TPointArray;
begin
  if not pSorted then
    p := Self.QuickSorted(Self.Xs)
  else
    p := Self.Copy;
  Result := p.Classes(p.Xs);
end;

{==============================================================================]
  <YClassify>
  @action: Classifies TPointArray to groups by X-value
  @note: None.
[==============================================================================}
function TPointArrayHelper.YClassify(const pSorted: Boolean = False): T2DPointArray; overload; 
var
  p: TPointArray;
begin
  if not pSorted then
    p := Self.QuickSorted(Self.Ys)
  else
    p := Self.Copy;
  Result := p.Classes(p.Ys);
end;

{==============================================================================]
  <Axes>
  @action: Stores X-values and Y-values from TPointArray to X and Y TIntegerArrays.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Axes(var X, Y: TIntegerArray): Integer; overload; 
var
  sX, sY, dX, dY: Pointer;
  p, c: SizeInt;
  i: Integer;
begin
  Result := Self.Size;
  specialize SetSize<Integer>(X, Y, Result);
  if (Result = 0) then
    Exit;
  c := SizeOf(Integer);
  p := SizeOf(TPoint);
  sX := @Self[0].X;
  sY := Pointer(PByte(sX) + c);
  dX := @X[0];
  dY := @Y[0];
  for i := 0 to High(Self) do
  begin
    Move(sX^, dX^, c);
    Move(sY^, dY^, c);
    Inc(PByte(sX), p);
    Inc(PByte(sY), p);
    Inc(PByte(dX), c);
    Inc(PByte(dY), c);
  end;
end;

{==============================================================================]
  <Axed>
  @action: Stores X-values and Y-values from TPointArray to X and Y TIntegerArrays.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Axed: T2DIntegerArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, 2, Self.Size);
  for i := 0 to High(Self) do
  begin
    Result[0][i] := Self[i].X;
    Result[1][i] := Self[i].Y;
  end;
end;

{==============================================================================]
  <Axed>
  @action: Stores X-values and Y-values from TPointArray to X and Y TIntegerArrays.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Axed(var X, Y: TIntegerArray): Integer; overload; 
var
  i: Integer;
begin
  Result := Self.Size;
  specialize SetSize<Integer>(X, Y, Result);
  for i := 0 to High(Self) do
  begin
    X[i] := Self[i].X;
    Y[i] := Self[i].Y;
  end;
end;

{==============================================================================]
  <Reinit>
  @action: Clears all elements of the array by zero-filling the underlying memory,
           setting all TPoint elements to (0,0), while keeping the current length unchanged.
  @note: None.
[==============================================================================}
function TPointArrayHelper.Reinit: Integer; 
begin
  Result := Self.Size;
  if (Result > 0) then
    FillChar(Pointer(Self)^, (Result * SizeOf(TPoint)), 0);
end;

{==============================================================================]
  <SortByRow>
  @action: Sorts array Row-by-Row.
  @note: Returns Length().
[==============================================================================}
function TPointArrayHelper.SortByRow(const aAscending: Boolean = True): Integer; overload; 
var
  x, y, w, h, r, i: Integer;
  c: T2DIntegerArray;
  b: TBox;
begin
  Result := Self.Size;
  if (Result > 1) then
  begin
    r := 0;
    b := Self.Bounds(w, h);
    c := T2D.Create(0, w, h);
    for i := 0 to High(Self) do
      Inc(c[Self[i].X - b.X1][Self[i].Y - b.Y1]);
	case aAscending of
	  True:
      for y := 0 to (b.Y2 - b.Y1) do
        for x := 0 to (b.X2 - b.X1) do
        begin
          if (c[x][y] = 0) then
            Continue;
          for i := 0 to (c[x][y] - 1) do
            Self[r + i] := Point((x + b.X1), (y + b.Y1));
          r := (r + c[x][y]);
        end;
	  False:
      for y := (b.Y2 - b.Y1) downto 0 do
        for x := (b.X2 - b.X1) downto 0 do
        begin
          if (c[x][y] = 0) then
            Continue;
          for i := (c[x][y] - 1) downto 0 do
            Self[r + i] := Point((x + b.X1), (y + b.Y1));
          r := (r + c[x][y]);
        end;
	end;
    SetLength(c, 0);
  end;
end;

{==============================================================================]
  <SortByColumn>
  @action: Sorts array Column-by-Column.
  @note: Returns Length().
[==============================================================================}
function TPointArrayHelper.SortByColumn(const aAscending: Boolean = True): Integer; overload; 
var
  x, y, w, h, r, i: Integer;
  c: T2DIntegerArray;
  b: TBox;
begin
  Result := Self.Size;
  if (Result > 1) then
  begin
    r := 0;
    b := Self.Bounds(w, h);
    c := T2D.Create(0, w, h);
    for i := 0 to High(Self) do
      Inc(c[Self[i].X - b.X1][Self[i].Y - b.Y1]);
	case aAscending of
	  True:
      for x := 0 to (b.X2 - b.X1) do
        for y := 0 to (b.Y2 - b.Y1) do
          if (c[x][y] > 0) then
          begin
            for i := 0 to (c[x][y] - 1) do
              Self[r + i] := Point((x + b.X1), (y + b.Y1));
            r := (r + c[x][y]);
          end;
	  False:
      for x := (b.X2 - b.X1) downto 0 do
        for y := (b.Y2 - b.Y1) downto 0 do
          if (c[x][y] > 0) then
          begin
            for i := (c[x][y] - 1) downto 0 do
              Self[r + i] := Point((x + b.X1), (y + b.Y1));
            r := (r + c[x][y]);
          end;
    end;		  
    SetLength(c, 0);
  end;
end;

{==============================================================================]
  <SortedByIndex>
  @action: Returns array sorted by indexes in array bounding box.
  @note: None.
[==============================================================================}
function TPointArrayHelper.SortedByIndex(const aAscending: Boolean = True): TPointArray; overload; 
begin
  if Self.Empty then
    SetLength(Result, 0)
  else
    Result := Self.QuickSorted(Self.Bounds.IDs(Self), aAscending);
end;

{==============================================================================]
  <Attach>
  @action: Appends all points from the given array to the end of Self.
           Returns the new total length of the array after appending.
  @note:   Uses Move() for efficiency since TPoint is an unmanaged type.
           If the input array is empty, the function returns the current length
           of Self without modification.
[==============================================================================}
function TPointArrayHelper.Attach(const items: TPointArray): Integer; overload;
var
  l, i: Integer;
begin
  l := Self.Length;
  i := items.Size;
  if (i = 0) then
    Exit(l);
  Result := (l + i);
  SetLength(Self, Result);
  Move(items[0], Self[l], (i * SizeOf(TPoint)));
end;

{==============================================================================]
  <Embed>
  @action: Inserts the contents of another TPoint array into the current array
           at the specified index. Existing elements from that position onward
           are shifted to make room for the new items.
  @note: If the index exceeds the current length, the items are appended.
         Passing an empty array leaves the original array unchanged.
         The function returns the new total element count.
[==============================================================================}
function TPointArrayHelper.Embed(const items: TPointArray; const index: Integer = 2147483647): Integer; overload;
var
  s, l, p, t: Integer;
begin
  s := Self.Size;
  l := items.Length;
  if (l = 0) then
    Exit(s);
  p := EnsureRange(index, 0, s);
  t := (s - p);
  SetLength(Self, (s + l));
  if (t > 0) then
    Move(Self[p], Self[p + l], (t * SizeOf(TPoint)));
  Move(items[0], Self[p], (l * SizeOf(TPoint)));
  Result := Self.Size;
end;

{==============================================================================]
  <FrameLinks>
  @action: For each point in the array that lies within the given area, generates
           a “frame” around the point (a box of size determined by dist) and a
           vertical line from the point to the top of the box. Returns a new
           TPointArray containing all these border and line points.
  @note:   Uses the Attach helper to efficiently append points. The size of the
           resulting array depends on the borders of all valid points. Points
           outside the area are ignored.
[==============================================================================}
function TPointArrayHelper.FrameLinks(const dist: Integer; const area: TBox): TPointArray; overload;
var
  b: TBox;
  i: Integer;
begin
  SetLength(Result, 0);
  if Self.Empty then
    Exit;
  for i := 0 to High(Self) do
    if area.Contains(Self[i]) then
    begin
      b.Create(Max(area.X1, (Self[i].X - dist)), Max(area.Y1, (Self[i].Y - dist)), Min(area.X2, (Self[i].X + dist)), Min(area.Y2, (Self[i].Y + dist)));
      Result.Attach(b.Border);
      Result.Attach(Self[i].ToY(b.Y1 + 1));
    end;
end;

function TPointArrayHelper.FrameLinks(const dist: Integer = 1): TPointArray; overload;
begin
  Result := Self.FrameLinks(dist, Self.Bounds);
end;

{==============================================================================]
  <XVals>
  @action: Returns an array of all X coordinates from the point array,
           optionally sorted in ascending or descending order.
  @note: Uses TIntegerArray_BinaryAppend to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.XVals(const aAscending: Boolean = True): TIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    Result.BinaryAppend(Self[i].X, aAscending);
end;

{==============================================================================]
  <YVals>
  @action:  Returns an array of all Y coordinates from the point array,
            optionally sorted in ascending or descending order.
  @note:    Uses TIntegerArray_BinaryAppend to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.YVals(const aAscending: Boolean = True): TIntegerArray;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    Result.BinaryAppend(Self[i].Y, aAscending);
end;

{==============================================================================]
  <XArr>
  @action: Returns an array of all X coordinates from the point array,
           optionally sorted in ascending or descending order.
  @note: Uses Quicksorting to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.XArr(const aAscending: Boolean = True): TIntegerArray;
begin
  Result := Self.Xs.QuickSorted(aAscending);
end;

{==============================================================================]
  <YArr>
  @action: Returns an array of all Y coordinates from the point array,
           optionally sorted in ascending or descending order.
  @note: Uses Quicksorting to maintain the order efficiently.
[==============================================================================}
function TPointArrayHelper.YArr(const aAscending: Boolean = True): TIntegerArray;
begin
  Result := Self.Ys.QuickSorted(aAscending);
end;

{==============================================================================]
  <XAxis>
  @action: Extracts all X-coordinate values from the point array.
  @note: When rUnique = True, the resulting array is sorted and contains
         only unique X values (duplicates removed).
         When rUnique = False, all X values are included in order of appearance.
[==============================================================================}
function TPointArrayHelper.XAxis(const rUnique: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 0);
  case rUnique of
    True:
    for i := 0 to High(Self) do
      Result.BinaryGrow(Self[i].X);
    False:
    for i := 0 to High(Self) do
      Result.BinaryAppend(Self[i].X);
  end;
end;

{==============================================================================]
  <YAxis>
  @action: Extracts all Y-coordinate values from the point array.
  @note: When rUnique = True, the resulting array is sorted and contains
         only unique Y values (duplicates removed).
         When rUnique = False, all Y values are included in order of appearance.
[==============================================================================}
function TPointArrayHelper.YAxis(const rUnique: Boolean = True): TIntegerArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 0);
  case rUnique of
    True:
    for i := 0 to High(Self) do
      Result.BinaryGrow(Self[i].Y);
    False:
    for i := 0 to High(Self) do
      Result.BinaryAppend(Self[i].Y);
  end;
end;

{==============================================================================]
  <X2D>
  @action: Groups all X-coordinates by their corresponding Y-coordinate.
  @note: Returns 2D array of X values where Result[i] contains all X's for Y = yArr[i].
   - The output parameter yArr receives the sorted list of unique Y values.
   - If no points exist, Result = [].
   - If only one Y value exists, Result = [yArr].
   - When xOrder = True (default), X values are inserted in sorted order
     using BinaryAppend.
   - The xAscending flag determines the sorting direction when xOrder = True.
     (True = ascending, False = descending)
   - When xOrder = False, X values are appended in input order using Supply
     (unsorted grouping).
[==============================================================================}
function TPointArrayHelper.X2D(var yArr: TIntegerArray; const xOrder: Boolean = True; const xAscending: Boolean = True): T2DIntegerArray; overload;
var
  i, l: Integer;
begin
  yArr := Self.YAxis;
  l := yArr.Length;
  case l of
    0: Exit([]);
    1: Exit([yArr]);
  end;
  SetLength(Result, l);
  case xOrder of 
    True:
    for i := 0 to High(Self) do
      Result[yArr.BinarySearch(Self[i].Y)].BinaryAppend(Self[i].X, xAscending);
	False:
	for i := 0 to High(Self) do
      Result[yArr.BinarySearch(Self[i].Y)].Supply(Self[i].X);
  end;
end;

{==============================================================================]
  <Y2D>
  @action: Groups all Y-coordinates by their corresponding X-coordinate.
  @note: Returns 2D array of Y values where Result[i] contains all Y's for X = xArr[i].
   - The output parameter xArr receives the sorted list of unique X values.
   - If no points exist, Result = [].
   - If only one X value exists, Result = [xArr].
   - When yOrder = True (default), Y values are inserted in sorted order
     using BinaryAppend.
   - The yAscending flag determines the sorting direction when yOrder = True.
     (True = ascending, False = descending)
   - When yOrder = False, Y values are appended in input order using Supply
     (unsorted grouping).
[==============================================================================}
function TPointArrayHelper.Y2D(var xArr: TIntegerArray; const yOrder: Boolean = True; const yAscending: Boolean = True): T2DIntegerArray; overload;
var
  i, l: Integer;
begin
  xArr := Self.XAxis;
  l := xArr.Length;
  case l of
    0: Exit([]);
    1: Exit([xArr]);
  end;
  SetLength(Result, l);
  case yOrder of
    True:
    for i := 0 to High(Self) do
      Result[xArr.BinarySearch(Self[i].X)].BinaryAppend(Self[i].Y, yAscending);
    False:
    for i := 0 to High(Self) do
      Result[xArr.BinarySearch(Self[i].X)].Supply(Self[i].Y);
  end;
end;

{==============================================================================]
  <Blobs>
  @action: Groups the points in the array into contiguous spatial clusters ("blobs")
           based on the specified xRadius and yRadius. Each blob is a TPointArray
           containing points that are all within the proximity ranges of each other.
  @note: Uses a breadth-first search style traversal combined with binary range
         searches on sorted X/Y arrays for efficiency. The result is a T2DPointArray,
         where each element represents a blob. Empty or single-element arrays are
         handled specially. This method may allocate intermediate arrays.
[==============================================================================}
function TPointArrayHelper.Blobs(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, p, g, t, z, l: Integer;
  h, v, r, c: TRange;
  x: T2DIntegerArray;
  y: TIntegerArray;
  q: TPointArray;
  a, n: TPoint;
  m: TBooleanArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  x := Self.X2D(y);
  SetLength(Result, l);
  SetLength(m, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if m[i] then
      Continue;
    SetLength(q, 1);
    q[0] := Self[i];
    m[i] := True;
    t := 0;
    while (t < q.Size) do
    begin
      a := q[t.Increase];
      SetLength(Result[g], (Result[g].Size + 1));
      Result[g][High(Result[g])] := a;
      h.Create((a.X - xRadius), (a.X + xRadius));
      v.Create((a.Y - yRadius), (a.Y + yRadius));
      r := y.BinaryRange(v);
      if r.Employs(-1) then
        Continue;
      for j := r.start to r.stop do
      begin
        c := x[j].BinaryRange(h);
        if c.Employs(-1) then
          Continue;
        for p := c.start to c.stop do
        begin
          n.Create(x[j][p], y[j]);
          for z := 0 to l - 1 do
            if (Self[z] = n) then
              Break;
          if ((z < l) and (not m[z])) then
          begin
            m[z] := True;
            SetLength(q, (q.Size + 1));
            q[High(q)] := n;
          end;
        end;
      end;
    end;
    if (Result[g].Size > 0) then
      Inc(g);
  end;
  SetLength(Result, g);
end;

function TPointArrayHelper.Blobs(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  i, j, p, g, t, z, l, d: Integer;
  h, v, r, c: TRange;
  x: T2DIntegerArray;
  y: TIntegerArray;
  q: TPointArray;
  a, n: TPoint;
  m: TBooleanArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  d := Trunc(radius);
  x := Self.X2D(y);
  SetLength(Result, l);
  SetLength(m, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if m[i] then
      Continue;
    SetLength(q, 1);
    q[0] := Self[i];
    m[i] := True;
    t := 0;
    while (t < q.Size) do
    begin
      a := q[t.Increase];
      SetLength(Result[g], (Result[g].Size + 1));
      Result[g][High(Result[g])] := a;
      h.Create((a.X - d), (a.X + d));
      v.Create((a.Y - d), (a.Y + d));
      r := y.BinaryRange(v);
      if r.Employs(-1) then
        Continue;
      for j := r.start to r.stop do
      begin
        c := x[j].BinaryRange(h);
        if c.Employs(-1) then
	      Continue;
        for p := c.start to c.stop do
        begin
          n.Create(x[j][p], y[j]);
          for z := 0 to (l - 1) do
            if (Self[z] = n) then
	          Break;
          if ((z < l) and (not m[z]) and a.Within(n, radius, distFunc)) then
          begin
            m[z] := True;
            SetLength(q, (q.Size + 1));
            q[High(q)] := n;
          end;
        end;
      end;
    end;
    if (Result[g].Size > 0) then
      Inc(g);
  end;
  SetLength(Result, g);
end;

function TPointArrayHelper.Blobs(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Blobs(radius, @Euclidean);
end;

{==============================================================================]
  <Blobify>
  @action: Similar to Blobs, but optimized with a pre-allocated queue to reduce
           repeated memory allocations. Groups the points into spatially connected
           blobs based on xRadius and yRadius.
  @note: Uses a breadth-first traversal combined with binary range searches on
         sorted X/Y arrays. Internal queue is pre-sized for better performance.
         Returns a T2DPointArray of blobs. Handles empty or single-element arrays
         correctly. Consider using this version when processing large point sets
         for efficiency.
[==============================================================================}
function TPointArrayHelper.Blobify(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, j, p, g, z, l: Integer;
  h, v, r, c, k: TRange;
  x: T2DIntegerArray;
  y: TIntegerArray;
  q: TPointArray;
  a, n: TPoint;
  m: TBooleanArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  x := Self.X2D(y);
  SetLength(Result, l);
  SetLength(m, l);
  SetLength(q, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if m[i] then
      Continue;
    k.Create(0, 1);
    q[0] := Self[i];
    m[i] := True;
    SetLength(Result[g], 0);
    while (k.start < k.stop) do
    begin
      a := q[k.start.Increase];
      SetLength(Result[g], (Result[g].Size + 1));
      Result[g][High(Result[g])] := a;
      h.Create((a.X - xRadius), (a.X + xRadius));
      v.Create((a.Y - yRadius), (a.Y + yRadius));
      r := y.BinaryRange(v);
      if r.Employs(-1) then
        Continue;
      for j := r.start to r.stop do
      begin
        c := x[j].BinaryRange(h);
        if c.Employs(-1) then
          Continue;
        for p := c.start to c.stop do
        begin
          n.Create(x[j][p], y[j]);
          for z := 0 to (l - 1) do
            if (Self[z] = n) then
              Break;
          if ((z < l) and (not m[z])) then
          begin
            m[z] := True;
            q[k.stop.Increase] := n;
          end;
        end;
      end;
    end;
    if (Result[g].Size > 0) then
      Inc(g);
  end;
  SetLength(Result, g);
end;

function TPointArrayHelper.Blobify(const radius: Double; const distFunc: TDistance): T2DPointArray; overload;
var
  i, j, p, g, z, l, d: Integer;
  h, v, r, c, k: TRange;
  x: T2DIntegerArray;
  y: TIntegerArray;
  q: TPointArray;
  a, n: TPoint;
  m: TBooleanArray;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  d := Trunc(radius);
  x := Self.X2D(y);
  SetLength(Result, l);
  SetLength(m, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if m[i] then
      Continue;
    SetLength(q, (l * 2));
    q[0] := Self[i];
    m[i] := True;
    k.Create(0, 1);
    SetLength(Result[g], 0);
    while (k.start < k.stop) do
    begin
      a := q[k.start.Increase];
      SetLength(Result[g], (Result[g].Size + 1));
      Result[g][High(Result[g])] := a;
      h.Create((a.X - d), (a.X + d));
      v.Create((a.Y - d), (a.Y + d));
      r := y.BinaryRange(v);
      if r.Employs(-1) then
        Continue;
      for j := r.start to r.stop do
      begin
        c := x[j].BinaryRange(h);
        if c.Employs(-1) then
		  Continue;
        for p := c.start to c.stop do
        begin
          n.Create(x[j][p], y[j]);
          for z := 0 to (l - 1) do
            if (Self[z] = n) then
              Break;
          if ((z < l) and (not m[z]) and a.Within(n, radius, distFunc)) then
          begin
            m[z] := True;
            if (k.stop >= q.Size) then
              SetLength(q, (q.Size * 2));
            q[k.stop.Increase] := n;
          end;
        end;
      end;
    end;
    if (Result[g].Size > 0) then
      Inc(g);
  end;
  SetLength(Result, g);
end;

function TPointArrayHelper.Blobify(const radius: Double = 1.0): T2DPointArray; overload;
begin
  Result := Self.Blobify(radius, @Euclidean);
end;

{==============================================================================]
 <YTo2D>
 @action: Converts the point array into a 2D integer array of Y-coordinates grouped by unique X-coordinates.
          Each sub-array contains the Y values of points sharing the same X.
          Also returns a 2D array of original indices (selfIDs) aligned with the grouped and sorted Y values.
 @note: The Y values in each group are sorted in ascending order.
[==============================================================================}
function TPointArrayHelper.YTo2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  l, i, j, k, c, p, s, m: Integer;
begin
  l := Self.Length;
  SetLength(xArr, 0);
  SetLength(selfIDs, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  xArr := Self.XAxis;
  c := xArr.Size;
  SetLength(Result, c);
  SetLength(selfIDs, c);
  for i := 0 to (c - 1) do
  begin
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].X = xArr[i]) then
        Inc(k);
    SetLength(Result[i], k);
    SetLength(selfIDs[i], k);
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].X = xArr[i]) then
      begin
        Result[i][k] := Self[j].Y;
        selfIDs[i][k.Increase] := j;
      end;
    for j := 1 to (k - 1) do
    begin
      p := Result[i][j];
      s := selfIDs[i][j];
      m := (j - 1);
      while ((m >= 0) and (Result[i][m] > p)) do
      begin
        Result[i][m + 1] := Result[i][m];
        selfIDs[i][m + 1] := selfIDs[i][m];
        Dec(m);	
      end;
      Result[i][m + 1] := p;
      selfIDs[i][m + 1] := s;
    end;
  end;
end;

{==============================================================================]
 <YTo2D>
 @action: Converts the point array into a 2D integer array of Y-coordinates grouped by unique X-coordinates.
          Each sub-array contains the Y values of points sharing the same X.
 @note: Original order of points is preserved; no selfIDs tracking and no sorting.
[==============================================================================}
function TPointArrayHelper.YTo2D(var xArr: TIntegerArray): T2DIntegerArray; overload;
var
  l, i, j, k, c: Integer;
begin
  l := Self.Length;
  SetLength(xArr, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  xArr := Self.XAxis;
  c := xArr.Size;
  SetLength(Result, c);
  for i := 0 to (c - 1) do
  begin
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].X = xArr[i]) then
        Inc(k);
    SetLength(Result[i], k);
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].X = xArr[i]) then
        Result[i][k.Increase] := Self[j].Y;
  end;
end;

{==============================================================================]
 <XTo2D>
 @action: Converts the point array into a 2D integer array of X-coordinates grouped by unique Y-coordinates.
          Each sub-array contains the X values of points sharing the same Y.
          Also returns a 2D array of original indices (selfIDs) aligned with the grouped and sorted X values.
 @note: The X values in each group are sorted in ascending order.
[==============================================================================}
function TPointArrayHelper.XTo2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  l, i, j, k, c, p, s, m: Integer;
begin
  l := Self.Length;
  SetLength(yArr, 0);
  SetLength(selfIDs, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  yArr := Self.YAxis;
  c := yArr.Size;
  SetLength(Result, c);
  SetLength(selfIDs, c);
  for i := 0 to (c - 1) do
  begin
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].Y = yArr[i]) then
        Inc(k);
    SetLength(Result[i], k);
    SetLength(selfIDs[i], k);
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].Y = yArr[i]) then
      begin
        Result[i][k] := Self[j].X;
        selfIDs[i][k.Increase] := j;
      end;
    for j := 1 to (k - 1) do
    begin
      p := Result[i][j];
      s := selfIDs[i][j];
      m := (j - 1);
      while ((m >= 0) and (Result[i][m] > p)) do
      begin
        Result[i][m + 1] := Result[i][m];
        selfIDs[i][m + 1] := selfIDs[i][m];
        Dec(m);
      end;
      Result[i][m + 1] := p;
      selfIDs[i][m + 1] := s;
    end;
  end;
end;

{==============================================================================]
 <XTo2D>
 @action: Converts the point array into a 2D integer array of X-coordinates grouped by unique Y-coordinates.
          Each sub-array contains the X values of points sharing the same Y.
 @note: Original order of points is preserved; no selfIDs tracking and no sorting.
[==============================================================================}
function TPointArrayHelper.XTo2D(var yArr: TIntegerArray): T2DIntegerArray; overload;
var
  l, i, j, k, c: Integer;
begin
  l := Self.Length;
  SetLength(yArr, 0);
  SetLength(Result, 0);
  if (l = 0) then
    Exit;
  yArr := Self.YAxis;
  c := yArr.Size;
  SetLength(Result, c);
  for i := 0 to (c - 1) do
  begin
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].Y = yArr[i]) then
        Inc(k);
    SetLength(Result[i], k);
    k := 0;
    for j := 0 to (l - 1) do
      if (Self[j].Y = yArr[i]) then
        Result[i][k.Increase] := Self[j].X;
  end;
end;

{==============================================================================]
  <YAs2D>
  @action: Groups Y-coordinates by unique X values and sorts each Y-group ascending.
           Also returns 2D array of self-indices (original point indices).
  @note: Each subarray of Result corresponds to one unique X in xArr.
         Result[i][*] = sorted Y values for X = xArr[i].
         selfIDs[i][*] = original indices of those points.
[==============================================================================}
function TPointArrayHelper.YAs2D(var xArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  i, j, k: Integer;
  g, d: specialize TDictionary<Integer, specialize TList<Integer>>;
  y, p: specialize TList<Integer>;
begin
  SetLength(Result, 0);
  SetLength(xArr, 0);
  SetLength(selfIDs, 0);
  if Self.Empty then
    Exit;
  g := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  d := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not g.TryGetValue(Self[i].X, y) then
      begin
        y := specialize TList<Integer>.Create;
        p := specialize TList<Integer>.Create;
        g.Add(Self[i].X, y);
        d.Add(Self[i].X, p);
      end else
        p := d[Self[i].X];
      y.Add(Self[i].Y);
      p.Add(i);
    end;
    SetLength(xArr, g.Count);
    SetLength(Result, g.Count);
    SetLength(selfIDs, g.Count);
    i := 0;
    for k in g.Keys do
    begin
      xArr[i] := k;
      y := g[k];
      p := d[k];
      y.Sort;
      SetLength(Result[i], y.Count);
      SetLength(selfIDs[i], y.Count);
      for j := 0 to (y.Count - 1) do
      begin
        Result[i][j] := y[j];
        selfIDs[i][j] := p[j];
      end;
      Inc(i);
    end;
  finally
    for y in g.Values do
      y.Free;
    for p in d.Values do
      p.Free;
    g.Free;
    d.Free;
  end;
end;

{==============================================================================]
  <YAs2D>
  @action: Groups Y-coordinates by unique X values (no sorting or index tracking).
  @note: Each subarray of Result corresponds to one unique X in xArr.
         Order of Y values matches original point order.
[==============================================================================}
function TPointArrayHelper.YAs2D(var xArr: TIntegerArray): T2DIntegerArray; overload;
var
  i, k: Integer;
  g: specialize TDictionary<Integer, specialize TList<Integer>>;
  y: specialize TList<Integer>;
begin
  SetLength(Result, 0);
  SetLength(xArr, 0);
  if Self.Empty then
    Exit;
  g := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not g.TryGetValue(Self[i].X, y) then
      begin
        y := specialize TList<Integer>.Create;
        g.Add(Self[i].X, y);
      end;
      y.Add(Self[i].Y);
    end;
    SetLength(xArr, g.Count);
    SetLength(Result, g.Count);
    i := 0;
    for k in g.Keys do
    begin
      xArr[i] := k;
      y := g[k];
      Result[i.Increase] := y.ToArray;
    end;
  finally
    for y in g.Values do
      y.Free;
    g.Free;
  end;
end;

{==============================================================================]
  <XAs2D>
  @action: Groups X-coordinates by unique Y values and sorts each X-group ascending.
           Also returns 2D array of self-indices (original point indices).
  @note: Each subarray of Result corresponds to one unique Y in yArr.
         Result[i][*] = sorted X values for Y = yArr[i].
         selfIDs[i][*] = original indices of those points.
[==============================================================================}
function TPointArrayHelper.XAs2D(var yArr: TIntegerArray; var selfIDs: T2DIntegerArray): T2DIntegerArray; overload;
var
  i, j, k: Integer;
  g: specialize TDictionary<Integer, specialize TList<Integer>>;
  d: specialize TDictionary<Integer, specialize TList<Integer>>;
  x, p: specialize TList<Integer>;
begin
  SetLength(Result, 0);
  SetLength(yArr, 0);
  SetLength(selfIDs, 0);
  if Self.Empty then
    Exit;
  g := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  d := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not g.TryGetValue(Self[i].Y, x) then
      begin
        x := specialize TList<Integer>.Create;
        p := specialize TList<Integer>.Create;
        g.Add(Self[i].Y, x);
        d.Add(Self[i].Y, p);
      end else
        p := d[Self[i].Y];
      x.Add(Self[i].X);
      p.Add(i);
    end;
    SetLength(yArr, g.Count);
    SetLength(Result, g.Count);
    SetLength(selfIDs, g.Count);
    i := 0;
    for k in g.Keys do
    begin
      yArr[i] := k;
      x := g[k];
      p := d[k];
      x.Sort;
      SetLength(Result[i], x.Count);
      SetLength(selfIDs[i], x.Count);
      for j := 0 to (x.Count - 1) do
      begin
        Result[i][j] := x[j];
        selfIDs[i][j] := p[j];
      end;
      Inc(i);
    end;
  finally
    for x in g.Values do
      x.Free;
    for p in d.Values do
      p.Free;
    g.Free;
    d.Free;
  end;
end;

{==============================================================================]
  <XAs2D>
  @action: Groups X-coordinates by unique Y values (no sorting or index tracking).
  @note: Each subarray of Result corresponds to one unique Y in yArr.
         Order of X values matches original point order.
[==============================================================================}
function TPointArrayHelper.XAs2D(var yArr: TIntegerArray): T2DIntegerArray; overload;
var
  i, k: Integer;
  g: specialize TDictionary<Integer, specialize TList<Integer>>;
  x: specialize TList<Integer>;
begin
  SetLength(Result, 0);
  SetLength(yArr, 0);
  if Self.Empty then
    Exit;
  g := specialize TDictionary<Integer, specialize TList<Integer>>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not g.TryGetValue(Self[i].Y, x) then
      begin
        x := specialize TList<Integer>.Create;
        g.Add(Self[i].Y, x);
      end;
      x.Add(Self[i].X);
    end;
    SetLength(yArr, g.Count);
    SetLength(Result, g.Count);
    i := 0;
    for k in g.Keys do
    begin
      yArr[i] := k;
      x := g[k];
      Result[i.Increase] := x.ToArray;
    end;
  finally
    for x in g.Values do
      x.Free;
    g.Free;
  end;
end;

{==============================================================================]
  <DBSCAN>
  @action: Performs density-based clustering on a TPointArray using a fixed
           radius and custom distance function.
  @params:
    radius   - The maximum distance between points to be considered neighbors.
    minPts   - Minimum number of points required to form a dense region (core point).
    distFunc - Function used to compute distance between two TPoints.
  @returns: T2DPointArray where each sub-array represents a cluster.
  @note: Points not belonging to any cluster are ignored (treated as noise).
[==============================================================================}
function TPointArrayHelper.DBSCAN(const radius: Double; const minPts: Integer; const distFunc: TDistance): T2DPointArray; overload;
const
  NOISE = -1;
  UNVISITED = 0;
var
  c, i, s: Integer;
  l: TIntegerArray;
  d: TDistance;
  function RegionQuery(const index: Integer): TIntegerArray;
  var
    i: Integer;
  begin
    SetLength(Result, 0);
    for i := 0 to (s - 1) do
      if ((i <> index) and Self[index].Within(Self[i], radius, d)) then
        Result.Supply(i);
  end;
  procedure ExpandCluster(const index: Integer);
  var
    r, n: TIntegerArray;
    i, j: Integer;
  begin
    r := RegionQuery(index);
    if (r.Size < minPts) then
    begin
      l[index] := NOISE;
      Exit;
    end;
    for i := 0 to High(r) do
      l[r[i]] := (c + 1);
    i := -1;
    while (i.Increment < r.Size) do
    begin
      n := RegionQuery(r[i]);
      if (n.Size >= minPts) then
      for j := 0 to High(n) do
        if l[n[j]] in [UNVISITED, NOISE] then
        begin
          if (l[n[j]] = UNVISITED) then
            r.Supply(n[j]);
          l[n[j]] := (c + 1);
        end;
    end;
  end;
begin
  d := Distance(distFunc);
  s := Self.Size;
  case s of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(l, s);
  for i := 0 to (s - 1) do
    l[i] := UNVISITED;
  c := 0;
  for i := 0 to (s - 1) do
  begin
    if (l[i] <> UNVISITED) then
      Continue;
    ExpandCluster(i);
    if (l[i] <> NOISE) then
      Inc(c);
  end;
  SetLength(Result, c);
  for i := 0 to (s - 1) do
    if (l[i] > 0) then
      Result[l[i] - 1].Supply(Self[i]);
end;

function TPointArrayHelper.DBSCAN(const radius: Double = 1.0; const minPts: Integer = 2; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
begin
  Result := Self.DBSCAN(radius, minPts, Distance(metric));
end;

{==============================================================================]
  <DBSCAN>
  @action: Performs density-based clustering using separate X and Y radii,
           allowing anisotropic neighborhoods.
  @params:
    xRadius - Maximum horizontal distance to consider points neighbors.
    yRadius - Maximum vertical distance to consider points neighbors.
    minPts  - Minimum number of points to form a cluster.
  @returns: T2DPointArray where each sub-array represents a cluster.
  @note: Useful for clustering pixel-based data or TPAs where horizontal and
         vertical spacing differs. Rectangular neighborhood used for efficiency.
[==============================================================================}
function TPointArrayHelper.DBSCAN(const xRadius, yRadius: Integer; const minPts: Integer): T2DPointArray; overload;
const
  NOISE = -1;
  UNVISITED = 0;
var
  c, i, s: Integer;
  l: TIntegerArray;
  function RegionQuery(const index: Integer): TIntegerArray;
  var
    i: Integer;
  begin
    SetLength(Result, 0);
    for i := 0 to (s - 1) do
      if ((i <> index) and Self[index].Within(Self[i], xRadius, yRadius)) then
        Result.Supply(i);
  end;
  procedure ExpandCluster(const index: Integer);
  var
    r, n: TIntegerArray;
    i, j: Integer;
  begin
    r := RegionQuery(index);
    if (r.Size < minPts) then
    begin
      l[index] := NOISE;
      Exit;
    end;
    for i := 0 to High(r) do
      l[r[i]] := (c + 1);
    i := -1;
    while (i.Increment < r.Size) do
    begin
      n := RegionQuery(r[i]);
      if (n.Size >= minPts) then
      for j := 0 to High(n) do
        if l[n[j]] in [UNVISITED, NOISE] then
        begin
          if (l[n[j]] = UNVISITED) then
            r.Supply(n[j]);
          l[n[j]] := (c + 1);
        end;
    end;
  end;
begin
  s := Self.Size;
  case s of
    0: Exit([]);
    1: Exit([Self]);
  end;
  SetLength(l, s);
  for i := 0 to (s - 1) do
    l[i] := UNVISITED;
  c := 0;
  for i := 0 to (s - 1) do
  begin
    if (l[i] <> UNVISITED) then
      Continue;
    ExpandCluster(i);
    if (l[i] <> NOISE) then
      Inc(c);
  end;
  SetLength(Result, c);
  for i := 0 to (s - 1) do
    if (l[i] > 0) then
      Result[l[i] - 1].Supply(Self[i]);
end;

{==============================================================================]
  <Nearby>
  @action: Returns all points from this array that lie within a given radius
           of a specified target point, using the provided distance function.
  @note: If no distance function is provided, a default (Euclidean) distance
         function is used. This checks distance from each point in Self to
         the target point.
[==============================================================================}
function TPointArrayHelper.Nearby(const target: TPoint; const radius: Double; const distFunc: TDistance): TPointArray; overload;
var
  i: Integer;
  f: TDistance;
begin
  f := Distance(distFunc);
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    if Self[i].Within(target, radius, f) then
      Result.Supply(Self[i]);
end;

function TPointArrayHelper.Nearby(const target: TPoint; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): TPointArray; overload;
begin
  Result := Self.Nearby(target, radius, Distance(metric));
end;

{==============================================================================]
  <Nearby>
  @action: Returns all points from this array that lie within a rectangular
           area centered on a specified target point, defined by horizontal
           and vertical radii.
  @note: Checks each point in Self for inclusion using separate X and Y
         tolerances instead of a circular distance metric.
[==============================================================================}
function TPointArrayHelper.Nearby(const target: TPoint; const xRadius, yRadius: Integer): TPointArray; overload;
var
  i: Integer;
begin
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    if Self[i].Within(target, xRadius, yRadius) then
      Result.Supply(Self[i]);
end;

{==============================================================================]
  <Nearby>
  @action: Returns all points from this array that lie within a given radius
           of any point in the specified array of target points, using the
           provided distance function.
  @note: If no distance function is provided, a default (Euclidean) distance
         function is used. Each point in Self is included if it is within
         the radius of at least one target point.
[==============================================================================}
function TPointArrayHelper.Nearby(const targets: TPointArray; const radius: Double; const distFunc: TDistance): TPointArray; overload;
var
  i, j: Integer;
  f: TDistance;
begin
  if targets.Empty then
    Exit([]);
  f := Distance(distFunc);
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    for j := 0 to High(targets) do
      if Self[i].Within(targets[j], radius, f) then
      begin
        Result.Supply(Self[i]);
	    Break;
      end;
end;

function TPointArrayHelper.Nearby(const targets: TPointArray; const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): TPointArray; overload;
begin
  Result := Self.Nearby(targets, radius, Distance(metric));
end;

{==============================================================================]
  <Nearby>
  @action: Returns all points from this array that lie within rectangular
           areas around any point in the specified array of target points,
           defined by horizontal and vertical radii.
  @note: Each point in Self is included if it lies within the rectangular
         bounds of at least one target point. Useful for grid or axis-aligned
         proximity checks.
[==============================================================================}
function TPointArrayHelper.Nearby(const targets: TPointArray; const xRadius, yRadius: Integer): TPointArray; overload;
var
  i, j: Integer;
begin
  if targets.Empty then
    Exit([]);
  SetLength(Result, 0);
  for i := 0 to High(Self) do
    for j := 0 to High(targets) do
      if Self[i].Within(targets[j], xRadius, yRadius) then
      begin
        Result.Supply(Self[i]);
	    Break;
      end;
end;

{==============================================================================]
  <CorePointsMax>
  @action: Returns all points that have **no more than `maximumNeighbours`** 
           within the specified rectangular or metric radius.
  @note: Used to detect *sparse* points or "edge" points in a spatial 
         distribution. Early-breaks when neighbour count exceeds the limit.
[==============================================================================}
function TPointArrayHelper.CorePointsMax(const maximumNeighbours: Integer; const xRadius, yRadius: Integer): TPointArray; overload;
var
  i, j, l, r, c: Integer;
  x: T2DIntegerArray;
  y: TIntegerArray;
  b, s: TRange;
begin
  l := Self.Length;
  if ((maximumNeighbours < 0) or (l = 0)) then
    Exit([]);
  SetLength(Result, l);
  r := 0;
  x := Self.X2D(y);
  for i := 0 to High(Self) do
  begin
    c := 0;
    b := y.BinarySpan(TRange.Construct((Self[i].Y - yRadius), (Self[i].Y + yRadius)));
    for j := b.start to b.stop do
    begin
      s := x[j].BinarySpan(TRange.Construct((Self[i].X - xRadius), (Self[i].X + xRadius)));
      if ((not s.Employs(-1)) and (c.Increment(s.Size) > maximumNeighbours)) then
        Break;
    end;
    if (c <= maximumNeighbours) then
      Result[r.Increase] := Self[i];
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <CorePointsMax>
  @action: Returns all points that have **no more than `maximumNeighbours`** 
           within the specified rectangular or metric radius.
  @note: Used to detect *sparse* points or "edge" points in a spatial 
         distribution. Early-breaks when neighbour count exceeds the limit.
[==============================================================================}
function TPointArrayHelper.CorePointsMax(const maximumNeighbours: Integer; const radius: Double; const metric: TMetrics = dmEuclidean): TPointArray; overload;
var
  i, j, k, l, r, c, z: Integer;
  x: T2DIntegerArray;
  q, y: TIntegerArray;
  b, s: TRange;
  p: TPoint;
begin
  l := Self.Length;
  if ((maximumNeighbours < 0) or (l = 0)) then
    Exit([]);
  SetLength(Result, l);
  r := 0;
  x := Self.X2D(y);
  z := Ceil(radius);
  for i := 0 to High(Self) do
  begin
    c := 0;
    p := Self[i];
    b := y.BinarySpan(TRange.Construct((p.Y - z), (p.Y + z)));
    for j := b.start to b.stop do
    begin
      q := x[j];
      s := q.BinarySpan(TRange.Construct((p.X - z), (p.X + z)));
      if s.Employs(-1) then
        Continue;
      for k := s.start to s.stop do
        if (p.Within(Point(q[k], y[j]), radius, metric) and (c.Increment > maximumNeighbours)) then
          Break;
      if (c > maximumNeighbours) then
        Break;
    end;
    if (c <= maximumNeighbours) then
      Result[r.Increase] := p;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <CorePointsMin>
  @action: Returns all points that have **at least `minimumNeighbours`** 
           within the specified rectangular or metric radius.
  @note: Used to detect *core* points in a density-based clustering context 
         (e.g. DBSCAN). Early-breaks when minimum is reached.
[==============================================================================}
function TPointArrayHelper.CorePointsMin(const minimumNeighbours: Integer; const xRadius, yRadius: Integer): TPointArray; overload;
var
  i, j, l, r, c: Integer;
  x: T2DIntegerArray;
  y: TIntegerArray;
  b, s: TRange;
begin
  l := Self.Length;
  if ((minimumNeighbours > l) or (l = 0)) then
    Exit([]);
  SetLength(Result, l);
  r := 0;
  x := Self.X2D(y);
  for i := 0 to High(Self) do
  begin
    c := 0;
    b := y.BinarySpan(TRange.Construct((Self[i].Y - yRadius), (Self[i].Y + yRadius)));
    for j := b.start to b.stop do
    begin
      s := x[j].BinarySpan(TRange.Construct((Self[i].X - xRadius), (Self[i].X + xRadius)));
      if ((not s.Employs(-1)) and (c.Increment(s.Size) >= minimumNeighbours)) then
      begin
        Result[r.Increase] := Self[i];
        Break;
      end;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <CorePointsMin>
  @action: Returns all points that have **at least `minimumNeighbours`** 
           within the specified rectangular or metric radius.
  @note: Used to detect *core* points in a density-based clustering context 
         (e.g. DBSCAN). Early-breaks when minimum is reached.
[==============================================================================}
function TPointArrayHelper.CorePointsMin(const minimumNeighbours: Integer; const radius: Double; const metric: TMetrics = dmEuclidean): TPointArray; overload;
var
  i, j, k, l, r, c, z: Integer;
  x: T2DIntegerArray;
  q, y: TIntegerArray;
  b, s: TRange;
  p: TPoint;
begin
  l := Self.Length;
  if ((minimumNeighbours > l) or (l = 0)) then
    Exit([]);
  SetLength(Result, l);
  r := 0;
  x := Self.X2D(y);
  z := Ceil(radius);
  for i := 0 to High(Self) do
  begin
    c := 0;
    p := Self[i];
    b := y.BinarySpan(TRange.Construct((p.Y - z), (p.Y + z)));
    for j := b.start to b.stop do
    begin
      q := x[j];
      s := q.BinarySpan(TRange.Construct((p.X - z), (p.X + z)));
      if s.Employs(-1) then
        Continue;
      for k := s.start to s.stop do
        if (p.Within(Point(q[k], y[j]), radius, metric) and (c.Increment >= minimumNeighbours)) then
        begin
          Result[r.Increase] := p;
          Break;
        end;
      if (c >= minimumNeighbours) then
        Break;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <CorePoints>
  @action: Returns all points whose number of neighbours lies **within the 
           inclusive range `allowedNeighbours`** for the given rectangular or 
           metric radius.
  @note: Generalized version of `CorePointsMin` and `CorePointsMax`. 
         Supports both integer radii (grid-based) and floating-point radii 
         with custom distance metrics. Automatically ignores points outside 
         the defined neighbour range.
[==============================================================================}
function TPointArrayHelper.CorePoints(const allowedNeighbours: TRange; const radius: Double; const metric: TMetrics = dmEuclidean): TPointArray; overload;
var
  i, j, k, l, r, c, z: Integer;
  x: T2DIntegerArray;
  q, y: TIntegerArray;
  b, s, n: TRange;
  p: TPoint;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  n := allowedNeighbours.Normalize;
  r := 0;
  if (n.start < l) then
  begin
    SetLength(Result, l);
    x := Self.X2D(y);
    z := Ceil(radius);
    for i := 0 to High(Self) do
    begin
      c := 0;
      p := Self[i];
      b := y.BinarySpan(TRange.Construct((p.Y - z), (p.Y + z)));
      for j := b.start to b.stop do
      begin
        q := x[j];
        s := q.BinarySpan(TRange.Construct((p.X - z), (p.X + z)));
        if s.Employs(-1) then
          Continue;
        for k := s.start to s.stop do
          if (p.Within(Point(q[k], y[j]), radius, metric) and (c.Increment > n.stop)) then
            Break;
        if (c > n.stop) then
          Break;
      end;
      if InRange(c, n.start, n.stop) then
        Result[r.Increase] := p;
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <CorePoints>
  @action: Returns all points whose number of neighbours lies **within the 
           inclusive range `allowedNeighbours`** for the given rectangular or 
           metric radius.
  @note: Generalized version of `CorePointsMin` and `CorePointsMax`. 
         Supports both integer radii (grid-based) and floating-point radii 
         with custom distance metrics. Automatically ignores points outside 
         the defined neighbour range.
[==============================================================================}
function TPointArrayHelper.CorePoints(const allowedNeighbours: TRange; const xRadius, yRadius: Integer): TPointArray; overload;
var
  i, j, l, r, c: Integer;
  x: T2DIntegerArray;
  y: TIntegerArray;
  b, n, s: TRange;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  n := allowedNeighbours.Normalize;
  r := 0;
  if (n.start < l) then
  begin
    SetLength(Result, l);
    x := Self.X2D(y);
    for i := 0 to High(Self) do
    begin
      c := 0;
      b := y.BinarySpan(TRange.Construct((Self[i].Y - yRadius), (Self[i].Y + yRadius)));
      for j := b.start to b.stop do
      begin
        s := x[j].BinarySpan(TRange.Construct((Self[i].X - xRadius), (Self[i].X + xRadius)));
        if ((not s.Employs(-1)) and (c.Increment(s.Size) > n.stop)) then
          Break;
      end;
      if InRange(c, n.start, n.stop) then
        Result[r.Increase] := Self[i];
    end;
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <Binify>
  @action: Groups points into clusters using axis-aligned neighborhood radii.
           Uses a binary-search-optimized spatial indexing approach to
           efficiently merge points within (xRadius, yRadius) bounds.
  @note: Overload for integer-based clustering; works on 2D points.
         Clustering is performed using union-find to merge overlapping neighborhoods.
[==============================================================================}
function TPointArrayHelper.Binify(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  n, i, c, r: Integer;
  h, z: T2DIntegerArray;
  v, q: TIntegerArray;
  m, l, p: TIntegerArray;
  x, y: TRange;
  function FindRoot(const index: Integer): Integer;
  begin
    if (q[index] = index) then
      Exit(index);
    q[index] := FindRoot(q[index]);
    Result := q[index];
  end;
  procedure Unioned(const a, b: Integer);
  var
    i, j: Integer;
  begin
    i := FindRoot(a);
    j := FindRoot(b);
    if (i = j) then
      Exit;
    q[j] := i;
  end;
begin
  n := Self.Length;
  if (n = 0) then
    Exit([]);
  h := Self.XTo2D(v, z);
  SetLength(q, n);
  for i := 0 to (n - 1) do
    q[i] := i;
  for i := 0 to (n - 1) do
  begin
    y := v.BinaryRange(TRange.Construct((Self[i].Y - yRadius), (Self[i].Y + yRadius)));
    if not y.Employs(-1) then
    for r := y.start to y.stop do
    begin
      x := h[r].BinaryRange(TRange.Construct((Self[i].X - xRadius), (Self[i].X + xRadius)));
      if not x.Employs(-1) then
        for c := x.start to x.stop do
          Unioned(i, z[r][c]);
    end;
  end;
  SetLength(m, n);
  for i := 0 to (n - 1) do
    m[i] := -1;
  c := 0;
  for i := 0 to (n - 1) do
  begin
    r := FindRoot(i);
    if (m[r] = -1) then
      m[r] := c.Increase;
  end;
  SetLength(l, c);
  for i := 0 to (n - 1) do
    Inc(l[m[FindRoot(i)]]);
  SetLength(Result, c);
  for i := 0 to (c - 1) do
    SetLength(Result[i], l[i]);
  SetLength(p, c);
  for i := 0 to (n - 1) do
  begin
    r := m[FindRoot(i)];
    Result[r][p[r].Increase] := Self[i];
  end;
end;

{==============================================================================]
  <Binify>
  @action: Groups points into clusters using a distance threshold and a specified metric.
           Uses binary-search-optimized spatial indexing and union-find to efficiently
           merge points within the given radius according to the metric.
  @note: Overload for floating-point / metric-aware clustering. 
         The metric can be Euclidean, Manhattan, or any user-defined TMetrics.
         Efficient for large point sets due to spatial partitioning and union-find.
[==============================================================================}
function TPointArrayHelper.Binify(const radius: Double; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
var
  n, i, c, r, k, d: Integer;
  h, z: T2DIntegerArray;
  v, q, m, l, p: TIntegerArray;
  x, y: TRange;
  procedure InitUnionFind;
  var
    j: Integer;
  begin
    SetLength(q, n);
    for j := 0 to (n - 1) do
      q[j] := j;
  end;
  function FindRoot(const index: Integer): Integer;
  begin
    if (q[index] = index) then
      Exit(index);
    q[index] := FindRoot(q[index]);
    Result := q[index];
  end;
  procedure Unioned(const a, b: Integer);
  var
    i, j: Integer;
  begin
    i := FindRoot(a);
    j := FindRoot(b);
    if (i <> j) then
      q[j] := i;
  end;
begin
  n := Self.Length;
  if (n = 0) then
    Exit([]);
  d := Ceil(radius);
  h := Self.XTo2D(v, z);
  InitUnionFind;
  for i := 0 to (n - 1) do
  begin
    y := v.BinaryRange(TRange.Construct((Self[i].Y - d), (Self[i].Y + d)));
    if not y.Employs(-1) then
    for r := y.start to y.stop do
    begin
      x := h[r].BinaryRange(TRange.Construct((Self[i].X - d), (Self[i].X + d)));
      if not x.Employs(-1) then
      for k := x.start to x.stop do
        if Self[i].Within(Self[z[r][k]], radius, metric) then
          Unioned(i, z[r][k]);
    end;
  end;
  SetLength(m, n);
  for i := 0 to (n - 1) do
    m[i] := -1;
  c := 0;
  for i := 0 to (n - 1) do
  begin
    r := FindRoot(i);
    if (m[r] = -1) then
      m[r] := c.Increase;
  end;
  SetLength(l, c);
  for i := 0 to (n - 1) do
    Inc(l[m[FindRoot(i)]]);
  SetLength(Result, c);
  for i := 0 to (c - 1) do
    SetLength(Result[i], l[i]);
  SetLength(p, c);
  for i := 0 to (n - 1) do
  begin
    r := m[FindRoot(i)];
    Result[r][p[r].Increase] := Self[i];
  end;
end;

{==============================================================================]
  <Binified>
  @action: Performs spatial clustering of points using separate integer radii
           for X and Y axes. Points that are within xRadius horizontally and
           yRadius vertically are grouped into the same cluster.
  @note: Uses binary-search arrays (h and v) for fast neighbor lookup. BFS-style
         propagation ensures that all connected points are included in the cluster.
         Deterministic and works entirely with integer distances.
[==============================================================================}
function TPointArrayHelper.Binified(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  l, i, j, r, c, a, n: Integer;
  h, z: T2DIntegerArray;
  v, p, q: TIntegerArray;
  x, y, s: TRange;
begin
  a := Self.Length;
  if (a = 0) then
    Exit([]);
  h := Self.XTo2D(v, z);
  SetLength(p, a);
  for i := 0 to (a - 1) do
    p[i] := -1;
  SetLength(Result, 0);
  SetLength(Result, a);
  l := 0;
  for i := 0 to (a - 1) do
  begin
    if (p[i] <> -1) then
      Continue;
    SetLength(Result[l], 0);
    SetLength(q, a);
    s.Create(0, 0);
    q[s.start.Increase] := i;
    p[i] := System.Length(Result);
    while (s.stop < s.start) do
    begin
      j := q[s.stop.Increase];
      SetLength(Result[l], (Result[l].Size + 1));
      Result[l][High(Result[l])] := Self[j];
      y := v.BinaryRange(TRange.Construct((Self[j].Y - yRadius), (Self[j].Y + yRadius)));
      if not y.Employs(-1) then
      for r := y.start to y.stop do
      begin
        x := h[r].BinaryRange(TRange.Construct((Self[j].X - xRadius), (Self[j].X + xRadius)));
        if not x.Employs(-1) then
        for c := x.start to x.stop do
        begin
          n := z[r][c];
          if (p[n] = -1) then
          begin
            p[n] := System.Length(Result);
            q[s.start.Increase] := n;
          end;
        end;
      end;
    end;
    Inc(l);
  end;
end;

{==============================================================================]
  <Binified>
  @action: Performs spatial clustering of points using a floating-point radius
           and a distance metric. Points within the specified radius according
           to the metric are grouped into the same cluster.
  @note: Uses binary-search arrays (h and v) for fast neighbor lookup. BFS-style
         propagation ensures transitive connectivity. Deterministic and metric-aware.
         The integer value d = Ceil(radius) is used for approximate bounding during
         binary search. Suitable for Euclidean, Manhattan, or custom distance metrics.
[==============================================================================}
function TPointArrayHelper.Binified(const radius: Double; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
var
  l, i, j, r, c, a, n, d: Integer;
  h, z: T2DIntegerArray;
  v, p, q: TIntegerArray;
  x, y, s: TRange;
begin
  a := Self.Size;
  if (a = 0) then
    Exit([]);
  d := Ceil(radius);
  h := Self.XTo2D(v, z);
  SetLength(p, a);
  for i := 0 to (a - 1) do
    p[i] := -1;
  SetLength(Result, 0);
  SetLength(Result, a);
  l := 0;
  for i := 0 to (a - 1) do
  begin
    if (p[i] <> -1) then
      Continue;
    SetLength(Result[l], 0);
    SetLength(q, a);
    s.Create(0, 0);
    q[s.start.Increase] := i;
    p[i] := System.Length(Result);
    while (s.stop < s.start) do
    begin
      j := q[s.stop.Increase];
      SetLength(Result[l], (Result[l].Size + 1));
      Result[l][High(Result[l])] := Self[j];
      y := v.BinaryRange(TRange.Construct((Self[j].Y - d), (Self[j].Y + d)));
      if not y.Employs(-1) then
      for r := y.start to y.stop do
      begin
        x := h[r].BinaryRange(TRange.Construct((Self[j].X - d), (Self[j].X + d)));
        if not x.Employs(-1) then
        for c := x.start to x.stop do
        begin
          n := z[r][c];
          if ((p[n] = -1) and Self[j].Within(Self[n], radius, metric)) then
          begin
            p[n] := System.Length(Result);
            q[s.start.Increase] := n;
          end;
        end;
      end;
    end;
    Inc(l);
  end;
end;

{==============================================================================]
  <Bins>
  @action: Cluster points into bins (clusters) using a floating-point radius and
           a distance metric. For each point, candidate neighbors are found via
           binary-range lookups on precomputed X/Y index arrays (h and v). Pairs
           within the radius (according to Metric) are unioned using a
           disjoint-set (union–find) structure; final clusters are produced by
           enumerating disjoint-set roots.
  @note:  Uses d := Ceil(radius) as an integer search bound to limit the
          binary-range queries; the precise inclusion test is performed with
          pt.Within(Self[i], Self[j], radius, metric). Implementation uses
          path compression and union-by-size for near-constant amortized
          union/find cost. Complexity dominated by neighbor lookups (≈ O(n log n)
          for spatial indexing) and O(n) memory for helper arrays. Deterministic
          and suitable for large point sets.
[==============================================================================}
function TPointArrayHelper.Bins(const radius: Double; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
var
  i, r, c, n, d, g: Integer;
  v, p, s, m, k, t: TIntegerArray;
  h, z: T2DIntegerArray;
  x, y: TRange;
  function FindRoot(i: Integer): Integer;
  begin
    if (p[i] <> i) then
      p[i] := FindRoot(p[i]);
    Result := p[i];
  end;
  procedure Unioned(i, j: Integer);
  var
    a, b: TPoint;
  begin
    a := Point(FindRoot(i), FindRoot(j));
    if (a.X = a.Y) then
      Exit;
    b := IfThen((s[a.X] < s[a.Y]), a, a.Reflected);
    p[b.X] := b.Y;
    Inc(s[b.Y], s[b.X]);
  end;
begin
  n := Self.Size;
  if (n = 0) then
    Exit([]);
  d := Ceil(radius);
  h := Self.XTo2D(v, z);
  SetLength(p, n);
  SetLength(s, n);
  for i := 0 to (n - 1) do
  begin
    p[i] := i;
    s[i] := 1;
  end;
  for i := 0 to (n - 1) do
  begin
    y := v.BinaryRange(TRange.Construct((Self[i].Y - d), (Self[i].Y + d)));
    if not y.Employs(-1) then
    for r := y.start to y.stop do
    begin
      x := h[r].BinaryRange(TRange.Construct((Self[i].X - d), (Self[i].X + d)));
      if not x.Employs(-1) then
      for c := x.start to x.stop do
        if Self[i].Within(Self[z[r][c]], radius, metric) then
          Unioned(i, z[r][c]);
    end;
  end;
  SetLength(m, n);
  for i := 0 to (n - 1) do
    m[i] := -1;
  g := 0;
  for i := 0 to (n - 1) do
  begin
    r := FindRoot(i);
    if (m[r] = -1) then
      m[r] := g.Increase;
  end;
  SetLength(k, g);
  for i := 0 to (n - 1) do
    Inc(k[m[FindRoot(i)]]);
  SetLength(Result, g);
  for i := 0 to (g - 1) do
    SetLength(Result[i], k[i]);
  SetLength(t, g);
  for i := 0 to (n - 1) do
  begin
    r := m[FindRoot(i)];
    Result[r][t[r].Increase] := Self[i];
  end;
end;

{==============================================================================]
  <Bins>
  @action: Cluster points into bins using separate axis-aligned radii (xRadius,
           yRadius). Candidate neighbors are located with binary-range queries on
           the precomputed X/Y index arrays (h and v). Pairs whose X and Y
           separations satisfy the rectangular neighborhood check are merged
           with a disjoint-set (union–find) structure; final clusters are
           collected from the union–find roots.
  @note:  This overload performs axis-aligned (rectangular) neighborhood checks
          and therefore does not use a distance metric. It uses binary-range
          indexing to avoid O(n²) pairwise checks and union-by-size + path
          compression for efficient merging. Complexity is dominated by the
          binary-range searches; memory is O(n). Use this overload when you
          want fast, axis-aligned binning instead of metric (circular) grouping.
[==============================================================================}
function TPointArrayHelper.Bins(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  i, r, c, n, g: Integer;
  p, s, m, k, t: TIntegerArray;
  h, z: T2DIntegerArray;
  v: TIntegerArray;
  x, y: TRange;
  function FindRoot(i: Integer): Integer;
  begin
    if (p[i] <> i) then
      p[i] := FindRoot(p[i]);
    Result := p[i];
  end;
  procedure Unioned(i, j: Integer);
  var
    a, b: TPoint;
  begin
    a := Point(FindRoot(i), FindRoot(j));
    if (a.X = a.Y) then
      Exit;
    b := IfThen((s[a.X] < s[a.Y]), a, a.Reflected);
    p[b.X] := b.Y;
    Inc(s[b.Y], s[b.X]);
  end;
begin
  n := Self.Size;
  if (n = 0) then
    Exit([]);
  h := Self.XTo2D(v, z);
  SetLength(p, n);
  SetLength(s, n);
  for i := 0 to (n - 1) do
  begin
    p[i] := i;
    s[i] := 1;
  end;
  for i := 0 to (n - 1) do
  begin
    y := v.BinaryRange(TRange.Construct((Self[i].Y - yRadius), (Self[i].Y + yRadius)));
    if not y.Employs(-1) then
    for r := y.start to y.stop do
    begin
      x := h[r].BinaryRange(TRange.Construct((Self[i].X - xRadius), (Self[i].X + xRadius)));
      if not x.Employs(-1) then
      for c := x.start to x.stop do
        if Self[i].Within(Self[z[r][c]], xRadius, yRadius) then
          Unioned(i, z[r][c]);
    end;
  end;
  SetLength(m, n);
  for i := 0 to (n - 1) do
    m[i] := -1;
  g := 0;
  for i := 0 to (n - 1) do
  begin
    r := FindRoot(i);
    if (m[r] = -1) then
      m[r] := g.Increase;
  end;
  SetLength(k, g);
  for i := 0 to (n - 1) do
    Inc(k[m[FindRoot(i)]]);
  SetLength(Result, g);
  for i := 0 to (g - 1) do
    SetLength(Result[i], k[i]);
  SetLength(t, g);
  for i := 0 to (n - 1) do
  begin
    r := m[FindRoot(i)];
    Result[r][t[r].Increase] := Self[i];
  end;
end;

{==============================================================================]
  <XBuckets>
  @action: Groups the points in the array into buckets (columns) based on their X-coordinate.
           Each bucket contains all points whose X-value falls within the range
           [BucketIndex * bWidth .. (BucketIndex+1) * bWidth - 1].
  @note: Returns a 2D array (T2DPointArray) where each element is a bucket (array of points).
         The default bucket width is 1. Use a larger value to group points into wider columns.
[==============================================================================}
function TPointArrayHelper.XBuckets(const bWidth: Integer = 1): T2DPointArray;
var
  i, m: Integer;
begin
  m := 0;
  for i := 0 to High(Self) do
    m := Max(m, (Self[i].X div bWidth));
  SetLength(Result, (m + 1));
  for i := 0 to High(Self) do
    Result[Self[i].X div bWidth].Supply(Self[i]);
end;

{==============================================================================]
  <YBuckets>
  @action: Groups the points in the array into buckets (rows) based on their Y-coordinate.
           Each bucket contains all points whose Y-value falls within the range
           [BucketIndex * bHeight .. (BucketIndex+1) * bHeight - 1].
  @note: Returns a 2D array (T2DPointArray) where each element is a bucket (array of points).
         The default bucket height is 1. Use a larger value to group points into taller rows.
[==============================================================================}
function TPointArrayHelper.YBuckets(const bHeight: Integer = 1): T2DPointArray;
var
  i, m: Integer;
begin
  m := 0;
  for i := 0 to High(Self) do
    m := Max(m, (Self[i].Y div bHeight));
  SetLength(Result, (m + 1));
  for i := 0 to High(Self) do
    Result[Self[i].Y div bHeight].Supply(Self[i]);
end;

{==============================================================================]
  <Buckets>
  @action: Divides the TPointArray into a rectangular grid of boxes of size bWidth x bHeight.
           Returns a T2DPointArray where each bucket contains all points falling
           into that box. The buckets are stored as a flattened 1D array:
           bucketIndex = col + row * numCols.
           Empty buckets are removed at the end.
  @note: - Computes the bounds of the points automatically (Self.Bounds).
         - Supports multiple points per bucket.
         - Uses arr.Supply to append points to each bucket.
         - Returns only non-empty buckets for convenience.
[==============================================================================}
function TPointArrayHelper.Buckets(const bWidth, bHeight: Integer): T2DPointArray; overload;
var
  i, h, v: Integer;
  b: TBox;
begin
  if Self.Empty then
    Exit([]);
  b := Self.Bounds;
  h := (((b.X2 - b.X1) div bWidth) + 1);
  v := (((b.Y2 - b.Y1) div bHeight) + 1);
  SetLength(Result, (h * v));
  for i := 0 to High(Self) do
    Result[((Self[i].X - b.X1) div bWidth) + (((Self[i].Y - b.Y1) div bHeight) * h)].Supply(Self[i]);
  Result.Squeeze;
end;

{==============================================================================]
  <Buckets>
  @action: Divides the TPointArray into a square grid of boxes of size bSize x bSize.
           Internally calls the same algorithm as the rectangular version.
  @note: - bSize defines both width and height of the grid cells.
         - Empty buckets are removed at the end.
[==============================================================================}
function TPointArrayHelper.Buckets(const bSize: Integer = 1): T2DPointArray; overload;
var
  i, h, v: Integer;
  b: TBox;
begin
  if Self.Empty then
    Exit([]);
  b := Self.Bounds;
  h := (((b.X2 - b.X1) div bSize) + 1);
  v := (((b.Y2 - b.Y1) div bSize) + 1);
  SetLength(Result, (h * v));
  for i := 0 to High(Self) do
    Result[((Self[i].X - b.X1) div bSize) + (((Self[i].Y - b.Y1) div bSize) * h)].Supply(Self[i]);
  Result.Squeeze;
end;

{==============================================================================]
  <Bucketed>
  @action: Splits the point array into a 2D grid of buckets, each containing points
           that fall within a specific rectangular region of the bounding box.
  @note: Each bucket’s dimensions are defined by (bWidth, bHeight). Empty buckets
         are removed using Squeeze. Returns an empty array if input or bounds are invalid.
[==============================================================================}
function TPointArrayHelper.Bucketed(const bWidth, bHeight: Integer): T2DPointArray; overload;
var
  i, w, h, x, y: Integer;
  b: TBox;
begin
  if (Self.Empty or (bWidth < 1) or (bHeight < 1)) then
    Exit([]);
  b := Self.Bounds(w, h);
  if ((w < 1) or (h < 1)) then
    Exit([]);
  y := (((h + bHeight) - 1) div bHeight);
  x := (((w + bWidth) - 1) div bWidth);
  SetLength(Result, 0);
  SetLength(Result, (y * x));
  for i := 0 to High(Self) do
    Result[Integer((Self[i].Y - b.Y1) div bHeight).Clamp(0, (y - 1)) + (Integer((Self[i].X - b.X1) div bWidth).Clamp(0, (x - 1)) * y)].Supply(Self[i]);
  Result.Squeeze;
end;

{==============================================================================]
  <Bucketed>
  @action: Creates a 2D grid of buckets using a uniform bucket size for both width and height.
  @note: Equivalent to calling Bucketed(bSize, bSize). Returns an empty array if input or size is invalid.
[==============================================================================}
function TPointArrayHelper.Bucketed(const bSize: Integer = 1): T2DPointArray; overload;
begin
  Result := Self.Bucketed(bSize, bSize);
end;

{==============================================================================]
  <Boxify>
  @action: Splits the current point array into a grid of rectangular cells 
           (boxes) of the specified width and height, returning a 2D array 
           of points grouped by their corresponding box.
  @note: Each box represents a bounded sub-region of the point array’s 
         overall bounding box. Boxes are generated in row-major order, 
         and may be smaller along the right or bottom edges if the total 
         width/height is not divisible by the box size. Empty boxes 
         return as empty point arrays.
[==============================================================================}
function TPointArrayHelper.Boxify(const bWidth, bHeight: Integer): T2DPointArray; overload;
var
  i, j, r, c, w, h, x, y, z, p: Integer;
  a, b: TBox;
  m: T2DBooleanArray;
begin
  if (Self.Empty or (bWidth < 1) or (bHeight < 1)) then
    Exit([]);
  b := Self.Bounds(w, h);
  m := T2D.Create(False, h, w);
  for i := 0 to High(Self) do
    m[Self[i].Y - b.Y1][Self[i].X - b.X1] := True;
  SetLength(Result, 0);
  r := Ceil(h / bHeight);
  c := Ceil(w / bWidth);
  SetLength(Result, (r * c));
  for i := 0 to (r - 1) do
    for j := 0 to (c - 1) do
    begin
      a := TBox.Construct((b.X1 + (j * bWidth)), (b.Y1 + (i * bHeight)), ((b.X1 + (j * bWidth)) + bWidth), ((b.Y1 + (i * bHeight)) + bHeight)).Clamp(b);
      z := 0;
      p := (i + (j * r));
      SetLength(Result[p], a.Area);
      for y := a.Y1 to a.Y2 do
        for x := a.X1 to a.X2 do
          if m[(y - b.Y1)][(x - b.X1)] then
            Result[p][z.Increase] := Point(x, y);
      SetLength(Result[p], z);
    end;
end;

{==============================================================================]
  <Boxify>
  @action: Splits the current point array into spatial groups using a uniform 
           box size (bSize). Each group contains points that fall within a 
           Chebyshev distance of bSize from the box's origin point.
  @note: Creates a grid of square boxes based on the specified size, 
         using the Chebyshev metric to determine point inclusion. 
         Effectively partitions the bounding area into square regions 
         and assigns points to their nearest box region. 
         Useful for coarse spatial grouping or uniform grid segmentation 
         of point data.
[==============================================================================}
function TPointArrayHelper.Boxify(const bSize: Integer = 1): T2DPointArray; overload;
var
  i, j, r, d, c, w, h, x, y, z, p: Integer;
  a, b: TBox;
  m: T2DBooleanArray;
  g: TPoint;
begin
  if (Self.Empty or (bSize < 1)) then
    Exit([]);
  d := Ceil(bSize);
  b := Self.Bounds(w, h);
  m := T2D.Create(False, h, w);
  for i := 0 to High(Self) do
    m[Self[i].Y - b.Y1][Self[i].X - b.X1] := True;
  SetLength(Result, 0);
  r := Ceil(h / bSize);
  c := Ceil(w / bSize);
  SetLength(Result, (r * c));
  for i := 0 to (r - 1) do
    for j := 0 to (c - 1) do
    begin
      a := TBox.Construct((b.X1 + (j * d)), (b.Y1 + (i * d)), (b.X1 + (j * d)) + d, (b.Y1 + (i * d)) + d).Clamp(b);
      g := Point(a.X1, a.Y1);
      z := 0;
      p := (i + (j * r));
      SetLength(Result[p], a.Area);
      for y := a.Y1 to a.Y2 do
        for x := a.X1 to a.X2 do
          if (m[(y - b.Y1)][(x - b.X1)] and (g.Within(Point(x, y), bSize, dmChebyshev))) then
            Result[p][z.Increase] := Point(x, y);
      SetLength(Result[p], z);
    end;
end;

{==============================================================================]
  <Boxified>
  @action: Groups the points of the current array into a grid of equally sized 
           square boxes of side length bSize, returning a 2D array where each 
           subarray contains the points belonging to its corresponding box.
  @note: Uses direct indexing (no grid scanning) to compute each point’s 
         target box based on its position relative to the bounding box. 
         Boxes are arranged in row-major order. 
         Empty boxes are automatically trimmed by Result.Squeeze. 
         This method is faster and more memory-efficient than Boxify 
         for uniformly sized square grids.
[==============================================================================}
function TPointArrayHelper.Boxified(const bSize: Integer = 1): T2DPointArray; overload;
var
  i, r, c, w, h: Integer;
  b: TBox;
begin
  if (Self.Empty or (bSize < 1)) then
    Exit([]);
  b := Self.Bounds(w, h);
  r := Ceil(h / bSize);
  c := Ceil(w / bSize);
  SetLength(Result, (r * c));
  for i := 0 to High(Self) do
    Result[(((Self[i].Y - b.Y1) div bSize) + (((Self[i].X - b.X1) div bSize) * r))].Supply(Self[i]);
  Result.Squeeze;
end;

{==============================================================================]
  <Boxified>
  @action: Groups the points of the current array into a grid of rectangular 
           boxes with dimensions bWidth × bHeight, returning a 2D array 
           where each element contains the points that fall within that box.
  @note:   Computes each point’s box position directly using integer division 
           based on its relative coordinates. Boxes are arranged in row-major 
           order (rows first, then columns). 
           The Result.Squeeze call removes any empty boxes from the final output. 
           This method is the most efficient rectangular variant of Boxify.
[==============================================================================}
function TPointArrayHelper.Boxified(const bWidth, bHeight: Integer): T2DPointArray; overload;
var
  i, r, c, w, h: Integer;
  b: TBox;
begin
  if (Self.Empty or (bWidth < 1) or (bHeight < 1)) then
    Exit([]);
  b := Self.Bounds(w, h);
  r := Ceil(h / bHeight);
  c := Ceil(w / bWidth);
  SetLength(Result, (r * c));
  for i := 0 to High(Self) do
    Result[(((Self[i].Y - b.Y1) div bHeight) + (((Self[i].X - b.X1) div bWidth) * r))].Supply(Self[i]);
  Result.Squeeze;
end;

{==============================================================================]
  <BinBox>
  @action: Groups all points in the array into a grid of rectangular boxes of
           size bWidth × bHeight. Uses a precomputed 2D X-index and binary
           search for fast assignment.
  @note: Boxes are arranged in row-major order: row + column * totalRows.
         Only points within the bounds of each box are included. Efficient
         for large and sparse point sets.
[==============================================================================}
function TPointArrayHelper.BinBox(const bWidth, bHeight: Integer): T2DPointArray; overload;
var
  i, j, r, c, p, k, l: Integer;
  a, b: TBox;
  h, z: T2DIntegerArray;
  v: TIntegerArray;
  x, y: TRange;
begin
  if (Self.Empty or (bWidth < 1) or (bHeight < 1)) then
    Exit([]);
  b := Self.Bounds;
  r := Ceil(b.Height / bHeight);
  c := Ceil(b.Width / bWidth);
  SetLength(Result, 0);
  SetLength(Result, (r * c));
  h := Self.XTo2D(v, z);
  for j := 0 to (c - 1) do
    for i := 0 to (r - 1) do
    begin
      p := (i + (j * r));
      a.X1 := (b.X1 + (j * bWidth));
      a.X2 := (a.X1 + (bWidth - 1));
      a.Y1 := (b.Y1 + (i * bHeight));
      a.Y2 := (a.Y1 + (bHeight - 1));
      y := v.BinaryRange(TRange.Construct(a.Y1, a.Y2));
      if not y.Employs(-1) then
      for k := y.start to y.stop do
      begin
        x := h[k].BinaryRange(TRange.Construct(a.X1, a.X2));
        if not x.Employs(-1) then
        for l := x.start to x.stop do
          Result[p].Supply(Self[z[k][l]]);
      end;
    end;
end;

{==============================================================================]
  <BinBox>
  @action: Convenience overload for square boxes. Groups points into boxes of
           size bSize × bSize by calling BinBox(bSize, bSize).
  @note: Calls the rectangular BinBox internally. Useful for uniform grids.
[==============================================================================}
function TPointArrayHelper.BinBox(const bSize: Integer = 1): T2DPointArray; overload;
begin
  Result := Self.BinBox(bSize, bSize);
end;

{==============================================================================]
  <BinaryFloodFill>
  @action:
    Performs a breadth-first flood fill (BFS) on the point array, grouping all
    points that lie within the specified radius (using the selected distance
    metric) into connected components.
  @note:
    • Uses a dynamically resizing queue to perform BFS traversal.
    • Employs a 2D spatial index (via TPointArray_XTo2D) to limit neighbor
      searches to points whose coordinates fall within ±Ceil(radius).
    • Each unvisited point becomes the seed of a new component; all reachable
      points are enqueued and marked as visited.
    • Returns: T2DPointArray where each subarray contains one connected cluster.
    • Complexity: O(N · K) on average (K = nearby points per lookup),
      worst case O(N²) when every point connects.
    • Memory: boolean visited array, integer queue, and spatial index buffers.
    • Recommended for small–medium point sets or when iterative BFS is preferred.
[==============================================================================}
function TPointArrayHelper.BinaryFloodFill(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
var
  l, i, j, r, c, d: Integer;
  h, z: T2DIntegerArray;
  q, v: TIntegerArray;
  u: TBooleanArray;
  x, y, s: TRange;
  p: TPoint;
  procedure Enqueue(const index: Integer);
  begin
    if u[index] then
      Exit;
    u[index] := True;
    if (s.stop.Increment > High(q)) then
      SetLength(q, (q.Size * 2));
    q[s.stop] := index;
  end;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  d := Ceil(Radius);
  SetLength(u, l);
  SetLength(Result, 0);
  SetLength(Result, l);
  h := Self.XTo2D(v, z);
  SetLength(q, Max(256, (l div 10)));
  c := 0;
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    s.Create(0, 0);
    q[s.stop] := i;
    u[i] := True;
    while (s.start <= s.stop) do
    begin
      p := Self[q[s.start.Increase]];
      Result[c].Supply(p);
      y := v.BinaryRange(TRange.Construct((p.Y - d), (p.Y + d)));
      if not y.Employs(-1) then
      for r := y.start to y.stop do
      begin
        x := h[r].BinaryRange(TRange.Construct((p.X - d), (p.X + d)));
        if not x.Employs(-1) then
        for j := x.start to x.stop do
          if ((not u[z[r][j]]) and p.Within(Self[z[r][j]], radius, metric)) then
            Enqueue(z[r][j]);
      end;
    end;
    if (Result[c].Size > 0) then
      Inc(c);
  end;
  SetLength(Result, c);
end;

{==============================================================================]
  <BinaryFill>
  @action:
    Uses a Union–Find (Disjoint-Set) structure to group points into connected
    components.  Points within the given radius (and metric) are merged into
    the same set; each root represents one cluster.
  @note:
    • Builds a 2D spatial index for efficient candidate lookup.
    • For each point, only bins within ±Ceil(radius) in X/Y are searched.
    • Applies union-by-size and path-compression for nearly-constant merge cost.
    • After all unions, unique roots define the final clusters.
    • Returns: T2DPointArray of all connected components.
    • Complexity: O(N · α(N)) amortized (almost linear).
    • Memory: integer arrays p (parent), s (size), m (root→component id).
    • Fixed logic: component counter increments only when a new root is found.
    • Best suited for large datasets where BFS would be too expensive.
[==============================================================================}
function TPointArrayHelper.BinaryFill(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
var
  i, j, r, l, c, d: Integer;
  p, s, m: TIntegerArray;
  h, z: T2DIntegerArray;
  v: TIntegerArray;
  x, y: TRange;
  t, n: TPoint;
  function FindRoot(const i: Integer): Integer;
  begin
    if (p[i] <> i) then
      p[i] := FindRoot(p[i]);
    Result := p[i];
  end;
  procedure UnionPoints(i, j: Integer);
  begin
    i := FindRoot(i);
    j := FindRoot(j);
    if (i <> j) then
    case (s[i] < s[j]) of
      True:
      begin
        p[i] := j;
        Inc(s[j], s[i]);
      end;
      False:
      begin
        p[j] := i;
        Inc(s[i], s[j]);
      end;
    end;
  end;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  d := Ceil(radius);
  SetLength(p, l);
  SetLength(s, l);
  for i := 0 to (l - 1) do
  begin
    p[i] := i;
    s[i] := 1;
  end;
  h := Self.XTo2D(v, z);
  for i := 0 to (l - 1) do
  begin
    t := Self[i];
    y := v.BinaryRange(TRange.Construct((t.Y - d), (t.Y + d)));
    if not y.Employs(-1) then
    for r := y.start to y.stop do
    begin
      x := h[r].BinaryRange(TRange.Construct((t.X - d), (t.X + d)));
      if not x.Employs(-1) then
      for j := x.start to x.stop do
      begin
        n := Self[z[r][j]];
        if t.Within(n, radius, metric) then
          UnionPoints(i, z[r][j]);
      end;
    end;
  end;
  SetLength(m, l);
  for i := 0 to (l - 1) do
    m[i] := -1;
  c := 0;
  for i := 0 to (l - 1) do
  begin
    r := FindRoot(i);
    if m[r] = -1 then
    begin
      m[r] := c;
      Inc(c);
    end;
  end;
  SetLength(Result, c);
  for i := 0 to (l - 1) do
    Result[m[FindRoot(i)]].Supply(Self[i]);
end;

{==============================================================================]
  <BinaryFilled>
  @action:
    Optimized Union–Find flood fill that iterates directly over the 2D grid
    and unites only point pairs (f > e) within radius, eliminating duplicate
    comparisons and producing compact pre-allocated output clusters.
  @note:
    • Traverses all grid cells returned by TPointArray.XTo2D.
    • Checks neighboring bins within ±Ceil(radius) in both axes.
    • Uses path-halving in FindRoot and union-by-size in UnionSets.
    • Avoids redundant pair checks by enforcing f > e condition.
    • Builds exact component sizes before allocating Result arrays,
      avoiding dynamic reallocation during population.
    • Complexity: O(N · α(N)) amortized; typically fastest variant.
    • Memory: integer arrays p, s, m, t, k; minimal overhead.
    • Returns: compact T2DPointArray of connected components.
    • Recommended for large point clouds—highest performance and scalability.
[==============================================================================}
function TPointArrayHelper.BinaryFilled(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
var
  l, i, e, f, g, q, n, j, c, r, o, d: Integer;
  h, z: T2DIntegerArray;
  x, y: TRange;
  v, p, s, m, t, k: TIntegerArray;
  function FindRoot(a: Integer): Integer;
  begin
    while (p[a] <> a) do
    begin
      p[a] := p[p[a]];
      a := p[a];
    end;
    Result := a;
  end;
  procedure UnionSets(const a, b: Integer);
  var
    x, y: Integer;
  begin
    x := FindRoot(a);
    y := FindRoot(b);
    if (x <> y) then
    case (s[x] < s[y]) of
      True:
      begin
        p[x] := y;
        Inc(s[y], s[x]);
      end;
      False:
      begin
        p[y] := x;
        Inc(s[x], s[y]);
      end;
    end;
  end;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  d := Ceil(radius);
  h := Self.XTo2D(v, z);
  SetLength(p, l);
  SetLength(s, l);
  for i := 0 to (l - 1) do
  begin
    p[i] := i;
    s[i] := 1;
  end;
  for g := 0 to High(h) do
    for q := 0 to High(h[g]) do
    begin
      e := z[g][q];
      y := v.BinaryRange(TRange.Construct((Self[e].Y - d), (Self[e].Y + d)));
      if not y.Employs(-1) then
      for n := y.start to y.stop do
      begin
        x := h[n].BinaryRange(TRange.Construct((Self[e].X - d), (Self[e].X + d)));
        if not x.Employs(-1) then
        for j := x.start to x.stop do
        begin
          f := z[n][j];
          if ((f > e) and Self[e].Within(Self[f], radius, metric)) then
            UnionSets(e, f);
        end;
      end;
    end;
  SetLength(m, l);
  for i := 0 to (l - 1) do
    m[i] := -1;
  c := 0;
  for i := 0 to (l - 1) do
  begin
    r := FindRoot(i);
    if (m[r] = -1) then
      m[r] := c.Increase;
  end;
  SetLength(t, c);
  for i := 0 to (l - 1) do
    Inc(t[m[FindRoot(i)]]);
  SetLength(Result, c);
  for i := 0 to (c - 1) do
    SetLength(Result[i], t[i]);
  SetLength(k, c);
  for i := 0 to (l - 1) do
  begin
    o := m[FindRoot(i)];
    Result[o][k[o].Increase] := Self[i];
  end;
end;

{==============================================================================]
  <BFloodFill>
  @action:
    Performs a breadth-first flood fill (BFS) similar to BinaryFloodFill but
    uses a pre-allocated queue sized to the total number of points, providing
    predictable performance and avoiding queue resizing.
  @note:
    • Pre-allocates queue (length = total points) and manages it via TRange
      (r.start/r.stop) as queue head/tail indices.
    • Uses 2D spatial index to quickly find potential neighbors.
    • Marks visited points (u[]) and collects connected components into Result.
    • Returns: T2DPointArray of connected clusters.
    • Complexity: O(N · K) average; O(N²) in the worst fully connected case.
    • Memory: boolean visited array + full-length queue.
    • Difference vs BinaryFloodFill:
        – No dynamic queue growth (fixed maximum size).
        – Slightly simpler and faster for large uniform point sets.
    • Ideal when deterministic memory footprint is desired.
[==============================================================================}
function TPointArrayHelper.BFloodFill(const radius: Double; const metric: TMetrics = dmChebyshev): T2DPointArray;
var
  l, i, k, j, d, f, c: Integer;
  h, z: T2DIntegerArray;
  q, v: TIntegerArray;
  u: TBooleanArray;
  x, y, r: TRange;
  a, b: TPoint;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  d := Ceil(Radius);
  h := Self.XTo2D(v, z);
  SetLength(u, l);
  SetLength(Result, l);
  c := 0;
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    SetLength(q, l);
    r.Create(0, 1);
    q[0] := i;
    u[i] := True;
    while (r.start < r.stop) do
    begin
      a := Self[q[r.start.Increase]];
      Result[c].Supply(a);
      y := v.BinaryRange(TRange.Construct((a.Y - d), (a.Y + d)));
      if not y.Employs(-1) then
      for k := y.start to y.stop do
      begin
        x := h[k].BinaryRange(TRange.Construct((a.X - d), (a.X + d)));
        if not x.Employs(-1) then
        for j := x.start to x.stop do
        begin
          f := z[k][j];
          if u[f] then
            Continue;
          b := Self[f];
          if a.Within(b, radius, metric) then
          begin
            u[f] := True;
            q[r.stop.Increase] := f;
          end;
        end;
      end;
    end;
    if (Result[c].Size > 0) then
      Inc(c);
  end;
  SetLength(Result, c);
end;

{==============================================================================]
  <AdjFill>
  @action:
    Groups points into connected components based on grid adjacency.
    Supports 4-way (N, S, E, W) or 8-way (adds diagonals) connectivity.
  @note:
    • Assumes all points have integer coordinates.
    • Uses binary search within pre-sorted 2D index for O(log N) neighbor lookup.
    • Much faster than radius-based flood fills when only adjacent cells connect.
    • Returns: T2DPointArray of adjacency-connected clusters.
    • Complexity: O(N · log N) (binary searches dominate), O(N) for dense grids.
    • Memory: boolean visited array + BFS queue.
[==============================================================================}
function TPointArrayHelper.AdjFill(const scan8W: Boolean = True): T2DPointArray;
var
  a, l, i, k, r, c, f, g: Integer;
  h, z: T2DIntegerArray;
  v, q, x, y: TIntegerArray;
  u: TBooleanArray;
  n, p: TPoint;
  s: TRange;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  case scan8W of
    True:
    begin
      X := [1, -1,  0,  0,  1,  1, -1, -1];
      Y := [0,  0,  1, -1,  1, -1,  1, -1];
    end;
    False:
    begin
      X := [1, -1,  0,  0];
      Y := [0,  0,  1, -1];
    end;
  end;
  a := x.Size;
  h := Self.XTo2D(v, z);
  SetLength(u, l);
  SetLength(Result, l);
  SetLength(q, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    s.Create(0, 1);
    q[0] := i;
    u[i] := True;
    SetLength(Result[g], 0);
    while (s.start < s.stop) do
    begin
      f := q[s.start.Increase];
      p := Self[f];
      Result[g].Supply(p);
      for k := 0 to (a - 1) do
      begin
        n := Point((p.X + x[k]), (p.Y + y[k]));
        r := v.BinarySearch(n.Y);
        if InRange(r, 0, High(v)) then
        begin
          c := h[r].BinarySearch(n.X);
          if (InRange(c, 0, High(h[r])) and (not u[z[r][c]])) then
          begin
            u[z[r][c]] := True;
            q[s.stop.Increase] := z[r][c];
          end;
        end;
      end;
    end;
    Inc(g);
  end;
  SetLength(Result, g);
end;

{==============================================================================]
  <NFill>
  @action: Performs adjacency-based flood fill using binary search for neighbor detection.
           Groups connected points (4-way or 8-way) into separate clusters.
  @note: "N" stands for Neighbor Fill.
         - When scan8W = True → uses 8-way connectivity (includes diagonals).
         - When scan8W = False → uses 4-way connectivity (up, down, left, right).
         The method uses binary search on sorted X/Y axes via TPointArray.XTo2D
         for efficient detection of neighboring points without spatial hashing.
[==============================================================================}
function TPointArrayHelper.NFill(const scan8W: Boolean = True): T2DPointArray;
var
  i, j, k, r, c, l, t: Integer;
  h, z: T2DIntegerArray;
  v, q: TIntegerArray;
  u: TBooleanArray;
  p, n: TPoint;
  x, y, s: TRange;
  o: TPointArray;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  if scan8W then
    o := [Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1), Point(1, 1), Point(-1, -1), Point(1, -1), Point(-1, 1)]
  else
    o := [Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1)];
  h := Self.XTo2D(v, z);
  SetLength(Result, l);
  SetLength(u, l);
  SetLength(q, l);
  c := 0;
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    s.Create(0, 0);
    q[0] := i;
    u[i] := True;
    while (s.start <= s.stop) do
    begin
      p := Self[q[s.start.Increase]];
      Result[c].Supply(p);
      for k := 0 to High(o) do
      begin
        n := Point((p.X + o[k].X), (p.Y + o[k].Y));
        y := v.BinaryRange(TRange.Construct(n.Y, n.Y));
        if not y.Employs(-1) then
        for r := y.start to y.stop do
        begin
          x := h[r].BinaryRange(TRange.Construct(n.X, n.X));
          if not x.Employs(-1) then
          for j := x.start to x.stop do
          begin
            t := z[r][j];
            if not u[t] and (Self[t].X = n.X) and (Self[t].Y = n.Y) then
            begin
              u[t] := True;
              q[s.stop.Increment] := t;
            end;
          end;
        end;
      end;
    end;
    Inc(c);
  end;
  SetLength(Result, c);
end;

{==============================================================================]
  <AFill>
  @action: Performs adjacency-based flood fill over a bounded 2D grid.
           Groups connected points (4-way or 8-way) into separate clusters
           using a boolean occupancy map for constant-time neighbor lookup.
  @note: "A" stands for Adjacent Fill.
         - When scan8W = True → 8-way connectivity (includes diagonals).
         - When scan8W = False → 4-way connectivity (orthogonal only).
         This version is grid-optimized and typically faster than NFill
         for dense or uniformly spaced point sets.
[==============================================================================}
function TPointArrayHelper.AFill(const scan8W: Boolean = True): T2DPointArray;
var
  m: T2DBooleanArray;
  w, h, i, j, c: Integer;
  q, d: TPointArray;
  s: TRange;
  b: TBox;
  p, n: TPoint;
begin
  if Self.Empty then
    Exit([]);
  b := Self.Bounds(w, h);
  SetLength(m, h, w);
  m := T2D.Create(False, h, w);
  for i := 0 to High(Self) do
    m[Self[i].Y - b.Y1][Self[i].X - b.X1] := True;
  if scan8W then
    d := [Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1), Point(1, 1), Point(1, -1), Point(-1, 1), Point(-1, -1)]
  else
    d := [Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1)];
  SetLength(Result, Self.Size);
  c := 0;
  for i := 0 to High(Self) do
  begin
    if not m[Self[i].Y - b.Y1][Self[i].X - b.X1] then
      Continue;
    s.Create(0, 0);
    SetLength(q, Self.Size);
    q[0] := Self[i];
    m[q[0].Y - b.Y1][q[0].X - b.X1] := False;
    while (s.start <= s.stop) do
    begin
      p := q[s.start.Increase];
      Result[c].Supply(p);
      for j := 0 to High(d) do
      begin
        n := Point((p.X + d[j].X), (p.Y + d[j].Y));
        if not (b.Contains(n) and m[n.Y - b.Y1][n.X - b.X1]) then
          Continue;
        m[n.Y - b.Y1, n.X - b.X1] := False;
        q[s.stop.Increment] := n;
      end;
    end;
    Inc(c);
  end;
  SetLength(Result, c);
end;

{==============================================================================]
  <CFill>
  @action: Groups adjacent points (4-way or 8-way) using a Union-Find
           (disjoint set) structure for efficient neighbor merging.
  @note: "C" stands for Cell/Connectivity Fill.
         - scan8W = True  →  8-way connectivity
         - scan8W = False →  4-way connectivity
         Unlike AFill, this method does not perform a flood search — it
         merges connected cells directly using disjoint sets.
[==============================================================================}
function TPointArrayHelper.CFill(const scan8W: Boolean = True): T2DPointArray;
var
  b: TBox;
  m: T2DIntegerArray;
  w, h, i, j, r, c: Integer;
  a: TPoint;
  d: TPointArray;
  p, s, l: TIntegerArray;
  function FindRoot(a: Integer): Integer;
  begin
    while (p[a] <> a) do
    begin
      p[a] := p[p[a]];
      a := p[a];
    end;
    Result := a;
  end;
  procedure UnionSets(a, b: Integer);
  var
    x, y: Integer;
  begin
    x := FindRoot(a);
    y := FindRoot(b);
    if (x <> y) then
    case (s[x] < s[y]) of
      True:
      begin
        p[x] := y;
        Inc(s[y], s[x]);
      end;
      False:
      begin
        p[y] := x;
        Inc(s[x], s[y]);
      end;
    end;
  end;
begin
  if Self.Empty then
    Exit([]);
  b := Self.Bounds(w, h);
  SetLength(m, h, w);
  for i := 0 to High(m) do
    for j := 0 to High(m[i]) do
      m[i, j] := -1;
  for i := 0 to High(Self) do
    m[Self[i].Y - b.Y1][Self[i].X - b.X1] := i;
  if scan8W then
    d := [Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1), Point(1, 1), Point(1, -1), Point(-1, 1), Point(-1, -1)]
  else
    d := [Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1)];
  SetLength(p, Self.Size);
  SetLength(s, Self.Size);
  for i := 0 to High(Self) do
  begin
    p[i] := i;
    s[i] := 1;
  end;
  for i := 0 to High(Self) do
    for j := 0 to High(d) do
    begin
      a := Point((Self[i].X + d[j].X), (Self[i].Y + d[j].Y));
      if (b.Contains(a) and (m[a.Y - b.Y1][a.X - b.X1] <> -1)) then
        UnionSets(i, m[a.Y - b.Y1][a.X - b.X1]);
    end;
  SetLength(l, Self.Size);
  for i := 0 to High(Self) do
    l[i] := -1;
  c := 0;
  for i := 0 to High(Self) do
  begin
    r := FindRoot(i);
    if (l[r] = -1) then
      l[r] := c.Increase;
  end;
  SetLength(Result, c);
  for i := 0 to High(Self) do
    Result[l[FindRoot(i)]].Supply(Self[i]);
end;

{==============================================================================]
  <BCluster>
  @action: Performs radius-based clustering using binary search.
           Each point is assigned to a cluster based on proximity.
  @params: -radius: Maximum distance for points to be considered neighbors.
           -metric: Distance metric (Chebyshev, Euclidean, Manhattan, etc.)
  @result: T2DPointArray where each subarray contains points of one cluster
[==============================================================================}
function TPointArrayHelper.BCluster(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
var
  h, z: T2DIntegerArray;
  d, l, i, j, r, g: Integer;
  x, y, s: TRange;
  t: TPoint;
  c, q, p, v: TIntegerArray;
  procedure Enqueue(const index: Integer);
  begin
    q[s.stop.Increment] := index;
    c[index] := g;
  end;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  d := Ceil(radius);
  SetLength(c, l);
  for i := 0 to (l - 1) do
    c[i] := -1;
  h := Self.XTo2D(v, z);
  SetLength(q, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if (c[i] <> -1) then
      Continue;
    s.Create(0, 0);
    q[0] := i;
    c[i] := g;
    while (s.start <= s.stop) do
    begin
      t := Self[q[s.start.Increase]];
      y := v.BinaryRange(TRange.Construct((t.Y - d), (t.Y + d)));
      if not y.Employs(-1) then
      for r := y.start to y.stop do
      begin
        x := h[r].BinaryRange(TRange.Construct((t.X - d), (t.X + d)));
        if not x.Employs(-1) then
        for j := x.start to x.stop do
          if ((c[z[r][j]] = -1) and t.Within(Self[z[r][j]], radius, metric)) then
            Enqueue(z[r][j]);
      end;
    end;
    Inc(g);
  end;
  SetLength(p, g);
  for i := 0 to (g - 1) do
    p[i] := 0;
  for i := 0 to (l - 1) do
    Inc(p[c[i]]);
  SetLength(Result, g);
  for i := 0 to (g - 1) do
    SetLength(Result[i], p[i]);
  for i := 0 to (g - 1) do
    p[i] := 0;
  for i := 0 to (l - 1) do
    Result[c[i]][p[c[i]].Increase] := Self[i];
end;

{==============================================================================]
  <BCluster>
  @action: Performs radius-based clustering using binary search.
           Each point is assigned to a cluster based on proximity.
  @params: -radius: Maximum distance for points to be considered neighbors.
           -metric: Distance metric (Chebyshev, Euclidean, Manhattan, etc.)
  @result: T2DPointArray where each subarray contains points of one cluster
[==============================================================================}
function TPointArrayHelper.BCluster(const xRadius, yRadius: Integer): T2DPointArray; overload;
var
  h, z: T2DIntegerArray;
  l, i, j, r, g: Integer;
  x, y, s: TRange;
  t: TPoint;
  c, q, p, v: TIntegerArray;
  procedure Enqueue(const index: Integer);
  begin
    q[s.stop.Increment] := index;
    c[index] := g;
  end;
begin
  l := Self.Length;
  if (l = 0) then
    Exit([]);
  SetLength(c, l);
  for i := 0 to (l - 1) do
    c[i] := -1;
  h := Self.XTo2D(v, z);
  SetLength(q, l);
  g := 0;
  for i := 0 to (l - 1) do
  begin
    if (c[i] <> -1) then
      Continue;
    s.Create(0, 0);
    q[0] := i;
    c[i] := g;
    while (s.start <= s.stop) do
    begin
      t := Self[q[s.start.Increase]];
      y := v.BinaryRange(TRange.Construct((t.Y - yRadius), (t.Y + yRadius)));
      if not y.Employs(-1) then
      for r := y.start to y.stop do
      begin
        x := h[r].BinaryRange(TRange.Construct((t.X - xRadius), (t.X + xRadius)));
        if not x.Employs(-1) then
        for j := x.start to x.stop do
          if ((c[z[r][j]] = -1) and t.Within(Self[z[r][j]], xRadius, yRadius)) then
            Enqueue(z[r][j]);
      end;
    end;
    Inc(g);
  end;
  SetLength(p, g);
  for i := 0 to (g - 1) do
    p[i] := 0;
  for i := 0 to (l - 1) do
    Inc(p[c[i]]);
  SetLength(Result, g);
  for i := 0 to (g - 1) do
    SetLength(Result[i], p[i]);
  for i := 0 to (g - 1) do
    p[i] := 0;
  for i := 0 to (l - 1) do
    Result[c[i]][p[c[i]].Increase] := Self[i];
end;

{==============================================================================]
  <QuickSortByX>
  @action: Sorts all points in ascending order based on their X coordinate.
  @note: Uses an in-place recursive QuickSort. Does not guarantee stability
         for equal X values. Complexity is O(n log n) on average.
[==============================================================================}
function TPointArrayHelper.QuickSortByX(const aAscending: Boolean = True): Integer;
  procedure QSX(var arr: TPointArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p: TPoint;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and (arr[i].X < p.X)) or ((not A) and (arr[i].X > p.X))) do
        Inc(i);
      while ((A and (arr[j].X > p.X)) or ((not A) and (arr[j].X < p.X))) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSX(arr, L, j, A);
    if (i < R) then
      QSX(arr, i, R, A);
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    QSX(Self, 0, (Result - 1), aAscending);
end;

{==============================================================================]
  <QuickSortByY>
  @action: Sorts all points in ascending order based on their Y coordinate.
  @note: In-place recursive QuickSort implementation. Equal Y values are not
         guaranteed to preserve original order (unstable sort).
[==============================================================================}
function TPointArrayHelper.QuickSortByY(const aAscending: Boolean = True): Integer;
  procedure QSY(var arr: TPointArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p: TPoint;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and (arr[i].Y < p.Y)) or ((not A) and (arr[i].Y > p.Y))) do
        Inc(i);
      while ((A and (arr[j].Y > p.Y)) or ((not A) and (arr[j].Y < p.Y))) do
        Dec(j);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSY(arr, L, j, A);
    if (i < R) then
      QSY(arr, i, R, A);
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    QSY(Self, 0, (Result - 1), aAscending);
end;

{==============================================================================]
  <QuickSortByXY>
  @action: Sorts all points by X coordinate first, and then by Y coordinate
           for points sharing the same X value.
  @note: Implements a dual-key QuickSort for consistent ordering by (X,Y).
         Average complexity O(n log n). Not stable for equal (X,Y) pairs.
[==============================================================================}
function TPointArrayHelper.QuickSortByXY(const aAscending: Boolean = True): Integer;
  procedure QSXY(var arr: TPointArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p: TPoint;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and ((arr[i].X < p.X) or ((arr[i].X = p.X) and (arr[i].Y < p.Y)))) or ((not A) and ((arr[i].X > p.X) or ((arr[i].X = p.X) and (arr[i].Y > p.Y))))) do
        Inc(i);
      while ((A and ((arr[j].X > p.X) or ((arr[j].X = p.X) and (arr[j].Y > p.Y))) or ((not A) and ((arr[j].X < p.X) or ((arr[j].X = p.X) and (arr[j].Y < p.Y)))))) do
        Dec(J);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSXY(arr, L, j, A);
    if (i < R) then
      QSXY(arr, i, R, A);
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    QSXY(Self, 0, (Result - 1), aAscending);
end;

{==============================================================================]
  <QuickSortByYX>
  @action: Sorts all points by Y coordinate first, and then by X coordinate
           for points sharing the same Y value.
  @note: Commonly used for spatial clustering and grid-based sorting.
         In-place QuickSort with O(n log n) average complexity.
[==============================================================================}
function TPointArrayHelper.QuickSortByYX(const aAscending: Boolean = True): Integer;
  procedure QSYX(var arr: TPointArray; const L, R: Integer; const A: Boolean);
  var
    i, j: Integer;
    p: TPoint;
  begin
    i := L;
    j := R;
    p := arr[(L + R) shr 1];
    repeat
      while ((A and ((arr[i].Y < p.Y) or ((arr[i].Y = p.Y) and (arr[i].X < p.X)))) or ((not A) and ((arr[i].Y > p.Y) or ((arr[i].Y = p.Y) and (arr[i].X > p.X))))) do
        Inc(i);
      while ((A and ((arr[j].Y > p.Y) or ((arr[j].Y = p.Y) and (arr[j].X > p.X)))) or ((not A) and ((arr[j].Y < p.Y) or ((arr[j].Y = p.Y) and (arr[j].X < p.X))))) do
        Dec(J);
      if (i <= j) then
        Swap(arr[i.Increase], arr[j.Decrease]);
    until (i > j);
    if (L < j) then
      QSYX(arr, L, j, A);
    if (i < R) then
      QSYX(arr, i, R, A);
  end;
begin
  Result := Self.Size;
  if (Result > 1) then
    QSYX(Self, 0, (Result - 1), aAscending);
end;

{==============================================================================]
  <SortByIndex>
  @action: Sorts the point array by a calculated linear index within the given bounding box.
  @note: Each point is mapped from (X,Y) to a single 1D index value and sorted
         using TArray_QuickSortWeighted. Returns the number of points in the array.
[==============================================================================}
function TPointArrayHelper.SortByIndex(const aBounds: TBox; const aAscending: Boolean = True): Integer; overload;
var
  i: Integer;
  w: TIntegerArray;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  SetLength(w, Result);
  for i := 0 to (Result - 1) do
    w[i] := (((Self[i].Y - aBounds.Y1) * ((aBounds.X2 - aBounds.X1) + 1)) + (Self[i].X - aBounds.X1));
  Self.QuickSortWeighted(w, aAscending);
end;

{==============================================================================]
  <SortByIndex>
  @action: Sorts the point array by index using a default large bounding box.
  @note: Calls SortByIndex(Box(-23169, -23169, 23169, 23169), aAscending).
         Useful when explicit bounds are not needed.
[==============================================================================}
function TPointArrayHelper.SortByIndex(const aAscending: Boolean = True): Integer; overload;
begin
  Result := Self.SortByIndex(TBox.Construct(-23169, -23169, 23169, 23169), aAscending);
end;

{==============================================================================]
  <SortByScanline>
  @action: Reorders all points in the array into strict row-to-column (scanline)
           sequence within the specified bounding box. The sort scans from the
           top-left corner to the bottom-right (ascending = True), or the reverse
           direction if ascending = False. The operation is performed by iterating
           through every coordinate in raster order and moving matching points into
           the output array.
 @note: - This is a *deterministic, stable* traversal-based ordering, not a
          comparison sort.
        - Complexity is O(W × H × N) in the worst case, so it is best used when
          the bounding box is small or the coordinate grid is discrete and bounded.
        - Points that fall outside the bounding box are discarded.
        - The method modifies the array in place and returns the number of points
          remaining after sorting.
[==============================================================================}
function TPointArrayHelper.SortByScanline(const aBounds: TBox; const aAscending: Boolean = True): Integer; overload;
var
  s: TPointArray;
  x, y, i, l, h: Integer;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  s := Self.Copy;
  l := 0;
  h := (Result - 1);
  case aAscending of
    True:
    for y := aBounds.Y1 to aBounds.Y2 do
      for x := aBounds.X1 to aBounds.X2 do
      begin
        i := 0;
	    while (i <= h) do
          if ((s[i].X = x) and (s[i].Y = y)) then
          begin
            Self[l.Increase] := s[i];
            Swap(s[i], s[h.Decrease]);
            if (h = -1) then
              Exit;
          end else
	        Inc(i);
    end;
    False:
    for y := aBounds.Y2 downto aBounds.Y1 do
      for x := aBounds.X2 downto aBounds.X1 do
      begin
        i := 0;
	    while (i <= h) do
          if ((s[i].X = x) and (s[i].Y = y)) then
          begin
            Self[l.Increase] := s[i];
            Swap(s[i], s[h.Decrease]);
            if (h = -1) then
              Exit;
          end else
	        Inc(i);
       end;
  end;
  SetLength(Self, l);
end;

{==============================================================================]
  <SortByScanline>
  @action: Convenience overload that calls SortByScanline using the array’s own
           bounding box (Self.Bounds) as the region to scan.
  @note: Equivalent to SortByScanline(Self.Bounds, aAscending).
         Produces identical ordering but automatically derives the limits from the
         data set.
[==============================================================================}
function TPointArrayHelper.SortByScanline(const aAscending: Boolean = True): Integer; overload;
begin
  Result := Self.SortByScanline(Self.Bounds, aAscending);
end;

{==============================================================================]
  <ProximityCluster>
  @action:
    Groups points into spatial clusters based on rectangular proximity.
    Two points belong to the same cluster if their X and Y differences are
    both within the specified radii.
  @params:
    xRadius : Integer
      Maximum horizontal distance (in coordinate units) between two points
      to be considered neighbors.
    yRadius : Integer
      Maximum vertical distance (in coordinate units) between two points
      to be considered neighbors.
    method  : Integer = 0
      Determines the output grouping method:
        0 - Use Groupify
        1 - Use Grouping
        2 - Use Grouped
  @returns:
    T2DPointArray containing one subarray per detected cluster.
[==============================================================================}
function TPointArrayHelper.ProximityCluster(const xRadius, yRadius: Integer; const method: Integer = 0): T2DPointArray; overload;
var
  i, j, k, c, l: Integer;
  g, y: TIntegerArray;
  x, s: T2DIntegerArray;
  h, v: TRange;
  procedure MC(const a, b: Integer);
  var
    o, n, m: Integer;
  begin
    if (a = b) then
      Exit;
    o := g[b];
    n := g[a];
    for m := 0 to High(g) do
      if (g[m] = o) then
        g[m] := n;
  end;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  g := Self.IDs;
  x := Self.XTo2D(y, s);
  for c := 0 to High(x) do
  begin
    h.Create(c);
    while ((h.start > 0) and (Abs(y[h.start - 1] - y[c]) <= xRadius)) do
      Dec(h.start);
    while ((h.stop < High(x)) and (Abs(y[h.stop + 1] - y[c]) <= xRadius)) do
      Inc(h.stop);
    for i := 0 to High(x[c]) do
      for j := h.start to h.stop do
      begin
        v.start := x[j].BinaryFirst(x[c][i] - yRadius);
        if not (v.start = -1) then
          v.stop := x[j].BinaryLast(x[c][i] + yRadius);
        if not v.Employs(-1) then
        for k := v.start to v.stop do
          if Self[s[c][i]].Within(Self[s[j][k]], xRadius, yRadius) then
            MC(s[c][i], s[j][k]);
      end;
  end;
  case method of
    0: Result := Self.Groupify(g);
    1: Result := Self.Grouping(g);
    2: Result := Self.Grouped(g);
  end;
end;

{==============================================================================]
  <ProximityCluster>
  @action:
    Clusters points in the array based on geometric proximity using a
    distance metric. Points closer than the given radius are merged
    into the same cluster.
  @params:
    radius : Double = 1.0
      Maximum distance between two points (according to the selected metric)
      for them to belong to the same cluster.
    metric : TMetrics = dmEuclidean
      Distance metric used to compute proximity:
        dmEuclidean - standard geometric distance
        dmManhattan - sum of absolute component differences
        dmChebyshev - maximum component difference
    method : Integer = 0
      Determines which grouping procedure is used to construct the result:
        0 - Groupify
        1 - Grouping
        2 - Grouped
  @returns:
    T2DPointArray in which each subarray represents one proximity-based cluster.
[==============================================================================}
function TPointArrayHelper.ProximityCluster(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const method: Integer = 0): T2DPointArray; overload;
var
  i, j, k, c, l, d: Integer;
  g, y: TIntegerArray;
  x, s: T2DIntegerArray;
  h, v: TRange;
  procedure MC(const a, b: Integer);
  var
    o, n, m: Integer;
  begin
    if (a = b) then Exit;
    o := g[b];
    n := g[a];
    for m := 0 to High(g) do
      if (g[m] = o) then
        g[m] := n;
  end;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  g := Self.IDs;
  x := Self.XTo2D(y, s);
  d := Ceil(radius);
  for c := 0 to High(x) do
  begin
    h.Create(c);
    while ((h.start > 0) and (Abs(y[h.start - 1] - y[c]) <= d)) do
      Dec(h.start);
    while ((h.stop < High(x)) and (Abs(y[h.stop + 1] - y[c]) <= d)) do
      Inc(h.stop);
    for i := 0 to High(x[c]) do
      for j := h.start to h.stop do
      begin
        v.start := x[j].BinaryFirst(x[c][i] - d);
        if not (v.start = -1) then
          v.stop := x[j].BinaryLast(x[c][i] + d);
        if not v.Employs(-1) then
        for k := v.start to v.stop do
          if Self[s[c][i]].Within(Self[s[j][k]], radius, metric) then
            MC(s[c][i], s[j][k]);
      end;
  end;
  case method of
    0: Result := Self.Groupify(g);
    1: Result := Self.Grouping(g);
    2: Result := Self.Grouped(g);
  end;
end;

{==============================================================================]
  <Linked>
  @action: Build neighbour-based clusters by linking each point to up to check
           nearest neighbours inside radius (using metric). Candidate
           neighbours are discovered quickly via binary-range lookups on the
           precomputed X/Y index arrays (XTo2D + BinaryRange).
           Matching neighbour pairs are merged with a disjoint-set (union–find)
           so clusters are transitively connected: if A→B and B→C then A, B, C
           belong to the same cluster.
  @note: - radius is the floating-point distance threshold used to select
           candidate neighbours; the integer search bound d := Ceil(radius)
           is used to restrict binary-range queries for speed.
         - check limits how many nearest neighbours (per point) are
           examined/linked; larger values increase connectivity and cost.
         - Uses Euclidean or other `metric` only for the final Within/Dist
           test and for ordering neighbours by distance.
         - Union–find uses path compression and union-by-size for near-
           constant amortized cost; overall runtime is dominated by the
           spatial index lookups (≈ O(n log n) to build/scan) and the
           average-local-candidate work.
         - Deterministic: same input → same clusters. Returns array of
           clusters (T2DPointArray); cluster ordering is implementation-
           dependent.
[==============================================================================}
function TPointArrayHelper.Linked(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const check: Integer = 1): T2DPointArray; overload;
var
  i, j, r, c, l, g, d, e: Integer;
  f: Double;
  v, p, s, k, t, o: TIntegerArray;
  h, z: T2DIntegerArray;
  y, x: TRange;
  n: array of record
    index: Integer;
    distance: Double;
  end;
  function FindRoot(const a: Integer): Integer;
  begin
    if (p[a] <> a) then
      p[a] := FindRoot(p[a]);
    Result := p[a];
  end;
  procedure Unioned(const a, b: Integer);
  var
    r: TRange;
  begin
    r.Create(FindRoot(a), FindRoot(b));
    if (r.start = r.stop) then
      Exit;
    if (s[r.start] < s[r.stop]) then
      Swap(r.start, r.stop);
    p[r.stop] := r.start;
    Inc(s[r.start], s[r.stop]);
  end;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  d := Ceil(radius);
  h := Self.XTo2D(v, z);
  SetLength(p, l);
  SetLength(s, l);
  for i := 0 to (l - 1) do
  begin
    p[i] := i;
    s[i] := 1;
  end;
  for i := 0 to (l - 1) do
  begin
    y := v.BinaryRange(TRange.Construct((Self[i].Y - d), (Self[i].Y + d)));
    if not y.Employs(-1) then
    for r := y.start to y.stop do
    begin
      x := h[r].BinaryRange(TRange.Construct((Self[i].X - d), (Self[i].X + d)));
      if not x.Employs(-1) then
      begin
        SetLength(n, 0);
        for c := x.start to x.stop do
        begin
          j := z[r][c];
          if ((i <> j) and Self[i].Within(Self[j], radius, metric)) then
          begin
            SetLength(n, (System.Length(n) + 1));
            n[High(n)].index := j;
            n[High(n)].distance := Self[i].Dist(Self[j], metric);
          end;
        end;
        for j := 0 to (High(n) - 1) do
          for c := (j + 1) to High(n) do
            if (n[j].distance > n[c].distance) then
            begin
              e := n[j].index;
              n[j].index := n[c].index;
              n[c].index := e;
              f := n[j].distance;
              n[j].distance := n[c].distance;
              n[c].distance := f;
            end;
        for j := 0 to Min(High(n), (check - 1)) do
          Unioned(i, n[j].index);
      end;
    end;
  end;
  SetLength(k, l);
  for i := 0 to (l - 1) do
    k[i] := -1;
  g := 0;
  for i := 0 to (l - 1) do
  begin
    r := FindRoot(i);
    if (k[r] = -1) then
      k[r] := g.Increase;
  end;
  SetLength(t, g);
  for i := 0 to (l - 1) do
    Inc(t[k[FindRoot(i)]]);
  SetLength(Result, g);
  for i := 0 to (g - 1) do
    SetLength(Result[i], t[i]);
  SetLength(o, g);
  for i := 0 to (l - 1) do
  begin
    r := k[FindRoot(i)];
    Result[r][o[r].Increase] := Self[i];
  end;
end;

{==============================================================================]
  <Linked>
  @action: Build neighbour-based clusters by linking each point to up to check
           nearest neighbours inside an axis-aligned box given by
           xRadius/yRadius. Candidate neighbours are located via binary-
           range queries on the X/Y index arrays produced by
           XTo2D, and nearest candidates are ranked by
           Euclidean distance (Hypot) before linking.
           Matching neighbour pairs are merged using a disjoint-set
           (union–find) so clusters are transitively connected.
  @note: - This overload uses rectangular neighbourhoods: a candidate is
           considered only if its X/Y deltas are inside xRadius/yRadius;
           distance is used only to sort nearest candidates.
         - check limits how many nearest neighbours (per point) are
           considered/linked; increasing it increases connectivity and cost.
         - Uses binary-range lookups to avoid global O(n²) scanning — great
           for large point sets (expected ≈ O(n log n) dominated by indexing).
         - Union–find uses path compression and union-by-size for near-
           constant amortized cost; final clusters are produced by grouping
           points by their disjoint-set roots.
         - Deterministic: same input → same clusters. Returns a T2DPointArray
           (array of clusters); cluster ordering is implementation-dependent.
[==============================================================================}
function TPointArrayHelper.Linked(const xRadius, yRadius: Integer; const check: Integer = 1): T2DPointArray; overload;
var
  i, j, r, c, l, g, e: Integer;
  f: Double;
  v, p, s, k, t, o: TIntegerArray;
  h, z: T2DIntegerArray;
  y, x: TRange;
  n: array of record
    index: Integer;
    distance: Double;
  end;
  function FindRoot(const a: Integer): Integer;
  begin
    if (p[a] <> a) then
      p[a] := FindRoot(p[a]);
    Result := p[a];
  end;
  procedure Unioned(const a, b: Integer);
  var
    r: TRange;
  begin
    r.Create(FindRoot(a), FindRoot(b));
    if (r.start = r.stop) then
      Exit;
    if (s[r.start] < s[r.stop]) then
      Swap(r.start, r.stop);
    p[r.stop] := r.start;
    Inc(s[r.start], s[r.stop]);
  end;
begin
  l := Self.Length;
  case l of
    0: Exit([]);
    1: Exit([Self]);
  end;
  h := Self.XTo2D(v, z);
  SetLength(p, l);
  SetLength(s, l);
  for i := 0 to (l - 1) do
  begin
    p[i] := i;
    s[i] := 1;
  end;
  for i := 0 to (l - 1) do
  begin
    y := v.BinaryRange(TRange.Construct((Self[i].Y - yRadius), (Self[i].Y + yRadius)));
    if not y.Employs(-1) then
    for r := y.start to y.stop do
    begin
      x := h[r].BinaryRange(TRange.Construct((Self[i].X - xRadius), (Self[i].X + xRadius)));
      if not x.Employs(-1) then
      begin
        SetLength(n, 0);
        for c := x.start to x.stop do
        begin
          j := z[r][c];
          if ((i <> j) and Self[i].Within(Self[j], xRadius, yRadius)) then
          begin
            SetLength(n, (System.Length(n) + 1));
            n[High(n)].index := j;
            n[High(n)].distance := Hypot((Self[i].X - Self[j].X), (Self[i].Y - Self[j].Y));
          end;
        end;
        for j := 0 to (High(n) - 1) do
          for c := (j + 1) to High(n) do
            if (n[j].distance > n[c].distance) then
            begin
              e := n[j].index;
              n[j].index := n[c].index;
              n[c].index := e;
              f := n[j].distance;
              n[j].distance := n[c].distance;
              n[c].distance := f;
            end;
        for j := 0 to Min(High(n), (check - 1)) do
          Unioned(i, n[j].index);
      end;
    end;
  end;
  SetLength(k, l);
  for i := 0 to (l - 1) do
    k[i] := -1;
  g := 0;
  for i := 0 to (l - 1) do
  begin
    r := FindRoot(i);
    if (k[r] = -1) then
      k[r] := g.Increase;
  end;
  SetLength(t, g);
  for i := 0 to (l - 1) do
    Inc(t[k[FindRoot(i)]]);
  SetLength(Result, g);
  for i := 0 to (g - 1) do
    SetLength(Result[i], t[i]);
  SetLength(o, g);
  for i := 0 to (l - 1) do
  begin
    r := k[FindRoot(i)];
    Result[r][o[r].Increase] := Self[i];
  end;
end;

{==============================================================================]
  <Chain>
  @action: Groups nearby points into connected chains using radius-based neighbor linking.
  @note: Each new chain starts from an unvisited point and expands by iteratively
         linking up to `check` nearest unlinked neighbors within the given radius.
         The process continues recursively until no further points can be connected.
         This version uses a simple full-scan distance check (no spatial indexing).
[==============================================================================}
function TPointArrayHelper.Chain(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const check: Integer = 5): T2DPointArray; overload;
var
  i, j, k, c, l, q: Integer;
  u: TBooleanArray;
  s: TIntegerArray;
  n: array of record
    index: Integer;
    distance: Double;
  end;
begin
  SetLength(Result, 0);
  l := Self.Length;
  case l of
    0: Exit;
    1: Exit([Self]);
  end;
  SetLength(u, l);
  c := 0;
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    SetLength(Result[c], 0);
    SetLength(s, 1);
    s[0] := i;
    u[i] := True;
    while (s.Size > 0) do
    begin
      q := s[High(s)];
      SetLength(s, High(s));
      Result[c].Supply(Self[q]);
      SetLength(n, 0);
      for j := 0 to (l - 1) do
        if ((not u[j]) and Self[q].Within(Self[j], radius, metric)) then
        begin
          SetLength(n, (System.Length(n) + 1));
          n[High(n)].index := j;
          n[High(n)].distance := Self[q].Dist(Self[j], metric);
        end;
      for j := 0 to (High(n) - 1) do
        for k := (j + 1) to High(n) do
          if (n[j].distance > n[k].distance) then
	      begin
            Swap(n[j].index, n[k].index);
	        Swap(n[j].distance, n[k].distance);
	      end;
      for j := 0 to Min(High(n), (check - 1)) do
        if not u[n[j].index] then
        begin
          u[n[j].index] := True;
          s.Supply(n[j].index);
        end;
    end;
    Inc(c);
  end;
end;

{==============================================================================]
  <Chain>
  @action: Groups nearby points into connected chains using rectangular X/Y radii.
  @note: Similar to the distance-based Chain but uses axis-aligned rectangular bounds
         (xRadius, yRadius) for neighborhood checks instead of circular distance.
         Efficient for grid-aligned or anisotropic data where X and Y scales differ.
[==============================================================================}
function TPointArrayHelper.Chain(const xRadius, yRadius: Integer; const check: Integer = 5): T2DPointArray; overload;
var
  i, j, k, c, l, q: Integer;
  u: TBooleanArray;
  s: TIntegerArray;
  n: array of record
    index: Integer;
    distance: Double;
  end;
begin
  SetLength(Result, 0);
  l := Self.Length;
  case l of
    0: Exit;
    1: Exit([Self]);
  end;
  SetLength(u, l);
  c := 0;
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    SetLength(Result[c], 0);
    SetLength(s, 1);
    s[0] := i;
    u[i] := True;
    while (s.Size > 0) do
    begin
      q := s[High(s)];
      SetLength(s, High(s));
      Result[c].Supply(Self[q]);
      SetLength(n, 0);
      for j := 0 to (l - 1) do
        if ((not u[j]) and Self[q].Within(Self[j], xRadius, yRadius)) then
        begin
          SetLength(n, (System.Length(n) + 1));
          n[High(n)].index := j;
          n[High(n)].distance := Hypot((Self[q].X - Self[j].X), (Self[q].Y - Self[j].Y));
        end;
      for j := 0 to (High(n) - 1) do
        for k := (j + 1) to High(n) do
          if (n[j].distance > n[k].distance) then
	      begin
            Swap(n[j].index, n[k].index);
	        Swap(n[j].distance, n[k].distance);
	      end;
      for j := 0 to Min(High(n), (check - 1)) do
        if not u[n[j].index] then
        begin
          u[n[j].index] := True;
          s.Supply(n[j].index);
        end;
    end;
    Inc(c);
  end;
end;

{==============================================================================]
  <Attach>
  @action: Connects points into clusters using spatial indexing (binary search + grid).
  @note: Uses precomputed X/Y grid slices (via TPointArray_XTo2D) and binary range
         search to quickly find neighbors within `radius`. Each cluster grows by
         recursively attaching up to `check` nearest neighbors that fall within range.
         Much faster than Chain for large point sets due to reduced search scope.
[==============================================================================}
function TPointArrayHelper.Attach(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean; const check: Integer = 5): T2DPointArray; overload;
var
  i, j, r, c, l, d, q: Integer;
  u: TBooleanArray;
  s: TIntegerArray;
  v: TIntegerArray;
  h, z: T2DIntegerArray;
  y, x: TRange;
  n: array of record
    index: Integer;
    distance: Double;
  end;
begin
  l := Self.Length;
  case l of
    0: Exit;
    1: Exit([Self]);
  end;
  d := Ceil(radius);
  h := Self.XTo2D(v, z);
  SetLength(u, l);
  SetLength(Result, 0);
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    SetLength(Result[High(Result)], 0);
    SetLength(s, 1);
    s[0] := i;
    u[i] := True;
    while (s.Size > 0) do
    begin
      q := s[High(s)];
      SetLength(s, High(s));
      Result[High(Result)].Supply(Self[q]);
      y := v.BinaryRange(TRange.Construct((Self[q].Y - d), (Self[q].Y + d)));
      if y.Employs(-1) then
        Continue;
      SetLength(n, 0);
      for r := y.start to y.stop do
      begin
        x := h[r].BinaryRange(TRange.Construct((Self[q].X - d), (Self[q].X + d)));
        if not x.Employs(-1) then
        for c := x.start to x.stop do
          if (not u[z[r][c]]) and Self[q].Within(Self[z[r][c]], radius, metric) then
          begin
            SetLength(n, (System.Length(n) + 1));
            n[High(n)].index := z[r][c];
            n[High(n)].distance := Self[q].Dist(Self[z[r][c]], metric);
          end;
      end;
      for j := 0 to (High(n) - 1) do
        for c := (j + 1) to High(n) do
          if (n[j].distance > n[c].distance) then
	  begin
            Swap(n[j].index, n[c].index);
	    Swap(n[j].distance, n[c].distance);
	  end;
      for j := 0 to Min(High(n), (check - 1)) do
      begin
        if u[n[j].index] then
          Continue;
        u[n[j].index] := True;
        s.Supply(n[j].index);
      end;
    end;
  end;
end;

{==============================================================================]
  <Attach>
  @action: Connects points into clusters using rectangular X/Y radii and spatial indexing.
  @note: Combines grid-based search (TPointArray_XTo2D) with axis-aligned neighbor
         bounds (xRadius, yRadius). Finds and links nearby points efficiently while
         respecting separate X and Y proximity limits. Ideal for non-uniform spacing.
[==============================================================================}
function TPointArrayHelper.Attach(const xRadius, yRadius: Integer; const check: Integer = 5): T2DPointArray; overload;
var
  i, j, r, c, l, q: Integer;
  u: TBooleanArray;
  s: TIntegerArray;
  v: TIntegerArray;
  h, z: T2DIntegerArray;
  y, x: TRange;
  n: array of record
    index: Integer;
    distance: Double;
  end;
begin
  l := Self.Length;
  case l of
    0: Exit;
    1: Exit([Self]);
  end;
  h := Self.XTo2D(v, z);
  SetLength(u, l);
  SetLength(Result, 0);
  for i := 0 to (l - 1) do
  begin
    if u[i] then
      Continue;
    SetLength(Result, (System.Length(Result) + 1));
    SetLength(Result[High(Result)], 0);
    SetLength(s, 1);
    s[0] := i;
    u[i] := True;
    while (s.Size > 0) do
    begin
      q := s[High(s)];
      SetLength(s, High(s));
      Result[High(Result)].Supply(Self[q]);
      y := v.BinaryRange(TRange.Construct((Self[q].Y - yRadius), (Self[q].Y + yRadius)));
      if y.Employs(-1) then
        Continue;
      SetLength(n, 0);
      for r := y.start to y.stop do
      begin
        x := h[r].BinaryRange(TRange.Construct((Self[q].X - xRadius), (Self[q].X + xRadius)));
        if x.Employs(-1) then
          Continue;
        for c := x.start to x.stop do
          if ((not u[z[r][c]]) and Self[q].Within(Self[z[r][c]], xRadius, yRadius)) then
          begin
            SetLength(n, (System.Length(n) + 1));
            n[High(n)].index := z[r][c];
            n[High(n)].distance := Hypot((Self[q].X - Self[z[r][c]].X), (Self[q].Y - Self[z[r][c]].Y));
          end;
      end;
      for j := 0 to (High(n) - 1) do
        for c := (j + 1) to High(n) do
          if (n[j].distance > n[c].distance) then
	  begin
	    Swap(n[j].index, n[c].index);
	    Swap(n[j].distance, n[c].distance);
          end;  
      for j := 0 to Min(High(n), (check - 1)) do
      begin
        if u[n[j].index] then
          Continue;
        u[n[j].index] := True;
        s.Supply(n[j].index);
      end;
    end;
  end;
end;

{==============================================================================]
  <RCluster>
  @action: Groups points into rectangular clusters based on X/Y radius thresholds.
  @note: Uses a grid-based flood-fill algorithm; points are considered connected 
         if their absolute X and Y distances are within (xRadius, yRadius).
[==============================================================================}
function TPointArrayHelper.RCluster(const xRadius, yRadius: Integer): T2DPointArray; overload;
type
  TCell = record
    indices: TIntegerArray;
  end;
  TCellArray = array of TCell;
  TGrid = array of TCellArray;
var
  v: TBooleanArray;
  g: TGrid;
  e, f, w, h, i, j, l, t, r, x, y, z: Integer;
  s: TIntegerArray;
  b: TBox;
  c, p, d: TPoint;
begin
  SetLength(Result, 0);
  l := Self.Length;
  case l of
    0: Exit;
    1: Exit([Self]);
  end;
  b := Self.Bounds;
  e := (xRadius * 2 + 1);
  f := (yRadius * 2 + 1);
  w := ((b.X2 - b.X1) div e + 1);
  h := ((b.Y2 - b.Y1) div f + 1);
  SetLength(g, w, h);
  for i := 0 to High(Self) do
    g[((Self[i].X - b.X1) div e)][((Self[i].Y - b.Y1) div f)].indices.Supply(i);
  SetLength(v, l);
  SetLength(s, l);
  SetLength(Result, l);
  r := 0;
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    t := 0;
    s[t.Increase] := i;
    v[i] := True;
    z := 0;
    SetLength(Result[r], 0);
    while (t > 0) do
    begin
      c := Self[s[t.Decrement]];
      SetLength(Result[r], z.Increment);
      Result[r][z - 1] := c;
      p := Point(((c.X - b.X1) div e), ((c.Y - b.Y1) div f));
      for x := Max(0, (p.X - 1)) to Min((w - 1), (p.X + 1)) do
        for y := Max(0, (p.Y - 1)) to Min((h - 1), (p.Y + 1)) do
          for j := 0 to High(g[x, y].indices) do
          begin
            if v[g[x, y].indices[j]] then
              Continue;
            d := Point(Abs(c.X - Self[g[x, y].indices[j]].X), Abs(c.Y - Self[g[x, y].indices[j]].Y));
            if ((d.X <= xRadius) and (d.Y <= yRadius)) then
            begin
              v[g[x, y].indices[j]] := True;
              s[t.Increase] := g[x, y].indices[j];
            end;
          end;
    end;
    Inc(r);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <RCluster>
  @action: Groups points into clusters based on a custom distance metric and radius.
  @note: Supports user-defined metrics (e.g. Euclidean, Manhattan, Chebyshev).
         Uses grid partitioning for spatial acceleration and a stack-based region grow.
[==============================================================================}
function TPointArrayHelper.RCluster(const radius: Double = 1.0; const metric: TMetrics = dmEuclidean): T2DPointArray; overload;
type
  TCell = record
    indices: TIntegerArray;
  end;
  TCellArray = array of TCell;
  TGrid = array of TCellArray;
var
  v: TBooleanArray;
  g: TGrid;
  k, w, h, i, j, l, t, r, x, y, z: Integer;
  s: TIntegerArray;
  b: TBox;
  c, p: TPoint;
begin
  SetLength(Result, 0);
  l := Self.Length;
  case l of
    0: Exit;
    1: Exit([Self]);
  end;
  k := (Trunc(Radius * 2) + 1);
  b := Self.Bounds;
  w := ((b.X2 - b.X1) div k + 1);
  h := ((b.Y2 - b.Y1) div k + 1);
  SetLength(g, w, h);
  for i := 0 to High(Self) do
    g[((Self[i].X - b.X1) div k)][((Self[i].Y - b.Y1) div k)].indices.Supply(i);
  SetLength(v, l);
  SetLength(s, l);
  SetLength(Result, l);
  r := 0;
  for i := 0 to (l - 1) do
  begin
    if v[i] then
      Continue;
    t := 0;
    s[t.Increase] := i;
    v[i] := True;
    z := 0;
    SetLength(Result[r], 0);
    while (t > 0) do
    begin
      c := Self[s[t.Decrement]];
      SetLength(Result[r], z.Increment);
      Result[r][z - 1] := c;
      p := Point(((c.X - b.X1) div k), ((c.Y - b.Y1) div k));
      for x := Max(0, (p.X - 1)) to Min((w - 1), (p.X + 1)) do
        for y := Max(0, (p.Y - 1)) to Min((h - 1), (p.Y + 1)) do
          for j := 0 to High(g[x, y].indices) do
          begin
            if v[g[x, y].indices[j]] then
              Continue;
            if c.Within(Self[g[x, y].indices[j]], radius, metric) then
            begin
              v[g[x, y].indices[j]] := True;
              s[t.Increase] := g[x, y].indices[j];
            end;
          end;
    end;
    Inc(r);
  end;
  SetLength(Result, r);
end;

{==============================================================================]
  <ToRows>
  @action: Groups all points in the array into rows based on their Y coordinates.
  @note: The Y values are sorted and deduplicated before grouping, so the resulting
         row order follows ascending Y. Each subarray of the result contains all
         points that share the same Y value.
[==============================================================================}
function TPointArrayHelper.ToRows: T2DPointArray;
var
  i: Integer;
  y: TIntegerArray;
begin
  y := Self.Ys.QuickSorted.BinaryPruned;
  SetLength(Result, y.Size);
  for i := 0 to High(Self) do
    Result[y.BinarySearch(Self[i].Y)].Supply(Self[i]);
end;

{==============================================================================]
  <ToColumns>
  @action: Groups all points in the array into columns based on their X coordinates.
  @note: The X values are sorted and deduplicated before grouping, so the resulting
         column order follows ascending X. Each subarray of the result contains all
         points that share the same X value.
[==============================================================================}
function TPointArrayHelper.ToColumns: T2DPointArray;
var
  i: Integer;
  x: TIntegerArray;
begin
  x := Self.Xs.QuickSorted.BinaryPruned;
  SetLength(Result, x.Size);
  for i := 0 to High(Self) do
    Result[x.BinarySearch(Self[i].x)].Supply(Self[i]);
end;

{==============================================================================]
  <AsRows>
  @action: Groups all points in the array into rows based on their Y coordinates.
  @note: The original order of Y values is preserved — rows are created in the
         order each Y first appears in the source array. No sorting or pruning
         is performed.
[==============================================================================}
function TPointArrayHelper.AsRows: T2DPointArray;
var
  i, j: Integer;
  y: TIntegerArray;
  p: Integer;
begin
  SetLength(Result, 0);
  SetLength(y, 0);
  for i := 0 to High(Self) do
  begin
    p := -1;
    for j := 0 to High(y) do
      if (y[j] = Self[i].Y) then
      begin
        p := j;
        Break;
      end;
    if (p = -1) then
    begin
      p := y.Size;
      SetLength(y, (p + 1));
      y[p] := Self[i].Y;
      SetLength(Result, (p + 1));
    end;
    Result[p].Supply(Self[i]);
  end;
end;

{==============================================================================]
  <AsColumns>
  @action: Groups all points in the array into columns based on their X coordinates.
  @note: The original order of X values is preserved — columns are created in the
         order each X first appears in the source array. No sorting or pruning
         is performed.
[==============================================================================}
function TPointArrayHelper.AsColumns: T2DPointArray;
var
  i, j: Integer;
  x: TIntegerArray;
  p: Integer;
begin
  SetLength(Result, 0);
  SetLength(x, 0);
  for i := 0 to High(Self) do
  begin
    p := -1;
    for j := 0 to High(x) do
      if (x[j] = Self[i].X) then
      begin
        p := j;
        Break;
      end;
    if (p = -1) then
    begin
      p := x.Size;
      SetLength(x, (p + 1));
      x[p] := Self[i].X;
      SetLength(Result, (p + 1));
    end;
    Result[p].Supply(Self[i]);
  end;
end;

{==============================================================================]
  <Rows>
  @action: Groups all points in the array into rows based on their Y coordinates.
  @note: Each unique Y value defines one row. The order of rows matches the order
         in which distinct Y values first appear in the source array (unsorted).
         Uses a dictionary for O(1) coordinate lookup, providing fast grouping
         while preserving the original encounter order.
[==============================================================================}
function TPointArrayHelper.Rows: T2DPointArray;
var
  i, p: Integer;
  m: specialize TDictionary<Integer, Integer>;
  o: TIntegerArray;
begin
  m := specialize TDictionary<Integer, Integer>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not m.TryGetValue(Self[i].Y, p) then
      begin
        p := o.Size;
        SetLength(o, (p + 1));
        o[p] := Self[i].Y;
        m.Add(Self[i].Y, p);
        SetLength(Result, (p + 1));
      end;
      Result[p].Supply(Self[i]);
    end;
  finally
    m.Free;
  end;
end;

{==============================================================================]
  <Columns>
  @action: Groups all points in the array into columns based on their X coordinates.
  @note: Each unique X value defines one column. The order of columns matches the
         order in which distinct X values first appear in the source array (unsorted).
         Uses a dictionary for O(1) coordinate lookup, providing fast grouping
         while preserving the original encounter order.
[==============================================================================}
function TPointArrayHelper.Columns: T2DPointArray;
var
  i, p: Integer;
  m: specialize TDictionary<Integer, Integer>;
  o: TIntegerArray;
begin
  m := specialize TDictionary<Integer, Integer>.Create;
  try
    for i := 0 to High(Self) do
    begin
      if not m.TryGetValue(Self[i].X, p) then
      begin
        p := o.Size;
        SetLength(o, (p + 1));
        o[p] := Self[i].X;
        m.Add(Self[i].X, p);
        SetLength(Result, (p + 1));
      end;
      Result[p].Supply(Self[i]);
    end;
  finally
    m.Free;
  end;
end;

function TPointArrayHelper.Pure(const allowed: TPointArray): Boolean; overload; var a: TPointArray; {$DEFINE Skeleton_Pure}{$I ../Skeletons.inc}{$UNDEF Skeleton_Pure}

{==============================================================================]
  <BSort>
  @action: Sorts the array of points in-place using the Binary Insertion Sort algorithm.
  @note: - The sorting order is determined by the 'aAscending' flag.
         - Comparison is performed using 'TPoint.Compare'.
         - Uses binary search to find the insertion position for efficiency, but
           shifting elements still makes it O(n²) in worst case.
         - Returns the total number of elements in the array after sorting.
[==============================================================================}
function TPointArrayHelper.BSort(const aAscending: Boolean = True): Integer; overload;
var
  C, i, M: Integer;
  s: TPointArray;
  R: TRange;
begin
  Result := Self.Size;
  if (Result < 2) then
    Exit;
  s := Self.Copy;
  SetLength(Self, 1);
  for i := 1 to (Result - 1) do
  begin
    R.Create(0, High(Self));
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if aAscending then
        C := Self[M].Compare(s[i])
      else
        C := s[i].Compare(Self[M]);
      case C of
        -1: R.start := (M + 1);
        1: R.stop := (M - 1);
	    0:
	    begin
          R.start := M;
          Break;
        end;
      end;
    end;
    Insert(s[i], Self, R.start);
  end;
end;

{==============================================================================]
  <BSorted>
  @action: Returns a new sorted copy of the current point array using Binary Insertion Sort.
  @note: - The original array remains unchanged.
         - Sorting order depends on the 'aAscending' parameter.
         - Comparison uses 'TPoint_Compare' to determine ordering.
         - Efficient for small arrays, but still O(n²) due to insertion shifting.
         - Binary search minimizes comparisons when finding insertion points.
[==============================================================================}
function TPointArrayHelper.BSorted(const aAscending: Boolean = True): TPointArray; Overload;
var
  C, i, M: Integer;
  R: TRange;
begin
  if (Self.Size < 2) then
    Exit(Self.Copy);
  SetLength(Result, 1);
  Result[0] := Self[0];
  for i := 1 to High(Self) do
  begin
    R.Create(0, High(Result));
    while (R.start <= R.stop) do
    begin
      M := R.Pivot;
      if aAscending then
        C := Result[M].Compare(Self[i])
      else
        C := Self[i].Compare(Result[M]);
      case C of
        -1: R.start := (M + 1);
        1: R.stop := (M - 1);
	    0:
        begin
          R.start := M;
          Break;
        end;
      end;
    end;
    Insert(Self[i], Result, R.start);
  end;
end;

{==============================================================================]
  <BinarySearch>
  @action: Performs a binary search for a specified point in a sorted TPointArray.
  @note: - The array must be sorted in ascending lexicographic order by X, then by Y,
           consistent with TPoint.Compare.
          - Returns the index of the matching point if found, or -1 if not found.
[==============================================================================}
function TPointArrayHelper.BinarySearch(const item: TPoint): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Compare(item) of
	  -1: R.start := (M + 1);
      1: R.stop := (M - 1);
      0: Exit(M);
	end;
  end;
  Result := -1;
end;

{==============================================================================]
  <BinarySearch>
  @action: Performs a binary search over the point array to locate any point contained within the specified bounding box (TBox).
           If a point lying inside the area is found, its index is returned; otherwise, the function returns –1.
  @note: The array must be pre-sorted by Y coordinate (and implicitly by X for tie-breaking) in the same ordering implemented by TPoint.Compare.
         The initial boundary check short-circuits the search if the box vertically lies outside the array’s extents.
		 The search returns the first matching point encountered during the binary-search traversal,
		 not a guaranteed minimal or maximal spatial index. Execution is O(log n).
[==============================================================================}
function TPointArrayHelper.BinarySearch(const area: TBox): Integer; overload;
var
  M: Integer;
  Y, R: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  Y.Create(area.Y1, area.Y2);
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Y < Y.start) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  while ((R.start <= High(Self)) and (Self[R.start].Y <= Y.stop)) do
  begin
    if ((Self[R.start].X >= area.X1) and (Self[R.start].X <= area.X2)) then
      Exit(R.start);
    Inc(R.start);
  end;
end;

{==============================================================================]
  <BinaryFind>
  @action: Performs binary search on the sorted point array to locate the exact TPoint whose coordinates match the specified item.
           The search is lexicographical: first by Y, then by X.
  @note: The array must be pre-sorted by Y ascending and, for identical Y values, by X ascending.
         Returns the index of the matching element, or -1 if no match is found.
[==============================================================================}
function TPointArrayHelper.BinaryFind(const item: TPoint): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case (Self[M].Y < item.Y) of
      True:
      begin
        R.start := (M + 1);
        Continue;
      end;
      False:
      if (Self[M].Y > item.Y) then
      begin
        R.stop := (M - 1);
        Continue;
      end;
    end;
    case (Self[M].X < item.X) of
      True:
      begin
        R.start := (M + 1);
        Continue;
      end;
      False:
      if (Self[M].X > item.X) then
      begin
        R.stop := (M - 1);
        Continue;
      end;
    end;
    Exit(M);
  end;
end;

{==============================================================================]
  <BinaryFind>
  @action: Locates the first point within the array whose coordinates fall inside the given rectangular TBox by performing a binary search on the Y coordinate,
           then scanning forward through the candidate range.
  @note: The array must be sorted by Y ascending. The function first narrows the search to the lowest index where Y ≥ area.Y1,
         then linearly scans forward until Y > area.Y2 or a qualifying point is found.
		 Returns the index of the first point inside the box, or -1 if the area contains no points.
[==============================================================================}
function TPointArrayHelper.BinaryFind(const area: TBox): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  Result := -1;
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Y < area.Y1) then
      R.start := (M + 1)
    else
      R.stop := (M - 1);
  end;
  while ((R.start <= High(Self)) and (Self[R.start].Y <= area.Y2)) do
  begin
    if ((Self[R.start].X >= area.X1) and (Self[R.start].X <= area.X2)) then
      Exit(R.start);
    Inc(R.start);
  end;
end;

{==============================================================================]
  <BinaryIndexOf>
  @action: Performs a binary search for a specified point in a sorted TPointArray.
  @note: - The array must be sorted in ascending lexicographic order by X, then by Y,
           consistent with TPoint.Compare.
          - Returns the index of the matching point if found, or -1 if not found.
[==============================================================================}
function TPointArrayHelper.BinaryIndexOf(const item: TPoint): Integer; overload;
  function BS(const L, R: Integer): Integer;
  var
    M: Integer;
  begin
    if (L > R) then
      Exit(-1);
    M := (L + ((R - L) div 2));
    if (Self[M] = item) then
      Exit(M);
    if (Self[M].Compare(item) = 1) then
      Result := BS(L, (M - 1))
    else
      Result := BS((M + 1), R);
  end;
begin
  Result := BS(0, High(Self));
end;

{==============================================================================]
  <BinaryExists>
  @action: Performs a binary search for a specified point in a sorted TPointArray.
  @note: Returns True if the matching point is found.
[==============================================================================}
function TPointArrayHelper.BinaryExists(const item: TPoint): Boolean; overload;
  function BS(const L, R: Integer): Boolean;
  var
    M: Integer;
  begin
    if (L > R) then
      Exit(False);
    M := (L + ((R - L) div 2));
    case Self[M].Compare(item) of
      0: Exit(True);
      1: Result := BS(L, (M - 1));
      -1: Result := BS((M + 1), R);
    end;
  end;
begin
  Result := BS(0, High(Self));
end;

{==============================================================================]
  <BinaryPosL>
  @action: Finds the leftmost index at which a given point could be inserted
           in sorted order (first element >= item).
  @note: - The array must be sorted in ascending lexicographic order by X, then Y.
          - Returns the insertion index (0..Length(Self)).
[==============================================================================}
function TPointArrayHelper.BinaryPosL(const item: TPoint): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, Self.Size);
  while (R.start < R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Compare(item) < 0) then
      R.start := (M + 1)
    else
      R.stop := M;
  end;
  Result := R.start;
end;

{==============================================================================]
  <BinaryPosR>
  @action: Finds the rightmost index at which a given point could be inserted
           in sorted order (last element <= item).
  @note: - The array must be sorted in ascending lexicographic order by X, then Y.
          - Returns the index of the last element <= item,
            or -1 if all elements are greater than item.
[==============================================================================}
function TPointArrayHelper.BinaryPosR(const item: TPoint): Integer; overload;
var
  M: Integer;
  R: TRange;
begin
  R.Create(0, Self.Size);
  while (R.start < R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Compare(item) <= 0) then
      R.start := (M + 1)
    else
      R.stop := M;
  end;
  Result := (R.start - 1);
end;

{==============================================================================]
  <BinaryRank>
  @action: Returns the rank (0-based index) of a point within a sorted TPointArray.
           The rank is the position at which the point would be inserted to
           maintain ascending lexicographic order by X, then Y.
  @note: - Equivalent to the index of the first element >= item.
         - If the item exists, returns the index of its first occurrence.
         - The array must be sorted ascending, consistent with TPoint.Compare.
[==============================================================================}
function TPointArrayHelper.BinaryRank(const item: TPoint): Integer; overload;
var
  R, M: Integer;
begin
  Result := 0;
  R := Self.Size;
  while (Result < R) do
  begin
    M := ((Result + R) div 2);
    if (Self[M].Compare(item) < 0) then
      Result := (M + 1)
    else
      R := M;
  end;
end;

{==============================================================================]
  <BinarySearch>
  @action: Performs a binary search for a specified point in a sorted TPointArray.
  @note: - The array must be sorted in ascending lexicographic order by X, then by Y,
           consistent with TPoint.Compare.
         - Returns the index of the matching point if found, or -1 if not found.
[==============================================================================}
function TPointArrayHelper.BinaryContains(const item: TPoint): Boolean; overload;
begin
  Result := (Self.BinarySearch(item) > -1);
end;

{==============================================================================]
  <BinaryInsert>
  @action: Inserts a specified point into a sorted TPointArray while maintaining
           lexicographic order.
  @note: - The array must be sorted in ascending lexicographic order by X, then by Y,
           consistent with TPoint.Compare.
         - If allowDuplicates = False, no insertion occurs if the point already exists.
         - Returns the index of the inserted or existing point.
[==============================================================================}
function TPointArrayHelper.BinaryInsert(const item: TPoint; const allowDuplicates: Boolean = True): Integer; overload;
var
  H, M: Integer;
begin
  Result := 0;
  H := High(Self);
  while (Result <= H) do
  begin
    M := ((Result + H) div 2);
    case Self[M].Compare(item) of
      -1: Result := (M + 1);
      1: H := (M - 1);
      0:
      if allowDuplicates then
        Result := (M + 1)
      else
        Exit(M);
    end;
  end;
  Insert(item, Self, Result);
end;

{==============================================================================]
  <BinaryAppend>
  @action: Appends a specified point to the end of a sorted TPointArray if it is greater
           than the last point, otherwise performs a BinaryInsert.
  @note: - The array must be sorted in ascending lexicographic order by X, then by Y,
           consistent with TPoint.Compare.
         - If allowDuplicates = False, duplicates are ignored.
         - Returns the index of the inserted or existing point.
[==============================================================================}
function TPointArrayHelper.BinaryAppend(const item: TPoint; const allowDuplicates: Boolean = True): Integer; overload;
begin
  if not (Self.Empty or (Self[High(Self)].Compare(item) < 0)) then
    Exit(Self.BinaryInsert(item, allowDuplicates));
  Result := Self.Size;
  Self.Supply(item);
end;

{==============================================================================]
  <BinarySupply>
  @action: Inserts a specified point into the sorted TPointArray while preserving
           ascending lexicographic order by X, then Y.
  @note: - The array must already be sorted in ascending order consistent with
           TPoint.Compare.
         - Uses BinaryPosL to determine the correct insertion position.
         - Shifts subsequent elements to make room for the new point.
         - Returns the index at which the point was inserted.
[==============================================================================}
function TPointArrayHelper.BinarySupply(const item: TPoint): Integer; overload;
var
  i: Integer;
begin
  Result := Self.BinaryPosL(item);
  SetLength(Self, (Self.Size + 1));
  for i := High(Self) downto (Result + 1) do
    Self[i] := Self[i - 1];
  Self[Result] := item;
end;

{==============================================================================]
  <BinaryCount>
  @action: Counts the total number of occurrences of a specified point in a
           sorted TPointArray using binary search for efficient lookup.
  @note: - The algorithm performs a binary search to locate one matching element,
           then scans outward in both directions to count all equal items.
         - Returns 0 if the specified point is not found.
[==============================================================================}
function TPointArrayHelper.BinaryCount(const item: TPoint): Integer; overload;
var
  M, i: Integer;
  R: TRange;
begin
  Result := 0;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Compare(item) of
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
      0:
      begin
        i := M;
        while ((i >= 0) and (Self[i] = item)) do
        begin
          Inc(Result);
          Dec(i);
        end;
        i := (M + 1);
        while ((i <= High(Self)) and (Self[i] = item)) do
        begin
          Inc(Result);
          Inc(i);
        end;
        Exit;
      end;
    end;
  end;
end;

{==============================================================================]
  <BinaryAmount>
  @action: Returns the number of elements in the sorted TPointArray that are
           equal to the specified point.
  @note: - The array must be sorted in ascending lexicographic order by X, then Y,
           consistent with TPoint.Compare.
         - Returns 0 if the point does not exist in the array.
         - Internally uses BinaryRangeOf to determine the index range.
[==============================================================================}
function TPointArrayHelper.BinaryAmount(const item: TPoint): Integer; overload;
var
  r: TRange;
begin
  r := Self.BinaryRangeOf(item);
  if (r.start > r.stop) then
    Exit(0);
  Result := ((r.stop - r.start) + 1);
end;

{==============================================================================]
  <BinaryRange>
  @action: Performs a binary search to find the contiguous index range of all
           points equal to the specified item.
  @note:   Assumes the array is sorted according to TPoint_Compare.
           Returns (-1,-1) if no matching point is found.
[==============================================================================}
function TPointArrayHelper.BinaryRange(const item: TPoint): TRange; overload;
var
  M: Integer;
  R: TRange;
begin
  Result.Create(-1);
  if Self.Empty then
    Exit;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Compare(item) of
      0:
      begin
        Result.start := M;
        R.stop := (M - 1);
      end;
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
    end;
  end;
  R.Create(0, High(Self));
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    case Self[M].Compare(item) of
      0:
      begin
        Result.stop := M;
        R.start := (M + 1);
      end;
      -1: R.start := (M + 1);
      1: R.stop := (M - 1);
    end;
  end;
end;

{==============================================================================]
  <BinaryRangeOf>
  @action: Returns the range of indices that correspond to all elements
           equal to a specified point within a sorted TPointArray.
  @note: - The array must be sorted in ascending lexicographic order by X, then Y,
           consistent with TPoint.Compare.
         - If the point is not found, Result.start > Result.stop.
         - Result.start is the index of the first element >= item.
         - Result.stop  is the index of the last element <= item.
[==============================================================================}
function TPointArrayHelper.BinaryRangeOf(const item: TPoint): TRange; overload;
begin
  Result.Create(Self.BinaryPosL(item), Self.BinaryPosR(item));
end;

{==============================================================================]
  <BinaryScan>
  @action: Performs a vertical binary scan on a Y-sorted point array to locate
           all points whose coordinates lie within the specified TBox.
  @note:   Array must be sorted by Y ascending. Uses binary search on Y to find
           the vertical range and linearly filters by X within that range.
           Returns indexes of all matching points.
[==============================================================================}
function TPointArrayHelper.BinaryScan(const area: TBox): TIntegerArray; overload;
var
  M, i: Integer;
  s, r: TRange;
begin
  SetLength(Result, 0);
  s.Create(0, High(Self));
  if ((s.stop = -1) or (area.Y2 < Self[s.start].Y) or (area.Y1 > Self[s.stop].Y)) then
    Exit;
  r.Create(-1);
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case (Self[M].Y < area.Y1) of
      False:
      begin
        r.start := M;
        s.stop := (M - 1);
      end;
      True: s.start := (M + 1);
    end;
  end;
  if (r.start = -1) then
    Exit;
  s.start := r.start;
  s.stop := High(Self);
  while (s.start <= s.stop) do
  begin
    M := s.Pivot;
    case (Self[M].Y > area.Y2) of
      False:
      begin
        r.stop := M;
        s.start := (M + 1);
      end;
      True: s.stop := (M - 1);
    end;
  end;
  if (r.stop = -1) then
    Exit;
  for i := r.start to r.stop do
    if ((Self[i].X >= area.X1) and (Self[i].X <= area.X2)) then
      Result.Supply(i);
end;

{==============================================================================]
  <BinaryScanned>
  @action: Performs a vertical binary scan on a Y-sorted point array to locate
           all point indexes lying within the specified TBox.
  @note: - The array must be sorted in ascending order by the Y coordinate.
         - Uses binary search on Y to find the vertical range (Y1..Y2),
           then linearly filters points whose X coordinate also lies within
           X1..X2.
         - Returns an index list (TIntegerArray) of all points inside the box.
         - Ideal for spatial lookups or clipping operations in sorted sets.
[==============================================================================}
function TPointArrayHelper.BinaryScanned(const area: TBox): TIntegerArray;
var
  M, i, S: Integer;
  o, r: TRange;
begin
  SetLength(Result, 0);
  o.Create(0, High(Self));
  if ((o.stop = -1) or (area.Y2 < Self[O.start].Y) or (area.Y1 > Self[o.stop].Y)) then
    Exit;
  S := o.stop;
  r.Create(-1);
  while (o.start <= o.stop) do
  begin
    M := o.Pivot;
    case ((Self[M].Y >= area.Y1) and (Self[M].Y <= area.Y2)) of
      True:
      begin
        r.Create(M);
        while ((r.start > 0) and (Self[r.start - 1].Y >= area.Y1)) do
          Dec(r.start);
        while ((r.stop < S) and (Self[r.stop + 1].Y <= area.Y2)) do
          Inc(r.stop);
        Break;
      end;
      False:
      if (Self[M].Y > area.Y2) then
        o.stop := (M - 1)
      else
        o.start := (M + 1);
    end;
  end;
  if not r.Employs(-1) then
  for i := r.start to r.stop do
    if ((Self[i].X >= area.X1) and (Self[i].X <= area.X2)) then
      Result.Supply(i);
end;

{==============================================================================]
  <BinaryDelete>
  @action: Removes the specified TPoint from the array using binary search.
           If found, the element is deleted and the array is resized.
  @note: - The array must be sorted according to the same ordering rule
           used by TPointArray.BinarySearch.
         - All elements after the deleted item are shifted left by one.
         - Returns True if the point was found and removed, False otherwise.
[==============================================================================}
function TPointArrayHelper.BinaryDelete(const item: TPoint): Boolean; overload;
var
  i, p: Integer;
begin
  p := Self.BinarySearch(item);
  Result := (p > -1);
  if not Result then
    Exit;
  for i := p to (High(Self) - 1) do
    Self[i] := Self[i + 1];
  SetLength(Self, (Self.Size - 1));
end;

{==============================================================================]
  <BinaryRemove>
  @action: Removes one or all occurrences of a specified TPoint from the array
           using binary search. If 'all' is True, every matching element is
           deleted; otherwise, only the first found instance is removed.
  @note: - The array must be sorted using the same ordering as
           TPointArray.BinarySearch and TPointArray.BinaryRange.
         - When 'all' is True, deletion shifts the remaining elements left.
         - Returns the number of elements removed (0 if none found).
[==============================================================================}
function TPointArrayHelper.BinaryRemove(const item: TPoint; const all: Boolean = True): Integer; overload;
var
  i, l: Integer;
  r: TRange;
begin
  l := Self.Length;
  if (l = 0) then
    Exit(0);
  case all of
    False: Result := IfThen(Self.BinaryDelete(item), 1, 0);
    True:
    begin
      r := Self.BinaryRange(item);
      if r.Employs(-1) then
        Exit(0);
      Result := r.Size;
      for i := r.start to ((l - Result) - 1) do
        Self[i] := Self[i + Result];
      SetLength(Self, (l - Result));
    end;
  end;
end;

{==============================================================================]
  <BinarySinglify>
  @action: Removes all occurrences of a specified point from the sorted TPointArray
           in place, preserving ascending lexicographic order by X, then Y.
  @note: - The array must be sorted ascending by X, then Y, consistent with TPoint.Compare.
         - Uses BinaryPosL to locate the first occurrence efficiently.
         - Shifts subsequent elements left to fill removed entries.
         - Returns the number of points removed.
		 - KEEPS ONLY ONE!
[==============================================================================}
function TPointArrayHelper.BinarySinglify(const item: TPoint): Integer; overload;
var
  i, l, s, p: Integer;
begin
  p := Self.BinaryPosL(item);
  if (p = -1) then
    Exit(0);
  s := Self.Size;
  l := p;
  for i := (p + 1) to (s - 1) do
    if (Self[i] <> item)then
      Self[l.Increment] := Self[i];
  Result := (s - (l + 1));
  if (Result > 0) then
    SetLength(Self, (l + 1));
end;

{==============================================================================]
  <BinarySinglified>
  @action: Returns a copy of the array with all occurrences of a specified point
           removed, preserving the original order.
  @note: - The array must be sorted ascending by X then Y, consistent with TPoint.Compare.
         - Uses BinaryPosL to locate the first occurrence efficiently.
[==============================================================================}
function TPointArrayHelper.BinarySinglified(const item: TPoint): TPointArray; overload;
var
  i, l, p: Integer;
begin
  p := Self.BinaryPosL(item);
  if (p = -1) then
    Exit(Self.Copy);
  SetLength(Result, Self.Size);
  l := 0;
  for i := 0 to High(Self) do
    if ((i = p) or (Self[i] <> item)) then
      Result[l.Increase] := Self[i];
  SetLength(Result, l);
end;

{==============================================================================]
  <BinaryMerge>
  @action: Merges the current sorted TPointArray with another sorted TPointArray,
           producing a new sorted array.
  @note: - Both arrays must be sorted in ascending lexicographic order by X, then by Y,
           consistent with TPoint.Compare.
         - The resulting array preserves sort order.
         - Duplicate points are preserved.
[==============================================================================}
function TPointArrayHelper.BinaryMerge(const items: TPointArray): TPointArray; overload;
var
  i, j, k: Integer;
  s, o: Integer;
begin
  s := Self.Size;
  o := items.Size;
  SetLength(Result, (s + o));
  if (Result.Size < 1) then
    Exit;
  i := 0;
  j := 0;
  k := 0;
  while ((i < s) and (j < o)) do
  begin
    if (Self[i].Compare(items[j]) <= 0) then
      Result[k] := Self[i.Increase]
    else
      Result[k] := items[j.Increase];
    Inc(k);
  end;
  while (i < s) do
    Result[k.Increase] := Self[i.Increase];
  while (j < o) do
    Result[k.Increase] := items[j.Increase];
end;

{==============================================================================]
  <BinaryReplace>
  @action: BinaryReplace for TPointArray
  @note: Only Ascending order.
[==============================================================================}
function TPointArrayHelper.BinaryReplace(const oItem, nItem: TPoint): Boolean; overload;
begin
  Result := Self.BinaryDelete(oItem);
  if (Result and (oItem <> nItem)) then
    Self.BinaryInsert(nItem);
end;

{==============================================================================]
  <BinaryReplaceAll>
  @action: BinaryReplaceAll for TPointArray
  @note: Only Ascending order.
[==============================================================================}
function TPointArrayHelper.BinaryReplaceAll(const oItem, nItem: TPoint): Integer; overload;
var
  i, p: Integer;
  r: Boolean;
begin
  Result := 0;
  p := Self.BinaryPosL(oItem);
  if (p = -1) then
    Exit;
  r := False;
  for i := p to High(Self) do
    if (Self[i] = oItem) then
    begin
      Self[i] := nItem;
      Inc(Result);
      if ((not r) and (not Self.IsSorted(i))) then
        r := True;
    end else
      Break;
  if r then
    Self.BinaryInsertionSort;
end;

{==============================================================================]
  <BinaryXs>
  @action:
    Returns all X-values from the TPointArray, grouped by their Y-value.
    Optionally returns only unique X-values within each Y-group.
  @note:
    - The array must be sorted by Y ascending for correct grouping.
    - Uniqueness is applied *per Y-group* only.
    - If unique=True, repeated X-values within the same Y-group are ignored.
    - If unique=False, all X-values are preserved.
[==============================================================================}
function TPointArrayHelper.BinaryXs(const unique: Boolean = True): TIntegerArray; overload;
var
  h, i, y, m, k, x: Integer;
  r, s: TRange;
begin
  SetLength(Result, 0);
  h := High(Self);
  if (h < 0) then
    Exit;
  i := 0;
  while (i <= h) do
  begin
    y := Self[i].Y;
    r.Create(i, h);
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if (Self[m].Y > y) then
        r.stop := (m - 1)
      else
        r.start := (m + 1);
    end;
    s.Create(i, (r.start - 1));
    case unique of
      True:
      begin
        x := Low(Integer);
        for k := s.start to s.stop do
        begin
          if (Self[k].X = x) then
            Continue;
          x := Self[k].X;
          Result.BinaryGrow(x);
        end;
      end;
      False:
      for k := s.start to s.stop do
        Result.BinaryInsert(Self[k].X);
    end;
    i := (s.stop + 1);
  end;
end;

{==============================================================================]
  <BinaryYs>
  @action:
    Returns all Y-values from the TPointArray, in the order they appear.
    Optionally returns only unique values (no duplicates).
  @note:
    - The array must be sorted by Y ascending for the unique option to work correctly.
    - If unique=True, repeated Y-values are ignored.
    - If unique=False, all Y-values including duplicates are returned.
[==============================================================================}
function TPointArrayHelper.BinaryYs(const unique: Boolean = True): TIntegerArray; overload;
var
  i, c: Integer;
begin
  SetLength(Result, Self.Size);
  if Self.Empty then
    Exit;
  Result[0] := Self[0].Y;
  c := 1;
  case unique of
    True:
    for i := 1 to High(Self) do
      if (Self[i].Y <> Self[i - 1].Y) then
        Result[c.Increase] := Self[i].Y;
    False:
    for i := 1 to High(Self) do
      Result[c.Increase] := Self[i].Y;
  end;
  SetLength(Result, c);
end;

{==============================================================================]
  <BinaryYPoints>
  @action:
    Returns a TPointArray containing all points with the specified Y-value.
    Uses binary search to locate the first and last indices with that Y.
  @note:
    - The array must be sorted by Y ascending.
    - Returns an empty array if no points match the given Y-value.
    - Efficient: O(log n) search to find the matching range.
[==============================================================================}
function TPointArrayHelper.BinaryYPoints(const yValue: Integer): TPointArray; overload;
var
  h, m, f, l, i: Integer;
  r: TRange;
begin
  h := High(Self);
  SetLength(Result, 0);
  if (h < 0) then
    Exit;
  r.Create(0, h);
  f := -1;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    if (Self[m].Y >= yValue) then
    begin
      if (Self[m].Y = yValue) then
        f := m;
      r.stop := (m - 1);
    end else
      r.start := (m + 1);
  end;
  if (f = -1) then
    Exit;
  r.Create(0, h);
  l := -1;
  while (r.start <= r.stop) do
  begin
    m := r.Pivot;
    if (Self[m].Y <= yValue) then
    begin
      if (Self[m].Y = yValue) then
        l := m;
      r.start := (m + 1);
    end else
      r.stop := (m - 1);
  end;
  SetLength(Result, ((l - f) + 1));
  for i := 0 to High(Result) do
    Result[i] := Self[f + i];
end;

{==============================================================================]
  <BinaryXPoints>
  @action:
    Returns a TPointArray containing all points with the specified X-value.
    For each Y-row in the array, it uses BinaryYPoints to get all points in that row,
    then performs a binary search within the row to find points with X = XValue.
  @note:
    - The array must be sorted in **scanline order** (Y ascending, then X ascending within each Y).
    - Returns an empty array if no points match the given X-value.
    - Efficient: O(R * log N) where R = number of distinct Y-rows, N = points per row.
    - Depends only on BinaryYPoints; does not rely on BinaryYRange or BinaryYs.
[==============================================================================}
function TPointArrayHelper.BinaryXPoints(const xValue: Integer): TPointArray; overload;
var
  h, i, a, c, y, m: Integer;
  p: TPointArray;
  r, s: TRange;
begin
  h := High(Self);
  SetLength(Result, 0);
  if (h < 0) then
    Exit;
  i := 0;
  while (i <= h) do
  begin
    y := Self[i].Y;
    p := Self.BinaryYPoints(y);
    if p.Empty then
    begin
      Inc(i);
      Continue;
    end;
    s.Create(0, High(p));
    r.start := -1;
    while (s.start <= s.stop) do
    begin
      m := s.Pivot;
      if (p[m].X >= xValue) then
      begin
        if (p[m].X = xValue) then
          r.start := m;
        s.stop := (m - 1);
      end else
        s.start := (m + 1);
    end;
    if (r.start = -1) then
    begin
      Inc(i);
      Continue;
    end;
    s.Create(0, High(p));
    r.stop := -1;
    while (s.start <= s.stop) do
    begin
      m := s.Pivot;
      if (p[m].X <= xValue) then
      begin
        if (p[m].X = xValue) then
          r.stop := m;
        s.start := (m + 1);
      end else
        s.stop := (m - 1);
    end;
    if (r.stop >= r.start) then
    begin
      a := ((r.stop - r.start) + 1);
      c := Result.Size;
      SetLength(Result, (c + a));
      for m := 0 to (a - 1) do
        Result[c + m] := p[r.start + m];
    end;
    Inc(i, p.Size);
  end;
end;

{==============================================================================]
  <BinaryGrouped>
  @action:
    Groups all points in the TPointArray by their Y-coordinate using binary search.
    Returns a T2DPointArray where each element is a TPointArray containing all
    points that share the same Y-value.
    The result is ordered by increasing Y, and contains only Y-rows that actually
    exist in the source array.
  @note:
    - The array must be sorted in **scanline order**:
      Y ascending, then X ascending for points with equal Y.
    - Internally uses BinaryYPoints to extract each Y-row efficiently.
    - Result length equals the number of unique Y-values present.
    - Empty rows (Y values with no points) are skipped.
[==============================================================================}
function TPointArrayHelper.BinaryGrouped: T2DPointArray; overload;
var
  r, h, i, l: Integer;
begin
  SetLength(Result, 0);
  h := High(Self);
  if (h > -1) then
  begin
    r := 0;
    l := Min((h + 1), ((Self[h].Y - Self[0].Y) + 1));
    SetLength(Result, l);
    for i := Self[0].Y to Self[h].Y do
      if (Result[r].Supply(Self.BinaryYPoints(i)) > -1) then
        Inc(r);
    if (r < l) then
      SetLength(Result, r);
  end;
end;

{==============================================================================]
  <BinaryExtract>
  @action: Returns all points within the specified rectangular area, using
           binary search on the Y-coordinate to minimize the scanned range.
  @note:   The array must be sorted in ascending Y order (scanline order).
           Only points satisfying:
               area.X1 ≤ X ≤ area.X2
               area.Y1 ≤ Y ≤ area.Y2
           are included in the output. The returned array preserves the
           original ordering of points with no duplicates.
[==============================================================================}
function TPointArrayHelper.BinaryExtract(const area: TBox): TPointArray; overload;
var
  R, Y: TRange;
  h, M, i, p, s: Integer;
begin
  SetLength(Result, 0);
  if Self.Empty then
    Exit;
  h := High(Self);
  R.Create(0, h);
  y.Create(-1);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Y >= area.Y1) then
    begin
      y.start := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  end;
  if (y.start = -1) then
    Exit;
  R.Create(y.start, h);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Y <= area.Y2) then
    begin
      y.stop := M;
      R.start := (M + 1);
    end else
      R.stop := (M - 1);
  end;
  if (y.stop = -1) then
    Exit;
  s := 0;
  for i := y.start to y.stop do
    if ((Self[i].X >= area.X1) and (Self[i].X <= area.X2)) then
      Inc(s);
  if (s = 0) then
    Exit;
  SetLength(Result, s);
  p := 0;
  for i := y.start to y.stop do
    if ((Self[i].X >= area.X1) and (Self[i].X <= area.X2)) then
      Result[p.Increase] := Self[i];
end;

{==============================================================================]
  <BinaryFilter>
  @action: Returns a new array containing all points that lie outside the
           specified rectangular area. The function uses binary search on the
           Y-coordinate to exclude the interior scanline interval efficiently.
  @note:   The array must be sorted in ascending Y order (scanline order).
           Points are excluded if and only if they satisfy:
               area.X1 ≤ X ≤ area.X2
               area.Y1 ≤ Y ≤ area.Y2
           All remaining points are preserved in their original order.
[==============================================================================}
function TPointArrayHelper.BinaryFilter(const area: TBox): TPointArray; overload;
var
  h, M, i, s, p: Integer;
  R, Y: TRange;
begin
  SetLength(Result, 0);
  if Self.Empty then
    Exit;
  h := High(Self);
  R.Create(0, h);
  Y.Create(-1);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Y >= area.Y1) then
    begin
      Y.start := M;
      R.stop := (M - 1);
    end else
      R.start := (M + 1);
  end;
  if (Y.start = -1) then
    Exit(Self.Copy);
  R.Create(Y.start, h);
  while (R.start <= R.stop) do
  begin
    M := R.Pivot;
    if (Self[M].Y <= area.Y2) then
    begin
      Y.stop := M;
      R.start := (M + 1);
    end else
      R.stop := (M - 1);
  end;
  if (Y.stop = -1) then
    Exit(Self.Copy);
  s := Y.start;
  Inc(s, (h - Y.stop));
  for i := Y.start to Y.stop do
    if ((Self[i].X < area.X1) or (Self[i].X > area.X2)) then
      Inc(s);
  if (s = 0) then
    Exit;
  SetLength(Result, s);
  p := 0;
  for i := 0 to (Y.start - 1) do
    Result[p.Increase] := Self[i];
  for i := Y.start to Y.stop do
    if ((Self[i].X < area.X1) or (Self[i].X > area.X2)) then
      Result[p.Increase] := Self[i];
  for i := (Y.stop + 1) to h do
    Result[p.Increase] := Self[i];
end;

{==============================================================================]
  <BinaryX>
  @action: Returns a sequence of X-values grouped by contiguous segments of equal Y within the TPointArray
          (which is assumed to be sorted by Y). For each block of points sharing the same Y value,
          the routine extracts the unique X values (unique within that Y-block)
          and inserts them into the output array in ascending order through binary growth.
  @note: The method performs a binary search on Y to locate each contiguous Y-block,
         then processes X values within the block. Uniqueness is enforced only within the same Y-group.
[==============================================================================}
function TPointArrayHelper.BinaryX: TIntegerArray; overload;
var
  h, i, y, m, k, x: Integer;
  s, r: TRange;
begin
  SetLength(Result, 0);
  h := High(Self);
  if (h < 0) then
    Exit;
  i := 0;
  while (i <= h) do
  begin
    y := Self[i].Y;
    r.Create(i, h);
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if (Self[m].Y > y) then
        r.stop := (m - 1)
      else
        r.start := (m + 1);
    end;
    s.Create(i, (r.start - 1));
    x := Low(Integer);
    for k := s.start to s.stop do
    begin
      if (x = Self[k].X) then
        Continue;
      x := Self[k].X;
      Result.BinaryGrow(x);
    end;
    i := (s.stop + 1);
  end;
end;

{==============================================================================]
  <BinaryY>
  @action: Returns a sequence of Y-values extracted from a TPointArray that is already sorted by Y.
           The method performs a run-length–style scan that groups contiguous points having non-decreasing Y values
           and emits one representative Y value for each such monotonic block.
  @note: The resulting array contains unique Y values only with respect to contiguous runs.
         Uniqueness is not guaranteed globally unless the underlying TPointArray is fully sorted by Y
         and contains no duplicated Y values in non-contiguous positions.
[==============================================================================}
function TPointArrayHelper.BinaryY: TIntegerArray; overload;
var
  h, i, y, m, l: Integer;
  r: TRange;
begin
  SetLength(Result, 0);
  h := High(Self);
  if (h < 0) then
    Exit;
  l := 0;
  i := 0;
  SetLength(Result, Self.Size);
  while (i <= h) do
  begin
    y := Self[i].Y;
    Result[l.Increase] := y;
    r.Create((i + 1), h);
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      if (Self[m].Y > y) then
        r.stop := (m - 1)
      else
        r.start := (m + 1);
    end;
    i := r.start;
  end;
  SetLength(Result, l);
end;

{==============================================================================]
  <BinaryInsertSorted>
  @action: Performs an insertion sort on a copy of the TPointArray using binary search
           to find the correct insertion position. Returns a new sorted TPointArray.
  @param: oAscending - Boolean indicating sort order. True = ascending (top-to-bottom, left-to-right),
                       False = descending (bottom-to-top, right-to-left).
  @note: The original array is not modified. Sorting is based on scanline order:
         first by Y coordinate, then by X if Y values are equal.
[==============================================================================}
function TPointArrayHelper.BinaryInsertSorted(const oAscending: Boolean = True): TPointArray; overload;
var
  K: TPoint;
  i, j, L, R, M, P: Integer;
begin
  Result := Self.Copy;
  for i := 1 to High(Result) do
  begin
    K := Result[i];
    L := 0;
    R := (i - 1);
    while (L <= R) do
    begin
      M := (L + ((R - L) div 2));
      if K.Lower(Result[M], oAscending) then
        R := (M - 1)
      else
        L := (M + 1);
    end;
    P := L;
    j := (i - 1);
    while (j >= P) do
      Result[j + 1] := Result[j.Decrease];
    Result[P] := K;
  end;
end;

{==============================================================================]
  <BinaryInsertSort>
  @action: Sorts the current TPointArray in-place using insertion sort with binary search
           to find the insertion position.
  @param: oAscending - Boolean indicating sort order. True = ascending (top-to-bottom, left-to-right),
                       False = descending (bottom-to-top, right-to-left).
  @return: Returns the length of the array after sorting (same as Length(Self)).
  @note: Sorting is done in scanline order: first by Y coordinate, then by X if Y values are equal.
[==============================================================================}
function TPointArrayHelper.BinaryInsertSort(const oAscending: Boolean = True): Integer; overload;
var
  K: TPoint;
  i, j, L, R, M, P: Integer;
begin
  Result := Self.Size;
  for i := 1 to (Result - 1) do
  begin
    K := Self[i];
    L := 0;
    R := (i - 1);
    while (L <= R) do
    begin
      M := (L + ((R - L) div 2));
      if K.Lower(Self[M], oAscending) then
        R := (M - 1)
      else
        L := (M + 1);
    end;
    P := L;
    j := (i - 1);
    while (j >= P) do
      Self[j + 1] := Self[j.Decrease];
    Self[P] := K;
  end;
end;

class function CPointArray.Init(var arr: TPointArray): Integer; overload; 
begin
  Result := Length(arr);
  if (Result > 0) then
    FillChar(arr[0], (Result * SizeOf(TPoint)), 0);
end;

class function CPointArray.Unique(var arr: TPointArray): Integer; overload; 
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

class function CPointArray.Create(const xRange, yRange: TRange): TPointArray; overload; 
var
  x, y, i: Integer;
begin
  SetLength(Result, (xRange.Size * yRange.Size));
  i := 0;
  for y in yRange do
    for x in xRange do
      Result[i.Increase] := Point(x, y);
end;

class function CPointArray.Create(const xRange, yRange: TRange; const offset: TPoint): TPointArray; overload; 
var
  x, y, i: Integer;
begin
  SetLength(Result, (xRange.Size * yRange.Size));
  i := 0;
  for y in yRange do
    for x in xRange do
      Result[i.Increase] := Point((x + offset.X), (y + offset.Y));
end;

class function CPointArray.Create(const xValues, yValues: TIntegerArray): TPointArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, Min(Length(xValues), Length(yValues)));
  for i := 0 to High(Result) do
    Result[i] := Point(xValues[i], yValues[i]);	
end;

class function CPointArray.Create(const xValues, yValues: TIntegerArray; const offset: TPoint): TPointArray; overload; 
var
  i: Integer;
begin
  SetLength(Result, Min(Length(xValues), Length(yValues)));
  for i := 0 to High(Result) do
    Result[i] := Point((xValues[i] + offset.X), (yValues[i] + offset.Y));	
end;
{$ENDIF}

{$UNDEF BASE}{$UNDEF TPoint}
