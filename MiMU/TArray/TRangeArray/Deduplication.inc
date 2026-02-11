{$IFDEF HELPERS}
function Squeeze: TRangeArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Squeeze>
  @action: Returns a new TRangeArray with all values from the original ranges
           flattened, sorted, deduplicated, and regrouped into contiguous streaks.
  @returns: TRangeArray containing normalized ranges covering all unique values.
  @note:
    - Converts the original TRangeArray to a flat integer array (TIA).
    - Sorts the integers in ascending order.
    - Removes duplicate values.
    - Converts consecutive sequences of integers back into contiguous ranges.
    - The resulting ranges are minimal: no overlapping ranges and no duplicates.
    - Original ranges with gaps between them may be merged if the sequences
      of values are contiguous.
    - Preserves ascending order for each resulting streak.
[==============================================================================}
function TRangeArrayHelper.Squeeze: TRangeArray; overload;
begin
  Result := Self.TIA.QuickSorted.Compressed.Streaks;
end;
{$ENDIF}
