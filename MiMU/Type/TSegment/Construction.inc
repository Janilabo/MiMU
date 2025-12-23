{$IFDEF METHODS}
constructor Create(const sA, sB: TPoint); overload;
constructor Create(const aX, aY, bX, bY: Integer); overload;
class function Construct(const sA, sB: TPoint): TSegment; overload; static;
class function Construct(const aX, aY, bX, bY: Integer): TSegment; overload; static;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Construct>
  @action: Constructs TSegment with sA and sB points.
  @note: None.
[==============================================================================}
constructor TSegment.Create(const sA, sB: TPoint); overload;
begin
  Self.A := sA;
  Self.B := sB;
end;

{==============================================================================]
  <Create>
  @action: Create a TSegment with aX, aY and bX, bY coordinates.
  @note: None.
[==============================================================================}
constructor TSegment.Create(const aX, aY, bX, bY: Integer); overload;
begin
  Self.A := Point(aX, aY);
  Self.B := Point(bX, bY);
end;

{==============================================================================]
  <Construct>
  @action: Constructs TSegment with sA and sB points.
  @note: None.
[==============================================================================}
class function TSegment.Construct(const sA, sB: TPoint): TSegment; overload;
begin
  Result.A := sA;
  Result.B := sB;
end;

{==============================================================================]
  <Construct>
  @action: Constructs TSegment with aX, aY, bX, bY.
  @note: None.
[==============================================================================}
class function TSegment.Construct(const aX, aY, bX, bY: Integer): TSegment; overload;
begin
  Result.A := Point(aX, aY);
  Result.B := Point(bX, bY);
end;
{$ENDIF}