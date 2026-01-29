{$IFDEF METHODS}
function Invert: Boolean;
function Inverted: TRange;
function Reverse: Boolean;
function Reversed: TRange;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Invert>
  @action: Negates both endpoints of the range in place.
  @note: This is a mutating operation. The range is reflected through the
         origin (0), mapping [start, stop] → [-start, -stop].
         The function returns True if the original range was non-zero
         (i.e. either endpoint was non-zero), and False otherwise.
         Direction and magnitude are preserved, but sign is inverted.
[==============================================================================}
function TRange.Invert: Boolean;
begin
  Result := ((Self.start <> 0) or (Self.stop <> 0));
  Self.start := -Self.start;
  Self.stop := -Self.stop;
end;

{==============================================================================]
  <Inverted>
  @action: Returns a copy of the range with both endpoints negated.
  @note: This is a non-mutating operation. The resulting range is the
         reflection of the original through the origin (0), mapping
         [start, stop] → [-start, -stop].
         Direction and magnitude are preserved.
[==============================================================================}
function TRange.Inverted: TRange;
begin
  Result.start := -Self.start;
  Result.stop := -Self.stop;
end;

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