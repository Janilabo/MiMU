var
  L, H, M: Integer;
begin
  L := 0;
  H := High(arr);
  while (L <= H) do
  begin
    M := (L + ((H - L) shr 1));
    if ((ascending and (arr[M] < item)) or ((not ascending) and (arr[M] > item))) then
      L := (M + 1)
    else if ((ascending and (arr[M] > item)) or ((not ascending) and (arr[M] < item))) then
      H := (M - 1)
    else
      Exit(M);
  end;
  Result := -1;
end;