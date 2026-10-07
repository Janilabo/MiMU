{$IFDEF HELPERS}
function Supply(const pX, pY: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Supply>
  @action: Appends the point (pX, pY) to the end of the array.
  @note: Returns the same value as Supply(TPoint).
[==============================================================================}
function TPointArrayHelper.Supply(const pX, pY: Integer): Integer; overload;
begin
  Result := Self.Supply(TPoint.Construct(pX, pY));
end;
{$ENDIF}
