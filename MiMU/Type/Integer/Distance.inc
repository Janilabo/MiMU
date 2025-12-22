{$IFDEF HELPERS}
function Distance(const T: Integer): Integer; inline;
function Difference(const T: Integer): Integer; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Distance>
  @action: Returns the distance between x and T.
  @note: None
[==============================================================================}
function TIntegerHelper.Distance(const T: Integer): Integer; inline;
begin
  Result := Abs(T - Self);
end;

{==============================================================================]
  <Difference>
  @action: Returns the difference from x to T.
  @note: None
[==============================================================================}
function TIntegerHelper.Difference(const T: Integer): Integer; inline;
begin
  Result := (T - Self);
end;
{$ENDIF}