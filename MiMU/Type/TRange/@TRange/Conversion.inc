{$IFDEF METHODS}
function AsStr(const rReversed: Boolean = False): string; overload;
function Str(const openRange: string = '['; const closeRange: string = ']'; const glueRange: string = '..'): string; overload;
function Stringify(const openRange: string = '['; const glueRange: string = '..'; const closeRange: string = ']'): string; overload;
function Text(const glueRange: string = '..';  const openRange: string = '['; const closeRange: string = ']'): string; overload;
function ToStr(const glueRange: string = '..'; const openRange: string = '['; const closeRange: string = ']'): string; overload;
function ToString(const glueRange: string = '..'; const openRange: string = '['; const closeRange: string = ']'): String; overload;
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
function TRange.Str(const openRange: string = '['; const closeRange: string = ']'; const glueRange: string = '..'): string; overload;
begin
  Result := ('[' + IntToStr(Self.start) + glueRange + IntToStr(Self.stop) + ']');
end;

{==============================================================================]
  <Stringify>
  @action: Converts TRange range to string.
  @note: None
[==============================================================================}
function TRange.Stringify(const openRange: string = '['; const glueRange: string = '..'; const closeRange: string = ']'): string; overload;
begin
  Result := Format(openRange + '%d' + glueRange + '%d' + closeRange, [Self.start, Self.stop]);
end;

{==============================================================================]
  <Text>
  @action: Returns the string representation of the range.
  @param:: glueRange  String inserted between Start and Stop (default '..').
           openRange  Prefix delimiter for the range (default '[').
           closeRange Suffix delimiter for the range (default ']').
  @note: Produces a formatted interval representation such as "[1..5]".
         Does not encode inclusivity/exclusivity semantics beyond the
         provided delimiters. Intended for display or logging purposes.
[==============================================================================}
function TRange.Text(const glueRange: string = '..'; const openRange: string = '['; const closeRange: string = ']'): string; overload;
begin
  Result := Concat(openRange, IntToStr(Self.start), glueRange, IntToStr(Self.stop), closeRange);
end;

{==============================================================================]
  <ToStr>
  @action: Converts TRange range to string.
  @note: None
[==============================================================================}
function TRange.ToStr(const glueRange: string = '..'; const openRange: string = '['; const closeRange: string = ']'): string; overload;
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
  <ToString>
  @action: Returns a string representation of the range using a customizable format.
           Constructs a textual interval in the form: openRange + Start + glueRange + Stop + closeRange.
  @param: glueRange  String inserted between Start and Stop (default '..').
          openRange  Prefix delimiter for the range (default '[').
          closeRange Suffix delimiter for the range (default ']').
  @note: Similar to Text(), but uses TStringBuilder for more efficient string concatenation.
         Primarily intended for display, logging, or debugging.
         Does not alter range semantics; delimiters are purely presentational.
[==============================================================================}
function TRange.ToString(const glueRange: string = '..'; const openRange: string = '['; const closeRange: string = ']'): String; overload;
var
  b: TStringBuilder;
begin
  b := TStringBuilder.Create;
  try
    b.Append(openRange);
    b.Append(Self.start);
    b.Append(glueRange);
    b.Append(Self.stop);
    b.Append(closeRange);
    Result := b.ToString;
  finally
    b.Free;
  end;
end;
{$ENDIF}