{$IFDEF HELPERS}
function BinaryGroup(const aAscending: Boolean = True): T2DIntegerArray; overload;
function BinaryGrouped(const aAscending: Boolean = True): T2DIntegerArray; overload;
function BinaryGroups(const aAscending: Boolean = True): T2DIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
{==============================================================================]
  <BinaryGroup>
  @action: Groups the elements of the array into subarrays of identical values,
           maintaining the groups in sorted order. Works efficiently on unsorted arrays.
           Uses binary search to locate existing groups or binary-insert to create new ones.
  @note:
    - Groups are kept in ascending order if aAscending = True, descending if False.
    - Complexity is O(n log k), where n = number of elements and k = number of unique values.
    - Fully compatible with unsorted input.
    - Relies on dynamic array insertion for both group keys and result subarrays.
[==============================================================================}
function TIntegerArrayHelper.BinaryGroup(const aAscending: Boolean = True): T2DIntegerArray; overload;
var
  k: TIntegerArray;
  i, m, p: Integer;
  f: Boolean;
  r: TRange;
begin
  SetLength(Result, 0);
  SetLength(k, 0);
  for i := 0 to High(Self) do
  begin
	r.Create(0, High(k));
    f := False;
    while (r.start <= r.stop) do
    begin
      m := r.Pivot;
      case (k[m] = Self[i]) of
        True:
        begin
          f := True;
          p := m;
          Break;
        end;
        False:
        if ((k[m] < Self[i]) xor (not aAscending)) then
          r.start := (m + 1)
        else
          r.stop := (m - 1);
      end;
    end;
    if not f then
    begin
      p := r.start;
      Insert(Self[i], k, p);
      Insert(nil, Result, p);
    end;
    Result[p].Supply(Self[i]);
  end;
end;

{==============================================================================]
  <BinaryGrouped>
  @action: Groups the elements of the array into subarrays of identical values.
           Works efficiently on arrays that are already sorted (ascending).
           Uses binary search to locate all occurrences of each value.
  @note:
    - For ascending order (aAscending = True), assumes Self is sorted ascending.
    - For descending order (aAscending = False), internally sorts a copy of Self
      using TArray_QuickSorted and then reverses the resulting groups.
    - Complexity is O(n + (max-min) * log n) where max-min is the integer range.
[==============================================================================}
function TIntegerArrayHelper.BinaryGrouped(const aAscending: Boolean = True): T2DIntegerArray; overload;
var
  i, r, l, m, v: Integer;
  s: TRange;
  t: TIntegerArray;
begin
  SetLength(Result, 0);
  case Self.Size of
    0: Exit;
    1: Exit([Self]);
  end;
  case aAscending of
    True:
    begin
      r := 0;
      for v := Self[0] to Self[High(Self)] do
      begin
        s.Create(0, High(Self));
        while (s.start <= s.stop) do
        begin
          m := s.Center;
          case Self[m].Compare(v) of
            0:
            begin
              l := m;
              while ((l > 0) and (Self[l - 1] = v)) do
                Dec(l);
              i := m;
              while ((i < High(Self)) and (Self[i + 1] = v)) do
                Inc(i);
              SetLength(Result, (r + 1));
              SetLength(Result[r], ((i - l) + 1));
              Move(Self[l], Result[r][0], (((i - l) + 1) * SizeOf(Integer)));
              Inc(r);
              Break;
            end;
            -1: s.start := (m + 1);
            1: s.stop := (m - 1);
          end;
        end;
      end;
    end;
    False:
    begin
      Result := Self.QuickSorted.BinaryGrouped(True);
	  i := 0;
      l := High(Result);
      while (i < l) do
      begin
        t := Result[i];
        Result[i] := Result[l];
        Result[l] := t;
        Inc(i);
        Dec(l);
      end;
	end;
  end;
end;

{==============================================================================]
  <BinaryGroups>
  @action: Groups the integer array into binary-value groups, returning a 2D array where each row contains
           the values belonging to a specific binary grouping. Iterates in ascending or descending order
           depending on the aAscending flag.
  @note: The input array (Self) must be sorted; otherwise the grouping order and bounds will be incorrect.
         The resulting number of groups may be smaller than the preallocated size and is trimmed afterward.
         Group determination relies on TIntegerArray_BinaryValues and successful insertion by TArray_Supply.
[==============================================================================}
function TIntegerArrayHelper.BinaryGroups(const aAscending: Boolean = True): T2DIntegerArray; overload;
var
  r, h, i, l: Integer;
begin
  SetLength(Result, 0);
  h := High(Self);
  if (h > -1) then
  begin
    r := 0;
    case aAscending of
      True:
      begin
        l := Min((h + 1), ((Self[h] - Self[0]) + 1));
        SetLength(Result, l);
        for i := Self[0] to Self[h] do
          if (Result[r].Supply(Self.BinaryValues(i, aAscending)) > -1) then
            Inc(r);
      end;
      False:
      begin
        l := Min((h + 1), ((Self[0] - Self[h]) + 1));
        SetLength(Result, l);
        for i := Self[0] downto Self[h] do
          if (Result[r].Supply(Self.BinaryValues(i, aAscending)) > -1) then
            Inc(r);
      end;
    end;
    if (r < l) then
      SetLength(Result, r);
  end;
end;
{$ENDIF}
