{$IFDEF HELPERS}
function Repeated(const rCount: Integer = 1): MArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Repeated>
  @action: Duplicates the elements of the current array a specified number of times sequentially.
  @note: If rCount is less than 1, an empty array is returned.
[==============================================================================}
function MArrayHelper.Repeated(const rCount: Integer = 1): MArray; overload;
var
  i, c, r, h: Integer;
begin
  if (rCount < 1) then
    Exit([]);
  h := High(Self);
  SetLength(Result, ((h + 1) * rCount));
  r := 0;
  for c := 1 to rCount do
    for i := 0 to h do
      Result[r.Increase] := Self[i];
end;
{$ENDIF}