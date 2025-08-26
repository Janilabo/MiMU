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
  <TSegment.Bounds>
  @action: Returns the bounds of TSegment as TBox.
  @note: None.
[==============================================================================}
function TSegment.Bounds: TBox; cdecl;
begin
  Result.Create(Min(Self.A.X, Self.B.X), Min(Self.A.Y, Self.B.Y), Max(Self.A.X, Self.B.X), Max(Self.A.Y, Self.B.Y));
end;

{==============================================================================]
  <TSegment.Boundaries>
  @action: Returns the bounds of TSegment as TBox.
  @note: None.
[==============================================================================}
function TSegment.Boundaries: TBox; cdecl;
begin
  with Self do
  Result := Box(IfThen((A.X < B.X), A.X, B.X), IfThen((A.Y < B.Y), A.Y, B.Y), IfThen((A.X > B.X), A.X, B.X), IfThen((A.Y > B.Y), A.Y, B.Y));
end;

{==============================================================================]
  <TSegment.Envelope>
  @action: Returns the bounds of TSegment as TBox.
  @note: None.
[==============================================================================}
function TSegment.Envelope: TBox; cdecl;
begin
  case Bitify((Self.A.X < Self.B.X), (Self.A.Y < Self.B.Y)) of
    0: Result.Create(Self.B.X, Self.B.Y, Self.A.X, Self.A.Y);
    1: Result.Create(Self.B.X, Self.A.Y, Self.A.X, Self.B.Y);
    2: Result.Create(Self.A.X, Self.B.Y, Self.B.X, Self.A.Y);
    3: Result.Create(Self.A.X, Self.A.Y, Self.B.X, Self.B.Y);
  end;
end;

{==============================================================================]
 <TSegment.Points>
 @action: Returns all the points of TSegment.
 @note: None.
[==============================================================================}
function TSegment.Points: TPointArray; cdecl;
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

{==============================================================================]
 <TSegment.Pixels>
 @action: Returns the points of TSegment.
 @note: Supports custom steps.
[==============================================================================}
function TSegment.Pixels(const steps: Integer = 2147483647): TPointArray; cdecl;
var
  i, h: Integer;
begin
  h := (Max(2, Min(steps, (Max(Abs(Self.B.X - Self.A.X), Abs(Self.B.Y - Self.A.Y)) + 1))) - 1);
  SetLength(Result, (h + 1));
  for i := 0 to h do
    Result[i] := Point(Round(Self.A.X + ((i / h) * (Self.B.X - Self.A.X))), Round(Self.A.Y + ((i / h) * (Self.B.Y - Self.A.Y))));
end;
