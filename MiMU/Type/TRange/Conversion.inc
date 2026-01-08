{$IFDEF METHODS}
function AsStr(const rReversed: Boolean = False): string; overload; cdecl;
function Str(const openRange: string = '['; const closeRange: string = ']'; const glueRange: string = '..'): string; cdecl;
function Stringify(const openRange: string = '['; const glueRange: string = '..'; const closeRange: string = ']'): string; cdecl;
function ToStr(const glueRange: string = '..'; const openRange: string = '['; const closeRange: string = ']'): string; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsStr>
  @action: Converts TRange range to string.
  @note: From..To or To..From.
[==============================================================================}
function TRange.AsStr(const rReversed: Boolean = False): string; overload; cdecl;
begin
  if not rReversed then
    Result := Format('%d..%d', [Self.start, Self.stop])
  else
    Result := Format('%d..%d', [Self.stop, Self.start]);
end;

{==============================================================================]
  <Str>
  @action: Converts TRange range to string.
  @note: None
[==============================================================================}
function TRange.Str(const openRange: string = '['; const closeRange: string = ']'; const glueRange: string = '..'): string; cdecl;
begin
  Result := ('[' + IntToStr(Self.start) + glueRange + IntToStr(Self.stop) + ']');
end;

{==============================================================================]
  <Stringify>
  @action: Converts TRange range to string.
  @note: None
[==============================================================================}
function TRange.Stringify(const openRange: string = '['; const glueRange: string = '..'; const closeRange: string = ']'): string; cdecl;
begin
  Result := Format(openRange + '%d' + glueRange + '%d' + closeRange, [Self.start, Self.stop]);
end;

{==============================================================================]
  <ToStr>
  @action: Converts TRange range to string.
  @note: None
[==============================================================================}
function TRange.ToStr(const glueRange: string = '..'; const openRange: string = '['; const closeRange: string = ']'): string; cdecl;
begin
  Result := '';
  if (openRange <> '') then
    Result := (Result + openRange);
  Result := (Result + IntToStr(Self.start));
  if (glueRange <> '') then
    Result := (Result + glueRange);
  Result := (Result + IntToStr(Self.stop));
  if (closeRange <> '') then
    Result := (Result + closeRange);
end;
{$ENDIF}