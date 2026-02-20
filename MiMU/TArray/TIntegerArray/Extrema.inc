{$IFDEF HELPERS}
function MaxVal: Integer; overload;
function MinVal: Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <MaxVal>
  @action: Returns maximum value from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.MaxVal: Integer; overload;
var
  i: Integer;
begin
  Result := Low(Integer);
  if not Self.Empty then
  for i := 0 to High(Self) do
    if (Self[i] > Result) then
	  Result := Self[i];
end;

{==============================================================================]
  <MinVal>
  @action: Returns minimum value from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.MinVal: Integer; overload;
var
  i: Integer;
begin
  Result := High(Integer);
  if not Self.Empty then
  for i := 0 to High(Self) do
    if (Self[i] < Result) then
	  Result := Self[i];
end;
{$ENDIF}