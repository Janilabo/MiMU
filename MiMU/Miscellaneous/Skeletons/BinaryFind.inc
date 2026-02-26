var
  L, H, M: Integer;
begin
  L := 0;
  H := High(arr);
  while (L <= H) do
  begin
    M := (L + ((H - L) shr 1));
    if (arr[M] = item) then
      Exit(M);
    case ascending of
      True:
      if (arr[M] < item) then
        L := (M + 1)
      else
        H := (M - 1);
      False:
      if (arr[M] > item) then
        L := (M + 1)
      else
        H := (M - 1);
    end;
  end;
  Result := -1;
end;