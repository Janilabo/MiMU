{$IFDEF METHODS}
function Boundaries: TBox; cdecl;
function Bounds: TBox; cdecl;
function Envelope: TBox; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Boundaries>
  @action: Returns the bounds of TSegment as TBox.
  @note: None.
[==============================================================================}
function TSegment.Boundaries: TBox; cdecl;
begin
  with Self do
  Result := Box(IfThen((A.X < B.X), A.X, B.X), IfThen((A.Y < B.Y), A.Y, B.Y), IfThen((A.X > B.X), A.X, B.X), IfThen((A.Y > B.Y), A.Y, B.Y));
end;

{==============================================================================]
  <Bounds>
  @action: Returns the bounds of TSegment as TBox.
  @note: None.
[==============================================================================}
function TSegment.Bounds: TBox; cdecl;
begin
  Result.Create(Min(Self.A.X, Self.B.X), Min(Self.A.Y, Self.B.Y), Max(Self.A.X, Self.B.X), Max(Self.A.Y, Self.B.Y));
end;

{==============================================================================]
  <Envelope>
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
{$ENDIF}