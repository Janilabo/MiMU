{$IFDEF TYPES}
TTriangle = record
  A, B, C: TPoint;
end;
TTriangleArray = array of TTriangle;
T2DTriangleArray = array of TTriangleArray;
{$ENDIF}

{$IFDEF OPERATORS}
operator =(const a, b: TTriangle): Boolean;
operator <>(const a, b: TTriangle): Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
operator =(const a, b: TTriangle): Boolean;
begin
  Result := ((a.A = b.A) and (a.B = b.B) and (a.C = b.C));
end;

operator <>(const a, b: TTriangle): Boolean;
begin
  Result := not (a = b);
end;
{$ENDIF}