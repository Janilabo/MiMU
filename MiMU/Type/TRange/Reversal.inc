{$IFDEF METHODS}
function Reverse: Boolean; cdecl;
function Reversed: TRange; cdecl;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Reverse>
  @action: Reverses range, returns True if range was reversed.
  @note: None.
[==============================================================================}
function TRange.Reverse: Boolean; cdecl;
begin
  Result := Self.Plural;
  if Result then
    Swap(Self.start, Self.stop);
end;

{==============================================================================]
  <Reversed>
  @action: Returns reversed range.
  @note: None.
[==============================================================================}
function TRange.Reversed: TRange; cdecl;
begin
  Result.start := Self.stop;
  Result.stop := Self.start;
end;
{$ENDIF}