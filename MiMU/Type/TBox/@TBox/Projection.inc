{$IFDEF METHODS}
function Parency(const parent: TBox): TBox; overload;
function Parented(const parent: TBox): TBox; overload;

function Adopted(const child: TBox): TBox; overload;
function Adoption(const child: TBox): TBox; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Parency>
  @action: Maps Self (child) from local space into Parent's absolute space.
  @note: Mechanically distinct from Parented — builds the result via the
         TBox constructor rather than direct field assignment, though the
         underlying translation is identical.
[==============================================================================}
function TBox.Parency(const parent: TBox): TBox; overload;
begin
  Result := TBox.Construct((parent.X1 + Self.X1), (parent.Y1 + Self.Y1), (parent.X1 + Self.X2), (parent.Y1 + Self.Y2));
end;

{==============================================================================]
  <Parented>
  @action: Maps Self (child) from local space into Parent's absolute space.
  @note: Since TBox coordinates are always normalized (X1 <= X2, Y1 <= Y2),
         no directional sign is needed — this is a straightforward
         translation of both corners by Parent's origin.
[==============================================================================}
function TBox.Parented(const parent: TBox): TBox; overload;
begin
  Result.X1 := (parent.X1 + Self.X1);
  Result.Y1 := (parent.Y1 + Self.Y1);
  Result.X2 := (parent.X1 + Self.X2);
  Result.Y2 := (parent.Y1 + Self.Y2);
end;

{==============================================================================]
  <Adopted>
  @action: Maps child from local space into Self's (parent's) absolute
           space.
  @note: Mirror-image of Parented with roles reversed — Self is treated as
         the parent, and the supplied child argument is the box being
         mapped. Delegates to Parented so both functions share one
         implementation of the underlying transform.
[==============================================================================}
function TBox.Adopted(const child: TBox): TBox; overload;
begin
  Result := child.Parented(Self);
end;

{==============================================================================]
  <Adoption>
  @action: Maps child from local space into Self's (parent's) absolute
           space.
  @note: Mirror-image of Parency with roles reversed — Self is treated as
         the parent, and the supplied child argument is the box being
         mapped. Delegates to Parency so both functions share one
         implementation of the underlying transform.
[==============================================================================}
function TBox.Adoption(const child: TBox): TBox; overload;
begin
  Result := child.Parency(Self);
end; 
{$ENDIF}
