{$IFDEF METHODS}
function Equal(const b: TBox): Boolean;
function Similar(const b: TBox; const maxWDiff, maxHDiff: Integer): Boolean; overload;
function Similar(const b: TBox; const diff: Integer): Boolean; overload;
function SimilarSize(const b: TBox; const widthDifferency, heightDifferency: Integer): Boolean; overload;
function SimilarSize(const b: TBox; const differency: Integer): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Equal>
  @action: Returns true if bx1 and bx2 are identical.
  @note: None
[==============================================================================}
function TBox.Equal(const b: TBox): Boolean;
begin
  Result := ((Self.X1 = b.X1) and (Self.Y1 = b.Y1) and (Self.X2 = b.X2) and (Self.Y2 = b.Y2));
end;

{==============================================================================]
  <Similar>
  @action: Returns true if the dimensions from boxes bx1 and bx2
           are within maxWDiff (max width differency) and maxHDiff (max height differency).
  @note: None
[==============================================================================}
function TBox.Similar(const b: TBox; const maxWDiff, maxHDiff: Integer): Boolean; overload;
begin
  Result := ((Abs(b.Width - Self.Width) <= maxWDiff) and (Abs(b.Height- Self.Height) <= maxHDiff));
end;

{==============================================================================]
  <Similar>
  @action: Returns true if the dimensions from boxes bx1 and bx2
           are within diff (max width and height differency).
  @note: None
[==============================================================================}
function TBox.Similar(const b: TBox; const diff: Integer): Boolean; overload;
begin
  Result := ((Abs(b.Width - Self.Width) <= diff) and (Abs(b.Height - Self.Height) <= diff));
end;

{==============================================================================]
  <SimilarSize>
  @action: Returns true if the size from boxes a and b
           are within widthDifferency and heightDifferency.
  @note: None.
[==============================================================================}
function TBox.SimilarSize(const b: TBox; const widthDifferency, heightDifferency: Integer): Boolean; overload;
begin
  Result := ((Abs(b.Width - Self.Width) <= widthDifferency) and (Abs(b.Height - Self.Height) <= heightDifferency));
end;

{==============================================================================]
  <SimilarSize>
  Explanation: Returns true if the size from boxes a and b
               are within differency.
  @note: None.
[==============================================================================}
function TBox.SimilarSize(const b: TBox; const differency: Integer): Boolean; overload;
begin
  Result := ((Abs(b.Width - Self.Width) <= differency) and (Abs(b.Width - Self.Width) <= differency));
end;
{$ENDIF}