{$IFDEF HELPERS}
function Percent(const position: Double): Double; inline;
function Percentage(const percent: Double): Double; inline;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Percent>
  @action: Returns percent (%) from x by position.
  @note: Value-to-Percent conversion!
[==============================================================================}
function TDoubleHelper.Percent(const position: Double): Double; inline;
begin
  if (position <> 0) then
    Result := ((position / Self) * 100.0)
  else
    Result := 0.0;
end;

{==============================================================================]
  <Percentage>
  @action: Returns value from x by percent.
  @note: Percent-to-Value conversion!
[==============================================================================}
function TDoubleHelper.Percentage(const percent: Double): Double; inline;
begin
  if (percent <> 0) then
    Result := ((percent / 100.0) * Self)
  else
    Result := 0.0;
end;
{$ENDIF}