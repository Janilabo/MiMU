{$IFDEF HELPERS}
function Difference(const T: Integer): Integer; cdecl; inline;
function Distance(const T: Integer): Integer; cdecl; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Difference>
  @action: Returns the difference from x to T.
  @note: None
[==============================================================================}
function TIntegerHelper.Difference(const T: Integer): Integer; cdecl; inline;
begin
  Result := (T - Self);
end;

{==============================================================================]
  <Distance>
  @action: Returns the distance between x and T.
  @note: None
[==============================================================================}
function TIntegerHelper.Distance(const T: Integer): Integer; cdecl; inline;
begin
  Result := Abs(T - Self);
end;
{$ENDIF}