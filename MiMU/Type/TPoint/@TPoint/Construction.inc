{$IFDEF METHODS}
function Apply(const source: TPoint): TPoint; overload;
function Apply(const val: Integer = 0): TPoint; overload;
function Assign(const val: Integer = 0): TPoint; overload;
function Assign(const pX, pY: Integer): TPoint; overload;
function Build(const pX, pY: Integer): TPoint; overload;
class function Construct(const pX, pY: Integer): TPoint; overload; static;
constructor Create(const pX, pY: Integer); overload;
constructor Create(const value: Integer); overload;
{$ENDIF}

{$IFDEF HELPERS}
function Create: TPoint; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Point(const pX, pY: Integer): TPoint; overload;
function Point(const val: Integer = 0): TPoint; overload;
function P(const xVal, yVal: Integer): TPoint; overload;
function P(const val: Integer = 0): TPoint; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Apply>
  @action: Overwrites the X and Y coordinates of this point with the values from 
           the source point.
  @note: Returns a snapshot of this point's original coordinates before the 
         new values are applied.
[==============================================================================}
function TPoint.Apply(const source: TPoint): TPoint; overload;
begin
  Result.X := Self.X;
  Result.Y := Self.Y;
  Self.X := source.X;
  Self.Y := source.Y;
end;

{==============================================================================]
  <Apply>
  @action: Updates both coordinates of this point to a uniform integer value 
           (defaults to 0).
  @note: Returns a snapshot of this point's original state.
[==============================================================================}
function TPoint.Apply(const val: Integer = 0): TPoint; overload;
begin
  Result := Self.Apply(Point(val, val));
end;

{==============================================================================]
  <Assign>
  @action: Sets both X and Y coordinates to a uniform value (defaults to 0).
  @note: Returns the original state of the point before the new value is applied.
[==============================================================================}
function TPoint.Assign(const val: Integer = 0): TPoint; overload;
begin
  Result := Self;
  Self.X := val;
  Self.Y := val;
end;

{==============================================================================]
  <Assign>
  @action: Sets the X and Y coordinates to the specified distinct values.
  @note: Returns the original state of the point before the new values are applied.
[==============================================================================}
function TPoint.Assign(const pX, pY: Integer): TPoint; overload;
begin
  Result := Self;
  Self.X := pX;
  Self.Y := pY;
end;

{==============================================================================]
  <Build>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
function TPoint.Build(const pX, pY: Integer): TPoint; overload;
begin
  Self.X := pX;
  Self.Y := pY;
  Result := Self;
end;

{==============================================================================]
  <Create>
  @action: Constructs new TPoint with pX and pY.
  @note: None.
[==============================================================================}
class function TPoint.Construct(const pX, pY: Integer): TPoint; overload;
begin
  Result.X := pX;
  Result.Y := pY;
end;

{==============================================================================]
  <Create>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
constructor TPoint.Create(const pX, pY: Integer); overload;
begin
  Self.X := pX;
  Self.Y := pY;
end;

{==============================================================================]
  <Create>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
constructor TPoint.Create(const value: Integer); overload;
begin
  Self.Create(value, value);
end;

{==============================================================================]
  <Create>
  @action: Returns TPoint 0,0.
  @note: None.
[==============================================================================}
function TPointHelper.Create: TPoint; overload;
begin
  Self.X := 0;
  Self.Y := 0;
  Result := Self;
end;

function Point(const pX, pY: Integer): TPoint; overload;
begin
  Result.X := pX;
  Result.Y := pY;
end;

function Point(const val: Integer = 0): TPoint; overload;
begin
  Result.X := val;
  Result.Y := val;
end;

function P(const xVal, yVal: Integer): TPoint; overload;
begin
  Result.X := xVal;
  Result.Y := yVal;
end;

function P(const val: Integer = 0): TPoint; overload;
begin
  Result.X := val;
  Result.Y := val;
end;
{$ENDIF}
