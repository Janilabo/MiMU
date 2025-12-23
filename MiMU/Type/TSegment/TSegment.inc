{$DEFINE TSegment}{$I ../Defines.inc}{$DEFINE BASE}

{$IFDEF TYPES}
TSegment = record
  A, B: TPoint;
  {$I TSegment.pph}
end;
{$I ../Type.inc}
{$ENDIF}

{$IFDEF HELPERS}
TSegmentHelper = type helper for TSegment
  {$I ../Type.inc}
  {$I TSegment.pph}
end;
{$ENDIF}

{$IFDEF OPERATORS}  
operator =(const a, b: TSegment): Boolean;
operator <>(const a, b: TSegment): Boolean;
{$ENDIF}

{$IF DEFINED(IMPLEMENTATION) OR DEFINED(FUNCTIONS)}
{$I ../Type.inc}
{$I TSegment.pph}
{$ENDIF}

{$IFDEF IMPLEMENTATION}
operator =(const a, b: TSegment): Boolean;
begin
  Result := ((a.A.X = b.A.X) and (a.A.Y = b.A.Y) and (a.B.X = b.B.X) and (a.B.Y = b.B.Y));
end;

operator <>(const a, b: TSegment): Boolean;
begin
  Result := not (a = b);
end;
{$ENDIF}

{$UNDEF BASE}{$UNDEF TSegment}
