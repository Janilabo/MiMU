{==============================================================================]
  <TBooleanArrayHelper.Invert>
  @action: Returns inverted version of arr.
  @note: [True, False] => [False, True].
[==============================================================================}
function TBooleanArrayHelper.Invert: TBooleanArray; overload; cdecl;
var
  i: Integer;
begin
  SetLength(Result, Length(Self));
  for i := 0 to High(Self) do
    Result[i] := not Self[i];
end;