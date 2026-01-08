{$IFDEF HELPERS}
function Difference(const T: Double): Double; cdecl; inline;
function Distance(const T: Double): Double; cdecl; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Difference>
  @action: Returns the difference from x to T.
  @note: None
[==============================================================================}
function TDoubleHelper.Difference(const T: Double): Double; cdecl; inline;
begin
  Result := (T - Self);
end;

{==============================================================================]
  <Distance>
  @action: Returns the distance between x and T.
  @note: None
[==============================================================================}
function TDoubleHelper.Distance(const T: Double): Double; cdecl; inline;
begin
  Result := Abs(T - Self);
end;
{$ENDIF}