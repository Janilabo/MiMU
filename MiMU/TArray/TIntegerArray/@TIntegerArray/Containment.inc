{$IFDEF HELPERS}
function Flanked(const item: Integer; const indexes: TRange; const oAscending: Boolean = True): Boolean; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Flanked>
  @action: Checks whether item falls within the value range spanned by Self[indexes.start] and Self[indexes.stop],
           given a sorted (ascending or descending per oAscending) subrange.
  @note: O(1) — does not search or inspect any elements between the two endpoints; only the boundary values are read.
         Assumes Self is sorted in the specified direction over indexes; unsorted or mismatched-direction input yields undefined results.
[==============================================================================}
function TIntegerArrayHelper.Flanked(const item: Integer; const indexes: TRange; const oAscending: Boolean = True): Boolean; overload;
begin
  if oAscending then
    Result := InRange(item, Self[indexes.start], Self[indexes.stop])
  else
    Result := InRange(item, Self[indexes.stop], Self[indexes.start]);
end;
{$ENDIF}