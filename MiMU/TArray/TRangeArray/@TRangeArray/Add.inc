{$IFDEF HELPERS}
function Supply(const aStart, aStop: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Supply>
  @action: Appends the range (aStart, aStop) to the end of the array.
  @note: Builds the range (start = aStart, stop = aStop).
         Returns the same value as Supply(TRange).
[==============================================================================}
function TRangeArrayHelper.Supply(const aStart, aStop: Integer): Integer; overload;
begin
  Result := Self.Supply(TRange.Construct(aStart, aStop));
end;
{$ENDIF}
