{$IFDEF HELPERS}
function Normalized: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
function TRangeArrayHelper.Normalized: TRangeArray; overload;
var
  i: Integer;
begin
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
    Result[i].Create(Min(Self[i].start, Self[i].stop), Max(Self[i].start, Self[i].stop));
end;
{$ENDIF}
