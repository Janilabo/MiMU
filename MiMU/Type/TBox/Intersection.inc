{$IFDEF METHODS}
function Intersect(const b: TBox): TBox; overload; cdecl;
function Intersect(const b: TBox; var iArea: TBox): Boolean; overload; cdecl;
function Overlap(const b: TBox): Boolean; cdecl; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Intersect>
  @action: Returns true if a and b are in anykind of contact with each other.
  @note: None
[==============================================================================}
function TBox.Intersect(const b: TBox): TBox; overload; cdecl;
begin
  Result.X1 := Max(Self.X1, b.X1);
  Result.Y1 := Max(Self.Y1, b.Y1);
  Result.X2 := Min(Self.X2, b.X2);
  Result.Y2 := Min(Self.Y2, b.Y2);
end;

{==============================================================================]
  <Intersect>
  @action: Returns true if a and b are in anykind of contact with each other.
  @note: None
[==============================================================================}
function TBox.Intersect(const b: TBox; var iArea: TBox): Boolean; overload; cdecl;
begin
  iArea := Self.Intersect(b);
  Result := not ((iArea.X1 > iArea.X2) or (iArea.Y1 > iArea.Y2));
end;

{==============================================================================]
  <Overlap>
  @action: Returns true if a and b are in anykind of contact with each other.
  @note: None
[==============================================================================}
function TBox.Overlap(const b: TBox): Boolean; cdecl; inline;
begin
  Result := not ((Self.X1 > b.X2) or (Self.X2 < b.X1) or (Self.Y1 > b.Y2) or (Self.Y2 < b.Y1));
end;
{$ENDIF}