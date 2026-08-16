{$IFDEF HELPERS}
function BinaryDiff: MType; overload;
function BinaryDifference(const oAscending: Boolean = True): MType; overload;
function BinaryMedian: Double; overload;
function BinaryMidrange: Double; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryDiff>
  @action: Returns the difference between the last and first elements of the
           array assuming it is sorted.
  @note: The array must already be ordered. If oAscending=True the spread is
         Self[High] - Self[0]. If False, the array is assumed descending and
         the spread is Self[0] - Self[High]. Returns 0 if the array has
         fewer than two elements.
[==============================================================================}
function MArrayHelper.BinaryDiff: MType; overload;
var
  H: Integer;
begin
  H := High(Self);
  if (H <= 0) then
    Exit(0);
  Result := Abs(Self[H] - Self[0]);
end;

{==============================================================================]
  <BinaryDifference>
  @action: Returns the difference between the last and first elements of the
           array assuming it is sorted.
  @note: The array must already be ordered. If oAscending=True the spread is
         Self[High] - Self[0]. If False, the array is assumed descending and
         the spread is Self[0] - Self[High]. Returns 0 if the array has
         fewer than two elements.
[==============================================================================}
function MArrayHelper.BinaryDifference(const oAscending: Boolean = True): MType; overload;
var
  H: Integer;
begin
  H := High(Self);
  if (H <= 0) then 
    Exit(0);
  if oAscending then
    Result := (Self[H] - Self[0])
  else
    Result := (Self[0] - Self[H]);
end;

{==============================================================================]
  <BinaryMedian>
  @action: Computes the median value of a sorted array.
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
function MArrayHelper.BinaryMedian: Double; overload;
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

{==============================================================================]
  <BinaryMidrange>
  @action: Returns the midrange of a sorted array.
           The midrange is the midpoint between the minimum and maximum values:
           midrange = (min + max) / 2
           Behavior:
            • Requires array sorted ascending or descending
            • Uses first and last elements as bounds
           Returns:
            • 0.0 if array is empty
            • the single element if array has length 1
  @note:
   • This is not the mean or median
   • Sensitive to outliers
[==============================================================================}
function MArrayHelper.BinaryMidrange: Double; overload;
var
  H: Integer;
begin
  H := High(Self);
  if (H < 0) then
    Exit(0.0);
  if (H = 0) then
    Exit(Self[0]);
  Result := ((Self[0] + Self[H]) / 2.0);
end;
{$ENDIF}
