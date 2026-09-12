{$IFDEF HELPERS}
function BinaryCount(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================|
  BinaryCount
  @action: Returns the exact number of occurrences of item in the sorted array.
  @note: Runs in O(log N) time using boundary lookups.
[==============================================================================}
function TBooleanArrayHelper.BinaryCount(const item: Boolean; const oAscending: Boolean = True): Integer; overload;
begin
  Result := Self.Binary1st(item, oAscending);
  if (Result = -1) then
    Exit(0);
  Result := ((Self.BinaryLst(item, oAscending) - Result) + 1);
end;
{$ENDIF}
