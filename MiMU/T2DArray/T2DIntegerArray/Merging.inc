{$IFDEF METHODS}
class function Merge(const arr: T2DIntegerArray): TIntegerArray; overload; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
class function C2DIntegerArray.Merge(const arr: T2DIntegerArray): TIntegerArray; overload; cdecl;
var
  i, r: Integer;
begin
  SetLength(Result, Length(arr));
  if Result.Empty then
    Exit;
  r := 0;
  for i := 0 to High(arr) do
    if (arr[i].Size > 0) then
      Move(arr[i][0], Result[r.Increase(arr[i].Size)], (arr[i].Size * SizeOf(Integer)));
end;
{$ENDIF}