{$IFDEF OPERATORS}  
operator =(const a, b: TConnection): Boolean;
operator <>(const a, b: TConnection): Boolean;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
operator =(const a, b: TConnection): Boolean;
begin
  Result := ((a.id1 = b.id1) and (a.id2 = b.id2));
end;

operator <>(const a, b: TConnection): Boolean;
begin
  Result := not (a = b);
end;
{$ENDIF}