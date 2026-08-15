{$IFDEF HELPERS}
function MaxVal: MType; overload;
function MinVal: MType; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <MaxVal>
  @action: Returns maximum value from arr.
  @note: None.
[==============================================================================}
function MArrayHelper.MaxVal: MType; overload;
var
  i: Integer;
begin
  {$IFDEF Double}
    Result := MinDouble;
  {$ELSE}
    Result := Low(MType);
  {$ENDIF}
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
function MArrayHelper.MinVal: MType; overload;
var
  i: Integer;
begin
  {$IFDEF Double}
    Result := MaxDouble;
  {$ELSE}
    Result := High(MType);
  {$ENDIF}
  if not Self.Empty then
  for i := 0 to High(Self) do
    if (Self[i] < Result) then
	  Result := Self[i];
end;
{$ENDIF}