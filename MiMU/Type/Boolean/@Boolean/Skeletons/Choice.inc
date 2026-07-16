begin
  P[False] := @bFalse;
  P[True] := @bTrue;
  Result := P[Self]^;
end;