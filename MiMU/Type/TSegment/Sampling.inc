{$IFDEF METHODS}
function Pixels(const steps: Integer = 2147483647): TPointArray; cdecl;
function Points: TPointArray; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
 <Pixels>
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

{==============================================================================]
 <Points>
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
{$ENDIF}