{$IFDEF METHODS}
function Parenate(const parent: TRange): TRange; overload;
function Parency(const parent: TRange): TRange; overload;
function Parented(const parent: TRange): TRange; overload;
function Parentile(const parent: TRange): TRange; overload;

function Adopt(const child: TRange): TRange; overload;
function Adopted(const child: TRange): TRange; overload;
function Adoption(const child: TRange): TRange; overload;
function Adoptive(const child: TRange): TRange; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Parenate>
  @action: Maps Self (child) from local space into Parent's absolute space,
           inheriting Parent's direction.
  @note: Derives the sign via Parent.Direction rather than recomputing
         Sign(Delta) inline, reusing the range's own directional property.
[==============================================================================}
function TRange.Parenate(const parent: TRange): TRange; overload;
var
  d: Integer;
begin
  d := parent.Direction;
  Result.start := (parent.start + (Self.start * d));
  Result.stop  := (parent.start + (Self.stop * d));
end;

{==============================================================================]
  <Parency>
  @action: Maps Self (child) from local space into Parent's absolute space,
           inheriting Parent's direction.
  @note: Branches explicitly on Parent.Descending rather than computing a
         shared numeric sign, applying direct addition or subtraction per
         branch instead of a signed multiplication.
[==============================================================================}
function TRange.Parency(const parent: TRange): TRange; overload;
begin
  if parent.Descending then
    Result := TRange.Construct((parent.start - Self.start), (parent.start - Self.stop))
  else
    Result := TRange.Construct((parent.start + Self.start), (parent.start + Self.stop));
end;

{==============================================================================]
  <Parented>
  @action: Maps Self (child) from local space into Parent's absolute space,
           inheriting Parent's direction.
  @note: Derives the sign via IfThen on Parent.Descending, then applies a
         single affine map — f(x) = Parent.start + x * s — to both
         endpoints of Self.
[==============================================================================}
function TRange.Parented(const parent: TRange): TRange; overload;
var
  s: Integer;
begin
  s := IfThen(parent.Descending, -1, 1);
  Result.start := (parent.start + (Self.start * s));
  Result.stop  := (parent.start + (Self.stop * s));
end;

{==============================================================================]
  <Parentile>
  @action: Maps Self (child) from local space into Parent's absolute space,
           inheriting Parent's direction.
  @note: Derives the sign arithmetically as (1 - (2 * Ord(Parent.Descending)))
         rather than via Sign(), IfThen, or a branch — True/False cast to
         1/0 and folded directly into a linear formula.
[==============================================================================}
function TRange.Parentile(const parent: TRange): TRange; overload;
var
  s: Integer;
begin
  s := (1 - (2 * Ord(parent.Descending)));
  Result.start := (parent.start + (Self.start * s));
  Result.stop  := (parent.start + (Self.stop * s));
end;

{==============================================================================]
  <Adopt>
  @action: Maps child from local space into Self's (parent's) absolute
           space, inheriting Self's direction.
  @note: Mirror-image of Parenate with roles reversed — Self is treated as
         the parent, and the supplied child argument is the range being
         mapped. Delegates to Parenate so both functions share one
         implementation of the underlying transform.
[==============================================================================}
function TRange.Adopt(const child: TRange): TRange; overload;
begin
  Result := child.Parenate(Self);
end;

{==============================================================================]
  <Adopted>
  @action: Maps child from local space into Self's (parent's) absolute
           space, inheriting Self's direction.
  @note: Mirror-image of Parented with roles reversed — Self is treated as
         the parent, and the supplied child argument is the range being
         mapped. Delegates to Parented so both functions share one
         implementation of the underlying transform.
[==============================================================================}
function TRange.Adopted(const child: TRange): TRange; overload;
begin
  Result := child.Parented(Self);
end;

{==============================================================================]
  <Adoption>
  @action: Maps child from local space into Self's (parent's) absolute
           space, inheriting Self's direction.
  @note: Mirror-image of Parency with roles reversed — Self is treated as
         the parent, and the supplied child argument is the range being
         mapped. Delegates to Parency so both functions share one
         implementation of the underlying transform.
[==============================================================================}
function TRange.Adoption(const child: TRange): TRange; overload;
begin
  Result := child.Parency(Self);
end;

{==============================================================================]
  <Adoptive>
  @action: Maps child from local space into Self's (parent's) absolute
           space, inheriting Self's direction.
  @note: Mirror-image of Parentile with roles reversed — Self is treated as
         the parent, and the supplied child argument is the range being
         mapped. Delegates to Parentile so both functions share one
         implementation of the underlying transform.
[==============================================================================}
function TRange.Adoptive(const child: TRange): TRange; overload;
begin
  Result := child.Parentile(Self);
end;
{$ENDIF}
