{$DEFINE TTriangle}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
TTriangle = record
  A, B, C: TPoint;
end;
{$I ../Type.inc}
{$ENDIF}

{$IFDEF HELPERS}
TTriangleHelper = type helper for TTriangle
  {$I ../Type.inc}
end;
{$ENDIF}

{$IFDEF OPERATORS}
operator =(const a, b: TTriangle): Boolean;
operator <>(const a, b: TTriangle): Boolean;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS)}
{$I ../Type.inc}
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

{$UNDEF BASE}{$UNDEF TTriangle}
