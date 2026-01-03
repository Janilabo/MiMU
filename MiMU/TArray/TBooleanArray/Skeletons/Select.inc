var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    if Self[i] then
      Result[i] := sTrue
    else
      Result[i] := sFalse;
end;