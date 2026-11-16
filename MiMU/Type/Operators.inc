{$IFDEF OPERATORS}
operator >< (const A, B: MType): MArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
operator >< (const A, B: MType): MArray;
begin
  if (A = B) then
    Result := []
  else
    Result := [A, B];
end;
{$ENDIF}