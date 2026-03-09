{$IFDEF HELPERS}
function BinaryMedian: Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryMedian>
  @action: Computes the median value of a sorted integer array.
  @note: Requires the array to be sorted.
         Returns:
           - The middle element if the array length is odd
           - The average of the two middle elements if the array length is even
           - 0.0 if the array is empty
         The result is returned as Double to support fractional medians when
         the array length is even.
         Runs in O(1) time since the median is determined directly from the
         middle index.
[==============================================================================}
function TIntegerArrayHelper.BinaryMedian: Double; overload;
var
  L, M: Integer;
begin
  L := Self.Length;
  if (L = 0) then
    Exit(0.0);
  M := (L div 2);
  if ((L mod 2) <> 0) then
    Result := Self[M]
  else
    Result := ((Self[M - 1] + Self[M]) / 2.0);
end;
{$ENDIF}
