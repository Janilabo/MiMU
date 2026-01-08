{$IFDEF METHODS}
function Build(const pX, pY: Integer): TPoint; cdecl; inline;
class function Construct(const pX, pY: Integer): TPoint; overload; cdecl; static;
constructor Create(const pX, pY: Integer); overload;
constructor Create(const value: Integer); overload;
{$ENDIF}

{$IFDEF HELPERS}
function Create: TPoint; overload; cdecl;
{$ENDIF}

{$IFDEF FUNCTIONS}
function Point(const pX, pY: Integer): TPoint; overload; cdecl; inline;
function Point(const val: Integer = 0): TPoint; overload; cdecl; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Build>
  @action: Returns TPoint with X and Y.
  @note: None.
[==============================================================================}
function TPoint.Build(const pX, pY: Integer): TPoint; cdecl; inline;
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
class function TPoint.Construct(const pX, pY: Integer): TPoint; overload; cdecl;
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
function TPointHelper.Create: TPoint; overload; cdecl;
begin
  Self.X := 0;
  Self.Y := 0;
  Result := Self;
end;

function Point(const pX, pY: Integer): TPoint; overload; cdecl; inline;
begin
  Result.X := pX;
  Result.Y := pY;
end;

function Point(const val: Integer = 0): TPoint; overload; cdecl; inline;
begin
  Result.X := val;
  Result.Y := val;
end;
{$ENDIF}