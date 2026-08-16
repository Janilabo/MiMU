{$IFDEF HELPERS}
function BinaryGrouped(const aAscending: Boolean = True): T2DIntegerArray; overload;
function BinaryGroups(const aAscending: Boolean = True): T2DIntegerArray; overload;
{$ENDIF}

{$IFDEF IMPLEMENTATION}
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
  h, i, r, l, m, v: Integer;
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
	  h := High(Self);
      r := 0;
      for v := Self[0] to Self[h] do
      begin
        s.Create(0, h);
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
              while ((i < h) and (Self[i + 1] = v)) do
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
          if (Result[r].Supply(Self.BinaryItems(i, aAscending)) > -1) then
            Inc(r);
      end;
      False:
      begin
        l := Min((h + 1), ((Self[0] - Self[h]) + 1));
        SetLength(Result, l);
        for i := Self[0] downto Self[h] do
          if (Result[r].Supply(Self.BinaryItems(i, aAscending)) > -1) then
            Inc(r);
      end;
    end;
    if (r < l) then
      SetLength(Result, r);
  end;
end;
{$ENDIF}
