{$IFDEF HELPERS}
function Opposite: Int64; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Opposite>
  @action: Returns the opposite number of x. 
           -9999 to 9999 OR 9999 to -9999 (- <=> +) 
  @note: None
[==============================================================================}
function TInt64Helper.Opposite: Int64; inline;
begin
  Result := (Self * -1);
end;
{$ENDIF}