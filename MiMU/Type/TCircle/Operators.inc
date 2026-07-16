{$IFDEF OPERATORS}
operator =(const a, b: TCircle): Boolean;
operator <>(const a, b: TCircle): Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
operator =(const a, b: TCircle): Boolean;
begin
  Result := ((a.Center = b.Center) and (a.Radius = b.Radius));
end;

operator <>(const a, b: TCircle): Boolean;
begin
  Result := not (a = b);
end;
{$ENDIF}