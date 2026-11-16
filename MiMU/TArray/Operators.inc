{$IFDEF OPERATORS}
operator ><(const A, B: MArray): MArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
operator ><(const A, B: MArray): MArray;
var
  i: MType;
begin
  Result := [];
  for i in A do
    if not B.Contains(i) then
      Result := (Result + [i]);
  for i in B do
    if not A.Contains(i) then
      Result := (Result + [i]);
end;
{$ENDIF}