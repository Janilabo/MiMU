{$IFDEF TYPES}
function AsStr(const rReversed: Boolean = False): string; overload; 
function Str(const openRange: string = '['; const closeRange: string = ']'; const glueRange: string = '..'): string;
function ToStr(const glueRange: string = '..'; const openRange: string = '['; const closeRange: string = ']'): string; 
function Stringify(const openRange: string = '['; const glueRange: string = '..'; const closeRange: string = ']'): string;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <AsStr>
  @action: Converts TRange range to string.
  @note: From..To or To..From.
[==============================================================================}
function TRange.AsStr(const rReversed: Boolean = False): string; overload;
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
function TRange.Str(const openRange: string = '['; const closeRange: string = ']'; const glueRange: string = '..'): string;
begin
  Result := ('[' + IntToStr(Self.start) + glueRange + IntToStr(Self.stop) + ']');
end;

{==============================================================================]
  <ToStr>
  @action: Converts TRange range to string.
  @note: None
[==============================================================================}
function TRange.ToStr(const glueRange: string = '..'; const openRange: string = '['; const closeRange: string = ']'): string;
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

{==============================================================================]
  <Stringify>
  @action: Converts TRange range to string.
  @note: None
[==============================================================================}
function TRange.Stringify(const openRange: string = '['; const glueRange: string = '..'; const closeRange: string = ']'): string;
begin
  Result := Format(openRange + '%d' + glueRange + '%d' + closeRange, [Self.start, Self.stop]);
end;
{$ENDIF}