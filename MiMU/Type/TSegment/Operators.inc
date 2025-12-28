{$IFDEF OPERATORS}  
operator =(const a, b: TSegment): Boolean;
operator <>(const a, b: TSegment): Boolean;
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