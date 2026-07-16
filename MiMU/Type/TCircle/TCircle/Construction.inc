{$IFDEF METHODS}
class function Construct(const cCenter: TPoint; const cRadius: Double): TCircle; overload; static;
class function Construct(const centerX, centerY: Integer; const cRadius: Double): TCircle; overload; static;
constructor Create(const cCenter: TPoint; const cRadius: Double); overload;
constructor Create(const centerX, centerY: Integer; const cRadius: Double); overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Construct>
  @action: Constructs TCircle with cCenter and cRadius.
  @note: None.
[==============================================================================}
class function TCircle.Construct(const cCenter: TPoint; const cRadius: Double): TCircle; overload;
begin
  Result.center := cCenter;
  Result.radius := cRadius;
end;

{==============================================================================]
  <Construct>
  @action: Constructs TCircle with centerX, centerY and radius.
  @note: None.
[==============================================================================}
class function TCircle.Construct(const centerX, centerY: Integer; const cRadius: Double): TCircle; overload;
begin
  Result.center := Point(centerX, centerY);
  Result.radius := cRadius;
end;

{==============================================================================]
  <Create>
  @action: Create a TCircle with center point and radius
  @note: None.
[==============================================================================}
constructor TCircle.Create(const cCenter: TPoint; const cRadius: Double); overload;
begin
  Self.center := cCenter;
  Self.radius := cRadius;
end;

{==============================================================================]
  <Create>
  @action: Create a TCircle with center point and radius
  @note: None.
[==============================================================================}
constructor TCircle.Create(const centerX, centerY: Integer; const cRadius: Double); overload;
begin
  Self.center := Point(centerX, centerY);
  Self.radius := cRadius;
end;
{$ENDIF}