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