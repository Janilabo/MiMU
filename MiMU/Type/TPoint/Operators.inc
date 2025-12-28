{$IFDEF OPERATORS}
operator +(const a, b: TPoint): TPoint;
operator -(const a, b: TPoint): TPoint;
operator =(const a, b: TPoint): Boolean;
operator <>(const a, b: TPoint): Boolean;
operator >(const a, b: TPoint): Boolean;
operator <(const a, b: TPoint): Boolean;
operator >=(const a, b: TPoint): Boolean;
operator <=(const a, b: TPoint): Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
operator +(const a, b: TPoint): TPoint;
begin
  Result.X := (a.X + b.X);
  Result.X := (a.Y + b.Y);
end;

operator -(const a, b: TPoint): TPoint;
begin
  Result.X := (a.X - b.X);
  Result.Y := (a.Y - b.Y);
end;

operator =(const a, b: TPoint): Boolean;
begin
  Result := ((a.X = b.X) and (a.Y = b.Y));
end;

operator <>(const a, b: TPoint): Boolean;
begin
  Result := not ((a.X = b.X) and (a.Y = b.Y));
end;

operator >(const a, b: TPoint): Boolean;
begin
  Result := ((a.Y > b.Y) or ((a.Y = b.Y) and (a.X > b.X)));
end;

operator <(const a, b: TPoint): Boolean;
begin
  Result := ((a.Y < b.Y) or ((a.Y = b.Y) and (a.X < b.X)));
end;

operator >=(const a, b: TPoint): Boolean;
begin
  Result := ((a > b) or (a = b));
end;

operator <=(const a, b: TPoint): Boolean;
begin
  Result := ((a < b) or (a = b));
end;
{$ENDIF}