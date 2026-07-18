{$IFDEF METHODS}
function Build(const minX, minY, maxX, maxY: Integer): Integer; overload;
function Build(const pTop, pBottom: TPoint): Integer; overload;
function Build(const valueX, valueY: Integer): Integer; overload;
function Build(const target: TPoint): Integer; overload;
function Build(const value: Integer = 0): Integer; overload;
function Cast(const val: Integer = 0): TBox; overload;
function Cast(const sBox: TBox): TBox; overload;
function Cast(const sX1, sY1, sX2, sY2: Integer): TBox; overload;
class function Construct(const bXS, bYS, bXE, bYE: Integer): TBox; overload; static;
constructor Create(const minX, minY, maxX, maxY: Integer); overload;
constructor Create(const pTop, pBottom: TPoint); overload;
constructor Create(const valueX, valueY: Integer); overload;
constructor Create(const target: TPoint); overload;
constructor Create(const value: Integer); overload;
function Form(const pt: TPoint; const size: Integer = 1): TBox; overload;
function Form(const pt: TPoint; const width, height: Integer): TBox; overload;
function Init(const bX1, bY1, bX2, bY2: Integer): TBox; overload;
function Init(const b: TBox): TBox; overload;
function Init(const val: Integer = 0): TBox; overload;
function Init(const p: TPoint): TBox; overload;
function Init(const TL, BR: TPoint): TBox; overload;
function Make(const pt: TPoint; const radius: Integer = 0): TBox; overload;
function Make(const pt: TPoint; const wRadius, hRadius: Integer): TBox; overload;
{$ENDIF}

{$IFDEF HELPERS}
function Create: TBox; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Box(const bX1, bY1, bX2, bY2: Integer): TBox; overload;
function Box(const val: Integer = 0): TBox; overload;
function B(const XS, YS, XE, YE: Integer): TBox; overload;
function B(const val: Integer = 0): TBox; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Build>
  @action: Creates TBox using minX, minY, maxX, maxY
  @note: Min-Maxed. Creates only valid TBoxes. Returns area.
[==============================================================================}
function TBox.Build(const minX, minY, maxX, maxY: Integer): Integer; overload;
begin
  Self.X1 := Min(minX, maxX);
  Self.Y1 := Min(minY, maxY);
  Self.X2 := Max(maxX, minX);
  Self.Y2 := Max(maxY, minY);
  Result := Self.Area;
end;

{==============================================================================]
  <Build>
  @action: Builds TBox using 2 points (a = start point, b = end point)..
  @note: Make sure start and end points are correct!
[==============================================================================}
function TBox.Build(const pTop, pBottom: TPoint): Integer; overload;
begin
  Result := Self.Build(pTop.X, pTop.Y, pBottom.X, pBottom.Y);
end;

{==============================================================================]
  <Build>
  @action: We simply build using
  @note: Constructor.
[==============================================================================}
function TBox.Build(const valueX, valueY: Integer): Integer; overload;
begin
  Result := Self.Build(valueX, valueY, valueX, valueY);
end;

{==============================================================================]
  <Build>
  @action: Creates TBox using target TPoint
  @note: Constructor.
[==============================================================================}
function TBox.Build(const target: TPoint): Integer; overload;
begin
  Result := Self.Build(target.X, target.Y, target.X, target.Y)
end;

{==============================================================================]
  <Build>
  @action: We simply build using value.
  @note: Constructor.
[==============================================================================}
function TBox.Build(const value: Integer = 0): Integer; overload;
begin
  Result := Self.Build(value, value, value, value);
end;

{==============================================================================]
  <Cast>
  @action: Reconstructs the box in place as a single-point box, returning
           the box as it existed prior to this call.
  @note:
    - X1, Y1, X2, and Y2 are all overwritten with val, collapsing the box
      to a single degenerate point (defaults to 0 if omitted).
    - The returned TBox reflects the PRIOR coordinates, not the newly
      assigned ones — callers needing the updated box should inspect Self
      after the call, not the function result.
    - Overload of Cast(sBox: TBox) / Cast(sX1, sY1, sX2, sY2: Integer),
      collapsing to a point box from a single scalar instead of a source
      TBox or four discrete coordinates.
[==============================================================================}
function TBox.Cast(const val: Integer = 0): TBox; overload;
begin
  Result := Self;
  Self.X1 := val;
  Self.Y1 := val;
  Self.X2 := val;
  Self.Y2 := val;
end;

{==============================================================================]
  <Cast>
  @action: Reconstructs the box in place from another TBox, returning the
           box as it existed prior to this call.
  @note:
    - Self is overwritten field-by-field with sBox's coordinates.
    - The returned TBox reflects the PRIOR coordinates, not the newly
      assigned ones — callers needing the updated box should inspect Self
      after the call, not the function result.
    - Overload of Cast(val: Integer) / Cast(sX1, sY1, sX2, sY2: Integer),
      accepting a full TBox as the replacement source instead of a single
      scalar or discrete coordinates.
[==============================================================================}
function TBox.Cast(const sBox: TBox): TBox; overload;
begin
  Result := Self;
  Self.X1 := sBox.X1;
  Self.Y1 := sBox.Y1;
  Self.X2 := sBox.X2;
  Self.Y2 := sBox.Y2;
end;

{==============================================================================]
  <Cast>
  @action: Reconstructs the box's coordinates in place from four discrete
           values, returning the box as it existed prior to this call.
  @note:
    - X1, Y1, X2, and Y2 are overwritten unconditionally with the supplied
      sX1, sY1, sX2, sY2 values.
    - The returned TBox reflects the PRIOR coordinates, not the newly
      assigned ones — callers needing the updated box should inspect Self
      after the call, not the function result.
    - Overload of Cast(val: Integer) / Cast(sBox: TBox), accepting four
      discrete coordinates as the replacement source instead of a single
      scalar or a source TBox.
[==============================================================================}
function TBox.Cast(const sX1, sY1, sX2, sY2: Integer): TBox; overload;
begin
  Result := Self;
  Self.X1 := sX1;
  Self.Y1 := sY1;
  Self.X2 := sX2;
  Self.Y2 := sY2;
end;

{==============================================================================]
  <Construct>
  @action: Constructs TBox with XS, YS, XE, YE.
  @note: None.
[==============================================================================}
class function TBox.Construct(const bXS, bYS, bXE, bYE: Integer): TBox; overload;
begin
  Result.X1 := bXS;
  Result.Y1 := bYS;
  Result.X2 := bXE;
  Result.Y2 := bYE;
end;

{==============================================================================]
  <Create>
  @action: Creates TBox using minX, minY, maxX, maxY
  @note: Constructor.
[==============================================================================}
constructor TBox.Create(const minX, minY, maxX, maxY: Integer); overload;
begin
  X1 := minX;
  Y1 := minY;
  X2 := maxX;
  Y2 := maxY;
end;

{==============================================================================]
  <Create>
  @action: Creates TBox using top and bottom TPoint (top contains minX,minY and bottom contains maxX,maxY)
  @note: Constructor.
[==============================================================================}
constructor TBox.Create(const pTop, pBottom: TPoint); overload;
begin
  Self.Create(pTop.X, pTop.Y, pBottom.X, pBottom.Y);
end;

{==============================================================================]
  <Create>
  @action: We simply build using
  @note: Constructor.
[==============================================================================}
constructor TBox.Create(const valueX, valueY: Integer); overload;
begin
  Self.Create(valueX, valueY, valueX, valueY);
end;

{==============================================================================]
  <Create>
  @action: Creates TBox using target TPoint
  @note: Constructor.
[==============================================================================}
constructor TBox.Create(const target: TPoint); overload;
begin
  Self.Create(target.X, target.Y, target.X, target.Y);
end;

{==============================================================================]
  <Create>
  @action: We simply build using value.
  @note: Constructor.
[==============================================================================}
constructor TBox.Create(const value: Integer); overload;
begin
  Self.Create(value, value, value, value);
end;

{==============================================================================]
  <Create>
  @action: Creates TBox(0,0,0,0).
  @note: None
[==============================================================================}
function TBoxHelper.Create: TBox; overload;
begin
  Self.X1 := 0;
  Self.Y1 := 0;
  Self.X2 := 0;
  Self.Y2 := 0;
  Result := Self;
end;

{==============================================================================]
  <Form>
  @action: Creates box to point, with size for width and height.
  @note: None.
[==============================================================================}
function TBox.Form(const pt: TPoint; const size: Integer = 1): TBox; overload;
begin
  Self.X1 := pt.X;
  Self.Y1 := pt.Y;
  Self.X2 := (pt.X + (size - 1));
  Self.Y2 := (pt.Y + (size - 1));
  Result := Self;
end;

{==============================================================================]
  <Form>
  @action: Creates box to point, with width and height.
  @note: None.
[==============================================================================}
function TBox.Form(const pt: TPoint; const width, height: Integer): TBox; overload;
begin
  Self.X1 := pt.X;
  Self.Y1 := pt.Y;
  Self.X2 := (pt.X + (width - 1));
  Self.Y2 := (pt.Y + (height - 1));
  Result := Self;
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TRange with the specified X1, Y1, X2, Y2 values.
           Also returns the initialized record so it can be assigned in-line.
  @note: Useful for initializing a TBox instance and simultaneously returning it
         for assignment. Example: a := b.Init(2,2,8,8);
[==============================================================================}
function TBox.Init(const bX1, bY1, bX2, bY2: Integer): TBox; overload;
begin
  Self.X1 := bX1;
  Self.Y1 := bY1;
  Self.X2 := bX2;
  Self.Y2 := bY2;
  Result.X1 := bX1;
  Result.Y1 := bY1;
  Result.X2 := bX2;
  Result.Y2 := bY2;
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TBox as a copy of another TBox.
           Also returns the copied record.
  @note: Useful for copying values from an existing TBox while allowing in-line assignment.
         Example: a := b.Init(c);
[==============================================================================}
function TBox.Init(const b: TBox): TBox; overload;
begin
  Self := b;
  Result := b;
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TBox with all X1, Y1, X2, Y2 set to the same value.
           Also returns the initialized record.
  @note: The parameter has a default of 0, allowing zero-initialization.
         Example: a := b.Init; or a := b.Init(5);
[==============================================================================}
function TBox.Init(const val: Integer = 0): TBox; overload;
begin
  Self.X1 := val;
  Self.Y1 := val;
  Self.X2 := val;
  Self.Y2 := val;
  Result.X1 := val;
  Result.Y1 := val;
  Result.X1 := val;
  Result.Y2 := val;
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TBox as a copy with TPoint.
           Also returns the copied record.
  @note: Useful for copying values from an existing TBox while allowing in-line assignment.
         Example: a := b.Init(p);
[==============================================================================}
function TBox.Init(const p: TPoint): TBox; overload;
begin
  Self.X1 := p.X;
  Self.Y1 := p.Y;
  Self.X2 := p.X;
  Self.Y2 := p.Y;
  Result.X1 := p.X;
  Result.Y1 := p.Y;
  Result.X1 := p.X;
  Result.Y2 := p.Y;
end;

{==============================================================================]
  <Init>
  @action: Initializes the current TBox as a copy with Top-Left and Bottom-Right TPoints.
           Also returns the copied record.
  @note: Useful for copying values from an existing TBox while allowing in-line assignment.
         Example: a := b.Init(c, d);
[==============================================================================}
function TBox.Init(const TL, BR: TPoint): TBox; overload;
begin
  Self.X1 := TL.X;
  Self.Y1 := TL.Y;
  Self.X2 := BR.X;
  Self.Y2 := BR.Y;
  Result.X1 := TL.X;
  Result.Y1 := TL.Y;
  Result.X1 := BR.X;
  Result.Y2 := BR.Y;
end;

{==============================================================================]
  <Make>
  @action: Creates TBox from pt by radius used for width and height.
  @note: None.
[==============================================================================}
function TBox.Make(const pt: TPoint; const wRadius, hRadius: Integer): TBox; overload;
begin
  Self.X1 := (pt.X - wRadius);
  Self.Y1 := (pt.Y - hRadius);
  Self.X2 := (pt.X + wRadius);
  Self.Y2 := (pt.Y + hRadius);
  Result := Self;
end;

{==============================================================================]
  <Make>
  @action: Creates TBox from pt by radius used for width and height.
  @note: None.
[==============================================================================}
function TBox.Make(const pt: TPoint; const radius: Integer = 0): TBox; overload;
begin
  Result := Self.Make(pt, radius, radius);
end;

function Box(const bX1, bY1, bX2, bY2: Integer): TBox; overload;
begin
  Result.X1 := bX1;
  Result.Y1 := bY1;
  Result.X2 := bX2;
  Result.Y2 := bY2;
end;

function Box(const val: Integer = 0): TBox; overload;
begin
  Result.X1 := val;
  Result.Y1 := val;
  Result.X2 := val;
  Result.Y2 := val;
end;

function B(const XS, YS, XE, YE: Integer): TBox; overload;
begin
  Result.X1 := XS;
  Result.Y1 := YS;
  Result.X2 := XE;
  Result.Y2 := YE;
end;

function B(const val: Integer = 0): TBox; overload;
begin
  Result.X1 := val;
  Result.Y1 := val;
  Result.X2 := val;
  Result.Y2 := val;
end;
{$ENDIF}
