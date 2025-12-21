{$IFDEF HELPERS}
function Distance(const T: Int64): Int64; inline;
function Difference(const T: Int64): Int64; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Distance>
  @action: Returns the distance between x and T.
  @note: None
[==============================================================================}
function TInt64Helper.Distance(const T: Int64): Int64; inline;
begin
  Result := Abs(T - Self);
end;

{==============================================================================]
  <Difference>
  @action: Returns the difference from x to T.
  @note: None
[==============================================================================}
function TInt64Helper.Difference(const T: Int64): Int64; inline;
begin
  Result := (T - Self);
end;
{$ENDIF}