{$IFDEF HELPERS}
function Difference(const T: Int64): Int64; cdecl; inline;
function Distance(const T: Int64): Int64; cdecl; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Difference>
  @action: Returns the difference from x to T.
  @note: None
[==============================================================================}
function TInt64Helper.Difference(const T: Int64): Int64; cdecl; inline;
begin
  Result := (T - Self);
end;

{==============================================================================]
  <Distance>
  @action: Returns the distance between x and T.
  @note: None
[==============================================================================}
function TInt64Helper.Distance(const T: Int64): Int64; cdecl; inline;
begin
  Result := Abs(T - Self);
end;
{$ENDIF}