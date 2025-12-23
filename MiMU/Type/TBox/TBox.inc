{$DEFINE TBox}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
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
  {$I TBox.pph}
  function GetEnumerator: TBoxEnumerator; 
end;
{$I ../Type.inc}
_TBox = class
public
  class function Create(const minX, minY, maxX, maxY: Integer): TBox; overload; 
  class function Create(const top, bottom: TPoint): TBox; overload; 
  class function Create(const valueX, valueY: Integer): TBox; overload; 
  class function Create(const target: TPoint): TBox; overload; 
  class function Create(const value: Integer = 0): TBox; overload; 
end;
{$ENDIF}

{$IFDEF HELPERS}
TBoxHelper = type helper for TBox
  {$I ../Type.inc}
  {$I TBox.pph}
end;
{$ENDIF}

{$IFDEF OPERATORS}
operator +(const a, b: TBox): TBox;
operator -(const a, b: TBox): TBox;
operator =(const a, b: TBox): Boolean;
operator <>(const a, b: TBox): Boolean;

operator in(const P: TPoint; const B: TBox): Boolean;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS)}
{$I ../Type.inc}
{$I TBox.pph}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <+>
  @action: Computes the union of two boxes. The resulting box fully contains
           both input boxes.
  @note:   Supports any coordinate ordering; assumes X1 <= X2 and Y1 <= Y2 after normalization.
[==============================================================================}
operator +(const a, b: TBox): TBox;
begin
  Result.X1 := Min(a.X1, b.X1);
  Result.Y1 := Min(a.Y1, b.Y1);
  Result.X2 := Max(a.X2, b.X2);
  Result.Y2 := Max(a.Y2, b.Y2);
end;

{==============================================================================]
  <->
  @action: Computes the intersection of two boxes. Returns a box representing the 
           overlapping area of `a` and `b`. If the boxes do not overlap, returns 
           a null box marker.
  @note:   A null box can be represented by `TBox.Null` (e.g., all coordinates = Low(Integer)).
           This function does not require the boxes to be normalized beforehand, but
           you may normalize them for consistent behavior.
[==============================================================================}
operator -(const a, b: TBox): TBox;
begin
  if ((a.X2 < b.X1) or (b.X2 < a.X1) or (a.Y2 < b.Y1) or (b.Y2 < a.Y1)) then
    Exit(TBox.Null);
  Result.X1 := Max(a.X1, b.X1);
  Result.Y1 := Max(a.Y1, b.Y1);
  Result.X2 := Min(a.X2, b.X2);
  Result.Y2 := Min(a.Y2, b.Y2);
end;

operator =(const a, b: TBox): Boolean;
begin
  Result := ((a.X1 = b.X1) and (a.Y1 = b.Y1) and (a.X2 = b.X2) and (a.Y2 = b.Y2));
end;

operator <>(const a, b: TBox): Boolean;
begin
  Result := not ((a.X1 = b.X1) and (a.Y1 = b.Y1) and (a.X2 = b.X2) and (a.Y2 = b.Y2));
end;

operator in(const P: TPoint; const B: TBox): Boolean;
begin
  Result := B.Contains(P);
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

{==============================================================================]
  <Create>
  @action: Creates TBox using minX, minY, maxX, maxY 
  @note: function version
[==============================================================================}
class function _TBox.Create(const minX, minY, maxX, maxY: Integer): TBox; overload;
begin
  Result.X1 := minX;
  Result.Y1 := minY;
  Result.X2 := maxX;
  Result.Y2 := maxY;
end;

{==============================================================================]
  <Create>
  @action: Creates TBox using top and bottom TPoint (top contains minX,minY and bottom contains maxX,maxY) 
  @note: Constructor.
[==============================================================================}
class function _TBox.Create(const top, bottom: TPoint): TBox; overload;
begin
  Result := _TBox.Create(top.X, top.Y, bottom.X, bottom.Y);
end;

{==============================================================================]
  <Create>
  @action: We simply build using  
  @note: Function.
[==============================================================================}
class function _TBox.Create(const valueX, valueY: Integer): TBox; overload;
begin
  Result := _TBox.Create(valueX, valueY, valueX, valueY);
end;

{==============================================================================]
  <Create>
  @action: Creates TBox using target TPoint 
  @note: Function.
[==============================================================================}
class function _TBox.Create(const target: TPoint): TBox; overload;
begin
  Result := _TBox.Create(target.X, target.Y, target.X, target.Y);
end;

{==============================================================================]
  <Create>
  @action: We simply build using value. 
  @note: Constructor.
[==============================================================================}
class function _TBox.Create(const value: Integer = 0): TBox; overload;
begin
  Result := _TBox.Create(value, value, value, value);
end;
{$ENDIF}

{$UNDEF BASE}{$UNDEF TBox}
