{$IFDEF HELPERS}
function BinaryGroup(const aAscending: Boolean = True): M2DArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryGroup>
  @action: Groups the elements of the array into subarrays of identical values,
           maintaining the groups in sorted order. Works efficiently on unsorted
           input, without requiring Self to be pre-sorted.
  @note:
    - Groups are kept in ascending order if aAscending = True, descending if False.
    - Locating an existing group is O(log k) via binary search, where k is the
      number of distinct values seen so far. Creating a new group is O(k) due
      to the underlying dynamic-array Insert shifting subsequent elements.
    - Overall complexity is O(n log k) when k is small relative to n (few
      distinct values, many repeats), degrading toward O(n·k) — i.e. O(n²)
      in the worst case — when most elements are distinct.
    - Fully compatible with unsorted input.
[==============================================================================}
function MArrayHelper.BinaryGroup(const aAscending: Boolean = True): M2DArray; overload;
var
  s: MArray;
  i, m, p: Integer;
  f: Boolean;
  r: TRange;
begin
  SetLength(Result, 0);
  SetLength(s, 0);
  for i := 0 to High(Self) do
  begin
	r.Create(0, High(s));
    f := False;
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      case (s[m] = Self[i]) of
        True:
        begin
          f := True;
          p := m;
          Break;
        end;
        False:
        if ((s[m] < Self[i]) xor (not aAscending)) then
          r.start := (m + 1)
        else
          r.stop := (m - 1);
      end;
    end;
    if not f then
    begin
      p := r.start;
      Insert(Self[i], s, p);
      Insert(nil, Result, p);
    end;
    Result[p].Supply(Self[i]);
  end;
end;
{$ENDIF}
