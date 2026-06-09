{$IFDEF HELPERS}
function Differ(const target: MArray): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Differ>
  @action: Returns true if arr differs from target.
  @note: None
[==============================================================================}
function MArrayHelper.Differ(const target: MArray): Boolean; overload;
var
  i: Integer;
begin
  Result := (Self.Size <> target.Size);
  if not Result then
  for i := High(Self) downto 0 do
    if (Self[i] <> target[i]) then
      Exit(True);
end;
{$ENDIF}