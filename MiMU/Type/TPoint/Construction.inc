{$IFDEF TYPES}
constructor Create(const pX, pY: Integer); overload;
constructor Create(const value: Integer); overload;
class function Construct(const pX, pY: Integer): TPoint; overload; static;
function Build(const pX, pY: Integer): TPoint;  inline;
{$ENDIF}

{$IFDEF HELPERS}
function Create: TPoint; overload;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Point(const pX, pY: Integer): TPoint; overload; inline;
function Point(const val: Integer = 0): TPoint; overload; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  <Build>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
function TPoint.Build(const pX, pY: Integer): TPoint; inline;
begin
  Self.X := pX;
  Self.Y := pY;
  Result := Self;
end;
{$ENDIF}