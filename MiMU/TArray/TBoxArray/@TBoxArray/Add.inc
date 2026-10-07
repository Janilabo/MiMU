{$IFDEF HELPERS}
function Supply(const bX1, bY1, bX2, bY2: Integer): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Supply>
  @action: Appends the box (bX1, bY1, bX2, bY2) to the end of the array.
  @note: Coordinates are used as given. Returns the same value as Supply(TBox).
[==============================================================================}
function TBoxArrayHelper.Supply(const bX1, bY1, bX2, bY2: Integer): Integer; overload;
begin
  Result := Self.Supply(TBox.Construct(bX1, bY1, bX2, bY2));
end;
{$ENDIF}
