{$IFDEF METHODS}
function Reverse: Boolean;
function Reversed: TRange;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Reverse>
  @action: Reverses range, returns True if range was reversed.
  @note: None.
[==============================================================================}
function TRange.Reverse: Boolean;
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
function TRange.Reversed: TRange;
begin
  Result.start := Self.stop;
  Result.stop := Self.start;
end;
{$ENDIF}