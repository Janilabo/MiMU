{$IFDEF HELPERS}
function Opposite: Int64;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Opposite>
  @action: Returns the opposite number of x.
           -9999 to 9999 OR 9999 to -9999 (- <=> +)
  @note: None
[==============================================================================}
function TInt64Helper.Opposite: Int64;
begin
  Result := (Self * -1);
end;
{$ENDIF}