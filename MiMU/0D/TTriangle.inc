{$DEFINE MType := TTriangle}
{$DEFINE MArray := TTriangleArray}
{$DEFINE M2DArray := T2DTriangleArray}
{$DEFINE MCompare := TTriangleCompare}
{$DEFINE MHelper := TTriangleHelper}
{$UNDEF Sortable}

{$IFDEF TYPES}
TTriangle = record
  A, B, C: TPoint;
end;
{$I Core.inc}
{$ENDIF}

{$IFDEF HELPERS}
TTriangleHelper = type helper for TTriangle
  {$I Core.inc}
end;
{$ENDIF}

{$IFDEF OPERATORS}
operator =(const a, b: TTriangle): Boolean;
operator <>(const a, b: TTriangle): Boolean;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(METHODS)}
{$I Core.inc}
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