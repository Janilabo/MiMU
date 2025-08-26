{==============================================================================]
  <TSegment.Construct>
  @action: Constructs TSegment with sA and sB points.
  @note: None.
[==============================================================================}
constructor TSegment.Create(const sA, sB: TPoint); overload;
begin
  Self.A := sA;
  Self.B := sB;
end;

{==============================================================================]
  <TSegment.Create>
  @action: Create a TSegment with aX, aY and bX, bY coordinates.
  @note: None.
[==============================================================================}
constructor TSegment.Create(const aX, aY, bX, bY: Integer); overload;
begin
  Self.A := Point(aX, aY);
  Self.B := Point(bX, bY);
end;

{==============================================================================]
  <TSegment.Construct>
  @action: Constructs TSegment with sA and sB points.
  @note: None.
[==============================================================================}
class function TSegment.Construct(const sA, sB: TPoint): TSegment; overload; cdecl;
begin
  Result.A := sA;
  Result.B := sB;
end;

{==============================================================================]
  <TSegment.Construct>
  @action: Constructs TSegment with aX, aY, bX, bY.
  @note: None.
[==============================================================================}
class function TSegment.Construct(const aX, aY, bX, bY: Integer): TSegment; overload; cdecl;
begin
  Result.A := Point(aX, aY);
  Result.B := Point(bX, bY);
end;

{==============================================================================]
 <TSegment.Points>
 @action: Returns the points of TSegment.
 @note: Supports custom steps.
[==============================================================================}
function TSegment.Points(const steps: Integer = 2147483647): TPointArray; cdecl;
var
  i, h: Integer;
begin
  h := (Max(2, Min(steps, (Max(Abs(Self.B.X - Self.A.X), Abs(Self.B.Y - Self.A.Y)) + 1))) - 1);
  SetLength(Result, (h + 1));
  for i := 0 to h do
    Result[i] := Point(Round(Self.A.X + ((i / h) * (Self.B.X - Self.A.X))), Round(Self.A.Y + ((i / h) * (Self.B.Y - Self.A.Y))));
end;

{==============================================================================]
 <TSegment.Pixels>
 @action: Returns all the points of TSegment.
 @note: None.
[==============================================================================}
function TSegment.Pixels: TPointArray; cdecl;
var
  l: TBox;
  s, i: Integer;
  v, h, x, y: Double;
  d: TPoint;
begin
  with Self do
  begin
    l.Create(A, B);
    d.X := (l.X2 - l.X1);
    d.Y := (l.Y2 - l.Y1);
    if (Abs(d.X) > Abs(d.Y)) then
      s := Abs(d.X)
    else
      s := Abs(d.Y);
    SetLength(Result, (s + 1));
    x := l.X1;
    y := l.Y1;
    h := (d.X / s);
    v := (d.Y / s);
    for i := 0 to s do
      Result[i] := Point(Round(x.Increase(h)), Round(y.Increase(v)));
  end;
end;