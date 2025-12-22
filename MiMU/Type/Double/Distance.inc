{$IFDEF HELPERS}
function Distance(const T: Double): Double; inline;
function Difference(const T: Double): Double; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Distance>
  @action: Returns the distance between x and T.
  @note: None
[==============================================================================}
function TDoubleHelper.Distance(const T: Double): Double; inline;
begin
  Result := Abs(T - Self);
end;

{==============================================================================]
  <Difference>
  @action: Returns the difference from x to T.
  @note: None
[==============================================================================}
function TDoubleHelper.Difference(const T: Double): Double; inline;
begin
  Result := (T - Self);
end;
{$ENDIF}