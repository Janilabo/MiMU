{$IFDEF HELPERS}
function Pure(const allowed: TDoubleArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Pure>
  @action: Returns true if arr is made with only allowed items.
  @note: None.
[==============================================================================}
function TDoubleArrayHelper.Pure(const allowed: TDoubleArray): Boolean;
var
  a: TDoubleArray;
  i: Integer;
begin
  if allowed.Empty then
    Exit(False);
  a := allowed.QuickSorted;
  for i := 0 to High(Self) do
    if not a.BinaryContains(Self[i]) then
      Exit(False);
  Result := True;
end;
{$ENDIF}
