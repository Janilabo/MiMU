{$IFDEF HELPERS}
function SortBySize(const oAscending: Boolean = True): Integer;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <SortBySize>
  @action: Sorts the TRangeArray in-place by the size of its elements.
           The sorting order is determined by the oAscending parameter:
             - True: ascending (smallest to largest)
             - False: descending (largest to smallest)
  @note: Returns the number of elements in the array.
         If the array has fewer than 2 elements, no sorting is performed.
[==============================================================================}
function TRangeArrayHelper.SortBySize(const oAscending: Boolean = True): Integer;
begin
  Result := Self.Length;
  if (Result > 1) then
  case oAscending of
    True: specialize QuickSort<TRange>(Self, @TRange.CompareSizeAscending);
    False: specialize QuickSort<TRange>(Self, @TRange.CompareSizeDescending);
  end;
end;
{$ENDIF}
