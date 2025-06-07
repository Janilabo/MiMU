{==============================================================================]
 <TArray_Distribute(arr: TArray; parts: Int32): T2DArray>
 @action: Distributes array arr to 2D array by number of parts.
 @note: ([1,2,3,4,5,6,7], 3) => [1,2,3][4,5][6,7]
 [==============================================================================}
{$IFDEF TArray_Distribute}
var
  l, p, b, r, i, j, s, c: Int32;
begin
  l := Length(arr);
  if ((parts > 0) and (l > 0)) then
  begin
    p := Min(parts, l);
    SetLength(Result, p);
    b := (l div p);
    r := (l mod p);
    s := 0;
    for i := 0 to (p - 1) do
    begin
      c := b;
      if (i < r) then
        Inc(c);
      SetLength(Result[i], c);
      for j := 0 to (c - 1) do
      begin
        Result[i][j] := arr[s];
        Inc(s);
      end;
    end;
  end else
    SetLength(Result, 0);
end;
{$ENDIF}