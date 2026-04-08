{$IFDEF HELPERS}
function Clean(const strictly: Boolean = True): Integer; overload;
function Reduce: Integer; overload;
function Refine(const strictly: Boolean = True): Integer; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <Clean>
  @action: Removes duplicate ranges from the array using a pairwise comparison
           strategy, preserving the first occurrence of each unique range and
           discarding subsequent duplicates.
           The operation is performed in-place using a boolean mask to mark
           elements for retention or removal.
  @note:
    - Comparison mode is controlled by `strictly`:
        * True  → compares (start, stop)
        * False → compares (Minimum, Maximum)
    - Algorithm:
        1. Initialize a boolean keep-mask `k[]` to True.
        2. For each element i:
             - If k[i] is True, compare against all subsequent elements j > i.
             - If a duplicate is found, mark k[j] := False.
        3. Perform a compaction pass:
             - Copy all k[i] = True elements forward.
             - Count removed العناصر.
    - Duplicate condition:
        strictly = True:
          (Self[j].start = Self[i].start) AND (Self[j].stop = Self[i].stop)
        strictly = False:
          (Self[j].Minimum = Self[i].Minimum) AND
          (Self[j].Maximum = Self[i].Maximum)
    - Stability:
        * Stable — preserves the first occurrence, removes later duplicates.
        * Original relative order of retained elements is preserved.
    - Complexity:
        * Time:  O(n²) due to nested comparisons.
        * Space: O(n) for the boolean mask.
    - Result:
        * Returns the number of removed elements.
        * Final array is truncated to contain only unique ranges.
    - Notes:
        * No sorting is performed; operates on current order.
        * Prefer Refine for O(n log n) deduplication when sorting is acceptable.
        * Effective for small arrays or when order preservation is critical
          without reordering side effects.
[==============================================================================}
function TRangeArrayHelper.Clean(const strictly: Boolean = True): Integer; overload;
var
  i, j, l: Integer;
  k: TBooleanArray;
begin
  l := Self.Length;
  k.Create(l, True);
  for i := 0 to (l - 2) do
    if k[i] then
      for j := (i + 1) to (l - 1) do
        if k[j] then
          if strictly then
            k[j] := ((Self[j].start <> Self[i].start) or (Self[j].stop <> Self[i].stop))
          else
            k[j] := ((Self[j].Minimum <> Self[i].Minimum) or (Self[j].Maximum <> Self[i].Maximum));
  Result := 0;
  j := 0;
  for i := 0 to (l - 1) do
    if k[i] then
      Self[j.Increase] := Self[i]
    else
      Inc(Result);
  SetLength(Self, j);
end;

{==============================================================================]
  <Reduce>
  @action: Compacts the range array by eliminating ranges that are fully contained
           within another range. The operation preserves only the minimal set of
           non-redundant ranges.
           The algorithm performs an in-place reduction:
             1. Sorts ranges (implicitly by Minimum, then Maximum).
             2. Iterates linearly, keeping a write index (r).
             3. For each range i, checks if it is completely enclosed within
                the current retained range r.
             4. If not enclosed, advances r and stores the new range.
  @note:
    - A range A is considered redundant if:
        A.Minimum >= B.Minimum AND A.Maximum <= B.Maximum
      where B is the current retained range.
    - Assumes Sort orders ranges ascending by Minimum (and Maximum as tie-breaker).
    - Time complexity:
        O(n log n) due to sorting + O(n) scan.
    - Operates in-place; no additional allocations except final resize.
    - Result returns the number of removed (reduced) elements:
        Result = original_length - new_length
    - If length < 2, no reduction occurs.
    - Final array is truncated to (r + 1) elements.
[==============================================================================}
function TRangeArrayHelper.Reduce: Integer; overload;
var
  i, r, l: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(0);
  Self.Sort;
  r := 0;
  for i := 1 to (l - 1) do
    if not ((Self[i].Minimum >= Self[r].Minimum) and (Self[i].Maximum <= Self[r].Maximum)) then
      Self[r.Increase] := Self[i];
  Result := (l - r);
  if (Result > 0) then
    SetLength(Self, (r + 1));
end; 

{==============================================================================]
  <Refine>
  @action: Deduplicates the range array by removing identical ranges. Supports
           two comparison modes controlled by the `strictly` flag.
           The operation performs an in-place refinement:
            - Sorts the array according to the selected comparison basis.
            - Iterates through elements, retaining only distinct entries.
            - Compacts results using a write index (r).
  @note:
    - strictly = True:
        * Uses Start/Stop fields for comparison.
        * Sort order: SortByStart.
        * Suitable when logical identity depends on exact boundaries
          as defined by start/stop semantics.
    - strictly = False:
        * Uses Minimum/Maximum fields for comparison.
        * Sort order: SortByMinimum.
        * Suitable when normalized bounds define equality.
    - Duplicate condition:
        Two ranges are considered equal if both boundary pairs match.
    - Uses r as the last unique element index; elements are overwritten
      in-place when duplicates are skipped.
    - Time complexity:
        O(n log n) due to sorting + O(n) scan.
    - Result returns the number of removed duplicates:
        Result = original_length - new_length
    - If length < 2, no refinement occurs.
    - Final array is truncated to (r + 1) elements.
    - The check:
        if (r.Increment <> i)
      avoids redundant self-assignment when the element is already
      in the correct position.
[==============================================================================}
function TRangeArrayHelper.Refine(const strictly: Boolean = True): Integer; overload;
var
  i, r, l: Integer;
begin
  l := Self.Length;
  if (l < 2) then
    Exit(0);
  r := 0;
  case strictly of
  True:
  begin
    Self.SortByStart;
    for i := 1 to High(Self) do
      if ((Self[i].start <> Self[r].start) or (Self[i].stop <> Self[r].stop)) then
        if (r.Increment <> i) then
          Self[r] := Self[i];
  end;
  False:
  begin
    Self.SortByMinimum;
    for i := 1 to High(Self) do
      if ((Self[i].Minimum <> Self[r].Minimum) or (Self[i].Maximum <> Self[r].Maximum)) then
        if (r.Increment <> i) then
          Self[r] := Self[i];
  end;
end;
  Result := (l - r);
  if (Result > 0) then
    SetLength(Self, (r + 1));
end;
{$ENDIF}