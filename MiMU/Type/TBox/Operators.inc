{$IFDEF OPERATORS}
operator +(const a, b: TBox): TBox;
operator -(const a, b: TBox): TBox;
operator =(const a, b: TBox): Boolean;
operator <>(const a, b: TBox): Boolean;

operator in(const P: TPoint; const B: TBox): Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <+>
  @action: Computes the union of two boxes. The resulting box fully contains
           both input boxes.
  @note:   Supports any coordinate ordering; assumes X1 <= X2 and Y1 <= Y2 after normalization.
[==============================================================================}
operator +(const a, b: TBox): TBox;
begin
  Result.X1 := Min(a.X1, b.X1);
  Result.Y1 := Min(a.Y1, b.Y1);
  Result.X2 := Max(a.X2, b.X2);
  Result.Y2 := Max(a.Y2, b.Y2);
end;

{==============================================================================]
  <->
  @action: Computes the intersection of two boxes. Returns a box representing the
           overlapping area of `a` and `b`. If the boxes do not overlap, returns
           a null box marker.
  @note:   A null box can be represented by `TBox.Null` (e.g., all coordinates = Low(Integer)).
           This function does not require the boxes to be normalized beforehand, but
           you may normalize them for consistent behavior.
[==============================================================================}
operator -(const a, b: TBox): TBox;
begin
  if ((a.X2 < b.X1) or (b.X2 < a.X1) or (a.Y2 < b.Y1) or (b.Y2 < a.Y1)) then
    Exit(TBox.Null);
  Result.X1 := Max(a.X1, b.X1);
  Result.Y1 := Max(a.Y1, b.Y1);
  Result.X2 := Min(a.X2, b.X2);
  Result.Y2 := Min(a.Y2, b.Y2);
end;

operator =(const a, b: TBox): Boolean;
begin
  Result := ((a.X1 = b.X1) and (a.Y1 = b.Y1) and (a.X2 = b.X2) and (a.Y2 = b.Y2));
end;

operator <>(const a, b: TBox): Boolean;
begin
  Result := not ((a.X1 = b.X1) and (a.Y1 = b.Y1) and (a.X2 = b.X2) and (a.Y2 = b.Y2));
end;

operator in(const P: TPoint; const B: TBox): Boolean;
begin
  Result := B.Contains(P);
end;
{$ENDIF}