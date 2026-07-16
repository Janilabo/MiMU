{$IFDEF HELPERS}
function Unduped: TCharArray;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Unduped>
  @action: Returns TCharArray with unique chars.
  @note: Works with ASCII.
[==============================================================================}
function TCharArrayHelper.Unduped: TCharArray;
var
  s: set of Char;
  i, l: Integer;
begin
  if (Self.Size < 2) then
    Exit(Self.Clone);
  s := [];
  l := 0;
  SetLength(Result, Self.Size);
  for i := 0 to High(Self) do
  begin
    if (Self[i] in s) then
      Continue;
    Include(s, Self[i]);
    Result[l.Increase] := Self[i];
  end;
  SetLength(Result, l);
end;
{$ENDIF}
