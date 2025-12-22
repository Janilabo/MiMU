{$IFDEF TYPES}
function HypotEuclidean(const target: TPoint): Double; overload;	
function Euclidean(const target: TPoint): Double; overload;
function Euclidean2(const target: TPoint): Double; overload;
function SquaredEuclidean(const target: TPoint): Double; overload;
function Manhattan(const target: TPoint): Double; overload;
function Chebyshev(const target: TPoint): Double; overload;
function Minkowski(const target: TPoint): Double; overload;
function Minkowski(const target: TPoint; const P: Double): Double; overload;
function MaxMinChebyshev(const target: TPoint): Double; overload;
function Octile(const target: TPoint): Double; overload;
{$ENDIF}

{$IFDEF HELPERS}
function Dist(const target: TPoint; const metric: TMetrics = dmEuclidean): Double; overload;
{$ENDIF}

{$IFDEF METHODS}
function HypotEuclidean(const A, B: TPoint): Double; overload;
function Euclidean(const A, B: TPoint): Double; overload;
function Euclidean2(const A, B: TPoint): Double; overload;
function SquaredEuclidean(const A, B: TPoint): Double; overload;
function Manhattan(const A, B: TPoint): Double; overload;
function Chebyshev(const A, B: TPoint): Double; overload;
function Minkowski(const A, B: TPoint): Double; overload;
function Minkowski(const A, B: TPoint; const P: Double): Double; overload;
function MaxMinChebyshev(const A, B: TPoint): Double; overload;
function Octile(const A, B: TPoint): Double; overload;
function Distance(const distFunc: TDistance): TDistance; overload;
function Distance(const method: Integer = 0): TDistance; overload;
function Distance(const metric: TMetrics): TDistance; overload;
function Distance(const A, B: TPoint; const distFunc: TDistance): Double; overload;
function Distance(const A, B: TPoint; const metric: TMetrics = dmEuclidean): Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <DistHypotEuclidean>
  @action: Calculates the distance from source to target.
  @note: Euclidean.
[==============================================================================}
function TPoint.HypotEuclidean(const target: TPoint): Double; overload;
begin
  Result := Hypot((Self.X - target.X), (Self.Y - target.Y));
end;

{==============================================================================]
  <DistEuclidean>
  @action: Calculates the distance from source to target.
  @note: Euclidean.
[==============================================================================}
function TPoint.Euclidean(const target: TPoint): Double; overload;
begin
  Result := (Sqrt(Sqr(Self.X - target.X) + Sqr(Self.Y - target.Y)));
end;

{==============================================================================]
  <DistEuclidean2>
  @action: Calculates the distance from source to target.
  @note: Euclidean v2
[==============================================================================}
function TPoint.Euclidean2(const target: TPoint): Double; overload;
begin
  Result := Sqrt(Power((Self.X - target.X), 2) + Power((Self.Y - target.Y), 2));
end;

{==============================================================================]
  <DistSquaredEuclidean>
  @action: Calculates the distance from source to target.
  @note: Squared Euclidean
[==============================================================================}
function TPoint.SquaredEuclidean(const target: TPoint): Double; overload;
begin
  Result := (Sqr(Self.X - target.X) + Sqr(Self.Y - target.Y));
end;

{==============================================================================]
  <DistManhattan>
  @action: Calculates the distance from source to target.
  @note: Manhattan
[==============================================================================}
function TPoint.Manhattan(const target: TPoint): Double; overload;
begin
  Result := (Abs(Self.X - target.X) + Abs(Self.Y - target.Y));
end;

{==============================================================================]
  <DistChebyshev>
  @action: Calculates the distance from source to target.
  @note: Chebyshev
[==============================================================================}
function TPoint.Chebyshev(const target: TPoint): Double; overload;
begin
  Result := Max(Abs(Self.X - target.X), Abs(Self.Y - target.Y));
end;

{==============================================================================]
  <DistMinkowski>
  @action: Calculates the distance from source to target.
  @note: Minkowski
[==============================================================================}
function TPoint.Minkowski(const target: TPoint): Double; overload;
begin
  Result := Power(Power(Abs(Self.X - target.X), 2.0) + Power(Abs(Self.Y - target.Y), 2.0), (1 / 2.0)); 
end;

{==============================================================================]
  <DistMinkowski>
  @action: Calculates the distance from source to target.
  @note: Minkowski
[==============================================================================}
function TPoint.Minkowski(const target: TPoint; const P: Double): Double; overload;
begin
  Result := Power(Power(Abs(Self.X - target.X), P) + Power(Abs(Self.Y - target.Y), P), (1 / P));
end;

{==============================================================================]
  <DistMaxMinChebyshev>
  @action: Calculates the distance from source to target.
  @note: Max-Min Chebyshev
[==============================================================================}
function TPoint.MaxMinChebyshev(const target: TPoint): Double; overload;
begin
  Result := Max(Max(Self.X, target.X) - Min(Self.X, target.X), Max(Self.Y, target.Y) - Min(Self.Y, target.Y));
end;

{==============================================================================]
  <DistOctile>
  @action: Calculates the distance from source to target.
  @note: Octile
[==============================================================================}
function TPoint.Octile(const target: TPoint): Double; overload;
var
  h, v: Integer;
begin
  h := Abs(Self.X - target.X);
  v := Abs(Self.Y - target.Y);
  Result := (Max(h, v) + (Sqrt(2) - 1) * Min(h, v));
end;

{==============================================================================]
  <Dist>
  @action: Calculates the distance from source to target.
  @note: Octile
[==============================================================================}
function TPointHelper.Dist(const target: TPoint; const metric: TMetrics = dmEuclidean): Double; overload;
begin
  Result := Distance(Self, target, metric);
end;

function HypotEuclidean(const A, B: TPoint): Double; overload;
begin
  Result := Hypot(A.X - B.X, A.Y - B.Y);
end;

function Euclidean(const A, B: TPoint): Double; overload;
begin
  Result := (Sqrt(Sqr(A.X - B.X) + Sqr(A.Y - B.Y)));
end;

function Euclidean2(const A, B: TPoint): Double; overload;
begin
  Result := Sqrt(Power((A.X - B.X), 2) + Power((A.Y - B.Y), 2));
end;

function SquaredEuclidean(const A, B: TPoint): Double; overload;
begin
  Result := (Sqr(A.X - B.X) + Sqr(A.Y - B.Y));
end;

function Manhattan(const A, B: TPoint): Double; overload;
begin
  Result := (Abs(A.X - B.X) + Abs(A.Y - B.Y));
end;

function Chebyshev(const A, B: TPoint): Double; overload;
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

function MaxMinChebyshev(const A, B: TPoint): Double; overload;
begin
  Result := Max(Max(A.X, B.X) - Min(A.X, B.X), Max(A.Y, B.Y) - Min(A.Y, B.Y));
end;

function Octile(const A, B: TPoint): Double; overload;
var
  h, v: Integer;
begin
  h := Abs(A.X - B.X);
  v := Abs(A.Y - B.Y);
  Result := (Max(h, v) + (Sqrt(2) - 1) * Min(h, v));
end;

function Distance(const distFunc: TDistance): TDistance; overload;
begin
  Result := distFunc;
  if not Assigned(Result) then
    Result := @Euclidean;
end;

function Distance(const method: Integer = 0): TDistance; overload;
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

function Distance(const metric: TMetrics): TDistance; overload;
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

function Distance(const A, B: TPoint; const distFunc: TDistance): Double; overload;
begin
  Result := distFunc(A, B);
end;

function Distance(const A, B: TPoint; const metric: TMetrics = dmEuclidean): Double; overload;
begin
  Result := Distance(A, B, Distance(metric));
end;
{$ENDIF}